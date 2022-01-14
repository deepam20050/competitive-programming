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

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << "? ";
  FOR(i, 1, 101) {
    cout << i << " ";
  }
  cout << endl;
  int y1;
  cin >> y1;
  cout << "? ";
  FOR(i, 1, 101) {
    cout << (i << 7) << " ";
  }
  cout << endl;
  int y2;
  cin >> y2;
  int x = 0;
  x |= (((1 << 7) - 1) << 7) & y1;
  x |= ((1 << 7) - 1) & y2;
  cout << "! " << x << endl;
  return 0;
}