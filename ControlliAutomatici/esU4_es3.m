close all
clear all
clc

s= tf('s');
F1 = (s+40)/(s+2);
F2 = (80)/(s^2 +13*s +256);
Kr = 1;
d1 =0.5;
d2 = 0.2;

%a)