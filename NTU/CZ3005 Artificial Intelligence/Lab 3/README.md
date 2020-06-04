## Assignment 1: Ten questions
In the two-people game of ten questions, one person is answerer and the other person is questioner. They decide one topic to confine the scope, say Olympics games. The answerer decides an Olympic game in his/her mind and does not reveal the game to the questioner. Questioner is supposed to ask a maximum of ten questions to guess the answer.

Design a prolog script that plays the role of an answerer. For example, queries can be related to:

* Team size (2 for badminton doubles, 1 for swimming)
* Number of teams in a game (2 for badminton doubles, many for swimming)
* Arena type (court for badminton doubles, pool for swimming)
* Play device (shuttle cock or racket for badminton doubles, water for swimming, ball or racket for tennis, javelin for javelin throw, etc.)
* Game mode (knock out, timed)
* Performance type (score, win)

There should be only one form of query, for example: has(ball), has(pool), has(team), has(teamsize,2), has (teams_per_game, 2), etc. And one form of decision: is(badminton).

Prolog script should be able to play the game 5 times, choosing a different game each time.