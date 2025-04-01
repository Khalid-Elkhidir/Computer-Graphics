main: main.cpp utils.c
	g++ -g -Wall -Wextra main.cpp utils.h utils.c -Wl,--copy-dt-needed-entries -lglut -lGLU -o main
curves: curves.cpp utils.c
	g++ -g -Wall -Wextra curves.cpp utils.h utils.c -Wl,--copy-dt-needed-entries -lglut -lGLU -o curves
clean:
	rm -rf main
