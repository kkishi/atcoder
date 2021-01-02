#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  V<string> sub;
  rep(i, s.size()) rep(j, 5) if (i + j < s.size()) {
    sub.pb(s.substr(i, j + 1));
  }
  sort(all(sub));
  unique(all(sub));
  wt(sub[k - 1]);
}
