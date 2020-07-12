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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
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
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

template <typename T>
std::map<T, int> Factorize(T x) {
  std::map<T, int> m;
  for (T i = 2; i * i <= x;) {
    if (x % i == 0) {
      m[i]++;
      x /= i;
    } else {
      ++i;
    }
  }
  if (x > 1) m[x]++;
  return m;
}

int main() {
  in(int, n);
  map<int, int> fs;
  for (int i = 2; i <= n; ++i) {
    for (auto [k, v] : Factorize(i)) fs[k] += v;
  }
  // 3 * 5 * 5
  // 15 * 5
  // 3 * 25
  // 75
  vector<int> cand = {3, 5, 15, 25, 75};
  map<int, int> m;
  for (auto [_, v] : fs) {
    for (int c : cand) {
      if (v >= c - 1) {
        m[c]++;
      }
    }
  }
  int ans = m[5] * (m[5] - 1) / 2 * (m[3] - 2) + m[15] * (m[5] - 1) +
            m[25] * (m[3] - 1) + m[75];
  out(ans);
}
