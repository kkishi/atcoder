#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<string> s(n);
  cin >> s;
  V<set<char>> st;
  each(e, s) st.eb(set(all(e)));
  int ans = -big;
  rep(mask, 1 << n) {
    map<char, int> mp;
    rep(i, n) {
      if (hasbit(mask, i)) {
        each(e, st[i])++ mp[e];
      }
    }
    int cnt = 0;
    each(_, e, mp) if (e == k)++ cnt;
    chmax(ans, cnt);
  }
  wt(ans);
}
