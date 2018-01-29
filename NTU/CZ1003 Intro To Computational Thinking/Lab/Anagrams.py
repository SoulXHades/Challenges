# Your task is to write a program, which given a word, 
# will output all the anagrams of that word beginning with the letter 
# ‘v’ (not case sensitive). 
# Recall that an anagram is the rearrangement of a word’s letters to make a new word e.g., 
# parental => paternal. 
# An anagram must use all the letters of the original word (i.e., be of the same length).
# You can find on edveNTUre in lab resources a file word_list.txt.
# This file contains 230,000 English words which you can use to lookup anagrams.
#
# Have your program generate all anagrams (beginning with the letter ‘v’) for the following 14 words:
# serve, rival, lovely, caveat, devote, irving, livery, selves, 
# latvian, saviour, observe, octavian, dovetail, levantine

import sys

dict1 = {'serve': [], 'rival': [], 'lovely': [], 'caveat': [], 'devote': [], 'irving': [], 'livery': [], 'selves': [],
    'latvian': [], 'saviour': [], 'observe': [], 'octavian': [], 'dovetail': [], 'levantine': []}

#OR

'''list1 = ['serve', 'rival', 'lovely', 'caveat', 'devote', 'irving', 'livery', 'selves',
    'latvian', 'saviour', 'observe', 'octavian', 'dovetail', 'levantine']

dict1 = {}

for items in list1:
    dict1[items] = []'''

with open("word_list.txt") as myFile:
    for word in myFile:
        #Wait until 'v' then compare
        if word[0].lower() != 'v':
            continue
        #Prevent wasting of time and resources
        elif word[0].lower() == 'w':
            break

        #Remove '\n' from list as using pop after loading everything reduces code efficiency
        wordlist = list(word[:-1].lower())
        wordlist.sort()

        for key in dict1:
            #print(key)     #debugging
            keylist = list(key)
            keylist.sort()
            
            #print(keylist, wordlist)   #debugging
            if keylist == wordlist:
                dict1[key].append(word[:-1])

print(dict1)
