/**
 *  \file       AVL.h
 *  \brief      Spécification d'un module de gestion d'arbres binaires
 *              de recherche H-Equilibré
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */

#ifndef _AVL_H_
#define _AVL_H_

/* ------------------------------------------------------------------------ */
/**
 *  \typedef    elt_t
 *  \brief      Définition de la nature de l'information portée par
 *              les noeuds de l'AVL.
 *              Ici c'est un entier.
 */
typedef int elt_t;
/* ------------------------------------------------------------------------ */

/**
 *  \typedef    T_Noeud
 *  \brief      Définition du type des noeuds qui composent les AVLs
 */
typedef struct noeudAVL noeudAVL_t;
/* ------------------------------------------------------------------------ */


/**
 *  \struct     noeudAVL
 *  \brief      Définition de la structure d'un noeud
 */
struct noeudAVL
{
    /** facteur de déséquilibre. balance = hauteur(ssarbreGAUCHE) - hauteur(ssarbreARBRE)*/
    int balance;
    /**         L'information enregistrée dans le noeudAVL         */
    elt_t elt ;
    /**         Le pointeur sur le sous arbre gauche            */
    struct noeudAVL * gauche ;
    /**         Le pointeur sur le sous arbre droit            */
    struct noeudAVL * droit ;
};

typedef noeudAVL_t* AVL_t ;

/* ------------------------------------------------------------------------ */

/**
 * \def MAX(a,b)
 * \brief Permet d'obtenir la valeur maximale entre a et b.
 * \param a Opérande de gauche, doit être comparable à b.
 * \param b Opérande de droite, doit être comparable à a.
 * \return a si a est supérieur ou égal à b, b sinon.
 */
#define	MAX(a,b)	(((a) >= (b)) ? (a) : (b))


/**
 * \def MIN(a,b)
 * \brief Permet d'obtenir la valeur minimale entre a et b.
 * \param a Opérande de gauche, doit être comparable à b.
 * \param b Opérande de droite, doit être comparable à a.
 * \return a si a est inférieur ou égal à b, b sinon.
 */
#define	MIN(a,b)	(((a) <= (b)) ? (a) : (b))


/**
 * \def ABS(a)
 * \brief Renvoie la valeur absolue d'un réel.
 * \param le réel.
 * \return sa valeur absolue.
 */
#define ABS(a) ( ( (a)<0 ) ? (-(a)) : (a) )

/**
 * \def VIDE(noeud)
 * \brief Permet de savoir si un noeud de l'arbre est vide ou non.
 * \param noeud Le noeud de l'arbre
 * \return 1 si le noeud est vide, 0 sinon.
 */
#define VIDE(noeud) ((noeud)==NULL)


/**
 * \def PASVIDE(noeud)
 * \brief Permet de savoir si un noeud de l'arbre est vide ou non.
 * \param noeud Le noeud de l'arbre
 * \return 1 si le noeud n'est pas vide, 0 sinon.
 */
#define PASVIDE(noeud) ((noeud) != NULL)


/**
 * \brief Définit la hauteur de déséquilibre maximum d'un AVL0
 */
#define FACTEUR_DESEQUILIBRE_MAX 2


/**
 * \def DESEQUILIBRE(arbre)
 * \brief Permet de savoir si un AVL est H-déséquilibré ou non.
 * \param noeud Le noeud de l'arbre
 * \return 1 si le noeud est vide, 0 sinon.
 */
#define DESEQUILIBRE(arbre) ( BALANCE( (arbre) ) <= -FACTEUR_DESEQUILIBRE_MAX || FACTEUR_DESEQUILIBRE_MAX <= BALANCE( (arbre) ) )

/**
 * \def GAUCHE(noeud)
 * \brief Permet d'obtenir le sous arbre gauche du noeud.
 * \param noeud Le noeud de l'arbre
 * \return le sous arbre gauche du paramètre noeud.
 */
#define GAUCHE(noeud) ((noeud)->gauche)


/**
 * \def DROITE(noeud)
 * \brief Permet d'obtenir le sous arbre droit du noeud.
 * \param noeud Le noeud de l'arbre
 * \return le sous arbre droit du paramètre noeud.
 */
#define DROITE(noeud) ((noeud)->droit)


/**
 * \def EST_FEUILLE(noeud)
 * \brief Permet de savoir si le noeud actuel est une feuille de l'arbre.
 * \param noeud Le noeud de l'arbre
 * \return 1 si le noeud ne contient pas de sous arbre, 0 sinon.
 */
#define EST_FEUILLE(noeud) ( (noeud)->droit == NULL && (noeud)->gauche == NULL)


/**
 * \def BALANCE(noeud)
 * \brief Permet d'obtenir la balance du noeud.
 * \param noeud Le noeud de l'arbre
 * \return la balance du noeud
 */
#define BALANCE(noeud) ((noeud)->balance)


/**
 * \def RACINE(noeud)
 * \brief Permet d'obtenir l'élément de la racine du noeud.
 * \param noeud Le noeud de l'arbre
 * \return l'élément de la racine du noeud
 */
#define RACINE(noeud) ((noeud)->elt)

/* ------------------------------------------------------------------------ */

/****************************************************************************
 *      F O N C T I O N S    D' A C C E S                                   *
 ****************************************************************************/

/**
 *  \brief      Permet d'afficher le contenu d'un AVL.
 *              Le parcours effectué est de type GRD (infixé)
 *  \param      arbre   le pointeur sur l'AVL
 *  \return		néant
 *  \note       Un saut de ligne est effectué à la fin de l'affichage
 */
