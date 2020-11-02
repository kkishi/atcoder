#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(K);
  int sum = 0;
  rep(a, K) rep(b, K) rep(c, K) sum += gcd(a + 1, gcd(b + 1, c + 1));
  wt(sum);
}
