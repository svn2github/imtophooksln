% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 717.308872338358580 ; 722.586214137136610 ];

%-- Principal point:
cc = [ 381.570664766891870 ; 238.486642682199030 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.007276786679099 ; -0.129530492974570 ; -0.001020941771863 ; -0.005620285772057 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 25.222848468458825 ; 26.827838215032305 ];

%-- Principal point uncertainty:
cc_error = [ 16.334828813426121 ; 7.972303597814225 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015704463003341 ; 0.043430936497235 ; 0.002403252436387 ; 0.003988571248973 ; 0.000000000000000 ];

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
omc_1 = [ 2.452663e+000 ; 1.820260e+000 ; 3.650232e-001 ];
Tc_1  = [ -1.611999e+002 ; 3.927298e+001 ; 3.210327e+002 ];
omc_error_1 = [ 1.594550e-002 ; 1.289851e-002 ; 3.146052e-002 ];
Tc_error_1  = [ 7.712713e+000 ; 3.678983e+000 ; 1.216416e+001 ];

%-- Image #2:
omc_2 = [ 2.150703e+000 ; 1.886741e+000 ; -1.045710e-001 ];
Tc_2  = [ -2.053030e+002 ; -1.253656e+002 ; 4.386702e+002 ];
omc_error_2 = [ 7.526684e-003 ; 1.394751e-002 ; 2.084224e-002 ];
Tc_error_2  = [ 1.036711e+001 ; 5.087045e+000 ; 1.571556e+001 ];

%-- Image #3:
omc_3 = [ 2.282862e+000 ; 1.908768e+000 ; -5.730563e-002 ];
Tc_3  = [ -1.638396e+002 ; -6.836665e+001 ; 4.264000e+002 ];
omc_error_3 = [ 1.073462e-002 ; 1.467035e-002 ; 2.563619e-002 ];
Tc_error_3  = [ 9.962717e+000 ; 4.817926e+000 ; 1.549061e+001 ];

%-- Image #4:
omc_4 = [ 2.072324e+000 ; 2.108854e+000 ; 6.265732e-001 ];
Tc_4  = [ -8.831403e+001 ; -2.483946e+000 ; 2.093407e+002 ];
omc_error_4 = [ 1.263460e-002 ; 9.940110e-003 ; 2.953048e-002 ];
Tc_error_4  = [ 4.967691e+000 ; 2.366619e+000 ; 7.843802e+000 ];

%-- Image #5:
omc_5 = [ 2.000819e+000 ; 2.169878e+000 ; 5.931410e-001 ];
Tc_5  = [ -4.786966e+001 ; -2.516747e+001 ; 2.161579e+002 ];
omc_error_5 = [ 1.259837e-002 ; 1.135466e-002 ; 2.987753e-002 ];
Tc_error_5  = [ 5.006234e+000 ; 2.396482e+000 ; 7.963597e+000 ];

%-- Image #6:
omc_6 = [ 2.035786e+000 ; 2.110974e+000 ; 4.199049e-001 ];
Tc_6  = [ -9.960979e+001 ; -6.199649e+001 ; 2.481981e+002 ];
omc_error_6 = [ 1.140901e-002 ; 1.544417e-002 ; 3.457545e-002 ];
Tc_error_6  = [ 5.902521e+000 ; 2.816718e+000 ; 9.070099e+000 ];

%-- Image #7:
omc_7 = [ 1.970963e+000 ; 2.108344e+000 ; 6.511535e-001 ];
Tc_7  = [ -1.503499e+001 ; -4.792172e+001 ; 1.915190e+002 ];
omc_error_7 = [ 1.285736e-002 ; 1.237545e-002 ; 2.943438e-002 ];
Tc_error_7  = [ 4.388202e+000 ; 2.103733e+000 ; 6.982209e+000 ];

%-- Image #8:
omc_8 = [ 1.981402e+000 ; 2.101546e+000 ; 7.233984e-001 ];
Tc_8  = [ -1.465288e+001 ; -2.477436e+001 ; 1.611632e+002 ];
omc_error_8 = [ 1.384563e-002 ; 1.144915e-002 ; 2.983624e-002 ];
Tc_error_8  = [ 3.686839e+000 ; 1.770364e+000 ; 5.957015e+000 ];

%-- Image #9:
omc_9 = [ 2.036511e+000 ; 2.101055e+000 ; 7.294800e-001 ];
Tc_9  = [ -3.248879e+001 ; -3.977255e+000 ; 1.566526e+002 ];
omc_error_9 = [ 1.366045e-002 ; 9.727031e-003 ; 3.011725e-002 ];
Tc_error_9  = [ 3.625834e+000 ; 1.729623e+000 ; 5.889722e+000 ];

