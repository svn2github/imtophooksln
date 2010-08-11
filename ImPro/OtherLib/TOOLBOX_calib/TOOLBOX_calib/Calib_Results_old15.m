% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 693.398899442999890 ; 684.708097373736900 ];

%-- Principal point:
cc = [ 341.071578003346470 ; 264.084364356156700 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.146463737045597 ; -0.690159078564786 ; 0.006598790599593 ; 0.011833644189373 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.702221678025290 ; 6.420027255380932 ];

%-- Principal point uncertainty:
cc_error = [ 4.810063229567326 ; 5.010218398255417 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.025573420488437 ; 0.160187907207284 ; 0.002895295675645 ; 0.002916262594304 ; 0.000000000000000 ];

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
omc_1 = [ 2.134293e+000 ; 2.129703e+000 ; -3.157630e-001 ];
Tc_1  = [ -4.031069e+001 ; -2.421047e+001 ; 1.946568e+002 ];
omc_error_1 = [ 6.984033e-003 ; 8.194877e-003 ; 1.522265e-002 ];
Tc_error_1  = [ 1.348056e+000 ; 1.430834e+000 ; 1.889385e+000 ];

%-- Image #2:
omc_2 = [ -2.231763e+000 ; -2.003791e+000 ; 4.992550e-001 ];
Tc_2  = [ -1.684574e+001 ; -2.477367e+001 ; 2.121047e+002 ];
omc_error_2 = [ 8.314988e-003 ; 6.527971e-003 ; 1.601804e-002 ];
Tc_error_2  = [ 1.473499e+000 ; 1.543663e+000 ; 1.972716e+000 ];

%-- Image #3:
omc_3 = [ -2.073581e+000 ; -2.266818e+000 ; -1.217886e-001 ];
Tc_3  = [ -6.081190e+001 ; -3.861935e+001 ; 1.599418e+002 ];
omc_error_3 = [ 9.314788e-003 ; 8.433784e-003 ; 2.189533e-002 ];
Tc_error_3  = [ 1.116913e+000 ; 1.218055e+000 ; 1.763070e+000 ];

%-- Image #4:
omc_4 = [ 1.567701e+000 ; 2.543415e+000 ; 2.190263e-001 ];
Tc_4  = [ -8.815742e+000 ; -4.726637e+001 ; 1.419100e+002 ];
omc_error_4 = [ 5.719184e-003 ; 8.217377e-003 ; 1.120589e-002 ];
Tc_error_4  = [ 9.981401e-001 ; 1.047430e+000 ; 1.452826e+000 ];

%-- Image #5:
omc_5 = [ 2.063218e+000 ; 2.180470e+000 ; -4.905055e-001 ];
Tc_5  = [ -3.704713e+001 ; -1.479519e+001 ; 2.841823e+002 ];
omc_error_5 = [ 8.665873e-003 ; 1.013580e-002 ; 1.883000e-002 ];
Tc_error_5  = [ 1.967190e+000 ; 2.088941e+000 ; 2.696955e+000 ];

%-- Image #6:
omc_6 = [ -2.079265e+000 ; -2.113402e+000 ; 9.188146e-002 ];
Tc_6  = [ 8.899810e+000 ; -3.086024e+001 ; 3.959974e+002 ];
omc_error_6 = [ 2.607770e-002 ; 3.056849e-002 ; 5.916302e-002 ];
Tc_error_6  = [ 2.764565e+000 ; 2.886320e+000 ; 4.315435e+000 ];

%-- Image #7:
omc_7 = [ -2.131148e+000 ; -2.238068e+000 ; 2.647798e-001 ];
Tc_7  = [ 1.091524e+001 ; -2.242771e+000 ; 5.085998e+002 ];
omc_error_7 = [ 3.864741e-002 ; 4.718546e-002 ; 9.535085e-002 ];
Tc_error_7  = [ 3.542175e+000 ; 3.726850e+000 ; 5.343181e+000 ];

%-- Image #8:
omc_8 = [ -1.983981e+000 ; -1.958903e+000 ; -1.846799e-001 ];
Tc_8  = [ -5.277035e+000 ; -7.257862e+001 ; 2.758768e+002 ];
omc_error_8 = [ 1.359122e-002 ; 1.416893e-002 ; 2.503918e-002 ];
Tc_error_8  = [ 1.945209e+000 ; 2.027243e+000 ; 2.990880e+000 ];

%-- Image #9:
omc_9 = [ 2.264566e+000 ; 2.086964e+000 ; -5.556501e-001 ];
Tc_9  = [ 6.999311e+000 ; -3.469482e+000 ; 2.624044e+002 ];
omc_error_9 = [ 1.198483e-002 ; 9.430618e-003 ; 2.304699e-002 ];
Tc_error_9  = [ 1.824977e+000 ; 1.910725e+000 ; 2.477086e+000 ];

