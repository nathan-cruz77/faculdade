# Exercicio de banco de dados
#
# Aluno: Nathan Cruz
#  R.A.: 86492
#

use Nathan_Cruz;

# 1
SELECT * FROM Ator WHERE sexo='f';

# 2 -- Nao temos nacionalidade na tabela
SELECT nomereal, nacionalidade, sexo FROM Ator;

# 3
SELECT nomeart, nomereal, indicacoesoscar, oscar FROM Ator;

# 4
SELECT codf FROM Personagem WHERE cache_ganho <= 3000;

# 5
SELECT nome_personagem FROM Personagem JOIN(Ator) ON
    (Personagem.coda = Ator.coda) where nomeart='demi moore';

# 6
SELECT nome FROM Personagem JOIN(Ator, Filme)
    ON (Personagem.coda = Ator.coda AND Personagem.codf = Filme.codf)
    WHERE nomeart='demi moore';

# 7
SELECT nomeart FROM Ator WHERE nomereal='Jessica';

# 8
SELECT nomeart FROM Ator WHERE idade >= 30 AND idade <= 40;

# 9
SELECT nomereal FROM Ator WHERE indicacoesoscar = oscar + 2;

# 10
SELECT nomereal FROM Ator ORDER BY nomereal;

# 11
SELECT * FROM Ator ORDER BY idade DESC, nomereal;

# 12 -- Nao temos nacionalidade na tabela
SELECT nomeart, nacionalidade FROM Ator;
