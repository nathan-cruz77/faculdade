# Exercicio de banco de dados
#
# Aluno: Nathan Cruz
#  R.A.: 86492
#
CREATE DATABASE IF NOT EXISTS Nathan_Cruz;

USE Nathan_Cruz;

CREATE TABLE IF NOT EXISTS Ator(
    coda INTEGER AUTO_INCREMENT,
    nomeart VARCHAR(50),
    nomereal VARCHAR(50),
    sexo VARCHAR(1),
    idade INTEGER,
    indicacoesoscar INTEGER DEFAULT 0,
    PRIMARY KEY(coda)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Filme(
    codf INTEGER AUTO_INCREMENT,
    nome VARCHAR(50),
    ano YEAR,
    orcamento REAL,
    tempo FLOAT NOT NULL,
    PRIMARY KEY(codf)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Personagem(
    coda INTEGER,
    codf INTEGER,
    nome_personagem VARCHAR(50),
    cache_ganho REAL,
    PRIMARY KEY(coda, codf)
) ENGINE = InnoDB;

ALTER TABLE Personagem ADD FOREIGN KEY(coda) REFERENCES Ator(coda) ON DELETE CASCADE;
ALTER TABLE Personagem ADD FOREIGN KEY(codf) REFERENCES Filme(codf);

ALTER TABLE Ator ADD oscar INTEGER;
ALTER TABLE Filme DROP orcamento;

INSERT INTO Ator(coda, nomeart, nomereal, sexo, idade, indicacoesoscar, oscar)
    VALUES(1, 'demi moore', 'maria da silva','f', 32, 0, 0);
INSERT INTO Ator(coda, nomeart, nomereal, sexo, idade, indicacoesoscar, oscar)
    VALUES(2, 'brad pitt', 'joao paulo','f', 28, 1, 0);
INSERT INTO Ator(coda, nomeart, nomereal, sexo, idade, indicacoesoscar, oscar)
    VALUES(3, 'dustin hoffman', 'dustin','m', 46, 2, 0);
INSERT INTO Ator(coda, nomeart, nomereal, sexo, idade, indicacoesoscar, oscar)
    VALUES(4,'jessica lange', 'jessica','f', 42, 4, 2);
INSERT INTO Ator(coda, nomeart, nomereal, sexo, idade, indicacoesoscar, oscar)
    VALUES(5,'sonia braga', 'sonia braga','f', 60, 0, 0);

INSERT INTO Filme(codf, nome, ano, tempo)
    VALUES(1, 'a jurada', 1996, 18);
INSERT INTO Filme(codf, nome, ano, tempo)
    VALUES(2,'a letra escarlate', 1995, 24);
INSERT INTO Filme(codf, nome, ano, tempo)
    VALUES(3,'seven', 1995, 20);
INSERT INTO Filme(codf, nome, ano, tempo)
    VALUES(4,'tootsie', 1982, 16);

INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(1,1,'mary', 3000);
INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(1,2,'sandy', 5000);
INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(2,3,'john', 5000);
INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(3,4,'mary', 10000);
INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(4,4,'tootsie', 2000);
INSERT INTO Personagem(coda, codf, nome_personagem, cache_ganho)
    VALUES(5,5,'tieta', 500);
