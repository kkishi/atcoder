#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  map<char, int> m;
  each(e, s)++ m[e];
  wt(m['R'] == k ? 'W' : 'R');
}
