female(queenElizabeth).
female(princessAnn).
male(princeCharles).
male(princeAndrew).
male(princeEdward).

parentOf(queenElizabeth, princeCharles).
parentOf(queenElizabeth, princessAnn).
parentOf(queenElizabeth, princeAndrew).
parentOf(queenElizabeth, princeEdward).

olderThan(queenElizabeth, princeCharles).
olderThan(princeCharles, princessAnn).
olderThan(princessAnn, princeAndrew).
olderThan(princeAndrew, princeEdward).


% iteration of the olderThan() cause never permutate all the olderThan() possibilities so need check if example princeCharles is older than princeEdward
isOlder(X, Y) :- olderThan(X, Y).
isOlder(X, Y) :- olderThan(X, Z), isOlder(Z, Y).

% condition to rank succession
inOrder(X, Y) :- isOlder(X, Y).

% sort in succession order based on age due to the new rule
insertionSort(List, Sorted) :- i_sort(List, [], Sorted).
i_sort([], Acc, Acc).
i_sort([H|T], Acc, Sorted) :- insert(H, Acc, NAcc), i_sort(T, NAcc, Sorted).
   
insert(X, [Y|T], [Y|NT]) :- inOrder(Y, X), insert(X, T, NT).
insert(X, [Y|T],[X, Y|T]) :- inOrder(X, Y).
insert(X, [], [X]).

% get a list of children usng findall() then use insertion sort to sort them in succession order
succession(ListOfSuccession) :- findall(Y, parentOf(queenElizabeth, Y), ListOfChildren), insertionSort(ListOfChildren, ListOfSuccession).