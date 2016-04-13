all: chat


chat: clean sdes.o rc4.o
	g++ chat.cpp -o chat -I. sdes.o rc4.o -lev -std=c++11


sdes.o:
	g++ sdes.cpp -c -o sdes.o -std=c++11


rc4.o:
	g++ rc4.cpp -c -o rc4.o -std=c++11


clean:
	rm chat
	rm rc4.o
	rm sdes.o
