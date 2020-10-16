#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(3);
  cin >> s;
  int i = 0;
  while (true) {
    if (s[i].empty()) {
      wt(char(i + 'A'));
      return;
    }
    char c = s[i][0];
    s[i] = s[i].substr(1);
    i = c - 'a';
  }
}
