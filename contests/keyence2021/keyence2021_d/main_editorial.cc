#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  wt((1 << n) - 1);
  rep(i, 1, 1 << n) {
    rep(j, 1 << n) cout << (even(popcount(i & j)) ? 'A' : 'B');
    cout << endl;
  }
}
