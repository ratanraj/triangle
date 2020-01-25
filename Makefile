CC=g++
OBJ = main.o Game.o TextureManager.o

triangle: $(OBJ)
	$(CC) -o triangle $(OBJ) -lSDL2 -lSDL2_image

%.o: %.cpp
	$(CC) -c -o $@ $^

clean:
	rm *.o triangle
