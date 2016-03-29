rm(list = ls())

set.seed(1)

xmin_treino = -100
xmax_treino = 100

xmin_teste = -50
xmax_teste = 50

nr_treino = 100
nr_teste = 500

nc = 100

x = matrix(runif(nr_treino*nc, xmin_treino, xmax_treino), ncol = nc)

knn_mat = rbind()
lm_mat = rbind()

for(j in c(0.5, 0.7, 0.9)){
    for(i in 1:10){
        y = matrix(sample(x))

        x = matrix(y, nc)

        linhas = (nr_treino)*j

        x_teste = x[1:linhas,]
        x_treino = x[-(1:linhas),]

        y_treino = apply(x_treino, 1, function(x) (sum(x)/max(x)*sd(x)))
        y_teste = apply(x_teste, 1, function(x) (sum(x)/max(x)*sd(x)))

        ####################################################################
        #################### Calculo do KNN ################################

        knn = function(k, x_treino, y_treino, x_teste){
          apply(x_teste, 1, function(xteste)
            mean(
                y_treino[
                      order(
                          apply(x_treino, 1, function(xtreino)
                              sqrt( sum( (xtreino - xteste)^2) )
                          )
                      )[1:k]
                  ]
            )
          )
        }
        for(knn_num in c(1,3,5)){
            max_k = knn_num
            resp_k = sapply(1:max_k, function(k){
              pred_teste = knn(k, x_treino, y_treino, x_teste)
              erro = pred_teste - y_teste
              mae = mean(abs(erro))
              mse = mean(erro^2)
              rmse = sqrt(mse)
              c(mae, mse, rmse)
            })

            media_mae = mean(resp_k[1,])
            media_mse = mean(resp_k[2,])
            media_rmse = mean(resp_k[3,])

            media = mean(media_mae, media_mse, media_rmse)

            knn_mat = rbind(knn_mat, c(media, media_mae, media_mse, media_rmse))
        }

        ####################################################################
        #################### Calculo do LM #################################

        modelo2 = lm (y_treino ~ ., data=data.frame(x_treino))

        pred_teste_lm = predict(modelo2, newdata=data.frame(x_teste))

        resp_lm = sapply(1:linhas, function(k){
          erro_lm = pred_teste_lm[k] - y_teste[k]
          mae_lm = mean(abs(erro_lm))
          mse_lm = mean(erro_lm^2)
          rmse_lm = sqrt(mse_lm)
          c(mae_lm, mse_lm, rmse_lm)
        })

        media_mae_lm = mean(resp_lm[1,])
        media_mse_lm = mean(resp_lm[2,])
        media_rmse_lm = mean(resp_lm[3,])

        media_lm = mean(media_mae_lm, media_mse_lm, media_rmse_lm)

        lm_mat = rbind(lm_mat, c(media_lm, media_mae_lm, media_mse_lm, media_rmse_lm))
    }
}

min_knn = which.min(knn_mat[,1])
knn_mat[min_knn,]

min_lm = which.min(lm_mat[,1])
lm_mat[min_lm,]
