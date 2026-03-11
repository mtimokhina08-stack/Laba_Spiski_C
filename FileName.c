#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define MAX_WORD 20
#define MAX_SENTENCE 30

int is_latin_letter(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    return 0;
}

int compare_words(char word1[], char word2[], int len1, int len2) {
    if (len1 != len2) return 0;
    for (int i = 0; i < len1; i++) {
        if (word1[i] != word2[i]) return 0;
    }
    return 1;
}

int main() {
    setlocale(0, "");
    char P[MAX_WORD];
    char current_word[MAX_WORD];
    char ch;
    int P_length = 0, count_matches = 0, word_count = 0, i;
    int word_too_long = 0;

    printf("Введите слово P (только латинские буквы, длина <= %d):\n", MAX_WORD);

    scanf("%c", &ch);
    while (ch == ' ') {
        scanf("%c", &ch);
    }

    while (ch != ' ' && ch != '\n') {
        if (P_length >= MAX_WORD) {
            word_too_long = 1;
        }
        else {
            if (!is_latin_letter(ch)) {
                printf("Ошибка: слово P содержит недопустимый символ '%c'\n", ch);
                return 1;
            }
            P[P_length] = ch;
            P_length++;
        }
        scanf("%c", &ch);
    }

    if (word_too_long) {
        printf("Ошибка: длина слова P превышает %d символов\n", MAX_WORD);
        return 1;
    }

    if (P_length == 0) {
        printf("Ошибка: слово P не может быть пустым\n");
        return 1;
    }

    printf("Введите предложение (только латинские буквы и пробелы, заканчивается . ! или ?):\n");

    scanf("%c", &ch);
    while (ch == ' ') {
        scanf("%c", &ch);
    }

    while (1) {
        if (ch == '.' || ch == '!' || ch == '?') {
            break;
        }

        if (ch == '\n' || ch == ',') {
            printf("Ошибка: предложение должно заканчиваться . ! или ?\n");
            return 1;
        }

        if (word_count >= MAX_SENTENCE) {
            printf("Ошибка: превышено максимальное количество слов (%d)\n", MAX_SENTENCE);
            return 1;
        }

        int word_len = 0;
        word_too_long = 0;

        while (ch != ' ' && ch != '.' && ch != '!' && ch != '?') {
            if (word_len >= MAX_WORD) {
                word_too_long = 1;
            }
            else {
                if (!is_latin_letter(ch)) {
                    printf("Ошибка: слово содержит недопустимый символ '%c'\n", ch);
                    return 1;
                }
                current_word[word_len] = ch;
                word_len++;
            }
            scanf("%c", &ch);
        }

        if (word_too_long) {
            printf("Ошибка: длина слова превышает %d символов\n", MAX_WORD);
            return 1;
        }

        if (word_len == 0) {
            printf("Ошибка: обнаружено пустое слово\n");
            return 1;
        }

        word_count++;

        if (compare_words(P, current_word, P_length, word_len)) {
            count_matches++;
        }

        while (ch == ' ') {
            scanf("%c", &ch);
        }

        if (ch == '.' || ch == '!' || ch == '?') {
            break;
        }
    }

    if (word_count == 0) {
        printf("Ошибка: предложение не содержит слов\n");
        return 1;
    }

    if (count_matches >= 2) {
        printf("Слово \"");
        for (i = 0; i < P_length; i++) {
            printf("%c", P[i]);
        }
        printf("\" встречается в предложении не менее двух раз (%d раз)\n", count_matches);
    }
    else {
        printf("Слово \"");
        for (i = 0; i < P_length; i++) {
            printf("%c", P[i]);
        }
        printf("\" встречается в предложении менее двух раз (%d раз)\n", count_matches);
    }

    return 0;
}