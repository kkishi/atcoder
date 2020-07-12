#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

template <typename T>
T Gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

template <int Mod>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {}
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
  bool operator==(const ModInt& m) const { return n_ == m.n_; }
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

int N, K;

typedef vector<mint> res;

vector<int> Primes(int N) {
  vector<bool> is_prime(N + 1);
  REP(i, is_prime.size()) is_prime[i] = true;

  vector<int> v;
  for (int i = 2; i <= N; ++i) {
    if (!is_prime[i]) {
      continue;
    }
    v.push_back(i);
    for (int j = i + i; j <= N; j += i) {
      is_prime[j] = false;
    }
  }
  return v;
}

vector<int> Factorize(int N, const vector<int>& primes) {
  vector<int> v;
  int i = 0;
  while (N > 1) {
    if (N % primes[i] == 0) {
      v.push_back(primes[i]);
      N /= primes[i];
    } else {
      ++i;
    }
  }
  return v;
}

void Dfs(int depth, int N, const vector<int>& factors) {
  if (depth == factors.size()) {
    cout << N << endl;
    return;
  }
  Dfs(depth + 1, N, factors);
  Dfs(depth + 1, N * factors[depth], factors);
}

void Dfs2(int depth, int N, const vector<int>& factors, int ai, const res& a,
          const res& b, res& c) {
  if (depth == factors.size()) {
    if (N == ai) {
      return;
    }
    c[N] += a[ai] * b[N] + b[ai] * a[N];
    return;
  }
  Dfs2(depth + 1, N, factors, ai, a, b, c);
  Dfs2(depth + 1, N * factors[depth], factors, ai, a, b, c);
}

vector<int> primes;

res combine(const res& a, const res& b) {
  res c(K + 1);
  for (int ai = 1; ai <= K; ++ai) {
    Dfs2(0, 1, Factorize(ai, primes), ai, a, b, c);
    /*
    for (int bi = 1; bi < ai; ++bi) {
      int g = Gcd(ai, bi);
      c[g] += a[ai] * b[bi] + b[ai] * a[bi];
    }
    */
    c[ai] += a[ai] * b[ai];
  }

  /*
  res c(K + 1);
  for (int ai = 1; ai <= K; ++ai) {
    for (int bi = ai; bi <= K; bi += ai) {
      c[ai] += b[bi];
      if (bi > ai) {
        c[bi] += b[ai];
      }
    }
  }

  cout << K << endl;
  cout << "a:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << a[i] << endl;
  }
  cout << endl;
  cout << "b:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << b[i] << endl;
  }
  cout << endl;
  cout << "c:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << c[i] << endl;
  }
  cout << endl;
  */

  return c;
}

map<int, res> memo;

res dp(int n) {
  auto it = memo.find(n);
  if (it != memo.end()) {
    return it->second;
  }
  if (n == 1) {
    res r(K + 1);
    for (int i = 1; i <= K; ++i) {
      r[i] = 1;
    }
    return memo[n] = r;
  }
  if (n % 2 == 1) {
    return memo[n] = combine(dp(1), dp(n - 1));
  }
  res r = dp(n / 2);
  return memo[n] = combine(r, r);
}

int main() {
  /*
  vector<int> primes = Primes(100);
  REP(i, primes.size()) cout << primes[i] << endl;

  vector<int> f = Factorize(120, primes);
  REP(i, f.size()) cout << f[i] << endl;

  Dfs(0, 1, f);
  return 0;
  */
  primes = Primes(100000);
  cout << primes.size() << endl;
  return 0;

  cin >> N >> K;

  res r = dp(N);

  mint ans = 0;
  for (int i = 1; i <= K; ++i) {
    ans += r[i] * i;
  }
  cout << ans << endl;
}
