#include <bits/stdc++.h>

#include "atcoder.h"

int C(int n, int m) {
  int p = 1, q = 1;
  rep(i, m) {
    p *= n - i;
    q *= m - i;
    int g = gcd(p, q);
    p /= g;
    q /= g;
  }
  assert(q == 1);
  return p;
}

void Main() {
  ints(a, b, k);
  string ans;

  int x = a + b;
  rep(i, x) {
    if (a == 0) {
      assert(k == 1);
      ans += 'b';
      --b;
      continue;
    }
    int c = C(a - 1 + b, a - 1);
    if (c >= k) {
      ans += 'a';
      --a;
    } else {
      ans += 'b';
      k -= c;
      --b;
    }
  }
  wt(ans);
}
