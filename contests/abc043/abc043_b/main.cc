#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  V<char> v;
  for (char c : s) {
    if (c == 'B') {
      if (!v.empty()) v.pop_back();
    } else {
      v.push_back(c);
    }
  }
  for (char c : v) cout << c;
  cout << endl;
}
