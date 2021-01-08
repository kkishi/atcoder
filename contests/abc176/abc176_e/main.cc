#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(H, W, m);
  VV<int> hw(H);
  V<int> hm(H), wm(W);
  rep(i, m) {
    ints(h, w);
    --h, --w;
    hw[h].pb(w);
    hm[h]++;
    wm[w]++;
  }
  multiset<int> vs;
  vs.insert(all(wm));

  int ans = 0;
  rep(i, H) {
    for (int hwi : hw[i]) {
      vs.erase(vs.find(wm[hwi]));
      vs.insert(wm[hwi] - 1);
    }

    auto p = prev(vs.end());
    chmax(ans, hm[i] + *p);

    for (int hwi : hw[i]) {
      vs.erase(vs.find(wm[hwi] - 1));
      vs.insert(wm[hwi]);
    }
  }
  wt(ans);
}
