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

struct Position {
  int r, c, dir;
  bool operator<(const Position& p) const {
    if (r != p.r) return r < p.r;
    if (c != p.c) return c < p.c;
    return dir < p.dir;
  }
};

struct Cost {
  int strokes;
  int dist;
  bool operator<(const Cost& c) const {
    if (strokes != c.strokes) return strokes < c.strokes;
    return dist < c.dist;
  }
};

struct State {
  Position position;
  Cost cost;
  bool operator<(const State& s) const {
    return s.cost < cost;
  }
};

const int INF = 1 << 30;

int main() {
  in(int, h, w, k);
  in(int, x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  vector<vector<vector<Cost>>> cost(h, vector(w, vector(4, Cost{INF, INF})));
  auto CostOf = [&](const Position& p)->Cost& { return cost[p.r][p.c][p.dir]; };
  priority_queue<State> que;
  auto push = [&](const State& s) {
    Cost& c = CostOf(s.position);
    if (!(s.cost < c)) return;
    c = s.cost;
    que.push(s);
  };
  rep(dir, 4) push(State{{x1, y1, dir}, {1, 0}});
  while (!que.empty()) {
    State here = que.top();
    que.pop();
    if (here.position.r == x2 && here.position.c == y2) {
      out(here.cost.strokes);
      return 0;
    }
    {
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      State there(here);
      there.position.r += dr[there.position.dir];
      there.position.c += dc[there.position.dir];
      if (there.cost.dist < k) {
        ++there.cost.dist;
      } else {
        ++there.cost.strokes;
        there.cost.dist = 1;
      }
      if (int r = there.position.r, c = there.position.c;
          0 <= r && r < h && 0 <= c && c < w && grid[r][c] == '.') {
        push(there);
      }
    }
    rep(i, 4) {
      State there(here);
      there.position.dir = i;
      ++there.cost.strokes;
      there.cost.dist = 0;
      push(there);
    }
  }
  out(-1);
}
