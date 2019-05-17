%clear;


%% CONSTANTEN
Rm = 2.6;
Km = 0.00767;
Kb = 0.00767;
Kg = 3.7;
Mc = 0.455;
l= 0.305;
m = 0.210;
r = 0.00635;
g= 9.81;
 
%% STATE model 
A = [0 0 1 0; 0 0 0 1; 0 -m*g/Mc -Kg^2*Km*Kb/(Mc*Rm*r^2) 0; 0 (Mc+m)*g/(Mc*l) Kg^2*Km*Kb/(Mc*Rm*r^2*l) 0];
B = [0; 0; Km*Kg/(Mc*Rm*r); -Km*Kg/(r*Rm*Mc*l)];
C = eye(4,4);
D = zeros(4,1);
system_open = ss(A,B,C,D);
Q= zeros(4,4); %We play with this
Q(1,1)= 0.25;
Q(2,2)= 4;
Q(3,3)= 0;
Q(4,4)= 0;
Q = [0.25 0 0 0; 0 4 0 0; 0 0 0 0; 0 0 0 0]; 
R = 0.03;
K = lqr(system_open,Q,R);

%ctrb
Con = ctrb(system_open);
RankControllability=rank(Con) 
Con
%observability
Ob = obsv(system_open);
RankObservability=rank(Ob)%rank 4 => not full rank => not observable
Ob
%stable
eigenvalues = eig(A) %unstable: 0 6.0049 -5.0774 -17.8110
eigenvalues_closed = eig (A-B*K);
%stabilizability

%% Deel 2: Closed-loop with LQR control.

A_closed=A-B*K
intial_State= [0;0;0;0];
reference_State = [0.2;0;0;0];
system_Closed_First = ss(A_closed,B,C,D); %aanpassen van A en B
%pzmap(system_Closed_First);
%impulse(system_Closed_First);

%% Deel 3: Closed-loop more realistic simulation

%The output of the linear model are now the variables that are measured in
%the real setup (x and alpha). Therefore we now have to compute the
%derivatives of the measured outputs by using the backward difference
%equation and the low pass filer. These are implemented in Simulink.
%Filtered values are used within the backward differential formula. 

T_s = 1/200; %
Ts = 1/200; 

%Determine cut-off frequency: the higher this value, the more noise is
%allowed to play. If it is chose too low (0.02*2*pi; we are deleting are
%own useful signal)
Omega_c = 20*2*pi; 

% TODO: find a way to talk about noise. 

V_max=5;%Voltage limit set by controller
%Kwantisering om van continu naar discreet te gaan, gebaseerd op voltage
%output met 16 bits
Q_interval = (2*V_max)/(2^16);

%Alternatieve K berekenen om studie te maken van andere Q en R
%mogelijkheden voor deze 2e closed loop
Q_alternative= zeros(4,4); %We play with this
Q_alternative(1,1)= 0.25;
Q_alternative(2,2)= 4;
Q_alternative(3,3)= 0;
Q_alternative(4,4)= 0;
R_alternative = 0.003; %Als R te klein is (0.0003), wordt het systeem instabiel door de saturator afknipping
K_alternative = lqr(system_open,Q_alternative,R_alternative);


%% Making plots

figure();
plot(Datatest);
























