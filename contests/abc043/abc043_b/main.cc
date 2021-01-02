#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<char> v;
  for (char c : s) {
    if (c == 'B') {
      if (!v.empty()) v.pop_back();
    } else {
      v.pb(c);
    }
  }
  for (char c : v) cout << c;
  cout << endl;
}
