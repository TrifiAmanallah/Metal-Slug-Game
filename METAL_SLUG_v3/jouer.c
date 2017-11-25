#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "chargements_SDL.h"
#include "creation_personnages.h"
#include "creation_stage.h"
#include"creation_projectils.h"
#include"mouvement_ennemie_1.h"
//////////////////////////////////////////////
void jouer(int *debut_stage,int *game_over){
///variables du jeu:
SDL_Surface *screen=NULL;
stage desert;
personnage leo;
personnage soldat_talkiwalki,soldat_bazouka,soldat_arabian,soldat_arabian_2,soldat_arabian_3,soldat_sniper,soldat_sniper_2,soldat_sniper_3,soldat_blinde,boss,terminator;
int blocage_camera=0;

///fonctions d'initialisation:
chargement_SDL(&screen);
creer_stage_1(&desert);
creer_joueur_1(&leo);
creer_ennemi_1(&soldat_talkiwalki);
creer_ennemi_arabian(&soldat_arabian);
creer_ennemi_arabian(&soldat_arabian_2);
creer_ennemi_arabian(&soldat_arabian_3);
creer_ennemi_sniper(&soldat_sniper);
creer_ennemi_sniper(&soldat_sniper_2);
creer_ennemi_sniper(&soldat_sniper_3);
creer_ennemi_soldat_blinde(&soldat_blinde);
creer_ennemi_boss(&boss);
creer_terminator(&terminator);
soldat_sniper_2.position.x=550;
soldat_sniper_2.ancienne_position.x=soldat_sniper_2.position.x;
soldat_sniper_2.position.y=225+110;
soldat_sniper_2.ancienne_position.y=soldat_sniper_2.position.y;
soldat_sniper_3.position.x=2230;
soldat_sniper_3.ancienne_position.x=soldat_sniper_3.position.x;
soldat_sniper_3.position.y=270+110;
soldat_sniper_3.ancienne_position.y=soldat_sniper_3.position.y;
soldat_arabian_2.position.x=1000;
soldat_arabian_2.ancienne_position.x=soldat_arabian_2.position.x;
soldat_arabian_3.position.x=1200;/////////////////////////////////////////////
soldat_arabian_3.ancienne_position.x=soldat_arabian_3.position.x;

///variables des personnages:
personnage joueur;
stage stage_x;
joueur=leo;
cartouche joueur_cartouche [joueur.MAX_affichage_cartouches];
stage_x=desert;
int test_cartouches=0;
/////////////////////////////////////////////
///variables pour deplacementdu joueur:
int exit_stage=0,appui_haut=0,appui_bas=0,appui_droite=0,appui_gauche=0,appui_saut=0,appui_tire=0,appui_grenade=0;
int attente_tire=0,nbr_tirs=0,attente_saut=0,hauteur_saut=70,descente_saut=0;
int debut_cartouche=0,nbr_cartouches=0;
int i,test=0;
Uint32 start=SDL_GetTicks();
Uint32 start_mort_joueur=SDL_GetTicks();
Uint32 starts_cartouche [30] ={SDL_GetTicks()};
//////////////////////////////////////////////////
///variables pour ennemies:
Uint32 start_talkiwalki=SDL_GetTicks();
Uint32 start_arabian=SDL_GetTicks();
Uint32 start_arabian_2=SDL_GetTicks();
Uint32 start_arabian_3=SDL_GetTicks();
Uint32 start_sniper=SDL_GetTicks();
Uint32 start_sniper_2=SDL_GetTicks();
Uint32 start_sniper_3=SDL_GetTicks();
Uint32 start_blinde=SDL_GetTicks();
Uint32 start_boss=SDL_GetTicks();
Uint32 start_terminator=SDL_GetTicks();
int debut_attaque_arabian=0,debut_attaque_arabian_2=0,debut_attaque_arabian_3=0,debut_attaque_blinde=0;
int test_premiere_fois=1,test_premiere_fois2=1,test_premiere_fois_2=1,test_premiere_fois_3=1;
int resistance_bouclier=10;

Uint32 starts_cartouches_sniper [30] ={SDL_GetTicks()};
int debut_cartouche_sniper=0,nbr_cartouches_sniper=0;
int test_sniper=0;
cartouche soldat_sniper_cartouche [soldat_sniper.MAX_affichage_cartouches];
Uint32 starts_cartouches_sniper_2 [30] ={SDL_GetTicks()};
int debut_cartouche_sniper_2=0,nbr_cartouches_sniper_2=0;
int test_sniper_2=0;
cartouche soldat_sniper_cartouche_2 [soldat_sniper_2.MAX_affichage_cartouches];
Uint32 starts_cartouches_sniper_3 [30] ={SDL_GetTicks()};
int debut_cartouche_sniper_3=0,nbr_cartouches_sniper_3=0;
int test_sniper_3=0;
cartouche soldat_sniper_cartouche_3 [soldat_sniper_3.MAX_affichage_cartouches];

Uint32 starts_cartouches_boss [30] ={SDL_GetTicks()};
int debut_cartouche_boss=0,nbr_cartouches_boss=0;
int test_boss=0;
cartouche cartouche_boss[boss.MAX_affichage_cartouches];
int boss_resistance=7;
/////////////////////////////////////////////
///variables de l'environnement:
int porte_ouverte=5;
SDL_Surface *porte;
SDL_Rect porte_position;
porte_position.x=625;
porte_position.y=229+110;
///variables de l'explosion:
int terminer_explosion=0;
int debut_explosion=0;
SDL_Rect explosion_position;
SDL_Rect explosion_ancienne_position;
explosion_position.x=625;
explosion_position.y=160+110;
explosion_ancienne_position=explosion_position;
Uint32 start_explosion=SDL_GetTicks();
/////////////////////////////////////////////////
///boucle principale
while(!exit_stage&&!*game_over){
*game_over=!joueur.affichage;
gestion_clavier(&exit_stage,&appui_haut,&appui_bas,&appui_droite,&appui_gauche,&appui_saut,&appui_tire,&appui_grenade);
gestion_camera(&stage_x,&blocage_camera);
if(joueur.contact_avec_le_sol)collusion_personnage_sol(&joueur,stage_x);
SDL_Flip(screen);
SDL_BlitSurface(stage_x.background_image,&stage_x.camera,screen,&stage_x.position_background);
///gestion du mape
 porte_position.x=625;
 porte_position.y=229+110;
 porte_position.x=porte_position.x-stage_x.camera.x;
if (porte_ouverte==0) {
              porte=IMG_Load("images/door.png");
              debut_explosion=1;
              SDL_BlitSurface(porte,NULL,screen,&porte_position);}
else if (joueur.position.x+stage_x.camera.x>=620)stage_x.camera.x=620-joueur.position.x;
///gestion de la mort du joueur
collusion_joueur_ennemie(&joueur,&soldat_talkiwalki,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_arabian,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_arabian_2,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_arabian_3,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_sniper,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_sniper_2,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_sniper_3,&stage_x);
collusion_joueur_ennemie(&joueur,&soldat_blinde,&stage_x);
collusion_joueur_boss(&joueur,&boss,&stage_x);
///gestion de la noyade
if((joueur.position.x<1752-stage_x.camera.x)&&(joueur.position.x>1730-stage_x.camera.x)&&joueur.contact_avec_le_sol){SDL_Rect position_noyade;
                                                                                      position_noyade.x=1730-stage_x.camera.x;
                                                                                      position_noyade.y=275+110;
                                                                                      noyade_joueur(&joueur,&stage_x,&screen,&start_mort_joueur,position_noyade);
                                                                                      }
else if((joueur.position.x<1856-stage_x.camera.x)&&(joueur.position.x>1830-stage_x.camera.x)&&joueur.contact_avec_le_sol){SDL_Rect position_noyade;
                                                                                      position_noyade.x=1830-stage_x.camera.x;
                                                                                      position_noyade.y=275+110;
                                                                                      noyade_joueur(&joueur,&stage_x,&screen,&start_mort_joueur,position_noyade);
                                                                                      }

else if((joueur.position.x<2026-stage_x.camera.x)&&(joueur.position.x>1990-stage_x.camera.x)&&joueur.contact_avec_le_sol){SDL_Rect position_noyade;
                                                                                      position_noyade.x=2000-stage_x.camera.x;
                                                                                      position_noyade.y=275+110;
                                                                                      noyade_joueur(&joueur,&stage_x,&screen,&start_mort_joueur,position_noyade);}
else if((joueur.position.x<2120-stage_x.camera.x)&&(joueur.position.x>2108-stage_x.camera.x)&&joueur.contact_avec_le_sol){SDL_Rect position_noyade;
                                                                                      position_noyade.x=2103-stage_x.camera.x;
                                                                                      position_noyade.y=275+110;
                                                                                      noyade_joueur(&joueur,&stage_x,&screen,&start_mort_joueur,position_noyade);
                                                                                      }

else if(joueur.mort) mort_joueur(&joueur,&stage_x,&screen,&start_mort_joueur);
else {
///deplacement du personnage:
if(appui_droite&&!attente_saut){
                  joueur.position.y=joueur.ancienne_position.y;
                  joueur.ancienne_position=joueur.position;
                  joueur.dernier_deplacement_horizontale=0;
                  joueur.position.x+=joueur.vitesse_deplacement;
                  stage_x.camera.x+=stage_x.vitesse_camera;
                  if(joueur.position.x<200||stage_x.blocage_camera){joueur.vitesse_deplacement=1;
                                            stage_x.vitesse_camera=0;}
                                      else {joueur.vitesse_deplacement=0;
                                            stage_x.vitesse_camera=1;
                                            decalage_camera_droite(&soldat_arabian);
                                            decalage_camera_droite(&soldat_arabian_2);
                                            decalage_camera_droite(&soldat_arabian_3);}
                   if(joueur.FPS_deplacement<SDL_GetTicks()-start){joueur.index_sprite_droite++;
                                                                       start=SDL_GetTicks();}
                  if (joueur.index_sprite_droite>=11) joueur.index_sprite_droite=3;
                  SDL_BlitSurface(joueur.sprites_droite,&joueur.ciseau_droite[joueur.index_sprite_droite],screen,&joueur.position);
                 }
else if(appui_gauche&&!attente_saut) {
                  joueur.position.y=joueur.ancienne_position.y;
                  joueur.ancienne_position=joueur.position;
                  joueur.dernier_deplacement_horizontale=1;
                  joueur.position.x-=joueur.vitesse_deplacement;
                  stage_x.camera.x-=stage_x.vitesse_camera;
                  if(joueur.position.x>10){joueur.vitesse_deplacement=1;
                                            stage_x.vitesse_camera=0;}
                                      else {joueur.vitesse_deplacement=0;
                                            stage_x.vitesse_camera=0;}
                   if(joueur.FPS_deplacement<SDL_GetTicks()-start){joueur.index_sprite_gauche++;
                                                                      start=SDL_GetTicks();}
                  if (joueur.index_sprite_gauche>=11) joueur.index_sprite_gauche=3;
                  SDL_BlitSurface(joueur.sprites_gauche,&joueur.ciseau_gauche[joueur.index_sprite_gauche],screen,&joueur.position);
                 }
else if(appui_bas&&!attente_saut){
                   if(joueur.FPS_bas<SDL_GetTicks()-start){joueur.index_sprite_bas++;
                                                                        start=SDL_GetTicks();}
                   if (joueur.index_sprite_bas>12)joueur.position.y=joueur.ancienne_position.y+16;
                   if (joueur.index_sprite_bas>=16) joueur.index_sprite_bas=13;
                   if(joueur.dernier_deplacement_horizontale==0)
                        SDL_BlitSurface(joueur.sprites_droite,&joueur.ciseau_droite[joueur.index_sprite_bas],screen,&joueur.position);
                   else
                         SDL_BlitSurface(joueur.sprites_gauche,&joueur.ciseau_gauche[joueur.index_sprite_bas],screen,&joueur.position);
                   }
else if((appui_tire||attente_tire)&&!attente_saut){
                     attente_tire=1;
                    joueur.position.y=joueur.ancienne_position.y;
                     if(joueur.FPS_recharge<SDL_GetTicks()-start){joueur.index_sprite_tire++;
                                                                     start=SDL_GetTicks();}
                     if(joueur.dernier_deplacement_horizontale==0)
                                         SDL_BlitSurface(joueur.sprites_droite,&joueur.ciseau_droite[joueur.index_sprite_tire],screen,&joueur.position);
                                       else
                                         {SDL_Rect position_personnage_gauche=joueur.position;
                                         if(joueur.index_sprite_tire<=17) position_personnage_gauche.x=joueur.position.x-joueur.ciseau_gauche[joueur.index_sprite_tire].w/2.5;
                                         else position_personnage_gauche.x=joueur.position.x-7;
                                         SDL_BlitSurface(joueur.sprites_gauche,&joueur.ciseau_gauche[joueur.index_sprite_tire],screen,&position_personnage_gauche);}
                     if(nbr_tirs==2){
                                     if(joueur.index_sprite_tire>=35) {joueur.index_sprite_tire=16;
                                                                         nbr_tirs=0;
                                                                         attente_tire=0;}
                                    }
                     else          {
                                    if(joueur.index_sprite_tire>=20) {joueur.index_sprite_tire=16;
                                                                         nbr_tirs++;
                                                                         attente_tire=0;}
                                   }
                 }
else if(appui_saut||attente_saut){

                                  if(10<SDL_GetTicks()-start){joueur.index_sprite_saut++;
                                                 start=SDL_GetTicks();}
                  if(appui_droite){joueur.dernier_deplacement_horizontale=0;
                                   joueur.position.x+=joueur.vitesse_deplacement;
                                   stage_x.camera.x+=stage_x.vitesse_camera;
                                   if(joueur.position.x<200||stage_x.blocage_camera){joueur.vitesse_deplacement=1;
                                                                                     stage_x.vitesse_camera=0;}
                                   else {joueur.vitesse_deplacement=0;
                                         stage_x.vitesse_camera=1;
                                         decalage_camera_droite(&soldat_arabian);
                                         decalage_camera_droite(&soldat_arabian_2);
                                         decalage_camera_droite(&soldat_arabian_3);}
                                  }
                  if(appui_gauche){joueur.dernier_deplacement_horizontale=1;
                                   joueur.position.x-=joueur.vitesse_deplacement;
                                   stage_x.camera.x-=stage_x.vitesse_camera;
                                   if(joueur.position.x>10){joueur.vitesse_deplacement=1;
                                                            stage_x.vitesse_camera=0;}
                                   else {joueur.vitesse_deplacement=0;
                                         stage_x.vitesse_camera=0;
                                         decalage_camera_droite(&soldat_arabian);
                                         decalage_camera_droite(&soldat_arabian_2);
                                         decalage_camera_droite(&soldat_arabian_3);}
                                   }
                     joueur.contact_avec_le_sol=0;
                     attente_saut=1;
                    if(descente_saut==0) {
                                          if (joueur.index_sprite_saut>=41)joueur.index_sprite_saut=40;
                                          joueur.position.y--;
                                          if(joueur.ancienne_position.y-joueur.position.y>=hauteur_saut) descente_saut=1;
                                         }
                    if(descente_saut==1) {if (joueur.index_sprite_saut>=44) joueur.index_sprite_saut=43;
                                         joueur.position.y++;
                                         if(joueur.ancienne_position.y-joueur.position.y<1) {descente_saut=0;
                                                                                             joueur.contact_avec_le_sol=1;
                                                                                             attente_saut=0;}
                                         }

                    if(joueur.dernier_deplacement_horizontale==0)
                          SDL_BlitSurface(joueur.sprites_droite,&joueur.ciseau_droite[joueur.index_sprite_saut],screen,&joueur.position);
                    else
                          SDL_BlitSurface(joueur.sprites_gauche,&joueur.ciseau_gauche[joueur.index_sprite_saut],screen,&joueur.position);
}
else {
      joueur.index_sprite_saut=35;
      joueur.index_sprite_bas=11;
      joueur.position.y=joueur.ancienne_position.y;
      if(joueur.FPS_attente<SDL_GetTicks()-start){joueur.index_sprite_attente++;
                                                     start=SDL_GetTicks();}
      if(joueur.index_sprite_attente>=3) joueur.index_sprite_attente=0;
      if(joueur.dernier_deplacement_horizontale==0)
            SDL_BlitSurface(joueur.sprites_droite,&joueur.ciseau_droite[joueur.index_sprite_attente],screen,&joueur.position);
        else
            SDL_BlitSurface(joueur.sprites_gauche,&joueur.ciseau_gauche[joueur.index_sprite_attente],screen,&joueur.position);
      }
 if(joueur.index_sprite_tire==18&&!test){debut_cartouche=1;
                                      int cartouche_trouve=0;
                                      i=0;
                                      if(nbr_cartouches>=joueur.MAX_affichage_cartouches)nbr_cartouches=0;
                                      while(i<=nbr_cartouches&&cartouche_trouve==0){
                                      if(joueur_cartouche[i].objet_touche==1)
                                      {ajouter_cartouche(joueur,&joueur_cartouche[i]);
                                       cartouche_trouve=1;}
                                       i++;}
                                      if(cartouche_trouve==0){ajouter_cartouche(joueur,&joueur_cartouche[nbr_cartouches]);
                                                              nbr_cartouches++;}
                                      test=1;
                                          }
 if(joueur.index_sprite_tire==19) test=0;
///gestion des cartouches:
 if(debut_cartouche){
   for(i=0;i<nbr_cartouches;i++){
   deplacement_cartouche(joueur,&joueur_cartouche[i],&screen,&starts_cartouche[i]);
   limite_cartouches(&joueur_cartouche[i],joueur);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_talkiwalki);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_arabian);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_arabian_2);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_arabian_3);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_sniper);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_sniper_2);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_sniper_3);
   collusion_cartouche_ennemie(&joueur_cartouche[i],&soldat_blinde);
   collusion_cartouche_boss(&joueur_cartouche[i],&boss);
   collusion_cartouche_porte(&joueur_cartouche[i],porte_position,&porte_ouverte);
                     }
                     }
}
///gestion des ennemies:
      ///*****ennemie soldat_talkiwalki
