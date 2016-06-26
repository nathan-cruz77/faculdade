set terminal pngcairo size 800,600 enhanced font 'Verdana,9'
set output 'knn_acuracia.png'

set xlabel 'K'
set ylabel 'Acurácia Média'

set style line 1 lc rgb '#228b22' pt 1 ps 1 lt 1 lw 2
set style line 11 lc rgb '#808080' lt 1

set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

set border 3 back ls 11
set tics nomirror

set title 'KNN'

plot 'results_knn.txt' u 1:2 w lp ls 1 notitle
