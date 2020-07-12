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
  in(int, n, k);
  in(string, s);
  vector<pair<bool, int>> v;
  int l = -1;
  dbg(s);
  rep(i, n) if (i + 1 == n || s[i] != s[i + 1]) {
    bool zero = s[i] == '0';
    v.push_back({zero, i - l});
    l = i;
    // dbg(v.back());
  }
  queue<pair<bool, int>> q;
  int sum = 0;
  int ans = 0;
  for (auto [zero, cnt] : v) {
    sum += cnt;
    if (zero) --k;
    q.push({zero, cnt});
    while (k < 0) {
      auto [z, c] = q.front();
      q.pop();
      sum -= c;
      if (z) ++k;
    }
    ans = max(ans, sum);
  }
  out(ans);
}
