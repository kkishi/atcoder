#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n);
  n *= 2;

  int ans = big;
  each(x, Divisors(n)) {
    int y = n / x;
    V<long long> r = {0, -1}, m = {x, y};
    if (long long f = atcoder::crt(r, m).first; f != 0) {
      chmin(ans, f);
    }
  }
  wt(ans);
}
