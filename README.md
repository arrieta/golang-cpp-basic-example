# Calling C++ from Go

This repo contains a simple example calling C++ from Go.

Sample run (tested on macOS High Sierra 10.13.3 running go version go1.10 darwin/amd64):

```
$ make
clang++ -o liblibrary.so library.cpp library-bridge.cpp \
	-std=c++17 -O3 -Wall -Wextra -fPIC -shared
$ go run library.go 
[c++ bridge] LIB_NewFoo(42)
[c++] Foo::Foo(42)
[c++ bridge] LIB_NewFoo(42) will return pointer 0x42002e0
[c++ bridge] LIB_FooValue(0x42002e0)
[c++] Foo::value() is 42
[go] 42
[c++ bridge] LIB_DestroyFoo(0x42002e0)
[c++] Foo::~Foo(42)
