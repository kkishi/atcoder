#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

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

int main() {
  ints(x, y);
  wt(g(x) == g(y));
}
