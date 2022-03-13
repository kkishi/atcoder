#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> m(n);
  cin >> m;
  wt((x - accumulate(m)) / *min_element(all(m)) + n);
}
