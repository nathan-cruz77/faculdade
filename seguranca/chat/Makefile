INCLUDE = -I./include
LIB = -Wl,-rpath,$(PWD)/lib
LIB_PATH = $(PWD)/lib
OPTIONS = -std=c++11

SRC = src
BUILD = build


all: $(BUILD)/chat


$(BUILD)/chat: $(SRC)/chat.cpp $(BUILD)/sdes.o $(BUILD)/rc4.o $(BUILD)/rsa.o $(LIB_PATH)/libev.so.4
	# export LD_LIBRARY_PATH=$(PWD)/lib
	g++ $(INCLUDE) $(LIB) $(OPTIONS) -o $@ $^


$(BUILD)/sdes.o: $(SRC)/sdes.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rc4.o: $(SRC)/rc4.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rsa.o: $(SRC)/rsa.cpp
	g++ $(OPTIONS) -c -o $@ $^


clean:
	rm -f $(BUILD)/*
