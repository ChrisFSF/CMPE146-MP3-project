/*
 * commctrl.h
 *
 * Windows "common controls" API declatations.
 *
 *
 * $Id: commctrl.h,v 4a1c8e69ddf7 2019/05/03 14:32:30 keith $
 *
 * Written by Anders Norlander <anorland@hem2.passagen.se>
 * Copyright (C) 1998-2006, 2008-2011, 2017, 2018, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _COMMCTRL_H
#pragma GCC system_header
#define _COMMCTRL_H

#include <winbase.h>
#include <prsht.h>

_BEGIN_C_DECLS

#ifndef COMMCTRLAPI
#ifdef __W32API_USE_DLLIMPORT__
#define COMMCTRLAPI  DECLSPEC_IMPORT
#else
#define COMMCTRLAPI
#endif
#endif

#define DRAGLISTMSGSTRING		  TEXT( "commctrl_DragListMsg" )

#define HOTKEY_CLASS			__AW_SUFFIXED__( HOTKEY_CLASS )
#define HOTKEY_CLASSW			__AW_STRING_W__( HOTKEY_CLASSA )
#define HOTKEY_CLASSA			__AW_STRING_A__( "msctls_hotkey32" )

#define PROGRESS_CLASS			__AW_SUFFIXED__( PROGRESS_CLASS )
#define PROGRESS_CLASSW 		__AW_STRING_W__( PROGRESS_CLASSA )
#define PROGRESS_CLASSA 		__AW_STRING_A__( "msctls_progress32" )

#define STATUSCLASSNAME 		__AW_SUFFIXED__( STATUSCLASSNAME )
#define STATUSCLASSNAMEW		__AW_STRING_W__( STATUSCLASSNAMEA )
#define STATUSCLASSNAMEA		__AW_STRING_A__( "msctls_statusbar32" )

#define TOOLBARCLASSNAME		__AW_SUFFIXED__( TOOLBARCLASSNAME )
#define TOOLBARCLASSNAMEW		__AW_STRING_W__( TOOLBARCLASSNAMEA )
#define TOOLBARCLASSNAMEA		__AW_STRING_A__( "ToolbarWindow32" )

#define TOOLTIPS_CLASS			__AW_SUFFIXED__( TOOLTIPS_CLASS )
#define TOOLTIPS_CLASSW 		__AW_STRING_W__( TOOLTIPS_CLASSA )
#define TOOLTIPS_CLASSA 		__AW_STRING_A__( "tooltips_class32" )

#define TRACKBAR_CLASS			__AW_SUFFIXED__( TRACKBAR_CLASS )
#define TRACKBAR_CLASSW 		__AW_STRING_W__( TRACKBAR_CLASSA )
#define TRACKBAR_CLASSA 		__AW_STRING_A__( "msctls_trackbar32" )

#define UPDOWN_CLASS			__AW_SUFFIXED__( UPDOWN_CLASS )
#define UPDOWN_CLASSW			__AW_STRING_W__( UPDOWN_CLASSA )
#define UPDOWN_CLASSA			__AW_STRING_A__( "msctls_updown32" )

#define ANIMATE_CLASS			__AW_SUFFIXED__( ANIMATE_CLASS )
#define ANIMATE_CLASSW			__AW_STRING_W__( ANIMATE_CLASSA )
#define ANIMATE_CLASSA			__AW_STRING_A__( "SysAnimate32" )

#define DATETIMEPICK_CLASS		__AW_SUFFIXED__( DATETIMEPICK_CLASS )
#define DATETIMEPICK_CLASSW		__AW_STRING_W__( DATETIMEPICK_CLASSA )
#define DATETIMEPICK_CLASSA		__AW_STRING_A__( "SysDateTimePick32" )

#define MONTHCAL_CLASS			__AW_SUFFIXED__( MONTHCAL_CLASS )
#define MONTHCAL_CLASSW 		__AW_STRING_W__( MONTHCAL_CLASSA )
#define MONTHCAL_CLASSA 		__AW_STRING_A__( "SysMonthCal32" )

#define REBARCLASSNAME			__AW_SUFFIXED__( REBARCLASSNAME )
#define REBARCLASSNAMEW 		__AW_STRING_W__( REBARCLASSNAMEA )
#define REBARCLASSNAMEA 		__AW_STRING_A__( "ReBarWindow32" )

#define WC_COMBOBOXEX			__AW_SUFFIXED__( WC_COMBOBOXEX )
#define WC_COMBOBOXEXW			__AW_STRING_W__( WC_COMBOBOXEXA )
#define WC_COMBOBOXEXA			__AW_STRING_A__( "ComboBoxEx32" )

#define WC_HEADER			__AW_SUFFIXED__( WC_HEADER )
#define WC_HEADERW			__AW_STRING_W__( WC_HEADERA )
#define WC_HEADERA			__AW_STRING_A__( "SysHeader32" )

#define WC_IPADDRESS			__AW_SUFFIXED__( WC_IPADDRESS )
#define WC_IPADDRESSW			__AW_STRING_W__( WC_IPADDRESSA )
#define WC_IPADDRESSA			__AW_STRING_A__( "SysIPAddress32" )

#define WC_LISTVIEW			__AW_SUFFIXED__( WC_LISTVIEW )
#define WC_LISTVIEWW			__AW_STRING_W__( WC_LISTVIEWA )
#define WC_LISTVIEWA			__AW_STRING_A__( "SysListView32" )

#define WC_TABCONTROL			__AW_SUFFIXED__( WC_TABCONTROL )
#define WC_TABCONTROLW			__AW_STRING_W__( WC_TABCONTROLA )
#define WC_TABCONTROLA			__AW_STRING_A__( "SysTabControl32" )

#define WC_TREEVIEW			__AW_SUFFIXED__( WC_TREEVIEW )
#define WC_TREEVIEWW			__AW_STRING_W__( WC_TREEVIEWA )
#define WC_TREEVIEWA			__AW_STRING_A__( "SysTreeView32" )

#define WC_PAGESCROLLER 		__AW_SUFFIXED__( WC_PAGESCROLLER )
#define WC_PAGESCROLLERW		__AW_STRING_W__( WC_PAGESCROLLERA )
#define WC_PAGESCROLLERA		__AW_STRING_A__( "SysPager" )

#define WC_NATIVEFONTCTL		__AW_SUFFIXED__( WC_NATIVEFONTCTL )
#define WC_NATIVEFONTCTLW		__AW_STRING_W__( WC_NATIVEFONTCTLA )
#define WC_NATIVEFONTCTLA		__AW_STRING_A__( "NativeFontCtl" )

#define WC_BUTTON			__AW_SUFFIXED__( WC_BUTTON )
#define WC_BUTTONW			__AW_STRING_W__( WC_BUTTONA )
#define WC_BUTTONA			__AW_STRING_A__( "Button" )

#define WC_STATIC			__AW_SUFFIXED__( WC_STATIC )
#define WC_STATICW			__AW_STRING_W__( WC_STATICA )
#define WC_STATICA			__AW_STRING_A__( "Static" )

#define WC_EDIT 			__AW_SUFFIXED__( WC_EDIT )
#define WC_EDITW			__AW_STRING_W__( WC_EDITA )
#define WC_EDITA			__AW_STRING_A__( "Edit" )

#define WC_LISTBOX			__AW_SUFFIXED__( WC_LISTBOX )
#define WC_LISTBOXW			__AW_STRING_W__( WC_LISTBOXA )
#define WC_LISTBOXA			__AW_STRING_A__( "ListBox" )

#define WC_COMBOBOX			__AW_SUFFIXED__( WC_COMBOBOX )
#define WC_COMBOBOXW			__AW_STRING_W__( WC_COMBOBOXA )
#define WC_COMBOBOXA			__AW_STRING_A__( "ComboBox" )

#define WC_SCROLLBAR			__AW_SUFFIXED__( WC_SCROLLBAR )
#define WC_SCROLLBARW			__AW_STRING_W__( WC_SCROLLBARA )
#define WC_SCROLLBARA			__AW_STRING_A__( "ScrollBar" )

#define WC_LINK 			__AW_SUFFIXED__( WC_LINK )
#define WC_LINKW			__AW_STRING_W__( WC_LINKA )
#define WC_LINKA			__AW_STRING_A__( "SysLink" )

#if _WIN32_IE >= _WIN32_IE_IE50

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define COMCTL32_VERSION				 6

#else
#define COMCTL32_VERSION				 5

#endif
#endif

#define LVM_FIRST				    0x1000
#define TV_FIRST				    0x1100
#define HDM_FIRST				    0x1200

#define ACM_OPENA			    (WM_USER + 100)
#define ACM_PLAY			    (WM_USER + 101)
#define ACM_STOP			    (WM_USER + 102)
#define ACM_OPENW			    (WM_USER + 103)

#define ACN_START					 1
#define ACN_STOP					 2

#define CBEIF_TEXT				0x00000001
#define CBEIF_IMAGE				0x00000002
#define CBEIF_SELECTEDIMAGE			0x00000004
#define CBEIF_OVERLAY				0x00000008
#define CBEIF_INDENT				0x00000010
#define CBEIF_LPARAM				0x00000020
#define CBEIF_DI_SETITEM			0x10000000

#define CBEN_INSERTITEM 		   (CBEN_FIRST - 1)
#define CBEN_DELETEITEM 		   (CBEN_FIRST - 2)
#define CBEN_BEGINEDIT			   (CBEN_FIRST - 4)
#define CBEN_ENDEDITA			   (CBEN_FIRST - 5)
#define CBEN_ENDEDITW			   (CBEN_FIRST - 6)

#define CBENF_KILLFOCUS 				 1
#define CBENF_RETURN					 2
#define CBENF_ESCAPE					 3
#define CBENF_DROPDOWN					 4

#define CBEMAXSTRLEN				       260

#define DL_BEGINDRAG				      1157
#define DL_CANCELDRAG				      1160
#define DL_DRAGGING				      1158
#define DL_DROPPED				      1159
#define DL_CURSORSET					 0
#define DL_STOPCURSOR					 1
#define DL_COPYCURSOR					 2
#define DL_MOVECURSOR					 3

#define CCS_TOP 					 1
#define CCS_NOMOVEY					 2
#define CCS_BOTTOM					 3
#define CCS_NORESIZE					 4
#define CCS_NOPARENTALIGN				 8
#define CCS_ADJUSTABLE					32
#define CCS_NODIVIDER					64

#if _WIN32_IE >= _WIN32_IE_IE30

#define CCS_VERT				       128
#define CCS_LEFT				       129
#define CCS_NOMOVEX				       130
#define CCS_RIGHT				       131

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define ACS_CENTER				    0x0001
#define ACS_TRANSPARENT 			    0x0002
#define ACS_AUTOPLAY				    0x0004
#define ACS_TIMER				    0x0008

#define PGS_VERT				0x00000000
#define PGS_HORZ				0x00000001
#define PGS_AUTOSCROLL				0x00000002
#define PGS_DRAGNDROP				0x00000004

#define CMB_MASKED					 2

#define MINSYSCOMMAND				   SC_SIZE

#define SBT_OWNERDRAW				    0x1000
#define SBT_NOBORDERS				       256
#define SBT_POPOUT				       512
#define SBT_RTLREADING				      1024

#define SB_SETTEXTA			    (WM_USER  +  1)
#define SB_SETTEXTW			    (WM_USER  + 11)
#define SB_GETTEXTA			    (WM_USER  +  2)
#define SB_GETTEXTW			    (WM_USER  + 13)
#define SB_GETTEXTLENGTHA		    (WM_USER  +  3)
#define SB_GETTEXTLENGTHW		    (WM_USER  + 12)
#define SB_SETPARTS			    (WM_USER  +  4)
#define SB_GETPARTS			    (WM_USER  +  6)
#define SB_GETBORDERS			    (WM_USER  +  7)
#define SB_SETMINHEIGHT 		    (WM_USER  +  8)
#define SB_SIMPLE			    (WM_USER  +  9)
#define SB_GETRECT			    (WM_USER  + 10)

#define MSGF_COMMCTRL_BEGINDRAG 		    0x4200
#define MSGF_COMMCTRL_SIZEHEADER		    0x4201
#define MSGF_COMMCTRL_DRAGSELECT		    0x4202
#define MSGF_COMMCTRL_TOOLBARCUST		    0x4203

#define ILC_COLOR					 0
#define ILC_COLOR4					 4
#define ILC_COLOR8					 8
#define ILC_COLOR16					16
#define ILC_COLOR24					24
#define ILC_COLOR32					32
#define ILC_COLORDDB				       254
#define ILC_MASK					 1
#define ILC_PALETTE				      2048

#define ILCF_MOVE					 0
#define ILCF_SWAP					 1

#define ILS_NORMAL					 0
#define ILS_GLOW					 1
#define ILS_SHADOW					 2
#define ILS_SATURATE					 4
#define ILS_ALPHA					 8

#define ILD_BLEND25					 2
#define ILD_BLEND50					 4
#define ILD_SELECTED					 4
#define ILD_BLEND					 4
#define ILD_FOCUS					 2
#define ILD_MASK					16
#define ILD_NORMAL					 0
#define ILD_TRANSPARENT 				 1

#define ILD_IMAGE				    0x0020
#define ILD_ROP 				    0x0040
#define ILD_OVERLAYMASK 			    0x0F00
#define ILD_PRESERVEALPHA			    0x1000
#define ILD_SCALE				    0x2000
#define ILD_DPISCALE				    0x4000

#define HDS_HORZ					 0
#define HDS_BUTTONS					 2
#define HDS_HIDDEN					 8

#if _WIN32_IE > _WIN32_IE_IE30

#define HDS_HOTTRACK					 4
#define HDS_DRAGDROP				    0x0040
#define HDS_FULLDRAG				    0x0080

#if _WIN32_IE >= _WIN32_IE_IE50

#define HDS_FILTERBAR				    0x0100

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE > _WIN32_IE_IE30 */

#define NM_FIRST					 0
#define NM_LAST 			       ((UINT)(-99))
#define LVN_FIRST			      ((UINT)(-100))
#define LVN_LAST			      ((UINT)(-199))
#define HDN_FIRST			      ((UINT)(-300))
#define HDN_LAST			      ((UINT)(-399))
#define TVN_FIRST			      ((UINT)(-400))
#define TVN_LAST			      ((UINT)(-499))
#define TTN_FIRST			      ((UINT)(-520))
#define TTN_LAST			      ((UINT)(-549))
#define TCN_FIRST			      ((UINT)(-550))
#define TCN_LAST			      ((UINT)(-580))

#ifndef CDN_FIRST
/* FIXME: The following pair of manifest constants are also defined
 * in <commdlg.h>; ensure that the definitions are consistent, then
 * remove this conditional guard, so GCC can check that they remain
 * that way.
 */
#define CDN_FIRST			      ((UINT)(-601))
#define CDN_LAST			      ((UINT)(-699))

#endif	/* ! CDN_FIRST */

#define TBN_FIRST			      ((UINT)(-700))
#define TBN_LAST			      ((UINT)(-720))
#define UDN_FIRST			      ((UINT)(-721))
#define UDN_LAST			      ((UINT)(-740))

#if _WIN32_IE >= _WIN32_IE_IE30

#define RBN_FIRST			      ((UINT)(-831))
#define RBN_LAST			      ((UINT)(-859))
#define MCN_FIRST			      ((UINT)(-750))
#define MCN_LAST			      ((UINT)(-759))
#define DTN_FIRST			      ((UINT)(-760))
#define DTN_LAST			      ((UINT)(-799))
#define CBEN_FIRST			      ((UINT)(-800))
#define CBEN_LAST			      ((UINT)(-830))

#if _WIN32_IE >= _WIN32_IE_IE40

#define IPN_FIRST			      ((UINT)(-860))
#define IPN_LAST			      ((UINT)(-879))

#define IPN_FIELDCHANGED		    (IPN_FIRST - 0)

#define SBN_FIRST			      ((UINT)(-880U))
#define SBN_LAST			      ((UINT)(-899U))
#define PGN_FIRST			      ((UINT)(-900U))
#define PGN_LAST			      ((UINT)(-950U))

#define PGN_SCROLL			    (PGN_FIRST - 1)
#define PGN_CALCSIZE			    (PGN_FIRST - 2)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define HDI_WIDTH					 1
#define HDI_HEIGHT					 1
#define HDI_TEXT					 2
#define HDI_FORMAT					 4
#define HDI_LPARAM					 8
#define HDI_BITMAP					16

#if _WIN32_IE >= _WIN32_IE_IE30

#define HDI_IMAGE					32
#define HDI_DI_SETITEM					64
#define HDI_ORDER				       128

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define CBES_EX_NOEDITIMAGE			0x00000001
#define CBES_EX_NOEDITIMAGEINDENT		0x00000002
#define CBES_EX_PATHWORDBREAKPROC		0x00000004

#if _WIN32_IE >= _WIN32_IE_IE40

#define CBES_EX_NOSIZELIMIT			0x00000008
#define CBES_EX_CASESENSITIVE			0x00000010

#define CBEN_GETDISPINFOA		   (CBEN_FIRST - 0)
#define CBEN_GETDISPINFOW		   (CBEN_FIRST - 7)
#define CBEN_DRAGBEGINA 		   (CBEN_FIRST - 8)
#define CBEN_DRAGBEGINW 		   (CBEN_FIRST - 9)

#if _WIN32_IE >= _WIN32_IE_IE50

#define HDI_FILTER				       256

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define HDF_LEFT					 0
#define HDF_RIGHT					 1
#define HDF_CENTER					 2
#define HDF_JUSTIFYMASK 				 3
#define HDF_RTLREADING					 4

#define HDF_OWNERDRAW				    0x8000
#define HDF_STRING				    0x4000
#define HDF_BITMAP				    0x2000

#if _WIN32_IE >= _WIN32_IE_IE30

#define HDF_BITMAP_ON_RIGHT			    0x1000
#define HDF_IMAGE				    0x0800

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define HDM_GETITEMCOUNT		  (HDM_FIRST  +  0)

#define HDM_INSERTITEMA 		  (HDM_FIRST  +  1)
#define HDM_INSERTITEMW 		  (HDM_FIRST  + 10)
#define HDM_DELETEITEM			  (HDM_FIRST  +  2)
#define HDM_GETITEMA			  (HDM_FIRST  +  3)
#define HDM_GETITEMW			  (HDM_FIRST  + 11)
#define HDM_SETITEMA			  (HDM_FIRST  +  4)
#define HDM_SETITEMW			  (HDM_FIRST  + 12)
#define HDM_LAYOUT			  (HDM_FIRST  +  5)

#if _WIN32_IE >= _WIN32_IE_IE30

#define HDM_GETITEMRECT 		  (HDM_FIRST  +  7)
#define HDM_SETIMAGELIST		  (HDM_FIRST  +  8)
#define HDM_GETIMAGELIST		  (HDM_FIRST  +  9)
#define HDM_ORDERTOINDEX		  (HDM_FIRST  + 15)
#define HDM_CREATEDRAGIMAGE		  (HDM_FIRST  + 16)
#define HDM_GETORDERARRAY		  (HDM_FIRST  + 17)
#define HDM_SETORDERARRAY		  (HDM_FIRST  + 18)
#define HDM_SETHOTDIVIDER		  (HDM_FIRST  + 19)

#if _WIN32_IE >= _WIN32_IE_IE40

#define HDM_GETUNICODEFORMAT		CCM_GETUNICODEFORMAT
#define HDM_SETUNICODEFORMAT		CCM_SETUNICODEFORMAT

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define HHT_NOWHERE					 1
#define HHT_ONHEADER					 2
#define HHT_ONDIVIDER					 4
#define HHT_ONDIVOPEN					 8
#define HHT_ABOVE				       256
#define HHT_BELOW				       512
#define HHT_TORIGHT				      1024
#define HHT_TOLEFT				      2048

#define HDM_HITTEST			   (HDM_FIRST +  6)
#define HDN_ITEMCHANGINGA		   (HDN_FIRST -  0)
#define HDN_ITEMCHANGINGW		   (HDN_FIRST - 20)
#define HDN_ITEMCHANGEDA		   (HDN_FIRST -  1)
#define HDN_ITEMCHANGEDW		   (HDN_FIRST - 21)
#define HDN_ITEMCLICKA			   (HDN_FIRST -  2)
#define HDN_ITEMCLICKW			   (HDN_FIRST - 22)
#define HDN_ITEMDBLCLICKA		   (HDN_FIRST -  3)
#define HDN_ITEMDBLCLICKW		   (HDN_FIRST - 23)
#define HDN_DIVIDERDBLCLICKA		   (HDN_FIRST -  5)
#define HDN_DIVIDERDBLCLICKW		   (HDN_FIRST - 25)
#define HDN_BEGINTRACKA 		   (HDN_FIRST -  6)
#define HDN_BEGINTRACKW 		   (HDN_FIRST - 26)
#define HDN_ENDTRACKA			   (HDN_FIRST -  7)
#define HDN_ENDTRACKW			   (HDN_FIRST - 27)
#define HDN_TRACKA			   (HDN_FIRST -  8)
#define HDN_TRACKW			   (HDN_FIRST - 28)

#if _WIN32_IE >= _WIN32_IE_IE30

#define HDN_ENDDRAG			   (HDN_FIRST - 11)
#define HDN_BEGINDRAG			   (HDN_FIRST - 10)
#define HDN_GETDISPINFOA		   (HDN_FIRST -  9)
#define HDN_GETDISPINFOW		   (HDN_FIRST - 29)

#if _WIN32_IE >= _WIN32_IE_IE40

#define HICF_OTHER				      0x00
#define HICF_MOUSE				      0x01
#define HICF_ARROWKEYS				      0x02
#define HICF_ACCELERATOR			      0x04
#define HICF_DUPACCEL				      0x08
#define HICF_ENTERING				      0x10
#define HICF_LEAVING				      0x20
#define HICF_RESELECT				      0x40
#define HICF_LMOUSE				      0x80
#define HICF_TOGGLEDROPDOWN			     0x100

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define IPM_CLEARADDRESS		    (WM_USER + 100)
#define IPM_SETADDRESS			    (WM_USER + 101)
#define IPM_GETADDRESS			    (WM_USER + 102)
#define IPM_SETRANGE			    (WM_USER + 103)
#define IPM_SETFOCUS			    (WM_USER + 104)
#define IPM_ISBLANK			    (WM_USER + 105)

#if _WIN32_IE >= _WIN32_IE_IE50

#define I_INDENTCALLBACK			       (-1)
#define I_IMAGENONE				       (-2)

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

#define CMB_MASKED					 2
#define TBSTATE_CHECKED 				 1
#define TBSTATE_PRESSED 				 2
#define TBSTATE_ENABLED 				 4
#define TBSTATE_HIDDEN					 8
#define TBSTATE_INDETERMINATE				16
#define TBSTATE_WRAP					32

#if _WIN32_IE >= _WIN32_IE_IE30

#define TBSTATE_ELLIPSES			      0x40

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBSTATE_MARKED				    0x0080

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TBSTYLE_BUTTON					 0
#define TBSTYLE_SEP					 1
#define TBSTYLE_CHECK					 2
#define TBSTYLE_GROUP					 4

#define TBSTYLE_CHECKGROUP		  (TBSTYLE_GROUP | TBSTYLE_CHECK)

#if _WIN32_IE >= _WIN32_IE_IE30

#define TBSTYLE_DROPDOWN				 8

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBSTYLE_AUTOSIZE				16
#define TBSTYLE_NOPREFIX				32

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TBSTYLE_TOOLTIPS			       256
#define TBSTYLE_WRAPABLE			       512
#define TBSTYLE_ALTDRAG 			      1024

#if _WIN32_IE >= _WIN32_IE_IE30

#define TBSTYLE_FLAT				      2048
#define TBSTYLE_LIST				      4096
#define TBSTYLE_CUSTOMERASE			      8192

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBSTYLE_REGISTERDROP			    0x4000
#define TBSTYLE_TRANSPARENT			    0x8000
#define TBSTYLE_EX_DRAWDDARROWS 		0x00000001

#if _WIN32_IE >= _WIN32_IE_IE501

#define TBSTYLE_EX_MIXEDBUTTONS 			 8
#define TBSTYLE_EX_HIDECLIPPEDBUTTONS			16

#endif	/* _WIN32_IE >= _WIN32_IE_IE501 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define TBSTYLE_EX_DOUBLEBUFFER 		      0x80

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#if _WIN32_IE >= _WIN32_IE_IE50

#define BTNS_BUTTON				TBSTYLE_BUTTON
#define BTNS_SEP				TBSTYLE_SEP
#define BTNS_CHECK				TBSTYLE_CHECK
#define BTNS_GROUP				TBSTYLE_GROUP
#define BTNS_CHECKGROUP 			TBSTYLE_CHECKGROUP
#define BTNS_DROPDOWN				TBSTYLE_DROPDOWN
#define BTNS_AUTOSIZE				TBSTYLE_AUTOSIZE
#define BTNS_NOPREFIX				TBSTYLE_NOPREFIX

#define BTNS_WHOLEDROPDOWN			    0x0080

#if _WIN32_IE >= _WIN32_IE_IE501

#define BTNS_SHOWTEXT				    0x0040

#endif	/* _WIN32_IE >= _WIN32_IE_IE501 */
#endif	 /* _WIN32_IE >= _WIN32_IE_IE50 */

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBCDRF_NOEDGES				   0x10000
#define TBCDRF_HILITEHOTTRACK			   0x20000
#define TBCDRF_NOOFFSET 			   0x40000
#define TBCDRF_NOMARK				   0x80000
#define TBCDRF_NOETCHEDEFFECT			  0x100000

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define HINST_COMMCTRL			   ((HINSTANCE)(-1))

#define IDB_STD_SMALL_COLOR				 0
#define IDB_STD_LARGE_COLOR				 1
#define IDB_VIEW_SMALL_COLOR				 4
#define IDB_VIEW_LARGE_COLOR				 5

#if _WIN32_IE >= _WIN32_IE_IE30

#define IDB_HIST_SMALL_COLOR				 8
#define IDB_HIST_LARGE_COLOR				 9

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define STD_CUT 					 0
#define STD_COPY					 1
#define STD_PASTE					 2
#define STD_UNDO					 3
#define STD_REDOW					 4
#define STD_DELETE					 5
#define STD_FILENEW					 6
#define STD_FILEOPEN					 7
#define STD_FILESAVE					 8
#define STD_PRINTPRE					 9
#define STD_PROPERTIES					10
#define STD_HELP					11
#define STD_FIND					12
#define STD_REPLACE					13
#define STD_PRINT					14

#define VIEW_LARGEICONS 				 0
#define VIEW_SMALLICONS 				 1
#define VIEW_LIST					 2
#define VIEW_DETAILS					 3
#define VIEW_SORTNAME					 4
#define VIEW_SORTSIZE					 5
#define VIEW_SORTDATE					 6
#define VIEW_SORTTYPE					 7
#define VIEW_PARENTFOLDER				 8
#define VIEW_NETCONNECT 				 9
#define VIEW_NETDISCONNECT				10
#define VIEW_NEWFOLDER					11

