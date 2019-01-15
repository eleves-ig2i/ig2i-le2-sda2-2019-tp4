/**
 *  \file       tp4.c
 *  \brief      Programme de test du module de gestion d'un
 *              arbre binaire de recherche H-equilibré contenant des valeurs
 *              entières 
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
#include <time.h>

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S P É C F I Q U E (s)				*/
/* ------------------------------------------------------------------------ */
#include "tp4.h"
#include "testAVL.h"

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main(void)
 *  \brief      Fonction principale unique destinée ici à effectuer les
 *				tests des différentes fonctions réalisées en TP
 *
 *				L'ensemble des tests prévus est encadré des directives
 *				de compilation conditionnelle #if ... #endif.
 *				Il suffit d'extraire de cette zone le test à effectuer
 *				et de l'insérer avant, pour activer le test en question.
 *				Le remettre dans sa zone initiale, lorsqu'il devient
 *				inutile de  l'exécuter.
 *
 *  \param      néant
 *  \return     EXIT_SUCCESS
 */
int main(void)
{
    prologue();

    test_supprimer1EltAVL();
    
#if (0)
    test_equilibrer();
    test_rotationGauche();
    test_rotationDroite();
    test_afficherAVL();
    test_afficherInverseAVL();
    test_insererAVL();
    test_copierAVL();
    test_egalAVL();
    test_estDansAVL();
    test_chercherMinAVL();
    test_supprimer1EltAVL();
    test_creerDotPng();
#endif
    
    return EXIT_SUCCESS;
}

