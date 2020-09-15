#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  V<int> c = atcoder::convolution(a, b);
  rep(i, sz(c)) {
    if (i) cout << " ";
    cout << c[i];
  }
  cout << endl;
}
