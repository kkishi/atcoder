#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> ans = [&]() -> V<int> {
    V<int> s(n);
    cin >> s;
    if (n == 1) {
      return {s[0], 0, 0};
    }
    if (n == 2) {
      return {s[0], 0, 0, s[1]};
    }
    V<int> d(n - 1);
    rep(i, n - 1) d[i] = s[i + 1] - s[i];
    V<int> sd = d;
    rep(i, 3, n - 1) sd[i] = sd[i - 3] + d[i];
    vector x(3, big);
    rep(i, n - 1) chmin(x[i % 3], sd[i]);
    int tot = 0;
    each(e, x) if (e < 0) tot += -e;
    if (tot > s[0]) return {};
    V<int> ans(n + 2);
    rep(i, 3) if (x[i] < 0) ans[i] = -x[i];
    int y = s[0] - (ans[0] + ans[1] + ans[2]);
    if (y > 0) ans[0] += y;
    rep(i, 3, n + 2) ans[i] = ans[i - 3] + (s[i - 2] - s[i - 3]);
    return ans;
  }();
  if (ans.empty()) {
    wt(false);
  } else {
    wt(true);
    wt(ans);
  }
}
