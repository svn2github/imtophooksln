package impro
{
	import impro.multiview.IMView;
	
	public class Setting
	{
		public static const DEBUG:Boolean = false;
		
		// this is for GEControl to communicate with googleEarth via a socket server
		// load from imFlashParam.txt
//		public static var ServerIP:String;
//		public static var ServerPort:Number;
		public static var ServerIP:String = "192.168.1.32";
		public static var ServerPort:Number = 5000;
		
		private static var width:Number = 800;
		private static var height:Number = 600;
		
		public static var LRes:IMView = new IMView("lres", 0, 0, width, height);		
		public static var HRes:Array = new Array(
//				new IMView("hres1", width, 0, width, height)	// high relosution 1
//				,new IMView("hres2", width*2, 0, width, height)	// high relosution 1
				new IMView("0", width, 0, width, height)	// high relosution 1
				,new IMView("1", width*2, 0, width, height)	// high relosution 1				
				);
				
		public static function getiFlashlightIMView():IMView{
			return HRes[1];
		}

	}
}