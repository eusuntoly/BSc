afis([]).
afis([H|T]):- write(H), nl, afis(T).
add(L, X, [X|L]).
add1(L, X, [L|X]).
add2([], E, [E]).
add2([H|T], E, [H|T1]):- add2(T, E, T1).
