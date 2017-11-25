#ifndef CREATION_PROJECTILS_H_INCLUDED
#define CREATION_PROJECTILS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "creation_personnages.h"
/////////////////////////////////////////////////////////
typedef struct{
SDL_Rect position;
SDL_Rect ancienne_position;
int deplacement_horizontale; //0::droite//1::gauche
SDL_Surface *sprite_droite;
SDL_Surface *sprite_gauche;
int objet_touche;
} cartouche;

//////////////////////////////////////////////////////////
void initialiser_cartouches(personnage,cartouche *);
void ajouter_cartouche(personnage,cartouche * );
void deplacement_cartouche(personnage,cartouche *,SDL_Surface **,Uint32*);
void deplacement_cartouche_bazouka(personnage,cartouche *,SDL_Surface **,Uint32*);
void supprimer_cartouche(cartouche **cartouche_personnage,int index_cartouche,int nbr_cartouches);
void ajouter_cartouche_boss(personnage joueur,cartouche *cartouche_personnage);
#endif // CREATION_PROJECTILS_H_INCLUDED
