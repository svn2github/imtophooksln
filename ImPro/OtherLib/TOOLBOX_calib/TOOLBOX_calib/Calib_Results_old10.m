% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 608.597204119296180 ; 607.569077077655490 ];

%-- Principal point:
cc = [ 311.435059795959890 ; 255.244847851724100 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.058405346943774 ; -0.081307058792526 ; 0.001863578934519 ; -0.011880636062551 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 5.982720997453346 ; 5.954339416763483 ];

%-- Principal point uncertainty:
cc_error = [ 6.092627345949425 ; 5.117537520097070 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.020970324715006 ; 0.082543884187824 ; 0.002746824525308 ; 0.003342879610920 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 20;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -1.793544e+000 ; -2.246315e+000 ; 9.749762e-001 ];
Tc_1  = [ -5.412447e+001 ; -2.508069e+001 ; 3.270224e+002 ];
omc_error_1 = [ 9.200744e-003 ; 6.926341e-003 ; 1.323762e-002 ];
Tc_error_1  = [ 3.255918e+000 ; 2.746935e+000 ; 3.030421e+000 ];

%-- Image #2:
omc_2 = [ 2.296344e+000 ; 1.847944e+000 ; -5.467832e-001 ];
Tc_2  = [ -1.135196e+002 ; -3.686977e+001 ; 3.320384e+002 ];
omc_error_2 = [ 5.947084e-003 ; 8.261904e-003 ; 1.614251e-002 ];
Tc_error_2  = [ 3.336790e+000 ; 2.819897e+000 ; 3.598821e+000 ];

%-- Image #3:
omc_3 = [ 2.064642e+000 ; 1.447549e+000 ; -5.377372e-002 ];
Tc_3  = [ -1.420843e+002 ; -2.982653e+001 ; 3.429442e+002 ];
omc_error_3 = [ 7.888037e-003 ; 8.329226e-003 ; 1.452149e-002 ];
Tc_error_3  = [ 3.464464e+000 ; 2.955913e+000 ; 4.069177e+000 ];

%-- Image #4:
omc_4 = [ 2.508966e+000 ; 1.794123e+000 ; 1.429748e-001 ];
Tc_4  = [ -9.847027e+001 ; -3.010499e+001 ; 3.440540e+002 ];
omc_error_4 = [ 1.318539e-002 ; 1.062596e-002 ; 2.795046e-002 ];
Tc_error_4  = [ 3.492201e+000 ; 2.936131e+000 ; 3.846862e+000 ];

%-- Image #5:
omc_5 = [ -2.266640e+000 ; -1.736747e+000 ; 4.401027e-001 ];
Tc_5  = [ 2.281575e+001 ; -1.898581e+001 ; 4.227192e+002 ];
omc_error_5 = [ 1.146212e-002 ; 1.129843e-002 ; 2.524279e-002 ];
Tc_error_5  = [ 4.263717e+000 ; 3.550187e+000 ; 4.344758e+000 ];

%-- Image #6:
omc_6 = [ -2.258672e+000 ; -1.512362e+000 ; -1.587381e-001 ];
Tc_6  = [ -2.394975e+000 ; -5.409914e+001 ; 3.223865e+002 ];
omc_error_6 = [ 9.083894e-003 ; 8.751542e-003 ; 1.555093e-002 ];
Tc_error_6  = [ 3.272827e+000 ; 2.698904e+000 ; 3.497815e+000 ];

%-- Image #7:
omc_7 = [ 1.832691e+000 ; 1.667938e+000 ; -1.236370e+000 ];
Tc_7  = [ -4.914826e+001 ; 7.688538e+000 ; 3.526155e+002 ];
omc_error_7 = [ 6.364379e-003 ; 8.918735e-003 ; 1.279843e-002 ];
Tc_error_7  = [ 3.517404e+000 ; 2.965601e+000 ; 3.148780e+000 ];

%-- Image #8:
omc_8 = [ -2.214761e+000 ; -1.659110e+000 ; 7.693844e-001 ];
Tc_8  = [ -2.300299e+001 ; -1.111086e+001 ; 3.163911e+002 ];
omc_error_8 = [ 8.343100e-003 ; 5.384335e-003 ; 1.398852e-002 ];
Tc_error_8  = [ 3.157071e+000 ; 2.627772e+000 ; 2.942476e+000 ];

%-- Image #9:
omc_9 = [ 2.351548e+000 ; 1.835851e+000 ; -2.048058e-001 ];
Tc_9  = [ -1.135576e+002 ; -1.770061e+001 ; 3.065178e+002 ];
omc_error_9 = [ 8.421508e-003 ; 8.464343e-003 ; 1.732077e-002 ];
Tc_error_9  = [ 3.065895e+000 ; 2.614315e+000 ; 3.465178e+000 ];

