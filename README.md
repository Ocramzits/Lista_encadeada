# Lista Encadeada em C

Implementação de uma **lista simplesmente encadeada** em C com menu interativo no terminal, cobrindo as operações clássicas de inserção, remoção, consulta e as versões recursivas dessas mesmas operações — feita para a disciplina de **Estrutura de Dados 1**.

## Sobre o projeto

O programa inicia a lista já com alguns valores (`3, 7, 53, 9, 15`) e abre um menu em loop, permitindo inserir, remover, consultar e exibir elementos, além de comparar abordagens **iterativas** e **recursivas** para os mesmos problemas.

## Funcionalidades

1. Inserir no início
2. Inserir em posição específica
3. Inserir no final
4. Exibir a lista
5. Consultar elemento por posição
6. Remover elemento por valor
7. Liberar toda a lista
8. Inserir em posição (versão recursiva)
9. Inserir em posição ordenada (versão recursiva)
10. Somar todos os elementos (versão recursiva)
11. Exibir a lista (versão recursiva)

## Conceitos aplicados

- **Alocação dinâmica de memória**: cada nó é criado com `malloc` e liberado com `free`, incluindo a liberação completa da lista (`liberar_lista`)
- **Ponteiros e structs auto-referenciadas**: a struct `no` contém um ponteiro para o próximo nó do mesmo tipo, formando a cadeia
- **Manipulação de ponteiro para a cabeça (head)**: operações como `inserir_inicio` e `remover_elemento` atualizam corretamente o ponteiro global `lista` quando o primeiro nó muda
- **Iteração vs. recursão**: cada operação de inserção em posição tem uma versão com laço (`for`/`while`) e outra recursiva (`inserir_posicao` x `inserir_posicao_recursivo`), reforçando os dois paradigmas para o mesmo problema
- **Inserção ordenada recursiva**: `inserir_posicao_ordenada_recursivo` percorre a lista comparando valores para inserir o novo nó na posição correta, mantendo a ordenação
- **Casos base e tratamento de bordas em recursão**: lista vazia, posição inválida e inserção no final da lista são tratados explicitamente para evitar desreferenciar ponteiros nulos
- **Acumulador em recursão**: `somar_recursivo` carrega o resultado parcial como parâmetro (`soma`) a cada chamada, técnica clássica de recursão com acumulador
- **Menu orientado a `switch` em loop `while(1)`**: fluxo de controle interativo típico de programas de terminal, com saída pelo `default`

## Como compilar e executar

```bash
gcc Lista_encadeada.c -o lista_encadeada
./lista_encadeada
```

O menu é exibido a cada iteração; basta digitar o número da operação desejada e seguir as instruções na tela. Qualquer opção fora de 1–11 encerra o programa.

## Autor

Marco Antônio — Sistemas de Informação, UFPI.