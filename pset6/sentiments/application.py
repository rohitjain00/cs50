from flask import Flask, redirect, render_template, request, url_for
from helpers import get_user_timeline

import helpers
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    recent_tweets = get_user_timeline(screen_name,100)
    if recent_tweets == None:
        sys.exit("ensure screen Name")

    analyze = Analyzer('positive-words.txt','negative-words.txt')

    no_positive,no_negative,no_neutral,positive,negative,neutral = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    for tweet in recent_tweets:
        sentiment = analyze.analyze(tweet)

        if sentiment > 0:
            no_positive += 1
        if sentiment < 0:
            no_negative += 1
        else:
            no_neutral += 1

        positive = (no_positive/len(recent_tweets))*100
        negative = (no_negative/len(recent_tweets))*100
        neutral = (no_neutral/len(recent_tweets))*100


    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
