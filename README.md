# Art-ASCII
O objetivo desse trabalho é explorar os conceitos de vizinhança dos pixels, amostragem e quantização utilizando arte ASCII.
Basicamente é uma ferramenta que a partir de uma imagem em tons de cinza (PGM), produz uma imagem usando caracteres ASCII como tons de cinza.
O usuário desse programa informa a imagem, o número de colunas e linhas da imagem ASCII que será gerada (amostragem) e o string de caracteres para codificar os tons de cinza (quantização)

Instruções de uso:

O programa deverá ser chamado em linha de comando no terminal da seguinte forma:

./ ascii <nome=arquivo=imagem> <ncolunas> <nlinhas> <string>[.pgm ]

Por exemplo :
./ asciicao.pgm 100 30 ”@$#*%o !=+;:˜ = ,. ”

