#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  string r = s;
  reverse(all(r));
  if (sz(s) & 1) {
    int i = sz(s) / 2;
    char c = s[i];
    while (i + 1 < sz(s) && s[i + 1] == c && r[i + 1] == c) ++i;
    wt(i + 1);
  } else {
    int i = sz(s) / 2;
    char c = s[i];
    if (c != s[i - 1]) {
      wt(sz(s) / 2);
    } else {
      while (i + 1 < sz(s) && s[i + 1] == c && r[i + 1] == c) ++i;
      wt(i + 1);
    }
  }
}
