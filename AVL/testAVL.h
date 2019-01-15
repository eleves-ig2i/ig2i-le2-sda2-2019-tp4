/* ------------------------------------------------------------------------ */
/**
 *  \file       testAVL.h
 *  \brief      Spécification d'un module de test des fonction de gestion
 *				d'arbres binaires de recherche H-Equilibré
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */

#ifndef __TESTAVL_H__
#define __TESTAVL_H__
#include "AVL.h"

// Fonctions de test du TP3
void	test_afficherAVL(void);
void	test_afficherInverseAVL(void);
void	test_copierAVL(void);
void	test_egalAVL(void);
void	test_isomorpheABR(void);
void	test_estDansAVL(void);
void	test_supprimer1EltAVL(void);
void	test_creerDotPng(void);
void    test_chercherMinAVL(void);

// Fonctions de test du TP4
void	test_rotationGauche(void);
void	test_rotationDroite(void);
void    test_equilibrer(void);
void	test_insererAVL(void);
void	test_supprimer1EltAVL(void);
void    test_insererAVL_v2(void);
#endif
/* ----------------------------------------------------------- THE END ---- */
