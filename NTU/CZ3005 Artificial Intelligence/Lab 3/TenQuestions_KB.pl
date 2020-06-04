:- dynamic(chosenSport/1).
:- dynamic(gameCounter/1).
:- dynamic(triesLeft/1).

% START OF INTERFACE COMMAND
/* command to start the game or new round */
play :- 
	initialize,
	gameCounter(X),
	format("Begin round ~w.", X),
	increment.

/* will decrease tries left before checking if guessed property is correct or not */
has(GuessProperty) :-
	triesChecker("has()");

	decrement,
	selectedSport(SportPicked),
	properties(PropertyList, SportPicked),
	member(GuessProperty, PropertyList),
	triesLeft(X), format("Yes, it has. (Left ~w tries.)", X);

	triesLeft(X), format("No. (Left ~w tries.)", X).

/* will decrease tries left before checking if guessed sport is correct or not.
 check if still have tries left before deciding if continue or game over */
is(GuessSport) :- 
	selectedSport(GuessSport),
	write("Congratulations! You have correctly guessed the sport."), nl,
	gameOver;

	triesChecker("is()");

	write("Incorrect. Please try again."), nl.

% END OF INTERFACE COMMAND

% START OF SYSTEM RULES
/* initilize a new round such as pick a new sport, 
 temporary store the selected sport for the round, 
 and reset number of tries left for query for the user */
initialize :- 
	pickSport(SportPicked),
	retractall(selectedSport(_)),
	assertz(selectedSport(SportPicked)),
	retractall(triesLeft(_)),
	assertz(triesLeft(10)).

/* to decrement the number of tries left */
decrement :- 
	triesLeft(X),
	Y is X - 1,
	retractall(triesLeft(_)),
	assertz(triesLeft(Y)).

/* end of the round, check if still have sports left to guess to play more rounds */
gameOver :- 
	sportsAvailable(ValidSportsList),
	ValidSportsList \== [],
	write("Game over! Would you like to restart the game? (y/n) "),
	read(Input),
	restartGame(Input);

	write("Game over!"), nl,
	reset.

/* to increment the number of games counter */
increment :-
	gameCounter(X),
	Y is X + 1,
	retractall(gameCounter(_)),
	assertz(gameCounter(Y)).

/* randomly generate an available sport from a list of sports available to play.
 The chosen sport will be keep tracked in chosenSport() */
pickSport(Result) :- 
	sportsAvailable(X), 
	random_member(Result, X),
	assertz(chosenSport(Result)).

/* reset knowledge base */
reset :-
	retractall(chosenSport(_)),
	retractall(gameCounter(_)),
	assertz(gameCounter(1)),
	retractall(triesLeft(_)),
	assertz(triesLeft(10)),
	abort.

/* based on user input, decide if should play another round or terminate */
restartGame(Input) :- 
	Input == y -> play;
	
	reset.

/* find all available sports left since cannot have repeated chosen sports */
sportsAvailable(ValidSportsList) :- 
	findall(X, sport(X), SportsList), 
	findall(Y, chosenSport(Y), ChosenSportsList),
	subtract(SportsList, ChosenSportsList, ValidSportsList).

/* check if user has run of tries */
triesChecker(From) :- 
	triesLeft(X),
	From == "has()",
	X == 0 -> write("No more questions available. Please guess what sport it is."), nl;

	triesLeft(X),
	From == "is()",
	X == 0 -> write("Sorry! It's incorrect."), nl,
	gameOver.

% END OF SYSTEM RULES



% FACTS
/* sports that the program can randomly choose from */
sport(badminton).
sport(basketball).
sport(football).
sport(swimming).
sport(tennis).
sport(fieldhockey).
sport(baseball).
sport(rugby).

/* properties of the sports which the user can query properties which will match with the properties of the chosen sport */
properties([racket, shuttlecock, net, court, singles, doubles, teams_per_game=2], badminton).
properties([jersey, ball, basket, court, captain, teamsize=5, teams_per_game=2], basketball).
properties([jersey, ball, goalpost, grass, field, captain, teamsize=11, teams_per_game=2], football).
properties([swimsuit, goggles, swimcap, water, pool, lane, teamsize=1, teams_per_game=many], swimming).
properties([racket, ball, net, court, singles, doubles, teams_per_game=2], tennis).
properties([stick, helmet, shinguards, jersey, ball, pitch, goalpost, teamsize=11, teams_per_game=2], fieldhockey).
properties([bat, glove, ball, jersey, cap, field, base, homeplate, teamsize=9, teams_per_game=2], baseball).
properties([ball, jersey, cap, goalpost, pitch, teamsize=15, teams_per_game=2], rugby).

/* dynamic facts which are counters to keep track of the program */
gameCounter(1).
triesLeft(10).