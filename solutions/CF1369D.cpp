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

const int MOD = 1e9 + 7;
const int N = 2e6 + 5;

int claw[N];

int add (int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
  return x;
}

int main () {
  claw[1] = 0;
  claw[2] = 0;
  claw[3] = 4;
  claw[4] = 4;
  FOR(i, 5, N) {
    claw[i] = add(claw[i - 1], add(claw[i - 2], claw[i - 2]));
    claw[i] = add(claw[i], (i % 3 == 0) * 4);
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", claw[n]);
  }
  return 0;
}