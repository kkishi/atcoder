#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(x, a, b);
  if (b <= a) {
    wt("delicious");
  } else if (b - a <= x) {
    wt("safe");
  } else {
    wt("dangerous");
  }
}
