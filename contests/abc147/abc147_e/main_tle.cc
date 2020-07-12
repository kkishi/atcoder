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

int h, w;
int a[80][80];
int b[80][80];

set<int> dp[81][81];

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];
  dp[0][1].insert(0);
  rep(i, h) rep(j, w) {
    int diff = abs(a[i][j] - b[i][j]);
    int dr[] = {-1, 0};
    int dc[] = {0, -1};
    rep(k, 2) {
      for (int d : dp[i + 1 + dr[k]][j + 1 + dc[k]]) {
        dbg(i, j, d);
        dp[i + 1][j + 1].insert(abs(d - diff));
        if (d + diff) {
          dp[i + 1][j + 1].insert(diff + d);
        }
      }
    }
  }
  out(*dp[h][w].begin());
}
