
all:
	make -C src latc
	cp ./src/latc ./

clean:
	rm -f latc
	make -C src clean
