%---------------------------------------------------------------

f(X,0):- X<3.

f(X,2):- 3=<X, X<6.

f(X,4):- 6=<X.

%---------------------------------------------------------------

square :- write(' Please enter a no. Write stop to end : '),
         read(N),
         process(N).


process(stop):-!.

process(N):- C is N*N,
             write(' Square of '), write(N), write(' is '),
             write(C), nl,
             square.

%---------------------------------------------------------------

cpu(8085).
cpu(intel).
cpu(athlon).

memory(zeon).
memory(sandisk).

peripheral(io).
peripheral(hdd).
peripheral(nic).


computer(C,X,Y,Z):- cpu(X),!, memory(Y), peripheral(Z).

%---------------------------------------------------------------

%different(X,Y):- X =\= Y.

different(X,Y):- not(X =:= Y).

%---------------------------------------------------------------