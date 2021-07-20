


mem(X,[X|T]).
mem(X,[H|T]) :- mem(X,T).


takeout(X,[X|R],R).
takeout(X,[F|R],[F|S]):-takeout(X,R,S).

max([H|T],A,Max):- H > A, max(T,H,Max).

max([H|T],A,Max):- H =< A, max(T,A,Max).

max([],[]).


