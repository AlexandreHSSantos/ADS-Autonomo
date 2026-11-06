public class aula01 {
//FUNDAMENTOS EM JAVA

        //1. MÉTODOS AUXILIARES (Funções fora do main)

        //Recebe dois números inteiros, soma e devolve o resultado
        public static int somar(int primeiroNumero, int segundoNumero) {
                int total = primeiroNumero + segundoNumero;
                return total; //Envia o valor calculado de volta para quem chamou
        }

        //Recebe um número e devolve 'true' se for par ou 'false' se for ímpar
        public static boolean verificar_se_e_par(int numero) {
                return (numero % 2 == 0);
        }

        //Void é usado somente para imprimir algo sem devolver valores à máquina
        public static void classificarIdade(int idade) {
                if (idade < 18) {
                        System.out.println("Categoria: Menor de idade");
                }
                else if (idade < 60) {
                        System.out.println("Categoria: Adulto");
                }
                else {
                        System.out.println("Categoria: Idoso");
                }
        }

        //main é onde inicia a execução
     public static void main(String[] args) {
        System.out.println("=== 1. TESTE DE VARIÁVEIS BÁSICAS ===");

        int alunos = 35;
        double mediaTurma = 8.75;
        boolean cursoAtivo = true;
        char turno = 'N';
        String nomeDisciplina = "POO em Java";

        // Exibindo textos no console (+ junta extos e variáveis)
        System.out.println("Disciplina: " + nomeDisciplina);
        System.out.println("Alunos matriculados: " + alunos);
        System.out.println("Média geral: " + mediaTurma);
        System.out.println("Turno: " + turno + " | Ativa: " + cursoAtivo);
        System.out.println(); //Só pra pular linha}


        System.out.println("=== 2. DIVISÃO INTEIRA VS COM VÍRGULA (PEGADINHA COMUM");
        int valorA = 7;
        int valorB = 2;

        // Como ambos são int, o Java joga fora a parte fracionária: 7 / 2 vira 3
        double divisaoTruncada = valorA / valorB;
        System.out.println("7 / 2 com variáveis inteiras: " + divisaoTruncada);

        // Com double, o Java é forçado a calcular com virgula
        double divisaoCorreta = (double) valorA / valorB;
        System.out.println("7 / 2 convertendo para double: " + divisaoCorreta);
        System.out.println();

        System.out.println("=== 3. CHAMANDO OS MÉTODOS QUE CRIAMOS ===");
        // Chamando o método somar e guardando a resposta
        int somaResultado = somar(10, 7);
        System.out.println("Resultado de somar(10, 7): " + somaResultado);

        //Testando a função que devolve verdadeiro ou falso
        int numeroParaTestar = 11;
        boolean par = verificar_se_e_par(numeroParaTestar);
        System.out.println("O número " + numeroParaTestar + " é par? " + par);

        // Testando o método de decisão
        System.out.print("Classificação para 17 anos: ");
        classificarIdade(17);
        System.out.println();

        
        System.out.println("=== 4. LAÇOS DE REPETIÇÃO (FOR E WHILE) ===");

        //FOR: usado quando você sabe quantas vezes quer repetir
        System.out.println("Contagem com laço FOR:");
        for (int i = 1; i <= 7; i++) {
                System.out.println(" Passo " + i);
        }

        //WHILE: repete enquanto a condição for verdadeira
        System.out.println("Contagem regressiva com laço WHILE:");
        int contador = 3;
        while (contador >= 3) {
                System.out.println(" Contagem: " + contador);
                contador--;
        }

        System.out.println("Fim do programa!");
        }
}