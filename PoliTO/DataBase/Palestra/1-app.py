from flask import Flask, render_template, request
from sqlalchemy.exc import SQLAlchemyError
from sqlalchemy import create_engine

app = Flask(__name__)

@app.route("/corso")
def index():

    return render_template('form1.html')

@app.route("/inseriscicorso")
def inserisci_programma():


    error=""

    if('codc' not in request.args or 'nome' not in request.args or 
       'tipo' not in request.args or 'livello' not in request.args):
        error += 'Inserire tutti i campi necessari. '
        return render_template('errore.html', error_message=error)

    codc = request.args.get('codc')
    nome = request.args.get('nome')
    tipo = request.args.get('tipo')
    livello = request.args.get('livello')

    if (codc=="" or nome=="" or tipo=="" or livello==""):
        error += 'Inserire tutti i campi necessari. '
        return render_template('errore.html', error_message=error)

    if(livello.isnumeric()==False):
        error += 'Il livello è un numero non valido'
        return render_template('errore.html', error_message=error)

    livello = int(livello)
    if(livello<1 or livello>4):
        error += 'Il livello è un numero compreso tra 1 e 4'
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


        query = "INSERT INTO Corsi(CodC,Nome,Tipo,Livello)\
        VALUES ('%s','%s','%s','%d')"%(codc,nome,tipo,livello)
        con.execute(query)

        con.close()
	
        return render_template('inserimento-corso.html',codc=codc, nome=nome)
    except SQLAlchemyError as e:

        error = str(e.__dict__['orig'])
        return render_template('errore.html', error_message=error)


app.run(debug=True, port=8080)