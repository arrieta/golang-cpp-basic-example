liblibrary.so: library.cpp library-bridge.cpp
	clang++ -o liblibrary.so library.cpp library-bridge.cpp \
	-std=c++17 -O3 -Wall -Wextra -fPIC -shared
