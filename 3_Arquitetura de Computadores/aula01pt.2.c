#include <stdio.h>


//Convertendo Decimal para Binário
int main(void) {
    int numero = 202;
    int restos[32];
    int qtd = 0;
    int atual = numero;



while (atual > 0) {
    restos[qtd] = atual % 2;
    atual = atual / 2;
    qtd++;
}


printf("%d em binario: ", numero);
for (int i =qtd - 1; i>= 0; i--) {
    printf("%d", restos[1]);
}
printf("\n");

return 0;
}
