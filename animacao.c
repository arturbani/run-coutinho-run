#include "Bibliotecas/library.h"



//Essa função determina qual parte do spritesheet sera exibido.
void reposicionaViewTextura(float XInicial,float XFinal,float YInicial,float YFinal,textura_animacao *textura){
  textura->X_Inicio_Textura = XInicial;
  textura->X_Final_Textura = XFinal;
  textura->Y_Inicio_Textura = YInicial;
  textura->Y_Final_Textura = YFinal;




}





void Animacao_Textura_Jogador1(textura_animacao *textura,int PularOn, int RolamentoOn, int *RolamentoContadorFrames,
                                int theEnd, int MovimentarOn){


  float CorrigeAcima =-.0;
  float CorrigeAbaixo=.1;
  float CorrigeFrente = -.018;
  float CorrigeAtras = -.008;

  float CorrigeAcimaRoll = -.03;

  //Morte
  // printf("THEEND:%i\n",theEnd);
  if(theEnd){
    float timer = 3;
    if(textura->Contador==1*timer)
    reposicionaViewTextura(0 , .25 , .2, 1,textura);

    else if(textura->Contador==2*timer)
    reposicionaViewTextura(.25, .5 ,.3, 1,textura);

    else if(textura->Contador==3*timer)
    reposicionaViewTextura(.5,.75, .3, 1,textura);

    else if(textura->Contador==4*timer){
      reposicionaViewTextura(.75, 1, .3, 1,textura);
      // textura->Contador=0;
        }
    textura->Contador++;
  }

   if(MovimentarOn){
    //ROLAMENTO
    if(RolamentoOn){
      float timer = 1;
      if(textura->Contador==1*timer)
      reposicionaViewTextura(0 , 1 , .75, 1,textura);

      else if(textura->Contador==2*timer)
      reposicionaViewTextura(0, 1 ,.5, .75,textura);

      else if(textura->Contador==3*timer)
      reposicionaViewTextura(0,1, .25, .5,textura);

      else if(textura->Contador==4*timer){
        reposicionaViewTextura(0, 1, 0, .25+CorrigeAcimaRoll,textura);
        textura->Contador=0;
          }
      textura->Contador++;
      *RolamentoContadorFrames+=1;


      }

     //Pular
     else if(PularOn){
      reposicionaViewTextura(.33+CorrigeAtras, .50+CorrigeFrente ,0+CorrigeAbaixo+.06, 1+CorrigeAcima,textura);
      }


      // MOVIMENTACAO NORMAL
      else{
        if(textura->Contador==1)
        reposicionaViewTextura(0+CorrigeAtras,.17+CorrigeFrente, 0+CorrigeAbaixo, 1+CorrigeAcima+CorrigeAcima,textura);

        else if(textura->Contador==2)
        reposicionaViewTextura(.17+CorrigeAtras,.33+CorrigeFrente, 0+CorrigeAbaixo, 1+CorrigeAcima,textura);

        else if(textura->Contador==3)
        reposicionaViewTextura(.33+CorrigeAtras, .50+CorrigeFrente ,0+CorrigeAbaixo, 1+CorrigeAcima,textura);

        else if(textura->Contador==4)
        reposicionaViewTextura(.50+CorrigeAtras ,.67+CorrigeFrente ,0+CorrigeAbaixo, 1+CorrigeAcima,textura);

        else if(textura->Contador==5)
        reposicionaViewTextura(.67+CorrigeAtras , .83+CorrigeFrente, 0+CorrigeAbaixo, 1+CorrigeAcima,textura);

        else if(textura->Contador==6){
        reposicionaViewTextura(.83+CorrigeAtras , 1+CorrigeFrente, 0+CorrigeAbaixo, 1+CorrigeAcima,textura);
        textura->Contador=0;
        }
        textura->Contador++;
      }

      glutPostRedisplay();


  }
}




void Animacao_Textura_Lobo(textura_animacao *textura){
  int timer =1.5;
  float CorrigePraFrente = .0075;
  float CorrigePraTras = .01;
  float CorrigePraCima = .1;
    if(textura->Contador==1*timer)
    reposicionaViewTextura(.0+CorrigePraFrente,.25-CorrigePraTras,0,1-CorrigePraCima,textura);

    else if(textura->Contador==2*timer)
    reposicionaViewTextura(.25+CorrigePraFrente,.5-CorrigePraTras,0,1-CorrigePraCima,textura);


    else if(textura->Contador==3*timer)
      reposicionaViewTextura(.5+CorrigePraFrente,.75-CorrigePraTras,0,1-CorrigePraCima,textura);

    else if(textura->Contador==4*timer){
      reposicionaViewTextura(.75+CorrigePraFrente,1,0,1-CorrigePraCima-.05,textura);
      textura->Contador=0;
    }
      textura->Contador++;

   glutPostRedisplay();



}

