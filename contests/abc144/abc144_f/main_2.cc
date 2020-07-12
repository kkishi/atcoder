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

struct DP {
  double edges;
  double prob;
  double Exp() const {
    return edges / prob;
  }
};

void Add(DP& a, const DP& b) {
  a.edges += b.edges + b.prob;
  a.prob += b.prob;
}

void Sub(DP& a, const DP& b) {
  Add(a, {-b.edges, -b.prob});
}

bool MaybeUpdate(DP& a, const DP& b) {
  if (a.prob == 0 || a.Exp() > b.Exp()) {
    a = b;
    return true;
  }
  return false;
}

// 0: before
// 1: after
DP dp[2][600];

int main() {
  in(int, n, m);
  vector<vector<int>> to(n);
  vector<vector<int>> from(n);
  rep(i, m) {
    in(int, s, t);
    --s, --t;
    to[s].push_back(t);
    from[t].push_back(s);
  }
  dp[0][0].edges = 0;
  dp[0][0].prob = 1;
  for (int i = 1; i < n; ++i) {
    for (int s : from[i]) {
      Add(dp[0][i], dp[0][s]);
    }
    for (int s : from[i]) {
      if (dp[1][s].prob > 0) {
        DP d = dp[0][i];
        Sub(d, dp[0][s]);
        Add(d, dp[1][s]);
        if (MaybeUpdate(dp[1][i], d)) {
          dbg(i + 1, dp[1][i].edges, dp[1][i].prob);
        }
      }
    }
    rep(j, 2) {
      dbg(i + 1, j, dp[j][i].edges, dp[j][i].prob);
    }
    if (from[i].size() > 1) {
      for (int s : from[i]) {
        DP d = dp[0][i];
        Sub(d, dp[0][s]);
        if (MaybeUpdate(dp[1][i], d)) {
          dbg(i + 1, dp[1][i].edges, dp[1][i].prob);
        }
      }
    }
    if (i < n - 1) {
      rep(j, 2) {
        dp[j][i].prob /= to[i].size();
      }
    }
    dbg(i + 1, dp[1][i].edges, dp[1][i].prob);
  }
  cout << setprecision(20);
  if (dp[1][n - 1].prob > 0) {
    out(dp[1][n - 1].Exp());
  } else {
    out(dp[0][n - 1].Exp());
  }
}
