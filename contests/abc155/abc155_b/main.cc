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
int A[100];

int main() {
  cin >> N;
  REP(i, N) cin >> A[i];

  bool ok = true;
  REP(i, N) if (A[i] % 2 == 0 && (A[i] % 3 != 0 && A[i] % 5 != 0)) {
    DBG(A[i]);
    ok = false;
  }

  if (ok) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
}
