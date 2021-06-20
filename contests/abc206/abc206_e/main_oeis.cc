// Attempted to use A045763 to solve the problem.
// This solution is not correct. This gives the right answer when L <= 2, but is
// not necessarily correct when L > 3.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "sieve.h"

const int N = 1e6;
Sieve sieve(N + 1);

void Main() {
  V<int> divisor_sigma(N + 1);
  rep(i, 1, N + 1) {
    for (int j = i; j <= N; j += i) {
      ++divisor_sigma[j];
    }
  }
  rep(i, 1, 10) dbg(divisor_sigma[i]);

  V<int> euler_phi(N + 1);
  rep(i, 1, N + 1) {
    int p = i, q = 1;
    each(k, _, sieve.Factors(i)) {
      p *= k - 1;
      q *= k;
      int g = gcd(p, q);
      p /= g;
      q /= g;
    }
    assert(q == 1);
    euler_phi[i] = p;
  }

  auto A045763 = [&](int i) { return i + 1 - divisor_sigma[i] - euler_phi[i]; };
  rep(i, 1, 20) dbg(A045763(i));
  rep(i, 999900, 1000001) dbg((A045763(i)));

  V<int> v(N + 1);
  rep(i, 1, N + 1) v[i] = v[i - 1] + A045763(i);
  each(e, v) e *= 2;
  rep(i, 1, 20) dbg(v[i]);

  ints(l, r);
  wt(v[r] - v[l - 1]);
}