#define TB_ENABLEBUTTON 		     (WM_USER +  1)
#define TB_CHECKBUTTON			     (WM_USER +  2)
#define TB_PRESSBUTTON			     (WM_USER +  3)
#define TB_HIDEBUTTON			     (WM_USER +  4)
#define TB_INDETERMINATE		     (WM_USER +  5)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TB_MARKBUTTON			     (WM_USER +  6)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TB_ISBUTTONENABLED		     (WM_USER +  9)
#define TB_ISBUTTONCHECKED		     (WM_USER + 10)
#define TB_ISBUTTONPRESSED		     (WM_USER + 11)
#define TB_ISBUTTONHIDDEN		     (WM_USER + 12)
#define TB_ISBUTTONINDETERMINATE	     (WM_USER + 13)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TB_ISBUTTONHIGHLIGHTED		     (WM_USER + 14)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TB_SETSTATE			     (WM_USER + 17)
#define TB_GETSTATE			     (WM_USER + 18)
#define TB_ADDBITMAP			     (WM_USER + 19)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TB_ADDBUTTONSA			     (WM_USER + 20)
#define TB_INSERTBUTTONA		     (WM_USER + 21)

#else	/* _WIN32_IE < _WIN32_IE_IE40 */

#define TB_ADDBUTTONS			     (WM_USER + 20)
#define TB_INSERTBUTTON 		     (WM_USER + 21)

#endif	/* _WIN32_IE < _WIN32_IE_IE40 */

#define TB_DELETEBUTTON 		     (WM_USER + 22)
#define TB_GETBUTTON			     (WM_USER + 23)
#define TB_BUTTONCOUNT			     (WM_USER + 24)
#define TB_COMMANDTOINDEX		     (WM_USER + 25)
#define TB_SAVERESTOREA 		     (WM_USER + 26)
#define TB_SAVERESTOREW 		     (WM_USER + 76)
#define TB_CUSTOMIZE			     (WM_USER + 27)
#define TB_ADDSTRINGA			     (WM_USER + 28)
#define TB_ADDSTRINGW			     (WM_USER + 77)
#define TB_GETITEMRECT			     (WM_USER + 29)
#define TB_BUTTONSTRUCTSIZE		     (WM_USER + 30)
#define TB_SETBUTTONSIZE		     (WM_USER + 31)
#define TB_SETBITMAPSIZE		     (WM_USER + 32)
#define TB_AUTOSIZE			     (WM_USER + 33)
#define TB_GETTOOLTIPS			     (WM_USER + 35)
#define TB_SETTOOLTIPS			     (WM_USER + 36)
#define TB_SETPARENT			     (WM_USER + 37)
#define TB_SETROWS			     (WM_USER + 39)
#define TB_GETROWS			     (WM_USER + 40)
#define TB_GETBITMAPFLAGS		     (WM_USER + 41)
#define TB_SETCMDID			     (WM_USER + 42)
#define TB_CHANGEBITMAP 		     (WM_USER + 43)
#define TB_GETBITMAP			     (WM_USER + 44)
#define TB_GETBUTTONTEXTA		     (WM_USER + 45)
#define TB_GETBUTTONTEXTW		     (WM_USER + 75)
#define TB_REPLACEBITMAP		     (WM_USER + 46)
#define TB_GETBUTTONSIZE		     (WM_USER + 58)
#define TB_SETBUTTONWIDTH		     (WM_USER + 59)

#if _WIN32_IE >= _WIN32_IE_IE30

#define TB_SETINDENT			     (WM_USER + 47)
#define TB_SETIMAGELIST 		     (WM_USER + 48)
#define TB_GETIMAGELIST 		     (WM_USER + 49)
#define TB_LOADIMAGES			     (WM_USER + 50)
#define TB_GETRECT			     (WM_USER + 51)
#define TB_SETHOTIMAGELIST		     (WM_USER + 52)
#define TB_GETHOTIMAGELIST		     (WM_USER + 53)
#define TB_SETDISABLEDIMAGELIST 	     (WM_USER + 54)
#define TB_GETDISABLEDIMAGELIST 	     (WM_USER + 55)
#define TB_SETSTYLE			     (WM_USER + 56)
#define TB_GETSTYLE			     (WM_USER + 57)
#define TB_GETBUTTONSIZE		     (WM_USER + 58)
#define TB_SETBUTTONWIDTH		     (WM_USER + 59)
#define TB_SETMAXTEXTROWS		     (WM_USER + 60)
#define TB_GETTEXTROWS			     (WM_USER + 61)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TB_GETOBJECT			     (WM_USER + 62)
#define TB_GETBUTTONINFOW		     (WM_USER + 63)
#define TB_SETBUTTONINFOW		     (WM_USER + 64)
#define TB_GETBUTTONINFOA		     (WM_USER + 65)
#define TB_SETBUTTONINFOA		     (WM_USER + 66)
#define TB_INSERTBUTTONW		     (WM_USER + 67)
#define TB_ADDBUTTONSW			     (WM_USER + 68)
#define TB_HITTEST			     (WM_USER + 69)

#if 0	/* Duplicate definitions -- remove them */
#define TB_SETEXTENDEDSTYLE		     (WM_USER + 84)
#define TB_GETEXTENDEDSTYLE		     (WM_USER + 85)
#endif

#define TB_SETDRAWTEXTFLAGS		     (WM_USER + 70)
#define TB_GETHOTITEM			     (WM_USER + 71)
#define TB_SETHOTITEM			     (WM_USER + 72)
#define TB_SETANCHORHIGHLIGHT		     (WM_USER + 73)
#define TB_GETANCHORHIGHLIGHT		     (WM_USER + 74)
#define TB_MAPACCELERATORA		     (WM_USER + 78)
#define TB_GETINSERTMARK		     (WM_USER + 79)
#define TB_SETINSERTMARK		     (WM_USER + 80)
#define TB_INSERTMARKHITTEST		     (WM_USER + 81)
#define TB_MOVEBUTTON			     (WM_USER + 82)
#define TB_GETMAXSIZE			     (WM_USER + 83)
#define TB_SETEXTENDEDSTYLE		     (WM_USER + 84)
#define TB_GETEXTENDEDSTYLE		     (WM_USER + 85)
#define TB_GETPADDING			     (WM_USER + 86)
#define TB_SETPADDING			     (WM_USER + 87)
#define TB_SETINSERTMARKCOLOR		     (WM_USER + 88)
#define TB_GETINSERTMARKCOLOR		     (WM_USER + 89)
#define TB_MAPACCELERATORW		     (WM_USER + 90)
#define TB_GETSTRINGW			     (WM_USER + 91)
#define TB_GETSTRINGA			     (WM_USER + 92)

#define TB_SETCOLORSCHEME		   CCM_SETCOLORSCHEME
#define TB_GETCOLORSCHEME		   CCM_GETCOLORSCHEME
#define TB_SETUNICODEFORMAT		   CCM_SETUNICODEFORMAT
#define TB_GETUNICODEFORMAT		   CCM_GETUNICODEFORMAT

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TBBF_LARGE			   		 1

#define TBN_GETBUTTONINFOA		   (TBN_FIRST -  0)
#define TBN_BEGINDRAG			   (TBN_FIRST -  1)
#define TBN_ENDDRAG			   (TBN_FIRST -  2)
#define TBN_BEGINADJUST 		   (TBN_FIRST -  3)
#define TBN_ENDADJUST			   (TBN_FIRST -  4)
#define TBN_RESET			   (TBN_FIRST -  5)
#define TBN_QUERYINSERT 		   (TBN_FIRST -  6)
#define TBN_QUERYDELETE 		   (TBN_FIRST -  7)
#define TBN_TOOLBARCHANGE		   (TBN_FIRST -  8)
#define TBN_CUSTHELP			   (TBN_FIRST -  9)

#if _WIN32_IE >= _WIN32_IE_IE30

#define TBN_DROPDOWN			   (TBN_FIRST - 10)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBN_HOTITEMCHANGE		   (TBN_FIRST - 13)
#define TBN_DRAGOUT			   (TBN_FIRST - 14)
#define TBN_DELETINGBUTTON		   (TBN_FIRST - 15)
#define TBN_GETDISPINFOA		   (TBN_FIRST - 16)
#define TBN_GETDISPINFOW		   (TBN_FIRST - 17)
#define TBN_GETINFOTIPA 		   (TBN_FIRST - 18)
#define TBN_GETINFOTIPW 		   (TBN_FIRST - 19)
#define TBN_GETBUTTONINFOW		   (TBN_FIRST - 20)

#if _WIN32_IE >= _WIN32_IE_IE50

#define TBN_RESTORE			   (TBN_FIRST - 21)
#define TBN_SAVE			   (TBN_FIRST - 22)
#define TBN_INITCUSTOMIZE		   (TBN_FIRST - 23)

#define TBNRF_HIDEHELP					 1
#define TBNRF_ENDCUSTOMIZE				 2
#define TBNF_IMAGE					 1
#define TBNF_TEXT					 2
#define TBNF_DI_SETITEM 			0x10000000

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TTS_ALWAYSTIP					 1
#define TTS_NOPREFIX					 2

#if _WIN32_IE >= _WIN32_IE_IE50

#define TTS_NOANIMATE				      0x10
#define TTS_NOFADE				      0x20
#define TTS_BALLOON				      0x40
#define TTS_CLOSE				      0x80

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

#define TTF_IDISHWND					 1
#define TTF_CENTERTIP					 2
#define TTF_RTLREADING					 4
#define TTF_SUBCLASS					16

#if _WIN32_IE >= _WIN32_IE_IE30

#define TTF_TRACK				    0x0020
#define TTF_ABSOLUTE				    0x0080
#define TTF_TRANSPARENT 			    0x0100

#if _WIN32_IE >= _WIN32_IE_IE501

#define TTF_PARSELINKS				    0x1000

#endif	/* _WIN32_IE >= _WIN32_IE_IE501 */

#define TTF_DI_SETITEM				    0x8000
#define TBCD_TICS					 1
#define TBCD_THUMB					 2
#define TBCD_CHANNEL					 3

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBDDRET_DEFAULT 				 0
#define TBDDRET_NODEFAULT				 1
#define TBDDRET_TREATPRESSED				 2
#define TBIMHT_AFTER					 1
#define TBIMHT_BACKGROUND				 2

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TTDT_AUTOMATIC					 0
#define TTDT_RESHOW					 1
#define TTDT_AUTOPOP					 2
#define TTDT_INITIAL					 3

#define TTM_ACTIVATE			     (WM_USER +  1)
#define TTM_SETDELAYTIME		     (WM_USER +  3)
#define TTM_ADDTOOLA			     (WM_USER +  4)
#define TTM_ADDTOOLW			     (WM_USER + 50)
#define TTM_DELTOOLA			     (WM_USER +  5)
#define TTM_DELTOOLW			     (WM_USER + 51)
#define TTM_NEWTOOLRECTA		     (WM_USER +  6)
#define TTM_NEWTOOLRECTW		     (WM_USER + 52)
#define TTM_RELAYEVENT			     (WM_USER +  7)
#define TTM_GETTOOLINFOA		     (WM_USER +  8)
#define TTM_GETTOOLINFOW		     (WM_USER + 53)
#define TTM_SETTOOLINFOA		     (WM_USER +  9)
#define TTM_SETTOOLINFOW		     (WM_USER + 54)
#define TTM_HITTESTA			     (WM_USER + 10)
#define TTM_HITTESTW			     (WM_USER + 55)
#define TTM_GETTEXTA			     (WM_USER + 11)
#define TTM_GETTEXTW			     (WM_USER + 56)
#define TTM_UPDATETIPTEXTA		     (WM_USER + 12)
#define TTM_UPDATETIPTEXTW		     (WM_USER + 57)
#define TTM_GETTOOLCOUNT		     (WM_USER + 13)
#define TTM_ENUMTOOLSA			     (WM_USER + 14)
#define TTM_ENUMTOOLSW			     (WM_USER + 58)
#define TTM_GETCURRENTTOOLA		     (WM_USER + 15)
#define TTM_GETCURRENTTOOLW		     (WM_USER + 59)
#define TTM_WINDOWFROMPOINT		     (WM_USER + 16)

#if _WIN32_IE >= _WIN32_IE_IE30

#define TTM_TRACKACTIVATE		     (WM_USER + 17)
#define TTM_TRACKPOSITION		     (WM_USER + 18)
#define TTM_SETTIPBKCOLOR		     (WM_USER + 19)
#define TTM_SETTIPTEXTCOLOR		     (WM_USER + 20)
#define TTM_GETDELAYTIME		     (WM_USER + 21)
#define TTM_GETTIPBKCOLOR		     (WM_USER + 22)
#define TTM_GETTIPTEXTCOLOR		     (WM_USER + 23)
#define TTM_SETMAXTIPWIDTH		     (WM_USER + 24)
#define TTM_GETMAXTIPWIDTH		     (WM_USER + 25)
#define TTM_SETMARGIN			     (WM_USER + 26)
#define TTM_GETMARGIN			     (WM_USER + 27)
#define TTM_POP 			     (WM_USER + 28)

#if _WIN32_IE >= _WIN32_IE_IE40 	/* IE4.0 ??? */

#define TTM_UPDATE			     (WM_USER + 29)
#define TTM_GETBUBBLESIZE		     (WM_USER + 30)
#define TTM_ADJUSTRECT			     (WM_USER + 31)
#define TTM_SETTITLEA			     (WM_USER + 32)
#define TTM_SETTITLEW			     (WM_USER + 33)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 	-- IE4.0 ??? */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TTN_GETDISPINFOA		   (TTN_FIRST -  0)
#define TTN_GETDISPINFOW		   (TTN_FIRST - 10)

#define TTN_NEEDTEXTA			   TTN_GETDISPINFOA
#define TTN_NEEDTEXTW			   TTN_GETDISPINFOW

#define TTN_SHOW			   (TTN_FIRST -  1)
#define TTN_POP 	   		   (TTN_FIRST -  2)

#define UD_MAXVAL			   	    0x7FFF
#define UD_MINVAL			       (-UD_MAXVAL)

#define UDN_DELTAPOS			   (UDN_FIRST -  1)

#define UDS_WRAP					 1
#define UDS_SETBUDDYINT 				 2
#define UDS_ALIGNRIGHT					 4
#define UDS_ALIGNLEFT					 8
#define UDS_AUTOBUDDY					16
#define UDS_ARROWKEYS					32
#define UDS_HORZ					64
#define UDS_NOTHOUSANDS 			       128

#if _WIN32_IE >= _WIN32_IE_IE30

#define UDS_HOTTRACK				    0x0100

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define UDM_SETRANGE			    (WM_USER + 101)
#define UDM_GETRANGE			    (WM_USER + 102)
#define UDM_SETPOS			    (WM_USER + 103)
#define UDM_GETPOS			    (WM_USER + 104)
#define UDM_SETBUDDY			    (WM_USER + 105)
#define UDM_GETBUDDY			    (WM_USER + 106)
#define UDM_SETACCEL			    (WM_USER + 107)
#define UDM_GETACCEL			    (WM_USER + 108)
#define UDM_SETBASE			    (WM_USER + 109)
#define UDM_GETBASE			    (WM_USER + 110)

#if _WIN32_IE >= _WIN32_IE_IE40

#define UDM_SETRANGE32			    (WM_USER + 111)
#define UDM_GETRANGE32			    (WM_USER + 112)
#define UDM_SETPOS32			    (WM_USER + 113)
#define UDM_GETPOS32			    (WM_USER + 114)

#if _WIN32_IE >= _WIN32_IE_IE50

#define UDM_SETUNICODEFORMAT		  CCM_SETUNICODEFORMAT
#define UDM_GETUNICODEFORMAT		  CCM_GETUNICODEFORMAT

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define SB_SETTEXTA			     (WM_USER +  1)
#define SB_SETTEXTW			     (WM_USER + 11)
#define SB_GETTEXTA			     (WM_USER +  2)
#define SB_GETTEXTW			     (WM_USER + 13)
#define SB_GETTEXTLENGTHA		     (WM_USER +  3)
#define SB_GETTEXTLENGTHW		     (WM_USER + 12)
#define SB_SETPARTS			     (WM_USER +  4)
#define SB_GETPARTS			     (WM_USER +  6)
#define SB_GETBORDERS			     (WM_USER +  7)
#define SB_SETMINHEIGHT 		     (WM_USER +  8)
#define SB_SIMPLE			     (WM_USER +  9)
#define SB_GETRECT			     (WM_USER + 10)

#define SBT_OWNERDRAW				    0x1000

#define SBT_NOBORDERS				       256
#define SBT_POPOUT				       512
#define SBT_RTLREADING				      1024

#if _WIN32_IE >= _WIN32_IE_IE40

#define SBT_TOOLTIPS				    0x0800
#define SBN_SIMPLEMODECHANGE			(SBN_FIRST)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TBS_AUTOTICKS					 1
#define TBS_VERT					 2
#define TBS_HORZ					 0
#define TBS_TOP 					 4
#define TBS_BOTTOM					 0
#define TBS_LEFT					 4
#define TBS_RIGHT					 0
#define TBS_BOTH					 8
#define TBS_NOTICKS					16
#define TBS_ENABLESELRANGE				32
#define TBS_FIXEDLENGTH 				64
#define TBS_NOTHUMB				       128

#if _WIN32_IE >= _WIN32_IE_IE30

#define TBS_TOOLTIPS				    0x0100

#define TBTS_TOP					 0
#define TBTS_LEFT					 1
#define TBTS_BOTTOM					 2
#define TBTS_RIGHT					 3

#if _WIN32_IE >= _WIN32_IE_IE50

#define TBS_REVERSED				    0x0200

#if _WIN32_IE >= _WIN32_IE_IE501

#define TBS_DOWNISLEFT				    0x0400

#endif	/* _WIN32_IE >= _WIN32_IE_IE501 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_IE >= _WIN32_IE_IE40

#define TBIF_BYINDEX				0x80000000

#define TBIF_COMMAND					32
#define TBIF_IMAGE					 1
#define TBIF_LPARAM					16
#define TBIF_SIZE					64
#define TBIF_STATE					 4
#define TBIF_STYLE					 8
#define TBIF_TEXT					 2

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TBM_GETPOS			     (WM_USER +  0)
#define TBM_GETRANGEMIN 		     (WM_USER +  1)
#define TBM_GETRANGEMAX 		     (WM_USER +  2)
#define TBM_GETTIC			     (WM_USER +  3)
#define TBM_SETTIC			     (WM_USER +  4)
#define TBM_SETPOS			     (WM_USER +  5)
#define TBM_SETRANGE			     (WM_USER +  6)
#define TBM_SETRANGEMIN 		     (WM_USER +  7)
#define TBM_SETRANGEMAX 		     (WM_USER +  8)
#define TBM_CLEARTICS			     (WM_USER +  9)
#define TBM_SETSEL			     (WM_USER + 10)
#define TBM_SETSELSTART 		     (WM_USER + 11)
#define TBM_SETSELEND			     (WM_USER + 12)
#define TBM_GETPTICS			     (WM_USER + 14)
#define TBM_GETTICPOS			     (WM_USER + 15)
#define TBM_GETNUMTICS			     (WM_USER + 16)
#define TBM_GETSELSTART 		     (WM_USER + 17)
#define TBM_GETSELEND			     (WM_USER + 18)
#define TBM_CLEARSEL			     (WM_USER + 19)
#define TBM_SETTICFREQ			     (WM_USER + 20)
#define TBM_SETPAGESIZE 		     (WM_USER + 21)
#define TBM_GETPAGESIZE 		     (WM_USER + 22)
#define TBM_SETLINESIZE 		     (WM_USER + 23)
#define TBM_GETLINESIZE 		     (WM_USER + 24)
#define TBM_GETTHUMBRECT		     (WM_USER + 25)
#define TBM_GETCHANNELRECT		     (WM_USER + 26)
#define TBM_SETTHUMBLENGTH		     (WM_USER + 27)
#define TBM_GETTHUMBLENGTH		     (WM_USER + 28)
#define TBM_SETTOOLTIPS 		     (WM_USER + 29)
#define TBM_GETTOOLTIPS 		     (WM_USER + 30)
#define TBM_SETTIPSIDE			     (WM_USER + 31)
#define TBM_SETBUDDY			     (WM_USER + 32)
#define TBM_GETBUDDY			     (WM_USER + 33)

#define TBM_GETUNICODEFORMAT		  CCM_GETUNICODEFORMAT
#define TBM_SETUNICODEFORMAT		  CCM_SETUNICODEFORMAT

#define TB_LINEUP					 0
#define TB_LINEDOWN					 1
#define TB_PAGEUP					 2
#define TB_PAGEDOWN					 3
#define TB_THUMBPOSITION				 4
#define TB_THUMBTRACK					 5
#define TB_TOP						 6
#define TB_BOTTOM					 7
#define TB_ENDTRACK					 8
#define HOTKEYF_SHIFT					 1
#define HOTKEYF_CONTROL 				 2
#define HOTKEYF_ALT					 4
#define HOTKEYF_EXT					 8
#define HKCOMB_NONE					 1
#define HKCOMB_S					 2
#define HKCOMB_C					 4
#define HKCOMB_A					 8
#define HKCOMB_SC					16
#define HKCOMB_SA					32
#define HKCOMB_CA					64
#define HKCOMB_SCA				       128

#define HKM_SETHOTKEY			      (WM_USER + 1)
#define HKM_GETHOTKEY			      (WM_USER + 2)
#define HKM_SETRULES			      (WM_USER + 3)
#define PBM_SETRANGE			      (WM_USER + 1)
#define PBM_SETPOS			      (WM_USER + 2)
#define PBM_DELTAPOS			      (WM_USER + 3)
#define PBM_SETSTEP			      (WM_USER + 4)
#define PBM_STEPIT			      (WM_USER + 5)

#define PBM_SETRANGE32				      1030
#define PBM_GETRANGE				      1031
#define PBM_GETPOS				      1032
#define PBM_SETBARCOLOR 			      1033

#define PBM_SETBKCOLOR	CCM_SETBKCOLOR

#define PBS_SMOOTH					 1
#define PBS_VERTICAL					 4
#define LVS_ICON					 0
#define LVS_REPORT					 1
#define LVS_SMALLICON					 2
#define LVS_LIST					 3
#define LVS_TYPEMASK					 3
#define LVS_SINGLESEL					 4
#define LVS_SHOWSELALWAYS				 8
#define LVS_SORTASCENDING				16
#define LVS_SORTDESCENDING				32
#define LVS_SHAREIMAGELISTS				64
#define LVS_NOLABELWRAP 			       128
#define LVS_AUTOARRANGE 			       256
#define LVS_EDITLABELS				       512

#define LVS_NOSCROLL				    0x2000
#define LVS_TYPESTYLEMASK			    0xFC00

#define LVS_ALIGNTOP					 0

#define LVS_ALIGNLEFT				     0x800
#define LVS_ALIGNMASK				     0xC00
#define LVS_OWNERDRAWFIXED			     0x400
#define LVS_NOCOLUMNHEADER			    0x4000
#define LVS_NOSORTHEADER			    0x8000

#if _WIN32_IE >= _WIN32_IE_IE30

#define CDIS_CHECKED					 8
#define CDIS_DEFAULT					32
#define CDIS_DISABLED					 4
#define CDIS_FOCUS					16
#define CDIS_GRAYED					 2
#define CDIS_HOT					64
#define CDIS_SELECTED					 1
#define CDIS_MARKED				       128
#define CDIS_INDETERMINATE			       256

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define CDIS_SHOWKEYBOARDCUES			       512

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define CDDS_POSTERASE					 4
#define CDDS_POSTPAINT					 2
#define CDDS_PREERASE					 3
#define CDDS_PREPAINT					 1
#define CDDS_ITEM				     65536
#define CDDS_ITEMPOSTERASE			     65540
#define CDDS_ITEMPOSTPAINT			     65538
#define CDDS_ITEMPREERASE			     65539
#define CDDS_ITEMPREPAINT			     65537

#if _WIN32_IE >= _WIN32_IE_IE40

#define CDDS_SUBITEM				   0x20000

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define CDRF_DODEFAULT				      0x00
#define CDRF_NOTIFYITEMDRAW			      0x20
#define CDRF_NOTIFYSUBITEMDRAW			      0x20
#define CDRF_NOTIFYITEMERASE			      0x80
#define CDRF_NOTIFYPOSTERASE			      0x40
#define CDRF_NOTIFYPOSTPAINT			      0x10
#define CDRF_NEWFONT				      0x02
#define CDRF_SKIPDEFAULT			      0x04

#if _WIN32_IE >= _WIN32_IE_IE40

#define LVBKIF_SOURCE_NONE			0x00000000
#define LVBKIF_SOURCE_HBITMAP			0x00000001
#define LVBKIF_SOURCE_URL			0x00000002
#define LVBKIF_SOURCE_MASK			0x00000003
#define LVBKIF_STYLE_NORMAL			0x00000000
#define LVBKIF_STYLE_TILE			0x00000010
#define LVBKIF_STYLE_MASK			0x00000010

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define LVBKIF_FLAG_TILEOFFSET			0x00000100
#define LVBKIF_TYPE_WATERMARK			0x10000000

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define LVS_OWNERDATA				      4096
#define LVS_EX_CHECKBOXES				 4
#define LVS_EX_FULLROWSELECT				32
#define LVS_EX_GRIDLINES				 1
#define LVS_EX_HEADERDRAGDROP				16
#define LVS_EX_ONECLICKACTIVATE 			64
#define LVS_EX_SUBITEMIMAGES				 2
#define LVS_EX_TRACKSELECT				 8
#define LVS_EX_TWOCLICKACTIVATE 		       128

#define LVSICF_NOINVALIDATEALL			0x00000001
#define LVSICF_NOSCROLL 			0x00000002

#if _WIN32_IE >= _WIN32_IE_IE40

#define LVS_EX_FLATSB				0x00000100
#define LVS_EX_REGIONAL 			0x00000200
#define LVS_EX_INFOTIP				0x00000400
#define LVS_EX_UNDERLINEHOT			0x00000800
#define LVS_EX_UNDERLINECOLD			0x00001000
#define LVS_EX_MULTIWORKAREAS			0x00002000

#if _WIN32_IE >= _WIN32_IE_IE50

#define LVS_EX_LABELTIP 			0x00004000
#define LVS_EX_BORDERSELECT			0x00008000

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define LVSIL_NORMAL					 0
#define LVSIL_SMALL					 1
#define LVSIL_STATE					 2

