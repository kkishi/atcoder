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

int main() {
  in(ll, d, g);
  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];
  ll ans = numeric_limits<ll>::max();
  for (int s = 0; s < (1 << d); ++s) {
    ll solved = 0;
    ll score = 0;
    rep(i, d) if ((s >> i) & 1) {
      solved += p[i];
      score += p[i] * 100 * (i + 1) + c[i];
    }
    for (int i = d - 1; i >= 0 && score < g; --i) {
      if ((s >> i) & 1) continue;
      ll score_per_problem = 100 * (i + 1);
      ll problems_to_solve = ((g - score) + score_per_problem - 1) / score_per_problem;
      ll solve = min(problems_to_solve, p[i]);
      solved += solve;
      score += score_per_problem * solve;
      if (solve == p[i]) score += c[i];
    }
    ans = min(ans, solved);
  }
  out(ans);
}