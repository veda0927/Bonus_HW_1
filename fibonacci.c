#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n;

	if (argc > 1) {
		n = atoi(argv[1]);
	} else {
		printf("How many elements you want to display: ");
		scanf("%d", &n);
	}

	int a = 0, b = 1;
	int next = b + a;

	printf("The first %d values: ", n);
	if (n == 0) {
		goto END;
	} else if (n == 1) {
		printf("%d", a);
		goto END;
	} else if (n == 2) {
		printf("%d, %d", a, b);
		goto END;
	} else {
		int i = 2;
		while (i < n)
		{
			printf(", %d", next);
			a = b;
			b = next;
			next += a;

			++i;
		}
	}

	END:
		printf("\n");
		return 0;
}
