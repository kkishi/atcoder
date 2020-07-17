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

int Dfs(int l, int mult, int node, vector<tuple<int, int, int>>& v) {
  if (l == 1) {
    return node;
  }
  if (l % 2 == 0) {
    v.push_back({node, node + 1, 0});
    v.push_back({node, node + 1, mult});
    return Dfs(l / 2, mult * 2, node + 1, v);
  }
  int n = Dfs(l - 1, mult, node, v);
  v.push_back({node, n, (l - 1) * mult});
  return n;
}

int main() {
  in(int, l);
  vector<tuple<int, int, int>> v;
  int n = Dfs(l, 1, 0, v);
  out(n + 1, v.size());
  for (auto [a, b, c] : v) {
    out(a + 1, b + 1, c);
  }
}
