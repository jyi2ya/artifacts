#include <stdio.h>

int main(void){
    int ele;
    float cost;
    scanf("%d",&ele);
    if(ele<=150) cost=(float)ele*0.4463;
    else if(150<ele && ele<=400) cost=0.4463*150+(float)(ele-150)*0.4663;
    else if(ele>400) cost=0.4463*150+250*0.4663+(float)(ele-400)*0.5663;
    
    printf("%.1f",cost);
    return 0;
}
