set term png
set output "graficoInsertion.png"
set grid
set title 'Insertion Sort'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set yrange [0:2.30753e+007]
set style data lines

plot 'insertionSort.txt'