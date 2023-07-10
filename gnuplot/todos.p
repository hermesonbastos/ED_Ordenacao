set term png
set output "graficoTodos.png"
set grid
set title 'Bubble X Insertion X Selection X Cocktail X Merge X Quick'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set style data lines
set yrange [0:2.50753e+007]
set multiplot

plot 'bubbleSort.txt' title 'Bubble', 'insertionSort.txt' title 'Insertion', 'selectionSort.txt' title 'Selection', 'cocktailSort.txt' title 'Cocktail', 'mergeSort.txt' title 'Merge', 'quickSort.txt' title 'Quick'

unset multiplot