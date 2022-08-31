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
    char c[UP_C] = { 'r','R' ,'s' ,'e' ,'E' ,'f' ,'a' ,'q' ,'Q' ,'t' ,'T' ,'d' ,'w' ,'W' ,'c' ,'z' ,'x' ,'v' ,'g' };//자음
    char downc[DOWN_FIRST_C] = { '-','r','R','-','s','-','-','e','f','-','-','-','-','-','-','-','a','q','-','t','T','d','w','c','z','x','v','g' };
    char checkc[DOWN_SECOND_C] = { 'r','t','w','g','a','q','x','v' };

    char v[FIRST_V] = { 'k', 'o', 'i', 'O', 'j', 'p', 'u', 'P', 'h', '-', '-', '-', 'y', 'n', '-', '-', '-', 'b', 'm', '-', 'l' }; //모음
    char checkv[SECOND_V] = { 'k','o','l','j','p' };

    char str[999];
    int word[999];

    int uv, uc;

    int goFirst = FALSE;

    int j = 0;// word[j]

    printf("문장을 입력해주십시오 : ");
    scanf_s("%[^\n]", &str, sizeof(str));

    for (int i = 0; i < 999; i++) {
        if (goFirst == TRUE)
            printf("처음으로 돌아옴\n");
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
                        //case a1 = ㅘ
                        for (int third_word = 0; third_word < SECOND_V; third_word++) {
                            if (str[i] == checkv[third_word] && goFirst == FALSE) {//3번째도 모음임
                                printf("3 str[%d] = %c\n", i, str[i]);
                                i++;//4

                                if (second_word == 8 && third_word == 0) //ㅘ
                                    uv = 9;
                                else if (second_word == 8 && third_word == 1) // ㅙ
                                    uv = 10;
                                else if (second_word == 8 && third_word == 2) // ㅚ
                                    uv = 11;
                                else if (second_word == 13 && third_word == 3) //ㅝ
                                    uv = 14;
                                else if (second_word == 13 && third_word == 4) //ㅞ
                                    uv = 15;
                                else if (second_word == 13 && third_word == 2) //ㅟ
                                    uv = 16;
                                else if (second_word == 18 && third_word == 2) // ㅢ
                                    uv = 19;

                                //case b1, b2 : 괅, 괄
                                for (int fourth_word = 0; fourth_word < DOWN_FIRST_C; fourth_word++) {
                                    if (str[i] == downc[fourth_word] && goFirst == FALSE) {
                                        printf("4 str[%d] = %c\n", i, str[i]);
                                        i++;//5

                                        //case 1 : 괅
                                        for (int fifth_word = 0; fifth_word < DOWN_SECOND_C; fifth_word++) {
                                            if (str[i] == checkc[fifth_word] && goFirst == FALSE) {//5번째가 받침임
                                                printf("5(case b1 : 괅) str[%d] = %c\n", i, str[i]);
                                                i++;//6
                                                for (int check = 0; check < UP_C; check++) {
                                                    if (str[i] == c[check] && goFirst == FALSE) {
                                                        printf("6(end) str[%d] = %c\n", i, str[i]);

                                                        if (fourth_word == 1 && fifth_word == 1) // ㄳ
                                                            uc = 3;
                                                        else if (fourth_word == 4 && fifth_word == 2) // ㄵ
                                                            uc = 5;
                                                        else if (fourth_word == 4 && fifth_word == 3) // ㄶ
                                                            uc = 6;
                                                        else if (fourth_word == 8 && fifth_word == 0) // ㄺ
                                                            uc = 9;
                                                        else if (fourth_word == 8 && fifth_word == 4) // ㄻ
                                                            uc = 10;
                                                        else if (fourth_word == 8 && fifth_word == 5) // ㄼ
                                                            uc = 11;
                                                        else if (fourth_word == 8 && fifth_word == 1) // ㄽ
                                                            uc = 12;
                                                        else if (fourth_word == 8 && fifth_word == 6) // ㄾ
                                                            uc = 13;
                                                        else if (fourth_word == 8 && fifth_word == 7) // ㄿ
                                                            uc = 14;
                                                        else if (fourth_word == 8 && fifth_word == 3) // ㅀ
                                                            uc = 15;
                                                        else if (fourth_word == 17 && fifth_word == 1) // ㅄ
                                                            uc = 18;

                                                        i--;
                                                        goFirst = TRUE;
                                                        word[j] = 44032 + (588 * first_word) + (28 * uv) + uc;
                                                        j++;
                                                        break;
                                                    }
                                                }
                                                if (str[i] == ' ' || str[i] <= 0 && goFirst == FALSE) {
                                                    if (fourth_word == 1 && fifth_word == 1) // ㄳ
                                                        uc = 3;
                                                    else if (fourth_word == 4 && fifth_word == 2) // ㄵ
                                                        uc = 5;
                                                    else if (fourth_word == 4 && fifth_word == 3) // ㄶ
                                                        uc = 6;
                                                    else if (fourth_word == 8 && fifth_word == 0) // ㄺ
                                                        uc = 9;
                                                    else if (fourth_word == 8 && fifth_word == 4) // ㄻ
                                                        uc = 10;
                                                    else if (fourth_word == 8 && fifth_word == 5) // ㄼ
                                                        uc = 11;
                                                    else if (fourth_word == 8 && fifth_word == 1) // ㄽ
                                                        uc = 12;
                                                    else if (fourth_word == 8 && fifth_word == 6) // ㄾ
                                                        uc = 13;
                                                    else if (fourth_word == 8 && fifth_word == 7) // ㄿ
                                                        uc = 14;
                                                    else if (fourth_word == 8 && fifth_word == 3) // ㅀ
                                                        uc = 15;
                                                    else if (fourth_word == 17 && fifth_word == 1) // ㅄ
                                                        uc = 18;

                                                    printf("6(case b1 : 괅) (end) str[%d] = %c\n", i, str[i]);
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


                                        //case 2 : 괄
                                        for (int fifth_word = 0; fifth_word < UP_C; fifth_word++) {
                                            if (str[i] == c[fifth_word] && goFirst == FALSE) {//새로운 문자일 수 있음(새로운 문자일 경우 i는 5번째일 때로)
                                                printf("5(case b2 : 괄) str[%d] = %c\n", i, str[i]);
                                                i++;//6
                                                for (int check = 0; check < FIRST_V; check++) {
                                                    if (str[i] == v[check] && goFirst == FALSE) {//확실하게 새로운 문자임
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
                                            printf("5(case b2 : 괄) (end) str[%d] = %c\n", i, str[i]);
                                            i--;
                                            goFirst = TRUE;
                                            word[j] = 44032 + (588 * first_word) + (28 * uv) + fourth_word;
                                            j++;
                                            break;
                                        }

                                        for (int fifth_word = 0; fifth_word < FIRST_V; fifth_word++) {
                                            if (str[i] == v[fifth_word]) {
                                                printf("case b3으로 이동\n");
                                                i--;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }

                                //case b3 : 과
                                for (int fourth_word = 0; fourth_word < UP_C; fourth_word++) {
                                    if (str[i] == c[fourth_word] && goFirst == FALSE) {
                                        printf("4(case b3 : 과) str[%d] = %c\n", i, str[i]);
                                        i++;//5
                                        for (int check = 0; check < FIRST_V; check++) {
                                            if (str[i] == v[check] && goFirst == FALSE) {//새로운 문자임
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
                                    printf("4(case 3 : 과) (end) str[%d] = %c\n", i, str[i]);
                                    i--;
                                    goFirst = TRUE;
                                    word[j] = 44032 + (588 * first_word) + (28 * uv);
                                    j++;
                                    break;
                                }
                            }
                        }

                        //case a2 = ㅏ
                        //case b1, b2 = 갉, 갈
                        for (int third_word = 0; third_word < DOWN_FIRST_C; third_word++) {
                            if (str[i] == downc[third_word] && goFirst == FALSE) {
                                printf("3 str[%d] = %c\n", i, str[i]);
                                i++;//4
                                //case b1 = 갉
                                for (int fourth_word = 0; fourth_word < DOWN_SECOND_C; fourth_word++) {
                                    if (str[i] == checkc[fourth_word] && goFirst == FALSE) {
                                        printf("4 (case b1 = 갉) str[%d] = %c\n", i, str[i]);
                                        i++;

                                        if (third_word == 1 && fourth_word == 1) // ㄳ
                                            uc = 3;
                                        else if (third_word == 4 && fourth_word == 2) // ㄵ
                                            uc = 5;
                                        else if (third_word == 4 && fourth_word == 3) // ㄶ
                                            uc = 6;
                                        else if (third_word == 8 && fourth_word == 0) // ㄺ
                                            uc = 9;
                                        else if (third_word == 8 && fourth_word == 4) // ㄻ
                                            uc = 10;
                                        else if (third_word == 8 && fourth_word == 5) // ㄼ
                                            uc = 11;
                                        else if (third_word == 8 && fourth_word == 1) // ㄽ
                                            uc = 12;
                                        else if (third_word == 8 && fourth_word == 6) // ㄾ
                                            uc = 13;
                                        else if (third_word == 8 && fourth_word == 7) // ㄿ
                                            uc = 14;
                                        else if (third_word == 8 && fourth_word == 3) // ㅀ
                                            uc = 15;
                                        else if (third_word == 17 && fourth_word == 1) // ㅄ
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
                                //case b2 = 갈
                                for (int fourth_word = 0; fourth_word < UP_C; fourth_word++) {
                                    if (str[i] == c[fourth_word] && goFirst == FALSE) {
                                        printf("4 (case b2 = 갈) str[%d] = %c\n", i, str[i]);
                                        i++;
                                        for (int check = 0; check < FIRST_V; check++) {
                                            if (str[i] == v[check] && goFirst == FALSE) {//새로운 문자임
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
                                    printf("4 (case b2 = 갈) (end) str[%d] = %c\n", i, str[i]);
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
                        //case b3 = 가
                        for (int third_word = 0; third_word < UP_C; third_word++) {
                            if (str[i] == c[third_word] && goFirst == FALSE) {
                                printf("3 (case b3 = 가) str[%d] = %c\n", i, str[i]);
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
    _wsetlocale(LC_ALL, L"korean"); // 한글 아스키코드 사용

    printf("입력한 문장\n->");
    for (int i = 0; word[i] != -1; i++) {
        wprintf(L"%c", word[i]);
    }
    printf("\n");
}