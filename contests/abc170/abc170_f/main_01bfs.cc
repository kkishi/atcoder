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
};

struct Cost {
  int strokes;
  int dist;
};

struct State {
  Position position;
  Cost cost;
};

int main() {
  in(int, h, w, k);
  in(int, x1, y1, x2, y2);
  --x1, --y1, --x2, --y2;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  vector<vector<vector<bool>>> visited(h, vector(w, vector(4, false)));
  deque<State> que;
  auto push = [&](const State& s, bool front) {
    const Position& p = s.position;
    if (visited[p.r][p.c][p.dir]) return;
    visited[p.r][p.c][p.dir] = true;
    if (front) {
      que.push_front(s);
    } else {
      que.push_back(s);
    }
  };
  rep(dir, 4) push(State{{x1, y1, dir}, {1, 0}}, false);
  while (!que.empty()) {
    State here = que.front();
    que.pop_front();
    dbg(here.cost.strokes, here.cost.dist);
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
      bool front;
      if (there.cost.dist < k) {
        ++there.cost.dist;
        front = true;
      } else {
        ++there.cost.strokes;
        there.cost.dist = 1;
        front = false;
      }
      if (int r = there.position.r, c = there.position.c;
          0 <= r && r < h && 0 <= c && c < w && grid[r][c] == '.') {
        push(there, front);
      }
    }
    rep(i, 4) {
      State there(here);
      there.position.dir = i;
      ++there.cost.strokes;
      there.cost.dist = 0;
      push(there, false);
    }
  }
  out(-1);
}
