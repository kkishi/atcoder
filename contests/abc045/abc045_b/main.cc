#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  V<string> s(3);
  cin >> s;
  int i = 0;
  while (true) {
    if (s[i].empty()) {
      wt(char(i + 'A'));
      return 0;
    }
    char c = s[i][0];
    s[i] = s[i].substr(1);
    i = c - 'a';
  }
}