%-- Image #10:
omc_10 = [ 2.412235e+000 ; 1.804315e+000 ; 1.279718e-001 ];
Tc_10  = [ -1.360784e+002 ; -2.762638e+001 ; 3.513288e+002 ];
omc_error_10 = [ 1.309522e-002 ; 1.237833e-002 ; 2.715078e-002 ];
Tc_error_10  = [ 3.568863e+000 ; 3.025770e+000 ; 4.088361e+000 ];

%-- Image #11:
omc_11 = [ -2.628474e+000 ; -1.700275e+000 ; 2.605659e-001 ];
Tc_11  = [ -1.193665e+002 ; 1.558620e+001 ; 4.461263e+002 ];
omc_error_11 = [ 1.359813e-002 ; 8.240367e-003 ; 2.533103e-002 ];
Tc_error_11  = [ 4.452217e+000 ; 3.792720e+000 ; 4.789584e+000 ];

%-- Image #12:
omc_12 = [ -2.477008e+000 ; -1.913411e+000 ; 1.422505e-001 ];
Tc_12  = [ -6.510107e+001 ; -4.439327e+001 ; 2.014713e+002 ];
omc_error_12 = [ 6.859179e-003 ; 4.602487e-003 ; 1.335570e-002 ];
Tc_error_12  = [ 2.030187e+000 ; 1.695846e+000 ; 2.238657e+000 ];

%-- Image #13:
omc_13 = [ 2.275379e+000 ; 2.043221e+000 ; -2.949072e-001 ];
Tc_13  = [ -9.017692e+001 ; -5.988361e+001 ; 2.590539e+002 ];
omc_error_13 = [ 5.702830e-003 ; 7.603386e-003 ; 1.567489e-002 ];
Tc_error_13  = [ 2.607371e+000 ; 2.185840e+000 ; 2.947487e+000 ];

%-- Image #14:
omc_14 = [ -2.534226e+000 ; -1.511855e+000 ; 7.585894e-001 ];
Tc_14  = [ -4.829360e+001 ; 4.289585e+001 ; 5.494100e+002 ];
omc_error_14 = [ 1.197826e-002 ; 7.039126e-003 ; 2.000457e-002 ];
Tc_error_14  = [ 5.495978e+000 ; 4.628524e+000 ; 5.472430e+000 ];

%-- Image #15:
omc_15 = [ 1.995561e+000 ; 1.607515e+000 ; -1.326429e+000 ];
Tc_15  = [ -1.882352e+001 ; 5.230345e+001 ; 5.426886e+002 ];
omc_error_15 = [ 7.740154e-003 ; 9.366625e-003 ; 1.440897e-002 ];
Tc_error_15  = [ 5.439872e+000 ; 4.587808e+000 ; 5.046392e+000 ];

%-- Image #16:
omc_16 = [ -2.445071e+000 ; -1.556275e+000 ; -3.642983e-001 ];
Tc_16  = [ -1.233137e+002 ; -4.883355e+001 ; 4.287948e+002 ];
omc_error_16 = [ 1.441562e-002 ; 9.205412e-003 ; 2.529178e-002 ];
Tc_error_16  = [ 4.327719e+000 ; 3.642099e+000 ; 4.897263e+000 ];

%-- Image #17:
omc_17 = [ 2.477419e+000 ; 1.931874e+000 ; -2.952618e-001 ];
Tc_17  = [ 2.422729e+001 ; -5.654955e+001 ; 4.301935e+002 ];
omc_error_17 = [ 1.484815e-002 ; 1.016513e-002 ; 2.873053e-002 ];
Tc_error_17  = [ 4.372065e+000 ; 3.620343e+000 ; 4.572409e+000 ];

%-- Image #18:
omc_18 = [ -2.124718e+000 ; -1.511222e+000 ; 7.812294e-001 ];
Tc_18  = [ 1.544746e+001 ; -1.042187e+001 ; 4.227759e+002 ];
omc_error_18 = [ 8.975196e-003 ; 6.360070e-003 ; 1.461006e-002 ];
Tc_error_18  = [ 4.249511e+000 ; 3.539975e+000 ; 3.919472e+000 ];

%-- Image #19:
omc_19 = [ -2.446934e+000 ; -1.769505e+000 ; 6.052952e-002 ];
Tc_19  = [ -5.051026e+001 ; -3.956873e+001 ; 2.641085e+002 ];
omc_error_19 = [ 8.484025e-003 ; 6.755997e-003 ; 1.687367e-002 ];
Tc_error_19  = [ 2.650670e+000 ; 2.228436e+000 ; 2.777760e+000 ];

%-- Image #20:
omc_20 = [ 2.357959e+000 ; 1.768690e+000 ; -7.997878e-001 ];
Tc_20  = [ -9.140973e+001 ; -3.409148e+001 ; 2.943419e+002 ];
omc_error_20 = [ 5.257772e-003 ; 7.939802e-003 ; 1.553603e-002 ];
Tc_error_20  = [ 2.958261e+000 ; 2.483572e+000 ; 3.036998e+000 ];

