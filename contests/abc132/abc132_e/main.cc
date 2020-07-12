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
  in(int, n, m);
  vector<vector<int>> g(n + 1);
  rep(i, m) {
    in(int, u, v);
    g[u].push_back(v);
  }
  in(int, s, t);
  vector<vector<bool>> visited(n + 1, vector<bool>(3));
  visited[s][0] = true;
  queue<tuple<int, int, int>> que;
  que.push({s, 0, 0});
  while (!que.empty()) {
    auto [node, step, dist] = que.front();
    que.pop();
    if (node == t && step == 0) {
      out(dist);
      return 0;
    }
    for (int child : g[node]) {
      int nstep = step + 1;
      int ndist = dist;
      if (nstep == 3) {
        nstep = 0;
        ++ndist;
      }
      if (visited[child][nstep]) continue;
      visited[child][nstep] = true;
      que.push({child, nstep, ndist});
    }
  }
  out(-1);
}
