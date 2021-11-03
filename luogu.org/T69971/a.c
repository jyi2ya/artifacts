#include <stdio.h>
#include <string.h>

char B[100009];
int Btop;

int is_python(void);
int is_pascal(void);
int is_cpp(void);
int is_java(void);

int main(void)
{
	int c;
	while ((c = getchar()) != EOF)
		B[Btop++] = c;
	if (is_python())
		puts("python");
	else if (is_java())
		puts("java");
	else if (is_cpp())
		puts("c++");
	else if (is_pascal())
		puts("pascal");
	else
		puts("python");
	return 0;
}

int is_python(void)
{
	return 0;
}

int is_pascal(void)
{
	return strstr(B, "begin") &&
		strstr(B, "end.") && strstr(B, ";");
}

int is_cpp(void)
{
	return strstr(B, "main") &&
		(strstr(B, "#include <") || strstr(B, "#include<") ||
		 strstr(B, "#include\"") || strstr(B, "#include \"")) &&
		*strchr(B, '{') == '{' && *strchr(B, ';') == ';';
}

int is_java(void)
{
	return strstr(B, "class") && strstr(B, "public");
}
