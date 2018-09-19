
void verificarLiberarMovimento(int *theEnd,int* MovimentarOn, int MenuOn);

void verificaColisao(quadrado *a, quadrado* Jogador,int* ColisaoOn);

void puloBackup(float *pulo, float*oldpulo);

void resetPulo(float *pulo, float*oldpulo, int * PularOn);

void pular(quadrado *Jogador, float *pulo,float *oldpulo, float *incPulo,int *groundlevel,int *PularOn);


void resetRolamento(quadrado *Objeto, GLuint Textura_Original,
                    int TXOriginal, int TYOriginal, int *RolamentoOn, int *RolamentoContadorFrames);


void aumentaScore(int *score, int MovimentaOn );
float posMaisDistante(quadrado *Primeiro_Quadrado);


//Teste(Não Implementado):
void  mudaCorrida(int *Tempo,int *MIN_DIST_SPAWN,int *MAX_RANDOM_SPAWN);
