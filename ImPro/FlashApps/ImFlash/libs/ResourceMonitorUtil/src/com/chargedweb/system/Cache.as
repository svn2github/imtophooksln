////////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2009 Julius Loa | jloa@chargedweb.com
//  All Rights Reserved.
//  license: GNU {http://www.opensource.org/licenses/gpl-2.0.php}
//  notice: just keep the header plz
//
////////////////////////////////////////////////////////////////////////////////

package com.chargedweb.system
{

	import flash.events.EventDispatcher;
	import flash.events.TimerEvent;
	import flash.utils.Timer;
	import flash.net.LocalConnection;
	import flash.system.System;
	
	/**
	 * Cache class gives u the ability to invoke GC automaticly or manually using 
	 * the clear() method
	 *
	 * @example
	 * <pre>
	 * import org.jloa.system.Cache;
	 *
	 * Cache.getInstance().debug = true;
	 * Cache.getInstance().sizeLimit = 10;
	 * Cache.getInstance().checkDelay = 500;
	 * </pre>
	 *
	 * @author Julius Lomako, Jloa
	 * @version 1.0
	 */
	public class Cache extends EventDispatcher
	{
		/** debug mode */
		public var debug:Boolean = false;
		
		/** auto-clean memory size limit [mb] @default=0 */
		private var _sizeLimit:Number = 0;

		/** auto-check memory size time delay [milisec] @default=0 if set to 0 = 'do not check'*/
		private var _checkDelay:Number = 0;
		
		/** current memory usage */
		private var currentRamUsage:Number = 0;
		
		/** timer instance */
		private var checkTimer:Timer;
		
		/** initizlized */
		private static var INITIALIZATION_ALLOWED:Boolean = true;
		
		/** */
		private static var INSTANCE:Cache;
		
		/**
		 * Constructor
		 */
		public function Cache()
		{
			super();
			if (!Cache.INITIALIZATION_ALLOWED) 
			{
        		throw new Error("error :: init failed: use Cache.getInstance() instead of new");
			}else{
				init();
			}		
		}
		
		/**
		 * Returns the reference to the class instance
		 */
		public static function getInstance():Cache
		{
			if(!Cache.INSTANCE)
			{
				Cache.INSTANCE = new Cache();
				Cache.INITIALIZATION_ALLOWED = false;
			}
			return Cache.INSTANCE;
		}
		
		//////////////////////////////////////////
		//
		//	PUBLIC
		//
		//////////////////////////////////////////
		
		/**
		 * Explicitly invoke the garbage collector
		 * @return	nothing
		 */
		public function clear():void
		{
			if(debug)
			{
				trace("Cache.clear() called :: memory usage exceeded ::");
				trace("\tmemory usage: "+currentRamUsage+"mb");
				trace("\tmemory limit: "+_sizeLimit+"mb");
			}
			try
			{
             	var hlcp:LocalConnection = new LocalConnection();
             	var hlcs:LocalConnection = new LocalConnection();
             	hlcp.connect('name');
              	hlcs.connect('name');
       		}
       		catch (e:Error)
			{
				flash.system.System.gc();
				flash.system.System.gc();
			}
			if(debug)
				trace("\tmemory usage [after clean()]: "+getCurrentRamUsage()+"mb");
		}
		
		/** 
		 * @param	value:Number	auto-clean memory size limit [mb]
		 * @return	Number			current auto-clean size limit [mb]
		 */
		public function set sizeLimit(value:Number):void
		{
			_sizeLimit = value;
		}
		
		public function get sizeLimit():Number
		{
			return _sizeLimit;
		}
		
		/** 
		 * @param	value:Number	auto-check memory size delay [milisec] if set to 0 = 'do not check'
		 * @return 	Number			current auto-check delay value [milisec]
		 */
		public function set checkDelay(value:Number):void
		{
			_checkDelay = value;
			init();
		}
		
		/**
		 * Returns current memory usage amount [mb]
		 * @return	Number	current memory usage [mb]
		 */
		public function get checkDelay():Number
		{
			return _checkDelay;
		}
		
		/**
		 * @return	value:Number 	current memory usage [mb]
		 */
		public function memoryUsage():Number
		{
			return getCurrentRamUsage();
		}
		
		//////////////////////////////////////////
		//
		//	PRIVATE
		//
		//////////////////////////////////////////
		
		/** @private inits the timer listener */
		private function init():void
		{
			if(checkTimer)
			{
				checkTimer.removeEventListener(TimerEvent.TIMER, checkMemorySize);
				checkTimer = null;
			}
			
			if(_checkDelay > 0)
			{
				checkTimer = new Timer(_checkDelay);
				checkTimer.addEventListener(TimerEvent.TIMER, checkMemorySize);
				checkTimer.start();
			}
		}
		
		private function checkMemorySize(event:TimerEvent):void
		{
			currentRamUsage = getCurrentRamUsage();
			
			if(currentRamUsage > _sizeLimit)
				clear();
		}
		
		private function getCurrentRamUsage():Number
		{
			return Math.floor(System.totalMemory/(1024*1024)*100)/100;
		}
	}
}