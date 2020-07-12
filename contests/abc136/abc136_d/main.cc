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
  in(string, s);
  vector<int> ans(s.size());
  int re = 0;
  int ro = 0;
  rep(i, s.size() - 1) {
    if (s[i] == 'R') {
      swap(re, ro);
      ++re;
    }
    if (s[i + 1] == 'L') {
      ans[i] += re;
      ans[i + 1] += ro;
      re = ro = 0;
    }
  }
  int le = 0;
  int lo = 0;
  for (int i = s.size() - 1; i >= 1; --i) {
    if (s[i] == 'L') {
      swap(le, lo);
      ++le;
    }
    if (s[i - 1] == 'R') {
      ans[i] += le;
      ans[i - 1] += lo;
      le = lo = 0;
    }
  }
  rep(i, s.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
