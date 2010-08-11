% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 564.527495694836940 ; 564.362276931100380 ];

%-- Principal point:
cc = [ 333.275825463334400 ; 239.262160986663420 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.000790590190032 ; -0.114688102953214 ; 0.000029733549862 ; -0.000277947970579 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.740125085950599 ; 6.781923978259422 ];

%-- Principal point uncertainty:
cc_error = [ 6.422109446251183 ; 5.634284268748959 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.020864329891259 ; 0.056356470375033 ; 0.002475253240218 ; 0.003074031392090 ; 0.000000000000000 ];

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
omc_1 = [ 2.266315e+000 ; 1.638361e+000 ; 7.457458e-001 ];
Tc_1  = [ -7.983699e+001 ; -6.425775e+001 ; 2.314663e+002 ];
omc_error_1 = [ 1.248211e-002 ; 1.094985e-002 ; 2.244673e-002 ];
Tc_error_1  = [ 2.742366e+000 ; 2.398881e+000 ; 3.369726e+000 ];

%-- Image #2:
omc_2 = [ 2.225621e+000 ; 1.555152e+000 ; 8.680060e-001 ];
Tc_2  = [ -7.980276e+001 ; -5.116997e+001 ; 1.682012e+002 ];
omc_error_2 = [ 1.099024e-002 ; 8.861473e-003 ; 1.820320e-002 ];
Tc_error_2  = [ 2.047063e+000 ; 1.773789e+000 ; 2.573059e+000 ];

%-- Image #3:
omc_3 = [ 1.945587e+000 ; 1.720870e+000 ; 8.407248e-001 ];
Tc_3  = [ -8.495827e+001 ; 1.784015e+000 ; 1.636641e+002 ];
omc_error_3 = [ 1.099344e-002 ; 7.475597e-003 ; 1.863509e-002 ];
Tc_error_3  = [ 1.957770e+000 ; 1.729043e+000 ; 2.526670e+000 ];

%-- Image #4:
omc_4 = [ 2.215466e+000 ; 2.129721e+000 ; -6.100397e-002 ];
Tc_4  = [ -6.342210e+001 ; -1.197983e+001 ; 1.339646e+002 ];
omc_error_4 = [ 8.608130e-003 ; 9.262542e-003 ; 1.733950e-002 ];
Tc_error_4  = [ 1.527859e+000 ; 1.375743e+000 ; 1.814477e+000 ];

%-- Image #5:
omc_5 = [ 2.198120e+000 ; 2.163015e+000 ; 2.649176e-002 ];
Tc_5  = [ -3.239266e+001 ; -1.974320e+001 ; 1.100504e+002 ];
omc_error_5 = [ 7.383331e-003 ; 6.448119e-003 ; 1.573530e-002 ];
Tc_error_5  = [ 1.264777e+000 ; 1.107586e+000 ; 1.393461e+000 ];

%-- Image #6:
omc_6 = [ 2.188173e+000 ; 2.170292e+000 ; -2.893187e-002 ];
Tc_6  = [ -3.349405e+001 ; -3.655594e+001 ; 1.214683e+002 ];
omc_error_6 = [ 7.297044e-003 ; 7.835692e-003 ; 1.557188e-002 ];
Tc_error_6  = [ 1.399892e+000 ; 1.214803e+000 ; 1.554085e+000 ];

%-- Image #7:
omc_7 = [ -2.092757e+000 ; -2.178601e+000 ; -1.815297e-002 ];
Tc_7  = [ -8.632590e+001 ; -4.314735e+001 ; 2.123826e+002 ];
omc_error_7 = [ 1.192954e-002 ; 1.007990e-002 ; 2.418232e-002 ];
Tc_error_7  = [ 2.448745e+000 ; 2.185302e+000 ; 2.835863e+000 ];

%-- Image #8:
omc_8 = [ -2.148846e+000 ; -2.102795e+000 ; 7.427618e-002 ];
Tc_8  = [ -1.666515e+002 ; -4.364077e+001 ; 3.318602e+002 ];
omc_error_8 = [ 1.432292e-002 ; 1.042125e-002 ; 2.613145e-002 ];
Tc_error_8  = [ 3.964682e+000 ; 3.484495e+000 ; 4.647171e+000 ];

%-- Image #9:
omc_9 = [ -1.734287e+000 ; -2.348466e+000 ; -2.279979e-001 ];
Tc_9  = [ -2.263133e+001 ; -5.890840e+001 ; 1.917467e+002 ];
omc_error_9 = [ 1.065029e-002 ; 1.412058e-002 ; 2.432775e-002 ];
Tc_error_9  = [ 2.222544e+000 ; 1.954397e+000 ; 2.475462e+000 ];

