#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  each(e, s) {
    if (string("aeiou").find(e) == string::npos) cout << e;
  }
  cout << endl;
}
