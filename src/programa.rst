Estrutura de um programa em C
=============================

Um programa em C é organizado como uma sequência de funções e variáveis.

As funções não podem conter outras funções mas podem conter variáveis.

Qualquer variável ou função deve ser declarada antes de ser invocada.

O ponto de entrada de execução num programa é a função **main**
(em certas circunstâncias pode ter outro nome).

A linguagem C dispõe de uma `biblioteca normalizada <https://en.cppreference.com/w/c/types/integer>`_,
essencialmente contendo código de funções.

Variáveis
--------------------

As variáveis definidas no interior de funções chamam-se variáveis locais.
As outras chamam-se variáveis globais e podem ser acedidas por todas as funções.
As variáveis locais também têm a designação de variáveis automaticas.
São as declaradas no âmbito de um bloco (abrir e fechar chavetas).
Têm existência temporária --
são criadas durante a execução do bloco e descartadas à saída do bloco.

.. code-block:: C
   :linenos:

      int x = 10;

      int f(char c)
      {
        int g = ' ';
        return c + g;
      }

      int main()
      {
         char y = 'a';
         if (x == 2) {
            bool z = true;
         }
         f(y);
      }

No exemplo, a variável ``x`` é global, ``y`` e ``z`` são  locais.
A variável ``z`` só tem existência enquanto o processamento estiver a decorrer
entre as linhas 12 e 13.
A variável y tem existência enquanto o processamento estiver a decorrer entre as linhas 10 e 16.

As variáveis são também classificadas como variáveis estáticas ou automáticas.
As automáticas são as variáveis locais que são criadas e eliminadas à medida que
a execução do programa entra e sai do âmbito do bloco.
As variáveis estáticas são aquelas que estão permanentemente alocadas em memória
-- têm um tempo de vida igual ao do programa.
É o caso das variáveis globais.

As variáveis locais, há dos dois tipos, as estáticas e as automáticas.
As estáticas são assinaladas com a colocação da palavra **static** antes da definição.

::

   void f()
   {
       static int i;
       int j;
   }

No exemplo acima, **i** é uma variável estática tem uma localização em memória
permanenete e exclusiva, como as variáveis globais.
É criada no arranque do programa, inicializada com zero.
A variável **j**, é criada e eliminada à entrada e à saída da função **f**,
com valor inicial indefinido.

Exemplo de programa
-------------------

O objetivo do programa é contar as ocorrências das vogais em frases.
É baseado na função ``histogram_vowel`` que recebe a frase a analisar
e um *array* para recolher as contagens das vogais.
Esta função tem a seguinte declaração:

.. literalinclude:: ../code/vowels.c
   :language: c
   :lines: 61

O primeiro parâmetro -- ``phrase`` -- representa um *array* de caracteres
com a frase a processar.
O segundo parâmetro -- ``max_letters`` --, inteiro natural representado a 16 *bits*,
indica o número máximo de caracteres a processar.
O terceiro parâmetro -- ``occurrences`` -- é um *array* com cinco posições
de inteiros naturais, em que cada posição recebe a contagem de cada uma das vogais.

.. literalinclude:: ../code/vowels.c
   :language: c
   :linenos:
   :caption: Programa para contar vogais
   :name: letters-main
   :lines: 3-5, 8-11, 70-75

Na :numref:`letters-main`, nas linhas 1 a 3, definem-se três frases.
São *arrays* de caracteres,
inicializados com o código dos caracteres que compõem as *strings*,
cujas dimensões são iguais às dimensões das *strings* mais um -- o terminador \'\\0\'.
Os *arrays* ``phrase1`` e ``phrase2`` têm a dimensão vinte
e o *array* ``phrase3`` tem a dimensão seis.

Nas linhas 5 a 7, definem-se três *array* para receberem as contagens. Os elementos
destes *arrays* são do tipo inteiro natural, representados a 16 *bits* (``uint16_t``).

Em linguagem C, as variáveis de localização estática sem valor inicial explícito,
são inicializadas com zero.
É o caso destes três *arrays*,
ambos, e todas as suas posições, são inicializadas com o valor zero.

O símbolo ``SIZE``, que aparece na definição da dimensão destes *arrays*,
é uma macro definida de seguinte forma:

.. literalinclude:: ../code/vowels.c
   :language: c
   :lines: 6

Nas linhas 11 a 13, invoca-se a função ``histogram_vowel`` para cada uma das frases.
Na linha 11, é invocada com o *array* ``phrase1`` como primeiro argumento,
o valor 18 como número máximo da caracteres a processar e por último o *array* ``ocurrencies1``.

.. literalinclude:: ../code/vowels.c
   :language: c
   :linenos:
   :caption: Definição da função ``histogram_vowel``
   :name: histogram_vowel
   :lines: 61-68

