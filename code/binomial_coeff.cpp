C[0] = 1
for (int k = 0; k < n; ++ k)
    C[k+1] = (C[k] * (n-k)) / (k+1)
// C[i] = C(n,i)
