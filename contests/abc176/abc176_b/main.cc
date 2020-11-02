#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  int sum = 0;
  rep(i, n.size()) {
    sum += n[i] - '0';
    sum %= 9;
  }
  wt(sum == 0);
}
