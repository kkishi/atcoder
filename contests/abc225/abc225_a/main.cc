#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  sort(all(s));
  int ans = 0;
  do {
    ++ans;
  } while (next_permutation(all(s)));
  wt(ans);
}
