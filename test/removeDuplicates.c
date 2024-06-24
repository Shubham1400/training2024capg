#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_adjacent_duplicates(char* s, int len) {
    char st[len + 1]; //
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (i > 0 && s[i] == s[i - 1]) {
            continue;
        }

        st[count++] = s[i];
    }

    st[count] = '\0';

    printf(": %s\n", st);
}

int main() {
    char s[100];

    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) != NULL) {
        size_t len = strlen(s);

        // Remove the newline character if present
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len--;
        }

        remove_adjacent_duplicates(s, len);
    } else {
        printf("Error reading input.\n");
    }

    return EXIT_SUCCESS;
}
