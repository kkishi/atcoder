#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  map<int, int> m;
  m[x] = 1;
  rep(n) {
    ints(l);
    map<int, int> nm;
    rep(l) {
      ints(a);
      each(k, v, m) if (k % a == 0) nm[k / a] += v;
    }
    swap(m, nm);
  }
  wt(m[1]);
}
