%% Modélisation du Pendule
% * Entrée: paramètres du moteur et du pendule
% * Sortie: Modèle d'état du pendule $$ \dot{x}(t)=Ax(t)+Bu(t) \wedge
% y(t)=Cx(t)+Du(t) $$

clear all
 
Rm = 2.6;                                                                  % Motor rotor resitance
Kt = .00767;                                                               % Motor Torque Constant (N.m/A)
Km = .00767;                                                              % Motor Back-EMF Constant (V.s/rd)
g=  9.81;                                                                    % Internal Gear Ratio (of the Planetary Gearbox)           
L = 0.335 / 2;                                                             % Length of Pendulum centre of mass (meters) 
m = 0.125;                                                                 % Mass of Pendulum (kg)
r = 0.158;                                                                 % Arm length in (m)
Jm = 3.9e-7;
Jtach = 7e-8;
Jmotor = Jm + Jtach;                                                       % Motor moment of inertia
%%  Moment d'inertie du système de transmission (engrenages) (kg.m^) 
% * J72: 72-tooth Gear Inertia (on the Potentiometer 
% * J120: 120-tooth Gear Inertia (on the Load Shaft) 
% * Linearized Inverted pendulum parameters

                                                                           %J24: 24-tooth Gear Inertia (on the Motor Shaft)
m24 = .005;                                                                % mass (kg)
r24 = 0.5 / 2 * 0.0254;                                                    % radius (m)
J24 = m24 * r24^2 / 2;
                                                                           %J72: 72-tooth Gear Inertia (on the Potentiometer Shaft)
m72 = .030;                                                                % mass (kg)
r72 = 1.5 / 2 * 0.0254;                                                    % radius (m)
J72 = m72 * r72^2 / 2;
                                                                           % J120: 120-tooth Gear Inertia (on the Load Shaft)
m120 = .083; % mass (kg)
r120 = 2.5 / 2 * 0.0254; % radius (m)
J120 = m120 * r120^2 / 2;
Kgi = 14;
Beq = 4e-3;
Kge = 5;
Kg = Kgi * Kge;
Jeq = J24 + 2 * J72 + J120 + Kg^2 * Jmotor;                                 % Equivalent motor inertia moment


                                                                           % Linearized Inverted pendulum parameters

a = Jeq + m*r^2;
b = m*r*L;
c = 4/3 * m*L^2;
d = m*g*L;

E = a*c - b^2;

P = Kt*Kg;
G = (P*Km*Kg + Beq*Rm) / Rm;

%% Initialisation des matrices du modèle d'état (A,B,C,D)
% * Source et explication: sujet du TP

A = zeros (4,4);
B = zeros (4,1);
C = zeros (2,4);
D = zeros (4,1);

A(1,3) = 1;
A(2,4) = 1;
A(3,2) = b*d / E;
A(3,3) = -G*c / E;
A(4,2) = a*d / E;
A(4,3) = -G*b / E;

B(3,1) = c*P / (E*Rm);
B(4,1) = b*P / (E*Rm);

C=[1 0 0 0;
   0 1 0 0];
D=[ 0 0 ]';
