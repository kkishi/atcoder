#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  cin >> h;
  int maxi = 0;
  int ans = 0;
  rep(i, n) {
    if (h[i] >= maxi) ++ans;
    chmax(maxi, h[i]);
  }
  wt(ans);
}
