#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  ints(k);
  strings(s);
  int maxc = max(s) - 'a';
  int ans = big;
  Fix([&](auto rec, string t) {
    if ((sz(t) << k) > sz(s)) return;
    {
      string rt = t;
      reverse(rt);
      if (t.empty() || rt != t) {
        // dbg(t);
        V<char> v;
        Fix([&](auto rec, int depth) {
          if (depth == k) {
            string x = t;
            each(e, v) {
              string nx = x;
              if (e != ' ') nx += e;
              reverse(x);
              nx += x;
              x = nx;
            }
            if (sz(x) == sz(s)) {
              // dbg(v, x);
              int cost = 0;
              rep(i, sz(x)) cost += x[i] != s[i];
              chmin(ans, cost);
            }
            return;
          }
          int ini = -1;
          if (t.empty() && depth == 0) ini = 0;
          rep(i, ini, maxc + 1) {
            v.pb(i == -1 ? ' ' : (char)('a' + i));
            rec(depth + 1);
            v.pop_back();
          }
        })(0);
      }
    }
    rep(i, maxc + 1) rec(t + (char)('a' + i));
  })("");
  if (ans == big) {
    wt("impossible");
  } else {
    wt(ans);
  }
}
