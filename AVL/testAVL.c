/* ------------------------------------------------------------------------ */
/**
 *  \file       testAVL.c
 *  \brief      Implémentation d'un module de test des fonction de gestion
 *				d'arbres binaires de recherche H-Equilibrés
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S T A N D A R D (s)					*/
/* ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S P É C F I Q U E (s)				*/
/* ------------------------------------------------------------------------ */
#include "testAVL.h"


#define	PROMPT	"\nNombre de tentatives d'insertion dans l'ABR"	\
"(. pour terminer) : "


/* ------------------------------------------------------------------------ */
void	test_rotationGauche(void)
{
    printf("Test de rotationGauche()\n---------------------\n");

    AVL_t arbre = creer1Noeud(1,NULL, creer1Noeud(2,NULL,creer1Noeud(3,NULL,NULL)));
    //AVL_t arbre = creer1Noeud(1,NULL, creer1Noeud(3,creer1Noeud(2,NULL,NULL),NULL));
    creerDotAVL(arbre,"rotaGauche_arbreOriginal");
    printf("Arbre créé :\n");afficherAVL(arbre);

    printf("On effectue la rotation gauche de l'arbre original :\n");
    arbre = rotationGauche(arbre);
    creerDotAVL(arbre,"rotaGauche_arbreModifie");
    printf("Arbre modifié :\n");afficherAVL(arbre);

    printf("Regarder les images .png créées.\n");
}
/* ------------------------------------------------------------------------ */
void	test_rotationDroite(void)
{
    printf("Test de rotationDroite()\n---------------------\n");

    AVL_t arbre = creer1Noeud(1,NULL, creer1Noeud(3,creer1Noeud(2,NULL,NULL),NULL));
    creerDotAVL(arbre,"rotaDroite_arbreOriginal");
    printf("Arbre créé :\n");afficherAVL(arbre);

    printf("On effectue la rotation droite du sous arbre droit :\n");
    DROITE(arbre) = rotationDroite(DROITE(arbre));
    creerDotAVL(arbre,"rotaDroite_arbreModifie");
    printf("Arbre modifié :\n");afficherAVL(arbre);

    printf("Regarder les images .png créées.\n");
}
/* ------------------------------------------------------------------------ */
void    test_equilibrer(void)
{
    printf("Test de equilibrer()\n---------------------\n");

    printf("Création de l'arbre 1.\n");
    AVL_t arbre1 = creer1Noeud(1,NULL, creer1Noeud(3,creer1Noeud(2,NULL,NULL),NULL));
    creerDotAVL(arbre1,"equilibrer_arbre1_original");
    printf("Arbre créé :\n");afficherAVL(arbre1);
    printf("On équilibre l'arbre 1.\n");
    arbre1=equilibrer(arbre1);
    printf("Arbre modifié :\n");afficherAVL(arbre1);
    creerDotAVL(arbre1,"equilibrer_arbre1_equilibre");

    printf("Création de l'arbre 2.\n");
    arbre1 = creer1Noeud(15,creer1Noeud(12,NULL,creer1Noeud(13,NULL,NULL)), NULL);
    creerDotAVL(arbre1,"equilibrer_arbre2_original");
    printf("Arbre créé :\n");afficherAVL(arbre1);
    printf("On équilibre l'arbre 2.\n");
    arbre1=equilibrer(arbre1);
    printf("Arbre modifié :\n");afficherAVL(arbre1);
    creerDotAVL(arbre1,"equilibrer_arbre2_equilibre");

    printf("Création de l'arbre 3.\n");
    arbre1 = creer1Noeud(1,NULL,creer1Noeud(2,NULL,creer1Noeud(3,NULL,NULL)));
    creerDotAVL(arbre1,"equilibrer_arbre3_original");
    printf("Arbre créé :\n");afficherAVL(arbre1);
    printf("On équilibre l'arbre 3.\n");
    arbre1=equilibrer(arbre1);
    printf("Arbre modifié :\n");afficherAVL(arbre1);
    creerDotAVL(arbre1,"equilibrer_arbre3_equilibre");

    printf("Création de l'arbre 4.\n");
    arbre1 = creer1Noeud(3,creer1Noeud(2,creer1Noeud(1,NULL,NULL),NULL),NULL);
    creerDotAVL(arbre1,"equilibrer_arbre4_original");
    printf("Arbre créé :\n");afficherAVL(arbre1);
    printf("On équilibre l'arbre 4.\n");
    arbre1=equilibrer(arbre1);
    printf("Arbre modifié :\n");afficherAVL(arbre1);
    creerDotAVL(arbre1,"equilibrer_arbre4_equilibre");

}
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
void	test_afficherAVL(void)
{
    noeudAVL_t * a = NULL;
    
    printf("Affichage d'un arbre vide\n");
    afficherAVL(a);
    
    printf("Affichage d'un arbre reduit a un seul noeud\n");
    a = creer1Noeud(19, NULL, NULL);
    afficherAVL(a);
    
    printf("Affichage d'un arbre de plusieurs noeuds\n");
    a->gauche = creer1Noeud(12, NULL,
                            creer1Noeud(16, creer1Noeud(14, NULL, NULL),
                                            creer1Noeud(18, NULL, NULL)));
    
    a->droit  = creer1Noeud(34,
                             creer1Noeud(24, creer1Noeud(21, NULL, NULL),
                                            creer1Noeud(30, NULL, NULL)), NULL);

    afficherAVL(a);
    a = supprimerAVL(a);
}

