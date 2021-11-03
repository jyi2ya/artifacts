#include <stdio.h>
#include <string.h>

int d, s, b;
int type;
int data[10][20000];

void read(void);
int check_disk(void);
void fix_disk_bugs(void);
void print_disk_info(void);

int main(void)
{
	int cases = 0;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	while (scanf("%d", &d) == 1 && d) {
		read();
		if (check_disk()) {
			printf("Disk set %d is invalid.\n", ++cases);
		} else {
			fix_disk_bugs();
			printf("Disk set %d is valid, contents are: ", ++cases);
			print_disk_info();
		}
	}
	return 0;
}

char buf[1024];
int top;
void print_disk_info(void)
{
	int i, j, k, l, block_cnt = 0, tmp;
	top = 0;
	for (i = 0; i < b; ++i) {
		for (j = 0; j < d; ++j)
			if (block_cnt % d != j)
				for (k = 0; k < s; ++k) {
					buf[top++] = data[j][i * s + k] - '0';
					if (top == 4) {
						tmp = 0;
						for (l = 0; l < 4; ++l)
							tmp = tmp << 1 | buf[l];
						printf("%X", tmp);
						top = 0;
					}
				}
		++block_cnt;
	}
	tmp = 0;
	if (top) {
		for (l = 0; l < top; ++l)
			tmp = tmp << 1 | buf[l];
		for (; l < 4; ++l)
			tmp <<= 1;
		printf("%X", tmp);
	}
	putchar('\n');
}

void fix_disk_bugs(void)
{
	int i, j, k;
	for (i = 0; i < b; ++i)
		for (k = 0; k < s; ++k) {
			int ans = type == 'O' ? 1 : 0;
			for (j = 0; j < d; ++j)
				if (data[j][i * s + k] != 'x')
					ans ^= data[j][i * s + k] - '0';
			for (j = 0; j < d; ++j)
				if (data[j][i * s + k] == 'x')
					data[j][i * s + k] = ans + '0';
		}
}

int check_disk(void)
{
	int i, j, k;
	for (i = 0; i < b; ++i)
		for (k = 0; k < s; ++k) {
			int cnt = 0, ans = 0;
			for (j = 0; j < d; ++j) {
				if (data[j][i * s + k] == 'x')
					++cnt;
				else
					ans ^= data[j][i * s + k] - '0';
			}
			if (cnt >= 2)
				return 1;
			if (cnt == 0) {
				if (type == 'E' && ans != 0)
					return 1;
				if (type == 'O' && ans != 1)
					return 1;
			}
		}
	return 0;
}

void read(void)
{
	int i, j, k;
	scanf("%d%d", &s, &b);
	while (getchar() != '\n');
	type = getchar();
	while (getchar() != '\n');
	for (i = 0; i < d; ++i) {
		for (j = 0; j < b; ++j)
			for (k = 0; k < s; ++k)
				data[i][j * s + k] = getchar();
		while (getchar() != '\n');
	}
}
