/* ------------------------------------------------------------------------ */
/**
 *  \file       AVL.c
 *  \brief      Implémentation d'un module de gestion d'arbres binaires
 *              de recherche H-Equilibrées
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */
/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S T A N D A R D (s)					*/
/* ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S P É C F I Q U E (s)				*/
/* ------------------------------------------------------------------------ */
#include "tp4.h"
#include "AVL.h"

/* ------------------------------------------------------------------------ */
/*		P R O T O T Y P E S   D E S   F O N C T I O N S   L O C A L E S		*/
/* ------------------------------------------------------------------------ */
static void displayAVL(const noeudAVL_t *a);
static void displayInverseAVL(const noeudAVL_t *a);
static void genererDotPng(const noeudAVL_t * a, FILE *fp);

// TP4

/**
 *  \brief      Utilisé dans supprimerRacineABR, supprime la racine de l'arbre.
 *  \param      e       l'élément à supprimer
 *  \param      a   L'arbre
 *  \return     l'arbre après suppression de l'élément.
 */
static AVL_t supprimerRacineAVL(elt_t e, AVL_t a);

/* ------------------------------------------------------------------------ */
static void displayAVL(const noeudAVL_t *a)
{
    // Affichage GRD
    if( PASVIDE(a) )
    {
        displayAVL(GAUCHE(a));      // G pour gauche
        printf("   %d(%d)",a->elt,a->balance);     // R pour racine
        displayAVL(DROITE(a));       // D pour droit
    }
}

/* ------------------------------------------------------------------------ */
static void displayInverseAVL(const noeudAVL_t *a)
{
    // Affichage DRG
    if( PASVIDE(a) )
    {
        displayInverseAVL(DROITE(a));      // D pour droit
        printf("   %d",a->elt);    // R pour racine
        displayInverseAVL(GAUCHE(a));     // G pour gauche
    }
}

/* ------------------------------------------------------------------------ */
static AVL_t supprimerRacineAVL(elt_t e, AVL_t a)
{
    assert( PASVIDE(a) && RACINE(a) == e);

    if( EST_FEUILLE(a) )
    {
        //printf("DEBUG - a est une feuille.\n");
        free(a);
        return NULL;
    }

    if( VIDE(GAUCHE(a)))
    {
        noeudAVL_t* aux = copierAVL(DROITE(a));
        //printf("DEBUG - VIDE(GAUCHE()) - aux :\n"); afficherAVL(aux);
        free(a);
        return aux;
    }

    if( VIDE(DROITE(a)) )
    {
        noeudAVL_t* aux = copierAVL(GAUCHE(a));
        //printf("DEBUG - VIDE(DROITE()) - aux :\n"); afficherAVL(aux);
        free(a);
        return aux;
    }

    //printf("DEBUG - a contient deux descendants, on va chercher le plus petit élément du sous arbre droit.\n");
    elt_t minArbreDroit = chercherMinAVL(DROITE(a));

    int hOrigine = hauteurAVL(DROITE(a));
    DROITE(a) = supprimer1EltAVL(minArbreDroit, DROITE(a));
    int hNouveau = hauteurAVL(DROITE(a));

    BALANCE(a) += hOrigine - hNouveau;

    RACINE(a) = minArbreDroit;

    return equilibrer(a);
}


