TESTS := $(patsubst test/%.c,test/target/%,$(wildcard test/*.c))
INC = -I./uthash/include -I./include

all: lib/libleakcheck.dylib

lib/libleakcheck.dylib: lib tmp tmp/mallochook.o tmp/init.o tmp/mem_tracer.o
	gcc -dynamiclib tmp/*.o -o $@

tmp/%.o: src/%.c
	gcc -c $< -o $@ $(INC)

tmp:
	mkdir -p tmp

lib:
	mkdir -p lib

test: $(TESTS) all
	@./test/run_test.sh

test/target/%: test/target/%.o
	gcc $< -o $@

test/target/%.o: test/%.c test_target
	gcc -c $< -o $@

test_target:
	mkdir -p test/target

clean:
	rm -rf lib tmp test/target
