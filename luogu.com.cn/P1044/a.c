#include <stdio.h>

long long a[19][19];

int main()
{
        int i,j;
        int n;
        scanf("%d",&n);
        for(i=0;i<=n;i++) a[0][i] = 1;
        for(i=1;i<=n;i++)
                for(j=i;j<=n;j++) {
                        if(i==j) a[i][j] = a[i-1][j];
                        else a[i][j] = a[i-1][j] + a[i][j-1];
                }
        printf("%d\n",a[n][n]);
        return 0;
}

