#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  bool flipped = false;
  string head, tail;
  rep(q, Q) {
    int T;
    cin >> T;
    if (T == 1) {
      flipped = !flipped;
      continue;
    }
    int F;
    char C;
    cin >> F >> C;
    (((F == 1) ^ flipped) ? head : tail) += C;
    dbg(head, tail);
  }
  reverse(all(head));
  string s = head + S + tail;
  if (flipped) {
    reverse(all(s));
  }
  cout << s << endl;
}
