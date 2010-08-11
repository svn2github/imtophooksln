% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 710.622926635008410 ; 710.657253604434350 ];

%-- Principal point:
cc = [ 315.853338520228190 ; 271.411512153294720 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.208175579404320 ; -0.639821465437853 ; 0.001966186049621 ; -0.001009502285897 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 4.768835174672690 ; 4.830474133454975 ];

%-- Principal point uncertainty:
cc_error = [ 7.157392315351319 ; 6.152014311937403 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.040376528817805 ; 0.258122475213850 ; 0.004117885242694 ; 0.004426060192018 ; 0.000000000000000 ];

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
omc_1 = [ -2.052305e+000 ; -1.773878e+000 ; 6.431079e-001 ];
Tc_1  = [ -4.231979e+001 ; -4.821774e+001 ; 3.236449e+002 ];
omc_error_1 = [ 9.658236e-003 ; 6.262918e-003 ; 1.376731e-002 ];
Tc_error_1  = [ 3.261793e+000 ; 2.786746e+000 ; 2.227899e+000 ];

%-- Image #2:
omc_2 = [ -2.059202e+000 ; -1.679759e+000 ; 8.521392e-001 ];
Tc_2  = [ -8.779824e+001 ; -5.912876e+001 ; 3.954448e+002 ];
omc_error_2 = [ 1.109384e-002 ; 5.709776e-003 ; 1.349324e-002 ];
Tc_error_2  = [ 4.016367e+000 ; 3.460954e+000 ; 2.804822e+000 ];

%-- Image #3:
omc_3 = [ -2.429417e+000 ; -1.889355e+000 ; 2.559510e-001 ];
Tc_3  = [ -8.069270e+001 ; -3.709722e+001 ; 2.760203e+002 ];
omc_error_3 = [ 1.012093e-002 ; 6.581500e-003 ; 1.815317e-002 ];
Tc_error_3  = [ 2.774824e+000 ; 2.407450e+000 ; 2.218973e+000 ];

%-- Image #4:
omc_4 = [ -1.940749e+000 ; -1.482614e+000 ; 8.145377e-001 ];
Tc_4  = [ -3.341414e+001 ; -1.998545e+001 ; 3.024468e+002 ];
omc_error_4 = [ 9.526932e-003 ; 6.212386e-003 ; 1.121278e-002 ];
Tc_error_4  = [ 3.029957e+000 ; 2.595905e+000 ; 1.890626e+000 ];

%-- Image #5:
omc_5 = [ -2.069199e+000 ; -2.003671e+000 ; 1.247770e+000 ];
Tc_5  = [ -3.778407e+001 ; -2.486991e+001 ; 2.929215e+002 ];
omc_error_5 = [ 1.148305e-002 ; 4.844446e-003 ; 1.302153e-002 ];
Tc_error_5  = [ 2.940375e+000 ; 2.520081e+000 ; 1.822877e+000 ];

%-- Image #6:
omc_6 = [ 1.854937e+000 ; 1.885668e+000 ; -1.254706e+000 ];
Tc_6  = [ -5.252858e+001 ; -2.080926e+001 ; 2.752209e+002 ];
omc_error_6 = [ 5.322758e-003 ; 1.038147e-002 ; 1.264932e-002 ];
Tc_error_6  = [ 2.760287e+000 ; 2.391571e+000 ; 1.738295e+000 ];

%-- Image #7:
omc_7 = [ -2.012813e+000 ; -1.321849e+000 ; 4.329724e-002 ];
Tc_7  = [ -7.358929e+001 ; -2.339380e+001 ; 2.637432e+002 ];
omc_error_7 = [ 8.390008e-003 ; 7.177112e-003 ; 1.152082e-002 ];
Tc_error_7  = [ 2.645948e+000 ; 2.284884e+000 ; 2.024974e+000 ];

%-- Image #8:
omc_8 = [ -2.034410e+000 ; -1.660932e+000 ; 7.551703e-001 ];
Tc_8  = [ -3.713216e+001 ; -3.786453e+001 ; 3.090501e+002 ];
omc_error_8 = [ 9.660031e-003 ; 5.811957e-003 ; 1.264279e-002 ];
Tc_error_8  = [ 3.109767e+000 ; 2.655351e+000 ; 2.032862e+000 ];

%-- Image #9:
omc_9 = [ 2.314731e+000 ; 1.901510e+000 ; 1.218522e-001 ];
Tc_9  = [ -8.616711e+001 ; -4.767739e+001 ; 2.421316e+002 ];
omc_error_9 = [ 9.236880e-003 ; 8.711104e-003 ; 1.864865e-002 ];
Tc_error_9  = [ 2.466051e+000 ; 2.145854e+000 ; 2.199938e+000 ];

