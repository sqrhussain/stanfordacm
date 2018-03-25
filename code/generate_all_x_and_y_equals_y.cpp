for(int x = 1; x <= n; x++)
    for(int y = x; y; y = (y-1)&x)
        cout<<y<<endl;
