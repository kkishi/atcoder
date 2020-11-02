#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int N, R;
  cin >> N >> R;

  if (N < 10) R += 100 * (10 - N);
  cout << R << endl;
}
