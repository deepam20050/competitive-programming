// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 505;
const int inf = 1e9;

vector < int > school[N];
char str[N];
int mino[N];
int dp[2][N];

int main () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  FOR(i, 0, n) {
    scanf("%s", str + 1);
    FOR(j, 1, m + 1) {
      if (str[j] == '1') school[i].eb(j);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    int curr = i & 1;
    int nxt = curr ^ 1;
    memset(dp[curr], 0x3f, sizeof dp[curr]);
    memset(mino, 0x3f, sizeof mino);
    FOR(j, 0, sz(school[i])) {
      FOR(z, j, sz(school[i])) {
        mino[z - j + 1] = min(mino[z - j + 1], school[i][z] - school[i][j] + 1);
      }
    }
    mino[0] = 0;
    FOR(j, 0, k + 1) {
      FOR(z, 0, j + 1) {
        int rem = j - z;
        dp[curr][j] = min(dp[curr][j], dp[nxt][rem] + mino[sz(school[i]) - z]);
      }
    }
  }
  printf("%d\n", dp[0][k]);
  return 0;
}
