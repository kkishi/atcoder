#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<int> v(6);
  each(c, s) v[c - 'A']++;
  wt(v);
}
