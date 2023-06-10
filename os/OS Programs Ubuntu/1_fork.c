#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	int a;

	// make two process which run same program after this instruction
	fork();

	printf("Hello world!\n");
	fflush(stdout); // Force stdout to be flushed
	scanf("%d", &a);
	return 0;
}

