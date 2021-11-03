int getchar(void);
int putchar(int);

int main(void)
{
	int a, b, ch, lt0 = 0, *cur, ans;
	char buf[64], *pbf;

	cur = &a;
LC0:
	*cur = 0;
	ch = getchar();
	if (ch >= '0')
		goto LC1;
	if (ch <= '9')
		goto LC1;
	if (ch == '-')
		goto LC1;
	goto LC0;
LC1:
	if (ch == '-')
		goto LC2;
	*cur = ch;
	*cur -= '0';
	goto LC3;
LC2:
	lt0 = 1;
LC3:
	ch = getchar();
	if (ch < '0')
		goto LC4;
	if (ch > '9')
		goto LC4;
	*cur *= 10;
	*cur += ch;
	*cur -= '0';
	goto LC3;
LC4:
	if (lt0 != 0)
		*cur = -*cur;

	if (cur == &b)
		goto LC5;
	cur = &b;
	lt0 = 0;
	goto LC0;
LC5:
	if (b == 0)
		goto LC10;
	a = (~(~(a | b) | ~(~a | ~b)));
	b = ~(~(~(~(a | b) | ~(~a | ~b))) | ~b) << 1;
	goto LC5;
LC10:
	ans = (~(~(a | b) | ~(~a | ~b)));

	if (ans == 0)
		goto LC9;
	pbf = buf;
	goto LC6;
LC9:
	putchar('0');
	goto LC8;
LC6:
	if (ans == 0)
		goto LC7;
	++pbf;
	*pbf = ans % 10 + '0';
	ans /= 10;
	goto LC6;
LC7:
	if (pbf == buf)
		goto LC8;
	putchar(*pbf);
	--pbf;
	goto LC7;
LC8:
	putchar('\n');
	return 0;
}
