
all:
	make -C src latte-jvm

clean:
	make -C src clean
	rm -f `find lattests | grep '\.j$$'`
	rm -f `find lattests | grep '\.class$$'`
