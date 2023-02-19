#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sumsum = 0;
  map<int, int> sum;
  int sumcnt = 0;
  map<int, int> cnt;
  int ans = 0;
  rep(i, n) {
    int l = i;
    int r = n - i;
    if (l > r) {
      int j = r;
      auto pop = [&](int idx) {
        sum[a[idx]] -= idx + 1;
        sumsum -= idx + 1;
        cnt[a[idx]]++;
        ++sumcnt;
      };
      pop(j);
      int k = i - 1;
      if (j < k) {
        pop(k);
      }
    }
    ans += sumsum - sum[a[i]];
    ans += (sumcnt - cnt[a[i]]) * r;

    sum[a[i]] += i + 1;
    sumsum += i + 1;
  }
  wt(ans);
}
