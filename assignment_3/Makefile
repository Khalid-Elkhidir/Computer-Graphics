1: 1.cpp utils.c
	g++ -g -Wall -Wextra 1.cpp utils.h utils.c transform.h -Wl,--copy-dt-needed-entries -lglut -lGLU -o 1
2: 2.cpp circle.h circle.cpp
	g++ -g -Wall -Wextra 2.cpp transform.h -Wl,--copy-dt-needed-entries -lglut -lGLU -o 2
3: 3.cpp utils.c
	g++ -g -Wall -Wextra 3.cpp utils.h utils.c transform.h -Wl,--copy-dt-needed-entries -lglut -lGLU -o 3
clean:
	rm -rf 1 2 3
