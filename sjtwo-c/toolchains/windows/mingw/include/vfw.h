#ifndef _VFW_H
#define _VFW_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef _WINDOWS_H
#include <windows.h>
#endif
#ifndef _MMSYSTEM_H
#include <mmsystem.h>
#endif
#if !defined  (_OLE2_H) && !defined (_OBJC_NO_COM)
#include <ole2.h>
#endif

#define VFWAPI WINAPI
#define VFWAPIV WINAPIV

#include <pshpack8.h>

#ifdef __cplusplus
extern "C" {
#endif

#define	ICERR_OK	0
#define	ICERR_DONTDRAW	1
#define	ICERR_NEWPALETTE	2
#define	ICERR_GOTOKEYFRAME	3
#define	ICERR_STOPDRAWING	4
#define	ICERR_UNSUPPORTED	-1
#define	ICERR_BADFORMAT	-2
#define	ICERR_MEMORY	-3
#define	ICERR_INTERNAL	-4
#define	ICERR_BADFLAGS	-5
#define	ICERR_BADPARAM	-6
#define	ICERR_BADSIZE	-7
#define	ICERR_BADHANDLE	-8
#define	ICERR_CANTUPDATE	-9
#define	ICERR_ABORT	-10
#define	ICERR_ERROR	-100
#define	ICERR_BADBITDEPTH	-200
#define	ICERR_BADIMAGESIZE	-201
#define	ICERR_CUSTOM	-400
#define ICCOMPRESSFRAMES_PADDING	0x01
#define	ICM_USER	(DRV_USER+0x0000)
#define	ICM_RESERVED_LOW	(DRV_USER+0x1000)
#define	ICM_RESERVED_HIGH	(DRV_USER+0x2000)
#define	ICM_RESERVED	ICM_RESERVED_LOW
#define	ICM_GETSTATE	(ICM_RESERVED+0)
#define	ICM_SETSTATE	(ICM_RESERVED+1)
#define	ICM_GETINFO	(ICM_RESERVED+2)
#define	ICM_CONFIGURE	(ICM_RESERVED+10)
#define	ICM_ABOUT	(ICM_RESERVED+11)
#define	ICM_GETDEFAULTQUALITY	(ICM_RESERVED+30)
#define	ICM_GETQUALITY	(ICM_RESERVED+31)
#define	ICM_SETQUALITY	(ICM_RESERVED+32)
#define	ICM_SET	(ICM_RESERVED+40)
#define	ICM_GET	(ICM_RESERVED+41)
#define ICM_FRAMERATE	mmioFOURCC('F','r','m','R')
#define ICM_KEYFRAMERATE	mmioFOURCC('K','e','y','R')
#define	ICM_COMPRESS_GET_FORMAT	(ICM_USER+4)
#define	ICM_COMPRESS_GET_SIZE	(ICM_USER+5)
#define	ICM_COMPRESS_QUERY	(ICM_USER+6)
#define	ICM_COMPRESS_BEGIN	(ICM_USER+7)
#define	ICM_COMPRESS	(ICM_USER+8)
#define	ICM_COMPRESS_END	(ICM_USER+9)
#define	ICM_DECOMPRESS_GET_FORMAT	(ICM_USER+10)
#define	ICM_DECOMPRESS_QUERY	(ICM_USER+11)
#define	ICM_DECOMPRESS_BEGIN	(ICM_USER+12)
#define	ICM_DECOMPRESS	(ICM_USER+13)
#define	ICM_DECOMPRESS_END	(ICM_USER+14)
#define	ICM_DECOMPRESS_SET_PALETTE	(ICM_USER+29)
#define	ICM_DECOMPRESS_GET_PALETTE	(ICM_USER+30)
#define	ICM_DRAW_QUERY	(ICM_USER+31)
#define	ICM_DRAW_BEGIN	(ICM_USER+15)
#define	ICM_DRAW_GET_PALETTE	(ICM_USER+16)
#define	ICM_DRAW_START	(ICM_USER+18)
#define	ICM_DRAW_STOP	(ICM_USER+19)
#define	ICM_DRAW_END	(ICM_USER+21)
#define	ICM_DRAW_GETTIME	(ICM_USER+32)
#define	ICM_DRAW	(ICM_USER+33)
#define	ICM_DRAW_WINDOW	(ICM_USER+34)
#define	ICM_DRAW_SETTIME	(ICM_USER+35)
#define	ICM_DRAW_REALIZE	(ICM_USER+36)
#define	ICM_DRAW_FLUSH	(ICM_USER+37)
#define	ICM_DRAW_RENDERBUFFER	(ICM_USER+38)
#define	ICM_DRAW_START_PLAY	(ICM_USER+39)
#define	ICM_DRAW_STOP_PLAY	(ICM_USER+40)
#define	ICM_DRAW_SUGGESTFORMAT	(ICM_USER+50)
#define	ICM_DRAW_CHANGEPALETTE	(ICM_USER+51)
#define	ICM_GETBUFFERSWANTED	(ICM_USER+41)
#define	ICM_GETDEFAULTKEYFRAMERATE	(ICM_USER+42)
#define	ICM_DECOMPRESSEX_BEGIN	(ICM_USER+60)
#define	ICM_DECOMPRESSEX_QUERY	(ICM_USER+61)
#define	ICM_DECOMPRESSEX	(ICM_USER+62)
#define	ICM_DECOMPRESSEX_END	(ICM_USER+63)
#define	ICM_COMPRESS_FRAMES_INFO	(ICM_USER+70)
#define	ICM_SET_STATUS_PROC	(ICM_USER+72)
#define ICMF_CONFIGURE_QUERY	0x01
#define ICCOMPRESS_KEYFRAME	0x01
#define ICSTATUS_START	0
#define ICSTATUS_STATUS	1
#define ICSTATUS_END	2
#define ICSTATUS_ERROR	3
#define ICSTATUS_YIELD	4
#define	ICMODE_COMPRESS	1
#define	ICMODE_DECOMPRESS	2
#define	ICMODE_FASTDECOMPRESS	3
#define	ICMODE_QUERY	4
#define	ICMODE_FASTCOMPRESS	5
#define	ICMODE_DRAW	8
#define ICQUALITY_LOW	0
#define ICQUALITY_HIGH	10000
#define ICQUALITY_DEFAULT	-1
#define	VIDCF_QUALITY	0x01
#define	VIDCF_CRUNCH	0x02
#define	VIDCF_TEMPORAL	0x04
#define	VIDCF_COMPRESSFRAMES	0x08
#define	VIDCF_DRAW	0x10
#define	VIDCF_FASTTEMPORALC	0x20
#define	VIDCF_FASTTEMPORALD	0x80
#define	VIDCF_QUALITYTIME	0x40
#define	VIDCF_FASTTEMPORAL	(VIDCF_FASTTEMPORALC|VIDCF_FASTTEMPORALD)
#define ICMF_ABOUT_QUERY	0x01
#define ICDECOMPRESS_HURRYUP	0x80000000
#define ICDECOMPRESS_UPDATE	0x40000000
#define ICDECOMPRESS_PREROLL	0x20000000
#define ICDECOMPRESS_NULLFRAME	0x10000000
#define ICDECOMPRESS_NOTKEYFRAME	0x8000000
#define ICDRAW_QUERY	0x01L
#define ICDRAW_FULLSCREEN	0x02L
#define ICDRAW_HDC	0x04L
#define ICDRAW_ANIMATE	0x08L
#define ICDRAW_CONTINUE	0x10L
#define ICDRAW_MEMORYDC	0x20L
#define ICDRAW_UPDATING	0x40L
#define ICDRAW_RENDER	0x80L
#define ICDRAW_BUFFER	0x100L
#define ICINSTALL_UNICODE	0x8000
#define ICINSTALL_FUNCTION	0x01
#define ICINSTALL_DRIVER	0x02
#define ICINSTALL_HDRV	0x04
#define ICINSTALL_DRIVERW	0x8002
#define ICDRAW_HURRYUP	0x80000000L
#define ICDRAW_UPDATE	0x40000000L
#define ICDRAW_PREROLL	0x20000000L
#define ICDRAW_NULLFRAME	0x10000000L
#define ICDRAW_NOTKEYFRAME	0x8000000L
#define ICMF_COMPVARS_VALID	0x01
#define ICMF_CHOOSE_KEYFRAME	0x01
#define ICMF_CHOOSE_DATARATE	0x02
#define ICMF_CHOOSE_PREVIEW	0x04
#define ICMF_CHOOSE_ALLCOMPRESSORS	0x08
#define ICTYPE_VIDEO	mmioFOURCC('v','i','d','c')
#define ICTYPE_AUDIO	mmioFOURCC('a','u','d','c')
#define formtypeAVI	mmioFOURCC('A','V','I',' ')
#define listtypeAVIHEADER	mmioFOURCC('h','d','r','l')
#define ckidAVIMAINHDR	mmioFOURCC('a','v','i','h')
#define listtypeSTREAMHEADER	mmioFOURCC('s','t','r','l')
#define ckidSTREAMHEADER	mmioFOURCC('s','t','r','h')
#define ckidSTREAMFORMAT	mmioFOURCC('s','t','r','f')
#define ckidSTREAMHANDLERDATA	mmioFOURCC('s','t','r','d')
#define ckidSTREAMNAME	mmioFOURCC('s','t','r','n')
#define listtypeAVIMOVIE	mmioFOURCC('m','o','v','i')
#define listtypeAVIRECORD	mmioFOURCC('r','e','c',' ')
#define ckidAVINEWINDEX	mmioFOURCC('i', 'd', 'x', '1')
#define streamtypeANY	0UL
#define streamtypeVIDEO	mmioFOURCC('v','i','d','s')
#define streamtypeAUDIO	mmioFOURCC('a','u','d','s')
#define streamtypeMIDI	mmioFOURCC('m','i','d','s')
#define streamtypeTEXT	mmioFOURCC('t','x','t','s')
#define cktypeDIBbits	aviTWOCC('d','b')
#define cktypeDIBcompressed	aviTWOCC('d','c')
#define cktypePALchange	aviTWOCC('p','c')
#define cktypeWAVEbytes	aviTWOCC('w','b')
#define ckidAVIPADDING	mmioFOURCC('J','U','N','K')
#define FromHex(n) (((n)>='A')?((n)+10-'A'):((n)-'0'))
#define StreamFromFOURCC(fcc) ((WORD)((FromHex(LOBYTE(LOWORD(fcc)))<<4)+(FromHex(HIBYTE(LOWORD(fcc))))))
#define TWOCCFromFOURCC(fcc) HIWORD(fcc)
#define ToHex(n) ((BYTE)(((n)>9)?((n)-10+'A'):((n)+'0')))
#define MAKEAVICKID(tcc, stream) MAKELONG((ToHex((stream)&0x0f)<<8)|(ToHex(((stream)&0xf0)>>4)),tcc)
#define AVIF_HASINDEX	0x10
#define AVIF_MUSTUSEINDEX	0x20
#define AVIF_ISINTERLEAVED	0x100
#define AVIF_TRUSTCKTYPE	0x800
#define AVIF_WASCAPTUREFILE	0x10000
#define AVIF_COPYRIGHTED	0x20000
#define AVI_HEADERSIZE	2048
#define AVISF_DISABLED	0x01
#define AVISF_VIDEO_PALCHANGES	0x10000
#define AVIIF_LIST	0x01
#define AVIIF_TWOCC	0x02
#define AVIIF_KEYFRAME	0x10
#define AVIIF_NOTIME	0x100
#define AVIIF_COMPUSE	0xfff0000
#define AVIIF_KEYFRAME	0x10
#define	AVIGETFRAMEF_BESTDISPLAYFMT	1
#define AVISTREAMINFO_DISABLED	0x01
#define AVISTREAMINFO_FORMATCHANGES	0x10000
#define AVIFILEINFO_HASINDEX	0x10
#define AVIFILEINFO_MUSTUSEINDEX	0x20
#define AVIFILEINFO_ISINTERLEAVED	0x100
#define AVIFILEINFO_TRUSTCKTYPE	0x800
#define AVIFILEINFO_WASCAPTUREFILE	0x10000
#define AVIFILEINFO_COPYRIGHTED	0x20000
#define AVIFILECAPS_CANREAD	0x01
#define AVIFILECAPS_CANWRITE	0x02
#define AVIFILECAPS_ALLKEYFRAMES	0x10
#define AVIFILECAPS_NOCOMPRESSION	0x20
#define AVICOMPRESSF_INTERLEAVE	0x01
#define AVICOMPRESSF_DATARATE	0x02
#define AVICOMPRESSF_KEYFRAMES	0x04
#define AVICOMPRESSF_VALID	0x08
#define FIND_DIR	0x0000000fL
#define FIND_NEXT	0x00000001L
#define FIND_PREV	0x00000004L
#define FIND_FROM_START	0x00000008L
#define FIND_TYPE	0x000000f0L
#define FIND_KEY	0x00000010L
#define FIND_ANY	0x00000020L
#define FIND_FORMAT	0x00000040L
#define FIND_RET	0x0000f000L
#define FIND_POS	0x00000000L
#define FIND_LENGTH	0x00001000L
#define FIND_OFFSET	0x00002000L
#define FIND_SIZE	0x00003000L
#define FIND_INDEX	0x00004000L
#define AVIERR_OK	0
#define MAKE_AVIERR(e)	MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x4000+e)
#define AVIERR_UNSUPPORTED	MAKE_AVIERR(101)
#define AVIERR_BADFORMAT	MAKE_AVIERR(102)
#define AVIERR_MEMORY	MAKE_AVIERR(103)
#define AVIERR_INTERNAL	MAKE_AVIERR(104)
#define AVIERR_BADFLAGS	MAKE_AVIERR(105)
#define AVIERR_BADPARAM	MAKE_AVIERR(106)
#define AVIERR_BADSIZE	MAKE_AVIERR(107)
#define AVIERR_BADHANDLE	MAKE_AVIERR(108)
#define AVIERR_FILEREAD	MAKE_AVIERR(109)
#define AVIERR_FILEWRITE	MAKE_AVIERR(110)
#define AVIERR_FILEOPEN	MAKE_AVIERR(111)
#define AVIERR_COMPRESSOR	MAKE_AVIERR(112)
#define AVIERR_NOCOMPRESSOR	MAKE_AVIERR(113)
#define AVIERR_READONLY	MAKE_AVIERR(114)
#define AVIERR_NODATA	MAKE_AVIERR(115)
#define AVIERR_BUFFERTOOSMALL	MAKE_AVIERR(116)
#define AVIERR_CANTCOMPRESS	MAKE_AVIERR(117)
#define AVIERR_USERABORT	MAKE_AVIERR(198)
#define AVIERR_ERROR	MAKE_AVIERR(199)
#define MCIWNDOPENF_NEW	0x0001
#define MCIWNDF_NOAUTOSIZEWINDOW	0x0001
#define MCIWNDF_NOPLAYBAR	0x0002
#define MCIWNDF_NOAUTOSIZEMOVIE	0x0004
#define MCIWNDF_NOMENU	0x0008
#define MCIWNDF_SHOWNAME	0x0010
#define MCIWNDF_SHOWPOS	0x0020
#define MCIWNDF_SHOWMODE	0x0040
#define MCIWNDF_SHOWALL	0x0070
#define MCIWNDF_NOTIFYMODE	0x0100
#define MCIWNDF_NOTIFYPOS	0x0200
#define MCIWNDF_NOTIFYSIZE	0x0400
#define MCIWNDF_NOTIFYERROR	0x1000
#define MCIWNDF_NOTIFYALL	0x1F00
#define MCIWNDF_NOTIFYANSI	0x0080
#define MCIWNDF_NOTIFYMEDIAA	0x0880
#define MCIWNDF_NOTIFYMEDIAW	0x0800
#define MCIWNDF_RECORD	0x2000
#define MCIWNDF_NOERRORDLG	0x4000
#define MCIWNDF_NOOPEN	0x8000
#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETLENGTH	(WM_USER + 104)
#define MCIWNDM_GETEND	(WM_USER + 105)
#define MCIWNDM_EJECT	(WM_USER + 107)
#define MCIWNDM_SETZOOM	(WM_USER + 108)
#define MCIWNDM_GETZOOM	(WM_USER + 109)
#define MCIWNDM_SETVOLUME	(WM_USER + 110)
#define MCIWNDM_GETVOLUME	(WM_USER + 111)
#define MCIWNDM_SETSPEED	(WM_USER + 112)
#define MCIWNDM_GETSPEED	(WM_USER + 113)
#define MCIWNDM_SETREPEAT	(WM_USER + 114)
#define MCIWNDM_GETREPEAT	(WM_USER + 115)
#define MCIWNDM_REALIZE	(WM_USER + 118)
#define MCIWNDM_VALIDATEMEDIA	(WM_USER + 121)
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO	(WM_USER + 123)
#define MCIWNDM_GETPALETTE	(WM_USER + 126)
#define MCIWNDM_SETPALETTE	(WM_USER + 127)
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER	(WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER	(WM_USER + 133)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE	(WM_USER + 140)
#define MCIWNDM_PUT_SOURCE	(WM_USER + 141)
#define MCIWNDM_GET_DEST	(WM_USER + 142)
#define MCIWNDM_PUT_DEST	(WM_USER + 143)
#define MCIWNDM_CAN_PLAY	(WM_USER + 144)
#define MCIWNDM_CAN_WINDOW	(WM_USER + 145)
#define MCIWNDM_CAN_RECORD	(WM_USER + 146)
#define MCIWNDM_CAN_SAVE	(WM_USER + 147)
#define MCIWNDM_CAN_EJECT	(WM_USER + 148)
#define MCIWNDM_CAN_CONFIG	(WM_USER + 149)
#define MCIWNDM_PALETTEKICK	(WM_USER + 150)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_SETOWNER	(WM_USER + 152)
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMATA	(WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA	(WM_USER + 120)
#define MCIWNDM_GETFILENAMEA	(WM_USER + 124)
#define MCIWNDM_GETDEVICEA	(WM_USER + 125)
#define MCIWNDM_GETERRORA	(WM_USER + 128)
#define MCIWNDM_NEWA	(WM_USER + 134)
#define MCIWNDM_RETURNSTRINGA	(WM_USER + 138)
#define MCIWNDM_OPENA	(WM_USER + 153)
#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_SETTIMEFORMATW	(WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW	(WM_USER + 220)
#define MCIWNDM_GETFILENAMEW	(WM_USER + 224)
#define MCIWNDM_GETDEVICEW	(WM_USER + 225)
#define MCIWNDM_GETERRORW	(WM_USER + 228)
#define MCIWNDM_NEWW	(WM_USER + 234)
#define MCIWNDM_RETURNSTRINGW	(WM_USER + 238)
#define MCIWNDM_OPENW	(WM_USER + 252)
#define MCIWNDM_NOTIFYMODE	(WM_USER + 200)
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)
#define MCIWNDM_NOTIFYMEDIA	(WM_USER + 203)
#define MCIWNDM_NOTIFYERROR	(WM_USER + 205)
#define MCIWND_START	-1
#define MCIWND_END	-2
#define DDF_UPDATE	0x02
#define DDF_SAME_HDC	0x04
#define DDF_SAME_DRAW	0x08
#define DDF_DONTDRAW	0x10
#define DDF_ANIMATE	0x20
#define DDF_BUFFER	0x40
#define DDF_JUSTDRAWIT	0x80
#define DDF_FULLSCREEN	0x100
#define DDF_BACKGROUNDPAL	0x200
#define DDF_NOTKEYFRAME	0x400
#define DDF_HURRYUP	0x800
#define DDF_HALFTONE	0x1000
#define DDF_PREROLL	DDF_DONTDRAW
#define DDF_SAME_DIB	DDF_SAME_DRAW
#define DDF_SAME_SIZE	DDF_SAME_DRAW
#define PD_CAN_DRAW_DIB	0x01
#define PD_CAN_STRETCHDIB	0x02
#define PD_STRETCHDIB_1_1_OK	0x04
#define PD_STRETCHDIB_1_2_OK	0x08
#define PD_STRETCHDIB_1_N_OK	0x10
#ifndef mmioFOURCC
#define mmioFOURCC(c0,c1,c2,c3) ((DWORD)(BYTE)(c0)|((DWORD)(BYTE)(c1)<<8)|((DWORD)(BYTE)(c2)<<16)|((DWORD)(BYTE)(c3)<<24))
#endif
#ifndef aviTWOCC
#define aviTWOCC(ch0,ch1) ((WORD)(BYTE)(ch0)|((WORD)(BYTE)(ch1)<<8))
#endif

#ifndef RC_INVOKED
DECLARE_HANDLE(HIC);
DECLARE_HANDLE(HDRAWDIB);
typedef WORD TWOCC;
typedef BOOL (CALLBACK *AVISAVECALLBACK)(INT);
typedef struct {
	DWORD dwSize;
	DWORD fccType;
	DWORD fccHandler;
	DWORD dwVersion;
	DWORD dwFlags;
	LRESULT dwError;
	LPVOID pV1Reserved;
	LPVOID pV2Reserved;
	DWORD dnDevNode;
} ICOPEN,*LPICOPEN;
typedef struct {
	DWORD dwFlags;
	LPBITMAPINFOHEADER lpbiOutput;
	LPVOID lpOutput;
	LPBITMAPINFOHEADER lpbiInput;
	LPVOID lpInput;
	LPDWORD lpckid;
	LPDWORD lpdwFlags;
	LONG lFrameNum;
	DWORD dwFrameSize;
	DWORD dwQuality;
	LPBITMAPINFOHEADER lpbiPrev;
	LPVOID lpPrev;
} ICCOMPRESS;
typedef struct {
	DWORD dwFlags;
	LPBITMAPINFOHEADER lpbiOutput;
	LPARAM lOutput;
	LPBITMAPINFOHEADER lpbiInput;
	LPARAM lInput;
	LONG lStartFrame;
	LONG lFrameCount;
	LONG lQuality;
	LONG lDataRate;
	LONG lKeyRate;
	DWORD dwRate;
	DWORD dwScale;
	DWORD dwOverheadPerFrame;
	DWORD dwReserved2;
	LONG (CALLBACK *GetData)(LPARAM,LONG,LPVOID,LONG);
	LONG (CALLBACK *PutData)(LPARAM,LONG,LPVOID,LONG);
} ICCOMPRESSFRAMES;
typedef struct {
	DWORD dwFlags;
	LPARAM lParam;
	LONG (CALLBACK *Status)(LPARAM,UINT,LONG);
} ICSETSTATUSPROC;
typedef struct {
	DWORD dwSize;
	DWORD fccType;
	DWORD fccHandler;
	DWORD dwFlags;
	DWORD dwVersion;
	DWORD dwVersionICM;
	WCHAR szName[16];
	WCHAR szDescription[128];
	WCHAR szDriver[128];
} ICINFO;
typedef struct {
	DWORD dwFlags;
	LPBITMAPINFOHEADER lpbiInput;
	LPVOID lpInput;
	LPBITMAPINFOHEADER lpbiOutput;
	LPVOID lpOutput;
	DWORD ckid;
} ICDECOMPRESS;
typedef struct {
	DWORD dwFlags;
	LPBITMAPINFOHEADER lpbiSrc;
	LPVOID lpSrc;
	LPBITMAPINFOHEADER lpbiDst;
	LPVOID lpDst;
	INT xDst;
	INT yDst;
	INT dxDst;
	INT dyDst;
	INT xSrc;
	INT ySrc;
	INT dxSrc;
	INT dySrc;
} ICDECOMPRESSEX;
typedef struct {
	DWORD dwFlags;
	LPBITMAPINFOHEADER lpbiIn;
	LPBITMAPINFOHEADER lpbiSuggest;
	INT dxSrc;
	INT dySrc;
	INT dxDst;
	INT dyDst;
	HIC hicDecompressor;
} ICDRAWSUGGEST;
typedef struct {
	DWORD dwFlags;
	INT iStart;
	INT iLen;
	LPPALETTEENTRY lppe;
} ICPALETTE;
typedef struct {
	DWORD dwFlags;
	HPALETTE hpal;
	HWND hwnd;
	HDC hdc;
	INT xDst;
	INT yDst;
	INT dxDst;
	INT dyDst;
	LPBITMAPINFOHEADER lpbi;
	INT xSrc;
	INT ySrc;
	INT dxSrc;
	INT dySrc;
	DWORD dwRate;
	DWORD dwScale;
} ICDRAWBEGIN;
typedef struct {
	DWORD dwFlags;
	LPVOID lpFormat;
	LPVOID lpData;
	DWORD cbData;
	LONG lTime;
} ICDRAW;
typedef struct {
	LONG cbSize;
	DWORD dwFlags;
	HIC hic;
	DWORD fccType;
	DWORD fccHandler;
	LPBITMAPINFO lpbiIn;
	LPBITMAPINFO lpbiOut;
	LPVOID lpBitsOut;
	LPVOID lpBitsPrev;
	LONG lFrame;
	LONG lKey;
	LONG lDataRate;
	LONG lQ;
	LONG lKeyCount;
	LPVOID lpState;
	LONG cbState;
} COMPVARS, *PCOMPVARS;
typedef struct _MainAVIHeader
{
	DWORD dwMicroSecPerFrame;
	DWORD dwMaxBytesPerSec;
	DWORD dwPaddingGranularity;
	DWORD dwFlags;
	DWORD dwTotalFrames;
	DWORD dwInitialFrames;
	DWORD dwStreams;
	DWORD dwSuggestedBufferSize;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwReserved[4];
} MainAVIHeader;
typedef struct {
	FOURCC fccType;
	FOURCC fccHandler;
	DWORD dwFlags;
	WORD wPriority;
	WORD wLanguage;
	DWORD dwInitialFrames;
	DWORD dwScale;
	DWORD dwRate;
	DWORD dwStart;
	DWORD dwLength;
	DWORD dwSuggestedBufferSize;
	DWORD dwQuality;
	DWORD dwSampleSize;
	RECT rcFrame;
} AVIStreamHeader;
typedef struct _AVIINDEXENTRY {
	DWORD ckid;
	DWORD dwFlags;
	DWORD dwChunkOffset;
	DWORD dwChunkLength;
} AVIINDEXENTRY;
typedef struct _AVIPALCHANGE {
	BYTE bFirstEntry;
	BYTE bNumEntries;
	WORD wFlags;
	PALETTEENTRY peNew[1];
} AVIPALCHANGE;
typedef struct _AVISTREAMINFOA {
	DWORD fccType;
	DWORD fccHandler;
	DWORD dwFlags;
	DWORD dwCaps;
	WORD wPriority;
	WORD wLanguage;
	DWORD dwScale;
	DWORD dwRate;
	DWORD dwStart;
	DWORD dwLength;
	DWORD dwInitialFrames;
	DWORD dwSuggestedBufferSize;
	DWORD dwQuality;
	DWORD dwSampleSize;
	RECT rcFrame;
	DWORD dwEditCount;
	DWORD dwFormatChangeCount;
	CHAR szName[64];
} AVISTREAMINFOA, * LPAVISTREAMINFOA, *PAVISTREAMINFOA;
typedef struct _AVISTREAMINFOW {
	DWORD fccType;
	DWORD fccHandler;
	DWORD dwFlags;
	DWORD dwCaps;
	WORD wPriority;
	WORD wLanguage;
	DWORD dwScale;
	DWORD dwRate;
	DWORD dwStart;
	DWORD dwLength;
	DWORD dwInitialFrames;
	DWORD dwSuggestedBufferSize;
	DWORD dwQuality;
	DWORD dwSampleSize;
	RECT rcFrame;
	DWORD dwEditCount;
	DWORD dwFormatChangeCount;
	WCHAR szName[64];
} AVISTREAMINFOW, * LPAVISTREAMINFOW, *PAVISTREAMINFOW;
typedef struct _AVIFILEINFOW {
	DWORD dwMaxBytesPerSec;
	DWORD dwFlags;
	DWORD dwCaps;
	DWORD dwStreams;
	DWORD dwSuggestedBufferSize;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwScale;
	DWORD dwRate;
	DWORD dwLength;
	DWORD dwEditCount;
	WCHAR szFileType[64];
} AVIFILEINFOW, *LPAVIFILEINFOW, *PAVIFILEINFOW;
typedef struct _AVIFILEINFOA {
	DWORD dwMaxBytesPerSec;
	DWORD dwFlags;
	DWORD dwCaps;
	DWORD dwStreams;
	DWORD dwSuggestedBufferSize;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwScale;
	DWORD dwRate;
	DWORD dwLength;
	DWORD dwEditCount;
	CHAR szFileType[64];
} AVIFILEINFOA, *LPAVIFILEINFOA, *PAVIFILEINFOA;
typedef struct _AVICOMPRESSOPTIONS {
	DWORD fccType;
	DWORD fccHandler;
	DWORD dwKeyFrameEvery;
	DWORD dwQuality;
	DWORD dwBytesPerSecond;
	DWORD dwFlags;
	LPVOID lpFormat;
	DWORD cbFormat;
	LPVOID lpParms;
	DWORD cbParms;
	DWORD dwInterleaveEvery;
} AVICOMPRESSOPTIONS, *LPAVICOMPRESSOPTIONS,*PAVICOMPRESSOPTIONS;
typedef struct _CAPDRIVERCAPS {
	UINT wDeviceIndex;
	BOOL fHasOverlay;
	BOOL fHasDlgVideoSource;
	BOOL fHasDlgVideoFormat;
	BOOL fHasDlgVideoDisplay;
	BOOL fCaptureInitialized;
	BOOL fDriverSuppliesPalettes;
	HANDLE hVideoIn;
	HANDLE hVideoOut;
	HANDLE hVideoExtIn;
	HANDLE hVideoExtOut;
} CAPDRIVERCAPS, *LPCAPDRIVERCAPS;
typedef struct _CAPINFOCHUNK {
	FOURCC fccInfoID;
	LPVOID lpData;
	LONG cbData;
} CAPINFOCHUNK, *LPCAPINFOCHUNK;
typedef struct _CAPSTATUS {
	UINT uiImageWidth;
	UINT uiImageHeight;
	BOOL fLiveWindow;
	BOOL fOverlayWindow;
	BOOL fScale;
	POINT ptScroll;
	BOOL fUsingDefaultPalette;
	BOOL fAudioHardware;
	BOOL fCapFileExists;
	DWORD dwCurrentVideoFrame;
	DWORD dwCurrentVideoFramesDropped;
	DWORD dwCurrentWaveSamples;
	DWORD dwCurrentTimeElapsedMS;
	HPALETTE hPalCurrent;
	BOOL fCapturingNow;
	DWORD dwReturn;
	UINT wNumVideoAllocated;
	UINT wNumAudioAllocated;
} CAPSTATUS, *LPCAPSTATUS;
typedef struct _CAPTUREPARMS {
	DWORD dwRequestMicroSecPerFrame;
	BOOL fMakeUserHitOKToCapture;
	UINT wPercentDropForError;
	BOOL fYield;
	DWORD dwIndexSize;
	UINT wChunkGranularity;
	BOOL fUsingDOSMemory;
	UINT wNumVideoRequested;
	BOOL fCaptureAudio;
	UINT wNumAudioRequested;
	UINT vKeyAbort;
	BOOL fAbortLeftMouse;
	BOOL fAbortRightMouse;
	BOOL fLimitEnabled;
	UINT wTimeLimit;
	BOOL fMCIControl;
	BOOL fStepMCIDevice;
	DWORD dwMCIStartTime;
	DWORD dwMCIStopTime;
	BOOL fStepCaptureAt2x;
	UINT wStepCaptureAverageFrames;
	DWORD dwAudioBufferSize;
	BOOL fDisableWriteCache;
	UINT AVStreamMaster;
} CAPTUREPARMS, *LPCAPTUREPARMS;

typedef struct videohdr_tag {
	LPBYTE lpData;
	DWORD dwBufferLength;
	DWORD dwBytesUsed;
	DWORD dwTimeCaptured;
	DWORD dwUser;
	DWORD dwFlags;
	DWORD_PTR dwReserved[4];
} VIDEOHDR, *LPVIDEOHDR;

#if !defined (_OBJC_NO_COM)
#define DEFINE_AVIGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)
DEFINE_AVIGUID(IID_IAVIFile,0x00020020,0,0);
DEFINE_AVIGUID(IID_IAVIStream,0x00020021,0,0);
DEFINE_AVIGUID(IID_IAVIStreaming,0x00020022,0,0);
DEFINE_AVIGUID(IID_IGetFrame,0x00020023,0,0);
DEFINE_AVIGUID(IID_IAVIEditStream,0x00020024,0,0);
DEFINE_AVIGUID(CLSID_AVIFile,0x00020000,0,0);

#define INTERFACE IAVIStream
DECLARE_INTERFACE_(IAVIStream, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD(Create)(THIS_ LPARAM,LPARAM) PURE;
	STDMETHOD(Info)(THIS_ AVISTREAMINFOW*,LONG) PURE;
	STDMETHOD_(LONG,FindSample)(THIS_ LONG,LONG) PURE;
	STDMETHOD(ReadFormat)(THIS_ LONG,LPVOID,LONG*) PURE;
	STDMETHOD(SetFormat)(THIS_ LONG,LPVOID,LONG) PURE;
	STDMETHOD(Read)(THIS_ LONG,LONG,LPVOID,LONG,LONG*,LONG*) PURE;
	STDMETHOD(Write)(THIS_ LONG,LONG,LPVOID,LONG,DWORD,LONG*,LONG*) PURE;
	STDMETHOD(Delete)(THIS_ LONG,LONG) PURE;
	STDMETHOD(ReadData)(THIS_ DWORD,LPVOID,LONG*) PURE;
	STDMETHOD(WriteData)(THIS_ DWORD,LPVOID,LONG) PURE;
	STDMETHOD(SetInfo)(THIS_ AVISTREAMINFOW*,LONG) PURE;
};
#undef INTERFACE
typedef IAVIStream *PAVISTREAM;

#define INTERFACE IAVIStreaming
DECLARE_INTERFACE_(IAVIStreaming, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD(Begin)(THIS_ LONG,LONG,LONG) PURE;
	STDMETHOD(End)(THIS) PURE;
};
#undef INTERFACE
typedef IAVIStreaming *PAVISTREAMING;

#define INTERFACE IAVIEditStream
DECLARE_INTERFACE_(IAVIEditStream, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD(Cut)(THIS_ LONG*,LONG*,PAVISTREAM*) PURE;
	STDMETHOD(Copy)(THIS_ LONG*,LONG*,PAVISTREAM*) PURE;
	STDMETHOD(Paste)(THIS_ LONG*,LONG*,PAVISTREAM,LONG,LONG) PURE;
	STDMETHOD(Clone)(THIS_ PAVISTREAM*) PURE;
	STDMETHOD(SetInfo)(THIS_ LPAVISTREAMINFOW,LONG) PURE;
};
#undef INTERFACE
typedef IAVIEditStream *PAVIEDITSTREAM;

#define INTERFACE IAVIFile
DECLARE_INTERFACE_(IAVIFile, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD(Info)(THIS_ AVIFILEINFOW*,LONG) PURE;
	STDMETHOD(GetStream)(THIS_ PAVISTREAM*,DWORD,LONG) PURE;
	STDMETHOD(CreateStream)(THIS_ PAVISTREAM*,AVISTREAMINFOW*) PURE;
	STDMETHOD(WriteData)(THIS_ DWORD,LPVOID,LONG) PURE;
	STDMETHOD(ReadData)(THIS_ DWORD,LPVOID,LONG*) PURE;
	STDMETHOD(EndRecord)(THIS) PURE;
	STDMETHOD(DeleteStream)(THIS_ DWORD,LONG) PURE;
};
#undef INTERFACE
typedef IAVIFile *PAVIFILE;

#define INTERFACE IGetFrame
DECLARE_INTERFACE_(IGetFrame, IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD_(LPVOID,GetFrame)(THIS_ LONG) PURE;
	STDMETHOD(Begin)(THIS_ LONG,LONG,LONG) PURE;
	STDMETHOD(End)(THIS) PURE;
	STDMETHOD(SetFormat)(THIS_ LPBITMAPINFOHEADER,LPVOID,INT,INT,INT,INT) PURE;
};
#undef INTERFACE
typedef IGetFrame *PGETFRAME;
#endif /* !defined (_OBJC_NO_COM) */

DWORD VFWAPI VideoForWindowsVersion(VOID);
LONG VFWAPI InitVFW(VOID);
LONG VFWAPI TermVFW(VOID);
DWORD VFWAPIV ICCompress(HIC,DWORD,LPBITMAPINFOHEADER,LPVOID,LPBITMAPINFOHEADER,LPVOID,LPDWORD,LPDWORD,LONG,DWORD,DWORD,LPBITMAPINFOHEADER,LPVOID);
DWORD VFWAPIV ICDecompress(HIC,DWORD,LPBITMAPINFOHEADER,LPVOID,LPBITMAPINFOHEADER,LPVOID);
LRESULT	VFWAPI ICSendMessage(HIC,UINT,DWORD,DWORD);
HANDLE VFWAPI ICImageCompress(HIC,UINT,LPBITMAPINFO,LPVOID,LPBITMAPINFO,LONG,LONG*);
HANDLE VFWAPI ICImageDecompress(HIC,UINT,LPBITMAPINFO,LPVOID,LPBITMAPINFO);
BOOL VFWAPI ICInfo(DWORD,DWORD,ICINFO*);
BOOL VFWAPI ICInstall(DWORD,DWORD,LPARAM,LPSTR,UINT);
BOOL VFWAPI ICRemove(DWORD,DWORD,UINT);
LRESULT VFWAPI ICGetInfo(HIC,ICINFO*,DWORD);
HIC VFWAPI ICOpen(DWORD,DWORD,UINT);
HIC VFWAPI ICOpenFunction(DWORD,DWORD,UINT,FARPROC);
LRESULT VFWAPI ICClose(HIC hic);
HIC VFWAPI ICLocate(DWORD,DWORD,LPBITMAPINFOHEADER,LPBITMAPINFOHEADER,WORD);
HIC VFWAPI ICGetDisplayFormat(HIC,LPBITMAPINFOHEADER,LPBITMAPINFOHEADER,INT,INT,INT);
DWORD VFWAPIV ICDrawBegin(HIC,DWORD,HPALETTE,HWND,HDC,INT,INT,INT,INT,LPBITMAPINFOHEADER,INT,INT,INT,INT,DWORD,DWORD);
DWORD VFWAPIV ICDraw(HIC,DWORD,LPVOID,LPVOID,DWORD,LONG);
BOOL VFWAPI ICCompressorChoose(HWND,UINT,LPVOID,LPVOID,PCOMPVARS,LPSTR);
BOOL VFWAPI ICSeqCompressFrameStart(PCOMPVARS,LPBITMAPINFO);
void VFWAPI ICSeqCompressFrameEnd(PCOMPVARS);
LPVOID VFWAPI ICSeqCompressFrame(PCOMPVARS,UINT,LPVOID,BOOL*,LONG*);
void VFWAPI ICCompressorFree(PCOMPVARS);
#if !defined (_OBJC_NO_COM)
ULONG WINAPI AVIStreamAddRef(PAVISTREAM);
ULONG WINAPI AVIStreamRelease(PAVISTREAM);
HRESULT WINAPI AVIStreamCreate(PAVISTREAM*,LONG,LONG,CLSID*);
HRESULT WINAPI AVIStreamInfoA(PAVISTREAM,AVISTREAMINFOA*,LONG);
HRESULT WINAPI AVIStreamInfoW(PAVISTREAM,AVISTREAMINFOW*,LONG);
HRESULT WINAPI AVIStreamFindSample(PAVISTREAM,LONG,DWORD);
HRESULT WINAPI AVIStreamReadFormat(PAVISTREAM,LONG,LPVOID,LONG*);
HRESULT WINAPI AVIStreamSetFormat(PAVISTREAM,LONG,LPVOID,LONG);
HRESULT WINAPI AVIStreamRead(PAVISTREAM,LONG,LONG,LPVOID,LONG,LONG*,LONG*);
HRESULT WINAPI AVIStreamWrite(PAVISTREAM,LONG,LONG,LPVOID,LONG,DWORD,LONG*,LONG*);
HRESULT WINAPI AVIStreamReadData(PAVISTREAM,DWORD,LPVOID,LONG*);
HRESULT WINAPI AVIStreamWriteData(PAVISTREAM,DWORD,LPVOID,LONG);
PGETFRAME WINAPI AVIStreamGetFrameOpen(PAVISTREAM,LPBITMAPINFOHEADER);
LPVOID WINAPI AVIStreamGetFrame(PGETFRAME,LONG);
HRESULT WINAPI AVIStreamGetFrameClose(PGETFRAME);
HRESULT WINAPI AVIMakeCompressedStream(PAVISTREAM*,PAVISTREAM,AVICOMPRESSOPTIONS*,CLSID*);
HRESULT WINAPI AVIMakeFileFromStreams(PAVIFILE*,INT,PAVISTREAM*);
HRESULT WINAPI AVIStreamOpenFromFileA(PAVISTREAM*,LPCSTR,DWORD,LONG,UINT,CLSID*);
HRESULT WINAPI AVIStreamOpenFromFileW(PAVISTREAM*,LPCWSTR,DWORD,LONG,UINT,CLSID*);
HRESULT WINAPI AVIBuildFilterA(LPSTR,LONG,BOOL);
HRESULT WINAPI AVIBuildFilterW(LPWSTR,LONG,BOOL);
BOOL WINAPI AVISaveOptions(HWND,UINT,INT,PAVISTREAM*,LPAVICOMPRESSOPTIONS*);
HRESULT WINAPI AVISaveOptionsFree(INT,LPAVICOMPRESSOPTIONS*);
HRESULT WINAPI AVISaveVA(LPCSTR,CLSID*,AVISAVECALLBACK,INT,PAVISTREAM*,LPAVICOMPRESSOPTIONS*);
HRESULT WINAPI AVISaveVW(LPCWSTR,CLSID*,AVISAVECALLBACK,INT,PAVISTREAM*,LPAVICOMPRESSOPTIONS*);
LONG WINAPI AVIStreamStart(PAVISTREAM);
LONG WINAPI AVIStreamLength(PAVISTREAM);
LONG WINAPI AVIStreamSampleToTime(PAVISTREAM,LONG);
LONG WINAPI AVIStreamTimeToSample(PAVISTREAM,LONG);
HRESULT WINAPI CreateEditableStream(PAVISTREAM*,PAVISTREAM);
HRESULT WINAPI EditStreamClone(PAVISTREAM,PAVISTREAM*);
HRESULT WINAPI EditStreamCopy(PAVISTREAM,LONG*,LONG*,PAVISTREAM*);
HRESULT WINAPI EditStreamCut(PAVISTREAM,LONG*,LONG*,PAVISTREAM*);
HRESULT WINAPI EditStreamPaste(PAVISTREAM,LONG*,LONG*,PAVISTREAM,LONG,LONG);
HRESULT WINAPI EditStreamSetInfoA(PAVISTREAM,LPAVISTREAMINFOA,LONG);
HRESULT WINAPI EditStreamSetInfoW(PAVISTREAM,LPAVISTREAMINFOW,LONG);
HRESULT WINAPI EditStreamSetNameA(PAVISTREAM,LPCSTR);
HRESULT WINAPI EditStreamSetNameW(PAVISTREAM,LPCWSTR);
HRESULT WINAPI CreateEditableStream(PAVISTREAM*,PAVISTREAM);
HRESULT WINAPI EditStreamClone(PAVISTREAM,PAVISTREAM*);
HRESULT WINAPI EditStreamCopy(PAVISTREAM,LONG*,LONG*,PAVISTREAM*);
HRESULT WINAPI EditStreamCut(PAVISTREAM,LONG*,LONG*,PAVISTREAM*);
HRESULT WINAPI EditStreamPaste(PAVISTREAM,LONG*,LONG*,PAVISTREAM,LONG,LONG);
HRESULT WINAPI EditStreamSetInfoA(PAVISTREAM,LPAVISTREAMINFOA,LONG);
HRESULT WINAPI EditStreamSetInfoW(PAVISTREAM,LPAVISTREAMINFOW,LONG);
HRESULT WINAPI EditStreamSetNameA(PAVISTREAM,LPCSTR);
HRESULT WINAPI EditStreamSetNameW(PAVISTREAM,LPCWSTR);
VOID WINAPI AVIFileInit(void);
VOID WINAPI AVIFileExit(void);
HRESULT WINAPI AVIFileOpenA(PAVIFILE*,LPCSTR,UINT,LPCLSID);
HRESULT WINAPI AVIFileOpenW(PAVIFILE*,LPCWSTR,UINT,LPCLSID);
ULONG WINAPI AVIFileAddRef(PAVIFILE);
ULONG WINAPI AVIFileRelease(PAVIFILE);
HRESULT WINAPI AVIFileInfoA(PAVIFILE,PAVIFILEINFOA,LONG);
HRESULT WINAPI AVIFileInfoW(PAVIFILE,PAVIFILEINFOW,LONG);
HRESULT WINAPI AVIFileGetStream(PAVIFILE,PAVISTREAM*,DWORD,LONG);
HRESULT WINAPI AVIFileCreateStreamA(PAVIFILE,PAVISTREAM*,AVISTREAMINFOA*);
HRESULT WINAPI AVIFileCreateStreamW(PAVIFILE,PAVISTREAM*,AVISTREAMINFOW*);
HRESULT WINAPI AVIFileWriteData(PAVIFILE,DWORD,LPVOID,LONG);
HRESULT WINAPI AVIFileReadData(PAVIFILE,DWORD,LPVOID,LPLONG);
HRESULT WINAPI AVIFileEndRecord(PAVIFILE);
HRESULT WINAPI AVIClearClipboard(VOID);
HRESULT WINAPI AVIGetFromClipboard(PAVIFILE*);
HRESULT WINAPI AVIPutFileOnClipboard(PAVIFILE);
#endif /* _OBJC_NO_COM */
#ifdef OFN_READONLY
BOOL WINAPI GetOpenFileNamePreviewA(LPOPENFILENAMEA);
BOOL WINAPI GetOpenFileNamePreviewW(LPOPENFILENAMEW);
BOOL WINAPI GetSaveFileNamePreviewA(LPOPENFILENAMEA);
BOOL WINAPI GetSaveFileNamePreviewW(LPOPENFILENAMEW);
#endif
HWND VFWAPIV MCIWndCreateA(HWND,HINSTANCE,DWORD,LPCSTR);
HWND VFWAPIV MCIWndCreateW(HWND,HINSTANCE,DWORD,LPCWSTR);
HDRAWDIB VFWAPI DrawDibOpen(VOID);
UINT VFWAPI DrawDibRealize(HDRAWDIB,HDC,BOOL);
BOOL VFWAPI DrawDibBegin(HDRAWDIB,HDC,INT,INT,LPBITMAPINFOHEADER,INT,INT,UINT);
BOOL VFWAPI DrawDibDraw(HDRAWDIB,HDC,INT,INT,INT,INT,LPBITMAPINFOHEADER,LPVOID,INT,INT,INT,INT,UINT);
BOOL VFWAPI DrawDibSetPalette(HDRAWDIB,HPALETTE);
HPALETTE VFWAPI DrawDibGetPalette(HDRAWDIB);
BOOL VFWAPI DrawDibChangePalette(HDRAWDIB,int,int,LPPALETTEENTRY);
LPVOID VFWAPI DrawDibGetBuffer(HDRAWDIB,LPBITMAPINFOHEADER,DWORD,DWORD);
BOOL VFWAPI DrawDibStart(HDRAWDIB,DWORD);
BOOL VFWAPI DrawDibStop(HDRAWDIB);
BOOL VFWAPI DrawDibEnd(HDRAWDIB);
BOOL VFWAPI DrawDibClose(HDRAWDIB);
DWORD VFWAPI DrawDibProfileDisplay(LPBITMAPINFOHEADER);

#define ICCompressGetFormat(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_COMPRESS_GET_FORMAT,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICCompressGetFormatSize(hic,lpbi) ICCompressGetFormat(hic,lpbi,NULL)
#define ICCompressBegin(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_COMPRESS_BEGIN,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICCompressGetSize(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_COMPRESS_GET_SIZE,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICCompressQuery(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_COMPRESS_QUERY,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICCompressEnd(hic) ICSendMessage(hic,ICM_COMPRESS_END,0,0)
#define ICQueryAbout(hic) (ICSendMessage(hic,ICM_ABOUT,(DWORD)-1,ICMF_ABOUT_QUERY)==ICERR_OK)
#define ICAbout(hic,hwnd) ICSendMessage(hic,ICM_ABOUT,(DWORD)(hwnd),0)
#define ICQueryConfigure(hic) (ICSendMessage(hic,ICM_CONFIGURE,(DWORD)-1,ICMF_CONFIGURE_QUERY)==ICERR_OK)
#define ICConfigure(hic,hwnd) ICSendMessage(hic,ICM_CONFIGURE,(DWORD)(hwnd),0)
#define ICDecompressBegin(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_DECOMPRESS_BEGIN,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICDecompressQuery(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_DECOMPRESS_QUERY,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICDecompressGetFormat(hic,lpbiInput,lpbiOutput) (LONG)ICSendMessage(hic,ICM_DECOMPRESS_GET_FORMAT,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICDecompressGetFormatSize(hic,lpbi) ICDecompressGetFormat(hic, lpbi, NULL)
#define ICDecompressGetPalette(hic,lpbiInput,lpbiOutput) ICSendMessage(hic,ICM_DECOMPRESS_GET_PALETTE,(DWORD)(lpbiInput),(DWORD)(lpbiOutput))
#define ICDecompressSetPalette(hic,lpbiPalette) ICSendMessage(hic,ICM_DECOMPRESS_SET_PALETTE,(DWORD)(lpbiPalette),0)
#define ICDecompressEnd(hic) ICSendMessage(hic,ICM_DECOMPRESS_END,0,0)
#define ICDecompressExEnd(hic) ICSendMessage(hic,ICM_DECOMPRESSEX_END,0,0)
#define ICDecompressOpen(fccType,fccHandler,lpbiIn,lpbiOut) ICLocate(fccType,fccHandler,lpbiIn,lpbiOut,ICMODE_DECOMPRESS)
#define ICDrawOpen(fccType,fccHandler,lpbiIn) ICLocate(fccType,fccHandler,lpbiIn,NULL,ICMODE_DRAW)
#define ICGetState(hic,pv,cb) ICSendMessage(hic,ICM_GETSTATE,(DWORD)(pv),(DWORD)(cb))
#define ICSetState(hic,pv,cb) ICSendMessage(hic,ICM_SETSTATE,(DWORD)(pv),(DWORD)(cb))
#define ICGetStateSize(hic) ICGetState(hic,NULL,0)
#define ICDrawWindow(hic,prc) ICSendMessage(hic,ICM_DRAW_WINDOW,(DWORD)(prc),sizeof(RECT))
#define ICDrawQuery(hic,lpbiInput) ICSendMessage(hic,ICM_DRAW_QUERY,(DWORD)(lpbiInput),0)
#define ICDrawChangePalette(hic,lpbiInput) ICSendMessage(hic,ICM_DRAW_CHANGEPALETTE,(DWORD)(lpbiInput),0)
#define ICGetBuffersWanted(hic,lpdwBuffers) ICSendMessage(hic,ICM_GETBUFFERSWANTED,(DWORD)(lpdwBuffers),0)
#define ICDrawEnd(hic) ICSendMessage(hic,ICM_DRAW_END,0,0)
#define ICDrawStart(hic) ICSendMessage(hic,ICM_DRAW_START,0,0)
#define ICDrawStartPlay(hic,lFrom,lTo) ICSendMessage(hic,ICM_DRAW_START_PLAY,(DWORD)(lFrom),(DWORD)(lTo))
#define ICDrawStop(hic) ICSendMessage(hic,ICM_DRAW_STOP,0,0)
#define ICDrawStopPlay(hic) ICSendMessage(hic,ICM_DRAW_STOP_PLAY,0,0)
#define ICDrawGetTime(hic,lplTime) ICSendMessage(hic,ICM_DRAW_GETTIME,(DWORD)(lplTime),0)
#define ICDrawSetTime(hic,lTime) ICSendMessage(hic,ICM_DRAW_SETTIME,(DWORD)lTime,0)
#define ICDrawRealize(hic,hdc,fBackground) ICSendMessage(hic,ICM_DRAW_REALIZE,(DWORD)(hdc),(DWORD)(fBackground))
#define ICDrawFlush(hic) ICSendMessage(hic,ICM_DRAW_FLUSH,0,0)
#define ICDrawRenderBuffer(hic) ICSendMessage(hic,ICM_DRAW_RENDERBUFFER,0,0)
#define AVIFileClose(pavi) AVIFileRelease(pavi)
#define AVIStreamClose(pavi) AVIStreamRelease(pavi);
#define AVIStreamEnd(pavi) (AVIStreamStart(pavi)+AVIStreamLength(pavi))
#define AVIStreamEndTime(pavi) AVIStreamSampleToTime(pavi,AVIStreamEnd(pavi))
#define AVIStreamFormatSize(pavi,lPos,plSize) AVIStreamReadFormat(pavi,lPos,NULL,plSize)
#define AVIStreamLengthTime(pavi) AVIStreamSampleToTime(pavi,AVIStreamLength(pavi))
#define AVIStreamSampleSize(pavi,pos,psize) AVIStreamRead(pavi,pos,1,NULL,0,psize,NULL)
#define AVIStreamSampleToSample(pavi1,pavi2,samp2) AVIStreamTimeToSample(pavi1,AVIStreamSampleToTime(pavi2,samp2))
#define AVIStreamStartTime(pavi) AVIStreamSampleToTime(pavi,AVIStreamStart(pavi))
#define AVIStreamNextSample(pavi,pos) AVIStreamFindSample(pavi,pos+1,FIND_NEXT|FIND_ANY)
#define AVIStreamPrevSample(pavi,pos) AVIStreamFindSample(pavi,pos-1,FIND_PREV|FIND_ANY)
#define AVIStreamNearestSample(pavi, pos) AVIStreamFindSample(pavi,pos,FIND_PREV|FIND_ANY)
#define AVStreamNextKeyFrame(pavi,pos) AVIStreamFindSample(pavi,pos+1,FIND_NEXT|FIND_KEY)
#define AVStreamPrevKeyFrame(pavi,pos) AVIStreamFindSample(pavi,pos-1,FIND_NEXT|FIND_KEY)
#define AVIStreamNearestKeyFrame(pavi,pos) AVIStreamFindSample(pavi,pos,FIND_PREV|FIND_KEY)
#define AVIStreamIsKeyFrame(pavi, pos) (AVIStreamNearestKeyFrame(pavi,pos) == pos)
#ifdef __cplusplus
#define MCIWndSM ::SendMessage
#else
#define MCIWndSM SendMessage
#endif
#define MCIWndCanPlay(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_PLAY,0,0)
#define MCIWndCanRecord(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_RECORD,0,0)
#define MCIWndCanSave(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_SAVE,0,0)
#define MCIWndCanWindow(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_WINDOW,0,0)
#define MCIWndCanEject(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_EJECT,0,0)
#define MCIWndCanConfig(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_CAN_CONFIG,0,0)
#define MCIWndPaletteKick(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_PALETTEKICK,0,0)
#define MCIWndSave(hWnd,szFile) (LONG)MCIWndSM(hWnd,MCI_SAVE,0,(LPARAM)(LPVOID)(szFile))
#define MCIWndSaveDialog(hWnd) MCIWndSave(hWnd,-1)
#define MCIWndNew(hWnd,lp) (LONG)MCIWndSM(hWnd,MCIWNDM_NEW,0,(LPARAM)(LPVOID)(lp))
#define MCIWndRecord(hWnd) (LONG)MCIWndSM(hWnd,MCI_RECORD,0,0)
#define MCIWndOpen(hWnd,sz,f) (LONG)MCIWndSM(hWnd,MCIWNDM_OPEN,(WPARAM)(UINT)(f),(LPARAM)(LPVOID)(sz))
#define MCIWndOpenDialog(hWnd) MCIWndOpen(hWnd,-1,0)
#define MCIWndClose(hWnd) (LONG)MCIWndSM(hWnd,MCI_CLOSE,0,0)
#define MCIWndPlay(hWnd) (LONG)MCIWndSM(hWnd,MCI_PLAY,0,0)
#define MCIWndStop(hWnd) (LONG)MCIWndSM(hWnd,MCI_STOP,0,0)
#define MCIWndPause(hWnd) (LONG)MCIWndSM(hWnd,MCI_PAUSE,0,0)
#define MCIWndResume(hWnd) (LONG)MCIWndSM(hWnd,MCI_RESUME,0,0)
#define MCIWndSeek(hWnd,lPos) (LONG)MCIWndSM(hWnd,MCI_SEEK,0,(LPARAM)(LONG)(lPos))
#define MCIWndEject(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_EJECT,0,0)
#define MCIWndHome(hWnd) MCIWndSeek(hWnd,MCIWND_START)
#define MCIWndEnd(hWnd) MCIWndSeek(hWnd,MCIWND_END)
#define MCIWndGetSource(hWnd,prc) (LONG)MCIWndSM(hWnd,MCIWNDM_GET_SOURCE,0,(LPARAM)(LPRECT)(prc))
#define MCIWndPutSource(hWnd,prc) (LONG)MCIWndSM(hWnd,MCIWNDM_PUT_SOURCE,0,(LPARAM)(LPRECT)(prc))
#define MCIWndGetDest(hWnd,prc) (LONG)MCIWndSM(hWnd,MCIWNDM_GET_DEST,0,(LPARAM)(LPRECT)(prc))
#define MCIWndPutDest(hWnd,prc) (LONG)MCIWndSM(hWnd,MCIWNDM_PUT_DEST,0,(LPARAM)(LPRECT)(prc))
#define MCIWndPlayReverse(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_PLAYREVERSE,0,0)
#define MCIWndPlayFrom(hWnd,lPos) (LONG)MCIWndSM(hWnd,MCIWNDM_PLAYFROM,0,(LPARAM)(LONG)(lPos))
#define MCIWndPlayTo(hWnd,lPos) (LONG)MCIWndSM(hWnd,MCIWNDM_PLAYTO,  0,(LPARAM)(LONG)(lPos))
#define MCIWndPlayFromTo(hWnd,lStart,lEnd) (MCIWndSeek(hWnd,lStart),MCIWndPlayTo(hWnd,lEnd))
#define MCIWndGetDeviceID(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETDEVICEID,0,0)
#define MCIWndGetAlias(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETALIAS,0,0)
#define MCIWndGetMode(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETMODE,(WPARAM)(UINT)(len),(LPARAM)(LPTSTR)(lp))
#define MCIWndGetPosition(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETPOSITION,0,0)
#define MCIWndGetPositionString(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETPOSITION,(WPARAM)(UINT)(len),(LPARAM)(LPTSTR)(lp))
#define MCIWndGetStart(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETSTART,0,0)
#define MCIWndGetLength(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETLENGTH,0,0)
#define MCIWndGetEnd(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETEND,0,0)
#define MCIWndStep(hWnd,n) (LONG)MCIWndSM(hWnd,MCI_STEP,0,(LPARAM)(long)(n))
#define MCIWndDestroy(hWnd) (VOID)MCIWndSM(hWnd,WM_CLOSE,0,0)
#define MCIWndSetZoom(hWnd,iZoom) (VOID)MCIWndSM(hWnd,MCIWNDM_SETZOOM,0,(LPARAM)(UINT)(iZoom))
#define MCIWndGetZoom(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETZOOM,0,0)
#define MCIWndSetVolume(hWnd,iVol) (LONG)MCIWndSM(hWnd,MCIWNDM_SETVOLUME,0,(LPARAM)(UINT)(iVol))
#define MCIWndGetVolume(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETVOLUME,0,0)
#define MCIWndSetSpeed(hWnd,iSpeed) (LONG)MCIWndSM(hWnd,MCIWNDM_SETSPEED,0,(LPARAM)(UINT)(iSpeed))
#define MCIWndGetSpeed(hWnd) (LONG)MCIWndSM(hWnd,MCIWNDM_GETSPEED,0,0)
#define MCIWndSetTimeFormat(hWnd,lp) (LONG)MCIWndSM(hWnd,MCIWNDM_SETTIMEFORMAT,0,(LPARAM)(LPTSTR)(lp))
#define MCIWndGetTimeFormat(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETTIMEFORMAT,(WPARAM)(UINT)(len),(LPARAM)(LPTSTR)(lp))
#define MCIWndValidateMedia(hWnd) (VOID)MCIWndSM(hWnd,MCIWNDM_VALIDATEMEDIA,0,0)
#define MCIWndSetRepeat(hWnd,f) (void)MCIWndSM(hWnd,MCIWNDM_SETREPEAT,0,(LPARAM)(BOOL)(f))
#define MCIWndGetRepeat(hWnd) (BOOL)MCIWndSM(hWnd,MCIWNDM_GETREPEAT,0,0)
#define MCIWndUseFrames(hWnd) MCIWndSetTimeFormat(hWnd,TEXT("frames"))
#define MCIWndUseTime(hWnd) MCIWndSetTimeFormat(hWnd,TEXT("ms"))
#define MCIWndSetActiveTimer(hWnd,active) (VOID)MCIWndSM(hWnd,MCIWNDM_SETACTIVETIMER,(WPARAM)(UINT)(active),0L)
#define MCIWndSetInactiveTimer(hWnd,inactive) (VOID)MCIWndSM(hWnd,MCIWNDM_SETINACTIVETIMER,(WPARAM)(UINT)(inactive),0L)
#define MCIWndSetTimers(hWnd,active,inactive) (VOID)MCIWndSM(hWnd,MCIWNDM_SETTIMERS,(WPARAM)(UINT)(active),(LPARAM)(UINT)(inactive))
#define MCIWndGetActiveTimer(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETACTIVETIMER,0,0L);
#define MCIWndGetInactiveTimer(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETINACTIVETIMER,0,0L);
#define MCIWndRealize(hWnd,fBkgnd) (LONG)MCIWndSM(hWnd,MCIWNDM_REALIZE,(WPARAM)(BOOL)(fBkgnd),0)
#define MCIWndSendString(hWnd,sz) (LONG)MCIWndSM(hWnd,MCIWNDM_SENDSTRING,0,(LPARAM)(LPTSTR)(sz))
#define MCIWndReturnString(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_RETURNSTRING,(WPARAM)(UINT)(len),(LPARAM)(LPVOID)(lp))
#define MCIWndGetError(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETERROR,(WPARAM)(UINT)(len),(LPARAM)(LPVOID)(lp))
#define MCIWndGetPalette(hWnd) (HPALETTE)MCIWndSM(hWnd,MCIWNDM_GETPALETTE,0,0)
#define MCIWndSetPalette(hWnd,hpal) (LONG)MCIWndSM(hWnd,MCIWNDM_SETPALETTE,(WPARAM)(HPALETTE)(hpal),0)
#define MCIWndGetFileName(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETFILENAME,(WPARAM)(UINT)(len),(LPARAM)(LPVOID)(lp))
#define MCIWndGetDevice(hWnd,lp,len) (LONG)MCIWndSM(hWnd,MCIWNDM_GETDEVICE,(WPARAM)(UINT)(len),(LPARAM)(LPVOID)(lp))
#define MCIWndGetStyles(hWnd) (UINT)MCIWndSM(hWnd,MCIWNDM_GETSTYLES,0,0L)
#define MCIWndChangeStyles(hWnd,mask,value) (LONG)MCIWndSM(hWnd,MCIWNDM_CHANGESTYLES,(WPARAM)(UINT)(mask),(LPARAM)(LONG)(value))
#define MCIWndOpenInterface(hWnd,pUnk) (LONG)MCIWndSM(hWnd,MCIWNDM_OPENINTERFACE,0,(LPARAM)(LPUNKNOWN)(pUnk))
#define MCIWndSetOwner(hWnd,hWndP) (LONG)MCIWndSM(hWnd,MCIWNDM_SETOWNER,(WPARAM)(hWndP),0)
#define DrawDibUpdate(hdd,hdc,x,y) DrawDibDraw(hdd,hdc,x,y,0,0,NULL,NULL,0,0,0,0,DDF_UPDATE)
static __inline DWORD
ICGetDefaultQuality(HIC hic)
{
   DWORD dwICValue;
   ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD));
   return dwICValue;
}
static __inline DWORD
ICGetDefaultKeyFrameRate(HIC hic)
{
   DWORD dwICValue;
   ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD)(LPVOID)&dwICValue, sizeof(DWORD));
   return dwICValue;
}
static __inline LRESULT
ICDrawSuggestFormat(HIC hic,LPBITMAPINFOHEADER lpbiIn,LPBITMAPINFOHEADER lpbiOut,INT dxSrc,INT dySrc,INT dxDst,INT dyDst,HIC hicDecomp)
{
	ICDRAWSUGGEST ic;
	ic.lpbiIn = lpbiIn;
	ic.lpbiSuggest = lpbiOut;
	ic.dxSrc = dxSrc;
	ic.dySrc = dySrc;
	ic.dxDst = dxDst;
	ic.dyDst = dyDst;
	ic.hicDecompressor = hicDecomp;
	return ICSendMessage(hic,ICM_DRAW_SUGGESTFORMAT,(DWORD)&ic,sizeof(ic));
}
static __inline LRESULT
ICSetStatusProc(HIC hic,DWORD dwFlags,LRESULT lParam,LONG (CALLBACK *fpfnStatus)(LPARAM,UINT,LONG))
{
	ICSETSTATUSPROC ic;
	ic.dwFlags = dwFlags;
	ic.lParam = lParam;
	ic.Status = fpfnStatus;
	return ICSendMessage(hic,ICM_SET_STATUS_PROC,(DWORD)&ic,sizeof(ic));
}
static __inline LRESULT
ICDecompressEx(HIC hic,DWORD dwFlags,LPBITMAPINFOHEADER lpbiSrc,LPVOID lpSrc,INT xSrc,INT ySrc,INT dxSrc,INT dySrc,LPBITMAPINFOHEADER lpbiDst,LPVOID lpDst,INT xDst,INT yDst,INT dxDst,INT dyDst)
{
	ICDECOMPRESSEX ic;
	ic.dwFlags = dwFlags;
	ic.lpbiSrc = lpbiSrc;
	ic.lpSrc = lpSrc;
	ic.xSrc = xSrc;
	ic.ySrc = ySrc;
	ic.dxSrc = dxSrc;
	ic.dySrc = dySrc;
	ic.lpbiDst = lpbiDst;
	ic.lpDst = lpDst;
	ic.xDst = xDst;
	ic.yDst = yDst;
	ic.dxDst = dxDst;
	ic.dyDst = dyDst;
	return ICSendMessage(hic,ICM_DECOMPRESSEX,(DWORD)&ic,sizeof(ic));
}
static __inline LRESULT
ICDecompressExBegin(HIC hic,DWORD dwFlags,LPBITMAPINFOHEADER lpbiSrc,LPVOID lpSrc,INT xSrc,INT ySrc,INT dxSrc,INT dySrc,LPBITMAPINFOHEADER lpbiDst,LPVOID lpDst,INT xDst,INT yDst,INT dxDst,INT dyDst)
{
	ICDECOMPRESSEX ic;
	ic.dwFlags = dwFlags;
	ic.lpbiSrc = lpbiSrc;
	ic.lpSrc = lpSrc;
	ic.xSrc = xSrc;
	ic.ySrc = ySrc;
	ic.dxSrc = dxSrc;
	ic.dySrc = dySrc;
	ic.lpbiDst = lpbiDst;
	ic.lpDst = lpDst;
	ic.xDst = xDst;
	ic.yDst = yDst;
	ic.dxDst = dxDst;
	ic.dyDst = dyDst;
	return ICSendMessage(hic,ICM_DECOMPRESSEX_BEGIN,(DWORD)&ic,sizeof(ic));
}
static __inline LRESULT
ICDecompressExQuery(HIC hic,DWORD dwFlags,LPBITMAPINFOHEADER lpbiSrc,LPVOID lpSrc,INT xSrc,INT ySrc,INT dxSrc,INT dySrc,LPBITMAPINFOHEADER lpbiDst,LPVOID lpDst,INT xDst,INT yDst,INT dxDst,INT dyDst)
{
	ICDECOMPRESSEX ic;
	ic.dwFlags = dwFlags;
	ic.lpbiSrc = lpbiSrc;
	ic.lpSrc = lpSrc;
	ic.xSrc = xSrc;
	ic.ySrc = ySrc;
	ic.dxSrc = dxSrc;
	ic.dySrc = dySrc;
	ic.lpbiDst = lpbiDst;
	ic.lpDst = lpDst;
	ic.xDst = xDst;
	ic.yDst = yDst;
	ic.dxDst = dxDst;
	ic.dyDst = dyDst;
	return ICSendMessage(hic,ICM_DECOMPRESSEX_QUERY,(DWORD)&ic,sizeof(ic));
}

