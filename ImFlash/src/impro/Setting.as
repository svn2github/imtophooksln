package impro
{
	import impro.multiview.IMView;
	
	public class Setting
	{
		public static const DEBUG:Boolean = true;
		
		// this is for GEControl to communicate with googleEarth via a socket server
		public static var ServerIP:String = "192.168.1.38";
		public static var ServerPort:Number = 5000;
		
//		public static var LRes:IMView = new IMView(-1, 0, 0, 1024, 768);		
//		public static var HRes:Array = new Array(
//				new IMView(0, 1024, 0, 1024, 768)	// high relosution 1
////				new IMView(1, 800, 0, 400, 400)	// high relosution 2
//				);
				
//		public static var LRes:IMView = new IMView(-1, 0, 0, 1024, 768);
//		public static var HRes:Array = new Array(
//				new IMView(0, 1024, 0, 1024, 768)	// high relosution 1
//				);

		public static var LRes:IMView = new IMView("lres", 0, 0, 600, 600);		
		public static var HRes:Array = new Array(
				new IMView("hres1", 600, 0, 600, 600)	// high relosution 1
//				,new IMView("hres2", 800, 0, 400, 600)	// high relosution 1
				);

	}
}