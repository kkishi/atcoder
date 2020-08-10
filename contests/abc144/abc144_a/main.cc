#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
    wt(a * b);
  } else {
    wt(-1);
  }
}
