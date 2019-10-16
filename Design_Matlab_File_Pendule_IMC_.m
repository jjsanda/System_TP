%% Design of Observer-Controller Control Law for Rotary Inverted Pendulum 
%% Goals
% * Study the inverted pendulum modelling and obtain its linear state
% space model.
% * Stabilization of inverted pendulum in the upper vertical position ($$ \ alpha = 0 $$) following the
% specifications given in the related topic.
% * Obtain the discrete observer-controller in state space form respecting
% the name of matrix parameters declared in the dSPACE/Simulink file
% Observateur_Controleur_Dspace_IMC.
% * Implementation of the control laws in dSPACE and test it on the *real
% inverted pendulum*.
%
%% Given Matlab/Simulink files and work to be done
% *  *Modele_Pendule.m*: State space model of opened loop inverted pendulum 
% based on the data provided by the constructor.
% * *Observateur_Controleur_Dspace_IMC.slx*: Observer-Controller discrete model used to generate the real time controller code. 
% * *Contruct the inverted pendulum* open loop state space model in Simulink and
% analyse its *stability, reachability and observability*.
% * *Design a continuous* observer-controller  capable to stabilize the inverted pendulum  in its upright position. 
% Realize the Simulink control scheme based on the figure given in the related topic and  give it the name
% *Pendule_Observateur_Controleur_Continu.slx* and conduct the necessary tests.
% * *Design a discrete* observer-controller  capable to stabilize the inverted pendulum  in its upright position. 
% Realize the Simulink control scheme based on the figure given in the related topic and  give it the name
% *Pendule_Observateur_Controleur_Discret.slx* and conduct the necessary tests.


clear all,
clc;clf;

%% Model of Ratary Inverted Pendulum
%%
%
% << Pendule_Rotatif.png >>
%
Modele_Pendule

%% Specifications
% The pendulum is a fourth order system whose  closed-loop dynamic given by its 
% characteristic polynomial will be decomposed into a second order polynomial 
% followed by two first-order polynomials 
% ($$ P_c(p)=(p^2 + 2\zeta \omega_0 p + \omega_0^2)(p+p_3)(p+p_4) $$).
% Specifying the $$ 5\% $$ response time and 
% the damping ratio $$ \zeta $$ we can determine $$ \omega_0 $$ 
% and thus calculate the  closed loop dominant poles of inverted pendulum 
% ($$ -\omega_0 \zeta  \pm j\omega_0 \sqrt{1-\zeta^2} $$). 
% The other two poles should be selected stable and sufficient fast compared 
% to dominant poles and consistent w.r.t actuators capacities and 
% pendulum structure.

z=1 ;                                                                      % damping ration zeta
Tr=0.75 ;                                                                  % The 5% response time
w0_Tr=4.5;                                                                 % oTr=4 
w0=w0_Tr/Tr;                                                               % feedback natural frequency 
p1=-z*w0;                                                                  % 1st dominant pole 
p2=-z*w0+0.001;                                                            % 2nd different with the first one otherwise problems with Matlab command place()
p3=-6.1*z*w0;                                                              % third pole which faster then the two previous ones
p4=-6.2*z*w0;                                                              % fourth  pole which faster then the two previous ones
Pc=[p1 p2 p3 p4];  

Po=3*Pc;                                                                   % The observer pole choice more rapid then the controller ones

cas='continue';

switch cas  
    
%% Design of the observer-controller control law for the continuous case.
% * Calculate the feedback gains supposing that *the pendulum state is
% measurable*.
% * Calculate the feedback observer gains *supposing that we mesure only the
% angles thetat and alpha* and using the dual linear model $$ \{A^T,B^T,C^T,D^T \}
% $$.
% * Construct the Simulink scheme and operate the necessary simulations in
% order to verify the stability and the defined performances of the feedbacked inverted
% pendulum.
% * Give the most significant results and illustrate your conclusions
%
%%
 %
 % <<Pendule_Observateur_Controleur_Continu.png>>
 %
case 'continue'
    X0=[0.3 0 0 0]';
    X0_o=[0 0 0 0]';
    Kc=place (A,B,Pc);
    Ko=place (A',C',Po);
    Ko=Ko';
    Ao=A-Ko*C;
    Bo=[B Ko];
    Co=eye(4,4);
    Do=zeros(4,3);
%% Design of the observer-controller control law for the discrete case.
% * Calculate the feedback gains supposing that *the pendulum state is
% measurable*.
% * Calculate the feedback observer gains *supposing that we mesure only the
% angles thetat an alpha* and using the dual linear model $$ \{A_d^T,B_d^T,C_d^T,D_d^T \}
% $$.
% * Construct the Simulink scheme and operate the necessary simulations in
% order to verify the stability and the defined performances of the feedbacked inverted
% pendulum.
% * Give the most significant results and illustrate your conclusions
%

   %%
    %
    % <<Pendule_Observateur_Controleur_Discret.png>>
    %
    case 'discret'
    
    T_ech=0.005;
    X0=[0.3 0 0 0]';
    X0_o=[0 0 0 0]';
    [Ad,Bd]=c2d(A,B,T_ech)
    Cd=C;Dd=D;
    Pcd=exp(Pc*T_ech);
    Pod=exp(Po*T_ech);
    Kcd=place(Ad,Bd,Pcd);
    Kod=place(Ad',Cd',Pod);
    Kod=Kod';
    Aod=Ad-Kod*Cd;
    Bod=[Bd Kod];
    Cod=eye(4,4);
    Dod=zeros(4,3);

end
%Observateur_Controleur_Dspace_IMC;