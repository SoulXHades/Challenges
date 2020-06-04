company(sumsum).
company(appy).
competitor(sumsum,appy).
technology(galactica_s3).
developed(sumsum,galactica_s3).
boss(stevey).
business(X) :- technology(X).
rival(X) :- competitor(X,appy).
steal(stevey,galactica_s3,sumsum).
unethical(X) :- boss(X), business(Y), company(Z), rival(Z), steal(X,Y,Z).