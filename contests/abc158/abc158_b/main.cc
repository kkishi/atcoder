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
#define DBG(...)                \
  cerr << #__VA_ARGS__ << ": "; \
  debug(__VA_ARGS__);           \
  cerr << " (L" << __LINE__ << ")" << endl
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  cout << N / (A + B) * A + min(N % (A + B), A) << endl;
}