#define LVM_GETBKCOLOR			   (LVM_FIRST +  0)
#define LVM_SETBKCOLOR			   (LVM_FIRST +  1)
#define LVM_GETIMAGELIST		   (LVM_FIRST +  2)
#define LVM_SETIMAGELIST		   (LVM_FIRST +  3)
#define LVM_GETITEMCOUNT		   (LVM_FIRST +  4)
#define LVM_SORTITEMSEX 		   (LVM_FIRST + 81)

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define LVM_SETSELECTEDCOLUMN		  (LVM_FIRST + 140)

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define LVM_SETVIEW			  (LVM_FIRST + 142)
#define LVM_GETVIEW			  (LVM_FIRST + 143)
#define LVM_INSERTGROUP 		  (LVM_FIRST + 145)
#define LVM_SETGROUPINFO		  (LVM_FIRST + 147)
#define LVM_GETGROUPINFO		  (LVM_FIRST + 149)
#define LVM_REMOVEGROUP 		  (LVM_FIRST + 150)
#define LVM_MOVEGROUP			  (LVM_FIRST + 151)
#define LVM_SETGROUPMETRICS		  (LVM_FIRST + 155)
#define LVM_GETGROUPMETRICS		  (LVM_FIRST + 156)
#define LVM_ENABLEGROUPVIEW		  (LVM_FIRST + 157)
#define LVM_SORTGROUPS			  (LVM_FIRST + 158)
#define LVM_INSERTGROUPSORTED		  (LVM_FIRST + 159)
#define LVM_REMOVEALLGROUPS		  (LVM_FIRST + 160)
#define LVM_HASGROUP			  (LVM_FIRST + 161)
#define LVM_SETTILEVIEWINFO		  (LVM_FIRST + 162)
#define LVM_GETTILEVIEWINFO		  (LVM_FIRST + 163)
#define LVM_SETTILEINFO 		  (LVM_FIRST + 164)
#define LVM_GETTILEINFO 		  (LVM_FIRST + 165)
#define LVM_SETINSERTMARK		  (LVM_FIRST + 166)
#define LVM_GETINSERTMARK		  (LVM_FIRST + 167)
#define LVM_INSERTMARKHITTEST		  (LVM_FIRST + 168)
#define LVM_GETINSERTMARKRECT		  (LVM_FIRST + 169)
#define LVM_SETINSERTMARKCOLOR		  (LVM_FIRST + 170)
#define LVM_GETINSERTMARKCOLOR		  (LVM_FIRST + 171)
#define LVM_SETINFOTIP			  (LVM_FIRST + 173)
#define LVM_GETSELECTEDCOLUMN		  (LVM_FIRST + 174)
#define LVM_ISGROUPVIEWENABLED		  (LVM_FIRST + 175)
#define LVM_GETOUTLINECOLOR		  (LVM_FIRST + 176)
#define LVM_SETOUTLINECOLOR		  (LVM_FIRST + 177)
#define LVM_CANCELEDITLABEL		  (LVM_FIRST + 179)
#define LVM_MAPIDTOINDEX		  (LVM_FIRST + 181)

#define LVIF_TEXT					 1
#define LVIF_IMAGE					 2
#define LVIF_PARAM					 4
#define LVIF_STATE					 8

#if _WIN32_IE >= _WIN32_IE_IE30

#define LVIF_INDENT					16
#define LVIF_NORECOMPUTE			      2048

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define LVIF_GROUPID				       256
#define LVIF_COLUMNS				       512

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define LVIS_FOCUSED					 1
#define LVIS_SELECTED					 2
#define LVIS_CUT					 4
#define LVIS_DROPHILITED				 8

#define LVIS_OVERLAYMASK			     0xF00
#define LVIS_STATEIMAGEMASK			    0xF000

#define LPSTR_TEXTCALLBACKW		      ((LPWSTR)(-1))
#define LPSTR_TEXTCALLBACKA		       ((LPSTR)(-1))

#define I_IMAGECALLBACK 			       (-1)

#define LVM_GETITEMA			   (LVM_FIRST +  5)
#define LVM_GETITEMW			   (LVM_FIRST + 75)
#define LVM_SETITEMA			   (LVM_FIRST +  6)
#define LVM_SETITEMW			   (LVM_FIRST + 76)
#define LVM_INSERTITEMA 		   (LVM_FIRST +  7)
#define LVM_INSERTITEMW 		   (LVM_FIRST + 77)
#define LVM_DELETEITEM			   (LVM_FIRST +  8)
#define LVM_DELETEALLITEMS		   (LVM_FIRST +  9)
#define LVM_GETCALLBACKMASK		   (LVM_FIRST + 10)
#define LVM_SETCALLBACKMASK		   (LVM_FIRST + 11)

#if _WIN32_IE >= _WIN32_IE_IE40

#define LVM_SETBKIMAGEA 		  (LVM_FIRST +  68)
#define LVM_SETBKIMAGEW 		  (LVM_FIRST + 138)
#define LVM_GETBKIMAGEA 		  (LVM_FIRST +  69)
#define LVM_GETBKIMAGEW 		  (LVM_FIRST + 139)

#define LV_MAX_WORKAREAS				16

#define LVM_SETWORKAREAS		   (LVM_FIRST + 65)
#define LVM_GETWORKAREAS		   (LVM_FIRST + 70)
#define LVM_GETNUMBEROFWORKAREAS	   (LVM_FIRST + 73)
#define LVM_GETSELECTIONMARK		   (LVM_FIRST + 66)
#define LVM_SETSELECTIONMARK		   (LVM_FIRST + 67)
#define LVM_SETHOVERTIME		   (LVM_FIRST + 71)
#define LVM_GETHOVERTIME		   (LVM_FIRST + 72)
#define LVM_SETTOOLTIPS 		   (LVM_FIRST + 74)
#define LVM_GETTOOLTIPS 		   (LVM_FIRST + 78)

#define LVM_SETUNICODEFORMAT		 CCM_SETUNICODEFORMAT
#define LVM_GETUNICODEFORMAT		 CCM_GETUNICODEFORMAT

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define LVNI_ALL					 0
#define LVNI_FOCUSED					 1
#define LVNI_SELECTED					 2
#define LVNI_CUT					 4
#define LVNI_DROPHILITED				 8
#define LVNI_ABOVE				       256
#define LVNI_BELOW				       512
#define LVNI_TOLEFT				      1024
#define LVNI_TORIGHT				      2048

#define LVM_GETNEXTITEM 		   (LVM_FIRST + 12)

#define LVFI_PARAM					 1
#define LVFI_STRING					 2
#define LVFI_PARTIAL					 8
#define LVFI_WRAP					32
#define LVFI_NEARESTXY					64

#define LVIF_DI_SETITEM 			    0x1000

#define LVM_FINDITEMA			   (LVM_FIRST + 13)
#define LVM_FINDITEMW			   (LVM_FIRST + 83)
#define LVIR_BOUNDS					 0
#define LVIR_ICON					 1
#define LVIR_LABEL					 2
#define LVIR_SELECTBOUNDS				 3

#define LVM_GETITEMRECT 		   (LVM_FIRST + 14)
#define LVM_SETITEMPOSITION		   (LVM_FIRST + 15)
#define LVM_GETITEMPOSITION		   (LVM_FIRST + 16)
#define LVM_GETSTRINGWIDTHA		   (LVM_FIRST + 17)
#define LVM_GETSTRINGWIDTHW		   (LVM_FIRST + 87)

#define LVHT_NOWHERE					 1
#define LVHT_ONITEMICON 				 2
#define LVHT_ONITEMLABEL				 4
#define LVHT_ONITEMSTATEICON				 8

#define LVHT_ONITEM	(LVHT_ONITEMICON | LVHT_ONITEMLABEL | LVHT_ONITEMSTATEICON)

#define LVHT_ABOVE					 8
#define LVHT_BELOW					16
#define LVHT_TORIGHT					32
#define LVHT_TOLEFT					64

#define LVM_HITTEST			   (LVM_FIRST + 18)
#define LVM_ENSUREVISIBLE		   (LVM_FIRST + 19)
#define LVM_SCROLL			   (LVM_FIRST + 20)
#define LVM_REDRAWITEMS 		   (LVM_FIRST + 21)

#define LVA_DEFAULT					 0
#define LVA_ALIGNLEFT					 1
#define LVA_ALIGNTOP					 2
#define LVA_SNAPTOGRID					 5

#define LVM_ARRANGE			  (LVM_FIRST +  22)
#define LVM_EDITLABELA			  (LVM_FIRST +  23)
#define LVM_EDITLABELW			  (LVM_FIRST + 118)
#define LVM_GETEDITCONTROL		  (LVM_FIRST +  24)

#define LVCF_FMT					 1
#define LVCF_WIDTH					 2
#define LVCF_TEXT					 4
#define LVCF_SUBITEM					 8

#if _WIN32_IE >= _WIN32_IE_IE30

#define LVCF_IMAGE					16
#define LVCF_ORDER					32

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define LVCFMT_LEFT					 0
#define LVCFMT_RIGHT					 1
#define LVCFMT_CENTER					 2
#define LVCFMT_JUSTIFYMASK				 3

#if _WIN32_IE >= _WIN32_IE_IE30

#define LVCFMT_BITMAP_ON_RIGHT			      4096
#define LVCFMT_COL_HAS_IMAGES			     32768
#define LVCFMT_IMAGE				      2048

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define LVM_GETCOLUMNA			   (LVM_FIRST + 25)
#define LVM_GETCOLUMNW			   (LVM_FIRST + 95)
#define LVM_SETCOLUMNA			   (LVM_FIRST + 26)
#define LVM_SETCOLUMNW			   (LVM_FIRST + 96)
#define LVM_INSERTCOLUMNA		   (LVM_FIRST + 27)
#define LVM_INSERTCOLUMNW		   (LVM_FIRST + 97)
#define LVM_DELETECOLUMN		   (LVM_FIRST + 28)
#define LVM_GETCOLUMNWIDTH		   (LVM_FIRST + 29)

#define LVSCW_AUTOSIZE				       (-1)
#define LVSCW_AUTOSIZE_USEHEADER		       (-2)

#define LVM_SETCOLUMNWIDTH		  (LVM_FIRST +  30)
#define LVM_CREATEDRAGIMAGE		  (LVM_FIRST +  33)
#define LVM_GETVIEWRECT 		  (LVM_FIRST +  34)
#define LVM_GETTEXTCOLOR		  (LVM_FIRST +  35)
#define LVM_SETTEXTCOLOR		  (LVM_FIRST +  36)
#define LVM_GETTEXTBKCOLOR		  (LVM_FIRST +  37)
#define LVM_SETTEXTBKCOLOR		  (LVM_FIRST +  38)
#define LVM_GETTOPINDEX 		  (LVM_FIRST +  39)
#define LVM_GETCOUNTPERPAGE		  (LVM_FIRST +  40)
#define LVM_GETORIGIN			  (LVM_FIRST +  41)
#define LVM_GETORIGIN			  (LVM_FIRST +  41)
#define LVM_UPDATE			  (LVM_FIRST +  42)
#define LVM_SETITEMSTATE		  (LVM_FIRST +  43)
#define LVM_GETITEMSTATE		  (LVM_FIRST +  44)
#define LVM_GETITEMTEXTA		  (LVM_FIRST +  45)
#define LVM_GETITEMTEXTW		  (LVM_FIRST + 115)
#define LVM_SETITEMTEXTA		  (LVM_FIRST +  46)
#define LVM_SETITEMTEXTW		  (LVM_FIRST + 116)
#define LVM_SETITEMCOUNT		  (LVM_FIRST +  47)
#define LVM_SORTITEMS			  (LVM_FIRST +  48)
#define LVM_SETITEMPOSITION32		  (LVM_FIRST +  49)
#define LVM_GETSELECTEDCOUNT		  (LVM_FIRST +  50)
#define LVM_GETITEMSPACING		  (LVM_FIRST +  51)
#define LVM_GETISEARCHSTRINGA		  (LVM_FIRST +  52)
#define LVM_GETISEARCHSTRINGW		  (LVM_FIRST + 117)

#if _WIN32_IE >= _WIN32_IE_IE30

#define LVM_APPROXIMATEVIEWRECT 	   (LVM_FIRST + 64)
#define LVM_SETEXTENDEDLISTVIEWSTYLE	   (LVM_FIRST + 54)
#define LVM_GETEXTENDEDLISTVIEWSTYLE	   (LVM_FIRST + 55)
#define LVM_SETCOLUMNORDERARRAY 	   (LVM_FIRST + 58)
#define LVM_GETCOLUMNORDERARRAY 	   (LVM_FIRST + 59)
#define LVM_GETHEADER			   (LVM_FIRST + 31)
#define LVM_GETHOTCURSOR		   (LVM_FIRST + 63)
#define LVM_GETHOTITEM			   (LVM_FIRST + 61)
#define LVM_GETSUBITEMRECT		   (LVM_FIRST + 56)
#define LVM_SETHOTCURSOR		   (LVM_FIRST + 62)
#define LVM_SETHOTITEM			   (LVM_FIRST + 60)
#define LVM_SETICONSPACING		   (LVM_FIRST + 53)
#define LVM_SUBITEMHITTEST		   (LVM_FIRST + 57)

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define LVN_ITEMCHANGING		   (LVN_FIRST -  0)
#define LVN_ITEMCHANGED 		   (LVN_FIRST -  1)
#define LVN_INSERTITEM			   (LVN_FIRST -  2)
#define LVN_DELETEITEM			   (LVN_FIRST -  3)
#define LVN_DELETEALLITEMS		   (LVN_FIRST -  4)
#define LVN_BEGINLABELEDITA		   (LVN_FIRST -  5)
#define LVN_BEGINLABELEDITW		   (LVN_FIRST - 75)
#define LVN_ENDLABELEDITA		   (LVN_FIRST -  6)
#define LVN_ENDLABELEDITW		   (LVN_FIRST - 76)
#define LVN_COLUMNCLICK 		   (LVN_FIRST -  8)
#define LVN_BEGINDRAG			   (LVN_FIRST -  9)
#define LVN_BEGINRDRAG			   (LVN_FIRST - 11)
#define LVN_GETDISPINFOA		   (LVN_FIRST - 50)
#define LVN_GETDISPINFOW		   (LVN_FIRST - 77)
#define LVN_SETDISPINFOA		   (LVN_FIRST - 51)
#define LVN_SETDISPINFOW		   (LVN_FIRST - 78)
#define LVN_KEYDOWN			   (LVN_FIRST - 55)

#if _WIN32_IE >= _WIN32_IE_IE40

#define LVN_MARQUEEBEGIN		   (LVN_FIRST - 56)
#define LVN_GETINFOTIPA 		   (LVN_FIRST - 57)
#define LVN_GETINFOTIPW 		   (LVN_FIRST - 58)

#define LVKF_ALT				    0x0001
#define LVKF_CONTROL				    0x0002
#define LVKF_SHIFT				    0x0004

#define LVGIT_UNFOLDED					 1

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TVS_HASBUTTONS					 1
#define TVS_HASLINES					 2
#define TVS_LINESATROOT 				 4
#define TVS_EDITLABELS					 8
#define TVS_DISABLEDRAGDROP				16
#define TVS_SHOWSELALWAYS				32

#if _WIN32_IE >= _WIN32_IE_IE30

#define TVS_CHECKBOXES				       256
#define TVS_NOTOOLTIPS				       128
#define TVS_RTLREADING					64
#define TVS_TRACKSELECT 			       512

#if _WIN32_IE >= _WIN32_IE_IE40

#define TVS_FULLROWSELECT			      4096
#define TVS_INFOTIP				      2048
#define TVS_NONEVENHEIGHT			     16384
#define TVS_NOSCROLL				      8192
#define TVS_SINGLEEXPAND			      1024

#if _WIN32_IE >= _WIN32_IE_IE50

#define TVS_NOHSCROLL				    0x8000

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TVIF_TEXT					 1
#define TVIF_IMAGE					 2
#define TVIF_PARAM					 4
#define TVIF_STATE					 8
#define TVIF_HANDLE					16
#define TVIF_SELECTEDIMAGE				32
#define TVIF_CHILDREN					64

#if _WIN32_IE >= _WIN32_IE_IE40

#define TVIF_INTEGRAL				    0x0080

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TVIS_FOCUSED					 1
#define TVIS_SELECTED					 2
#define TVIS_CUT					 4
#define TVIS_DROPHILITED				 8
#define TVIS_BOLD					16
#define TVIS_EXPANDED					32
#define TVIS_EXPANDEDONCE				64

#define TVIS_OVERLAYMASK			     0xF00
#define TVIS_STATEIMAGEMASK			    0xF000
#define TVIS_USERMASK				    0xF000

#define I_CHILDRENCALLBACK			       (-1)

#define TVI_ROOT		   ((HTREEITEM)(0xFFFF0000))
#define TVI_FIRST		   ((HTREEITEM)(0xFFFF0001))
#define TVI_LAST		   ((HTREEITEM)(0xFFFF0002))
#define TVI_SORT		   ((HTREEITEM)(0xFFFF0003))

#define TVSIL_NORMAL					 0
#define TVSIL_STATE					 2

#define TVM_INSERTITEMA 		    (TV_FIRST +  0)
#define TVM_INSERTITEMW 		    (TV_FIRST + 50)
#define TVM_DELETEITEM			    (TV_FIRST +  1)
#define TVM_EXPAND			    (TV_FIRST +  2)
#define TVM_GETITEMRECT 		    (TV_FIRST +  4)
#define TVM_GETCOUNT			    (TV_FIRST +  5)
#define TVM_GETINDENT			    (TV_FIRST +  6)
#define TVM_SETINDENT			    (TV_FIRST +  7)
#define TVM_GETIMAGELIST		    (TV_FIRST +  8)
#define TVM_SETIMAGELIST		    (TV_FIRST +  9)
#define TVM_GETNEXTITEM 		    (TV_FIRST + 10)
#define TVM_SELECTITEM			    (TV_FIRST + 11)
#define TVM_GETITEMA			    (TV_FIRST + 12)
#define TVM_GETITEMW			    (TV_FIRST + 62)
#define TVM_SETITEMA			    (TV_FIRST + 13)
#define TVM_SETITEMW			    (TV_FIRST + 63)
#define TVM_EDITLABELA			    (TV_FIRST + 14)
#define TVM_EDITLABELW			    (TV_FIRST + 65)
#define TVM_GETEDITCONTROL		    (TV_FIRST + 15)
#define TVM_GETVISIBLECOUNT		    (TV_FIRST + 16)
#define TVM_HITTEST			    (TV_FIRST + 17)
#define TVM_CREATEDRAGIMAGE		    (TV_FIRST + 18)
#define TVM_SORTCHILDREN		    (TV_FIRST + 19)
#define TVM_ENSUREVISIBLE		    (TV_FIRST + 20)
#define TVM_SORTCHILDRENCB		    (TV_FIRST + 21)
#define TVM_ENDEDITLABELNOW		    (TV_FIRST + 22)
#define TVM_GETISEARCHSTRINGA		    (TV_FIRST + 23)
#define TVM_GETISEARCHSTRINGW		    (TV_FIRST + 64)

#if _WIN32_IE >= _WIN32_IE_IE30

#define TVM_GETTOOLTIPS 		    (TV_FIRST + 25)
#define TVM_SETTOOLTIPS 		    (TV_FIRST + 24)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TVM_GETBKCOLOR			    (TV_FIRST + 31)
#define TVM_GETINSERTMARKCOLOR		    (TV_FIRST + 38)
#define TVM_GETITEMHEIGHT		    (TV_FIRST + 28)
#define TVM_GETSCROLLTIME		    (TV_FIRST + 34)
#define TVM_GETTEXTCOLOR		    (TV_FIRST + 32)
#define TVM_SETBKCOLOR			    (TV_FIRST + 29)
#define TVM_SETINSERTMARK		    (TV_FIRST + 26)
#define TVM_SETINSERTMARKCOLOR		    (TV_FIRST + 37)
#define TVM_SETITEMHEIGHT		    (TV_FIRST + 27)
#define TVM_SETSCROLLTIME		    (TV_FIRST + 33)
#define TVM_SETTEXTCOLOR		    (TV_FIRST + 30)

#define TVM_SETUNICODEFORMAT		  CCM_SETUNICODEFORMAT
#define TVM_GETUNICODEFORMAT		  CCM_GETUNICODEFORMAT

#if _WIN32_IE >= _WIN32_IE_IE50

#define TVM_GETITEMSTATE		    (TV_FIRST + 39)
#define TVM_SETLINECOLOR		    (TV_FIRST + 40)
#define TVM_GETLINECOLOR		    (TV_FIRST + 41)

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TVE_COLLAPSE					 1
#define TVE_EXPAND					 2
#define TVE_TOGGLE					 3

#define TVE_COLLAPSERESET			    0x8000

#if _WIN32_IE >= _WIN32_IE_IE30

#define TVE_EXPANDPARTIAL			    0x4000

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TVC_UNKNOWN					 0
#define TVC_BYMOUSE					 1
#define TVC_BYKEYBOARD					 2
#define TVGN_ROOT					 0
#define TVGN_NEXT					 1
#define TVGN_PREVIOUS					 2
#define TVGN_PARENT					 3
#define TVGN_CHILD					 4
#define TVGN_FIRSTVISIBLE				 5
#define TVGN_NEXTVISIBLE				 6
#define TVGN_PREVIOUSVISIBLE				 7
#define TVGN_DROPHILITE 				 8
#define TVGN_CARET					 9

#if _WIN32_IE >= _WIN32_IE_IE40

#define TVGN_LASTVISIBLE				10

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TVN_SELCHANGINGA		   (TVN_FIRST -  1)
#define TVN_SELCHANGINGW		   (TVN_FIRST - 50)
#define TVN_SELCHANGEDA 		   (TVN_FIRST -  2)
#define TVN_SELCHANGEDW 		   (TVN_FIRST - 51)
#define TVN_GETDISPINFOA		   (TVN_FIRST -  3)
#define TVN_GETDISPINFOW		   (TVN_FIRST - 52)
#define TVN_SETDISPINFOA		   (TVN_FIRST -  4)
#define TVN_SETDISPINFOW		   (TVN_FIRST - 53)
#define TVN_ITEMEXPANDINGA		   (TVN_FIRST -  5)
#define TVN_ITEMEXPANDINGW		   (TVN_FIRST - 54)
#define TVN_ITEMEXPANDEDA		   (TVN_FIRST -  6)
#define TVN_ITEMEXPANDEDW		   (TVN_FIRST - 55)
#define TVN_BEGINDRAGA			   (TVN_FIRST -  7)
#define TVN_BEGINDRAGW			   (TVN_FIRST - 56)
#define TVN_BEGINRDRAGA 		   (TVN_FIRST -  8)
#define TVN_BEGINRDRAGW 		   (TVN_FIRST - 57)
#define TVN_DELETEITEMA 		   (TVN_FIRST -  9)
#define TVN_DELETEITEMW 		   (TVN_FIRST - 58)
#define TVN_BEGINLABELEDITA		   (TVN_FIRST - 10)
#define TVN_BEGINLABELEDITW		   (TVN_FIRST - 59)
#define TVN_ENDLABELEDITA		   (TVN_FIRST - 11)
#define TVN_ENDLABELEDITW		   (TVN_FIRST - 60)
#define TVN_KEYDOWN			   (TVN_FIRST - 12)

#if _WIN32_IE >= _WIN32_IE_IE40

#define TVN_GETINFOTIPA 		   (TVN_FIRST - 13)
#define TVN_GETINFOTIPW 		   (TVN_FIRST - 14)
#define TVN_SINGLEEXPAND		   (TVN_FIRST - 15)

#define TVNRET_DEFAULT					 0
#define TVNRET_SKIPOLD					 1
#define TVNRET_SKIPNEW					 2

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TVIF_DI_SETITEM 			    0x1000

#define TVHT_NOWHERE					 1
#define TVHT_ONITEMICON 				 2
#define TVHT_ONITEMLABEL				 4

#define TVHT_ONITEM	(TVHT_ONITEMICON | TVHT_ONITEMLABEL | TVHT_ONITEMSTATEICON)

#define TVHT_ONITEMINDENT				 8
#define TVHT_ONITEMBUTTON				16
#define TVHT_ONITEMRIGHT				32
#define TVHT_ONITEMSTATEICON				64
#define TVHT_ABOVE				       256
#define TVHT_BELOW				       512
#define TVHT_TORIGHT				      1024
#define TVHT_TOLEFT				      2048

#define TCHT_NOWHERE					 1
#define TCHT_ONITEMICON 				 2
#define TCHT_ONITEMLABEL				 4

#define TCHT_ONITEM			(TCHT_ONITEMICON | TCHT_ONITEMLABEL)

#define TCS_FORCEICONLEFT				16
#define TCS_FORCELABELLEFT				32
#define TCS_TABS					 0
#define TCS_BUTTONS				       256
#define TCS_SINGLELINE					 0
#define TCS_MULTILINE				       512
#define TCS_RIGHTJUSTIFY				 0
#define TCS_FIXEDWIDTH				      1024
#define TCS_RAGGEDRIGHT 			      2048

#define TCS_FOCUSONBUTTONDOWN			    0x1000
#define TCS_OWNERDRAWFIXED			    0x2000
#define TCS_TOOLTIPS				    0x4000
#define TCS_FOCUSNEVER				    0x8000

#if _WIN32_IE >= _WIN32_IE_IE30

#define TCS_BOTTOM					 2
#define TCS_RIGHT					 2
#define TCS_VERTICAL				       128

#define TCS_SCROLLOPPOSITE			    0x0001
#define TCS_HOTTRACK				    0x0040
#define TCS_MULTISELECT 			    0x0004

#if _WIN32_IE >= _WIN32_IE_IE40

#define TCS_FLATBUTTONS 			    0x0008
#define TCS_EX_FLATSEPARATORS			0x00000001
#define TCS_EX_REGISTERDROP			0x00000002

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define TCIF_TEXT					 1
#define TCIF_IMAGE					 2
#define TCIF_RTLREADING 				 4
#define TCIF_PARAM					 8

#if _WIN32_IE >= _WIN32_IE_IE40

#define TCIF_STATE					16

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TCIS_BUTTONPRESSED				 1

#if _WIN32_IE >= _WIN32_IE_IE40

#define TCIS_HIGHLIGHTED				 2

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TCM_FIRST				    0x1300

#define TCM_GETIMAGELIST		   (TCM_FIRST +  2)
#define TCM_SETIMAGELIST		   (TCM_FIRST +  3)
#define TCM_GETITEMCOUNT		   (TCM_FIRST +  4)
#define TCM_GETITEMA			   (TCM_FIRST +  5)
#define TCM_GETITEMW			   (TCM_FIRST + 60)
#define TCM_SETITEMA			   (TCM_FIRST +  6)
#define TCM_SETITEMW			   (TCM_FIRST + 61)
#define TCM_INSERTITEMA 		   (TCM_FIRST +  7)
#define TCM_INSERTITEMW 		   (TCM_FIRST + 62)
#define TCM_DELETEITEM			   (TCM_FIRST +  8)
#define TCM_DELETEALLITEMS		   (TCM_FIRST +  9)
#define TCM_GETITEMRECT 		   (TCM_FIRST + 10)
#define TCM_GETCURSEL			   (TCM_FIRST + 11)
#define TCM_SETCURSEL			   (TCM_FIRST + 12)
#define TCM_HITTEST			   (TCM_FIRST + 13)
#define TCM_SETITEMEXTRA		   (TCM_FIRST + 14)

#define TCM_ADJUSTRECT			   (TCM_FIRST + 40)
#define TCM_SETITEMSIZE 		   (TCM_FIRST + 41)
#define TCM_REMOVEIMAGE 		   (TCM_FIRST + 42)
#define TCM_SETPADDING			   (TCM_FIRST + 43)
#define TCM_GETROWCOUNT 		   (TCM_FIRST + 44)
#define TCM_GETTOOLTIPS 		   (TCM_FIRST + 45)
#define TCM_SETTOOLTIPS 		   (TCM_FIRST + 46)
#define TCM_GETCURFOCUS 		   (TCM_FIRST + 47)
#define TCM_SETCURFOCUS 		   (TCM_FIRST + 48)
#define TCM_SETMINTABWIDTH		   (TCM_FIRST + 49)
#define TCM_DESELECTALL 		   (TCM_FIRST + 50)

#if _WIN32_IE >=_WIN32_IE_IE40

