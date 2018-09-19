#include "Bibliotecas/library.h"

//Essa função Inicializa o Glut
void inicializaOGlut(int argc,char**argv){
    //Inicializar o glut
    glutInit(&argc,argv);

    //Configurações de inicialização do glut
    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //Configurações da Janela
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(480*2,270*2);
    // glutInitWindowPosition(100,100);
    glutInitWindowPosition(1200,50);


    //Abrir(criar) Janela
    glutCreateWindow("Run, Coutinho, Run!");
    // inicializa();

}


// int Enter = 0;
int main(int argc, char**argv){

  inicializaOGlut(argc,argv);

  srand(time(NULL));

  //Chama a função Jogo(), que é onde está o Jogo.
  Jogo();
     glutMainLoop();
  return 0;

}
