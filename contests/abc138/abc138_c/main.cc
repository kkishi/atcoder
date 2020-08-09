#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<double> v(n);
  rep(i, n) cin >> v[i];
  sort(all(v));
  double ans = (v[0] + v[1]) / 2;
  for (int i = 2; i < n; ++i) {
    ans = (ans + v[i]) / 2;
  }
  cout << setprecision(20);
  wt(ans);
}
