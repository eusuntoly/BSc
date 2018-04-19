%Exercitiul 3

casatorit(ana, vasile).
casatorit(claudia, alexandru).
casatorit(sergiu, ioana).
casatorit(gheorghe, andrada).
casatorit(florin, alina).
casatorit(andrei, sorana).
verif_casatorit(X, Y):- casatorit(X, Y) ; casatorit(Y, X).
copil(dan, ana).
copil(dan, vasile).
copil(ioana, ana).
copil(ioana, vasile).
copil(gheorghe, vasile).
copil(gheorghe, ana).
copil(andrada, alexandru).
copil(andrada, claudia).
copil(alina, sergiu).
copil(alina, ioana).
copil(alin, sergiu).
copil(alin, ioana).
copil(claudiu, gheorghe).
copil(claudiu, andrada).
copil(andrei, gheorghe).
copil(andrei, andrada).
copil(bogdan, andrei).
copil(bogdan, sorana).
copil(georgiana, florin).
copil(georgiana, alina).
femeie(ana).
femeie(claudia).
femeie(ioana).
femeie(andrada).
femeie(alina).
femeie(sorana).
femeie(georgiana).
barbat(vasile).
barbat(alexandru).
barbat(sergiu).
barbat(gheorghe).
barbat(florin).
barbat(andrei).
barbat(dan).
barbat(alin).
barbat(claudiu).
barbat(bogdan).
frate(X, Y):- barbat(X), copil(X, P), copil(Y, P), X \= Y.
sora(X, Y):- femeie(Y), copil(X, P), copil(Y, P), X \= Y.
frati(X, Y):- frate(X, Y); sora(X, Y).
verisor(X, Y):- barbat(X), copil(X, P1), copil(Y, P2), frati(P1, P2).
verisoara(X, Y):- femeie(X), copil(X, P1), copil(Y, P2), frati(P1, P2).
unchi(X, Y):- barbat(X), copil(Y, P), frati(X, P).
matusa(X, Y):- femeie(X), copil(Y, P), frati(X, P).
cumnat(X, Y):- barbat(X), ((frati(X, Z1), verif_casatoriti(Z1, Y)) ; (frati(Y, Z2), verif_casatoriti(Z2, X))).
cumnata(X, Y):- femeie(X), ((frati(X, Z1), verif_casatoriti(Z1, Y)) ; (frati(Y, Z2), verif_casatoriti(Z2, X))).
bunic(X, Y):- barbat(X), copil(Y, P), copil(P, X).
bunica(X, Y):- femeie(X), copil(Y, P), copil(P, X).
strabunic(X, Y):- barbat(X), copil(Y, P1), copil(P1, P2), copil(P2, X).
strabunica(X, Y):- femeie(X), copil(Y, P1), copil(P1, P2), copil(P2, X).