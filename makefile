all: compile run

compile:
	gcc -I ./include -c src/zaman.c           -o lib/zaman.o
	gcc -I ./include -c src/gezegen.c         -o lib/gezegen.o
	gcc -I ./include -c src/kayac_gezegen.c   -o lib/kayac_gezegen.o
	gcc -I ./include -c src/gazdevi_gezegen.c -o lib/gazdevi_gezegen.o
	gcc -I ./include -c src/buzdevi_gezegen.c -o lib/buzdevi_gezegen.o
	gcc -I ./include -c src/cuce_gezegen.c    -o lib/cuce_gezegen.o
	gcc -I ./include -c src/kisi.c            -o lib/kisi.o
	gcc -I ./include -c src/uzayaraci.c       -o lib/uzayaraci.o
	gcc -I ./include -c src/dosya_okuma.c     -o lib/dosya_okuma.o
	gcc -I ./include -c src/simulasyon.c      -o lib/simulasyon.o
	gcc -I ./include -c main.c                -o lib/main.o
	gcc lib/*.o -o bin/uzaysimulasyonu.exe

run:
	bin/uzaysimulasyonu.exe

clean:
	del /Q lib\\*.o bin\\uzaysimulasyonu.exe 2>nul || rm -rf lib/*.o bin/uzaysimulasyonu.exe
