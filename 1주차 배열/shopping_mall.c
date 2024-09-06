#include <stdio.h>
#include <stdlib.h>

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

    printf("��ǰ �� �԰� ������ �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    printf("��ǰ �� �Ǹ� ������ �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    for (int i = 0; i < n; i++) {
        remainingStock[i] = stock[i] - sales[i];
    }

    int id;  // ��ȸ�� ��ǰ�� ID
    printf("ID�� �Է��ϼ���: ");
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
