#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char urlbuf[1009][1000], inbuf[100000009], tagstack[100009], outbuf[100000009];
int tagtop = 0, urltop = 0, intop = 0, outtop = 0;

void die(const char *msg);
void vputs(const char *str);
void vputc(int ch);

int main(void)
{
	int ch, i, t;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	while ((ch = getchar()) != EOF)
		inbuf[intop++] = ch;

	for (i = 0; i < intop; ++i) {
		if (strncmp(inbuf + i, "[h1]", strlen("[h1]")) == 0) {
			i += strlen("[h1]") - 1;
			tagstack[tagtop++] = '1';
			vputs("# ");
		} else if (strncmp(inbuf + i, "[h2]", strlen("[h2]")) == 0) {
			i += strlen("[h2]") - 1;
			tagstack[tagtop++] = '2';
			vputs("## ");
		} else if (strncmp(inbuf + i, "[i]", strlen("[i]")) == 0) {
			i += strlen("[i]") - 1;
			tagstack[tagtop++] = 'i';
			vputs("*");
		} else if (strncmp(inbuf + i, "[b]", strlen("[b]")) == 0) {
			i += strlen("[b]") - 1;
			tagstack[tagtop++] = 'b';
			vputs("__");
		} else if (strncmp(inbuf + i, "[url=", strlen("[url=")) == 0) {
			i += strlen("[url=");
			tagstack[tagtop++] = 'u';
			t = 0;
			while (inbuf[i] != ']')
				urlbuf[urltop][t++] = inbuf[i++];
			urlbuf[urltop][t++] = '\0';
			++urltop;
			vputs("[");
		} else if (strncmp(inbuf + i, "[img=", strlen("[img=")) == 0) {
			i += strlen("[img=");
			tagstack[tagtop++] = 'i';
			t = 0;
			while (inbuf[i] != ']')
				urlbuf[urltop][t++] = inbuf[i++];
			urlbuf[urltop][t++] = '\0';
			++urltop;
			vputs("![");
		} else if (strncmp(inbuf + i, "[quote]", strlen("[quote]")) == 0) {
			if (i != 0 && inbuf[i - 1] != '\n')
				vputs("\n> ");
			if (i == 0)
				vputs("> ");
			i += strlen("[quote]");
			while (inbuf[i] == '\n')
				++i;
			while (strncmp(inbuf + i, "[/quote]", strlen("[/quote]")) != 0) {
				if (inbuf[i] == '\n')
					vputs("\n> ");
				else
					vputc(inbuf[i]);
				++i;
			}
			t = 0;
			outtop -= 3;
			while (strncmp(outbuf + outtop, "\n> ", strlen("\n> ")) == 0) {
				outtop -= 3;
				++t;
			}
			outtop += 3;
			while (t--)
				vputc('\n');
			i += strlen("[/quote]") - 1;

		} else if (strncmp(inbuf + i, "[/h1]", strlen("[/h1]")) == 0) {
			i += strlen("[/h1]") - 1;
			if (tagstack[--tagtop] != '1')
				die("Match Error");
			vputs(" #");
		} else if (strncmp(inbuf + i, "[/h2]", strlen("[/h2]")) == 0) {
			i += strlen("[/h2]") - 1;
			if (tagstack[--tagtop] != '2')
				die("Match Error");
			vputs(" ##");
		} else if (strncmp(inbuf + i, "[/i]", strlen("[/i]")) == 0) {
			i += strlen("[/i]") - 1;
			if (tagstack[--tagtop] != 'i')
				die("Match Error");
			vputs("*");
		} else if (strncmp(inbuf + i, "[/b]", strlen("[/b]")) == 0) {
			i += strlen("[/b]") - 1;
			if (tagstack[--tagtop] != 'b')
				die("Match Error");
			vputs("__");
		} else if (strncmp(inbuf + i, "[/url]", strlen("[/url]")) == 0) {
			i += strlen("[/url]") - 1;
			if (tagstack[--tagtop] != 'u')
				die("Match Error");
			vputs("](");
			vputs(urlbuf[--urltop]);
			vputs(")");
		} else if (strncmp(inbuf + i, "[/img]", strlen("[/img]")) == 0) {
			i += strlen("[/img]") - 1;
			if (tagstack[--tagtop] != 'i')
				die("Match Error");
			vputs("](");
			vputs(urlbuf[--urltop]);
			vputs(")");
		} else if (strncmp(inbuf + i, "[/quote]", strlen("[/quote]")) == 0) {
			die("Match Error");
		} else {
			vputc(inbuf[i]);
		}
	}
	vputc('\n');
	if (tagtop)
		die("Unclosed Mark");
	for (i = 0; i < outtop; ++i)
		putchar(outbuf[i]);
	return 0;
}

void die(const char *msg)
{
	puts(msg);
	exit(0);
}

void vputs(const char *str)
{
	strcat(outbuf + outtop, str);
	outtop += strlen(str);
}

void vputc(int ch)
{
	outbuf[outtop++] = ch;
}
