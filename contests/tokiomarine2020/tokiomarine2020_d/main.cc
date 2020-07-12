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

const int kMax = int(1e5);
int n;
int v[1 << 18];
int w[1 << 18];
// int dp[20][kMax + 1];
int q;
int ans[kMax];
int num_qs[1 << 18];
int max_ls[1 << 18];

struct Query {
  int v;
  int l;
  int index;
};

map<int, vector<Query>> queries;

void setmax(int& a, int b) {
  if (a < b) a = b;
}

void dfs(int depth, int node, const map<int, int>& dp) {
  dbg(depth, node);
  if (node >= n) {
    return;
  }
  if (num_qs[node] == 0) {
    return;
  }
  map<int, int> ndp(dp);
  for (const auto p : dp) {
    setmax(ndp[p.first + w[node]], p.second + v[node]);
  }

  for (const Query& query : queries[node]) {
    // ans[query.index] = dp[depth + 1][query.l];
    for (int i = query.l; i >= 0; --i) {
      if (ndp[i] > 0) {
        ans[query.index] = ndp[i];
        break;
      }
    }
    // ans[query.index] = ndp[query.l];
  }
  dfs(depth + 1, node * 2 + 1, ndp);
  dfs(depth + 1, node * 2 + 2, ndp);
}

int main() {
  cin >> n;
  rep(i, n) scanf("%d %d", &v[i], &w[i]);

  cin >> q;
  rep(i, q) {
    int v, l;
    scanf("%d %d", &v, &l);
    --v;

    queries[v].push_back({v, l, i});

    while (v) {
      ++num_qs[v];
      setmax(max_ls[v], l);
      v = (v - 1) / 2;
    }
    ++num_qs[0];
    setmax(max_ls[0], l);
  }
  dfs(1, 0, {{0, 0}});
  rep(i, q) printf("%d\n", ans[i]);
}
