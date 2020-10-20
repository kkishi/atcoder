#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string t = "keyence";
  int i = 0;
  while (i < sz(t) && s[i] == t[i]) ++i;
  int j = 0;
  while (j < sz(t) && t[sz(t) - 1 - j] == s[sz(s) - 1 - j]) ++j;
  wt((i + j >= sz(t)) ? "YES" : "NO");
}
