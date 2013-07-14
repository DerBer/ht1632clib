all: libht1632c.so libht1632c-py.so test

clean:
	rm -rf *.o *.a *.so

# install: libht1632c.so
# 	cp $^ /usr/lib/

PYTHON_VERSION=2.7

libht1632c-py.so:	ht1632c.o fonts.o rotenc.c /usr/lib/libwiringPi.so
	gcc -std=c99 -shared -DPYTHON -I/usr/include/python${PYTHON_VERSION} -L/Python${PYTHON_VERSION}/libs -lpython${PYTHON_VERSION} -o $@ $^
	strip $@

libht1632c.so:	ht1632c.o fonts.o rotenc.o /usr/lib/libwiringPi.so
	gcc -std=c99 -shared -o $@ $^
	strip $@

libht1632c.a:	ht1632c.o fonts.o rotenc.o
	ar rcs $@ $^

test:	test.o libht1632c.a /usr/lib/libwiringPi.so
	gcc -std=c99 -o $@ $^

%.o:	%.c
	gcc -std=c99 -o $@ -c $^
