#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, x);
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  int ans = 1;
  int cx = 0;
  rep(i, n) {
    cx += l[i];
    if (cx <= x) ++ans;
  }
  wt(ans);
}
