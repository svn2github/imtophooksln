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
#include "GEPosition.h"
#include "GEPlaneIntersection.h"


#define RANGE_SCALE 1.7
#define BASE_BOUNDARY 0.01223

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Timers;
using namespace System::Net::Sockets;

//using namespace SocketSystem;
/* set up the video format globals */

#ifdef _WIN32
char    *vconf = "Data\\WDM_camera_flipV.xml";
#else
char    *vconf = "";
#endif

#define PI 3.1416

CCritSec g_State;

// New York
//double LeftTopLong = -74.013908;
//double LeftTopLat = 40.711236;
//double LeftDownLong = -74.016356;
//double LeftDownLat = 40.704047;
//double RightDownLong = -74.006875;
//double RightDownLat = 40.704129;
//double RightTopLong = -74.005278;
//double RightTopLat = 40.711096;

// Taipei 101
double LeftTopLong = 121.561008; //-200
double LeftTopLat = 25.035922;
double LeftDownLong = 121.561208;
double LeftDownLat = 25.025659005961995;
double RightTopLong = 121.57323882736176;
double RightTopLat = 25.035922;
double RightDownLong = 121.57323882736176;
double RightDownLat = 25.025659005961995;

// LA Convention Center
//double LeftTopLong = -118.277872;
//double LeftTopLat = 34.047147;
//double LeftDownLong = -118.277872;
//double LeftDownLat = 34.033955;
//double RightTopLong = -118.260622;
//double RightTopLat = 34.047147;
//double RightDownLong = -118.260622;
//double RightDownLat = 34.033955;

double altitude_scale = 1.0;

// bool
bool cameraMoved = false;
bool view_polygon_initialized = false;
bool view_ground_initialized = false;
bool boundaryMoved = false;
bool SVInitialized = false;

// test parameter
int BulidingCount = 0;

namespace googleearth{
	ref class Form1;
};

gcroot<googleearth::Form1^> g_formPtr = NULL;
ARTagCameraDS* g_pARCam = NULL;


//create Google Earth Data class//
GEPosition GEData;
//////////////////////////////////

GEPlaneIntersection good;


D3DXPLANE test;

D3DXVECTOR3 point1;
D3DXVECTOR3 point2;
D3DXVECTOR3 point3;


