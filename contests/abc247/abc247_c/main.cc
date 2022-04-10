#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string s = "1";
  rep(i, 2, n + 1) s = s + " " + to_string(i) + " " + s;
  wt(s);
}
