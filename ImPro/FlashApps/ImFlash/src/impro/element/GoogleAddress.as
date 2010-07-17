package impro.element
{
	import com.google.maps.LatLng;
	
	public class GoogleAddress
	{		
		private var _location:String;
		private var _latlng:LatLng;
		private var _zoom:Number;
		
		public function GoogleAddress(location:String, latlng:LatLng, zoom:Number)
		{
			this._location = location;
			this._latlng = latlng;
			this._zoom = zoom;
		}

	    public function get location():String
	    {
	    	return _location;
	    }
	    public function get latlng():LatLng
	    {
	    	return _latlng;
	    }
	    public function get zoom():Number
	    {
	    	return _zoom;
	    }
		
	}
}