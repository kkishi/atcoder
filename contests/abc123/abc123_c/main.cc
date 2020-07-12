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
  in(ll, n);
  vector<ll> transportation(5);
  rep(i, 5) cin >> transportation[i];
  vector<ll> population(6);
  population[0] = n;
  ll ans = 0;
  while (population[5] < n) {
    ++ans;
    vector<ll> change(6);
    rep(i, 5) {
      ll c = min(transportation[i], population[i]);
      change[i] -= c;
      change[i + 1] += c;
    }
    rep(i, 6) population[i] += change[i];
    rep(i, 6) cerr << change[i] << " ";
    cerr << endl;
    if (population[0] > 0) {
      bool fixed = true;
      // 0 a 1 b 2 c 3 d 4 e 5
      rep(i, 4) if (change[i + 1] != 0) fixed = false;
      if (fixed) {
        ll repeat = population[0] / -change[0];
        ans += repeat;
        population[0] += change[0] * repeat;
        population[5] += change[5] * repeat;
      }
    }
  }
  out(ans);
}
