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

template <typename T>
std::map<T, int> Factorize(T x) {
  std::map<T, int> m;
  for (T i = 2; i * i <= x;) {
    if (x % i == 0) {
      m[i]++;
      x /= i;
    } else {
      ++i;
    }
  }
  if (x > 1) m[x]++;
  return m;
}

int main() {
  in(ll, n, k);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll sum = accumulate(all(a), 0LL);
  map<ll, int> fs = Factorize(sum);
  vector<pair<ll, int>> v(all(fs));

  auto check = [&](ll g) {
    vector<ll> mods(n);
    rep(i, n) mods[i] = a[i] % g;
    sort(all(mods));
    vector<ll> upper(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      upper[i] = upper[i + 1] + g - mods[i];
    }
    vector<ll> lower(n + 1);
    rep(i, n) {
      lower[i + 1] = lower[i] + mods[i];
    }
    rep(i, n) {
      ll l = lower[i + 1], u = upper[i + 1];
      dbg(g, l, u);
      if (l > k) continue;
      if (l == u) {
        return true;
      }
    }
    return false;
  };

  function<ll(int, ll)> dfs = [&](int depth, ll g)->ll {
    if (depth == v.size()) {
      if (check(g)) {
        return g;
      }
      return 0LL;
    }
    ll ret = 0;
    rep(i, v[depth].second + 1) {
      ret = max(ret, dfs(depth + 1, g));
      g *= v[depth].first;
    }
    return ret;
  };

  out(dfs(0, 1));
}
