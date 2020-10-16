#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> s;
  rep(n) {
    ints(a);
    if (!s.insert(a).second) s.erase(a);
  }
  wt(s.size());
}
