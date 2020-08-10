#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  sort(all(p));
  wt(accumulate(p.begin(), p.begin() + k, 0));
}
