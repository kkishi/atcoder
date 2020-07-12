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

struct State {
  int diff;
  int r, c;
  bool operator<(const State& s) const {
    if (diff != s.diff) {
      return diff > s.diff;
    }
    if (r != s.r) {
      return r < s.r;
    }
    return c < s.c;
  }
};

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];

  State init = {abs(a[0][0] - b[0][0]), 0, 0};

  map<State, int> seen;
  seen[init] = init.diff;

  priority_queue<State> que;
  que.push(init);

  while (!que.empty()) {
    State here = que.top();
    que.pop();
    dbg(here.diff, here.r, here.c);
    if (here.r == h - 1 && here.c == w - 1) {
      out(here.diff);
      return 0;
    }
    int dr[] = {1, 0};
    int dc[] = {0, 1};
    rep(i, 2) {
      int nr = here.r + dr[i];
      int nc = here.c + dc[i];
      if (nr == h || nc == w) continue;
      int d = abs(a[nr][nc] - b[nr][nc]);
      dbg(d);
      int sign[] = {-1, 1};
      rep(j, 2) {
        State there = {abs(here.diff + sign[j] * d), nr, nc};
        if (seen.count(there) && seen[there] <= there.diff) continue;
        seen[there] = there.diff;
        que.push(there);
      }
    }
  }
}
