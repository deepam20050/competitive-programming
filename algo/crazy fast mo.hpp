// 1 based indexing
struct query {
  int id, l, r, order;
  query (int _i, int _l, int _r) {
    id = _i;
    l = _l;
    r = _r;
    order = hilbertOrder(l, r, 21, 0);
  }
} q[Q];

int nq; cin >> nq;
for (int i = 0; i < nq; ++i) {
  int l, r; cin >> l >> r;
  q[i] = query(i, l, r);
}
sort(q, q + nq, [&] (const query &a, const query &b) {
  return a.order < b.order;
});
for (int i = 0, L = 1, R = 0; i < nq; ++i) {
  while (R < q[i].r) add_element(++R);
  while (L > q[i].l) add_element(--L);
  while (R > q[i].r) remove_element(R--);
  while (L < q[i].l) remove_element(L++);
  res[q[i].id] = ans;
}

// Credits : https://codeforces.com/blog/entry/61203
inline lli hilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow-1);
  int seg = (x < hpow) ? (
    (y < hpow) ? 0 : 3
  ) : (
    (y < hpow) ? 1 : 2
  );
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  lli subSquareSize = lli(1) << (2*pow - 2);
  lli ans = seg * subSquareSize;
  lli add = hilbertOrder(nx, ny, pow-1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}