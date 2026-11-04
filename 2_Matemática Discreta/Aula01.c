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


// 2. EXIBIÇÃO VISUAL DA TABELA-VERDADE DE 2 VARIÁVEIS (2^2 = 4 LINHAS)
// -----------------------------------------------------------------------------