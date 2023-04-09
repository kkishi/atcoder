#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  strings(s);
  map<char, V<int>> p;
  rep(i, 8) p[s[i]].eb(i);
  if (even(p['B'][0]) == even(p['B'][1])) return false;
  if (!(p['R'][0] < p['K'][0] && p['K'][0] < p['R'][1])) return false;
  return true;
}
