#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  int all = 0;
  rep(i, n) all ^= a[i];
  rep(i, n) {
    if (i) cout << " ";
    cout << (all ^ a[i]);
  }
  cout << endl;
}