#define TCM_HIGHLIGHTITEM		   (TCM_FIRST + 51)
#define TCM_SETEXTENDEDSTYLE		   (TCM_FIRST + 52)
#define TCM_GETEXTENDEDSTYLE		   (TCM_FIRST + 53)

#define TCM_SETUNICODEFORMAT		 CCM_SETUNICODEFORMAT
#define TCM_GETUNICODEFORMAT		 CCM_GETUNICODEFORMAT

#endif	/* _WIN32_IE >=_WIN32_IE_IE40 */

#define TCN_KEYDOWN			   (TCN_FIRST -  0)
#define TCN_SELCHANGE			   (TCN_FIRST -  1)
#define TCN_SELCHANGING 		   (TCN_FIRST -  2)

#define NM_OUTOFMEMORY			    (NM_FIRST -  1)
#define NM_CLICK			    (NM_FIRST -  2)
#define NM_DBLCLK			    (NM_FIRST -  3)
#define NM_RETURN			    (NM_FIRST -  4)
#define NM_RCLICK			    (NM_FIRST -  5)
#define NM_RDBLCLK			    (NM_FIRST -  6)
#define NM_SETFOCUS			    (NM_FIRST -  7)
#define NM_KILLFOCUS			    (NM_FIRST -  8)
#define NM_CUSTOMDRAW			    (NM_FIRST - 12)
#define NM_HOVER			    (NM_FIRST - 13)
#define NM_NCHITTEST			    (NM_FIRST - 14)
#define NM_KEYDOWN			    (NM_FIRST - 15)
#define NM_RELEASEDCAPTURE		    (NM_FIRST - 16)
#define NM_SETCURSOR			    (NM_FIRST - 17)
#define NM_CHAR 			    (NM_FIRST - 18)
#define NM_TOOLTIPSCREATED		    (NM_FIRST - 19)

#define SBARS_SIZEGRIP				       256
#define CCM_FIRST				    0x2000

#define CCM_LAST			(CCM_FIRST + 0x200)

#define CCM_SETBKCOLOR				      8193
#define CCM_SETCOLORSCHEME			      8194
#define CCM_GETCOLORSCHEME			      8195
#define CCM_GETDROPTARGET			      8196
#define CCM_SETUNICODEFORMAT			      8197
#define CCM_GETUNICODEFORMAT			      8198
#define CCM_SETVERSION				    0x2007
#define CCM_GETVERSION				    0x2008
#define CCM_SETNOTIFYWINDOW			    0x2009

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define CCM_SETWINDOWTHEME			    0x200B
#define CCM_DPISCALE				    0x200C

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define ICC_LISTVIEW_CLASSES				 1
#define ICC_TREEVIEW_CLASSES				 2
#define ICC_BAR_CLASSES 				 4
#define ICC_TAB_CLASSES 				 8
#define ICC_UPDOWN_CLASS				16
#define ICC_PROGRESS_CLASS				32
#define ICC_HOTKEY_CLASS				64
#define ICC_ANIMATE_CLASS			       128
#define ICC_WIN95_CLASSES			       255
#define ICC_DATE_CLASSES			       256
#define ICC_USEREX_CLASSES			       512
#define ICC_COOL_CLASSES			      1024

#if _WIN32_IE >= _WIN32_IE_IE40

#define ICC_INTERNET_CLASSES			      2048
#define ICC_PAGESCROLLER_CLASS			      4096
#define ICC_NATIVEFNTCTL_CLASS			      8192
#define INFOTIPSIZE				      1024

#endif	/* _WIN32_IE */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define ICC_STANDARD_CLASSES			0x00004000
#define ICC_LINK_CLASS				0x00008000

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define GDTR_MIN					 1
#define GDTR_MAX					 2
#define GMR_VISIBLE					 0
#define GMR_DAYSTATE					 1
#define GDT_ERROR					-1
#define GDT_VALID					 0
#define GDT_NONE					 1
#define DTS_UPDOWN					 1
#define DTS_SHOWNONE					 2
#define DTS_SHORTDATEFORMAT				 0
#define DTS_LONGDATEFORMAT				 4
#define DTS_TIMEFORMAT					 9
#define DTS_APPCANPARSE 				16
#define DTS_RIGHTALIGN					32

#if _WIN32_IE >= _WIN32_IE_IE50

#define DTS_SHORTDATECENTURYFORMAT		    0x000C

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

#define MCS_DAYSTATE					 1
#define MCS_MULTISELECT 				 2
#define MCS_WEEKNUMBERS 				 4

#if _WIN32_IE >= _WIN32_IE_IE40

#define MCS_NOTODAYCIRCLE			    0x0008
#define MCS_NOTODAY				    0x0010

#else	/* _WIN32_IE < _WIN32_IE_IE40 */

#define MCS_NOTODAY				    0x0008

#endif	/* _WIN32_IE < _WIN32_IE_IE40 */

#define DTM_GETSYSTEMTIME			    0x1001
#define DTM_SETSYSTEMTIME			    0x1002
#define DTM_GETRANGE				    0x1003
#define DTM_SETRANGE				    0x1004
#define DTM_SETFORMATA				    0x1005
#define DTM_SETFORMATW				    0x1032
#define DTM_SETMCCOLOR				    0x1006
#define DTM_GETMCCOLOR				    0x1007
#define DTM_GETMONTHCAL 			    0x1008
#define DTM_SETMCFONT				    0x1009
#define DTM_GETMCFONT				    0x100A

#define DTN_USERSTRINGA 		      ((UINT)(-758))
#define DTN_USERSTRINGW 		      ((UINT)(-745))
#define DTN_WMKEYDOWNA			      ((UINT)(-757))
#define DTN_WMKEYDOWNW			      ((UINT)(-744))
#define DTN_FORMATA			      ((UINT)(-756))
#define DTN_FORMATW			      ((UINT)(-743))
#define DTN_FORMATQUERYA		      ((UINT)(-755))
#define DTN_FORMATQUERYW		      ((UINT)(-742))
#define DTN_DROPDOWN			      ((UINT)(-754))
#define DTN_CLOSEUP			      ((UINT)(-753))
#define DTN_DATETIMECHANGE		      ((UINT)(-759))

#define MCM_GETCURSEL				    0x1001
#define MCM_SETCURSEL				    0x1002
#define MCM_GETMAXSELCOUNT			    0x1003
#define MCM_SETMAXSELCOUNT			    0x1004
#define MCM_GETSELRANGE 			    0x1005
#define MCM_SETSELRANGE 			    0x1006
#define MCM_GETMONTHRANGE			    0x1007
#define MCM_SETDAYSTATE 			    0x1008
#define MCM_GETMINREQRECT			    0x1009
#define MCM_SETCOLOR				    0x100A
#define MCM_GETCOLOR				    0x100B
#define MCM_SETTODAY				    0x100C
#define MCM_GETTODAY				    0x100D
#define MCM_HITTEST				    0x100E
#define MCM_SETFIRSTDAYOFWEEK			    0x100F
#define MCM_GETFIRSTDAYOFWEEK			    0x1010
#define MCM_GETRANGE				    0x1011
#define MCM_SETRANGE				    0x1012
#define MCM_GETMONTHDELTA			    0x1013
#define MCM_SETMONTHDELTA			    0x1014
#define MCM_GETMAXTODAYWIDTH			    0x1015

#define MCM_GETUNICODEFORMAT		   CCM_GETUNICODEFORMAT
#define MCM_SETUNICODEFORMAT		   CCM_SETUNICODEFORMAT

#define MCN_SELCHANGE			      ((UINT)(-749))
#define MCN_GETDAYSTATE 		      ((UINT)(-747))
#define MCN_SELECT			      ((UINT)(-746))

#define ODT_HEADER				       100
#define ODT_TAB 				       101
#define ODT_LISTVIEW				       102

#define SB_SETBKCOLOR				    0x2001

#if _WIN32_IE >= _WIN32_IE_IE30

#define SB_ISSIMPLE				      1038

#define MCSC_BACKGROUND 				 0
#define MCSC_TEXT					 1
#define MCSC_TITLEBK					 2
#define MCSC_TITLETEXT					 3
#define MCSC_MONTHBK					 4
#define MCSC_TRAILINGTEXT				 5

#if _WIN32_IE >= _WIN32_IE_IE40

#define MCHT_TITLE				   0x10000
#define MCHT_CALENDAR				   0x20000
#define MCHT_TODAYLINK				   0x30000
#define MCHT_NEXT				 0x1000000
#define MCHT_PREV				 0x2000000
#define MCHT_NOWHERE				      0x00

#define MCHT_TITLEBK			       (MCHT_TITLE)
#define MCHT_TITLEMONTH 		       (MCHT_TITLE | 0x0001)
#define MCHT_TITLEYEAR			       (MCHT_TITLE | 0x0002)
#define MCHT_TITLEBTNNEXT	   (MCHT_TITLE | MCHT_NEXT | 0x0003)
#define MCHT_TITLEBTNPREV	   (MCHT_TITLE | MCHT_PREV | 0x0003)

#define MCHT_CALENDARBK			    (MCHT_CALENDAR)
#define MCHT_CALENDARDATE		    (MCHT_CALENDAR | 0x0001)
#define MCHT_CALENDARDATENEXT		(MCHT_CALENDARDATE | MCHT_NEXT)
#define MCHT_CALENDARDATEPREV		(MCHT_CALENDARDATE | MCHT_PREV)
#define MCHT_CALENDARDAY		    (MCHT_CALENDAR | 0x0002)
#define MCHT_CALENDARWEEKNUM		    (MCHT_CALENDAR | 0x0003)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define RBS_TOOLTIPS				       256
#define RBS_VARHEIGHT				       512
#define RBS_BANDBORDERS 			      1024
#define RBS_FIXEDORDER				      2048
#define RBIM_IMAGELIST					 1

#define RB_SETCOLORSCHEME		   CCM_SETCOLORSCHEME
#define RB_GETCOLORSCHEME		   CCM_GETCOLORSCHEME

#define RBBS_BREAK				    0x0001
#define RBBS_FIXEDSIZE				    0x0002
#define RBBS_CHILDEDGE				    0x0004
#define RBBS_HIDDEN				    0x0008
#define RBBS_NOVERT				    0x0010
#define RBBS_FIXEDBMP				    0x0020
#define RBBS_VARIABLEHEIGHT			    0x0040
#define RBBS_GRIPPERALWAYS			    0x0080
#define RBBS_NOGRIPPER				    0x0100

#if _WIN32_IE >= _WIN32_IE_IE50

#define RBBS_USECHEVRON 			    0x0200

#if _WIN32_IE >= _WIN32_IE_IE501

#define RBBS_HIDETITLE				    0x0400
#define RBBS_TOPALIGN				    0x0800

#endif	/* _WIN32_IE >= _WIN32_IE_IE501 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

#define RBBIM_STYLE					 1
#define RBBIM_COLORS					 2
#define RBBIM_TEXT					 4
#define RBBIM_IMAGE					 8
#define RBBIM_CHILD					16
#define RBBIM_CHILDSIZE 				32
#define RBBIM_SIZE					64
#define RBBIM_BACKGROUND			       128
#define RBBIM_ID				       256

#define RB_INSERTBANDA			     (WM_USER +  1)
#define RB_INSERTBANDW			     (WM_USER + 10)
#define RB_DELETEBAND			     (WM_USER +  2)
#define RB_GETBARINFO			     (WM_USER +  3)
#define RB_SETBARINFO			     (WM_USER +  4)
#define RB_GETBANDCOUNT 		     (WM_USER + 12)
#define RB_GETROWCOUNT			     (WM_USER + 13)
#define RB_GETROWHEIGHT 		     (WM_USER + 14)
#define RB_SETBANDINFOA 		     (WM_USER +  6)
#define RB_SETBANDINFOW 		     (WM_USER + 11)
#define RB_SETPARENT			     (WM_USER +  7)

#define RBN_HEIGHTCHANGE			 RBN_FIRST

#if _WIN32_IE >= _WIN32_IE_IE30

#define LVN_ODCACHEHINT 		   (LVN_FIRST - 13)

#define LVN_ODFINDITEM		__AW_SUFFIXED__( LVN_ODFINDITEM )

#define LVN_ODFINDITEMA 		   (LVN_FIRST - 52)
#define LVN_ODFINDITEMW 		   (LVN_FIRST - 79)

#define LVN_ITEMACTIVATE		   (LVN_FIRST - 14)
#define LVN_ODSTATECHANGED		   (LVN_FIRST - 15)

#endif	/* _WIN32_IE */

#if _WIN32_IE >= _WIN32_IE_IE40

#define SB_SETICON				      1039
#define SB_SETTIPTEXTA				      1040
#define SB_SETTIPTEXTW				      1041
#define SB_GETTIPTEXTA				      1042
#define SB_GETTIPTEXTW				      1043
#define SB_GETICON				      1044

#define SB_SETUNICODEFORMAT			    0x2005
#define SB_GETUNICODEFORMAT			    0x2006

#define PGF_INVISIBLE					 0
#define PGF_NORMAL					 1
#define PGF_GRAYED					 2
#define PGF_DEPRESSED					 4
#define PGF_HOT 					 8

#define PGB_TOPORLEFT					 0
#define PGB_BOTTOMORRIGHT				 1

#define PGF_SCROLLUP					 1
#define PGF_SCROLLDOWN					 2
#define PGF_SCROLLLEFT					 4
#define PGF_SCROLLRIGHT 				 8

#define PGK_SHIFT					 1
#define PGK_CONTROL					 2
#define PGK_MENU					 4

#define PGF_CALCWIDTH					 1
#define PGF_CALCHEIGHT					 2

#define PGM_FIRST				    0x1400

#define PGM_SETCHILD			   (PGM_FIRST +  1)
#define PGM_RECALCSIZE			   (PGM_FIRST +  2)
#define PGM_FORWARDMOUSE		   (PGM_FIRST +  3)
#define PGM_SETBKCOLOR			   (PGM_FIRST +  4)
#define PGM_GETBKCOLOR			   (PGM_FIRST +  5)
#define PGM_SETBORDER			   (PGM_FIRST +  6)
#define PGM_GETBORDER			   (PGM_FIRST +  7)
#define PGM_SETPOS			   (PGM_FIRST +  8)
#define PGM_GETPOS			   (PGM_FIRST +  9)
#define PGM_SETBUTTONSIZE		   (PGM_FIRST + 10)
#define PGM_GETBUTTONSIZE		   (PGM_FIRST + 11)
#define PGM_GETBUTTONSTATE		   (PGM_FIRST + 12)

#define PGM_GETDROPTARGET		   CCM_GETDROPTARGET

#define RBS_REGISTERDROP			      4096
#define RBS_AUTOSIZE				      8192
#define RBS_VERTICALGRIPPER			     16384
#define RBS_DBLCLKTOGGLE			     32768
#define RBBIM_IDEALSIZE 			       512
#define RBBIM_LPARAM				      1024
#define RBBIM_HEADERSIZE			      2048

#define RB_HITTEST			     (WM_USER +  8)
#define RB_GETRECT			     (WM_USER +  9)
#define RB_IDTOINDEX			     (WM_USER + 16)
#define RB_GETTOOLTIPS			     (WM_USER + 17)
#define RB_SETTOOLTIPS			     (WM_USER + 18)
#define RB_SETBKCOLOR			     (WM_USER + 19)
#define RB_GETBKCOLOR			     (WM_USER + 20)
#define RB_SETTEXTCOLOR 		     (WM_USER + 21)
#define RB_GETTEXTCOLOR 		     (WM_USER + 22)
#define RB_SIZETORECT			     (WM_USER + 23)
#define RB_BEGINDRAG			     (WM_USER + 24)
#define RB_ENDDRAG			     (WM_USER + 25)
#define RB_DRAGMOVE			     (WM_USER + 26)
#define RB_GETBARHEIGHT 		     (WM_USER + 27)
#define RB_GETBANDINFOW 		     (WM_USER + 28)
#define RB_GETBANDINFOA 		     (WM_USER + 29)
#define RB_MINIMIZEBAND 		     (WM_USER + 30)
#define RB_MAXIMIZEBAND 		     (WM_USER + 31)

#define RB_GETDROPTARGET		   CCM_GETDROPTARGET

#define RB_GETBANDBORDERS		     (WM_USER + 34)
#define RB_SHOWBAND			     (WM_USER + 35)
#define RB_SETPALETTE			     (WM_USER + 37)
#define RB_GETPALETTE			     (WM_USER + 38)
#define RB_MOVEBAND			     (WM_USER + 39)

#define RB_SETUNICODEFORMAT		  CCM_SETUNICODEFORMAT
#define RB_GETUNICODEFORMAT		  CCM_GETUNICODEFORMAT

#define RBN_GETOBJECT			    (RBN_FIRST - 1)
#define RBN_LAYOUTCHANGED		    (RBN_FIRST - 2)
#define RBN_AUTOSIZE			    (RBN_FIRST - 3)
#define RBN_BEGINDRAG			    (RBN_FIRST - 4)
#define RBN_ENDDRAG			    (RBN_FIRST - 5)
#define RBN_DELETINGBAND		    (RBN_FIRST - 6)
#define RBN_DELETEDBAND 		    (RBN_FIRST - 7)
#define RBN_CHILDSIZE			    (RBN_FIRST - 8)

#define RBNM_ID 					 1
#define RBNM_STYLE					 2
#define RBNM_LPARAM					 4
#define RBHT_NOWHERE					 1
#define RBHT_CAPTION					 2
#define RBHT_CLIENT					 3
#define RBHT_GRABBER					 4

#define SB_SETTIPTEXT		__AW_SUFFIXED__( SB_SETTIPTEXT )
#define SB_GETTIPTEXT		__AW_SUFFIXED__( SB_GETTIPTEXT )
#define RB_GETBANDINFO		__AW_SUFFIXED__( RB_GETBANDINFO )

#else	/* _WIN32_IE < _WIN32_IE_IE40 */

#define RB_GETBANDINFO			      (WM_USER + 5)

#endif	/* _WIN32_IE < _WIN32_IE_IE40 */

#define CBEM_INSERTITEMA		      (WM_USER + 1)
#define CBEM_SETIMAGELIST		      (WM_USER + 2)
#define CBEM_GETIMAGELIST		      (WM_USER + 3)
#define CBEM_GETITEMA			      (WM_USER + 4)
#define CBEM_SETITEMA			      (WM_USER + 5)

#define CBEM_DELETEITEM	CB_DELETESTRING

#define CBEM_GETCOMBOCONTROL		      (WM_USER + 6)
#define CBEM_GETEDITCONTROL		      (WM_USER + 7)
#define CBEM_SETEXSTYLE 		      (WM_USER + 8)
#define CBEM_GETEXSTYLE 		      (WM_USER + 9)

#if _WIN32_IE >= _WIN32_IE_IE40

#define CBEM_SETEXTENDEDSTYLE		     (WM_USER + 14)
#define CBEM_GETEXTENDEDSTYLE		     (WM_USER +  9)

#define CBEM_SETUNICODEFORMAT		  CCM_SETUNICODEFORMAT
#define CBEM_GETUNICODEFORMAT		  CCM_GETUNICODEFORMAT

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define CBEM_HASEDITCHANGED		     (WM_USER + 10)
#define CBEM_INSERTITEMW		     (WM_USER + 11)
#define CBEM_SETITEMW			     (WM_USER + 12)
#define CBEM_GETITEMW			     (WM_USER + 13)

#define DA_LAST 				0x7FFFFFFF
#define DPA_APPEND				0x7FFFFFFF

#define DPA_ERR 					-1

#define DSA_APPEND				0x7FFFFFFF

#define DSA_ERR 					-1

#define DPAS_SORTED					 1
#define DPAS_INSERTBEFORE				 2
#define DPAS_INSERTAFTER				 4

#if _WIN32_IE >= _WIN32_IE_IE40

#define WSB_PROP_CYVSCROLL				 1
#define WSB_PROP_CXHSCROLL				 2
#define WSB_PROP_CYHSCROLL				 4
#define WSB_PROP_CXVSCROLL				 8
#define WSB_PROP_CXHTHUMB				16
#define WSB_PROP_CYVTHUMB				32
#define WSB_PROP_VBKGCOLOR				64
#define WSB_PROP_HBKGCOLOR			       128
#define WSB_PROP_VSTYLE 			       256
#define WSB_PROP_HSTYLE 			       512
#define WSB_PROP_WINSTYLE			      1024
#define WSB_PROP_PALETTE			      2048

#define WSB_PROP_MASK				     0xFFF

#define FSB_FLAT_MODE					 2
#define FSB_ENCARTA_MODE				 1
#define FSB_REGULAR_MODE				 0

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define LIF_ITEMINDEX				0x00000001
#define LIF_STATE				0x00000002
#define LIF_ITEMID				0x00000004
#define LIF_URL 				0x00000008
#define LIS_FOCUSED				0x00000001
#define LIS_ENABLED				0x00000002
#define LIS_VISITED				0x00000004

#define LM_HITTEST			    (WM_USER + 768)
#define LM_GETIDEALHEIGHT		    (WM_USER + 769)
#define LM_SETITEM			    (WM_USER + 770)
#define LM_GETITEM			    (WM_USER + 771)

#define MAX_LINKID_TEXT 				48
#define L_MAX_URL_LENGTH			      2084

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#ifndef RC_INVOKED

typedef
struct tagNMTCKEYDOWN
{ NMHDR 		 hdr;
  WORD			 wVKey;
  UINT			 flags;
} NMTCKEYDOWN;

typedef
struct tagCOMBOBOXEXITEMA
{ UINT			 mask;
  int			 iItem;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 iOverlay;
  int			 iIndent;
  LPARAM		 lParam;
} COMBOBOXEXITEMA, *PCOMBOBOXEXITEMA;

typedef COMBOBOXEXITEMA CONST *PCCOMBOEXITEMA;

typedef
struct tagCOMBOBOXEXITEMW
{ UINT			 mask;
  int			 iItem;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 iOverlay;
  int			 iIndent;
  LPARAM		 lParam;
} COMBOBOXEXITEMW, *PCOMBOBOXEXITEMW;

typedef COMBOBOXEXITEMW CONST *PCCOMBOEXITEMW;

#if _WIN32_IE >= _WIN32_IE_IE40

typedef struct
{ NMHDR 		 hdr;
  COMBOBOXEXITEMA	 ceItem;
} NMCOMBOBOXEXA, *PNMCOMBOBOXEXA;

typedef struct
{ NMHDR 		 hdr;
  COMBOBOXEXITEMW	 ceItem;
} NMCOMBOBOXEXW, *PNMCOMBOBOXEXW;

typedef struct
{ NMHDR 		 hdr;
  int			 iItemid;
  WCHAR 		 szText[CBEMAXSTRLEN];
} NMCBEDRAGBEGINW, *LPNMCBEDRAGBEGINW, *PNMCBEDRAGBEGINW;

typedef struct
{ NMHDR 		 hdr;
  int			 iItemid;
  char			 szText[CBEMAXSTRLEN];
} NMCBEDRAGBEGINA, *LPNMCBEDRAGBEGINA, *PNMCBEDRAGBEGINA;

typedef
struct tagNMIPADDRESS
{ NMHDR 		 hdr;
  int			 iField;
  int			 iValue;
} NMIPADDRESS, *LPNMIPADDRESS;

typedef
struct tagLVKEYDOWN
{ NMHDR 		 hdr;
  WORD			 wVKey;
  UINT			 flags;
} NMLVKEYDOWN, *LPNMLVKEYDOWN;

typedef struct
{ NMHDR 		 hdr;
  DWORD 		 dwFlag;
  int			 iWidth;
  int			 iHeight;
} NMPGCALCSIZE, *LPNMPGCALCSIZE;

#pragma pack (push, 1)

typedef struct
{ /* Formerly, MinGW.org had this declared with 4-byte BOOL type for
   * the "fwKeys" field, and no specific packing requirement.  Today,
   * I can find no Microsoft documentation to support that declaration.
   * Furthermore, https://sourceforge.net/p/mingw/bugs/2248/ shows, by
   * way of a test case, that the correct declaration should probably
   * have 2-byte WORD type for "fwKeys", (as hinted by its Hungarian
   * notation name anyway), and the structure should be packed as
   * tightly as possible.
   */
  NMHDR 		 hdr;
  WORD			 fwKeys;
  RECT			 rcParent;
  int			 iDir;
  int			 iXpos;
  int			 iYpos;
  int			 iScroll;
} NMPGSCROLL, *LPNMPGSCROLL;

#pragma pack (pop)

typedef
struct tagNMSELCHANGE
{ NMHDR 		 nmhdr;
  SYSTEMTIME		 stSelStart;
  SYSTEMTIME		 stSelEnd;
} NMSELCHANGE, *LPNMSELCHANGE;

typedef
struct tagNMTBHOTITEM
{ NMHDR 		 hdr;
  int			 idOld;
  int			 idNew;
  DWORD 		 dwFlags;
} NMTBHOTITEM, *LPNMTBHOTITEM;

typedef struct
{ NMHDR 		 hdr;
  DWORD 		 dwMask;
  int			 idCommand;
  DWORD_PTR		 lParam;
  int			 iImage;
  LPSTR 		 pszText;
  int			 cchText;
} NMTBDISPINFOA, *LPNMTBDISPINFOA;

typedef struct
{ NMHDR 		 hdr;
  DWORD 		 dwMask;
  int			 idCommand;
  DWORD_PTR		 lParam;
  int			 iImage;
  LPWSTR		 pszText;
  int			 cchText;
} NMTBDISPINFOW, *LPNMTBDISPINFOW;

typedef
struct tagNMTBGETINFOTIPA
{ NMHDR 		 hdr;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iItem;
  LPARAM		 lParam;
} NMTBGETINFOTIPA, *LPNMTBGETINFOTIPA;

typedef
struct tagNMTBGETINFOTIPW
{ NMHDR 		 hdr;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iItem;
  LPARAM		 lParam;
} NMTBGETINFOTIPW, *LPNMTBGETINFOTIPW;

typedef
struct tagNMMOUSE
{ NMHDR 		 hdr;
  DWORD_PTR		 dwItemSpec;
  DWORD_PTR		 dwItemData;
  POINT 		 pt;
  LPARAM		 dwHitInfo;
} NMMOUSE, *LPNMMOUSE;

#endif	/*_WIN32_IE >= _WIN32_IE_IE40 */

#if _WIN32_IE >= _WIN32_IE_IE401

typedef
struct tagNMTOOLTIPSCREATED
{ NMHDR 		 hdr;
  HWND			 hwndToolTips;
} NMTOOLTIPSCREATED, *LPNMTOOLTIPSCREATED;

#endif	/* _WIN32_IE >= _WIN32_IE_IE401 */

typedef
struct tagNMDATETIMECHANGE
{ NMHDR 		 nmhdr;
  DWORD 		 dwFlags;
  SYSTEMTIME		 st;
} NMDATETIMECHANGE, *LPNMDATETIMECHANGE;

typedef struct
{ NMHDR 		 hdr;
  BOOL			 fChanged;
  int			 iNewSelection;
  WCHAR 		 szText[CBEMAXSTRLEN];
  int			 iWhy;
} NMCBEENDEDITW, *LPNMCBEENDEDITW, *PNMCBEENDEDITW;

typedef struct
{ NMHDR 		 hdr;
  BOOL			 fChanged;
  int			 iNewSelection;
  char			 szText[CBEMAXSTRLEN];
  int			 iWhy;
} NMCBEENDEDITA, *LPNMCBEENDEDITA, *PNMCBEENDEDITA;

