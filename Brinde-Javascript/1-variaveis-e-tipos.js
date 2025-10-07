//VARIÁVEIS
/*_Conceitos_

*/
//VARIÁVEIS
/*_Conceitos_
Pode ser visto como um nome/identificador que guarda algum objeto/valor que será armazenado na memória para um uso futuro, sendo usado o operador '='(igualdade) para relacioanr o nome com o objeto/valor.
No javasctript se declara variável usando nada ou usando as palavras-chave 'let'/'var'/'const' antes do nome/identificador.
let = Para var. que vai mudar ao longo do tempo, suas var. só podem ser acessadas dentro do bloco {qualquer coisa entre chaves} em que são definidas. Resolve problemas de escopo e segurança.
var = Modo antigo, usado apenas em código legado/Legacy Code (desatualizado) que se precisa manter
const = Para var. que serão fixos em todo o código, imutáveis, seja por opção ou necessidade no código.
*/

//Exemplos
nome = "LucasCalvo";  //Recebe uma string em 'nome'
let idade = 22;  //Recebe um valor inteiro em 'idade'
let altura = 1.89;  //Recebe um valo real em 'altura'

//Tipos de variáveis
/*
Reflete o tipo de conteúdo armazenado nas variáveis.
Por exemplo (e.g.): Texto = string ; Núm. inteiro = number ; Núm. real = number; Booleano = boolean; 
*/
//Exemplos
nome = "Bob";  //String
idade = 21;  //Number
altura = 2.10; //Number
dormeCedo = true;  //Boolean, sempre é tudo minúsculo
//dormeTarde = True;  //Erro, não reconhece como 'true'

/* OBS= OBSERVAÇÃO
Sempre use o símbolo de ';' no final de cada declaração, pois Javascript precisa entender claramente onde cada instrução começa e termina para que não tenha erros e o navegador consiga entender o código Javascript.
Pode ser feito declarações de intruções no código sem usar o ';', mas como foi citado, isso pode gerar certos erros a depender da situação a depender do conteúdo da declaração seguinte (ainda mais se não usar o let na declaração seguinte) ou do ambiente em que será usado o código.
*/
