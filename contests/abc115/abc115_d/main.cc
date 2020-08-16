#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

/*
struct B {
  ll p, b;
};

B Burger(int n) {

struct Result {
  ll p, b;
};

ll rec(int n, ll x) {

}
*/

int main() {
  rd(ll, n, x);
  vector<ll> p(n + 1);
  vector<ll> b(n + 1);
  p[0] = 1;
  rep(i, n) {
    p[i + 1] = p[i] * 2 + 1;
    b[i + 1] = b[i] * 2 + 2;
  }
  wt(Fix([&p, &b](auto rec, ll n, ll x) {
    if (n == 0) return 1LL;
    if (x <= 1) return 0LL;
    --x;
    ll pb = p[n - 1] + b[n - 1];
    if (x <= pb) {
      return rec(n - 1, x);
    }
    x -= pb;
    ll ps = p[n - 1];
    if (x <= 1) {
      return x + ps;
    }
    --x;
    ++ps;
    if (x <= pb) {
      return ps + rec(n - 1, x);
    }
    return ps + p[n - 1];
  })(n, x));
}
