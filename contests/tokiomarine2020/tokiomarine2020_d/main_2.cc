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

const int kMaxCache = 1 << 11;
const int kMaxL = int(1e5);
int V[1 << 18];
int W[1 << 18];
int dp[kMaxCache][kMaxL + 1];

void Setmax(int& a, int b) { if (a < b) a = b; }
int Parent(int node) { return (node - 1) / 2; }

int main() {
  in(int, n);
  rep(i, n) cin >> V[i] >> W[i];

  for (int i = W[0]; i <= kMaxL; ++i) dp[0][i] = V[0];
  for (int node = 1; node < min(kMaxCache, n); ++node) {
    int parent = Parent(node);
    for (int i = 0; i <= kMaxL; ++i) dp[node][i] = dp[parent][i];
    for (int i = kMaxL; i - W[node] >= 0; --i) {
      Setmax(dp[node][i], dp[parent][i - W[node]] + V[node]);
    }
  }

  in(int, q);
  rep(i, q) {
    in(int, v, l);
    --v;

    if (v < kMaxCache) {
      out(dp[v][l]);
    } else {
      vector<int> vs, ws;
      while (v >= kMaxCache) {
        vs.push_back(V[v]);
        ws.push_back(W[v]);
        v = Parent(v);
      }
      int ans = 0;
      rep(i, 1 << vs.size()) {
        int v_sum = 0;
        int w_sum = 0;
        rep(j, vs.size()) if ((i >> j) & 1) {
          v_sum += vs[j];
          w_sum += ws[j];
        }
        if (w_sum <= l) {
          ans = max(ans, v_sum + dp[v][l - w_sum]);
        }
      }
      out(ans);
    }
  }
}