#define WM_CAP_SET_CALLBACK_ERRORA      (WM_USER + 2)
#define WM_CAP_SET_CALLBACK_ERRORW      (WM_CAP_SET_CALLBACK_ERRORA + 100)
#define WM_CAP_SET_CALLBACK_STATUS      (WM_USER + 3)
#define WM_CAP_SET_CALLBACK_YIELD       (WM_USER + 4)
#define WM_CAP_SET_CALLBACK_FRAMEA      (WM_USER + 5)
#define WM_CAP_SET_CALLBACK_FRAMEW      (WM_CAP_SET_CALLBACK_FRAMEA + 100)
#define WM_CAP_SET_CALLBACK_VIDEOSTREAM (WM_USER + 6)
#define WM_CAP_SET_CALLBACK_WAVESTREAM  (WM_USER + 7)
#define WM_CAP_GET_USER_DATA            (WM_USER + 8)
#define WM_CAP_SET_USER_DATA            (WM_USER + 9)
#define WM_CAP_DRIVER_CONNECT           (WM_USER + 10)
#define WM_CAP_DRIVER_DISCONNECT        (WM_USER + 11)
#define WM_CAP_DRIVER_GET_NAMEA         (WM_USER + 12)
#define WM_CAP_DRIVER_GET_NAMEW         (WM_CAP_DRIVER_GET_NAMEA + 100)
#define WM_CAP_DRIVER_GET_VERSIONA      (WM_USER + 13)
#define WM_CAP_DRIVER_GET_VERSIONW      (WM_CAP_DRIVER_GET_VERSIONA + 100)
#define WM_CAP_DRIVER_GET_CAPS          (WM_USER + 14)
#define WM_CAP_FILE_SET_CAPTURE_FILEA   (WM_USER + 20)
#define WM_CAP_FILE_SET_CAPTURE_FILEW   (WM_CAP_FILE_SET_CAPTURE_FILEA + 100)
#define WM_CAP_FILE_GET_CAPTURE_FILEA   (WM_USER + 21)
#define WM_CAP_FILE_GET_CAPTURE_FILEW   (WM_CAP_FILE_GET_CAPTURE_FILEA + 100)
#define WM_CAP_FILE_ALLOCATE            (WM_USER + 22)
#define WM_CAP_FILE_SAVEASA             (WM_USER + 23)
#define WM_CAP_FILE_SAVEASW             (WM_CAP_FILE_SAVEASA + 100)
#define WM_CAP_FILE_SET_INFOCHUNK       (WM_USER + 24)
#define WM_CAP_FILE_SAVEDIBA            (WM_USER + 25)
#define WM_CAP_FILE_SAVEDIBW            (WM_CAP_FILE_SAVEDIBA + 100)
#define WM_CAP_EDIT_COPY                (WM_USER + 30)
#define WM_CAP_SET_AUDIOFORMAT          (WM_USER + 35)
#define WM_CAP_GET_AUDIOFORMAT          (WM_USER + 36)
#define WM_CAP_DLG_VIDEOFORMAT          (WM_USER + 41)
#define WM_CAP_DLG_VIDEOSOURCE          (WM_USER + 42)
#define WM_CAP_DLG_VIDEODISPLAY         (WM_USER + 43)
#define WM_CAP_GET_VIDEOFORMAT          (WM_USER + 44)
#define WM_CAP_SET_VIDEOFORMAT          (WM_USER + 45)
#define WM_CAP_DLG_VIDEOCOMPRESSION     (WM_USER + 46)
#define WM_CAP_SET_PREVIEW              (WM_USER + 50)
#define WM_CAP_SET_OVERLAY              (WM_USER + 51)
#define WM_CAP_SET_PREVIEWRATE          (WM_USER + 52)
#define WM_CAP_SET_SCALE                (WM_USER + 53)
#define WM_CAP_GET_STATUS               (WM_USER + 54)
#define WM_CAP_SET_SCROLL               (WM_USER + 55)
#define WM_CAP_GRAB_FRAME               (WM_USER + 60)
#define WM_CAP_GRAB_FRAME_NOSTOP        (WM_USER + 61)
#define WM_CAP_SEQUENCE                 (WM_USER + 62)
#define WM_CAP_SEQUENCE_NOFILE          (WM_USER + 63)
#define WM_CAP_SET_SEQUENCE_SETUP       (WM_USER + 64)
#define WM_CAP_GET_SEQUENCE_SETUP       (WM_USER + 65)
#define WM_CAP_SET_MCI_DEVICEA          (WM_USER + 66)
#define WM_CAP_SET_MCI_DEVICEW          (WM_CAP_SET_MCI_DEVICEA + 100)
#define WM_CAP_GET_MCI_DEVICEA          (WM_USER + 67)
#define WM_CAP_GET_MCI_DEVICEW          (WM_CAP_GET_MCI_DEVICEA + 100)
#define WM_CAP_STOP                     (WM_USER + 68)
#define WM_CAP_ABORT                    (WM_USER + 69)
#define WM_CAP_SINGLE_FRAME_OPEN        (WM_USER + 70)
#define WM_CAP_SINGLE_FRAME_CLOSE       (WM_USER + 71)
#define WM_CAP_SINGLE_FRAME             (WM_USER + 72)
#define WM_CAP_PAL_OPENA                (WM_USER + 80)
#define WM_CAP_PAL_OPENW                (WM_CAP_PAL_OPENA + 100)
#define WM_CAP_PAL_SAVEA                (WM_USER + 81)
#define WM_CAP_PAL_SAVEW                (WM_CAP_PAL_SAVEA + 100)
#define WM_CAP_PAL_PASTE                (WM_USER + 82)
#define WM_CAP_PAL_AUTOCREATE           (WM_USER + 83)
#define WM_CAP_PAL_MANUALCREATE         (WM_USER + 84)
#define WM_CAP_SET_CALLBACK_CAPCONTROL  (WM_USER + 85)

