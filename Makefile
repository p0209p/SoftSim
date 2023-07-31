cc = g++
cflags = -std=c++17 -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing
cflags += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
cflags += -Ilib/glfw/include -Ilib/glad/include -Ilib/glm/glm/
ldflags = lib/glfw/src/libglfw3.a lib/glad/src/glad.o lib/glm/glm/libglm_static.a

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
bin = bin

.PHONY: all clean dir softsim lib

lib:
	cd lib/glfw && cmake . && make
	cd lib/glad && gcc -c src/glad.c -Iinclude/ -o src/glad.o
	cd lib/glm && cmake . && make

clean: 
	rm -rf $(obj) $(bin)/softsim

softsim: $(obj)
	$(cc) -o $(bin)/softsim $^ $(ldflags)
	./$(bin)/softsim

%.o : %.cpp
	$(cc) -o  $@ -c $< $(cflags)
