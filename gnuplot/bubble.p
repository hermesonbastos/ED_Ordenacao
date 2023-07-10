set term png
set output "graficoBubble.png"
set grid
set title 'Bubble Sort'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set yrange [0:2.30753e+007]
set style data lines

plot 'bubbleSort.txt'