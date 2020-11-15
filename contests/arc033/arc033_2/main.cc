#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(na, nb);
  V<int> a(na), b(nb);
  cin >> a >> b;
  set<int> sa(all(a));
  int both = 0;
  for (int bi : b) both += sa.count(bi);
  wt((double)both / (na + nb - both));
}
