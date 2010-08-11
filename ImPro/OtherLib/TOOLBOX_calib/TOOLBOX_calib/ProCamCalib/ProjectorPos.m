%% step 1 load the camera intrinsic
 clear all;
 load Cam_Proj_calib ;
  fc_proj = fc;
 cc_proj = cc;
 kc_proj = kc;
alpha_c_proj = alpha_c;
nx_proj = nx;
ny_proj = ny;

 loading_calib; 
 alpha_c_cam = alpha_c;
 fc_cam = fc;
 cc_cam = cc;
 kc_cam =kc;
 nx_cam = nx;
 ny_cam = ny;
 
%% step 2 get the grid in image
getImgGrid ; 

%% step 3 compute_extrinsic from camera to plane

[omcCam,TcCam,RcCam,H] = compute_extrinsic(x,X,fc,cc,kc,alpha_c);

disp('Get Camera Extrinsic Parameter');
disp( TcCam);
disp( RcCam);

%% step 4 get the 3D point of the projector (mark the projected image)
 i = 1 ;
   display(['Processing Image number ' num2str(i)]);
    ProjectedGrid_2dpoints_cameraPlane = extract_grid(I,wintx,winty,fc,cc,kc,dX,dY);

    X_1 = obtain3Dpoints_from_knownPlane(KK,eye(4), RcCam , TcCam , ProjectedGrid_2dpoints_cameraPlane) ;
    X_2 = obtain3Dpoints_from_knownPlane(KK,eye(4), RcCam , TcCam , printed_grid) ;
     
Projected_name = input('Projected image name: ','s');
I = double(rgb2gray(imread(Projected_name)));
[ProjectedGrid_2dpoints_projectorFrame,dumb,n_sq_x,n_sq_y] = extract_grid(I);%,wintx,winty,fc,cc,kc,dX,dY);

  
%% step 5

xx = [] ;
XX = [] ;
xx = [ProjectedGrid_2dpoints_projectorFrame];  %  grid on the projected image  
XX = [X_1] ;

[omcProj,TcProj,RcProj,HProj] = compute_extrinsic(xx,XX,fc_proj,cc_proj,kc_proj,alpha_c_proj);

disp('Get Projector Extrinsic Parameter');

%% step 6 draw the 3D fig
drawProjectorPos ;



    