# Extração de Palíndromos em Strings

> Status do projeto: Concluído ✔️

## 📝 Descrição do Projeto
O seguinte projeto é um trabalho da disciplina de Algoritmos e Estrutura de Dados 2 da Universidade Tecnológica Federal do Paraná (UTFPR - PB), e tem por objetivo utilizar os paradigmas de programação para solucionar um problema.

O problema escolhido foi o de dividir uma string de modo que todas as substrings sejam palíndromos, ou seja, a string pode ser lida da mesma forma de trás pra frente ou de frente para trás, usando o mínimo de cortes possível, e o paradigma escolhido foi o de programação dinâmica. 

O programa lê cada string de um arquivo de texto e calcula o mínimo de cortes possíveis na string para no fim imprimir a string com as divisões entre as substrings. 
Por exemplo, a string "bcdddaaadddadabba" resultaria em: bc | dddaaaddd | ad | abba.

## 🛠️ Funcionalidades do projeto
- `void gerarPalindromo(char *s, int n, bool pal[n][n]):`esta função preenche uma matriz **‘pal’**, onde **‘pal[i][j]’** é **‘true’** se a substring **‘s[i…j]’** for um palíndromo;
- `void imprimirStringCortada(char *s, int indicesCortes[], int n):`esta função imprime a string original de forma que as substrings palindrômicas sejam separadas por **‘|’**, o que representaria os cortes da string;
- `int minCortes(char *s):`Através dos dados obtidos na função **‘gerarPalindromo’**, esta função calcula o número mínimo de cortes necessários na string e posteriormente chama a função **‘imprimirStringCortada’** para mostrar o resultado dos cortes.
  

## 💻 Abrir e rodar o projeto
- **01.Compilação:** Use um compilador em C;
- **02.Arquivo de entrada:** Certifique-se que o arquivo de texto esteja no mesmo diretório do executável e que haja uma string por linha dentro do arquivo;
- **03.Execução:** Execute o programa;


## 🌐 Técnicas e tecnologias utilizadas
✔️ Programação dinâmica

✔️ Pilha

✔️ Matriz 2D

✔️ Estruturas de controle
