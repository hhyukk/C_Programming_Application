#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int start(); //�ʱ����
void receiving(int* totalCount); //�԰� ���� �� ����
void sale(int* totalCount, int* saleCount); //�Ǹ� ���ý� ����
void countSituation(int* totalCount, int* saleCount); //�����Ȳ

int main()
{
	int totalCount[SIZE] = { 0 }; //��ü ��ǰ�� ����
	int saleCount[SIZE] = { 0 }; //��ü ��ǰ�� �Ǹ� ����
	while (1)
	{
		int menu = start();
		switch (menu)
		{
		case 1:
			receiving(totalCount);
			break;
		case 2:
			sale(totalCount, saleCount);
			break;
		case 3:
			countSituation(totalCount, saleCount);
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
			break;
		}
	}
}

int start() {
	int menu;

	printf("[���θ� ���� ���α׷�]\n");
	printf("���ϴ� �޴��� �����ϼ���. (1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
	scanf("%d", &menu);
	    
	return menu;
}
void receiving(int* totalCount)
{
	int menu;

	printf("\n�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
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

		printf("��ǰID: ");
		scanf("%d", &productID);

		if (productID >= 0 && productID < SIZE) {
			printf("�԰� ����: ");
			scanf("%d", &totalCount[productID]);
		}
		else {
			printf("Error: �߸��� �����Դϴ�.\n");
		}
	}
	else printf("Error: �߸��� �����Դϴ�.\n");

	printf("\n");
}

void sale(int* totalCount, int* saleCount) {
	int menu;

	printf("\n�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է�1, ���� ��ǰ �Է� 2�� ����\n");
	scanf("%d", &menu);

	if (menu == 1) {
		for (int i = 0; i < SIZE; i++) {
			scanf("%d", &saleCount[i]);

			if (saleCount[i] > totalCount[i]) {
				printf("Error: �Ǹ� ������ ��� �������� �����ϴ�.\n");
				saleCount[i] = 0; // �߸��� �Է� ����
			}
		}
	}
	else if (menu == 2) {
		int priceId;

		printf("��ǰID: ");
		scanf("%d", &priceId);

		if (priceId >= 0 && priceId < SIZE) {
			printf("�Ǹż���: ");
			scanf("%d", &saleCount[priceId]);

			if (saleCount[priceId] > totalCount[priceId]) {
				printf("Error: �Ǹ� ������ ��� �������� �����ϴ�.\n");
				saleCount[priceId] = 0;
			}
		}
		else {
			printf("Error: �߸��� ��ǰID.\n");
		}
	}
	else {
		printf("Error: �߸��� �����Դϴ�.\n");
	}

	printf("\n");
}

void countSituation(int* totalCount, int* saleCount) {
	int totalProductCount=0, totalSaleCount = 0; // �� ��ǰ ����, �� �Ǹ� ����
	int maxSale = saleCount[0], minSale = saleCount[0]; // ���� ����, ���� �Ǹŵ� ��ǰ
	int maxSaleID = 0, minSaleID = 0; // �ش� ��ǰ�� ID

	printf("\n������: ");
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

	printf("\n�� �Ǹŷ�: %d (�Ǹ��� %.2lf%%)\n",totalSaleCount, ((double)totalSaleCount / (double)totalProductCount)*100);
	printf("���� ���� �Ǹŵ� ��ǰID: %d, �Ǹŷ�: %d\n", maxSaleID+1, maxSale);
	printf("���� ���� �Ǹŵ� ��ǰID: %d, �Ǹŷ�: %d\n", minSaleID+1, minSale);

	for (int i = 0; i < SIZE; i++) {
		int remainingStock = totalCount[i] - saleCount[i];
		if (remainingStock <= 2) {
			printf("��ǰ ID %d : ������(%d)\n", i, remainingStock);
		}
	}
	printf("\n");
}