if(soldat_talkiwalki.affichage==0) supprimer_ennemi(&soldat_talkiwalki);
else {
if(joueur.index_sprite_explosion==48) soldat_talkiwalki.mort_brulure=1;
if(soldat_talkiwalki.mort_brulure) mort_ennemie_brulure(&soldat_talkiwalki,&stage_x,&screen,&start_talkiwalki);
else attente_ennemie_toure(&soldat_talkiwalki,&stage_x,&screen,&start_talkiwalki);
     }
      ///********ennemie soldat_blinde
if(soldat_blinde.affichage==0) supprimer_ennemi(&soldat_blinde);
else {
if(soldat_blinde.mort&&resistance_bouclier&&soldat_blinde.index_sprite_tire==6) {resistance_bouclier-=1;
                                             soldat_blinde.mort=0;
                                             soldat_blinde.index_sprite_attente=3;}
else if (soldat_blinde.mort&&soldat_blinde.index_sprite_tire>6) resistance_bouclier=0;
if((joueur.position.x-120>soldat_blinde.position.x-stage_x.camera.x)&&!soldat_blinde.contact_avec_le_sol) joueur.mort=1;
if(soldat_blinde.mort&&!resistance_bouclier) mort_ennemie(&soldat_blinde,&stage_x,&screen,&start_blinde);
else if(((joueur.position.x-120>soldat_blinde.position.x-stage_x.camera.x)||debut_attaque_blinde)&&!joueur.mort) {
         debut_attaque_blinde=1;
         attaque_blinde(&soldat_blinde,&stage_x,&screen,&start_blinde);
         if(soldat_blinde.index_sprite_tire==9) {debut_attaque_blinde=0;
                                                 soldat_blinde.contact_avec_le_sol=1;
                                                 soldat_blinde.index_sprite_tire=6;}
                                                                                                }
    else attente_blinde(&soldat_blinde,&stage_x,&screen,&start_blinde);
     }




       ///*****ennemie arabian 1
