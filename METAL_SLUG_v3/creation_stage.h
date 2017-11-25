#ifndef CREATION_STAGE_H_INCLUDED
#define CREATION_STAGE_H_INCLUDED

#include"creation_personnages.h"
#include"creation_projectils.h"
#include <SDL/SDL_image.h>
typedef struct        {
                       SDL_Surface* background_image;
                       SDL_Rect position_background;
                       SDL_Rect camera;
                       SDL_Rect ancienne_camera;
                       int y_relative;
                       int vitesse_camera;
                       int blocage_camera;
                       int debut_compteur_camera;
                     }stage;
void creer_stage(stage *un_stage);
void decalage_camera_droite(personnage *un_joueur);
void decalage_camera_gauche(personnage *un_joueur);
void decalage_camera_droite_cartouches(cartouche *un_joueur);
void decalage_camera_gauche_cartouches(cartouche *un_joueur);

#endif // CREATION_STAGE_H_INCLUDED
