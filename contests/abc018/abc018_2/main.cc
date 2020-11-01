#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(n);
  rep(n) {
    ints(l, r);
    reverse(s.begin() + l - 1, s.begin() + r);
  }
  wt(s);
}
