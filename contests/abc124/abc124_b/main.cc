#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int maxi = 0;
  int ans = 0;
  rep(i, n) {
    if (h[i] >= maxi) ++ans;
    maxi = max(maxi, h[i]);
  }
  wt(ans);
}
