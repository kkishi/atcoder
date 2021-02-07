#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  map<int, int> s;
  each(x, a) each(f, Divisors(x)) s[f] = gcd(s[f], x);

  int ans = 0;
  each(k, v, s) if (k <= a[0] && k == v)++ ans;
  wt(ans);
}
