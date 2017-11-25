#include "creation_personnages.h"
#include"creation_stage.h"
#include"clavier.h"
#include"creation_projectils.h"
/////////////////////////////////////////////////////////////////////////////////
void deplacement_personnage(personnage *joueur,stage *stage_x,cartouche **joueur_cartouche,SDL_Surface **screen){
int exit_stage=0,appui_haut=0,appui_bas=0,appui_droite=0,appui_gauche=0,appui_saut=0,appui_tire=0,appui_grenade=0;
int attente_tire=0,nbr_tirs=0,attente_saut=0,hauteur_saut=70,descente_saut=0;
int debut_cartouche=0,nbr_cartouches=0;
int i,test=0;
Uint32 start=SDL_GetTicks();
Uint32 start_cartouche=SDL_GetTicks();
Uint32 starts_cartouche [10] ={SDL_GetTicks()};

while(!exit_stage){
gestion_clavier(&exit_stage,&appui_haut,&appui_bas,&appui_droite,&appui_gauche,&appui_saut,&appui_tire,&appui_grenade);
SDL_BlitSurface((*stage_x).background_image,&(*stage_x).camera,*screen,&(*stage_x).position_background);


if(appui_droite&&!attente_saut){
                  (*joueur).position.y=(*joueur).ancienne_position.y;
                  (*joueur).ancienne_position=(*joueur).position;
                  (*joueur).dernier_deplacement_horizontale=0;
                  (*joueur).position.x+=(*joueur).vitesse_deplacement;
                  (*stage_x).camera.x+=(*stage_x).vitesse_camera;
                  if((*joueur).position.x<200){(*joueur).vitesse_deplacement=1;
                                            (*stage_x).vitesse_camera=0;}
                                      else {(*joueur).vitesse_deplacement=0;
                                            (*stage_x).vitesse_camera=1;}
                   if((*joueur).FPS_deplacement<SDL_GetTicks()-start){(*joueur).index_sprite_droite++;
                                                                       start=SDL_GetTicks();}
                  if ((*joueur).index_sprite_droite>=11) (*joueur).index_sprite_droite=3;
                  SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_droite],*screen,&(*joueur).position);
                 }
else if(appui_gauche&&!attente_saut) {
                  (*joueur).position.y=(*joueur).ancienne_position.y;
                  (*joueur).ancienne_position=(*joueur).position;
                  (*joueur).dernier_deplacement_horizontale=1;
                  (*joueur).position.x-=(*joueur).vitesse_deplacement;
                  (*stage_x).camera.x-=(*stage_x).vitesse_camera;
                  if((*joueur).position.x>600){(*joueur).vitesse_deplacement=1;
                                            (*stage_x).vitesse_camera=0;}
                                      else {(*joueur).vitesse_deplacement=0;
                                            (*stage_x).vitesse_camera=1;}
                   if((*joueur).FPS_deplacement<SDL_GetTicks()-start){(*joueur).index_sprite_gauche++;
                                                                      start=SDL_GetTicks();}
                  if ((*joueur).index_sprite_gauche>=11) (*joueur).index_sprite_gauche=3;
                  SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_gauche],*screen,&(*joueur).position);
                 }
else if(appui_bas&&!attente_saut){
                   if((*joueur).FPS_bas<SDL_GetTicks()-start){(*joueur).index_sprite_bas++;
                                                                        start=SDL_GetTicks();}
                   if ((*joueur).index_sprite_bas>12)(*joueur).position.y=(*joueur).ancienne_position.y+16;
                   if ((*joueur).index_sprite_bas>=16) (*joueur).index_sprite_bas=13;
                   if((*joueur).dernier_deplacement_horizontale==0)
                        SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_bas],*screen,&(*joueur).position);
                   else
                         SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_bas],*screen,&(*joueur).position);
                   }
