#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

template <int Mod>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {}
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ > Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt operator+(const ModInt& m) const {
    ModInt n(*this);
    n += m;
    return n;
  }
  ModInt& operator++() {
    (*this) += 1;
    return *this;
  }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt operator-(const ModInt& m) const {
    ModInt n(*this);
    n -= m;
    return n;
  }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt operator*(const ModInt& m) const {
    ModInt n(*this);
    n *= m;
    return n;
  }
  long long value() const { return n_; }

 private:
  long long n_;
};

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

using mint = ModInt<1000000007>;

template <typename T>
T Gcd(T a, T b) {
  if (a > b) {
    return Gcd(b, a);
  }
  T m = b % a;
  if (m == 0) {
    return a;
  }
  return Gcd(m, a);
}

template <typename N>
class Rational {
 public:
  Rational(N numerator, N denominator) {
    assert(denominator != 0);
    if (numerator == 0) {
      numerator_ = 0;
      denominator_ = 1;
      return;
    }
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
    N sign = 1;
    if (numerator < 0) {
      sign = -1;
      numerator = -numerator;
    }
    N gcd = Gcd(numerator, denominator);
    numerator_ = sign * (numerator / gcd);
    denominator_ = denominator / gcd;
  }
  N numerator() const { return numerator_; }
  N denominator() const { return denominator_; }

 private:
  N numerator_;
  N denominator_;
};

using ll = long long;

using Rat = Rational<ll>;

pair<ll, ll> ToPair(const Rat& r) { return {r.numerator(), r.denominator()}; }

map<pair<ll, ll>, int> s1;
map<pair<ll, ll>, int> s2;

mint two[200001];

int main() {
  two[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    two[i] = two[i - 1] * 2;
  }

  int N;
  cin >> N;

  mint zeros = 0;

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

    s1[ToPair(Rat(-B, A))]++;
    s2[ToPair(Rat(A, B))]++;
  }

  vector<pair<int, int>> groups;
  for (auto it : s2) {
    pair<int, int> p(it.second, s1[it.first]);
    if (p.second != 0 && it.first.first < 0) continue;

    groups.push_back(p);
  }
  groups.push_back({A_zeros, B_zeros});

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
  cout << (mul - 1 + zeros) << endl;
}
