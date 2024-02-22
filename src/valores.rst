Tipos básicos
=============

Inteiros
--------

Os valores inteiros são representados, ao nível da máquina, em binário, no sistema de significância posicional.
O conjunto dos números naturais têm uma representação direta
e o conjunto de números relativos são codificados em código dos complementos.
Na :numref:`tipos_c_kotlin` apresentam-se os identificadores de tipo,
assim como as dimensões de representação nas linguagens Kotlin e C, medida em *bytes*.

Como a linguagem C não define dimensões concretas para
os tipos numéricos ``char``, ``int``, ``short int`` e ``long int``,
foi definido, ao nível da `biblioteca normalizada <https://en.cppreference.com/w/c/types/integer>`_,
a existência dos tipos ``intXX_t`` sendo ``XX``
o número de *bits* dessa representação concreta.
A variante ``uintXX_t`` representa valores no conjunto dos números naturais
e a variante ``intXX_t`` representa valores no conjunto dos números relativos.

As palavras ``short`` e ``long`` atuam como modificadores de dimensão no tipo ``int``,
produzindo representações com menor ou maior número de *bits*, respetivamente.
Sintaticamente estas palvras podem aparecem isoladas (sem ``int`` à frente)
com o mesmo significado.


.. table:: Tipos numéricos da linguagem C e Kotlin
   :widths: auto
   :align: center
   :name: tipos_c_kotlin

   +--------------------------------+-----------------------------------------------+--------------------------------------+
   | Linguagem Kotlin               |           Linguagem C                         | Processador                          |
   +===============+================+======================+========================+============+============+============+
   | **Relativos** | **Naturais**   | **Relativos**        | **Naturais**           | **16 bit** | **32 bit** | **64 bit** |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ``Byte``      | ``UByte``      | ``signed char``      | ``unsigned char``      | 1          | 1          | 1          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ``Short``     | ``UShort``     | ``signed short int`` | ``unsigned short int`` | 2          | 2          | 2          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ``Int``       | ``UInt``       | ``signed int``       | ``unsigned int``       | 2          | 4          | 4          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ``Long``      | ``ULong``      | ``signed long int``  | ``unsigned long int``  | 4          | 4          | 8          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ..            | ..             | ``int8_t``           | ``uint8_t``            | 1          | 1          | 1          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ..            | ..             | ``int16_t``          | ``uint16_t``           | 2          | 2          | 2          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ..            | ..             | ``int32_t``          | ``uint32_t``           | 4          | 4          | 4          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+
   | ..            | ..             | ``int64_t``          | ``uint64_t``           | 8          | 8          | 8          |
   +---------------+----------------+----------------------+------------------------+------------+------------+------------+

O domínio de valores representável depende da dimensão da palavra em número de *bits*.
Na :numref:`tipos_dimensoes` apresentam-se os domínios de valores representáveis
para as dimensões de palavra de 8, 16, 32 e 64 *bits* para números naturais ou relativos.

A escolha, por parte do programador, do tipo da variável a empregar,
está relacionada com a utilização eficiente da memória,
face ao domínio de representação necessário no programa.


.. table:: Domínio de valores face à dimensão da palavra
   :widths: auto
   :align: center
   :name: tipos_dimensoes

   +----------+-----------------------------------+---------------------------------------------+
   | Dimensão | Naturais                          | Relativos                                   |
   +==========+============+======================+======================+======================+
   | (bits)   | **Mínimo** | **Máximo**           | **Mínimo**           | **Máximo**           |
   +----------+------------+----------------------+----------------------+----------------------+
   | 8        | 0          | 255                  | -128                 | +127                 |
   +----------+------------+----------------------+----------------------+----------------------+
   | 16       | 0          | 65535                | -32768               | +32767               |
   +----------+------------+----------------------+----------------------+----------------------+
   | 32       | 0          | 4294967295           | -2147483648          | +2147483647          |
   +----------+------------+----------------------+----------------------+----------------------+
   | 64       | 0          | 18446744073709551615 | -9223372036854775808 | +9223372036854775807 |
   +----------+------------+----------------------+----------------------+----------------------+

Carateres
---------

Apesar de se utilizar principalmente o tipo `char` para representar carateres,
também se pode utilizar o tipo `int`.
O tipo `char` é encarado como se fosse um tipo inteiro com menos *bits*.

Booleanos
---------

