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
```

I can also build an executable

```
$ go build library.go
$ ./library
[c++ bridge] LIB_NewFoo(42)
[c++] Foo::Foo(42)
[c++ bridge] LIB_NewFoo(42) will return pointer 0x4500000
[c++ bridge] LIB_FooValue(0x4500000)
[c++] Foo::value() is 42
[go] 42
[c++ bridge] LIB_DestroyFoo(0x4500000)
[c++] Foo::~Foo(42)
```

## Calling C++ from goroutines

In the `goroutines` folder I created a very simple example that dispatches
multiple cpu-intensive tasks, and many io-intensive tasks. It is pleasant that
Go can coordinate the calls relatively well.

Sample run:

```
$ cd goroutines
$ make fancy
clang++ -o libfancy.so fancy.cpp \
	-std=c++17 -O3 -Wall -Wextra -fPIC -shared
go build fancy.go
$ ./fancy
[go] dispatched all tasks
[go] dispatching io_intensive
[go] dispatching cpu_intensive( 45 )
[go] dispatching cpu_intensive( 30 )
[c++] starting to download NASA image on thread 0x7fff94f7d340.
[c++] starting fib(45) on thread 0x7000006a0000.
[go] dispatching cpu_intensive( 45 )
[c++] starting fib(30) on thread 0x70000061d000.
[go] dispatching cpu_intensive( 40 )
[c++] starting fib(45) on thread 0x70000059a000.
[c++] starting fib(40) on thread 0x7000008ac000.
[go] dispatching cpu_intensive( 35 )
[c++] starting fib(35) on thread 0x7000007a6000.
[go] dispatching cpu_intensive( 35 )
[go] dispatching cpu_intensive( 30 )
[c++] starting fib(35) on thread 0x7000009b2000.
[c++] starting fib(30) on thread 0x700000829000.
[go] dispatching cpu_intensive( 30 )
[c++] starting fib(30) on thread 0x700000a35000.
[c++] fib(30) on thread 0x700000829000 took 0.003607 seconds.
[go] dispatching cpu_intensive( 45 )
[go] dispatching cpu_intensive( 45 )
[c++] fib(30) on thread 0x70000061d000 took 0.003796 seconds.
[go] dispatching cpu_intensive( 40 )
[c++] starting fib(45) on thread 0x700000829000.
[go] dispatching cpu_intensive( 40 )
[c++] fib(30) on thread 0x700000a35000 took 0.003653 seconds.
[go] dispatching cpu_intensive( 50 )
[c++] starting fib(45) on thread 0x700000ab8000.
[c++] starting fib(40) on thread 0x70000061d000.
[c++] starting fib(40) on thread 0x70000092f000.
[c++] starting fib(50) on thread 0x700000a35000.
[go] dispatching cpu_intensive( 45 )
[c++] starting fib(45) on thread 0x700000b3b000.
[go] dispatching io_intensive
[c++] starting to download NASA image on thread 0x700000bbe000.
[go] dispatching cpu_intensive( 50 )
[c++] starting fib(50) on thread 0x700000c41000.
[go] dispatching cpu_intensive( 35 )
[c++] starting fib(35) on thread 0x700000cc4000.
[go] dispatching io_intensive
[c++] starting to download NASA image on thread 0x700000d47000.
[c++] fib(35) on thread 0x7000009b2000 took 0.063846 seconds.
[go] dispatching cpu_intensive( 50 )
[c++] starting fib(50) on thread 0x7000009b2000.
[c++] fib(35) on thread 0x7000007a6000 took 0.067398 seconds.
[go] dispatching cpu_intensive( 45 )
[c++] starting fib(45) on thread 0x7000007a6000.
[c++] fib(35) on thread 0x700000cc4000 took 0.054202 seconds.
[c++] fib(40) on thread 0x70000061d000 took 0.707855 seconds.
[c++] fib(40) on thread 0x7000008ac000 took 0.716816 seconds.
[c++] fib(40) on thread 0x70000092f000 took 0.716797 seconds.
[c++] fib(45) on thread 0x70000059a000 took 6.23767 seconds.
[c++] fib(45) on thread 0x700000829000 took 6.23499 seconds.
[c++] fib(45) on thread 0x7000006a0000 took 6.23971 seconds.
[c++] fib(45) on thread 0x700000ab8000 took 6.2396 seconds.
[c++] fib(45) on thread 0x700000b3b000 took 6.23648 seconds.
[c++] fib(45) on thread 0x7000007a6000 took 6.1945 seconds.
[c++] downloaded NASA image
[c++] io_intensive on thread 0x7fff94f7d340 took 12.1647 seconds.
[c++] downloaded NASA image
[c++] io_intensive on thread 0x700000bbe000 took 23.5905 seconds.
[c++] downloaded NASA image
[c++] io_intensive on thread 0x700000d47000 took 32.3157 seconds.
[c++] fib(50) on thread 0x700000a35000 took 33.1472 seconds.
[c++] fib(50) on thread 0x700000c41000 took 33.1787 seconds.
[c++] fib(50) on thread 0x7000009b2000 took 33.2035 seconds.
[go] done (elapsed: 33.268694231 seconds)
```