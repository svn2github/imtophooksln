% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 585.018745782136650 ; 574.812537321305400 ];

%-- Principal point:
cc = [ 357.271589950604950 ; 255.055231489857900 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.025009690637701 ; -0.026249516597025 ; 0.006973330782666 ; 0.020292058393033 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 10.252780640381594 ; 10.071285818756648 ];

%-- Principal point uncertainty:
cc_error = [ 9.478354805342065 ; 6.322776394257422 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.026100190941651 ; 0.063421337473474 ; 0.003608330697884 ; 0.004684032731327 ; 0.000000000000000 ];

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
omc_1 = [ -2.159792e+000 ; -2.094487e+000 ; -7.425784e-001 ];
Tc_1  = [ -4.577696e+001 ; -1.892011e+001 ; 1.210281e+002 ];
omc_error_1 = [ 1.634763e-002 ; 1.566057e-002 ; 3.093654e-002 ];
Tc_error_1  = [ 2.004950e+000 ; 1.418706e+000 ; 2.586724e+000 ];

%-- Image #2:
omc_2 = [ 2.056922e+000 ; 1.852540e+000 ; -4.836062e-002 ];
Tc_2  = [ -7.203558e+001 ; -3.266181e+001 ; 1.443008e+002 ];
omc_error_2 = [ 1.274481e-002 ; 2.074381e-002 ; 3.068118e-002 ];
Tc_error_2  = [ 2.383275e+000 ; 1.740604e+000 ; 3.027985e+000 ];

%-- Image #3:
omc_3 = [ 2.100046e+000 ; 1.667060e+000 ; -2.128552e-002 ];
Tc_3  = [ -6.609407e+001 ; -6.142115e+001 ; 1.567132e+002 ];
omc_error_3 = [ 1.088716e-002 ; 1.853295e-002 ; 2.699564e-002 ];
Tc_error_3  = [ 2.654900e+000 ; 1.893429e+000 ; 3.281554e+000 ];

%-- Image #4:
omc_4 = [ 2.024473e+000 ; 2.075155e+000 ; 2.249440e-001 ];
Tc_4  = [ -1.359591e+001 ; -5.563846e+001 ; 1.690684e+002 ];
omc_error_4 = [ 1.493969e-002 ; 2.075371e-002 ; 3.325277e-002 ];
Tc_error_4  = [ 2.816425e+000 ; 1.886595e+000 ; 3.362834e+000 ];

%-- Image #5:
omc_5 = [ -2.126912e+000 ; -2.111903e+000 ; -5.525536e-001 ];
Tc_5  = [ -1.751431e+001 ; -2.858311e+001 ; 1.098817e+002 ];
omc_error_5 = [ 1.475833e-002 ; 1.639373e-002 ; 2.765348e-002 ];
Tc_error_5  = [ 1.822767e+000 ; 1.254759e+000 ; 2.212389e+000 ];

%-- Image #6:
omc_6 = [ -2.092495e+000 ; -2.037090e+000 ; -3.423846e-001 ];
Tc_6  = [ -2.410974e+001 ; -2.003077e+001 ; 6.937672e+001 ];
omc_error_6 = [ 1.083835e-002 ; 1.225565e-002 ; 1.964979e-002 ];
Tc_error_6  = [ 1.157236e+000 ; 8.008507e-001 ; 1.380022e+000 ];

%-- Image #7:
omc_7 = [ 2.108252e+000 ; 2.002195e+000 ; -1.596523e-001 ];
Tc_7  = [ -2.859370e+001 ; -1.695885e+001 ; 7.390706e+001 ];
omc_error_7 = [ 9.144950e-003 ; 1.222986e-002 ; 2.212432e-002 ];
Tc_error_7  = [ 1.206525e+000 ; 8.352331e-001 ; 1.417993e+000 ];

%-- Image #8:
omc_8 = [ 1.956852e+000 ; 1.811943e+000 ; -3.095327e-001 ];
Tc_8  = [ -4.862398e+001 ; -2.720576e+001 ; 1.400241e+002 ];
omc_error_8 = [ 9.656455e-003 ; 1.633508e-002 ; 2.454046e-002 ];
Tc_error_8  = [ 2.296721e+000 ; 1.610854e+000 ; 2.662469e+000 ];

%-- Image #9:
omc_9 = [ 1.571065e+000 ; 2.108375e+000 ; 3.347791e-002 ];
Tc_9  = [ -7.527656e+001 ; 1.840927e+001 ; 2.116969e+002 ];
omc_error_9 = [ 2.806076e-002 ; 4.059406e-002 ; 6.314174e-002 ];
Tc_error_9  = [ 3.517471e+000 ; 2.476307e+000 ; 4.487448e+000 ];

