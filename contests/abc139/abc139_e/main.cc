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
  in(int, n);
  vector<vector<int>> a(n, vector<int>(n - 1));
  rep(i, n) rep(j, n - 1) cin >> a[i][j];

  set<pair<int, int>> s1;
  set<pair<int, int>> s2;
  vector<int> indice(n);
  auto advance = [&](int x) {
    int y = a[x][indice[x]] - 1;
    ++indice[x];
    if (x > y) swap(x, y);
    const auto it = s1.insert({x, y});
    if (!it.second) {
      s2.insert({x, y});
    }
  };
  rep(i, n) advance(i);
  int ans = 0;
  int completed = 0;
  while (true) {
    vector<pair<int, int>> v(all(s2));
    if (v.empty()) {
      out(-1);
      return 0;
    }
    for (const auto p : v) {
      advance(p.first);
      advance(p.second);
      s2.erase(p);
      ++completed;
    }
    ++ans;
    if (completed == n * (n - 1) / 2) break;
  }
  out(ans);
}
