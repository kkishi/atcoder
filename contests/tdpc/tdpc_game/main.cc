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

template <typename T>
bool Setmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  in(int, A, B);
  vector<int> a(A), b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  reverse(all(a));
  reverse(all(b));
  vector<int> as(A + 1), bs(B + 1);
  rep(i, A) as[i + 1] = as[i] + a[i];
  rep(i, B) bs[i + 1] = bs[i] + b[i];
  vector dp(A + 1, vector(B + 1, 0));
  rep(i, A + 1) rep(j, B + 1) {
    if (i > 0) Setmax(dp[i][j], as[i] + bs[j] - dp[i - 1][j]);
    if (j > 0) Setmax(dp[i][j], as[i] + bs[j] - dp[i][j - 1]);
  }
  out(dp[A][B]);
}
