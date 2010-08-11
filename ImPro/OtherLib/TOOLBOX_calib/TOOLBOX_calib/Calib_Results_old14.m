% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 704.570873527472830 ; 704.208495667320220 ];

%-- Principal point:
cc = [ 308.887352666659810 ; 241.713166290299280 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.205756818851085 ; -0.547378024566003 ; -0.016958162009751 ; -0.006839986081704 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.019604636612058 ; 6.314250638289502 ];

%-- Principal point uncertainty:
cc_error = [ 6.801609757835540 ; 6.092869384342298 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.025448740999465 ; 0.146291540987682 ; 0.003478899824970 ; 0.004023962046790 ; 0.000000000000000 ];

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
omc_1 = [ 2.041503e+000 ; 1.865863e+000 ; -6.546171e-001 ];
Tc_1  = [ -8.447718e+001 ; -3.183197e+001 ; 3.477575e+002 ];
omc_error_1 = [ 6.016453e-003 ; 7.773519e-003 ; 1.322249e-002 ];
Tc_error_1  = [ 3.320271e+000 ; 3.001498e+000 ; 3.104963e+000 ];

%-- Image #2:
omc_2 = [ 1.635295e+000 ; 1.689482e+000 ; -1.030342e+000 ];
Tc_2  = [ -5.635075e+001 ; -6.775588e+000 ; 3.893291e+002 ];
omc_error_2 = [ 6.741299e-003 ; 8.441199e-003 ; 1.175353e-002 ];
Tc_error_2  = [ 3.733462e+000 ; 3.364436e+000 ; 3.154048e+000 ];

%-- Image #3:
omc_3 = [ 1.472514e+000 ; 1.886680e+000 ; -1.002704e+000 ];
Tc_3  = [ -2.317965e+000 ; -3.889902e+001 ; 3.841128e+002 ];
omc_error_3 = [ 6.713083e-003 ; 8.633518e-003 ; 1.156099e-002 ];
Tc_error_3  = [ 3.687781e+000 ; 3.305065e+000 ; 3.099342e+000 ];

%-- Image #4:
omc_4 = [ 1.679838e+000 ; 1.500491e+000 ; -1.303118e+000 ];
Tc_4  = [ -2.419718e+001 ; 3.803853e+001 ; 4.874939e+002 ];
omc_error_4 = [ 7.580686e-003 ; 8.816394e-003 ; 1.140092e-002 ];
Tc_error_4  = [ 4.708245e+000 ; 4.213388e+000 ; 3.849890e+000 ];

%-- Image #5:
omc_5 = [ 2.344283e+000 ; 1.548958e+000 ; -4.742518e-001 ];
Tc_5  = [ -1.298737e+002 ; -5.898478e+001 ; 4.067745e+002 ];
omc_error_5 = [ 7.021947e-003 ; 7.856768e-003 ; 1.461379e-002 ];
Tc_error_5  = [ 3.910226e+000 ; 3.544782e+000 ; 3.881908e+000 ];

%-- Image #6:
omc_6 = [ 2.018035e+000 ; 1.839012e+000 ; -5.634185e-001 ];
Tc_6  = [ -7.877113e+001 ; -3.051948e+001 ; 2.605339e+002 ];
omc_error_6 = [ 5.696820e-003 ; 7.178606e-003 ; 1.229931e-002 ];
Tc_error_6  = [ 2.489303e+000 ; 2.249264e+000 ; 2.427499e+000 ];

%-- Image #7:
omc_7 = [ 1.998640e+000 ; 1.840813e+000 ; -1.089526e+000 ];
Tc_7  = [ -7.253214e+001 ; 3.916843e+001 ; 5.119353e+002 ];
omc_error_7 = [ 6.666229e-003 ; 8.843514e-003 ; 1.412468e-002 ];
Tc_error_7  = [ 4.920707e+000 ; 4.440259e+000 ; 4.380072e+000 ];

%-- Image #8:
omc_8 = [ -2.286888e+000 ; -2.065641e+000 ; 3.358128e-001 ];
Tc_8  = [ -1.097796e+001 ; -6.852503e+001 ; 4.186523e+002 ];
omc_error_8 = [ 1.104486e-002 ; 9.450389e-003 ; 2.176888e-002 ];
Tc_error_8  = [ 4.053306e+000 ; 3.581444e+000 ; 3.776237e+000 ];

%-- Image #9:
omc_9 = [ 1.778778e+000 ; 1.810336e+000 ; -8.559132e-001 ];
Tc_9  = [ -4.764015e+001 ; -1.685510e+001 ; 2.664766e+002 ];
omc_error_9 = [ 6.026208e-003 ; 7.413006e-003 ; 1.183205e-002 ];
Tc_error_9  = [ 2.540992e+000 ; 2.286526e+000 ; 2.206693e+000 ];

