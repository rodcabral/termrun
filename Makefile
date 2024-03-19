CFLAGS = -Wall -Wextra
OBJ = ./build/obj

all: build libtermrun game

libtermrun: \
	$(OBJ)/trm_window.o \
	$(OBJ)/trm_context.o \
	$(OBJ)/trm_destroy.o

#example
game:
	gcc $(CFLAGS) -fsanitize=address ./example/main.c $(OBJ)/*.o -I include -o ./build/$@

$(OBJ)/%.o: ./src/%.c
	gcc -c $< -I include -o $@

build:
	mkdir build
	mkdir build/obj

clean:
	rm -rf build
