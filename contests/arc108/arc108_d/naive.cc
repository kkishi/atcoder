#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  rd(char, aa, ab, ba, bb);
  map<string, char> c{{"AA", aa}, {"AB", ab}, {"BA", ba}, {"BB", bb}};
  set<string> st = {"AB"};
  rep(n - 2) {
    set<string> nst;
    for (const string& s : st) {
      rep(i, sz(s) - 1) {
        string t = s.substr(0, i + 1) + c[s.substr(i, 2)] + s.substr(i + 1);
        nst.insert(t);
      }
    }
    swap(st, nst);
  }
  wt(sz(st));
}
