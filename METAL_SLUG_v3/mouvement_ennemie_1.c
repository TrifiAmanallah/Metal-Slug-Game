#include "creation_personnages.h"
#include"creation_stage.h"
#include"creation_projectils.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

void ennemie_talkiwalki(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;

if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=15) (*joueur).index_sprite_attente=0;
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
/////////////////////////////////////////////////////////////////////////////////////
void grande_explosion (personnage *joueur,SDL_Rect *position_explosion,SDL_Rect *ancienne_position_explosion,stage *stage_x,SDL_Surface **screen,Uint32 *start,int*fin_explosion){

(*position_explosion).x=(*ancienne_position_explosion).x-(*stage_x).camera.x;

if(150<SDL_GetTicks()-*start){(*joueur).index_sprite_explosion++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_explosion>=67) {(*joueur).index_sprite_explosion=47;
                                                *fin_explosion=1;}
       if(*fin_explosion==0) SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_explosion],*screen,&(*position_explosion));

}
///////////////////////////////////////////////////////////////////////////////////
void mort_ennemie(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_mort++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort==26)  (*joueur).collusion_cartouche=0;
      if((*joueur).index_sprite_mort>=30) {(*joueur).index_sprite_mort=29;
                                           (*joueur).affichage=0;}
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_complementaires,&(*joueur).ciseau_droite[(*joueur).index_sprite_mort],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_complementaires,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort],*screen,&(*joueur).position);


      }
/////////////////////////////////////////////////////////////////////////////////
void mort_ennemie_brulure(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
(*joueur).position.y=(*joueur).ancienne_position.y-20;
if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_mort++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort>=52) {(*joueur).index_sprite_mort=51;
                                           (*joueur).affichage=0;}
            SDL_BlitSurface((*joueur).sprites_complementaires_2,&(*joueur).ciseau_droite[(*joueur).index_sprite_mort],*screen,&(*joueur).position);
      }
////////////////////////////////////////////////////////////////////////////////
void attente_ennemie_toure(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){

(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=4) (*joueur).index_sprite_attente=0;
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
if((*joueur).position.y<=227+110)
{ SDL_Surface *tour=IMG_Load("images/toure.png");
  SDL_Rect tour_position;
  tour_position.x=637;
  tour_position.y=108+110;
  tour_position.x=tour_position.x-(*stage_x).camera.x;
  SDL_BlitSurface(tour,NULL,*screen,&tour_position);
}
      }
///////////////////////////////////////////////////////////////////////////////////////////////
void tire_ennemie_bazouka(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *debut_cartouche){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_tire<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_tire==20) *debut_cartouche=1;
      if((*joueur).index_sprite_tire>=20) (*joueur).index_sprite_tire=17;
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_tire],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&(*joueur).position);
if((*joueur).position.y<=227+110)
{ SDL_Surface *tour=IMG_Load("images/toure.png");
  SDL_Rect tour_position;
  tour_position.x=637;
  tour_position.y=108+110;
  tour_position.x=tour_position.x-(*stage_x).camera.x;
  SDL_BlitSurface(tour,NULL,*screen,&tour_position);
}

      }
///////////////////////////////////////////////////////////////////////////////////////
void attente_ennemie_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;

if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=6) (*joueur).index_sprite_attente=0;
SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
/////////////////////////////////////////////////////////////////////////////////////////
void mort_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
SDL_Rect nouvelle_position;
nouvelle_position.y=(*joueur).ancienne_position.y-5;
nouvelle_position.x=(*joueur).position.x;

if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_mort++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort==15) (*joueur).collusion_cartouche=0;
      if((*joueur).index_sprite_mort>=26) {(*joueur).index_sprite_mort=6;
                                           (*joueur).affichage=0;}
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort],*screen,&nouvelle_position);


      }
///////////////////////////////////////////////////////////////////////////////////////
void courir_ennemie_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){

(*joueur).position.x-=1;
if((*joueur).FPS_deplacement<SDL_GetTicks()-*start){(*joueur).index_sprite_gauche++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_gauche>=38) (*joueur).index_sprite_gauche=26;
SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_gauche],*screen,&(*joueur).position);
      }
/////////////////////////////////////////////////////////////////////////////////////
void attaque_arabian(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
SDL_Rect nouvelle_position;
nouvelle_position.y=(*joueur).position.y-5;
nouvelle_position.x=(*joueur).position.x-(*stage_x).camera.x+(*stage_x).debut_compteur_camera;

if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_tire==41) (*joueur).contact_avec_le_sol=0;///l'attaque est prise en compte
      if((*joueur).index_sprite_tire>=41) (*joueur).index_sprite_tire=0;
      if((*joueur).index_sprite_tire==5)  (*joueur).index_sprite_tire=0;
      if((*joueur).index_sprite_tire>=0&&(*joueur).index_sprite_tire<=5) {nouvelle_position.x=(*joueur).position.x-(*stage_x).camera.x+(*stage_x).debut_compteur_camera+40;
                                                                            nouvelle_position.y=(*joueur).position.y-5;}

            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&nouvelle_position);


      }
