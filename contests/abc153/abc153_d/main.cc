#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll dfs(ll x) {
  if (x == 1) {
    return 1;
  }
  return 1 + 2 * dfs(x / 2);
}

int main() {
  rd(ll, H);
  wt(dfs(H));
}
