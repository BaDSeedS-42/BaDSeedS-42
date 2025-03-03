--Es 1

--CORSO (CodCorso, NomeC, Anno, Semestre)
--ORARIO-LEZIONI (CodCorso, GiornoSettimana, OraInizio, OraFine, Aula)

SELECT Aula
FROM CORSO, ORARIO-LEZIONI
WHERE CORSO.CodCorso=ORARIO-LEZIONI.CodCorso AND
      CodCorso NOT IN (SELECT CodCorso
                                  FROM ORARIO-LEZIONI
                                  WHERE Anno=1 AND CORSO.CodCorso=ORARIO-LEZIONI.CodCorso);

--versione corretta

SELECT DISTINCT Aula
FROM ORARIO-LEZIONI
WHERE Aula NOT IN (SELECT Aula
                  FROM ORARIO-LEZIONI AS OL, CORSO AS C
                  WHERE C.Anno=1 AND C.CodCorso=OL.CodCorso);

--versione rifatta il giorno dopo

SELECT DISTINCT Aula
FROM CORSO as C, ORARIO-LEZIONI AS OL
WHERE C.CodCorso=OL.CodCorso AND CodCorso NOT IN(SELECT CodCorso
                                                 FROM ORARIO-LEZIONI AS OL, CORSO AS C
                                                 WHERE Anno=1)

--Es 2

--versione corretta

SELECT C.CodCorso, NomeC, SUM(OraFine-OraInizio)
FROM ORARIO-LEZIONI AS OL, CORSO AS C
WHERE Anno=3 AND C.CodCorso=OL.CodCorso
GROUP BY C.CodCorso, NomeC
HAVING COUNT (DISTINCT GiornoSettimana) >3 AND
       SUM(OraFine-OraInizio)>10

--versione rifatta il giorno dopo

SELECT C.CodCorso, NomeC, SUM(OraFine-OraInizio)
FROM ORARIO-LEZIONI AS OL, CORSO AS C
WHERE Anno=3 AND C.CodCorso=OL.CodCorso
GROUP BY C.CodCorso, NomeC
HAVING COUNT(*)>10
HAVING COUNT(DISTINCT *)>3

--Es 3

--ALLOGGIO (CodA, Indirizzo, Citta, Superficie, CostoAffittoMensile)
--CONTRATTO-AFFITTO (CodC, DataInizio, DataFine, NomePersona, CodA)

SELECT Citta, MAX(CostoAffittoMensile), AVG(CostoAffittoMensile), MAX(DataFine-DataInizio), AVG(DataFine-DataInizio), COUNT(CodC)
FROM ALLOGGIO AS A, CONTRATTO-AFFITTO AS CA
WHERE A.CodA=C.CodA
GROUP BY Citta
HAVING COUNT(DataInizio)>=100

--Es 4

SELECT NomePersona
FROM ALLOGGIO AS A, CONTRATTO-AFFITTO AS CA
WHERE CodA NOT IN (SELECT CodA
                  FROM ALLOGGIO AS A, CONTRATTO-AFFITTO AS CA
                  WHERE A.CodA=CA.CodA AND Superficie>80)

--Es 5

--AEREI (Matr, Modello, NumPosti)
--ORARIO (Sigla, ParteDa, Destinaz, OraPart, OraArr)
--VOLI (Sigla, Matr, Data, PostiPren)

SELECT O.Sigla, OraPart
FROM AEREI AS A, ORARIO AS A, VOLI AS V
WHERE A.Matr=V.Matr AND V.Sigla=O.Sigla AND 
      ParteDa='Milano' AND Destinaz='Napoli' AND
      DATA='1/10/1993' AND NumPosti<>0 AND
      (OraArr-OraPart)<AVG(OraArr-OraPart)
GROUP BY O.Sigla, OraPart

--verione corretta

SELECT O.Sigla, OraPart
FROM AEREI AS A, ORARIO AS A, VOLI AS V
WHERE A.Matr=V.Matr AND V.Sigla=O.Sigla AND 
      ParteDa='Milano' AND Destinaz='Napoli' AND
      DATA='1/10/1993' AND NumPosti<>0 AND
      (OraArr-OraPart)<(SELECT AVG(OraArr-OraPart)
                        FROM ORARIO AS O2, VOLI AS V2
                        WHERE ParteDa='Milano' AND Destinaz='Napoli' AND
                              V2.Sigla=O2.Sigla)

