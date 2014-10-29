# 13
SELECT MAX(idade), MIN(idade), AVG(idade) FROM Ator;

# 14
SELECT MIN(idade), MAX(idade) FROM Ator WHERE sexo='f';

# 15
SELECT COUNT(*) FROM Ator WHERE sexo='f';

# 16
SELECT SUM(idade) FROM Ator;

# 17
SELECT nomeart, COUNT(Filme.nome) FROM Ator, Filme, Personagem
    WHERE Ator.coda=Personagem.coda AND Personagem.codf=Filme.codf
    GROUP BY nomeart;

# 18
SELECT nomeart, MAX(ano), MIN(ano) FROM Ator JOIN(Personagem, Filme)
    ON(Ator.coda=Personagem.coda AND Personagem.codf=Filme.codf)
    WHERE indicacoesoscar > 0 GROUP BY nomeart;

# 19
SELECT Filme.nome, AVG(cache_ganho), MAX(cache_ganho),
       MIN(cache_ganho), SUM(cache_ganho) FROM Filme JOIN(Personagem)
       ON(Filme.codf=Personagem.codf) GROUP BY Filme.nome;

# 20
SELECT nomeart, COUNT(codf) FROM Ator JOIN(Personagem)
    ON(Ator.coda=Personagem.coda) GROUP BY nomeart HAVING COUNT(codf) >= 2;

# 21
SELECT Filme.nome, COUNT(DISTINCT(cache_ganho)) FROM Ator JOIN(Personagem, Filme)
    ON(Ator.coda=Personagem.coda AND Filme.codf=Personagem.codf)
    WHERE cache_ganho > 2000 GROUP BY Filme.nome
    HAVING SUM(cache_ganho) > 8000;
