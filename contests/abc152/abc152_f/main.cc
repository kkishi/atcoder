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

struct Edge {
  int index;
  int dst;
};

ll use[20];

ll DFS(int curr, int dst, int prev, ll used, const vector<vector<Edge>>& edges) {
  if (curr == dst) {
    return used;
  }
  for (const Edge& e : edges[curr]) {
    if (e.dst == prev) continue;
    ll res = DFS(e.dst, dst, curr, used | (1LL << e.index), edges);
    if (res > 0) {
      return res;
    }
  }
  return 0;
}

int main() {
  CIN(int, N);
  vector<vector<Edge>> edges(N);
  REP(i, N - 1) {
    CIN(int, a, b);
    --a, --b;
    edges[a].push_back({i, b});
    edges[b].push_back({i, a});
  }
  CIN(int, M);
  REP(i, M) {
    CIN(int, u, v);
    --u, --v;
    use[i] = DFS(u, v, -1, 0, edges);
    DBG(use[i]);
  }
  ll ans = 1LL << (N - 1);
  for (int s = 1; s < (1 << M); ++s) {
    int cnt = 0;
    ll u = 0;
    for (int i = 0; i < M; ++i) {
      if (s & (1 << i)) {
        ++cnt;
        u |= use[i];
      }
    }
    ans -= (cnt % 2 ? 1 : -1) * (1LL << (N - 1 - bitset<64>(u).count()));
  }
  COUT(ans);
}
