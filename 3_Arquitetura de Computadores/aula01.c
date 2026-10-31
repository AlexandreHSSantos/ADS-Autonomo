#include <stdio.h>
#include <stdint.h>

//Convertendo Hexadecimal -> Binário
//Lendo valores de bites para cada tipo
int main(void) {
    unsigned int n = 202;

    printf("Decimal:  %d\n", n);
    printf("Hexa:     %X\n", n);

    printf("0xFF em decimal: %d\n", 0xFF);
    printf("0x10 em decimal: %d\n", 0x10);

    printf("char:      %d byte(s)\n", (int)sizeof(char));
    printf("short:     %d byte(s)\n", (int)sizeof(short));
    printf("int:       %d byte(s)\n", (int)sizeof(int));
    printf("long:      %d byte(s)\n", (int)sizeof(long));
    printf("long long: %d byte(s)\n", (int)sizeof(long long));
    printf("uint8_t:   %d byte(s)\n", (int)sizeof(uint8_t));

    return 0;
}