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

    # Lettura opere
    annoDa = int(request.args.get('annoDa'))
    annoA = int(request.args.get('annoA'))
    citta = request.args.get('citta')

    return render_template('opere-parameteronly.html', annoDa=annoDa, annoA=annoA, citta=citta)


app.run(debug=True, port=8080)