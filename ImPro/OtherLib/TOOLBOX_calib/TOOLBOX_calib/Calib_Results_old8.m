% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 585.480857031207050 ; 581.951802331253480 ];

%-- Principal point:
cc = [ 329.459555238399840 ; 240.464138889618620 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.000054540672361 ; -0.149216292814060 ; 0.002974958056893 ; 0.002035507786078 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 10.441928754634217 ; 10.746852803814452 ];

%-- Principal point uncertainty:
cc_error = [ 10.840753417812673 ; 11.107945532844877 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.032274142077243 ; 0.085855698812632 ; 0.004203893910817 ; 0.004735121795773 ; 0.000000000000000 ];

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
omc_1 = [ 2.080891e+000 ; 2.321977e+000 ; 7.591821e-002 ];
Tc_1  = [ 3.025787e+000 ; 2.158627e+001 ; 2.372612e+002 ];
omc_error_1 = [ 2.049415e-002 ; 1.474962e-002 ; 4.215306e-002 ];
Tc_error_1  = [ 4.403738e+000 ; 4.565688e+000 ; 4.475493e+000 ];

%-- Image #2:
omc_2 = [ 2.090090e+000 ; 2.300866e+000 ; 9.147895e-002 ];
Tc_2  = [ -5.605976e+001 ; 5.860975e-001 ; 2.346956e+002 ];
omc_error_2 = [ 2.191113e-002 ; 2.182260e-002 ; 4.650715e-002 ];
Tc_error_2  = [ 4.366386e+000 ; 4.534983e+000 ; 4.534399e+000 ];

%-- Image #3:
omc_3 = [ 2.193206e+000 ; 2.174034e+000 ; 1.044975e-001 ];
Tc_3  = [ -1.097394e+002 ; 7.097293e+000 ; 2.303722e+002 ];
omc_error_3 = [ 2.291647e-002 ; 2.276568e-002 ; 4.598553e-002 ];
Tc_error_3  = [ 4.293789e+000 ; 4.586766e+000 ; 5.015898e+000 ];

%-- Image #4:
omc_4 = [ 2.053529e+000 ; 2.356644e+000 ; 1.600819e-001 ];
Tc_4  = [ -1.049220e+002 ; -7.075788e+001 ; 2.247859e+002 ];
omc_error_4 = [ 1.572953e-002 ; 2.602220e-002 ; 5.873993e-002 ];
Tc_error_4  = [ 4.277673e+000 ; 4.481282e+000 ; 5.238809e+000 ];

%-- Image #5:
omc_5 = [ -2.075939e+000 ; -2.305874e+000 ; -1.465739e-001 ];
Tc_5  = [ -3.606330e+001 ; -8.425959e+001 ; 2.294671e+002 ];
omc_error_5 = [ 2.498778e-002 ; 2.298639e-002 ; 5.412255e-002 ];
Tc_error_5  = [ 4.368162e+000 ; 4.455295e+000 ; 4.769670e+000 ];

%-- Image #6:
omc_6 = [ -2.325986e+000 ; -2.057093e+000 ; -1.220908e-001 ];
Tc_6  = [ 1.292619e+001 ; -5.479773e+001 ; 2.325184e+002 ];
omc_error_6 = [ 2.096189e-002 ; 2.117952e-002 ; 4.206421e-002 ];
Tc_error_6  = [ 4.412736e+000 ; 4.468538e+000 ; 4.765163e+000 ];

%-- Image #7:
omc_7 = [ 1.949043e+000 ; 2.391264e+000 ; -2.308994e-001 ];
Tc_7  = [ 6.757111e+000 ; -1.301743e+001 ; 1.909325e+002 ];
omc_error_7 = [ 1.708902e-002 ; 1.634548e-002 ; 4.293912e-002 ];
Tc_error_7  = [ 3.536855e+000 ; 3.621597e+000 ; 3.432111e+000 ];

%-- Image #8:
omc_8 = [ 1.656385e+000 ; 2.275713e+000 ; -4.926590e-001 ];
Tc_8  = [ 1.432777e+001 ; 7.502913e+000 ; 4.532626e+002 ];
omc_error_8 = [ 2.262527e-002 ; 2.869569e-002 ; 5.111831e-002 ];
Tc_error_8  = [ 8.392702e+000 ; 8.703301e+000 ; 7.994544e+000 ];

%-- Image #9:
omc_9 = [ -1.560859e+000 ; -2.067222e+000 ; -4.396354e-001 ];
Tc_9  = [ -4.183881e+001 ; -3.621542e+001 ; 1.700236e+002 ];
omc_error_9 = [ 1.238134e-002 ; 1.782254e-002 ; 2.483642e-002 ];
Tc_error_9  = [ 3.159030e+000 ; 3.277091e+000 ; 3.319994e+000 ];

