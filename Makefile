bminor: main.o scanner.o parser.o codegen.o expr.o stmt.o type.o param_list.o decl.o scope.o resolve.o symbol.o typecheck.o hash_table.o
	gcc -o $@ $^ -g

main.o: main.c tokens.h
	gcc -c -o $@ main.c -g

codegen.o: codegen.c codegen.h
	gcc -c -o $@ codegen.c -g

scope.o: scope.c scope.h
	gcc -c -o $@ scope.c -g

resolve.o: resolve.c resolve.h
	gcc -c -o $@ resolve.c -g

symbol.o: symbol.c symbol.h
	gcc -c -o $@ symbol.c -g

typecheck.o: typecheck.c typecheck.h
	gcc -c -o $@ typecheck.c -g

hash_table.o: hash_table.c hash_table.h
	gcc -c -o $@ hash_table.c

decl.o: decl.c decl.h
	gcc -c -o $@ decl.c

param_list.o: param_list.c param_list.h
	gcc -c -o $@ param_list.c -g

type.o: type.c type.h
	gcc -c -o $@ type.c -g

stmt.o: stmt.c stmt.h
	gcc -c -o $@ stmt.c -g

expr.o: expr.c expr.h
	gcc -c -o $@ expr.c -g

scanner.o: scanner.c tokens.h
	gcc -c -o $@ scanner.c

scanner.c: scanner.flex
	flex -o $@ scanner.flex

parser.o: parser.c tokens.h
	gcc -c -o $@ parser.c

parser.c: parser.bison
	bison -o $@ --defines=tokens.h parser.bison

test: bminor
	./typecheck_tests/run_tests.sh

clean:
	rm ./bminor ./*.o
