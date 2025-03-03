SET storage_engine=InnoDB;
SET FOREIGN_KEY_CHECKS=1;
USE CAMPIONATO_CICLISTICO;

INSERT INTO CICLISTA (CodC, Nome, Cognome, Nazionalita, CodS, AnnoNascita)
VALUES('7', 'Paul', 'Smith', 'Australia', '1', 1963);
INSERT INTO CICLISTA (CodC, Nome, Cognome, Nazionalita, CodS, AnnoNascita)
VALUES('100', 'John', 'Johnson', 'Regno Unito', '2', '1988');
INSERT INTO CICLISTA (CodC, Nome, Cognome, Nazionalita, CodS, AnnoNascita)
VALUES('35', 'Peter', 'Johnson', 'U.S.A.', '1', '1900');

INSERT INTO CLASSIFICA_INDIVIDUALE(CodC, CodT, Edizione, Posizione)
VALUES('7', '2', '4', '1');
INSERT INTO CLASSIFICA_INDIVIDUALE(CodC, CodT, Edizione, Posizione)
VALUES('100', '5', '1', '4');
INSERT INTO CLASSIFICA_INDIVIDUALE(CodC, CodT, Edizione, Posizione)
VALUES('35', '15', '1', '7');

INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('1', '1', 'Torino', 'Bergamo', '250000', '700', '4');
INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('4', '1', 'Roma', 'Zagabria', '1200000', '2000', '9');
INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('7', '6', 'Amsterdam', 'Rotterdam', '60000', '30', '2');
INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('7', '2', 'Londra', 'Edimburgo', '600000', '1500', '7');
INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('6', '5', 'Berlino', 'Monaco', '950000', '2700', '4');
INSERT INTO TAPPA(Edizione, CodT, CittaPartenza, CittaArrivo, Lunghezza, Dislivello, GradoDifficolta)
VALUES('2', '1', 'Parigi', 'Marsiglia', '750000', '630', '3');

INSERT INTO SQUADRA(CodS, NomeS, AnnoFondazione, SedeLegale)
VALUES('1', 'Squadra1', '1950', 'Barcellona');
INSERT INTO SQUADRA(CodS, NomeS, AnnoFondazione, SedeLegale)
VALUES('2', 'Squadra2', '1930', 'Torino');
INSERT INTO SQUADRA(CodS, NomeS, AnnoFondazione, SedeLegale)
VALUES('3', 'Squadra3', '1990', NULL);   