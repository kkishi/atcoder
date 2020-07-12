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

struct Edge {
  int node;
  int index;
};

int main() {
  in(int, n);
  vector<vector<Edge>> edges(n + 1);
  rep(i, n) {
    in(int, a, b);
    edges[a].push_back({b, i});
    edges[b].push_back({a, i});
  }
  set<int> seen;
  seen.insert(1);
  queue<int> que;
  que.push(1);
  map<int, int> color;
  int max_color = 0;
  while (!que.empty()) {
    int here = que.front();
    que.pop();
    set<int> used;
    for (Edge e : edges[here]) used.insert(color[e.index]);
    int c = 1;
    for (Edge e : edges[here]) {
      if (seen.count(e.node)) continue;
      seen.insert(e.node);
      assert(color[e.index] == 0);
      while (used.count(c)) ++c;
      color[e.index] = c;
      max_color = max(max_color, c);
      ++c;
      que.push(e.node);
    }
  }
  out(max_color);
  rep(i, n - 1) out(color[i]);
}
