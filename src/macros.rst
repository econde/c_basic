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

