#include <stdio.h>
#include <string.h>

int main()
{
	char src[100] = "source contents";
	char dest[100];

	printf("length of src = %d\n", strlen(src));
	strcpy(dest, src);
	printf("after copy. src = \"%s\",desc \"%s\"\n", src, dest);
	printf("comp = %d\n", strcmp(src, dest));
	strcat(dest, src);
	printf("after strcat. src = \"%s\", desc \"%s\"\n", src, dest);
	return 0;
}