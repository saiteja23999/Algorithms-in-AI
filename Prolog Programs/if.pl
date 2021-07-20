% If-Else in Prolog

positive(X):- X>0.
negative(X):- X<0.
zero(X):- X=:=0.

num(X,Sign) :- positive(X) -> Sign = positive ;
               negative(X) -> Sign = negative ;
               zero(X)-> Sign = zero. 