#ifdef UNICODE
#define WM_CAP_SET_CALLBACK_ERROR       WM_CAP_SET_CALLBACK_ERRORW
#define WM_CAP_SET_CALLBACK_FRAME       WM_CAP_SET_CALLBACK_FRAMEW
#define WM_CAP_DRIVER_GET_NAME          WM_CAP_DRIVER_GET_NAMEW
#define WM_CAP_DRIVER_GET_VERSION       WM_CAP_DRIVER_GET_VERSIONW
#define WM_CAP_FILE_SET_CAPTURE_FILE    WM_CAP_FILE_SET_CAPTURE_FILEW
#define WM_CAP_FILE_GET_CAPTURE_FILE    WM_CAP_FILE_GET_CAPTURE_FILEW
#define WM_CAP_FILE_SAVEAS              WM_CAP_FILE_SAVEASW
#define WM_CAP_FILE_SAVEDIB             WM_CAP_FILE_SAVEDIBW
#define WM_CAP_SET_MCI_DEVICE           WM_CAP_SET_MCI_DEVICEW
#define WM_CAP_GET_MCI_DEVICE           WM_CAP_GET_MCI_DEVICEW
#define WM_CAP_PAL_OPEN                 WM_CAP_PAL_OPENW
#define WM_CAP_PAL_SAVE                 WM_CAP_PAL_SAVEW
#else
#define WM_CAP_SET_CALLBACK_ERROR       WM_CAP_SET_CALLBACK_ERRORA
#define WM_CAP_SET_CALLBACK_FRAME       WM_CAP_SET_CALLBACK_FRAMEA
#define WM_CAP_DRIVER_GET_NAME          WM_CAP_DRIVER_GET_NAMEA
#define WM_CAP_DRIVER_GET_VERSION       WM_CAP_DRIVER_GET_VERSIONA
#define WM_CAP_FILE_SET_CAPTURE_FILE    WM_CAP_FILE_SET_CAPTURE_FILEA
#define WM_CAP_FILE_GET_CAPTURE_FILE    WM_CAP_FILE_GET_CAPTURE_FILEA
#define WM_CAP_FILE_SAVEAS              WM_CAP_FILE_SAVEASA
#define WM_CAP_FILE_SAVEDIB             WM_CAP_FILE_SAVEDIBA
#define WM_CAP_SET_MCI_DEVICE           WM_CAP_SET_MCI_DEVICEA
#define WM_CAP_GET_MCI_DEVICE           WM_CAP_GET_MCI_DEVICEA
#define WM_CAP_PAL_OPEN                 WM_CAP_PAL_OPENA
#define WM_CAP_PAL_SAVE                 WM_CAP_PAL_SAVEA
#endif

