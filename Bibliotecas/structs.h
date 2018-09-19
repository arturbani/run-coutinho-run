#include <GL/freeglut.h>

//animacao header (.h)
typedef struct Textura_Animacao{
  //Armazena os valores de X e Y para ser exibido do SpriteSheet.
  float X_Inicio_Textura,X_Final_Textura,Y_Inicio_Textura,Y_Final_Textura;
  int Contador; //Conta qual parte da animação de textura ele está. (Usado nas funções de Animação).


}textura_animacao;

typedef struct propriedades_jogador {
  /*Nao implementado. Os powerups e algumas propriedade a mais ficariam nessa parte.
  */
  // int InvencibilidadeOn;
  // int AllowDoubleJump
  // int DiminuirTempo;
  //
  GLuint rolamento;
  GLuint pulo;
  GLuint morte;
  GLuint backup;

}Propriedades_Jogador;


//Structs_Functions header (.h) (Para as funções genericas de qualquer quadrado)
typedef struct Quadrado{
  //Atributos Base: Servem para qualquer Quadrado:
    char nome [30];
    float x;
    float y;
    float tx;
    float ty;
    GLuint textura;
    textura_animacao animacao ;
    Propriedades_Jogador jogador;
    float r,g,b; //Cores
    struct Quadrado *proxquadrado;


  /*Atributos Específicos: Para cada "Subclasse", pensando na struct Quadrado,
  como uma Classe principal*/

  //Moedas:
    int isMoeda; //Identidade de Moeda ("Subclasse")

  //Inimigos:
    int isInimigo; //Identidade de Inimigo("Subclasse")

    int isJogador; //Identidade de Jogador("Subclasse")

  //Fundo:
    int isFundo;

  //PowerUp - 1:Invencilibidade 2:?
    int isPowerUp;


    int visivel;   //Define se pode Desenhar
    int colidivel; //Define se pode Colidir


}quadrado;
