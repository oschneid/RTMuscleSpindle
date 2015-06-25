clear all;
clc;
close all;

%% General
ksr = 10.4649;
kpr = 0.15;
m = 0.0002;
cl = 1;
cs = 0.42;
x = 0.7;
lsrn = 0.0423;
lprn = 0.89;
a = 0.3;
r = 0.46;
lsr0 = 0.04;
lpr0 = 0.76;
lsnd = 0.04;
p = 2;
s = 0.156;

%% Bag1
bag1_b0 = 0.0605;
bag1_b1 = 0.2593;
bag1_gamma1 = 0.0289;
bag1_g = 20000;
bag1_tau = 0.149;
bag1_freq = 60;

%% Bag2
bag2_b0 = 0.0822;
bag2_b2 = -0.046;
bag2_gamma2 = 0.0636;
bag2_g = 10000;
bag2_gsnd = 7250;
bag2_tau = 0.205;
bag2_freq = 60;

%% Chain
chain_b0 = 0.0822;
chain_b2 = -0.0690;
chain_gamma2 = 0.0954;
chain_g = 10000;
chain_gsnd = 7250;
chain_freq = 90;