//////////////////////////////////////////
void mort_joueur(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.y=(*joueur).ancienne_position.y-10;
if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_mort++;
                                              (*joueur).position.x=(*joueur).ancienne_position.x-20;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort==54) (*joueur).collusion_cartouche=0;
      if((*joueur).index_sprite_mort>=57) {(*joueur).index_sprite_mort=56;
                                           (*joueur).affichage=0;}
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_complementaires,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_complementaires,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort],*screen,&(*joueur).position);


      }
//////////////////////////////////////////////////////////////////////////////////////
void attente_ennemie_sniper(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;

if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=4) (*joueur).index_sprite_attente=0;
SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
/////////////////////////////////////////////////////////////////////////////////////////
void tire_ennemie_sniper(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *debut_cartouche){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_tire<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_tire==6) *debut_cartouche=1;
      if((*joueur).index_sprite_tire>=7) (*joueur).index_sprite_tire=0;
      SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&(*joueur).position);
}
///////////////////////////////////////////////////////////////////////////////////////
void attente_blinde(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=6) (*joueur).index_sprite_attente=0;

            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
 void attaque_blinde(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
 (*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
 if((*joueur).FPS_tire<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_tire==8) (*joueur).contact_avec_le_sol=0;///l'attaque est prise en compte
      if((*joueur).index_sprite_tire>=10) (*joueur).index_sprite_tire=6;

            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&(*joueur).position);


      }
 ///////////////////////////////////////////////////////////////////////
 void attente_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=5) (*joueur).index_sprite_attente=0;
      SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
 ////////////////////////////////////////////////////////////////////////
 void tire_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,int *debut_cartouche){
SDL_Rect rectificateur;
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
rectificateur=(*joueur).position;
rectificateur.y=(*joueur).position.y-20;
rectificateur.x=(*joueur).position.x-50;
if((*joueur).FPS_tire<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_tire==5) *debut_cartouche=1;
      if((*joueur).index_sprite_tire>=9) (*joueur).index_sprite_tire=5;
      SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&rectificateur);
}
//////////////////////////////////////////////////////////////////////////////////
void mort_boss(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.x=(*joueur).ancienne_position.x-(*stage_x).camera.x;
if((*joueur).FPS_mort<SDL_GetTicks()-*start){(*joueur).index_sprite_mort++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort==13)  (*joueur).collusion_cartouche=0;
      if((*joueur).index_sprite_mort>=14) {(*joueur).index_sprite_mort=14;
                                           (*joueur).affichage=0;}
      SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort],*screen,&(*joueur).position);


      }
///////////////////////////////////////////////////////////////////////////////////
void noyade_joueur(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start,SDL_Rect position){
if(400<SDL_GetTicks()-*start){(*joueur).index_sprite_mort_noyade++;
                                                     *start=SDL_GetTicks();}
      if((*joueur).index_sprite_mort_noyade>=61) {(*joueur).index_sprite_mort_noyade=60;
                                                  (*joueur).affichage=0;}
            SDL_BlitSurface((*joueur).sprites_complementaires,&(*joueur).ciseau_gauche[(*joueur).index_sprite_mort_noyade],*screen,&position);
      }
//////////////////////////////////////////////////////////////////////////////////
void descente_terminator(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
(*joueur).position.y++;
if((*joueur).FPS_attente<SDL_GetTicks()-*start){(*joueur).index_sprite_attente++;
                                                     *start=SDL_GetTicks();
                                                                                              }
           if((*joueur).index_sprite_attente>=4) (*joueur).index_sprite_attente=0;
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
//////////////////////////////////////////////////////////////////////////////////
void attaque_terminator(personnage *joueur,stage *stage_x,SDL_Surface **screen,Uint32 *start){
SDL_Rect rectificateur;

rectificateur=(*joueur).position;
if((*joueur).FPS_tire<SDL_GetTicks()-*start){(*joueur).index_sprite_tire++;
                                                     *start=SDL_GetTicks();}
           if((*joueur).index_sprite_tire>=22) (*joueur).index_sprite_tire=5;
           if(15<=(*joueur).index_sprite_tire) rectificateur.x=(*joueur).position.x-60;
           if(15==(*joueur).index_sprite_tire) rectificateur.y=(*joueur).position.y-12;


            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&rectificateur);
      }
