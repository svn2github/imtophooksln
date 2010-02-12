#pragma once
#include <mshtml.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif
#include "ARTagCameraDS.h"
/*#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>*/
//#include "draw_object.h"
#include <d3dx9math.h>
#include <vcclr.h>
#include "Streams.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Timers;
using namespace System::Net::Sockets;
/* set up the video format globals */

#ifdef _WIN32
char    *vconf = "Data\\WDM_camera_flipV.xml";
#else
char    *vconf = "";
#endif

#define PI 3.1416

D3DXVECTOR3 lookat;  //camera看的方向的vector
D3DXVECTOR3 lookup;  //camera的 up vector
D3DXVECTOR3 origin_lookup;  //原始的camera up vector
D3DXVECTOR3 google_earth_point;
D3DXMATRIX camera;

CCritSec g_State;
double LeftTopLong = 121.564422;
double LeftTopLat = 25.033828;
double LeftDownLong = 121.564423;
double LeftDownLat = 25.033341;
double RightDownLong = 121.565153;
double RightDownLat = 25.033338;

double longitude = 0;
double latitude = 0;
double altitude = 0;
double tilt = 0;
double heading = 0;
double roll = 0;

double tlongitude = 0;
double tlatitude = 0;
double taltitude = 0;
double ttilt = 0;
double theading = 0;
double troll = 0;

double clongitude = 0;
double clatitude = 0;
double caltitude = 0;
double ctilt = 0;
double cheading = 0;
double croll = 0;

double altitude_scale = 0.8;

bool getFstTag = false;

int             xsize;
int             ysize;
int             thresh = 100;
//ARParam         cparam;
int             outputMode = 0;

int             mouse_ox;
int             mouse_oy;
int             mouse_st = 0;
int             disp_mode = 1;
double          a =   0.0;
double          b = -45.0;
double          r = 500.0;

int             target_id;
double          target_center[2] = {0.5, 0.5};
double          target_width = 1.0;
//double          target_center[2] = {0, 0};
//double          target_width = 80.0;
namespace googleearth{
	ref class Form1;
};
gcroot<googleearth::Form1^> g_formPtr = NULL;
ARTagCameraDS* g_pARCam = NULL;
bool computeNeedData(int numDetected, const ARMarkerInfo* markinfos,  const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[]);
bool arTimerTickFunc();
bool animTimerTickFunc();

BOOL __stdcall ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	CAutoLock lck(&g_State);

	computeNeedData(numDetected, markinfos, config, matView, matProj, argc, argv);	
	arTimerTickFunc();
	//animTimerTickFunc();
	return TRUE;
}


bool arTimerTickFunc()
{
	

	// set target camera
	tlatitude = latitude;
	tlongitude = longitude;
	taltitude = altitude;
	theading = heading;
	ttilt = tilt;
	troll = roll;

	if(!getFstTag){
		clatitude = tlatitude;
		clongitude = tlongitude;
		caltitude = taltitude;
		cheading = theading;
		ctilt = ttilt;
		croll = troll;
		double para[6] = {clatitude, clongitude, caltitude, cheading, ctilt, croll};
		for (int i =0; i<6; i++)
		{
			if (Double::IsNaN(para[i]))
			{
				int test = 0;
			}
		}
		getFstTag = true;
	}
	return true;
}



namespace googleearth {



	//using namespace System::Windows::Forms::HtmlDocument;
	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

		// variables for socket connection
		private: static System::Net::Sockets::TcpClient^ tcpClient;
		private: static System::Net::Sockets::NetworkStream^ GetNetworkStream;
		private: static System::AsyncCallback^ GetCallbackReadMethod;
		private: static String^ ipAddress = "192.168.1.26";
		private: static Int32 port = 5000;
	private: System::Windows::Forms::Timer^  animTimer;


	private: static array<Byte>^ GetRawBuffer; // Buffer to store the response bytes.	

	public:

		Form1(void)
		{

			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			
			//full screen mode
			//setFullScreen();			
			g_formPtr = this;
			setupBrowser();
			
			setupArtoolkit();

			//setupSocket();
			
		}

		private: System::Void setFullScreen(){
			if(this->FormBorderStyle == System::Windows::Forms::FormBorderStyle::Sizable){
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->Bounds = System::Windows::Forms::Screen::PrimaryScreen->Bounds;
				this->TopMost = true;
			}				 
		}

