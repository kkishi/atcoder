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

int A[3][3];

bool bingo() {
  REP(i, 3) if (!A[i][0] && !A[i][1] && !A[i][2]) return true;
  REP(i, 3) if (!A[0][i] && !A[1][i] && !A[2][i]) return true;
  if (!A[0][0] && !A[1][1] && !A[2][2]) return true;
  if (!A[2][0] && !A[1][1] && !A[2][0]) return true;
  return false;
}

int main() {
  REP(i, 3) REP(j, 3) cin >> A[i][j];
  int N;
  cin >> N;
  REP(n, N) {
    int b;
    cin >> b;
    REP(i, 3) REP(j, 3) if (A[i][j] == b) A[i][j] = 0;
  }
  cout << (bingo() ? "Yes" : "No") << endl;
}
