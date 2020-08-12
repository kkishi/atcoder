#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

struct S {
  int x, c;
};

int main() {
  rd(int, n, k);

  set<int> x;
  for (int i = 1; i * i <= n; ++i) {
    x.insert(i);
    x.insert(n / i);
  }
  map<int, int> c;
  for (auto it = x.begin(); it != x.end(); ++it) {
    auto jt = next(it);
    if (jt == x.end()) {
      assert(*it == n);
      c[*it] = 1;
    } else {
      c[*it] = n / *it - n / *jt;
    }
  }
  vector<S> v;
  for (auto [x, ci] : c) {
    v.push_back({x, ci});
  }

  vector dp(k + 1, vector(v.size(), mint(0)));
  rep(i, v.size()) dp[1][i] = v[i].c;
  for (int i = 2; i <= k; ++i) {
    for (int j = v.size() - 2; j >= 0; --j) {
      dp[i - 1][j] += dp[i - 1][j + 1];
    }
    rep(j, v.size()) dp[i][j] = dp[i - 1][v.size() - 1 - j] * v[j].c;
  }
  wt(accumulate(all(dp[k]), mint(0)));
}
