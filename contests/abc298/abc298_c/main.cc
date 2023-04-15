#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<multiset<int>> v(n);
  map<int, set<int>> mp;
  rep(q) {
    ints(tp);
    if (tp == 1) {
      ints(i, j);
      --i, --j;
      v[j].insert(i);
      mp[i].insert(j);
    } else if (tp == 2) {
      ints(i);
      V<int> ans;
      each(e, v[i - 1]) ans.eb(e + 1);
      wt(ans);
    } else {
      ints(i);
      V<int> ans;
      each(e, mp[i - 1]) ans.eb(e + 1);
      wt(ans);
    }
  }
}