/* ------------------------------------------------------------------------ */
AVL_t rotationGauche(AVL_t a)   // cf notes
{
    AVL_t b = DROITE(a);    // b sera la nouvelle racine de l'arbre en question.
    DROITE(a) = GAUCHE(b) ;
    GAUCHE(b) = a ;

    // Ces formules viennent du cours
    BALANCE(a) = BALANCE(a)  + 1 - MIN(0, BALANCE(b));
    BALANCE(b) = BALANCE(b) + 1 + MAX(0, BALANCE(a));

    return b;
}
/* ------------------------------------------------------------------------ */
AVL_t rotationDroite(AVL_t a)
{
    AVL_t b = GAUCHE(a);       // cf 1er commentaire rotationGauche
    GAUCHE(a) = DROITE(b);
    DROITE(b) = a ;

    // Cf cours.
    BALANCE(a) = BALANCE(a) - 1 - MAX(BALANCE(b),0);
    BALANCE(b) = BALANCE(b) - 1 + MIN(0,BALANCE(a));

    return b;
}
/* ------------------------------------------------------------------------ */
AVL_t equilibrer(AVL_t a)
{

    if( BALANCE(a) == -FACTEUR_DESEQUILIBRE_MAX )     // Si l'arbre penche à droite
    {
        if (BALANCE(DROITE(a)) == 1)   // Si le ss arbre droit penche à gauche, il faut le repencher vers la droite.
            DROITE(a) = rotationDroite(DROITE(a));
        return rotationGauche(a);
    }

    if( BALANCE(a) == FACTEUR_DESEQUILIBRE_MAX )   // Si l'arbre penche à gauche
    {
        if( BALANCE(GAUCHE(a)) == -1)   // même raisonnement que ci-dessus.
            GAUCHE(a) = rotationGauche(GAUCHE(a));
        return rotationDroite(a);
    }

    return a;   // Si l'arbre est déjà équilibré, on le retourne.

}
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
int insererAVL(elt_t e, AVL_t *a)
{
    if( VIDE(*a) )   // On crée une feuille (cas trivial de la récursivité) et on renvoie 1 car variation de hauteur.
    {
        *a = creer1Noeud(e, NULL, NULL);
        return 1;
    }

    int retourCascade = 0;

    if( RACINE(*a) > e )
    {
        retourCascade = +insererAVL(e, &GAUCHE(*a));    // on insère dans le sous arbre gauche
    }
    else if( RACINE(*a) < e)                    // On évite les doublons.
    {
        retourCascade = -insererAVL(e, &DROITE(*a));    // on insère dans le sous arbre droit
    }

    if( retourCascade == 0 )        // pas de variation de hauteur, on retourne 0
        return 0;

    BALANCE(*a) += retourCascade;

    //printf("DEBUG - Racine actuelle : %d (balance = %d)\n",RACINE(*a),BALANCE(*a));
    if( DESEQUILIBRE(*a) )
    {
        *a = equilibrer(*a);
        //BALANCE(*a) vaut soit -1, soit 0, soit 1
        // Si l'arbre est équilibré, on retourne 0. sinon 1 car variation de hauteur.
        return ABS( BALANCE(*a) );
    }

    return 1;   // il y a eu variation de hauteur => on retourne 1
}


int   estDansAVL(elt_t e, const noeudAVL_t *a)
{
    if( VIDE(a) )   //1er cas trivial
        return false;

    if ( a->elt == e)   // 2e cas trivial
        return -true;       // true retourne -1

    // On effectue le parcours GAUCHE -> DROITE
    if (estDansAVL(e, GAUCHE(a)) )
        return -true;
    else
        return estDansAVL(e, DROITE(a));
}

/* ------------------------------------------------------------------------ */
int hauteurAVL(const noeudAVL_t *a)
{
    if( VIDE(a) )       // Cas trivial : ABR vide == niveau -1
        return -1;

    return 1+ MAX(hauteurAVL(GAUCHE(a)), hauteurAVL(DROITE(a)) );
}

unsigned int nbNoeudsAVL(const noeudAVL_t *a)
{
    if( VIDE(a) )       // Cas trivial : ABR vide <=> 0 élément
        return 0;

    /*if( EST_FEUILLE(a) )    // Cas trivial : on a une feuille <=> 1 élément
        return 1;*/

    return 1 + nbNoeudsAVL(GAUCHE(a)) + nbNoeudsAVL(DROITE(a));


}

/* ------------------------------------------------------------------------ */
noeudAVL_t * supprimerAVL(noeudAVL_t *a)
{
    if( VIDE(a) )
        return NULL;

    if( EST_FEUILLE(a))
    {
        free(a);
        return NULL;
    }

    GAUCHE(a) = supprimerAVL(GAUCHE(a));
    DROITE(a) = supprimerAVL(DROITE(a));
    free(a);
    return NULL;
}

