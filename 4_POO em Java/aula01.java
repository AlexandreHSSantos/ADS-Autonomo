public class aula01 {


        public static int somar(int primeiroNumero, int segundoNumero) {
                int total = primeiroNumero + segundoNumero;
                return total;
        }

        public static boolean verificar_se_e_par(int numero) {
                return (numero % 2 == 0);
        }

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

     public static void main(String[] args) {

        System.out.println("Olá, Java!");
}
}
