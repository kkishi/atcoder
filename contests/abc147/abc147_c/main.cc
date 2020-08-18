#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

bool check(int s, const VV<pair<int, int>>& v) {
  rep(i, v.size()) {
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
  VV<pair<int, int>> v(n);
  rep(i, n) {
    ints(a);
    rep(j, a) {
      ints(x, y);
      v[i].push_back({x - 1, y});
    }
  }
  int ans = 0;
  rep(s, 1 << n) {
    if (check(s, v)) {
      chmax(ans, __builtin_popcount(s));
    }
  }
  wt(ans);
}