void afficherAVL(const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Permet d'afficher le contenu d'un AVL.
 *              Le parcours effectué est de type GDR (postfixé)
 *  \param      arbre   le pointeur sur l'AVL
 *  \return     néant
 *  \note       Un saut de ligne est effectué à la fin de l'affichage
 */
void afficherInverseAVL(const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Calcule le nombre de noeuds d'un AVL.
 *  \param      arbre   le pointeur sur l'AVL
 *  \return    le nombre d'éléments de l'AVL
 */
unsigned int nbNoeudsAVL(const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Détermine si l'élément e est dans l'arbre
 *  \param      e       l'élément recherché
 *  \param      arbre   le pointeur sur la racine de l'AVL
 *  \return     0 si e n'est pas dans l'arbre ou 1 s'il est présent
 */
int   estDansAVL(elt_t e, const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */


/****************************************************************************
 *      F O N C T I O N S    D E    M O D F I C A T I O N  D' U N           *
 *         A R B R E   B I N A I R E   D E   R E C H E R C H E              *
 ****************************************************************************/


/**
 *  \brief      Permet de créer un nouveau noeudAVL d'AVL, et
 *              d'intialiser ses 3 composantes
 *  \param      e   la valeur d'initialisation de l'élément
 *  \param      g   la valeur d'initialisation du pointeur gauche du noeud
 *  \param      d   la valeur d'initialisation du pointeur droite du noeud
 *  \return    La pointeur sur le nouveau noeudABR ou NULL si l'allocation
 *              mémoire échoue.
 */
noeudAVL_t * creer1Noeud (elt_t e, noeudAVL_t * g, noeudAVL_t * d);


/**
 *  \brief      Permet d'insérer un élément dans un AVL
 *  \param      arbre       le pointeur sur l'AVL
 *  \param      e           l'élément à insérer
 *  \return     -1 ou 1 s'il y a eu variation de la hauteur, 0 sinon.
 *  \note       arbre peut désigner un arbre vide.
 *  \note       Utilise <b>creer1Noeud</b>
 *	\note		l'insertion n'est pas réalisée si la valeur est déjà
 *				présente dans l'arbre.
 */
int insererAVL(elt_t e, AVL_t *a);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Crée une copie d'un AVL
 *  \param      arbre    le pointeur sur la racine de l'arbre
 *  \return     le pointeur sur la racine de la copie
 *  \note       arbre peut désigner un arbre vide. Dans ce cas
 *              elle retourne simplement NULL
 *  \note       Utilise <b>insererABR</b>
 */
noeudAVL_t * copierAVL(const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Permet de supprimer un AVL et de
 *              récupérer tout l'espace mémoire qu'il occupait
 *  \param      arbre    le pointeur sur la racine de l'arbre
 *  \return    NULL
 *  \note       arbre peut désigner un arbre vide. Dans ce cas
 *              elle retourne simplement NULL
 */
noeudAVL_t * supprimerAVL(noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */


/**
 *  \brief      Renvoie la plus petite valeur de l'arbre passé en paramètre.
 *  \param      arbre   le pointeur sur la racine de l'arbre
 *  \return     le plus petit élément de l'arbre s'il n'est pas vide, 1024 sinon.
 */
elt_t chercherMinAVL(noeudAVL_t *pRac);


/**
 *  \brief      Permet de supprimer un élément d'un AVL et de
 *              récupérer tout l'espace mémoire qu'il occupait
 *  \param      e       l'élément à supprimer
 *  \param      pRac  L'arbre
 *  \return     l'arbre après suppression.
 *  \note       si e n'est pas dans l'arbre alors elle retourne
 *              le pointeur sur sa racine.
 */
AVL_t supprimer1EltAVL(elt_t e, AVL_t pRac);


/****************************************************************************
 *      F O N C T I O N S    U T I L E S   S U R   A R B R E S              *
 *           B I N A I R E S   D E   R E C H E R C H E                      *
 ****************************************************************************/

/**
 *  \brief      Détermine la hauteur d'un AVL
 *  \param      arbre   l'AVL dont on détermine la hauteur
 *  \return    la hauteur de l'arbre
 *  \note       Un arbre vide a une hauteur égale à -1
 */
int hauteurAVL(const noeudAVL_t *arbre);
/* ------------------------------------------------------------------------ */

/**
 *  \brief      Détermine si deux arbres sont identiques
 *  \param      arbre1  le 1er arbre binaire
 *  \param      arbre2  le second arbre binaire
 *  \return		true s'ils sont égaux, false sinon.
 */
int egalAVL(const noeudAVL_t *arbre1, const noeudAVL_t *arbre2);
/* ------------------------------------------------------------------------ */

/**
 *  \fn         int isomorpheABR(const noeudABR_t * arbre1, const noeudABR_t * arbre2)
 *  \brief      Détermine si deux arbres sont de même forme
 *  \param      arbre1  le 1er arbre binaire
 *  \param      arbre2  le second arbre binaire
 *  \return    1 s'ils ont même forme, 0 sinon.
 */
int isomorpheABR (const noeudAVL_t * arbre1, const noeudAVL_t * arbre2);
/* ------------------------------------------------------------------------ */

/**
 * \brief Génère un fichier dot et png, permettant d'afficher un arbre binaire de recherche en 2D.
 * \param arbre L'arbre à afficher.
 * \param basename Le nom des fichiers créés.
 */
void creerDotAVL(const noeudAVL_t *arbre, const char *basename);

// TP4
AVL_t rotationGauche(AVL_t a);
AVL_t rotationDroite(AVL_t a);
AVL_t equilibrer(AVL_t a);

#endif

