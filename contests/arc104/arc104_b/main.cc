#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  map<pair<int, int>, int> m;
  m[{0, 0}] = 1;
  int ans = 0;
  int a = 0, c = 0;
  rep(i, n) {
    if (s[i] == 'A') ++a;
    if (s[i] == 'T') --a;
    if (s[i] == 'C') ++c;
    if (s[i] == 'G') --c;
    ans += m[{a, c}];
    ++m[{a, c}];
  }
  wt(ans);
}
