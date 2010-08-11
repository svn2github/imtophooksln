% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 537.555549320468340 ; 542.094837681433320 ];

%-- Principal point:
cc = [ 311.083092663548090 ; 227.534463302156440 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.069640328870162 ; -0.122910176608287 ; -0.008652971244577 ; -0.002684096609600 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 7.610992601513528 ; 6.635558814576005 ];

%-- Principal point uncertainty:
cc_error = [ 5.298106105168031 ; 6.270260006277380 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.016316092643461 ; 0.040117751028778 ; 0.002829164632899 ; 0.003325927335383 ; 0.000000000000000 ];

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
omc_1 = [ 1.835520e+000 ; 2.303850e+000 ; -4.359612e-001 ];
Tc_1  = [ 8.462773e+000 ; -1.673292e+002 ; 4.459479e+002 ];
omc_error_1 = [ 6.784650e-003 ; 9.640536e-003 ; 1.466382e-002 ];
Tc_error_1  = [ 4.507123e+000 ; 4.881751e+000 ; 6.087493e+000 ];

%-- Image #2:
omc_2 = [ 1.865781e+000 ; 2.214437e+000 ; -4.547322e-001 ];
Tc_2  = [ 2.610721e+001 ; -8.124527e+001 ; 4.773476e+002 ];
omc_error_2 = [ 7.419525e-003 ; 8.428534e-003 ; 1.575908e-002 ];
Tc_error_2  = [ 4.710163e+000 ; 5.365888e+000 ; 6.362227e+000 ];

%-- Image #3:
omc_3 = [ 2.026821e+000 ; 2.194329e+000 ; -3.710506e-001 ];
Tc_3  = [ 9.140404e+000 ; 1.110308e+001 ; 4.803647e+002 ];
omc_error_3 = [ 1.046087e-002 ; 8.306285e-003 ; 2.254862e-002 ];
Tc_error_3  = [ 4.764312e+000 ; 5.584281e+000 ; 6.656135e+000 ];

%-- Image #4:
omc_4 = [ 1.981217e+000 ; 2.348921e+000 ; -5.811913e-001 ];
Tc_4  = [ 1.406544e+002 ; -3.871533e+001 ; 7.093367e+002 ];
omc_error_4 = [ 1.439164e-002 ; 1.162740e-002 ; 2.877370e-002 ];
Tc_error_4  = [ 7.043960e+000 ; 8.166482e+000 ; 9.609150e+000 ];

%-- Image #5:
omc_5 = [ -1.936262e+000 ; -2.320334e+000 ; 4.999964e-001 ];
Tc_5  = [ 1.125940e+001 ; -5.296231e+001 ; 7.126888e+002 ];
omc_error_5 = [ 1.216575e-002 ; 1.655453e-002 ; 3.008543e-002 ];
Tc_error_5  = [ 7.002708e+000 ; 8.185181e+000 ; 9.536943e+000 ];

%-- Image #6:
omc_6 = [ -1.845660e+000 ; -2.353237e+000 ; 6.039878e-001 ];
Tc_6  = [ -7.488396e+001 ; -2.452453e+002 ; 6.830579e+002 ];
omc_error_6 = [ 1.083913e-002 ; 8.607771e-003 ; 1.845396e-002 ];
Tc_error_6  = [ 6.882419e+000 ; 7.699285e+000 ; 9.012637e+000 ];

%-- Image #7:
omc_7 = [ -2.109191e+000 ; -2.130974e+000 ; 6.705600e-001 ];
Tc_7  = [ 2.122442e+001 ; 9.369353e+001 ; 7.649274e+002 ];
omc_error_7 = [ 1.278839e-002 ; 1.788547e-002 ; 3.265488e-002 ];
Tc_error_7  = [ 7.558099e+000 ; 8.969497e+000 ; 9.916869e+000 ];

%-- Image #8:
omc_8 = [ -1.889095e+000 ; -2.037138e+000 ; 7.569027e-001 ];
Tc_8  = [ -1.922464e+002 ; -1.130763e+000 ; 7.887203e+002 ];
omc_error_8 = [ 9.788623e-003 ; 9.653225e-003 ; 1.724865e-002 ];
Tc_error_8  = [ 7.850318e+000 ; 9.150721e+000 ; 1.029243e+001 ];

%-- Image #9:
omc_9 = [ -1.945146e+000 ; -2.020615e+000 ; 7.787519e-001 ];
Tc_9  = [ -3.393123e+002 ; -4.994642e+001 ; 7.555783e+002 ];
omc_error_9 = [ 1.061260e-002 ; 9.551044e-003 ; 1.648570e-002 ];
Tc_error_9  = [ 7.809884e+000 ; 8.856032e+000 ; 1.025044e+001 ];

