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

struct State {
  int r, c;
  int cost;
};

int main() {
  in(int, h, w, k);
  in(int, x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  State init = {x1, y1, 0};
  vector<vector<int>> seen(h, vector(w, -1));
  seen[x1][y1] = 0;
  queue<State> que;
  que.push(init);

  while (!que.empty()) {
    State here = que.front();
    dbg(here.r, here.c, here.cost);
    que.pop();
    if (here.r == x2 && here.c == y2) {
      out(here.cost);
      return 0;
    }
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    rep(i, 4) {
      for (int j = 1; j <= k; ++j) {
        State there(here);
        there.r = here.r + dr[i] * j;
        there.c = here.c + dc[i] * j;
        there.cost++;
        if (there.r < 0 || h <= there.r ||
            there.c < 0 || w <= there.c) {
          break;
        }
        if (grid[there.r][there.c] == '@') {
          break;
        }
        int& s = seen[there.r][there.c];
        if (s != -1 && s < there.cost) break;
        if (s != -1 && s <= there.cost) continue;
        s = there.cost;
        que.push(there);
      }
    }
  }
  out(-1);
}
