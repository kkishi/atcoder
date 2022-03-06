#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(q);
  rep(q) {
    ints(t, k);
    --k;
    V<bool> v;
    while (t > 0 && k > 0) {
      v.pb(even(k));
      --t;
      k /= 2;
    }
    int c = s[k] - 'A';
    rep(i, sz(v)) c = (c + 1 + !v[i]) % 3;
    wt(char((c + t) % 3 + 'A'));
  }
}