		private: System::Void setupBrowser(){
			String^ URL = "file:///C:/googleEarth.html";
			this->webBrowser1->Navigate(URL);
		}

		private: System::Void setupArtoolkit()
				 {
			//if( init() < 0 ) 
			//	exit(0);
			//arVideoCapStart();

			//this->arTimer->Start();
					 if (g_pARCam == NULL)
					 {
						g_pARCam = new ARTagCameraDS();			
					 }
					
					 g_pARCam->OpenCamera(0,true);
					
					 g_pARCam->SetARCallback(ARTagCallback, 0, NULL);
					 g_pARCam->Play();
					 this->animTimer->Start();
				}
		
		private: System::Void setupSocket(){

			// Attempt to establish a connection
			tcpClient = gcnew TcpClient(ipAddress ,port );
			GetNetworkStream = tcpClient->GetStream();
			
			
			// Set these socket options
			tcpClient->ReceiveBufferSize = 1048576;
            tcpClient->SendBufferSize = 1048576;
            tcpClient->NoDelay = true;
			tcpClient->LingerState = gcnew System::Net::Sockets::LingerOption(false, 0);
			
			GetRawBuffer = gcnew array<Byte>(1024);
			GetCallbackReadMethod = gcnew AsyncCallback( &Form1::ReceiveComplete);

            // Start to receive messages
            Receive();
			
			// register to TcpServer.
			sendData("11,tabletGE_1");		 
			 
		}

        //**********************************************
        /// <summary> Wait for a message to arrive </summary>
		private: static System::Void Receive(){

            if ((GetNetworkStream != nullptr) && (GetNetworkStream->CanRead))
            {
                // Issue an asynchronous read
				GetNetworkStream->BeginRead(GetRawBuffer, 0, GetRawBuffer->Length, GetCallbackReadMethod, GetNetworkStream);
            }
			else{
				//throw gcnew System::Exception("Socket Closed");
				Console::WriteLine( "Sorry.  You cannot read from this NetworkStream." );
			}
		}

        //*********************************************
        /// <summary> Called when a message arrives </summary>
        /// <param name="ar"> RefType: An async result interface </param>				 
		private: static System::Void ReceiveComplete(System::IAsyncResult ^ar){
			// Is the Network Stream object valid
			if (GetNetworkStream->CanRead){
				// Read the current bytes from the stream buffer
                Int32 iBytesRecieved = GetNetworkStream->EndRead(ar);
                // If there are bytes to process else the connection is lost			
				if (iBytesRecieved > 0){
					
					MessageHandler(iBytesRecieved);
					Receive();
				}
					// Wait for a new message
					

			}
		}

		private: static System::Void MessageHandler(Int32 iNumberOfBytes){

			// Find a complete message
			String^ strMessage = System::Text::ASCIIEncoding::ASCII->GetString(GetRawBuffer, 0, iNumberOfBytes);			

			// 15,csGE,flashGE,11,p1x,p1y,..
			//array<String>^ data = strMessage->Split(',');
			array<String^>^cmds = strMessage->Split(',');
			
			if(cmds!=nullptr && cmds->Length == 10){			

				double leftTopLat = System::Double::Parse(cmds[4]);
				double leftTopLong = System::Double::Parse(cmds[5]);
				double leftDownLat = System::Double::Parse(cmds[6]);
				double leftDownLong = System::Double::Parse(cmds[7]);
				double rightDownLat = System::Double::Parse(cmds[8]);
				double rightDownLong = System::Double::Parse(cmds[9]);
				set_4_point(leftTopLong, leftTopLat, leftDownLong, leftDownLat, rightDownLong, rightDownLat);
			}
			
		}

		// Translate the passed message into ASCII and store it as a Byte array.
		private: System::Void sendData (String^ message) {
			array<Byte>^data = System::Text::Encoding::ASCII->GetBytes( message );
			GetNetworkStream->Write( data, 0, data->Length );
		}


		//設定tag對應的四個點經緯度位置(左上、左下、右下)
		static void set_4_point(double LTLong,double LTLat,double LDLong,double LDLat,double RDLong,double RDLat)
		{
			LeftTopLong = LTLong;
			LeftTopLat = LTLat;
			LeftDownLong = LDLong;
			LeftDownLat = LDLat;
			RightDownLong = RDLong;
			RightDownLat = RDLat;
		}