/* ------------------------------------------------------------------------ */
void	test_afficherInverseAVL(void)
{
    noeudAVL_t * a = NULL;
    
    printf("Affichage inverse d'un arbre vide\n");
    afficherInverseAVL(a);
    
    printf("Affichage inverse d'un arbre reduit a un seul noeud\n");
    a = creer1Noeud(19, NULL, NULL);
    afficherInverseAVL(a);
    
    printf("Affichage inverse d'un arbre de plusieurs noeuds\n");
    a->gauche = creer1Noeud(12,
                            NULL,
                            creer1Noeud(16,
                                        creer1Noeud(14, NULL, NULL),
                                        creer1Noeud(18, NULL, NULL)));
    a->droit  = creer1Noeud(34,
                             creer1Noeud(24,
                                         creer1Noeud(21, NULL, NULL),
                                         creer1Noeud(30, NULL, NULL)
                                         ),
                             NULL);
    afficherInverseAVL(a);
    
    a = supprimerAVL(a);
}

/* ------------------------------------------------------------------------ */
void test_insererAVL(void)
{
    printf("Test de insererAVL()\n---------------------\n");
    AVL_t a = NULL;

    printf("On insère les valeurs dans l'ordre suivant : 10,5,15,12,13,11,3,12\n");
    insererAVL(10,&a);
    insererAVL(5,&a);
    insererAVL(15,&a);
    insererAVL(12,&a);
    insererAVL(13,&a);
    creerDotAVL(a,"inserer_tempo_");
    insererAVL(11,&a);
    creerDotAVL(a,"inserer_tempo_");
    insererAVL(3,&a);
    insererAVL(12,&a);
    printf("Arbre créé :\n");afficherAVL(a);
    creerDotAVL(a,"inserer_1");

}

