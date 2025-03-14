--Es 1

--APPARTAMENTO(CodA, Superficie, Indirizzo, Citta)
--CONTRATTO-AFFITTO(CodA, DataInizio, DataFine, NomePersona, RettaMensile)

--a)

SELECT NomePersona
FROM CONTRATTO-AFFITTO AS CA1, CONTRATTO-AFFITTO AS CA2
WHERE CA1.CodA=CA2.CodA AND CA1.DataInizio<>CA2.DataInizio
GROUP BY NomePersona, CodA
HAVING COUNT(*)>2

--versione corretta

SELECT NomePersona 
FROM CONTRATTO-AFFITTO
GROUP BY CodA,NomePersona
HAVING COUNT(*)>2

--b)

SELECT A.CodA, Indirizzo
FROM APPARTAMENTO AS A, CONTRATTO-AFFITTO AS CA
WHERE A.CodA=CA.CodA AND Citta='Torino' AND RettaMensile>500
GROUP BY A.CodA, Indirizzo
HAVING COUNT(*)<=5

--versione corretta

SELECT A.CodA, Indirizzo
FROM APPARTAMENTO AS A, CONTRATTO-AFFITTO AS CA
WHERE A.CodA=CA.CodA AND Citta='Torino'
GROUP BY A.CodA, Indirizzo
HAVING COUNT(*)<=5 AND MIN(RettaMensile)>500

--c)

SELECT A.CodA, Indirizzo
FROM APPARTAMENTO AS A, CONTRATTO-AFFITTO AS CA
WHERE A.CodA=CA.CodA AND Citta='Torino'
GROUP BY A.CodA, Indirizzo
HAVING COUNT(*)<=5

--Es 2

--GARA(CodG, Luogo, Data, Disciplina)
--ATLETA(CodA, Nome, Nazione, DataNascita)
--PARTECIPAZIONE(CodG, CodA,PosizioneArrivo, Tempo)

--a)

SELECT Nome, DataNascita
FROM GARA AS G, ATLETA AS A, PARTECIPAZIONE AS PARTECIPAZIONE
WHERE G.CodG=P.CodG AND P.CodA=A.CodA AND Nazione='Italia' AND
      G.CodG NOT IN (SELECT G.CodG
                     FROM GARA AS G
                     WHERE Disciplina='Discesa Libera')

--versione corretta

SELECT Nome,DataNascita 
FROM ATLETA
WHERE Nazione=’Italia’
AND CodA NOT IN (SELECT CodA 
                 FROM PARTECIPAZIONE P,GARA G
                 WHERE P.CodG=G.CodG
                 AND G.Disciplina=’discesa libera’)

--b)

SELECT Nazione
FROM ATLETA AS A
WHERE A.CodA IN (SELECT A.CodA
                FROM ATLETA AS A, GARA AS G, PARTECIPAZIONE AS P
                WHERE DataNascita<"1/1/1981" AND G.CodG=P.CodG AND 
                      P.CodA=A.CodA AND G.CodG IN (SELECT G.CodG
                      FROM GARA AS G
                      WHERE Disciplina='Sci di Fondo'
                      GROUP BY G.CodG
                      HAVING COUNT(*)>=10)
                GROUP BY A.CodA
                HAVING COUNT(*)>=5)

--versione corretta                

SELECT Nazione 
FROM ATLETA
WHERE DataNascita<’1/1/1980’
AND CodA IN (SELECT CodA FROM PARTECIPAZIONE P,GARA G
            WHERE P.CodG=G.CodG
            AND Disciplina=’fondo’
            GROUP BY CodA
            HAVING COUNT(*)>=10)
GROUP BY Nazione
HAVING COUNT(*)>=5

--Es 3

--EDITORE(CodE, NomeEditore, Indirizzo, Citta)
--PUBBLICAZIONE(CodP, Titolo, NomeAutore, CodE)
--LIBRERIA(CodL, NomeLibreria, Indirizzo, Citta)
--VENDITA(CodP, CodL, Data, CopieVendute)

--a)

SELECT NomeLibreria
FROM LIBRERIA AS L, PUBBLICAZIONE AS P, EDITORE AS E, VENDITA AS V
WHERE E.CodE=P.CodE AND P.CodP=V.CodP AND L.CodL=V.CodL AND 
      P.CodP NOT IN (SELECT P.CodP
                    FROM PUBBLICAZIONE AS P, EDITORE AS E
                    WHERE P.CodE=E.CodE AND E.Citta='Torino')

--versione corretta

SELECT NomeLibreria FROM LIBRERIA L
WHERE CodL NOT IN (SELECT CodL FROM VENDITA V, PUBBLICAZIONE P, EDITORE E
                   WHERE V.CodP=P.CodP
                   AND P.CodE=E.CodE
                   AND Citta=’Torino’)

