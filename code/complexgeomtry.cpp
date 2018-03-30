src: http://codeforces.com/blog/entry/22175
Functions using std::complex
1)  Vector addition: a + b
2)  Scalar multiplication: r * a
3)  Dot product: (conj(a) * b).x
4)  Cross product: (conj(a) * b).y
5)  notice: conj(a) * b = (ax*bx + ay*by) + i (ax*by — ay*bx)
6)  Squared distance: norm(a - b)
7)  Euclidean distance: abs(a - b)
8)  Angle of elevation: arg(b - a)
9)  Slope of line (a, b): tan(arg(b - a))
10) Polar to cartesian: polar(r, theta)
11) Cartesian to polar: point(abs(p), arg(p))
12) Rotation about the origin: a * polar(1.0, theta)
13) Rotation about pivot p: (a-p) * polar(1.0, theta) + p
14) Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
       remainder normalizes the angle to be between [-PI, PI]. Thus, we can get the positive non-reflex angle by taking its abs value.
15) Project p onto vector v: v * dot(p, v) / norm(v);
16) Project p onto line (a, b): a + (b - a) * dot(p - a, b - a) / norm(b - a)
17) Reflect p across line (a, b): a + conj((p - a) / (b - a)) * (b - a)
18) Intersection of line (a, b) and (p, q):
19)
point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

Drawbacks:
Using std::complex is very advantageous, but it has one disadvantage: you can't use std::cin or scanf. Also, if we macro x and y, we can't use them as variables. But that's rather minor, don't you think?
EDIT: Credits to Zlobober for pointing out that std::complex has issues with integral data types. The library will work for simple arithmetic like vector addition and such, but not for polar or abs. It will compile but there will be some errors in correctness! The tip then is to rely on the library only if you're using floating point data all throughout.
