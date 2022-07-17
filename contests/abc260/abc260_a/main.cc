#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  map<char, int> mp;
  each(e, s)++ mp[e];
  each(k, v, mp) if (v == 1) {
    wt(k);
    return;
  }
  wt(-1);
}
