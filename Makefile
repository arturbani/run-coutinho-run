CC=gcc
OPCOES_COMPILADOR=-I. -I/usr/include/SOIL -lglut -lGLU -lSOIL -lGLEW -lGL -lm -lSDL2 -lSDL2_mixer
TODOS_ARQUIVOS_PONTOH =
TODOS_ARQUIVOS_OBJ = main.c structs.c mecanicas.c texto.c animacao.c Jogo.c telas.c

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all:$(TODOS_ARQUIVOS_OBJ)
	$(CC) -o main.o $^ $(OPCOES_COMPILADOR)

run: all
	./main.o


clean:
	rm *.o main

#gcc main.c structs.c verificar.c texto.c respawn.c 

