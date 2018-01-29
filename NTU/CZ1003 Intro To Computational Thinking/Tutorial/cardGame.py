# Design a computer version of a high/low game. 
# During each turn, the player is given a number from the list. 
# Using the number, the player has to guess if the next number in the list will be higher or lower.  
# At the start of the game, a random sequence of numbers is generated in the list. 
# Note that the numbers in the list should not repeat. 
# In this program, a dealer will shuffle the cards and conduct the game play.  
# The program will simulate the player, where the simulated player will guess whether the next card will be higher 
# or lower when given the current card.

# Design a function shuffleCards() to shuffle the cards.  
# This function will return a list of unique randomly-ordered integers (from 1 to 10 (inclusive)) to simulate the deck of cards. 

# Write a function called simulateDecision(currentNumber) to simulate the decision of the player when given a number. 
# The function will decide (with some appropriate logic) whether to guess higher or lower given the current number.  
# For example, if the current number is 3, the program  will  guess  higher. 
# The function should return True to  simulate the guess is higher, and False when the guess is lower. 
# If both numbers are the same, it does not matter if the player chooses higher or lower. 



import random

def playTurn(lst):
	while len(lst) != 1:
		#Simulate user's guess
		usersGuess = simulateDecision(lst[0], max(lst), min(lst))

		#Output result of simulated user's guesses
		if usersGuess == True and lst[1] > lst[0]:
			print("Correct: {} is higher than {}".format(lst[1], lst[0]))
		elif usersGuess == False and lst[1] < lst[0]:
			print("Correct: {} is lower than {}".format(lst[1], lst[0]))
		elif usersGuess == False and lst[1] > lst[0]:
			print("Wrong: {} is higher than {}".format(lst[1], lst[0]))
		else:
			print("Wrong: {} is lower than {}".format(lst[1], lst[0]))

		#Simulate like real life removing the picked up card
		lst.pop(0)


def shuffleCards():
	#Create a list from 1 to 10
	cardsList = [x for x in range(1, 10+1)]

	#Less efficient since we know it's 1 to 10 so no need create an empty list then pick and check random repeated number
	'''while count < 10:
		randNum = random.randint(1,10)

		#Check for number already exist in deck
		for num in range(len(cardsList)):
			if randNum == cardsList[num]:
				continue

		#Add number into deck of cards
		cardsList.append(randNum)
		count += 1'''

	random.shuffle(cardsList);

	return cardsList


def simulateDecision(currentNumber, maxNum, minNum):
	#Create a random guess of high or low
	highLow = random.randint(0, 1)

	#Cannot be higher than 10 
	if currentNumber == 10:
		return False
	#Cannot be lower than 1
	elif currentNumber == 1:
		return True
	#Pretend com/person remembers what numbers were picked
	elif maxNum == currentNumber:
		return False
	elif minNum == currentNumber:
		return True

	if highLow == 1:
		return True
	
	return False


#Create a list and shuffle the list(cards)
deckOfCards = shuffleCards()

#print(deckOfCards) #debugging

playTurn(deckOfCards)