#include "Bibliotecas/library.h"

void overlay_cinza(){
    //tela cinza no fundo
    glDisable(GL_TEXTURE_2D);

    glColor4f(0, 0, 0, 0.2);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        glVertex2f(160, 0);
        glVertex2f(160, 90);
        glVertex2f(0, 90);

    glEnd();

    glEnable(GL_TEXTURE_2D);
    glColor4f(1, 1, 1, 1);

}

void pausa(int contador_seta, GLuint Textura_Popup, GLuint Textura_Texto_Pause, GLuint Textura_Voltar_Jogo, 
            GLuint Textura_Texto_Reiniciar, GLuint Textura_Texto_Menu, GLuint Textura_Texto_Sair, GLuint Textura_Seletor){

    overlay_cinza();

    //desenha popup
    glBindTexture(GL_TEXTURE_2D, Textura_Popup);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(40, 15,  0);
        glTexCoord2f(1, 0);  glVertex3f(120, 15,  0);
        glTexCoord2f(1, 1);  glVertex3f(120, 75,  0);
        glTexCoord2f(0, 1);  glVertex3f(40, 75,  0);

    glEnd();

    //desenha texto do pause

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Pause);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(67.5, 65,  0);
        glTexCoord2f(1, 0);  glVertex3f(92.5, 65,  0);
        glTexCoord2f(1, 1);  glVertex3f(92.5, 70,  0);
        glTexCoord2f(0, 1);  glVertex3f(67.5, 70,  0);

    glEnd();

    // opçoes
    glBindTexture(GL_TEXTURE_2D, Textura_Voltar_Jogo);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(59, 40, 0);
        glTexCoord2f(1, 0);  glVertex3f(101, 40, 0);
        glTexCoord2f(1, 1);  glVertex3f(101, 43, 0);
        glTexCoord2f(0, 1);  glVertex3f(59, 43, 0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Reiniciar);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(66.5, 35,  0);
        glTexCoord2f(1, 0);  glVertex3f(93.5, 35,  0);
        glTexCoord2f(1, 1);  glVertex3f(93.5, 38,  0);
        glTexCoord2f(0, 1);  glVertex3f(66.5, 38,  0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Menu); 
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(62, 30,  0);
        glTexCoord2f(1, 0);  glVertex3f(98, 30,  0);
        glTexCoord2f(1, 1);  glVertex3f(98, 33,  0);
        glTexCoord2f(0, 1);  glVertex3f(62, 33,  0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Sair);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(62, 25,  0);
        glTexCoord2f(1, 0);  glVertex3f(98, 25,  0);
        glTexCoord2f(1, 1);  glVertex3f(98, 28,  0);
        glTexCoord2f(0, 1);  glVertex3f(62, 28,  0);

    glEnd();

    //agora cuido da seleção das opções com a setinha
    glBindTexture(GL_TEXTURE_2D, Textura_Seletor);
        if (contador_seta==1){ // voltar ao jogo
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(51, 40,  0);
                glTexCoord2f(1, 0);  glVertex3f(56, 40,  0);
                glTexCoord2f(1, 1);  glVertex3f(56, 43,  0);
                glTexCoord2f(0, 1);  glVertex3f(51, 43,  0);

            glEnd();
        }

        if (contador_seta==2){ // restart
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(58.5, 35,  0);
                glTexCoord2f(1, 0);  glVertex3f(63.5, 35,  0);
                glTexCoord2f(1, 1);  glVertex3f(63.5, 38,  0);
                glTexCoord2f(0, 1);  glVertex3f(58.5, 38,  0);

            glEnd();

        }

        if (contador_seta==3){ // voltar ao menu inicial
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(54, 30,  0);
                glTexCoord2f(1, 0);  glVertex3f(59, 30,  0);
                glTexCoord2f(1, 1);  glVertex3f(59, 33,  0);
                glTexCoord2f(0, 1);  glVertex3f(54, 33,  0);

            glEnd();
        }

        if (contador_seta==4){
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(54, 25,  0);
                glTexCoord2f(1, 0);  glVertex3f(59, 25,  0);
                glTexCoord2f(1, 1);  glVertex3f(59, 28,  0);
                glTexCoord2f(0, 1);  glVertex3f(54, 28,  0);

            glEnd();

        }
}

