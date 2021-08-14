#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  if (n <= 125) {
    wt(4);
  } else if (n <= 211) {
    wt(6);
  } else {
    wt(8);
  }
}