void Animacao_Textura_Goomba(textura_animacao *textura){
  float timer = 1;

  if(textura->Contador==1*timer)
    reposicionaViewTextura(0,.111,0,1,textura);
  if(textura->Contador==2*timer)
    reposicionaViewTextura(.222,.333,0,1,textura);
  if(textura->Contador==3*timer)
    reposicionaViewTextura(.444,.555,0,1,textura);
  if(textura->Contador==4*timer)
    reposicionaViewTextura(.666,.777,0,1,textura);
  if(textura->Contador==5*timer){
    reposicionaViewTextura(.888,.999,0,1,textura);
    textura->Contador = 0;
  }

  textura->Contador++;


}

void Animacao_Textura_MutantCrab(textura_animacao *textura){
  int timer = 1;
  float ConcertaDireita = .05;
  float ConcertaEsquerda = -.06;
  float ConcertaCima = -.04;

  if(textura->Contador==1*timer)
    reposicionaViewTextura(0+ConcertaDireita,.25+ConcertaEsquerda,0,1+ConcertaCima,textura);
  if(textura->Contador==2*timer)
    reposicionaViewTextura(.25+ConcertaDireita,.5+ConcertaEsquerda,0,1+ConcertaCima+ConcertaCima,textura);
  if(textura->Contador==3*timer)
    reposicionaViewTextura(.5+ConcertaDireita,.75+ConcertaEsquerda,0,1+ConcertaCima,textura);
  if(textura->Contador==4*timer){
    reposicionaViewTextura(.75+ConcertaDireita,1+ConcertaEsquerda,0,1+ConcertaCima,textura);
    textura->Contador = 0;
  }

  textura->Contador++;



}

void Animacao_Textura_OlhoVoador(textura_animacao *textura){
  int timer = 1;
  float ConcertaDireita = .0;
  float ConcertaEsquerda = -.0;
  float ConcertaCima = -.03;

  if(textura->Contador==1*timer)
    reposicionaViewTextura(0+ConcertaDireita,.132231405+ConcertaEsquerda,0,1+ConcertaCima,textura);
  if(textura->Contador==2*timer)
    reposicionaViewTextura(.299357208+ConcertaDireita,.426997245+ConcertaEsquerda,0,1+ConcertaCima+ConcertaCima,textura);
  if(textura->Contador==3*timer)
    reposicionaViewTextura(.59687787+ConcertaDireita,.723599633+ConcertaEsquerda,0,1+ConcertaCima,textura);
  if(textura->Contador==4*timer){
    reposicionaViewTextura(.899908173+ConcertaDireita,1+ConcertaEsquerda,0,1+ConcertaCima,textura);
  textura->Contador = 0;
  }

  textura->Contador++;
}


void Animacao_Textura_MoedaGoldCoin(textura_animacao *textura){
  int timer = 1;
    if(textura->Contador==1*timer)
      reposicionaViewTextura(0,.126911315,0,1,textura);
    if(textura->Contador==2*timer)
      reposicionaViewTextura(.162079511,.285932722,0,1,textura);
    if(textura->Contador==3*timer)
      reposicionaViewTextura(.316513761,.432721713,0,1,textura);
    if(textura->Contador==4*timer)
      reposicionaViewTextura(.440366972,.558103976,0,1,textura);
    if(textura->Contador==5*timer)
      reposicionaViewTextura(.558103976,.625382263,0,1,textura);
    if(textura->Contador==6*timer)
      reposicionaViewTextura(.625382263,.709480122,0,1,textura);
    if(textura->Contador==7*timer)
      reposicionaViewTextura(.74617737,.850152905,0,1,textura);
    if(textura->Contador==8*timer){
      reposicionaViewTextura(.877675841,1,0,1,textura);
      textura->Contador = 0;
    }

  textura->Contador++;

}


void Animacao_Textura_CaveiraFogo(textura_animacao *textura){
  int timer = 2;
    if(textura->Contador==1*timer)
      reposicionaViewTextura(0,.125,0,1,textura);
    if(textura->Contador==2*timer)
      reposicionaViewTextura(.125,.250,0,1,textura);
    if(textura->Contador==3*timer)
      reposicionaViewTextura(.250,.375,0,1,textura);
    if(textura->Contador==4*timer)
      reposicionaViewTextura(.375,.5,0,1,textura);
    if(textura->Contador==5*timer)
      reposicionaViewTextura(.5,.625,0,1,textura);
    if(textura->Contador==6*timer)
      reposicionaViewTextura(.625,.750,0,1,textura);
    if(textura->Contador==7*timer)
      reposicionaViewTextura(.750,.875,0,1,textura);
    if(textura->Contador==8*timer){
      reposicionaViewTextura(.875,1,0,1,textura);
      textura->Contador = 0;
    }

  textura->Contador++;

}

