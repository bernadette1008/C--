#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

#define UP_C 19
#define DOWN_FIRST_C 28
#define DOWN_SECOND_C 8
#define FIRST_V 21
#define SECOND_V 5

void printWord(int word[999]);

int main() {
    char c[UP_C] = { 'r','R' ,'s' ,'e' ,'E' ,'f' ,'a' ,'q' ,'Q' ,'t' ,'T' ,'d' ,'w' ,'W' ,'c' ,'z' ,'x' ,'v' ,'g' };//����
    char downc[DOWN_FIRST_C] = { '-','r','R','-','s','-','-','e','f','-','-','-','-','-','-','-','a','q','-','t','T','d','w','c','z','x','v','g' };
    char checkc[DOWN_SECOND_C] = { 'r','t','w','g','a','q','x','v' };

    char v[FIRST_V] = { 'k', 'o', 'i', 'O', 'j', 'p', 'u', 'P', 'h', '-', '-', '-', 'y', 'n', '-', '-', '-', 'b', 'm', '-', 'l' }; //����
    char checkv[SECOND_V] = { 'k','o','l','j','p' };

    char str[999];
    int word[999];

    int uv, uc;

    int goFirst = FALSE;

    int j = 0;// word[j]

    printf("������ �Է����ֽʽÿ� : ");
    scanf_s("%[^\n]", &str, sizeof(str));

    for (int i = 0; i < 999; i++) {
        if (goFirst == TRUE)
            printf("ó������ ���ƿ�\n");
        goFirst = FALSE;

        if (str[i] == ' ') {
            printf("test");
            word[j] = 32;
            i++;
            j++;
        }

        if (str[i] <= 0 && goFirst == FALSE) {
            word[j] = -1;
            printWord(word);
            system("pause");
            break;
        }

        for (int first_word = 0; first_word < UP_C; first_word++) {
            if (str[i] == c[first_word] && goFirst == FALSE) {
                printf("1 str[%d] = %c\n", i, str[i]);
                i++;//2
                for (int second_word = 0; second_word < FIRST_V; second_word++) {
                    if (str[i] == v[second_word] && goFirst == FALSE) {
                        printf("2 str[%d] = %c\n", i, str[i]);
                        i++;//3
                        //case a1 = ��
                        for (int third_word = 0; third_word < SECOND_V; third_word++) {
                            if (str[i] == checkv[third_word] && goFirst == FALSE) {//3��°�� ������
                                printf("3 str[%d] = %c\n", i, str[i]);
                                i++;//4

                                if (second_word == 8 && third_word == 0) //��
                                    uv = 9;
                                else if (second_word == 8 && third_word == 1) // ��
                                    uv = 10;
                                else if (second_word == 8 && third_word == 2) // ��
                                    uv = 11;
                                else if (second_word == 13 && third_word == 3) //��
                                    uv = 14;
                                else if (second_word == 13 && third_word == 4) //��
                                    uv = 15;
                                else if (second_word == 13 && third_word == 2) //��
                                    uv = 16;
                                else if (second_word == 18 && third_word == 2) // ��
                                    uv = 19;

                                //case b1, b2 : ��, ��
                                for (int fourth_word = 0; fourth_word < DOWN_FIRST_C; fourth_word++) {
                                    if (str[i] == downc[fourth_word] && goFirst == FALSE) {
                                        printf("4 str[%d] = %c\n", i, str[i]);
                                        i++;//5

                                        //case 1 : ��
                                        for (int fifth_word = 0; fifth_word < DOWN_SECOND_C; fifth_word++) {
                                            if (str[i] == checkc[fifth_word] && goFirst == FALSE) {//5��°�� ��ħ��
                                                printf("5(case b1 : ��) str[%d] = %c\n", i, str[i]);
                                                i++;//6
                                                for (int check = 0; check < UP_C; check++) {
                                                    if (str[i] == c[check] && goFirst == FALSE) {
                                                        printf("6(end) str[%d] = %c\n", i, str[i]);

                                                        if (fourth_word == 1 && fifth_word == 1) // ��
                                                            uc = 3;
                                                        else if (fourth_word == 4 && fifth_word == 2) // ��
                                                            uc = 5;
                                                        else if (fourth_word == 4 && fifth_word == 3) // ��
                                                            uc = 6;
                                                        else if (fourth_word == 8 && fifth_word == 0) // ��
                                                            uc = 9;
                                                        else if (fourth_word == 8 && fifth_word == 4) // ��
                                                            uc = 10;
                                                        else if (fourth_word == 8 && fifth_word == 5) // ��
                                                            uc = 11;
                                                        else if (fourth_word == 8 && fifth_word == 1) // ��
                                                            uc = 12;
                                                        else if (fourth_word == 8 && fifth_word == 6) // ��
                                                            uc = 13;
                                                        else if (fourth_word == 8 && fifth_word == 7) // ��
                                                            uc = 14;
                                                        else if (fourth_word == 8 && fifth_word == 3) // ��
                                                            uc = 15;
                                                        else if (fourth_word == 17 && fifth_word == 1) // ��
                                                            uc = 18;

                                                        i--;
                                                        goFirst = TRUE;
                                                        word[j] = 44032 + (588 * first_word) + (28 * uv) + uc;
                                                        j++;
                                                        break;
                                                    }
                                                }
                                                if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                                    if (fourth_word == 1 && fifth_word == 1) // ��
                                                        uc = 3;
                                                    else if (fourth_word == 4 && fifth_word == 2) // ��
                                                        uc = 5;
                                                    else if (fourth_word == 4 && fifth_word == 3) // ��
                                                        uc = 6;
                                                    else if (fourth_word == 8 && fifth_word == 0) // ��
                                                        uc = 9;
                                                    else if (fourth_word == 8 && fifth_word == 4) // ��
                                                        uc = 10;
                                                    else if (fourth_word == 8 && fifth_word == 5) // ��
                                                        uc = 11;
                                                    else if (fourth_word == 8 && fifth_word == 1) // ��
                                                        uc = 12;
                                                    else if (fourth_word == 8 && fifth_word == 6) // ��
                                                        uc = 13;
                                                    else if (fourth_word == 8 && fifth_word == 7) // ��
                                                        uc = 14;
                                                    else if (fourth_word == 8 && fifth_word == 3) // ��
                                                        uc = 15;
                                                    else if (fourth_word == 17 && fifth_word == 1) // ��
                                                        uc = 18;

                                                    printf("6(case b1 : ��) (end) str[%d] = %c\n", i, str[i]);
                                                    i--;
                                                    goFirst = TRUE;
                                                    word[j] = 44032 + (588 * first_word) + (28 * uv) + uc;
                                                    j++;
                                                    break;
                                                }
                                                if (goFirst == FALSE)
                                                    i--;
                                            }
                                        }


                                        //case 2 : ��
                                        for (int fifth_word = 0; fifth_word < UP_C; fifth_word++) {
                                            if (str[i] == c[fifth_word] && goFirst == FALSE) {//���ο� ������ �� ����(���ο� ������ ��� i�� 5��°�� ����)
                                                printf("5(case b2 : ��) str[%d] = %c\n", i, str[i]);
                                                i++;//6
                                                for (int check = 0; check < FIRST_V; check++) {
                                                    if (str[i] == v[check] && goFirst == FALSE) {//Ȯ���ϰ� ���ο� ������
                                                        printf("6(end) str[%d] = %c\n", i, str[i]);
                                                        i -= 2;//5
                                                        goFirst = TRUE;
                                                        word[j] = 44032 + (588 * first_word) + (28 * uv) + fourth_word;
                                                        j++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                            printf("5(case b2 : ��) (end) str[%d] = %c\n", i, str[i]);
                                            i--;
                                            goFirst = TRUE;
                                            word[j] = 44032 + (588 * first_word) + (28 * uv) + fourth_word;
                                            j++;
                                            break;
                                        }

                                        for (int fifth_word = 0; fifth_word < FIRST_V; fifth_word++) {
                                            if (str[i] == v[fifth_word]) {
                                                printf("case b3���� �̵�\n");
                                                i--;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }

                                //case b3 : ��
                                for (int fourth_word = 0; fourth_word < UP_C; fourth_word++) {
                                    if (str[i] == c[fourth_word] && goFirst == FALSE) {
                                        printf("4(case b3 : ��) str[%d] = %c\n", i, str[i]);
                                        i++;//5
                                        for (int check = 0; check < FIRST_V; check++) {
                                            if (str[i] == v[check] && goFirst == FALSE) {//���ο� ������
                                                word[j] = 44032 + (588 * first_word) + (28 * uv);
                                                j++;
                                                i -= 3;
                                                goFirst = TRUE;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                    printf("4(case 3 : ��) (end) str[%d] = %c\n", i, str[i]);
                                    i--;
                                    goFirst = TRUE;
                                    word[j] = 44032 + (588 * first_word) + (28 * uv);
                                    j++;
                                    break;
                                }
                            }
                        }

                        //case a2 = ��
                        //case b1, b2 = ��, ��
                        for (int third_word = 0; third_word < DOWN_FIRST_C; third_word++) {
                            if (str[i] == downc[third_word] && goFirst == FALSE) {
                                printf("3 str[%d] = %c\n", i, str[i]);
                                i++;//4
                                //case b1 = ��
                                for (int fourth_word = 0; fourth_word < DOWN_SECOND_C; fourth_word++) {
                                    if (str[i] == checkc[fourth_word] && goFirst == FALSE) {
                                        printf("4 (case b1 = ��) str[%d] = %c\n", i, str[i]);
                                        i++;

                                        if (third_word == 1 && fourth_word == 1) // ��
                                            uc = 3;
                                        else if (third_word == 4 && fourth_word == 2) // ��
                                            uc = 5;
                                        else if (third_word == 4 && fourth_word == 3) // ��
                                            uc = 6;
                                        else if (third_word == 8 && fourth_word == 0) // ��
                                            uc = 9;
                                        else if (third_word == 8 && fourth_word == 4) // ��
                                            uc = 10;
                                        else if (third_word == 8 && fourth_word == 5) // ��
                                            uc = 11;
                                        else if (third_word == 8 && fourth_word == 1) // ��
                                            uc = 12;
                                        else if (third_word == 8 && fourth_word == 6) // ��
                                            uc = 13;
                                        else if (third_word == 8 && fourth_word == 7) // ��
                                            uc = 14;
                                        else if (third_word == 8 && fourth_word == 3) // ��
                                            uc = 15;
                                        else if (third_word == 17 && fourth_word == 1) // ��
                                            uc = 18;

                                        for (int check = 0; check < UP_C; check++) {
                                            if (str[i] == c[check] && goFirst == FALSE) {
                                                printf("5 (end) str[%d] = %c\n", i, str[i]);
                                                goFirst = TRUE;
                                                word[j] = 44032 + (588 * first_word) + (28 * second_word) + uc;
                                                j++;
                                                i -= 1;
                                                break;
                                            }
                                        }
                                        if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                            printf("5 (end) str[%d] = %c\n", i, str[i]);
                                            goFirst = TRUE;
                                            word[j] = 44032 + (588 * first_word) + (28 * second_word) + uc;
                                            j++;
                                            i--;
                                            break;
                                        }
                                        if (goFirst == FALSE)
                                            i--;
                                    }
                                }
                                //case b2 = ��
                                for (int fourth_word = 0; fourth_word < UP_C; fourth_word++) {
                                    if (str[i] == c[fourth_word] && goFirst == FALSE) {
                                        printf("4 (case b2 = ��) str[%d] = %c\n", i, str[i]);
                                        i++;
                                        for (int check = 0; check < FIRST_V; check++) {
                                            if (str[i] == v[check] && goFirst == FALSE) {//���ο� ������
                                                printf("5 (end) str[%d] = %c\n", i, str[i]);
                                                i -= 2;
                                                word[j] = 44032 + (588 * first_word) + (28 * second_word) + third_word;
                                                j++;
                                                goFirst = TRUE;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                    printf("4 (case b2 = ��) (end) str[%d] = %c\n", i, str[i]);
                                    i--;
                                    word[j] = 44032 + (588 * first_word) + (28 * second_word) + third_word;
                                    j++;
                                    goFirst = TRUE;
                                    break;
                                }
                                if (goFirst == FALSE)
                                    i--;
                            }
                        }
                        //case b3 = ��
                        for (int third_word = 0; third_word < UP_C; third_word++) {
                            if (str[i] == c[third_word] && goFirst == FALSE) {
                                printf("3 (case b3 = ��) str[%d] = %c\n", i, str[i]);
                                i++;
                                for (int check = 0; check < FIRST_V; check++) {
                                    i -= 3;
                                    word[j] = 44032 + (588 * first_word) + (28 * second_word);
                                    j++;
                                    goFirst = TRUE;
                                    break;
                                }
                            }
                        }
                        if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                            i--;
                            word[j] = 44032 + (588 * first_word) + (28 * second_word);
                            j++;
                            goFirst = TRUE;
                            break;
                        }
                    }
                }
            }
        }

    }

}

void printWord(int word[999]) {
    _wsetlocale(LC_ALL, L"korean"); // �ѱ� �ƽ�Ű�ڵ� ���

    printf("�Է��� ����\n->");
    for (int i = 0; word[i] != -1; i++) {
        wprintf(L"%c", word[i]);
    }
    printf("\n");
}