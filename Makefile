CFLAGS = -Wall -Wextra
OBJ = ./build/obj

all: build libtermrun game

libtermrun: \
	$(OBJ)/trm_window.o \
	$(OBJ)/trm_context.o \
	$(OBJ)/trm_destroy.o \
	$(OBJ)/trm_event.o
	
	gcc $(CFLAGS) -fPIC -shared $(OBJ)/*.o -I include -o $(OBJ)/libtermrun.so
	cp -r ./include /usr/local/include
	mv /usr/local/include/include /usr/local/include/termrun
	mv $(OBJ)/libtermrun.so /lib

game:
	gcc $(CFLAGS) -fsanitize=address ./example/main.c -I include -ltermrun -o ./build/$@

$(OBJ)/%.o: ./src/%.c
	gcc -c -fPIC $< -I include -o $@

build:
	mkdir build
	mkdir build/obj

clean:
	rm -rf build
