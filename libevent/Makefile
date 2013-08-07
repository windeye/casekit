CURRENT_PATH=$(PWD)
CC=g++
SHELL=/bin/sh

INCLUDES=-I/usr/local/include 
LIB_PATH=-L/usr/local/lib

CPPFLAGS=-O0 -g -static -fPIC -finline-functions -Wall -Werror-pipe \
        -Wreturn-type -Wtrigraphs -Wformat -Wparentheses -Wpointer-arith \
        -D_XOPEN_SOURE=500 -D_GNU_SOURCE -DSOCK_SERV -Wno-deprecated

LDFLAGS= -levent

all:config 

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDES) $(LIB_PATH)

config: config_test.o 
	$(CC)  -o $@ $^ $(INCLUDES) $(LIB_PATH) $(LDFLAGS)

clean:
	rm -f ./*.o ./timer 
