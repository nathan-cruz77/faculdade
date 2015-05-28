# Aluno: Nathan Cruz
# R.A. : 86492

create type tenderecoN as
    (rua varchar(20), cidade varchar(20), estado varchar(20), cep integer);

create type tpessoaN as
    (nome varchar(20), sobrenome varchar(20), data date);

create type tfuncionarion as
    (matricula integer, data_admissao date, pessoa tpessoan,
     endereco tenderecon, fone integer array[3]);

create table funcionarion of tfuncionarion;

create table medicon(crm integer, especialidade varchar(20))
    inherits (funcionarion);

create table engenheiron(crea integer) inherits (funcionarion);

insert into funcionarion values
    (1, '1998-11-03', ('Marcelo', 'Silva', '1975-05-20'),
     ('Av 9 de julho', 'SJC', 'SP', 9999), '{8888, 7777}');

insert into funcionarion values
    (2, '2015-04-05', ('Manuela', 'Silva', '1973-06-28'),
     ('Av.Adhemar de Barros', 'SJC', 'SP', 8888),'{9999,6666}');

insert into medicon values
    (1, '1979-07-03', ('Walter', 'Silva', '2007-02-20'),
     ('Av. Das Flores', 'SJC', 'SP', 111), '{222, 333}', 32, 'cardiologista');

insert into medicon values
    (2, '1981-07-23', ('Joao', 'Silva', '2009-03-21'),
     ('Av. Das Orquideas', 'SJC', 'SP', 11), '{22, 33}', 33, 'pediatra');

insert into engenheiron values
    (1, '1989-10-13', ('Patricia', 'Marques', '2007-02-20'),
     ('Cassiopeia', 'SJC', 'SP', 44), '{55, 66}', 1111);

insert into engenheiron values
    (2, '1956-11-12',('Willian', 'Alves', '2007-02-20'),
     ('Andromeda', 'SJC', 'SP', 88), '{66, 77}', 2222);

select (pessoa).nome, endereco from funcionarion
    where (pessoa).nome='Marcelo';

select (endereco).rua, (endereco).cidade from funcionarion
    where (pessoa).nome='Manuela';

select fone[1] from funcionarion
    where (pessoa).nome='Marcelo';

select fone from funcionarion
    where (pessoa).nome='Manuela';

select (pessoa).nome from funcionarion;