		//計算camera在tag座標系中的位置(tag左下角為(0,0))
		public: void countLoc(double x,double y,double z)
		{
			D3DXMATRIX Transform;

			D3DXVECTOR3 eye;
			D3DXVECTOR3 X;
			D3DXVECTOR3 Y;
			D3DXVECTOR3 Z;
			D3DXVECTOR3 marker_point;
			marker_point.x = x;
			marker_point.y = y;
			marker_point.z = z;
	
			eye.x = LeftDownLong;
			eye.y = 0;
			eye.z = LeftDownLat;
	
			X.x = RightDownLong - LeftDownLong;
			X.y = 0;
			X.z = RightDownLat - LeftDownLat;

			//D3DXVec3Cross(&Y,&X,&Z);

			Y.x = 0;
			Y.y = RightDownLong - LeftDownLong;
			Y.z = 0;

			Z.x = LeftTopLong - LeftDownLong;
			Z.y = 0;
			Z.z = LeftTopLat - LeftDownLat;

			Transform._11 = X.x;
			Transform._12 = Y.x;
			Transform._13 = Z.x;
			Transform._14 = 0;

			Transform._21 = X.y;
			Transform._22 = Y.y;
			Transform._23 = Z.y;
			Transform._24 = 0;

			Transform._31 = X.z;
			Transform._32 = Y.z;
			Transform._33 = Z.z;
			Transform._34 = 0;

			Transform._41 = eye.x;
			Transform._42 = eye.y;
			Transform._43 = eye.z;
			Transform._44 = 1;

			D3DXVec3TransformCoord(&google_earth_point,&marker_point,&Transform);

		}

		//計算lookat的向量(camera看的方向)
		public: void countLookat(void)
		{
			D3DXVECTOR3 lookat000;
			D3DXVECTOR3 lookat001;
	
			D3DXVECTOR3 temp;
			temp.x = 0;
			temp.y = 0;
			temp.z = 0;
			D3DXVec3TransformCoord(&lookat000,&temp,&camera);

			temp.x = 0;
			temp.y = 0;
			temp.z = 1;
			D3DXVec3TransformCoord(&lookat001,&temp,&camera);

			lookat.x = lookat001.x - lookat000.x;
			lookat.y = lookat001.y - lookat000.y;
			lookat.z = lookat001.z - lookat000.z;

		}

		//計算lookat的垂直向量
		//計算lookat的垂直向量
		public: void countLookup(void)
		{
			D3DXVECTOR3 lookup000;
			D3DXVECTOR3 lookup010;
	
			D3DXVECTOR3 temp;
			
			temp.x = 0;
			temp.y = 0;
			temp.z = 0;
			D3DXVec3TransformCoord(&lookup000,&temp,&camera);

			temp.x = 0;
			temp.y = 1;
			temp.z = 0;
			D3DXVec3TransformCoord(&lookup010,&temp,&camera);

			/*lookup.x = lookup010.x - lookup000.x;
			lookup.y = lookup010.y - lookup000.y;
			lookup.z = lookup010.z - lookup000.z;*/

			lookup.x = lookup000.x - lookup010.x;
			lookup.y = lookup000.y - lookup010.y;
			lookup.z = lookup000.z - lookup010.z;

			D3DXVec3Normalize(&lookup,&lookup);
		}

		//用z軸的向量與lookat的向量求夾角算出tilt的值
		public: void countTilt(void)
		{
			D3DXVECTOR3 normal;

			double dist_lookat = 0;
			double cosin = 0;
			double arcosin = 0;

			normal.x = 0;
			normal.y = 0;
			normal.z = -1;

			dist_lookat = (double)sqrt( (double)pow((double)lookat.x,2)+(double)pow((double)lookat.y,2)+(double)pow((double)lookat.z,2) );
	
			cosin = (double)D3DXVec3Dot(&lookat,&normal) / (double)dist_lookat; 
			arcosin = acos(cosin);
	
			tilt = (double)180*(double)arcosin / (double)PI;

		}	

