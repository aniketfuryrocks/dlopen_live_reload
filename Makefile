all: clean make_lib make_main run

clean:
	cd dist && rm -rf *.so *.o

make_lib:
	clang src/lib.c -shared -o dist/lib.so

make_main:
	clang src/main.c -ldl -o dist/main.o

run: make_main
	cd dist && ./main.o
