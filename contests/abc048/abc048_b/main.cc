#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(a, b, x);
  int ans = b / x;
  if (a == 0) {
    ++ans;
  } else {
    ans -= (a - 1) / x;
  }
  wt(ans);
}
