#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> cond(m);
  cin >> cond;
  ints(k);
  V<pair<int, int>> cd(k);
  cin >> cd;
  int ans = -big;
  rep(s, 1 << k) {
    V<bool> ball(n + 1);
    rep(i, k) {
      if (hasbit(s, i)) {
        ball[cd[i].first] = true;
      } else {
        ball[cd[i].second] = true;
      }
    }
    int cnt = 0;
    each(a, b, cond) if (ball[a] && ball[b])++ cnt;
    chmax(ans, cnt);
  }
  wt(ans);
}
