#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 5005;
const int MOD = 998244353;

int pref[N];
int pascal[N][N];
char s[N];
int n, k;

int add (int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

void pre () {
  pascal[0][0] = 1;
  FOR(i, 1, N) {
    pascal[i][0] = 1;
    FOR(j, 1, i + 1) {
      pascal[i][j] = add(pascal[i - 1][j - 1], pascal[i - 1][j]);
    }
  }
}

int nCk (int n, int k) {
  if (k < 0 || k > n) return 0;
  return pascal[n][k];
}

int main () {
  pre();
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  FOR(i, 1, n + 1) {
    pref[i] = pref[i - 1] + s[i] - '0';
  }
  int ans = 1;
  FOR(i, 1, n + 1) {
    FOR(j, i + 1, n + 1) {
      int cnt = j - i + 1;
      int ones = pref[j] - pref[i - 1];
      if (ones > k || pref[n] < k) continue;
      if (s[i] == '0') --ones;
      if (s[j] == '0') --ones;
      cnt -= 2;
      ans = add(ans, nCk(cnt, ones));
    }
  }
  printf("%d\n", ans);
  return 0;
}
