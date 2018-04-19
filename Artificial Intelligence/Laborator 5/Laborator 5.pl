mat([[1, 2, 3], [4, 5, 6], [7, 8, 9]]).

%1
linie(I) :- mat(M), linie(M, I).
linie([], _).
linie([H|_], 1) :- write(H).
linie([_|T], I) :- I1 is I - 1, linie(T, I1).

%2
coloana(J) :- mat(M), coloana(M, J).
coloana([], _).
coloana([H|T], J) :- linie(H, J), coloana(T, J).

%3
subdiag :- mat(M), subdiag(M, 0).
subdiag([], _).
subdiag([H|T], Nr) :- afisare(H, Nr), nl, Nr1 is Nr + 1, subdiag(T, Nr1).
afisare(_, 0).
afisare([H|T], Nr) :- write(H), Nr1 is Nr - 1, afisare(t, Nr1).

%4
mat1([[1, 0, 1], [0, 1, 0], [1, 0, 1]]).
zu :- mat1(M), M = [H|T], length(H, Len), zu(M, 1, 1, Len).
zu([], _, _, _).
zu([H|T], I, J, Len) :- I1 is I + 1, verifica(H, I, J, Len), zu(T, I1, J, Len).
verifica([], _, _, _).
verifica([H|T], I, J, Len) :- I == J, H == 1, J1 is J + 1, verifica(T, I, J1, Len).
verifica([H|T], I, J, Len) :- I + J =:= Len + 1, H == 1, J1 is J + 1, verifica(T, I, J1, len).
verifica([0|T], I, J, Len) :- J1 is J + 1, verifica(T, I, J1, Len).

%5
sublists(L, LP) :- setof(C, E^member(E/C, L), LC), sublists(LC, L, LP).
sublists([], _, []).
sublists([C|T], L, [LC1, LC2]) :- extrage(L, C, LC1), sublists(T, L, LC2).
extrage([], _, []).
extrage([E/C|T], C, [E|T1]) :- extrage(T, C, T1).
extrage([_/C1|T], C, T1) :- C1 \== C, extrage(T, C, T1).

%6
trans(M, MT) :- mat(M), M = [H, T], length(H, Len), trans(M, 1, Len, MT).
trans(_, C, Len, []) :- Len =:= C - 1.
trans(M, C, Len, [LC|TC]) :- coloane(M, C, LC), C1 is C + 1, trans(M, C1, Len, TC).
coloane([], _, []).
coloane([H|_], C, [E|T1]) :- linie(H, C, E), coloane(T, C, T1).
linie([H|_], 1, H).
linie([H|T], C, E) :- C1 is C - 1, line(T, C1, E).

%7
sub(M, C, LI, LF, CI, CF) :- C < LI, C1 is C + 1, M = [H|T], sub(T, C1, LI, LF, CI, CF).
sub(M, C, LI, LF, CI, CF) :- LI =< C, C =< LF, M = [H|T], afisare(H, CI, CF, 1), nl, C1 is C + 1, sub(T, C1, LI, LF, CI, CF).
sub(_, C, _, LF, _, _) :- LF =:= C - 1.
afisare([H|T], CI, CF, P) :- LI < CI, P1 is P + 1, afisare(T, CI, CF, P1).
afisare(_, CI, CF, P) :- LI > CF, !.
afisare([H|T], CI, CF, P) :- write(H), P1 is P + 1, afisare(T, CI, CF, P1).
