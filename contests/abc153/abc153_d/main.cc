#include <bits/stdc++.h>

#include "atcoder.h"

int dfs(int x) {
  if (x == 1) {
    return 1;
  }
  return 1 + 2 * dfs(x / 2);
}

void Main() {
  ints(H);
  wt(dfs(H));
}