%-- Image #10:
omc_10 = [ 1.782955e+000 ; 2.405858e+000 ; -3.890539e-001 ];
Tc_10  = [ -2.520959e+001 ; -3.772201e+001 ; 2.400109e+002 ];
omc_error_10 = [ 9.365853e-003 ; 1.371187e-002 ; 2.354129e-002 ];
Tc_error_10  = [ 2.715006e+000 ; 2.381150e+000 ; 2.755723e+000 ];

%-- Image #11:
omc_11 = [ 1.666947e+000 ; 2.265262e+000 ; -5.465329e-001 ];
Tc_11  = [ -2.927211e+001 ; -5.423550e+001 ; 2.024832e+002 ];
omc_error_11 = [ 5.926962e-003 ; 1.109288e-002 ; 1.630887e-002 ];
Tc_error_11  = [ 2.310243e+000 ; 2.009999e+000 ; 2.271836e+000 ];

%-- Image #12:
omc_12 = [ -2.146823e+000 ; -2.099961e+000 ; -2.944401e-002 ];
Tc_12  = [ -2.266503e+002 ; -4.567708e+001 ; 4.489751e+002 ];
omc_error_12 = [ 1.766252e-002 ; 1.294324e-002 ; 3.251244e-002 ];
Tc_error_12  = [ 5.471615e+000 ; 4.720757e+000 ; 6.622129e+000 ];

%-- Image #13:
omc_13 = [ -2.086079e+000 ; -2.078768e+000 ; 1.227889e-002 ];
Tc_13  = [ -1.394447e+002 ; -5.517117e+001 ; 4.366402e+002 ];
omc_error_13 = [ 1.843470e-002 ; 1.545566e-002 ; 3.559024e-002 ];
Tc_error_13  = [ 5.082841e+000 ; 4.453757e+000 ; 5.939482e+000 ];

%-- Image #14:
omc_14 = [ -1.243164e+000 ; -2.263704e+000 ; 3.014258e-001 ];
Tc_14  = [ -3.030028e+000 ; -1.156406e+002 ; 3.619258e+002 ];
omc_error_14 = [ 1.029052e-002 ; 1.398049e-002 ; 2.026452e-002 ];
Tc_error_14  = [ 4.197799e+000 ; 3.655140e+000 ; 4.574130e+000 ];

%-- Image #15:
omc_15 = [ 2.289754e+000 ; 1.444891e+000 ; 7.148945e-001 ];
Tc_15  = [ -5.832541e+001 ; -3.197284e+001 ; 2.569608e+002 ];
omc_error_15 = [ 1.273540e-002 ; 8.454868e-003 ; 2.020506e-002 ];
Tc_error_15  = [ 2.966486e+000 ; 2.593353e+000 ; 3.633503e+000 ];

%-- Image #16:
omc_16 = [ -1.947572e+000 ; -1.649219e+000 ; -1.042129e+000 ];
Tc_16  = [ -1.492792e+002 ; 1.151071e+001 ; 3.850092e+002 ];
omc_error_16 = [ 1.214918e-002 ; 1.176148e-002 ; 1.951178e-002 ];
Tc_error_16  = [ 4.475595e+000 ; 3.958317e+000 ; 5.683480e+000 ];

%-- Image #17:
omc_17 = [ 1.676240e+000 ; 2.011362e+000 ; 1.456174e+000 ];
Tc_17  = [ -2.073778e+001 ; -2.659570e+001 ; 1.340770e+002 ];
omc_error_17 = [ 1.243188e-002 ; 7.898758e-003 ; 1.513514e-002 ];
Tc_error_17  = [ 1.544374e+000 ; 1.345186e+000 ; 2.049357e+000 ];

%-- Image #18:
omc_18 = [ -1.506429e+000 ; -2.010739e+000 ; -5.160656e-001 ];
Tc_18  = [ -7.632127e+001 ; -2.522501e+001 ; 1.631679e+002 ];
omc_error_18 = [ 7.538332e-003 ; 1.001781e-002 ; 1.452326e-002 ];
Tc_error_18  = [ 1.883436e+000 ; 1.699550e+000 ; 2.369538e+000 ];

%-- Image #19:
omc_19 = [ -1.939998e+000 ; -2.176909e+000 ; -2.200317e-001 ];
Tc_19  = [ -9.818378e+001 ; -5.172062e+001 ; 2.292393e+002 ];
omc_error_19 = [ 1.148271e-002 ; 1.063977e-002 ; 2.432706e-002 ];
Tc_error_19  = [ 2.665157e+000 ; 2.377979e+000 ; 3.221526e+000 ];

%-- Image #20:
omc_20 = [ -1.957634e+000 ; -2.266500e+000 ; -2.192010e-001 ];
Tc_20  = [ -2.885686e+001 ; -5.351119e+001 ; 1.841949e+002 ];
omc_error_20 = [ 1.203499e-002 ; 1.357537e-002 ; 2.520426e-002 ];
Tc_error_20  = [ 2.137529e+000 ; 1.882772e+000 ; 2.384514e+000 ];

