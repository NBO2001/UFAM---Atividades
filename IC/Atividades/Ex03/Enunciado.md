# Introdução a Computação (IC) - Atividade 3

## Problema
Considere o problema dos movimentos do cavalo no jogo do xadrez (Seção 9 - pg.59, das Notas de Aula), onde as posições no tabuleiro são representadas por valores x e y.

Defina a função possivel(x1,y1,x2,y2) que verifica se a posição (x2,y2) constitui um movimento válido para um cavalo na posição (x1,y1).

&nbsp;

## Resolvendo

![Horse_move](https://user-images.githubusercontent.com/54229396/153724857-94132fbc-8eaa-48fe-ac66-3a36f4a44e62.png)

Um cavalo tem 8 posições possiveis.

Um cavalo vai sempre andar duas casa em direção ao X e Y

Se o x aumentar 2, o cavalo foi para a direita, se ele diminuir 2 o cavalo foi para a esquerda.

Se o y aumentar 2, o cavalo foi para a cima, se ele diminuir 2 o cavalo foi para a baixo.

Impedende para onde ele foi, o proximo valor vai somar ou subitraí 1.

O modulo( a distância entre o cavalo e a posição procurada ) do cavalo sempre vai resultar 2 ou 1, caso seja uma posição válida.

Ou seja, a soma dos modulos sendo 3 resulta em um movimento válido.

## Social Media
* [Linkedin](www.linkedin.com/in/natanael-bezerra) :slightly_smiling_face:
