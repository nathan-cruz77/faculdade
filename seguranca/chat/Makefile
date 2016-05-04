all: chat


chat: chat.cpp sdes.o rc4.o rsa.o
	g++ chat.cpp -o chat -I. sdes.o rc4.o rsa.o -lev -std=c++11


sdes.o: sdes.cpp
	g++ sdes.cpp -c -o sdes.o -std=c++11


rc4.o: rc4.cpp
	g++ rc4.cpp -c -o rc4.o -std=c++11


rsa.o: rsa.cpp
	g++ rsa.cpp -c -o rsa.o -std=c++11

clean:
	rm rc4.o
	rm sdes.o
	rm rsa.o
	rm chat
