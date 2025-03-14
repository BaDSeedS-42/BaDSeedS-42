from flask import Flask, render_template, request
from sqlalchemy.exc import SQLAlchemyError
from sqlalchemy import create_engine

dialect = "mysql"
username="root"
password=""
host="127.0.0.1"
dbname = "CAMPIONATO_CICLISTICO"
engine = create_engine("%s://%s:%s@%s/%s"%(dialect,username,password,host,dbname))

app = Flask(__name__)

@app.route("/posizioneCiclistaInTappa")
def posizione_ciclista_in_tappa():

    try:
        con = engine.connect()

        query="SELECT CodC, Nome, Cognome\
               FROM CICLISTA\
               ORDER BY CodC, Cognome, Nome"\

        ciclisti = con.execute(query)

        con.close()

        return render_template('posizioneciclistaintappa.html', ciclisti = ciclisti)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


@app.route("/risultatoPosizioneCiclistaInTappa")
def risultato_posizione_ciclista_in_tappa():

    error=""

    CodC = request.args.get('CodC')
    Nome = request.args.get('Nome')
    Cognome = request.args.get('Cognome')
    CodT = request.args.get('CodT')

    if('CodC' not in request.args or 'CodT' not in request.args):
        error += 'Inserire tutti i campi necessari. '
        return render_template('errore.html', error_message=error)

    if (CodC=="" or CodT==""):
        error += 'Inserire tutti i campi necessari. '
        return render_template('errore.html', error_message=error)

    if(CodT.isnumeric()==False):
        error += 'Il CodT è un numero non valido'
        return render_template('errore.html', error_message=error)

    CodT = int(CodT)
    if(CodT<1):
        error += 'Il CodT è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)


    try:
        con = engine.connect()    


        query = "SELECT Posizione, Edizione\
        FROM CLASSIFICA_INDIVIDUALE\
        WHERE CodC='%s' AND CodT='%s'\
        ORDER BY Edizione"%(CodC, CodT)\

        result = con.execute(query)

        con.close()
	
        return render_template('risultatoposizione.html', result = result)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)

#--------------------------------------------------------------------------------------------------------------------------

@app.route("/inserisciCiclista")
def inserisisci_ciclista():

    try:
        con = engine.connect()

        query="SELECT DISTINCT CodS\
               FROM CICLISTA\
               ORDER BY CodS"\

        squadre = con.execute(query)

        con.close()

        return render_template('inserisciciclista.html', squadre = squadre)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)



@app.route("/risultatatoInserisciCiclista")
def risultatato_inserisci_ciclista():


    error=""

    if('CodC' not in request.args or 'Nome' not in request.args or 
       'Cognome' not in request.args or 'Nazionalita' not in request.args or 
       'CodS' not in request.args or 'AnnoNascita' not in request.args):
        error += 'Inserire tutti i dati necessari.'
        return render_template('errore.html', error_message=error)

    CodC = request.args.get('CodC')
    Nome = request.args.get('Nome')
    Cognome = request.args.get('Cognome')
    Nazionalita = request.args.get('Nazionalita')
    CodS = request.args.get('CodS')
    AnnoNascita = request.args.get('AnnoNascita')

    if(CodC.isnumeric()==False):
        error += 'Il CodC è un numero non valido'
        return render_template('errore.html', error_message=error)

    CodC = int(CodC)
    if(CodC<1):
        error += 'Il CodC è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    if(CodS.isnumeric()==False):
        error += 'Il CodS è un numero non valido'
        return render_template('errore.html', error_message=error)

    CodS = int(CodS)
    if(CodS<1):
        error += 'Il CodS è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    if(AnnoNascita.isnumeric()==False):
        error += 'L\'anno di nascita è un numero non valido'
        return render_template('errore.html', error_message=error)

    AnnoNascita = int(AnnoNascita)
    if(AnnoNascita<1):
        error += 'L\'anno di nascita è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    try:
        con = engine.connect()  

        trans = con.begin()
 
        query  = "SELECT CodS\
        FROM CICLISTA\
        WHERE CodS='%s'"%(CodS)

        squadra = con.execute(query)

        squadra = squadra.fetchall()
        if not (squadra):
            error="La squadra non esiste ancora nella base di dati";
            trans.rollback()
            return render_template('errore.html', error_message=error)

        query  = "SELECT CodC\
        FROM CICLISTA\
        WHERE CodC='%s'"%(CodC)
        
        
        ciclista = con.execute(query)
        
        ciclista = ciclista.fetchall() 
        if (ciclista):
            error="Non è consentito inserire un ciclista già presente nella base di dati";
            trans.rollback()
            return render_template('errore.html', error_message=error)

        query = "INSERT INTO CICLISTA (CodC, Nome, Cognome, Nazionalita, CodS, AnnoNascita)\
        VALUES ('%d','%s','%s','%s','%d','%d')"%(CodC, Nome, Cognome, Nazionalita, CodS, AnnoNascita)

        con.execute(query)

        trans.commit()
        
        trans.close()

        con.close()
	
        return render_template('successo.html')
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        trans.rollback()
        return render_template('errore.html', error_message=error)

