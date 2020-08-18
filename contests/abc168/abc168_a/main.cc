#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N);
  switch (N % 10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      wt("hon");
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      wt("pon");
      break;
    default:
      wt("bon");
      break;
  }
}
