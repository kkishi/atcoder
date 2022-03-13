#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int n, int m, const V<int>& a) {
  int ans = 0;
  auto comb = [](int n, int k) {
    if (n < k) return 0L;
    int ret = 1;
    rep(i, k) ret *= n - i;
    rep(i, k) ret /= k - i;
    return ret;
  };
  V<int> init;
  Fix([&](auto rec, int depth, int rem, V<int>& xs) -> void {
    if (depth == n) {
      if (rem != 0) return;
      int p = 1;
      rep(i, sz(xs)) {
        int pi = comb(xs[i], a[i]);
        // cerr << xs[i] << "C" << a[i] << "=" << pi << " ";
        p *= pi;
      }
      // cout << endl;
      ans += p;
      return;
    }
    rep(i, a[depth], rem + 1) {
      xs.pb(i);
      rec(depth + 1, rem - i, xs);
      xs.pop_back();
    }
  })(0, m, init);
  return ans;
}

void Main() {
  /*
  ints(n, m);
  V<int> a(n);
  cin >> a;
  wt(Solve(n, m, a));
  */

  // 2, 2 -> C(n, 5)
  // 2, 2, 2 -> C(n, 8)
  // 2, 2, 2, 2 -> C(n, 11)
  // 3, 3 -> C(n, 7)
  // 3, 3, 3 -> C(n, 11)
  // 1, 2, 1 -> C(n, 6)
  V<int> a{1, 2, 1};
  int sum = accumulate(a);
  int n = sz(a);
  int acc = 0;
  rep(i, 10) {
    int ans = Solve(n, i + sum, a);
    acc += ans;
    wt(i + sum, ans, acc);
  }
}
