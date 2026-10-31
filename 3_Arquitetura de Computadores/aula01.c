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

    printf("---2. COMPLEMENTO DE DOIS (COMO O NEGATIVO APARECE NA MEMORIA) ---\n");
    int8_t positivo = 5;
    int8_t negativo = -5;

    printf("+5 em bits: ");
    imprimir_bits((uint8_t)positivo);
    printf(" (valor: %d)\n", positivo);

    printf("-5 em bits: ");
    imprimir_bits((uint8_t)negativo);
    printf(" (Observe o bit 1 na ponta esquerda indicando negativo)\n");

    int8_t soma = positivo + negativo;
    printf("Soma (+5 com -5): ");
    imprimir_bits((uint8_t)soma);
    printf(" -> Resultado decimal: %d\n\n", soma);

    printf("--- 3. OVERFLOW (ESTOURO DO LIMITE DE 8 BITS) ---\n");
    int8_t limite = 127;

    printf("Antes da soma: %d | Bits: ", limite);
    imprimir_bits((uint8_t)limite);
    printf("\n");

    limite = limite + 1;

    printf("Após somar 1: %d | Bits: ", limite);
    imprimir_bits((uint8_t)limite);
    printf(" -> O valor virou -128 por causa do overflo!\n\n");


    printf("--- 4. PONTO FLUANTE (IMPRECISÃO DA BASE 2) ---\n");
    float a = 0.1f;
    float b = 0.2f;
    float resultado = a + b;


    printf("0.1 com alta precisão: %.20f\n", a);
    printf("0.2 com alta precisão: %.20f\n", b);
    printf("Soma (0.1 + 0.2):      %.20f\n", resultado);

    if (resultado == 0.3f) {
        printf("Resultado: Exatamente igual a 0.3\n");

    }
    else
    {
        printf("Resultado DIFERENTE de 0.3 devido ao arredondamento dos 23 bits da mantissa");
    }
    return 0;
    
}
