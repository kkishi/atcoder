#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  n %= 30;
  V<int> ord(6);
  iota(all(ord), 0);
  rep(i, n) swap(ord[i % 5], ord[i % 5 + 1]);
  rep(i, 6) cout << ord[i] + 1;
  cout << endl;
}
