#include <stdio.h>
#include <string.h>

char mp[2049][2049];
int h, w;

void init_mp(void);
void print_mp(void);
void multi(void);

int main(void)
{
	int n;
	scanf("%d", &n);
	memset(mp, ' ', sizeof(mp));
	init_mp();
	while (--n)
		multi();
	print_mp();
	return 0;
}

void multi(void)
{
	int i, j;
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			mp[i + h][j] = mp[i][j];
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			mp[i + h][j + w] = mp[i][j];
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			mp[i][j] = ' ';
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			mp[i][j + w / 2] = mp[i + h][j];
	h *= 2;
	w *= 2;
}

void print_mp(void)
{
	int i, j;
	for (i = 0; i < h; ++i) {
		for (j = 0; j < w; ++j)
			putchar(mp[i][j]);
		putchar('\n');
	}
}

void init_mp(void)
{
	/*
	    /\
	   /__\
	   */
	mp[0][0] = ' ';
	mp[0][1] = '/';
	mp[0][2] = '\\';
	mp[0][3] = ' ';
	mp[1][0] = '/';
	mp[1][1] = '_';
	mp[1][2] = '_';
	mp[1][3] = '\\';
	h = 2;
	w = 4;
}
