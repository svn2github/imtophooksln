﻿package app.core.element{//-----------------------------------------------------------------------------------------------------------	import flash.display.Sprite;	import flash.display.MovieClip;	import flash.events.*;		import flash.filters.*;	import caurina.transitions.Tweener;//-----------------------------------------------------------------------------------------------------------	public class Accordion extends Sprite{		//-----------------------------------------------------------------------------------------------------------		public var n_state:Number;		private var n_width;		private var n_height;		//		private var navW;		private var panelN;		private var panelW;		private var maxWidth;		public static const EVENT_ON_CHANGE = "ON_CHANGE";//-----------------------------------------------------------------------------------------------------------		public function Accordion($width:Number, $height:Number, $count:Number=0, $btnW:Number=0){			n_width  = $width;			n_height = $height;			panelN = $count;			navW = $btnW;				//-------------------------------------------------------------------------------------			this.graphics.beginFill(0xFFFFFF,1);			this.graphics.drawRect(0,0, n_width, n_height);			this.graphics.endFill();			panelW = n_width-$count*$btnW;			maxWidth=panelW+$btnW;			//-------------------------------------------------------------------------------------			var n_mask:Sprite = new Sprite();			n_mask.graphics.beginFill(0xFFFFFF,1);			n_mask.graphics.drawRect(0,0, n_width, n_height);			n_mask.graphics.endFill();			this.addChild(n_mask);			this.mask = n_mask;		}//-----------------------------------------------------------------------------------------------------------		public function toggleNode(pNumber:Number):void{			var obj:Object;			var i:Number;			for(i=1;i<this.numChildren;i++){				obj = this.getChildAt(i) as Sprite;				obj.getChildByName("n_target").addEventListener(MouseEvent.MOUSE_DOWN, handleDownEvent);				obj.getChildByName("n_target").addEventListener(TouchEvent.MOUSE_DOWN, handleDownEvent);				Tweener.addTween(obj.getChildByName("n_target"), {alpha:0.0, time:1.25});			}						obj = this.getChildAt(pNumber) as Sprite;			obj.getChildByName("n_target").removeEventListener(MouseEvent.MOUSE_DOWN, handleDownEvent);			obj.getChildByName("n_target").removeEventListener(TouchEvent.MOUSE_DOWN, handleDownEvent);				Tweener.addTween(obj.getChildByName("n_target"), {alpha:0.5, time:1.25});						for(i=pNumber+1; i<this.numChildren;i++){				obj = this.getChildAt(i);				Tweener.addTween(obj, {x:n_width-(this.numChildren-i)*navW, time:0.75});			}			for(i=1; i<=pNumber;i++){				obj = this.getChildAt(i);				Tweener.addTween(obj, {x:(i-1)*navW, time:0.85});			}			n_state=pNumber;			dispatchEvent(new Event(EVENT_ON_CHANGE));		}//-----------------------------------------------------------------------------------------------------------		public function addNode($skin,$content){			var n_holder:Sprite = new Sprite();			n_holder.graphics.beginFill(0xFFFFFF,0.0);			n_holder.graphics.drawRect(0,0,maxWidth,n_height);			//-------------------------------------------------------------------------------------			var n_content = $content;				n_holder.addChild(n_content);			n_content.x+=navW;					var c_mask:MovieClip = drawContent();			n_content.addChild(c_mask);			n_content.mask=c_mask;			//-------------------------------------------------------------------------------------			var n_mc:MovieClip = drawButton();			var n_mask:MovieClip = drawButton();			n_holder.addChild(n_mc);			n_holder.addChild($skin);			//n_mc.addChild(n_mask);			//n_mc.mask=n_mask;				n_mc.panelNumber = this.numChildren-1;			n_mc.name="n_target";			//var n_shadow : DropShadowFilter = new DropShadowFilter(10,90,0,0.75,15,15,4,1);			//n_mc.filters=[n_shadow];			//-------------------------------------------------------------------------------------			this.addChild(n_holder);			n_holder.x= (this.numChildren-2)*navW;		}//-----------------------------------------------------------------------------------------------------------		private function drawButton():MovieClip{			var r:MovieClip = new MovieClip();			r.graphics.beginFill(0xFFFFFF,1);			r.graphics.drawRect(0,0,navW,n_height);			r.graphics.endFill();			r.alpha=0;			return r;		} //-----------------------------------------------------------------------------------------------------------			private function drawContent():MovieClip{			var r:MovieClip = new MovieClip();			r.graphics.beginFill(0xFFFFFF,0);			r.graphics.drawRect(0,0,panelW,n_height);			r.graphics.endFill();			return r;		}	//-----------------------------------------------------------------------------------------------------------				private function handleDownEvent(e:Event){			if(e.target.panelNumber){				toggleNode(e.target.panelNumber);				}		}//-----------------------------------------------------------------------------------------------------------		}}