if(soldat_arabian.mort) {
                           if(test_premiere_fois)  {stage_x.debut_compteur_camera=stage_x.camera.x;
                                                    test_premiere_fois=0;}
                           mort_arabian(&soldat_arabian,&stage_x,&screen,&start_arabian);}
else if(porte_ouverte==0) {

                           if((soldat_arabian.position.x-stage_x.camera.x+stage_x.debut_compteur_camera>joueur.position.x+10)&&!debut_attaque_arabian){
                           stage_x.debut_compteur_camera=stage_x.camera.x;
                           courir_ennemie_arabian(&soldat_arabian,&stage_x,&screen,&start_arabian);
                           collusion_personnage_sol(&soldat_arabian,stage_x);
                           soldat_arabian.position.y=soldat_arabian.ancienne_position.y-10;
                           soldat_arabian.ancienne_position.y=soldat_arabian.position.y;}
                           else {debut_attaque_arabian=1;
                                 attaque_arabian(&soldat_arabian,&stage_x,&screen,&start_arabian);}

                           }
else attente_ennemie_arabian(&soldat_arabian,&stage_x,&screen,&start_arabian);
if(soldat_arabian.affichage==0) supprimer_ennemi(&soldat_arabian);
        ///*****ennemie arabian 2
if(soldat_arabian_2.mort) {
                           if(test_premiere_fois_2)  {stage_x.debut_compteur_camera=stage_x.camera.x;
                                                    test_premiere_fois_2=0;}
                           mort_arabian(&soldat_arabian_2,&stage_x,&screen,&start_arabian_2);}
