#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, x);
  int ans = 1;
  for (int b = 2; b * b <= x; ++b) {
    for (int c = b * b; c <= x; c *= b) {
      ans = max(ans, c);
    }
  }
  wt(ans);
}
