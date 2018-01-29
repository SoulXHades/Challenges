#Consider  a  system  for  storing  anonymous  grades  of  each  lab  class. 
#Define  a  data structure,  
#which can  identify  individuals  in  each  lab  group by a number between 1 - 40 (inclusive). 
#To identify the person in the entire class you would also need the group name, e,g., ‘FE2’. 
#Each corresponding  person  should  have  a  number  between  1 - 100 (inclusive) to define grade.


import sys

FE1Grade = [50, 40, 31]

classes = {'FE1': FE1Grade}

print(classes['FE1'][1])