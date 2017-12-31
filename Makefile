CC = g++
CFLAGS = -Wall -Wextra -g -std=c++11
EXEC_NAME = lancer
OBJ_FILES = couleur.o ecran.o objet.o point.o pointcolore.o rayon.o scene.o sphere.o triangle.o

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<
