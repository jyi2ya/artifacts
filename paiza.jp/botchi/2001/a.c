#include <stdio.h>
#include <string.h>

char ans[100009] = "", buf[1009];

int main(void)
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int ans_length = strlen(ans), i, same_length = 0;
		scanf("%s", buf);
		for (i = 0; i <= ans_length && (!i || buf[i - 1] != '\0'); ++i)
			if (strncmp(ans + ans_length - i, buf, i) == 0)
				same_length = i;
		ans[ans_length - same_length] = '\0';
		strcat(ans, buf);
	}
	puts(ans);
	return 0;
}
