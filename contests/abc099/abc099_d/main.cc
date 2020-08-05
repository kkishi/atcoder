#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
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
  std::cout << value << '\n';
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

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, N, C);
  vector D(C, vector(C, 0));
  rep(i, C) rep(j, C) cin >> D[i][j];
  vector c(N, vector(N, 0));
  rep(i, N) rep(j, N) cin >> c[i][j];

  VV<pair<int, int>> cost(3);
  rep(i, 3) {
    V<int> cs;
    rep(j, N) rep(k, N) if (((j + 1) + (k + 1)) % 3 == i) {
      cs.push_back(c[j][k]);
    }
    rep(j, C) {
      ll sum = 0;
      for (int csi : cs) sum += D[csi - 1][j];
      cost[i].push_back({sum, j});
    }
    sort(all(cost[i]));
  }
  ll ans = numeric_limits<ll>::max();
  V<int> idx = {0, 1, 2};
  do {
    set<int> used;
    ll sum = 0;
    rep(i, 3) {
      for (auto& p : cost[idx[i]]) {
        if (used.insert(p.second).second) {
          sum += p.first;
          break;
        }
      }
    }
    ans = min(ans, sum);
  } while (next_permutation(all(idx)));
  out(ans);
}