#define __capSendMessage(hwnd,m,w,l) (IsWindow(hwnd)?SendMessage(hwnd,m,w,l):0)

#define capSetCallbackOnError(hwnd,fpProc)          ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_ERROR,0,(LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnStatus(hwnd,fpProc)         ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_STATUS,0,(LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnYield(hwnd,fpProc)          ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_YIELD,0,(LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnFrame(hwnd,fpProc)          ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_FRAME,0,(LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnVideoStream(hwnd,fpProc)    ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_VIDEOSTREAM,0,(LPARAM)(LPVOID)(fpProc)))
#define capSetCallbackOnWaveStream(hwnd,fpProc)     ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_WAVESTREAM,0,(LPARAM)(LPVOID)(fpProc)))
#define capGetUserData(hwnd)                        ((LONG) __capSendMessage(hwnd,WM_CAP_GET_USER_DATA,0,0))
#define capSetUserData(hwnd,lUser)                  ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_USER_DATA,0,(LPARAM)lUser))
#define capDriverConnect(hwnd,i)                    ((BOOL) __capSendMessage(hwnd,WM_CAP_DRIVER_CONNECT,(WPARAM)(i),0))
#define capDriverDisconnect(hwnd)                   ((BOOL) __capSendMessage(hwnd,WM_CAP_DRIVER_DISCONNECT,0,0))
#define capDriverGetName(hwnd,szName,wSize)         ((BOOL) __capSendMessage(hwnd,WM_CAP_DRIVER_GET_NAME,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capDriverGetVersion(hwnd,szVer,wSize)       ((BOOL) __capSendMessage(hwnd,WM_CAP_DRIVER_GET_VERSION,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPTSTR)(szVer)))
#define capDriverGetCaps(hwnd,psCaps,wSize)         ((BOOL) __capSendMessage(hwnd,WM_CAP_DRIVER_GET_CAPS,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(psCaps)))
#define capFileSetCaptureFile(hwnd,szName)          ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_SET_CAPTURE_FILE,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileGetCaptureFile(hwnd,szName,wSize)    ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_GET_CAPTURE_FILE,(WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileAlloc(hwnd,dwSize)                   ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_ALLOCATE,0,(LPARAM)(DWORD)(dwSize)))
#define capFileSaveAs(hwnd,szName)                  ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_SAVEAS,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capFileSetInfoChunk(hwnd,lpInfoChunk)       ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_SET_INFOCHUNK,0,(LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))
#define capFileSaveDIB(hwnd, szName)                ((BOOL) __capSendMessage(hwnd,WM_CAP_FILE_SAVEDIB,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capEditCopy(hwnd)                           ((BOOL) __capSendMessage(hwnd,WM_CAP_EDIT_COPY,0,0))
#define capSetAudioFormat(hwnd,psAudioFormat,wSize) ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_AUDIOFORMAT,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPWAVEFORMATEX)(psAudioFormat)))
#define capGetAudioFormat(hwnd,psAudioFormat,wSize) ((DWORD)__capSendMessage(hwnd,WM_CAP_GET_AUDIOFORMAT,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPWAVEFORMATEX)(psAudioFormat)))
#define capGetAudioFormatSize(hwnd)                 ((DWORD)__capSendMessage(hwnd,WM_CAP_GET_AUDIOFORMAT,0,0))
#define capDlgVideoFormat(hwnd)                     ((BOOL) __capSendMessage(hwnd,WM_CAP_DLG_VIDEOFORMAT,0,0))
#define capDlgVideoSource(hwnd)                     ((BOOL) __capSendMessage(hwnd,WM_CAP_DLG_VIDEOSOURCE,0,0))
#define capDlgVideoDisplay(hwnd)                    ((BOOL) __capSendMessage(hwnd,WM_CAP_DLG_VIDEODISPLAY,0,0))
#define capGetVideoFormat(hwnd,psVideoFormat,wSize) ((DWORD)__capSendMessage(hwnd,WM_CAP_GET_VIDEOFORMAT,(WPARAM)(wSize),(LPARAM)(LPVOID)(psVideoFormat)))
#define capGetVideoFormatSize(hwnd)                 ((DWORD)__capSendMessage(hwnd,WM_CAP_GET_VIDEOFORMAT,0,0))
#define capSetVideoFormat(hwnd,psVideoFormat,wSize) ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_VIDEOFORMAT,(WPARAM)(wSize),(LPARAM)(LPVOID)(psVideoFormat)))
#define capDlgVideoCompression(hwnd)                ((BOOL) __capSendMessage(hwnd,WM_CAP_DLG_VIDEOCOMPRESSION,0,0))
#define capPreview(hwnd,f)                          ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_PREVIEW,(WPARAM)(BOOL)(f),0))
#define capOverlay(hwnd,f)                          ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_OVERLAY,(WPARAM)(BOOL)(f),0))
#define capPreviewRate(hwnd,wMS)                    ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_PREVIEWRATE,(WPARAM)(wMS),0))
#define capPreviewScale(hwnd,f)                     ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_SCALE,(WPARAM)(BOOL)f,0))
#define capGetStatus(hwnd,s,wSize)                  ((BOOL) __capSendMessage(hwnd,WM_CAP_GET_STATUS,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPCAPSTATUS)(s)))
#define capSetScrollPos(hwnd,lpP)                   ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_SCROLL,0,(LPARAM)(LPPOINT)(lpP)))
#define capGrabFrame(hwnd)                          ((BOOL) __capSendMessage(hwnd,WM_CAP_GRAB_FRAME,0,0))
#define capGrabFrameNoStop(hwnd)                    ((BOOL) __capSendMessage(hwnd,WM_CAP_GRAB_FRAME_NOSTOP,0,0))
#define capCaptureSequence(hwnd)                    ((BOOL) __capSendMessage(hwnd,WM_CAP_SEQUENCE,0,0))
#define capCaptureSequenceNoFile(hwnd)              ((BOOL) __capSendMessage(hwnd,WM_CAP_SEQUENCE_NOFILE,0,0))
#define capCaptureSetSetup(hwnd,s,wSize)            ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_SEQUENCE_SETUP,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capCaptureGetSetup(hwnd,s,wSize)            ((BOOL) __capSendMessage(hwnd,WM_CAP_GET_SEQUENCE_SETUP,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))
#define capSetMCIDeviceName(hwnd,szName)            ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_MCI_DEVICE,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capGetMCIDeviceName(hwnd,szName,wSize)      ((BOOL) __capSendMessage(hwnd,WM_CAP_GET_MCI_DEVICE,(WPARAM)(wSize),(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capCaptureStop(hwnd)                        ((BOOL) __capSendMessage(hwnd,WM_CAP_STOP,0,0))
#define capCaptureAbort(hwnd)                       ((BOOL) __capSendMessage(hwnd,WM_CAP_ABORT,0,0))
#define capCaptureSingleFrameOpen(hwnd)             ((BOOL) __capSendMessage(hwnd,WM_CAP_SINGLE_FRAME_OPEN,0,0))
#define capCaptureSingleFrameClose(hwnd)            ((BOOL) __capSendMessage(hwnd,WM_CAP_SINGLE_FRAME_CLOSE,0,0))
#define capCaptureSingleFrame(hwnd)                 ((BOOL) __capSendMessage(hwnd,WM_CAP_SINGLE_FRAME,0,0))
#define capPaletteOpen(hwnd,szName)                 ((BOOL) __capSendMessage(hwnd,WM_CAP_PAL_OPEN,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPaletteSave(hwnd,szName)                 ((BOOL) __capSendMessage(hwnd,WM_CAP_PAL_SAVE,0,(LPARAM)(LPVOID)(LPTSTR)(szName)))
#define capPalettePaste(hwnd)                       ((BOOL) __capSendMessage(hwnd,WM_CAP_PAL_PASTE,0,0))
#define capPaletteAuto(hwnd,iFrames,iColors)        ((BOOL) __capSendMessage(hwnd,WM_CAP_PAL_AUTOCREATE,(WPARAM)(iFrames),(LPARAM)(DWORD)(iColors)))
#define capPaletteManual(hwnd,fGrab,iColors)        ((BOOL) __capSendMessage(hwnd,WM_CAP_PAL_MANUALCREATE,(WPARAM)(fGrab),(LPARAM)(DWORD)(iColors)))
#define capSetCallbackOnCapControl(hwnd,fpProc)     ((BOOL) __capSendMessage(hwnd,WM_CAP_SET_CALLBACK_CAPCONTROL,0,(LPARAM)(LPVOID)(fpProc)))

