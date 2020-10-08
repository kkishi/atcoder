#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(w);
  for (int i = 0; i < sz(s); i += w) {
    cout << s[i];
  }
  cout << endl;
}
