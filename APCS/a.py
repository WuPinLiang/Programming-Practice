
from flask import Flask, request, render_template, Response
from flag import FLAG

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/robots.txt')
def noindex():
    r = Response(response="User-Agent: *\nDisallow: /hum4n-0nLy\n", status=200, mimetype="text/plain")
    r.headers["Content-Type"] = "text/plain; charset=utf-8"
    return r

@app.route('/hum4n-0nLy')
def source_code():
    return open(__file__).read()

@app.route('/r0b07-0Nly-9e925dc2d11970c33393990e93664e9d')
def secret_flag():
    if len(request.headers) > 1:
        return "I'm sure robots are headless, but you are not a robot, right?"
    return FLAG

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80, debug=False)

