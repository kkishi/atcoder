#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int ans = 0;
  each(e, s) each(e, e) if (e == '#')++ ans;
  wt(ans);
}
