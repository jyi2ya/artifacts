#include <stdio.h>

#include <iostream>

#include <cstring>

using namespace std;

void ISBN(char *x, char *raw)
{
	int c = 0;
	int i;
	strcpy(x, raw);
	for (i = 1; i <= 9; ++i) {
		while (*raw < '0' || *raw > '9')
			++raw;
		c = (c + (*raw - '0') * i) % 11;
		++raw;
	}
	sprintf(x + strlen(x), "-%c", c < 10 ? c + '0' : 'X');
}

int main()
{
    char charISBN11[12], charISBN[14];
    cin>>charISBN11;
    ISBN(charISBN,charISBN11);
    cout<<charISBN<<endl;
    return 0;
}
