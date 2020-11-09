#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(day);
  V<string> v = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                 "Thursday", "Friday", "Saturday"};
  rep(i, sz(v)) if (day == v[i]) wt((6 - i) % 6);
}
