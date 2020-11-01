#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> s;
  rep(n) {
    ints(a);
    s.insert(a);
  }
  wt(*prev(prev(s.end())));
}
