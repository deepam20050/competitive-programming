void push (int lx, int rx, int x) {
  if (!sum[x]) return;
  t[x] += sum[x];
  if (lx != rx) {
    sum[2 * x] += sum[x];
    sum[2 * x + 1] += sum[x];
  }
  sum[x] = 0;
}

void update (int lx, int rx, int x, int ql, int qr, int v) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return;
  if (ql <= lx && rx <= qr) {
    sum[x] += v;
    push(lx, rx, x);
    return;
  }
  int midx = lx + rx >> 1;
  update(lx, midx, 2 * x, ql, qr, v);
  update(midx + 1, rx, 2 * x + 1, ql, qr, v);
  t[x] = min(t[2 * x], t[2 * x + 1]);
}

lli query (int lx, int rx, int x, int ql, int qr) {
  push(lx, rx, x);
  if (lx > qr || ql > rx) return inf;
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return min(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
