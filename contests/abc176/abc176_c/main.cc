#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  V<int> a(n);
  cin >> a;
  int maxi = 0;
  int ans = 0;
  rep(i, n) {
    ans += max(0LL, maxi - a[i]);
    chmax(maxi, a[i]);
  }
  wt(ans);
}
