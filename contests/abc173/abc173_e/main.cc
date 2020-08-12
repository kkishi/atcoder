#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> p;
  vector<ll> z;
  vector<ll> m;
  rep(i, n) {
    rd(ll, a);
    if (a == 0) {
      z.push_back(0);
    } else if (a > 0) {
      p.push_back(a);
    } else {
      m.push_back(-a);
    }
  }
  bool can_make_positive = false;
  for (int mc = 0; mc <= min<int>(m.size(), k); ++mc) {
    if (p.size() >= (k - mc) && mc % 2 == 0) {
      can_make_positive = true;
    }
  }
  // answer has to be minus or zero
  if (!can_make_positive) {
    // if (k > p.size() && (k - p.size()) % 2 == 1) {
    // can be zero?
    if (!z.empty()) {
      dbg("can be zero");
      wt(0);
    } else {
      dbg("has to be minus");
      mint ans = 1;
      rep(i, p.size()) ans *= p[i];
      sort(all(m));
      rep(i, k - p.size()) ans *= m[i];
      wt(-ans);
    }
  } else {
    // answer has to be zero?
    if (!z.empty() && k > (p.size() + m.size())) {
      dbg("has to be zero");
      wt(0);
    } else {
      mint ans = 1;
      ll pi = 0;
      ll mi = 0;
      sort(all(p), greater());
      sort(all(m), greater());
      while (pi + mi < k) {
        int rk = k - (pi + mi);
        if (rk == 1) {
          assert(pi < p.size());
          ans *= p[pi];
          wt(ans);
          return 0;
        }
        if (pi + 1 >= p.size()) {
          assert(mi + 1 < m.size());
          ans *= m[mi] * m[mi + 1];
          mi += 2;
        } else if (mi + 1 >= m.size()) {
          assert(pi + 1 < p.size());
          ans *= p[pi] * p[pi + 1];
          pi += 2;
        } else {
          ll px = p[pi] * p[pi + 1];
          ll mx = m[mi] * m[mi + 1];
          if (px > mx) {  // ?
            ans *= p[pi] * p[pi + 1];
            pi += 2;
          } else {
            ans *= m[mi] * m[mi + 1];
            mi += 2;
          }
        }
      }
      wt(ans);
    }
  }
}
