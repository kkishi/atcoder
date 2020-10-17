#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(n);
  vector<Vec> v(n);
  cin >> v;
  sort(all(v));
  double sum = 0;
  int cnt = 0;
  do {
    rep(i, n - 1) sum += (v[i + 1] - v[i]).Norm();
    ++cnt;
  } while (next_permutation(all(v)));
  wt(sum / cnt);
}
