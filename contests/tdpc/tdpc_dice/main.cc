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
  in(ll, n, d);

  map<ll, int> fs = Factorize(d);
  for (auto [k, _] : fs) {
    if (!set{2, 3, 5}.count(k)) {
      out(0);
      return 0;
    }
  }

  vector dp(60, vector(38, vector(26, 0.0)));
  dp[0][0][0] = 1;
  rep(i, n) {
    vector ndp(60, vector(38, vector(26, 0.0)));
    rep(two, 60) rep(three, 38) rep(five, 26) {
      auto add = [&](int a, int b, int c) {
        ndp[min(59, two + a)][min(37, three + b)][min(25, five + c)] +=
            dp[two][three][five] / 6;
      };
      add(0, 0, 0);
      add(1, 0, 0);
      add(0, 1, 0);
      add(2, 0, 0);
      add(0, 0, 1);
      add(1, 1, 0);
    }
    swap(dp, ndp);
  }

  double ans = 0;
  for (int two = fs[2]; two < 60; ++two) {
    for (int three = fs[3]; three < 38; ++three) {
      for (int five = fs[5]; five < 26; ++five) {
        ans += dp[two][three][five];
      }
    }
  }
  printf("%.9f\n", ans);
}
