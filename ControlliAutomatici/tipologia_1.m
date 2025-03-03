clear all
close all
clc
s = tf('s');
F1 = 30/(s+15);
F2 = (3*s+3)/(s^3+10*s^2+24*s);
d1 = 1;
d2 = 4;
Kr = 1;
K1 = dcgain(F1);
K2 = dcgain(s*F2);

Kca = Kr/(K1*K2*0.1); %Kc minimo in modulo per soddifare la specifica a)
Kcb = d1/(K1*0.05);   %Kc minimo in modulo per soddifare la specifica b)
Kc = max(Kca, Kcb);   %valore minimo in modulo di Kc
nyquist(F1*F2);       %scelta del segno di Kc
Ga1 = Kc*F1*F2;       %funzione ad anello di partenza
wc = 13;              %wc = 12.6 ma la aumento a 13
%e) ricavo il picco di risonanza Mr tramite la formula,
%converto quel numero in dB e trovo su nichols a quale 
%valore della fase corrisponde, questo è il Margine di fase
%da Nichols a cui andrà sommata la fase che ora ricaverò da
%Bode della Ga1 alla frequenza wc
figure, margin(Ga1);    %ottengo un margine di fase minimo 
                      %di 5(Bode) + 40(Nichols)

%Rete anticipatrice
md = 10;
wtau = sqrt(md);
taud = wtau/wc;
taud = 0.25;          %valore arrotondato
Rd = (1+taud*s)/(1+taud/md*s);
Ga2 = Rd*Ga1;         %funzione di trasferimento d'anello comprendente 
                      %anche la rete anticipatrice
[ma2,fa2] = bode(Ga2,wc); %valutazione di modulo e fase alla wc desierata

%Rete attenuatrice
mi = 3.15;
wtaui = 50;
taui = wtaui/wc;
taui = 4;             %valore arrotondato
Ri = (1+taui/mi*s)/(1+taui*s);

Ga = Ri * Ga2;        %funzione di trasferimento d'anello finale

figure, margin(Ga)    %verifica dei requisiti operativi

C = Kc*Rd*Ri;         %controllore risultante
W = feedback(C*F1*F2,1); %fdt ad anello chiuso
figure, bode(W/dcgain(W)); %verifica della specifica d) e valutazione di Mr
figure, step(W/dcgain(W)); %verifica della specifica e) e valutazione di ts

sens = feedback(1,Ga);%funzione di sensibilità
We = Kr*sens;         %fdt d'errore
figure, step(We/s);   %errore di inseguimento all rampa
Wd1 = F2*sens;        %fdt y/d1
Wd2 = sens;           %fdt y/d2
figure, step(d1*Wd1); %effetto del disturbo d1 su y
figure, step(d2*Wd2); %effetto del disturbo d2 su y

%gamma) errore max al riferimento sinusoidale
wd = 0.2;             %pulsazione del riferimento sinusoidale
[ms,fs] = bode(sens,wd);
err_sin = ms*Kr;      %errore massimo di inseguimento alla sinusoide 
                      %in regime permanente
%Discretizzazione del controllore
figure, bode(W);      %cerco la pulsazione ad un'amplificazione di -3dB
wb = 21.5;
t = (2*pi)/(20*wb);   
t = 0.01;             %arrotondo il valore a 0.01 da 0.146
Gaz = Ga/(1+s*t/2);
figure, margin(Gaz);  %ottengo un margine di fase di 47 che è superiore
                      %ai 45 minimi richiesti da Nichols e da Bode
                      %calcolati prima. Procedo con la discretizzazione
Cd1 = c2d(C, t,'tustin');
Cd2 = c2d(C, t,'zoh');
Cd3 = c2d(C, t,'matched');

% W1 = feedback(Cd1*F1*F2,1);
% W2 = feedback(Cd2*F1*F2,1);
% W3 = feedback(Cd3*F1*F2,1);
% 
% figure, step(W1);
% figure, step(W2);
% figure, step(W3);