		//用y軸的向量與lookat的xy向量求夾角來計算heading的值
		public: void countHeading(void)
		{
			D3DXVECTOR3 yaxis;
			D3DXVECTOR3 lookatXY;
			D3DXVECTOR3 result;
			double angle = 0;
			double dist_lookatXY = 0;
			double cosin = 0;
			double arcosin = 0;

			yaxis.x = 0;
			yaxis.y = 1;
			yaxis.z = 0;

			lookatXY.x = lookat.x;
			lookatXY.y = lookat.y;
			lookatXY.z = 0;

			/*testxy.x = lookat.x;
			testxy.y = lookat.y;
			testxy.z = 0;*/
		
			//D3DXVec3Cross(&test,&yaxis,&testxy);
			D3DXVec3Cross(&result,&yaxis,&lookatXY);

			dist_lookatXY = (double)sqrt( (double)pow((double)lookatXY.x,2)+(double)pow((double)lookatXY.y,2)+(double)pow((double)lookatXY.z,2) );
			if (dist_lookatXY == 0)
			{
				return;
			}
			cosin = (double)D3DXVec3Dot(&lookat,&yaxis) / (double)dist_lookatXY; 
			arcosin = acos(cosin);
	
			angle = (double)180*(double)arcosin / (double)PI;

			if(result.z <= 0)	heading = angle;
			else	heading = (double)360 - (double)angle;
			if (Double::IsNaN(heading))
			{
				int test = 0 ;
			}
		}

