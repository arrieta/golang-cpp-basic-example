liblibrary.so: fancy.cpp
	clang++ -o libfancy.so fancy.cpp \
	-std=c++17 -O3 -Wall -Wextra -fPIC -shared

fancy: fancy.go liblibrary.so
	go build fancy.go
