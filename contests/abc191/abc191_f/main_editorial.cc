#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  map<int, int> s;
  each(x, a) {
    set<int> fs;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        fs.insert(i);
        fs.insert(x / i);
      }
    }
    each(f, fs) s[f] = gcd(s[f], x);
  }
  int ans = 0;
  each(k, v, s) if (k <= a[0] && k == v)++ ans;
  wt(ans);
}
