add: lib/libleakcheck.dylib

lib/libleakcheck.dylib: lib tmp tmp/mallochook.o tmp/init.o
	gcc -dynamiclib tmp/*.o -o $@

tmp/%.o: src/%.c
	gcc -c $< -o $@

tmp:
	mkdir tmp

lib:
	mkdir lib

clean:
	rm -rf lib tmp
