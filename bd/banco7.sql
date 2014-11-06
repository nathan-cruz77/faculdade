# 8
SELECT Medico.nome, Medico.telefone FROM Medico
    JOIN(Especialidade, MedicoEspecialidade)
    ON(Medico.cod = MedicoEspecialidade.medico_cod AND
        Especialidade.cod = MedicoEspecialidade.especialidade_cod)
    WHERE Especialidade.nome = 'Pediatria';

# 9
SELECT Clinica.nome, Clinica.endereco FROM Clinica
    JOIN(EspecialidadeClinica, Especialidade)
    ON(Clinica.cod = EspecialidadeClinica.clinica_cod AND
        EspecialidadeClinica.especialidade_cod = Especialidade.cod)
    WHERE Especialidade.nome = 'Oftalmologia' OR
    Especialidade.nome = 'Ginecologia';

# 10
SELECT Medico.nome FROM Medico
    JOIN(Clinica, MedicoClinica, MedicoEspecialidade, Especialidade)
    ON(Medico.cod = MedicoClinica.medico_cod AND
        MedicoClinica.clinica_cod = Clinica.cod AND
        MedicoEspecialidade.medico_cod = Medico.cod AND
        Especialidade.cod = MedicoEspecialidade.especialidade_cod)
    WHERE Clinica.endereco = 'Barro Preto' AND
        Especialidade.nome = 'Clinico Geral';

# 11
INSERT INTO Especialidade(cod, nome) VALUES(11, 'endocrino');
INSERT INTO Especialidade(cod, nome) VALUES(12, 'alergista');

# 12
SELECT Medico.nome, Especialidade.nome FROM Medico
    RiGHT JOIN(MedicoEspecialidade, Especialidade)
    ON(Medico.cod = MedicoEspecialidade.medico_cod AND
        Especialidade.cod = MedicoEspecialidade.especialidade_cod)
    ORDER BY Medico.nome;

# 13
SELECT Medico.nome, COUNT(Clinica.cod) FROM Medico
    LEFT JOIN(MedicoClinica, Clinica) ON(Medico.cod = MedicoClinica.medico_cod
        AND Clinica.cod = MedicoClinica.clinica_cod) GROUP BY Medico.cod;
