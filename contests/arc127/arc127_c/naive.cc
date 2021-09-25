#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(x);
  vector<string> v;
  rep(i, 1, 1 << n) {
    string s;
    int I = i;
    while (I) {
      s += (char)('0' + I % 2);
      I /= 2;
    }
    reverse(all(s));
    v.eb(s);
  }
  sort(all(v));
  rep(i, sz(v)) {
    string s;
    int I = i;
    while (I) {
      s += (char)('0' + I % 2);
      I /= 2;
    }
    reverse(all(s));
  }
  int X = 0;
  rep(i, sz(x)) { X = X * 2 + (x[i] - '0'); }
  wt(v[X - 1]);
}
