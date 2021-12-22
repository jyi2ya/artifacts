#include <iostream>

using namespace std;

void longest(char *str, char *result)
{
	char *start, *cur;
	int len = 0;
	cur = str;
	while (*cur != '\0') {
		while ((*cur == ' ' || *cur == '\t' || *cur == '\n' || *cur == '\r') && *cur != '\0')
			++cur;
		start = cur;
		while (!(*cur == ' ' || *cur == '\t' || *cur == '\n' || *cur == '\r') && *cur != '\0')
			++cur;
		if (cur - start > len) {
			len = cur - start;
			for (int i = 0; i < len; ++i)
				result[i] = start[i];
			result[len] = '\0';
		}
	}
}


int main()

{

	char c1[1000];

	char c2[100];

	cin.getline(c1,1000);

	longest(c1,c2);

	cout<<c2<<endl;

	return 0;

}
