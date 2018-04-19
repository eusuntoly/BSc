% Clauze/Fapte:
parinte(ion,maria).
parinte(ana,maria).
parinte(ana,dan).
parinte(maria,elena).
parinte(maria,radu).
parinte(elena,nicu).
parinte(andrei,gabriela).
parinte(radu,gigi).
parinte(radu,dragos).
parinte(ion,andrei).
% Reguli:
bunic(ion):-parinte(ion , andrei),
parinte(andrei, gabriela).
% Acestea sunt comentarii:
% “Daca ( :- ) Ion este parintele lui Andrei si ( , ) Andrei
% este parintele Gabrielei, atunci Ion este bunic”.

% Exercitiul 2

femeie(maria).
femeie(ana).
femeie(elena).
femeie(gabriela).
barbat(ion).
barbat(dan).
barbat(nicu).
barbat(radu).
barbat(dragos).
barbat(gigi).
barbat(andrei).
sora(X, Y):-femeie(X), barbat(Y), X\=Y, parinte(C, X), parinte(C,Y).

%Exercitiul 3

casatorit(ana, vasile).
casatorit(claudia, alexandru).
casatorit(sergiu, ioana).
casatorit(gheorghe, andrada).
casatorit(florin, alina).
casatorit(andrei, sorana).
verif_casatorit(X, Y):- casatorit(X, Y) ; casatorit(Y, x).
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
barbat(vasile).
barbat(alexandru).
barbat(sergiu).
barbat(gheorghe).
barbat(florin).
barbat(andrei).
frate(X, Y):- barbat(X), copil(X, P), copil(Y, P), X \= y.
sora(X, Y):- femeie(Y), copil(x, P), copil(Y, P), x \= Y.
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