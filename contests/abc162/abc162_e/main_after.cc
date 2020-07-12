#include <bits/stdc++.h>

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
    *this *= m.inverse();
    return *this;
  }
  ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
  ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
  ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
  ModInt operator/(const ModInt& m) const { return ModInt(*this) /= m; }
#define DEFINE_BINARY_OPERATOR(op) \
  bool operator op(const ModInt& m) const { return n_ op m.n_; }
  DEFINE_BINARY_OPERATOR(!=);
  DEFINE_BINARY_OPERATOR(<);
  DEFINE_BINARY_OPERATOR(<=);
  DEFINE_BINARY_OPERATOR(==);
  DEFINE_BINARY_OPERATOR(>);
#undef BOP
  ModInt pow(int n) const {
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
  ModInt inverse() const {
    // Compute the inverse based on Fermat's little theorem. Note that this only
    // works when n_ and Mod are relatively prime. The theorem says that
    // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
    return pow(Mod - 2);
  }
  long long value() const { return n_; }

  static ModInt factorial(int n) {
    for (int i = factorial_.size(); i <= n; ++i) {
      factorial_.push_back(i == 0 ? 1 : factorial_.back() * i);
    }
    return ModInt<Mod>::factorial_[n];
  }
  static ModInt combination(int n, int k) {
    return factorial(n) / factorial(n - k) / factorial(k);
  }

 private:
  long long n_;
  static std::vector<ModInt> factorial_;
};

template <int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::factorial_ = std::vector<ModInt<Mod>>();

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

using mint = ModInt<1000000007>;
mint gcds[100001];

int main() {
  int N, K;
  cin >> N >> K;

  mint ans = 0;
  for (int i = K; i >= 1; --i) {
    gcds[i] = mint(K / i).pow(N);
    for (int j = i * 2; j <= K; j += i) {
      gcds[i] -= gcds[j];
    }
    ans += gcds[i] * i;
  }
  cout << ans << endl;
}
