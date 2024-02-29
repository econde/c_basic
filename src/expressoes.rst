
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
mantém o valor se estiver a operar um tipo com sinal
ou recebe zero se estiver a operar um tipo sem sinal.

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
Se na avaliação de uma sub-expressão o resultado for igual ao elemento absorvente,
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

