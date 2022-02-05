#include <bits/stdc++.h>

#include "atcoder.h"
#include "mo.h"
#include "sieve.h"

const int N = 1000000;
Sieve s(N);
VV<pair<int, int>> fs(200000);
int8_t v[N];

struct DS {
  int nonzero = 0;
  void Update(int a, int b) {
    if (a != 0 && b == 0) --nonzero;
    if (a == 0 && b != 0) ++nonzero;
  }
  void Add(int i) {
    each(f, n, fs[i]) {
      int vf = v[f];
      v[f] += n;
      v[f] %= 3;
      Update(vf, v[f]);
    }
  }
  void Del(int i) {
    each(f, n, fs[i]) {
      int vf = v[f];
      v[f] += 3 - n;
      v[f] %= 3;
      Update(vf, v[f]);
    }
  }
  bool Get() const { return nonzero == 0; }
};

void Main() {
  ints(n, q);
  rep(i, n) {
    ints(a);
    each(k, v, s.Factors(a)) {
      if (v % 3) fs[i].eb(k, v % 3);
    }
  }
  DS ds;
  Mo<bool, DS> mo(ds);
  rep(q) {
    ints(l, r);
    mo.AddQuery(l - 1, r);
  }
  each(e, mo.ProcessQueries()) wt(e == 1);
}
