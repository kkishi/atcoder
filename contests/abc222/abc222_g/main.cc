#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

// https://ei1333.github.io/luzhiled/snippets/math/mod-log.html
int64_t mod_log(int64_t a, int64_t b, int64_t p) {
  int64_t g = 1;

  for (int64_t i = p; i; i /= 2) (g *= a) %= p;
  g = __gcd(g, p);

  int64_t t = 1, c = 0;
  for (; t % g; c++) {
    if (t == b) return c;
    (t *= a) %= p;
  }
  if (b % g) return -1;

  t /= g;
  b /= g;

  int64_t n = p / g, h = 0, gs = 1;

  for (; h * h < n; h++) (gs *= a) %= n;

  unordered_map<int64_t, int64_t> bs;
  for (int64_t s = 0, e = b; s < h; bs[e] = ++s) {
    (e *= a) %= n;
  }

  for (int64_t s = 0, e = t; s < n;) {
    (e *= gs) %= n;
    s += h;
    if (bs.count(e)) return c + s - bs[e];
  }
  return -1;
}

void Main() {
  ints(t);
  rep(t) {
    ints(k);
    if (even(k)) {
      k /= 2;
    }
    if (k == 1) {
      wt(1);
      continue;
    }
    // If k is divisible by 2 or 5, the answer is -1. We handle these cases
    // explicitly because we want to use inv_mod(10, k) below.
    if (gcd(10, k) != 1) {
      wt(-1);
      continue;
    }
    k *= 9;
    // We want mod_log(10, 1, k) but want to skip 0 (note that 10^0 = 1). So
    // instead we calculate mod_log(10, 10^(-1), k).
    wt(mod_log(10, atcoder::inv_mod(10, k), k) + 1);
  }
}
