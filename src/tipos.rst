Tipos básicos
=============

Inteiros
--------

Os valores inteiros são representados, ao nível da máquina, em binário,
no sistema de significância posicional.
O conjunto dos números naturais têm uma representação direta
e o conjunto de números relativos são codificados em código dos complementos.
Na :numref:`tipos-c-kotlin` apresentam-se os identificadores de tipo,
assim como as dimensões de   representação nas linguagens Kotlin e C.

As palavras ``signed`` e ``unsigned`` atuam como "modificadores de sinal".
``signed`` significa que o domínio de valores pertence ao conjunto dos números relativos
e ``unsigned`` significa que o domínio pertence ao conjunto dos números naturais.
Estes modificadores podem ser omitidos e as palavras ``char``
ou ``int`` aparecer isoladas com os seguintes significados:

   * ``char`` pode ser equivalente a ``signed char`` ou a ``unsigned char``.
     A norma remete a definição para a implementação. Por omissão,
     os compiladores gcc e clang consideram ``char`` equivalente a ``signed char``,
     mas por opção podem considerar equivalente a ``unsigned char``.
   * ``int`` é equivalente a ``signed int``

As palavras ``short`` e ``long`` atuam como modificadores de dimensão no tipo ``int``,
produzindo representações com menor ou maior número de *bits*, respetivamente.
Sintaticamente estas palavras podem aparecem isoladas (sem ``int`` à frente)
com os seguintes significados:

   * ``short`` é equivalente a ``short int``
   * ``long`` é equivalente a ``long int``

Como a linguagem C não define dimensões concretas para
os tipos numéricos ``char``, ``int``, ``short`` e ``long``, foi definido,
ao nível da `biblioteca normalizada <https://en.cppreference.com/w/c/types/integer>`_,
a existência dos tipos ``intXX_t`` sendo ``XX``
o número de *bits* dessa representação concreta.
A variante ``uintXX_t`` representa valores no conjunto dos números naturais
e a variante ``intXX_t`` representa valores no conjunto dos números relativos.

.. table:: Tipos numéricos na linguagem Kotlin e dimensões típicas na linguagem C, para processadores de  16, 32 e 64 bit.
   :widths: auto
   :align: center
   :name: tipos-c-kotlin

   +--------------------------------+-----------------------------------------------+--------------------------------------+
   | Linguagem Kotlin               |           Linguagem C                         | Dimensão em bytes                    |
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
com palavra de 8, 16, 32 e 64 *bits*, para números naturais ou relativos.

A escolha por parte do programador, do tipo de dados a empregar,
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
O tipo ``char`` é o tipo normalmente utilizado para representar caracteres.
Como os códigos dos caracteres são considerados valores numéricos,
também se pode utilizar o tipo ``int`` ou as variantes ``short`` ou ``long``
para os representar.

Booleanos
---------

Uma variável do tipo ``bool`` pode assumir os valores ``true`` ou ``false``.

Os valores numéricos dos tipos ``char``, ``short``, ``int`` ou ``long``
podem ser avaliados como valores booleanos com o seguinte critérios:
o valor zero é avaliado como ``false`` e um valor diferente de zero é avaliado como ``true``.

