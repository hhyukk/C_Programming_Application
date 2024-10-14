#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

typedef struct shopping {
	int productID; //��ǰID
	char productName[100]; //��ǰ��
	int productCount; //���
	int productPrice; //�ǸŰ���
	int soldCount; //�Ǹŷ�
} SHOP;

int start(); //�ʱ����
void receiving(SHOP* shop); //�԰� ���� �� ����
void sale(SHOP* shop); //�Ǹ� ���ý� ����
void individualStatus(SHOP shop[]); //������Ȳ
void totalStatus(SHOP shop[]); //��ü��Ȳ

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
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n\n");
			break;
		}
	}
}

int start() {
	int menu;

	printf("[���θ� ���� ���α׷�]\n");
	printf("���ϴ� �޴��� �����ϼ���. (1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ����)\n");
	scanf("%d", &menu);
	getchar();

	return menu;
}

void receiving(SHOP* shop)
{
	int id;
	bool found = false;

	printf("��ǰID : ");
	scanf("%d", &id);

	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID == id) {
			found = true;
			printf("��ǰ�� : ");
			scanf("%s", shop[i].productName);
			printf("�԰� : ");
			scanf("%d", &(shop[i].productCount));
			printf("�ǸŰ��� : ");
			scanf("%d", &(shop[i].productPrice));
			break;
		}
	}
	if (found == false) {
		for (int i = 0; i < SIZE; i++) {
			if (shop[i].productID == 0) { // �� �ڸ� ã��
				shop[i].productID = id;
				printf("��ǰ��: ");
				scanf("%s", shop[i].productName);
				printf("�԰�: ");
				scanf("%d", &(shop[i].productCount));
				printf("�ǸŰ���: ");
				scanf("%d", &(shop[i].productPrice));
				shop[i].soldCount = 0; // ���� �߰��� ��ǰ�� �Ǹŷ� 0���� ����
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

	printf("��ǰID : ");
	scanf("%d", &id);

	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID == id) {
			found = true;
			printf("�Ǹŷ� : ");
			scanf("%d", &saleCount);

			if (shop[i].productCount >= saleCount) {
				shop[i].productCount -= saleCount;  // ��� ����
				shop[i].soldCount += saleCount;     // �Ǹŷ� ����
				printf("�Ǹ� �Ϸ�!\n\n");
			}
			else {
				printf("��� ����: ���� ����� %d���Դϴ�.\n\n", shop[i].productCount);
			}
			break;
		}
	}
	if (!found) {
		printf("�ش� ��ǰ ID�� �������� �ʽ��ϴ�.\n");
	}
}

void individualStatus(SHOP shop[]) {
	for (int i = 0; i < SIZE; i++) {
		if (shop[i].productID != 0) {
			printf("%d. ��ǰID : %d, ��ǰ�� : %s, ��� : %d, �ǸŰ��� : %d, �Ǹŷ�: %d\n",
				i + 1, shop[i].productID, shop[i].productName, shop[i].productCount, shop[i].productPrice, shop[i].soldCount);
		}
	}
	printf("\n");
}

void totalStatus(SHOP shop[]) {
	int totalReceived = 0;  // �� �԰�
	int totalSold = 0;      // �� �Ǹŷ�
	int max = 0, min = 0;

	for (int i = 0; i < SIZE; i++) {
		totalReceived += (shop[i].productCount + shop[i].soldCount);  // ���� ��� + �Ǹŷ��� �� �԰�
		totalSold += shop[i].soldCount;  // �� �Ǹŷ�

		if (shop[i].soldCount > shop[max].soldCount) {
			max = i;
		}
		if (shop[i].soldCount < shop[min].soldCount) {
			min = i;
		}


	}

	if (totalReceived > 0) {
		double sellRate = (double)totalSold / totalReceived * 100.0;
		printf("\n�� �Ǹŷ�: %d (�� �Ǹ���: %.2lf%%)\n\n", totalSold, sellRate);

		printf("���� ���� �Ǹŵ� ��ǰID %d, ��ǰ�� : %s, �Ǹŷ�: %d\n", shop[max].productID, shop[max].productName, shop[max].soldCount);
		printf("���� ���� �Ǹŵ� ��ǰID %d, ��ǰ�� : %s, �Ǹŷ�: %d\n", shop[min].productID, shop[min].productName, shop[min].soldCount);
	}
	else {
		printf("\n�԰�� ��ǰ�� �����ϴ�.\n\n");
	}

}