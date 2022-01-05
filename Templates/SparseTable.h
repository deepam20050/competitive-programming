/* Credits: https://codeforces.com/contest/1548/submission/124526158
 * Usage: SparseTable < lli > st(vec, [&](lli i, ll j) { return __gcd(i, j); });
 * Indexing is from 0 (NOT from 1)
 */
template < typename T, class F = function < T (const T&, const T&) >>
struct SparseTable {
  int n;
  vector < vector < T > > mat;
  F foo;

  SparseTable (const vector < T > &a, const F &f) : func (f) {
    n = sz(a);
    int max_log = __lg(n);
    mat[0] = a;
    FOR(j, 1, max_log) {
      mat[j].resize(n - (1 << j) + 1);
      FOR(i, 0, n - (1 << j) + 1) {
        mat[j][i] = foo(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query (int l, int r) const {
    int lg = __lg(r - l + 1);
    return foo(mat[lg][l], mat[lg][r - (1 << lg) + 1]);
  }
};
