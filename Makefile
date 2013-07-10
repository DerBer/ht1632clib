all: libht1632c.so test

clean:
	rm -rf *.o *.a *.so

install: libht1632c.so
	cp $^ /usr/lib/

libht1632c.so:	ht1632c.o fonts.o rotenc.o /usr/lib/libwiringPi.so
	gcc -std=c99 -shared -o $@ $^
	strip $@

libht1632c.a:	ht1632c.o fonts.o rotenc.o
	ar rcs $@ $^

test:	test.o libht1632c.a /usr/lib/libwiringPi.so
	gcc -std=c99 -o $@ $^

%.o:	%.c
	gcc -std=c99 -o $@ -c $^
