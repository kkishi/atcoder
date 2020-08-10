#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  int c = 1;
  int ans = 0;
  while (c < b) {
    ++ans;
    c += a - 1;
  }
  wt(ans);
}
