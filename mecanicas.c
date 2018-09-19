#include <stdio.h>
#include "Bibliotecas/structs.h"
#include "Bibliotecas/structs_functions.h"
#include "Bibliotecas/animacao.h"

/*Verifica se é possivel liberar o movimento*/
void verificarLiberarMovimento(int *theEnd,int* MovimentarOn, int MenuOn){
    if(MenuOn==0){
      if(*theEnd == 0){
          if(*MovimentarOn == 0)
              *MovimentarOn = 1;
          else
              *MovimentarOn = 0;
      }
    }
}


//Verifica se houve colisao com o Jogador.
void verificaColisao(quadrado *a, quadrado* Jogador,int *ColisaoOn){

float hitbox=1.5 ;
    //Eixo X e Eixo Y, respectivamente
    if( Jogador->x+Jogador->tx > a->x+hitbox && Jogador->x <= a->x+ a->tx-hitbox)
    if( (Jogador->y+Jogador->ty >= a->y+hitbox &&  Jogador->y <= a->y + a->ty-hitbox) )
        *ColisaoOn = 1;


}

//Guarda o valor original de pulo no oldpulo
void puloBackup(float *pulo, float*oldpulo){
  *oldpulo = *pulo;
}

//Após acabar o Pulo, reseta ele para os valores iniciais
void resetPulo(float *pulo, float*oldpulo, int* PularOn){
  *pulo = *oldpulo;
  *PularOn = 0;

}

//
void pular(quadrado *Jogador, float *pulo,float *oldpulo, float *incPulo,int *groundlevel,int *PularOn){

    Jogador->y+=*pulo;
    *pulo-=*incPulo;

    //Se o jogador chegar na altura do chão, para o pulo.
    if(Jogador->y<=*groundlevel)
        resetPulo(pulo,oldpulo,PularOn);

}



//Reseta o rolamento
void resetRolamento(quadrado *Objeto, GLuint Textura_Original, int TXOriginal,
                    int TYOriginal, int *RolamentoOn,int *RolamentoContadorFrames){
  if(*RolamentoOn>0){
    *RolamentoOn = 0;
    *RolamentoContadorFrames = 0;
    Objeto->tx = TXOriginal;
    Objeto->ty = TYOriginal;
    texturaQuadrado(Objeto,Textura_Original);
    reposicionaViewTextura(.83 , 1, 0, 1,&(Objeto->animacao));
    Objeto->animacao.Contador = 3;

  }
}

//Aumenta o score. Por tempo
void aumentaScore(int *score, int MovimentarOn ){
  if(MovimentarOn)
    *score+=200;
  // if(tempo>=2000);
  //   tempo-=500;
  printf("Score:%i\n",*score);
}




//Teste(Não implementado):
// Muda o tipo de corrida(mexendo nos valores MAX_RANDOM_SPAWN e MIN_DIST_SPAWN)- X: Valor recebido pelo glutTimerFunc( Tempo para chamar a função)
void  mudaCorrida(int *Tempo,int *MIN_DIST_SPAWN,int *MAX_RANDOM_SPAWN){
  printf("Mudando tipo de corrida:\n");
  if(*MIN_DIST_SPAWN == 100){
    *Tempo*=2; //Teste dobrar o tempo para chamar a função
    *MIN_DIST_SPAWN = 50;
    *MAX_RANDOM_SPAWN = 300;
  }
  else{
    *Tempo/=2; //Teste - dividir o tempo para chamar a função
    *MIN_DIST_SPAWN = 100;
    *MAX_RANDOM_SPAWN = 60;
  }
  // glutTimerFunc(*Tempo,chama_mudaCorrida,*Tempo);

}



/*Essa função retorna a posição X do objeto mais distante (Mais a direita
do jogador), para realizar o Respawn dos inimigos
Retorna somente a posição do INIMIGO mais distante, ou seja,
MOEDAS, FUNDOS e AFINS, não são consideradas nesse calculo
*/
float posMaisDistante(quadrado *Primeiro_Quadrado){
  float Distancia = Primeiro_Quadrado->x;
  quadrado *Quadrado_Pointer = Primeiro_Quadrado; //Ponteiro iteração. Aponta para todos os quadrados
  do{                                  //   da Lista Encadeada.
    if(Quadrado_Pointer->isInimigo) //Moeda e fundo não conta, somente inimigos
    if( Quadrado_Pointer->x > Distancia)
    Distancia = Quadrado_Pointer->x;
    Quadrado_Pointer = Quadrado_Pointer->proxquadrado;
  }
  while ( Quadrado_Pointer != NULL);


  return Distancia;
}
