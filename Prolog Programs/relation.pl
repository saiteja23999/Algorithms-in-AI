

male(bob).
female(alice).
male(jim).
female(jane).

married(jane,jim).
married(bob,alice).
married(john,mary).

married(X,Y):-married(Y,X).
husband(X,Y):- married(X,Y),male(X),female(Y).
wife(X,Y):- married(X,Y),male(Y),female(X).


