#include <stdio.h>
#include <stdbool.h>


// -----------------------------------------------------------------------------
// 1. FUNÇÕES LÓGICAS QUE NÃO EXISTEM NATIVAMENTE COMO OPERADOR ÚNICO EM C
// -----------------------------------------------------------------------------

// Implementa p -> q usando a identidade !p || q
bool operador_implica(bool p, bool q) {
    return (!p) || q;
}

// Implementa p <-> q (verdadeiro se p e q tiverem o mesmo valor)
bool operador_bicondicional(bool p, bool q) {
    return (p == q);
}

// -----------------------------------------------------------------------------
// 2. EXIBIÇÃO VISUAL DA TABELA-VERDADE DE 2 VARIÁVEIS (2^2 = 4 LINHAS)
// -----------------------------------------------------------------------------

void exibir_tabela_geral(void) {
    printf("==================== TABELA-VERDADE BASICA ====================\n");
    printf("|  p  |  q  | !p  | p && q | p || q | p -> q | p <-> q |\n");
    printf("|-----|-----|-----|--------|--------|--------|---------|\n");

    // Vetor com os dois estados possíveis da lógica booleana
    bool valores[2] = {true, false};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            bool p = valores[i];
            bool q = valores[j];

            printf("|  %d  |  %d  |  %d  |   %d    |   %d    |   %d    |    %d    |\n",
                p,
                q,
                !p,
                (p && q),
                (p || q),
                operador_implica(p, q),
                operador_bicondicional(p, q));
        }
    }
    printf("===================================================================\n\n");
}

// -----------------------------------------------------------------------------
// 3. PROVA COMPUTACIONAL DA 1ª LEI DE DE MORGAN: !(p && q) == (!p || !q)
// -----------------------------------------------------------------------------
void testar_de_morgan(void) {
    printf("========== PROVA DA 1a LEI DE DE MORGAN ==========\n");
    printf("|  p  |  q  | !(p && q) | (!p || !q) | Identicos? |\n");
    printf("|-----|-----|-----------|------------|------------|\n");

    bool valores[2] = {true, false};
    bool equivalencia_valida = true;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            bool p = valores[i];
            bool q = valores[j];

            // Avaliando os dois lados da igualdade lógica
            bool lado_esquerdo = !(p && q);
            bool lado_direito  = (!p) || (!q);

            // Verificação se batem linha a linha
            bool linha_igual = (lado_esquerdo == lado_direito);
            if (!linha_igual) {
                equivalencia_valida = false;
            }

            printf("|  %d  |  %d  |     %d     |     %d      |     %s    |\n",
                   p, q, lado_esquerdo, lado_direito, linha_igual ? "SIM" : "NAO");
        }
    }

    printf("--------------------------------------------------\n");
        printf("Resultado: As duas formulas sao %s!\n\n",
            equivalencia_valida ? "LOGICAMENTE EQUIVALENTES" : "DISTINTAS");
    }

    int main(void) {
        exibir_tabela_geral();
        testar_de_morgan();
        return 0;
    }