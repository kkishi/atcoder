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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int N;
int X[100];

int cost(int i, int x) {
  int a = abs(X[i] - x);
  return a * a;
}

int main() {
  cin >> N;
  REP(i, N) cin >> X[i];

  int ans = 1000000000;
  for (int x = 1; x <= 100; ++x) {
    int total = 0;
    REP(i, N) total += cost(i, x);
    ans = min(ans, total);
  }
  cout << ans << endl;
}