Uma variável do tipo ``bool`` pode assumir os valores ``true`` ou ``false``.

Os valores numéricos dos tipos ``char``, ``short``, ``int`` ou ``long``
podem ser avaliados como valores booleanos com o seguinte critérios:
o valoe zero é avaliado como ``false`` e um valor diferente de zero é avaliado como ``true``.

Literais
========

Inteiros
--------

.. table:: Valores literais inteiros
   :widths: auto
   :align: center
   :name: literais_inteiros

   +-------------+--------------------------------------------+------------------------------+
   | Base        | Sintaxe                                    | Exemplos                     |
   +=============+============================================+==============================+
   | decimal     | cddddd   c = 1 ... 9, d = 0 ... 9          | 123  (cento e vinte e três)  |
   +-------------+------------+-------------------------------+------------------------------+
   | binária     | 0bdddd   d = 0 ... 1                       | 0b101  (cinco)               |
   +-------------+------------+-------------------------------+------------------------------+
   | hexadecimal | 0xdddd   d = 0 ... 9 ou a ... f ou A ... F | 0x1f   (trinta e um)         |
   +-------------+------------+-------------------------------+------------------------------+
   | octal       | 0ddddd   d = 0 ... 7                       | 023    (dezanove)            |
   +-------------+------------+-------------------------------+------------------------------+

Para melhorar a legibilidade de números extensos podem-se agrupar dígitos separados por plicas.

   +---------------+----------------+------------------------------+
   |   100000000   | 100'000'000    | cem milhões                  |
   +---------------+----------------+------------------------------+
   | 0b100000000   | 0b1'0000'0000  | duzentos e cinquenta e seis  |
   +---------------+----------------+------------------------------+

Caracteres
----------

Especificação de um caractere literal: \'0\' ... \'9\' \'a\'...\'z\' \'A\'...\'Z\'

Um carater literal também pode ser definido através do seu código numérico,
em qualquer das base aceites pela linguagem C.
Exemplos: \'\\48\' - caractere cujo código numérico é 48;
\'\\x30\' - caractere cujo código numérico é 48.

.. table:: Sequências de escape
   :widths: auto
   :align: center
   :name: sequencias_escape

   +--------------------------+--------------------------------+------------------------------------+----------------------------------+
   | **\'\\n\'** - nova linha | **\'\\r\'** - retorno de carro | **\'\\t\'** - tabulador horizontal | **\'\\v\'** - tabulador vertical |
   +--------------------------+--------------------------------+------------------------------------+----------------------------------+
   | **\'\\a\'** - alerta     | **\'\\b\'** - recuar cursor    | **\'\\f\'** - avanço de página     |                                  |
   +--------------------------+--------------------------------+------------------------------------+----------------------------------+
   | **\'\\\\\'** - o próprio | **\'\\\'\'** - plica           | **\'\\\"\'** - aspas               |                                  |
   +--------------------------+--------------------------------+------------------------------------+----------------------------------+

Variáveis
=========

Variáveis simples
-----------------

Uma variável define-se com a seguinte sintaxe:

{*tipo*} {*nome*};

Exemplos:

   ``char c;``    Variável do tipo ``char`` com o nome ``c``

   ``int i;``     Variável do tipo  ``int`` com o nome ``index``

   ``uint8_t x;`` Variável do tipo inteiro natural representada a 8 *bits* com o nome ``x``

   ``int16_t y;`` Variável do tipo inteiro relativo representada a 16 *bits* com o nome ``y``

Definição de variável com inicialização:

{*tipo*} {*nome*} = {*valor*};

Exemplos com inicialização:

   ``char c = 'a';``    Variável inicializada com o código numérico do caractere \'a\'.

   ``int i = 0;``     Variável inicializada com o valor zero.

   ``uint8_t x = 0xff;`` Variável inicializada com o valor máximo.

   ``int16_t y = -1;`` Variável inicializada com menos um.

*Array* de variáveis
--------------------

Arrays são sequências de valores do mesmo tipo armazenados em posições de memória contiguas.

Um *array* define-se com a seguinte sintaxe:

{*tipo*} {*nome*} **[** {dimensão} **]**;

Exemplos de definição:

   ``char c[10];``    *Array* de dez caracteres.

   ``int fruit[100];``    *Array* de cem valores inteiros.

O acesso aos elementos do *array* realiza-se apenas através do operador indexação **[]**.
Os índices vão de zero -- primeira posição -- à dimensão menos um -- última posição.

