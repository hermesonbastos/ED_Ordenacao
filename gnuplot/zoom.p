set term png
set output "graficoZoom.png"
set grid
set title 'Bubble X Insertion X Selection X Cocktail X Merge X Quick (Aproximado)'
set xlabel 'Tamanho do Vetor'
set ylabel 'Microssegundos'
set style data lines
set yrange [0:15000]
set multiplot

plot 'bubbleSort.txt' title 'Bubble', 'insertionSort.txt' title 'Insertion', 'selectionSort.txt' title 'Selection', 'cocktailSort.txt' title 'Cocktail', 'mergeSort.txt' title 'Merge', 'quickSort.txt' title 'Quick'

unset multiplot