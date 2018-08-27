#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Base: {

int init=1;//Somente para a inicialização(TESTE).
int MovimentarOn=0; //Define se o movimento esta ativo (Tecla C) (TESTE)
int ColisaoObjeto=0;

int PularOn = 0;

int timer =24;

int theEnd = 0;

float velocidade = 3;

float oldpulo;
float pulo = 5; //o quanto eu vou pra cima no y (variação do y)
float incPulo = 0.5; //incremento no y (variação da variação)

float aspect; //Ainda não mexi, para arrumar o AspectRatio(TESTE).

typedef struct Quadrado{
    float x;
    float y;
    //int id;//Identificar o quadrado;
    float tx;
    float ty;
    float r,g,b; //Cores

}quadrado;

quadrado q1,q2,q3,q4;


//



//Funções Base: {
void posQuadrado(quadrado* a ,float xa,float ya ){
    a->x = xa;
    a->y = ya;
    //a.id = ida;
}

void tamQuadrado(quadrado* a,float xa, float ya){
    a->tx = xa;
    a->ty = ya;

}

void corQuadrado(quadrado *a,float r,float g,float b){
  a->r = r;
  a->g = g;
  a->b = b;

}

//}
void texto(void* font, char* s, float x, float y){
  unsigned int i;
  glRasterPos2f(x, y);

  for (i=0; i<strlen(s); i++){
      glutBitmapCharacter(font, s[i]);
    }
}

void telaFim(){
glColor4f(0, 0, 0, 0.1);

glBegin(GL_POLYGON);

  glVertex2d(0, 0);
  glVertex2d(0, 100);
  glVertex2d(100, 100);
  glVertex2d(100, 0);

glEnd();

glColor3f(0, 0, 0);
texto(GLUT_BITMAP_HELVETICA_18, "PERDEU OTARIO!", 25, 50);


}

void verificaColisao(quadrado *a){
  if(q1.x+q1.tx >= a->x && q1.y<=a->y+a->ty){
    MovimentarOn = 0;
    theEnd = 1;

  }

  if(q1.y<= a->y+a->ty && q1.x+q1.tx>= a->x){
    MovimentarOn = 0;
    theEnd = 1;
  }

}


void verificaPosicao(quadrado *a){
  //REPOSICIONA INIMIGOS
  //Reposicionar o objeto caso ele tenha saido de Cena (para os quadrados "inimigos"),
  //if(a-> < tamMundo) //Mudar depois para variável global
  if( a->x < -10 )
    //Gerar uma distancia aleatoria do spawn
    posQuadrado(a,100,30);


}



//             (quadrado, velocidade)
void movimenta(){
  q2.x-=velocidade;
  q3.x-=velocidade;
  q4.x-=velocidade;

}

void puloBackup(){
  oldpulo = pulo;
}



void resetPulo(){
  pulo = oldpulo;
  PularOn = 0;
}


void pular(){

    q1.y+=pulo;
    pulo-=incPulo;

//Verifica se o jogador chegou na altura do chão (TESTE) (MODIFICAR)
  if(q1.y<=31){
    resetPulo();

  }
}




void atualiza(int timer){
//MovimentarOn para controlar se o movimento está ativo ou não
  if (MovimentarOn==1){
      movimenta();

//PularOn para controlar se o pulo está ativo ou não
  if(PularOn==1)
    pular();
  }

  glutPostRedisplay();
  glutTimerFunc(timer,atualiza,timer);

}

void desenhaQuadrado(quadrado* a){
    glColor3f(a->r,a->g,a->b);


    //Para nao verificar a colisão no próprio q1(MODIFICAR)
    if(a!=&q1)
    verificaColisao(a);
    verificaPosicao(a);

    glBegin(GL_TRIANGLE_FAN);

      glVertex2d(a->x , a->y);
      glVertex2d(a->x + a->tx, a->y);
      glVertex2d(a->x + a->tx, a->y + a->ty);
      glVertex2d(a->x , a->y + a->ty);

    glEnd();


}



void desenhaCena(){
  glClear(GL_COLOR_BUFFER_BIT);
  //glColor3f(.1,.2,1);

  glEnable(GL_BLEND); // teste pra opacidade
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  desenhaQuadrado(&q1);
  desenhaQuadrado(&q2);
   // desenhaQuadrado(&q3);
   // desenhaQuadrado(&q4);

//Verifica o se o jogador perdeu ou não, indo pro tela do fim (GAME-OVER) (MODIFICAR)
 if (theEnd==1)
     telaFim();

  glutSwapBuffers();

}


void redimensiona(int width, int height){
  aspect = width/height;
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0,100*aspect,0,100*aspect,-1,1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


}


void initQuadrado(){
//Para inicializar o quadrado somente uma vez. Podendo atualizar ele sem preocupações
  if (init==1){
    puloBackup(); //Guarda o valor inicial de pulo
  init++;
  tamQuadrado(&q1,10,15);
  posQuadrado(&q1,0,30);
  corQuadrado(&q1,1,1,1);

  tamQuadrado(&q2,10,10);
  posQuadrado(&q2,90,30);
  corQuadrado(&q2,.1,.3,.9);

  tamQuadrado(&q3,10,10);
  posQuadrado(&q3,120,30);
  corQuadrado(&q3,.8,.5,.1);

  tamQuadrado(&q4,10,10);
  posQuadrado(&q4,150,30);
  corQuadrado(&q4,.8,.3,.9);

  }
}


void resetAll(){    //Da para colocar um variavel para avisar se volta em movimento ou nao
  theEnd = 0;
  resetPulo();
  init = 1;
  MovimentarOn = 0;
  initQuadrado();
  glutPostRedisplay();
}




void keyboard(unsigned char key, int x, int y){

  switch (key){
    case 27:
      exit(0);
      break;

    case 'c':
    case 'C':
      //Nao liberar movimento enquanto em tela de morte (TESTE) (DESATIVADO)
     if(theEnd==0){
      if(MovimentarOn==0)
        MovimentarOn=1;
      else
        MovimentarOn=0;
    }
      //glutPostRedisplay();
      break;

      // Tela de Fim de Jogo
      case 13: //Enter
      if(theEnd==1){
        resetAll();
      }
    break;

    //Reset em qualquer momento
    case 'r':
    case 'R':
      resetAll();
    break;

    case 32:
    if(MovimentarOn){
      if(PularOn==0)
        PularOn=1;
    }
      break;

    default:
      break;


  }

}

void inicializa(){
  glClearColor(.9,.9,.9,0);
}


int main(int argc, char**argv){
  //Inicializar o glut
  glutInit(&argc,argv);

  //Configurações de inicialização do glut
  glutInitContextVersion(1,1);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  //Configurações da Janela
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(400,400);
  glutInitWindowPosition(100,100);

  //Abrir(criar) Janela
  glutCreateWindow("Teste");
  inicializa();


  //Callbacks
  initQuadrado();
  glutDisplayFunc(desenhaCena);
  glutReshapeFunc(redimensiona);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(timer,atualiza,timer);

  glutMainLoop();
  return 0;

}
