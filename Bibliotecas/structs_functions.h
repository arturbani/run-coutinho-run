//Funcoes do quadrado header


//Objeto Manipulado + Novo Nome
void nomeQuadrado(quadrado*Objeto, char* Novo_Nome);
//Objeto Manipulado + Nova Coord X e Nova Coord Y
void posQuadrado(quadrado* Objeto ,float Novo_X,float Novo_Y );
//Objeto Manipulado + Novo Tamanho no Eixo X(Tx) e Novo Tamanho no Eixo Y (Ty)
void tamQuadrado(quadrado* Objeto,float Novo_Tx, float Novo_Ty);
//Objeto Manipulado + cores R,G,B
void corQuadrado(quadrado *Objeto,float r,float g,float b);
//Realiza um Link entre dois Objetos(Liga Dois Quadrados formando uma Lista Encadeada)
void linkQuadrado(quadrado *Objeto1, quadrado*Objeto2);
//Acaba o Link(Fim_da_Lista_Encadeada) entre os Quadrados
void linkEnd(quadrado *Objeto1);


void texturaQuadrado(quadrado *a, GLuint type);


//Moeda:
  void initAsMoeda(quadrado *a);

  //Funcao para colisao da moeda
  void colisaoMoeda(quadrado *a,int *score);


//Inimigos:
  //Inicialização como Inimigo
  void initAsInimigo(quadrado *a);

  //O efeito da colisão com Inimigo
  void colisaoInimigo(quadrado *a);

  //Inicialização do Jogador
  void initAsJogador(quadrado *a);

  //Inicialização de PowerUps
  void initAsPowerUp(quadrado *a);


//Fundo:
  void initAsFundo(quadrado *a);
  // void initAsGrama(quadrado *a);

// TESTE
void PropriedadesQuadrado(quadrado * q1, GLuint backup, GLuint rolamento, GLuint pulo, GLuint morte);