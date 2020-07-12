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
  in(int, k);
  int n = 1 << k;

  vector<double> ratings(n);
  rep(i, n) cin >> ratings[i];

  map<pair<int, int>, double> memo;
  function<double(int, int)> prob = [&](int index, int wins) {
    pair<int, int> key = {index, wins};
    double& m = memo[key];
    if (m == 0) {
      if (wins == 0) {
        m = 1;
      } else {
        m = 0;
        int p = index;
        rep(i, wins - 1) p /= 2;
        p ^= 1;
        int l = p, r = p;
        rep(i, wins - 1) {
          l = l * 2;
          r = r * 2 + 1;
        }
        for (int i = l; i <= r; ++i) {
          if (i == index) continue;
          m += prob(i, wins - 1) /
               (1 + pow(10, (ratings[i] - ratings[index]) / 400));
        }
        m *= prob(index, wins - 1);
      }
    }
    return m;
  };

  cout << fixed << setprecision(9);
  rep(i, n) out(prob(i, k));
}
