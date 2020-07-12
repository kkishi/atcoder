#include <bits/stdc++.h>

template <typename T, T Op(T, T), T Unit = T()>
class SegmentTree {
 public:
  SegmentTree(int size) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, Unit);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = Op(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    return aggregate(begin, end, 0, (v_.size() + 1) / 2, 0);
  }

 private:
  T aggregate(int begin, int end, int cbegin, int cend, int index) const {
    if (begin <= cbegin && cend <= end) {
      return v_[index];
    }
    if (cend <= begin || end <= cbegin) {
      return Unit;
    }
    int cmid = (cbegin + cend) / 2;
    return Op(aggregate(begin, end, cbegin, cmid, index * 2 + 1),
              aggregate(begin, end, cmid, cend, index * 2 + 2));
  }
  std::vector<T> v_;
};

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
#define DEFINE_BINARY_OPERATOR(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op##= m; }
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
    assert(n <= 1000000 && "n is too large. If k is small, consider using combination_slow.");
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

template<int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::factorial_;

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
#define DBG(...)                \
  cerr << #__VA_ARGS__ << ": "; \
  debug(__VA_ARGS__);           \
  cerr << " (L" << __LINE__ << ")" << endl
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using mint = ModInt<998244353>;

using namespace std;

struct Robot {
  int X, D;
  int Destination() const {
    return X + D;
  }
  bool operator<(const Robot& r) const {
    return X < r.X;
  }
};

Robot robot[200000];
mint dp[200001];

int Max(int a, int b) { return max(a, b); }

int main() {
  int N;
  cin >> N;

  REP(i, N) cin >> robot[i].X >> robot[i].D;
  sort(robot, robot + N);

  SegmentTree<int, Max> tree(N);
  REP(i, N) tree.Set(i, i);

  dp[N] = 1;
  for (int i = N - 1; i >= 0; --i) {
    Robot r = {robot[i].Destination(), 0};
    int n = lower_bound(robot, robot + N, r) - robot;
    int m = tree.Aggregate(i, n);
    tree.Set(i, m);

    dp[i] = dp[i + 1] + dp[m + 1];
  }
  cout << dp[0] << endl;
}
