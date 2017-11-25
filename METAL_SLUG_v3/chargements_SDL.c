#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//////////////////////////////////////////////////////////////////
void chargement_SDL(SDL_Surface **screen){
SDL_Init(SDL_INIT_EVERYTHING);
*screen=SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
SDL_WM_SetCaption("METAL SLUG", NULL);
SDL_ShowCursor(SDL_DISABLE);
}
