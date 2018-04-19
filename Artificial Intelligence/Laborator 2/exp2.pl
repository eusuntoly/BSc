getX('X1').
getZ('Z1').
getX('X2').
getZ('Z2').
wr:-getX(X), getZ(Z), wrXZ(X, Z), fail.
wrXZ(X, Z):-write(X), write(' '), write(Z), write(' '), nl, fail.