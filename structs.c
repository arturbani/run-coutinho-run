#include <string.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Bibliotecas/structs.h"





// Função Especifica para o Jogador
void PropriedadesQuadrado(quadrado * q1, GLuint backup, GLuint rolamento, GLuint pulo, GLuint morte){
q1->jogador.backup = backup;
q1->jogador.rolamento = rolamento;
q1->jogador.pulo = pulo;
q1->jogador.morte = morte;

}


//Funções Base/Genéricas (Para qualquer quadrado):

//Objeto Manipulado + Novo Nome
void nomeQuadrado(quadrado*Objeto, char* Novo_Nome){
  strcpy(Objeto->nome,Novo_Nome);
}


//Objeto Manipulado + Nova Coord X e Nova Coord Y
void posQuadrado(quadrado* Objeto ,float Novo_X,float Novo_Y ){
    Objeto->x = Novo_X;
    Objeto->y = Novo_Y;
}
//Objeto Manipulado + Novo Tamanho no Eixo X(Tx) e Novo Tamanho no Eixo Y (Ty)
void tamQuadrado(quadrado* Objeto,float Novo_Tx, float Novo_Ty){
    Objeto->tx = Novo_Tx;
    Objeto->ty = Novo_Ty;

}

//Objeto Manipulado + cores R,G,B
void corQuadrado(quadrado *Objeto,float r,float g,float b){
  Objeto->r = r;
  Objeto->g = g;
  Objeto->b = b;

}

//Realiza um Link entre dois Objetos(Liga Dois Quadrados formando uma Lista Encadeada)
void linkQuadrado(quadrado *Objeto1, quadrado*Objeto2){
  Objeto1->proxquadrado = Objeto2;


}
//Acaba o Link(Fim_da_Lista_Encadeada) entre os Quadrados
void linkEnd(quadrado *Objeto1){
  Objeto1->proxquadrado = NULL;
}



void texturaQuadrado(quadrado *a, GLuint type){
    a->textura = type;
    a->animacao.Contador = 1;
    a->animacao.X_Inicio_Textura = 0;
    a->animacao.X_Final_Textura = 1;
    a->animacao.Y_Inicio_Textura = 0;
    a->animacao.Y_Final_Textura = 1;
}



//Funções Moeda:

void initAsMoeda(quadrado *a){
//Atribuir Classe: Quadrado como Subclasse: Moeda
  a->isMoeda = 1;
//Desatribuir das demais Classes: (Ou é moeda ou inimigo, não pode ser os 2)
  a->isInimigo = 0;
  a->isFundo = 0;
  a->isJogador = 0;
  a->isPowerUp = 0;

  a->visivel = 1; //A moeda vai estar de inicio visivel pro jogador
  a->colidivel = 1;

}

//Funcao para colisao da moeda
void colisaoMoeda(quadrado *a,int *score){
   // a->visivel = 0;
   a->x = -30;

  *score+=1000;
  // printf("PegueiMoeda:%i\n",*score);
//Highscore ++

  //Reset da colisão dentro da main
}



//Inimigo:

//Inicialização como Inimigo
void initAsInimigo(quadrado *a){
//Atribuição Classe: Quadrado Atribuir Subclasse: Inimigo
  a->isInimigo = 1;
//Desatribuir demais Classes:
  a->isMoeda = 0;
  a->isFundo = 0;
  a->isJogador = 0;
  a->isPowerUp = 0;

  a->visivel = 1; //Inimigo sempre visivel
  a->colidivel = 1;


}



//O efeito da colisão com Inimigo
void colisaoInimigo(quadrado *a){
  // GameOver();


}


//Jogador
void initAsJogador(quadrado *a){


  a->isJogador = 1;

  a->isInimigo = 0;
  a->isMoeda = 0;
  a->isFundo = 0;
  a->isPowerUp = 0;

  a->visivel = 1;
  a->colidivel = 0;



}

//isPowerUp(Não Implementado)
void initAsPowerUp(quadrado *a){

  a->isPowerUp = 1;

  a->isInimigo = 0;
  a->isMoeda = 0;
  a->isFundo = 0;
  a->isJogador = 0;

  a->visivel = 1;
  a->colidivel = 1;




}





//Fundo:

//Inicializacao como Fundo
void initAsFundo(quadrado *a){

   a->isFundo = 1;

  a->isMoeda = 0;
  a->isInimigo = 0;
  a->isJogador = 0;
  a->isPowerUp = 0;

  a->visivel = 1;
  a->colidivel = 0;


}
