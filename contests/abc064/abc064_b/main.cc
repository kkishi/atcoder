#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  wt(*max_element(all(a)) - *min_element(all(a)));
}
