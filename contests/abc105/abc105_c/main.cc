#include <bits/stdc++.h>

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
  in(ll, n);
  ll ans = 0;
  while (n) {
    if (n < 0) {
      ll val = -2;
      ll sum = -2;
      while (sum > n) {
        val *= 4;
        sum += val;
      }
      dbg(n, val, sum);
      ans |= -val;
      n -= val;
    } else {
      ll val = 1;
      ll sum = 1;
      while (sum < n) {
        val *= 4;
        sum += val;
      }
      dbg(n, val, sum);
      ans |= val;
      n -= val;
    }
  }
  if (int clz = __builtin_clzll(ans); clz == 64) {
    out(0);
  } else {
    for (int i = 63 - clz; i >= 0; --i) {
      cout << ((ans >> i) & 1);
    }
    cout << endl;
  }
}