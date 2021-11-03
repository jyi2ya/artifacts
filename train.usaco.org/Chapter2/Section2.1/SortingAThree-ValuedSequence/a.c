/*
ID:lindong6
PROG:sort3
LANG:C
*/

#include <stdio.h>

int seq[1009], N;

void read(void);
int find(int start, int number, int delta);
int swap(int p, int q);
void prtseq(void);

int num[4];

int main(void)
{
	register int i;
	int pos, ans = 0;

	read();
	for (i = 0; i < N; ++i)
		++num[seq[i]];
	for (i = 0; i < num[1]; ++i) {
		if (seq[i] == 2) {
			pos = find(num[1], 1, 1);
			if (pos > 0) {
				swap(pos, i);
				++ans;
			} else {
				pos = find(num[1] + num[2], 1, 1);
				if (pos > 0) {
					swap(pos, i);
					++ans;
				}
			}
		}
		if (seq[i] == 3) {
			pos = find(num[1] + num[2], 1, 1);
			if (pos > 0) {
				swap(pos, i);
				++ans;
			} else {
				pos = find(num[1], 1, 1);
				if (pos > 0) {
					swap(pos, i);
					++ans;
				}
			}
		}
	}
	for (i = num[1]; i < num[1] + num[2]; ++i)
		if (seq[i] == 3) {
			pos = find(num[1] + num[2], 2, 1);
			swap(pos, i);
			++ans;
		}

	printf("%d\n", ans);
	return 0;
}

void read(void)
{
	register int i;
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", seq + i);
}

int find(int start, int number, int delta)
{
	register int i;
	for (i = start; i >= 0 && i < N; i += delta)
		if (seq[i] == number)
			return i;
	return -1;
}

int swap(int p, int q)
{
	int t = seq[p]; seq[p] = seq[q]; seq[q] = t;
	return 0;
}

void prtseq(void)
{
	register int i;
	for (i = 0; i < N; ++i)
		printf("%d", seq[i]);
	putchar('\n');
}
