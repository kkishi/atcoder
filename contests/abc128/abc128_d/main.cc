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
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  int ans = 0;
  for (int l = 0; l <= min(k, n); ++l) {
    for (int r = 0; r + l <= min(k, n); ++r) {
      priority_queue<int, vector<int>, greater<int>> q;
      rep(i, l) q.push(v[i]);
      rep(i, r) q.push(v[n - 1 - i]);
      rep(i, k - (l + r)) {
        if (!q.empty() && q.top() < 0) q.pop();
      }
      int sum = 0;
      while (!q.empty()) {
        sum += q.top();
        q.pop();
      }
      ans = max(ans, sum);
    }
  }
  out(ans);
}
