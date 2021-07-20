

male(harry).
male(tom).
male(bob).
male(john).
male(richard).
female(mary).
female(alice).
female(jane).
female(sonia).
female(maria).

parent(john,bob).
parent(bob,tom).
brother(john,richard).
sister(jane,tom).
sister(sonia,maria).


grandparent(X,Y):- parent(X,Z),parent(Z,Y).
grandparent(john,tom).


husband(X,Y):-wife(Y,X).


parent(X,Y):-child(Y,X).

