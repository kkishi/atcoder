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
  in(ll, n, q);
  vector<vector<int>> g(n + 1);
  rep(i, n - 1) {
    in(int, a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<ll> xs(n + 1);
  rep(i, q) {
    in(ll, p, x);
    xs[p] += x;
  }
  vector<ll> result(n + 1);
  function<void(ll, int, int)> dfs = [&](ll x, int node, int parent) {
    x += xs[node];
    result[node] = x;
    for (int child : g[node]) {
      if (child == parent) continue;
      dfs(x, child, node);
    }
  };
  dfs(0, 1, -1);
  rep(i, n) {
    if (i) cout << " ";
    cout << result[i + 1];
  }
  cout << endl;
}