		public: void countRoll(void)
		{
			D3DXVECTOR3 zaxis;
			D3DXVECTOR3 axis3;
			D3DXVECTOR3 result;
	
			double dist_lookup = 0;
			double dist_origin_lookup = 0;
			double cosin = 0;
			double arcosin = 0;
			double angle = 0;

			zaxis.x = 0;
			zaxis.y = 0;
			zaxis.z = 1;

			D3DXVec3Cross(&axis3,&zaxis,&lookat);
			D3DXVec3Cross(&origin_lookup,&lookat,&axis3);
			D3DXVec3Normalize(&origin_lookup,&origin_lookup);

			D3DXVec3Cross(&result,&origin_lookup,&lookup);

			dist_lookup = (double)sqrt( (double)pow((double)lookup.x,2)+(double)pow((double)lookup.y,2)+(double)pow((double)lookup.z,2) );
			dist_origin_lookup = (double)sqrt( (double)pow((double)origin_lookup.x,2)+(double)pow((double)origin_lookup.y,2)+(double)pow((double)origin_lookup.z,2) );

			cosin = (double)D3DXVec3Dot(&lookup,&origin_lookup) / (double)dist_lookup*(double)dist_origin_lookup; 
			if (cosin <-1 || cosin > 1)
			{
				return;
			}
			else
			{
				arcosin = acos(cosin);
				angle = (double)180*(double)arcosin / (double)PI;
			}
			if(result.x * lookat.x <= 0 || result.y * lookat.y <=0)	roll = angle;
			else	roll = -angle;
			if (Double::IsNaN(roll))
			{
				int test = 0;
			}
		}
//
//void mainLoop(void)
//{
//	ARUint8         *dataPtr;
//    ARMarkerInfo    *marker_info;
//    int             marker_num;
//    int             j, k;
//
//    /* grab a vide frame */
//    if( (dataPtr = (ARUint8 *)arVideoGetImage()) == NULL ) {
//        arUtilSleep(2);
//        return;
//    }
//
//    //glClearColor( 0.0, 0.0, 0.0, 0.0 );
//    //glClearDepth( 1.0 );
//    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    argDrawMode2D();
//    if( disp_mode ) {
//        argDispImage( dataPtr, 0, 0 );
//    }
//    else {
//        argDispImage( dataPtr, 1, 1 );
//    }
//
//    /* detect the markers in the video frame */
//    if( arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0 ) {
//        cleanup();
//        exit(0);
//    }
//    arVideoCapNext();
//
//    /* if the debug mode is on draw squares 
//       around the detected squares in the video image */
//    if( arDebug ) {
//        if( arImageProcMode == AR_IMAGE_PROC_IN_HALF )
//            argDispHalfImage( arImage, 2, 1 );
//        else
//            argDispImage( arImage, 2, 1);
//    }
//
//    /* check for object visibility */
//    k = -1;
//    for( j = 0; j < marker_num; j++ ) {
//        if( marker_info[j].id == target_id ) {
//            if( k == -1 ) k = j;
//            else {
//                if( marker_info[k].cf < marker_info[j].cf ) k = j;
//            }
//        }
//    }
//	if( k != -1 ) {
//        glDisable(GL_DEPTH_TEST);
//        switch( outputMode ) {
//            case 0:
//                getResultRaw( &marker_info[k] );
//                break;
//            case 1:
//                getResultQuat( &marker_info[k] );
//                break;
//        }
//    }
//
//    argSwapBuffers();
//}
//
//void getResultRaw( ARMarkerInfo *marker_info )
//{
//    double      target_trans[3][4];
//    double      cam_trans[3][4];
//    char        string[256];
//	double det = 0;
//
//	//cam_trans矩陣資料將camera的位置轉成世界座標 =>求出camera在tag座標系中的位置
//    if( arGetTransMat(marker_info, target_center, target_width, target_trans) < 0 ) return;
//    if( arUtilMatInv(target_trans, cam_trans) < 0 ) return;
//
//	//將openGL中的矩陣(column major)轉成directX中的矩陣(row major)
//	camera._11 = cam_trans[0][0];
//	camera._12 = cam_trans[1][0]; 
//	camera._13 = cam_trans[2][0];
//	camera._14 = 0;
//	camera._21 = cam_trans[0][1];
//	camera._22 = cam_trans[1][1];
//	camera._23 = cam_trans[2][1];
//	camera._24 = 0;
//	camera._31 = cam_trans[0][2];
//	camera._32 = cam_trans[1][2];
//	camera._33 = cam_trans[2][2];
//	camera._34 = 0;
//	camera._41 = cam_trans[0][3];
//	camera._42 = cam_trans[1][3];
//	camera._43 = cam_trans[2][3];
//	camera._44 = 1;
//
//	//計算google earth中需要的各個參數
//	countLoc(cam_trans[0][3],cam_trans[2][3],cam_trans[1][3]);
//	countLookat();
//	countLookup();
//	countTilt();
//	countHeading();
//	countRoll();
//
//	longitude = google_earth_point.x;
//	latitude = google_earth_point.z;
//	altitude = google_earth_point.y;
//	altitude *= 111000;  //一度 = 111000 公尺
//	altitude *= altitude_scale;
//
//	sprintf(string," RAW: Cam Pos x: %f  y: %f  z: %f\n long:%f alt:%f lat:%f\n tilt:%f heading:%f roll:%f \n",
//		cam_trans[0][3], cam_trans[1][3], cam_trans[2][3],longitude,altitude,latitude,tilt,heading,roll);
//
//	return;
//}
//
//void getResultQuat( ARMarkerInfo *marker_info )
//{
//    double      target_trans[3][4];
//    double      cam_trans[3][4];
//    double      quat[4], pos[3];
//    char        string1[256];
//    char        string2[256];
//
//    if( arGetTransMat(marker_info, target_center, target_width, target_trans) < 0 ) return;
//    if( arUtilMatInv(target_trans, cam_trans) < 0 ) return;
//    if( arUtilMat2QuatPos(cam_trans, quat, pos) < 0 ) return;
//
//    sprintf(string1," QUAT: Pos x: %3.1f  y: %3.1f  z: %3.1f\n",
//            pos[0], pos[1], pos[2]);
//    sprintf(string2, "      Quat qx: %3.2f qy: %3.2f qz: %3.2f qw: %3.2f ",
//            quat[0], quat[1], quat[2], quat[3]);
//    strcat( string1, string2 );
//
//    return;
//}
//
//int init(void)
//{
//    char     cparaname[256];
//    char     pattname[256];
//    ARParam  wparam;
//
//    strcpy( cparaname, "Data/camera_para.dat" );
//    strcpy( pattname,  "Data/patt.hiro" );
//    
//    /* open the video path */
//    if( arVideoOpen( vconf ) < 0 ) exit(0);
//    /* find the size of the window */
//    if( arVideoInqSize(&xsize, &ysize) < 0 ) exit(0);
//    printf("Image size (x,y) = (%d,%d)\n", xsize, ysize);
//
//    /* set the initial camera parameters */
//    if( arParamLoad(cparaname, 1, &wparam) < 0 ) {
//       printf("Camera parameter load error !!\n");
//        exit(0);
//    }
//    arParamChangeSize( &wparam, xsize, ysize, &cparam );
//    arInitCparam( &cparam );
//    printf("*** Camera Parameter ***\n");
//    arParamDisp( &cparam );
//
//    /* open the graphics window */
//    argInit( &cparam, 1.0, 0, 2, 1, 0 );
//
//    if( (target_id = arLoadPatt(pattname)) < 0 ) {
//        printf("Target pattern load error!!\n");
//        exit(0);
//    }
//
//    arDebug = 0;
//
//    return 0;
//}			
//
//void cleanup(void)
//{
//    arVideoCapStop();
//    arVideoClose();
//    argCleanup();
//}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			if (g_pARCam != NULL)
			{
				g_pARCam->Stop();
				delete g_pARCam;
				g_pARCam = NULL;
			}
		}

	public: System::Windows::Forms::WebBrowser^  webBrowser1;
	//private: System::Windows::Forms::Timer^  arTimer;
	private: System::ComponentModel::IContainer^  components;
	private: static int temp = 300;

	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			//this->arTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->animTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(0, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(628, 334);
			this->webBrowser1->TabIndex = 0;
			// 
			// arTimer
			// 
			//this->arTimer->Interval = 30;
			//this->arTimer->Tick += gcnew System::EventHandler(this, &Form1::arTimer_Tick);
			//// 
			//// animTimer
			//// 
			this->animTimer->Interval = 30;
			this->animTimer->Tick += gcnew System::EventHandler(this, &Form1::animTimer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 334);
			this->Controls->Add(this->webBrowser1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}

