#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (b % a == 0) {
    return a;
  }
  return gcd(b % a, a);
}

struct Rat {
  ll sign, n, d;
  Rat(ll _n, ll _d) {
    if (_n == 0 || _d == 0) {
      sign = 0;
      n = 0;
      d = 0;
      return;
    }
    sign = 1;
    if (_n < 0) {
      sign = -sign;
      _n = -_n;
    }
    if (_d < 0) {
      sign = -sign;
      _d = -_d;
    }
    ll g = gcd(_n, _d);
    n = _n / g;
    d = _d / g;
  }
  bool operator<(const Rat& r) const {
    if (sign != r.sign) {
      return sign < r.sign;
    }
    if (n != r.n) {
      return n < r.n;
    }
    return d < r.d;
  }
};

map<Rat, int> s1;
map<Rat, int> s2;

Rat rev(const Rat& r) { return Rat(-r.d, r.n); }

bool eq(const Rat& a, const Rat& b) {
  return a.sign == b.sign && a.n == b.n && a.d == b.d;
}

ll two[200001];

void disp(const Rat& r) {
  cout << (r.sign < 0 ? "-" : "+") << r.n << "/" << r.d << endl;
}

int main() {
  const int kMod = 1000000007;

  two[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    two[i] = two[i - 1] * 2 % kMod;
  }

  int N;
  cin >> N;

  ll zeros = 0;

  ll A_zeros = 0;
  ll B_zeros = 0;

  REP(i, N) {
    ll A, B;
    cin >> A >> B;

    if (A == 0 && B == 0) {
      ++zeros;
      continue;
    }
    if (A == 0) {
      ++A_zeros;
      continue;
    }
    if (B == 0) {
      ++B_zeros;
      continue;
    }

    // cout << "A: " << A << " " << "B:"<< B << endl;

    // -B/A
    Rat r1(-B, A);
    // disp(r1);
    s1[r1]++;

    // A/B
    Rat r2(A, B);
    // disp(r2);
    s2[r2]++;
  }

  vector<pair<int, int>> groups;
  for (auto it : s2) {
    /*
    if (eq(it.first, rev(it.first))) {
      pair<int, int> p(it.second, 0);
      groups.push_back(make_pair(it.second, s1[it.first]));
      continue;
    }
    */

    pair<int, int> p(it.second, s1[it.first]);
    if (p.second != 0 && it.first.sign < 0) continue;

    groups.push_back(p);
    // disp(it.first);
    // cout << "group: " << groups.back().first << " ";
    // cout << groups.back().second << endl;
  }
  groups.push_back(make_pair(A_zeros, B_zeros));

  long long mul = 1;
  for (auto p : groups) {
    // cout << p.first << " " << p.second << endl;
    ll m;
    if (p.second == 0) {
      m = two[p.first];
    } else {
      m = (two[p.first] + two[p.second] - 1) % kMod;
    }
    // cout << m << endl;
    mul *= m;
    mul %= kMod;
  }
  ll ans = (mul - 1 + zeros) % kMod;
  cout << ans << endl;
}
