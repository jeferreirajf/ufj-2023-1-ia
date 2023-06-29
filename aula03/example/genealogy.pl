parent(ferreira,arthur).
parent(raissa,arthur).
parent(jose,ferreira).
parent(gilda,ferreira).
parent(moacir,raissa).
parent(regina,raissa).
parent(jose,juliana).
parent(gilda,juliana).
parent(regina,kaue).
parent(moacir,kaue).
parent(regina,inaie).
parent(moacir,inaie).
parent(juliana,mateus).
parent(gubio,mateus).
parent(borges,jose).
parent(ana,jose).
parent(geraldo,gilda).
parent(marta,gilda).

brother(P1,P2) :- 
	parent(X,P1),
    parent(X,P2).

cousin(P1,P2) :-
    parent(X,P1),
    parent(Y,P2),
    brother(X,Y).

uncle(P1,P2) :-
    parent(X,P2),
    brother(X,P1).

grandfather(P1,P2) :-
    parent(P1,X),
    parent(X,P2).