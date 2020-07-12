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
  REP(i, 3) {
    bool ok = true;
    REP(j, 3) if (A[i][j] > 0) ok = false;
    if (ok) return true;
  }
  REP(i, 3) {
    bool ok = true;
    REP(j, 3) if (A[j][i] > 0) ok = false;
    if (ok) return true;
  }
  {
    bool ok = true;
    REP(i, 3) {
      if (A[i][i] > 0) ok = false;
    }
    if (ok) return true;
  }
  {
    bool ok = true;
    REP(i, 3) {
      if (A[i][2 - i] > 0) ok = false;
    }
    if (ok) return true;
  }
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
