/* ------------------------------------------------------------------------ */
/**
 *  \file       util.c
 *  \brief      Ce fichier contient la fonction exécutée à la fin de
 *				l'exécution du programme
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
*/

/* ------------------------------------------------------------------------ */
/*				I N C L U D E(s)  S T A N D A R D(s)                        */
/* ------------------------------------------------------------------------ */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <time.h>

#include <sys/types.h>
#include <sys/timeb.h>

#if defined (_WIN32)
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")
//#elif defined (__unix__)
#else
#define  __unix__
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif


#if defined (_MSC_VER)
/*
 *	Sélection du niveau le plus élevé d'affichage des messages
 *	d'avertissement
 */
#pragma warning( push, 4 )

/*
 *	Désactivation de l'affichage des messages d'avertissement liés à
 *	l'utilisation de fonctions dépréciées par Visual C++ car remplaéÈes
 *	par des fonctions spécifiques plus sûres mais non standards
 */
#pragma warning( disable : 4996 )
#endif
/* ------------------------------------------------------------------------ */
/*		C O N S T A N T E S   &   P R O T O T Y P E S						*/
/* ------------------------------------------------------------------------ */
#define MAXLEN          256
/* ------------------------------------------------------------------------ */
/**
 *  \fn         void epilogue(void)
 *  \brief      Fonction exécutée à la fin de l'exécution du programme
 *
 *				Elle affiche des informations identifiant l'utilisateur,
 *				l'ordinateur sur lequel il travaille et donne la date et
 *				l'heure de fin d'exécution.
 *
 *  \param      néant
 *  \return     néant
 */
void epilogue(void)
{
    static const char * jour[] = {
        "Dimanche", "Lundi", "Mardi", "Mercredi",
        "Jeudi", "Vendredi", "Samedi"};
    
    static const char * mois[] = {
        "Janvier", "Fevrier", "Mars"     , "Avril"  , "Mai"     , "Juin"    ,
        "Juillet", "Aout"   , "Septembre", "Octobre", "Novembre", "Decembre",
    };
    
    time_t ltime;
    struct tm * today;
    char userName[MAXLEN + 1] = "";
    char hostName[MAXLEN + 1] = "";
    unsigned long name_len = MAXLEN + 1;
    
#if defined (_WIN32)
    WSADATA wsaData;
#endif
    
    struct hostent * pHostEntry;
    struct in_addr *pinAddr;
    
#if defined (_WIN32)
    WSAStartup(MAKEWORD(2,2), &wsaData);
#endif
    
    /*	Nom de l'utilisateur   					                			*/
#if defined (_WIN32)
    GetUserName(userName, &name_len);
#elif defined (__unix__)
    getlogin_r(userName,name_len);
#endif
    printf("\n%-9.9s ", userName);
    
    /*	Nom de l'ordinateur   								                */
    gethostname(hostName, MAXLEN);
    
    /* Nom rÈseau et adresse IP de l'ordinateur								*/
    pHostEntry = gethostbyname(hostName);
    if (pHostEntry != NULL)
    {
        printf("%-13.10s ", pHostEntry->h_name);
        pinAddr = ((struct in_addr *)pHostEntry->h_addr_list[0]);
        if (pinAddr != NULL)
            printf("%s ", inet_ntoa(*pinAddr));
    }
    
    /*	Date et heure														*/
    tzset();
    time(&ltime);
    today = localtime(&ltime);
    printf("%9s %d %s %4d a %dh %dmn %ds\n",
           jour[today->tm_wday], today->tm_mday,
           mois[today->tm_mon], today->tm_year + 1900,
           today->tm_hour, today->tm_min, today->tm_sec);
    
#if defined (_WIN32)
    WSACleanup();
#endif
}

void prologue(void)
{
    srand((unsigned int)time(NULL));
    atexit(epilogue);
}
/* ------------------------------------------------------------- THE END -- */
