segredo = strsplit("zoeiragoldenmasterblaster", "")[[1]]

aptidao = function(individuo){
    get('segredo', envir=.GlobalEnv)
    sum(individuo == segredo)
}

mutacao = function(individuo, qtd_mutantes){
    mutados = sample(1:length(individuo), qtd_mutantes)

    for(i in mutados){
        individuo[i] = sample(letters[-match(individuo[i], letters)], 1)
    }

    individuo
}

torneio = function(fit, tam_torneio){
    participantes = sample(1:length(fit), tam_torneio)
    vencedor = which.max(fit[participantes])
    participantes[vencedor]
}

cruzamento = function(individuo1, individuo2){
    pos = sample(2:(length(individuo1) - 1), 1)

    c(individuo1[1:pos], individuo2[(pos+1):length(individuo2)])
}

# cruzamento = function(pai, mae){
#     corte = sample(1:length(pai), 1)
#
#     aux1 = paste(pai[1:corte], collapse="")
#     aux2 = paste(mae[(corte+1):length(mae), collapse=""]
#
#     filho = paste(aux1, aux2, sep="")
#     strsplit(filho, "")[[1]]
# }

# Laco evolutivo
tam_pop = 2000
tam_ind = length(segredo)
max_gen = 100
prob_cross = 0.2
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(sample(letters, tam_pop*tam_ind, replace=TRUE), ncol=tam_ind)
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
