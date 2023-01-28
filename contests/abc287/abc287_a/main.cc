#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int cnt = 0;
  rep(n) {
    strings(s);
    if (s == "For") ++cnt;
  }
  wt(cnt > n / 2);
}
