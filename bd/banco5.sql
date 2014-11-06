# Exercicio de banco de dados
#
# Aluno: Nathan Cruz
# R.A.: 86492
#

USE Clinica_Medico;

# 1
SELECT Clinica.nome FROM Clinica 
WHERE cod IN(SELECT clinica_cod FROM MedicoClinica 
WHERE medico_cod IN(SELECT cod FROM Medico WHERE nome = 'Arthur'));

# 2
SELECT Especialidade.nome FROM Especialidade 
WHERE cod IN(SELECT especialidade_cod FROM MedicoEspecialidade 
WHERE medico_cod IN(SELECT cod FROM Medico WHERE nome = 'Andre'));

# 3
SELECT Medico.nome, Clinica.nome FROM Consulta 
JOIN(Medico,Clinica) ON (Medico.cod = Consulta.medico_cod 
AND Clinica.cod = Consulta.clinica_cod) ORDER BY data, hora;

# 4
SELECT Medico.nome FROM Medico 
WHERE cod IN(SELECT medico_cod FROM Consulta 
WHERE hora IN(SELECT max(hora) FROM Consulta));

# 5
SELECT Medico.nome FROM Medico 
WHERE cod NOT IN(SELECT medico_cod FROM MedicoClinica
WHERE clinica_cod IN(SELECT cod FROM Clinica));

# 6
SELECT Medico.nome, COUNT(MedicoClinica.clinica_cod) 
FROM MedicoClinica JOIN (Medico) ON (Medico.cod = MedicoClinica.medico_cod) 
GROUP BY Medico.nome
ORDER BY Medico.nome;

# 7
SELECT Medico.nome FROM Medico JOIN (MedicoEspecialidade) 
ON (MedicoEspecialidade.medico_cod = Medico.cod) 
GROUP BY  Medico.cod
HAVING COUNT(MedicoEspecialidade.especialidade_cod) = 2;

# 8
SELECT Clinica.nome FROM Clinica JOIN(Consulta) 
ON (Consulta.clinica_cod = Clinica.cod) GROUP BY Clinica.cod
HAVING HOUR(AVG(Consulta.hora)) > 20;

# 9
SELECT Clinica.nome, S.nome FROM Clinica 
JOIN(EspecialidadeClinica E, Especialidade S) 
ON (E.especialidade_cod = S.cod AND Clinica.cod = E.clinica_cod)
ORDER BY Clinica.nome;

# 10
SELECT Clinica.nome, COUNT(E.especialidade_cod) 
FROM Clinica, EspecialidadeClinica E 
WHERE Clinica.cod = E.clinica_cod
GROUP BY Clinica.nome;
