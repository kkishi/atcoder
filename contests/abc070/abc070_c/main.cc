#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  V<int> t(n);
  cin >> t;
  int l = 1;
  rep(i, n) l = lcm(l, t[i]);
  wt(l);
}
