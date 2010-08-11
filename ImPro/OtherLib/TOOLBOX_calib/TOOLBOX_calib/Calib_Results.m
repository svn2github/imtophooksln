% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 711.380275939985270 ; 710.716225182435550 ];

%-- Principal point:
cc = [ 318.750355249874470 ; 255.744363112849070 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.265935580393316 ; -0.950105735045037 ; -0.005028614444631 ; 0.001620192730829 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 7.627863822790125 ; 7.401967541251083 ];

%-- Principal point uncertainty:
cc_error = [ 4.559168247296125 ; 4.744131313839727 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.031705027004020 ; 0.184035400770538 ; 0.003044808133671 ; 0.002749530701013 ; 0.000000000000000 ];

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
omc_1 = [ -2.309782e+000 ; -1.908497e+000 ; 4.881680e-001 ];
Tc_1  = [ -5.808452e+001 ; -1.871109e+001 ; 2.873642e+002 ];
omc_error_1 = [ 6.287619e-003 ; 4.824794e-003 ; 1.238775e-002 ];
Tc_error_1  = [ 1.809996e+000 ; 1.904566e+000 ; 2.971826e+000 ];

%-- Image #2:
omc_2 = [ -2.261028e+000 ; -1.858642e+000 ; 3.474077e-001 ];
Tc_2  = [ -7.418178e+001 ; -2.775947e+001 ; 2.481907e+002 ];
omc_error_2 = [ 5.954241e-003 ; 4.414480e-003 ; 1.110365e-002 ];
Tc_error_2  = [ 1.563294e+000 ; 1.657019e+000 ; 2.640243e+000 ];

%-- Image #3:
omc_3 = [ 2.144241e+000 ; 1.758339e+000 ; 2.462035e-001 ];
Tc_3  = [ -1.162402e+002 ; -2.115179e+001 ; 4.976727e+002 ];
omc_error_3 = [ 1.077272e-002 ; 9.998597e-003 ; 2.119025e-002 ];
Tc_error_3  = [ 3.209804e+000 ; 3.354653e+000 ; 5.856569e+000 ];

%-- Image #4:
omc_4 = [ 2.074394e+000 ; 1.709871e+000 ; 4.054170e-001 ];
Tc_4  = [ -1.276012e+002 ; -3.225806e+001 ; 6.140462e+002 ];
omc_error_4 = [ 1.060816e-002 ; 9.855685e-003 ; 1.983526e-002 ];
Tc_error_4  = [ 3.963705e+000 ; 4.131075e+000 ; 7.431120e+000 ];

%-- Image #5:
omc_5 = [ 1.991557e+000 ; 2.194710e+000 ; 8.155621e-001 ];
Tc_5  = [ -6.180909e+001 ; -6.071672e+001 ; 5.648737e+002 ];
omc_error_5 = [ 9.620768e-003 ; 8.891649e-003 ; 1.772307e-002 ];
Tc_error_5  = [ 3.625499e+000 ; 3.780745e+000 ; 6.957149e+000 ];

%-- Image #6:
omc_6 = [ 2.255577e+000 ; 1.587263e+000 ; -2.692251e-001 ];
Tc_6  = [ -7.987731e+001 ; -4.482685e+001 ; 4.951404e+002 ];
omc_error_6 = [ 8.098631e-003 ; 7.319782e-003 ; 1.453875e-002 ];
Tc_error_6  = [ 3.168734e+000 ; 3.307599e+000 ; 5.505181e+000 ];

%-- Image #7:
omc_7 = [ 2.261774e+000 ; 1.531158e+000 ; -6.962105e-001 ];
Tc_7  = [ -6.426475e+001 ; -2.835359e+001 ; 3.997759e+002 ];
omc_error_7 = [ 6.329363e-003 ; 6.268096e-003 ; 1.076744e-002 ];
Tc_error_7  = [ 2.543927e+000 ; 2.670033e+000 ; 4.152202e+000 ];

%-- Image #8:
omc_8 = [ 2.171602e+000 ; 1.533317e+000 ; -1.027675e+000 ];
Tc_8  = [ -5.598956e+001 ; -8.972352e+000 ; 3.238175e+002 ];
omc_error_8 = [ 5.425640e-003 ; 6.329313e-003 ; 9.383572e-003 ];
Tc_error_8  = [ 2.055455e+000 ; 2.160381e+000 ; 3.080899e+000 ];

%-- Image #9:
omc_9 = [ -2.295538e+000 ; -1.924082e+000 ; 3.226171e-001 ];
Tc_9  = [ -6.212612e+001 ; -3.707332e+001 ; 2.714818e+002 ];
omc_error_9 = [ 6.418752e-003 ; 5.015654e-003 ; 1.243020e-002 ];
Tc_error_9  = [ 1.714422e+000 ; 1.802110e+000 ; 2.921349e+000 ];