//get the coordinate of the camera relative to the ARTag
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

	cameraMoved = true;

	return TRUE;
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
		private: System::Net::Sockets::TcpClient^ tcpClient;
		private: static System::Net::Sockets::NetworkStream^ GetNetworkStream;
		private: static System::AsyncCallback^ GetCallbackReadMethod;
		private: String^ ipAddress;
		private: Int32 port;
		private: String^ htmlFile;		
	    private: static String^ tabletName;
		private: System::Windows::Forms::Timer^  animTimer;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button1;

		//private : CSocketClient^ socketClient;;
		private : delegate System::Void updateCallback(System::String^ text);


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

			// test plane
			point1.x = 120;
			point1.y = 24;
			point1.z = (double)10/(double)111000;
			point2.x = 120;
			point2.y = 26;
			point2.z = (double)10/(double)111000;
			point3.x = 122;
			point3.y = 26;
			point3.z = (double)10/(double)111000;
			D3DXPlaneFromPoints(&test,&point1,&point2,&point3);
			//////////////////////////////////////////////////////////////////////////

			image1 = gcnew System::Drawing::Bitmap("C:/3D.jpg");
			image2 = gcnew System::Drawing::Bitmap("C:/2D.jpg");
			button2->BackgroundImage = image1;

			g_formPtr = this;
			
			// read parameters ip, port, tabletID from setting.txt
			loadParamsFromFile();

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

		private: System::Void loadParamsFromFile(){
			String^ line;
			System::IO::StreamReader^ file = gcnew System::IO::StreamReader(".\\setting.txt");
			
			// read parameters ip, port, tabletID
			line = file->ReadLine();
			String^ _ip = line->Split(' ')[1];
			line = file->ReadLine();
			String^ _port = line->Split(' ')[1];
			line = file->ReadLine();
			String^ _tabletID = line->Split(' ')[1];
			line = file->ReadLine();
			String^ _tabletResWidth = line->Split(' ')[1];
			line = file->ReadLine();
			String^ _tabletResHeight = line->Split(' ')[1];

			ipAddress = _ip;
			port = Int32::Parse(_port);
			tabletName = _tabletID;
			htmlFile = "GE_" + _tabletResWidth + "_" + _tabletResHeight + ".html";
		}
		

		private: System::Void setupBrowser(){
			//String^ URL = "file:///C:/GE.html";  
		    //String^ URL = "C:/GE_MU.html";
		    String^ URL = "C:/GE_1366_768.html";
			//String^ URL = "C:/GE_test_building.html";
			//String^ URL = Application::StartupPath;
			//URL += "/web_file/GE.html";
			//URL += "/web_file/";
			//URL += htmlFile;
			
			//MessageBox::Show(URL);
			this->webBrowser1->Navigate(URL);
		}

		private: System::Void setupArtoolkit(){

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
			//sendData("11," + tabletName + "\0");
			sendData("11," + tabletName);
			sendData("15,flashGE,tabletGE,geLogin");

			/*socketClient = gcnew CSocketClient(10240, nullptr,
			gcnew CSocketClient::MESSAGE_HANDLER(&Form1::MessageHandlerClient),
			gcnew CSocketClient::CLOSE_HANDLER(&Form1::CloseHandler),
			gcnew CSocketClient::ERROR_HANDLER(&Form1::ErrorHandler));*/
		}

		/*
		public: static System::Void MessageHandlerClient(CSocketClient^ pSocket, Int32 iNumberOfBytes){
		}
		public: static System::Void CloseHandler(CSocketClient^ pSocket){
		}
		public: static System::Void ErrorHandler(CSocketClient^ pSocket, Exception^ pException){
		}		
		*/

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
			//strMessage = strMessage->Trim('\0');
			array<String^>^data = strMessage->Split(',');

			
			if(data!=nullptr && data->Length==12){			
				
				// && cmds->Length == 12
				
				String^ cmd = data[3];

				/*if(cmd == "assignID"){
					tabletName = data[4];
					sendData("13," + tabletName); // rename
				}
				else if(cmd == "flashGE-login"){
					sendData("15,flashGE,"+tabletName+",geLogin");				
				}
				else*/ if(cmd == "setBoundary"){

					try{
						double leftTopLat = System::Double::Parse(data[4]);
						double leftTopLong = System::Double::Parse(data[5]);
						double leftDownLat = System::Double::Parse(data[6]);
						double leftDownLong = System::Double::Parse(data[7]);
						double rightDownLat = System::Double::Parse(data[8]);
						double rightDownLong = System::Double::Parse(data[9]);
						double rightTopLat = System::Double::Parse(data[10]);
						double rightTopLong = System::Double::Parse(data[11]);
						set_4_point(leftTopLong, leftTopLat, leftDownLong, leftDownLat,rightTopLong,rightTopLat, rightDownLong, rightDownLat);

					}catch(System::Exception^ e){

					}

					//webBrowser1->Document->InvokeScript("boundaryLine");
				}
			}
		}

		// Translate the passed message into ASCII and store it as a Byte array.
		private: static System::Void sendData (String^ message) {
		    message += "\0";
			array<Byte>^data = System::Text::Encoding::ASCII->GetBytes( message );
			GetNetworkStream->Write( data, 0, data->Length );
			GetNetworkStream->Flush();
		}


		//設定tag對應的四個點經緯度位置
		private: static System::Void set_4_point(double LTLong,double LTLat,double LDLong,double LDLat,double RTLong,double RTLat,double RDLong,double RDLat) {

			LeftTopLong = LTLong;
			LeftTopLat = LTLat;
			LeftDownLong = LDLong;
			LeftDownLat = LDLat;
			RightTopLong = RTLong;
			RightTopLat = RTLat;
			RightDownLong = RDLong;
			RightDownLat = RDLat;

			boundaryMoved = true;

		}

		private: System::Void boundaryMovedUpdate() {	

			 if(boundaryMoved){
				 // update table boundary in main view
				 array<Object^>^ parameterB = gcnew array<Object^>(8); 
				 parameterB[0] = LeftTopLong;
				 parameterB[1] = LeftTopLat;
				 parameterB[2] = LeftDownLong;
				 parameterB[3] = LeftDownLat;
				 parameterB[4] = RightTopLong;
				 parameterB[5] = RightTopLat;
				 parameterB[6] = RightDownLong;
				 parameterB[7] = RightDownLat;
				 webBrowser1->Document->InvokeScript("boundaryLineStyle3",parameterB);	
				 array<Object^>^ parameterSB = gcnew array<Object^>(8); 

				 // update table boundary in small view
				 parameterSB[0] = LeftTopLong;
				 parameterSB[1] = LeftTopLat;
				 parameterSB[2] = LeftDownLong;
				 parameterSB[3] = LeftDownLat;
				 parameterSB[4] = RightTopLong;
				 parameterSB[5] = RightTopLat;
				 parameterSB[6] = RightDownLong;
				 parameterSB[7] = RightDownLat;
				 webBrowser1->Document->InvokeScript("small_boundaryLine",parameterSB);

				 boundaryMoved = false;
			 }
		}

		private: System::Void cameraMovedUpdate() {		

				 //google earth view
				 if(!cameraMoved)		
					 return;

				 // compute camera position
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

				 //(width_ratio, high_ratio, focalLength, cvTrans[4][4], table_boundary......)
				 GEData.computeNeedData(0.1,0.1,-0.2,tmpcvTrans, LeftDownLong, LeftDownLat, LeftTopLong, LeftTopLat, RightDownLong, RightDownLat);	

				 //update main view
				 //update camera position of main view
				 array<Object^>^ parameter = gcnew array<Object^>(6); 
				 parameter[0] = GEData.getLatitude();
				 parameter[1] = GEData.getLongitude();
				 parameter[2] = GEData.getAltitude();
				 parameter[3] = GEData.getHeading();
				 parameter[4] = GEData.getTilt();
				 parameter[5] = GEData.getRoll();
				 webBrowser1->Document->InvokeScript("cameraView",parameter);

				 // update camera position of small view
				 array<Object^>^ parameterC = gcnew array<Object^>(5); 
				 parameterC[0] = LeftTopLong + (RightTopLong - LeftTopLong) / 2;
				 parameterC[1] = LeftTopLat - (LeftTopLat - LeftDownLat) / 2;
				 parameterC[2] = (RightTopLong - LeftTopLong) * 111000 * RANGE_SCALE;
				 parameterC[3] = GEData.getSVAngle();
				 parameterC[4] = SVInitialized;	
				 webBrowser1->Document->InvokeScript("small_cameraView",parameterC);
				 SVInitialized = true;

				 // update the position of the model in the small view
				 array<Object^>^ parameterSM = gcnew array<Object^>(7); 
				 parameterSM[0] = GEData.getLatitude();
				 parameterSM[1] = GEData.getLongitude();
				 parameterSM[2] = GEData.getAltitude();
				 parameterSM[3] = GEData.getHeading();
				 parameterSM[4] = GEData.getTilt();
				 parameterSM[5] = GEData.getRoll();
				 parameterSM[6] = (RightTopLong - LeftTopLong) / BASE_BOUNDARY;
				 webBrowser1->Document->InvokeScript("setSVModel_position",parameterSM);


				 //// view polygon initialized
				 //if(!view_polygon_initialized){	
					// webBrowser1->Document->InvokeScript("CreateViewPolygon");
					// view_polygon_initialized = true;
				 //}
				 //// update the position of the view polygon 
				 //else{	
					// array<Object^>^ parameterVP = gcnew array<Object^>(12); 
					// parameterVP[0] = GEData.getLatitude_LT();
					// parameterVP[1] = GEData.getLongitude_LT();
					// parameterVP[2] = GEData.getAltitude_LT();
					// parameterVP[3] = GEData.getLatitude_LD();
					// parameterVP[4] = GEData.getLongitude_LD();
					// parameterVP[5] = GEData.getAltitude_LD();
					// parameterVP[6] = GEData.getLatitude_RT();
					// parameterVP[7] = GEData.getLongitude_RT();
					// parameterVP[8] = GEData.getAltitude_RT();
					// parameterVP[9] = GEData.getLatitude_RD();
					// parameterVP[10] = GEData.getLongitude_RD();
					// parameterVP[11] = GEData.getAltitude_RD();
					// webBrowser1->Document->InvokeScript("SetViewPolygonPosition",parameterVP);
				 ////}


				 //// view polygon on the ground //
				 //if(!view_ground_initialized){
					// webBrowser1->Document->InvokeScript("CreateViewGroungPolygon");
					// view_ground_initialized = true;
				 //}	
				 //else{
					// array<Object^>^ parameterVGP = gcnew array<Object^>(12); 
					// parameterVGP[0] = GEData.getGEGroundPointLT().y;
					// parameterVGP[1] = GEData.getGEGroundPointLT().x;
					// parameterVGP[2] = 0;
					// parameterVGP[3] = GEData.getGEGroundPointLD().y;
					// parameterVGP[4] = GEData.getGEGroundPointLD().x;
					// parameterVGP[5] = 0;
					// parameterVGP[6] = GEData.getGEGroundPointRT().y;
					// parameterVGP[7] = GEData.getGEGroundPointRT().x;
					// parameterVGP[8] = 0;
					// parameterVGP[9] = GEData.getGEGroundPointRD().y;
					// parameterVGP[10] = GEData.getGEGroundPointRD().x;
					// parameterVGP[11] = 0;
					// webBrowser1->Document->InvokeScript("SetViewGroundPolygonPosition",parameterVGP);
				 //}

				 //D3DXVECTOR3 start;
				 //D3DXVECTOR3 temp1 = GEData.getLookat();
				 //D3DXVECTOR3 temp2 = GEData.getOriginalPoint();
				 //D3DXVECTOR3 temp3 = temp1 + temp2;
				 //D3DXVECTOR3 end = GEData.countGELoc(temp3.x,temp3.y,temp3.z);
				 //start.x = GEData.getGEPoint().x;
				 //start.y = GEData.getGEPoint().y;
				 //start.z = GEData.getGEPoint().z;
				 //good.IntersectPoint(test,start,end);

				 //if(good.hit(120,122,24,26,(double)10/(double)111000,(double)10/(double)111000)){
					// array<Object^>^ parameterTTT = gcnew array<Object^>(3); 
					// parameterTTT[0] = good.getHitPoint().x;
					// parameterTTT[1] = good.getHitPoint().y;
					// parameterTTT[2] = good.getHitPoint().z * 111000;
					// webBrowser1->Document->InvokeScript("testpoint",parameterTTT);
				 //}
				

				 // control visibility of small view
				 int rollDifference1 = abs(GEData.getRoll() - 90);
				 int rollDifference2 = abs(GEData.getRoll() + 90);
				 if(rollDifference1 <= 20 || rollDifference2 <= 20 || GEData.getRoll() >= 90 || GEData.getRoll() <= -90)	
					 webBrowser1->Document->InvokeScript("HideSV");	
				 else	webBrowser1->Document->InvokeScript("ShowSV");	

				 cameraMoved = false;
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

	Bitmap^ image1;
	Bitmap^ image2;

	public: System::Windows::Forms::WebBrowser^  webBrowser1;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(0, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(988, 722);
			this->webBrowser1->TabIndex = 0;
			this->webBrowser1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Form1::OnBrowsePreviewKeyDown);
			// 
			// animTimer
			// 
			this->animTimer->Interval = 30;
			this->animTimer->Tick += gcnew System::EventHandler(this, &Form1::animTimer_Tick);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(47, 528);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(117, 116);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(803, 687);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(988, 722);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->webBrowser1);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}

