#include <bits/stdc++.h>

#include "atcoder.h"
#include "twosets.h"

void Main() {
  ints(n, m, k);
  V<int> a(n);
  cin >> a;
  TwoSets s;
  rep(i, m - 1) s.Add(a[i]);
  V<int> ans;
  rep(i, m - 1, n) {
    s.Add(a[i]);
    s.Adjust(k);
    ans.eb(s.LSum());
    s.Rem(a[i - (m - 1)]);
  }
  wt(ans);
}
