#include"creation_projectils.h"
///////////////////////////////////////////////////////////////////////////////
void initialiser_cartouches(personnage joueur,cartouche *cartouche_personnage){
int i;

for(i=0;i<=joueur.MAX_affichage_cartouches;i++){
(cartouche_personnage)[i].position.x=0;
(cartouche_personnage)[i].position.y=0;
                    }
}

/////////////////////////////////////////////////////////////////////////////
void ajouter_cartouche(personnage joueur,cartouche *cartouche_personnage){
 (*cartouche_personnage).objet_touche=0;
 (*cartouche_personnage).deplacement_horizontale=joueur.dernier_deplacement_horizontale;
 if(joueur.dernier_deplacement_horizontale==0){
 (*cartouche_personnage).position.x=joueur.position.x+40;
 (*cartouche_personnage).position.y=joueur.position.y+10;}
 else {
 (*cartouche_personnage).position.x=joueur.position.x-40;
 (*cartouche_personnage).position.y=joueur.position.y+10;}
 (*cartouche_personnage).ancienne_position=(*cartouche_personnage).position;
}
////////////////////////////////////////////////////////////////////////////////
void ajouter_cartouche_sniper(personnage joueur,cartouche *cartouche_personnage){
 (*cartouche_personnage).objet_touche=0;
 (*cartouche_personnage).deplacement_horizontale=joueur.dernier_deplacement_horizontale;
 if(joueur.dernier_deplacement_horizontale==0){
 (*cartouche_personnage).position.x=joueur.position.x+10;
 (*cartouche_personnage).position.y=joueur.position.y+8;}
 else {
 (*cartouche_personnage).position.x=joueur.position.x-10;
 (*cartouche_personnage).position.y=joueur.position.y+8;}
 (*cartouche_personnage).ancienne_position=(*cartouche_personnage).position;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void deplacement_cartouche(personnage joueur,cartouche *cartouche_personnage,SDL_Surface **screen,Uint32*start){
if((*cartouche_personnage).objet_touche==0){
if((*cartouche_personnage).deplacement_horizontale==0)
    {if(5<SDL_GetTicks()-*start){ (*cartouche_personnage).position.x+=2;
                                              *start=SDL_GetTicks();}
    SDL_BlitSurface(joueur.sprites_cartouche_droite,NULL,*screen,&(*cartouche_personnage).position);}
else
    {if(5<SDL_GetTicks()-*start){ (*cartouche_personnage).position.x-=2;
                                              *start=SDL_GetTicks();}
    SDL_BlitSurface(joueur.sprites_cartouche_gauche,NULL,*screen,&(*cartouche_personnage).position);}

                                            }
}
//////////////////////////////////////////////////////////////////////////////
void supprimer_cartouche(cartouche **cartouche_personnage,int index_cartouche,int nbr_cartouches){
int compteur=0;
for(compteur=index_cartouche;compteur<nbr_cartouches-1;compteur++)
  {
     cartouche_personnage[compteur]=cartouche_personnage[compteur+1];
  }

}
/////////////////////////////////////////////////////////////////////////////////
void deplacement_cartouche_bazouka(personnage joueur,cartouche *cartouche_personnage,SDL_Surface **screen,Uint32*start){
if((*cartouche_personnage).objet_touche==0){
float a,b;
a=((*cartouche_personnage).ancienne_position.y-joueur.ancienne_position.y)/((*cartouche_personnage).ancienne_position.x^2-joueur.ancienne_position.x^2);
b=joueur.ancienne_position.y-a*(joueur.ancienne_position.x^2);
if((*cartouche_personnage).deplacement_horizontale==0)
    {if(5<SDL_GetTicks()-*start){ (*cartouche_personnage).position.x++;
     (*cartouche_personnage).position.y=a*((*cartouche_personnage).position.x^2)+b;
                                              *start=SDL_GetTicks();}
    SDL_BlitSurface(joueur.sprites_cartouche_droite,NULL,*screen,&(*cartouche_personnage).position);}
else
    {if(5<SDL_GetTicks()-*start){ (*cartouche_personnage).position.x--;
           (*cartouche_personnage).position.y=a*((*cartouche_personnage).position.x^2)+b;

                                              *start=SDL_GetTicks();}
    SDL_BlitSurface(joueur.sprites_cartouche_gauche,NULL,*screen,&(*cartouche_personnage).position);}

                                            }
}
////////////////////////////////////////////////////////////////////////////////
void ajouter_cartouche_boss(personnage joueur,cartouche *cartouche_personnage){
 (*cartouche_personnage).objet_touche=0;
 (*cartouche_personnage).deplacement_horizontale=joueur.dernier_deplacement_horizontale;
 if(joueur.dernier_deplacement_horizontale==0){
 (*cartouche_personnage).position.x=joueur.position.x+20;
 (*cartouche_personnage).position.y=joueur.position.y+8;}
 else {
 (*cartouche_personnage).position.x=joueur.position.x-20;
 (*cartouche_personnage).position.y=joueur.position.y+8;}
 (*cartouche_personnage).ancienne_position=(*cartouche_personnage).position;
}
/////////////////////////////////////////////////////////////////////////////
