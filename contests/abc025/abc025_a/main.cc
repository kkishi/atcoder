#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(n);
  --n;
  cout << s[n / 5] << s[n % 5] << endl;
}
