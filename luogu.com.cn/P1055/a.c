#include <stdio.h>

/*#define DEBUG*/

int main(void){
    char isbn[15];
    int check;
    scanf("%s",isbn);
    
    check=
    ((isbn[0]-'0')*1+(isbn[2]-'0')*2+
    (isbn[3]-'0')*3+(isbn[4]-'0')*4+
    (isbn[6]-'0')*5+(isbn[7]-'0')*6+
    (isbn[8]-'0')*7+(isbn[9]-'0')*8+
    (isbn[10]-'0')*9)%11;
    
    #ifdef DEBUG
    printf("%s\n",isbn);
    printf("%d\n",check);
    #endif
    
    if((isbn[12]-'0')==check || (check==10 && isbn[12]=='X')) printf("Right");
    else {
        isbn[12]='\0';
        printf("%s",isbn);
        printf((check==10)?"X":"%d",check);
    }
    
    return 0;
}
