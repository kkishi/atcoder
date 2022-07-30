#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(a, b);
  int ans = -big;
  rep(i, 3) {
    {
      string c = a;
      c[i] = '9';
      chmax(ans, stoi(c) - stoi(b));
    }
    {
      string c = b;
      c[i] = i == 0 ? '1' : '0';
      chmax(ans, stoi(a) - stoi(c));
    }
  }
  wt(ans);
}
