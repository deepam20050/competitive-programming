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

const int N = 1e6 + 5;

int arr[N];
vector < int > pos[N];
int n;

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    pos[arr[i]].eb(i);
  }
  lli sum = 0;
  FOR(i, 1, N) {
    if (pos[i].empty()) continue;
    int m = sz(pos[i]);
    FOR(j, 0, m) {
      int frnt = j + 1 >= m ? n + 1 : pos[i][j + 1]; 
      int c1 = pos[i][j];
      int c2 = frnt - pos[i][j];
      sum += c1 * 2ll * c2;
      sum -= 1;
    }
  }
  printf("%.6lf\n", 1.0 * sum / (n * 1ll * n));
  return 0;
}
