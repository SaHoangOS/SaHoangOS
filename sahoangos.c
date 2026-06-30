#include <stdio.h>

int main() {
    int chon;

    printf("=================================\n");
    printf("       SaHoangOS 2.0\n");
    printf("  Lam chu thiet bi cua ban.\n");
    printf("=================================\n\n");

    printf("1. About\n");
    printf("2. Version\n");
    printf("3. Calculator\n");
    printf("4. Logo\n");
    printf("5. Exit\n\n");

    printf("Chon: ");
    scanf("%d", &chon);

    switch(chon) {
        case 1:
            printf("\n=== ABOUT ===\n");
            printf("Developer: Nguyen Quoc Dai\n");
            printf("Project: SaHoangOS\n");
            break;

        case 2:
            printf("\nSaHoangOS Version 2.0 Alpha\n");
            break;

        case 3: {
            int a, b;
            printf("\nNhap so thu nhat: ");
            scanf("%d", &a);
            printf("Nhap so thu hai: ");
            scanf("%d", &b);
            printf("Tong = %d\n", a + b);
            break;
        }

        case 4:
            printf("\n");
            printf("  *****   *****\n");
            printf(" *     * *     *\n");
            printf(" * SaHoangOS  *\n");
            printf(" *     * *     *\n");
            printf("  *****   *****\n");
            break;

        case 5:
            printf("\nTam biet!\n");
            break;

        default:
            printf("\nLua chon khong hop le!\n");
    }

    return 0;
}
