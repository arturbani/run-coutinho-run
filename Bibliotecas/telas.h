void overlay_cinza();

void pausa(int contador_seta, GLuint Textura_Popup, GLuint Textura_Texto_Pause, GLuint Textura_Voltar_Jogo, 
            GLuint Textura_Texto_Reiniciar, GLuint Textura_Texto_Menu, GLuint Textura_Texto_Sair, GLuint Textura_Seletor);

void confirmacao(int contador_seletor, char acao,  int * sair, GLuint Textura_Popup, GLuint Textura_Seletor, 
                GLuint Textura_Texto_Confirmacao, GLuint Textura_BotaoS, GLuint Textura_BotaoN);

void tela_morte(int contador_seta, int score, GLuint Textura_Popup, GLuint Textura_Texto_GameOver,
                 GLuint Textura_Texto_Retry, GLuint Textura_Texto_Menu, GLuint Textura_Texto_Sair, 
                 GLuint Textura_Seletor, GLuint Textura_Score);

void controle(int contador, GLuint Textura_Popup, GLuint Textura_WASD, GLuint Textura_Espaco,
              GLuint Textura_ESC, GLuint Textura_Texto_WASD, GLuint Textura_Texto_Espaco,
              GLuint Textura_Texto_ESC, GLuint Textura_Texto_Aperte);
              
void tela_comecar(GLuint Textura_Texto_Start);