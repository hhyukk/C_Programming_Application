#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

typedef struct shopping {
	int productID; //상품ID
	char productName[100]; //상품명
	int productCount; //재고량
	int productPrice; //판매가격
	int soldCount; //판매량
} SHOP;

int start(); //초기실행
void receiving(SHOP* shop); //입고 선택 시 실행
void sale(SHOP* shop); //판매 선택시 실행
void individualStatus(SHOP shop[]); //개별현황
void totalStatus(SHOP shop[]); //전체현황

int main()
{
	SHOP shop[SIZE] = { 0,0,0,0,0 };

	while (1)
	{
		int menu = start();
		switch (menu)
		{
		case 1:
			receiving(shop);
			break;
		case 2:
			sale(shop);
			break;
		case 3:
			individualStatus(shop);
			break;
		case 4:
			totalStatus(shop);
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n\n");
			break;
		}
	}
}

int start() {
	int menu;

	printf("[쇼핑몰 관리 프로그램]\n");
	printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n");
	scanf("%d", &menu);
	getchar();

	return menu;
}

void receiving(SHOP* shop)
{
	int id;
	bool found = false;

	printf("상품ID : ");
	scanf("%d", &id);

	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID == id) {
			found = true;
			printf("상품명 : ");
			scanf("%s", shop[i].productName);
			printf("입고량 : ");
			scanf("%d", &(shop[i].productCount));
			printf("판매가격 : ");
			scanf("%d", &(shop[i].productPrice));
			break;
		}
	}
	if (found == false) {
		for (int i = 0; i < SIZE; i++) {
			if (shop[i].productID == 0) { // 빈 자리 찾기
				shop[i].productID = id;
				printf("상품명: ");
				scanf("%s", shop[i].productName);
				printf("입고량: ");
				scanf("%d", &(shop[i].productCount));
				printf("판매가격: ");
				scanf("%d", &(shop[i].productPrice));
				shop[i].soldCount = 0; // 새로 추가된 상품은 판매량 0으로 설정
				break;
			}
		}
	}
	printf("\n");
}

void sale(SHOP* shop) {
	int id;
	int saleCount;
	bool found = false;

	printf("상품ID : ");
	scanf("%d", &id);

	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID == id) {
			found = true;
			printf("판매량 : ");
			scanf("%d", &saleCount);

			if (shop[i].productCount >= saleCount) {
				shop[i].productCount -= saleCount;  // 재고 감소
				shop[i].soldCount += saleCount;     // 판매량 증가
				printf("판매 완료!\n\n");
			}
			else {
				printf("재고 부족: 현재 재고량은 %d개입니다.\n\n", shop[i].productCount);
			}
			break;
		}
	}
	if (!found) {
		printf("해당 상품 ID가 존재하지 않습니다.\n");
	}
}

void individualStatus(SHOP shop[]) {
	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID != 0) {
			printf("%d. 상품ID : %d, 상품명 : %s, 재고량 : %d, 판매가격 : %d, 판매량: %d\n",
				i + 1, shop[i].productID, shop[i].productName, shop[i].productCount, shop[i].productPrice, shop[i].soldCount);
		}
	}
	printf("\n");
}

void totalStatus(SHOP shop[]) {
	int totalReceived = 0;  // 총 입고량
	int totalSold = 0;      // 총 판매량
	int max = 0, min = 0;

	for (int i = 0; i < SIZE; i++) {
		totalReceived += (shop[i].productCount + shop[i].soldCount);  // 현재 재고 + 판매량이 총 입고량
		totalSold += shop[i].soldCount;  // 총 판매량

		if (shop[i].soldCount > shop[max].soldCount) {
			max = i;
		}
		if (shop[i].soldCount < shop[min].soldCount) {
			min = i;
		}


	}

	if (totalReceived > 0) {
		double sellRate = (double)totalSold / totalReceived * 100.0;
		printf("\n총 판매량: %d (총 판매율: %.2lf%%)\n\n", totalSold, sellRate);

		printf("가장 많이 판매된 상품ID %d, 상품명 : %s, 판매량: %d\n", shop[max].productID, shop[max].productName, shop[max].soldCount);
		printf("가장 적게 판매된 상품ID %d, 상품명 : %s, 판매량: %d\n", shop[min].productID, shop[min].productName, shop[min].soldCount);
	}
	else {
		printf("\n입고된 상품이 없습니다.\n\n");
	}

}