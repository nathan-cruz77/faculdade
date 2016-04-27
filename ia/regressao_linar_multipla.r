rm(list=ls())

linhas = 100
colunas = 10

data_treino = matridata_treino(runif(linhas * colunas, -100, 100), ncol=colunas)
resposta_treino =

betas = (solve(t(data_treino) %*% data_treino) %*% (t(data_treino) %*% data_treino)) %*% (t(data_treino) %*% )
