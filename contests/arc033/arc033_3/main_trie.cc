#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_trie.h"

void Main() {
  ints(q);
  BinaryTrie tr;
  rep(q) {
    ints(t, x);
    if (t == 1) {
      tr.Insert(x);
    } else {
      int y = tr.FindByOrder(x - 1);
      wt(y);
      tr.Erase(y);
    }
  }
}
