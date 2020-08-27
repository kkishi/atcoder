#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  int ans = 0, x = 1;
  while (x * 2 <= n) {
    x *= 2;
    ++ans;
  }
  wt(x);
}
