set terminal pngcairo size 800,600 enhanced font 'Verdana,9'
set output 'id3_acuracia.png'

set xlabel 'Casas Decimais'
set ylabel 'Acurácia Média'

set style line 1 lc rgb '#6a5acd' pt 1 ps 1 lt 1 lw 2
set style line 11 lc rgb '#808080' lt 1

set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

set border 3 back ls 11
set tics nomirror

set title 'ID3'

plot 'results_id3.txt' u 1:2 w lp ls 1 notitle