%-- Image #10:
omc_10 = [ -1.827120e+000 ; -1.852388e+000 ; 3.637170e-001 ];
Tc_10  = [ -7.387200e+000 ; -5.013147e+001 ; 3.434555e+002 ];
omc_error_10 = [ 5.896201e-003 ; 6.335008e-003 ; 1.111659e-002 ];
Tc_error_10  = [ 2.195190e+000 ; 2.269858e+000 ; 3.528221e+000 ];

%-- Image #11:
omc_11 = [ 2.255682e+000 ; 1.737411e+000 ; 2.316274e-001 ];
Tc_11  = [ -9.996148e+001 ; -1.802319e+001 ; 3.220810e+002 ];
omc_error_11 = [ 8.356735e-003 ; 7.002571e-003 ; 1.640730e-002 ];
Tc_error_11  = [ 2.088021e+000 ; 2.185316e+000 ; 3.710535e+000 ];

%-- Image #12:
omc_12 = [ 1.939796e+000 ; 1.755358e+000 ; 9.112401e-001 ];
Tc_12  = [ -1.251983e+002 ; -7.027961e+001 ; 6.865408e+002 ];
omc_error_12 = [ 9.695115e-003 ; 8.565703e-003 ; 1.597224e-002 ];
Tc_error_12  = [ 4.437170e+000 ; 4.614915e+000 ; 8.626749e+000 ];

%-- Image #13:
omc_13 = [ 2.339219e+000 ; 1.576877e+000 ; 1.300578e-001 ];
Tc_13  = [ -1.052265e+002 ; -7.854560e+001 ; 6.166072e+002 ];
omc_error_13 = [ 1.141954e-002 ; 1.003525e-002 ; 2.215836e-002 ];
Tc_error_13  = [ 3.978997e+000 ; 4.137502e+000 ; 7.219137e+000 ];

%-- Image #14:
omc_14 = [ 2.287891e+000 ; 1.216249e+000 ; -5.822422e-001 ];
Tc_14  = [ -1.124898e+002 ; -1.970315e+001 ; 6.317860e+002 ];
omc_error_14 = [ 8.127168e-003 ; 7.213081e-003 ; 1.284237e-002 ];
Tc_error_14  = [ 4.043998e+000 ; 4.241227e+000 ; 6.978321e+000 ];

%-- Image #15:
omc_15 = [ 2.035858e+000 ; 1.299843e+000 ; -7.968411e-001 ];
Tc_15  = [ -8.513198e+001 ; -5.081448e+000 ; 6.339732e+002 ];
omc_error_15 = [ 7.255597e-003 ; 7.281495e-003 ; 1.100010e-002 ];
Tc_error_15  = [ 4.054287e+000 ; 4.248243e+000 ; 6.832212e+000 ];

%-- Image #16:
omc_16 = [ -2.262411e+000 ; -2.077693e+000 ; 2.016689e-001 ];
Tc_16  = [ -8.395742e+001 ; -3.454521e+001 ; 2.319040e+002 ];
omc_error_16 = [ 6.440933e-003 ; 5.245312e-003 ; 1.262836e-002 ];
Tc_error_16  = [ 1.473130e+000 ; 1.573774e+000 ; 2.649527e+000 ];

%-- Image #17:
omc_17 = [ -2.291732e+000 ; -2.084060e+000 ; 1.645263e-001 ];
Tc_17  = [ -6.137881e+001 ; -3.213333e+001 ; 2.317925e+002 ];
omc_error_17 = [ 5.894373e-003 ; 5.412998e-003 ; 1.251871e-002 ];
Tc_error_17  = [ 1.477422e+000 ; 1.548978e+000 ; 2.581633e+000 ];

%-- Image #18:
omc_18 = [ 1.350258e+000 ; 2.431554e+000 ; -3.897888e-001 ];
Tc_18  = [ -4.509077e+000 ; -7.150989e+001 ; 3.172754e+002 ];
omc_error_18 = [ 4.132620e-003 ; 6.962577e-003 ; 1.089623e-002 ];
Tc_error_18  = [ 2.022968e+000 ; 2.102212e+000 ; 3.329383e+000 ];

%-- Image #19:
omc_19 = [ 2.653778e+000 ; 1.303134e+000 ; 1.363296e-001 ];
Tc_19  = [ -1.259899e+002 ; 4.171229e-001 ; 2.979197e+002 ];
omc_error_19 = [ 9.923467e-003 ; 6.646045e-003 ; 1.936359e-002 ];
Tc_error_19  = [ 1.912539e+000 ; 2.058957e+000 ; 3.563572e+000 ];

%-- Image #20:
omc_20 = [ 2.177629e+000 ; 1.637933e+000 ; 4.239540e-001 ];
Tc_20  = [ -1.387053e+002 ; -4.853852e+001 ; 4.166887e+002 ];
omc_error_20 = [ 8.787342e-003 ; 8.032259e-003 ; 1.698721e-002 ];
Tc_error_20  = [ 2.714656e+000 ; 2.841515e+000 ; 5.026440e+000 ];

