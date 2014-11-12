CREATE DATABASE IF NOT EXISTS Banco_Nathan;

USE Banco_Nathan;

# 1
CREATE TABLE IF NOT EXISTS Conta(
    cod_conta INTEGER,
    saldo REAL,
    PRIMARY KEY(cod_conta)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Depositos(
    cod_dep INTEGER,
    cod_conta INTEGER,
    valor REAL,
    PRIMARY KEY(cod_dep),
    FOREIGN KEY(cod_conta) REFERENCES Conta(cod_conta)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Retiradas(
    cod_ret INTEGER,
    cod_conta INTEGER,
    valor REAL,
    PRIMARY KEY(cod_ret),
    FOREIGN KEY(cod_conta) REFERENCES Conta(cod_conta)
) ENGINE = InnoDB;

# 2
INSERT INTO Conta VALUES(1, 23.2);
INSERT INTO Conta VALUES(2, 65.2);
INSERT INTO Conta VALUES(3, 96.15);
SELECT * FROM Conta;

# 3
CREATE TRIGGER TR_DEP AFTER INSERT ON Depositos FOR EACH ROW
    UPDATE Conta SET Conta.saldo = Conta.saldo + NEW.valor
    WHERE NEW.cod_conta = Conta.cod_conta;

# 4
INSERT INTO Depositos VALUES(1, 2, 32.25);
INSERT INTO Depositos VALUES(2, 1, 2.54);
SELECT * FROM Conta;

# 5
CREATE TRIGGER TR_RET AFTER INSERT ON Retiradas FOR EACH ROW
    UPDATE Conta SET Conta.saldo = Conta.saldo - NEW.valor
    WHERE NEW.cod_conta = Conta.cod_conta;

# 6
INSERT INTO Retiradas VALUES(1, 2, 32.25);
INSERT INTO Retiradas VALUES(2, 1, 2.54);
SELECT * FROM Conta;
