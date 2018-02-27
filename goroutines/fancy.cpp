#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>

#include "fancy.hpp"

// Print to STDOUT without interleaving messages
std::mutex gIO_MUTEX;
#define LOG(x)                                  \
  do {                                          \
    {                                           \
      std::lock_guard<std::mutex> _(gIO_MUTEX); \
      std::cout << x << std::endl;              \
    }                                           \
  } while (false)

// Sample "cpu-intensive" task
int fib(int n) {
  switch (n) {
    case 0:
      return 1;
    case 1:
      return 1;
    default:
      return fib(n - 1) + fib(n - 2);
  }
}

// Sample "io-intensive" task
static constexpr const char* const COMMAND =
    ""
    "curl -O "
    "https://photojournal.jpl.nasa.gov/tiff/PIA17218.tif "
    " 2>/dev/null";
int fetch_nasa_image() { return std::system(COMMAND); }

using namespace std::chrono;
int cpu_intensive(int n) {
  const auto tbeg = system_clock::now();
  const auto id = std::this_thread::get_id();
  LOG("[c++] starting fib(" << n << ") on thread " << id << ".");
  const auto res = n < 0 ? -1 : fib(n);
  const auto dur = nanoseconds(system_clock::now() - tbeg).count();
  LOG("[c++] fib(" << n << ") on thread " << id << " took " << (dur / 1.0E9)
                   << " seconds.");
  return res;
}

int io_intensive() {
  const auto tbeg = system_clock::now();
  const auto id = std::this_thread::get_id();
  LOG("[c++] starting to download NASA image on thread " << id << ".");
  const auto status = fetch_nasa_image();
  if (status == 0) {
    LOG("[c++] downloaded NASA image");
  } else {
    LOG("[c++] failed to download NASA image");
  }
  const auto dur = nanoseconds(system_clock::now() - tbeg).count();
  LOG("[c++] io_intensive on thread " << id << " took " << (dur / 1.0E9)
                                      << " seconds.");
  return status;
}
