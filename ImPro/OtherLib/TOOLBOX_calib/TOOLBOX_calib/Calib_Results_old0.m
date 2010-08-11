% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 534.447801665943870 ; 535.371406319854830 ];

%-- Principal point:
cc = [ 321.499141269679400 ; 219.417811313938810 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.037465784773794 ; -0.096549554128833 ; -0.005030849657982 ; -0.001364400920259 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 2.311774745020272 ; 2.288239629418469 ];

%-- Principal point uncertainty:
cc_error = [ 3.637804745801466 ; 2.972973267306200 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.013540268433494 ; 0.037849329621836 ; 0.001907224046648 ; 0.002297952268151 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 21;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.109102e+000 ; 2.281595e+000 ; -4.448063e-002 ];
Tc_1  = [ -9.472410e+001 ; -1.006638e+002 ; 3.239677e+002 ];
omc_error_1 = [ 5.371552e-003 ; 6.262124e-003 ; 1.198951e-002 ];
Tc_error_1  = [ 2.245854e+000 ; 1.822527e+000 ; 1.815824e+000 ];

%-- Image #2:
omc_2 = [ 1.891286e+000 ; 1.948477e+000 ; -1.100053e+000 ];
Tc_2  = [ -8.529774e+001 ; -3.493194e+001 ; 3.519605e+002 ];
omc_error_2 = [ 3.503477e-003 ; 6.105341e-003 ; 8.765141e-003 ];
Tc_error_2  = [ 2.367467e+000 ; 1.951428e+000 ; 1.374240e+000 ];

%-- Image #3:
omc_3 = [ -2.261716e+000 ; -1.993349e+000 ; -5.166357e-001 ];
Tc_3  = [ -6.636114e+001 ; -5.384474e+001 ; 2.710441e+002 ];
omc_error_3 = [ 4.450245e-003 ; 6.190058e-003 ; 1.080643e-002 ];
Tc_error_3  = [ 1.881994e+000 ; 1.518906e+000 ; 1.547224e+000 ];

%-- Image #4:
omc_4 = [ 2.321072e+000 ; 1.888248e+000 ; -4.483396e-001 ];
Tc_4  = [ -1.289701e+002 ; -1.359639e+001 ; 3.008374e+002 ];
omc_error_4 = [ 4.923538e-003 ; 5.074650e-003 ; 9.459016e-003 ];
Tc_error_4  = [ 2.039372e+000 ; 1.699884e+000 ; 1.573716e+000 ];

%-- Image #5:
omc_5 = [ 1.784845e+000 ; 2.053186e+000 ; -2.103063e-001 ];
Tc_5  = [ -7.321594e+001 ; -7.707418e+001 ; 3.005902e+002 ];
omc_error_5 = [ 4.369967e-003 ; 5.506259e-003 ; 8.689192e-003 ];
Tc_error_5  = [ 2.052465e+000 ; 1.660830e+000 ; 1.503764e+000 ];

%-- Image #6:
omc_6 = [ 2.013243e+000 ; 2.373505e+000 ; -1.390049e-001 ];
Tc_6  = [ -1.402443e+002 ; -3.115835e+001 ; 4.385036e+002 ];
omc_error_6 = [ 8.028398e-003 ; 9.119811e-003 ; 1.660316e-002 ];
Tc_error_6  = [ 2.994748e+000 ; 2.494980e+000 ; 2.414355e+000 ];

%-- Image #7:
omc_7 = [ -1.967455e+000 ; -1.724727e+000 ; 9.976001e-001 ];
Tc_7  = [ -1.862761e+001 ; 1.101723e+001 ; 5.690804e+002 ];
omc_error_7 = [ 7.010516e-003 ; 5.730859e-003 ; 1.001323e-002 ];
Tc_error_7  = [ 3.874563e+000 ; 3.139744e+000 ; 2.256892e+000 ];

%-- Image #8:
omc_8 = [ 1.749937e+000 ; 2.098296e+000 ; 5.246533e-001 ];
Tc_8  = [ -6.300766e+001 ; -7.102946e+001 ; 3.145785e+002 ];
omc_error_8 = [ 5.998208e-003 ; 5.402815e-003 ; 9.498042e-003 ];
Tc_error_8  = [ 2.173307e+000 ; 1.767901e+000 ; 1.829242e+000 ];

%-- Image #9:
omc_9 = [ 1.777040e+000 ; 1.712378e+000 ; -7.279540e-001 ];
Tc_9  = [ -9.901480e+001 ; -8.406585e+000 ; 4.284887e+002 ];
omc_error_9 = [ 4.551616e-003 ; 6.050307e-003 ; 8.607306e-003 ];
Tc_error_9  = [ 2.900729e+000 ; 2.393484e+000 ; 1.881975e+000 ];

%-- Image #10:
omc_10 = [ -2.112287e+000 ; -2.102029e+000 ; -6.441783e-001 ];
Tc_10  = [ -8.505308e+001 ; -8.343133e+001 ; 3.153453e+002 ];
omc_error_10 = [ 5.014301e-003 ; 6.512196e-003 ; 1.149719e-002 ];
Tc_error_10  = [ 2.211800e+000 ; 1.798736e+000 ; 1.950371e+000 ];

