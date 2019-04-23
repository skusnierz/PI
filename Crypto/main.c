#include <stdio.h>
#include <stdlib.h>

void encrypt(char* message, int n) {
    int move = 0;
    while(move<n&&message[move]!=' ')move++;
    for(int i=0; i<n; i++)
    {
        if(message[i]!=' ') {
            message[i] = (message[i] - 'a' + (move % ('z' - 'a' + 1))) % ('z' - 'a' + 1) + 'a';
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char* message = (char*) malloc((n+1) * sizeof(char));
    fgets(message, n+1, stdin); // reads \n
    fgets(message, n+1, stdin);
    encrypt(message, n);
    printf("%s\n", message);
    free(message);
}