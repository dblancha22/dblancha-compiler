bminor: main.c scanner.c tokens.h
	gcc -o $@ main.c scanner.c

scanner.c: scanner.flex
	flex -o $@ scanner.flex

test:
	./tests/sample/run_all_tests.sh

clean:
	rm ./bminor