%-- Image #10:
omc_10 = [ 2.040747e+000 ; 2.112814e+000 ; 7.151160e-001 ];
Tc_10  = [ -6.909950e+001 ; -1.602246e+001 ; 2.000941e+002 ];
omc_error_10 = [ 1.306365e-002 ; 1.019997e-002 ; 2.909080e-002 ];
Tc_error_10  = [ 4.709611e+000 ; 2.240498e+000 ; 7.533434e+000 ];

%-- Image #11:
omc_11 = [ 2.340852e+000 ; 1.795785e+000 ; -4.754936e-001 ];
Tc_11  = [ -2.834191e+002 ; 7.459168e+000 ; 7.103551e+002 ];
omc_error_11 = [ 1.075395e-002 ; 1.409103e-002 ; 2.678864e-002 ];
Tc_error_11  = [ 1.648927e+001 ; 8.044982e+000 ; 2.535600e+001 ];

%-- Image #12:
omc_12 = [ 2.064242e+000 ; 1.769757e+000 ; -5.120456e-001 ];
Tc_12  = [ -3.258949e+002 ; -1.212908e+002 ; 7.187315e+002 ];
omc_error_12 = [ 7.613073e-003 ; 1.406076e-002 ; 1.954120e-002 ];
Tc_error_12  = [ 1.681075e+001 ; 8.202612e+000 ; 2.558841e+001 ];

%-- Image #13:
omc_13 = [ 2.083320e+000 ; 1.958881e+000 ; 6.376975e-001 ];
Tc_13  = [ -4.887738e+001 ; -2.401908e+001 ; 1.317825e+002 ];
omc_error_13 = [ 1.181727e-002 ; 1.021051e-002 ; 2.876218e-002 ];
Tc_error_13  = [ 3.102000e+000 ; 1.476079e+000 ; 4.857386e+000 ];

%-- Image #14:
omc_14 = [ -1.993797e+000 ; -2.320455e+000 ; -8.912968e-002 ];
Tc_14  = [ -7.957587e+001 ; -8.293806e+001 ; 4.059507e+002 ];
omc_error_14 = [ 2.252786e-002 ; 2.162751e-002 ; 3.927139e-002 ];
Tc_error_14  = [ 9.338537e+000 ; 4.526859e+000 ; 1.491903e+001 ];

%-- Image #15:
omc_15 = [ 2.055278e+000 ; 2.268276e+000 ; 5.105177e-001 ];
Tc_15  = [ 4.267211e+001 ; -1.027267e+002 ; 3.305850e+002 ];
omc_error_15 = [ 1.381557e-002 ; 1.543598e-002 ; 3.426149e-002 ];
Tc_error_15  = [ 7.539880e+000 ; 3.612254e+000 ; 1.178358e+001 ];

%-- Image #16:
omc_16 = [ 2.091718e+000 ; 2.102454e+000 ; 7.204481e-001 ];
Tc_16  = [ 1.708692e+001 ; -1.352251e+001 ; 2.496948e+002 ];
omc_error_16 = [ 1.501686e-002 ; 1.058641e-002 ; 3.253444e-002 ];
Tc_error_16  = [ 5.668571e+000 ; 2.752443e+000 ; 9.066502e+000 ];

%-- Image #17:
omc_17 = [ 2.369586e+000 ; 1.863942e+000 ; 1.501169e-001 ];
Tc_17  = [ -1.769843e+002 ; 4.293074e+001 ; 4.180969e+002 ];
omc_error_17 = [ 1.940583e-002 ; 1.944152e-002 ; 3.926727e-002 ];
Tc_error_17  = [ 9.916606e+000 ; 4.729854e+000 ; 1.578701e+001 ];

%-- Image #18:
omc_18 = [ 2.181151e+000 ; 1.845789e+000 ; 1.588662e-001 ];
Tc_18  = [ -1.865292e+002 ; -7.852529e+001 ; 3.880922e+002 ];
omc_error_18 = [ 1.095855e-002 ; 1.584585e-002 ; 2.563594e-002 ];
Tc_error_18  = [ 9.239362e+000 ; 4.478219e+000 ; 1.419987e+001 ];

%-- Image #19:
omc_19 = [ 2.164013e+000 ; 2.135603e+000 ; 4.546503e-001 ];
Tc_19  = [ -1.386334e+002 ; -3.210411e+001 ; 2.916393e+002 ];
omc_error_19 = [ 1.408874e-002 ; 1.557579e-002 ; 3.473915e-002 ];
Tc_error_19  = [ 6.971152e+000 ; 3.352270e+000 ; 1.090935e+001 ];

%-- Image #20:
omc_20 = [ 2.088401e+000 ; 2.056748e+000 ; 5.202160e-001 ];
Tc_20  = [ -1.133021e+002 ; -5.651695e+001 ; 2.357723e+002 ];
omc_error_20 = [ 1.269937e-002 ; 1.551113e-002 ; 3.616425e-002 ];
Tc_error_20  = [ 5.618216e+000 ; 2.701399e+000 ; 8.508877e+000 ];

