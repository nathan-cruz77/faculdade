rm(list = ls())


resposta = function(x) (sum(x) / max(x)) * sd(x)

# Funcoes para medir o erro que o professor pediu...
mse = function(esperado, previsto) mean((esperado - previsto)^2)
mae = function(esperado, previsto) mean(abs(esperado - previsto))
rmse = function(esperado, previsto) sqrt(mse(esperado, previsto))


knn = function(k, x_treino, y_treino, x_teste){
    distance = function(a, b) sqrt(sum(a-b)^2)

    resposta = c()

    for(x in x_teste){
        distances = c()

        distances = c(distances, apply(x_treino, 1, function(e) distance(e, x)))

        knn = order(distances)[1:k]

        resposta = mean(y_treino[knn])
    }

    return(resposta)
}

# Dados de treino
linhas_treino = 1000
colunas_treino = 10

x_treino = matrix(runif(linhas_treino * colunas_treino, -100, 100),
                  ncol = colunas_treino)
y_treino = apply(x_treino, 1, resposta)

# Dados de teste
linhas_teste = 10000
colunas_teste = 10

x_teste = matrix(runif(linhas_teste * colunas_teste, -50, 50),
                 ncol = colunas_teste)
y_teste = apply(x_teste, 1, resposta)

# Teste
dados = rbind()

for(k in 1:100){
    resposta = knn(k, x_treino, y_treino, x_teste)

    mae_value = mae(y_teste, resposta)
    mse_value = mse(y_teste, resposta)
    rmse_value = rmse(y_teste, resposta)
    media_value = mean(c(mae_value, mse_value, rmse_value))

    dados = rbind(dados, c(k, media_value, mae_value, mse_value, rmse_value))
}

# dados
index = which.min(dados[,2])
dados[index,]
