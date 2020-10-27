#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"

void Main() {
  ints(n, d, k);
  V<int> l(d), r(d);
  rep(i, d) cin >> l[i] >> r[i];
  V<int> s(k), t(k);
  rep(i, k) cin >> s[i] >> t[i];

  V<int> c;
  rep(i, d) {
    c.push_back(l[i]);
    c.push_back(r[i]);
  }
  rep(i, k) {
    c.push_back(s[i]);
    c.push_back(t[i]);
  }
  c = Compress(c);

  V<int> ans;
  rep(i, k) {
    int si = Uncompress(c, s[i]);
    int ti = Uncompress(c, t[i]);
    V<bool> v(sz(c));
    v[si] = true;
    rep(i, d) {
      int li = Uncompress(c, l[i]);
      int ri = Uncompress(c, r[i]);
      bool found = false;
      for (int j = li; j <= ri; ++j) {
        if (v[j]) found = true;
      }
      if (found) {
        for (int j = li; j <= ri; ++j) {
          v[j] = true;
        }
      }
      if (v[ti]) {
        ans.push_back(i + 1);
        break;
      }
    }
  }
  rep(i, k) wt(ans[i]);
}
