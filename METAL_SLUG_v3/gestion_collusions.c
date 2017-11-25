#include "creation_personnages.h"
#include "creation_stage.h"
#include"creation_projectils.h"
void gestion_camera(stage *stage_x,int *blocage_camera){
if((*stage_x).camera.x<1) (*stage_x).camera.x=1;
if((*stage_x).camera.x>2090) {(*stage_x).camera.x=2090;
                              (*stage_x).blocage_camera=1;}
}
//////////////////////////////////////////////////////////////////
void collusion_cartouche_ennemie(cartouche *joueur_cartouche,personnage *ennemie){
if(((*joueur_cartouche).position.x>=(*ennemie).position.x)&&((*joueur_cartouche).position.x<=(*ennemie).position.x+25)&&(*ennemie).collusion_cartouche&&(*joueur_cartouche).objet_touche==0&&(*joueur_cartouche).position.y>=(*ennemie).position.y&&((*joueur_cartouche).position.y<=(*ennemie).position.y+(*ennemie).position.h))
    {(*joueur_cartouche).objet_touche=1;
    (*ennemie).mort=1;}
}
////////////////////////////////////////////////////////////////////
void collusion_cartoucheboss_joueur(cartouche *joueur_cartouche,personnage *ennemie){
if(((*joueur_cartouche).position.x>=(*ennemie).position.x)&&((*joueur_cartouche).position.x<=(*ennemie).position.x+25)&&(*ennemie).collusion_cartouche&&(*joueur_cartouche).objet_touche==0&&(*joueur_cartouche).position.y>=(*ennemie).position.y-5&&((*joueur_cartouche).position.y<=(*ennemie).position.y+(*ennemie).position.h))
    {(*joueur_cartouche).objet_touche=1;
    (*ennemie).mort=1;}


}
////////////////////////////////////////////////////////////////////
void collusion_cartouche_boss(cartouche *joueur_cartouche,personnage *ennemie){
if(((*joueur_cartouche).position.x>=(*ennemie).position.x)&&((*joueur_cartouche).position.x<=(*ennemie).position.x+25)&&(*ennemie).collusion_cartouche&&(*joueur_cartouche).objet_touche==0&&(*joueur_cartouche).position.y>=(*ennemie).position.y)
    {(*joueur_cartouche).objet_touche=1;
    (*ennemie).mort=1;}
}
///////////////////////////////////////////////////////////////////
void limite_cartouches(cartouche *joueur_cartouche,personnage joueur){
if((*joueur_cartouche).position.x<1||(*joueur_cartouche).position.x>800) (*joueur_cartouche).objet_touche=1;
}
///////////////////////////////////////////////////////////////////
void collusion_explosion_personnages(SDL_Rect position_explosion,personnage *ennemie){
if((position_explosion.x<=(*ennemie).position.x+25)&&(*ennemie).mort_brulure==0)
    {
    (*ennemie).mort_brulure=1;}

}
///////////////////////////////////////////////////////////////////
void collusion_cartouche_porte(cartouche *joueur_cartouche,SDL_Rect position_porte,int *porte_ouverte){
if(((*joueur_cartouche).position.x>=position_porte.x+10)&&((*joueur_cartouche).position.x<=position_porte.x+50)&&((*joueur_cartouche).position.y<=position_porte.y+45)&&((*joueur_cartouche).position.y>=position_porte.y-20)&&(*porte_ouverte!=0)&&(*joueur_cartouche).objet_touche==0)
    {    *porte_ouverte=*porte_ouverte-1;
        (*joueur_cartouche).objet_touche=1;
   }

}
////////////////////////////////////////////////////////////////////
void collusion_personnage_sol(personnage *joueur,stage stage_x){
int c=stage_x.y_relative;
int segment=0;
if((*joueur).position.x>=770) (*joueur).position.x=769;
if((*joueur).position.x<154-stage_x.camera.x) segment=0;
else if((*joueur).position.x<179-stage_x.camera.x) segment=1;
else if((*joueur).position.x<230-stage_x.camera.x) segment=2;
else if((*joueur).position.x<250-stage_x.camera.x) segment=3;
else if((*joueur).position.x<340-stage_x.camera.x) segment=4;
else if((*joueur).position.x<390-stage_x.camera.x) segment=5;
else if((*joueur).position.x<420-stage_x.camera.x) segment=6;
else if((*joueur).position.x<510-stage_x.camera.x) segment=7;
else if((*joueur).position.x<750-stage_x.camera.x) segment=8;
else if((*joueur).position.x<760-stage_x.camera.x) segment=9;
else if((*joueur).position.x<940-stage_x.camera.x) segment=10;
else if((*joueur).position.x<1475-stage_x.camera.x) segment=11;
else if((*joueur).position.x<1543-stage_x.camera.x) segment=12;
else if((*joueur).position.x<1558-stage_x.camera.x) segment=13;
else if((*joueur).position.x<1649-stage_x.camera.x) segment=14;
else if((*joueur).position.x<1730-stage_x.camera.x) segment=15;
else if((*joueur).position.x<1752-stage_x.camera.x) segment=16;
else if((*joueur).position.x<1830-stage_x.camera.x) segment=17;
else if((*joueur).position.x<1856-stage_x.camera.x) segment=18;
else if((*joueur).position.x<1990-stage_x.camera.x) segment=19;
else if((*joueur).position.x<2026-stage_x.camera.x) segment=20;
else if((*joueur).position.x<2108-stage_x.camera.x) segment=21;
else if((*joueur).position.x<2120-stage_x.camera.x) segment=22;
else if((*joueur).position.x<2234-stage_x.camera.x) segment=23;
else if((*joueur).position.x<2890-stage_x.camera.x) segment=24;

switch(segment)
 {
 case 0:
      (*joueur).position.y=c+243;
      (*joueur).ancienne_position.y=(*joueur).position.y;

       break;
  case 1:
      (*joueur).position.y=c+237;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+229;
       break;
  case 2:
      (*joueur).position.y=c+231;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+227;
       break;
   case 3:
      (*joueur).position.y=c+238;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
   break;
   case 4:
      (*joueur).position.y=c+245;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
   case 5:
      (*joueur).position.y=c+235;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
    case 6:
      (*joueur).position.y=c+227;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
    case 7:
      (*joueur).position.y=c+230;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
    case 8:
      (*joueur).position.y=c+220;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
     case 9:
      (*joueur).position.y=c+230;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
     case 10:
      (*joueur).position.y=c+233;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
      case 11:
      (*joueur).position.y=c+220;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
       case 12:
      (*joueur).position.y=c+230;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 13:
      (*joueur).position.y=c+240;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 14:
      (*joueur).position.y=c+260;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 15:
      (*joueur).position.y=c+278;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
       case 16:
      (*joueur).position.y=c+287;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 17:
      (*joueur).position.y=c+278;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 18:
      (*joueur).position.y=c+287;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 19:
      (*joueur).position.y=c+278;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
       case 20:
      (*joueur).position.y=c+287;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
       case 21:
      (*joueur).position.y=c+278;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 22:
      (*joueur).position.y=c+287;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 23:
      (*joueur).position.y=c+278;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
        case 24:
      (*joueur).position.y=c+260;
      (*joueur).ancienne_position.y=(*joueur).position.y;
      (*joueur).hauteur_saut=(*joueur).hauteur_saut+213;
       break;
   break;
 }



 }
//////////////////////////////////////////////////////////////////
void collusion_joueur_ennemie(personnage *joueur,personnage *ennemie,stage *stage_x){
if(((*joueur).position.x<=(*ennemie).position.x)&&((*joueur).position.x>=(*ennemie).position.x-20)&&(*joueur).mort==0&&!(!(*joueur).contact_avec_le_sol&&(*ennemie).mort))
 {
    if((*ennemie).contact_avec_le_sol==0)(*joueur).mort=1;
    else
    {   if((*joueur).position.x>=200)
        {(*joueur).position.x=198;
        (*stage_x).vitesse_camera=0;}
        else
        (*joueur).vitesse_deplacement=0;
    }
}
}
///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void collusion_joueur_boss(personnage *joueur,personnage *ennemie,stage *stage_x){
if(((*joueur).position.x<=(*ennemie).position.x)&&((*joueur).position.x>=(*ennemie).position.x-20)&&(*joueur).mort==0&&!(!(*joueur).contact_avec_le_sol&&(*ennemie).mort))
    (*joueur).mort=1;
}
///////////////////////////////////////////////////////////////////
