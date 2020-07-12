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
  in(int, m, k);

  if (m == 0) {
    if (k == 0) {
      out(0, 0);
    } else {
      out(-1);
    }
    return 0;
  }
  if (m == 1) {
    if (k == 0) {
      out(0, 0, 1, 1);
    } else {
      out(-1);
    }
    return 0;
  }

  int pow2 = 1 << m;

  int xors = 0;
  rep(i, pow2) xors ^= i;
  dbg(xors);

  if (0 <= k && k < pow2) {
    for (int i = 0; i < pow2; ++i) {
      if (i == k) continue;
      cout << i << " ";
    }
    cout << k << " ";
    for (int i = pow2 - 1; i >= 0; --i) {
      if (i == k) continue;
      cout << i << " ";
    }
    cout << k << endl;
  } else {
    out(-1);
  }
}
