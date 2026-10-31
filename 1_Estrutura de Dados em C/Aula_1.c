//Código Inicial + Declaração de Funções
#include <stdio.h>
#include <limits.h>

int main(void)
{
    
printf("Olá, C!\n");

//sizeof(tipo) devolve quantos bytes o tipo ocupa.
//O resultado tem o tipo size_t, e seu formato no printf é %zu.
printf("char:     %zu byte(s)\n", sizeof(char));
printf("int:      %zu byte(s)\n", sizeof(int));
printf("long:     %zu byte(s)\n", sizeof(long));
printf("float:    %zu byte(s)\n", sizeof(float));
printf("double:   %zu byte(s)\n", sizeof(double));
printf("INT_MAX = %d\n", INT_MAX);


//Operadores aritméticos: + - * / e % (resto da divisão)
printf("7  / 2  = %d\n", 7 / 2);
printf("7  %% 2 = %d\n", 7 % 2);
printf("7 / 2.0 = %f\n", 7 / 2.0);

    return 0;
}
