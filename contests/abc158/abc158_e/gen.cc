#include <bits/stdc++.h>

std::vector<bool> Sieve(int n) {
  std::vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (!v[i]) {
      continue;
    }
    for (int j = i * 2; j <= n; j += i) {
      v[j] = false;
    }
  }
  return v;
}

std::vector<int> Primes(int n) {
  std::vector<bool> sieve = Sieve(n);
  std::vector<int> v;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      v.push_back(i);
    }
  }
  return v;
}

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

template <typename T>
T read() {
  T x;
  std::cin >> x;
  return x;
}

using ll = long long;

using namespace std;

int main() {
  int N = 200000;
  cout << N << " " << Primes(10000).back() << endl;
  REP(i, 200000) cout << rand() % 10;
  cout << endl;
}