void confirmacao(int contador_seletor, char acao, int * sair, GLuint Textura_Popup, GLuint Textura_Seletor, 
                GLuint Textura_Texto_Confirmacao, GLuint Textura_BotaoS, GLuint Textura_BotaoN){
    overlay_cinza();

    //desenha popup
        glBindTexture(GL_TEXTURE_2D, Textura_Popup);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(50, 25,  0);
            glTexCoord2f(1, 0);  glVertex3f(110, 25,  0);
            glTexCoord2f(1, 1);  glVertex3f(110, 65,  0);
            glTexCoord2f(0, 1);  glVertex3f(50, 65,  0);

        glEnd();

    //texto confirma 
        glBindTexture(GL_TEXTURE_2D, Textura_Texto_Confirmacao);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(53, 45,  0);
            glTexCoord2f(1, 0);  glVertex3f(107, 45,  0);
            glTexCoord2f(1, 1);  glVertex3f(107, 48,  0);
            glTexCoord2f(0, 1);  glVertex3f(53, 48,  0);

        glEnd();

    //botoes
        glBindTexture(GL_TEXTURE_2D, Textura_BotaoS);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(57.5, 30,  0);
            glTexCoord2f(1, 0);  glVertex3f(77.5, 30,  0);
            glTexCoord2f(1, 1);  glVertex3f(77.5, 40,  0);
            glTexCoord2f(0, 1);  glVertex3f(57.5, 40,  0);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, Textura_BotaoN);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(82.5, 30,  0);
            glTexCoord2f(1, 0);  glVertex3f(102.5, 30,  0);
            glTexCoord2f(1, 1);  glVertex3f(102.5, 40,  0);
            glTexCoord2f(0, 1);  glVertex3f(82.5, 40,  0);

        glEnd();

    //seletor
        glBindTexture(GL_TEXTURE_2D, Textura_Seletor);
        if(contador_seletor==1){
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(57.5, 30,  0);
            glTexCoord2f(1, 0);  glVertex3f(77.5, 30,  0);
            glTexCoord2f(1, 1);  glVertex3f(77.5, 40,  0);
            glTexCoord2f(0, 1);  glVertex3f(57.5, 40,  0);

        glEnd();
        }

        if(contador_seletor==2){
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(82.5, 30,  0);
            glTexCoord2f(1, 0);  glVertex3f(102.5, 30,  0);
            glTexCoord2f(1, 1);  glVertex3f(102.5, 40,  0);
            glTexCoord2f(0, 1);  glVertex3f(82.5, 40,  0);

        glEnd();

        }

        *sair=1;

}

