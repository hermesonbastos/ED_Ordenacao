set term png
set output "graficoSelection.png"
set grid
set title 'Selection Sort'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set yrange [0:2.30753e+007]
set style data lines

plot 'selectionSort.txt'