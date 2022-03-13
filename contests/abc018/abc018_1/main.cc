#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(3);
  cin >> v;
  V<int> sv = v;
  sort(sv, greater{});
  rep(i, 3) rep(j, 3) if (v[i] == sv[j]) wt(j + 1);
}
