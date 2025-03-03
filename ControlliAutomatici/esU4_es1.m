% clear all
% close all
% clc
% s = tf('s');
% F1 = 30/(s+15);
% F2 = (3*s+3)/(s^3+10*s^2+24*s);
% d1 = 1;
% d2 = 4;
% Kr = 1;
% K1 = dcgain(F1);
% K2 = dcgain(s*F2);
% 
% Kca = Kr/(K1*K2*0.1); %Kc minimo in modulo per soddifare la specifica a)
% Kcb = d1/(k1*0.05);   %Kc minimo in modulo per soddifare la specifica b)
% Kc = max(Kca, Kcb);   %valore minimo in modulo di Kc
% nyquist(F1*F2);       %scelta del segno di Kc
% Ga1 = Kc*F1*F2;       %funzione ad anello di partenza
% wc=12.6;              %wc desiderata
% figure, bode(Ga1);
% 
% %Rete anticipatrice
% md = 10;
% wtau = sqrt(md);
% taud = wtaud/wc;
% taud = 0.25;          %valore arrotondato
% Rd = (1+taud*s)/(1+taud/md*s);
% Ga2 = Rd*Ga1;         %funzione di trasferimento d'anello comprendente anche la rete anticipatrice
% [ma2,fa2] = bode(Ga2,wc); %valutazione di modulo e fase alla wc desierata
% 
% %Rete attenuatrice
% mi = 3.15;
% wtaui = 50;
% taui = wtaui/wc;
% taui = 4;             %valore arrotondato
% Ri = (1+taui/mi*s)/(1+taui*s);
% 
% Ga = Ri * Ga2;        %funzione di trasferimento d'anello finale
% 
% figure, margin(Ga)    %verifica dei requisiti operativi
% 
% C = Kc*Rd*Ri;         %controllore risultante
% W = feedback(C*F1*F2,1); %fdt ad anello chiuso
% figure, bode(W);      %verifica della specifica d) e valutazione di Mr
% figure, step(W);      %verifica della specifica e) e valutazione di ts
% 
% sens = feedback(1,Ga);%funzione di sensibilità
% We = Kr*sens;         %fdt d'errore
% figure, step(We/s);   %errore di inseguimento all rampa
% Wd1 = F2*sens;        %fdt y/d1
% Wd2 = sens;           %fdt y/d2
% figure, step(d1*Wd1); %effetto del disturbo d1 su y
% figure, step(d2*Wd2); %effetto del disturbo d2 su y
% wd = 0.2;             %pulsazione del riferimento sinusoidale
% [ms,fs] = bode(sens,wd);
% err_sin = ms*Kr;      %errore massimo di inseguimento alla sinusoide in regime permanente

%-------------------------------------------------------------------------
clear all
close all
clc

s = tf('s');
F1 = 30/(s+15);
F2 = (3*s+3)/(s^3+10*s^2+24*s);

d1 = 1;
d2 = 4;

Kr = 1;
Kf1 = dcgain(F1);
Kf2 = dcgain(s*F2);
%a)
Kc1 = (Kr^2)/(0.1*Kf1*Kf2);
%b)
Kc2 = d1/(Kf1*0.05);
%c) già risolto

Kc = max(Kc1, Kc2);
%guardo il segno di Kc con Nyquist
nyquist(F1*F2);
%ottengo che da Nyquist e dal segno della retroazione che Kc ha segno
%positivo

%OPPURE
%Kga > 0
%1 solo wc in cui la fase = -180° e il modulo = 0
%minima rotazione di fase = 
KGa = dcgain(Kc*s*F1*F2);

%d)
wcd = 20*0.63;
%e)
sovr = 0.2;
Mr = 20*log10((1+sovr)/0.9);
%Guardo Nichols ottengo 45°

Ga = Kc*F1*F2;
figure, bode(Ga);
%ottengo che all' omega di crossover la fase vale -181° quindi Nichols più
%questo dato mi dice che ho bisogo di recuperare almeno 50-55 gradi

%RETI
%Anticipatrice
md = 10;
xd = sqrt(md);
taud = xd/wcd;
D = (s*taud+1)/(s*taud/md+1);

Ga1 = Ga * D;
figure, bode(Ga1);
%ottengo da bode che in wcd = 12.6 ho una fase di -126°, quindi ho
%recuperato un totale di 54°. Ottimo, sono nelle specifiche

%Per fare l'attenuatrice guardo il modulo alla mia wcd e lo approssimo al
%primo decimale, dagli abachi prendo una wt nell'abaco sopra che sia
%intorno al 70-80, e guardo,scendendo in quello della fase, quanta fase
%recupero e se è accettabile
[m1,f1] = bode(Ga1,wcd);
m1 = 3.2;

%Attenuatrice
mi = m1;
wtaui = 70;
%la taui la costruisco così e non dal formulario ATTENZIONE!
taui = wtaui/wcd;
I = (s*taui/mi+1)/(s*taui+1);

Ga2 = Ga1 * I;
%Con questo bode faccio le verifiche finali su fase e modulo
figure, bode(Ga2);
figure, margin(Ga2);

C = Kc*D*I;
W = feedback(C*F1*F2,1/Kr);

%devo ancora controllare che la specifica d) sia rispettata quindi
%controllo il bode di Ga3 a modulo 3db e vedo che sia, come nel testo
%dell'esercizio, 20 rad/s +/- 20%, quindi tra 18 e 19 dB

figure, step(W);

%Passo a simulink