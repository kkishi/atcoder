#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, s);
  V<int> v(n);
  rep(i, k) v[i] = s;
  rep(i, k, n) v[i] = s == 1 ? 2 : s - 1;
  rep(i, n) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
