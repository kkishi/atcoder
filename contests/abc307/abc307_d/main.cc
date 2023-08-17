#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<char> v;
  string ans;
  each(c, s) {
    if (c == '(') {
      v.eb(c);
      ans += c;
    } else if (c == ')') {
      if (sz(v) > 0 && v.back() == '(') {
        v.pop_back();
        while (ans.back() != '(') ans.pop_back();
        ans.pop_back();
      } else {
        v.eb(c);
        ans += c;
      }
    } else {
      ans += c;
    }
  }
  wt(ans);
}