No exemplo anterior, as posições do *array* ``fruit`` vão de 0 a 99.

Exemplos de acesso:

   ``fruit[0] = 34;`` A primeira posição do *array* ``fruit`` é afetada com trinta e quatro.

   ``c[9] = 'f';`` A última posição do *array* ``c`` é afetado com o código numérico da letra 'f'.

Em linguagem C não se pode afetar um *array*
com a totalidade do conteúdo de outro *array* numa operação de afetação.
Poder-se-á contudo, realizar a afetação posição a posição.

Considerando: ::

   int a[3];
   int b[] = {10, 20, 30}:

``a = b;`` é inválido ::

   a[0] = b[0];
   a[1] = b[1];
   a[2] = b[2];

é válido, embora não seja o código adequado para expressar a cópia um *array* extenso.

Definição de *arrays* com inicialização
.......................................

{*tipo*} {*nome*}[] = {*lista de valores*};

Exemplos com inicialização:

   ``char c[] = {'a', 'b', 'c', 'd'};`` *Array* de quatro caracteres inicializado
   com o código numérico de \'a\' na primeira posição, de \'b\' na segunda posição,
   de \'c\' na terceira posição e de \'d\' na quarta posição.

   ``uint8_t x[] = {0xff, 0xaa};`` *Array* de duas posições iniciado
   com ``0xff`` e ``0xaa`` nas primeira e segunda posições, respetivamente.

   ``int i[10] = {0};`` *Array* de dez posições, com todas as posições iniciadas a zero.

   ``int32_t k[100] = {0b00110011, 0xfa, 167, 028};`` *Array* com cem posições.
   As primeiras quatro são inicializadas como os valores indicados,
   as restantes são inicializadas com zero.

Strings
=======

A linguagem C não define formalmente a existência de variáveis do tipo *string*
como String em Java ou em Kotlin.
No entanto utiliza a mesma notação sintática para definir literais do tipo *string*. ::

   “Isto é uma string literal em C, em Java ou em Kotlin”

Em linguagem C um literal do tipo *string* é formalmente considerado um *array* de elementos do tipo ``char``.

No exemplo ::

   char name[] = “Ana”;

os códigos numéricos dos caracteres que compõem a palavra \“Ana\”
são armazenados nas sucessivas posições do *array* ``name``.
Na posição a seguir à do código do último caractere é colocado o valor numérico zero,
para indicar o final da string (indiretamente define a dimensão da string).
Assim, a definição acima produz um *array* de valores do tipo ``char`` com quatro posições.


Exemplos de definição de *strings* em C: ::

   char string1[] = "string terminada com mudança de linha\n";

   char string2[] = "uma string separada"
                    "em duas linhas";

Em linguagem C não é possível embutir valores em *strings* usando $,
nem é possível definir texto em bruto delimitado por três aspas \”\”\”,
como em Kotlin.

Constantes
==========

Um valor constante define-se de forma idêntica à definição de uma variável com inicialização.
Sintaticamente, é caraterizado pela definição começar pela palavra ``const``.

Exemplos de constantes:

   ``const int limit = 1000;`` Definição da constante ``limit`` com o valor mil.

   ``const char message[] = "Cuidado com o cão";`` O conteúdo do *array* ``message`` não pode ser alterado.

Conversão de tipos
==================
Na linguagem C é possível afetar uma variável do qualquer tipo básico
com um valor também de qualquer tipo básico.
A representação dos tipos numéricos (char, short, int, long) diferem entre si
apenas no número de *bits*.

Conversão sem perda de informação
---------------------------------

Na conversão de tipo cujo domínio de representação está contido no domínio
de representação do tipo destino --
representação com menos *bits* para representação com mais *bits* --
não há perda de informação.
Para manter a mesma representação numérica os *bits* de maior peso
recebem zero no caso de valores naturais
ou o valor do *bit* de sinal no caso de valores relativos.

Conversão com perda de informação
---------------------------------

Na conversão de tipo cujo domínio de representação é diferente
do domínio de representação do tipo destino, pode haver perda de informação.
Para o evitar, cabe ao programador garantir
que o valor a converter é representável no domínio do tipo destino.

Conversão entre valores numéricos e booleanos
---------------------------------------------
No sentido de valor numérico para booleano, o valor zero converte para **false**
e um valor diferente de zero converte para **true**.

