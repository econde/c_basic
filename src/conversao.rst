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
