#include <stdio.h>



//EXERCÍCIO 1: SOMA DE VALORES
int atualizar(int x) {
    return x + 10;
}


int main(void) {
    int valor = 5;

    valor = atualizar(valor);
    
    printf("Valor final: %d\n", valor);
    


//EXERCÍCIO 2: CALCULAR FATORIAL

    
    int número;
    int fatorial = 1;
    printf("Qual o valor que você quer o fatorial?");
    scanf("%d", &número);


    for (int i = número; i > 1; i--)
    {
        fatorial =  fatorial * i;
    }
    printf("%d\n", fatorial);

    return 0;
}