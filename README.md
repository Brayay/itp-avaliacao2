# itp-avaliacao2
Nome: Brayam Leônidas Fonseca de Lima
Projeto escolhido: Opção 1 - Boletim de uma pequena turma
Descrição: O programa registra três notas de cada estudante de uma turma de até 10 pessoas e mostra um resumo dos resultados.
Funcionalidades: Ler quantidade de estudantes, nome de cada um, 3 notas de cada estudante; Armazenar as notas em uma matriz; Calcular médias de cada estudante; Exibir tabela com todas as informações, média geral da turma e maior média

Compilar: gcc -std=c11 -Wall -Wextra main.c -o programa
Executar: .\programa

Teste 1: funcionamento normal
Entrada:
Quantidade de estudantes: 1
Nome: Ana
Notas: 5, 6 e 7
Resultado esperado: média 6,00, situação "atingiu a meta". Média geral 6,00 e maior média 6,00 (Ana).

Teste 2: entrada inválida
Entrada: ao digitar a nota 11 para um estudante.
Resultado esperado: o programa rejeita o valor, mostra a mensagem de nota inválida e pede a nota novamente.

Vídeo:
