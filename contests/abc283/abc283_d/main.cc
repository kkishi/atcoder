#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    strings(s);
    set<char> seen;
    V<char> stk;
    each(e, s) {
      if (e == ')') {
        while (true) {
          char b = stk.back();
          stk.pop_back();
          if (b == '(') {
            break;
          } else {
            seen.erase(b);
          }
        }
      } else {
        stk.pb(e);
        if (e != '(') {
          if (seen.count(e)) return false;
          seen.insert(e);
        }
      }
    }
    return true;
  }());
}
