clear all;
close all;
clc;
s = tf('s');

Gp = -0.65/(s^3+4*s^2+1.75*s);
Tp = 1;
A = 9;
d1 = 5.5e-3;
d2 = 5.5e-3;

%a)