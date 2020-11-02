#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  for (int i = 0; i < sz(s);) {
    int j = i;
    while (j < sz(s) && s[j] == s[i]) ++j;
    cout << s[i] << (j - i);
    i = j;
  }
  cout << endl;
}
