#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

int Solve(int p) {
  int ans = 0;
  map<int, int> m;
  rep(x, p) {
    bool ok = false;
    int z = x == 0 ? 0 : 1;
    set<int> st;
    while (true) {
      if (st.count(z)) break;
      st.insert(z);
      z *= x;
      z %= p;
    }
    dbg(p, x, sz(st));
    ans += sz(st);
    ++m[sz(st)];
  }
  dbg(p, m);
  return ans;
}

void Main() {
  ints(p);
  // wt(Solve(p));
  // return;
  V<int> ps = Primes(200);
  V<int> v;
  each(e, ps) {
    int f = Solve(e);
    dbg(e, f);
    v.pb(f);
  }
  dbg(v);
}
