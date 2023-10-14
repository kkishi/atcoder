#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n);
  strings(t);
  V<string> s(n);
  cin >> s;
  V<int> pre, suf;
  each(e, s) {
    int idx = 0;
    each(e, e) if (idx < sz(t) && t[idx] == e)++ idx;
    pre.eb(idx);
    int ridx = 0;
    rrep(i, sz(e)) {
      int j = sz(t) - 1 - ridx;
      if (j >= 0 && e[i] == t[j]) ++ridx;
    }
    suf.eb(ridx);
  }
  sort(suf);
  int ans = 0;
  rep(i, n) ans += CountGE(suf, sz(t) - pre[i]);
  wt(ans);
}
