
//Função Desenvolvimento do Jogo
void verificarLiberarMovimento(int *theEnd,int* MovimentarOn){
    if(*theEnd == 0){    //Nao liberar movimento enquanto em tela de morte (TESTE) (DESATIVADO)
        if(*MovimentarOn == 0)
            *MovimentarOn = 1;
        else
            *MovimentarOn = 0;
    }
}
