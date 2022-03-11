.PHONY: all

all: main

bridge.so:
	/usr/bin/clang++ -o libbridge.so *.cpp  -std=c++20 -O3 -Wall -Wextra -fPIC -shared

main: bridge.so
	go build main.go
