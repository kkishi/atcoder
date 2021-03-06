#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> target(3);
  cin >> target;
  vector<int> l(n);
  cin >> l;
  vector<int> current(3);
  int ans = big;
  Fix([&](auto dfs, int depth, int used_mp) {
    if (depth == n) {
      rep(i, 3) {
        if (current[i] == 0) return;
        used_mp += abs(target[i] - current[i]);
      }
      chmin(ans, used_mp);
      return;
    }
    rep(i, 4) {
      int mp = 0;
      if (i < 3) {
        if (current[i] != 0) {
          mp += 10;
        }
        current[i] += l[depth];
      }
      dfs(depth + 1, used_mp + mp);
      if (i < 3) {
        current[i] -= l[depth];
      }
    }
  })(0, 0);
  wt(ans);
}
