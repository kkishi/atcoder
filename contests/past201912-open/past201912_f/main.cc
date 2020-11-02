#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<string> v;
  int i = 0;
  while (i < sz(s)) {
    int j = i + 1;
    while (!isupper(s[j])) ++j;
    string t = s.substr(i, j - i + 1);
    rep(k, sz(t)) t[k] = tolower(t[k]);
    v.push_back(t);
    i = j + 1;
  }
  sort(all(v));
  for (string& s : v) {
    s[0] = toupper(s[0]);
    s[sz(s) - 1] = toupper(s[sz(s) - 1]);
    cout << s;
  }
  cout << endl;
}
