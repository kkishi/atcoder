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
  vector<ll> x(n), y(n), h(n);
  int I = -1;
  rep(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0) I = i;
  }
  assert(I >= 0);
  rep(cx, 101) rep(cy, 101) {
    ll H = h[I] + abs(x[I] - cx) + abs(y[I] - cy);
    bool ok = true;
    rep(i, n) {
      if (max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL) != h[i]) ok = false;
    }
    if (ok) {
      out(cx, cy, H);
      return 0;
    }
  }
}