%-- Image #10:
omc_10 = [ -2.144942e+000 ; -2.187202e+000 ; 1.163916e-001 ];
Tc_10  = [ -3.362816e+001 ; -3.259325e+001 ; 1.453917e+002 ];
omc_error_10 = [ 6.750582e-003 ; 6.330125e-003 ; 1.391382e-002 ];
Tc_error_10  = [ 1.015477e+000 ; 1.068570e+000 ; 1.457002e+000 ];

%-- Image #11:
omc_11 = [ 1.546787e+000 ; 2.403556e+000 ; 1.041315e-001 ];
Tc_11  = [ -1.910182e+001 ; -3.769676e+001 ; 2.015698e+002 ];
omc_error_11 = [ 6.225347e-003 ; 9.150492e-003 ; 1.301634e-002 ];
Tc_error_11  = [ 1.402243e+000 ; 1.476291e+000 ; 2.014915e+000 ];

%-- Image #12:
omc_12 = [ -2.187314e+000 ; -2.120237e+000 ; 4.417150e-001 ];
Tc_12  = [ -1.195045e+000 ; -1.645459e+001 ; 3.620522e+002 ];
omc_error_12 = [ 1.481531e-002 ; 1.517666e-002 ; 3.234657e-002 ];
Tc_error_12  = [ 2.517587e+000 ; 2.646051e+000 ; 3.492362e+000 ];

%-- Image #13:
omc_13 = [ -1.885093e+000 ; -1.898283e+000 ; -1.163045e-001 ];
Tc_13  = [ 1.132342e+001 ; -3.993003e+001 ; 2.622712e+002 ];
omc_error_13 = [ 8.353756e-003 ; 1.040873e-002 ; 1.502640e-002 ];
Tc_error_13  = [ 1.823275e+000 ; 1.904577e+000 ; 2.702360e+000 ];

%-- Image #14:
omc_14 = [ 2.078007e+000 ; 2.196850e+000 ; -4.346240e-001 ];
Tc_14  = [ -2.712531e+000 ; -2.720039e+001 ; 2.655051e+002 ];
omc_error_14 = [ 9.165342e-003 ; 9.648365e-003 ; 1.926295e-002 ];
Tc_error_14  = [ 1.846679e+000 ; 1.930640e+000 ; 2.578595e+000 ];

%-- Image #15:
omc_15 = [ -2.373977e+000 ; -1.577651e+000 ; 8.861864e-001 ];
Tc_15  = [ -1.250084e+001 ; -2.183843e+000 ; 2.742968e+002 ];
omc_error_15 = [ 9.316743e-003 ; 4.693182e-003 ; 1.325082e-002 ];
Tc_error_15  = [ 1.905502e+000 ; 1.998496e+000 ; 2.390087e+000 ];

%-- Image #16:
omc_16 = [ 1.323355e+000 ; 2.383536e+000 ; 2.643899e-001 ];
Tc_16  = [ -1.176215e+001 ; -4.158113e+001 ; 1.635031e+002 ];
omc_error_16 = [ 5.488193e-003 ; 7.556298e-003 ; 9.499821e-003 ];
Tc_error_16  = [ 1.141162e+000 ; 1.200074e+000 ; 1.655269e+000 ];

%-- Image #17:
omc_17 = [ -2.105058e+000 ; -2.133148e+000 ; 5.407438e-001 ];
Tc_17  = [ 1.501482e+001 ; -4.898573e+001 ; 3.118779e+002 ];
omc_error_17 = [ 1.092739e-002 ; 9.573650e-003 ; 2.094571e-002 ];
Tc_error_17  = [ 2.189983e+000 ; 2.274260e+000 ; 2.984350e+000 ];

%-- Image #18:
omc_18 = [ 2.082689e+000 ; 1.862485e+000 ; -8.378256e-001 ];
Tc_18  = [ -2.290329e+001 ; -2.748676e+001 ; 2.073154e+002 ];
omc_error_18 = [ 5.351261e-003 ; 7.711900e-003 ; 1.075961e-002 ];
Tc_error_18  = [ 1.443839e+000 ; 1.516684e+000 ; 1.852204e+000 ];

%-- Image #19:
omc_19 = [ 2.062135e+000 ; 1.889086e+000 ; -5.886202e-001 ];
Tc_19  = [ -4.314386e+001 ; -3.500593e+001 ; 1.591890e+002 ];
omc_error_19 = [ 4.996516e-003 ; 7.529726e-003 ; 1.087834e-002 ];
Tc_error_19  = [ 1.119612e+000 ; 1.185694e+000 ; 1.505235e+000 ];

%-- Image #20:
omc_20 = [ -2.346810e+000 ; -1.780937e+000 ; 9.803323e-001 ];
Tc_20  = [ -4.318729e+001 ; -1.851098e+001 ; 1.688573e+002 ];
omc_error_20 = [ 8.583252e-003 ; 3.054030e-003 ; 1.128765e-002 ];
Tc_error_20  = [ 1.179636e+000 ; 1.255298e+000 ; 1.424506e+000 ];

