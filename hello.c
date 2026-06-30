#include <stdio.h>
#include <string.h>

int main() {
    char cmd[50];

    printf("=================================\n");
    printf("       SaHoangOS 1.0 Alpha\n");
    printf("   Lam chu thiet bi cua ban.\n");
    printf("=================================\n\n");

    printf("Nhap lenh: ");
    scanf("%49s", cmd);

    if (strcmp(cmd, "about") == 0) {
        printf("\nDeveloper: Nguyen Quoc Dai\n");
        printf("Version: 1.0 Alpha\n");

    } else if (strcmp(cmd, "help") == 0) {
        printf("\nDanh sach lenh:\n");
        printf("about   - Thong tin he dieu hanh\n");
        printf("help    - Hien thi tro giup\n");
        printf("version - Xem phien ban\n");
        printf("logo    - Hien thi logo\n");
        printf("exit    - Thoat\n");

    } else if (strcmp(cmd, "version") == 0) {
        printf("\nSaHoangOS Version 1.0 Alpha\n");

    } else if (strcmp(cmd, "logo") == 0) {
        printf("\n");
        printf("  *****   *****\n");
        printf(" *     * *     *\n");
        printf(" * SaHoangOS  *\n");
        printf(" *     * *     *\n");
        printf("  *****   *****\n");

    } else if (strcmp(cmd, "exit") == 0) {
        printf("\nTam biet!\n");

    } else {
        printf("\nLenh khong ton tai!\n");
    }

    return 0;
}
