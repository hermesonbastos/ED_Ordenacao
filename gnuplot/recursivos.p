set term png
set output "graficoRecursivos.png"
set grid
set title 'Quick X Merge'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set style data lines
set autoscale xy
set multiplot

plot 'quickSort.txt' title 'Quick', 'mergeSort.txt' title 'Merge'

unset multiplot