else if((porte_ouverte==0)&&(soldat_arabian.position.x<600)) {

                           if((soldat_arabian_2.position.x-stage_x.camera.x+stage_x.debut_compteur_camera>joueur.position.x+10)&&!debut_attaque_arabian_2){
                           stage_x.debut_compteur_camera=stage_x.camera.x;
                           courir_ennemie_arabian(&soldat_arabian_2,&stage_x,&screen,&start_arabian_2);
                           collusion_personnage_sol(&soldat_arabian_2,stage_x);
                           soldat_arabian_2.position.y=soldat_arabian_2.ancienne_position.y-10;
                           soldat_arabian_2.ancienne_position.y=soldat_arabian_2.position.y;}
                           else {debut_attaque_arabian_2=1;
                                 attaque_arabian(&soldat_arabian_2,&stage_x,&screen,&start_arabian_2);}

                           }
else attente_ennemie_arabian(&soldat_arabian_2,&stage_x,&screen,&start_arabian_2);
if(soldat_arabian_2.affichage==0) supprimer_ennemi(&soldat_arabian_2);

       ///*****ennemie arabian 3
if(soldat_arabian_3.mort) {
                           if(test_premiere_fois_3)  {stage_x.debut_compteur_camera=stage_x.camera.x;
                                                    test_premiere_fois_3=0;}
                           mort_arabian(&soldat_arabian_3,&stage_x,&screen,&start_arabian_3);}
