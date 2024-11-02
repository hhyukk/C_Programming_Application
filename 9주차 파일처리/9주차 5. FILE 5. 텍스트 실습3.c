#include <stdio.h>
int main()
{
	char input[100];
	FILE* fp_src;
	int num1, num2;
	FILE* fp_dest;
	
	if ((fp_src = fopen("outut.txt", "r")) == NULL){
		printf("error");
		return 0;
	}
	if ((fp_dest = fopen("outut3.txt", "w")) == NULL) {
		printf("error");
		return 0;
	}
	while (!feof(fp_src)) { //파일의 끝인지 확인
		fscanf(fp_src, "%s %d %d\n",input, &num1,&num2);
		fprintf(fp_dest, "%s %d %d\n", input, num1, num2);
	}

	fclose(fp_src);
	fclose(fp_dest);

	return 0;
}