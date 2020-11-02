#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> m(n);
  cin >> m;
  wt((x - accumulate(all(m), 0)) / *min_element(all(m)) + n);
}
