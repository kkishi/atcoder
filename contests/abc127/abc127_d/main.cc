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
  in(ll, n, m);
  map<ll, ll> as;
  rep(i, n) {
    in(ll, a);
    ++as[a];
  }
  rep(i, m) {
    in(ll, b, c);
    ll changed = 0;
    while (changed < n && b > 0) {
      auto [k, v] = *as.begin();
      if (k >= c) {
        break;
      }
      ll change = min(b, v);
      if (change == v) {
        as.erase(as.begin());
      } else {
        as[k] -= change;
      }
      changed += change;
      b -= change;
    }
    as[c] += changed;
  }
  ll ans = 0;
  for (auto [k, v] : as) ans += k * v;
  out(ans);
}
