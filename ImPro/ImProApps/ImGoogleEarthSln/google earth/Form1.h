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

#define RANGE_SCALE 1.5
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


double longitude = 0;
double latitude = 0;
double altitude = 0;
double tilt = 0;
double heading = 0;
double roll = 0;
double altitude_scale = 1.0;

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

bool getFstTag = false;
int BulidingCount = 0;

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

bool computeNeedData(float cvTrans[4][4]);
bool arTimerTickFunc();
bool animTimerTickFunc();


//create Google Earth Data class//
countAllData GEData;
//////////////////////////////////



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
	/// Form1 ���K�n
	///
	/// ĵ�i: �p�G�z�ܧ�o�����O���W�١A�N�����ܧ�P�o�����O�Ҩ̾ڤ��Ҧ� .resx �ɮ����p��
	///          Managed �귽�sĶ���u�㪺 'Resource File Name' �ݩʡC
	///          �_�h�A�o�ǳ]�p�u��
	///          �N�L�k�P�o�Ӫ�����p����a�y�t�Ƹ귽
	///          ���T���ʡC
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
		private: static bool boundaryDirty;

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
			//TODO: �b���[�J�غc�禡�{���X
			//
			
			//full screen mode
			//setFullScreen();		

			image1 = gcnew System::Drawing::Bitmap("C:/3D.jpg");
			image2 = gcnew System::Drawing::Bitmap("C:/2D.jpg");
			button2->BackgroundImage = image1;

			g_formPtr = this;
			
			boundaryDirty = false;
						
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
		    String^ URL = "C:/GE_1366_768.html";
			//String^ URL = Application::StartupPath;
			//URL += "/web_file/GE.html";
			//URL += "/web_file/";
			//URL += htmlFile;
			
			//MessageBox::Show(URL);
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


		//�]�wtag�������|���I�g�n�צ�m
		private: static System::Void set_4_point(double LTLong,double LTLat,double LDLong,double LDLat,double RTLong,double RTLat,double RDLong,double RDLat) {
		//static void set_4_point(double LTLong,double LTLat,double LDLong,double LDLat,double RTLong,double RTLat,double RDLong,double RDLat){
			LeftTopLong = LTLong;
			LeftTopLat = LTLat;
			LeftDownLong = LDLong;
			LeftDownLat = LDLat;
			RightTopLong = RTLong;
			RightTopLat = RTLat;
			RightDownLong = RDLong;
			RightDownLat = RDLat;

			boundaryDirty = true;
			
			/*
			array<Object^>^ parameterB = gcnew array<Object^>(8); 
			
			parameterB[0] = LeftTopLong;
			parameterB[1] = LeftTopLat;
			parameterB[2] = LeftDownLong;
			parameterB[3] = LeftDownLat;
			parameterB[4] = RightTopLong;
			parameterB[5] = RightTopLat;
			parameterB[6] = RightDownLong;
			parameterB[7] = RightDownLat;
			
			//System::Windows::Forms::WebBrowser^ browser = g_formPtr->webBrowser1;
			//browser->Document->InvokeScript("boundaryLine",parameterB);
			webBrowser1->Document->InvokeScript("boundaryLine",parameterB);

			
			//webBrowser1->Document->InvokeScript("boundaryLine",parameterB);		
			*/
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
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
	//private: System::Windows::Forms::Timer^  arTimer;
	private: System::ComponentModel::IContainer^  components;
	private: static int temp = 300;

	protected: 

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�o�Ӥ�k�����e�C
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
			this->button2->Location = System::Drawing::Point(35, 582);
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
			this->button1->Visible = false;
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
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::OnKeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::OnKeyDown);
			this->ResumeLayout(false);

		}

#pragma endregion
	
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
				double heading = GEData.getHeading();
				//double lat = intersect_point.y;
				//double lng = intersect_point.x;

				String^ _vspaceX = vspaceX.ToString("0.0000");
				String^ _vspaceY = vspaceY.ToString("0.0000");
				String^ _heading = heading.ToString("0.0000");
				
				//if(GetNetworkStream != nullptr)
				//	sendData("15,flashGE,"+tabletName+",geDebug," + _vspaceX + "," + _vspaceY + "," + _heading);
				
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
				
				array<Object^>^ parameter = gcnew array<Object^>(11); 
				parameter[0] = clatitude;
				parameter[1] = clongitude;
				parameter[2] = caltitude;
				parameter[3] = cheading;
				parameter[4] = ctilt;
				parameter[5] = croll;
				parameter[6] = LeftTopLong + (RightTopLong - LeftTopLong) / 2;
				parameter[7] = LeftTopLat - (LeftTopLat - LeftDownLat) / 2;
				parameter[8] = (RightTopLong - LeftTopLong) * 111000 * RANGE_SCALE;
				parameter[9] = GEData.getSVAngle();
				parameter[10] = (RightTopLong - LeftTopLong) / BASE_BOUNDARY;

				double para[6] = {clatitude, clongitude, caltitude, cheading, ctilt, croll};
				for (int i = 0; i < 6; i++)
				{
					if (Double::IsNaN(para[i]))
					{
						return ;
					}
				}

				webBrowser1->Document->InvokeScript("cameraView",parameter);
				

				array<Object^>^ parameterModel = gcnew array<Object^>(2); 
				parameterModel[0] = GEData.getIntersect_point().y;
				parameterModel[1] = GEData.getIntersect_point().x;
				
				//webBrowser1->Document->InvokeScript("setModelLoc",parameterModel);
				//webBrowser1->Document->InvokeScript("setIconLoc",parameterModel);
			 
			 }
			 
			 if(boundaryDirty){
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
				
				boundaryDirty = false;
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
