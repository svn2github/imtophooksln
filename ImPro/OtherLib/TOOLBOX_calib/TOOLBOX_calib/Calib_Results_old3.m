% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 409.506537220468320 ; 410.879370245709990 ];

%-- Principal point:
cc = [ 325.748949838799210 ; 285.805737575831300 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.020516932609924 ; -0.047652152141992 ; 0.009022881284558 ; 0.002016459057459 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 30.457721776221341 ; 29.600549125873794 ];

%-- Principal point uncertainty:
cc_error = [ 6.236501804467032 ; 13.217430630556162 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.017730333805387 ; 0.022578187511613 ; 0.003374866934180 ; 0.003880367805034 ; 0.000000000000000 ];

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
omc_1 = [ 2.125386e+000 ; 2.202705e+000 ; -2.365159e-001 ];
Tc_1  = [ -3.787252e+001 ; -2.245577e+001 ; 1.922512e+002 ];
omc_error_1 = [ 1.056346e-002 ; 1.211833e-002 ; 2.380597e-002 ];
Tc_error_1  = [ 2.888116e+000 ; 6.107614e+000 ; 1.428824e+001 ];

%-- Image #2:
omc_2 = [ 2.087577e+000 ; 2.235300e+000 ; -1.847948e-001 ];
Tc_2  = [ -5.442641e+001 ; -8.826214e+001 ; 1.757225e+002 ];
omc_error_2 = [ 8.930156e-003 ; 1.470075e-002 ; 2.798933e-002 ];
Tc_error_2  = [ 2.750486e+000 ; 5.411476e+000 ; 1.304479e+001 ];

%-- Image #3:
omc_3 = [ 2.072158e+000 ; 2.294116e+000 ; -4.617756e-001 ];
Tc_3  = [ -8.131591e+001 ; -1.006020e+002 ; 2.715971e+002 ];
omc_error_3 = [ 7.020667e-003 ; 1.826479e-002 ; 3.685790e-002 ];
Tc_error_3  = [ 4.187183e+000 ; 8.564056e+000 ; 1.974817e+001 ];

%-- Image #4:
omc_4 = [ -1.892780e+000 ; -2.202554e+000 ; 7.592033e-001 ];
Tc_4  = [ -2.924708e+001 ; -9.284354e+001 ; 4.730953e+002 ];
omc_error_4 = [ 1.826467e-002 ; 1.209370e-002 ; 4.517310e-002 ];
Tc_error_4  = [ 7.196579e+000 ; 1.528680e+001 ; 3.322296e+001 ];

%-- Image #5:
omc_5 = [ 2.022317e+000 ; 2.230773e+000 ; -4.656926e-001 ];
Tc_5  = [ -1.982537e+002 ; -1.655003e+002 ; 2.787648e+002 ];
omc_error_5 = [ 9.146526e-003 ; 2.666153e-002 ; 4.674231e-002 ];
Tc_error_5  = [ 4.761730e+000 ; 9.211050e+000 ; 2.061125e+001 ];

%-- Image #6:
omc_6 = [ 2.191834e+000 ; 2.159142e+000 ; -3.966820e-001 ];
Tc_6  = [ -1.598933e+002 ; 2.418139e+000 ; 2.671527e+002 ];
omc_error_6 = [ 1.314464e-002 ; 2.224679e-002 ; 3.294091e-002 ];
Tc_error_6  = [ 4.070842e+000 ; 8.774884e+000 ; 1.944235e+001 ];

%-- Image #7:
omc_7 = [ -2.058618e+000 ; -2.194339e+000 ; 5.029620e-001 ];
Tc_7  = [ 9.654364e+001 ; -1.194085e+001 ; 2.690194e+002 ];
omc_error_7 = [ 1.599540e-002 ; 2.290878e-002 ; 5.679735e-002 ];
Tc_error_7  = [ 4.323783e+000 ; 8.647496e+000 ; 2.045056e+001 ];

%-- Image #8:
omc_8 = [ -2.042661e+000 ; -2.298900e+000 ; 6.122295e-001 ];
Tc_8  = [ 6.231106e+001 ; -8.948271e+001 ; 2.573047e+002 ];
omc_error_8 = [ 1.602902e-002 ; 1.108759e-002 ; 4.318727e-002 ];
Tc_error_8  = [ 4.067412e+000 ; 8.177974e+000 ; 1.858968e+001 ];

%-- Image #9:
omc_9 = [ -2.038661e+000 ; -2.319174e+000 ; 6.154669e-001 ];
Tc_9  = [ 4.254813e+001 ; -1.237746e+002 ; 2.464848e+002 ];
omc_error_9 = [ 1.809452e-002 ; 1.034634e-002 ; 4.231390e-002 ];
Tc_error_9  = [ 3.940514e+000 ; 7.814360e+000 ; 1.791249e+001 ];

%-- Image #10:
omc_10 = [ -2.085904e+000 ; -2.209688e+000 ; 2.190480e-001 ];
Tc_10  = [ 1.201450e+002 ; -5.305182e+001 ; 3.588973e+002 ];
omc_error_10 = [ 1.608545e-002 ; 2.242564e-002 ; 3.415134e-002 ];
Tc_error_10  = [ 5.921799e+000 ; 1.151004e+001 ; 2.708454e+001 ];