%-- Image #10:
omc_10 = [ -1.963334e+000 ; -1.936596e+000 ; 8.680409e-001 ];
Tc_10  = [ -3.039863e+002 ; 7.974472e+001 ; 8.551160e+002 ];
omc_error_10 = [ 1.026551e-002 ; 9.971931e-003 ; 1.617108e-002 ];
Tc_error_10  = [ 8.724000e+000 ; 1.006487e+001 ; 1.154411e+001 ];

%-- Image #11:
omc_11 = [ -2.221320e+000 ; -2.012065e+000 ; 6.758712e-001 ];
Tc_11  = [ -1.778330e+002 ; 1.335182e+002 ; 7.474357e+002 ];
omc_error_11 = [ 1.041507e-002 ; 1.090045e-002 ; 2.137074e-002 ];
Tc_error_11  = [ 7.509430e+000 ; 8.877883e+000 ; 1.005752e+001 ];

%-- Image #12:
omc_12 = [ 2.099378e+000 ; 1.930941e+000 ; -3.152340e-001 ];
Tc_12  = [ -3.160340e+002 ; -2.109762e+002 ; 6.516808e+002 ];
omc_error_12 = [ 6.051613e-003 ; 1.150925e-002 ; 1.940926e-002 ];
Tc_error_12  = [ 6.675843e+000 ; 7.399649e+000 ; 1.034271e+001 ];

%-- Image #13:
omc_13 = [ 2.087488e+000 ; 1.847329e+000 ; -4.256901e-001 ];
Tc_13  = [ -1.483355e+002 ; -1.730755e+002 ; 6.069197e+002 ];
omc_error_13 = [ 7.145519e-003 ; 9.726600e-003 ; 1.545733e-002 ];
Tc_error_13  = [ 6.059051e+000 ; 6.741815e+000 ; 8.723017e+000 ];

%-- Image #14:
omc_14 = [ 2.101200e+000 ; 2.033045e+000 ; -9.338159e-001 ];
Tc_14  = [ 1.604378e+002 ; -2.274611e+001 ; 1.258585e+003 ];
omc_error_14 = [ 1.539889e-002 ; 1.437581e-002 ; 2.761196e-002 ];
Tc_error_14  = [ 1.251628e+001 ; 1.456827e+001 ; 1.605951e+001 ];

%-- Image #15:
omc_15 = [ 2.098136e+000 ; 1.563911e+000 ; -3.032023e-002 ];
Tc_15  = [ -7.139879e+001 ; -7.301608e+001 ; 2.746436e+002 ];
omc_error_15 = [ 9.120423e-003 ; 6.526805e-003 ; 1.160275e-002 ];
Tc_error_15  = [ 2.744631e+000 ; 3.044101e+000 ; 3.829874e+000 ];

%-- Image #16:
omc_16 = [ -2.154220e+000 ; -2.075760e+000 ; 7.667423e-001 ];
Tc_16  = [ -6.935854e+001 ; -8.461062e+001 ; 3.905619e+002 ];
omc_error_16 = [ 8.982488e-003 ; 6.316909e-003 ; 1.638350e-002 ];
Tc_error_16  = [ 3.824817e+000 ; 4.392005e+000 ; 4.894743e+000 ];

%-- Image #17:
omc_17 = [ -2.041454e+000 ; -1.820781e+000 ; -4.204374e-001 ];
Tc_17  = [ -1.284986e+001 ; -2.080507e+001 ; 6.741241e+002 ];
omc_error_17 = [ 1.044762e-002 ; 1.329216e-002 ; 1.820765e-002 ];
Tc_error_17  = [ 6.679154e+000 ; 7.758824e+000 ; 9.636183e+000 ];

%-- Image #18:
omc_18 = [ 2.093508e+000 ; 1.428162e+000 ; -6.584586e-001 ];
Tc_18  = [ -2.456028e+001 ; 4.978196e+001 ; 5.842687e+002 ];
omc_error_18 = [ 9.165787e-003 ; 8.123379e-003 ; 1.351411e-002 ];
Tc_error_18  = [ 5.770340e+000 ; 6.818951e+000 ; 7.594931e+000 ];

%-- Image #19:
omc_19 = [ 1.918643e+000 ; 1.466916e+000 ; 3.358185e-001 ];
Tc_19  = [ -1.275122e+002 ; -3.032492e+001 ; 5.156380e+002 ];
omc_error_19 = [ 1.104999e-002 ; 7.252524e-003 ; 1.337240e-002 ];
Tc_error_19  = [ 5.148502e+000 ; 5.968993e+000 ; 7.440689e+000 ];

%-- Image #20:
omc_20 = [ 2.161386e+000 ; 1.614794e+000 ; 1.698718e-001 ];
Tc_20  = [ -2.417477e+002 ; 4.490623e+001 ; 5.049065e+002 ];
omc_error_20 = [ 1.363807e-002 ; 1.113277e-002 ; 2.161007e-002 ];
Tc_error_20  = [ 5.277239e+000 ; 6.026998e+000 ; 7.350491e+000 ];