#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 array<Object^>^ parameter = gcnew array<Object^>(6); 

				 parameter[0] = latitude;
				 parameter[1] = longitude;
				 parameter[2] = altitude;
				 parameter[3] = heading;
				 parameter[4] = tilt;
				 parameter[5] = roll;

				 webBrowser1->Document->InvokeScript("cameraView",parameter);
				
			 }

	
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //this->arTimer->Start();
		 }


		private: System::Void arTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			 //mainLoop();	
			 
			 // set target camera
			 tlatitude = latitude;
			 tlongitude = longitude;
			 taltitude = altitude;
			 theading = heading;
			 ttilt = tilt;
			 troll = roll;
	         
			 if(!getFstTag){
				 clatitude = tlatitude;
				 clongitude = tlongitude;
				 caltitude = taltitude;
				 cheading = theading;
				 ctilt = ttilt;
 				 croll = troll;

				 getFstTag = true;
			 }
		}

		private: System::Void animTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			CAutoLock lck(&g_State);
			if(!getFstTag)
				return;
			 
			/*
			 clatitude = tlatitude;
			 clongitude = tlongitude;
			 caltitude = taltitude;
			 cheading = theading;
			 ctilt = ttilt;
 			 croll = troll;
			*/

			 double alpha = 0.2;
			 clatitude = clatitude*alpha + tlatitude*(1-alpha);
			 clongitude = clongitude*alpha + tlongitude*(1-alpha);
			 caltitude = caltitude*alpha + taltitude*(1-alpha);
			 cheading = cheading*alpha + theading*(1-alpha);
			 ctilt = ctilt*alpha + ttilt*(1-alpha);
 			 croll = croll*alpha + troll*(1-alpha);


			/*
			 // calculate current camera
			 clatitude += ((tlatitude - clatitude)/2);
			 clongitude += ((tlongitude - clongitude)/2);
			 caltitude += ((taltitude - caltitude)/2);
			 cheading += ((theading - cheading)/2);
			 ctilt += ((ttilt - ctilt)/2);
 			 croll += ((troll - croll)/2);
			 */ 

			 array<Object^>^ parameter = gcnew array<Object^>(6); 
			
			 parameter[0] = clatitude;
			 parameter[1] = clongitude;
			 parameter[2] = caltitude;
			 parameter[3] = cheading;
			 parameter[4] = ctilt;
			 parameter[5] = croll;
			 double para[6] = {clatitude, clongitude, caltitude, cheading, ctilt, croll};
			 for (int i =0; i<6; i++)
			 {
				 if (Double::IsNaN(para[i]))
				 {
					 return ;
				 }
			 }
			 webBrowser1->Document->InvokeScript("cameraView",parameter);
		}

		private: System::Void zoomInBtn_Click(System::Object^  sender, System::EventArgs^  e) {		
			altitude_scale -= 0.1;
			if(altitude_scale < 0)
				altitude_scale = 0;

		}
		private: System::Void zoomoutBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			altitude_scale += 0.1;
			if(altitude_scale > 1.0)
				altitude_scale = 1.0;
		 
		}
};
}


