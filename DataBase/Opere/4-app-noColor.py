from flask import Flask, render_template, request
from sqlalchemy.exc import SQLAlchemyError
from sqlalchemy import create_engine

app = Flask(__name__)

@app.route("/")
def index():


    dialect = "mysql"
    username="root"
    password=""
    host="127.0.0.1"
    dbname = "Opere"
    #Connection object creation
    engine = create_engine("%s://%s:%s@%s/%s"%(dialect,username,password,host,dbname))

    try:
        con = engine.connect()

        #QUERY SQL
        query="SELECT DISTINCT citta\
               FROM autore"

        result = con.execute(query)
        header = result.keys()
        con.close()

        return render_template('index.html', rows = result)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


    

@app.route("/opere")
def opere():
    
    error=""
    # Validazione anni
    if not('annoDa' in request.args and 'annoA' in request.args):
        error += 'Inserire anno di inizio ed anno di fine. '
    elif not(request.args.get('annoDa').isdigit() and request.args.get('annoA').isdigit()):
        error += 'Anno non valido, inserire un valore numerico. '
    elif int(request.args.get('annoDa')) > int(request.args.get('annoA')):
        error += 'L\'anno di fine non puo\' essere precedente all\'anno di inizio. '

    # Validazione citta'
    if not('citta' in request.args) or request.args.get('citta')=="":
        error += 'Inserire citta\'. '

    if error:
        return render_template('errore.html', error_message=error)
    # Letttura opere
    annoDa = int(request.args.get('annoDa'))
    annoA = int(request.args.get('annoA'))
    citta = request.args.get('citta')

    dialect = "mysql"
    username="root"
    password=""
    host="127.0.0.1"
    dbname = "Opere"
    #Connection object creation
    engine = create_engine("%s://%s:%s@%s/%s"%(dialect,username,password,host,dbname))

    try:
        con = engine.connect()

        #QUERY SQL
        query="SELECT autore.cognome, opera.nome, categoria\
               FROM autore, opera\
               WHERE autore.coda = opera.autore AND anno >= %d AND anno <= %d AND Autore.citta='%s'\
               ORDER BY cognome, opera.nome;"%(annoDa,annoA,citta)


        result = con.execute(query)
        header = result.keys()
        con.close()
        return render_template('opere-simple.html', annoDa=annoDa, annoA=annoA, citta=citta, header=header, values=result)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


app.run(debug=True, port=8080)