/* AVICAP32 exports */
HWND VFWAPI capCreateCaptureWindowA (LPCSTR,DWORD,int,int,int,int,HWND,int);
HWND VFWAPI capCreateCaptureWindowW (LPCWSTR,DWORD,int,int,int,int,HWND,int);
BOOL VFWAPI capGetDriverDescriptionA (UINT,LPSTR,int,LPSTR,int);
BOOL VFWAPI capGetDriverDescriptionW (UINT,LPWSTR,int,LPWSTR,int);

#ifdef UNICODE
#define AVISTREAMINFO AVISTREAMINFOW
#define LPAVISTREAMINFO LPAVISTREAMINFOW
#define PAVISTREAMINFO PAVISTREAMINFOW
#define AVIFILEINFO AVIFILEINFOW
#define PAVIFILEINFO PAVIFILEINFOW
#define LPAVIFILEINFO LPAVIFILEINFOW
#define AVIStreamInfo AVIStreamInfoW
#define AVIStreamOpenFromFile AVIStreamOpenFromFileW
#define AVIBuildFilter AVIBuildFilterW
#define AVISaveV AVISaveVW
#define EditStreamSetInfo EditStreamSetInfoW
#define EditStreamSetName EditStreamSetNameW
#define AVIFileOpen AVIFileOpenW
#define AVIFileInfo AVIFileInfoW
#define AVIFileCreateStream AVIFileCreateStreamW
#define GetOpenFileNamePreview GetOpenFileNamePreviewW
#define GetSaveFileNamePreview GetSaveFileNamePreviewW
#define MCIWndCreate MCIWndCreateW
#define MCIWNDF_NOTIFYMEDIA MCIWNDF_NOTIFYMEDIAW
#define MCIWNDM_SENDSTRING MCIWNDM_SENDSTRINGW
#define MCIWNDM_GETPOSITION MCIWNDM_GETPOSITIONW
#define MCIWNDM_GETMODE MCIWNDM_GETMODEW
#define MCIWNDM_SETTIMEFORMAT MCIWNDM_SETTIMEFORMATW
#define MCIWNDM_GETTIMEFORMAT MCIWNDM_GETTIMEFORMATW
#define MCIWNDM_GETFILENAME MCIWNDM_GETFILENAMEW
#define MCIWNDM_GETDEVICE MCIWNDM_GETDEVICEW
#define MCIWNDM_GETERROR MCIWNDM_GETERRORW
#define MCIWNDM_NEW MCIWNDM_NEWW
#define MCIWNDM_RETURNSTRING MCIWNDM_RETURNSTRINGW
#define MCIWNDM_OPEN MCIWNDM_OPENW

