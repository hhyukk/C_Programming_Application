#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int start(); //초기실행
void receiving(int* totalCount); //입고 선택 시 실행
void sale(int* totalCount, int* saleCount); //판매 선택시 실행
void countSituation(int* totalCount, int* saleCount); //재고현황

int main()
{
	int totalCount[SIZE] = { 0 }; //전체 상품의 수량
	int saleCount[SIZE] = { 0 }; //전체 상품의 판매 수량
	while (1)
	{
		int menu = start();
		if (menu == 1) {
			receiving(totalCount);
		}
		else if (menu == 2) {
			sale(totalCount, saleCount);
		}
		else if (menu == 3) {
			countSituation(totalCount, saleCount);
		}
		else if (menu == 4) {
			break;
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
}

int start() {
	printf("[쇼핑몰 관리 프로그램]\n");
	printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
	
	int menu;
	scanf("%d", &menu);
	    
	return menu;
}
void receiving(int* totalCount)
{
	printf("\n입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
	int menu;
	scanf("%d", &menu);
	if (menu == 1)
	{
		for (int i = 0; i < SIZE; i++)
		{
			scanf("%d", &totalCount[i]);
		}
	}
	else if (menu == 2)
	{
		int productID;

		printf("상품ID: ");
		scanf("%d", &productID);

		if (productID >= 0 && productID < SIZE) {
			printf("입고 수량: ");
			scanf("%d", &totalCount[productID]);
		}
		else {
			printf("Error: 잘못된 선택입니다.\n");
		}
	}
	else printf("Error!!");

	printf("\n");
}

void sale(int* totalCount, int* saleCount) {
	printf("\n판매수량 입력: 전체 상품 판매수량 입력1, 개별 상품 입력 2를 선택\n");

	int menu;
	scanf("%d", &menu);

	if (menu == 1) {
		for (int i = 0; i < SIZE; i++) {
			scanf("%d", &saleCount[i]);

			if (saleCount[i] > totalCount[i]) {
				printf("Error: 판매 수량이 재고 수량보다 많습니다.\n");
				saleCount[i] = 0; // 잘못된 입력 방지
			}
		}
	}
	else if (menu == 2) {
		int priceId;

		printf("상품ID: ");
		scanf("%d", &priceId);

		if (priceId >= 0 && priceId < SIZE) {
			printf("판매수량: ");
			scanf("%d", &saleCount[priceId]);

			if (saleCount[priceId] > totalCount[priceId]) {
				printf("Error: 판매 수량이 재고 수량보다 많습니다.\n");
				saleCount[priceId] = 0;
			}
		}
		else {
			printf("Error: 잘못된 상품ID.\n");
		}
	}
	else {
		printf("Error: 잘못된 선택입니다.\n");
	}

	printf("\n");
}

void countSituation(int* totalCount, int* saleCount) {
	int totalProductCount=0, totalSaleCount = 0; // 총 상품 수량, 총 판매 수량
	int maxSale = saleCount[0], minSale = saleCount[0]; // 가장 많이, 적게 판매된 상품
	int maxSaleID = 0, minSaleID = 0; // 해당 상품의 ID

	printf("\n재고수량: ");
	for (int i = 0; i < SIZE; i++) {
		int remainingStock = totalCount[i] - saleCount[i];
		printf("%d ", remainingStock);

		totalProductCount += totalCount[i];
		totalSaleCount += saleCount[i];

		if (saleCount[i] > maxSale) {
			maxSale = saleCount[i];
			maxSaleID = i;
		}

		if (saleCount[i] < minSale) {
			minSale = saleCount[i];
			minSaleID = i;
		}
	}

	printf("\n총 판매량: %d (판매율 %.2lf%%)\n",totalSaleCount, ((double)totalSaleCount / (double)totalProductCount)*100);
	printf("가장 많이 판매된 상품ID: %d, 판매량: %d\n", maxSaleID+1, maxSale);
	printf("가장 적게 판매된 상품ID: %d, 판매량: %d\n", minSaleID+1, minSale);

	for (int i = 0; i < SIZE; i++) {
		int remainingStock = totalCount[i] - saleCount[i];
		if (remainingStock <= 2) {
			printf("상품 ID %d : 재고부족(%d)\n", i, remainingStock);
		}
	}
	printf("\n");
}