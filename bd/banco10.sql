USE Circuito;

# 1
SELECT pais.nomepais FROM pais WHERE NOT EXISTS(SELECT piloto.codpais
    FROM piloto WHERE pais.codpais = piloto.codpais);

# 2
SELECT DISTINCT(piloto.nomepil) FROM piloto JOIN(pospilotoprova)
    ON(piloto.codpil = pospilotoprova.codpil);

# 3
SELECT nomeeq FROM equipe WHERE equipe.codpais = ANY(SELECT piloto.codpais FROM
    piloto WHERE piloto.codeq = equipe.codeq);

# 4
CREATE VIEW PilotoCircuitoPos AS
    SELECT piloto.nomepil, circuito.nomecir, pospilotoprova.posicao
    FROM piloto JOIN(circuito, pospilotoprova)
    ON(piloto.codpil = pospilotoprova.codpil AND
       pospilotoprova.codcirc = circuito.codcirc);

# 5
SELECT p1.nomepil, p2.nomepil FROM piloto p1, piloto p2 JOIN(amizade)
    WHERE p1.codpil = amizade.codpiloto1 AND p2.codpil = codpiloto2;
