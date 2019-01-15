/* ------------------------------------------------------------------------ */
/**
 *  \file       tp4.h
 *  \brief      Fichiers contenant des déclarations utilisées dans
 *				les autres fichiers du projet
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */
/* ------------------------------------------------------------------------ */

#ifndef	__TP4_H_
#define __TP4_H_

/* ------------------------------------------------------------------------ */
/*      C O N S T A N T E S   S Y M B O L I Q U E S                         */
/* ------------------------------------------------------------------------ */

/**
 *  \def        MAXLEN
 *  \brief      Longueur maxiamle des phrases lues au clavier et traitées
 *				dans ce programme
 */
#define MAXLEN	255


/**
 *  \def        _TEST_
 *  \brief		Constante symbolique contrôlant l'affichage d'informations
 *				de test si sa valeur est non nulle.
 *
 */
#define _TEST_		1
/* ------------------------------------------------------------------------ */

/**
 *  \def        DOSSIER_PNG
 *  \brief		Constante symbolique désignant le nom du dossier destiné
 *				à contenir les fichiers .png générés par le programme
 *
 */
#define	DOSSIER_PNG	"./Png/"

/**
 *  \def        DOSSIER_DOT
 *  \brief		Constante symbolique désignant le nom du dossier destiné
 *				à contenir les fichiers .dot générés par le programme
 *
 */
#define	DOSSIER_DOT	"./Dot/"


/**
 *  \def        DOT_CMD
 *  \brief		Constante symbolique désignant le nom de la commande
 *				permettant de produire le fichier .png à partir du
 *				fichier .dot
 *
 */
#define	DOT_CMD		"dot"


/* ------------------------------------------------------------------------ */

#ifndef false
#define false	(0)
#endif

#ifndef true
#define	true	(~0)
#endif

void prologue (void);

#endif
/* ------------------------------------------------------------------------ */
