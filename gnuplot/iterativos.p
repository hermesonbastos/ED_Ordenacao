set term png
set output "graficoIterativos.png"
set grid
set title 'Bubble X Insertion X Selection X Cocktail'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set style data lines
set yrange [0:2.30753e+007]
set multiplot

plot 'bubbleSort.txt' title 'Bubble', 'insertionSort.txt' title 'Insertion', 'selectionSort.txt' title 'Selection', 'cocktailSort.txt' title 'Cocktail',

unset multiplot