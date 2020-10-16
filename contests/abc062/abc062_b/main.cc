#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  wt(string(w + 2, '#'));
  rep(i, h) wt('#' + a[i] + '#');
  wt(string(w + 2, '#'));
}
