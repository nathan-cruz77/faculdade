set terminal jpeg size 800, 600
set out 'grafico.jpg'

set xlabel 'Tempo'
set ylabel 'Doentes'

plot     'doenca.txt' using 6:1 title 'Suscetiveis' with lines, \
    'doenca.txt' using 6:2 title 'Expostos' with lines, \
    'doenca.txt' using 6:3 title 'Infectados' with lines, \
    'doenca.txt' using 6:4 title 'Recuperados' with lines, \
    'doenca.txt' using 6:5 title 'Vacinados' with lines
