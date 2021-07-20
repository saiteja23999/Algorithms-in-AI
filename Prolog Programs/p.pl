
male(ram).
male(tom).
male(bob).
male(harry).
male(john).

female(sita).
female(mary).
female(alice).
female(jane).
female(jinia).

man(X):-male(X).
woman(X):-male(X),fail.
woman(X):-female(X).









test:- repeat, write('enter a no :'),read(X),write(X),nl,(X=:=10).















