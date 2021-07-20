
boy(john).
boy(rick).
boy(harry).
boy(peter).
boy(tom).
boy(bob).

girl(alice).
girl(jane).
girl(martha).
girl(mary).


girl(X).

girl(X):- boy(X),!,fail.

%boy(X):- girl(X),!,fail.