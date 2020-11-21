#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rep(s, 1 << 4) {
    map<string, char> c;
    rep(i, 4) {
      string key;
      key += 'A' + (i & 1);
      key += 'A' + ((i >> 1) & 1);
      c[key] = 'A' + ((s >> i) & 1);
    }
    cout << "if ("
         << "aa == '" << c["AA"] << "' &&"
         << "ab == '" << c["AB"] << "' &&"
         << "ba == '" << c["BA"] << "' &&"
         << "bb == '" << c["BB"] << "') " << endl;
    dbg(c);
    set<string> st = {"AB"};
    rep(i, 10) {
      set<string> nst;
      for (const string& s : st) {
        rep(i, sz(s) - 1) {
          string t = s.substr(0, i + 1) + c[s.substr(i, 2)] + s.substr(i + 1);
          nst.insert(t);
        }
      }
      swap(st, nst);
      dbg(i, sz(st));
    }
  }
}
