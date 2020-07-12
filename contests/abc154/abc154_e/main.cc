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

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
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
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int dp_eq[101][5];
int dp_lo[101][5];

int main() {
  CIN(string, N);
  CIN(int, K);
  dp_eq[0][0] = 1;
  REP(i, N.size()) {
    for (int z = 0; z <= 3; ++z) {
      int d = N[i] - '0';
      // Equal to d
      dp_eq[i + 1][z + (d != 0)] += dp_eq[i][z];
      dp_lo[i + 1][z + (d != 0)] += dp_lo[i][z];
      // Lower than d (zero)
      if (d > 0) dp_lo[i + 1][z] += dp_eq[i][z] + dp_lo[i][z];
      // Lower than d (non-zero)
      if (d > 1) dp_lo[i + 1][z + 1] += (dp_eq[i][z] + dp_lo[i][z]) * (d - 1);
      // Highe than d
      dp_lo[i + 1][z + 1] += dp_lo[i][z] * (9 - d);
    }
  }
  COUT(dp_eq[N.size()][K] + dp_lo[N.size()][K])
}
