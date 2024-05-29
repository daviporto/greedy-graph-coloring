# Trabalho Prático 2: Essa Coloração é Gulosa

## Introdução

Este projeto implementa um programa em C++ para verificar se a coloração de um grafo foi realizada por um algoritmo guloso. O programa utiliza diversos algoritmos de ordenação antes de verificar a coloração.

## Estrutura do Projeto

### Ambiente de Desenvolvimento

- **Linguagem:** C++
- **Compilador:** g++

### Tipos Abstratos de Dados

- **Grafo:** Representado por um array de ponteiros para vértices.
- **Heap:** Implementado usando um array para facilitar a ordenação com heap sort.

### Principais Métodos

1. **Ordenação:** Implementa vários algoritmos de ordenação, incluindo bubble sort, insert sort, selection sort, e uma versão modificada do quicksort para evitar o pior caso.
2. **Verificação Gulosa:** Método que verifica se a coloração do grafo é resultado de um algoritmo guloso, checando se todos os vértices vizinhos com cores menores foram coloridos adequadamente.

## Complexidade

- **Ordenação:** Os algoritmos de ordenação seguem as complexidades tradicionais, com a versão modificada do quicksort permanecendo O(n log n).
- **Verificação Gulosa:** No pior caso, a complexidade é O(n³), mas o caso médio tende a ser melhor, pois o algoritmo retorna falso assim que detecta uma coloração não gulosa.

## Estratégias de Robustez

- Utilização de valgrind para detectar vazamentos de memória.
- Uso de exceções para tratar entradas inválidas e comportamentos inesperados.
- Código padronizado em C++ com documentação em javadoc e comentários explicativos.

## Análise Experimental

Testes de desempenho foram realizados utilizando um script em Python para rodar o programa com diferentes métodos de ordenação, utilizando entradas geradas por um gerador de casos de teste. Os gráficos resultantes mostram a eficiência e a complexidade dos algoritmos implementados.

## Conclusão

O programa verifica a coloração de grafos utilizando diversos métodos de ordenação e confirma se a coloração foi gerada por um algoritmo guloso. Durante o desenvolvimento, conceitos importantes de POO, estruturas de dados e algoritmos de ordenação foram revisitados e aplicados.

## Referências

1. Slides da disciplina fornecidos pelos professores no Moodle.
2. Cormen, T., Leiserson, C., Rivest R., Stein, C. "Introduction to Algorithms," Third Edition, MIT Press, 2009.
3. Kenneth H. Rosen, "Discrete Mathematics and Its Applications," Eighth Edition.
4. [GeeksforGeeks: Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms) acessado em 5 de novembro de 2023.
