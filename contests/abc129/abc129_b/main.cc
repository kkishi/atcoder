#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> w(n);
  rep(i, n) cin >> w[i];
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + w[i];
  int ans = 1000000;
  rep(i, n + 1) ans = min(ans, abs(s[n] - 2 * s[i]));
  wt(ans);
}
