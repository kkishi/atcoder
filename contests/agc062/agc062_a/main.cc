#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    strings(s);
    RunLengthQueue q;
    each(e, s) q.PushBack(e, 1);
    string t;
    each(e, q) t += (char)e.first;
    if (t == "B" || t == "AB") {
      wt("B");
    } else {
      wt("A");
    }
  }
}
