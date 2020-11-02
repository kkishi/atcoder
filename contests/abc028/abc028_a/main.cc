#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  if (n <= 59)
    wt("Bad");
  else if (n <= 89)
    wt("Good");
  else if (n <= 99)
    wt("Great");
  else
    wt("Perfect");
}