else if((porte_ouverte==0)&&(soldat_arabian_2.position.x<600)) {

                           if((soldat_arabian_3.position.x-stage_x.camera.x+stage_x.debut_compteur_camera>joueur.position.x+10)&&!debut_attaque_arabian_3){
                           stage_x.debut_compteur_camera=stage_x.camera.x;
                           courir_ennemie_arabian(&soldat_arabian_3,&stage_x,&screen,&start_arabian_3);
                           collusion_personnage_sol(&soldat_arabian_3,stage_x);
                           soldat_arabian_3.position.y=soldat_arabian_3.ancienne_position.y-10;
                           soldat_arabian_3.ancienne_position.y=soldat_arabian_3.position.y;}
                           else {debut_attaque_arabian_3=1;
                                collusion_personnage_sol(&soldat_arabian_3,stage_x);
                           soldat_arabian_3.position.y=soldat_arabian_3.ancienne_position.y-10;
                           soldat_arabian_3.ancienne_position.y=soldat_arabian_3.position.y;
                                attaque_arabian(&soldat_arabian_3,&stage_x,&screen,&start_arabian_3);}

                           }
else attente_ennemie_arabian(&soldat_arabian_3,&stage_x,&screen,&start_arabian_3);
if(soldat_arabian_3.affichage==0) supprimer_ennemi(&soldat_arabian_3);
       ///****ennemie sniper
