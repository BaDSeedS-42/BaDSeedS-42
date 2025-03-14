from flask import Flask, render_template, request
from sqlalchemy.exc import SQLAlchemyError
from sqlalchemy import create_engine

app = Flask(__name__)

@app.route("/programmazione")
def index():

    dialect = "mysql"
    username="root"
    password=""
    host="127.0.0.1"
    dbname = "palestra"
    #Connection object creation
    engine = create_engine("%s://%s:%s@%s/%s"%(dialect,username,password,host,dbname))

    try:
        con = engine.connect()

        #QUERY SQL
        query="SELECT CodFisc, Cognome, Nome\
               FROM Istruttore\
               ORDER BY Cognome, Nome"

        istruttori = con.execute(query)

        query="SELECT CodC, Nome\
               FROM Corsi\
               ORDER BY Nome"

        corsi = con.execute(query)

        con.close()

        return render_template('form2.html', istruttori = istruttori, corsi=corsi)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)

    

@app.route("/inserisciProgrammazione")
def inserisci_programma():


    error=""

    if('codfisc' not in request.args or 'giorno' not in request.args or 
       'orainizio' not in request.args or 'durata' not in request.args or 
       'codc' not in request.args or 'sala' not in request.args):
        error += 'Inserire tutti i dati necessari.'
        return render_template('errore.html', error_message=error)

    codfisc = request.args.get('codfisc')
    if(len(codfisc)!=16):
        error += 'Il codice fiscale non è valido'
        return render_template('errore.html', error_message=error)


    giorni = ["Lunedì","Martedì","Mercoledì","Giovedì","Venerdì","Sabato"]
    giorno = request.args.get('giorno')

    if(giorno not in giorni):
        error += 'Il giorno specificato non è valido'
        return render_template('errore.html', error_message=error)

    codc = request.args.get('codc')
    orainizio = request.args.get('orainizio')
    durata = request.args.get('durata')
    sala = request.args.get('sala')

    if(durata.isnumeric()==False):
        error += 'La durata non è valida'
        return render_template('errore.html', error_message=error)

    durata = int(durata)
    if(durata>60):
        error += 'Le lezioni non possono durare più di 60 minuti'
        return render_template('errore.html', error_message=error)


    error = ""
    dialect = "mysql"
    username="root"
    password=""
    host="127.0.0.1"
    dbname = "palestra"
    #Connection object creation
    engine = create_engine("%s://%s:%s@%s/%s"%(dialect,username,password,host,dbname))

    try:
        con = engine.connect()    
        query  = "SELECT count(*) as count\
        FROM Programma\
        where CodC='%s' and Giorno='%s'"%(codc,giorno)

        result = con.execute(query)
        rows = result.fetchall() #in some systems: result.all()
        if (rows[0][0]>0):
            error="Non è consentito inserire due lezioni per lo stesso corso nello stesso giorno";
            return render_template('errore.html', error_message=error)

        query = "INSERT INTO Programma (CodFisc,Giorno,OraInizio,Durata,CodC,Sala)\
        VALUES ('%s','%s','%s','%d','%s','%s')"%(codfisc,giorno,orainizio,durata,codc,sala)
        con.execute(query)

        con.close()
	
        return render_template('inserimento-programmazione.html')
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


app.run(debug=True, port=8080)
