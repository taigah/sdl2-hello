main: main.c
	gcc main.c -lSDL2 -o main

.PHONY: clean
clean:
	rm main
