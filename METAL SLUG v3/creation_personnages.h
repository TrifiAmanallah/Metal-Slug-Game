#ifndef CREATION_PERSONNAGES_H_INCLUDED
#define CREATION_PERSONNAGES_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct {
                           SDL_Rect position;
                           SDL_Rect ancienne_position;
                           SDL_Surface *sprites_droite;
                           SDL_Surface *sprites_gauche;
                           SDL_Surface *sprites_cartouche_droite;
                           SDL_Surface *sprites_cartouche_gauche;
                           SDL_Surface *sprites_complementaires;///sprites pour la mort par cartouch
                           SDL_Surface *sprites_complementaires_2;///sprites pour la mort par brulure
                           int dernier_deplacement_horizontale;//0:droite//1::gauche//
                           int vitesse_deplacement;
                           int index_sprite_attente;
                           int index_sprite_droite;
                           int index_sprite_gauche;
                           int index_sprite_bas;
                           int index_sprite_saut;
                           int index_sprite_tire;
                           int index_sprite_mort;
                           int index_sprite_explosion;
                           int index_sprite_mort_noyade;
                           int FPS_deplacement;
                           int FPS_attente;
                           int FPS_bas;
                           int FPS_tire;
                           int FPS_recharge;
                           int FPS_saut;
                           int FPS_mort;
                           int MAX_affichage_cartouches;
                           int nbr_de_sprites;
                           int affichage;
                           int collusion_cartouche;
                           int hauteur_saut;
                           int mort; /// joueur mort=1 ou vivant=0
                           int mort_brulure;
                           int contact_avec_le_sol;
                           SDL_Rect ciseau_droite[67];
                           SDL_Rect ciseau_gauche[67];
                          } personnage;

void creer_joueur(personnage *);
void creer_ennemi_1(personnage *joueur);
void creer_ennemi_bazouka(personnage *joueur);
void supprimer_ennemi(personnage *joueur);
void creer_ennemi_arabian(personnage *joueur);
void creer_ennemi_sniper(personnage *joueur);
void creer_ennemi_soldat_blinde(personnage *joueur);
 void creer_ennemi_boss(personnage *joueur);
#endif // CREATION_PERSONNAGES_H_INCLUDED
