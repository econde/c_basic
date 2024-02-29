Controlo da execução
====================

*if else*
---------

::

   if (boolean expression)
      statement1
   else
      statement2


*else if*
---------

::

   if (expression1)
      statement1
   else if (expression2)
      statement2
   else if (expression3)
      statement3
   else
      statement4

switch case
-----------

::

   switch (expression) {
       case const-expression1:
           statements1
       case const-expression2:
           statements2
       case const-expression3:
           statements3
       default:
           statements4
   }

while
-----

Repetição com condição inicial.

::

   while (expression)
       statement

do while
--------

Repetições com condição final.

::

   do {
       statement
   } while (expression);

for
---

A instrução ::

   for (expression1; expression2; expression3)
       statement;

é equivalente a ::

   expression1;
   while (expression2) {
       statement;
       expression3;
   }

Exemplo: somar o conteúdo de todos os elementos de um *array* usando **for**.

::

   int array[] = {10, 20, 30, 40};
   int accumulate = 0;
   for (int i = 0; i < 4; ++i)
      accumulate += array[i];


break
-----

A quebra pode aparecer no interior de uma formação de repetição
(**while**, **do while** ou **for**) ou no interior de um **switch**.
Tem o efeito de interromper a repetição
ou quebar a sequência de execução do **switch**.

Exemplo: dada a indicação do mês, na forma de um número de um a doze,
obter o número de dias do mês.

.. code-block:: C
   :linenos:

   int month;
   int days;

   switch (month) {
      case 2:
         days = 28;
         break;
      case 4:
      case 6:
      case 9:
      case 11:
         days = 30;
         break;
      default:
         days = 31;
   }

Porquê a colocação de ``break`` nas linhas 7 e 13? Porque, por definição,
a construção ``switch`` executa em sequência, até ao final (fechar **}**)
todo o código a jusante da entrada ``case`` selecionada.

continue
--------

É utilizado num bloco while, do while ou for.
Provoca o avanço para a próxima iteração,
sem executar o código até ao final do bloco.
