// AC
#include "bits/stdc++.h"
using namespace std;


#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int inf = 2e9;
const int N = 5005;

int arr[N];
int dp[N][N >> 1];
vector < int > pos;

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", arr + i);
    if (arr[i]) {
      pos.eb(i);
    }
  }
  int k = sz(pos);
  FOR(i, 0, N) FOR(j, 0, N >> 1) dp[i][j] = inf;
  dp[0][0] = 0;
  FOR(i, 0, n) FOR(j, 0, k + 1) {
    if (dp[i][j] == inf) continue;
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    if (j < k && arr[i] == 0) {
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(pos[j] - i));
    }
  }
  printf("%d\n", dp[n][k]);
  return 0;
}