#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string rs(s.rbegin(), s.rend());
  wt(sz(s) - rs.find('Z') - s.find('A'));
}
