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

