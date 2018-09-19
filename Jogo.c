
#include "Bibliotecas/library.h"

//Inicialização do programa
int init = 1;

//Indica Game Over(Tela de fim de jogo)
int theEnd = 0;
int animacaoMorteOn = 1; /*Serve como parametro para na hora da morte mudar a
                          textura do jogador para a textura de morte*/


//Ativa a Geração Aleatoria de Inimigos
int RandomEnemiesOn = 1;

int DificuldadeProgressivaOn = 1;
int ContadorInimigos = 0;
int NumInimigosMudarSpawn = 5;


//Timers:
int fpstimer =24; //Timer FPS(Tempo de atualização(em ms))

int timerAnimacao = 100;//Timer para animação

int Score=0; //Score do jogador

// Menu inicial:
int MenuOn=1; //Determina se o menu está ativado ou não
int contador_selecao=1; //Seleção de Opções no Menu

//Controles:
int timer_controle=8;
int ControlesOn=0;
int contador_control=0;

//Pause:
int sair=0;
char acao='M';
int PauseOn=0;
int ConfirmaOn=0;
int contador_seta=1;
int contador_seletor=1;

//Movimento:
int Start=1;
int MovimentarOn=0; //Determina se Movimentar está habilitado ou não
int ColisaoOn=0; //Determina se está havendo ou não colisão

//Rolamento:
int RolamentoOn=0; //Determina se o rolamento está ligado
int RolamentoContadorFrames = 0; //Conta os frames da animação de Rolamento do Jogador
int RolamentoMaxFrames = 10; //Determina o numero máximo de frames da animação de Rolamento

//Pulo:
int PularOn = 0; //Determina se está havendo ou não pulo
float oldpulo; //Guarda o valor inicial de pulo
float pulo = 5; //o quanto eu vou pra cima no y (variação do y)
float incPulo = 0.5; //incremento no y (variação da variação)


//Spawn:
//OBS: Atentar à função mudaCorrida que pega valores determinados
int RANDOM_SPAWN = 300; //Random Spawn (Determina o limite dos numeros randômicos)
int DIST_SPAWN = 300; //Distância do Spawn (Determina a distância minima para o Spawn]
int OLD_DIST_SPAWN; //Backup dos valores padrões do spawn
int OLD_RANDOM_SPAWN; // ''
int MIN_RANDOM_SPAWN = 30; //Minimo Randown para o Spawn(DificuldadeProgressiva)
int MIN_DIST_SPAWN = 80; //Minima distancia para o spawn(DificuldadeProgressiva)
int DECR_RANDOM_SPAWN = 30; //Decremento no Random Spawn(DificuldadeProgressiva)
int DECR_DIST_SPAWN = 30; //Decremento na Distancia Spawn(DificuldadeProgressiva)
int mudaCorridaTimer = 10000; //(Teste - Não Implementado)
int aumentaScoreTimer = 4000; //Tempo para aumentar o Score(em ms)

float velocidade = 3.0; //Velocidade dos inimigos


//Mundo:
int INICIO_DO_MUNDO = 0;
int FIM_DO_MUNDO = 100;
int ALTURA_DO_MUNDO = 90;
int LARGURA_DO_MUNDO = 160;
int CHAO_DO_MUNDO = 0;
int ALTURA_DA_GRAMA = -10;

int groundlevel = 8; //Nivel do Chao
int MOEDA_ALTURA = 45; //Altura da Moeda
quadrado *Ponteiro_Moeda; //Aponta para a moeda para a hora do seu respawn.
int Moeda_Timer_Respawn = 1000;


int VOADOR_INCREMENTO_ALTURA_MINIMA = 10;
int VOADOR_INCREMENTO_ALTURA_MAXIMA = 4;

int TXMOEDA = 10; //Tamanho no Eixo X da Moeda
int TYMOEDA = 10; //Tamanho no Eixo Y da Moeda

int TXDEFAULT = 13; //Tamanho no Eixo X Padrão
int TYDEFAULT = 13; //Tamanho no Eixo Y Padrão
int TXPLAYER = 15; //Tamanho no Eixo X do Jogador
int TYPLAYER = 15; //Tamanho no Eixo Y do Jogador
int TXPLAYER_ROLL = 13; //Tamanho no Eixo X do Jogador ao Rolar
int TYPLAYER_ROLL = 10; //Tamanho no Eixo Y do Jogador ao Rolar

float aspect; //Para manter o AspectRatio

float velocidade_g = 2.5; //Velocidade da grama
float velocidade_f = -.1; //Velocidade do fundo


//////////////////////////////////////////////////
//Declaração dos "Objetos":
// Fundo do jogo
quadrado fundo1, grama1;
quadrado fundo2, grama2;

// Menu inicial
quadrado logo, seta, texto_iniciar, texto_controles;
quadrado texto_sair, texto_creditos;

//Declaração Jogador
quadrado q1; //Player

//Declaração Inimigos
quadrado q2,q3,q4;
quadrado voador1,voador2;


//Declaração Colecionaveis(Moedas e PowerUps):
quadrado moeda1;
quadrado pw1;//PowerUp(Teste - Não foi implementado)

//////////////////////////////////////////////
//Declaração de Texturas
//Start:
GLuint Textura_Texto_Start;
//Fundo e Grama:
GLuint Textura_Fundo, Textura_Fundo2, Textura_Grama;
//Moedas
GLuint Textura_MoedaRing,Textura_MoedaGoldCoin;

//Inimigos 1
GLuint Textura_CaveiraFogo,Textura_CaveiraSemFogo,
Textura_Lobo1,Textura_Lobo2, Textura_GoombaRunning,
Textura_MutantCrab, Textura_OlhoVoador, Textura_DemonioFudendoVoador;

//Inimigos 2
GLuint Textura_RolyPolyRoxo,Textura_RolyPolyVerde,Textura_RolyPolyMarrom,
Textura_RolyPolyPreto;

//Inimigos 3
GLuint Textura_LostVikingsSoldier, Textura_AnimaniacsPolicialGordo;
GLuint Textura_DonaldArabian;

//Jogador
GLuint Textura_Jogador1, Textura_Jogador1_Roll, Textura_Jogador1_Pulo, Textura_Jogador1_Morte;

// Menu inicial
GLuint Textura_Logo, Textura_Jogar, Textura_Controles, Textura_Texto_Sair_M;
GLuint Textura_Seletor;

// Controles
GLuint Textura_WASD, Textura_Espaco, Textura_ESC;
GLuint Textura_Texto_WASD, Textura_Texto_Espaco, Textura_Texto_ESC, Textura_Texto_Aperte;

// Menu de Pause
GLuint Textura_Popup;
GLuint Textura_Texto_Pause, Textura_Voltar_Jogo, Textura_Texto_Reiniciar, Textura_Texto_Menu, Textura_Texto_Sair;

