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
ll maximum[100001];
ll A[100001];

ll solve() {
  if (N == 0) {
    if (A[0] == 1) {
      return 1;
    } else {
      return -1;
    }
  }

  maximum[0] = 1;
  for (int i = 1; i <= N; ++i) {
    if (maximum[i - 1] - A[i - 1] < 0) {
      return -1;
    }
    maximum[i] = min((maximum[i - 1] - A[i - 1]) * 2, 100000000000000000LL);
    DBG(i, maximum[i]);
  }

  if (A[0] > 0) {
    return -1;
  }

  if (maximum[N] < A[N]) {
    return -1;
  }

  ll nodes = A[N];
  ll ans = A[N];
  for (int i = N - 1; i >= 0; --i) {
    DBG(i, nodes, A[i], maximum[i]);
    if (nodes / 2 + nodes % 2 + A[i] > maximum[i]) {
      return -1;
    }
    nodes = min(nodes + A[i], maximum[i]);
    ans += nodes;
    DBG(nodes, ans);
  }
  return ans;
}

int main() {
  cin >> N;

  REP(i, N + 1) cin >> A[i];

  cout << solve() << endl;
}
