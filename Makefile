all: libht1632c.so test

clean:
	rm -rf *.o *.a *.so

libht1632c.so:	ht1632c.o fonts.o /usr/lib/libwiringPi.so
	gcc -std=c99 -shared -o $@ $^
	strip $@

libht1632c.a:	ht1632c.o fonts.o
	ar rcs $@ $^

test:	test.o libht1632c.a /usr/lib/libwiringPi.so
	gcc -std=c99 -o $@ $^

%.o:	%.c
	gcc -std=c99 -o $@ -c $^
