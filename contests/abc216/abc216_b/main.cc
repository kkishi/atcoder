#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<string, string>> v(n);
  cin >> v;
  wt(sz(set(all(v))) < n);
}
