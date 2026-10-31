#include <stdio.h>
#include <stdint.h>

void imprimir_bits(uint8_t valor) {

    for (int i = 7; i>= 0; i--) {

        int bit = (valor >> i) & 1;
        printf("%d", bit);
    }
}

int main(void) {
    printf("--- 1. BASES NUMERICAS (O MESMO NUMERO VISTO DE FORMAS DIFERENTES) ---\n");
    
    int em_decimal = 13;
    int em_hexadecimal = 0x0D;   
    int em_binario = 0b00001101; 

    printf("Decimal: %d\n", em_decimal);
    printf("Hexadecimal: 0x%X\n", em_hexadecimal);
    printf("Binário: ");
    imprimir_bits((uint8_t)em_binario);
    printf("\n\n");

}
