from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp
import csv
import datetime

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    return apology("TODO")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""
    if request.method == "GET":
        return render_template("buy.html")

    elif request.method == "POST":
        share_short = request.form.get("stock_symbol")
        shares = lookup(share_short)

    if shares == None:
        return apology("Sorry no Share Found")

    no_shares = int(request.form.get("no_of_shares"))

    if no_shares < 0:
        return apology("Negative Dude Seriously!")

    cash = db.execute("SELECT cash FROM users WHERE username = :username", username=request.form.get("username"))

    to_spend = no_shares * shares.price

    if to_spend > cash:
        return apology("PaISA Nhi H RE!!")
    else:
        db.execute("UPDATE user SET cash = cash - :to_spend WHERE username = :username ",
        to_spend = to_spend, username=request.form.get("username"))
        #add the log to buy_history table
        db.execute("INSERT INTO buy_history (samay,price,username,stock_name,share_no) VALUES (:date,:price,:username,:stock_name,:share_no)"
        ,date = datetime.datetime.now(),price = shares.price,username = request.form.get("username"),stock_name = share_short,share_no =
        no_share)

    return render_template("layout.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    return apology("TODO")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    elif request.method == "POST":
        share_short = request.form.get("stock_symbol")
        shares = lookup(share_short)

        if shares == None:
            return apology("Sorry no Share Found")


        return render_template("quoted.html",shares = shares)



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    if request.method == "POST":
        if not request.form.get("username") or not request.form.get("password") or not request.form.get("Re-password"):
            return apology("all the feilds are neccessory!")
        elif request.form.get("password") != request.form.get("Re-password"):
            return apology("pasword do not match!")

        rows = db.execute("SELECT username FROM users")

        for username in rows:
            if username == request.form.get("username"):
                return apology("User already Registered")

        db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", username = request.form.get("username"),
        hash = pwd_context.hash(request.form.get("password")))
        return render_template("login.html")
    else:
        return render_template("register.html")




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    return apology("TODO")