/* ------------------------------------------------------------------------ */
noeudAVL_t * copierAVL(const noeudAVL_t *a)
{
    if( VIDE(a) )
        return NULL;

    /*if( EST_FEUILLE(a))
        return creer1Noeud(a->elt,NULL,NULL);*/

    noeudAVL_t * aux = creer1Noeud(a->elt,NULL,NULL);
    GAUCHE(aux) = copierAVL(GAUCHE(a));
    DROITE(aux) = copierAVL(DROITE(a));
    BALANCE(aux) = BALANCE(a);

    return aux;
}

/* ------------------------------------------------------------------------ */
int egalAVL(const noeudAVL_t *a1, const noeudAVL_t *a2)
{
    if( VIDE(a1) || VIDE(a2) )
        return VIDE(a1) && VIDE(a2);


    if( EST_FEUILLE(a1) || EST_FEUILLE(a2) )
    {
        if( EST_FEUILLE(a1) && EST_FEUILLE(a2) )
            return a1->elt == a2->elt;
        else
            return false;
    }

    return egalAVL(GAUCHE(a1), GAUCHE(a2)) && egalAVL(DROITE(a1), DROITE(a2));
}

/* ------------------------------------------------------------------------ */
static void  genererDotPng(const noeudAVL_t * a, FILE *fp)
{
    if( VIDE(a) )
        return;

    fprintf(fp,"%d [label = \"{<c> %d | { <g> | <d>}}\"];\n",a->elt,a->elt);        // on écrit la ligne commune à tous les arbres non vides.

    if( VIDE(DROITE(a)) || VIDE(GAUCHE(a))) {            // Si a ne possède pas 2 descendants directs.
        fprintf(fp, "%d [label = \"{<c> %d | { <g>", a->elt, a->elt);              // on écrit une ligne où il y a aura AU MOINS une inscription NULL.

        if (VIDE(GAUCHE(a)))
            fprintf(fp, " NULL");

        fprintf(fp, " | <d>");

        if (VIDE(DROITE(a)))
            fprintf(fp, " NULL");

        fprintf(fp, "}}\"];\n");
    }

    if( !EST_FEUILLE(a) )           // si a possède au moins un descendant
    {
        if( PASVIDE(GAUCHE(a)) )
            fprintf(fp,"%d:g -> %d;\n",a->elt,GAUCHE(a)->elt);
        genererDotPng(GAUCHE(a),fp);
        if( PASVIDE(DROITE(a)) )
            fprintf(fp,"%d:d -> %d;\n",a->elt,DROITE(a)->elt);
        genererDotPng(DROITE(a),fp);
    }


}

/* ------------------------------------------------------------------------ */

elt_t chercherMinAVL(noeudAVL_t *a)
{
    if( VIDE(a) )       // Cas particulier : arbre vide, on renvoie une valeur d'erreur.
        return 1024;

    if( VIDE(GAUCHE(a)) || EST_FEUILLE(a) )
    {
        return a->elt;  // Cas trivial de la récursivité : on renvoie l'élément si l'arbre est une feuille
                        // Mais aussi lorsqu'on ne peut plus aller à gauche !
    }

    return chercherMinAVL(GAUCHE(a));   // Cas général de la récursivité : on va chercher l'élément le plus à gauche de l'arbre.
}

/* ------------------------------------------------------------------------ */
AVL_t supprimer1EltAVL(elt_t e, AVL_t a)
{
    if( VIDE(a) )
        return NULL;

    if( RACINE(a) == e )
    {
        //printf("DEBUG - Elément trouvé !\n");
        a = supprimerRacineAVL(e, a);
        if( a != NULL)
            BALANCE(a) = hauteurAVL(GAUCHE(a)) - hauteurAVL(DROITE(a));
        return a;
    }

    if(RACINE(a) > e)
    {
        GAUCHE(a) = supprimer1EltAVL(e, GAUCHE(a));
        BALANCE(a) = hauteurAVL(GAUCHE(a)) - hauteurAVL(DROITE(a));
    }
    else
    {
        DROITE(a) = supprimer1EltAVL(e, DROITE(a));
        BALANCE(a) = hauteurAVL(GAUCHE(a)) - hauteurAVL(DROITE(a));
    }


    return equilibrer(a);
}
/* ------------------------------------------------------------------------ */


