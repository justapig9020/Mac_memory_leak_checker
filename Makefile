add: libleakcheck.dylib

libleakcheck.dylib: pmalloc.o init.o
	gcc -dynamiclib *.o -o $@

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.dylib *.o
