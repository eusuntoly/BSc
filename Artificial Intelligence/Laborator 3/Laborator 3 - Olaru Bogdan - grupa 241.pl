%1
membru([], _) :- !, fail.
membru([X], E) :- E =:= X; !, fail.
membru([H|T], E) :- E =:= H; membru(T, E).

%2
poz([], _, _) :- !, fail.
poz([H|T], P, E) :- P =:= 1, E = H.
poz([H|T], P, E) :- P =\= 0, P1 is P - 1, poz(T, P1, E).

%3
sterge([], _, []):- write('pozitie mai mare decat dimensiune').
sterge([H|T], 1, T).
sterge([H|T], P, [H|T1]):- P1 is P - 1, sterge(T, P1, T1). 

%4
stergeVal([], _, []).
stergeVal([H|T], E, T1):- E =:= H, stergeVal(T, E, T1).
stergeVal([H|T], E, [H|T1]):- E =\= H, stergeVal(T, E, T1).

%5
count([], C) :- write(C).
count([H|T], C) :- C1 is C + 1	, count(T, C1).

%6
adauga([], L, L).
adauga([H|T], L, [H|T1]) :- adauga(T, L, T1).

%7
dublic([]):- !, fail.
dublic([H|T]):- membru(T, H), write('dublicate').

%9
suma([], S):- write(S).
suma([H|T], S):- H < 5, S1 is S + H, suma(T, S1).

%10
mar(mar).
port(portocala).
numara([], M, P):- M is 0, P is 0.
numara([H|T], Mere, Portocale) :- mar(H), numara(T, M, Portocale), Mere is M + 1. 
numara([H|T], Mere, Portocale) :- port(H), numara(T, Mere, P), Portocale is P + 1. 