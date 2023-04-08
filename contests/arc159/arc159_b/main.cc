#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a > b) swap(a, b);
  int ans = 0;
  while (a >= 1 && b >= 1) {
    int g = gcd(a, b);
    int na = a / g;
    int nb = b / g;
    int d = nb - na;
    if (d == 0) {
      ++ans;
      break;
    }
    if (d == 1) {
      ans += na;
      break;
    }
    int rem = na % d;
    for (int i = 2; i * i <= d; ++i) {
      if (d % i == 0) {
        chmin(rem, na % i);
        chmin(rem, na % (d / i));
      }
    }
    ans += rem;
    a -= g * rem;
    b -= g * rem;
  }
  wt(ans);
}
