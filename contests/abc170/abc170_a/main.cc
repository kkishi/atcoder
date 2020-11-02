#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int v[5];
  rep(i, 5) cin >> v[i];
  wt(15 - accumulate(v, v + 5, 0));
}
