#include <stdio.h>
#include <stdlib.h>

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

    printf("상품 별 입고 수량을 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    printf("상품 별 판매 수량을 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    for (int i = 0; i < n; i++) {
        remainingStock[i] = stock[i] - sales[i];
    }

    int id;  // 조회할 상품의 ID
    printf("ID를 입력하세요: ");
    scanf("%d", &id);

    printf("%d\n", remainingStock[id - 1]);

    for (int i = 0; i < n; i++) {
        printf("%d ", remainingStock[i]);
    }
    printf("\n");

    free(stock);
    free(sales);
    free(remainingStock);

    return 0;
}
