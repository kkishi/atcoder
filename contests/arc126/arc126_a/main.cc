#include <bits/stdc++.h>

#include "atcoder.h"

void Solve() {
  ints(n2, n3, n4);
  n3 /= 2;
  int ans = 0;
  {
    int x = min(n3, n4);
    ans += x;
    n3 -= x;
    n4 -= x;
  }
  {
    int x = min(n3, n2 / 2);
    ans += x;
    n3 -= x;
    n2 -= x * 2;
  }
  {
    int x = min(n4 / 2, n2);
    ans += x;
    n4 -= x * 2;
    n2 -= x;
  }
  {
    int x = min(n4, n2 / 3);
    ans += x;
    n4 -= x;
    n2 -= x * 3;
  }
  ans += n2 / 5;
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
