#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int** a; // ��������� �� ������
    int** b;
    int i, j, n, m, c;
    int count = 0;
    int iz = 0;
    int konc = 0;
    int dom = 0;
    system("chcp 1251");
    system("cls");
    printf("������� ���������� �����: ");
    scanf("%d", &n);

    // ��������� ������
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    // ���� ��������� �������

    srand(time(NULL));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i != j ) {
                a[i][j] = rand() % 100;
                if (a[i][j] < 80) {
                    a[i][j] = 0;
                }
                a[j][i] = a[i][j];
            }
            else a[i][j] = 0; // 
        }
    printf("M1:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)

            printf("%3d", a[i][j]);
        printf("\n");
    };

    printf("\n");
    printf("������� 2:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                count += 1;
            }
        }
    }
    count = count / 2;
    printf("������ �����: %d", count);
    printf("\n");
    printf("������� 3:\n");
    for (i = 0; i < n; i++) {
        c = 0;
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                c += 1;
            }
        }
        if (c == 0) {
            iz += 1;
        }
        if (c == 1) {
            konc += 1;
        }
        if (c == (n - 1)) {
            dom += 1;
        }
    }
    printf("��������: %d\n", konc);
    printf("�������������: %d\n", iz);
    printf("������������: %d\n", dom);
    free(a);

}