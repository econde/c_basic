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

O acesso aos elementos do *array* realiza-se através do operador indexação **[]**.
Os índices vão de zero -- primeira posição -- à dimensão menos um -- última posição.

No exemplo anterior, as posições do *array* ``fruit`` vão de 0 a 99.

Exemplos de acesso:

   ``fruit[0] = 34;`` A primeira posição do *array* ``fruit`` é afetada com trinta e quatro.

   ``c[9] = 'f';`` A última posição do *array* ``c`` é afetada com o código numérico da letra 'f'.

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

é válido. (Embora não seja o código adequado para expressar a cópia de um *array* extenso.)

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
