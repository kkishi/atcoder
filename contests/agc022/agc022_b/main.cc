#include <bits/stdc++.h>

#include "atcoder.h"

V<int> Solve(int n) {
  if (n == 3) return {2, 5, 63};

  V<int> ans;
  rep(i, n / 8) {
    V<int> v{2, 3, 4, 6, 8, 9, 10, 12};
    for (int vi : v) ans.push_back(i * 12 + vi);
  }

  int rem = n % 8;
  V<int> v;
  if (rem == 1) v = {6};
  if (rem == 2) v = {2, 4};
  if (rem == 3) v = {2, 4, 6};
  if (rem == 4) v = {2, 3, 4, 9};
  if (rem == 5) v = {2, 3, 4, 6, 9};
  if (rem == 6) v = {2, 3, 4, 8, 9, 10};
  if (rem == 7) v = {2, 3, 4, 6, 8, 9, 10};
  for (int vi : v) ans.push_back(n / 8 * 12 + vi);

  return ans;
}

void Main() {
  ints(n);

  V<int> ans = Solve(n);

#ifdef DEBUG
  auto check = [](int n, const V<int>& ans) {
    assert(sz(ans) == n);
    int sum = accumulate(all(ans), int(0));
    rep(i, n) assert(gcd(ans[i], sum - ans[i]) != 1);
    int g = ans[0];
    rep(i, 1, n) g = gcd(g, ans[i]);
    assert(g == 1);
    rep(i, n) assert(ans[i] <= 30000);
    set<int> s(all(ans));
    assert(s.size() == n);
  };
  check(n, ans);
#endif

  rep(i, n) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
