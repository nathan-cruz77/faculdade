# You may try setting the environment variable to alter the lib search path
# Something like:
# export LD_LIBRARY_PATH=$(PWD)/lib

INCLUDE = -I./include
LIB = -Wl,-rpath,$(PWD)/lib -lev -fopenmp
LIB_PATH = $(PWD)/lib
OPTIONS = -std=c++11

SRC = src
BUILD = build


all: $(BUILD)/chat


$(BUILD)/chat: $(SRC)/chat.cpp $(BUILD)/sdes.o $(BUILD)/rc4.o $(BUILD)/rsa.o
	g++ $(INCLUDE) $(LIB) $(OPTIONS) -o $@ $^


$(BUILD)/sdes.o: $(SRC)/sdes.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rc4.o: $(SRC)/rc4.cpp
	g++ $(OPTIONS) -c -o $@ $^


$(BUILD)/rsa.o: $(SRC)/rsa.cpp
	g++ $(OPTIONS) -c -o $@ $^


clean:
	rm -f $(BUILD)/*
