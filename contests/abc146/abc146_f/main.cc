#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  strings(s);

  V<int> v;
  int i = n;
  while (true) {
    int ni = max(0, i - m);
    while (s[ni] == '1' && ni < i) ++ni;
    if (ni == i) {
      wt(-1);
      return;
    }
    v.pb(i - ni);
    i = ni;
    if (i == 0) {
      reverse(all(v));
      wt(v);
      return;
    }
  }
}
