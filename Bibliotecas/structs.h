
typedef struct Quadrado{
    char nome [30];
    float x;
    float y;
    float tx;
    float ty;
    float r,g,b; //Cores
    struct Quadrado *proxquadrado;

}quadrado;

//Funções Base:

void nomeQuadrado(quadrado*a, char* asd){
  strcpy(a->nome,asd);
}



void posQuadrado(quadrado* a ,float xa,float ya ){
    a->x = xa;
    a->y = ya;
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

void linkQuadrado(quadrado *a, quadrado*b){
  a->proxquadrado = b;


}

void linkEnd(quadrado *a){
  a->proxquadrado = NULL;
}
