#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  for (int a = 1; a <= 9; ++a) {
    if (n % a == 0) {
      int b = n / a;
      if (1 <= b && b <= 9) {
        wt("Yes");
        return 0;
      }
    }
  }
  wt("No");
}
