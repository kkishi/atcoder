#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<double> v(n);
  cin >> v;
  sort(all(v));
  double ans = (v[0] + v[1]) / 2;
  rep(i, 2, n) ans = (ans + v[i]) / 2;
  cout << setprecision(20);
  wt(ans);
}
