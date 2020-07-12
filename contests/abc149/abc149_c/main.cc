#include <bits/stdc++.h>

std::vector<bool> Sieve(int n) {
  std::vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (!v[i]) {
      continue;
    }
    for (int j = i * 2; j <= n; j += i) {
      v[j] = false;
    }
  }
  return v;
}

std::vector<int> Primes(int n) {
  std::vector<bool> sieve = Sieve(n);
  std::vector<int> v;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      v.push_back(i);
    }
  }
  return v;
}

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  in(int, x);
  vector<bool> sieve = Sieve(200000);
  while (!sieve[x]) ++x;
  out(x);
}
