#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(5);
  cin >> v;
  V<int> ans;
  rep(i, 3) rep(j, i + 1, 4) rep(k, j + 1, 5) ans.pb(v[i] + v[j] + v[k]);
  sort(ans, greater{});
  wt(ans[2]);
}
