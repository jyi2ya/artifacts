#include <stdio.h>
#include <string.h>

int N;
int A[20], B[20], C[20], D[20];

void read(void);
void nextone(int *arr);
int check(int *arr);
void print_statu(int *arr);

int main(void)
{
	int cases = 0;
	while (scanf("%d", &N) == 1 && N) {
		int ans = 1;
		read();
		if (!check(C)) {
			do {
				++ans;
				nextone(C);
				if (check(C))
					break;
				nextone(D);
				nextone(D);
			} while (memcmp(C, D, sizeof(C)) != 0);
		}
		if (!check(C))
			ans = -1;
		printf("Case %d: %d\n", ++cases, ans);
	}
	return 0;
}

int check(int *arr)
{
	int i;
	for (i = 0; i < N; ++i)
		if (arr[i] > A[i])
			return 0;
	return 1;
}

void print_statu(int *arr)
{
	int i;
	for (i = 0;i < N; ++i) {
		if (arr[i] <= A[i])
			putchar('O');
		else
			putchar('x');
		printf("(%d,%d,%d)", A[i], B[i], C[i]);
	}
	putchar('\n');
}

void nextone(int *arr)
{
	int sleeping = 0, i;
	for (i = 0; i < N; ++i)
		if (arr[i] > A[i])
			++sleeping;
	for (i = 0; i < N; ++i)
		++arr[i];
	for (i = 0; i < N; ++i) {
		if (arr[i] == A[i] + 1)
			if (sleeping * 2 <= N)
				arr[i] = 1;
		if (arr[i] == A[i] + B[i] + 1)
			arr[i] = 1;
	}
}

void read(void)
{
	int i;
	for (i = 0; i < N; ++i)
		scanf("%d%d%d", A + i, B + i, C + i);
	memcpy(D, C, sizeof(C));
}
