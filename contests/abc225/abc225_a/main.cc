#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  sort(s);
  int ans = 0;
  do {
    ++ans;
  } while (next_permutation(all(s)));
  wt(ans);
}
