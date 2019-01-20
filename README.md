# Run, Coutinho, Run! 

Jogo feito para um trabalho de Computação Gráfica, matéria lecionada pelo professor Flávio Coutinho no CEFET-MG.

## Enredo:

Coutinho gastou demais comprando camisetas em lojas online! Agora sua esposa está furiosa e ele deve fugir para sobreviver. Enquanto fugia, foi atingido por um tênis que sua companheira jogou, começando a enxergar personagens conhecidos de jogos retrô de sua infância! 

## Sobre o jogo:
Run, Coutinho, Run! é um jogo do tipo 'Endless Runner' programado em C, usando OpenGL, criado por Artur Bani e Rodrigo Gomes.

O jogo possui sprites próprias para o personagem principal (Coutinho) e design próprio (Texturas de menus, opções e popups). O restante são sprites de jogos conhecidos e artistas desconhecidos.

### Caso você seja o dono de alguma textura usada, por favor entrar em contato por meio do perfil de um dos criadores no GitHub ou por email (arturbani@gmail.com ou rgomesms227@gmail.com) para que possamos colocar os créditos!

### If you own any texture used in the game, please contact us here or by e-mail (arturbani@gmail.com or rgomesms227@gmail.com), so we can give you proper credits!

## Instalação e como jogar:
Certifique-se que possui as bibliotecas **freeglut**, **glew** e **SOIL** instaladas! 

Bibliotecas extras utilizadas:
 - SDL2
 - SDL2-Mixer

### Caso estejam utilizando o Ubuntu, podem instalá-las por meio desses comandos:
    sudo apt-get install libsdl2-dev
    sudo apt-get install libsdl2-mixer-dev
    sudo apt-get install libsdl-mixer1.2-dev

Para compilar o programa, execute o Makefile disponível por meio do comando **make run**.
### Caso prefira, o comando para compilar manualmente usando o GCC é:
 - gcc main.c structs.c mecanicas.c texto.c animacao.c Jogo.c telas.c -lglut -lGLU -lSOIL -lGLEW -lGL -lm -lSDL2 -lSDL2_mixer