if(soldat_sniper.affichage==0) supprimer_ennemi(&soldat_sniper);
else if(soldat_sniper.mort) mort_ennemie(&soldat_sniper,&stage_x,&screen,&start_sniper);
else {
if(stage_x.camera.x>(1400-800)&&!joueur.mort) tire_ennemie_sniper(&soldat_sniper,&stage_x,&screen,&start_sniper,&debut_cartouche_sniper);
else attente_ennemie_sniper(&soldat_sniper,&stage_x,&screen,&start_sniper);
if(soldat_sniper.index_sprite_tire==6) test_sniper=0;
if(soldat_sniper.index_sprite_tire==5&&!test_sniper){int cartouche_trouve=0;
                            i=0;
                            if(nbr_cartouches_sniper>=soldat_sniper.MAX_affichage_cartouches)nbr_cartouches_sniper=0;
                            while(i<=nbr_cartouches_sniper&&cartouche_trouve==0){
                            if(soldat_sniper_cartouche[i].objet_touche==1)
                            {ajouter_cartouche_sniper(soldat_sniper,&soldat_sniper_cartouche[i]);
                            cartouche_trouve=1;}
                            i++;}
                            if(cartouche_trouve==0){ajouter_cartouche_sniper(soldat_sniper,&soldat_sniper_cartouche[nbr_cartouches_sniper]);
                                                    nbr_cartouches_sniper++;}
                            test_sniper=1;
                           }
}
if(debut_cartouche_sniper){
   for(i=0;i<nbr_cartouches_sniper;i++){
                                         deplacement_cartouche(soldat_sniper,&soldat_sniper_cartouche[i],&screen,&starts_cartouches_sniper[i]);
                                         limite_cartouches(&soldat_sniper_cartouche[i],soldat_sniper);
                                         collusion_cartouche_ennemie(&soldat_sniper_cartouche[i],&joueur);
                                         if(appui_droite&&joueur.position.x>=200) decalage_camera_droite_cartouches(&soldat_sniper_cartouche[i]);
                                       }
                          }

       ///****ennemie sniper_2
