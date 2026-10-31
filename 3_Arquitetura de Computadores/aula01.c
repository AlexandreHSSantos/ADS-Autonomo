#include <stdio.h>
#include <stdint.h>

void imprimir_bits(uint8_t valor) {

    for (int i = 7; i>= 0; i--) {

        int bit = (valor >> i) & 1;
        printf("%d", bit);
    }

    return 0;
}
