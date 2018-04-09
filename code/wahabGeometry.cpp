int segmentLatticePointsCount(int x1, int y1, int x2, int y2) {
  return abs(__gcd(x1 - x2, y1 - y2)) + 1;
}
int picksTheorm(int a, int b) {
  return a - b / 2 + 1;
}
void polygonCut(const vector<point>& p, const point&a, const point&b, vector<point>& res) {
  res.clear();
  for (int i = 0; i < sz(p); i++) {
    int j = (i + 1) % sz(p);
    bool in1 = cross(vec(a,b),vec(a,p[i])) > EPS;
    bool in2 = cross(vec(a,b),vec(a,p[j])) > EPS;
    if (in1) res.push_back(p[i]);
    if (in1 ^ in2) {
        point r;
        intersect(a, b, p[i], p[j], r);
        res.push_back(r);
    }
  }
}

// assume that both are anti-clockwise
void convexPolygonIntersect(const vector<point>& p, const vector<point>& q, vector<point>& res) {
  res = q;
  for (int i = 0; i < sz(p); i++) {
    int j = (i + 1) % sz(p);
    vector<point> temp;
    polygonCut(res, p[i], p[j], temp);
    res = temp;
    if (res.empty()) return;
  }
}