if(soldat_sniper_2.affichage==0) supprimer_ennemi(&soldat_sniper_2);
else if(soldat_sniper_2.mort) mort_ennemie(&soldat_sniper_2,&stage_x,&screen,&start_sniper_2);
else {
if(!soldat_blinde.collusion_cartouche&&!joueur.mort) tire_ennemie_sniper(&soldat_sniper_2,&stage_x,&screen,&start_sniper_2,&debut_cartouche_sniper_2);
else attente_ennemie_sniper(&soldat_sniper_2,&stage_x,&screen,&start_sniper_2);
if(soldat_sniper_2.index_sprite_tire==6) test_sniper_2=0;
if(soldat_sniper_2.index_sprite_tire==5&&!test_sniper_2){int cartouche_trouve=0;
                            i=0;
                            if(nbr_cartouches_sniper_2>=soldat_sniper_2.MAX_affichage_cartouches)nbr_cartouches_sniper_2=0;
                            while(i<=nbr_cartouches_sniper_2&&cartouche_trouve==0){
                            if(soldat_sniper_cartouche_2[i].objet_touche==1)
                            {ajouter_cartouche_sniper(soldat_sniper_2,&soldat_sniper_cartouche_2[i]);
                            cartouche_trouve=1;}
                            i++;}
                            if(cartouche_trouve==0){ajouter_cartouche_sniper(soldat_sniper_2,&soldat_sniper_cartouche_2[nbr_cartouches_sniper_2]);
                                                    nbr_cartouches_sniper_2++;}
                            test_sniper_2=1;
                           }
}
if(debut_cartouche_sniper_2){
   for(i=0;i<nbr_cartouches_sniper_2;i++){
                                         deplacement_cartouche(soldat_sniper_2,&soldat_sniper_cartouche_2[i],&screen,&starts_cartouches_sniper_2[i]);
                                          limite_cartouches(&soldat_sniper_cartouche_2[i],soldat_sniper_2);
                                         collusion_cartouche_ennemie(&soldat_sniper_cartouche_2[i],&joueur);
                                         if(appui_droite&&joueur.position.x>=200) decalage_camera_droite_cartouches(&soldat_sniper_cartouche_2[i]);
                                       }
                          }
 ///****ennemie sniper_3
