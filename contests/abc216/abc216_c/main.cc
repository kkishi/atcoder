#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string ans;
  rrep(i, 60) {
    ans += 'B';
    if (hasbit(n, i)) ans += 'A';
  }
  wt(ans);
}
