INC = -I./uthash/include -I./include

add: lib/libleakcheck.dylib

lib/libleakcheck.dylib: lib tmp tmp/mallochook.o tmp/init.o tmp/mem_tracer.o
	gcc -dynamiclib tmp/*.o -o $@

tmp/%.o: src/%.c
	gcc -c $< -o $@ $(INC)

tmp:
	mkdir tmp

lib:
	mkdir lib

clean:
	rm -rf lib tmp
