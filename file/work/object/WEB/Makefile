tiny:       main_web.o web.o rio.o sbuf.o 
	 gcc -o tiny main_web.o web.o rio.o sbuf.o -lpthread
main_web.o: main_web.c
	 gcc -c main_web.c
web.o:      web.c
	 gcc -c web.c
rio.o:      rio.c
	 gcc -c rio.c
sbuf.o:     sbuf.c
	gcc -c sbuf.c
clean:
	rm main_web.o web.o sbuf.o rio.o

