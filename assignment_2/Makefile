1: 1.cpp utils.c
	g++ -g -Wall -Wextra 1.cpp utils.h utils.c -Wl,--copy-dt-needed-entries -lglut -lGLU -o 1
2: 2.cpp circle.h circle.cpp
	g++ -g -Wall -Wextra 2.cpp circle.h circle.cpp -Wl,--copy-dt-needed-entries -lglut -lGLU -o 2
3: 3.cpp utils.c
	g++ -g -Wall -Wextra 3.cpp utils.h utils.c -Wl,--copy-dt-needed-entries -lglut -lGLU -o 3
4: 4.cpp utils.c
	g++ -g -Wall -Wextra 4.cpp utils.h utils.c -Wl,--copy-dt-needed-entries -lglut -lGLU -o 4
test: test.cpp circle.h circle.cpp
	g++ -g -Wall -Wextra test.cpp circle.h circle.cpp -Wl,--copy-dt-needed-entries -lglut -lGLU -o test
clean:
	rm -rf 1 2 3 4 test