void Animacao_Textura_CaveiraSemFogo(textura_animacao *textura){
  int timer = 1;
    if(textura->Contador==1*timer)
      reposicionaViewTextura(0,.25,0,1,textura);
    if(textura->Contador==2*timer)
      reposicionaViewTextura(.25,.5,0,1,textura);
    if(textura->Contador==3*timer)
      reposicionaViewTextura(.5,.75,0,1,textura);
    if(textura->Contador==4*timer){
      reposicionaViewTextura(.75,1,0,1,textura);
      textura->Contador = 0;
    }

  textura->Contador++;

}

void Animacao_Textura_LostVikingsSoldier(textura_animacao *textura){
  int timer = 1;
    if(textura->Contador==1*timer)
      reposicionaViewTextura(0,.1531,0,1,textura);
    if(textura->Contador==2*timer)
      reposicionaViewTextura(.163265306,.357142857,0,1,textura);
    if(textura->Contador==3*timer)
      reposicionaViewTextura(.367346939,.5,0,1,textura);
    if(textura->Contador==4*timer)
      reposicionaViewTextura(.510204082,.683673469,0,1,textura);
    if(textura->Contador==5*timer)
      reposicionaViewTextura(.683673469,.867346939,0,1,textura);
    if(textura->Contador==6*timer){
      reposicionaViewTextura(.867346939,1,0,1,textura);
      textura->Contador = 0;
    }

  textura->Contador ++;

 }



 void Animacao_Textura_AnimaniacsPolicialGordo(textura_animacao *textura){
   int timer = 1;
     if(textura->Contador==1*timer)
     reposicionaViewTextura(.771523179,1,0,1,textura);
     if(textura->Contador==2*timer)
     reposicionaViewTextura(.5033,.748344371,0,1,textura);
     if(textura->Contador==3*timer)
       reposicionaViewTextura(.261589404,.4901,0,1,textura);
     if(textura->Contador==4*timer){
       reposicionaViewTextura(.003311258,.238410596,0,1,textura);
       textura->Contador = 0;
     }

   textura->Contador ++;

 }


 void Animacao_Textura_DonaldArabian(textura_animacao *textura){
   int timer = 1;
     if(textura->Contador==1*timer)
     reposicionaViewTextura(.879396985,.989949749,0,1,textura);
     if(textura->Contador==2*timer)
     reposicionaViewTextura(.7513,.8643,0,1,textura);
     if(textura->Contador==3*timer)
       reposicionaViewTextura(.633165829,.748743719,0,1,textura);
     if(textura->Contador==4*timer)
       reposicionaViewTextura(.5,.6181,0,1,textura);
     if(textura->Contador==5*timer)
       reposicionaViewTextura(.379396985,.497487437,0,1,textura);
     if(textura->Contador==6*timer)
       reposicionaViewTextura(.251256281,.364321608,0,1,textura);
     if(textura->Contador==7*timer)
       reposicionaViewTextura(.128140704,.246231156,0,1,textura);
     if(textura->Contador==8*timer){
       reposicionaViewTextura(0,.120603015,0,1,textura);
       textura->Contador = 0;
     }

   textura->Contador ++;

 }


 void Animacao_Textura_DemonioFudendoVoador(textura_animacao *textura){
   int timer = 1;

     if(textura->Contador==1*timer)
     reposicionaViewTextura(0,.1667,0,1,textura);
     if(textura->Contador==2*timer)
     reposicionaViewTextura(.1667,.333333333,0,1,textura);
     if(textura->Contador==3*timer)
       reposicionaViewTextura(.333333333,.5,0,1,textura);
     if(textura->Contador==4*timer)
       reposicionaViewTextura(.5,.6667,0,1,textura);
     if(textura->Contador==5*timer)
       reposicionaViewTextura(.6667,.833333333,0,1,textura);
     if(textura->Contador==6*timer){
       reposicionaViewTextura(.833333333,1,0,1,textura);
       textura->Contador = 0;
     }

   textura->Contador ++;

 }

 void Animacao_Textura_RolyPoly(textura_animacao *textura){

   int timer = 1;

     if(textura->Contador==1*timer)
     reposicionaViewTextura(.806818182,1,0,1,textura);
     if(textura->Contador==2*timer)
     reposicionaViewTextura(.397727273,.590909091,0,1,textura);
     if(textura->Contador==3*timer){
       reposicionaViewTextura(0,.204545455,0,1,textura);
       textura->Contador = 0;
     }
      textura->Contador ++;

 }






 //Moeda do Sonic
 void Animacao_Textura_MoedaRing(textura_animacao *textura){

   int timer = 2;

   if(textura->Contador==1*timer)
   reposicionaViewTextura(0,.25,.75,1,textura);

   else if(textura->Contador==2*timer)
   reposicionaViewTextura(0,.25,.50,0.75,textura);

   else if(textura->Contador==3*timer)
   reposicionaViewTextura(0,.25,.25,.50,textura);

   else if(textura->Contador==4*timer){
   reposicionaViewTextura(0,.25,0,.25,textura);
   textura->Contador=0;
   }

   textura->Contador++;

   // glutPostRedisplay();



 }
