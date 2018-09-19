#include "Bibliotecas/library.h"

// mostra qualquer texto na tela, na posição escolhida
void texto(void * font, char *s, float x, float y) {
    int i;
    glRasterPos2f(x, y);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

// converte o score de int para string
// função acabou inutil, descobri depois que existe sprintf, usei ela mesmo assim por orgulho
char *my_itoa(int num, char *str){
        if(str == NULL)
          return NULL;

        sprintf(str, "%d", num);
        return str;
}

void mostraScore(int score, float x, float y){

    char stringScore[50];
    my_itoa(score, stringScore);

    // gambiarra pro score sempre ficar na tela
    if (x>=10000){
      x-=5;
    }

    if (x>=100000){
      x-=5;
    }

    
    texto(GLUT_BITMAP_TIMES_ROMAN_24, stringScore , x, y);
  
    // glutSwapBuffers();

  }


