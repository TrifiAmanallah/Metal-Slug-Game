#ifndef GESTION_COLLUSIONS_H_INCLUDED
#define GESTION_COLLUSIONS_H_INCLUDED

void gestion_camera(stage *stage_x,int* blocage);
void limite_cartouches(cartouche *joueur_cartouche,personnage joueur);
void collusion_cartouche_ennemie(cartouche *joueur_cartouche,personnage *ennemie);
void collusion_cartouche_boss(cartouche *joueur_cartouche,personnage *ennemie);
void collusion_personnage_sol(personnage *joueur,stage stage_x);
void collusion_cartouche_porte(cartouche *joueur_cartouche,SDL_Rect position_porte,int *porte_ouverte);
void collusion_explosion_personnages(SDL_Rect position_explosion,personnage *ennemie);
void collusion_joueur_ennemie(personnage *joueur,personnage *ennemie,stage *);
void collusion_joueur_boss(personnage *joueur,personnage *ennemie,stage *stage_x);
#endif // GESTION_COLLUSIONS_H_INCLUDED
