--Es 1

--RIVISTA (CodR, NomeR, Editore)
--ARTICOLO (CodA, Titolo, Argomento, CodR)

--a)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodR AND Argomento='Motociclismo'

--b)
SELECT R.CodR, NomeR
FROM RIVISTA AS R
WHERE CodR NOT IN (SELECT CodR
                   FROM ARTICOLO
                   WHERE Argomento='Motociclismo')

--c)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodR AND R.CodR NOT IN (SELECT CodR
                                          FROM ARTICOLO
                                          WHERE Argomento<>'Motociclismo')

--d)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodR AND R.CodR IN (SELECT CodR
                                   FROM ARTICOLO
                                   WHERE Argomento='Motociclismo' OR Argomento='Auto')
                            
--e)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodA AND R.CodR IN (SELECT CodR
                                   FROM ARTICOLO
                                   WHERE Argomento='Motociclismo' AND Argomento='Auto')

--f)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodR AND R.CodR IN (SELECT CodR
                                   FROM ARTICOLO
                                   WHERE Argomento='Motociclismo'
                                   GROUP BY CodR
                                   HAVING COUNT(CodR)>=2)

--g)
SELECT R.CodR, NomeR
FROM RIVISTA AS R, ARTICOLO AS A
WHERE R.CodR=A.CodR AND R.CodR IN (SELECT CodR
                                       FROM ARTICOLO
                                       WHERE Argomento='Motociclismo')
GROUP BY R.CodR, NomeR
HAVING COUNT(DISTINCT R.CodR)=1

--Es 2

--VELISTI(Vid, VNome, Esperienza, DataNascita)
--PRENOTAZIONI(Vid, Bid, Data)
--BARCHE(Bid, BNome, Colore)

--a)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P, BARCHE AS B
WHERE V.Vid=P.Vid AND P.Bid=B.Bid AND Colore='Rosso' OR Colore='Verde'

--b)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P, BARCHE AS B
WHERE V.Vid=P.Vid AND P.Bid=B.Bid AND Colore='Rosso' AND Colore='Verde'

--c)
SELECT V.Vid
FROM VELISTI AS V, PRENOTAZIONI AS P
WHERE V.Vid=P.Vid AND V.Vid NOT IN (SELECT Vid
                                    FROM PRENOTAZIONI, BARCHE
                                    WHERE P.Bid=B.Bid AND  Colore='Rosso')

--d)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P
WHERE V.Vid=P.Vid AND V.Vid NOT IN (SELECT Vid
                                    FROM PRENOTAZIONI, BARCHE
                                    WHERE P.Bid=B.Bid AND  Colore='Rosso')

--e)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P
WHERE V.Vid=P.Vid
GROUP BY V.Vid, VNome
HAVING COUNT(DISTINCT Bid)>=2

--f)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P
WHERE V.Vid=P.Vid
GROUP BY V.Vid, VNome
HAVING COUNT(DISTINCT Bid)>=3

--g)
SELECT V.Vid, VNome
FROM VELISTI AS V, PRENOTAZIONI AS P
WHERE V.Vid=P.Vid
GROUP BY V.Vid, VNome
HAVING COUNT(*)>=3

--Es 3

--AEREO(Aid, ANome, Autonomia)
--CERTIFICATO(Did, Aid)
--DIPENDENTE(Did, DNome, Stipendio)

--a)
SELECT D.Did, DNome
FROM AEREO AS A, CERTIFICATO AS C,DIPENDENTE AS D
WHERE A.Aid=C.Aid AND C.Did=D.Did AND Autonomia>=5000

--b)
SELECT D.Did, DNome
FROM AEREO AS A, CERTIFICATO AS C,DIPENDENTE AS D
WHERE A.Aid=C.Aid AND C.Did=D.Did AND Autonomia>=5000
GROUP BY D.Did, DNome
HAVING COUNT(DISTINCT *)>=2

--c)
SELECT D.Did, DNome
FROM AEREO AS A, CERTIFICATO AS C,DIPENDENTE AS D
WHERE A.Aid=C.Aid AND C.Did=D.Did AND Autonomia>=5000 AND Did IN (SELECT Did
                                                                  FROM CERTIFICATO AS C, AEREO AS A
                                                                  WHERE C.Aid=A.Aid AND ANome='Boeing')
GROUP BY D.Did, DNome
HAVING COUNT(DISTINCT *)>=2