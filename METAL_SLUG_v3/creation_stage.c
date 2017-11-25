#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "creation_stage.h"
//////////////////////////////////////////////////////
void creer_stage_1(stage *un_stage){
(*un_stage).background_image=IMG_Load("images/stage1.png");
(*un_stage).position_background.x=0;
(*un_stage).position_background.y=150;
(*un_stage).position_background.w=2890;
(*un_stage).position_background.h=288;
(*un_stage).y_relative=110;
(*un_stage).camera.x=0;
(*un_stage).camera.y=0;
(*un_stage).camera.w=800;
(*un_stage).camera.h=288;
(*un_stage).ancienne_camera=(*un_stage).camera;
(*un_stage).vitesse_camera=1;
(*un_stage).blocage_camera=0;
(*un_stage).debut_compteur_camera=0;

}
///////////////////////////////////////////////////////
void decalage_camera_droite(personnage *un_joueur){
(*un_joueur).position.x-=1;
}
void decalage_camera_gauche(personnage *un_joueur){
(*un_joueur).position.x+=1;
}
void decalage_camera_droite_cartouches(cartouche *un_joueur){
(*un_joueur).position.x-=1;
}
void decalage_camera_gauche_cartouches(cartouche *un_joueur){
(*un_joueur).position.x+=1;
}
