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

bool check(int s, const vector<vector<pair<int, int>>>& v) {
  int n = v.size();
  rep(i, n) {
    if (!((s >> i) & 1)) continue;
    for (const auto& p : v[i]) {
      int j = p.first;
      bool honest = (s >> j) & 1;
      if (p.second == 1 != honest) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  in(int, n);
  vector<vector<pair<int, int>>> v(n);
  rep(i, n) {
    in(int, a);
    rep(j, a) {
      in(int, x, y);
      v[i].push_back({x - 1, y});
    }
  }
  int ans = 0;
  for (int s = 0; s < (1 << n); ++s) {
    if (check(s, v)) {
      ans = max(ans, __builtin_popcount(s));
    }
  }
  out(ans);
}