No sentido de valor booleano para numérico, o valor **false** converte para zero
e o valor **true** converte para um.

Macros
======

A compilação da linguagem C é realizada em dois passos.
O primeiro passo, designado por pré-processamento, atua ao nível
da modificação do texto escrito pelo programador.
O segundo passo é a compilação propriamente dita.

A *macros* é um dos mecanismos de pré-processamento que opera a substituição de texto.

Define-se numa única linha de texto com a seguinte sintaxe:

#define {*símbolo*} {*texto de substituição*}

O pré-processador substitui a ocorrência do {*símbolo*}, no código do programa,
pelo {*texto de substituição*}.

No exemplo ::

   #define DIM  1000

   int array[DIM];

o pré-processador troca ``DIM`` por ``1000``, na definição de ``array``.
O código anterior é efetivamente compilado como: ::

   int array[1000];

Expressões
==========

Operações aritméticas
---------------------

.. table:: Operadores aritméticos
   :widths: auto
   :align: center

   +-----------------+----------------------+--------------------------------+---------------------+
   | **+** adição    | **\*** multiplicação | **%** resto da divisão inteira | **++** incremento   |
   +-----------------+----------------------+--------------------------------+---------------------+
   | **-** subtração | **/** divisão        |                                | **\-\-** decremento |
   +-----------------+----------------------+--------------------------------+---------------------+

Operações *bit-a-bit* (*bitwise*)
---------------------------------

.. table:: Operadores *bit-a-bit*
   :widths: auto
   :align: center

   ======================== ====== =======
   Operação                 C      Kotlin
   ======================== ====== =======
   conjunção                a & b  a and b
   disjunção                a | b  a or b
   disjunção exclusiva      a ^ b  a xor b
   negação                  ~a     inv a
   deslocar para a esquerda a << 3 a shl 3
   deslocar para a direita  b >> 8 b shr 8
   ======================== ====== =======

No deslocamento para a direita, o *bit* de maior peso
mantém o valor se estiver a operar sobre um tipo com sinal
ou recebe zero se estiver a operar sobre um tipo sem sinal.

Exemplos:

===================================================================== =======================
Deslocar um valor para a esquerda **p** posições                      ``b = a << p``
Colocar **0** no *bit* da posição **p**                               ``b = a & ~(1 << p);``
Colocar **1** no *bit* da posição **p**                               ``b = a | 1 << p``
Isolar o *bit* da posição **p**                                       ``b = a & (1 << p))``
Formar um sequência de **n** *bits* a **1** a partir da posição **p** ``b = ~(~0 << n) << p``
===================================================================== =======================

Operações relacionais
------------------------

.. table:: Operadores relacionais
   :widths: auto
   :align: center

   ====== ============== ===== =========== ====== ================
   **==** igual a        **>** maior que   **>=** maior ou igual a
   **!=** diferente de   **<** menor que   **<=** menor ou igual a
   ====== ============== ===== =========== ====== ================

Das operações relacionais resultam valores booleanos -- **true** ou **false**.

::

   int x = 20;
   bool y = x == 20;

Operações booleanas
-------------------

.. table:: Operadores booleanos
   :widths: auto
   :align: center

   ====== =========    ====== =========   =====  =======
   **&&** conjunção    **||** disjunção   **!**  negação
   ====== =========    ====== =========   =====  =======

A avaliação de expressões booleanas realiza-se da esquerda para a direita.
Se na avaliação uma sub-expressão o resultado for igual ao elemento absorvente,
as restantes sub-expressões já não serão avaliadas (*lazzy evaluation*).

Os operandos naturais destes operadores são valores booleanos.
Nas versões da linguagem anteriores à C23 não existia tipo **bool**,
por isso é comum verem-se expressões booleanas em que os operandos são valores numéricos.

::

   int flag;

   if (!flag)
      ...

O que acontece nestes casos, é uma conversão implícita de valor numérico
para valor booleano. A regra é a seguinte:
um valor numérico de zero é equivalente a **false**
e um valor numérico diferente de zero é equivalente a **true**.

Expressão condicional
---------------------

A expressão

::

   var = expr1 ? expr2 : expr3;

é equivalente a

::

   if (expr1)
   	var = expr2;
   else
   	var = expr3;

com a diferença de poder ser utilizada onde é suposto aparecer um valor.

Exemplo:

::

   int minor = a < b ? a : b;

Operador afetação
-----------------

A utilização mais comum do operador **=** é na simples afetação de valores a variáveis.

::

   int x = 20;
   int y = x * 10;

Em linguagem C os operadores afetação produzem valor.
Podem ser embebidos numa expressão e o seu resultado ser operado por um operador.
O valor produzido pela operação de afetação é o valor do operando do lado direito.

::

   while ((c = getchar()) != '\n')
      ;

Primeiro a variável **c** é afetada com o valor do código do caractere devolvido por ``getchar()``.
Desta afetação resulta esse valor, que vai ser comparado com o código do caractere ``\n``.

Também permite realizar uma cadeia de afetações.

::

   a = b = c = 7;

Como associa da direita para a esquerda, a expressão anterior é equivalente a

::

   a = (b = (c = 7));

Tem a seguinte interpretação: afeta **c** com **7** donde resulta o valor **7**
que por sua vez é afetado à variável **b**, donde resulta o mesmo valor **7**
que por sua vez é afetado à variavel **a**. Ficando todas as variáveis com o mesmo valor.

Os operadores **+= -= *= /= %= &= ^= |= <<= >>=** realizam a operação indicada à esquerda do sinal **=**.
A variável escrita à esquerda é o destino e o primeiro operando.

Por exemplo ``m |= 2`` é equivalente a ``m = m | 2``.

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

::

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


continue
--------

É utilizado num bloco while, do while ou for. Provoca o avanço para a próxima iteração.

Funções
=======

::

   return-type function-name(argument list)
   {
       statements
   }

No exemplo

::

   int minimum(int a, int b)
   {
       if (a < b)
           return a;
       else
           return b;
   }

a função tem o nome ``minimum``, devolve um valor do tipo ``int``,
tem dois parâmetros, ambos do tipo ``int``.

Os parâmetros são escritos com uma sintaxe igual à declaração de variáveis.
Separados por **,** (vírgula).

Se o return-type for omitido significa que a função devolve um valor do tipo ``int``.

Para indicar que a função não tem valor associado,
deve colocar-se a palavra ``void`` no lugar do tipo de retorno.

::

   void delay(int cicles)
   {
       while (cicles--)
           ;
   }

A lista de parâmetros também pode ser omitida.
Neste caso o significado é que a função não recebe argumentos.
(Nem sempre foi assim, em versões antigas tinha outro significado.)

Relativamente a outras linguagens de programação, na linguagem C:
   * a passagem de argumentos é posicional -- não existe passagem de argumentos nomeados;
   * não existe sobrecarga de funções -- não se podem redefinir funções com o mesmo nome;
   * não existem argumentos por omissão.

*Array* como parâmetro
----------------------

Considere-se a seguinte função que verifica se um *array* de inteiros contém um dado valor.

::

   bool contains(int array[], int array_size, int value)
   {
       bool result = false;
       int i = 0;
       while (i < array_size) {
           if (array[i] == value) {
               result = true;
               break;
           }
           i++;
       }
       return result;
   }


Conside-se o seguinte programa de teste da função ``contais``.

::

   int numbers[] = {45, 25, 50, 55, 57, 85};

   bool has_five;

   int main()
   {
      has_five = contains(numbers, 6, 5);
   }

Na declaração de um argumento de função do tipo *array* não se indica a dimensão do *array*.
É o caso de ``int array[]`` em ``contains``.

::

   bool contains(int array[], int array_size, int value);

Formalmente pode figurar, mas é ignorada pelo compilador, não tem qualquer efeito.

::

   bool contains(int array[333], int array_size, int value);

Na passagem de um *array* como argumento de função,
apenas é passada a informação sobre o endereço inicial do *array* em memória.
No interior de uma função não há maneira de obter a dimensão de um  *array*
que está a ser recebido em parâmetro.
Algo como ``array.length`` não existe em linguagem C.
Essa é a justificação para a existência do segundo parâmetro ``array_size``
na função ``contains``.

Na linguagem C, um *array* como parâmetro é sempre acompanhado de algum artifício
que permita operar o array dentro dos seus limites.

No caso das funções que manipulam *strings*, que são suportadas por *arrays* de caracteres,
a informação sobre a dimensão está no termindador da *string* -- valor zero após o último caractere da *string*.

Na função ``strcmp`` a sub-expressão ``str1[i] != 0``
serve para não se ultrapassar os limites dos *arras*.
Esta sub-expressão só será avaliada como falsa se as *strings* forem iguais.

::

   int strcmp(const char str1[], const char str2[])
   {
      for (int i = 0; str1[i] != 0 && str1[i] == str2[i]; ++i)
         ;
      return str1[i] - str2[i];
   }

O método de utilizar um valor marcador para indicar o final do *array*
só pode ser aplicado se o marcador não for um valor possível de dados no *array*.

Parâmetros constantes
---------------------

A utilização da palavra ``const`` na declaração de parâmetros
significa que os argumentos não podem ser modificados durante a execução da função.
No caso de *arrays*, significa que o conteúdo do array não pode ser alterado.

Sem o atributo ``const`` os parâmetros de funções assumem o papel de variáveis locais.

.. code-block:: C
   :linenos:

   int f(const char string[], int i)
   {
      if (string[i] != '\0')
         string[i] += ' ';
      i += 3;
   }

No exemplo, a tentativa de alteração do conteúdo de ``string`` na linha 3
é assinalada com erro pelo compilador.

A instrução da linha 4 adiciona 3 ao parâmetro ``i``, como se fosse uma variável comum.

Estrutura de um programa em C
=============================

Um programa em C é organizado como uma sequência de funções e variáveis.

As funções não podem conter outras funções mas podem conter variáveis.

Qualquer variável ou função deve ser declarada antes de ser invocada.

O ponto de entrada na execução de um programa é a função **main**
(em certas circunstâncias pode ter outro nome).

A linguagem C dispõe de uma biblioteca normalizada,
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
A variável ``z`` só tem existência enquanto o processamentos estiver a decorrer
entre as linhas 11 e 12.
A variável y tem existência enquanto o processamento estiver a decorrer entre as linhas 9 e 13.

As variáveis são também classificadas como variáveis estáticas ou automáticas.
As automáticas são as variáveis locais que são criadas e eliminadas à medida que
a execução do programa entra e sai do âmbito do bloco.
As variáveis estáticas são aquelas que estão permanentemente alocadas em memória
-- têm um tempo de vida igual ao do programa.
É o caso das variáveis globais.

As variáveis locais há dos dois tipo, as estáticas e as automáticas.
As estáticas são assinaladas com a colocação da palavra **static** antes da definição.

::

   void f()
   {
       static int i;
       int j;
   }

No exemplo acima, i é uma variável estática tem uma localização em memória
permanenete e exclusiva,
é criada no arranque do programa e é inicializada com zero.
A variável j, é criada e eliminada à entrada e à saída de função f, respetivamente.
O seu valor inicial é indefinido.

Exemplo de programa
-------------------

O objetivo do programa é contar as ocorrências das vogais em frases.
É baseado na função ``histogram_vowel`` que recebe a frase a analisar
e um *array* para recolher as contagens das vogais.
Esta função tem a seguinte declaração:

.. literalinclude:: ../code/letters.c
   :language: c
   :lines: 30

O primeiro parâmetro -- ``phrase`` -- representa um *array* de caracteres
com a frase a processar.
O segundo parâmetro -- ``max_letters`` --, inteiro natural representado a 16 *bits*,
indica o número máximo de caracteres a processar.
O terceiro parâmetro -- ``occurrences`` -- é um *array* com cinco posições
de inteiros naturais, em que cada posição recebe a contagem de cada uma das vogais.

.. literalinclude:: ../code/letters.c
   :language: c
   :linenos:
   :caption: Programa para contar vogais
   :name: letters_main
   :lines: 3-6, 9-12, 40-45

Na :numref:`letters_main`, nas linhas 1 a 3, definem-se três frases.
São *arrays* de caracteres,
inicializados com o código dos caracteres que compõem as *strings*,
cujas dimensões são iguais às dimensões das *strings* mais um -- o terminador \'\\0\'.
Os *arrays* ``phrase1`` e ``phrase2`` têm a dimensão vinte
e o *array* ``phrase3`` tem a dimensão seis.

Nas linhas 5 a 7, definem-se três *array* para receberem as contagens. Os elementos
destes *arrays* são do tipo inteiro natural, representados a 16 *bits* (``uint16_t``).

Em linguagem C, as variáveis de localização estática sem valor inicial definido,
são inicializadas com zero.
É o caso destes três *arrays*,
ambos, e todas as suas posições, são inicializadas com o valor zero.

O símbolo ``SIZE``, que aparece na definição da dimensão destes *arrays*,
é uma macro definida de seguinte forma:

.. literalinclude:: ../code/letters.c
   :language: c
   :lines: 7

Nas linhas 10 a 12, invoca-se a função ``histogram_vowel`` para cada uma das frases.
Na linha 10, é invocada com o *array* ``phrase1`` como primeiro argumento,
o valor 18 como número máximo da caracteres a processar e por último o *array* ``ocurrencies1``.

.. literalinclude:: ../code/letters.c
   :language: c
   :linenos:
   :caption: Definição da função ``histogram_vowel``
   :name: histogram_vowel
   :lines: 31-38

O corpo principal da função ``histogram_vowel`` consiste em iterar sobre as posições do array ``phrase``,
a começar na primeira posição -- ``uint16_t i = 0`` --
até se encontrar o terminador da *string* -- ``phrase[i] != '\0'`` --
ou se ter atingido o máximo de iterações -- ``i < max_letters``.

Em cada iteração, é invocada a função ``find_vowel``,
que recebe o código de uma letra e a classifica.
A classificação é retornada como valor da função, na forma de um inteiro relativo,
representado a 16 *bits*.
Se a letra for uma vogal, é retornado o valor 0 para \'a\', 1 para \'e\'
e assim sucessivamente até, 4 para \'u\'.
Se a letra não for uma vogal, é retornado -1.

A invocação de ``find_vowel`` está embebida na expressão de afetação
``idx = find_vowel(phrase[i])``, cujo valor é o valor retornado por ``find_vowel``.
Esse valor é depois comparado com a constante literal -1 (linha 5).
Se for diferente é contabilizada a ocorrência de uma vogal (linha 6).

A indicação [5] na declaração do parâmetro ``uint16_t occurrences[5]`` é meramente ilustrativa.
Não tem qualquer consequência no funcionamento do programa.
Essa declaração é equivalente a ``uint16_t occurrences[]`` (sem indicação de dimensão).

A única informação passada como argumento num parâmetro do tipo *array*,
como ``phrase`` ou ``occurrences``,
é o local da memória onde estão alojados os *arrays*.

A sub-expressão ``ocurrencies[idx]``
dá acesso direto à posição do *array* utilizado como argumento de ``histogram_vowel``.
(na invocação da linha 10 na :numref:`letters_main`, o *array* ``occurrencies1``).
O valor de ``idx`` situa-se entre 0 e 4.
O *array* utilizado como argumento deve ter pelo menos 5 posições.

Na compilação de uma função,
o compilador da linguagem C não realiza qualquer verificação
da ultrapassagem dos limites de um *array* passado em parâmetro,
nem ativa qualquer mecanismo de verificação em execução.
Na hipótese de o *array* passado como argumento em ``occurrences``
ter uma dimensão inferior a 5,
uma escrita na posição 4 consumaria um **acesso inválido** à memória,
com efeito imprevissível.

Poder-se-ão alvitrar alguns efeitos:
   * o endereço de memória acedido é viável e não está atribuido a outra variável
     -- o programa tem um comportamento "normal";
   * o endereço de memória acedido não é viável
     -- o programa poderá terminar abruptamente ou o acesso ser ignorado;
   * o endereço de memória acedido está atribuido a outra variável
     -- o efeito notar-se-á mais tarde,
     com comportamentos incompreensiveis no contexto de utilização dessa variável.

.. literalinclude:: ../code/letters.c
   :language: c
   :linenos:
   :caption: Definição da função ``find_vowel``
   :name: find_vowel
   :lines: 13-29

Na :numref:`find_vowel` a função ``find_vowel`` baseia-se na utilização de uma
estrututa *switch/case*.

As notações de caracteres entre plicas \' \',
representam o código numérico do caractere indicado. Por exemplo, \'a\'
origina o número 97, se se utilizar a codificação ASCII.
Conforme o valor numérico em ``letter``, a construção *switch* realiza um salto
para a linha *case* com valor numérico igual. No caso do valor numérico de ``letter``
não estar contemplado em nenhum *case* o salto dá-se para *default*.
Em qualquer caso é executado imediatamente o retorno da função
com um valor de classificação associado a *return*.

**Código completo:** :download:`letters.c<../code/letters.c>`
