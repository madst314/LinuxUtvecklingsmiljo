#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "gdblab.h"

int test()
{
	int i;
	typedef struct{
		int buffert1[17];
		int buffert2[17];
	}theTest;

	theTest *test = (theTest*)malloc(sizeof(theTest));

	int j=2;

	for (i=0; i<17; i++)
	{
		test->buffert1[i] = i;
	}

	test->buffert2[0] = 45;
	test->buffert2[1] = 5;

	printf("16 + 14 = %i\n", test->buffert1[16] + test->buffert1[14]);
	printf("45 + 5 = %i\n", test->buffert2[0] + test->buffert2[1]);
	free(test);

	//test->buffert2[0] = 5;
	//printf("16 + 14 = %i\n", test->buffert1[16] + test->buffert1[14]);

	//kill(getpid(),SIGSEGV);

return 0;
}
