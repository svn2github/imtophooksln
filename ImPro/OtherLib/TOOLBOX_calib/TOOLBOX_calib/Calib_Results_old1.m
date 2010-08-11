% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 520.677495523409900 ; 519.048286698750990 ];

%-- Principal point:
cc = [ 323.493850983679470 ; 236.001254717401200 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.022042693628691 ; -0.147193075004376 ; 0.001403659943644 ; -0.000502820242620 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 11.532165534573615 ; 11.728124623113624 ];

%-- Principal point uncertainty:
cc_error = [ 6.881362452728473 ; 6.338863551756425 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.019430432518090 ; 0.037975665785617 ; 0.003061100173772 ; 0.003717131457463 ; 0.000000000000000 ];

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
omc_1 = [ 1.753933e+000 ; 2.376008e+000 ; 3.210880e-001 ];
Tc_1  = [ -1.495895e+001 ; -1.572724e+001 ; 2.557869e+002 ];
omc_error_1 = [ 1.089229e-002 ; 1.097605e-002 ; 1.986656e-002 ];
Tc_error_1  = [ 3.394988e+000 ; 3.130156e+000 ; 5.940693e+000 ];

%-- Image #2:
omc_2 = [ 1.845825e+000 ; 2.439224e+000 ; 6.173140e-002 ];
Tc_2  = [ 8.979303e+001 ; -4.901836e+001 ; 3.211494e+002 ];
omc_error_2 = [ 1.471123e-002 ; 1.676727e-002 ; 2.692118e-002 ];
Tc_error_2  = [ 4.218994e+000 ; 3.986588e+000 ; 7.445314e+000 ];

%-- Image #3:
omc_3 = [ 1.781366e+000 ; 2.403572e+000 ; -1.638301e-001 ];
Tc_3  = [ 6.312927e+001 ; -1.152241e+002 ; 3.500408e+002 ];
omc_error_3 = [ 1.102375e-002 ; 1.676654e-002 ; 2.494867e-002 ];
Tc_error_3  = [ 4.709795e+000 ; 4.369719e+000 ; 7.942629e+000 ];

%-- Image #4:
omc_4 = [ 1.730387e+000 ; 2.535775e+000 ; -1.775038e-001 ];
Tc_4  = [ 1.329701e+002 ; -1.183273e+002 ; 3.838371e+002 ];
omc_error_4 = [ 1.364612e-002 ; 2.121309e-002 ; 3.163877e-002 ];
Tc_error_4  = [ 5.213738e+000 ; 4.902456e+000 ; 8.849946e+000 ];

%-- Image #5:
omc_5 = [ 1.934164e+000 ; 2.187501e+000 ; 2.005832e-001 ];
Tc_5  = [ -2.563019e+001 ; -5.294567e+001 ; 2.782147e+002 ];
omc_error_5 = [ 1.086595e-002 ; 1.192153e-002 ; 2.093810e-002 ];
Tc_error_5  = [ 3.719126e+000 ; 3.405096e+000 ; 6.555503e+000 ];

%-- Image #6:
omc_6 = [ 1.950378e+000 ; 2.247810e+000 ; 4.266714e-001 ];
Tc_6  = [ -1.969037e+001 ; -9.690726e+001 ; 2.596417e+002 ];
omc_error_6 = [ 1.085708e-002 ; 1.262474e-002 ; 2.045543e-002 ];
Tc_error_6  = [ 3.516171e+000 ; 3.233610e+000 ; 6.352201e+000 ];

%-- Image #7:
omc_7 = [ 1.944816e+000 ; 2.163424e+000 ; 4.781625e-001 ];
Tc_7  = [ -1.000912e+002 ; -7.085924e+001 ; 2.152668e+002 ];
omc_error_7 = [ 1.001781e-002 ; 1.432848e-002 ; 2.611846e-002 ];
Tc_error_7  = [ 3.018503e+000 ; 2.771899e+000 ; 5.408244e+000 ];

%-- Image #8:
omc_8 = [ 1.961636e+000 ; 2.191931e+000 ; 5.347474e-001 ];
Tc_8  = [ -1.069623e+002 ; -3.437655e+001 ; 2.136203e+002 ];
omc_error_8 = [ 1.109624e-002 ; 1.219227e-002 ; 2.359637e-002 ];
Tc_error_8  = [ 2.975063e+000 ; 2.773518e+000 ; 5.351205e+000 ];

%-- Image #9:
omc_9 = [ 1.992757e+000 ; 2.142450e+000 ; 5.888346e-001 ];
Tc_9  = [ -8.048719e+001 ; 1.636209e+001 ; 2.164766e+002 ];
omc_error_9 = [ 1.191764e-002 ; 8.437408e-003 ; 1.755618e-002 ];
Tc_error_9  = [ 2.996169e+000 ; 2.730543e+000 ; 5.328992e+000 ];

