rm(list = ls())

# algoritmo genetico: onemax

# Funcao objetivo
aptidao = function(individuo){
    sum(individuo)
}

# Funcao de mutacao
mutacao = function(individuo, qt_genes){
    pos = sample(1:length(individuo), qt_genes)

    for(i in pos){
        if(individuo[i] == 1){
            individuo[i] = 0
        }
        else{
            individuo[i] = 1
        }
    }

    individuo
}

cruzamento = function(individuo1, individuo2){
    pos = sample(2:(length(individuo1) - 1), 1)

    c(individuo1[1:pos], individuo2[(pos+1):length(individuo2)])
}

torneio = function(fit, tam_torneio){
    participantes = sample(1:length(fit), tam_torneio)
    vencedor = which.max(fit[participantes])
    participantes[vencedor]
}

# Laco evolutivo
tam_pop = 200
tam_ind = 100
max_gen = 100
prob_cross = 0.2
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(round(runif(tam_pop*tam_ind, 0, 1)), ncol=tam_ind)
fitness = apply(pop, 1, function(i) aptidao(i))

melhor_fit = NULL

for (i in 1:max_gen){

    melhor_fit = c(melhor_fit, max(fitness))

    cat("\r", (i*100)/max_gen, "%")

    nova_pop = NULL
    nova_fit = NULL

    pop_filhos = NULL
    fit_filhos = NULL

    pai1 = NULL
    pai2 = NULL

    for (p in 1:(tam_pop * prob_cross)){
        idx_pai1 = torneio(fitness, tam_torneio)
        idx_pai2 = torneio(fitness[-(idx_pai1)], tam_torneio)

        pai1 = pop[idx_pai1, ]
        pai2 = pop[idx_pai2, ]

        filho = cruzamento(pai1, pai2)
        filho = mutacao(filho, qtd_mut)
        aptidao_filho = aptidao(filho)

        pop_filhos = rbind(pop_filhos, filho)
        fit_filhos = c(fit_filhos, aptidao_filho)
    }

    pop = rbind(pop, pop_filhos)
    fitness = c(fitness, fit_filhos)

    nova_pop = rbind(nova_pop, pop[order(fitness, decreasing=TRUE)[1:elite], ])
    nova_fit = rbind(nova_fit, fitness[order(fitness, decreasing=TRUE)[1:elite]])

    pop = pop[(-order(fitness, decreasing=TRUE)[1:elite]), ]
    fitness = fitness[(-order(fitness, decreasing=TRUE)[1:elite])]

    # print(fitness)

    for(i in 1:(tam_pop - elite)){
        boladao = torneio(fitness, tam_torneio)

        nova_pop = rbind(nova_pop, pop[boladao, ])
        nova_fit = c(nova_fit, fitness[boladao])

        pop = pop[-(boladao), ]
        fitness = fitness[-(boladao)]
    }

    pop = nova_pop
    fitness = nova_fit

}

melhor = order(fitness, decreasing=TRUE)[1]
cat("Melhor individuo: ", pop[melhor, ], " fitness: ", fitness[melhor], "\n")

pior = order(fitness)[length(fitness)]
cat("Pior individuo: ", pop[pior, ], " fitness: ", fitness[pior], "\n")

media = mean(fitness)
cat("Fitness media da pop: ", mean(fitness), "\n")

plot(melhor_fit)

# imprimir:
# Melhor individuo e seu fitness
# Fitness medio da populacao
# Pior fitness
# Grafico mostrando a evolucao do melhor fitness
