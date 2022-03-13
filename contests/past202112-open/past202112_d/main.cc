#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<tuple<int, int, int>> v;
  rep(i, n) v.eb(a[i], b[i], i);
  sort(v, [](const auto& a, const auto& b) {
    auto [A, B, C] = a;
    auto [D, E, F] = b;
    if (A + B != D + E) return A + B > D + E;
    if (A != D) return A > D;
    return C < F;
  });
  V<int> ans;
  each(e, v) ans.eb(get<2>(e) + 1);
  wt(ans);
}
