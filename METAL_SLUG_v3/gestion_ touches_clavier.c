 #include <SDL/SDL.h>
 ///////////////////////////////////////////////////////////
 void gestion_clavier(int *exit_stage,int *appui_haut,int *appui_bas,int *appui_droite,int *appui_gauche,int *appui_saut,int *appui_tire,int *appui_grenade){
 SDL_Event event;
 SDL_PollEvent(&event);
 SDL_EnableKeyRepeat(10,10);
 switch(event.type)
{
    case SDL_QUIT:
        *exit_stage=1;
        break;
    case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    *exit_stage=1;
                    break;
                case SDLK_UP:
                     *appui_bas=0;
                     *appui_haut=1;
                     break;
                case SDLK_DOWN:
                     *appui_droite=0;
                     *appui_gauche=0;
                     *appui_bas=1;
                     *appui_haut=0;
                     *appui_tire=0;
                     *appui_grenade=0;
                     *appui_saut=0;
                     break;
                case SDLK_RIGHT:
                     *appui_droite=1;
                     *appui_gauche=0;
                     *appui_bas=0;
                     *appui_haut=0;
                     break;
                case SDLK_LEFT:
                     *appui_droite=0;
                     *appui_gauche=1;
                     *appui_bas=0;
                     *appui_haut=0;
                     break;
                case SDLK_v:
                     *appui_droite=0;
                     *appui_gauche=0;
                     *appui_bas=0;
                     *appui_tire=1;
                     *appui_grenade=0;
                     *appui_saut=0;
                     break;
                case SDLK_c:

                     *appui_tire=0;
                     *appui_grenade=0;
                     *appui_saut=1;
                     break;
                case SDLK_x:
                     *appui_droite=0;
                     *appui_gauche=0;
                     *appui_bas=0;
                     *appui_haut=0;
                     *appui_tire=0;
                     *appui_grenade=1;
                     *appui_saut=0;
                     break;
                                         }
     break;
 case SDL_KEYUP:
                switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    *exit_stage=0;
                    break;
                case SDLK_UP:
                     *appui_haut=0;
                     break;
                case SDLK_DOWN:
                     *appui_bas=0;
                     break;
                case SDLK_RIGHT:
                     *appui_droite=0;
                     break;
                case SDLK_LEFT:
                     *appui_gauche=0;
                     break;
                case SDLK_v:
                     *appui_tire=0;
                     break;
                case SDLK_c:
                     *appui_saut=0;
                     break;
                case SDLK_x:
                     *appui_grenade=0;
                     break;
                                         }
     break;
}



 }
