#include <stdio.h>

int days[8];

int main(void){
    int most=1;
    {
        int i;
        for(i=1;i<=7;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            days[i]=a+b;
        }
    }
    {
        int i;
        for(i=1;i<=7;i++)
            if(days[most]<days[i]) most=i;
    }
    printf("%d",most);
    return 0;
}
