#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VENDAS 50

//1. ESTRUTURAS DE DADOS (Definem os metadados e o estado do negócio)
typedef struct 
{
    int id;
    char nome[40];
    int estoque;
    double preco_unitario;
} Produto;

typedef struct 
{
    int id_venda;
    int id_produto;
    int qtd_solicitada;
    double valor_total;
    bool aprovada;
    char motivo[25];
} RegistroVenda;

// Armazenamento temporário na memória RAM (volátil)
RegistroVenda historico[MAX_VENDAS];
int total_registros = 0;


//2. PROCESSO DE NEGÓCIO: VENDA COM VALIDAÇÃO DE REGRAS
bool processar_venda(Produto *prod, int quantidade) {
    if (total_registros >= MAX_VENDAS) {
        return false;
    }
    int id_atual = total_registros + 1;

    //REGRA DE NEGÓCIO 1: Bloqueia pedidos com quantidade zero ou negativa
    if (quantidade <= 0) {
        historico[total_registros] = (RegistroVenda){
            .id_venda = id_atual,
            .id_produto = prod->id,
            .qtd_solicitada = quantidade,
            .valor_total = 0.0,
            .aprovada = false,
            .motivo = "QTD_INVALIDA"
        };
        total_registros++;
        return false;
    }

    //REGRA DE NEGÓCIO 2: Bloqueia a venda se não houver estoque suficiente
    if (prod->estoque < quantidade) {
        historico[total_registros] = (RegistroVenda) {
            .id_venda = id_atual,
            .id_produto = prod->id,
            .qtd_solicitada = quantidade,
            .valor_total = 0.0,
            .aprovada = false,
            .motivo = "SEM_ESTOQUE"
        };
        total_registros++;
        return false;
    }

    //TRANSIÇÃO DE ESTADO:
    prod->estoque -= quantidade;
    double total_compra = quantidade * prod->preco_unitario;


    //AUDITORIA: Regista que a venda deu certo
    historico[total_registros] = (RegistroVenda) {
        .id_venda = id_atual,
        .id_produto = prod->id,
        .qtd_solicitada = quantidade,
        .valor_total = total_compra,
        .aprovada = true,
        .motivo = "CONCLUIDA"
    };
    total_registros++;
    return true;
}

    //3. RELATÓRIO GERENCIAL (TRANSFORMA DADOS BRUTOS EM INFORMAÇÃO)

    void gerar_relatorio_gerencial(const Produto *prod) {
        printf("================ RELATÓRIO GERENCIAL (INFORMAÇÃO) ================");
        // %s = texto | %d = inteiro | %2.f = decimal com 2 casas
        printf("Produto: %s (ID: %d) | Preço: R$ %2.f | Estoque Atual: %d un.\n",
        prod->nome, prod->id, prod->preco_unitario, prod->estoque);
        
        printf("--------------------------------------------------------------------------\n");
        printf("| Venda | Prod | Qtd | Total (R$) | Status    | Motivo                   |\n");
        printf("|-------|------|-----|------------|-----------|--------------------------|\n");

        double faturamento = 0.0;
        int vendas_aprovadas = 0;

        //Percorre tods as transações gravadas no vetor 'histórico'
        for (int i = 0; i < total_registros; i++)
        {
            RegistroVenda v = historico[i];

            //Como 'v' é a ficha direta (e não um ponteiro), acessamos os campos com PONTO (.)
            //Trecho (v.aprovada ? é um if/else curto)
            printf("|  %03d  | %03d  | %02d  | %10.2f | %-9s | %-24s |\n",
               v.id_venda,
               v.id_produto,
               v.qtd_solicitada,
               v.valor_total,
               v.aprovada ? "APROVADA" : "RECUSADA",
               v.motivo);

               //Soma ao faturamento apenas as vendas que foram aprovadas
               if (v.aprovada) {
                faturamento += v.valor_total;
                vendas_aprovadas++;
               }
            }

            printf("--------------------------------------------------------------------------\n");
            printf("Faturamento Total: R$ %.2f | Taxa de Aprovacao: %d de %d tentativas\n\n",
           faturamento, vendas_aprovadas, total_registros);
    }

    //4. PERSISTÊNCIA EM ARQUIVO (GRAVA OS DADOS DA RAM PARA O DISCO)

