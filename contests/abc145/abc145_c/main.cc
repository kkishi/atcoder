#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n);
  vector<Point> v(n);
  cin >> v;
  sort(v);
  double sum = 0;
  int cnt = 0;
  do {
    rep(i, n - 1) sum += (v[i + 1] - v[i]).Norm();
    ++cnt;
  } while (next_permutation(all(v)));
  wt(sum / cnt);
}
