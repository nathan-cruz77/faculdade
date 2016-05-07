rm(list = ls())

# Funcao objetivo
aptidao = function(individuo){
    a = (sum(individuo ^ 2) / (3.2 * sqrt(abs(max(individuo)))))
    a
}

# Funcao de mutacao
mutacao = function(individuo, qt_genes){
    mutados = sample(length(individuo), qt_genes)

    for(i in mutados){

        aux = runif(1, -10, 10)

        while(individuo[i] == aux){
            aux = runif(1, -10, 10)
        }

        individuo[i] = aux
    }

    individuo
}

cruzamento = function(individuo1, individuo2){
    pos = sample((length(individuo1) - 1), 1)
    c(individuo1[1:pos], individuo2[(pos+1):length(individuo2)])
}

torneio = function(fit, tam_torneio){
    participantes = sample(1:length(fit), tam_torneio)
    vencedor = which.max(fit[participantes])
    participantes[vencedor]
}

# Laco evolutivo
tam_pop = 1000
tam_ind = 2
max_gen = 100
prob_cross = 0.2
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(runif(tam_pop*tam_ind, -10, 10), ncol=tam_ind)
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

pior = order(fitness, decreasing=TRUE)[length(fitness)]
cat("Pior individuo: ", pop[pior, ], " fitness: ", fitness[pior], "\n")

media = mean(fitness)
cat("Fitness media da pop: ", mean(fitness), "\n")

plot(melhor_fit)

# imprimir:
# Melhor individuo e seu fitness
# Fitness medio da populacao
# Pior fitness
# Grafico mostrando a evolucao do melhor fitness
