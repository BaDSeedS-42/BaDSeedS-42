from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template('index-static.html')

@app.route("/opere")
def opere():
    # Lettura opere
    annoDa = int(request.args.get('annoDa'))
    annoA = int(request.args.get('annoA'))
    citta = request.args.get('citta')

    return render_template('opere-parameteronly.html', annoDa=annoDa, annoA=annoA, citta=citta)
app.run(debug=True, port=8080)