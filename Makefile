bminor: main.o scanner.o tokens.h parser.o
	gcc -o $@ main.o scanner.o parser.o

main.o: main.c tokens.h
	gcc -c -o $@ main.c

scanner.o: scanner.c tokens.h
	gcc -c -o $@ scanner.c

scanner.c: scanner.flex
	flex -o $@ scanner.flex

parser.o: parser.c tokens.h
	gcc -c -o $@ parser.c

parser.c: parser.bison
	bison -o $@ --defines=tokens.h parser.bison


#test:
#	./tests/sample/run_all_tests.sh

clean:
	rm ./bminor ./*.o
