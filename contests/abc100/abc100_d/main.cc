#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
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
  std::cout << value << '\n';
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

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, n, m);
  VV<ll> x(n, V<ll>(3));
  V<int> idx(n);
  rep(i, n) {
    rep(j, 3) cin >> x[i][j];
    idx[i] = i;
  }
  ll ans = 0;
  rep(s, 1 << 3) {
    auto f = [&](int i) {
      ll ret = 0;
      rep(j, 3) { ret += x[i][j] * (((s >> j) & 1) ? 1 : -1); }
      return ret;
    };
    sort(all(idx), [&](int a, int b) { return f(a) > f(b); });
    ll sum = 0;
    rep(j, 3) {
      ll tmp = 0;
      rep(i, m) { tmp += x[idx[i]][j]; }
      sum += abs(tmp);
    }
    ans = max(ans, sum);
  }
  out(ans);
}
