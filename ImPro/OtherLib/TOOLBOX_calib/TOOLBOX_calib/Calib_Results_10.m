% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 716.531753410919240 ; 714.976850034456670 ];

%-- Principal point:
cc = [ 306.053777422236580 ; 219.741006583495930 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.180611310130661 ; -0.393529624043211 ; -0.020386292449176 ; -0.015458582134458 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 3.791480869284318 ; 3.991379012048264 ];

%-- Principal point uncertainty:
cc_error = [ 6.177851195543573 ; 4.766999135260285 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.021694505684057 ; 0.113022157064423 ; 0.002789668747129 ; 0.003807854946804 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 10;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 1.933475e+000 ; 2.260903e+000 ; -6.748488e-001 ];
Tc_1  = [ -3.832569e+001 ; -3.424088e+001 ; 3.321379e+002 ];
omc_error_1 = [ 5.618109e-003 ; 7.950498e-003 ; 1.197518e-002 ];
Tc_error_1  = [ 2.833699e+000 ; 2.187024e+000 ; 1.758200e+000 ];

%-- Image #2:
omc_2 = [ -1.942874e+000 ; -2.073918e+000 ; 1.120852e+000 ];
Tc_2  = [ 4.859168e+000 ; -4.790828e-001 ; 3.746326e+002 ];
omc_error_2 = [ 8.220042e-003 ; 6.016077e-003 ; 1.066500e-002 ];
Tc_error_2  = [ 3.210828e+000 ; 2.479640e+000 ; 1.779258e+000 ];

%-- Image #3:
omc_3 = [ 1.839818e+000 ; 2.300097e+000 ; -9.397720e-001 ];
Tc_3  = [ -3.514059e+000 ; -7.041419e+001 ; 3.484110e+002 ];
omc_error_3 = [ 4.791695e-003 ; 8.102118e-003 ; 1.171148e-002 ];
Tc_error_3  = [ 3.002791e+000 ; 2.289908e+000 ; 1.818353e+000 ];

%-- Image #4:
omc_4 = [ 1.962228e+000 ; 2.001188e+000 ; -6.834314e-001 ];
Tc_4  = [ -8.079935e+001 ; -4.081826e+001 ; 3.158336e+002 ];
omc_error_4 = [ 4.654715e-003 ; 7.737571e-003 ; 1.062618e-002 ];
Tc_error_4  = [ 2.699974e+000 ; 2.093798e+000 ; 1.796708e+000 ];

%-- Image #5:
omc_5 = [ 1.963753e+000 ; 1.860226e+000 ; -7.991818e-001 ];
Tc_5  = [ -8.439619e+001 ; -5.198683e+000 ; 3.253239e+002 ];
omc_error_5 = [ 4.826791e-003 ; 7.476483e-003 ; 1.031388e-002 ];
Tc_error_5  = [ 2.777090e+000 ; 2.171406e+000 ; 1.817909e+000 ];

%-- Image #6:
omc_6 = [ 2.055878e+000 ; 2.017382e+000 ; -8.517734e-001 ];
Tc_6  = [ -2.725000e+001 ; -6.926320e+000 ; 3.148744e+002 ];
omc_error_6 = [ 5.483677e-003 ; 6.789509e-003 ; 1.131437e-002 ];
Tc_error_6  = [ 2.691308e+000 ; 2.073585e+000 ; 1.564568e+000 ];

%-- Image #7:
omc_7 = [ -2.089485e+000 ; -1.912061e+000 ; 3.181370e-002 ];
Tc_7  = [ -2.639542e+001 ; -5.418898e+001 ; 2.976691e+002 ];
omc_error_7 = [ 7.664284e-003 ; 8.490820e-003 ; 1.626414e-002 ];
Tc_error_7  = [ 2.573293e+000 ; 1.974923e+000 ; 1.768214e+000 ];

%-- Image #8:
omc_8 = [ 2.100513e+000 ; 2.081230e+000 ; -9.361850e-001 ];
Tc_8  = [ 3.908973e+001 ; 1.075327e+001 ; 5.296558e+002 ];
omc_error_8 = [ 9.102320e-003 ; 8.536237e-003 ; 1.635186e-002 ];
Tc_error_8  = [ 4.563465e+000 ; 3.539493e+000 ; 2.753626e+000 ];

%-- Image #9:
omc_9 = [ 1.476289e+000 ; 1.866278e+000 ; -7.541738e-001 ];
Tc_9  = [ -1.860556e+001 ; -3.803011e+001 ; 3.454989e+002 ];
omc_error_9 = [ 5.296600e-003 ; 7.584258e-003 ; 9.294892e-003 ];
Tc_error_9  = [ 2.964047e+000 ; 2.284850e+000 ; 1.746123e+000 ];

%-- Image #10:
omc_10 = [ 1.534042e+000 ; 1.693918e+000 ; -7.277213e-001 ];
Tc_10  = [ -9.645509e+001 ; -3.250322e+001 ; 3.394515e+002 ];
omc_error_10 = [ 4.971867e-003 ; 7.809411e-003 ; 9.016409e-003 ];
Tc_error_10  = [ 2.926202e+000 ; 2.273021e+000 ; 1.918849e+000 ];