// Tela de Morte
GLuint Textura_Texto_GameOver, Textura_Texto_Retry, Textura_Score;

// Confirmacao
GLuint Textura_Seletor_Botao, Textura_BotaoS, Textura_BotaoN;
GLuint Textura_Texto_Confirmacao;

//////////////////////////////////////////////////
//Som
Mix_Music * musica_ingame, * musica_menu;
int MusicaMenu=0, MusicainGame=0;
//////////////////////////////////////////////////
//Funções


/*Essa Função vai realizar a inicialização de todas as texturas*/
void inicializaTextura(){
  glClearColor(.9,.9,.9,0);

  //Menu
  Textura_Logo = SOIL_load_OGL_texture("texturas/Menu/logo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Jogar = SOIL_load_OGL_texture("texturas/Menu/jogar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Controles = SOIL_load_OGL_texture("texturas/Menu/controles.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Seletor = SOIL_load_OGL_texture("texturas/seta.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Sair_M = SOIL_load_OGL_texture("texturas/sair_do_jogo_m.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  // Controles
  Textura_WASD = SOIL_load_OGL_texture("texturas/Menu/Controles/wasd.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Espaco = SOIL_load_OGL_texture("texturas/Menu/Controles/keyboard.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_ESC = SOIL_load_OGL_texture("texturas/Menu/Controles/esc.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_WASD = SOIL_load_OGL_texture("texturas/Menu/Controles/rolartxt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Espaco = SOIL_load_OGL_texture("texturas/Menu/Controles/pulartxt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_ESC = SOIL_load_OGL_texture("texturas/Menu/Controles/pausartxt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Aperte = SOIL_load_OGL_texture("texturas/Menu/Controles/apertetxt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  //Jogo
  Textura_Texto_Start = SOIL_load_OGL_texture("texturas/start.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Fundo  = SOIL_load_OGL_texture("texturas/fundo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Fundo2  = SOIL_load_OGL_texture("texturas/fundo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Grama  = SOIL_load_OGL_texture("texturas/grama.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Jogador1 = SOIL_load_OGL_texture("texturas/Coutinho/coutinho_correndo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Jogador1_Roll  = SOIL_load_OGL_texture("texturas/Coutinho/coutinho_rolando.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Jogador1_Morte  = SOIL_load_OGL_texture("texturas/Coutinho/coutinho_morrendo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_MoedaRing = SOIL_load_OGL_texture("texturas/SonicRingCoin.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_MoedaGoldCoin = SOIL_load_OGL_texture("texturas/GoldCoin.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Lobo1 = SOIL_load_OGL_texture("texturas/wolf-runing-cycle-skin.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Lobo2 = SOIL_load_OGL_texture("texturas/wolf-runing-cycle.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_GoombaRunning = SOIL_load_OGL_texture("texturas/GoombaRunning.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_MutantCrab = SOIL_load_OGL_texture("texturas/mutant_crab.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_LostVikingsSoldier = SOIL_load_OGL_texture("texturas/LostVikingsSoldier.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_AnimaniacsPolicialGordo = SOIL_load_OGL_texture("texturas/AnimaniacsPolicialGordo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_DonaldArabian = SOIL_load_OGL_texture("texturas/DonaldArabian.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_OlhoVoador = SOIL_load_OGL_texture("texturas/OlhoVoador.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_CaveiraFogo = SOIL_load_OGL_texture("texturas/fire-skull.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_CaveiraSemFogo = SOIL_load_OGL_texture("texturas/no-fire-skull.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_DemonioFudendoVoador = SOIL_load_OGL_texture("texturas/demon-idle.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_RolyPolyRoxo = SOIL_load_OGL_texture("texturas/ChronoTrigger/purpleRolyPoly_CT.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_RolyPolyVerde = SOIL_load_OGL_texture("texturas/ChronoTrigger/greenRolyPoly_CT.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_RolyPolyMarrom = SOIL_load_OGL_texture("texturas/ChronoTrigger/brownRolyPoly_CT.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_RolyPolyPreto = SOIL_load_OGL_texture("texturas/ChronoTrigger/blackRolyPoly_CT.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  // menu de pause
  Textura_Popup = SOIL_load_OGL_texture("texturas/popup.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Pause = SOIL_load_OGL_texture("texturas/pause_texto.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Voltar_Jogo = SOIL_load_OGL_texture("texturas/voltar_jogo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Reiniciar = SOIL_load_OGL_texture("texturas/reiniciar.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Menu = SOIL_load_OGL_texture("texturas/go_menu.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Sair = SOIL_load_OGL_texture("texturas/sair_do_jogo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  // tela de morte
  Textura_Texto_GameOver = SOIL_load_OGL_texture("texturas/gameover.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Retry = SOIL_load_OGL_texture("texturas/retry.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Score = SOIL_load_OGL_texture("texturas/score.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  // confirmacao
  Textura_Popup = SOIL_load_OGL_texture("texturas/popup.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Texto_Confirmacao = SOIL_load_OGL_texture("texturas/confirmacao.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_Seletor_Botao = SOIL_load_OGL_texture("texturas/seletor_botao.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_BotaoS = SOIL_load_OGL_texture("texturas/botao_sim.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  Textura_BotaoN = SOIL_load_OGL_texture("texturas/botao_nao.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);


  if(Textura_MutantCrab== 0){
      printf("[Texture loader] \"%s\" failed to load!\n", SOIL_last_result());
  }

}

///////Som
void inicializaAudio(){
    musica_ingame = Mix_LoadMUS("sons/green_hill.mp3");
    musica_menu = Mix_LoadMUS("sons/the_prelude.mp3");

}

int VariacoesDeInimigos = 16; /*Determina o numero de Variações de inimigos
                              para a função randomizarInimigos*/


//SEÇÃO RESPAWN
void randomizarInimigos(quadrado *Inimigo){
  // int NumeroAleatorio;
  int NumeroAleatorio = rand()%VariacoesDeInimigos+1;

  if(Inimigo->y > groundlevel)
    posQuadrado(Inimigo,Inimigo->x,groundlevel);
  if(Inimigo->isMoeda)
    NumeroAleatorio = rand()%2+50; //Vai para o 50 no switch, onde estão as possiveis moedas

  // NumeroAleatorio = 8; //Para testes diretos de textura
  switch (NumeroAleatorio){

    //Lobo1
    case 1:
      tamQuadrado(Inimigo,16,10);
      texturaQuadrado(Inimigo,Textura_Lobo1);
    break;
    //Lobo2:
    case 2:
      tamQuadrado(Inimigo,16,10);
      texturaQuadrado(Inimigo,Textura_Lobo2);
    break;
    //Goomba
    case 3:
      tamQuadrado(Inimigo,13,13);
      texturaQuadrado(Inimigo,Textura_GoombaRunning);
    break;
    //GoombaBigger
    case 4:
      tamQuadrado(Inimigo,15,15);
      texturaQuadrado(Inimigo,Textura_GoombaRunning);
    break;
    //MutantCrab(Caranguejo Fudidao)
    case 5:
      tamQuadrado(Inimigo,13,13);
      texturaQuadrado(Inimigo,Textura_MutantCrab);
    break;
    //LostVikingsSoldier
    case 6:
      tamQuadrado(Inimigo,14,15);
      texturaQuadrado(Inimigo,Textura_LostVikingsSoldier);
    break;
    //AnimaniacsPolicialGordo
    case 7:
      tamQuadrado(Inimigo,20,18);
      texturaQuadrado(Inimigo,Textura_AnimaniacsPolicialGordo);
    break;
    //DonaldArabian
    case 8:
      tamQuadrado(Inimigo,17,17);
      texturaQuadrado(Inimigo,Textura_DonaldArabian);
    break;

    /*
    A partir daqui começam textura de voadores. É preciso setar sua posição como acima do nivel do chão,
    para que, na função eventoRespawn, ocorra o seu respawn como o de um voador.
    */
    //OlhoVoador
    case 9:
      tamQuadrado(Inimigo,15,13);
      texturaQuadrado(Inimigo,Textura_OlhoVoador);
      posQuadrado(Inimigo,Inimigo->x,groundlevel+1);
    break;
    //Caveira de Fogo
    case 10:
      tamQuadrado(Inimigo,15,15);
      texturaQuadrado(Inimigo,Textura_CaveiraFogo);
      posQuadrado(Inimigo,Inimigo->x,groundlevel+1);
    break;
    //Caveira Sem Fogo
    case 11:
      tamQuadrado(Inimigo,13,13);
      texturaQuadrado(Inimigo,Textura_CaveiraSemFogo);
      posQuadrado(Inimigo,Inimigo->x,groundlevel+1);
    break;
    case 12:
      tamQuadrado(Inimigo,42,33);
      texturaQuadrado(Inimigo,Textura_DemonioFudendoVoador);
      posQuadrado(Inimigo,Inimigo->x,groundlevel+1);
    break;

  //RolyPolys:ChronoTrigger)
  //Roxo
  case 13:
    texturaQuadrado(Inimigo,Textura_RolyPolyRoxo);
    tamQuadrado(Inimigo,13,13);
  break;
  //Preto
  case 14:
    texturaQuadrado(Inimigo,Textura_RolyPolyPreto);
    tamQuadrado(Inimigo,13,13);
  break;
  //Marrom
  case 15:
    texturaQuadrado(Inimigo,Textura_RolyPolyMarrom);
    tamQuadrado(Inimigo,13,13);
  break;
  //Verde
  case 16:
    texturaQuadrado(Inimigo,Textura_RolyPolyVerde);
    tamQuadrado(Inimigo,13,13);
  break;

  case 50:
    texturaQuadrado(Inimigo,Textura_MoedaRing);
    posQuadrado(Inimigo,Inimigo->x,MOEDA_ALTURA);
  break;
  case 51:
    texturaQuadrado(Inimigo,Textura_MoedaGoldCoin);
    posQuadrado(Inimigo,Inimigo->x,MOEDA_ALTURA);
  break;

}

}


/*Essa função é responsável por diminuir a distâncias do spawn a cada 'x' inimigos,
permitindo o ajuste de dificuldade com o tempo. */
void mudarDistanciasSpawn(){
    if(ContadorInimigos == NumInimigosMudarSpawn){
        if(DIST_SPAWN>MIN_DIST_SPAWN)
            RANDOM_SPAWN -=30;
        if(RANDOM_SPAWN > MIN_RANDOM_SPAWN)
            DIST_SPAWN -= 30;

        printf("Ajeitando Distancias DIST_SPAWN:%i RANDOM_SPAWN:%i\n",DIST_SPAWN,RANDOM_SPAWN);
    ContadorInimigos = 0;
    }
}



// //Respawn do Objeto
void eventoRespawn(quadrado *Objeto){

  //Variavel que determina se a geração aleatoria de inimigos esta ativada
  if(RandomEnemiesOn)
    randomizarInimigos(Objeto);

  /*Variavel que determina se o jogo está com a dificuldade progressiva
  (dificuldade aumenta com o passar do tempo) ativada.
  */
  if(DificuldadeProgressivaOn)
    mudarDistanciasSpawn();


  //Primeiramente: Descobre Objeto posição do objeto mais distante;
  float posMaior = posMaisDistante(&q2);

  //Atribui um valor da variação para ser somado à posição;
  float valorVariacao = rand()%RANDOM_SPAWN + DIST_SPAWN;

   if(Objeto->isMoeda)
    posQuadrado(Objeto,posMaior+valorVariacao,MOEDA_ALTURA);

   //Para o caso de inimigos voadores, muda ligeiramente sua altura, entre os valores possíveis.
   else if(Objeto->y > groundlevel){
     int valorVariacaoInimigoVoador = (rand()%VOADOR_INCREMENTO_ALTURA_MAXIMA)+VOADOR_INCREMENTO_ALTURA_MINIMA+groundlevel;
     posQuadrado(Objeto,posMaior+valorVariacao,valorVariacaoInimigoVoador);
   }

   //Para os demais inimigos
   else
      posQuadrado(Objeto, posMaior+valorVariacao,Objeto->y);
}



//Para o Respawn da Moeda
void respawnMoeda(){
  if(Ponteiro_Moeda->x  < INICIO_DO_MUNDO){
    eventoRespawn(Ponteiro_Moeda);

    // printf("RespawnDaMoeda\n"); //Para debugging, informa no console  se houve respawn da moeda
  }

}

/*Essa função é responsavel por verificar se o objeto analisado saiu ou nao de cena,
especialmente importante, para os objetos to tipo inimigo*/
void verificaPosicao(quadrado *Objeto){

  /*Quando o quadrado percorrer até o final do mundo(no caso o inicio, pelo referencial)
   estiver saido de cena, ocorre o evento do Respawn, para o caso dos Inimigos.
   No caso da Moeda, é chamado um glutTimerFunc para ela respawnar em 'X' segundos (Moeda_Timer_Respawn).
   No caso do Fundo, ele respawna na posição onde o proximo quadrado de Fundo termina. */
  if( Objeto->x < -(Objeto->tx)+INICIO_DO_MUNDO ){ //Se saiu para fora da tela
    if(Objeto->isInimigo){
    eventoRespawn(Objeto); //Ocorre o Respawn do Objeto
    ContadorInimigos ++;
    printf("ContadorInimigos:%i\n",ContadorInimigos);
    }
     if(Objeto->isMoeda){
      Ponteiro_Moeda = Objeto; //Salva o endereço da moeda
      glutTimerFunc(Moeda_Timer_Respawn,respawnMoeda,0); //Para Objeto moeda respawnar pelo tempo.
    }

     if(Objeto->isFundo){
       posQuadrado(Objeto, Objeto->tx-velocidade_g ,Objeto->y);
       glutPostRedisplay();
     }


  }


  Objeto->visivel = 1; //Retorna o objeto pra sua visibilidade, caso tenha sido alterada
}



void jogadorAnimacao_Morte(quadrado *Jogador, int *animacaoMorteOn){

  /*Reseta o Rolamento, caso esteja ocorrendo, pois durante o rolamento, propriedades do jogadorAnimacao_Morte
  estão sendo alteradas, como a textura, e o *tamanho*.
  */
  resetRolamento(&q1,Textura_Jogador1,TXPLAYER,TYPLAYER,&RolamentoOn,&RolamentoContadorFrames);

  /*Se animacaoMorteOn estiver ativa, muda a textura associada ao jogador, para a textura de morte,
    o objetivo é chamar a função de mudar textura somente uma vez, para não ficar mudando o tempo inteiro.
  */
  if(*animacaoMorteOn == 1){
    *animacaoMorteOn = 0; //Para so chamar essa função uma vez.
    Jogador->animacao.Contador = 1; //Estabelece o contador de animacao do Jogador como 1
    texturaQuadrado(Jogador,Textura_Jogador1_Morte); //Binda a Textura de Morte ao Quadrado Jogador
    reposicionaViewTextura(0 , .25 , .2, 1,&(Jogador->animacao)); /*Reposiciona para a primeira sprite,
                                                                    para não exibir a spritesheet inteira */


  }

}



void verificaTipo(quadrado *a){
 /*Após verificar a colisão, verifica-se o tipo do quadrado, para reações diferente, ou seja,
  se é Moeda(isMoeda), Inimigo(isInimigo), reagindo da maneira apropriada
  (ex:Inimigo, ocorre o GameOver, ou seja, o personagem morreu.
      No caso da Moeda, chama a função colisãoMoeda(), responsável por aumentar
      o Score do jogo )
 */
  //Se colisao estar ligada
  if(ColisaoOn){

    if(a->isMoeda){
      colisaoMoeda(a,&Score); /*Função do structs.c. Aumenta o (por ter
                              pego a moeda), e movimenta ela para fora de cena */
    }

    if (a->isInimigo){
      theEnd=1; //Fim do jogo(Pronuncio de Morte do Jogador)
      jogadorAnimacao_Morte(&q1,&animacaoMorteOn); //Libera a animação de morte do jogador. Pq ele morreu
      MovimentarOn=0; //Para com o movimento da cena
    }

    ColisaoOn=0; //Resetar o estado de Colisao
  }

}


// Essa função é responsável por movimentar os inimigos.
void movimentaInimigos(){
  /*Poderia ser implementado facilmente em lista encadeada, mas não houve necessidade.
  */
  q2.x-=velocidade;
  q3.x-=velocidade;
  q4.x-=velocidade;
  moeda1.x-=velocidade/2; //VELOCIDADE ITENS PEGAVEIS (MUDAR DEPOIS)
  voador1.x-=velocidade;
  pw1.x-=velocidade/1.5;

}


/*Essa função é responsável pela ação de rolar, desde o bind da textura e mudanças
de tamanho do quadrado Jogador, até resetar todas as mudanças, ao fim do Rolamento.
*/
void rolar(quadrado * a){
  if(RolamentoOn==1){
    texturaQuadrado(a,Textura_Jogador1_Roll);
    reposicionaViewTextura(0 , 1 , .75, 1, &q1.animacao);
    a->ty = TYPLAYER_ROLL;
    a->tx = TXPLAYER_ROLL;
    RolamentoOn = 2;
  }

  if(RolamentoContadorFrames >= RolamentoMaxFrames)
    resetRolamento(&q1,Textura_Jogador1,TXPLAYER,TYPLAYER,&RolamentoOn,&RolamentoContadorFrames);

}

//Essa função é responsável por movimentar o cenário
void movimentaCenario(){
  /*Poderia ser implementado facilmente  no formato de lista encadeada,
  mas não houve necessidade*/

  if(MovimentarOn){
    fundo1.x+=velocidade_f;
    fundo2.x+=velocidade_f;
      grama1.x-=velocidade_g;
      grama2.x-=velocidade_g;

  }

  //Caso esteja no menu, a velocidade é mais devagar.(Para ser mais "fancy")
  if (MenuOn){
    fundo1.x+=velocidade_f;
    fundo2.x+=velocidade_f;
    grama1.x-=velocidade_g-1.9;
    grama2.x-=velocidade_g-1.9;

  }



}



//Essa função atualiza o jogo.
void atualiza(int fpstimer){

  //MenuOn para controlar se o menu está ativo ou não
  if (MenuOn==1){
    reposiciona_seta(&seta);
  }

  //Pois o jogo precisa estar ocorrendo.
  if(theEnd==0){
        //MovimentarOn para controlar se o movimento está ativo ou não
        if (MovimentarOn==1){
          movimentaInimigos();

          //RolamentoOn para controlar se o rolamento está ativo ou não
          if (RolamentoOn>0)
            rolar(&q1);

            //PularOn para controlar se o pulo está ativo ou não
          if(PularOn>0)
            pular(&q1,&pulo,&oldpulo,&incPulo,&groundlevel,&PularOn);
        }

      movimentaCenario();
      glutPostRedisplay();

  }

  else
      glutPostRedisplay();

  //Continua chamando a atualiza().
  glutTimerFunc(fpstimer,atualiza,fpstimer);
}



//Verica se vai mudar ou nao de textura
void verificaTextura(int timer_controle){
  /*Nessa função foi usado lista encadeada, permitindo encaixar o glutTimerFunc
   e a mudança de textura.

   Nela, se verifica o tipo de textura, e chama a função de Animação correspondente.
   Permitiu ficar variando a textura entre os objetos, enquanto, mantem-se a animação
  */

  quadrado *i; //Ponteiro Iteração(Vai percorrer toda a lista encadeada)
    i = &(q1); /*Aponta para o primeira posição a ser considerada da lista,
                 no caso, para o quadrado q1, que é o quadrado do Jogador.
                */

  do{

    //Se textura for igual à textura do jogador
    if(i->textura == Textura_Jogador1 ||
       i->textura == Textura_Jogador1_Roll||
       i->textura == Textura_Jogador1_Morte)
      Animacao_Textura_Jogador1(&(i->animacao),PularOn, RolamentoOn, &RolamentoContadorFrames,
                                theEnd,MovimentarOn);

    if(MovimentarOn){
      //Se textura for igual a da moeda
      if(i->textura == Textura_MoedaRing )
        Animacao_Textura_MoedaRing(& (i->animacao) );

      //Se textura for igual ao do lobo
      if(i->textura == Textura_Lobo1 ||
          i->textura == Textura_Lobo2 )
        Animacao_Textura_Lobo(&(i->animacao));

      if(i->textura == Textura_GoombaRunning)
        Animacao_Textura_Goomba(&(i->animacao));

      if(i->textura == Textura_MutantCrab)
        Animacao_Textura_MutantCrab(&(i->animacao));

      if(i->textura == Textura_OlhoVoador)
        Animacao_Textura_OlhoVoador(&(i->animacao));

      if(i->textura == Textura_MoedaGoldCoin)
        Animacao_Textura_MoedaGoldCoin(&(i->animacao));

      if(i->textura == Textura_MoedaRing)
        Animacao_Textura_MoedaRing(&(i->animacao));

      if(i->textura == Textura_CaveiraFogo)
        Animacao_Textura_CaveiraFogo(&(i->animacao));

      if(i->textura == Textura_CaveiraSemFogo)
        Animacao_Textura_CaveiraSemFogo(&(i->animacao));

      if(i->textura == Textura_LostVikingsSoldier)
        Animacao_Textura_LostVikingsSoldier(&(i->animacao));

      if(i->textura == Textura_AnimaniacsPolicialGordo)
        Animacao_Textura_AnimaniacsPolicialGordo(&(i->animacao));

      if(i->textura == Textura_DonaldArabian)
        Animacao_Textura_DonaldArabian(&(i->animacao));

      if(i->textura == Textura_DemonioFudendoVoador)
        Animacao_Textura_DemonioFudendoVoador(&(i->animacao));
      if(i->textura == Textura_RolyPolyRoxo ||
         i->textura == Textura_RolyPolyVerde ||
         i->textura == Textura_RolyPolyPreto ||
         i->textura == Textura_RolyPolyMarrom)
         Animacao_Textura_RolyPoly(&(i->animacao));
      }

    i = i->proxquadrado;
  }
  while( (i)!= NULL);

  //Chama essa função novamente em 'X' segundos(timerAnimacao).
  glutTimerFunc(timerAnimacao,verificaTextura,timerAnimacao);
}


/* Essa função é responsável por desenhar o quadrado 'a' qualquer, passado como
parámetro. Ou seja, qualquer quadrado que se passe para ela será desenhado.
Isso permitiu o uso dessa função para o desenho de qualquer quadrado da Cena(fundo,
grama(chao), inimigo, moeda).
*/
/*Antes de desenhar qualquer Objeto, é necessário passar por uma etapa de verificação,
que verifica se houve qualquer reação na cena, como colisao, por exemplo.
*/

void desenhaQuadrado(quadrado* a){

    /*Caso queira adicionar cor. Não há necessidade, pois já há textura,
    mas é possivel mudar a cor para "special effects".
    */
    // glColor4f(0,0,0,.0);
      // glClear(GL_COLOR_BUFFER_BIT);

    //Parametros para a textura funcionar certinho
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    /*Se a for do tipo colídivel, maneira elegante de impedir de checar a colisãonce
    do Jogador com ele mesmo.
    */
    if(a->colidivel)
    verificaColisao(a,&q1,&ColisaoOn); /*Verifica se houve colisão - Caso ocorra
                                      muda a variável ColisaoOn para 1(true)*/
    verificaPosicao(a); //Verifica a posição do objeto
    verificaTipo(a); //Verifica o tipo de objeto, associado à reação respectiva.



    /*Para somente desenhar se visibilidade estiver ativa, para o objeto.
      No código não foi implementado nenhuma mudança de estado de visibilidade,
      mas é um atributo interessante para se ter na "Classe"(na Struct Quadrado).
    */
    if(a->visivel){
      /*Essa parte é mais complexa, por usar duas características específicas da Struct Quadrado.
       Primeiramente, irá se bindar a textura, com a textura respectiva do quadrado( uma Gluint dentro da struct quadrado),
       Depois, na hora de plotar os vértices. Primeiro analisa as coordenadas de Inicio e Final da Textura( associados à
       Struct Animacao), que é responsável por mudar a exibição no SpriteSheet. E plotando seu ponto correspondente.
      */
      glBindTexture(GL_TEXTURE_2D, a->textura); //Binda com a textura que esta associada ao Objeto 'a'.
      glBegin(GL_TRIANGLE_FAN); //Começa o desenho

      glTexCoord2f(a->animacao.X_Inicio_Textura, a->animacao.Y_Inicio_Textura);  glVertex3f(a->x, a->y,  0)  ;
      glTexCoord2f(a->animacao.X_Final_Textura,   a->animacao.Y_Inicio_Textura);  glVertex3f(a->x + a->tx, a->y,  0);
      glTexCoord2f(a->animacao.X_Final_Textura,   a->animacao.Y_Final_Textura);    glVertex3f(a->x + a->tx, a->y + a->ty,  0);
      glTexCoord2f(a->animacao.X_Inicio_Textura, a->animacao.Y_Final_Textura);    glVertex3f(a->x, a->y + a->ty,  0);

      glEnd(); //Termina o desenho
  }



}

void desenhaFundo(){
 /*Desenha todos os quadrados com a propriedade IsFundo.
  A implementação se fez por meio de uma lista encadeada que passa desde o primeiro
  quadrado do fundo até o ultimo.
 */
  quadrado *Fundo_Pointer; //Ponteiro Iteração(Aposta para os quadrados)
    Fundo_Pointer = &(fundo1);
  do{
    desenhaQuadrado(Fundo_Pointer);
    Fundo_Pointer = Fundo_Pointer->proxquadrado;
  }
  while ( Fundo_Pointer->isFundo );

}

/* Essa função reposiciona a seta do menu inicial, de acordo com contador_selecao.
    A maneira mais prática de implementar o menu inicial e suas funções foi direto na main, 
    de forma a alterar as telas pelo switch com mais facilidade */
void reposiciona_seta(quadrado * seta){
    if (contador_selecao == 1){
        seta->x = (160-30)/2;
        seta->y = 30;
        }

    if (contador_selecao == 2){
        seta->x = (160-42)/2;
        seta->y = 25;
    }

    if (contador_selecao == 3){
        seta->x = (160-51)/2;
        seta->y = 20;
    }

}

void desenhaCena(){
  //Poderia ter sido implementado a Lista encadeada, mas não houve necessidade.

  glClear(GL_COLOR_BUFFER_BIT); //Limpar Buffer

  glEnable(GL_BLEND); //Enable Blend
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Função da Blend
  glEnable(GL_TEXTURE_2D); //Enable Texture_2D

  //Desenha o Fundo.
  desenhaFundo();

  //Desenha os quadrados em cena:
  desenhaQuadrado(&q1);
     desenhaQuadrado(&q2);
     desenhaQuadrado(&q3);
     desenhaQuadrado(&q4);
     desenhaQuadrado(&moeda1);
     desenhaQuadrado(&voador1);

    // Checa a variável para aparecer a tela instruindo a começar o jogo
    // Sem essa tela, o personagem já começaria correndo direto, dando ao jogador
    // pouco tempo de reação
    if (Start==0){
      tela_comecar(Textura_Texto_Start);
    }

    // Chama a tela de Game Over e para a música tema.
    if (theEnd==1){
        Mix_FadeOutMusic(1000);
        tela_morte(contador_seta, Score, Textura_Popup, Textura_Texto_GameOver,
                  Textura_Texto_Retry, Textura_Texto_Menu, Textura_Texto_Sair, Textura_Seletor,
                  Textura_Score);
        if (ConfirmaOn==1){
        confirmacao(contador_seletor, acao, &sair, Textura_Popup,  Textura_Seletor_Botao, Textura_Texto_Confirmacao, Textura_BotaoS, Textura_BotaoN);
        }
    }

  // Chama o menu de pause 
   else if (PauseOn==1){
    pausa(contador_seta, Textura_Popup, Textura_Texto_Pause, Textura_Voltar_Jogo, Textura_Texto_Reiniciar,
          Textura_Texto_Menu, Textura_Texto_Sair, Textura_Seletor);
      if (ConfirmaOn==1){
        confirmacao(contador_seletor, acao, &sair, Textura_Popup,  Textura_Seletor_Botao, Textura_Texto_Confirmacao, Textura_BotaoS, Textura_BotaoN);
        }
    }


  glDisable(GL_TEXTURE_2D);


  /* Mostra e muda o score de posição, dependendo do estado do jogo (Normal ou Game Over) */
  if(theEnd==0)
    mostraScore(Score, 150, 85);
  else if(theEnd==1 && ConfirmaOn==0)
    mostraScore(Score, 75, 50);

  glDisable(GL_BLEND);
  glutSwapBuffers();

}

// Como o nome diz, cuida de desenhar o menu inicial
// Função usada no switch que troca de telas
void desenhaMenu(){

  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);

  //Desenha o Fundo
  desenhaFundo();

  desenhaQuadrado(&logo);
  desenhaQuadrado(&seta);
  desenhaQuadrado(&texto_iniciar);
  desenhaQuadrado(&texto_controles);
  // desenhaQuadrado(&texto_creditos);
  desenhaQuadrado(&texto_sair);

  // Chama a tela que mostra os controles do jogo
  if (ControlesOn==1){
    controle(contador_control, Textura_Popup, Textura_WASD, Textura_Espaco, Textura_ESC,
            Textura_Texto_WASD, Textura_Texto_Espaco, Textura_Texto_ESC, Textura_Texto_Aperte);
    contador_control++;
    if (contador_control==2*timer_controle)
      contador_control=0;
  }

  // Chama a tela que confirma a saída
  if (ConfirmaOn==1){
        confirmacao(contador_seletor, acao, &sair, Textura_Popup,  Textura_Seletor_Botao, Textura_Texto_Confirmacao, Textura_BotaoS, Textura_BotaoN);
      }

  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);

  glutSwapBuffers();

}

// switch para mudança de telas
void seletorCena(){
  switch(MenuOn){
    case 0:
      if(Start==1){
          if(MusicainGame==0){
            Mix_PlayMusic(musica_ingame, -1);
            MusicainGame=1;
          }
      }
      desenhaCena();
    break;

    case 1:
      if(MusicaMenu==0){
        Mix_PlayMusic(musica_menu, -1);
        MusicaMenu=1;
      }
      desenhaMenu();
    break;


  }

}

// Para manter o aspecto do jogo, função por Flávio Coutinho
void redimensiona(int width, int height){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA_DO_MUNDO, 0, ALTURA_DO_MUNDO, -1, 1);

    float razaoAspectoJanela = ((float)width)/height;
    float razaoAspectoMundo = ((float) LARGURA_DO_MUNDO)/ ALTURA_DO_MUNDO;
    if (razaoAspectoJanela < razaoAspectoMundo) {
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


/*Essa função é responsável pela incialização de todos os objetos em cena*/

void initQuadrado(){

  if (init==1){   //Para inicializar o quadrado somente uma vez. Podendo atualizar ele sem preocupações
     OLD_DIST_SPAWN = DIST_SPAWN; //Guarda o valor inicial de DIST_SPAWN (DificuldadeProgressiva)
     OLD_RANDOM_SPAWN = RANDOM_SPAWN; //Guarda o valor inicial de RANDOM_SPAWN(DificuldadeProgressiva)
    puloBackup(&pulo,&oldpulo); //Guarda o valor inicial de pulo
  init++;

  //Fundo:
  initAsFundo(&fundo1);
  tamQuadrado(&fundo1, LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
  posQuadrado(&fundo1, 0, 0);
  texturaQuadrado(&fundo1, Textura_Fundo);
  linkQuadrado(&fundo1,&fundo2);

  initAsFundo(&fundo2);
  tamQuadrado(&fundo2, LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
  posQuadrado(&fundo2, -LARGURA_DO_MUNDO + 1, 0);
  texturaQuadrado(&fundo2, Textura_Fundo2);
  linkQuadrado(&fundo2,&grama1);


  initAsFundo(&grama1);
  tamQuadrado(&grama1, LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
  posQuadrado(&grama1, 0, ALTURA_DA_GRAMA);
  texturaQuadrado(&grama1, Textura_Grama);
  linkQuadrado(&grama1,&grama2);

  initAsFundo(&grama2);
  tamQuadrado(&grama2, LARGURA_DO_MUNDO,ALTURA_DO_MUNDO);
  posQuadrado(&grama2, LARGURA_DO_MUNDO, ALTURA_DA_GRAMA);
  texturaQuadrado(&grama2, Textura_Grama);
  linkQuadrado(&grama2,&q2);

  //Menu Inicial
  tamQuadrado(&logo, 60, 30);
  posQuadrado(&logo, (160-60)/2, 50);
  texturaQuadrado(&logo, Textura_Logo);

  tamQuadrado(&texto_iniciar, 15, 3);
  posQuadrado(&texto_iniciar, (160-15)/2, 30);
  texturaQuadrado(&texto_iniciar, Textura_Jogar);

  tamQuadrado(&texto_controles, 27, 3);
  posQuadrado(&texto_controles, (160-27)/2, 25);
  texturaQuadrado(&texto_controles, Textura_Controles);

  tamQuadrado(&texto_sair, 36, 3);
  posQuadrado(&texto_sair, (160-36)/2, 20);
  texturaQuadrado(&texto_sair, Textura_Texto_Sair_M);

  tamQuadrado(&seta, 5, 3);
  posQuadrado(&seta, (160-30)/2, 30);
  texturaQuadrado(&seta, Textura_Seletor);



  //Resto:
  initAsJogador(&q1); //TEMPORARIO
  tamQuadrado(&q1,TXPLAYER,TYPLAYER);
  posQuadrado(&q1,5,groundlevel);
  corQuadrado(&q1,.8,.1,.1);
  linkQuadrado(&q1,&q2);
  texturaQuadrado(&q1,Textura_Jogador1 );
  PropriedadesQuadrado(&q1, Textura_Jogador1, Textura_Jogador1_Roll, Textura_Jogador1_Pulo, Textura_Jogador1_Morte);
  reposicionaViewTextura(.83 , 1, 0, 1,&q1.animacao);

  nomeQuadrado(&q2,"q2");  //NÃO ESTA EM USO(SOMENTE PARA TESTES) (IDEIA NOMES LEGAIS ALEATORIOS PARA QUANDO MORRER APARECER --- ROGUE LEGACY)
  initAsInimigo(&q2);
  tamQuadrado(&q2,TXDEFAULT,TYDEFAULT);
  posQuadrado(&q2,180,groundlevel);
  corQuadrado(&q2,.1,.3,.9);
  linkQuadrado(&q2,&q3);
  texturaQuadrado(&q2, Textura_RolyPolyPreto);

  nomeQuadrado(&q3,"q3");
  initAsInimigo(&q3);
  tamQuadrado(&q3,TXDEFAULT,TYDEFAULT);
  posQuadrado(&q3,-30,groundlevel);
  corQuadrado(&q3,.8,.5,.1);
  linkQuadrado(&q3,&q4);
  texturaQuadrado(&q3, Textura_RolyPolyPreto);

  nomeQuadrado(&q4,"q4");
  initAsInimigo(&q4);
  tamQuadrado(&q4,TXDEFAULT,TYDEFAULT);
  posQuadrado(&q4,-30,groundlevel);
  corQuadrado(&q4,.8,.3,.9);
  linkQuadrado(&q4,&voador1);
  texturaQuadrado(&q4, Textura_RolyPolyPreto);

  nomeQuadrado(&voador1,"voador1");
  initAsInimigo(&voador1);
  tamQuadrado(&voador1,TXDEFAULT,TYDEFAULT);
  posQuadrado(&voador1,-60,groundlevel+13);
  corQuadrado(&voador1,.8,.3,.9);
  linkQuadrado(&voador1,&moeda1);
  texturaQuadrado(&voador1, Textura_RolyPolyPreto);

  nomeQuadrado(&moeda1,"moeda1");
  initAsMoeda(&moeda1);
  tamQuadrado(&moeda1,TXMOEDA,TYMOEDA);
  posQuadrado(&moeda1,190,MOEDA_ALTURA);
  corQuadrado(&moeda1,.5,.6,.6);
  texturaQuadrado(&moeda1, Textura_MoedaGoldCoin);
  // linkQuadrado(&moeda1,&moeda2);
   linkEnd(&moeda1);




  }
}

/*Reseta o jogo todo.
*/
void resetAll(){
  theEnd = 0;
  Start=0;
  animacaoMorteOn = 1;
  glColor3f(1, 1, 1);
   resetPulo(&pulo,&oldpulo,&PularOn);
   resetRolamento(&q1,Textura_Jogador1,TXPLAYER,TYPLAYER,&RolamentoOn,&RolamentoContadorFrames);
   DIST_SPAWN = OLD_DIST_SPAWN;
   RANDOM_SPAWN = OLD_RANDOM_SPAWN;
   init = 1; //Permite a reinicialização dos quadrados.
  //  if (acao=='M')
    MovimentarOn=0;
  // else
  //   MovimentarOn=1;
   Score = 0;
   ContadorInimigos = 0;
   sair=0;
   PauseOn=0;
   ConfirmaOn=0;
   ControlesOn=0;
   contador_seta=1;
   contador_seletor=1;
   glClear(GL_COLOR_BUFFER_BIT);
   inicializaTextura();
   initQuadrado();
   desenhaFundo();
   glutPostRedisplay();


}

//KEYBOARD:
/*Essa parte ficou mais longa, pela dificuldade em colocar ela a parte,
 e pela grande quantidade de condições embutidas*/
void keyboard(unsigned char key, int x, int y){
  if (theEnd){
    switch(key){

      case 'w':
      case 'W':
        if(contador_seta==1)
            contador_seta=1;
        else
          contador_seta--;
      break;

      case 's':
      case 'S':
        if(contador_seta==3)
          contador_seta=3;
        else
          contador_seta++;
      break;

      case 13: //Enter

        switch(contador_seta){
          case 1:
            resetAll();
            // Mix_HaltMusic();
            MusicainGame=0;
            break;
          break;

          case 2:
            ConfirmaOn=1;
            acao='M';
          break;

          case 3:
            ConfirmaOn=1;
            acao='S';
          break;
          }

          // Confirmação

          if(ConfirmaOn==1 && contador_seletor==2){
            ConfirmaOn=0;
            contador_seletor=1;
            sair=0;
            break;
          }

          if (ConfirmaOn==1 && contador_seta==2)
            if (contador_seletor==1 && sair==1){
                if(acao=='M'){
                    contador_selecao=0;
                    resetAll();
                    Mix_HaltMusic();
                    // Mix_RewindMusic();
                    MusicaMenu=0;
                    MenuOn=1;
                    // glutPostRedisplay();
                    break;
                    }
              }

        if (ConfirmaOn==1 && contador_seta==3)
          if (contador_seletor==1 && sair==1){
            if(acao=='S')
              exit(0);
            break;

            }

        case 'd':
      case 'D':
      if (ConfirmaOn==1){
        if(contador_seletor==2)
          contador_seletor=2;
        else
          contador_seletor++;
      }

      break;

      case 'a':
      case 'A':
      if (ConfirmaOn==1){
        if(contador_seletor==1)
          contador_seletor=1;
        else
          contador_seletor--;
      }

    }

  }

  else if(Start==0){
    switch(key){
      case 13:
      MusicainGame=0;
      Start=1;
      verificarLiberarMovimento(&theEnd, &MovimentarOn, MenuOn);
      break;
      }

  }

   else if(PauseOn){
    switch (key){
      //Menu de Pause
      case 27: //Esc
        PauseOn=0;
        ConfirmaOn=0;
        verificarLiberarMovimento(&theEnd, &MovimentarOn, MenuOn);
      break;

       //
      case 13: //Enter

        switch(contador_seta){
          case 1:
            PauseOn = 0;
            Mix_ResumeMusic();
            verificarLiberarMovimento(&theEnd, &MovimentarOn, MenuOn);
          break;

          case 2:
            ConfirmaOn=1;
            acao='R';
            break;
          break;

          case 3:
            ConfirmaOn=1;
            acao='M';
            printf("acao=%c\n", acao);
          break;

          case 4:
            ConfirmaOn=1;
            acao='S';
          break;

        }

        //Menu de confirmacao

        if(ConfirmaOn==1 && contador_seletor==2){
          // sair=0;
          ConfirmaOn=0;
          contador_seletor=1;
          sair=0;
          break;
        }

        if (ConfirmaOn==1 && contador_seta==2)
          if (contador_seletor==1 && sair==1){
              if(acao=='R'){
                  MusicainGame=0;
                  contador_selecao=0;
                  resetAll();
                  break;
                  }
            }

        if (ConfirmaOn==1 && contador_seta==3)
          if (contador_seletor==1 && sair==1){
              if(acao=='M'){
                  contador_selecao=0;
                  resetAll();
                  MusicaMenu=0;
                  MenuOn=1;
                  // glutPostRedisplay();
                  break;
                  }
            }

        if (ConfirmaOn==1 && contador_seta==4)
          if (contador_seletor==1 && sair==1){
            if(acao=='S'){
              exit(0);
            break;

            }
          }

      break;

      case 'w':
      case 'W':
        if(contador_seta==1)
            contador_seta=1;
        else
          contador_seta--;
      break;

      case 's':
      case 'S':
        if(contador_seta==4)
          contador_seta=4;
        else
          contador_seta++;
      break;

      case 'd':
      case 'D':
      if (ConfirmaOn==1){
        if(contador_seletor==2)
          contador_seletor=2;
        else
          contador_seletor++;
      }

      break;

      case 'a':
      case 'A':
      if (ConfirmaOn==1){
        if(contador_seletor==1)
          contador_seletor=1;
        else
          contador_seletor--;
      }

    }

  }

  if (MenuOn==1){
    switch(key){
      case 27:
        if (ControlesOn==1)
          ControlesOn=0;
        break;

      case 13: //Enter
        switch(contador_selecao){
          case 1:
            resetAll();
            MenuOn=0;
            Mix_FadeOutMusic(1000);
            // Mix_HaltMusic();
            MusicainGame=0;
            MovimentarOn=0;
            Start=0;
          break;

          case 2:
            if (ControlesOn==0)
              ControlesOn=1;
            break;


          case 3:
          ConfirmaOn=1;
          acao='S';
          break;

        }

        // Confirmacao
        if (ConfirmaOn==1 && contador_selecao==3)
          if (contador_seletor==1 && sair==1){
            switch(acao){
            case 'S':
              exit(0);
            break;

            }
          }

        if(ConfirmaOn==1 && contador_seletor==2){
        // sair=0;
        ConfirmaOn=0;
        contador_seletor=1;
        sair=0;
        break;
        }

      case 'A':
      case 'a':
        // Confirmacao
        if (ConfirmaOn==1){
        if(contador_seletor==1)
          contador_seletor=1;
        else
          contador_seletor--;
        }
      break;

      case'd':
      case'D':
        if (ConfirmaOn==1){
        if(contador_seletor==2)
          contador_seletor=2;
        else
          contador_seletor++;
        }
      break;

      case 'w':
      case 'W':
        if(contador_selecao==1)
          contador_selecao=1;
        else
          contador_selecao--;
      break;

      case 's':
      case 'S':
        if (contador_selecao==0)
          contador_selecao=2;
        else if(contador_selecao==3)
          contador_selecao=3;
        else
          contador_selecao++;
      break;

    }


  }
  else
  switch (key){
    case 27:
    case 'p':
    case 'P':
    if(Start==1){
      Mix_PauseMusic();
      PauseOn=1;
        if(MovimentarOn==1)
          verificarLiberarMovimento(&theEnd, &MovimentarOn, MenuOn);
          }

    break;

    //Pular
    case 32: //Barra de Espaço
    case 'w':
    case 'W':
    if(MovimentarOn){
      if(PularOn==0)
        PularOn=1;

      //Quando pula cancela o rolamento
      resetRolamento(&q1,Textura_Jogador1,TXPLAYER,TYPLAYER,&RolamentoOn,&RolamentoContadorFrames);

    }


      break;

    //Rolamento:
    case 's':
    case 'S':
    case 25:
    if(MovimentarOn){
    // if(PularOn==0)
      if(RolamentoOn==0)
        RolamentoOn=1;
    }

    break;
    break;
    default:
      break;


  }

}

//Para habilitar teclas consideradas especiais (Setinhas do Teclado)
/*Não eh um controle oficial do jogo. Considere um "Easter-Egg"*/
void SpecialKeys(int key, int x, int y){
      switch (key)
  	{
  		case GLUT_KEY_LEFT:
  			break;
  		case GLUT_KEY_RIGHT:
  			break;
  		case GLUT_KEY_UP:
          if(MovimentarOn)
          {
            if(PularOn==0)
              PularOn=1;
            //Quando pula cancela o rolamento
            resetRolamento(&q1,Textura_Jogador1,TXPLAYER,TYPLAYER,&RolamentoOn,&RolamentoContadorFrames);

          }
  		  break;

      case GLUT_KEY_DOWN:
        if(MovimentarOn){
        // if(PularOn==0)
          if(RolamentoOn==0)
            RolamentoOn=1;
        }
  			break;
  	}
}


void inicializa(){
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  inicializaAudio();
  glClearColor(.3,.3,.3,0);
  inicializaTextura();
  initQuadrado();
}

//Essa função chama a função aumentaScore. Essa ultima responsavel por aumentar o score.
void chama_aumentaScore(int aumentaScoreTimer){
  if(theEnd==0)
    aumentaScore(&Score,MovimentarOn);
  glutTimerFunc(aumentaScoreTimer,chama_aumentaScore,aumentaScoreTimer);
}


//Essa função chama a função mudaCorrida(Não implementada, versão de teste. "Traços de desenvolvimento")
void chama_mudaCorrida(int mudaCorridaTimer){
  mudaCorrida(&mudaCorridaTimer,&DIST_SPAWN,&RANDOM_SPAWN);
  glutTimerFunc(mudaCorridaTimer,chama_mudaCorrida,mudaCorridaTimer);
}




void Jogo(){

    inicializa(); //Inicializa o Jogo.

  //Callbacks
    glutDisplayFunc(seletorCena);
    glutTimerFunc(timerAnimacao,verificaTextura,timerAnimacao);
    glutReshapeFunc(redimensiona);
    glutSpecialFunc(SpecialKeys); //Outras Teclas(Setinhas do Teclado)
    glutKeyboardFunc(keyboard); //Para teclas do ASCII CODE
    glutTimerFunc(fpstimer,atualiza,fpstimer);
    glutTimerFunc(aumentaScoreTimer,chama_aumentaScore,aumentaScoreTimer);
    glutMainLoop();
}
