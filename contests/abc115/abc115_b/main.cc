#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  wt(accumulate(all(p), 0) - *max_element(all(p)) / 2);
}
