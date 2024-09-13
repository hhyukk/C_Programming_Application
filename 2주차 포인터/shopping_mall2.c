#include <stdio.h>
#include <stdlib.h>

void input(int* stock, int* sales, int n);
void calStock(int* stock, int* sales, int* remainingStock, int n);
void printStock(int* remainingStock, int n);
int calTotalSales(int* sales, int n);
void calSalesRateAndPrint(int* stock, int* sales, int totalSales, int n);
void maxAndMinSalesPrint(int* sales, int n);
void warning(int* remainingStock, int n);

int main() {
    int n;  // ��ǰ ������ ����
    printf("��ǰ ����(����)�� �Է��ϼ���: ");
    scanf("%d", &n);

    int* stock = (int*)malloc(n * sizeof(int));  // �԰� ����
    int* sales = (int*)malloc(n * sizeof(int));  // �Ǹ� ����
    int* remainingStock = (int*)malloc(n * sizeof(int));  // ���� ��� ����

    if (stock == NULL || sales == NULL || remainingStock == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 0;
    }

    input(stock, sales, n);
    calStock(stock, sales, remainingStock, n);
    printStock(remainingStock, n);

    int totalSales = calTotalSales(sales, n);
    printf("�� �Ǹŷ�: %d", totalSales);

    calSalesRateAndPrint(stock, sales, totalSales, n);
    maxAndMinSalesPrint(sales, n);
    warning(remainingStock, n);

    free(stock);
    free(sales);
    free(remainingStock);

    return 0;
}

// ��ǰ �԰� �� �Ǹ� ���� �Է�
void input(int* stock, int* sales, int n) {
    printf("��ǰ �� �԰� ������ �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    printf("��ǰ �� �Ǹ� ������ �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }
}

// ���� ��� ���
void calStock(int* stock, int* sales, int* remainingStock, int n) {
    for (int i = 0; i < n; i++) {
        remainingStock[i] = stock[i] - sales[i];
    }
}

// ���� ��� ���
void printStock(int* remainingStock, int n) {
    printf("\n\n��� ����:");
    for (int i = 0; i < n; i++) {
        printf("%d ", remainingStock[i]);
    }
    printf("\n");

}

// ��ü �Ǹŷ� ���
int calTotalSales(int* sales, int n) {
    int totalSales = 0;
    for (int i = 0; i < n; i++) {
        totalSales += sales[i];
    }
    return totalSales;
}

// �Ǹ��� ��� �� ���
void calSalesRateAndPrint(int* stock, int* sales, int totalSales, int n) {
    int totalStock = 0;
    double percent = 0;
    for (int i = 0; i < n; i++)
    {
        totalStock += stock[i];
    }
    percent = ((double)totalSales / (double)totalStock) * 100;
    printf(" (�Ǹ��� %.2lf%%)\n", percent);

}

// �ִ� �� �ּ� �Ǹŷ� ��ǰ ���
void maxAndMinSalesPrint(int* sales, int n) {
    int maxSales = sales[0], minSales = sales[0];
    int maxId = 1, minId = 1;
    for (int i = 1; i < n; i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxId = i + 1;
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minId = i + 1;
        }
    }
    printf("�ִ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxId, maxSales);
    printf("�ּ� �Ǹŷ� ��ǰ: ID %d, �Ǹŷ� %d\n", minId, minSales);
}

// ��� ���� ��� ���
void warning(int* remainingStock, int n) {
    for (int i = 0; i < n; i++) {
        if (remainingStock[i] <= 2) {
            printf("��ǰ ID %d : ������(%d)\n", i + 1, remainingStock[i]);
        }
    }
}
