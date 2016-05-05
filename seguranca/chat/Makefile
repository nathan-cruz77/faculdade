INCLUDE = -I./include
LIB = -L./lib
OPTIONS = -std=c++11

SRC = src
BUILD = build


all: $(BUILD)/chat


$(BUILD)/chat: $(SRC)/chat.cpp $(BUILD)/sdes.o $(BUILD)/rc4.o $(BUILD)/rsa.o
	export LD_LIBRARY_PATH=$(PWD)/lib
	g++ $(INCLUDE) -lev $(OPTIONS) -o $@ $^


$(BUILD)/sdes.o: $(SRC)/sdes.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rc4.o: $(SRC)/rc4.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rsa.o: $(SRC)/rsa.cpp
	g++ $(OPTIONS) -c -o $@ $^


clean:
	rm -f $(BUILD)/*
