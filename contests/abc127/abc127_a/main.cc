#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  if (a >= 13) {
    wt(b);
  } else if (a >= 6) {
    wt(b / 2);
  } else {
    wt(0);
  }
}
