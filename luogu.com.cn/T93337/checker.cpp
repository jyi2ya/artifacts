#include "testlib.h"

int main(int argc, char * argv[])
{
	setName("A Checker which always gives full score\n");
	registerTestlibCmd(argc, argv);
	while (!ouf.eof())
		ouf.readChar();
	quitf(_ok, "Thank you for sharing your code!");
	return 0;
}
