set term png
set output "graficoMerge.png"
set grid
set title 'Merge Sort'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set autoscale xy
set style data lines

plot 'mergeSort.txt'