bool animTimerTickFunc()
{
	try
	{
		if(!getFstTag)
			return false;

		 double alpha = 0.2;
		 clatitude = clatitude*alpha + tlatitude*(1-alpha);
		 clongitude = clongitude*alpha + tlongitude*(1-alpha);
		 caltitude = caltitude*alpha + taltitude*(1-alpha);
		 cheading = cheading*alpha + theading*(1-alpha);
		 ctilt = ctilt*alpha + ttilt*(1-alpha);
		 croll = croll*alpha + troll*(1-alpha);

		 array<Object^>^ parameter = gcnew array<Object^>(6); 
		 parameter[0] = clatitude;
		 parameter[1] = clongitude;
		 parameter[2] = caltitude;
		 parameter[3] = cheading;
		 parameter[4] = ctilt;
		 parameter[5] = croll;
		 System::Windows::Forms::WebBrowser^ browser = g_formPtr->webBrowser1;
		 browser->Document->InvokeScript("cameraView",parameter);
	}

	catch (System::Exception^ e)
	{
		return false;
	}

	return true;
}


bool computeNeedData(int numDetected, const ARMarkerInfo* markinfos,  const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	
	double      target_trans[3][4];
	double      cam_trans[3][4];
	char        string[256];
	double det = 0;
	D3DXMATRIX d3dTarget_trans, d3d_camTrans;
	D3DXMatrixIdentity(&d3dTarget_trans);
	D3DXMatrixIdentity(&d3d_camTrans);
	for (int row = 0; row < 3; row ++)
	{
		for (int col =0; col < 4; col++)
		{
			target_trans[row][col] = config->cvTrans[row][col];
			d3dTarget_trans.m[col][row] = config->cvTrans[row][col];
		}
	}
	D3DXMatrixInverse(&d3d_camTrans, NULL, &d3dTarget_trans);
	for (int row = 0; row < 3; row ++)
	{
		for (int col =0; col < 4; col++)
		{
			cam_trans[row][col] = d3d_camTrans.m[col][row];

		}
	}
	WCHAR str[MAX_PATH] = {0};
	OutputDebugStringW(L"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");	
	swprintf_s(str, MAX_PATH, L"@@@@@ target_tran: %.2f, %.2f, %.2f, %.2f \n",target_trans[0][0], target_trans[0][1], target_trans[0][2], target_trans[0][3]);
	OutputDebugStringW(str);
	swprintf_s(str, MAX_PATH, L"@@@@@              %.2f, %.2f, %.2f, %.2f \n",target_trans[1][0], target_trans[1][1], target_trans[1][2], target_trans[1][3]);
	OutputDebugStringW(str);
	swprintf_s(str, MAX_PATH, L"@@@@@              %.2f, %.2f, %.2f, %.2f \n",target_trans[2][0], target_trans[2][1], target_trans[2][2], target_trans[2][3]);
	OutputDebugStringW(str);
	OutputDebugStringW(L"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");	
	//將openGL中的矩陣(column major)轉成directX中的矩陣(row major)
	camera._11 = cam_trans[0][0];
	camera._12 = cam_trans[1][0]; 
	camera._13 = cam_trans[2][0];
	camera._14 = 0;
	camera._21 = cam_trans[0][1];
	camera._22 = cam_trans[1][1];
	camera._23 = cam_trans[2][1];
	camera._24 = 0;
	camera._31 = cam_trans[0][2];
	camera._32 = cam_trans[1][2];
	camera._33 = cam_trans[2][2];
	camera._34 = 0;
	camera._41 = cam_trans[0][3];
	camera._42 = cam_trans[1][3];
	camera._43 = cam_trans[2][3];
	camera._44 = 1;

	//計算google earth中需要的各個參數
	g_formPtr->countLoc(cam_trans[0][3],cam_trans[2][3],cam_trans[1][3]);
	g_formPtr->countLookat();
	g_formPtr->countLookup();
	g_formPtr->countTilt();
	g_formPtr->countHeading();
	g_formPtr->countRoll();

	longitude = google_earth_point.x;
	latitude = google_earth_point.z;
	altitude = google_earth_point.y;
	altitude *= 111000;  //一度 = 111000 公尺
	altitude *= altitude_scale;

	sprintf(string," RAW: Cam Pos x: %f  y: %f  z: %f\n long:%f alt:%f lat:%f\n tilt:%f heading:%f roll:%f \n",
		cam_trans[0][3], cam_trans[1][3], cam_trans[2][3],longitude,altitude,latitude,tilt,heading,roll);
	return true;
}