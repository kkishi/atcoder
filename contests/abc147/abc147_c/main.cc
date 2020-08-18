#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool check(int s, const vector<vector<pair<int, int>>>& v) {
  int n = v.size();
  rep(i, n) {
    if (!((s >> i) & 1)) continue;
    for (const auto& p : v[i]) {
      int j = p.first;
      bool honest = (s >> j) & 1;
      if (p.second == 1 != honest) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ints(n);
  vector<vector<pair<int, int>>> v(n);
  rep(i, n) {
    ints(a);
    rep(j, a) {
      ints(x, y);
      v[i].push_back({x - 1, y});
    }
  }
  int ans = 0;
  for (int s = 0; s < (1 << n); ++s) {
    if (check(s, v)) {
      chmax(ans, __builtin_popcount(s));
    }
  }
  wt(ans);
}
