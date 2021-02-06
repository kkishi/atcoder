#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  wt(atcoder::convolution(a, b));
}
