#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(w);
  for (char c : w)
    if (!set{'a', 'i', 'u', 'e', 'o'}.count(c)) cout << c;
  cout << endl;
}
