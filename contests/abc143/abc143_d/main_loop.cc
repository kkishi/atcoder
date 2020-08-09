#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

short l[2000];

int main() {
  rd(int, n);
  rep(i, n) cin >> l[i];
  sort(l, l + n);

  int ans = 0;
  for (int a = 0; a < n - 2; ++a) {
    for (int b = a + 1; b < n - 1; ++b) {
      for (int c = b + 1; c < n; ++c) {
        if (l[c] >= l[a] + l[b]) {
          break;
        }
        ++ans;
      }
    }
  }
  wt(ans);
}
