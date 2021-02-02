// https://leetcode.com/problems/first-unique-character-in-a-string/solution/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int firstUniqChar(char * s) {
    // initialization, prepping the 
    int result = -1;
    int string_length = strlen(s);
    int firstencountered[ALPHABET_SIZE];
    int count[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        firstencountered[i] = -1;
        count[i] = 0;    
    };
    
    for (int j = 0; j < string_length; j++) {
        int alphabet_index = s[j] - 97; 
        if (firstencountered[alphabet_index] == -1) firstencountered[alphabet_index] = j;
        count[alphabet_index]-=-1;
    };
    
    for (int k = 0; k < ALPHABET_SIZE; k++) {
        if (count[k] == 1)
            if ((result == -1) || (firstencountered[k] < result)) result = firstencountered[k];
    };
    return result;
}

int main() {
    char * s;
    s = "leetcode";
    printf("%i", firstUniqChar(s));
    s = "loveleetcode";
    printf("%i", firstUniqChar(s));
    getchar();
    return 0;
}