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
template <typename T>
using vec = std::vector<T>;

using namespace std;

int main() {
  in(int, h, w);
  int H = h + 2, W = w + 2;

  vec<string> s(H);
  s[0] = s[H - 1] = string(W, '#');
  rep(i, h) {
    in(string, row);
    s[i + 1] = '#' + row + '#';
  }

  function<int(int, int, int, int, vec<vec<int>>&)> rec =
      [&](int dr, int dc, int r, int c, vec<vec<int>>& m) {
        if (s[r][c] == '#') {
          return 0;
        }
        if (m[r][c] == -1) {
          m[r][c] = rec(dr, dc, r + dr, c + dc, m) + 1;
        }
        return m[r][c];
      };
  vec<vec<vec<int>>> memo(4, vec<vec<int>>(H, vec<int>(W, -1)));
  int ans = 0;
  int dr[] = {1, -1, 0, 0};
  int dc[] = {0, 0, 1, -1};
  rep(r, H) rep(c, W) if (s[r][c] == '.') {
    int res = -3;
    rep(i, 4) res += rec(dr[i], dc[i], r, c, memo[i]);
    ans = max(ans, res);
  }
  out(ans);
}