#pragma endregion
	
		//timer
		private: System::Void animTimer_Tick(System::Object^  sender, System::EventArgs^  e) {

			 boundaryMovedUpdate();
			 cameraMovedUpdate();

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


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			BulidingCount++;

			array<Object^>^ parameterBuilding = gcnew array<Object^>(1); 
			parameterBuilding[0] = BulidingCount % 2;

			if(BulidingCount % 2 != 0){
				button2->BackgroundImage = image2;
				webBrowser1->Document->InvokeScript("Building",parameterBuilding);
			}
			else{
				BulidingCount = 0;
				button2->BackgroundImage = image1;
				webBrowser1->Document->InvokeScript("Building",parameterBuilding);
			}
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
 			array<Object^>^ parameterB = gcnew array<Object^>(8); 
			
			parameterB[0] = LeftTopLong;
			parameterB[1] = LeftTopLat;
			parameterB[2] = LeftDownLong;
			parameterB[3] = LeftDownLat;
			parameterB[4] = RightTopLong;
			parameterB[5] = RightTopLat;
			parameterB[6] = RightDownLong;
			parameterB[7] = RightDownLat;

 			array<Object^>^ parameterSB = gcnew array<Object^>(8); 
			
			parameterSB[0] = LeftTopLong;
			parameterSB[1] = LeftTopLat;
			parameterSB[2] = LeftDownLong;
			parameterSB[3] = LeftDownLat;
			parameterSB[4] = RightTopLong;
			parameterSB[5] = RightTopLat;
			parameterSB[6] = RightDownLong;
			parameterSB[7] = RightDownLat;

			array<Object^>^ parameterC = gcnew array<Object^>(3); 

			parameterC[0] = LeftTopLong + (RightTopLong - LeftTopLong) / 2;
			parameterC[1] = LeftTopLat - (LeftTopLat - LeftDownLat) / 2;
			parameterC[2] = (RightTopLong - LeftTopLong) * 111000 * RANGE_SCALE;

			webBrowser1->Document->InvokeScript("boundaryLineStyle3",parameterB);	
			webBrowser1->Document->InvokeScript("small_cameraView",parameterC);
			webBrowser1->Document->InvokeScript("small_boundaryLine",parameterSB);
		 }
};
}