if(soldat_sniper_3.affichage==0) supprimer_ennemi(&soldat_sniper_3);
else if(soldat_sniper_3.mort) mort_ennemie(&soldat_sniper_3,&stage_x,&screen,&start_sniper_3);
else {
if(stage_x.camera.x>=1020&&!joueur.mort) tire_ennemie_sniper(&soldat_sniper_3,&stage_x,&screen,&start_sniper_3,&debut_cartouche_sniper_3);
else attente_ennemie_sniper(&soldat_sniper_3,&stage_x,&screen,&start_sniper_3);
if(soldat_sniper_3.index_sprite_tire==6) test_sniper_3=0;
if(soldat_sniper_3.index_sprite_tire==5&&!test_sniper_3){int cartouche_trouve=0;
                            i=0;
                            if(nbr_cartouches_sniper_3>=soldat_sniper_3.MAX_affichage_cartouches)nbr_cartouches_sniper_3=0;
                            while(i<=nbr_cartouches_sniper_3&&cartouche_trouve==0){
                            if(soldat_sniper_cartouche_3[i].objet_touche==1)
                            {ajouter_cartouche_sniper(soldat_sniper_3,&soldat_sniper_cartouche_3[i]);
                            cartouche_trouve=1;}
                            i++;}
                            if(cartouche_trouve==0){ajouter_cartouche_sniper(soldat_sniper_3,&soldat_sniper_cartouche_3[nbr_cartouches_sniper_3]);
                                                    nbr_cartouches_sniper_3++;}
                            test_sniper_3=1;
                           }
}
if(debut_cartouche_sniper_3){
   for(i=0;i<nbr_cartouches_sniper_3;i++){
                                         deplacement_cartouche(soldat_sniper_3,&soldat_sniper_cartouche_3[i],&screen,&starts_cartouches_sniper_3[i]);
                                          limite_cartouches(&soldat_sniper_cartouche_3[i],soldat_sniper_3);
                                         collusion_cartouche_ennemie(&soldat_sniper_cartouche_3[i],&joueur);
                                         if(appui_droite&&joueur.position.x>=200) decalage_camera_droite_cartouches(&soldat_sniper_cartouche_3[i]);
                                       }
                          }
 ///****ennemie boss
if(boss.affichage==0) supprimer_ennemi(&boss);
else if(boss.mort&&boss_resistance) {  boss_resistance-=1;
                                       boss.mort=0;
                                      }
else if(boss.mort&&boss_resistance==0) mort_boss(&boss,&stage_x,&screen,&start_boss);
else {
if(stage_x.camera.x>=1420&&!joueur.mort) tire_boss(&boss,&stage_x,&screen,&start_boss,&debut_cartouche_boss);
else attente_boss(&boss,&stage_x,&screen,&start_boss);
if(boss.index_sprite_tire==6) test_boss=0;
if(boss.index_sprite_tire==5&&!test_boss){int cartouche_trouve=0;
                            i=0;
                            if(nbr_cartouches_boss>=boss.MAX_affichage_cartouches)nbr_cartouches_boss=0;
                            while(i<=nbr_cartouches_boss&&cartouche_trouve==0){
                            if(cartouche_boss[i].objet_touche==1)
                            {ajouter_cartouche_boss(boss,&cartouche_boss[i]);
                            cartouche_trouve=1;}
                            i++;}
                            if(cartouche_trouve==0){ajouter_cartouche_boss(boss,&cartouche_boss[nbr_cartouches_boss]);
                                                    nbr_cartouches_boss++;}
                            test_boss=1;
                           }
}
if(debut_cartouche_boss){
   for(i=0;i<nbr_cartouches_boss;i++){
                                         deplacement_cartouche(boss,&cartouche_boss[i],&screen,&starts_cartouches_boss[i]);
                                         limite_cartouches(&cartouche_boss[i],boss);
                                         collusion_cartoucheboss_joueur(&cartouche_boss[i],&joueur);
                                         if(appui_droite&&joueur.position.x>=200) decalage_camera_droite_cartouches(&cartouche_boss[i]);
                                       }
                          }
      ///****ennemie terminator
      if(boss.mort) {joueur.vitesse_deplacement=0;
                    stage_x.vitesse_camera=0;
                    terminator.position.x=joueur.position.x+150;
                    joueur.sprites_cartouche_droite=NULL;
                    joueur.sprites_cartouche_gauche=NULL;
                    if(terminator.position.x>700)terminator.position.x=700;
                    }
      if(boss.affichage==0){
      if(terminator.position.y<joueur.position.y)
      descente_terminator(&terminator,&stage_x,&screen,&start_terminator);
      else attaque_terminator(&terminator,&stage_x,&screen,&start_terminator);
      if(terminator.index_sprite_tire==16) joueur.mort=1;
      }
      ///affichage des explosions
      if(debut_explosion&&terminer_explosion==0) grande_explosion(&joueur,&explosion_position,&explosion_ancienne_position,&stage_x,&screen,&start_explosion,&terminer_explosion);



}






////////////////////////////////////////////////
*debut_stage=!exit_stage;
SDL_FreeSurface(screen);
SDL_FreeSurface(desert.background_image);
SDL_FreeSurface(leo.sprites_droite);
SDL_FreeSurface(leo.sprites_gauche);


}
