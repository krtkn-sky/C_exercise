#include <stdio.h>
#include <string.h>

int isValidWord(char word[], char secret[], int green[], char yellow[], char grey[]) {
    int i;
    int secret_count[26] = {0};
    int word_count[26] = {0};
    
    for (i = 0; i < 5; i++) {
        if (green[i] && word[i] != secret[i]) {
            return 0;
        }
        if (yellow[i] && word[i] == secret[i]) {
            return 0;
        }
        secret_count[secret[i] - 'A']++;
        word_count[word[i] - 'A']++;
        if (grey[i] && word_count[grey[i] - 'A'] > secret_count[grey[i] - 'A']) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    char dictionary[N][6];
    char secret[6];
    int green[5] = {0};
    char yellow[5] = {0};
    char grey[5] = {0};
    
    for (int i = 0; i < N; i++) {
        scanf("%s", dictionary[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        char type;
        scanf(" %c", &type); 
        if (type == 'G') {
            green[i] = 1;
        } else if (type == 'Y') {
            yellow[i] = 1;
        } else if (type == 'P') {
            grey[i] = 1;
        }
    }
    
    scanf("%s", secret);
    
    int validWordsFound = 0;
    
    for (int i = 0; i < N; i++) {
        if (isValidWord(dictionary[i], secret, green, yellow, grey)) {
            if (validWordsFound > 0) {
                printf(" ");
            }
            printf("%s", dictionary[i]);
            validWordsFound++;
        }
    }
    
    if (validWordsFound == 0) {
        printf("-1");
    }
    
    return 0;
}
