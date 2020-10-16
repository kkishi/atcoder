#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, x);
  int maxi = min(1000000, x + (k - 1));
  int mini = max(-1000000, x - (k - 1));
  for (int i = mini; i <= maxi; ++i) {
    cout << i << " ";
  }
  cout << endl;
}
