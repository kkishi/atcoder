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

ll calc(ll x) {
  if (x == 0) return 0;
  return 1 + calc(x % __builtin_popcount(x));
}

int main() {
  in(ll, n);
  in(string, x);
  ll p = count(all(x), '1');

  map<ll, vector<ll>> mods_cache;
  auto getMods = [&](ll mod) -> auto& {
    if (mods_cache.count(mod) == 0) {
      vector<ll> m(n);
      m[0] = 1 % mod;
      for (ll i = 1; i < n; ++i) {
        m[i] = (m[i - 1] << 1) % mod;
      }
      mods_cache[mod] = m;
    }
    return mods_cache[mod];
  };

  auto getMod = [&](ll i, ll mod) { return getMods(mod)[n - 1 - i]; };

  map<ll, ll> get_sum_cache;
  auto getSum = [&](ll mod) {
    if (get_sum_cache.count(mod) == 0) {
      ll sum = 0;
      rep(i, n) if (x[i] == '1') sum += getMod(i, mod);
      get_sum_cache[mod] = sum;
    }
    return get_sum_cache[mod];
  };

  rep(i, n) {
    if (x[i] == '1') {
      if (p == 1) {
        out(0);
      } else {
        ll sum = getSum(p - 1);
        sum -= getMod(i, p - 1);
        sum %= p - 1;
        out(1 + calc(sum));
      }
    } else {
      ll sum = getSum(p + 1);
      sum += getMod(i, p + 1);
      sum %= p + 1;
      out(1 + calc(sum));
    }
  }
}
