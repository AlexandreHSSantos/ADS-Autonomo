//CÓDIGO INICIAL + DECLARAÇÃO DE FUNÇÕES + ESCOPO

#include <stdio.h>
#include <limits.h>

//DECLARAÇÃO DE FUNÇÕES

//protótipo: apresenta a função ANTES de ela ser definida, para que main possa chamá-la
int soma(int a, int b);

//Função sem parâmetros (void) que devolve um int.
int contador(void) {
    //static: a variável é criada UMA vez e dura o programa inteiro,
    //mas continua visível só aqui dentro. O "= 0" roda apenas na primeira chamada.
    static int vezes = 0;
    vezes++;
    return vezes;
}

void tenta_mudar(int x) {
    x = 99;
}

int main(void) {

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


    //DECLARAÇÃO DE VARIÁVEIS
    int idade = 20;         //int: número inteiro (geralmente 4 bytes)
    double altura = 1.75;   //double:decimal de precisão dupla (8 bytes)
    char letra = 'A';       //char: 1 byte. Aspas SIMPLES = um único caractere.
                            //Por dentro é um número (código ASCII: 'A' vale 65).

    //printf com formatos: Cada % é um espaço que recebe, em ordem, um argumento.
    //  %d inteiro      %f decimal      %c caractere
    //  %.2f = decimal com 2 casas depois da vírgula
    printf("idade= %d altura= %.2f letra= %c codigo= %d\n", idade, altura, letra, letra);
    //'letra' impressa com %c vira o caractere, e com %d vira o número 65.
    
    
    
    
    int n = 5;
    tenta_mudar(n);             //envia uma cópia do valor de n (5)
    printf("n = %d\n", n);      //continua 5: passagem POR VALOR

    printf("soma = %d\n", soma(2, 3));  // o resultado da função entra direto no printf  


    printf("primeira vez: %d\n",contador());    // 1ª chamada: vezes passa a 1
    contador();                                 // 2ª chamada: vezes passa a 2
    printf("vezes = %d\n", contador());  // 3ª chamada: vezes passa a 3 e é impresso   


{   //Um bloco solto cria um escopo novo
    int n = 10;                 //Este n é outro, e "esconde" o n de fora (sombreamento)
    printf("n interno = %d\n", n);
}                               //Aqui o n interno deixa de existir
    printf("n externo = %d\n", n);  //Volta a valor o n de fora: 5
    return 0;
}

//Definição da função declarada lá em cima.
int soma(int a, int b) {
    return a + b;
}