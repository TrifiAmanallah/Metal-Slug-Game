#ifndef MOUVEMENT_ENNEMIE_1_H_INCLUDED
#define MOUVEMENT_ENNEMIE_1_H_INCLUDED

void ennemie_talkiwalki(personnage *,stage *,cartouche **,SDL_Surface **);
void attente_ennemie_toure(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void tire_ennemie_bazouka(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *);
void mort_ennemie(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void mort_ennemie_brulure(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void mort_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void grande_explosion (personnage *joueur,SDL_Rect *position_explosion,SDL_Rect *ancienne_position_explosion,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *fin_explosion);
void attente_ennemie_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void courir_ennemie_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void attaque_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void mort_joueur(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void attente_ennemie_sniper(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void tire_ennemie_sniper(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *debut_cartouche);
void attente_blinde(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void attaque_blinde(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void attente_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void tire_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *debut_cartouche);
void mort_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void noyade_joueur(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,SDL_Rect position);
void attaque_terminator(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
void descente_terminator(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start);
#endif // MOUVEMENT_ENNEMIE_1_H_INCLUDED
