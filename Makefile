cc = g++
cflags = -std=c++17 -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing
cflags += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
cflags += -Ilib/glfw/include -Ilib/glad/include -Ilib/glm/glm/ -Ilib/assimp/include
ldflags = lib/glfw/src/libglfw3.a lib/glad/src/glad.o lib/glm/glm/libglm_static.a lib/assimp/lib/libassimp.a lib/assimp/contrib/zlib/libzlibstatic.a

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
bin = bin

.PHONY: all clean dir softsim lib

lib:
	cd lib/glfw && cmake . && make
	cd lib/glad && gcc -c src/glad.c -Iinclude/ -o src/glad.o
	cd lib/glm && cmake . && make
	cd lib/assimp && cmake . -DBUILD_SHARED_LIBS=OFF -DASSIMP_BUILD_ZLIB=ON -DASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT=OFF -DASSIMP_INSTALL=OFF -DASSIMP_INSTALL_PDB=OFF && make

clean: 
	rm -rf $(obj) $(bin)/softsim

softsim: $(obj)
	$(cc) -o $(bin)/softsim $^ $(ldflags)
	./$(bin)/softsim

%.o : %.cpp
	$(cc) -o  $@ -c $< $(cflags)
