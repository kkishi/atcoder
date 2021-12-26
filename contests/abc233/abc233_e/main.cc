#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(x);
  each(e, x) e -= '0';
  int n = sz(x);
  int s = 0;
  each(e, x) s += e;
  string ans;
  int carry = 0;
  rep(i, n) {
    carry += s;
    s -= x[n - 1 - i];
    int y = carry % 10;
    carry /= 10;
    ans.pb((char)('0' + y));
  }
  while (carry) {
    int y = carry % 10;
    carry /= 10;
    ans.pb((char)('0' + y));
  }
  reverse(all(ans));
  wt(ans);
}