%-- Image #10:
omc_10 = [ -1.874229e+000 ; -1.917326e+000 ; 4.388931e-001 ];
Tc_10  = [ 5.496013e+000 ; -3.614027e+001 ; 1.404035e+002 ];
omc_error_10 = [ 1.510438e-002 ; 1.396785e-002 ; 2.775724e-002 ];
Tc_error_10  = [ 2.335824e+000 ; 1.535167e+000 ; 2.422515e+000 ];

%-- Image #11:
omc_11 = [ -1.779964e+000 ; -1.940179e+000 ; 4.087151e-001 ];
Tc_11  = [ -2.737947e+000 ; -6.229015e+000 ; 1.198385e+002 ];
omc_error_11 = [ 1.179915e-002 ; 1.411291e-002 ; 2.076002e-002 ];
Tc_error_11  = [ 1.932265e+000 ; 1.316555e+000 ; 2.032088e+000 ];

%-- Image #12:
omc_12 = [ -1.933936e+000 ; -2.146530e+000 ; 1.813655e-001 ];
Tc_12  = [ -5.473508e+001 ; -1.326049e+001 ; 9.974309e+001 ];
omc_error_12 = [ 1.554875e-002 ; 1.415746e-002 ; 2.323172e-002 ];
Tc_error_12  = [ 1.656974e+000 ; 1.201043e+000 ; 2.039124e+000 ];

%-- Image #13:
omc_13 = [ 1.763007e+000 ; 2.098317e+000 ; -4.442782e-001 ];
Tc_13  = [ -5.823372e+001 ; -3.302451e+001 ; 1.609720e+002 ];
omc_error_13 = [ 8.739240e-003 ; 1.890918e-002 ; 2.577873e-002 ];
Tc_error_13  = [ 2.655046e+000 ; 1.874889e+000 ; 3.040409e+000 ];

%-- Image #14:
omc_14 = [ -1.768677e+000 ; -2.007943e+000 ; -7.312382e-004 ];
Tc_14  = [ -5.437202e+001 ; -1.440931e+001 ; 9.955104e+001 ];
omc_error_14 = [ 1.341302e-002 ; 1.456657e-002 ; 2.040018e-002 ];
Tc_error_14  = [ 1.649144e+000 ; 1.192215e+000 ; 2.067011e+000 ];

%-- Image #15:
omc_15 = [ 1.953254e+000 ; 1.844472e+000 ; 8.663328e-001 ];
Tc_15  = [ -3.295615e+001 ; -2.449314e+001 ; 1.344604e+002 ];
omc_error_15 = [ 1.683514e-002 ; 1.416529e-002 ; 2.199363e-002 ];
Tc_error_15  = [ 2.210976e+000 ; 1.532011e+000 ; 2.833625e+000 ];

%-- Image #16:
omc_16 = [ 1.810984e+000 ; 1.530054e+000 ; 4.693294e-001 ];
Tc_16  = [ -7.703782e+001 ; -2.371846e+001 ; 1.997512e+002 ];
omc_error_16 = [ 1.507723e-002 ; 1.800718e-002 ; 2.573051e-002 ];
Tc_error_16  = [ 3.328180e+000 ; 2.307640e+000 ; 4.341035e+000 ];

%-- Image #17:
omc_17 = [ -1.971516e+000 ; -2.155014e+000 ; 1.630013e-001 ];
Tc_17  = [ -3.253391e+001 ; -2.408700e+001 ; 7.408007e+001 ];
omc_error_17 = [ 1.322805e-002 ; 1.096606e-002 ; 2.266307e-002 ];
Tc_error_17  = [ 1.222553e+000 ; 8.566860e-001 ; 1.459614e+000 ];

%-- Image #18:
omc_18 = [ -1.812604e+000 ; -1.866828e+000 ; -6.841311e-001 ];
Tc_18  = [ -5.806480e+001 ; -1.754473e+001 ; 1.374482e+002 ];
omc_error_18 = [ 1.241988e-002 ; 1.515944e-002 ; 2.265730e-002 ];
Tc_error_18  = [ 2.242539e+000 ; 1.608949e+000 ; 2.937344e+000 ];

%-- Image #19:
omc_19 = [ -1.752695e+000 ; -1.931384e+000 ; 1.855175e-001 ];
Tc_19  = [ -1.904815e+001 ; -3.485065e+001 ; 1.471688e+002 ];
omc_error_19 = [ 1.352520e-002 ; 1.395040e-002 ; 2.322443e-002 ];
Tc_error_19  = [ 2.407017e+000 ; 1.625841e+000 ; 2.614868e+000 ];

%-- Image #20:
omc_20 = [ -1.797563e+000 ; -1.771863e+000 ; 4.593159e-001 ];
Tc_20  = [ 1.699136e+001 ; -3.015264e+001 ; 1.512853e+002 ];
omc_error_20 = [ 1.421863e-002 ; 1.436830e-002 ; 2.497247e-002 ];
Tc_error_20  = [ 2.520094e+000 ; 1.650572e+000 ; 2.598917e+000 ];

