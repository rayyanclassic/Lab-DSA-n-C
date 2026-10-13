
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char ch) {
    ch = tolower((unsigned char)ch);
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

// 1. Reverse only vowels
void reverse_vowels(char str[]) {
    int start = 0;
    int end = (int)strlen(str) - 1;

    while (start < end) {
        while (start < end && !is_vowel(str[start]))
            start++;

        while (start < end && !is_vowel(str[end]))
            end--;

        if (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;

            start++;
            end--;
        }
    }

    printf("String after reversing vowels: %s\n", str);
}

// 2 and 6. Find longest consecutive vowel/consonant sequence
void longest_sequence(char str[], int want_vowels) {
    int i, current = 0, longest = 0;
    int current_start = 0, best_start = 0;
    int n = (int)strlen(str);

    for (i = 0; i < n; i++) {
        int letter = isalpha((unsigned char)str[i]);
        int match = 0;

        if (letter) {
            match = want_vowels
                    ? is_vowel(str[i])
                    : !is_vowel(str[i]);
        }

        if (match) {
            if (current == 0)
                current_start = i;

            current++;

            if (current > longest) {
                longest = current;
                best_start = current_start;
            }
        } else {
            current = 0;
        }
    }

    if (longest == 0) {
        printf("No matching sequence found.\n");
    } else {
        printf("Longest sequence: ");
        for (i = best_start; i < best_start + longest; i++)
            putchar(str[i]);

        printf("\nLength: %d\n", longest);
    }
}

// 3 and 7. Find most frequent vowel/consonant
void most_frequent(char str[], int want_vowels) {
    int freq[26] = {0};
    int i, max = 0;

    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (!isalpha(ch))
            continue;

        char lower = (char)tolower(ch);

        if (want_vowels ? is_vowel(lower) : !is_vowel(lower))
            freq[lower - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] > max)
            max = freq[i];
    }

    if (max == 0) {
        printf("No matching letters found.\n");
        return;
    }

    printf("Most frequent %s(s): ",
           want_vowels ? "vowel" : "consonant");

    for (i = 0; i < 26; i++) {
        if (freq[i] == max)
            printf("%c ", 'a' + i);
    }

    printf("\nFrequency: %d\n", max);
}

// 4. Display vowel/consonant pattern
void display_pattern(char str[]) {
    int i;

    printf("Vowel/consonant pattern: ");

    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (!isalpha(ch))
            putchar(str[i]);
        else if (is_vowel(str[i]))
            putchar('V');
        else
            putchar('C');
    }

    printf("\n");
}

// 5. Count vowels and consonants
void count_letters(char str[]) {
    int vowels = 0, consonants = 0;
    int freq[5] = {0};
    char vowel[] = "aeiou";
    int i, j;

    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (!isalpha(ch))
            continue;

        if (is_vowel(str[i])) {
            vowels++;

            char lower = (char)tolower(ch);
            for (j = 0; j < 5; j++) {
                if (lower == vowel[j]) {
                    freq[j]++;
                    break;
                }
            }
        } else {
            consonants++;
        }
    }

    printf("Count of each vowel:\n");

    for (i = 0; i < 5; i++)
        printf("%c = %d\n", vowel[i], freq[i]);

    printf("Total vowels: %d\n", vowels);
    printf("Total consonants: %d\n", consonants);
}

int main(void) {
    char input[200];
    int choice;

    printf("Enter a string: ");

    if (fgets(input, sizeof(input), stdin) == NULL)
        return 1;

    input[strcspn(input, "\n")] = '\0';

    do {
        printf("\n--- MENU ---\n");
        printf("1. Reverse Only Vowels\n");
        printf("2. Find Longest Consecutive Vowel Sequence\n");
        printf("3. Find Most Frequent Vowel\n");
        printf("4. Display Vowel/Consonant Pattern\n");
        printf("5. Count Vowels and Consonants\n");
        printf("6. Find Longest Consecutive Consonant Sequence\n");
        printf("7. Find Most Frequent Consonant\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                reverse_vowels(input);
                break;

            case 2:
                longest_sequence(input, 1);
                break;

            case 3:
                most_frequent(input, 1);
                break;

            case 4:
                display_pattern(input);
                break;

            case 5:
                count_letters(input);
                break;

            case 6:
                longest_sequence(input, 0);
                break;

            case 7:
                most_frequent(input, 0);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Enter 1-8.\n");
        }

    } while (choice != 8);

    return 0;
}