%-- Image #10:
omc_10 = [ -2.054687e+000 ; -1.677171e+000 ; -4.021563e-001 ];
Tc_10  = [ -8.085357e+001 ; -5.146894e+001 ; 2.548648e+002 ];
omc_error_10 = [ 8.002660e-003 ; 8.226525e-003 ; 1.349636e-002 ];
Tc_error_10  = [ 2.595108e+000 ; 2.249529e+000 ; 2.252324e+000 ];

%-- Image #11:
omc_11 = [ 2.078488e+000 ; 2.136693e+000 ; -8.417032e-001 ];
Tc_11  = [ -4.573290e+001 ; -5.422044e+001 ; 3.132105e+002 ];
omc_error_11 = [ 5.825812e-003 ; 9.718544e-003 ; 1.503425e-002 ];
Tc_error_11  = [ 3.160558e+000 ; 2.695849e+000 ; 2.162934e+000 ];

%-- Image #12:
omc_12 = [ -2.170254e+000 ; -1.770532e+000 ; 2.819929e-001 ];
Tc_12  = [ -1.798082e+001 ; -7.485395e+001 ; 4.186735e+002 ];
omc_error_12 = [ 1.299161e-002 ; 1.099512e-002 ; 2.439507e-002 ];
Tc_error_12  = [ 4.250875e+000 ; 3.613940e+000 ; 3.143962e+000 ];

%-- Image #13:
omc_13 = [ -1.942110e+000 ; -1.660174e+000 ; 5.392011e-001 ];
Tc_13  = [ -1.264271e+001 ; -6.197744e+001 ; 3.905527e+002 ];
omc_error_13 = [ 9.472305e-003 ; 7.309329e-003 ; 1.423883e-002 ];
Tc_error_13  = [ 3.953363e+000 ; 3.364266e+000 ; 2.713641e+000 ];

%-- Image #14:
omc_14 = [ 2.294679e+000 ; 1.991056e+000 ; 3.005969e-001 ];
Tc_14  = [ -4.476025e+001 ; -6.276355e+001 ; 2.894102e+002 ];
omc_error_14 = [ 1.090616e-002 ; 8.959965e-003 ; 1.894167e-002 ];
Tc_error_14  = [ 2.956909e+000 ; 2.511740e+000 ; 2.441160e+000 ];

%-- Image #15:
omc_15 = [ 2.081859e+000 ; 2.009574e+000 ; -8.853304e-001 ];
Tc_15  = [ -4.061699e+001 ; -5.261451e+001 ; 3.836766e+002 ];
omc_error_15 = [ 6.754094e-003 ; 1.003377e-002 ; 1.539368e-002 ];
Tc_error_15  = [ 3.870758e+000 ; 3.305129e+000 ; 2.649626e+000 ];

%-- Image #16:
omc_16 = [ -1.868392e+000 ; -1.205174e+000 ; -3.040647e-001 ];
Tc_16  = [ -3.548946e+001 ; -4.706008e+001 ; 3.507272e+002 ];
omc_error_16 = [ 7.945203e-003 ; 8.553924e-003 ; 1.130647e-002 ];
Tc_error_16  = [ 3.545740e+000 ; 3.013986e+000 ; 2.739408e+000 ];

%-- Image #17:
omc_17 = [ -2.425451e+000 ; -1.941905e+000 ; 3.014743e-001 ];
Tc_17  = [ -3.034131e+001 ; -1.090511e+002 ; 5.036773e+002 ];
omc_error_17 = [ 1.730400e-002 ; 1.143597e-002 ; 2.957078e-002 ];
Tc_error_17  = [ 5.142624e+000 ; 4.365392e+000 ; 3.935004e+000 ];

%-- Image #18:
omc_18 = [ -2.083601e+000 ; -1.749723e+000 ; 6.248297e-001 ];
Tc_18  = [ -2.684116e+001 ; -1.016455e+002 ; 4.823550e+002 ];
omc_error_18 = [ 1.196363e-002 ; 7.479356e-003 ; 1.708096e-002 ];
Tc_error_18  = [ 4.921887e+000 ; 4.163830e+000 ; 3.552608e+000 ];

%-- Image #19:
omc_19 = [ 2.388722e+000 ; 1.764352e+000 ; 1.818208e-001 ];
Tc_19  = [ -5.234756e+001 ; -5.713276e+001 ; 3.519892e+002 ];
omc_error_19 = [ 1.193884e-002 ; 9.340270e-003 ; 2.165195e-002 ];
Tc_error_19  = [ 3.575007e+000 ; 3.053465e+000 ; 2.975651e+000 ];

%-- Image #20:
omc_20 = [ NaN ; NaN ; NaN ];
Tc_20  = [ NaN ; NaN ; NaN ];
omc_error_20 = [ NaN ; NaN ; NaN ];
Tc_error_20  = [ NaN ; NaN ; NaN ];

