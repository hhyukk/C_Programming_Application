#include <stdio.h>
void getLine(char* line) {
	int ch, i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';

}
int main()
{
	char input[100];
	FILE* fp;
	
	if ((fp = fopen("outut.txt", "w")) == NULL){
		printf("error");
		return 0;
	}
	for (int i = 0; i < 5; i++) {
		getLine(input);
		fputs(input,fp);
		fputs("\n", fp);
	}

	fclose(fp);
	return 0;
}