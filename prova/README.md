## Prova P1 (17/10/2023) -  Gerenciador de Tarefas com Lista Encadeada
Este é um programa em C que permite gerenciar uma lista de tarefas usando uma lista encadeada. O programa oferece as seguintes funcionalidades:

## Estrutura de Dados - `TASK`
A estrutura de dados `TASK` (TAREFA) é usada para representar cada tarefa na lista. Ela contém os seguintes campos:
- Um atributo string para a descrição (`description`) da tarefa.
- Um atributo inteiro para representar a prioridade (`priority`) da tarefa.
- Um atributo ponteiro para a próxima (`next`) tarefa.

## Instruções Gerais
- Certifique-se de que seu código compile corretamente antes de entregá-lo. Qualquer código que não compile receberá uma pontuação zero.
- Mantenha uma endentação clara e consistente em seu código. A falta de endentação adequada pode resultar em uma penalização de 1.5 pontos na prova.

## Funcionalidades

### Parte 1: Estrutura de Dados
A parte 1 consiste na definição da estrutura de dados `TASK`. Cada tarefa na lista é representada por essa estrutura. Além disso, é necessário criar um ponteiro principal (`head`) para o primeiro nó da lista encadeada, inicializado como NULL.

### Parte 2: Inserção de Tarefas
Nesta parte, é implementada a função `insertTask`. Esta função recebe como parâmetros a descrição e a prioridade da tarefa e insere a tarefa na lista encadeada em ordem crescente de prioridade. Tarefas de mesma prioridade são equivalentes.

### Parte 3: Tarefa Concluída
A parte 3 requer a implementação da função `completeTask`. Esta função recebe como parâmetro a prioridade de uma tarefa a ser "concluída". A função deve encontrar a primeira tarefa da prioridade informada e removê-la da lista. Em seguida, ela retorna a descrição da tarefa concluída.

### Parte 4: Exibição de Tarefas
Na parte 4, é implementada a função `displayTasks`. Esta função exibe todas as tarefas da lista encadeada, incluindo sua descrição e prioridade. As tarefas são exibidas em ordem de prioridade, da mais alta para a mais baixa.

### Parte 5: Programa Principal
Na parte 5, o programa principal (`main`) é criado. Um menu interativo permite ao usuário escolher entre as seguintes opções:
- Adicionar uma nova tarefa.
- Concluir uma tarefa de prioridade.
- Exibir todas as tarefas na lista.
- Sair do programa.
O loop do menu permite que o usuário execute várias operações até optar por sair.

## Prova P2 (27/11/2023) -  Bolsa de Valores/Relatório de Operações

**Bolsa de Valores - Relatório de Operações**

Este programa em C trata de operações na Bolsa de Valores, gerando relatórios de saldo para cada cliente com base em operações de compra e venda.

**Parte 1 - Estrutura de Dados**

Defina uma estrutura de dados chamada `OPERACAO` que contém os seguintes campos:
- `CodigoCliente` (inteiro)
- `CodigoOperacao` ('V' para Venda, 'C' para Compra)
- `QuantidadeTitulos` (inteiro)
- `ValorUnitario` (real)

**Parte 2 - Leitura do Arquivo de Operações**

Implemente uma função para ler o arquivo de operações chamado "operacoes.csv". Cada registro no arquivo contém uma operação da Bolsa.

*Exemplo de entrada ("operacoes.csv"):*
```plaintext
NumeroCliente,Operacao,QuantidadeTitulos,ValorUnitario
48,C,1,10.0
48,V,2,15.5
20,C,5,8.3
20,V,3,12.7
2,C,10,5.2
```

**Parte 3 - Cálculo do Saldo Apurado**

Crie funções para calcular o saldo apurado de cada cliente. O saldo apurado é a diferença entre o valor total vendido e o valor total comprado por um cliente.

*Exemplo de saldo das operações do cliente 20:*
- Compra: 5 títulos a R$8.3 cada, totalizando R$41.5
- Venda: 3 títulos a R$12.7 cada, totalizando R$38.1
- Saldo Apurado = R$41.5 - R$38.1 = R$3.4

**Parte 4 - Liste Resultados**

Implemente uma função que apresente o consolidado dos resultados das operações, os mesmos do arquivo.

*Exemplo de listagem no console:*
```plaintext
Número Cliente | Saldo Apurado | Tipo de Saldo
----------------------------------------------
48             | 7.5           | Credor
20             | 3.4           | Credor
2              | 52.0          | Credor
```

**Parte 5 - Geração do Arquivo de Resultados**

Implemente uma função que gere um arquivo de texto chamado "resultados.txt" contendo as seguintes informações para cada cliente:
- Número do cliente
- Saldo apurado
- Tipo de saldo ('C' para credor, 'D' para devedor)

*Exemplo de saída no arquivo "resultados.txt":*
```plaintext
Número Cliente | Saldo Apurado | Tipo de Saldo
----------------------------------------------
48             | 7.5           | Credor
20             | 3.4           | Credor
2              | 52.0          | Credor
```

**Parte 6 - Menu Interativo/Programa Principal**

No programa principal (main), crie um menu interativo com as seguintes opções:
a) Gerar relatório de saldo de operações por cliente.
b) Listar saldo de operações por cliente.
c) Sair do programa.

*Exemplo de Saída (console ou arquivo "resultados.txt"):*
```plaintext
Número Cliente | Saldo Apurado | Tipo de Saldo
----------------------------------------------
48             | 7.5           | Credor
20             | -50.8         | Devedor
2              | 52.0          | Credor
```
