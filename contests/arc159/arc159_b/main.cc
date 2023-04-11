#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(a, b);
  if (a > b) swap(a, b);
  int ans = 0;
  while (a >= 1 && b >= 1) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
    int d = b - a;
    if (d == 0) {
      ++ans;
      break;
    }
    if (d == 1) {
      ans += a;
      break;
    }
    int rem = big;
    each(e, Divisors(d)) if (e != 1) chmin(rem, a % e);
    ans += rem;
    a -= rem;
    b -= rem;
  }
  wt(ans);
}
