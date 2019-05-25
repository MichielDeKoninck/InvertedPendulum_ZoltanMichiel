%% CODE FOR INVERTED PENDULUM
%Zoltan d'Haese & Michiel De Koninck 

%This code contains different sections each relevant for the tasks given to
%us by the assignment. This file creates the necessary matrices and control
%parameters so that the relevant '.slx' files can be ran to test our
%designs. 
 
clear;
close all;
%% Constants
Rm = 2.6;
Km = 0.00767;
Kb = 0.00767;
Kg = 3.7;
Mc = 0.455;
l= 0.305;
m = 0.210;
r = 0.00635;
g= 9.81;
 
%% PART 1: State-space model & Open loop analysis
A = [0 0 1 0; 0 0 0 1; 0 -m*g/Mc -Kg^2*Km*Kb/(Mc*Rm*r^2) 0; 0 (Mc+m)*g/(Mc*l) Kg^2*Km*Kb/(Mc*Rm*r^2*l) 0];
B = [0; 0; Km*Kg/(Mc*Rm*r); -Km*Kg/(r*Rm*Mc*l)];
C = eye(4,4); %In fact y is only two values, but this allows easy access to all states for our first design.
D = zeros(4,1); 
% C = eye(2,4); %Actual realistic C matrix
% D = zeros(2,1); %Actual realistic D matrix
system_open = ss(A,B,C,D);

figure();
pzmap(system_open); %Not all poles are in LHP: not stable
title("Pool-zero map for open-loop system");

figure();
impulse(system_open);
title("Impulse response for open-loop system");

figure();
step(system_open);
title("Step response for open-loop system");

Openloop_stepinfo = stepinfo(system_open);

%Controlability
Con = ctrb(system_open);
RankControllability=rank(Con); 
amount_of_uncontrollable_states = length(A)-rank(Con); %-> Is zero: no uncontrollable states
%Observability
Ob = obsv(system_open);
RankObservability=rank(Ob);%rank 4 -> Full rank -> Observable system
amount_of_unobservable_states = length(A)-rank(Ob); %-> Is zero: no unobservable states

%Stability
eigenvalues = eig(A) %Unstable system because some positive eigenvalues: 0 6.0049 -5.0774 -17.8110

%% PART 2: Closed-loop with LQR control.


Q_given= zeros(4,4); %We play with this
Q= zeros(4,4);
Q_given(1,1)= 0.25;
Q(1,1)= 0.4;
Q_given(2,2)= 4;
Q(2,2)= 6;
Q_given(3,3)= 0;
Q(3,3)= 0;
Q_given(4,4)= 0;
Q(4,4)= 0;
R = 0.001;
R_given=0.003;

K= lqr(system_open,Q,R); %K using our own values
K_given = lqr(system_open,Q_given,R_given); %K using given values

A_closed=A-B*K_given;
intial_State= [0;0;0;0];
reference_State = [0.2;0;0;0]; %Reference state defined here, change if you want to test different setpoint.
system_Closed_First_given = ss(A_closed,B,C,D); %System based on given values

A_closed=A-B*K;
system_Closed_First = ss(A_closed,B,C,D); %System based on our calculated values


figure();
pzmap(system_Closed_First_given); 
title("Pool-zero map for first closed-loop system");

figure();
impulse(system_Closed_First_given);
hold on;
impulse(system_Closed_First);
title("Impulse response for first closed-loop system");
legend("Given Q and R", "Adjusted version");

figure();
step(system_Closed_First_given);
hold on;
step(system_Closed_First);
title("Step response for first closed-loop system");
legend("Given Q and R", "Adjusted version");

Closedloopfirst_stepinfo = stepinfo(system_Closed_First)
%With given Q and R: 1.5862 rise time and 2.5804 settling time
%With adjusted values: 1.3673 and 3.6032 settling time

eigenvalues_closed = eig (A-B*K);


%% PART 3: Closed-loop more realistic simulation

%The output of the linear model are now the variables that are measured in
%the real setup (x and alpha). Therefore we now have to compute the
%derivatives of the measured outputs by using the backward difference
%equation and the low pass filer. These are implemented in Simulink.
%Filtered values are used within the backward differential formula. 

T_s = 1/200; 
Ts = 1/200; 

%Determine cut-off frequency: the higher this value, the more different frequency noise is
%allowed to play. If it is chose too low (0.02*2*pi; we are deleting are
%own useful signal)
Omega_c = 2*2*pi; %25 was the eventual choice for our actual system: change if real setup is tested. 

V_max=5;%Voltage limit set by controller
Q_interval = (2*V_max)/(2^16); %Quantizing using the info that we have 16 bits to represent the 10V voltage span

%Calculate alternative K for this more realistic closed-loop
Q_alternative= zeros(4,4); %We play with this
Q_alternative(1,1)= 2;
Q_alternative(2,2)= 6;
Q_alternative(3,3)= 0.2;
Q_alternative(4,4)= 0.3;
R_alternative = 0.005; %If R is too small (0.0003), the system will be unstable due to saturation of inputvoltage.
K_alternative = lqr(system_open,Q_alternative,R_alternative);


%% PART 4: Proof of the Pudding

%New Q and R determined by trial and error for the actual setup
Q_realsetup= zeros(4,4); %We play with this
Q_realsetup(1,1)= 6;
Q_realsetup(2,2)=2.5;
Q_realsetup(3,3)= 0.03;
Q_realsetup(4,4)= 0.25;
R_realsetup = 0.04; 
K_realsetup = lqr(system_open,Q_realsetup,R_realsetup);
display(K_realsetup)

A_realsetup=A-B*K_realsetup
system_realsetup = ss(A_realsetup,B,C,D); 

figure();
pzmap(system_realsetup); %In the LHP: stable poles.

















