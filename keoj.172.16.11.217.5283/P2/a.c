#include <stdio.h>

int n, k;

void do_k1(void)
{
	int i;
	int t, a = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &t);
		a ^= t;
	}
	printf("%d\n", a);
}

int val[44];
void do_k2(void)
{
	int i, j;
	int t, a1 = 0, a2 = 0;
	int x = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &t);
		for (j = 0; j < 32; ++j)
			if (t & (1 << j))
				val[j] ^= t;
		x ^= t;
	}
	for (i = 0; i < 32; ++i)
		if (x & (1 << i))
			break;
	a1 = x ^ val[i];
	a2 = x ^ a1;
	if (a1 > a2) {
		t = a1;
		a1 = a2;
		a2 = t;
	}
	printf("%d %d\n", a1, a2);
}

int main(void)
{
	scanf("%d%d", &n, &k);
	if (k == 1)
		do_k1();
	else
		do_k2();
	return 0;
}

/*
#include <stdio.h>

struct {
	FILE *fp;
} varray;

int v_read(int pos)
{
	int t;
	fseek(varray.fp, pos * sizeof(int), SEEK_SET);
	fread(&t, 1, sizeof(int), varray.fp);
	return t;
}

void v_write(int pos, int value)
{
	fseek(varray.fp, pos * sizeof(int), SEEK_SET);
	fwrite(&value, 1, sizeof(int), varray.fp);
}

void v_init(void)
{
	varray.fp = tmpfile();
}

void v_destroy(void)
{
	fclose(varray.fp);
}

int main(void)
{
	int n, k;
	int i, j;
	int cnt = 0;
	int last = -1;
	v_init();
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		v_write(i, t);
	}
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j) {
			int t = v_read(i);
			int t2 = v_read(j);
			if (t > t2) {
				v_write(i, t2);
				v_write(j, t);
			}
		}
	for (i = 0; i < n; ++i) {
		int t = v_read(i);
		if (last == t) {
			++cnt;
		} else {
			if (cnt & 1)
				printf("%d ", last);
			cnt = 1;
		}
		last = t;
	}
	if (cnt & 1)
		printf("%d\n", last);
	v_destroy();
	return 0;
}
*/