%-- Image #10:
omc_10 = [ 1.665805e+000 ; 1.910093e+000 ; -1.080070e+000 ];
Tc_10  = [ 3.644690e+001 ; -4.059429e+000 ; 4.917663e+002 ];
omc_error_10 = [ 7.170970e-003 ; 8.520761e-003 ; 1.273410e-002 ];
Tc_error_10  = [ 4.728599e+000 ; 4.249730e+000 ; 4.002681e+000 ];

%-- Image #11:
omc_11 = [ 1.876012e+000 ; 1.773264e+000 ; -9.518400e-001 ];
Tc_11  = [ -4.162488e+001 ; -4.473881e+001 ; 4.016921e+002 ];
omc_error_11 = [ 6.693973e-003 ; 8.434445e-003 ; 1.268002e-002 ];
Tc_error_11  = [ 3.855338e+000 ; 3.456868e+000 ; 3.335426e+000 ];

%-- Image #12:
omc_12 = [ -2.242590e+000 ; -1.748882e+000 ; 2.644646e-001 ];
Tc_12  = [ -5.261634e+001 ; -5.145689e+001 ; 3.230662e+002 ];
omc_error_12 = [ 8.193531e-003 ; 6.409931e-003 ; 1.529040e-002 ];
Tc_error_12  = [ 3.089137e+000 ; 2.770812e+000 ; 2.853759e+000 ];

%-- Image #13:
omc_13 = [ -2.389104e+000 ; -1.773870e+000 ; 2.473512e-001 ];
Tc_13  = [ -9.753382e+001 ; -2.601800e+001 ; 3.015957e+002 ];
omc_error_13 = [ 8.439840e-003 ; 5.722749e-003 ; 1.482294e-002 ];
Tc_error_13  = [ 2.877230e+000 ; 2.614332e+000 ; 2.806192e+000 ];

%-- Image #14:
omc_14 = [ 1.718611e+000 ; 2.278528e+000 ; -1.044006e+000 ];
Tc_14  = [ -1.409239e+001 ; -3.893434e+001 ; 3.363758e+002 ];
omc_error_14 = [ 5.050474e-003 ; 8.615268e-003 ; 1.371094e-002 ];
Tc_error_14  = [ 3.223090e+000 ; 2.885980e+000 ; 2.729953e+000 ];

%-- Image #15:
omc_15 = [ -2.186898e+000 ; -2.062247e+000 ; 4.406385e-001 ];
Tc_15  = [ -7.127611e+001 ; -3.259649e+001 ; 2.587064e+002 ];
omc_error_15 = [ 7.364201e-003 ; 5.764122e-003 ; 1.231477e-002 ];
Tc_error_15  = [ 2.447671e+000 ; 2.221638e+000 ; 2.387732e+000 ];

%-- Image #16:
omc_16 = [ -2.218752e+000 ; -1.865426e+000 ; 1.097082e+000 ];
Tc_16  = [ -6.555623e+000 ; 1.261374e+001 ; 5.886389e+002 ];
omc_error_16 = [ 1.046081e-002 ; 6.308251e-003 ; 1.606980e-002 ];
Tc_error_16  = [ 5.682476e+000 ; 5.082253e+000 ; 4.944196e+000 ];

%-- Image #17:
omc_17 = [ 1.712987e+000 ; 1.741980e+000 ; -1.428433e+000 ];
Tc_17  = [ 3.590224e+001 ; 3.830254e+001 ; 6.289447e+002 ];
omc_error_17 = [ 7.902627e-003 ; 9.627378e-003 ; 1.263744e-002 ];
Tc_error_17  = [ 6.094010e+000 ; 5.446999e+000 ; 5.049489e+000 ];

%-- Image #18:
omc_18 = [ -2.231556e+000 ; -1.600919e+000 ; 6.005512e-001 ];
Tc_18  = [ -3.916131e+000 ; -2.707906e-001 ; 5.272706e+002 ];
omc_error_18 = [ 9.877013e-003 ; 7.651301e-003 ; 1.698495e-002 ];
Tc_error_18  = [ 5.085950e+000 ; 4.537732e+000 ; 4.512255e+000 ];

%-- Image #19:
omc_19 = [ -2.257301e+000 ; -2.012150e+000 ; 7.876561e-001 ];
Tc_19  = [ -1.045157e+002 ; -1.038122e+002 ; 5.742065e+002 ];
omc_error_19 = [ 1.055946e-002 ; 5.209303e-003 ; 1.636115e-002 ];
Tc_error_19  = [ 5.508649e+000 ; 4.976703e+000 ; 5.120296e+000 ];

%-- Image #20:
omc_20 = [ 2.212822e+000 ; 2.031392e+000 ; -7.015173e-001 ];
Tc_20  = [ -1.951505e+002 ; -1.321579e+002 ; 5.881271e+002 ];
omc_error_20 = [ 5.627246e-003 ; 1.046986e-002 ; 1.955835e-002 ];
Tc_error_20  = [ 5.746610e+000 ; 5.213966e+000 ; 5.972105e+000 ];

