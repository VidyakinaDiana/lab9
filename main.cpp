#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mod(int* mas, int k) {
    for (int i = k; i >= 0; i--) {
        mas[i] = mas[i] % 2;
        if (i < 0)
            break;
    }
    return 0;
}
int main()
{
    int mnog1[10], mnog2[10], koef[10];
    for (int i = 0; i < 10; i++) {
        mnog1[i] = 0;
        mnog2[i] = 0;
        koef[i] = 0;
    }
    int st1, st2;  //������� �����������
    printf("Enter degree of first multinomial: ");
    if (scanf("%d", &st1) == 0)
        return -1;
    printf("Enter degree of second multinomial: ");
    if (scanf("%d", &st2) == 0)
        return -1;
    if (st1 == 0 || st2 == 0) {
        printf("Degrees don't coincide");
        return -1;
    }
    for (int i = st1; i >= 0; i--) {     // ������� ����������� 1��� ����������
        printf("Enter factor for first multinomial x^%d = ", i);
        if (scanf("%d", &mnog1[i]) == 0)
            return -1;
    }
    for (int i = st2; i >= 0; i--) {         //������� 2���
        printf("Enter factor for second multinomial x^%d = ", i);
        if (scanf("%d", &mnog2[i]) == 0)
            return -1;
    }
    mod(mnog1,st1);
    mod(mnog2,st2);
    int f = st1 - st2;   // ������ ������� �������� ��� ��������� ����� ���� � �������
    int r = st1;
    if (st2 > st1) {
        printf("Result of division = 0, Koef ostatka = ");  // ������� ������ mnog2[] (�������), ���� ��������� ������� 0
        for (int i = st1; i >= 0; i--) {
            printf("%d ", mnog1[i]);
        }
    }
    else
    {
        for (;;)
        {   
            int x  = mnog1[st1] & mnog2[st2]; // �������
            int r2 = st2;
            koef[r] = x;
            r--;
            for (int i = st1; i >= (st1 - st2); i--) {
                mnog1[i] = abs(mnog1[i] - mnog2[r2]);    //�������
                r2--;
            }
            st1--;
            if (st1 <= st2)
                break;
        }
        printf("Koef chastnogo = ");
        for (int i = f; i >= 0; i--) {
            printf("%d ", koef[i]);
        };  // �������
        printf("\nKoef ostatka = ");
        for (int i = st1; i >= 0; i--) {
            printf("%d ", mnog1[i]);
        };   // �������
    }
    return 0;
}