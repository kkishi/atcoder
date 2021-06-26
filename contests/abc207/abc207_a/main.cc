#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(3);
  cin >> v;
  wt(accumulate(all(v), int(0)) - *min_element(all(v)));
}