#define capCreateCaptureWindow  capCreateCaptureWindowW
#define capGetDriverDescription capGetDriverDescriptionW

#else
#define AVISTREAMINFO AVISTREAMINFOA
#define LPAVISTREAMINFO LPAVISTREAMINFOA
#define PAVISTREAMINFO PAVISTREAMINFOA
#define AVIFILEINFO AVIFILEINFOA
#define PAVIFILEINFO PAVIFILEINFOA
#define LPAVIFILEINFO LPAVIFILEINFOA
#define AVIStreamInfo AVIStreamInfoA
#define AVIStreamOpenFromFile AVIStreamOpenFromFileA
#define AVIBuildFilter AVIBuildFilterA
#define AVISaveV AVISaveVA
#define EditStreamSetInfo EditStreamSetInfoA
#define EditStreamSetName EditStreamSetNameA
#define AVIFileOpen AVIFileOpenA
#define AVIFileInfo AVIFileInfoA
#define AVIFileCreateStream AVIFileCreateStreamA
#define GetOpenFileNamePreview GetOpenFileNamePreviewA
#define GetSaveFileNamePreview GetSaveFileNamePreviewA
#define MCIWndCreate MCIWndCreateA
#define MCIWNDF_NOTIFYMEDIA MCIWNDF_NOTIFYMEDIAA
#define MCIWNDM_SENDSTRING MCIWNDM_SENDSTRINGA
#define MCIWNDM_GETPOSITION MCIWNDM_GETPOSITIONA
#define MCIWNDM_GETMODE MCIWNDM_GETMODEA
#define MCIWNDM_SETTIMEFORMAT MCIWNDM_SETTIMEFORMATA
#define MCIWNDM_GETTIMEFORMAT MCIWNDM_GETTIMEFORMATA
#define MCIWNDM_GETFILENAME MCIWNDM_GETFILENAMEA
#define MCIWNDM_GETDEVICE MCIWNDM_GETDEVICEA
#define MCIWNDM_GETERROR MCIWNDM_GETERRORA
#define MCIWNDM_NEW MCIWNDM_NEWA
#define MCIWNDM_RETURNSTRING MCIWNDM_RETURNSTRINGA
#define MCIWNDM_OPEN MCIWNDM_OPENA

#define capCreateCaptureWindow  capCreateCaptureWindowA
#define capGetDriverDescription capGetDriverDescriptionA

#endif

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif
#include <poppack.h>
#endif /* _VFW_H */
