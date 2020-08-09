#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  int ans = 0;
  function<void(string, bool, bool, bool)> rec = [&](string s, bool three,
                                                     bool five, bool seven) {
    if (s.size() >= 10) return;
    if (three && five && seven && stoll(s) <= n) ++ans;
    rec(s + '3', true, five, seven);
    rec(s + '5', three, true, seven);
    rec(s + '7', three, five, true);
  };
  rec("", false, false, false);
  wt(ans);
}
