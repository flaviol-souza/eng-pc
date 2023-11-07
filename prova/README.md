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
