%% START mutare blocuri
% ----------------------------------------
% Cautare de tip breadth-first
% ----------------------------------------
rezolva_b(NodInitial,Solutie):- breadthfirst([[NodInitial]],Solutie).
breadthfirst([[Nod|Drum]|_],[Nod|Drum]):-scop(Nod).
breadthfirst([Drum|Drumuri],Solutie):- extinde(Drum,DrumNoi),
append(Drumuri,DrumNoi,Drumuri1),
breadthfirst(Drumuri1,Solutie).
extinde([Nod|Drum],DrumNoi):-
bagof([NodNou,Nod|Drum],(s(Nod,NodNou),
\+ (member(NodNou,[Nod|Drum]))), DrumNoi),!.
extinde(_,[]).
% ----------------------------------------
%Cautare de tip depth-first cu mecanism de detectare a ciclurilor
% ----------------------------------------
rezolva(Nod,Solutie):-depthfirst([],Nod,Solutie).
depthfirst(Drum, Nod,[Nod|Drum]):-scop(Nod).
depthfirst(Drum,Nod,Solution):- s(Nod,Nod1),\+ (member(Nod1,Drum)),
depthfirst([Nod|Drum],Nod1,Solution).
% ----------------------------------------
%Cautare de tip iterative deepening
% ----------------------------------------
cale(Nod,Nod,[Nod]).
cale(PrimNod,UltimNod,[UltimNod|Drum]):- cale(PrimNod,PenultimNod,Drum),
s(PenultimNod,UltimNod),
\+(member(UltimNod,Drum)).
depth_first_iterative_deepening(Nod,Solutie):- cale(Nod,NodScop,Solutie),
scop(NodScop),!.
% ----------------------------------------
%Predicatele specifice problemei mutarii blocurilor
% ----------------------------------------
det_poz_el([Element|T], 1, Element).
det_poz_el([H|T], Poz, Element) :- det_poz_el(T, Poz1, Element), Poz is Poz1 + 1.

sterg_la_n([H|T], Lista_inter, 1) :- H = [H1|T1], Lista_inter = [T1|T].
sterg_la_n([H|T], [H|Lista], N) :- N1 is N  - 1, sterg_la_n(T, Lista, N1).

adaug_la_n(V, [H|T], Lista, 1) :- H1 = [V|H], Lista = [H1|T].
adaug_la_n(V, [H|T], [H|L], N) :- N1 is N - 1, adaug_la_n(V, T, L, N1).

dim([], 0).
dim([H|T], D) :- dim(T, D1), length(H, D2), D is max(D1, D2).
egal(0) :- nl.
egal(N) :- write('='), N1 is N - 1, egal(N1).
afisare([]).
afisare([H|T]) :- afis(H), length(H, N), egal(N), nl, afisare(T).
afis(L) :- dim(L, 0).
afis(L) :- dim(L, D), afis2(L, D, L1), nl, afis(L1).
afis2([], _, []).
afis2([H|T], N, [T1|L2]) :- length(H, N), H = [Vf|T1], write(Vf), afis2(T, N, L2).
afis2([H|T], N, [H|L2]) :- write(' '), afis2(T, N, L2).

s(Lista_stive, Lista_stive_rez):-
    member(X, Lista_stive), X = [Varf|_],
    det_poz_el(Lista_stive, N, X),
    sterg_la_n(Lista_stive, Lista_stive_inter, N),
    member(Y, Lista_stive),
    det_poz_el(Lista_stive, N1, Y), N1 \== N,
    adaug_la_n(Varf, Lista_stive_inter, Lista_stive_rez, N1).
% configuratia initiala a stivelor.
initial([[d],[a,b],[c]]).
% configuratia-scop a stivelor, cea pe care o cauta fiecare dintre algoritmii de cautare folositi.
scop([[],[a,b,c,d],[]]).
% Mai jos se gasesc trei posibilitati de apel pentru problema mutarii blocurilor. Alegeti cate una, in
% functie de ce algoritm doriti sa folositi
% Inlocuiti calea de mai jos cu una catre directorul in care lucrati voi
pb_bf:-initial(S),rezolva_b(S,Solutie), afisare(Solutie).
pb_df:-initial(S),rezolva(S,Solutie), afisare(Solutie).
pb_df_id:-initial(S), depth_first_iterative_deepening(S,Solutie), afisare(Solutie).
% ----------------------------------------
%% END mutare blocuri
% ----------------------------------------