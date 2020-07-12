#include <bits/stdc++.h>

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

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

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
  ModInt& operator%=(const ModInt& m) {
    // *this /= m;
    n_ %= m.n_;
    return *this;
  }
#define DEFINE_BINARY_OPERATOR(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op## = m; }
  DEFINE_BINARY_OPERATOR(+)
  DEFINE_BINARY_OPERATOR(-)
  DEFINE_BINARY_OPERATOR(*)
  DEFINE_BINARY_OPERATOR(/)
  DEFINE_BINARY_OPERATOR(%)
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
    return factorial_[n];
  }
  static ModInt combination(int n, int k) {
#if DEBUG
    assert(n <= 1000000 &&
           "n is too large. If k is small, consider using combination_slow.");
#endif
    return factorial(n) / factorial(n - k) / factorial(k);
  }
  static ModInt combination_slow(int n, int k) {
    ModInt numerator = 1;
    for (int i = 0; i < k; ++i) {
      numerator *= (n - i);
    }
    return numerator / factorial(k);
  }

 private:
  long long n_;
  static std::vector<ModInt> factorial_;
};

template <int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::factorial_;

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

using mint = ModInt<int(1e9+7)>;

int A[10000];

template <typename T>
std::map<T, int> Factorize(T x) {
  std::map<T, int> m;
  for (T i = 2; i * i <= x;) {
    if (x % i == 0) {
      m[i]++;
      x /= i;
    } else {
      ++i;
    }
  }
  if (x > 1) m[x]++;
  return m;
}

int main() {
  CIN(int, N);
  REP(i, N) cin >> A[i];
  map<int, int> m;
  REP(i, N) {
    map<int, int> fs = Factorize(A[i]);
    for (auto [k, v] : fs) {
      m[k] = max(m[k], v);
    }
  }
  mint lcm = 1;
  for (auto [k, v] : m) {
    REP(i, v) {
      lcm *= k;
    }
  }
  mint ans = 0;
  REP(i, N) {
    ans += lcm / mint(A[i]);
  }
  COUT(ans);
}
