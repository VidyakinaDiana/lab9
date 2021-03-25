#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float mnog1[10], mnog2[10], koef[10];
    for (int i = 0; i < 10; i++) {
        mnog1[i] = 0;
        mnog2[i] = 0;
        koef[i] = 0;
    }
    int st1, st2;  //������� �����������
    printf("Enter degree of first mnogochlen: ");
    if (scanf("%d", &st1) == 0)
        return -1;
    printf("Enter degree of second mnogochlen: ");
    if (scanf("%d", &st2) == 0)
        return -1;
    if (st1 == 0 || st2 == 0) {
        printf("Degrees don't coincide");
        return -1;
    }
    for (int i = st1; i >= 0; i--) {     // ������� ����������� 1��� ����������
        printf("Enter factor for first mnogochlen x^%d = ", i);
        if (scanf("%f", &mnog1[i]) == 0)
            return -1;
    }
    for (int i = st2; i >= 0; i--) {         //������� 2���
        printf("Enter factor for second mnogochlen x^%d = ", i);
        if (scanf("%f", &mnog2[i]) == 0)
            return -1;
    }
    int f = st1 - st2;   // ������ ������� �������� ��� ��������� ����� ���� � �������
    int r = f;
    if (st2 > st1) {
        printf("Result of division = 0, Koef ostatka = ");  // ������� ������ mnog2[] (�������), ���� ��������� ������� 0
        for (int i = st1; i >= 0; i--) {
            printf("%f ", mnog1[i]);
        }
    }
    else
    {
        for (;;)
        {   
            float x  = mnog1[st1] / mnog2[st2]; // �������
            int r2 = st2;
            koef[r] = x;
            r--;
            for (int i = st1; i >= (st1 - st2); i--) {
                mnog1[i] = mnog1[i] - x * mnog2[r2];    //�������
                r2--;
            }
            st1--;
            if (st1 < st2)
                break;
        }
        printf("Koef chastnogo = ");
        for (int i = f; i >= 0; i--) {
            printf("%f", koef[i]);
        };  // �������
        printf("\nKoef ostatka = ");
        for (int i = st1; i >= 0; i--) {
            printf("%f ", mnog1[i]);
        };   // �������
    }
    return 0;
}