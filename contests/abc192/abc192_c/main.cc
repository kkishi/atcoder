#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int a = n;
  rep(k) {
    string s = to_string(a);
    sort(all(s), greater{});
    int g1 = stoll(s);
    sort(s);
    int g2 = stoll(s);
    a = g1 - g2;
  }
  wt(a);
}
