#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(2) {
    V<int> cnt(200001);
    rep(i, 1, n)++ cnt[a[i]];
    rep(i, n / 2) {
      // Count pairs that satisfy the following:
      // * The index of the left element is i.
      // * The values of the left and the right elements are different.
      // * The pair contributes i+1 times to the final answer.
      //
      // That is equal to the number of elements in [i + 1, n - i) whose value
      // is different from a[i].
      int all_cnt = n - 1 - i * 2;
      int same_cnt = cnt[a[i]];
      int diff_cnt = all_cnt - same_cnt;
      ans += diff_cnt * (i + 1);
      --cnt[a[i + 1]];
      --cnt[a[n - 1 - i]];
    }
    reverse(a);
  }
  // Adjust for double counting.
  rep(i, n / 2) if (a[i] != a[n - 1 - i]) ans -= i + 1;
  wt(ans);
}
