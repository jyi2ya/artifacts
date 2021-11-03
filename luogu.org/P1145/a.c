#include <stdio.h>

int main(void)
{
        int k,num=0;
        scanf("%d",&k);
        while(++num){
                int pos=0,i,mod=k<<1;
                for(i=0;i<k;++i){
                        pos=(pos+num-1)%mod;
                        if(pos<k) goto bad;
                        --mod;
                }
                printf("%d\n",num);
                return 0;
bad:
                continue;
        }
        return 0;
}
