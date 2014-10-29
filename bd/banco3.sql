# Alunos: Mariane Robl AND Nathan Cruz
#   R.A.: 86902 AND 86492

# 1
SELECT jogador.nome FROM jogador join(selecao)
    ON(jogador.selecao_sigla = selecao.sigla) WHERE selecao.nome ='Brasil';

# 2
SELECT selecao.nome FROM selecao_copa JOIN(copa, selecao)
    ON(selecao_copa.selecao_sigla = selecao.sigla AND
        selecao_copa.copa_ano = copa.ano) WHERE ano=2006;

# 3
SELECT estadio FROM jogo WHERE copa_ano=2006;

# 4
SELECT nome FROM jogador_copa join(jogador)
    ON(jogador_copa.cod_jogador = jogador.cod_jogador) WHERE copa_ano=2006;

# 5
SELECT jogador.nome FROM jogador_copa join(jogador, selecao)
    ON(jogador_copa.cod_jogador = jogador.cod_jogador AND
        selecao.sigla = jogador.selecao_sigla)
    WHERE copa_ano=2006 AND selecao.nome = 'Brasil';

# 6
SELECT campeao FROM copa ORDER BY campeao;

# 7
SELECT nome, data_nascimento FROM jogador;
