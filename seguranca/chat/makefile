all: chat


chat: sdes.o rc4.o rsa.o
	g++ chat.cpp -o chat -I. sdes.o rc4.o rsa.o -lev -std=c++11


sdes.o:
	g++ sdes.cpp -c -o sdes.o -std=c++11


rc4.o:
	g++ rc4.cpp -c -o rc4.o -std=c++11


rsa.o:
	g++ rsa.cpp -c -o rsa.o -std=c++11

clean:
	rm chat
	rm rc4.o
	rm sdes.o
	rm rsa.o
