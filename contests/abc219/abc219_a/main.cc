#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  if (x < 40) {
    wt(40 - x);
  } else if (x < 70) {
    wt(70 - x);
  } else if (x < 90) {
    wt(90 - x);
  } else {
    wt("expert");
  }
}
