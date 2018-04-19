arb1(t(5, t(2, t(1,n,n), t(3,n,n)), t(6, n, t(7,n,n)))).
arb2(t(20, t(15, n, t(17, n, n)), t(40, t(35, n, n), t(41, n, n)))).

%1
afisPre :- arb1(T), afisPre(T).
afisPre(t(R, n, n)) :- write(R).
afisPre(n).
afisPre(t(R, S, D)) :- write(R), afisPre(S), afisPre(D).

afisIn :- arb1(T), afisIn(T).
afisIn(t(R, n, n)) :- write(R).
afisIn(n).
afisIn(t(R, S, D)) :- afisIn(S), write(R), afisIn(D).

afisPost :- arb1(T), afisPost(T).
afisPost(t(R, n, n)) :- write(R).
afisPost(n).
afisPost(t(R, S, D)) :- afisPost(S), afisPost(D), write(R).

%2
nrFrunze :- arb1(T), afisPost(T).
nrFrunze(t(R, n, n), 1) :- !.
nrFrunze(n, 0) :- !.
nrFrunze(t(R, S, D), N) :- afisPost(S, N1), afisPost(D, N2), N is N1 + N2, !.

%toate nodurile fara frunze
nrFrunze :- arb1(T), afisPost(T).
nrFrunze(t(R, n, n), 0), !.
nrFrunze(n, 0), !.
nrFrunze(t(R, S, D), N) :- afisPost(S, N1), afisPost(D, N2), N is N1 + N2 + 1, !.

%3
nrNodVal(P, N) :- arb1(T), nrNodVal(T, P, N).
nrNodVal(n, _, 0).
nrNodVal(t(R, S, D), P, N) :- nrNodVal(S, P, N1), nrNodVal(D, P, N2), (R > P, N is N1 + N2 + 1; N is N1 + N2).

%4
minMax(Min, Max) :- arb1(T), minMax(T, Min, Max).
minMax(n, 99, -99) :- !.
minMax(t(R, n, n), R, R) :- !.
minMax(t(R, S, D), Min, Max) :- minMax(S, Min1, Max1),
                                minMax(D, Min2, Max2),
					            M is min(Min1, Min2),
						        Min is min(M, R),
						        Ma is max(Max1, Max2),
						        Max is max(Ma, R), !.


%5
media(M) :- arb2(T), srch(T, S, Nr), M is S / Nr.
srch((t, n, n), 0, 0):- !.
srch(n, 0, 0) :- !.
srch(t(R, S, D), Sum, Nr) :- srch(S, S1, N1), srch(D, S2, N2), Sum is S1 + S2 + R, Nr is N1 + N2 + 1.

%6
sumN(N, S) :- arb1(T), sumN(T, N, S).
sumN(n, _, 0).
sumN(t(R, _, _), 1, R).
sumN(t(R, S, D), N, Sum) :-  N1 is N - 1, sumN(S, N1, Sum1), sumN(D, N1, Sum2), Sum is Sum1 + Sum2.

%7
formeaza(L, T) :- form(L, n, T).
form([], T, T).
form([H|T], Ti, Tf) :- add(H, Ti, Ti1), form(T, Ti1, Tf).
add(E, n, t(E, n, n)).
add(E, t(R, S, D), Tree) :- (E > R, add(E, D, D1), Tree = t(R, S, D1)); (add(E, S, S1), Tree = t(R, S1, D)).

%8
muchii(LM) :- arb1(T), muchii(T, LM, _).
muchii(t(R, n, D), LM, R) :- muchii(D, LM1, Fiu), LM = [(R, Fiu) | LM1].
muchii(t(R, S, n), LM, R) :- muchii(S, LM1, Fiu), LM = [(R, Fiu) | LM1].
muchii(t(R, n, n), [], R).
muchii(t(R, S, D), LM, R) :- muchii(S, LM1, Fiu1), muchii(D, LM2, Fiu2), append(LM1, LM2, L), LM = [(R, Fiu1), (R, Fiu2) | L].