/* ------------------------------------------------------------------------ */
/*			F O N C T I O N S   M I S E S   À   D I S P O S I T I O N		*/
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
noeudAVL_t * creer1Noeud(elt_t e, noeudAVL_t * g, noeudAVL_t * d)
{
    noeudAVL_t * p;
    p = (noeudAVL_t *)malloc(sizeof(noeudAVL_t));
    if (p != NULL)
    {
        p->elt = e;
        p->gauche = g;
        p->droit = d;
        p->balance = hauteurAVL(g) - hauteurAVL(d);
    }
    return p;
}

/* ------------------------------------------------------------------------ */
void afficherAVL(const noeudAVL_t *a)
{
    displayAVL(a);
    printf("\n");
}

/* ------------------------------------------------------------------------ */
void afficherInverseAVL(const noeudAVL_t *a)
{
    displayInverseAVL(a);
    printf("\n");
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void creerDotABR(const T_ABR arbre, const char *basename)
 *  \brief      Créer le fichier .dot représentant l'arbre binaire de
 *				rechercher
 *  \param      arbre  l'arbre binaire
 *  \param      basename le nom du fichier à créer, sans son extension qui
 *				sera ajoutée (.dot) ainsi qu'un numéro de version
 *  \return    	néant
 *	\note		Le fichier est refermé en fin d'exécution de la fonction
 *	\remark		Ne convient (dans l'état) que pour des ABR dont
 *				les noeuds contiennent des valeurs entières toutes distinctes
 */
void creerDotAVL(const noeudAVL_t *arbre, const char *basename)
{
    static char oldBasename[FILENAME_MAX + 1] = "";
    char fnameDot [FILENAME_MAX + 1];
    char fnamePng [FILENAME_MAX + 1];
    static unsigned int noVersion = 0;
    char	cmdLine [2 * FILENAME_MAX + 20];
    FILE *fp;
    
    /*
     *	Au premier appel, création (si nécessaire) des répertoires
     *	où seront rangés les fichiers .dot et .png générés par cette
     *	fonction
     */
    if (oldBasename[0] == '\0')
    {
        mkdir(DOSSIER_PNG,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
        mkdir(DOSSIER_DOT,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    }
    /*
     *	S'il y a changement de nom de base alors recommencer
     *	à zéro, la numérotation des fichiers
     */
    if (strcmp(oldBasename, basename) != 0)
    {
        noVersion = 0;
        strcpy(oldBasename, basename);
    }
    sprintf(fnameDot, "%s%s_v%02u.dot", DOSSIER_DOT, basename, noVersion);
    sprintf(fnamePng, "%s%s_v%02u.png", DOSSIER_PNG, basename, noVersion);
    if ( (fp = fopen(fnameDot, "w")) == NULL)
    {
        fprintf(stderr, "Impossible de creer le fichier \"%s\"\n", fnameDot);
        exit(EXIT_FAILURE);
    }
    
    noVersion ++;
    fprintf(fp, "digraph %s {\n", basename);
    fprintf(fp,
            "\tnode [\n"
            "\t\tfontname  = \"Arial bold\" \n"
            "\t\tfontsize  = \"14\"\n"
            "\t\tfontcolor = \"red\"\n"
            "\t\tstyle     = \"rounded, filled\"\n"
            "\t\tshape     = \"record\"\n"
            "\t\tfillcolor = \"grey90\"\n"
            "\t\tcolor     = \"blue\"\n"
            "\t\twidth     = \"2\"\n"
            "\t]\n"
            "\n"
            "\tedge [\n"
            "\t\tcolor     = \"blue\"\n"
            "\t]\n\n"
            );
    
    if (arbre == NULL)
        fprintf(fp, "\n");
    else
        genererDotPng(arbre, fp);
    
    fprintf(fp, "}\n");	
    fclose(fp);
    
    sprintf(cmdLine, "%s -Tpng  %s -o %s", DOT_CMD, fnameDot, fnamePng);
    system(cmdLine);
    
    printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}
/* ------------------------------------------------------------------------ */
