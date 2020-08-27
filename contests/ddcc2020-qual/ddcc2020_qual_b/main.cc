#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  V<int> a(n);
  cin >> a;
  int tot = accumulate(all(a), 0LL);
  int sum = 0;
  int ans = numeric_limits<int>::max();
  rep(i, n) {
    sum += a[i];
    chmin(ans, abs(sum - (tot - sum)));
  }
  wt(ans);
}
