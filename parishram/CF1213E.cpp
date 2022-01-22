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

string s, t;
int n;

bool check (const string &test) {
  return test.find(s) == string::npos && test.find(t) == string::npos;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> s >> t;
  string p = "abc";
  do {
    string test1 = "";
    FOR(i, 0, n) test1 += p;
    string test2 = string(n, p[0]) + string(n, p[1]) + string(n, p[2]);
    if (check(test1)) {
      cout << "YES\n" << test1 << '\n';
      return 0;
    } 
    if (check(test2)) {
     cout << "YES\n" << test2 << '\n';
     return 0;
    }
  } while (next_permutation(all(p)));
  cout << "NO\n";
  return 0;
}
