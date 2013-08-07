CC=g++
CFLAGS=-Wall

all: node.o trie.o

node.o: node.cpp
	g++ -c node.cpp

trie.o: trie.cpp
	g++ -c trie.cpp

words.o: words.cpp
	g++ -c words.cpp
clean:
	rm -f node.o trie.o words.o wordstat
