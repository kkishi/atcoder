#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  V<int> v(n);
  cin >> v;

  sort(all(v), greater());
  int sum = accumulate(v.begin(), v.begin() + a, 0LL);

  wt(sum / double(a));

  map<int, int> cnt;
  for (int vi : v) ++cnt[vi];

  auto comb = [](int n, int k) {
    chmin(k, n - k);
    int p = 1, q = 1;
    rep(i, k) {
      p *= n - i;
      q *= k - i;
      int g = gcd(p, q);
      p /= g;
      q /= g;
    }
    assert(q == 1);
    return p;
  };

  int ans = 0;
  rep(i, a - 1, b) {
    int nsum = 0;
    rep(j, a, i + 1) nsum += v[j];
    if (sum * (i - (a - 1)) != nsum * a) continue;
    int last = v[i];
    int used = 0;
    rep(j, i + 1) if (v[j] == last)++ used;

    ans += comb(cnt[last], used);
  }
  wt(ans);
}
