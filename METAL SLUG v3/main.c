#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jouer.h"
#include"chargements_SDL.h"

int main(int argc, char *argv[])
{
SDL_Surface *ecran=NULL;
chargement_SDL(&ecran);
SDL_Surface* menu,*over_game;
menu=IMG_Load("images/menu.png");
over_game=IMG_Load("images/game_over.png");
SDL_Rect position_menu;
position_menu.x=0;
position_menu.y=0;
int exit_jeu=0;
int debut_stage=0;
int game_over=0;
///boucle principale**
while(!exit_jeu){
   ///**affichage du menu
if(!debut_stage&&!game_over){
                 SDL_BlitSurface(menu,NULL,ecran,&position_menu);
                 SDL_Flip(ecran);
                 SDL_Event event;
                 SDL_WaitEvent(&event);
                 ///destion_clavier_menu*******************************
                 switch(event.type)
                 {
                     case SDL_QUIT:
                     exit_jeu=1;
                     break;
                     case SDL_KEYDOWN:
                              switch(event.key.keysym.sym){
                                    case SDLK_ESCAPE:
                                    exit_jeu=1;
                                    break;
                                    default:
                                    debut_stage=1;
                                    break;
                                                           }
                  }
                  ///**************************************************
              }
///**commencement du jeu
if(!game_over&&debut_stage) jouer(&debut_stage,&game_over);
///**affichage game over
if(game_over) {
                SDL_BlitSurface(over_game,NULL,ecran,&position_menu);
                SDL_Flip(ecran);
                SDL_Delay(3000);
                game_over=0;
                debut_stage=0;
              }

}
return EXIT_SUCCESS;
}