/* ------------------------------------------------------------------------ */
void	test_estDansAVL(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que la recherche dans un arbre vide est correcte		*/
    /*	2)	construire un ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions : cf. test_insererAVL()							*/
    /*	3)	Prendre quelques valeurs différentes (~ 3 valeurs) et			*/
    /*		afficher "la valeur xx est presente dans l'ABR" si elle s'y		*/
    /*		trouve et "la valeur xx est absente de l'ABR si c'est le cas	*/
    /*																		*/
    /*	Prévoir l'affichage de l'ABR pour le contrôle des résultats			*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    printf("Test de estDansAVL()\n---------------------\n");

    noeudAVL_t *a = NULL;

    printf("Dans un arbre vide :\n");
    afficherAVL(a);
    printf("estDansAVL(18,a) = %d\n", estDansAVL(18, a) );

    printf("On effectue une dizaine d'insertions :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        insererAVL(1 + rand() % nb, &a);
    afficherAVL(a);
    int test = 1 + rand() % nb;
    printf("estDansAVL(%d,a) = %d\n",test, estDansAVL(test, a) );
}

/* ------------------------------------------------------------------------ */
void	test_copierAVL(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que la copie d'un arbre vide est un arbre vide			*/
    /*	2)	construire un ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions et l'afficher										*/
    /*	3)	créer la copie et l'afficher									*/
    /*	4)	supprimer l'orginal et s'assurer que sa copie est intacte		*/
    /*	5)	supprimer tous les arbres créés dans ce test					*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    noeudAVL_t *monArbre = NULL, *copie = NULL;
    printf("Test de copierAVL()\n---------------------\n");

    printf("On copie un arbre vide dans un arbre vide. Affichage de copie :\n");
    copie = copierAVL(monArbre);
    afficherAVL(copie);

    printf("On effectue une dizaine d'insertions dans monArbre. Affichage de monArbre :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        insererAVL(1 + rand() % nb, &monArbre);
    afficherAVL(monArbre);

    printf("On copie cet arbre dans la copie. Affichage de copie :\n");
    copie = copierAVL(monArbre);
    afficherAVL(copie);

    printf("On modifie l'arbre original, affichage de copie :\n");
    insererAVL(325, &monArbre);
    afficherAVL(copie);
    printf("Affichage de monArbre :\n");
    afficherAVL(monArbre);

    copie = supprimerAVL(copie);
    monArbre = supprimerAVL(monArbre);

}


/* ------------------------------------------------------------------------ */
void	test_egalAVL(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que deux arbres vides sont égaux						*/
    /*	2)	vérifier qu'un arbre vide ne peut être égal à un arbre non vide	*/
    /*	2)	construire deux ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions les afficher puis les comparer 					*/
    /*	3)	créer une copie de l'un des deux et la comparer à l'original	*/
    /*	4)	supprimer tous les arbres créés dans ce test					*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    printf("Test de egalAVL()\n---------------------\n");

    printf("On vérifie que 2 arbres vides sont égaux.\n");
    printf("egalAVL(NULL,NULL) == %d\n", egalAVL(NULL, NULL));

    noeudAVL_t *monArbre1 = NULL;
    noeudAVL_t *monArbreCopie = NULL;
    insererAVL(18, &monArbre1);
    noeudAVL_t *monArbre2 = NULL;
    printf("On crée un ABR, qui est une feuille.\n");
    printf("egalABR(monArbre1,NULL) == %d && egalAVL(NULL,monArbre1) == %d\n", egalAVL(monArbre1, NULL),
           egalAVL(NULL, monArbre1));

    printf("On effectue une dizaine d'insertions dans monArbre1 et monArbre2. Affichage de monArbre1 :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++) {
        insererAVL(1 + rand() % nb, &monArbre1);
        insererAVL(1 + rand() % nb, &monArbre2);
    }
    afficherAVL(monArbre1);
    printf("Affichage de monArbre2 :\n");
    afficherAVL(monArbre2);
    printf("egalAVL(monArbre1,monArbre2) == %d\n", egalAVL(monArbre1, monArbre2));

    printf("On copie monArbre1 dans monArbreCopie. Affichage de monArbreCopie :\n");
    monArbreCopie = copierAVL(monArbre1);
    afficherAVL(monArbreCopie);
    printf("egalABR(monArbre1,monArbreCopie) == %d && egalAVL(monArbreCopie,monArbre1) == %d",
           egalAVL(monArbre1, monArbreCopie),
           egalAVL(monArbreCopie, monArbre1));

    monArbreCopie = supprimerAVL(monArbreCopie);
    monArbre1 = supprimerAVL(monArbre1);
    monArbre2 = supprimerAVL(monArbre2);
}

/* ------------------------------------------------------------------------ */
void	test_supprimer1EltAVL(void)
{
    noeudAVL_t *a = NULL;
    int i, nb, e;
    elt_t Val;
    
    //while(printf(PROMPT), scanf("%d", &nb))
    //{
        /*for (i = 0; i < nb; i++) {
            e = 1 + rand() % nb;
            insererAVL(e, &a);
        }*/

    insererAVL(10,&a);
    insererAVL(5,&a);
    insererAVL(15,&a);
    insererAVL(12,&a);
    insererAVL(13,&a);
    insererAVL(11,&a);
    insererAVL(3,&a);
    insererAVL(9,&a);
        afficherAVL(a);
        creerDotAVL(a,"supprimer_origin_");
        
        while (printf("\nQuelle valeur faut-il supprimer (. pour arreter) ? "), scanf("%d", &Val))
        {
            a = supprimer1EltAVL(Val, a);
            afficherAVL(a);
            creerDotAVL(a,"supprimer_tempo_");
        }
        while (getchar() != '\n');
        a = supprimerAVL(a);
    //}
    //while (getchar() != '\n');
    
}

/* ------------------------------------------------------------------------ */
void    test_chercherMinAVL(void)
{
    printf("Test de chercherMinAVL()\n---------------------\n");

    printf("On vérifie qu'un arbre vide renvoie une valeur d'erreur (ici 1024).\n");
    printf("chercherMinAVL(NULL) == %d\n", chercherMinAVL(NULL));

    noeudAVL_t *monArbre = NULL;
    printf("On effectue une dizaine d'insertions dans monArbre. Affichage de monArbre :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        insererAVL(1 + rand() % nb, &monArbre);
    afficherAVL(monArbre);

    printf("chercherMinAVL(monArbre) == %d\n", chercherMinAVL(monArbre));

    monArbre = supprimerAVL(monArbre);


}
/* ------------------------------------------------------------------------ */
void	test_creerDotPng(void)
{
    noeudAVL_t * a = NULL;
    unsigned int i;
    unsigned int nb;
    unsigned int val;
    
    /*while(printf("Nombre d'insertions dans l'ABR (. pour terminer) : "), scanf("%d", &nb))
    {
        for (i = 0; i < nb; )
        {
            val = 1 + rand() % nb;
            if (! estDansAVL(val, a))
            {
                a = insererAVL(val, a);
                creerDotAVL(a, "Abr");
                i++;
            }
        }
        a = supprimerAVL(a);
    }
    while (getchar() != '\n');*/
    /*a = creer1Noeud(3, NULL, NULL);
    GAUCHE(a) = creer1Noeud(2, creer1Noeud(1,NULL,NULL),NULL);
    DROITE(a) = creer1Noeud(4,NULL,creer1Noeud(5,NULL,NULL));
    afficherAVL(a);*/
    a = creer1Noeud(19, NULL, NULL);
    a->gauche = creer1Noeud(12,
                            NULL,
                            creer1Noeud(16,
                                        creer1Noeud(14, NULL, NULL),
                                        creer1Noeud(18, NULL, NULL)));
    a->droit  = creer1Noeud(34,
                            creer1Noeud(24,
                                        creer1Noeud(21, NULL, NULL),
                                        creer1Noeud(30, NULL, NULL)
                            ),
                            NULL);
    //a=insererAVL(17,a);

    printf("On crée l'image PNG de l'arbre suivant :\n");
    afficherAVL(a);
    creerDotAVL(a, "testFinal");

    a = supprimerAVL(a);
}


void    test_insererAVL_v2(void)
{
    AVL_t a = NULL;
    int elt = 0;
    do{
        printf("Quel élément voulez-vous insérer dans l'arbre (0 pour arrêter) ?\n");
        scanf("%d",&elt);
        if( elt != 0) {
            insererAVL(elt, &a);
            afficherAVL(a);
            creerDotAVL(a,"test_inserer_v2_");
        }
    }while( elt != 0);

    a=supprimerAVL(a);
}
