#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<bool> done(n);
  rep(i, n) if (!done[i]) done[a[i] - 1] = true;
  V<int> ans;
  rep(i, n) if (!done[i]) ans.eb(i + 1);
  wt(sz(ans));
  wt(ans);
}