typedef
struct _COLORMAP
{ COLORREF		 from;
  COLORREF		 to;
} COLORMAP, *LPCOLORMAP;

typedef struct
{ UINT			 uNotification;
  HWND			 hWnd;
  POINT 		 ptCursor;
} DRAGLISTINFO, *LPDRAGLISTINFO;

typedef
struct _TBBUTTON
{ int			 iBitmap;
  int			 idCommand;
  BYTE			 fsState;
  BYTE			 fsStyle;
  BYTE			 bReserved[2];
  DWORD 		 dwData;
  int			 iString;
} TBBUTTON, *PTBBUTTON, *LPTBBUTTON;
typedef const TBBUTTON *LPCTBBUTTON;

#if _WIN32_IE >= _WIN32_IE_IE40

typedef struct
{ UINT			 cbSize;
  DWORD 		 dwMask;
  int			 idCommand;
  int			 iImage;
  BYTE			 fsState;
  BYTE			 fsStyle;
  WORD			 cx;
  DWORD 		 lParam;
  LPSTR 		 pszText;
  int			 cchText;
} TBBUTTONINFOA, *LPTBBUTTONINFOA;

typedef struct
{ UINT			 cbSize;
  DWORD 		 dwMask;
  int			 idCommand;
  int			 iImage;
  BYTE			 fsState;
  BYTE			 fsStyle;
  WORD			 cx;
  DWORD 		 lParam;
  LPWSTR		 pszText;
  int			 cchText;
} TBBUTTONINFOW, *LPTBBUTTONINFOW;

typedef struct
{ int			 iButton;
  DWORD 		 dwFlags;
} TBINSERTMARK, *LPTBINSERTMARK;

typedef
struct tagLVBKIMAGEA
{ ULONG 		 ulFlags;
  HBITMAP		 hbm;
  LPSTR 		 pszImage;
  UINT			 cchImageMax;
  int			 xOffsetPercent;
  int			 yOffsetPercent;
} LVBKIMAGEA, *LPLVBKIMAGEA;

typedef
struct tagLVBKIMAGEW
{ ULONG 		 ulFlags;
  HBITMAP		 hbm;
  LPWSTR		 pszImage;
  UINT			 cchImageMax;
  int			 xOffsetPercent;
  int			 yOffsetPercent;
} LVBKIMAGEW, *LPLVBKIMAGEW;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef struct
{ NMHDR 		 hdr;
  int			 iItem;
  TBBUTTON		 tbButton;
  int			 cchText;
  LPTSTR		 pszText;
} TBNOTIFY, *LPTBNOTIFY;

typedef struct
{ HKEY			 hkr;
  LPCTSTR		 pszSubKey;
  LPCTSTR		 pszValueName;
} TBSAVEPARAMS;

typedef
struct _IMAGEINFO
{ HBITMAP		 hbmImage;
  HBITMAP		 hbmMask;
  int			 Unused1;
  int			 Unused2;
  RECT			 rcImage;
} IMAGEINFO, *LPIMAGEINFO;

typedef struct _IMAGELIST *HIMAGELIST;

typedef
struct _HDITEMA
{ UINT			 mask;
  int			 cxy;
  LPSTR 		 pszText;
  HBITMAP		 hbm;
  int			 cchTextMax;
  int			 fmt;
  LPARAM		 lParam;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iImage;
  int			 iOrder;

#if _WIN32_IE >= _WIN32_IE_IE50

  UINT			 type;
  LPVOID		 pvFilter;

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} HDITEMA, * LPHDITEMA;

typedef
struct _HDITEMW
{ UINT			 mask;
  int			 cxy;
  LPWSTR		 pszText;
  HBITMAP		 hbm;
  int			 cchTextMax;
  int			 fmt;
  LPARAM		 lParam;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iImage;
  int			 iOrder;

#if _WIN32_IE >= _WIN32_IE_IE50

  UINT			 type;
  LPVOID		 pvFilter;

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} HDITEMW, *LPHDITEMW;

/* for backward compatibility */
#define HD_ITEMA  HDITEMA
#define HD_ITEMW  HDITEMW
#define HD_ITEM   HDITEM

typedef
struct _HD_LAYOUT
{ RECT			*prc;
  WINDOWPOS		*pwpos;
} HDLAYOUT, *LPHDLAYOUT;
#define HD_LAYOUT HDLAYOUT /*  backward compatibility */

typedef
struct _HD_HITTESTINFO
{ POINT 		 pt;
  UINT			 flags;
  int			 iItem;
} HD_HITTESTINFO, *LPHDHITTESTINFO;

typedef
struct _HD_NOTIFYA
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iButton;
  HD_ITEMA		*pitem;
} HD_NOTIFYA;

typedef
struct _HD_NOTIFYW
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iButton;
  HD_ITEMW		*pitem;
} HD_NOTIFYW;

/* FIXME: NMHEADER structure (base for all events of the comctl controls)
 * is the same as HD_NOTIFY depending on the value of _WIN32_IE macro.
 * I'm defining both for now.
 */
typedef
struct _NMHEADERA
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iButton;
  HD_ITEMA		*pitem;
} NMHEADERA, *LPNMHEADERA;

typedef
struct _NMHEADERW
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iButton;
  HD_ITEMW		*pitem;
} NMHEADERW, *LPNMHEADERW;

#define NMHEADER    __AW_SUFFIXED__( NMHEADER )
#define LPNMHEADER  __AW_SUFFIXED__( LPNMHEADER )

/* End FIXME. */

typedef
struct tagNMHDDISPINFOA
{ NMHDR 		 hdr;
  int			 iItem;
  UINT			 mask;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;
} NMHDDISPINFOA, *LPNMHDDISPINFOA;

typedef
struct tagNMHDDISPINFOW
{ NMHDR 		 hdr;
  int			 iItem;
  UINT			 mask;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;
} NMHDDISPINFOW, *LPNMHDDISPINFOW;

typedef
struct tagNMCUSTOMDRAWINFO
{ NMHDR 		 hdr;
  DWORD 		 dwDrawStage;
  HDC			 hdc;
  RECT			 rc;
  DWORD 		 dwItemSpec;
  UINT			 uItemState;
  LPARAM		 lItemlParam;
} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;

typedef
struct tagNMLVCUSTOMDRAW
{ NMCUSTOMDRAW		 nmcd;
  COLORREF		 clrText;
  COLORREF		 clrTextBk;

#if _WIN32_IE >= _WIN32_IE_IE40

  int			 iSubItem;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

} NMLVCUSTOMDRAW, *LPNMLVCUSTOMDRAW;

#if _WIN32_IE >= _WIN32_IE_IE40

typedef
struct tagNMLVGETINFOTIPA
{ NMHDR 		 hdr;
  DWORD 		 dwFlags;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iItem;
  int			 iSubItem;
  LPARAM		 lParam;
} NMLVGETINFOTIPA, *LPNMLVGETINFOTIPA;

typedef
struct tagNMLVGETINFOTIPW
{ NMHDR 		 hdr;
  DWORD 		 dwFlags;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iItem;
  int			 iSubItem;
  LPARAM		 lParam;
} NMLVGETINFOTIPW, *LPNMLVGETINFOTIPW;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef
struct tagNMTVCUSTOMDRAW
{ NMCUSTOMDRAW		 nmcd;
  COLORREF		 clrText;
  COLORREF		 clrTextBk;

#if _WIN32_IE >= _WIN32_IE_IE40

  int			 iLevel;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

} NMTVCUSTOMDRAW, *LPNMTVCUSTOMDRAW;

#if _WIN32_IE >= _WIN32_IE_IE40

typedef
struct _NMTBCUSTOMDRAW
{ NMCUSTOMDRAW		 nmcd;
  HBRUSH		 hbrMonoDither;
  HBRUSH		 hbrLines;
  HPEN			 hpenLines;
  COLORREF		 clrText;
  COLORREF		 clrMark;
  COLORREF		 clrTextHighlight;
  COLORREF		 clrBtnFace;
  COLORREF		 clrBtnHighlight;
  COLORREF		 clrHighlightHotTrack;
  RECT			 rcText;
  int			 nStringBkMode;
  int			 nHLStringBkMode;

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

  int			 iListGap;

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

} NMTBCUSTOMDRAW, * LPNMTBCUSTOMDRAW;

typedef
struct tagNMITEMACTIVATE
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iSubItem;
  UINT			 uNewState;
  UINT			 uOldState;
  UINT			 uChanged;
  POINT 		 ptAction;
  LPARAM		 lParam;
  UINT			 uKeyFlags;
} NMITEMACTIVATE, *LPNMITEMACTIVATE;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef
struct tagTBADDBITMAP
{ HINSTANCE		 hInst;
  UINT			 nID;
} TBADDBITMAP, *LPTBADDBITMAP;

typedef
struct tagTBSAVEPARAMSA
{ HKEY			 hkr;
  LPCSTR		 pszSubKey;
  LPCSTR		 pszValueName;
} TBSAVEPARAMSA;

typedef
struct tagTBSAVEPARAMSW
{ HKEY			 hkr;
  LPCWSTR		 pszSubKey;
  LPCWSTR		 pszValueName;
} TBSAVEPARAMSW;

typedef struct
{ HINSTANCE		 hInstOld;
  UINT			 nIDOld;
  HINSTANCE		 hInstNew;
  UINT			 nIDNew;
  int			 nButtons;
} TBREPLACEBITMAP, *LPTBREPLACEBITMAP;

typedef
struct tagNMTOOLBARA
{ NMHDR 		 hdr;
  int			 iItem;
  TBBUTTON		 tbButton;
  int			 cchText;
  LPSTR 		 pszText;

#if _WIN32_IE >= _WIN32_IE_IE50

  RECT			 rcButton;

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

} NMTOOLBARA, *LPNMTOOLBARA;

#define TBNOTIFYA    NMTOOLBARA
#define LPTBNOTIFYA  LPNMTOOLBARA

typedef
struct tagNMTOOLBARW
{ NMHDR 		 hdr;
  int			 iItem;
  TBBUTTON		 tbButton;
  int			 cchText;
  LPWSTR		 pszText;

#if _WIN32_IE >= _WIN32_IE_IE50

  RECT			 rcButton;

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

} NMTOOLBARW, *LPNMTOOLBARW;

#define TBNOTIFYW    NMTOOLBARW
#define LPTBNOTIFYW  LPNMTOOLBARW

typedef
struct tagTOOLINFOA
{ UINT			 cbSize;
  UINT			 uFlags;
  HWND			 hwnd;
  UINT			 uId;
  RECT			 rect;
  HINSTANCE		 hinst;
  LPSTR 		 lpszText;

#if _WIN32_IE >= _WIN32_IE_IE30

  LPARAM		 lParam;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} TTTOOLINFOA, *LPTTTOOLINFOA, *PTOOLINFOA;

#define TOOLINFOA            TTTOOLINFOA
#define LPTOOLINFOA          LPTTTOOLINFOA
#define TTTOOLINFOA_V1_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOA, lpszText)
#define TTTOOLINFOA_V2_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOA, lParam)
#define TTTOOLINFOA_V3_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOA, lpReserved)

typedef
struct tagTOOLINFOW
{ UINT			 cbSize;
  UINT			 uFlags;
  HWND			 hwnd;
  UINT			 uId;
  RECT			 rect;
  HINSTANCE		 hinst;
  LPWSTR		 lpszText;

#if _WIN32_IE >= _WIN32_IE_IE30

  LPARAM		 lParam;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} TTTOOLINFOW, *LPTTTOOLINFOW, *PTOOLINFOW;

#define TOOLINFOW            TTTOOLINFOW
#define LPTOOLINFOW          LPTTTOOLINFOW
#define TTTOOLINFOW_V1_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOW, lpszText)
#define TTTOOLINFOW_V2_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOW, lParam)
#define TTTOOLINFOW_V3_SIZE  CCSIZEOF_STRUCT (TTTOOLINFOW, lpReserved)

typedef
struct _TT_HITTESTINFOA
{ HWND			 hwnd;
  POINT 		 pt;
  TOOLINFOA		 ti;
} TTHITTESTINFOA, *LPTTHITTESTINFOA;

#define LPHITTESTINFOA    LPTTHITTESTINFOA

typedef
struct _TT_HITTESTINFOW
{ HWND			 hwnd;
  POINT 		 pt;
  TOOLINFOW		 ti;
} TTHITTESTINFOW, *LPTTHITTESTINFOW;

#define LPHITTESTINFOW    LPTTHITTESTINFOW

typedef
struct tagNMTTDISPINFOA
{ NMHDR 		 hdr;
  LPSTR 		 lpszText;
  char			 szText[80];
  HINSTANCE		 hinst;
  UINT			 uFlags;

#if _WIN32_IE >= _WIN32_IE_IE30

  LPARAM		 lParam;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} NMTTDISPINFOA, *LPNMTTDISPINFOA;

#define TOOLTIPTEXTA	NMTTDISPINFOA
#define LPTOOLTIPTEXTA	LPNMTTDISPINFOA

typedef
struct tagNMTTDISPINFOW
{ NMHDR 		 hdr;
  LPWSTR		 lpszText;
  WCHAR 		 szText[80];
  HINSTANCE		 hinst;
  UINT			 uFlags;

#if _WIN32_IE >= _WIN32_IE_IE30

  LPARAM		 lParam;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} NMTTDISPINFOW, *LPNMTTDISPINFOW;

#define TOOLTIPTEXTW	NMTTDISPINFOW
#define LPTOOLTIPTEXTW	LPNMTTDISPINFOW

typedef
struct _UDACCEL
{ UINT			 nSec;
  UINT			 nInc;
} UDACCEL, *LPUDACCEL;

typedef
struct _NM_UPDOWN
{ NMHDR 		 hdr;
  int			 iPos;
  int			 iDelta;
} NMUPDOWN, *LPNMUPDOWN;

/* for backward compatibility */
#define NM_UPDOWN    NMUPDOWN
#define LPNM_UPDOWN  LPNMUPDOWN

typedef
struct _LVITEMA
{ UINT			 mask;
  int			 iItem;
  int			 iSubItem;
  UINT			 state;
  UINT			 stateMask;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iIndent;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

  int			 iGroupId;
  UINT			 cColumns;
  PUINT 		 puColumns;

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

} LVITEMA, FAR *LPLVITEMA;

#define _LV_ITEMA  _LVITEMA
#define  LV_ITEMA   LVITEMA

typedef
struct _LVITEMW
{ UINT			 mask;
  int			 iItem;
  int			 iSubItem;
  UINT			 state;
  UINT			 stateMask;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iIndent;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

  int			 iGroupId;
  UINT			 cColumns;
  PUINT 		 puColumns;

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

} LVITEMW, FAR *LPLVITEMW;

#define _LV_ITEMW  _LVITEMW
#define  LV_ITEMW   LVITEMW

typedef
struct tagLVFINDINFOA
{ UINT			 flags;
  LPCSTR		 psz;
  LPARAM		 lParam;
  POINT 		 pt;
  UINT			 vkDirection;
} LVFINDINFOA, FAR * LPFINDINFOA;

#define _LV_FINDINFOA  tagLVFINDINFOA
#define  LV_FINDINFOA  LVFINDINFOA

typedef
struct tagLVFINDINFOW
{ UINT			 flags;
  LPCWSTR		 psz;
  LPARAM		 lParam;
  POINT 		 pt;
  UINT			 vkDirection;
} LVFINDINFOW, FAR * LPFINDINFOW;

#define _LV_FINDINFOW  tagLVFINDINFOW
#define  LV_FINDINFOW  LVFINDINFOW

typedef
struct tagNMLVFINDITEMA
{ NMHDR 		 hdr;
  int			 iStart;
  LVFINDINFOA		 lvfi;
} NMLVFINDITEMA, *PNMLVFINDITEMA, FAR *LPNMLVFINDITEMA;

#define _NMLVFINDITEMA  tagNMLVFINDITEMA

typedef
struct tagNMLVFINDITEMW
{ NMHDR 		 hdr;
  int			 iStart;
  LVFINDINFOW		 lvfi;
} NMLVFINDITEMW, *PNMLVFINDITEMW, FAR *LPNMLVFINDITEMW;

#define _NMLVFINDITEMW  tagNMLVFINDITEMW

typedef
struct _LVHITTESTINFO
{ POINT 		 pt;
  UINT			 flags;
  int			 iItem;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iSubItem;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} LVHITTESTINFO, FAR *LPLVHITTESTINFO;

#define _LV_HITTESTINFO  _LVHITTESTINFO
#define  LV_HITTESTINFO   LVHITTESTINFO

typedef
struct _LVCOLUMNA
{ UINT			 mask;
  int			 fmt;
  int			 cx;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iSubItem;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iImage;
  int			 iOrder;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} LVCOLUMNA, FAR *LPLVCOLUMNA;

#define _LV_COLUMNA  _LVCOLUMNA
#define  LV_COLUMNA   LVCOLUMNA

typedef
struct _LVCOLUMNW
{ UINT			 mask;
  int			 fmt;
  int			 cx;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iSubItem;

#if _WIN32_IE >= _WIN32_IE_IE30

  int			 iImage;
  int			 iOrder;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

} LVCOLUMNW, FAR *LPLVCOLUMNW;

#define _LV_COLUMNW  _LVCOLUMNW
#define  LV_COLUMNW   LVCOLUMNW

typedef int (CALLBACK *PFNLVCOMPARE) (LPARAM, LPARAM, LPARAM);

typedef
struct tagNMLISTVIEW
{ NMHDR 		 hdr;
  int			 iItem;
  int			 iSubItem;
  UINT			 uNewState;
  UINT			 uOldState;
  UINT			 uChanged;
  POINT 		 ptAction;
  LPARAM		 lParam;
} NMLISTVIEW, *LPNMLISTVIEW;

/* for backward compatibility */
#define _NM_LISTVIEW   tagNMLISTVIEW
#define  NM_LISTVIEW   NMLISTVIEW
#define LPNM_LISTVIEW  LPNMLISTVIEW

typedef
struct tagNMLVDISPINFOA
{ NMHDR 		 hdr;
  LV_ITEMA		 item;
} NMLVDISPINFOA, FAR *LPNMLVDISPINFOA;

#define _LV_DISPINFOA  tagNMLVDISPINFOA
#define  LV_DISPINFOA  NMLVDISPINFOA

typedef
struct tagNMLVDISPINFOW
{ NMHDR 		 hdr;
  LV_ITEMW		 item;
} NMLVDISPINFOW, FAR *LPNMLVDISPINFOW;

#define _LV_DISPINFOW  tagNMLVDISPINFOW
#define  LV_DISPINFOW  NMLVDISPINFOW

typedef
struct _LV_KEYDOWN
{ NMHDR 		 hdr;
  WORD			 wVKey;
  UINT			 flags;
} LV_KEYDOWN;

typedef
struct tagNMLVCACHEHINT
{ NMHDR 		 hdr;
  int			 iFrom;
  int			 iTo;
} NMLVCACHEHINT, *LPNMLVCACHEHINT;

#define NM_CACHEHINT    NMLVCACHEHINT
#define PNM_CACHEHINT   LPNMLVCACHEHINT
#define LPNM_CACHEHINT  LPNMLVCACHEHINT

typedef struct _TREEITEM *HTREEITEM;

typedef
struct tagTVITEMA
{ UINT			 mask;
  HTREEITEM		 hItem;
  UINT			 state;
  UINT			 stateMask;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 cChildren;
  LPARAM		 lParam;
} TVITEMA, *LPTVITEMA;

#define _TV_ITEMA   tagTVITEMA
#define  TV_ITEMA   TVITEMA
#define LPTV_ITEMA  LPTVITEMA

typedef
struct tagTVITEMW
{ UINT			 mask;
  HTREEITEM		 hItem;
  UINT			 state;
  UINT			 stateMask;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 cChildren;
  LPARAM		 lParam;
} TVITEMW, *LPTVITEMW;

#define _TV_ITEMW   tagTVITEMW
#define  TV_ITEMW   TVITEMW
#define LPTV_ITEMW  LPTVITEMW

#if _WIN32_IE >= _WIN32_IE_IE40

typedef
struct tagTVITEMEXA
{ UINT			 mask;
  HTREEITEM		 hItem;
  UINT			 state;
  UINT			 stateMask;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 cChildren;
  LPARAM		 lParam;
  int			 iIntegral;
} TVITEMEXA, *LPTVITEMEXA;

typedef
struct tagTVITEMEXW
{ UINT			 mask;
  HTREEITEM		 hItem;
  UINT			 state;
  UINT			 stateMask;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  int			 iSelectedImage;
  int			 cChildren;
  LPARAM		 lParam;
  int			 iIntegral;
} TVITEMEXW, *LPTVITEMEXW;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef
struct tagTVINSERTSTRUCTA
{ HTREEITEM		 hParent;
  HTREEITEM		 hInsertAfter;

#if _WIN32_IE >= _WIN32_IE_IE40

  _ANONYMOUS_UNION union
  { TVITEMEXA		   itemex;
    TV_ITEMA		   item;
  }			 DUMMYUNIONNAME;

#else	/* _WIN32_IE < _WIN32_IE_IE40 */

  TV_ITEMA		 item;

#endif	/* _WIN32_IE < _WIN32_IE_IE40 */

} TVINSERTSTRUCTA, *LPTVINSERTSTRUCTA;

#define _TV_INSERTSTRUCTA   tagTVINSERTSTRUCTA
#define  TV_INSERTSTRUCTA   TVINSERTSTRUCTA
#define LPTV_INSERTSTRUCTA  LPTVINSERTSTRUCTA

typedef
struct tagTVINSERTSTRUCTW
{ HTREEITEM		 hParent;
  HTREEITEM		 hInsertAfter;

#if _WIN32_IE >= _WIN32_IE_IE40

  _ANONYMOUS_UNION union
  { TVITEMEXW		   itemex;
    TV_ITEMW		   item;
  }			 DUMMYUNIONNAME;

#else	/* _WIN32_IE < _WIN32_IE_IE40 */

  TV_ITEMW		 item;

#endif	/* _WIN32_IE < _WIN32_IE_IE40 */

} TVINSERTSTRUCTW, *LPTVINSERTSTRUCTW;

#define _TV_INSERTSTRUCTW   tagTVINSERTSTRUCTW
#define  TV_INSERTSTRUCTW   TVINSERTSTRUCTW
#define LPTV_INSERTSTRUCTW  LPTVINSERTSTRUCTW

typedef
struct tagTVHITTESTINFO
{ POINT 		 pt;
  UINT			 flags;
  HTREEITEM		 hItem;
} TVHITTESTINFO, *LPTVHITTESTINFO;

#define _TV_HITTESTINFO   tagTVHITTESTINFO
#define  TV_HITTESTINFO   TVHITTESTINFO
#define LPTV_HITTESTINFO  LPTVHITTESTINFO

typedef int (CALLBACK *PFNTVCOMPARE) (LPARAM, LPARAM, LPARAM);

typedef
struct tagTVSORTCB
{ HTREEITEM		 hParent;
  PFNTVCOMPARE		 lpfnCompare;
  LPARAM		 lParam;
} TVSORTCB, *LPTVSORTCB;

#define _TV_SORTCB   tagTVSORTCB
#define  TV_SORTCB   TVSORTCB
#define LPTV_SORTCB  LPTVSORTCB

typedef
struct tagNMTREEVIEWA
{ NMHDR 		 hdr;
  UINT			 action;
  TV_ITEMA		 itemOld;
  TV_ITEMA		 itemNew;
  POINT 		 ptDrag;
} NMTREEVIEWA, *LPNMTREEVIEWA;

#define _NM_TREEVIEWA   tagNMTREEVIEWA
#define  NM_TREEVIEWA   NMTREEVIEWA
#define LPNM_TREEVIEWA  LPNMTREEVIEWA

typedef
struct tagNMTREEVIEWW
{ NMHDR 		 hdr;
  UINT			 action;
  TV_ITEMW		 itemOld;
  TV_ITEMW		 itemNew;
  POINT 		 ptDrag;
} NMTREEVIEWW, *LPNMTREEVIEWW;

#define _NM_TREEVIEWW   tagNMTREEVIEWW
#define  NM_TREEVIEWW   NMTREEVIEWW
#define LPNM_TREEVIEWW  LPNMTREEVIEWW

typedef
struct tagNMTVDISPINFOA
{ NMHDR 		 hdr;
  TVITEMA		 item;
} NMTVDISPINFOA, *LPNMTVDISPINFOA;

#define _TV_DISPINFOA  tagNMTVDISPINFOA
#define  TV_DISPINFOA  NMTVDISPINFOA

typedef
struct tagNMTVDISPINFOW
{ NMHDR 		 hdr;
  TVITEMW		 item;
} NMTVDISPINFOW, *LPNMTVDISPINFOW;

#define _TV_DISPINFOW  tagNMTVDISPINFOW
#define  TV_DISPINFOW  NMTVDISPINFOW

#if _WIN32_IE >= _WIN32_IE_IE40

typedef
struct tagNMTVGETINFOTIPA
{ NMHDR 		 hdr;
  LPSTR 		 pszText;
  int			 cchTextMax;
  HTREEITEM		 hItem;
  LPARAM		 lParam;
} NMTVGETINFOTIPA, *LPNMTVGETINFOTIPA;

typedef
struct tagNMTVGETINFOTIPW
{ NMHDR 		 hdr;
  LPWSTR		 pszText;
  int			 cchTextMax;
  HTREEITEM		 hItem;
  LPARAM		 lParam;
} NMTVGETINFOTIPW, *LPNMTVGETINFOTIPW;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef
struct _TV_KEYDOWN
{ NMHDR 		 hdr;
  WORD			 wVKey;
  UINT			 flags;
} TV_KEYDOWN;

typedef
struct tagTCITEMHEADERA
{ UINT			 mask;
  UINT			 lpReserved1;
  UINT			 lpReserved2;
  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
} TCITEMHEADERA, *LPTCITEMHEADERA;

#define TC_ITEMHEADERA  TCITEMHEADERA

typedef
struct tagTCITEMHEADERW
{ UINT			 mask;
  UINT			 lpReserved1;
  UINT			 lpReserved2;
  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
} TCITEMHEADERW, *LPTCITEMHEADERW;

#define TC_ITEMHEADERW  TCITEMHEADERW

typedef
struct tagTCITEMA
{ UINT			 mask;

#if _WIN32_IE >= _WIN32_IE_IE30

  DWORD 		 dwState;
  DWORD 		 dwStateMask;

#else	/* _WIN32_IE < _WIN32_IE_IE30 */

  UINT			 lpReserved1;
  UINT			 lpReserved2;

#endif	/* _WIN32_IE < _WIN32_IE_IE30 */

  LPSTR 		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;
} TCITEMA, *LPTCITEMA;

#define TC_ITEMA  TCITEMA

typedef
struct tagTCITEMW
{ UINT			 mask;

#if _WIN32_IE >= _WIN32_IE_IE30

  DWORD 		 dwState;
  DWORD 		 dwStateMask;

#else	/* _WIN32_IE < _WIN32_IE_IE30 */

  UINT			 lpReserved1;
  UINT			 lpReserved2;

#endif	/* _WIN32_IE < _WIN32_IE_IE30 */

