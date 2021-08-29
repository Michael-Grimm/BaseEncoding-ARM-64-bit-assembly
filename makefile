clear_and_test: 
	make clear
	make build
	make -C ./test test

clear:
	rm -rf ./base_encoding.o
	rm -rf ./lib_base_encoding.a
	

build: lib_base_encoding.a

lib_base_encoding.a: base_encoding.o 
	ar rcs lib_base_encoding.a  base_encoding.o  


base_encoding.o: base_encoding.sx
	gcc -c -o ./base_encoding.o ./base_encoding.sx

 
	










	
