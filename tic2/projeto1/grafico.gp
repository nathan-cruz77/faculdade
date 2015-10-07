set out 'doenca.jpeg'
set terminal jpeg

set xlabel 'Tempo'

set yrange [0:1]

plot 'doenca.txt' using 6:1 title 'Saudaveis' with lines,\
     'doenca.txt' using 6:2 title 'Expostos' with lines,\
     'doenca.txt' using 6:3 title 'Infectados' with lines,\
     'doenca.txt' using 6:4 title 'Recuperados' with lines,\
     'doenca.txt' using 6:5 title 'Vacinados' with lines