  LPWSTR		 pszText;
  int			 cchTextMax;
  int			 iImage;
  LPARAM		 lParam;
} TCITEMW, *LPTCITEMW;

#define TC_ITEMW  TCITEMW

typedef
struct tagTCHITTESTINFO
{ POINT 		 pt;
  UINT			 flags;
} TCHITTESTINFO, *LPTCHITTESTINFO;

#define TC_HITTESTINFO    TCHITTESTINFO
#define LPTC_HITTESTINFO  LPTCHITTESTINFO

typedef
struct _TC_KEYDOWN
{ NMHDR 		 hdr;
  WORD			 wVKey;
  UINT			 flags;
} TC_KEYDOWN;

#if _WIN32_IE >= _WIN32_IE_IE30

typedef
struct tagINITCOMMONCONTROLSEX
{ DWORD 		 dwSize;
  DWORD 		 dwICC;
} INITCOMMONCONTROLSEX, *LPINITCOMMONCONTROLSEX;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

typedef
struct tagPBRANGE
{ int			 iLow;
  int			 iHigh;
} PBRANGE, *PPBRANGE;

typedef
struct tagCOLORSCHEME
{ DWORD 		 dwSize;
  COLORREF		 clrBtnHighlight;
  COLORREF		 clrBtnShadow;
} COLORSCHEME, *LPCOLORSCHEME;

typedef
struct tagMCHITTESTINFO
{ UINT			 cbSize;
  POINT 		 pt;
  UINT			 uHit;
  SYSTEMTIME		 st;
}MCHITTESTINFO, *PMCHITTESTINFO;

typedef DWORD MONTHDAYSTATE;
typedef MONTHDAYSTATE *LPMONTHDAYSTATE;

typedef
struct tagNMDAYSTATE
{ NMHDR 		 nmhdr;
  SYSTEMTIME		 stStart;
  int			 cDayState;
  LPMONTHDAYSTATE	 prgDayState;
}NMDAYSTATE, *LPNMDAYSTATE;

typedef
struct tagREBARINFO
{ UINT			 cbSize;
  UINT			 fMask;
  HIMAGELIST		 himl;
} REBARINFO, *LPREBARINFO;

typedef
struct tagREBARBANDINFOA
{ UINT			 cbSize;
  UINT			 fMask;
  UINT			 fStyle;
  COLORREF		 clrFore;
  COLORREF		 clrBack;
  LPSTR 		 lpText;
  UINT			 cch;
  int			 iImage;
  HWND			 hwndChild;
  UINT			 cxMinChild;
  UINT			 cyMinChild;
  UINT			 cx;
  HBITMAP		 hbmBack;
  UINT			 wID;

#if _WIN32_IE >= _WIN32_IE_IE40

  UINT			 cyChild;
  UINT			 cyMaxChild;
  UINT			 cyIntegral;
  UINT			 cxIdeal;
  LPARAM		 lParam;
  UINT			 cxHeader;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

} REBARBANDINFOA, *LPREBARBANDINFOA;

typedef
struct tagREBARBANDINFOW
{ UINT			 cbSize;
  UINT			 fMask;
  UINT			 fStyle;
  COLORREF		 clrFore;
  COLORREF		 clrBack;
  LPWSTR		 lpText;
  UINT			 cch;
  int			 iImage;
  HWND			 hwndChild;
  UINT			 cxMinChild;
  UINT			 cyMinChild;
  UINT			 cx;
  HBITMAP		 hbmBack;
  UINT			 wID;

#if _WIN32_IE >= _WIN32_IE_IE40

  UINT			 cyChild;
  UINT			 cyMaxChild;
  UINT			 cyIntegral;
  UINT			 cxIdeal;
  LPARAM		 lParam;
  UINT			 cxHeader;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

} REBARBANDINFOW, *LPREBARBANDINFOW;

typedef REBARBANDINFOA const *LPCREBARBANDINFOA;
typedef REBARBANDINFOW const *LPCREBARBANDINFOW;

#define REBARBANDINFOA_V3_SIZE  CCSIZEOF_STRUCT (REBARBANDINFOA, wID)
#define REBARBANDINFOW_V3_SIZE  CCSIZEOF_STRUCT (REBARBANDINFOW, wID)

#if _WIN32_IE >= _WIN32_IE_IE30

typedef
struct tagNMLVODSTATECHANGE
{ NMHDR 		 hdr;
  int			 iFrom;
  int			 iTo;
  UINT			 uNewState;
  UINT			 uOldState;
} NMLVODSTATECHANGE, *LPNMLVODSTATECHANGE;

typedef
struct tagIMAGELISTDRAWPARAMS
{ DWORD 		 cbSize;
  HIMAGELIST		 himl;
  int			 i;
  HDC			 hdcDst;
  int			 x;
  int			 y;
  int			 cx;
  int			 cy;
  int			 xBitmap;
  int			 yBitmap;
  COLORREF		 rgbBk;
  COLORREF		 rgbFg;
  UINT			 fStyle;
  DWORD 		 dwRop;

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

  DWORD 		 fState;
  DWORD 		 Frame;
  COLORREF		 crEffect;

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

} IMAGELISTDRAWPARAMS, *LPIMAGELISTDRAWPARAMS;

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_IE >= _WIN32_IE_IE40

typedef
struct tagNMREBARCHILDSIZE
{ NMHDR 		 hdr;
  UINT			 uBand;
  UINT			 wID;
  RECT			 rcChild;
  RECT			 rcBand;
} NMREBARCHILDSIZE, *LPNMREBARCHILDSIZE;

typedef
struct tagNMREBAR
{ NMHDR 		 hdr;
  DWORD 		 dwMask;
  UINT			 uBand;
  UINT			 fStyle;
  UINT			 wID;
  LPARAM		 lParam;
} NMREBAR, *LPNMREBAR;

typedef
struct tagNMRBAUTOSIZE
{ NMHDR 		 hdr;
  BOOL			 fChanged;
  RECT			 rcTarget;
  RECT			 rcActual;
} NMRBAUTOSIZE, *LPNMRBAUTOSIZE;

#if _WIN32_IE >= _WIN32_IE_IE50

typedef
struct tagNMREBARCHEVRON
{ NMHDR 		 hdr;
  UINT			 uBand;
  UINT			 wID;
  LPARAM		 lParam;
  RECT			 rc;
  LPARAM		 lParamNM;
} NMREBARCHEVRON, *LPNMREBARCHEVRON;

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

typedef
struct _RB_HITTESTINFO
{ POINT 		 pt;
  UINT			 flags;
  int			 iBand;
} RBHITTESTINFO, *LPRBHITTESTINFO;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef struct _DSA *HDSA;
typedef struct _DPA *HDPA;

typedef INT (CALLBACK *PFNDPAENUMCALLBACK) (PVOID, PVOID);
typedef INT (CALLBACK *PFNDSAENUMCALLBACK) (PVOID, PVOID);
typedef INT (CALLBACK *PFNDPACOMPARE) (PVOID, PVOID, LPARAM);

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

typedef LRESULT (CALLBACK *SUBCLASSPROC)
( HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR );

typedef
struct tagLITEM
{ UINT			 mask;
  int			 iLink;
  UINT			 state;
  UINT			 stateMask;
  WCHAR 		 szID[MAX_LINKID_TEXT];
  WCHAR 		 szUrl[L_MAX_URL_LENGTH];
} LITEM, *PLITEM;

typedef
struct tagLHITTESTINFO
{ POINT 		 pt;
  LITEM 		 item;
} LHITTESTINFO, *PLHITTESTINFO;

typedef
struct tagNMLINK
{ NMHDR 		 hdr;
  LITEM 		 item;
} NMLINK, *PNMLINK;

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define INDEXTOOVERLAYMASK( i )     ((i) <<  8)
#define INDEXTOSTATEIMAGEMASK( i )  ((i) << 12)

#define HANDLE_WM_NOTIFY( h, w, l, f )					\
  (f)((h), (int)(w), (NMHDR *)(l))

#define FORWARD_WM_NOTIFY( h, i, p, f ) 				\
  (LRESULT)((f)((h), WM_NOTIFY, (WPARAM)((int)(i)),			\
      (LPARAM)((NMHDR *)(p)))						\
    )
#define CCSIZEOF_STRUCT( s, m ) 					\
  (int)((PBYTE)(&((s *)(0))->m) - (PBYTE)((s *)(0))			\
      + sizeof (((s *)(0))->m)						\
    )
#define MAKEIPADDRESS( b1, b2, b3, b4 ) 				\
  (LPARAM)( ((DWORD)(b1) << 24) + ((DWORD)(b2) << 16)			\
      + ((DWORD)(b3) << 8) + (DWORD)(b4)				\
    )
#define MAKEIPRANGE( low, high )					\
  (LPARAM)((WORD)(((BYTE)(high) << 8) + (BYTE)(low)))

#define FIRST_IPADDRESS( a )   (((a) >> 24) & 0xFF)
#define SECOND_IPADDRESS( a )  (((a) >> 16) & 0xFF)
#define THIRD_IPADDRESS( a )   (((a) >>  8) & 0xFF)
#define FOURTH_IPADDRESS( a )   ((a) & 0xFF)

#define Animate_Create( w, i, s, hI )					\
  CreateWindow (ANIMATE_CLASS, NULL, (s), 0, 0, 0, 0, (w),		\
      (HMENU)(i), (hI), NULL						\
    )
#define Animate_Open( w, f )						\
  (BOOL)(SNDMSG ((w), ACM_OPEN, 0, (LPARAM)(f)))

#define Animate_OpenEx( w, h, s )					\
  (BOOL)(SNDMSG ((w), ACM_OPEN, (WPARAM)(h), (LPARAM)((LPTSTR)(s))))

#define Animate_Play( w, f, t, r )					\
  (BOOL)(SNDMSG ((w), ACM_PLAY, (r), (LPARAM)(MAKELONG ((f), (t)))))

#define Animate_Stop( w )						\
  (BOOL)(SNDMSG ((w), ACM_STOP, 0, 0))

#define Animate_Close( w )						\
  Animate_Open ((w), NULL)

#define Animate_Seek( w, f )						\
  Animate_Play ((w), (f), (f), 1)

WINAPI HBITMAP CreateMappedBitmap (HINSTANCE, int, UINT, LPCOLORMAP, int);
WINAPI HWND CreateStatusWindowA (LONG, LPCSTR, HWND, UINT);
WINAPI HWND CreateStatusWindowW (LONG, LPCWSTR, HWND, UINT);

WINAPI HWND CreateToolbarEx
( HWND, DWORD, UINT, int, HINSTANCE, UINT, LPCTBBUTTON,
  int, int, int, int, int, UINT
);

WINAPI HWND CreateUpDownControl
( DWORD, int, int, int, int, HWND, int, HINSTANCE, HWND, int, int, int );

#define DateTime_GetMonthCal( hwnd )					\
  SNDMSG ((hwnd), DTM_GETMONTHCAL, 0, 0)

#define DateTime_GetMonthCalColor( hwnd, icolor )			\
  SNDMSG ((hwnd), DTM_GETMONTHCAL, (WPARAM)(icolor), 0)

#define DateTime_GetMonthCalFont( hwnd )				\
  SNDMSG ((hwnd), DTM_GETMCFONT, 0, 0)

#define DateTime_GetRange( hwnd, lpsystimearray )			\
  SNDMSG ((hwnd), DTM_GETRANGE, 0, (LPARAM)(lpsystimearray))

#define DateTime_GetSystemtime( hwnd, lpsystime )			\
  SNDMSG ((hwnd), DTM_GETSYSTEMTIME, 0, (LPARAM)(lpsystime))

#define DateTime_SetFormat( hwnd, lpszformat )				\
  SNDMSG ((hwnd), DTM_SETFORMAT, 0, (LPARAM)(lpszformat))

#define DateTime_SetMonthCalColor( hwnd, icolor, clr )			\
  SNDMSG ((hwnd), DTM_SETMCCOLOR, (WPARAM)(icolor), (LPARAM)(clr))

#define DateTime_SetMonthCalFont( hwnd, hfont, lparam ) 		\
  SNDMSG ((hwnd), DTM_SETMCFONT, (WPARAM)(hfont), (LPARAM)(lparam))

#define DateTime_SetRange( hwnd, flags, lpsystimearray )		\
  SNDMSG ((hwnd), DTM_SETRANGE, (WPARAM)(flags),			\
      (LPARAM)(lpsystimearray)						\
    )
#define DateTime_SetSystemtime( hwnd, flag, lpsystime ) 		\
  SNDMSG ((hwnd), DTM_SETSYSTEMTIME, (WPARAM)(flag),			\
      (LPARAM)(lpsystime)						\
    )

WINAPI void DrawInsert (HWND, HWND, int);
WINAPI void DrawStatusTextA (HDC, LPRECT, LPCSTR, UINT);
WINAPI void DrawStatusTextW (HDC, LPRECT, LPCWSTR, UINT);
WINAPI void GetEffectiveClientRect (HWND, LPRECT, LPINT);

#if _WIN32_IE >= _WIN32_IE_IE50

WINAPI LANGID GetMUILanguage (VOID);

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

#define Header_GetItemCount( w )					\
  (int)(SNDMSG ((w), HDM_GETITEMCOUNT, 0, 0))

#define Header_InsertItem( w, i, phdi ) 				\
  (int)(SNDMSG ((w), HDM_INSERTITEM, (WPARAM)((int)(i)),		\
      (LPARAM)((const HD_ITEM *)(phdi)))				\
    )
#define Header_DeleteItem( w, i )					\
  (BOOL)(SNDMSG ((w), HDM_DELETEITEM, (WPARAM)((int)(i)), 0))

#define Header_GetItem( w, i, phdi )					\
  (BOOL)(SNDMSG ((w), HDM_GETITEM, (WPARAM)((int)(i)),			\
      (LPARAM)((HD_ITEM *)(phdi)))					\
    )
#define Header_SetItem( w, i, phdi )					\
  (BOOL)(SNDMSG ((w), HDM_SETITEM, (WPARAM)((int)(i)),			\
      (LPARAM)((const HD_ITEM *)(phdi)))				\
    )
#define Header_Layout( w, l )						\
  (BOOL)(SNDMSG ((w), HDM_LAYOUT, 0, (LPARAM)((HD_LAYOUT *)(l))))

#if _WIN32_IE >= _WIN32_IE_IE30

#define Header_OrderToIndex( w, o )					\
  (int)(SNDMSG ((w), HDM_ORDERTOINDEX, (WPARAM)(o), 0))

#define Header_GetItemRect( w, i, r )					\
  (BOOL)(SNDMSG ((w), HDM_GETITEMRECT, (WPARAM)(i), (LPARAM)(r)))

#define Header_GetOrderArray( w, l, a ) 				\
  (BOOL)(SNDMSG ((w), HDM_GETORDERARRAY, (WPARAM)(l), (LPARAM)(a)))

#define Header_SetOrderArray( w, l, a ) 				\
  (BOOL)(SNDMSG ((w), HDM_SETORDERARRAY, (WPARAM)(l), (LPARAM)(a)))

#define Header_CreateDragImage( w, i )					\
  (HIMAGELIST)(SNDMSG ((w), HDM_CREATEDRAGIMAGE, (WPARAM)(i), 0))

#define Header_SetImageList( w, l )					\
  (HIMAGELIST)(SNDMSG ((w), HDM_SETIMAGELIST, 0, (LPARAM)(l)))

#define Header_GetImageList( w )					\
  (HIMAGELIST)(SNDMSG ((w), HDM_GETIMAGELIST, 0, 0))

#if _WIN32_IE >= _WIN32_IE_IE40

#define Header_GetUnicodeFormat( w )					\
  (BOOL)(SNDMSG ((w), HDM_GETUNICODEFORMAT, 0, 0))

#define Header_SetUnicodeFormat( w, f ) 				\
  (BOOL)(SNDMSG ((w), HDM_SETUNICODEFORMAT, (WPARAM)(f), 0))

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */
#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

WINAPI HDSA DSA_Create (INT, INT);
WINAPI BOOL DSA_Destroy (HDSA);
WINAPI VOID DSA_DestroyCallback (HDSA, PFNDSAENUMCALLBACK, PVOID);
WINAPI PVOID DSA_GetItemPtr (HDSA, INT);
WINAPI INT DSA_InsertItem (HDSA, INT, PVOID);
WINAPI HDPA DPA_Create (INT);
WINAPI BOOL DPA_Destroy (HDPA);
WINAPI PVOID DPA_DeletePtr (HDPA, INT);
WINAPI BOOL DPA_DeleteAllPtrs (HDPA);
WINAPI VOID DPA_EnumCallback (HDPA, PFNDPAENUMCALLBACK, PVOID);
WINAPI VOID DPA_DestroyCallback (HDPA, PFNDPAENUMCALLBACK, PVOID);
WINAPI BOOL DPA_SetPtr (HDPA, INT, PVOID);
WINAPI INT DPA_InsertPtr (HDPA, INT, PVOID);
WINAPI PVOID DPA_GetPtr (HDPA, INT_PTR);
WINAPI BOOL DPA_Sort (HDPA, PFNDPACOMPARE, LPARAM);
WINAPI INT DPA_Search (HDPA, PVOID, INT, PFNDPACOMPARE, LPARAM, UINT);
WINAPI BOOL Str_SetPtrW (LPWSTR *, LPCWSTR);

#if _WIN32_IE >= _WIN32_IE_IE40

WINAPI BOOL FlatSB_EnableScrollBar (HWND, INT, UINT);
WINAPI BOOL FlatSB_ShowScrollBar (HWND, INT, BOOL);
WINAPI BOOL FlatSB_GetScrollRange (HWND, INT, LPINT, LPINT);
WINAPI BOOL FlatSB_GetScrollInfo (HWND, INT, LPSCROLLINFO);
WINAPI INT FlatSB_GetScrollPos (HWND, INT);
WINAPI BOOL FlatSB_GetScrollProp (HWND, INT, LPINT);

#ifdef _WIN64

WINAPI BOOL FlatSB_GetScrollPropPtr (HWND, INT, PINT_PTR);

#else	/* !_WIN64 */

#define FlatSB_GetScrollPropPtr  FlatSB_GetScrollProp

#endif	/* !_WIN64 */

WINAPI INT FlatSB_SetScrollPos (HWND, INT, INT, BOOL);
WINAPI INT FlatSB_SetScrollInfo (HWND, INT, LPSCROLLINFO, BOOL);
WINAPI INT FlatSB_SetScrollRange (HWND, INT, INT, INT, BOOL);
WINAPI BOOL FlatSB_SetScrollProp (HWND, UINT, INT_PTR, BOOL);

#define FlatSB_SetScrollPropPtr  FlatSB_SetScrollProp

WINAPI BOOL InitializeFlatSB (HWND);
WINAPI HRESULT UninitializeFlatSB (HWND);

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

WINAPI BOOL SetWindowSubclass (HWND, SUBCLASSPROC, UINT_PTR, DWORD_PTR);
WINAPI BOOL GetWindowSubclass (HWND, SUBCLASSPROC, UINT_PTR, DWORD_PTR *);
WINAPI BOOL RemoveWindowSubclass (HWND, SUBCLASSPROC, UINT_PTR);
WINAPI LRESULT DefSubclassProc (HWND, UINT, WPARAM, LPARAM);

WINAPI INT DrawShadowText
( HDC, LPCWSTR, UINT, RECT *, DWORD, COLORREF, COLORREF, INT, INT );

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

WINAPI int ImageList_Add (HIMAGELIST, HBITMAP, HBITMAP);

#define ImageList_AddIcon( l, i )  ImageList_ReplaceIcon((l), -1, (i))

WINAPI int ImageList_AddMasked (HIMAGELIST, HBITMAP, COLORREF);
WINAPI BOOL ImageList_BeginDrag (HIMAGELIST, int, int, int);
WINAPI HIMAGELIST ImageList_Create (int, int, UINT, int, int);
WINAPI BOOL ImageList_Destroy (HIMAGELIST);
WINAPI BOOL ImageList_DragEnter (HWND, int, int);
WINAPI BOOL ImageList_DragLeave (HWND);
WINAPI BOOL ImageList_DragMove (int, int);
WINAPI BOOL ImageList_DragShowNolock (BOOL);
WINAPI BOOL ImageList_Draw (HIMAGELIST, int, HDC, int, int, UINT);

WINAPI BOOL ImageList_DrawEx
( HIMAGELIST, int, HDC, int, int, int, int, COLORREF, COLORREF, UINT );

WINAPI void ImageList_EndDrag (VOID);

#define ImageList_ExtractIcon( h, l, i )  ImageList_GetIcon((l), (i), 0)

WINAPI COLORREF ImageList_GetBkColor (HIMAGELIST);
WINAPI HIMAGELIST ImageList_GetDragImage (LPPOINT, LPPOINT);
WINAPI HICON ImageList_GetIcon (HIMAGELIST, int, UINT);
WINAPI BOOL ImageList_GetIconSize (HIMAGELIST, int *, int *);
WINAPI int ImageList_GetImageCount (HIMAGELIST);
WINAPI BOOL ImageList_GetImageInfo (HIMAGELIST, int, IMAGEINFO *);

#define ImageList_LoadBitmap( h, l, x, G, M )				\
  ImageList_LoadImage((h), (l), (x), (G), (M), IMAGE_BITMAP, 0)

WINAPI HIMAGELIST ImageList_LoadImageA
( HINSTANCE, LPCSTR, int, int, COLORREF, UINT, UINT );

WINAPI HIMAGELIST ImageList_LoadImageW
( HINSTANCE, LPCWSTR, int, int, COLORREF, UINT, UINT );

WINAPI HIMAGELIST ImageList_Merge
( HIMAGELIST, int, HIMAGELIST, int, int, int );

WINAPI BOOL ImageList_Remove (HIMAGELIST, int);

#define ImageList_RemoveAll( l )  ImageList_Remove((l), -1)

WINAPI BOOL ImageList_Replace (HIMAGELIST, int, HBITMAP, HBITMAP);
WINAPI int ImageList_ReplaceIcon (HIMAGELIST, int, HICON);
WINAPI COLORREF ImageList_SetBkColor (HIMAGELIST, COLORREF);
WINAPI BOOL ImageList_SetDragCursorImage (HIMAGELIST, int, int, int);
WINAPI BOOL ImageList_SetIconSize (HIMAGELIST, int, int);
WINAPI BOOL ImageList_SetOverlayImage (HIMAGELIST, int, int);

#ifdef _OBJIDL_H

WINAPI HIMAGELIST ImageList_Read (LPSTREAM);
WINAPI BOOL ImageList_Write (HIMAGELIST, LPSTREAM);

#endif	/* _OBJIDL_H */

#if _WIN32_IE >= _WIN32_IE_IE40

WINAPI HIMAGELIST ImageList_Duplicate (HIMAGELIST himl);

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

WINAPI void InitCommonControls (void);

#if _WIN32_IE >= _WIN32_IE_IE30

WINAPI BOOL InitCommonControlsEx (LPINITCOMMONCONTROLSEX);

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_IE >= _WIN32_IE_IE50

WINAPI VOID InitMUILanguage (LANGID);

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

WINAPI int LBItemFromPt (HWND, POINT, BOOL);

#define ListView_GetBkColor( w )					\
  (COLORREF)(SNDMSG ((w), LVM_GETBKCOLOR, 0, 0))

#define ListView_GetImageList( w, i )					\
  (HIMAGELIST)(SNDMSG ((w), LVM_GETIMAGELIST, (i), 0))

#define ListView_GetItemCount( w )					\
  (int)(SNDMSG ((w), LVM_GETITEMCOUNT, 0, 0))

#define ListView_GetItem( w, i )					\
  (BOOL)(SNDMSG ((w), LVM_GETITEM, 0, (LPARAM)(i)))

#define ListView_SetBkColor( w, c )					\
  (BOOL)(SNDMSG ((w), LVM_SETBKCOLOR, 0, (LPARAM)(c)))

#define ListView_SetImageList( w, h, i )				\
  (HIMAGELIST)((UINT)(SNDMSG ((w), LVM_SETIMAGELIST, (i),		\
      (LPARAM)(h)))							\
    )
#define ListView_SetItem( w, i )					\
  (BOOL)(SNDMSG ((w), LVM_SETITEM, 0,					\
      (LPARAM)((const LV_ITEM *)(i)))					\
    )
#define ListView_InsertItem( w, i )					\
  (int)(SNDMSG ((w), LVM_INSERTITEM, 0, 				\
      (LPARAM)((const LV_ITEM *)(i)))					\
    )
#define ListView_DeleteItem( w, i )					\
  (BOOL)(SNDMSG ((w), LVM_DELETEITEM, (i), 0))

#define ListView_DeleteAllItems( w )					\
  (BOOL)(SNDMSG ((w), LVM_DELETEALLITEMS, 0, 0))

#define ListView_GetCallbackMask( w )					\
  (UINT)(SNDMSG ((w), LVM_GETCALLBACKMASK, 0, 0))

#define ListView_SetCallbackMask( w, m )				\
  (BOOL)(SNDMSG ((w), LVM_SETCALLBACKMASK, (m), 0))

#define ListView_GetNextItem( w, i, f ) 				\
  (int)(SNDMSG ((w), LVM_GETNEXTITEM, (i), MAKELPARAM ((f), 0)))

#define ListView_FindItem( w, i, p )					\
  (int)(SNDMSG ((w), LVM_FINDITEM, (WPARAM)(i), 			\
      (LPARAM)((const LV_FINDINFO *)(p)))				\
    )
#define ListView_GetItemRect( w, i, p, c )				\
  (BOOL)(SNDMSG ((w), LVM_GETITEMRECT, i,				\
      ((p) ? (((LPRECT)(p))->left = (c), (LPARAM)((LPRECT)(p))) 	\
	   : 0								\
      ))								\
    )
#define ListView_SetItemPosition( w, i, x, y )				\
  (BOOL)(SNDMSG ((w), LVM_SETITEMPOSITION, (i), 			\
      MAKELPARAM ((x), (y)))						\
    )
#define ListView_GetItemPosition( w, i, p )				\
  (BOOL)(SNDMSG ((w), LVM_GETITEMPOSITION, (i), (LPARAM)(p)))

#define ListView_GetItemSpacing( w, f ) 				\
  (DWORD)(SNDMSG ((w), LVM_GETITEMSPACING, (f), 0))

#define ListView_GetStringWidth( w, s ) 				\
  (int)(SNDMSG ((w), LVM_GETSTRINGWIDTH, 0, (LPARAM)(s)))

#define ListView_HitTest( w, p )					\
  (int)(SNDMSG ((w), LVM_HITTEST, 0, (LPARAM)((LV_HITTESTINFO *)(p))))

#define ListView_EnsureVisible( w, i, f )				\
  (BOOL)(SNDMSG ((w), LVM_ENSUREVISIBLE, (i), MAKELPARAM ((f), 0)))

#define ListView_Scroll( w, x, y )					\
  (BOOL)(SNDMSG ((w), LVM_SCROLL, (x), (y)))

#define ListView_RedrawItems( w, f, l ) 				\
  (BOOL)(SNDMSG ((w), LVM_REDRAWITEMS, (f), (l)))

#define ListView_Arrange( w, c )					\
  (BOOL)(SNDMSG ((w), LVM_ARRANGE, (c), 0))

#define ListView_EditLabel( w, i )					\
  (HWND)(SNDMSG ((w), LVM_EDITLABEL, (i), 0))