#--------------------------------------------------------------------------------------------------------------------------

@app.route("/inserisciPosizione")
def inserisisci_posizione():

    try:
        con = engine.connect()

        query="SELECT DISTINCT CodC\
               FROM CLASSIFICA_INDIVIDUALE\
               ORDER BY CodC"\

        ciclisti = con.execute(query)

        query="SELECT DISTINCT CodT\
               FROM CLASSIFICA_INDIVIDUALE\
               ORDER BY CodT"\

        tappe = con.execute(query)

        query="SELECT DISTINCT Edizione\
               FROM CLASSIFICA_INDIVIDUALE\
               ORDER BY Edizione"\

        edizioni = con.execute(query)

        con.close()

        return render_template('inserisciposizione.html', ciclisti = ciclisti, tappe = tappe, edizioni = edizioni)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


@app.route("/risultatatoInserisciPosizione")
def risultato_inserisci_posizione():


    error=""

    if('CodC' not in request.args or 'CodT' not in request.args or 
       'Edizione' not in request.args or 'Posizione' not in request.args):
        error += 'Inserire tutti i dati necessari.'
        return render_template('errore.html', error_message=error)

    CodC = request.args.get('CodC')
    CodT = request.args.get('CodT')
    Edizione = request.args.get('Edizione')
    Posizione = request.args.get('Posizione')

    if(CodC.isnumeric()==False):
        error += 'Il CodC è un numero non valido'
        return render_template('errore.html', error_message=error)

    CodC = int(CodC)
    if(CodC<1):
        error += 'Il CodC è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    if(CodT.isnumeric()==False):
        error += 'Il CodT è un numero non valido'
        return render_template('errore.html', error_message=error)

    CodT = int(CodT)
    if(CodT<1):
        error += 'Il CodT è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    if(Edizione.isnumeric()==False):
        error += 'L\'edizione è un numero non valido'
        return render_template('errore.html', error_message=error)

    Edizione = int(Edizione)
    if(Edizione<1):
        error += 'L\'edizione è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    if(Posizione.isnumeric()==False):
        error += 'La posizione è un numero non valido'
        return render_template('errore.html', error_message=error)

    Posizione = int(Posizione)
    if(Posizione<1):
        error += 'La posizione è un numero maggiore di 1'
        return render_template('errore.html', error_message=error)

    try:
        con = engine.connect()  

        trans = con.begin()
 
        query  = "SELECT CodC\
        FROM CLASSIFICA_INDIVIDUALE\
        WHERE CodT='%d' AND Edizione='%d'"%(CodT, Edizione)

        verifica_CodC = con.execute(query)

        verifica_CodC = verifica_CodC.fetchall()
        if not (verifica_CodC):
            error="Il ciclista relativo alla tappa %d e all\'edzione n° %d, non esiste ancora nella base di dati" %(CodT, Edizione);
            trans.rollback()
            return render_template('errore.html', error_message=error)

        query  = "SELECT CodT\
        FROM CLASSIFICA_INDIVIDUALE\
        WHERE CodC='%d' AND Edizione='%d'"%(CodC, Edizione)

        verifica_CodT = con.execute(query)

        verifica_CodT = verifica_CodT.fetchall()
        if not (verifica_CodT):
            error="Il ciclista con CodC %d che ha partecipato all\'edzione n° %d, non esiste ancora nella base di dati" %(CodC, Edizione);
            trans.rollback()
            return render_template('errore.html', error_message=error)

        query  = "SELECT Edizione\
        FROM CLASSIFICA_INDIVIDUALE\
        WHERE CodC='%d' AND CodT='%d'"%(CodC, CodT)

        verifica_Edizione = con.execute(query)

        verifica_Edizione = verifica_Edizione.fetchall()
        if not (verifica_Edizione):
            error="Il ciclista con CodC %d relativo alla tappa %d, non esiste ancora nella base di dati" %(CodC, CodT);
            trans.rollback()
            return render_template('errore.html', error_message=error)


        query = "INSERT INTO CLASSIFICA_INDIVIDUALE (CodC, CodT, Edizione, Posizione)\
        VALUES ('%d','%d','%d','%d')"%(CodC, CodT, Edizione, Posizione)

        con.execute(query)

        trans.commit()

        trans.close()

        con.close()
	
        return render_template('successo.html')
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        trans.rollback()
        return render_template('errore.html', error_message=error)


app.run(debug=True, port=8080)