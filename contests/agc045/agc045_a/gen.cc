#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int t = 10;
  wt(t);
  Random r;
  rep(t) {
    int n = 20;
    wt(n);
    rep(i, n) wt(r.Int(1, 10));
    rep(i, n) cout << r.Int(0, 1);
    cout << endl;
  }
}