#define ListView_GetEditControl( w )					\
  (HWND)(SNDMSG ((w), LVM_GETEDITCONTROL, 0, 0))

#define ListView_GetColumn( w, i, p )					\
  (BOOL)(SNDMSG ((w), LVM_GETCOLUMN, (i), (LPARAM)((LV_COLUMN *)(p))))

#define ListView_SetColumn( w, i, p )					\
  (BOOL)(SNDMSG ((w), LVM_SETCOLUMN, (i),				\
      (LPARAM)((const LV_COLUMN *)(p))) 				\
    )
#define ListView_InsertColumn( w, i, p )				\
  (int)(SNDMSG ((w), LVM_INSERTCOLUMN, (i),				\
      (LPARAM)((const LV_COLUMN *)(p))) 				\
    )
#define ListView_DeleteColumn( w, i )					\
  (BOOL)(SNDMSG ((w), LVM_DELETECOLUMN, (i), 0))

#define ListView_GetColumnWidth( w, i ) 				\
  (int)(SNDMSG ((w), LVM_GETCOLUMNWIDTH, (i), 0))

#define ListView_SetColumnWidth( w, i, x )				\
  (BOOL)(SNDMSG ((w), LVM_SETCOLUMNWIDTH, (i), MAKELPARAM ((x), 0)))

#define ListView_CreateDragImage( w, i, p )				\
  (HIMAGELIST)(SNDMSG ((w), LVM_CREATEDRAGIMAGE, (i),			\
      (LPARAM)((LPPOINT)(p)))						\
    )
#define ListView_GetViewRect( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_GETVIEWRECT, 0, (LPARAM)((LPRECT)(p))))

#define ListView_GetTextColor( w )					\
  (COLORREF)(SNDMSG ((w), LVM_GETTEXTCOLOR, 0, 0))

#define ListView_SetTextColor( w, c )					\
  (BOOL)(SNDMSG ((w), LVM_SETTEXTCOLOR, 0, (LPARAM)((COLORREF)(c))))

#define ListView_GetTextBkColor( w )					\
  (COLORREF)(SNDMSG ((w), LVM_GETTEXTBKCOLOR, 0, 0))

#define ListView_SetTextBkColor( w, c ) 				\
  (BOOL)(SNDMSG ((w), LVM_SETTEXTBKCOLOR, 0, (LPARAM)(COLORREF)(c)))

#define ListView_GetTopIndex( w )					\
  (int)(SNDMSG ((w), LVM_GETTOPINDEX, 0, 0))

#define ListView_GetCountPerPage( w )					\
  (int)(SNDMSG ((w), LVM_GETCOUNTPERPAGE, 0, 0))

#define ListView_GetOrigin( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_GETORIGIN, 0, (LPARAM)((POINT *)(p))))

#define ListView_Update( w, i ) 					\
  (BOOL)(SNDMSG ((w), LVM_UPDATE, (WPARAM)(i), 0))

#define ListView_SetItemState( w, i, d, m )				\
{ LV_ITEM _lvi; _lvi.stateMask = (m); _lvi.state = (d); 		\
  SNDMSG ((w), LVM_SETITEMSTATE, (i), (LPARAM)((LV_ITEM *)(&_lvi)));	\
}
#define ListView_GetItemState( w, i, m )				\
  (UINT)(SNDMSG ((w), LVM_GETITEMSTATE, (i), (m)))

#define ListView_GetItemText( w, i, iS, s, n )				\
{ LV_ITEM _lvi; 							\
  _lvi.iSubItem = (iS); _lvi.cchTextMax = (n); _lvi.pszText = (s);	\
  SNDMSG ((w), LVM_GETITEMTEXT, (i), (LPARAM)((LV_ITEM *)(&_lvi)));	\
}
#define ListView_SetItemText( w, i, iS, s )				\
{ LV_ITEM _lvi; _lvi.iSubItem = (iS); _lvi.pszText = (s);		\
  SNDMSG ((w), LVM_SETITEMTEXT, (i), (LPARAM)((LV_ITEM *)(&_lvi)));	\
}
#define ListView_SetItemCount( w, n )					\
  (void)(SNDMSG ((w), LVM_SETITEMCOUNT, (n), 0))

#define ListView_SortItems( w, f, l )					\
  (BOOL)(SNDMSG ((w), LVM_SORTITEMS, (l), (LPARAM)(f)))

#define ListView_SetItemPosition32( w, i, x, y )			\
{ POINT p = {(x), (y)}; 						\
  SNDMSG ((w), LVM_SETITEMPOSITION32, (i), (LPARAM)(&p));		\
}
#define ListView_GetSelectedCount( w )					\
  (UINT)(SNDMSG ((w), LVM_GETSELECTEDCOUNT, 0, 0))

#define ListView_GetCheckState( w, i )					\
  ((((UINT)(SNDMSG ((w), LVM_GETITEMSTATE, (WPARAM)(i), 		\
      LVIS_STATEIMAGEMASK))) >> 12) - 1 				\
    )
#define ListView_SetCheckState( w, i, f )				\
  ListView_SetItemState ((w), (i), INDEXTOSTATEIMAGEMASK ((f) + 1), 	\
      LVIS_STATEIMAGEMASK						\
    )
#define ListView_GetISearchString( w, lpsz )				\
  (BOOL)(SNDMSG ((w), LVM_GETISEARCHSTRING, 0,				\
      (LPARAM)((LPTSTR)(lpsz))) 					\
    )
#define ListView_CancelEditLabel( w )					\
  (VOID)(SNDMSG((w), LVM_CANCELEDITLABEL, 0, 0))

#define ListView_EnableGroupView( w, i )				\
  (int)(SNDMSG ((w), LVM_ENABLEGROUPVIEW, (WPARAM)(i), 0))

#define ListView_GetGroupInfo( w, i, p )				\
  (int)(SNDMSG ((w), LVM_GETGROUPINFO, (WPARAM)(i), (LPARAM)(p)))

#define ListView_GetGroupMetrics( w, p )				\
  SNDMSG ((w), LVM_GETGROUPMETRICS, 0, (LPARAM)(p))

#define ListView_GetInsertMark( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_GETINSERTMARK, 0, (LPARAM)(p)))

#define ListView_GetInsertMarkColor( w )				\
  (COLORREF)(SNDMSG ((w), LVM_GETINSERTMARKCOLOR, 0, 0))

#define ListView_GetInsertMarkRect( w, p )				\
  (int)(SNDMSG ((w), LVM_GETINSERTMARKRECT, 0, (LPARAM)(p)))

#define ListView_GetOutlineColor( w )					\
  (COLORREF)(SNDMSG ((w), LVM_GETOUTLINECOLOR, 0, 0))

#define ListView_GetSelectedColumn( w ) 				\
  (UINT)(SNDMSG ((w), LVM_GETSELECTEDCOLUMN, 0, 0))

#define ListView_GetTileInfo( w, p )					\
  SNDMSG ((w), LVM_GETTILEINFO, 0, (LPARAM)(p))

#define ListView_GetTileViewInfo( w, p )				\
  SNDMSG ((w), LVM_GETTILEVIEWINFO, 0, (LPARAM)(p))

#define ListView_GetView( w )						\
  (DWORD)(SNDMSG ((w), LVM_GETVIEW, 0, 0))

#define ListView_HasGroup( w, i )					\
  (BOOL)(SNDMSG ((w), LVM_HASGROUP, (WPARAM)(i), 0))

#define ListView_InsertGroup( w, i, p ) 				\
  (int)(SNDMSG ((w), LVM_INSERTGROUP, (WPARAM)(i), (LPARAM)(p)))

#define ListView_InsertGroupSorted( w, p )				\
  SNDMSG ((w), LVM_INSERTGROUPSORTED, (WPARAM)(p), 0)

#define ListView_InsertMarkHitTest( w, p, t )				\
  (BOOL)(SNDMSG ((w), LVM_INSERTMARKHITTEST, (WPARAM)(p),		\
      (LPARAM)(t))							\
    )
#define ListView_IsGroupViewEnabled( w )				\
  (BOOL)(SNDMSG ((w), LVM_ISGROUPVIEWENABLED, 0, 0))

#define ListView_MapIDToIndex( w, i )					\
  (UINT)(SNDMSG ((w), LVM_MAPIDTOINDEX, (WPARAM)(i), 0))

#define ListView_MoveGroup( w, i, t )					\
  SNDMSG ((w), LVM_MOVEGROUP, (WPARAM)(i), (LPARAM)(t))

#define ListView_RemoveAllGroups( w )					\
  SNDMSG ((w), LVM_REMOVEALLGROUPS, 0, 0)

#define ListView_RemoveGroup( w, i )					\
  (int)(SNDMSG ((w), LVM_REMOVEGROUP, (WPARAM)(i), 0))

#define ListView_SetGroupInfo( w, i, p )				\
  (int)(SNDMSG ((w), LVM_SETGROUPINFO, (WPARAM)(i), (LPARAM)(p)))

#define ListView_SetGroupMetrics( w, p )				\
  SNDMSG ((w), LVM_SETGROUPMETRICS, 0, (LPARAM)(p))

#define ListView_SetInfoTip( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_SETINFOTIP, 0, (LPARAM)(p)))

#define ListView_SetInsertMark( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_SETINSERTMARK, 0, (LPARAM)(p)))

#define ListView_SetInsertMarkColor( w, c )				\
  (COLORREF)SNDMSG((w), LVM_SETINSERTMARKCOLOR, 0, (LPARAM)(c))

#define ListView_SetOutlineColor( w, c )				\
  (COLORREF)(SNDMSG ((w), LVM_SETOUTLINECOLOR, 0, (LPARAM)(c)))

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define ListView_SetSelectedColumn( w, i )				\
  SNDMSG ((w), LVM_SETSELECTEDCOLUMN, (WPARAM)(i), 0)

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

#define ListView_SetTileInfo( w, p )					\
  (BOOL)(SNDMSG ((w), LVM_SETTILEINFO, 0, (LPARAM)(p)))

#define ListView_SetTileViewInfo( w, p )				\
  (BOOL)(SNDMSG ((w), LVM_SETTILEVIEWINFO, 0, (LPARAM)(p)))

#define ListView_SetView( w, i )					\
  (int)(SNDMSG ((w), LVM_SETVIEW, (WPARAM)(i), 0))

#define ListView_SortGroups( w, c, p )					\
  (int)(SNDMSG ((w), LVM_SORTGROUPS, (WPARAM)(c), (LPARAM)(p)))

#define ListView_SortItemsEx( w, c, p ) 				\
  (BOOL)(SNDMSG((w), LVM_SORTITEMSEX, (WPARAM)(p), (LPARAM)(c)))

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP

#define ComboBox_SetMinVisible( w, i )					\
  (BOOL)(SNDMSG ((w), CB_SETMINVISIBLE, (WPARAM)(i), 0))

#define ComboBox_GetMinVisible( w )					\
  (INT)(SNDMSG ((w), CB_GETMINVISIBLE, 0, 0))

#endif	/* _WIN32_WINNT >= _WIN32_WINNT_WINXP */

WINAPI BOOL MakeDragList (HWND);
WINAPI void MenuHelp (UINT, WPARAM, LPARAM, HMENU, HINSTANCE, HWND, PUINT);

#define MonthCal_GetColor( hwnd, icolor )				\
  SNDMSG (hwnd, MCM_GETCOLOR, (WPARAM)(icolor), (LPARAM)(0))

#define MonthCal_GetCurSel( hwnd, lpsystime )				\
  SNDMSG (hwnd, MCM_GETCURSEL, 0, (LPARAM)(lpsystime))

#define MonthCal_GetFirstDayOfWeek( hwnd )				\
  SNDMSG (hwnd, MCM_GETFIRSTDAYOFWEEK, 0, 0)

#define MonthCal_GetMaxSelCount( hwnd ) 				\
  SNDMSG (hwnd, MCM_GETMAXSELCOUNT, 0, 0)

#define MonthCal_GetMaxTodayWidth( hwnd )				\
  SNDMSG (hwnd, MCM_GETMAXTODAYWIDTH, 0, 0)

#define MonthCal_GetMinReqRect( hwnd, lpRectInfo )			\
  SNDMSG (hwnd, MCM_GETMINREQRECT, 0, (LPARAM)(lpRectInfo))

#define MonthCal_GetMonthDelta( hwnd )					\
  SNDMSG (hwnd, MCM_GETMONTHDELTA, 0, 0)

#define MonthCal_GetMonthRange( hwnd, flag, systimearray )		\
  SNDMSG (hwnd, MCM_GETMONTHRANGE, (WPARAM)(flag),			\
      (LPARAM)(systimearray)						\
    )
#define MonthCal_GetRange( hwnd, systimearray ) 			\
  SNDMSG (hwnd, MCM_GETRANGE, 0, (LPARAM)(systimearray))

#define MonthCal_GetSelRange( hwnd, systimearray )			\
  SNDMSG (hwnd, MCM_GETSELRANGE, 0, (LPARAM)(systimearray))

#define MonthCal_GetToday( hwnd, systime )				\
  SNDMSG (hwnd, MCM_GETTODAY, 0, (LPARAM)(systime))

#define MonthCal_GetUnicodeFormat( hwnd )				\
  SNDMSG (hwnd, MCM_GETUNICODEFORMAT, 0, 0)

#define MonthCal_HitTest( hwnd, pmchittest )				\
  SNDMSG (hwnd, MCM_HITTEST, 0, (LPARAM)(pmchittest))

#define MonthCal_SetColor( hwnd, icolor, clr )				\
  SNDMSG (hwnd, MCM_SETCOLOR, (WPARAM)(icolor), (LPARAM)(clr))

#define MonthCal_SetCurSel( hwnd, lpsystime )				\
  SNDMSG (hwnd, MCM_SETCURSEL, 0, (LPARAM)(lpsystime))

#define MonthCal_SetDayState( hwnd, imonths, lpdatestatearray ) 	\
  SNDMSG (hwnd, MCM_SETDAYSTATE, (WPARAM)(imonths),			\
      (LPARAM)(lpdatestatearray)					\
    )
#define MonthCal_SetFirstDayOfWeek( hwnd, iday )			\
  SNDMSG (hwnd, MCM_SETFIRSTDAYOFWEEK, 0, (LPARAM)(iday))

#define MonthCal_SetMaxSelCount( hwnd, imax )				\
  SNDMSG (hwnd, MCM_SETMAXSELCOUNT, (WPARAM)(imax), 0)

#define MonthCal_SetMonthDelta( hwnd, idelta )				\
  SNDMSG (hwnd, MCM_SETMONTHDELTA, (WPARAM)(idelta), 0)

#define MonthCal_SetSelRange( hwnd, systimearray )			\
  SNDMSG (hwnd, MCM_SETSELRANGE, 0, (LPARAM)(systimearray))

#define MonthCal_SetToday( hwnd, systime )				\
  SNDMSG (hwnd, MCM_SETTODAY, 0, (LPARAM)(systime))

#define MonthCal_SetUnicodeFormat( hwnd, unicode )			\
  SNDMSG (hwnd, MCM_SETUNICODEFORMAT, (WPARAM)(unicode), 0)

#define MonthCal_SetRange( w, f, st )					\
  (BOOL)(SNDMSG ((w), MCM_SETRANGE, (WPARAM)(f), (LPARAM)(st)))

WINAPI BOOL ShowHideMenuCtl (HWND, UINT, PINT);

#define TabCtrl_GetItem( w, i, p )					\
  (BOOL)(SNDMSG ((w), TCM_GETITEM, (i), (LPARAM)((TC_ITEM *)(p))))

#define TabCtrl_SetItem( w, i, p )					\
  (BOOL)(SNDMSG ((w), TCM_SETITEM, (i), (LPARAM)((TC_ITEM *)(p))))

#define TabCtrl_InsertItem( w, i, p )					\
  (int)(SNDMSG ((w), TCM_INSERTITEM, (i),				\
      (LPARAM)((const TC_ITEM *)(p)))					\
    )
#define TabCtrl_DeleteItem( w, i )					\
  (BOOL)(SNDMSG ((w), TCM_DELETEITEM, (i), 0))

#define TabCtrl_DeleteAllItems( w )					\
  (BOOL)(SNDMSG ((w), TCM_DELETEALLITEMS, 0, 0))

#define TabCtrl_GetItemRect( w, i, p )					\
  (BOOL)(SNDMSG ((w), TCM_GETITEMRECT, (i), (LPARAM)((LPRECT)(p))))

#define TabCtrl_GetCurSel( w )						\
  (int)(SNDMSG ((w), TCM_GETCURSEL, 0, 0))

#define TabCtrl_SetCurSel( w, i )					\
  (int)(SNDMSG ((w), TCM_SETCURSEL, (i), 0))

#define TabCtrl_HitTest( w, p ) 					\
  (int)(SNDMSG ((w), TCM_HITTEST, 0, (LPARAM)((TC_HITTESTINFO *)(p))))

#define TabCtrl_SetItemExtra( w, c )					\
  (BOOL)(SNDMSG ((w), TCM_SETITEMEXTRA, (c), 0))

#define TabCtrl_AdjustRect( w, b, p )					\
  (int)(SNDMSG ((w), TCM_ADJUSTRECT, (b), (LPARAM)((LPRECT)(p))))

#define TabCtrl_SetItemSize( w, x, y )					\
  (DWORD)(SNDMSG ((w), TCM_SETITEMSIZE, 0, MAKELPARAM ((x), (y))))

#define TabCtrl_RemoveImage( w, i )					\
  (void)(SNDMSG ((w), TCM_REMOVEIMAGE, (i), 0))

#define TabCtrl_SetPadding( w, x, y )					\
  (void)(SNDMSG ((w), TCM_SETPADDING, 0, MAKELPARAM ((x), (y))))

#define TabCtrl_GetRowCount( w )					\
  (int)(SNDMSG ((w), TCM_GETROWCOUNT, 0, 0))

#define TabCtrl_GetToolTips( w )					\
  (HWND)(SNDMSG ((w), TCM_GETTOOLTIPS, 0, 0))

#define TabCtrl_SetToolTips( w, t )					\
  (void)(SNDMSG ((w), TCM_SETTOOLTIPS, (WPARAM)(t), 0))

#define TabCtrl_GetCurFocus( w )					\
  (int)(SNDMSG ((w), TCM_GETCURFOCUS, 0, 0))

#define TabCtrl_SetCurFocus( w, i )					\
  (void)(SNDMSG ((w), TCM_SETCURFOCUS, (i), 0))

#define TabCtrl_GetImageList( w )					\
  (HIMAGELIST)(SNDMSG ((w), TCM_GETIMAGELIST, 0, 0))

#define TabCtrl_SetImageList( w, h )					\
  (HIMAGELIST)(SNDMSG ((w), TCM_SETIMAGELIST, 0, (LPARAM)((UINT)(h))))

#define TabCtrl_GetItemCount( w )					\
  (int)(SNDMSG ((w), TCM_GETITEMCOUNT, 0, 0))

WINAPI BOOL _TrackMouseEvent (LPTRACKMOUSEEVENT);

#define TreeView_InsertItem( w, i )					\
  (HTREEITEM)(SNDMSG ((w), TVM_INSERTITEM, 0,				\
      (LPARAM)((LPTV_INSERTSTRUCT)(i))) 				\
    )
#define TreeView_DeleteItem( w, i )					\
  (BOOL)(SNDMSG ((w), TVM_DELETEITEM, 0, (LPARAM)((HTREEITEM)(i))))

#define TreeView_DeleteAllItems( w )					\
  (BOOL)(SNDMSG ((w), TVM_DELETEITEM, 0, (LPARAM)(TVI_ROOT)))

#define TreeView_Expand( w, i, c )					\
  (BOOL)(SNDMSG ((w), TVM_EXPAND, (c), (LPARAM)((HTREEITEM)(i))))

#define TreeView_GetItemRect( w, i, p, c )				\
  (*(HTREEITEM *)((p) = (i)),						\
    (BOOL)(SNDMSG ((w), TVM_GETITEMRECT, (c), (LPARAM)((LPRECT)(p))))	\
  )
#define TreeView_GetCount( w )						\
  (UINT)(SNDMSG ((w), TVM_GETCOUNT, 0, 0))

#define TreeView_GetIndent( w ) 					\
  (UINT)(SNDMSG ((w), TVM_GETINDENT, 0, 0))

#define TreeView_SetIndent( w, i )					\
  (BOOL)(SNDMSG ((w), TVM_SETINDENT, (i), 0))

#define TreeView_GetImageList( w, i )					\
  (HIMAGELIST)(SNDMSG ((w), TVM_GETIMAGELIST, (i), 0))

#define TreeView_SetImageList( w, h, i )				\
  (HIMAGELIST)(SNDMSG ((w), TVM_SETIMAGELIST, (i),			\
      (LPARAM)((HIMAGELIST)(h)))					\
    )
#define TreeView_GetNextItem( w, i, c ) 				\
  (HTREEITEM)(SNDMSG ((w), TVM_GETNEXTITEM, (c),			\
      (LPARAM)((HTREEITEM)(i))) 					\
    )
#define TreeView_GetChild( w, i )					\
  TreeView_GetNextItem ((w), (i), TVGN_CHILD)

#define TreeView_GetNextSibling( w, i ) 				\
  TreeView_GetNextItem ((w), (i), TVGN_NEXT)

#define TreeView_GetPrevSibling( w, i ) 				\
  TreeView_GetNextItem ((w), (i), TVGN_PREVIOUS)

#define TreeView_GetParent( w, i )					\
  TreeView_GetNextItem ((w), (i), TVGN_PARENT)

#define TreeView_GetFirstVisible( w )					\
  TreeView_GetNextItem ((w), NULL, TVGN_FIRSTVISIBLE)

#define TreeView_GetNextVisible( w, i ) 				\
  TreeView_GetNextItem ((w), (i), TVGN_NEXTVISIBLE)

#define TreeView_GetPrevVisible( w, i ) 				\
  TreeView_GetNextItem ((w), (i), TVGN_PREVIOUSVISIBLE)

#define TreeView_GetSelection( w )					\
  TreeView_GetNextItem ((w), NULL, TVGN_CARET)

#define TreeView_GetDropHilight( w )					\
  TreeView_GetNextItem ((w), NULL, TVGN_DROPHILITE)

#define TreeView_GetRoot( w )						\
  TreeView_GetNextItem ((w), NULL, TVGN_ROOT)

#define TreeView_Select( w, i, c )					\
  (BOOL)(SNDMSG ((w), TVM_SELECTITEM, (c), (LPARAM)((HTREEITEM)(i))))

#define TreeView_SelectItem( w, i )					\
  TreeView_Select ((w), (i), TVGN_CARET)

#define TreeView_SelectDropTarget( w, i )				\
  TreeView_Select ((w), (i), TVGN_DROPHILITE)

#define TreeView_SelectSetFirstVisible( w, i )				\
  TreeView_Select ((w), (i), TVGN_FIRSTVISIBLE)

#define TreeView_GetItem( w, i )					\
  (BOOL)(SNDMSG ((w), TVM_GETITEM, 0, (LPARAM)(TV_ITEM *)(i)))

#define TreeView_SetItem( w, i )					\
  (BOOL)(SNDMSG ((w), TVM_SETITEM, 0, (LPARAM)((const TV_ITEM *)(i))))

#define TreeView_EditLabel( w, i )					\
  (HWND)(SNDMSG ((w), TVM_EDITLABEL, 0, (LPARAM)((HTREEITEM)(i))))

#define TreeView_GetEditControl( w )					\
  (HWND)(SNDMSG((w), TVM_GETEDITCONTROL, 0, 0))

#define TreeView_GetVisibleCount( w )					\
  (UINT)(SNDMSG ((w), TVM_GETVISIBLECOUNT, 0, 0))

#define TreeView_HitTest( w, p )					\
  (HTREEITEM)(SNDMSG ((w), TVM_HITTEST, 0,				\
      (LPARAM)((LPTV_HITTESTINFO)(p)))					\
    )
#define TreeView_CreateDragImage( w, i )				\
  (HIMAGELIST)(SNDMSG ((w), TVM_CREATEDRAGIMAGE, 0,			\
      (LPARAM)((HTREEITEM)(i))) 					\
    )
#define TreeView_SortChildren( w, i, r )				\
  (BOOL)(SNDMSG ((w), TVM_SORTCHILDREN, (r),				\
      (LPARAM)((HTREEITEM)(i))) 					\
    )
#define TreeView_EnsureVisible( w, i )					\
  (BOOL)(SNDMSG ((w), TVM_ENSUREVISIBLE, 0,				\
      (LPARAM)((HTREEITEM)(i))) 					\
    )
#define TreeView_SortChildrenCB( w, s, r )				\
  (BOOL)(SNDMSG ((w), TVM_SORTCHILDRENCB, r,				\
      (LPARAM)((LPTVSORTCB)(s)))					\
    )
#define TreeView_EndEditLabelNow( w, f )				\
  (BOOL)(SNDMSG ((w), TVM_ENDEDITLABELNOW, (f), 0))

#define TreeView_GetISearchString( w, s )				\
  (BOOL)(SNDMSG ((w), TVM_GETISEARCHSTRING, 0, (LPARAM)(s)))

#if _WIN32_IE >= _WIN32_IE_IE30

#define ListView_ApproximateViewRect( w, iw, ih, i )			\
  (DWORD)(SNDMSG ((w), LVM_APPROXIMATEVIEWRECT, (i),			\
      MAKELPARAM ((iw), (ih)))						\
    )
#define ListView_SetExtendedListViewStyle( w, s )			\
  (DWORD)(SNDMSG ((w), LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (s)))

#define ListView_GetExtendedListViewStyle( w )				\
  (DWORD)(SNDMSG ((w), LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0))

#define ListView_SetColumnOrderArray( w, i, a ) 			\
  (BOOL)(SNDMSG ((w), LVM_SETCOLUMNORDERARRAY, (WPARAM)(i),		\
       (LPARAM)((LPINT)(a)))						\
    )
#define ListView_GetColumnOrderArray( w, i, a ) 			\
  (BOOL)(SNDMSG ((w), LVM_GETCOLUMNORDERARRAY, (WPARAM)(i),		\
       (LPARAM)((LPINT)(a)))						\
    )
#define ListView_GetHeader( w ) 					\
  (HWND)(SNDMSG ((w), LVM_GETHEADER, 0, 0))

#define ListView_GetHotCursor( w )					\
  (HCURSOR)(SNDMSG ((w), LVM_GETHOTCURSOR, 0, 0))

#define ListView_GetHotItem( w )					\
  (INT)(SNDMSG ((w), LVM_GETHOTITEM, 0, 0))

#define ListView_GetSubItemRect( w, i, is, c, p )			\
  (BOOL)(SNDMSG ((w), LVM_GETSUBITEMRECT, (WPARAM)((int)(i)), ((p)	\
       ? (((LPRECT)(p))->left=(c), (((LPRECT)(p))->top=(is)),		\
	   (LPARAM)((LPRECT)(p)))					\
       : 0))								\
    )
#define ListView_SetHotCursor( w, c )					\
  (HCURSOR)(SNDMSG ((w), LVM_SETHOTCURSOR, 0, (LPARAM)(c)))

#define ListView_SetHotItem( w, i )					\
  (int)(SNDMSG ((w), LVM_SETHOTITEM, (WPARAM)(i), 0))

