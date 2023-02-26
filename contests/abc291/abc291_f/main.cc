#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;
  V<int> front(n, big);
  front[0] = 0;
  rep(i, n) rep(j, m) {
    int ni = i + j + 1;
    if (ni < n && s[i][j] == '1') {
      chmin(front[ni], front[i] + 1);
    }
  }
  V<int> back(n, big);
  back[n - 1] = 0;
  rrep(i, n) rep(j, m) {
    int ni = i + j + 1;
    if (ni < n && s[i][j] == '1') {
      chmin(back[i], back[ni] + 1);
    }
  }
  V<int> ans;
  rep(i, 1, n - 1) {
    int mi = big;
    rep(j, 1, m) {
      int I = i - j;
      if (I < 0) continue;
      rep(k, m) {
        int J = I + (k + 1);
        if (J >= n) continue;
        if (J <= i) continue;
        if (s[I][k] == '1') {
          chmin(mi, front[I] + back[J] + 1);
        }
      }
    }
    if (mi == big) mi = -1;
    ans.eb(mi);
  }
  wt(ans);
}
