#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int t = count(all(s), 'T');
  int a = count(all(s), 'A');
  if (t != a) {
    wt(t > a ? "T" : "A");
  } else {
    wt(s.back() == 'T' ? "A" : "T");
  }
}
