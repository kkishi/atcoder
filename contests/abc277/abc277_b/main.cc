#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    ints(n);
    V<string> s(n);
    cin >> s;
    set<char> st1{'H', 'D', 'C', 'S'};
    set<char> st2{'A', '2', '3', '4', '5', '6', '7',
                  '8', '9', 'T', 'J', 'Q', 'K'};
    each(e, s) {
      if (!st1.count(e[0])) return false;
      if (!st2.count(e[1])) return false;
    }
    set<string> st3(all(s));
    return sz(st3) == n;
  }());
}