void tela_morte(int contador_seta, int score, GLuint Textura_Popup, GLuint Textura_Texto_GameOver,
                 GLuint Textura_Texto_Retry, GLuint Textura_Texto_Menu, GLuint Textura_Texto_Sair,
                 GLuint Textura_Seletor, GLuint Textura_Score){
    overlay_cinza();

    //desenha popup
    glBindTexture(GL_TEXTURE_2D, Textura_Popup);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(40, 15,  0);
        glTexCoord2f(1, 0);  glVertex3f(120, 15,  0);
        glTexCoord2f(1, 1);  glVertex3f(120, 75,  0);
        glTexCoord2f(0, 1);  glVertex3f(40, 75,  0);

    glEnd();

    //desenha texto de fim de jogo
    glBindTexture(GL_TEXTURE_2D, Textura_Texto_GameOver);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(57.5, 65,  0);
        glTexCoord2f(1, 0);  glVertex3f(102.5, 65,  0);
        glTexCoord2f(1, 1);  glVertex3f(102.5, 70,  0);
        glTexCoord2f(0, 1);  glVertex3f(57.5, 70,  0);

    glEnd();
    
    //mostra score
    glBindTexture(GL_TEXTURE_2D, Textura_Score);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(68, 55,  0);
        glTexCoord2f(1, 0);  glVertex3f(92, 55,  0);
        glTexCoord2f(1, 1);  glVertex3f(92, 59,  0);
        glTexCoord2f(0, 1);  glVertex3f(68, 59,  0);

    glEnd();

    // mostraScore(score, 70, 40);

    //opcoes
    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Retry);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(56, 35, 0);
        glTexCoord2f(1, 0);  glVertex3f(104, 35, 0);
        glTexCoord2f(1, 1);  glVertex3f(104, 38, 0);
        glTexCoord2f(0, 1);  glVertex3f(56, 38, 0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Menu); 
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(62, 30,  0);
        glTexCoord2f(1, 0);  glVertex3f(98, 30,  0);
        glTexCoord2f(1, 1);  glVertex3f(98, 33,  0);
        glTexCoord2f(0, 1);  glVertex3f(62, 33,  0);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Sair);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(62, 25,  0);
        glTexCoord2f(1, 0);  glVertex3f(98, 25,  0);
        glTexCoord2f(1, 1);  glVertex3f(98, 28,  0);
        glTexCoord2f(0, 1);  glVertex3f(62, 28,  0);

    glEnd();

    //agora cuido da seleção das opções com a setinha
    glBindTexture(GL_TEXTURE_2D, Textura_Seletor);
        if (contador_seta==1){ // retry
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(48, 35,  0);
                glTexCoord2f(1, 0);  glVertex3f(53, 35,  0);
                glTexCoord2f(1, 1);  glVertex3f(53, 38,  0);
                glTexCoord2f(0, 1);  glVertex3f(48, 38,  0);

            glEnd();

        }

        if (contador_seta==2){ // voltar ao menu inicial
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(54, 30,  0);
                glTexCoord2f(1, 0);  glVertex3f(59, 30,  0);
                glTexCoord2f(1, 1);  glVertex3f(59, 33,  0);
                glTexCoord2f(0, 1);  glVertex3f(54, 33,  0);

            glEnd();
        }

        if (contador_seta==3){
            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0, 0);  glVertex3f(54, 25,  0);
                glTexCoord2f(1, 0);  glVertex3f(59, 25,  0);
                glTexCoord2f(1, 1);  glVertex3f(59, 28,  0);
                glTexCoord2f(0, 1);  glVertex3f(54, 28,  0);

            glEnd();

        }

}

