bradut(N) :- br(N, N, 1).
br(N, S, N) :- Stelute is N * 2 - 1, afisStelute(Stelute).
br(N, S, 1) :- afisSpatii(S), write('*'), nl, br(N, N, 2).
br(N1, S, L) :- afisSpatii(S), write('*'), Egaluri is 2 * L - 3, afisEgaluri(Egaluri), write('*'), nl, Ln is L + 1, br(N1, Sp, Ln).
afisEgaluri(1) :- write('=').
afisEgaluri(X) :- X > 1, X < write('='), X1 is X - 1, afisEgaluri(X1).
afisStelute(1) :- write('*').
afisStelute(X) :- X > 1, X < write('*'), X1 is X - 1, afisStelute(X1).
afisSpatii(0).
afisSpatii(X) :- X > 0, write(' '), X1 is X - 1, afisSpatii(X1).