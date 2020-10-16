#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

int n, m;
int a[100000];
int s[100001];

pair<int, int> count(int x) {
  int cnt = 0;
  int sum = 0;
  rep(i, n) {
    int lb = lower_bound(a, a + n, x - a[i]) - a;
    cnt += n - lb;
    sum += s[lb] + (n - lb) * a[i];
  }
  return {cnt, sum};
}

void Main() {
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  rrep(i, n) s[i] = s[i + 1] + a[i];

  int x = BinarySearch<int>(0, a[n - 1] * 2 + 1,
                            [&](int x) { return count(x).first >= m; });
  auto p = count(x);
  wt(p.second - (p.first - m) * x);
}
