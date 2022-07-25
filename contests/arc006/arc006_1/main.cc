#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> e(6), l(6);
  int b;
  cin >> e >> b >> l;
  int same = 0;
  rep(i, 6) rep(j, 6) if (e[i] == l[j])++ same;
  int bonus = 0;
  rep(i, 6) if (l[i] == b) bonus = 1;
  if (same == 6) {
    wt(1);
  } else if (same == 5 && bonus) {
    wt(2);
  } else if (same == 5) {
    wt(3);
  } else if (same == 4) {
    wt(4);
  } else if (same == 3) {
    wt(5);
  } else {
    wt(0);
  }
}
