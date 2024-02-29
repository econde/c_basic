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

