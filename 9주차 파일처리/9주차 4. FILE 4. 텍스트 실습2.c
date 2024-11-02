#include <stdio.h>
int main()
{
	char input[100];
	FILE* fp_src;
	FILE* fp_dest;
	
	if ((fp_src = fopen("outut.txt", "r")) == NULL){
		printf("error");
		return 0;
	}
	if ((fp_dest = fopen("outut2.txt", "w")) == NULL) {
		printf("error");
		return 0;
	}
	while (!feof(fp_src)) { //파일의 끝인지 확인
		fgets(input, 100, fp_src);
		printf("출력중\n");
		fputs(input,fp_dest);
	}

	fclose(fp_src);
	fclose(fp_dest);

	return 0;
}