else if((appui_tire||attente_tire)&&!attente_saut){
                     attente_tire=1;
                    (*joueur).position.y=(*joueur).ancienne_position.y;
                     if((*joueur).FPS_recharge<SDL_GetTicks()-start){(*joueur).index_sprite_tire++;
                                                                     start=SDL_GetTicks();}
                     if((*joueur).dernier_deplacement_horizontale==0)
                                         SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_tire],*screen,&(*joueur).position);
                                       else
                                         {SDL_Rect position_personnage_gauche=(*joueur).position;
                                         if((*joueur).index_sprite_tire<=17) position_personnage_gauche.x=(*joueur).position.x-(*joueur).ciseau_gauche[(*joueur).index_sprite_tire].w/2.5;
                                         else position_personnage_gauche.x=(*joueur).position.x-7;
                                         SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_tire],*screen,&position_personnage_gauche);}
                     if(nbr_tirs==5){
                                     if((*joueur).index_sprite_tire>=35) {(*joueur).index_sprite_tire=16;
                                                                         nbr_tirs=0;
                                                                         attente_tire=0;}
                                    }
                     else          {
                                    if((*joueur).index_sprite_tire>=20) {(*joueur).index_sprite_tire=16;
                                                                         nbr_tirs++;
                                                                         attente_tire=0;}
                                   }
                 }
else if(appui_saut||attente_saut){

                    if(10<SDL_GetTicks()-start){(*joueur).index_sprite_saut++;
                                                 start=SDL_GetTicks();}
                    if(appui_droite&&!attente_saut){}//5edmet SLIM HMIDI
               else if(appui_gauche&&!attente_saut){}//5edmet SLIM HMIDI
               else {
                     attente_saut=1;
                    if(descente_saut==0) {if ((*joueur).index_sprite_saut>=41)(*joueur).index_sprite_saut=40;
                                          (*joueur).position.y--;
                                          if((*joueur).ancienne_position.y-(*joueur).position.y>=hauteur_saut) descente_saut=1;
                                         }
                    if(descente_saut==1) {if ((*joueur).index_sprite_saut>=44) (*joueur).index_sprite_saut=43;
                                         (*joueur).position.y++;
                                         if((*joueur).ancienne_position.y-(*joueur).position.y<1) {descente_saut=0;
                                                                                                   attente_saut=0;}
                                         }
                    }
                    if((*joueur).dernier_deplacement_horizontale==0)
                          SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_saut],*screen,&(*joueur).position);
                    else
                          SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_saut],*screen,&(*joueur).position);
}
else if(appui_grenade&&!attente_saut){}
else {
      (*joueur).index_sprite_saut=35;
      (*joueur).index_sprite_bas=11;
      (*joueur).position.y=(*joueur).ancienne_position.y;
      if((*joueur).FPS_attente<SDL_GetTicks()-start){(*joueur).index_sprite_attente++;
                                                     start=SDL_GetTicks();}
      if((*joueur).index_sprite_attente>=3) (*joueur).index_sprite_attente=0;
      if((*joueur).dernier_deplacement_horizontale==0)
            SDL_BlitSurface((*joueur).sprites_droite,&(*joueur).ciseau_droite[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
        else
            SDL_BlitSurface((*joueur).sprites_gauche,&(*joueur).ciseau_gauche[(*joueur).index_sprite_attente],*screen,&(*joueur).position);
      }
 if((*joueur).index_sprite_tire==18&&!test){debut_cartouche=1;

                                      if(nbr_cartouches>=(*joueur).MAX_affichage_cartouches)nbr_cartouches=0;
                                      ajouter_cartouche((*joueur),&joueur_cartouche[nbr_cartouches]);
                                      nbr_cartouches++;
                                      test=1;
                                          }
 if((*joueur).index_sprite_tire==19) test=0;
 if(debut_cartouche){
   for(i=0;i<nbr_cartouches;i++)
   deplacement_cartouche((*joueur),&joueur_cartouche,&(*screen),&starts_cartouche[i],i);

                    }
SDL_Flip(*screen);
}
}
