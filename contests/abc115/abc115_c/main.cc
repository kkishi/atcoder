#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(all(h));
  int ans = h[n - 1] - h[0];
  rep(i, n) if (i + k - 1 < n) { ans = min(ans, h[i + k - 1] - h[i]); }
  wt(ans);
}
