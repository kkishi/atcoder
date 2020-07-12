#include <bits/stdc++.h>

template <typename T>
T BinarySearch(T lo, T hi, std::function<bool(T)> pred) {
  while (lo + 1 < hi) {
    T mid = (hi - lo) / 2 + lo;
    if (pred(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
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
  in(ll, n, k);
  vector<ll> a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(all(a));
  sort(all(f), greater<ll>());
  auto check = [&](ll x) {
    ll training = 0;
    rep(i, n) {
      if (a[i] * f[i] > x) {
        training += a[i] - x / f[i];
      }
    }
    return training > k;
  };
  ll x = BinarySearch<ll>(0, 1e12L+1, check);
  if (!check(x)) {
    out(x);
  } else {
    out(x + 1);
  }
}