%-- Image #11:
omc_11 = [ -1.615557e+000 ; -2.113116e+000 ; 1.102863e+000 ];
Tc_11  = [ 1.298645e+002 ; -2.479937e+001 ; 7.480678e+002 ];
omc_error_11 = [ 7.874879e-003 ; 8.284062e-003 ; 1.275516e-002 ];
Tc_error_11  = [ 5.143568e+000 ; 4.191229e+000 ; 3.542443e+000 ];

%-- Image #12:
omc_12 = [ -1.930530e+000 ; -2.299169e+000 ; -6.539300e-001 ];
Tc_12  = [ -2.152005e+002 ; 4.904893e+001 ; 6.823570e+002 ];
omc_error_12 = [ 7.906304e-003 ; 9.582768e-003 ; 1.707953e-002 ];
Tc_error_12  = [ 4.695207e+000 ; 3.945302e+000 ; 4.687196e+000 ];

%-- Image #13:
omc_13 = [ -1.666914e+000 ; -2.192399e+000 ; 1.480292e+000 ];
Tc_13  = [ -6.307316e+001 ; 1.519191e+002 ; 9.423259e+002 ];
omc_error_13 = [ 8.667017e-003 ; 8.399974e-003 ; 1.227674e-002 ];
Tc_error_13  = [ 6.475350e+000 ; 5.330699e+000 ; 5.042488e+000 ];

%-- Image #14:
omc_14 = [ -1.551261e+000 ; -2.283227e+000 ; 3.528270e-001 ];
Tc_14  = [ -9.301106e+001 ; -2.002781e+002 ; 8.084838e+002 ];
omc_error_14 = [ 8.439857e-003 ; 1.041323e-002 ; 1.649687e-002 ];
Tc_error_14  = [ 5.600487e+000 ; 4.538479e+000 ; 4.518124e+000 ];

%-- Image #15:
omc_15 = [ -1.705359e+000 ; -2.508872e+000 ; -5.383732e-001 ];
Tc_15  = [ -1.512210e+002 ; -1.308141e+002 ; 5.270878e+002 ];
omc_error_15 = [ 9.024908e-003 ; 1.085655e-002 ; 2.051728e-002 ];
Tc_error_15  = [ 3.680554e+000 ; 3.047175e+000 ; 3.740071e+000 ];

%-- Image #16:
omc_16 = [ -2.124605e+000 ; -1.674318e+000 ; 1.032788e+000 ];
Tc_16  = [ 6.653197e+001 ; -1.216955e+002 ; 6.892116e+002 ];
omc_error_16 = [ 9.401602e-003 ; 5.362118e-003 ; 1.241538e-002 ];
Tc_error_16  = [ 4.772654e+000 ; 3.831828e+000 ; 3.244843e+000 ];

%-- Image #17:
omc_17 = [ -1.588862e+000 ; -2.262164e+000 ; 6.225834e-001 ];
Tc_17  = [ -8.687270e+001 ; 2.323365e+001 ; 9.308164e+002 ];
omc_error_17 = [ 7.592752e-003 ; 1.178892e-002 ; 1.710075e-002 ];
Tc_error_17  = [ 6.350794e+000 ; 5.223635e+000 ; 5.266026e+000 ];

%-- Image #18:
omc_18 = [ 1.722137e+000 ; 2.237753e+000 ; -9.743781e-001 ];
Tc_18  = [ -6.762395e+001 ; -8.735622e+001 ; 4.962105e+002 ];
omc_error_18 = [ 4.153933e-003 ; 7.282894e-003 ; 1.006118e-002 ];
Tc_error_18  = [ 3.375224e+000 ; 2.768409e+000 ; 2.093355e+000 ];

%-- Image #19:
omc_19 = [ -1.910124e+000 ; -1.844162e+000 ; 1.097501e+000 ];
Tc_19  = [ -1.547549e+001 ; -1.682700e+001 ; 5.459992e+002 ];
omc_error_19 = [ 7.182684e-003 ; 5.356236e-003 ; 9.704359e-003 ];
Tc_error_19  = [ 3.714813e+000 ; 3.013405e+000 ; 2.096304e+000 ];

%-- Image #20:
omc_20 = [ 1.646123e+000 ; 1.893584e+000 ; 5.420441e-001 ];
Tc_20  = [ -9.689786e+001 ; -6.636200e+001 ; 3.118566e+002 ];
omc_error_20 = [ 5.683779e-003 ; 5.332759e-003 ; 8.603028e-003 ];
Tc_error_20  = [ 2.183343e+000 ; 1.773232e+000 ; 1.857867e+000 ];

%-- Image #21:
omc_21 = [ 1.648389e+000 ; 1.607150e+000 ; -9.180417e-001 ];
Tc_21  = [ -9.711761e+001 ; 2.476624e+001 ; 3.918167e+002 ];
omc_error_21 = [ 4.212790e-003 ; 5.807474e-003 ; 7.657920e-003 ];
Tc_error_21  = [ 2.657009e+000 ; 2.193925e+000 ; 1.610208e+000 ];

