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

Pode colocar-se ``void`` no lugar da lista de parâmetros
para explicitar que a função não recebe argumentos.

::

   int delay_5_seconds(void);

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

Na declaração de um parâmetro de função do tipo *array* não se indica a dimensão do *array*.
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

Na linguagem C, um *array* como parâmetro é sempre acompanhado de outro parâmetro
ou de algum artifício que permita operar o array dentro dos seus limites.

No caso das funções que manipulam *strings*, que são suportadas por *arrays* de caracteres,
a informação de dimensão está no termindador da *string* -- valor zero após o último caractere da *string*.

Na função ``strcmp`` a sub-expressão ``str1[i] != 0``
serve para não se ultrapassar os limites dos *arrays*.
Esta sub-expressão só será avaliada como falsa se as *strings* forem iguais.

::

   int strcmp(const char str1[], const char str2[])
   {
      for (int i = 0; str1[i] != 0 && str1[i] == str2[i]; ++i)
         ;
      return str1[i] - str2[i];
   }

O método de utilizar um valor marcador para indicar o final do *array*
só pode ser aplicado se o marcador não for um valor de dados possível.

Parâmetros constantes
---------------------

A utilização da palavra ``const`` na declaração de parâmetros
significa que os argumentos não podem ser modificados durante a execução da função.
No caso de *arrays*, significa que o conteúdo do array não pode ser alterado.

Sem o atributo ``const`` os parâmetros de funções são como variáveis locais.

.. code-block:: C
   :linenos:

   int f(const char string[], int i)
   {
      if (string[i] != '\0')
         string[i] += ' ';
      i += 3;
   }

No exemplo, a tentativa de alteração do conteúdo de ``string`` na linha 4
é assinalada com erro pelo compilador.

A instrução da linha 5 adiciona 3 ao parâmetro ``i``, como se fosse uma variável local.


