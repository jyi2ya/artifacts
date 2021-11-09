#include <stdio.h>

//#define DEBUG

int main(void){
    int N,i,pre=0,days=0,MaxDays=0;
    scanf("%d",&N);
    scanf("%d",&pre);
    days++;
    MaxDays++;
    
    for(i=1;i<N;i++){
        int a;
        scanf("%d",&a);
        if(a>pre){
            days++;
            pre=a;
        }
        else {
            if(days>MaxDays) MaxDays=days;
            days=1;
            pre=a;
        }
        #ifdef DEBUG
        printf("     -----days=%d,i=%d,a=%d\n",days,i,a);
        #endif
    }
    if(days>MaxDays) MaxDays=days;
    printf("%d",MaxDays);
    return 0;
}
