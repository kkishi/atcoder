#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  strings(s, t);
  map<int, int> ms, mt;
  each(e, s)++ ms[e];
  each(e, t)++ mt[e];
  const string st = s + t;
  each(c, set(all(st))) {
    if (c == '@') continue;
    int d = ms[c] - mt[c];
    if (string("atcoder").find(c) == string::npos) {
      if (d != 0) return false;
    } else {
      if (d > 0) ms['@'] -= d;
      if (d < 0) ms['@'] -= d;
    }
  }
  return min(ms['@'], mt['@']) >= 0;
}
