#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TABUNG 10
#define MAX_BOLA 30

bool zero(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return true;
        }
        num /= 10;
    }
    return false;
}

//fungsi sorting descending
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int bola[MAX_BOLA], tabung1[MAX_TABUNG], tabung2[MAX_TABUNG];
    int count1 = 0, count2 = 0, sum1 = 0, sum2 = 0;

    printf("Masukkan 30 bola: \n");
    for (int i = 0; i < MAX_BOLA; i++) {
        scanf("%d", &bola[i]);
    }

    for (int i = 0; i < MAX_BOLA; i++) {
        if (zero(bola[i])) {
            continue;
        }
        if (bola[i] % 2 == 1 && count1 < MAX_TABUNG) {
            tabung1[count1++] = bola[i];
            sum1 += bola[i];
        } else if (bola[i] % 2 == 0 && count2 < MAX_TABUNG) {
            tabung2[count2++] = bola[i];
            sum2 += bola[i];
        }
    }

    // fungsi urut dari terbesar ke terkecil
    qsort(tabung1, count1, sizeof(int), compare);
    qsort(tabung2, count2, sizeof(int), compare);

    //pengelompokkan ganjil & genap
    printf("=========================================================================================\n");
    printf("Tabung 1 : ");
    for (int i = 0; i < count1; i++) {
        printf("%d ", tabung1[i]);
    }
    printf("\n");

    printf("Tabung 2 : ");
    for (int i = 0; i < count2; i++) {
        printf("%d ", tabung2[i]);
    }
    printf("\n");
    printf("=========================================================================================\n");

    printf("Jumlah nomor bola pada tabung 1 = %d\n", sum1);
    printf("Jumlah nomor bola pada tabung 2 = %d\n", sum2);

    return 0;
}
