SET storage_engine=InnoDB;
SET FOREIGN_KEY_CHECKS=1;


USE Opere;


-- insert data values

START TRANSACTION;

INSERT INTO Autore VALUES ('1', 'Gian Lorenzo', 'Bernini', 1598, 'Napoli');
INSERT INTO Autore VALUES ('2', 'Francesco', 'Borromini', 1599, 'Bissone');

INSERT INTO Opera VALUES ('1', 'Apollo e Dafne', 'scultura', 'Roma', 'Italia', '1');
INSERT INTO Opera VALUES ('2', 'Baldacchino S.Pietro', 'architettura', 'Roma', 'Italia', '1');
INSERT INTO Opera VALUES ('3', 'Fontana dei fiumi', 'architettura', 'Roma', 'Italia', '1');
INSERT INTO Opera VALUES ('4', 'S.Ivo la Sapienza', 'architettura', 'Roma', 'Italia', '2');
        
COMMIT;

