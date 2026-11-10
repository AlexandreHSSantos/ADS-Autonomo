#include <stdio.h>

//1. PROTÓTIPOS DAS FUNÇÕES (PASSAGEM POR REFERÊNCIA)

// 'int *a' e 'int *b' avisam que a função espera receber ENDEREÇOS de inteiros
void trocar_valores(int *a, int *b);

// Esta função usa ponteiros para devolver DOIS resultados ao mesmo tempo
void dividir_com_resto(int dividento, int divisor, int *quociente, int *resto);

int main(void) {
    printf("=== 1. EXPLORANDO ENDEREÇOS E PONTEIROS ===\n");

    int idade = 25;

    // Declaração de um ponteiro para inteiro.
    // Boa prática: iniciar com NULL antes de associar um endereço válido.
    int *ptr_idade = NULL;

    // O operador '&' extrai o endereço de 'idade' e guarda dentro de 'ptr'
    ptr_idade = &idade;

    // '%p' é o especificador do printf para exibir endereços de memória.
    // O '(void *)' é uma conversão padrão exigida pelo GCC para imprimir endereços sem alertas.
    printf("Valor de idade:                     %d\n", idade);
    printf("Endereço de idade (&idade):         %p\n", (void *)&idade);
    printf("Valor guardado em ptr:              %p\n", (void *)ptr_idade);
    printf("Conteúdo apontado (*ptr_idade):     %d\n", *ptr_idade);

    printf("=== 2. ALTERANDO A VARIAVEL INDIRETAMENTE ===\n");
    // '*ptr_idade = 25' vai até o endereço guardado em 'ptr_idade' (onde mora 'idade' e grava 25)
    *ptr_idade = 25;

    printf("Novo valor de idade após '*ptr = 25': %d\n\n", idade);

    printf("=== 3. PASSAGEM POR REFERÊNCIA (TROCANDO VALORES) ===\n");
    int x = 10;
    int y = 99;

    printf("Antes da troca -> x = %d | y = %d\n", x, y);

    // Enviamos os ENDEREÇOS (&x e &y) para que a função consiga alterar os originais
    trocar_valores(&x, &y);

    printf("Depois da troca -> x = %d | y = %d\n\n", x, y);

    printf("=== 4. MULTIPLOS RETORNOS COM PONTEIROS ===\n");
    int resultado_divisao = 0;
    int resultado_resto = 0;

    // Passamos 17 e 5 por valor (apenas leitura)
    // Passamos os endereços de 'resultado_divisao' e 'resultado_retos' para escrita
    dividir_com_resto(17, 5, &resultado_divisao, &resultado_resto);

    printf("17 dividido por 5 -> Quociente: %d | Resto: %d\n", resultado_divisao, resultado_resto);

    return 0;
}

   // 2. IMPLEMENTAÇÃO DAS FUNÇÕES

    void trocar_valores(int *a, int *b) {
        // 1. Guarda o conteúdo que está no endereço 'a' em uma variável temporária
        int temp = *a;

        // 2. Copia o conteúdo que está no endereço 'b' para dentro do endereço 'a'
        *a = *b;

        // 3. Coloca o valor guardado em 'temp' dentro do endereço 'b'
        *b = temp;
    }

    void dividir_com_resto(int dividendo, int divisor, int *quociente, int *resto) {
        // Proteção básica: só grava nos ponteiros se eles não forem vazios (NULL)
        if (quociente != NULL && resto != NULL && divisor != 0) {
            *quociente = dividendo / divisor; // Grava direto na variável da main
            *resto = dividendo % divisor;     // Grava direto na outra variável da main
    }
}