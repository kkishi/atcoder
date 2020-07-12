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

int N, M;
int s[5], c[5];

bool ok(int i) {
  REP(m, M) {
    int j = i;
    REP(si, N - s[m]) j /= 10;
    if (i == 702) DBG(N, m, s[m], c[m], j);
    if (j % 10 != c[m])  return false;
  }
  return true;
}

int main() {
  cin >> N >> M;
  REP(i, M) cin >> s[i] >> c[i];

  int minimum = 1;
  REP(n, N - 1) minimum *= 10;
  if (N == 1) minimum = 0;
  int maximum = 1;
  REP(n, N) maximum *= 10;

  int ans = -1;
  for (int i = minimum; i < maximum; ++i) {
    if (ok(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
