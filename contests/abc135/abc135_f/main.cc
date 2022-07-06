#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash.h"

void Main() {
  strings(s, t);

  RollingHash rt;
  each(e, t) rt.PushBack(e);
  using u64 = uint64_t;
  u64 ht = rt.hash();

  string ss;
  while (sz(ss) - sz(s) < sz(t) - 1) ss += s;
  V<u64> hs;
  RollingHash rs;
  rep(i, sz(ss) - sz(s) - (sz(t) - 1), sz(ss) - sz(s)) rs.PushBack(ss[i]);
  rep(i, sz(ss) - sz(s), sz(ss)) {
    rs.PushBack(ss[i]);
    hs.eb(rs.hash());
    rs.PopFront();
  }
  int ans = 0;
  int g = gcd(sz(s), sz(t));
  rep(offset, g) {
    V<bool> v;
    int p = offset;
    do {
      v.eb(hs[p] == ht);
      p += sz(t);
      p %= sz(s);
    } while (p != offset);
    int ones = 0;
    rep(2) {
      rep(i, sz(v)) {
        if (v[i]) {
          ++ones;
        } else {
          ones = 0;
        }
        chmax(ans, ones);
      }
    }
    if (ans == sz(v) * 2) {
      wt(-1);
      return;
    }
  }
  wt(ans);
}
