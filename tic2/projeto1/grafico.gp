set out 'doenca.jpeg'
set terminal jpeg

set ylabel '% Doentes'
set xlabel 'Tempo (dias)'

plot 'doenca.txt' using 2:1 with lines