%-- Image #10:
omc_10 = [ 1.327951e+000 ; 1.878021e+000 ; -8.063781e-001 ];
Tc_10  = [ -5.013185e+001 ; 6.518315e+000 ; 3.390624e+002 ];
omc_error_10 = [ 1.373031e-002 ; 2.188018e-002 ; 2.535568e-002 ];
Tc_error_10  = [ 6.267478e+000 ; 6.536629e+000 ; 5.664694e+000 ];

%-- Image #11:
omc_11 = [ 1.436122e+000 ; 1.791099e+000 ; -8.113787e-001 ];
Tc_11  = [ 6.477983e+001 ; 1.488103e+001 ; 3.392728e+002 ];
omc_error_11 = [ 1.707293e-002 ; 1.738931e-002 ; 2.589472e-002 ];
Tc_error_11  = [ 6.231345e+000 ; 6.539886e+000 ; 5.821552e+000 ];

%-- Image #12:
omc_12 = [ -1.522300e+000 ; -1.886860e+000 ; -4.539457e-001 ];
Tc_12  = [ 1.425593e+001 ; -5.804845e+001 ; 2.162583e+002 ];
omc_error_12 = [ 1.295167e-002 ; 1.991591e-002 ; 2.574473e-002 ];
Tc_error_12  = [ 4.088364e+000 ; 4.128877e+000 ; 4.106660e+000 ];

%-- Image #13:
omc_13 = [ -1.627183e+000 ; -1.962358e+000 ; -5.701620e-001 ];
Tc_13  = [ -3.511660e+001 ; -1.701163e+001 ; 1.282549e+002 ];
omc_error_13 = [ 1.181304e-002 ; 1.807206e-002 ; 2.303906e-002 ];
Tc_error_13  = [ 2.362270e+000 ; 2.473333e+000 ; 2.555548e+000 ];

%-- Image #14:
omc_14 = [ 1.933473e+000 ; 2.367245e+000 ; -4.406065e-002 ];
Tc_14  = [ -3.908292e+001 ; -2.109076e+001 ; 1.388843e+002 ];
omc_error_14 = [ 1.140969e-002 ; 1.352765e-002 ; 2.616239e-002 ];
Tc_error_14  = [ 2.573244e+000 ; 2.664014e+000 ; 2.638785e+000 ];

%-- Image #15:
omc_15 = [ 1.292007e+000 ; 1.714042e+000 ; -8.913533e-001 ];
Tc_15  = [ -5.309366e+001 ; 3.143905e+001 ; 2.999419e+002 ];
omc_error_15 = [ 1.434687e-002 ; 2.158127e-002 ; 2.332750e-002 ];
Tc_error_15  = [ 5.552633e+000 ; 5.837354e+000 ; 4.950080e+000 ];

%-- Image #16:
omc_16 = [ 1.418251e+000 ; 1.788860e+000 ; -9.101663e-001 ];
Tc_16  = [ -1.025763e+002 ; 2.127508e+001 ; 2.768260e+002 ];
omc_error_16 = [ 1.174454e-002 ; 2.342770e-002 ; 2.356159e-002 ];
Tc_error_16  = [ 5.162111e+000 ; 5.475530e+000 ; 5.006183e+000 ];

%-- Image #17:
omc_17 = [ 1.457456e+000 ; 1.894909e+000 ; -9.506008e-001 ];
Tc_17  = [ 5.448788e+001 ; -5.974931e+001 ; 3.645319e+002 ];
omc_error_17 = [ 1.555611e-002 ; 1.921839e-002 ; 2.465281e-002 ];
Tc_error_17  = [ 6.835632e+000 ; 6.924579e+000 ; 6.119567e+000 ];

%-- Image #18:
omc_18 = [ 1.591167e+000 ; 1.766678e+000 ; -8.508055e-001 ];
Tc_18  = [ 2.050015e+001 ; -3.141869e+001 ; 2.316165e+002 ];
omc_error_18 = [ 1.498782e-002 ; 1.690742e-002 ; 2.387477e-002 ];
Tc_error_18  = [ 4.295763e+000 ; 4.367664e+000 ; 3.587014e+000 ];

%-- Image #19:
omc_19 = [ 1.383752e+000 ; 2.201569e+000 ; -7.062452e-001 ];
Tc_19  = [ -1.020781e+002 ; -1.254083e+002 ; 3.340163e+002 ];
omc_error_19 = [ 9.219173e-003 ; 2.234143e-002 ; 2.837179e-002 ];
Tc_error_19  = [ 6.474408e+000 ; 6.484310e+000 ; 6.517528e+000 ];

%-- Image #20:
omc_20 = [ 1.280311e+000 ; 1.906082e+000 ; -8.332372e-001 ];
Tc_20  = [ -1.383059e+002 ; -7.213658e+001 ; 3.571029e+002 ];
omc_error_20 = [ 1.063793e-002 ; 2.335186e-002 ; 2.369170e-002 ];
Tc_error_20  = [ 6.749135e+000 ; 6.945798e+000 ; 7.038859e+000 ];

