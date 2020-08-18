#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(A, B);
  int ans = -1;
  rep(i, 1500) if (i * 2 / 25 == A && i / 10 == B) {
    ans = i;
    break;
  }
  wt(ans);
}
