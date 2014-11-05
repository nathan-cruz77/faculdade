# Aluno: Nathan Cruz
#  R.A.: 86492

# 1
SELECT data FROM Consulta JOIN(Medico)
    ON(Consulta.medico_cod = Medico.cod AND Medico.nome = 'Arthur');

# 2
SELECT Especialidade.nome FROM MedicoEspecialidade JOIN(Medico, Especialidade)
    ON(Medico.cod = MedicoEspecialidade.medico_cod AND
       Especialidade.cod = MedicoEspecialidade.especialidade_cod AND
       Medico.nome = 'Paulo');

# 3
DELETE FROM Consulta WHERE medico_cod =
    (SELECT cod FROM Medico WHERE nome='Andre');

# 4
SELECT Medico.nome, Consulta.data FROM Medico LEFT JOIN(Consulta)
    ON(Medico.cod = Consulta.medico_cod);

# 5
DELETE FROM MedicoClinica WHERE MedicoClinica.medico_cod = 1;

# 6
SELECT Medico.nome, Clinica.nome, Clinica.endereco FROM Medico
    LEFT JOIN(MedicoClinica, Clinica) ON(Medico.cod = MedicoClinica.medico_cod
    AND Clinica.cod = MedicoClinica.clinica_cod);
