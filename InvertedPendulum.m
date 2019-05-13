
%% CONSTANTEN
Rm = 2.6;
Km = 0.00767;
Kb = 0.00767;
Kg = 3.7;
Mc = 0.455;
l= 0.302;
m = 0.210;
r = 0.00635;
g= 9.81;
 
%% STATE model 
A = [0 0 1 0; 0 0 0 1; 0 -m*g/Mc -Kg^2*Km*Kb/(Mc*Rm*r^2) 0; 0 (Mc+m)*g/(Mc*l) Kg^2*Km*Kb/(Mc*Rm*r^2*l) 0];
B = [0; 0; Km*Kg/(Mc*Rm*r); -Km*Kg/(r*Rm*Mc*l)];
C = eye(4,4);
D = zeros(4,1);
system = ss(A,B,C,D);
Q = [0.15 0 0 0; 0 4 0 0; 0 0 0 0; 0 0 0 0]; %hier mee spelen?
R = 0.0003;
K = lqr(system,Q,R);

%ctrb
Con = ctrb(system);
RankConrollability=rank(Con) 
con
%observability
Ob = obsv(system);
RankObservability=rank(Ob)%rank 4 => not full rank => not observable
Ob
%stable
eigenvalues = eig(A) %unstable: 0 6.0049 -5.0774 -17.8110
eigenvalues_closed = eig (A-B*K)
%stabilizability

%% evaluatie controller
systeem = ss(A-B*K,B,C,D); %aanpassen van A en B
pzmap(systeem);
figure;
impulse(systeem);




