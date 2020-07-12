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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const {
    return X < m.X;
  }
};

Monster monster[200000];

ll Add(ll a, ll b) { return a + b; }

int main() {
  CIN(ll, N, D, A);
  REP(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  ll ans = 0;
  queue<pair<ll, ll>> que;
  ll damage_sum = 0;
  REP(i, N) {
    while (!que.empty() && que.front().first < monster[i].X) {
      damage_sum -= que.front().second;
      que.pop();
    }
    ll remaining = monster[i].H - damage_sum;
    if (remaining > 0) {
      ll cnt = (remaining + A - 1) / A;
      ans += cnt;
      damage_sum += cnt * A;
      que.push({monster[i].X + 2 * D, cnt * A});
    }
  }
  COUT(ans);
}
