% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 723.629478918826750 ; 722.091381927581550 ];

%-- Principal point:
cc = [ 304.313193396808630 ; 212.553113128474680 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.174677769352443 ; -0.322579389973120 ; -0.022816539838631 ; -0.016482064858234 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 7.959836692070034 ; 9.040532528302405 ];

%-- Principal point uncertainty:
cc_error = [ 9.282736103525657 ; 7.322921128103936 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.025668924022946 ; 0.128775208759569 ; 0.003996605566284 ; 0.005415471981670 ; 0.000000000000000 ];

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
omc_1 = [ 1.930161e+000 ; 2.255913e+000 ; -6.847864e-001 ];
Tc_1  = [ -3.751497e+001 ; -3.095622e+001 ; 3.353010e+002 ];
omc_error_1 = [ 7.107334e-003 ; 1.073774e-002 ; 1.554164e-002 ];
Tc_error_1  = [ 4.249714e+000 ; 3.364573e+000 ; 3.736523e+000 ];

%-- Image #2:
omc_2 = [ -1.944827e+000 ; -2.072263e+000 ; 1.132873e+000 ];
Tc_2  = [ 5.774025e+000 ; 3.233880e+000 ; 3.777213e+002 ];
omc_error_2 = [ 1.131219e-002 ; 7.018527e-003 ; 1.440548e-002 ];
Tc_error_2  = [ 4.823855e+000 ; 3.793467e+000 ; 3.921909e+000 ];

%-- Image #3:
omc_3 = [ 1.836142e+000 ; 2.293218e+000 ; -9.503453e-001 ];
Tc_3  = [ -2.685022e+000 ; -6.695955e+001 ; 3.516438e+002 ];
omc_error_3 = [ 6.196117e-003 ; 1.159625e-002 ; 1.628008e-002 ];
Tc_error_3  = [ 4.495470e+000 ; 3.538186e+000 ; 3.817232e+000 ];

%-- Image #4:
omc_4 = [ 1.957755e+000 ; 1.996260e+000 ; -6.924370e-001 ];
Tc_4  = [ -8.005136e+001 ; -3.770831e+001 ; 3.189351e+002 ];
omc_error_4 = [ 6.858501e-003 ; 1.091351e-002 ; 1.468233e-002 ];
Tc_error_4  = [ 4.038885e+000 ; 3.223288e+000 ; 3.577434e+000 ];

%-- Image #5:
omc_5 = [ 1.958755e+000 ; 1.855127e+000 ; -8.074796e-001 ];
Tc_5  = [ -8.361070e+001 ; -1.971039e+000 ; 3.283960e+002 ];
omc_error_5 = [ 7.102620e-003 ; 1.051754e-002 ; 1.433837e-002 ];
Tc_error_5  = [ 4.160059e+000 ; 3.324790e+000 ; 3.630243e+000 ];

%-- Image #6:
omc_6 = [ 2.051320e+000 ; 2.011613e+000 ; -8.607044e-001 ];
Tc_6  = [ -2.646768e+001 ; -3.806371e+000 ; 3.176875e+002 ];
omc_error_6 = [ 7.250704e-003 ; 9.480543e-003 ; 1.522546e-002 ];
Tc_error_6  = [ 4.040959e+000 ; 3.180362e+000 ; 3.407928e+000 ];

%-- Image #7:
omc_7 = [ -2.093077e+000 ; -1.913888e+000 ; 4.186520e-002 ];
Tc_7  = [ -2.567848e+001 ; -5.123428e+001 ; 3.006168e+002 ];
omc_error_7 = [ 9.190604e-003 ; 1.031087e-002 ; 1.847008e-002 ];
Tc_error_7  = [ 3.849074e+000 ; 3.043779e+000 ; 3.420722e+000 ];

%-- Image #8:
omc_8 = [ 2.095217e+000 ; 2.074173e+000 ; -9.449592e-001 ];
Tc_8  = [ 4.036287e+001 ; 1.606240e+001 ; 5.340884e+002 ];
omc_error_8 = [ 9.906493e-003 ; 1.070225e-002 ; 1.868445e-002 ];
Tc_error_8  = [ 6.867538e+000 ; 5.417340e+000 ; 5.828117e+000 ];

%-- Image #9:
omc_9 = [ 1.469487e+000 ; 1.861484e+000 ; -7.627557e-001 ];
Tc_9  = [ -1.779374e+001 ; -3.458512e+001 ; 3.486209e+002 ];
omc_error_9 = [ 7.645526e-003 ; 1.083191e-002 ; 1.352701e-002 ];
Tc_error_9  = [ 4.437345e+000 ; 3.519409e+000 ; 3.696435e+000 ];

%-- Image #10:
omc_10 = [ 1.526881e+000 ; 1.689811e+000 ; -7.366681e-001 ];
Tc_10  = [ -9.562716e+001 ; -2.912189e+001 ; 3.426372e+002 ];
omc_error_10 = [ 7.586345e-003 ; 1.108764e-002 ; 1.363171e-002 ];
Tc_error_10  = [ 4.391327e+000 ; 3.498991e+000 ; 3.656103e+000 ];

