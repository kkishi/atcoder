#include <bits/stdc++.h>

#include "atcoder.h"

int g(int x) {
  switch (x) {
    case 2:
      return 2;
    case 4:
    case 6:
    case 9:
    case 11:
      return 1;
  }
  return 0;
}

void Main() {
  ints(x, y);
  wt(g(x) == g(y));
}
