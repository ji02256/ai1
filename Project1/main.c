#include <stdio.h>

int main() {
    int row = 0;
    int col;

    while (row < 5) {
        col = 0;
        while (col < 5) {
            // 테두리 위치일 때만 '*'
            if (row == 0 || row == 4 || col == 0 || col == 4)
                printf("*");
            else
                printf(" ");
            col++;
        }
        printf("\n");
        row++;
    }
    dsfa
    return 0;
}

