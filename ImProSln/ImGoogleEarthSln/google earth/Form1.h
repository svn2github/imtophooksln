#pragma once
#include <mshtml.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ARTagCameraDS.h"
#include <d3dx9math.h>
#include <vcclr.h>
#include "Streams.h"
#include "countAllData.h"

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

//double LeftTopLong = 121.564422;
//double LeftTopLat = 25.033828;
//double LeftDownLong = 121.564423;
//double LeftDownLat = 25.033341;
//double RightDownLong = 121.565153;
//double RightDownLat = 25.033338;


// Zoomout to 101
double LeftTopLong = 121.55607268966645;
double LeftTopLat = 25.041212573911324;
double LeftDownLong = 121.55607268966645;
double LeftDownLat = 25.025659005961995;
double RightDownLong = 121.57323882736176;
double RightDownLat = 25.025659005961995;

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

double clongitude = tlongitude;
double clatitude = tlatitude;
double caltitude = taltitude;
double ctilt = ttilt;
double cheading = theading;
double croll = troll;

double altitude_scale = 1.0;

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
float g_cvTrans[4][4];

namespace googleearth{
	ref class Form1;
};

gcroot<googleearth::Form1^> g_formPtr = NULL;
ARTagCameraDS* g_pARCam = NULL;

bool computeNeedData(float cvTrans[4][4]);
bool arTimerTickFunc();
bool animTimerTickFunc();


//create Google Earth Data class
countAllData GEData;


BOOL __stdcall ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	
	{
		CAutoLock lck(&g_State);
		for (int row = 0; row < 4; row++)
		{
			for(int col = 0; col < 4; col++)
			{
				GEData.g_cvTrans[row][col] = config->cvTrans[row][col];
			}
		}
	}

	getFstTag = true;

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
		private: static String^ ipAddress = "192.168.1.6";
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

			setupSocket();
						
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
			lookat.x = -camera.m[0][2];
			lookat.y = -camera.m[1][2];
			lookat.z = -camera.m[2][2];;
			D3DXVec3Normalize(&lookat, &lookat);
			int test = 0;
		}

		//計算lookat的垂直向量
		public: void countLookup(void)
		{
			lookup.x = camera.m[0][1];
			lookup.y = camera.m[1][1];
			lookup.z = camera.m[2][1];
			D3DXVec3Normalize(&lookup,&lookup);
		}

		//用z軸的向量與lookat的向量求夾角算出tilt的值
		public: void countTilt(void)
		{
			double cosin = 0;
			double arcosin = 0;

			D3DXVECTOR3 normalLookat;
		
			D3DXVec3Normalize(&normalLookat,&lookat);
			D3DXVECTOR3 viewDown(0, 0, -1);
			cosin = D3DXVec3Dot(&lookat,&viewDown);
			arcosin = acos(cosin);
			tilt = (double)180*(double)arcosin / (double)PI;
			int test = 0;
		}	

		//用y軸的向量與lookat的xy向量求夾角來計算heading的值
		public: void countHeading(void)
		{
			
			D3DXVECTOR3 lookatXY(lookat.x, lookat.y, 0);
			D3DXVec3Normalize(&lookatXY, &lookatXY);
			D3DXVECTOR3 north(0, 1, 0);
			double cosin = D3DXVec3Dot(&lookatXY, &north);
			double arccosin = acos(cosin);
			if (lookatXY.x < 0)
				arccosin = 2*D3DX_PI - arccosin;
			heading = (double)180*(double)arccosin / (double)PI;
			int test = 0;
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

			D3DXVec3Cross(&axis3, &lookat, &zaxis);
			D3DXVec3Cross(&origin_lookup,&axis3, &lookat);
			D3DXVec3Normalize(&origin_lookup,&origin_lookup);
			D3DXVec3Cross(&result,&origin_lookup,&lookup);

			cosin = D3DXVec3Dot(&lookup,&origin_lookup); 
		
			arcosin = acos(cosin);
			angle = (double)180*(double)arcosin / (double)PI;
			
			if(result.x * lookat.x <= 0 || result.y * lookat.y <=0)	roll = angle;
			else	roll = -angle;
			if (Double::IsNaN(roll))
			{
				int test = 0;
			}
		}

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
			this->webBrowser1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Form1::OnBrowsePreviewKeyDown);
			// 
			// animTimer
			// 
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
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::OnKeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::OnKeyDown);
			this->ResumeLayout(false);

		}

