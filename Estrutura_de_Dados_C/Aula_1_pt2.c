//Escopo

#include <stdio.h>

//Declaração de Variáveis
int soma(int a, int b);

int contador(void) {
    static int vezes = 0;
    vezes++;
    return vezes;
}

void tenta_mudar(int x) {
    x = 99;
}

int main(void) {
    int n = 5;
    tenta_mudar(n);
    printf("n = %d\n", n);
    printf("soma = %d\n", soma(2, 3));


contador();
contador();
printf("vezes = %d\n", contador());


{
    int n = 10;
    printf("n interno = %d\n", n);
}
    printf("n externo = %d\n", n);
    return 0;
}

int soma(int a, int b) {
    return a + b;
}