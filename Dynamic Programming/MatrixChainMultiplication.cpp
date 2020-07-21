int mcm_rec(int p[] ,  int s , int e)
{
    if(s == e)  //ONLY ONE DIMENSION
        return 0;
    if(s == e - 1) //TWO DIMENSIONS WHICH MEANS ONE MATRIX
        return 0;
    
    int min_ans = INT_MAX;
    for(int k = s + 1 ; k <= e - 1 ; k ++)
    {
    	int ans = mcm_rec(p , s , k) + mcm_rec(p , k , e) + p[s]*p[k]*p[e];
        if(ans < min_ans)
            min_ans = ans;
    }
    
    return min_ans;
}

int mcm(int p[], int n)
{
	n = n + 1;
    int m[n][n];
    int i, j, k, L, q;
 
    for (i = 1; i < n; i++)
        m[i][i] = 0;    

    for (L=2; L<n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;  //assigning to maximum value
 
            for (k = i; k < = j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }
 
    return m[1][n-1];   
}