#define ListView_SetIconSpacing( w, x, y )				\
  (DWORD)(SNDMSG ((w), LVM_SETICONSPACING, 0, MAKELONG ((x), (y))))

#define ListView_SubItemHitTest( w, p ) 				\
  (INT)(SNDMSG ((w), LVM_SUBITEMHITTEST, 0,				\
      (LPARAM)((LPLVHITTESTINFO)(p)))					\
    )
#define ListView_SetItemCountEx( w, i, f )				\
  (void)(SNDMSG ((w), LVM_SETITEMCOUNT, (WPARAM)(i), (LPARAM)(f)))

WINAPI WINBOOL ImageList_SetImageCount (HIMAGELIST, UINT);
WINAPI WINBOOL ImageList_Copy (HIMAGELIST, int, HIMAGELIST, int, UINT);
WINAPI WINBOOL ImageList_DrawIndirect (IMAGELISTDRAWPARAMS *);

#define TabCtrl_SetMinTabWidth( hwnd, x )				\
  SNDMSG ((hwnd), TCM_SETMINTABWIDTH, 0, (x))

#define TabCtrl_DeselectAll( hwnd, fExcludeFocus )			\
  SNDMSG ((hwnd), TCM_DESELECTALL, (fExcludeFocus), 0)

#define TreeView_GetToolTips( w )					\
  (HWND)(SNDMSG ((w), TVM_GETTOOLTIPS, 0, 0))

#define TreeView_SetToolTips( w, wt )					\
  (HWND)(SNDMSG ((w), TVM_SETTOOLTIPS, (WPARAM)(wt), 0))

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#if _WIN32_IE >= _WIN32_IE_IE40

#define ListView_GetBkImage( h, plvbki )				\
  (BOOL)(SNDMSG ((h), LVM_GETBKIMAGE, 0, (LPARAM)(plvbki)))

#define ListView_SetBkImage( h, plvbki )				\
  (BOOL)(SNDMSG ((h), LVM_SETBKIMAGE, 0, (LPARAM)(plvbki)))

#define ListView_SetExtendedListViewStyleEx( w, m, s )			\
  (DWORD)(SNDMSG ((w), LVM_SETEXTENDEDLISTVIEWSTYLE, (m), (s)))

#define ListView_SetWorkAreas( w, n, r )				\
  (BOOL)(SNDMSG ((w), LVM_SETWORKAREAS, (WPARAM)(n),			\
      (LPARAM)((RECT *)(r)))						\
    )
#define ListView_GetWorkAreas( w, n, r )				\
  (BOOL)(SNDMSG ((w), LVM_GETWORKAREAS, (WPARAM)(n),			\
      (LPARAM)((RECT *)(r)))						\
    )
#define ListView_GetNumberOfWorkAreas( w, n )				\
  (BOOL)(SNDMSG ((w), LVM_GETNUMBEROFWORKAREAS, 0,			\
      (LPARAM)((UINT *)(n)))						\
    )
#define ListView_SetHoverTime( w, t )					\
  (DWORD)(SNDMSG ((w), LVM_SETHOVERTIME, 0, (LPARAM)(t)))

#define ListView_GetHoverTime( w )					\
  (DWORD)(SNDMSG ((w), LVM_GETHOVERTIME, 0, 0))

#define ListView_GetSelectionMark( w )					\
  (INT)(SNDMSG ((w), LVM_GETSELECTIONMARK, 0, 0))

#define ListView_SetSelectionMark( w, i )				\
  (INT)(SNDMSG ((w), LVM_SETSELECTIONMARK, 0, (LPARAM)(i)))

#define ListView_SetToolTips( w, n )					\
  (HWND)(SNDMSG ((w), LVM_SETTOOLTIPS, (WPARAM)(n), 0))

#define ListView_GetToolTips( w )					\
  (HWND)(SNDMSG ((w), LVM_GETTOOLTIPS, 0, 0))

#define ListView_SetUnicodeFormat( w, f )				\
  (BOOL)(SNDMSG ((w), LVM_SETUNICODEFORMAT, (WPARAM)(f), 0))

#define ListView_GetUnicodeFormat( w )					\
  (BOOL)(SNDMSG ((w), LVM_GETUNICODEFORMAT, 0, 0))

#define TabCtrl_HighlightItem( w, i, fHighlight )			\
  SNDMSG ((w), TCM_HIGHLIGHTITEM, (WPARAM)i,				\
      (LPARAM)(MAKELONG ((fHighlight), 0))				\
    )
#define TabCtrl_SetExtendedStyle( w, dw )				\
  SNDMSG ((w), TCM_SETEXTENDEDSTYLE, 0, (dw))

#define TabCtrl_GetExtendedStyle( w )					\
  SNDMSG ((w), TCM_GETEXTENDEDSTYLE, 0, 0)

#define TabCtrl_SetUnicodeFormat( w, u )				\
  SNDMSG ((w), TCM_SETUNICODEFORMAT, (WPARAM)(u), 0)

#define TabCtrl_GetUnicodeFormat( w )					\
  SNDMSG ((w), TCM_GETUNICODEFORMAT, 0, 0)

#define TreeView_GetBkColor( w )					\
  (COLORREF)(SNDMSG ((w), TVM_GETBKCOLOR, 0, 0))

#define TreeView_GetInsertMarkColor( w )				\
  (COLORREF)(SNDMSG ((w), TVM_GETINSERTMARKCOLOR, 0, 0))

#define TreeView_GetItemHeight( w )					\
  (int)(SNDMSG ((w), TVM_GETITEMHEIGHT, 0, 0))

#define TreeView_GetScrollTime( w )					\
  (UINT)(SNDMSG ((w), TVM_GETSCROLLTIME, 0, 0))

#define TreeView_GetTextColor( w )					\
  (COLORREF)(SNDMSG ((w), TVM_GETTEXTCOLOR, 0, 0))

#define TreeView_SetBkColor( w, c )					\
  (COLORREF)(SNDMSG ((w), TVM_SETBKCOLOR, 0, (LPARAM)(c)))

#define TreeView_SetInsertMarkColor( w, c )				\
  (COLORREF)(SNDMSG ((w), TVM_SETINSERTMARKCOLOR, 0, (LPARAM)(c)))

#define TreeView_SetItemHeight( w, h )					\
  (int)(SNDMSG ((w), TVM_SETITEMHEIGHT, (WPARAM)(h), 0))

#define TreeView_SetScrollTime( w, t )					\
  (UINT)(SNDMSG ((w), TVM_SETSCROLLTIME, (WPARAM)((UINT)(t)), 0))

#define TreeView_SetTextColor( w, c )					\
  (COLORREF)(SNDMSG ((w), TVM_SETTEXTCOLOR, 0, (LPARAM)(c)))

#define TreeView_SetInsertMark( w, i, a )				\
  (BOOL)(SNDMSG ((w), TVM_SETINSERTMARK, (WPARAM)(a), (LPARAM)(i)))

#define TreeView_SetUnicodeFormat( w, u )				\
  (BOOL)(SNDMSG ((w), TVM_SETUNICODEFORMAT, (WPARAM)(u), 0))

#define TreeView_GetUnicodeFormat( w )					\
  (BOOL)(SNDMSG ((w), TVM_GETUNICODEFORMAT, 0, 0))

#define TreeView_GetLastVisible( w )					\
  TreeView_GetNextItem (w, NULL, TVGN_LASTVISIBLE)

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#if _WIN32_IE >= _WIN32_IE_IE50

#define TreeView_GetItemState( w, i, m )				\
  (UINT)(SNDMSG ((w), TVM_GETITEMSTATE, (WPARAM)(i), (LPARAM)(m)))

#define TreeView_SetItemState( w, i, d, m )				\
{ TVITEM _tvi; _tvi.mask = TVIF_STATE;					\
  _tvi.hItem = (i); _tvi.stateMask = (m); _tvi.state = (d);		\
  SNDMSG ((w), TVM_SETITEM, 0, (LPARAM)((TVITEM *)(&_tvi)));		\
}

#endif	/* _WIN32_IE >= _WIN32_IE_IE50 */

/* Variant type definitions, dependent of the state of the UNICODE macro.
 * FIXME: Consider relocating these, placing each immediately below, and
 * adjacent to, the invariants to which they refer.
 */
typedef __AW_ALIAS__( HDITEM );
typedef __AW_ALIAS__( TOOLINFO ), *PTOOLINFO, *LPTOOLINFO;
typedef __AW_ALIAS__( TTHITTESTINFO ), *LPHITTESTINFO, *LPTTHITTESTINFO;
typedef __AW_ALIAS__( TOOLTIPTEXT ), *LPTOOLTIPTEXT;
typedef __AW_ALIAS__( NMTTDISPINFO ), *LPNMTTDISPINFO;
typedef __AW_ALIAS__( TV_ITEM ), *LPTV_ITEM;
typedef __AW_ALIAS__( TVITEM ), *LPTVITEM;

#if _WIN32_IE >= _WIN32_IE_IE40

typedef __AW_ALIAS__( TVITEMEX ), *LPTVITEMEX;

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

typedef __AW_ALIAS__( TV_INSERTSTRUCT ), *LPTV_INSERTSTRUCT;
typedef __AW_ALIAS__( TVINSERTSTRUCT ), *LPTVINSERTSTRUCT;
typedef __AW_ALIAS__( NM_TREEVIEW ), *LPNM_TREEVIEW;
typedef __AW_ALIAS__( NMTREEVIEW ), *LPNMTREEVIEW;
typedef __AW_ALIAS__( NMHDDISPINFO ), *LPNMHDDISPINFO;

/* Variant constant aliases, dependent of the state of the UNICODE macro.
 * FIXME: Consider relocating these, placing each adjacent to the invariant
 * manifest constants to which they refer.
 */
#define ACM_OPEN		__AW_SUFFIXED__( ACM_OPEN )
#define COMBOBOXEXITEM		__AW_SUFFIXED__( COMBOBOXEXITEM )
#define PCOMBOBOXEXITEM 	__AW_SUFFIXED__( PCOMBOBOXEXITEM )
#define PCCOMBOBOXEXITEM	__AW_SUFFIXED__( PCCOMBOBOXEXITEM )
#define CBEM_INSERTITEM 	__AW_SUFFIXED__( CBEM_INSERTITEM )
#define CBEM_SETITEM		__AW_SUFFIXED__( CBEM_SETITEM )
#define CBEM_GETITEM		__AW_SUFFIXED__( CBEM_GETITEM )
#define CBEN_ENDEDIT		__AW_SUFFIXED__( CBEN_ENDEDIT )
#define NMCBEENDEDIT		__AW_SUFFIXED__( NMCBEENDEDIT )
#define LPNMCBEENDEDIT		__AW_SUFFIXED__( LPNMCBEENDEDIT )
#define PNMCBEENDEDIT		__AW_SUFFIXED__( PNMCBEENDEDIT )

#if _WIN32_IE >= _WIN32_IE_IE40

#define NMCOMBOBOXEX		__AW_SUFFIXED__( NMCOMBOBOXEX )
#define PNMCOMBOBOXEX		__AW_SUFFIXED__( PNMCOMBOBOXEX )
#define CBEN_GETDISPINFO	__AW_SUFFIXED__( CBEN_GETDISPINFO )
#define CBEN_DRAGBEGIN		__AW_SUFFIXED__( CBEN_DRAGBEGIN )
#define NMCBEDRAGBEGIN		__AW_SUFFIXED__( NMCBEDRAGBEGIN )
#define LPNMCBEDRAGBEGIN	__AW_SUFFIXED__( LPNMCBEDRAGBEGIN )
#define PNMCBEDRAGBEGIN 	__AW_SUFFIXED__( PNMCBEDRAGBEGIN )

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define SB_GETTEXT		__AW_SUFFIXED__( SB_GETTEXT )
#define SB_SETTEXT		__AW_SUFFIXED__( SB_SETTEXT )
#define SB_GETTEXTLENGTH	__AW_SUFFIXED__( SB_GETTEXTLENGTH )
#define HDM_INSERTITEM		__AW_SUFFIXED__( HDM_INSERTITEM )
#define HDM_GETITEM		__AW_SUFFIXED__( HDM_GETITEM )
#define HDM_SETITEM		__AW_SUFFIXED__( HDM_SETITEM )
#define HDN_ITEMCHANGING	__AW_SUFFIXED__( HDN_ITEMCHANGING )
#define HDN_ITEMCHANGED 	__AW_SUFFIXED__( HDN_ITEMCHANGED )
#define HDN_ITEMCLICK		__AW_SUFFIXED__( HDN_ITEMCLICK )
#define HDN_ITEMDBLCLICK	__AW_SUFFIXED__( HDN_ITEMDBLCLICK )
#define HDN_DIVIDERDBLCLICK	__AW_SUFFIXED__( HDN_DIVIDERDBLCLICK )
#define HDN_BEGINTRACK		__AW_SUFFIXED__( HDN_BEGINTRACK )
#define HDN_ENDTRACK		__AW_SUFFIXED__( HDN_ENDTRACK )
#define HDN_TRACK		__AW_SUFFIXED__( HDN_TRACK )

#if _WIN32_IE >= _WIN32_IE_IE30

#define HDN_GETDISPINFO 	__AW_SUFFIXED__( HDN_GETDISPINFO )

#endif	/* _WIN32_IE >= _WIN32_IE_IE30 */

#define HD_NOTIFY		__AW_SUFFIXED__( HD_NOTIFY )
#define TBSAVEPARAMS		__AW_SUFFIXED__( TBSAVEPARAMS )
#define TB_GETBUTTONTEXT	__AW_SUFFIXED__( TB_GETBUTTONTEXT )
#define TB_SAVERESTORE		__AW_SUFFIXED__( TB_SAVERESTORE )
#define TB_ADDSTRING		__AW_SUFFIXED__( TB_ADDSTRING )
#define TBN_GETBUTTONINFO	__AW_SUFFIXED__( TBN_GETBUTTONINFO )

#if _WIN32_IE >= _WIN32_IE_IE40

#define TB_GETBUTTONINFO	__AW_SUFFIXED__( TB_GETBUTTONINFO )
#define TB_SETBUTTONINFO	__AW_SUFFIXED__( TB_SETBUTTONINFO )
#define TB_INSERTBUTTON 	__AW_SUFFIXED__( TB_INSERTBUTTON )
#define TB_ADDBUTTONS		__AW_SUFFIXED__( TB_ADDBUTTONS )
#define TB_MAPACCELERATOR	__AW_SUFFIXED__( TB_MAPACCELERATOR )
#define TB_GETSTRING		__AW_SUFFIXED__( TB_GETSTRING )
#define TBBUTTONINFO		__AW_SUFFIXED__( TBBUTTONINFO )
#define LPTBBUTTONINFO		__AW_SUFFIXED__( LPTBBUTTONINFO )
#define TBN_GETDISPINFO 	__AW_SUFFIXED__( TBN_GETDISPINFO )
#define NMTBDISPINFO		__AW_SUFFIXED__( NMTBDISPINFO )
#define LPNMTBDISPINFO		__AW_SUFFIXED__( LPNMTBDISPINFO )
#define NMTBGETINFOTIP		__AW_SUFFIXED__( NMTBGETINFOTIP )
#define LPNMTBGETINFOTIP	__AW_SUFFIXED__( LPNMTBGETINFOTIP )

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TBNOTIFY		__AW_SUFFIXED__( TBNOTIFY )
#define LPTBNOTIFY		__AW_SUFFIXED__( LPTBNOTIFY )
#define NMTOOLBAR		__AW_SUFFIXED__( NMTOOLBAR )
#define LPNMTOOLBAR		__AW_SUFFIXED__( LPNMTOOLBAR )
#define TTM_ADDTOOL		__AW_SUFFIXED__( TTM_ADDTOOL )
#define TTM_DELTOOL		__AW_SUFFIXED__( TTM_DELTOOL )
#define TTM_NEWTOOLRECT 	__AW_SUFFIXED__( TTM_NEWTOOLRECT )
#define TTM_GETTOOLINFO 	__AW_SUFFIXED__( TTM_GETTOOLINFO )
#define TTM_SETTOOLINFO 	__AW_SUFFIXED__( TTM_SETTOOLINFO )
#define TTM_HITTEST		__AW_SUFFIXED__( TTM_HITTEST )
#define TTM_GETTEXT		__AW_SUFFIXED__( TTM_GETTEXT )
#define TTM_UPDATETIPTEXT	__AW_SUFFIXED__( TTM_UPDATETIPTEXT )
#define TTM_ENUMTOOLS		__AW_SUFFIXED__( TTM_ENUMTOOLS )
#define TTM_GETCURRENTTOOL	__AW_SUFFIXED__( TTM_GETCURRENTTOOL )
#define TTN_NEEDTEXT		__AW_SUFFIXED__( TTN_NEEDTEXT )
#define TTN_GETDISPINFO 	__AW_SUFFIXED__( TTN_GETDISPINFO )
#define SB_GETTEXT		__AW_SUFFIXED__( SB_GETTEXT )
#define SB_SETTEXT		__AW_SUFFIXED__( SB_SETTEXT )
#define SB_GETTEXTLENGTH	__AW_SUFFIXED__( SB_GETTEXTLENGTH )
#define LV_ITEM 		__AW_SUFFIXED__( LV_ITEM )
#define LVITEM			__AW_SUFFIXED__( LVITEM )
#define LPSTR_TEXTCALLBACK	__AW_SUFFIXED__( LPSTR_TEXTCALLBACK )

#if _WIN32_IE >= _WIN32_IE_IE40

#define LVBKIMAGE		__AW_SUFFIXED__( LVBKIMAGE )
#define LPLVBKIMAGE		__AW_SUFFIXED__( LPLVBKIMAGE )
#define LVM_SETBKIMAGE		__AW_SUFFIXED__( LVM_SETBKIMAGE )
#define LVM_GETBKIMAGE		__AW_SUFFIXED__( LVM_GETBKIMAGE )

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define LVM_GETITEM		__AW_SUFFIXED__( LVM_GETITEM )
#define LVM_SETITEM		__AW_SUFFIXED__( LVM_SETITEM )
#define LVM_INSERTITEM		__AW_SUFFIXED__( LVM_INSERTITEM )
#define LV_FINDINFO		__AW_SUFFIXED__( LV_FINDINFO )
#define LVFINDINFO		__AW_SUFFIXED__( LVFINDINFO )
#define LPFINDINFO		__AW_SUFFIXED__( LPFINDINFO )
#define NMLVFINDITEM		__AW_SUFFIXED__( NMLVFINDITEM )
#define PNMLVFINDITEM		__AW_SUFFIXED__( PNMLVFINDITEM )
#define LPNMLVFINDITEM		__AW_SUFFIXED__( LPNMLVFINDITEM )
#define LVM_FINDITEM		__AW_SUFFIXED__( LVM_FINDITEM )
#define LVM_GETSTRINGWIDTH	__AW_SUFFIXED__( LVM_GETSTRINGWIDTH )
#define LVM_EDITLABEL		__AW_SUFFIXED__( LVM_EDITLABEL )
#define LV_COLUMN		__AW_SUFFIXED__( LV_COLUMN )
#define LVCOLUMN		__AW_SUFFIXED__( LVCOLUMN )
#define LVM_GETCOLUMN		__AW_SUFFIXED__( LVM_GETCOLUMN )
#define LVM_SETCOLUMN		__AW_SUFFIXED__( LVM_SETCOLUMN )
#define LVM_INSERTCOLUMN	__AW_SUFFIXED__( LVM_INSERTCOLUMN )
#define LVM_GETITEMTEXT 	__AW_SUFFIXED__( LVM_GETITEMTEXT )
#define LVM_SETITEMTEXT 	__AW_SUFFIXED__( LVM_SETITEMTEXT )
#define LVM_GETISEARCHSTRING	__AW_SUFFIXED__( LVM_GETISEARCHSTRING )
#define LVN_BEGINLABELEDIT	__AW_SUFFIXED__( LVN_BEGINLABELEDIT )
#define LVN_ENDLABELEDIT	__AW_SUFFIXED__( LVN_ENDLABELEDIT )
#define LVN_GETDISPINFO 	__AW_SUFFIXED__( LVN_GETDISPINFO )
#define LVN_SETDISPINFO 	__AW_SUFFIXED__( LVN_SETDISPINFO )
#define LVN_GETINFOTIP		__AW_SUFFIXED__( LVN_GETINFOTIP )
#define NMLVGETINFOTIP		__AW_SUFFIXED__( NMLVGETINFOTIP )
#define LPNMLVGETINFOTIP	__AW_SUFFIXED__( LPNMLVGETINFOTIP )
#define LV_DISPINFO		__AW_SUFFIXED__( LV_DISPINFO )
#define NMLVDISPINFO		__AW_SUFFIXED__( NMLVDISPINFO )
#define LPNMLVDISPINFO		__AW_SUFFIXED__( LPNMLVDISPINFO )
#define TVM_INSERTITEM		__AW_SUFFIXED__( TVM_INSERTITEM )
#define TVM_GETITEM		__AW_SUFFIXED__( TVM_GETITEM )
#define TVM_SETITEM		__AW_SUFFIXED__( TVM_SETITEM )
#define TVM_EDITLABEL		__AW_SUFFIXED__( TVM_EDITLABEL )
#define TVM_GETISEARCHSTRING	__AW_SUFFIXED__( TVM_GETISEARCHSTRING )
#define TV_DISPINFO		__AW_SUFFIXED__( NMTVDISPINFO )
#define NMTVDISPINFO		__AW_SUFFIXED__( NMTVDISPINFO )
#define LPNMTVDISPINFO		__AW_SUFFIXED__( LPNMTVDISPINFO )

#if _WIN32_IE >= _WIN32_IE_IE40

#define NMTVGETINFOTIP		__AW_SUFFIXED__( NMTVGETINFOTIP )
#define LPNMTVGETINFOTIP	__AW_SUFFIXED__( LPNMTVGETINFOTIP )
#define TVN_GETINFOTIP		__AW_SUFFIXED__( TVN_GETINFOTIP )

#endif	/* _WIN32_IE >= _WIN32_IE_IE40 */

#define TVN_SELCHANGING 	__AW_SUFFIXED__( TVN_SELCHANGING )
#define TVN_SELCHANGED		__AW_SUFFIXED__( TVN_SELCHANGED )
#define TVN_GETDISPINFO 	__AW_SUFFIXED__( TVN_GETDISPINFO )
#define TVN_SETDISPINFO 	__AW_SUFFIXED__( TVN_SETDISPINFO )
#define TVN_ITEMEXPANDING	__AW_SUFFIXED__( TVN_ITEMEXPANDING )
#define TVN_ITEMEXPANDED	__AW_SUFFIXED__( TVN_ITEMEXPANDED )
#define TVN_BEGINDRAG		__AW_SUFFIXED__( TVN_BEGINDRAG )
#define TVN_BEGINRDRAG		__AW_SUFFIXED__( TVN_BEGINRDRAG )
#define TVN_DELETEITEM		__AW_SUFFIXED__( TVN_DELETEITEM )
#define TVN_BEGINLABELEDIT	__AW_SUFFIXED__( TVN_BEGINLABELEDIT )
#define TVN_ENDLABELEDIT	__AW_SUFFIXED__( TVN_ENDLABELEDIT )
#define TC_ITEMHEADER		__AW_SUFFIXED__( TC_ITEMHEADER )
#define TCITEMHEADER		__AW_SUFFIXED__( TCITEMHEADER )
#define LPTCITEMHEADER		__AW_SUFFIXED__( LPTCITEMHEADER )
#define TC_ITEM 		__AW_SUFFIXED__( TC_ITEM )
#define TCITEM			__AW_SUFFIXED__( TCITEM )
#define LPTCITEM		__AW_SUFFIXED__( LPTCITEM )
#define TCM_GETITEM		__AW_SUFFIXED__( TCM_GETITEM )
#define TCM_SETITEM		__AW_SUFFIXED__( TCM_SETITEM )
#define TCM_INSERTITEM		__AW_SUFFIXED__( TCM_INSERTITEM )
#define CreateStatusWindow	__AW_SUFFIXED__( CreateStatusWindow )
#define DrawStatusText		__AW_SUFFIXED__( DrawStatusText )
#define ImageList_LoadImage	__AW_SUFFIXED__( ImageList_LoadImage )
#define DTM_SETFORMAT		__AW_SUFFIXED__( DTM_SETFORMAT )
#define DTN_USERSTRING		__AW_SUFFIXED__( DTN_USERSTRING )
#define DTN_WMKEYDOWN		__AW_SUFFIXED__( DTN_WMKEYDOWN )
#define DTN_FORMAT		__AW_SUFFIXED__( DTN_FORMAT )
#define DTN_FORMATQUERY 	__AW_SUFFIXED__( DTN_FORMATQUERY )

typedef __AW_ALIAS__( REBARBANDINFO ), *LPREBARBANDINFO;

#ifdef UNICODE
/* Ideally, we would like to use one-line __AW_SUFFIXED__ style semantics
 * for each UNICODE variant name, but in this case, it likely isn't worth
 * defining a custom macro, to generate just this one anomalously formed
 * UNICODE variant manifest constant name mapping.
 */
#define REBARBANDINFO_V3_SIZE	  REBARBANDINFOW_V3_SIZE

#else	/* ! UNICODE */

#define REBARBANDINFO_V3_SIZE	  REBARBANDINFOA_V3_SIZE

#endif	/* ! UNICODE */

#define LPCREBARBANDINFO	__AW_SUFFIXED__( LPCREBARBANDINFO )
#define RB_INSERTBAND		__AW_SUFFIXED__( RB_INSERTBAND )
#define RB_SETBANDINFO		__AW_SUFFIXED__( RB_SETBANDINFO )

#endif	/* ! RC_INVOKED */

#ifdef _WIN32_WCE               /* these are PPC only */

WINAPI COMMCTRLAPI HWND CommandBar_Create (HINSTANCE, HWND, int);
WINAPI COMMCTRLAPI BOOL CommandBar_Show (HWND, BOOL);

WINAPI COMMCTRLAPI int CommandBar_AddBitmap
( HWND, HINSTANCE, int, int, int, int );

WINAPI COMMCTRLAPI HWND CommandBar_InsertComboBox
( HWND, HINSTANCE, int, UINT, WORD, WORD );

WINAPI COMMCTRLAPI BOOL CommandBar_InsertMenubar
( HWND, HINSTANCE, WORD, WORD );

WINAPI COMMCTRLAPI BOOL CommandBar_InsertMenubarEx
( HWND, HINSTANCE, LPTSTR, WORD );

WINAPI COMMCTRLAPI BOOL CommandBar_DrawMenuBar (HWND, WORD);
WINAPI COMMCTRLAPI HMENU CommandBar_GetMenu (HWND, WORD);
WINAPI COMMCTRLAPI BOOL CommandBar_AddAdornments (HWND, DWORD, DWORD);
WINAPI COMMCTRLAPI int CommandBar_Height (HWND hwndCB);

/* These two are not in the DLL */
#define CommandBar_InsertButton( hwnd, i, lptbbutton )		\
    SendMessage ((hwnd), TB_INSERTBUTTON, (i), (lptbbutton))

#define CommandBar_Destroy( hwnd )				\
    DestroyWindow (hwnd)

#endif	/* _WIN32_WCE */

_END_C_DECLS

#endif	/* !_COMMCTRL_H: $RCSfile: commctrl.h,v $: end of file */
