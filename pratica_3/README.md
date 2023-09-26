## Estruturas Avançadas (Prática III)
Estes exercícios abrangem vários aspectos de tipos abstratos de dados em C, como vetores, ponteiros, listas encadeadas, pilhas, filas, árvores binárias de busca e tabelas hash. Eles oferecem uma ampla gama de oportunidades para praticar a criação, manipulação e uso de estruturas de dados em C.

### Exercício 1: Vetor

Neste exercício, você irá criar um programa em C para trabalhar com um vetor de números inteiros. O objetivo é praticar o uso de vetores para armazenar e manipular dados.

#### Requisitos
1. Declare um vetor de inteiros com espaço para, pelo menos, 10 elementos.
2. Implemente uma função para preencher o vetor com valores inteiros fornecidos pelo usuário.
3. Implemente uma função para calcular a média dos valores no vetor.
4. Implemente uma função para encontrar o valor máximo no vetor.
5. Implemente uma função para encontrar o valor mínimo no vetor.

#### Exemplo de Saída
```
Digite 10 valores inteiros:
1 5 9 3 6 8 2 4 7 10
Média: 5.50
Valor Máximo: 10
Valor Mínimo: 1
```

### Exercício 2: Lista Encadeada Simples
Neste exercício, você irá criar um tipo abstrato de dados (TAD) em C para representar uma lista encadeada simples de números inteiros.

#### Requisitos
1. Implemente uma estrutura para representar um nó da lista com um campo inteiro para armazenar os dados e um ponteiro para o próximo nó.
2. Implemente funções para:
   - Inicializar uma lista vazia.
   - Adicionar elementos ao final da lista.
   - Remover elementos da lista.
   - Verificar se um elemento está na lista.
   - Exibir os elementos da lista.

#### Exemplo de Saída

```
Lista Inicial: 1 2 3 4 5
1. Adicionar elemento
2. Remover elemento
3. Verificar se o elemento está na lista
4. Exibir a lista
5. Sair
Escolha uma opção: 2
Digite o elemento a ser removido: 3
Elemento removido com sucesso.
```

### Exercício 3: Pilha (Stack)
Neste exercício, você irá criar um tipo abstrato de dados (TAD) em C para representar uma pilha de números inteiros.

#### Requisitos
1. Implemente uma estrutura para representar uma pilha usando um vetor dinâmico.
2. Implemente funções para:
   - Inicializar uma pilha vazia.
   - Empilhar (push) elementos na pilha.
   - Desempilhar (pop) elementos da pilha.
   - Verificar se a pilha está vazia.
   - Exibir os elementos da pilha.

#### Exemplo de Saída

```
Pilha Inicial: 3 6 9
1. Empilhar elemento
2. Desempilhar elemento
3. Verificar se a pilha está vazia
4. Exibir a pilha
5. Sair
Escolha uma opção: 2
Elemento desempilhado: 9
```

### Exercício 4: Fila (Queue)
Neste exercício, você irá criar um tipo abstrato de dados (TAD) em C para representar uma fila de números inteiros.

#### Requisitos
1. Implemente uma estrutura para representar uma fila usando um vetor dinâmico.
2. Implemente funções para:
   - Inicializar uma fila vazia.
   - Enfileirar (enqueue) elementos na fila.
   - Desenfileirar (dequeue) elementos da fila.
   - Verificar se a fila está vazia.
   - Exibir os elementos da fila.

#### Exemplo de Saída
```
Fila Inicial: 5 10 15
1. Enfileirar elemento
2. Desenfileirar elemento
3. Verificar se a fila está vazia
4. Exibir a fila
5. Sair
Escolha uma opção: 2
Elemento desenfileirado: 5
```

### Exercício 5: Árvore Binária de Busca (BST)
Neste exercício, você irá criar um tipo abstrato de dados (TAD) em C para representar uma árvore binária de busca (BST) de números inteiros.

#### Requisitos
1. Implemente uma estrutura para representar um nó da árvore com campos para armazenar o valor e os ponteiros para os filhos esquerdo e direito.
2. Implemente funções para:
   - Inicializar uma árvore vazia.
   - Inserir elementos na árvore.
   - Pesquisar elementos na árvore.
   - Remover elementos da árvore.
   - Percorrer a árvore em ordem (impressão em ordem).

#### Exemplo de Saída
```
Árvore Inicial: 5 3 8 2 4 7 9
1. Inserir elemento
2. Pesquisar elemento
3. Remover elemento
4. Exibir a árvore (ordem)
5. Sair
Escolha uma opção: 2
Digite o valor a ser pesquisado: 4
Elemento encontrado na árvore.
```

### Exercício 6: Tabela Hash
Neste exercício, você irá criar um tipo abstrato de dados (TAD) em C para representar uma tabela hash de pares chave-valor, onde as chaves e os valores são strings.

#### Requisitos
1. Implemente uma estrutura para representar um par chave-valor.
2. Implemente uma estrutura para representar uma tabela hash que contenha um vetor de pares chave-valor e funções para calcular o índice (hash) de uma chave e manipular a tabela.
3. Implemente funções para:
   - Inicializar uma tabela hash vazia com um tamanho específico.
   - Inserir pares chave-valor na tabela.
   - Pesquisar valores por chave na tabela.
   - Remover pares chave-valor da tabela.

#### Exemplo de Saída

```
Tabela Hash Inicial:
Chave: "nome", Valor: "João"
Chave: "idade", Valor: "30"
1. Inserir par chave-valor
2. Pesquisar valor por chave
3. Remover par chave-valor
4. Exibir a tabela hash
5. Sair
Escolha uma opção: 2
Digite a chave a ser pesquisada: "idade"
Valor encontrado na tabela: "30"
```