--Es 6

--ORCHESTRA(CodO, NomeO, NomrDirettore, numElementi)
--CONCERTI(CodC, Data, CodO, CodS, PrezzoBiglietto)
--SALE(CodS, NomeS, Citt`a, Capienza)

SELECT O.CodO, NomeO
FROM ORCHESTRA AS O, CONCERTI AS C, SALE AS S
WHERE O.CodO=C.CodO AND C.CodS=S.CodS AND numElementi>30 AND
      Citta IN (SELECT Citta
                FROM SALE
                WHERE Citta='Milano') AND
      Citta IN (SELECT Citta
                FROM SALE
                WHERE Citta='Torino') AND
      Citta NOT IN (SELECT Citta
                    FROM SALE
                    WHERE Citta='Bologna')

--Es 7

--CLIENTE(Cod-Cli,nome)
--CONTO(Cod-Conto, saldo, agenzia, stato)
--CONTO-CLIENTE(Cod-Conto, Cod-Cli)

--versione mia

SELECT DISTINCT agenzia
FROM CLIENTE AS CL, CONTO AS CO, CONTO-CLIENTE AS CC
WHERE CL.Cod-Cli=CC.Cod-Cli AND 
      CC.Cod-Conto=CO.Cod-Conto AND CL.Cod-Cli IN (SELECT CL.Cod-Cli
                                                   FROM CLIENTE AS CL
                                                   GROUP BY CL.Cod-Cli
                                                   HAVING COUNT(*)=1)     

--versione di filippo

SELECT DISTINCT C.Agenzia
FROM CONTO C, CONTO-CLIENTE CC
WHERE CC.Cod-Conto=C.Cod-Conto AND C.Cod-Cli IN (SELECT Cod-Cli
                                                FROM CONTO-CLIENTE
                                                GROUP BY Cod-Cli
                                                HAVING COUNT(*)=1)

--versione rifatta

SELECT DISTINCT agenzia
FROM CLIENTE AS CL, CONTO AS CO, CONTO-CLIENTE AS CC
WHERE CC.Cod-Conto=CO.Cod-Conto AND CC.Cod-Cli IN (SELECT CC1.Cod-Cli 
                                                   FROM CONTO-CLIENTE AS CC1
                                                   WHERE CC1.Cod-Conto=CC.Cod-Conto AND
                                                         CC1.Cod-Cli<>CC.Cod-Cli) AND
      CC.Cod-Conto IN (SELECT CC2.Cod-Cli 
                       FROM CONTO-CLIENTE AS CC2
                       WHERE CC2.Cod-Cli=CC.Cod-Cli AND
                             CC2.Cod-Cli<>CC.Cod-Cli)                                                   

--Es 8

--CONTRIBUENTE(CodFiscale, Nome, Via, Citta)
--DICHIARAZIONE(CodDichiarazione, Tipo, Reddito)
--PRESENTA(CodFiscale, CodDichiarazione, Data)

SELECT D.CodDichiarazione, Nome, AVG(Reddito)
FROM CONTRIBUENTE AS C, DICHIARAZIONE AS D, PRESENTA AS P
WHERE C.CodFiscale=P.CodFiscale AND 
      P.CodDichiarazione=D.CodDichiarazione AND
      Data>=1990
GROUP BY D.CodDichiarazione, Nome
HAVING AVG(Reddito)>(SELECT AVG(Reddito)
                     FROM DICHIARAZIONE AS D)

--Es 9

--PERSONA(Nome, Sesso, Eta)
--GENITORE(Nome-Gen, Nome-Figlio)

SELECT Nome
FROM PERSONA AS P, GENITORE AS G
WHERE Eta<10 AND P.Nome=G.Nome-Gen AND Nome-Figlio NOT IN (SELECT Nome-Figlio
                                                           FROM GENITORE AS G1
                                                           WHERE G1.Nome-Figlio<>G.Nome-Figlio)