--b)

SELECT NomeEditore
FROM EDITORE AS E, PUBBLICAZIONE AS P, VENDITA AS V, LIBRERIA AS L
WHERE P.CodP IN (SELECT P.CodP
                 FROM PUBBLICAZIONE AS P, VENDITA AS V, LIBRERIA AS L
                 WHERE P.CodP=V.CodP AND V.CodL=L.CodL AND Data='2002' AND
                       L.Citta='Roma' AND CopieVendute>2000)
GROUP BY NomeEditore
HAVING COUNT(*)>=10

--versione corretta

SELECT NomeEditore FROM EDITORE E, PUBBLICAZIONE P1
WHERE P1.CodE=E.CodE
AND CodP IN (SELECT CodP FROM VENDITA V, LIBRERIA L
             WHERE V.CodL=L.CodL
             AND Data>=’1/1/2002’ AND Data<=’31/12/2002’
             AND L.Citta=’Roma’
             GROUP BY CodP
             HAVING SUM(CopieVendute)>2000)
GROUP BY E.CodE, NomeEditore
HAVING COUNT(*)>=10;

--Es 4

--QUIZ(CodQuiz, Argomento, Punteggio)
--STUDENTE(Matricola, Nome, Indirizzo, Citta)
--RISULTATO-TEST(Matricola, CodQuiz, RispostaCorretta)

--a)

SELECT Nome
FROM STUDENTE AS S
WHERE Matricola NOT IN (SELECT Matricola
                        FROM QUIZ AS Q, RISULTATO-TEST AS RT
                        WHERE Argomento='Matematica' AND Punteggio=0 AND 
                              Q.CodQuiz=RT.CodQuiz AND RT.Matricola=S.Matricola)

--versione corretta

SELECT Nome FROM STUDENTE S
WHERE Matricola NOT IN (SELECT Matricola FROM RISULTATO_TEST R,QUIZ Q
                        WHERE R.CodQuiz=Q.CodQuiz
                        AND RispostaCorretta=’si’
                        AND Argomento=’matematica’)

--b)

SELECT Nome
FROM STUDENTE AS S, QUIZ AS Q, RISULTATO-TEST AS RT
WHERE Q.CodQuiz=RT.CodQuiz AND RT.Matricola=S.Matricola AND Citta='Torino'
GROUP BY Nome
HAVING MAX(Punteggio)

--versione corretta

SELECT Nome FROM STUDENTE S,RISULTATO_TEST R,QUIZ Q
WHERE S.Matricola=R.Matricola AND Q.CodQuiz=R.CodQuiz AND Citta=’Torino’ AND
      RispostaCorretta=’si’ AND Argomento=’matematica’
GROUP BY S.Matricola,Nome
HAVING SUM(Punteggio) = (SELECT SUM(Punteggio) 
                         FROM QUIZ
                         WHERE Argomento=’matematica’);

--Es 5

--ALLOGGIO(CodA, Indirizzo, Citta, Superficie, CostoAffittoMensile)
--CONTRATTO-AFFITTO(CodC, DataInizio, DataFine, NomePersona, CodA)

--a)

SELECT A.CodA, Indirizzo, Citta
FROM ALLOGGIO AS A, CONTRATTO-AFFITTO AS CA
WHERE A.CodA=CA.CodA AND AVG(Superficie)>(SELECT AVG(Superficie)
                                          FROM ALLOGGIO AS A1
                                          WHERE A1.Citta=A.Citta)

--versione corretta

SELECT CodA, Indirizzo, Citta FROM ALLOGGIO A1
WHERE Superficie > (SELECT AVG(Superficie) 
                    FROM ALLOGGIO A2
                    WHERE A2.Citta=A1.Citta);

--Es 6

--AEREI (Matr, Modello, NumPosti)
--ORARIO (Sigla, ParteDa, Destinaz, OraPart, OraArr)
--VOLI (Sigla, Matr, Data, PostiPren)

--a)

SELECT ParteDa, Destinaz
FROM ORARIO AS O
WHERE Sigla NOT IN (SELECT O.Sigla
                    FROM ORARIO AS O, AEREI AS A, VOLI AS V
                    WHERE A.Matr=V.Matr AND O.Sigla=V.Sigla AND 
                    Modello='Boeing-747');

--versione corretta                    

SELECT ParteDa, Destinaz FROM ORARIO O1
WHERE Sigla NOT IN (SELECT O1.Sigla 
                    FROM ORARIO O2, VOLI V, AEREI A
                    WHERE O2.Sigla=V.Sigla AND A.Matr=V.Matr
                    AND A.Modello=’Boing-747’ AND O2.ParteDa=O1.ParteDa
                    AND O2.Destinaz=O1.Destinaz);