void controle(int contador, GLuint Textura_Popup, GLuint Textura_WASD, GLuint Textura_Espaco,
              GLuint Textura_ESC, GLuint Textura_Texto_WASD, GLuint Textura_Texto_Espaco,
              GLuint Textura_Texto_ESC, GLuint Textura_Texto_Aperte){
    

    overlay_cinza();

    //desenha popup
    glBindTexture(GL_TEXTURE_2D, Textura_Popup);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(40, 15,  0);
        glTexCoord2f(1, 0);  glVertex3f(120, 15,  0);
        glTexCoord2f(1, 1);  glVertex3f(120, 75,  0);
        glTexCoord2f(0, 1);  glVertex3f(40, 75,  0);

    glEnd();

    // animacao WASD improviso
    if (contador<9){
        glBindTexture(GL_TEXTURE_2D, Textura_WASD);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0.5);  glVertex3f(56, 55,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(71, 55,  0);
            glTexCoord2f(1, 1);  glVertex3f(71, 65,  0);
            glTexCoord2f(0, 1);  glVertex3f(56, 65,  0);
        glEnd();

    }

    else if (contador<17){
        glBindTexture(GL_TEXTURE_2D, Textura_WASD);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(56, 55,  0);
            glTexCoord2f(1, 0);  glVertex3f(71, 55,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(71, 65,  0);
            glTexCoord2f(0, 0.5);  glVertex3f(56, 65,  0);
        glEnd();

        
    }

    // animacao barra de escpaco
    if (contador<9){
        glBindTexture(GL_TEXTURE_2D, Textura_Espaco);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0.5);  glVertex3f(50, 45,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(77, 45,  0);
            glTexCoord2f(1, 1);  glVertex3f(77, 50,  0);
            glTexCoord2f(0, 1);  glVertex3f(50, 50,  0);
        glEnd();

    }

    else if (contador<17){
        glBindTexture(GL_TEXTURE_2D, Textura_Espaco);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(50, 45,  0);
            glTexCoord2f(1, 0);  glVertex3f(77, 45,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(77, 50,  0);
            glTexCoord2f(0, 0.5);  glVertex3f(50, 50,  0);
        glEnd();
    }

    // animacao esc
    if (contador<9){
        glBindTexture(GL_TEXTURE_2D, Textura_ESC);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0.5);  glVertex3f(60, 35,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(67, 35,  0);
            glTexCoord2f(1, 1);  glVertex3f(67, 40,  0);
            glTexCoord2f(0, 1);  glVertex3f(60, 40,  0);
        glEnd();

    }

    else if (contador<17){
        glBindTexture(GL_TEXTURE_2D, Textura_ESC);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(60, 35,  0);
            glTexCoord2f(1, 0);  glVertex3f(67, 35,  0);
            glTexCoord2f(1, 0.5);  glVertex3f(67, 40,  0);
            glTexCoord2f(0, 0.5);  glVertex3f(60, 40,  0);
        glEnd();
    }

    // legendas
    glBindTexture(GL_TEXTURE_2D, Textura_Texto_WASD);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(85, 56,  0);
            glTexCoord2f(1, 0);  glVertex3f(100, 56,  0);
            glTexCoord2f(1, 1);  glVertex3f(100, 59,  0);
            glTexCoord2f(0, 1);  glVertex3f(85, 59,  0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, Textura_Texto_Espaco);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(85, 46,  0);
            glTexCoord2f(1, 0);  glVertex3f(100, 46,  0);
            glTexCoord2f(1, 1);  glVertex3f(100, 49,  0);
            glTexCoord2f(0, 1);  glVertex3f(85, 49,  0);
        glEnd();

    glBindTexture(GL_TEXTURE_2D, Textura_Texto_ESC);
        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0, 0);  glVertex3f(83.5, 36,  0);
            glTexCoord2f(1, 0);  glVertex3f(101.5, 36,  0);
            glTexCoord2f(1, 1);  glVertex3f(101.5, 39,  0);
            glTexCoord2f(0, 1);  glVertex3f(83.5, 39,  0);
        glEnd();
    
    // texto de saída
    glBindTexture(GL_TEXTURE_2D, Textura_Texto_Aperte);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(47, 25,  0);
        glTexCoord2f(1, 0);  glVertex3f(113, 25,  0);
        glTexCoord2f(1, 1);  glVertex3f(113, 28,  0);
        glTexCoord2f(0, 1);  glVertex3f(47, 28,  0);
    glEnd();
        
    
  
}

void tela_comecar(GLuint Textura_Texto_Start){
overlay_cinza();

glBindTexture(GL_TEXTURE_2D, Textura_Texto_Start);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(17.5, 42.5,  0);
        glTexCoord2f(1, 0);  glVertex3f(142.5, 42.5,  0);
        glTexCoord2f(1, 1);  glVertex3f(142.5, 47.5,  0);
        glTexCoord2f(0, 1);  glVertex3f(17.5, 47.5,  0);

    glEnd();

}
