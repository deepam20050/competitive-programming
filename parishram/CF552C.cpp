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

const int LN = 105;

int fin[LN], stock[LN];
int w, m;

int main () {
  scanf("%d %d", &w, &m);
  vector < int > nums;
  int x = m;
  while (x > 0) {
    nums.eb(x % w);
    x /= w;
  }
  FOR(i, 0, sz(nums)) {
    if (nums[i] == 0) {
      fin[i] = 0;
    } else if (nums[i] == w - 1) {
      --stock[i];
      ++nums[i + 1];
      fin[i] = 0;
    } else if (nums[i] == w) {
      fin[i] = 0;
      ++nums[i + 1];
    } else if (nums[i] == 1) {
      fin[i] = 1;
    } else {
      puts("NO");
      return 0;
    }
  }
  FOR(i, 0, LN) {
    if (fin[i]) {
      if (stock[i] == -1) {
        puts("NO");
        return 0;
      } 
    }
  }
  puts("YES");
  return 0;
}
