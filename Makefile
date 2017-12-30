EXEC = main
SOURCES = couleur.cpp point.cpp sphere.cpp ecran.cpp scene.cpp rayon.cpp pointcolore.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
CC = g++
CFLAGS = -Wall -g -Wextra -Werror -std=c++11

.PHONY: default clean
 
default: $(EXEC)
 
couleur.o: couleur.cpp couleur.hpp
point.o: point.cpp point.hpp
pointcolore.o: pointcolore.cpp pointcolore.hpp
rayon.o : rayon.cpp rayon.hpp
sphere.o: sphere.cpp sphere.hpp
scene.o: scene.cpp scene.hpp
ecran.o: ecran.cpp ecran.hpp



%.o: %.cpp
	$(CC) $< $(CFLAGS) -o $@ -c 
 
$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^
 
clean:
	rm -rf $(EXEC) $(OBJECTS) $(SOURCES:.cpp=.cpp~) $(SOURCES:.cpp=.hpp~) Makefile~