#pragma endregion
	
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

			 if(!getFstTag)		return;
				
			 else{

				double tmpcvTrans[4][4];
				{
					CAutoLock lck(&g_State);
					for (int row = 0; row < 4; row++)
					{
						for(int col = 0; col < 4; col++)
						{
							tmpcvTrans[row][col] = GEData.g_cvTrans[row][col];
						}
					}
				}

				getFstTag = false;

				GEData.computeNeedData(tmpcvTrans, LeftDownLong, LeftDownLat, LeftTopLong, LeftTopLat, RightDownLong, RightDownLat);	

				tlatitude = GEData.getLatitude();
				tlongitude = GEData.getLongitude();
				taltitude = GEData.getAltitude();
				theading = GEData.getHeading();
				ttilt = GEData.getTilt();
				troll = GEData.getRoll();

				D3DXVECTOR3 intersect_origin_point = GEData.getIntersect_origin_point();
				D3DXVECTOR3 intersect_point = GEData.getIntersect_point();

				double vspaceX = (double)intersect_origin_point.x / (double)1.33;
				double vspaceY = -intersect_origin_point.y;
				double lat = intersect_point.y;
				double lng = intersect_point.x;

				sendData("15,flashGE,tabletGE_1,geDebug," + vspaceX + "," + vspaceY + "," + lat + "," + lng);
				
				clatitude = tlatitude;
				clongitude = tlongitude;
				caltitude = taltitude;
				cheading = theading;
				ctilt = ttilt;
 				croll = troll;
			
			/*
			 double alpha = 0.2;
			 clatitude = clatitude*alpha + tlatitude*(1-alpha);
			 clongitude = clongitude*alpha + tlongitude*(1-alpha);
			 caltitude = caltitude*alpha + taltitude*(1-alpha);
			 cheading = cheading*alpha + theading*(1-alpha);
			 ctilt = ctilt*alpha + ttilt*(1-alpha);
 			 croll = croll*alpha + troll*(1-alpha);
			*/

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
				for (int i =0; i < 6; i++)
				{
					if (Double::IsNaN(para[i]))
					{
						return ;
					}
				}

				webBrowser1->Document->InvokeScript("cameraView",parameter);
			 }
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
private: System::Void OnKeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {


		 }
private: System::Void OnKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		 }
private: System::Void OnBrowsePreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
			 if (g_pARCam != NULL)
			 {
				 if (e->KeyCode == Keys::D1)
				 {
					 g_pARCam->ShowCamProp();
				 }
				 else if(e->KeyCode == Keys::D2)
				 {
					 g_pARCam->ShowCamPinProp();
				 }
				 else if(e->KeyCode == Keys::D3)
				 {
					 g_pARCam->ShowARProp();
				 }
			 }
		 }
};
}


bool animTimerTickFunc()
{
	try
	{
		if(!getFstTag)
			return false;

		clatitude = tlatitude;
		clongitude = tlongitude;
		caltitude = taltitude;
		cheading = theading;
		ctilt = ttilt;
		croll = troll;

		/*
		 double alpha = 0.2;
		 clatitude = clatitude*alpha + tlatitude*(1-alpha);
		 clongitude = clongitude*alpha + tlongitude*(1-alpha);
		 caltitude = caltitude*alpha + taltitude*(1-alpha);
		 cheading = cheading*alpha + theading*(1-alpha);
		 ctilt = ctilt*alpha + ttilt*(1-alpha);
		 croll = croll*alpha + troll*(1-alpha);
		*/

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


//bool computeNeedData(float cvTrans[4][4])
//{
//	char        string[256];
//	double det = 0;
//	D3DXMATRIX d3d_camTrans, matInvYZ, matSwitchYZ;
//	D3DXMatrixScaling(&matInvYZ, 1, -1, -1);
//
//	/*matSwitchYZ.m[0][0] = 0; matSwitchYZ.m[0][1] = 0; matSwitchYZ.m[0][2] = 1; matSwitchYZ.m[0][3] = 0; 
//	matSwitchYZ.m[1][0] = 1; matSwitchYZ.m[1][1] = 0; matSwitchYZ.m[1][2] = 0; matSwitchYZ.m[1][3] = 0; 
//	matSwitchYZ.m[2][0] = 0; matSwitchYZ.m[2][1] = 1; matSwitchYZ.m[2][2] = 0; matSwitchYZ.m[2][3] = 0; 
//	matSwitchYZ.m[3][0] = 0; matSwitchYZ.m[3][1] = 0; matSwitchYZ.m[3][2] = 0; matSwitchYZ.m[3][3] = 1; 
//*/
//
//	D3DXMatrixIdentity(&d3d_camTrans);
//
//	for (int row = 0; row < 4; row ++)
//	{
//		for (int col = 0; col < 4; col++)
//		{
//			d3d_camTrans.m[col][row] = cvTrans[row][col];
//		}
//	}
//
//	d3d_camTrans = d3d_camTrans * matInvYZ;
//
//	
//	camera = d3d_camTrans;
//	//from right hand to left hand
//	
//	//計算google earth中需要的各個參數
//	countLoc(-camera.m[3][0], -camera.m[3][2], -camera.m[3][1]);
//	countLookat();
//	countLookup();
//	countTilt();
//	countHeading();
//	countRoll();
//	/*WCHAR str[MAX_PATH] = {0};
//	
//	OutputDebugStringW(L"@@@@@@@@@@@@\n");
//	swprintf_s(str, MAX_PATH, L"@@@@ lookat = ( %.2f, %.2f, %.2f) \n", 
//		lookat.x, lookat.y, lookat.z);
//	OutputDebugStringW(str);
//	swprintf_s(str, MAX_PATH, L"@@@@ ViewUp = ( %.2f, %.2f, %.2f) \n", 
//		lookup.x, lookup.y, lookup.z);
//	OutputDebugStringW(str);
//	swprintf_s(str, MAX_PATH, L"@@@@ Tilt, Heading, Roll = ( %.2f, %.2f, %.2f) \n", 
//		tilt, heading, roll);
//	OutputDebugStringW(str);
//	OutputDebugStringW(L"@@@@@@@@@@@@\n");
//	*/
//	longitude = google_earth_point.x;
//	latitude = google_earth_point.z;
//	altitude = google_earth_point.y;
//	altitude *= 111000;  //一度 = 111000 公尺
//	altitude *= altitude_scale;
//
//	return true;
//}