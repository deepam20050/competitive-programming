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

int main () {
  pre();
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  return 0;
}
