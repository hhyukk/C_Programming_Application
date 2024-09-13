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
    int n;  // 상품 종류의 개수
    printf("상품 개수(종류)를 입력하세요: ");
    scanf("%d", &n);

    int* stock = (int*)malloc(n * sizeof(int));  // 입고 수량
    int* sales = (int*)malloc(n * sizeof(int));  // 판매 수량
    int* remainingStock = (int*)malloc(n * sizeof(int));  // 남은 재고 수량

    if (stock == NULL || sales == NULL || remainingStock == NULL) {
        printf("메모리 할당 실패\n");
        return 0;
    }

    input(stock, sales, n);
    calStock(stock, sales, remainingStock, n);
    printStock(remainingStock, n);

    int totalSales = calTotalSales(sales, n);
    printf("총 판매량: %d", totalSales);

    calSalesRateAndPrint(stock, sales, totalSales, n);
    maxAndMinSalesPrint(sales, n);
    warning(remainingStock, n);

    free(stock);
    free(sales);
    free(remainingStock);

    return 0;
}

// 상품 입고 및 판매 수량 입력
void input(int* stock, int* sales, int n) {
    printf("상품 별 입고 수량을 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    printf("상품 별 판매 수량을 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }
}

// 남은 재고 계산
void calStock(int* stock, int* sales, int* remainingStock, int n) {
    for (int i = 0; i < n; i++) {
        remainingStock[i] = stock[i] - sales[i];
    }
}

// 남은 재고 출력
void printStock(int* remainingStock, int n) {
    printf("\n\n재고 수량:");
    for (int i = 0; i < n; i++) {
        printf("%d ", remainingStock[i]);
    }
    printf("\n");

}

// 전체 판매량 계산
int calTotalSales(int* sales, int n) {
    int totalSales = 0;
    for (int i = 0; i < n; i++) {
        totalSales += sales[i];
    }
    return totalSales;
}

// 판매율 계산 및 출력
void calSalesRateAndPrint(int* stock, int* sales, int totalSales, int n) {
    int totalStock = 0;
    double percent = 0;
    for (int i = 0; i < n; i++)
    {
        totalStock += stock[i];
    }
    percent = ((double)totalSales / (double)totalStock) * 100;
    printf(" (판매율 %.2lf%%)\n", percent);

}

// 최대 및 최소 판매량 상품 출력
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
    printf("최대 판매량 상품: ID %d, 판매량 %d\n", maxId, maxSales);
    printf("최소 판매량 상품: ID %d, 판매량 %d\n", minId, minSales);
}

// 재고 부족 경고 출력
void warning(int* remainingStock, int n) {
    for (int i = 0; i < n; i++) {
        if (remainingStock[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, remainingStock[i]);
        }
    }
}
