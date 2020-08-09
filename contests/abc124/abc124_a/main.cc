#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  if (a > b) {
    wt(a * 2 - 1);
  } else if (a == b) {
    wt(a * 2);
  } else {
    wt(b * 2 - 1);
  }
}
