bradut(N) :- br(N, N).
br(N, 1) :- afisStelute(N).
br(N1, N2) :- N3 is N2 - 1, afisSpatii(N3), CateStelute is N1 - N3, afisStelute(CateStelute), nl, br(N1, N3).
afisStelute(0).
afisStelute(X) :- X > 0, write('* '), X1 is X - 1, afisStelute(X1).
afisSpatii(0).
afisSpatii(X) :- X > 0, write(' '), X1 is X - 1, afisSpatii(X1).