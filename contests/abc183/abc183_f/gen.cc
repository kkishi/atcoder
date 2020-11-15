#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 2 * 100000;
  int q = 2 * 100000;
  wt(n, q);
  Random r;
  int maxc = 5;
  rep(i, n) cout << r.Int(1, maxc) << " ";
  cout << endl;
  rep(i, q) {
    int k = r.Int(1, 2);
    if (k == 1) {
      wt(k, r.Int(1, n), r.Int(1, n));
    } else {
      wt(k, r.Int(1, n), r.Int(1, maxc));
    }
  }
}
