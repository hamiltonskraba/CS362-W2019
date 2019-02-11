CFLAGS = -Wall -fpic -coverage -lm

test: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

runtest: test
	./testme

clean:
	-rm -f testme testme.exe *.gcda *.gcno
