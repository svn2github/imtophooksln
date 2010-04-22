#pragma once
#define SLIDER_GetRangeMin(hWndTrack) SendMessage(hWndTrack, TBM_GETRANGEMIN,0,0)
#define SLIDER_GetRangeMax(hWndTrack) SendMessage(hWndTrack, TBM_GETRANGEMAX,0,0)

#define SLIDER_GetPos(hWndTrack)  SendMessage(hWndTrack, TBM_GETPOS, 0, 0)
#define SLIDER_SetPos(hWndTrack, pos)  SendMessage(hWndTrack, TBM_SETPOS, (WPARAM) TRUE,(LPARAM) pos)
#define SLIDER_SetRange(hWndTrack, iMin, iMax)  SendMessage(hWndTrack, TBM_SETRANGE, (WPARAM) TRUE, (LPARAM) MAKELONG(iMin, iMax))   

