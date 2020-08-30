#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, k);
  V<pair<int, int>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(all(v));
  int cnt = 0;
  rep(i, n) {
    cnt += v[i].second;
    if (cnt >= k) {
      wt(v[i].first);
      return 0;
    }
  }
}
