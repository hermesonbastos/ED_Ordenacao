set term png
set output "graficoQuick.png"
set grid
set title 'Quick Sort'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set autoscale xy
set style data lines

plot 'quickSort.txt'