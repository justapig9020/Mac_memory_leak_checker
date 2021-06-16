add: libleakcheck.dylib

libleakcheck.dylib: pmalloc.o
	gcc -dynamiclib pmalloc.o -o $@

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.dylib
