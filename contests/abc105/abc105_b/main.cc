#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  for (int i = 0; i * 4 <= n; ++i) {
    if ((n - i * 4) % 7 == 0) {
      wt("Yes");
      return 0;
    }
  }
  wt("No");
}
