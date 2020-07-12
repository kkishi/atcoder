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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
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
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

template <typename T>
std::vector<T> Compress(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
T Uncompress(const std::vector<T>& v, T x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
std::function<T(T)> Uncompressor(const std::vector<T>& v) {
  return [&v](T i) -> T { return Uncompress(v, i); };
}

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      if (begin <= cbegin && cend <= end) {
        return v_[index];
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(rec(cbegin, cmid, index * 2 + 1),
                        rec(cmid, cend, index * 2 + 2));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
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
  ModInt pow(int n) const {
    if (n < 0) {
      return inverse().pow(-n);
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

using mint = ModInt<998244353>;

struct Point {
  ll x, y, i;
  bool operator<(const Point& p) const {
    return x < p.x;
  }
};

int main() {
  in(ll, n);
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  vector<Point> p(n);
  rep(i, n) p[i] = {x[i], y[i], i};
  sort(all(p));

  vector<ll> cx = Compress(x), cy = Compress(y);
  vector<ll> upper_left(n), lower_left(n), upper_right(n), lower_right(n);
  {
    SegmentTree<ll> tree(n, [](ll a, ll b) { return a + b; });
    for (auto [x, y, i] : p) {
      ll yi = Uncompress(cy, y);
      upper_left[i] = tree.Aggregate(yi + 1, n);
      lower_left[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  reverse(all(p));
  {
    SegmentTree<ll> tree(n, [](ll a, ll b) { return a + b; });
    for (auto [x, y, i] : p) {
      ll yi = Uncompress(cy, y);
      upper_right[i] = tree.Aggregate(yi + 1, n);
      lower_right[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  mint ans = 0;
  for (auto [x, y, i] : p) {
    /*
    ll xi = Uncompress(cx, x);
    ll yi = Uncompress(cy, y);
    ans += mint(2).pow(xi) - 1;
    ans += mint(2).pow(n - xi) - 1;
    ans += mint(2).pow(yi) - 1;
    ans += mint(2).pow(n - yi) - 1;
    ans -= mint(2).pow(upper_left[i]) - 1;
    ans -= mint(2).pow(lower_left[i]) - 1;
    ans -= mint(2).pow(upper_right[i]) - 1;
    ans -= mint(2).pow(lower_right[i]) - 1;
    */
    dbg(x, y, i);
    dbg(upper_left[i], lower_right[i], lower_left[i], upper_right[i]);
    auto fun = [&](ll z) { return mint(2).pow(z) - 1; };
    ans += fun(upper_left[i]) * fun(lower_right[i]) * mint(2).pow(lower_left[i] + upper_right[i]) +
           fun(lower_left[i]) * fun(upper_right[i]) * mint(2).pow(upper_left[i] + lower_right[i]) -
           fun(upper_left[i]) * fun(lower_right[i]) * fun(lower_left[i]) * fun(upper_right[i]) +
           mint(2).pow(n - 1);
  }
  out(ans);
}
