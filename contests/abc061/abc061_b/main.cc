#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<int> ans(n);
  rep(m) {
    ints(a, b);
    ++ans[a - 1];
    ++ans[b - 1];
  }
  rep(i, n) wt(ans[i]);
}
