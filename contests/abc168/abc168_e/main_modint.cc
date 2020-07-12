#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

template <int Mod>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {
    if (n_ < 0) {
      // In C++, (-n)%m == -(n%m).
      n_ += Mod;
    }
  }
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt& operator/=(const ModInt& m) {
    *this *= m.Inv();
    return *this;
  }
#define DEFINE_BINARY_OPERATOR(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op## = m; }
  DEFINE_BINARY_OPERATOR(+)
  DEFINE_BINARY_OPERATOR(-)
  DEFINE_BINARY_OPERATOR(*)
  DEFINE_BINARY_OPERATOR(/)
#undef DEFINE_BINARY_OPERATOR
#define DEFINE_COMPARISON_OPERATOR(op) \
  bool operator op(const ModInt& m) const { return n_ op m.n_; }
  DEFINE_COMPARISON_OPERATOR(!=)
  DEFINE_COMPARISON_OPERATOR(<)
  DEFINE_COMPARISON_OPERATOR(<=)
  DEFINE_COMPARISON_OPERATOR(==)
  DEFINE_COMPARISON_OPERATOR(>)
  DEFINE_COMPARISON_OPERATOR(>=)
#undef BDEFINE_COMPARISON_OPERATOR
  ModInt operator-() const { return ModInt(-n_); }
  ModInt Pow(int n) const {
    if (n < 0) {
      return Inv().Pow(-n);
    }
    // a * b ^ n = answer.
    ModInt a = 1, b = *this;
    while (n != 0) {
      if (n & 1) {
        a *= b;
      }
      n /= 2;
      b *= b;
    }
    return a;
  }
  ModInt Inv() const {
    // Compute the inverse based on Fermat's little theorem. Note that this only
    // works when n_ and Mod are relatively prime. The theorem says that
    // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
    return Pow(Mod - 2);
  }
  long long value() const { return n_; }

  static ModInt Fact(int n) {
    for (int i = fact_.size(); i <= n; ++i) {
      fact_.push_back(i == 0 ? 1 : fact_.back() * i);
    }
    return fact_[n];
  }
  static ModInt Comb(int n, int k) { return Perm(n, k) / Fact(k); }
  static ModInt CombSlow(int n, int k) { return PermSlow(n, k) / Fact(k); }
  static ModInt Perm(int n, int k) {
#if DEBUG
    assert(n <= 1000000 &&
           "n is too large. If k is small, consider using PermSlow.");
#endif
    return Fact(n) / Fact(n - k);
  }
  static ModInt PermSlow(int n, int k) {
    ModInt p = 1;
    for (int i = 0; i < k; ++i) {
      p *= (n - i);
    }
    return p;
  }

 private:
  long long n_;
  static std::vector<ModInt> fact_;
};

template <int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::fact_;

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

using mint = ModInt<1000000007>;

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

mint two[200001];

void disp(const Rat& r) {
  cout << (r.sign < 0 ? "-" : "+") << r.n << "/" << r.d << endl;
}

int main() {
  two[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    two[i] = two[i - 1] * 2;
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

  mint mul = 1;
  for (auto p : groups) {
    // cout << p.first << " " << p.second << endl;
    mint m;
    if (p.second == 0) {
      m = two[p.first];
    } else {
      m = two[p.first] + two[p.second] - 1;
    }
    // cout << m << endl;
    mul *= m;
  }
  mint ans = (mul - 1 + zeros);
  cout << ans.value() << endl;
}
