#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n - 2) {
    if (s.substr(i, 3) == "ABC") {
      wt(i + 1);
      return;
    }
  }
  wt(-1);
}
