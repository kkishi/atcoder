#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  bool flipped = false;
  deque<char> que(all(S));
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
    if ((F == 1) ^ flipped) {
      que.push_front(C);
    } else {
      que.push_back(C);
    }
  }
  string s(all(que));
  if (flipped) {
    reverse(all(s));
  }
  cout << s << endl;
}