%-- Image #10:
omc_10 = [ 2.031567e+000 ; 2.197135e+000 ; 5.107706e-001 ];
Tc_10  = [ -2.555788e+001 ; 3.707795e+001 ; 2.306930e+002 ];
omc_error_10 = [ 1.226980e-002 ; 6.683797e-003 ; 2.008698e-002 ];
Tc_error_10  = [ 3.080017e+000 ; 2.858391e+000 ; 5.448210e+000 ];

%-- Image #11:
omc_11 = [ 2.046116e+000 ; 2.262756e+000 ; 3.286922e-001 ];
Tc_11  = [ 7.199893e+001 ; 3.428397e+001 ; 2.458655e+002 ];
omc_error_11 = [ 1.674172e-002 ; 9.568452e-003 ; 2.930582e-002 ];
Tc_error_11  = [ 3.231201e+000 ; 3.088657e+000 ; 5.631032e+000 ];

%-- Image #12:
omc_12 = [ 2.030050e+000 ; 2.175210e+000 ; 2.148259e-001 ];
Tc_12  = [ 4.315958e+001 ; 5.204809e+000 ; 2.712366e+002 ];
omc_error_12 = [ 1.370713e-002 ; 9.714611e-003 ; 2.480341e-002 ];
Tc_error_12  = [ 3.545364e+000 ; 3.333120e+000 ; 6.162903e+000 ];

%-- Image #13:
omc_13 = [ 1.948198e+000 ; 2.110020e+000 ; 7.960368e-002 ];
Tc_13  = [ 9.994814e+000 ; -4.928429e+001 ; 2.835708e+002 ];
omc_error_13 = [ 1.115728e-002 ; 1.135662e-002 ; 2.048544e-002 ];
Tc_error_13  = [ 3.753463e+000 ; 3.457643e+000 ; 6.455617e+000 ];

%-- Image #14:
omc_14 = [ 2.121070e+000 ; 2.167589e+000 ; 2.006291e-001 ];
Tc_14  = [ -1.179126e+002 ; -3.001866e+001 ; 4.400140e+002 ];
omc_error_14 = [ 3.147616e-002 ; 3.960459e-002 ; 7.771135e-002 ];
Tc_error_14  = [ 6.011729e+000 ; 5.459220e+000 ; 1.082750e+001 ];

%-- Image #15:
omc_15 = [ 1.869176e+000 ; 1.671255e+000 ; -9.074932e-003 ];
Tc_15  = [ -9.186113e+001 ; 3.096629e+001 ; 3.553680e+002 ];
omc_error_15 = [ 1.222074e-002 ; 1.233510e-002 ; 2.048756e-002 ];
Tc_error_15  = [ 4.724332e+000 ; 4.420328e+000 ; 7.979642e+000 ];

%-- Image #16:
omc_16 = [ 1.894472e+000 ; 1.748525e+000 ; -4.304763e-001 ];
Tc_16  = [ -1.037137e+002 ; -5.872336e+000 ; 4.795752e+002 ];
omc_error_16 = [ 1.054270e-002 ; 1.373033e-002 ; 1.937767e-002 ];
Tc_error_16  = [ 6.391363e+000 ; 5.909130e+000 ; 1.091723e+001 ];

%-- Image #17:
omc_17 = [ 1.821796e+000 ; 2.081059e+000 ; -4.807907e-001 ];
Tc_17  = [ -1.231377e+001 ; -9.812692e+000 ; 4.239733e+002 ];
omc_error_17 = [ 1.162377e-002 ; 1.585431e-002 ; 2.195315e-002 ];
Tc_error_17  = [ 5.595154e+000 ; 5.177325e+000 ; 8.688047e+000 ];

%-- Image #18:
omc_18 = [ 1.904281e+000 ; 1.787387e+000 ; -5.446484e-001 ];
Tc_18  = [ -6.463695e+001 ; -9.820065e+001 ; 3.499717e+002 ];
omc_error_18 = [ 8.599698e-003 ; 1.388064e-002 ; 1.489843e-002 ];
Tc_error_18  = [ 4.663735e+000 ; 4.366082e+000 ; 7.902322e+000 ];

%-- Image #19:
omc_19 = [ 2.043031e+000 ; 1.856942e+000 ; -4.776925e-001 ];
Tc_19  = [ -8.979752e+001 ; 5.396541e+001 ; 3.655570e+002 ];
omc_error_19 = [ 1.385363e-002 ; 1.469390e-002 ; 2.649333e-002 ];
Tc_error_19  = [ 4.863352e+000 ; 4.546671e+000 ; 7.926803e+000 ];

%-- Image #20:
omc_20 = [ -1.862227e+000 ; -2.485433e+000 ; -2.303605e-002 ];
Tc_20  = [ -7.563607e+001 ; -9.112169e+001 ; 3.479378e+002 ];
omc_error_20 = [ 1.537901e-002 ; 1.534146e-002 ; 3.099898e-002 ];
Tc_error_20  = [ 4.674415e+000 ; 4.318828e+000 ; 8.312616e+000 ];

