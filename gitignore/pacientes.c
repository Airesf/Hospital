#include <stdio.h>
#include <string.h>


int main () {
    char notas[5];
    notas[0] = 'N';
    notas[1] = 'A';
    notas[2] = 'N';
    notas[3] = 'D';
    notas[4] = 'A';
    for (int i = 0; i < 5; i++) {
        printf("Nota %d: %c\n", i, notas[i]);
    }
}