O corpo principal da função ``histogram_vowel`` consiste em iterar sobre as posições do array ``phrase``,
a começar na primeira posição -- ``uint16_t i = 0`` --
até se encontrar o terminador da *string* -- ``phrase[i] != '\0'`` --
ou se atingir o máximo de iterações -- ``i < max_letters``.

Em cada iteração, é invocada a função ``find_vowel``,
que recebe o código de uma letra e a classifica.
A classificação é retornada como valor da função, na forma de um inteiro relativo,
representado a 16 *bits*.
Se a letra for uma vogal, é retornado o valor 0 para \'a\', 1 para \'e\'
e assim sucessivamente até, 4 para \'u\'.
Se a letra não for uma vogal, é retornado -1.

.. literalinclude:: ../code/vowels.c
   :language: c
   :lines: 15

A invocação de ``find_vowel`` está embebida na expressão de afetação
``idx = find_vowel(phrase[i])``, cujo valor é o valor retornado por ``find_vowel``.
Esse valor é afetado a ``idx`` e depois comparado com a constante literal -1 (linha 5).
Se for diferente é contabilizada a ocorrência de uma vogal (linha 6).

A indicação [5] na declaração do parâmetro ``uint16_t occurrences[5]`` é meramente ilustrativa.
Não tem qualquer consequência no funcionamento do programa.
Essa declaração é equivalente a ``uint16_t occurrences[]`` (sem indicação de dimensão).

A única informação passada como argumento num parâmetro do tipo *array*,
como ``phrase`` ou ``occurrences``,
é o local da memória onde estão alojados os *arrays*.

A sub-expressão ``ocurrencies[idx]``
dá acesso direto à posição do *array* utilizado como argumento de ``histogram_vowel``.
Na invocação da linha 10 na :numref:`letters-main`, é o *array* ``occurrencies1``.
O valor de ``idx`` situa-se entre 0 e 4.
O *array* utilizado como argumento deve ter pelo menos 5 posições.

Na compilação de uma função,
o compilador da linguagem C não realiza qualquer verificação
da ultrapassagem dos limites de um *array* passado em parâmetro,
nem ativa qualquer mecanismo para verificação em execução.
Na hipótese de o *array* passado como argumento em ``occurrences``
ter uma dimensão inferior a 5,
uma escrita na posição 4 consumaria um **acesso inválido** à memória,
com efeito imprevisível.

Poder-se-ão alvitrar alguns efeitos:
   * o endereço de memória acedido é viável e não está atribuido a outra variável
     -- o programa tem um comportamento "normal";
   * o endereço de memória acedido não é viável
     -- o programa poderá terminar abruptamente ou o acesso ser ignorado;
   * o endereço de memória acedido está atribuido a outra variável
     -- o efeito notar-se-á mais tarde,
     com comportamentos incompreensiveis no contexto de utilização dessa variável.

+---------------------------------------------------+---------------------------------------------------+
|.. literalinclude:: ../code/vowels.c               |.. literalinclude:: ../code/vowels.c               |
|   :language: c                                    |   :language: c                                    |
|   :linenos:                                       |   :linenos:                                       |
|   :caption: Definição da função ``find_vowel`` (a)|   :caption: Definição da função ``find_vowel`` (b)|
|   :name: find-vowel-a                             |   :name: find-vowel-b                             |
|   :lines: 15-31                                   |   :lines: 37-57                                   |
+---------------------------------------------------+---------------------------------------------------+

Nas :numref:`find-vowel-a` e :numref:`find-vowel-b` a função ``find_vowel`` baseia-se na utilização de uma
estrutura *switch/case*.

As notações de caracteres entre plicas \' \',
representam o código numérico do caractere indicado. Por exemplo, \'a\'
origina o número 97, se se utilizar a codificação ASCII.
Conforme o valor numérico em ``letter``, a construção *switch* realiza um salto
para a linha *case* com valor numérico igual.

Na :numref:`find-vowel-a`, no caso do valor numérico de ``letter``
não estar contemplado em nenhum *case* o salto dá-se para *default*.
Em qualquer caso é executado imediatamente o retorno da função
com o valor de classificação como argumento de ``return``.

Na :numref:`find-vowel-b`, aplica-se o princípio "uma entrada - uma saída".
A variável ``result`` é inicialmente afetada com -1, o valor que representa "não vogal",
depois será afetada com a classificação adequada no respetivo *case*, se for vogal.
A quebra *break* impede que o processamento siga para os casos seguintes.
No caso de ``letter`` não ser uma vogal a estrutura de *switch* não realiza qualquer processamento.

Exercício: Programar uma versão da função ``find_vowel`` que seja indiferente a letras maiúsculas e a minúsculas.

**Código completo:** :download:`vowels.c<../code/vowels.c>`
