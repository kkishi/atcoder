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
  vector<int> target(3);
  rep(i, 3) cin >> target[i];
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  vector<int> current(3);
  int ans = numeric_limits<int>::max();
  function<void(int, int)> dfs = [&](int depth, int used_mp) {
    if (depth == n) {
      rep(i, 3) {
        if (current[i] == 0) return;
        used_mp += abs(target[i] - current[i]);
      }
      ans = min(ans, used_mp);
      return;
    }
    rep(i, 4) {
      int mp = 0;
      if (i < 3) {
        if (current[i] != 0) {
          mp += 10;
        }
        current[i] += l[depth];
      }
      dfs(depth + 1, used_mp + mp);
      if (i < 3) {
        current[i] -= l[depth];
      }
    }
  };
  dfs(0, 0);
  out(ans);
}
