% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 710.902741536270130 ; 711.611419403991480 ];

%-- Principal point:
cc = [ 310.520737427734670 ; 281.986329591093920 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.174763226242565 ; -0.209835277568146 ; 0.020108358780009 ; -0.002123729250442 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 5.977869163044166 ; 6.342212432481949 ];

%-- Principal point uncertainty:
cc_error = [ 10.480805192613788 ; 9.365630380590998 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.053741697057580 ; 0.364048631441301 ; 0.006679833102503 ; 0.006973534142355 ; 0.000000000000000 ];

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
omc_1 = [ -1.145091e+000 ; -1.593925e+000 ; -5.078707e-001 ];
Tc_1  = [ -3.384959e+001 ; -9.427091e+001 ; 3.307016e+002 ];
omc_error_1 = [ 9.659228e-003 ; 1.296530e-002 ; 1.452232e-002 ];
Tc_error_1  = [ 4.993487e+000 ; 4.412394e+000 ; 2.855589e+000 ];

%-- Image #2:
omc_2 = [ -1.699011e+000 ; -1.924913e+000 ; -4.650626e-001 ];
Tc_2  = [ -5.513975e+001 ; -7.630170e+001 ; 2.818038e+002 ];
omc_error_2 = [ 8.352774e-003 ; 1.125608e-002 ; 1.786481e-002 ];
Tc_error_2  = [ 4.251418e+000 ; 3.789669e+000 ; 2.472777e+000 ];

%-- Image #3:
omc_3 = [ 2.285211e+000 ; 1.824191e+000 ; -1.728172e-001 ];
Tc_3  = [ -9.621103e+001 ; -3.723943e+001 ; 3.561805e+002 ];
omc_error_3 = [ 1.250619e-002 ; 1.261540e-002 ; 2.747789e-002 ];
Tc_error_3  = [ 5.258548e+000 ; 4.740460e+000 ; 3.062494e+000 ];

%-- Image #4:
omc_4 = [ 2.089219e+000 ; 1.406117e+000 ; 1.031810e+000 ];
Tc_4  = [ -4.972971e+001 ; -3.979972e+001 ; 1.911013e+002 ];
omc_error_4 = [ 1.444565e-002 ; 9.465449e-003 ; 1.783687e-002 ];
Tc_error_4  = [ 2.895241e+000 ; 2.553126e+000 ; 2.009179e+000 ];

%-- Image #5:
omc_5 = [ -1.974151e+000 ; -2.073648e+000 ; -4.065133e-001 ];
Tc_5  = [ -6.772360e+001 ; -4.318273e+001 ; 2.301575e+002 ];
omc_error_5 = [ 8.654116e-003 ; 1.146905e-002 ; 1.925514e-002 ];
Tc_error_5  = [ 3.450285e+000 ; 3.100104e+000 ; 2.073841e+000 ];

%-- Image #6:
omc_6 = [ -1.349864e+000 ; -1.678546e+000 ; -7.949871e-001 ];
Tc_6  = [ -6.136531e+001 ; -4.766464e+001 ; 2.243981e+002 ];
omc_error_6 = [ 9.715089e-003 ; 1.303864e-002 ; 1.528413e-002 ];
Tc_error_6  = [ 3.341859e+000 ; 3.014285e+000 ; 2.094482e+000 ];

%-- Image #7:
omc_7 = [ -2.201855e+000 ; -2.122052e+000 ; -4.647894e-002 ];
Tc_7  = [ -1.046276e+002 ; -8.906365e+001 ; 3.547101e+002 ];
omc_error_7 = [ 1.499389e-002 ; 1.158143e-002 ; 3.445093e-002 ];
Tc_error_7  = [ 5.326917e+000 ; 4.778776e+000 ; 3.344012e+000 ];

%-- Image #8:
omc_8 = [ 2.159178e+000 ; 1.587607e+000 ; 1.200959e+000 ];
Tc_8  = [ -6.556613e+001 ; -3.879239e+001 ; 2.927209e+002 ];
omc_error_8 = [ 1.555893e-002 ; 8.505958e-003 ; 1.913577e-002 ];
Tc_error_8  = [ 4.414752e+000 ; 3.910302e+000 ; 2.933296e+000 ];

%-- Image #9:
omc_9 = [ 2.268998e+000 ; 1.654332e+000 ; 4.006157e-001 ];
Tc_9  = [ -1.006705e+002 ; -7.447196e+001 ; 3.515751e+002 ];
omc_error_9 = [ 1.379880e-002 ; 1.217650e-002 ; 2.412461e-002 ];
Tc_error_9  = [ 5.265284e+000 ; 4.710027e+000 ; 3.512331e+000 ];

%-- Image #10:
omc_10 = [ -1.506447e+000 ; -1.945678e+000 ; -1.820005e-003 ];
Tc_10  = [ 8.239057e+000 ; -8.900989e+001 ; 3.934599e+002 ];
omc_error_10 = [ 8.488850e-003 ; 1.119952e-002 ; 1.908124e-002 ];
Tc_error_10  = [ 5.943744e+000 ; 5.218904e+000 ; 3.233644e+000 ];

