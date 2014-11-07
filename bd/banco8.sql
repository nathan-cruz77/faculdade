# 1
CREATE VIEW MEDCLIN(med_nome, clin_nome) AS SELECT Medico.nome, Clinica.nome
    FROM Medico LEFT JOIN(MedicoClinica, Clinica)
    ON(Medico.cod = MedicoClinica.medico_cod AND
       Clinica.cod = MedicoClinica.clinica_cod);
SELECT * FROM MEDCLIN;

# 2
CREATE VIEW MEDESP(med_nome, esp_nome) AS
    SELECT Medico.nome, Especialidade.nome FROM Medico
    LEFT JOIN(MedicoEspecialidade, Especialidade)
    ON(Medico.cod = MedicoEspecialidade.medico_cod AND
       Especialidade.cod = MedicoEspecialidade.especialidade_cod);
SELECT * FROM MEDESP;

# 3
CREATE VIEW CLIESP(cli_nome, esp_nome) AS
    SELECT Clinica.nome, Especialidade.nome FROM Clinica
    JOIN(EspecialidadeClinica, Especialidade)
    ON(Clinica.cod = EspecialidadeClinica.clinica_cod AND
       Especialidade.cod = EspecialidadeClinica.especialidade_cod);
SELECT * FROM CLIESP;

# 4
INSERT INTO Medico(cod, nome, telefone) VALUES (11, 'Bernardo', '1159-6498');
SELECT * FROM MEDCLIN;
SELECT * FROM MEDESP;

# 5
SELECT * FROM MEDCLIN WHERE clin_nome = 'clinica bem estar';

# 6
SELECT med_nome, COUNT(esp_nome) FROM MEDESP GROUP BY med_nome;

# 7
CREATE VIEW CONTAESP AS SELECT med_nome, COUNT(esp_nome) FROM MEDESP
    GROUP BY med_nome;
SELECT * FROM CONTAESP;

# 8
INSERT INTO Medico(cod, nome, telefone) VALUES(12, 'Rafael', '1159-6498');
