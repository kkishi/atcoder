#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  int ans = 1;
  for (int b = 2; b * b <= x; ++b) {
    for (int c = b * b; c <= x; c *= b) {
      chmax(ans, c);
    }
  }
  wt(ans);
}
