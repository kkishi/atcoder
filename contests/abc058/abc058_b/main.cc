#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(o, e);
  string ans{o + e};
  rep(i, sz(o)) ans[i * 2] = o[i];
  rep(i, sz(e)) ans[i * 2 + 1] = e[i];
  wt(ans);
}
