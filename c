clc;
clear;
close all;
a_deg = 120;
a = 1 * exp(1j * deg2rad(a_deg));
Va = 10 * exp(1j * deg2rad(90));  
Vb = 5  * exp(1j * deg2rad(30));  
Vc = 10 * exp(1j * deg2rad(210)); 
a2 = a^2;
Va0 = (1/3) * (Va + Vb + Vc);       
Va1 = (1/3) * (Va + a*Vb + a2*Vc);         
Va2 = (1/3) * (Va + a2*Vb + a*Vc);         

Vb0 = Va0;
Vb1 = a2 * Va1;
Vb2 = a * Va2;

Vc0 = Va0;
Vc1 = a * Va1;
Vc2 = a2 * Va2;
figure; 
sgtitle('Symmetrical Component Analysis of Unbalanced Voltages');

subplot(2, 2, 2);
compass([Va0, Vb0, Vc0], 'k');
title('Zero-Sequence Components');
legend('Va0', 'Vb0', 'Vc0', 'Location', 'northeast');

subplot(2, 2, 1);
compass([Va, Vb, Vc], 'b');
title('Original Unbalanced Phasors');
legend('Va', 'Vb', 'Vc', 'Location', 'northeast');

subplot(2, 2, 3);
compass([Va1, Vb1, Vc1], 'r');
title('Positive-Sequence Components (ABC)');
legend('Va1', 'Vb1', 'Vc1', 'Location', 'northeast');

subplot(2, 2, 4);
compass([Va2, Vb2, Vc2], 'm');
title('Negative-Sequence Components (ACB)');
legend('Va2', 'Vb2', 'Vc2', 'Location', 'northeast');
