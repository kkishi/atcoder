#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  rd(int, n, k);
  int ans = 0;
  for (int b = k + 1; b <= n; ++b)
    for (int a = k; a <= n; a += b)
      ans += max(0ll, min(b - k, n - a + 1) - ll(a == 0 ? 1 : 0));
  wt(ans);
}
