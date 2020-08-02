#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

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
using bigint = boost::multiprecision::cpp_int;

using namespace std;

int N;
bigint A[100000];
ll kMax = 1000000000000000000;

int main() {
  cin >> N;
  REP(i, N) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  bigint ans = 1;
  REP(i, N) {
    ans *= A[i];
    if (ans > kMax) {
      cout << -1 << endl;
      return 0;
    }
  }
  COUT(ans);
}