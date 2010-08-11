% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly excecuted under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 538.931201468706260 ; 538.380636806383110 ];

%-- Principal point:
cc = [ 318.833659804140500 ; 247.364252357052810 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.009083917943448 ; -0.071389930596969 ; -0.004847020070242 ; -0.000872630864952 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 11.279499542480096 ; 11.282329823814875 ];

%-- Principal point uncertainty:
cc_error = [ 6.305664742881523 ; 4.661571372366739 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.010924414529621 ; 0.022900772673994 ; 0.002030562519603 ; 0.002248738416294 ; 0.000000000000000 ];

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
omc_1 = [ 2.377777e+000 ; 2.000953e+000 ; 1.661085e-001 ];
Tc_1  = [ -1.346192e+002 ; -7.090337e+001 ; 2.868121e+002 ];
omc_error_1 = [ 1.086735e-002 ; 1.469683e-002 ; 2.655781e-002 ];
Tc_error_1  = [ 3.506236e+000 ; 2.637615e+000 ; 6.155812e+000 ];

%-- Image #2:
omc_2 = [ 2.375015e+000 ; 1.813418e+000 ; 6.027449e-001 ];
Tc_2  = [ -7.018866e+001 ; -2.463380e+001 ; 1.735861e+002 ];
omc_error_2 = [ 8.820643e-003 ; 6.388497e-003 ; 1.918280e-002 ];
Tc_error_2  = [ 2.126037e+000 ; 1.551374e+000 ; 3.715629e+000 ];

%-- Image #3:
omc_3 = [ 2.318154e+000 ; 1.800625e+000 ; 7.021616e-001 ];
Tc_3  = [ -3.246006e+001 ; -2.323138e+001 ; 1.444636e+002 ];
omc_error_3 = [ 9.093744e-003 ; 5.106902e-003 ; 1.644285e-002 ];
Tc_error_3  = [ 1.723917e+000 ; 1.262426e+000 ; 3.129716e+000 ];

%-- Image #4:
omc_4 = [ 2.278576e+000 ; 1.788000e+000 ; 8.134669e-001 ];
Tc_4  = [ 2.137570e+001 ; -1.895981e+001 ; 1.211088e+002 ];
omc_error_4 = [ 1.149568e-002 ; 5.979942e-003 ; 1.764555e-002 ];
Tc_error_4  = [ 1.391519e+000 ; 1.049538e+000 ; 2.640691e+000 ];

%-- Image #5:
omc_5 = [ 2.331117e+000 ; 1.729395e+000 ; 7.908379e-001 ];
Tc_5  = [ -6.746548e-001 ; 2.634728e+000 ; 1.317114e+002 ];
omc_error_5 = [ 1.032826e-002 ; 4.834928e-003 ; 1.746746e-002 ];
Tc_error_5  = [ 1.531332e+000 ; 1.131219e+000 ; 2.884343e+000 ];

%-- Image #6:
omc_6 = [ -2.450943e+000 ; -1.715889e+000 ; -2.816076e-001 ];
Tc_6  = [ -1.557815e+002 ; -7.854248e+001 ; 4.099182e+002 ];
omc_error_6 = [ 2.474283e-002 ; 1.174112e-002 ; 3.940082e-002 ];
Tc_error_6  = [ 4.964993e+000 ; 3.713575e+000 ; 8.903410e+000 ];

%-- Image #7:
omc_7 = [ -2.416310e+000 ; -1.589528e+000 ; -1.670914e-001 ];
Tc_7  = [ -1.597972e+002 ; -8.784900e+001 ; 5.302385e+002 ];
omc_error_7 = [ 2.346545e-002 ; 1.197246e-002 ; 3.653106e-002 ];
Tc_error_7  = [ 6.382433e+000 ; 4.744675e+000 ; 1.151448e+001 ];

%-- Image #8:
omc_8 = [ 2.504694e+000 ; 1.563309e+000 ; 8.297364e-001 ];
Tc_8  = [ -1.023491e+002 ; -1.624740e+001 ; 2.307231e+002 ];
omc_error_8 = [ 1.114208e-002 ; 6.611536e-003 ; 1.960833e-002 ];
Tc_error_8  = [ 2.870534e+000 ; 2.073681e+000 ; 5.112474e+000 ];

%-- Image #9:
omc_9 = [ -1.926777e+000 ; -2.041318e+000 ; -3.924724e-001 ];
Tc_9  = [ 4.871274e+001 ; -6.974811e+001 ; 2.518665e+002 ];
omc_error_9 = [ 9.007057e-003 ; 1.251293e-002 ; 2.580048e-002 ];
Tc_error_9  = [ 3.155816e+000 ; 2.195299e+000 ; 4.414828e+000 ];

