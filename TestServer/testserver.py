from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/sensor", methods=["POST"])
def sensor():
    data = request.json
    print("Received JSON:", data)
    return jsonify({"status": "ok"}), 200

if __name__ == "__main__":
    # 0.0.0.0 makes it accessible on your local network
    app.run(host="0.0.0.0", port=5000)
