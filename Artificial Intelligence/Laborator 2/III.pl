cifre(X) :- X == 0, write('(zero, 0)').
cifre(X) :- X == 1, write('(unu, 1)').
cifre(X) :- X == 2, write('(doi, 2)').
cifre(X) :- X == 3, write('(trei, 3)').
cifre(X) :- X == 4, write('(patru, 4)').
cifre(X) :- X == 5, write('(cinci, 5)').
cifre(X) :- X == 6, write('(sase, 6)').
cifre(X) :- X == 7, write('(sapte, 7)').
cifre(X) :- X == 8, write('(opt, 8)').
cifre(X) :- X == 9, write('(noua, 9)').
extrage(X) :- X > 0, A is X mod 10, B is X // 10, extrage(B), cifre(A); true.