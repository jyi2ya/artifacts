#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int nlec, ncla, ppen, ppcl, csiz;
		int npen, npcl;
		scanf("%d%d%d%d%d", &nlec, &ncla, &ppen, &ppcl, &csiz);
		npen = (nlec + ppen - 1) / ppen;
		npcl = (ncla + ppcl - 1) / ppcl;
		if (npen + npcl > csiz)
			puts("-1");
		else
			printf("%d %d\n", npen, npcl);
	}
	return 0;
}