%-- Image #10:
omc_10 = [ -2.115577e+000 ; -2.299125e+000 ; 5.505882e-002 ];
Tc_10  = [ 4.722290e+001 ; 8.835608e+000 ; 2.506028e+002 ];
omc_error_10 = [ 7.445859e-003 ; 1.250772e-002 ; 2.329744e-002 ];
Tc_error_10  = [ 2.921248e+000 ; 2.188997e+000 ; 5.313327e+000 ];

%-- Image #11:
omc_11 = [ -2.123613e+000 ; -2.278656e+000 ; 6.955410e-002 ];
Tc_11  = [ 4.104164e+001 ; 3.286565e+001 ; 2.469128e+002 ];
omc_error_11 = [ 6.691636e-003 ; 1.279143e-002 ; 2.393229e-002 ];
Tc_error_11  = [ 2.909206e+000 ; 2.155291e+000 ; 5.204903e+000 ];

%-- Image #12:
omc_12 = [ 2.137872e+000 ; 2.291431e+000 ; 4.270782e-003 ];
Tc_12  = [ 5.701900e+001 ; 3.462493e+001 ; 2.349968e+002 ];
omc_error_12 = [ 1.127824e-002 ; 6.258402e-003 ; 2.391493e-002 ];
Tc_error_12  = [ 2.766381e+000 ; 2.075855e+000 ; 4.966236e+000 ];

%-- Image #13:
omc_13 = [ 2.246412e+000 ; 2.124267e+000 ; 6.374264e-002 ];
Tc_13  = [ -3.553134e+001 ; 4.550391e+001 ; 2.514603e+002 ];
omc_error_13 = [ 1.198462e-002 ; 8.451738e-003 ; 2.167951e-002 ];
Tc_error_13  = [ 2.971460e+000 ; 2.158655e+000 ; 5.415484e+000 ];

%-- Image #14:
omc_14 = [ -2.253131e+000 ; -2.023573e+000 ; -1.500813e-001 ];
Tc_14  = [ -7.210136e+001 ; -7.914890e+000 ; 2.455907e+002 ];
omc_error_14 = [ 9.858941e-003 ; 9.117891e-003 ; 2.100172e-002 ];
Tc_error_14  = [ 2.892113e+000 ; 2.153355e+000 ; 5.254171e+000 ];

%-- Image #15:
omc_15 = [ -1.875358e+000 ; -1.908968e+000 ; 2.553043e-001 ];
Tc_15  = [ -2.231326e+002 ; -8.908520e+001 ; 4.476534e+002 ];
omc_error_15 = [ 1.120801e-002 ; 7.047933e-003 ; 1.338088e-002 ];
Tc_error_15  = [ 5.546392e+000 ; 4.082124e+000 ; 9.292801e+000 ];

%-- Image #16:
omc_16 = [ -1.911317e+000 ; -2.046024e+000 ; -2.194383e-002 ];
Tc_16  = [ -1.855957e+002 ; 9.902362e-001 ; 3.801741e+002 ];
omc_error_16 = [ 9.646046e-003 ; 8.834114e-003 ; 1.482662e-002 ];
Tc_error_16  = [ 4.706809e+000 ; 3.442975e+000 ; 8.159092e+000 ];

%-- Image #17:
omc_17 = [ -1.919204e+000 ; -2.244811e+000 ; -2.997790e-001 ];
Tc_17  = [ -1.254145e+002 ; 5.715769e+001 ; 2.606909e+002 ];
omc_error_17 = [ 8.038375e-003 ; 1.070913e-002 ; 1.618027e-002 ];
Tc_error_17  = [ 3.176114e+000 ; 2.337126e+000 ; 5.704704e+000 ];

%-- Image #18:
omc_18 = [ 2.128324e+000 ; 2.179486e+000 ; 3.900836e-001 ];
Tc_18  = [ -4.555866e+001 ; -5.778623e+000 ; 1.198746e+002 ];
omc_error_18 = [ 7.415085e-003 ; 5.403148e-003 ; 1.478974e-002 ];
Tc_error_18  = [ 1.442945e+000 ; 1.062729e+000 ; 2.563386e+000 ];

%-- Image #19:
omc_19 = [ 2.162922e+000 ; 2.102269e+000 ; 4.634333e-001 ];
Tc_19  = [ -4.137427e+001 ; -2.890595e+001 ; 1.024499e+002 ];
omc_error_19 = [ 6.511375e-003 ; 5.077152e-003 ; 1.473974e-002 ];
Tc_error_19  = [ 1.253854e+000 ; 9.219567e-001 ; 2.163586e+000 ];

%-- Image #20:
omc_20 = [ 2.433564e+000 ; 1.924654e+000 ; -3.876678e-001 ];
Tc_20  = [ -2.979241e+002 ; 4.989455e+001 ; 6.419016e+002 ];
omc_error_20 = [ 1.199139e-002 ; 1.480311e-002 ; 2.478719e-002 ];
Tc_error_20  = [ 8.008095e+000 ; 5.822548e+000 ; 1.340637e+001 ];

