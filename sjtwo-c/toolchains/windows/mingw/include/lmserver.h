#ifndef _LMSERVER_H
#define _LMSERVER_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include <winsvc.h>
#include <lmcons.h>
typedef struct _SERVER_INFO_100 {
DWORD	sv100_platform_id;
LPWSTR	sv100_name;
} SERVER_INFO_100,*PSERVER_INFO_100,*LPSERVER_INFO_100;
typedef struct _SERVER_INFO_101 {
DWORD	sv101_platform_id;
LPWSTR	sv101_name;
DWORD	sv101_version_major;
DWORD	sv101_version_minor;
DWORD	sv101_type;
LPWSTR	sv101_comment;
} SERVER_INFO_101,*PSERVER_INFO_101,*LPSERVER_INFO_101;
typedef struct _SERVER_INFO_102 {
DWORD	sv102_platform_id;
LPWSTR	sv102_name;
DWORD	sv102_version_major;
DWORD	sv102_version_minor;
DWORD	sv102_type;
LPWSTR	sv102_comment;
DWORD	sv102_users;
LONG	sv102_disc;
BOOL	sv102_hidden;
DWORD	sv102_announce;
DWORD	sv102_anndelta;
DWORD	sv102_licenses;
LPWSTR	sv102_userpath;
} SERVER_INFO_102,*PSERVER_INFO_102,*LPSERVER_INFO_102;
typedef struct _SERVER_INFO_402 {
DWORD	sv402_ulist_mtime;
DWORD	sv402_glist_mtime;
DWORD	sv402_alist_mtime;
LPWSTR	sv402_alerts;
DWORD	sv402_security;
DWORD	sv402_numadmin;
DWORD	sv402_lanmask;
LPWSTR	sv402_guestacct;
DWORD	sv402_chdevs;
DWORD	sv402_chdevq;
DWORD	sv402_chdevjobs;
DWORD	sv402_connections;
DWORD	sv402_shares;
DWORD	sv402_openfiles;
DWORD	sv402_sessopens;
DWORD	sv402_sessvcs;
DWORD	sv402_sessreqs;
DWORD	sv402_opensearch;
DWORD	sv402_activelocks;
DWORD	sv402_numreqbuf;
DWORD	sv402_sizreqbuf;
DWORD	sv402_numbigbuf;
DWORD	sv402_numfiletasks;
DWORD	sv402_alertsched;
DWORD	sv402_erroralert;
DWORD	sv402_logonalert;
DWORD	sv402_accessalert;
DWORD	sv402_diskalert;
DWORD	sv402_netioalert;
DWORD	sv402_maxauditsz;
LPWSTR	sv402_srvheuristics;
} SERVER_INFO_402,*PSERVER_INFO_402,*LPSERVER_INFO_402;
typedef struct _SERVER_INFO_403 {
DWORD	sv403_ulist_mtime;
DWORD	sv403_glist_mtime;
DWORD	sv403_alist_mtime;
LPWSTR	sv403_alerts;
DWORD	sv403_security;
DWORD	sv403_numadmin;
DWORD	sv403_lanmask;
LPWSTR	sv403_guestacct;
DWORD	sv403_chdevs;
DWORD	sv403_chdevq;
DWORD	sv403_chdevjobs;
DWORD	sv403_connections;
DWORD	sv403_shares;
DWORD	sv403_openfiles;
DWORD	sv403_sessopens;
DWORD	sv403_sessvcs;
DWORD	sv403_sessreqs;
DWORD	sv403_opensearch;
DWORD	sv403_activelocks;
DWORD	sv403_numreqbuf;
DWORD	sv403_sizreqbuf;
DWORD	sv403_numbigbuf;
DWORD	sv403_numfiletasks;
DWORD	sv403_alertsched;
DWORD	sv403_erroralert;
DWORD	sv403_logonalert;
DWORD	sv403_accessalert;
DWORD	sv403_diskalert;
DWORD	sv403_netioalert;
DWORD	sv403_maxauditsz;
LPWSTR	sv403_srvheuristics;
DWORD	sv403_auditedevents;
DWORD	sv403_autoprofile;
LPWSTR	sv403_autopath;
} SERVER_INFO_403,*PSERVER_INFO_403,*LPSERVER_INFO_403;
typedef struct _SERVER_INFO_502 {
DWORD	sv502_sessopens;
DWORD	sv502_sessvcs;
DWORD	sv502_opensearch;
DWORD	sv502_sizreqbuf;
DWORD	sv502_initworkitems;
DWORD	sv502_maxworkitems;
DWORD	sv502_rawworkitems;
DWORD	sv502_irpstacksize;
DWORD	sv502_maxrawbuflen;
DWORD	sv502_sessusers;
DWORD	sv502_sessconns;
DWORD	sv502_maxpagedmemoryusage;
DWORD	sv502_maxnonpagedmemoryusage;
BOOL	sv502_enablesoftcompat;
BOOL	sv502_enableforcedlogoff;
BOOL	sv502_timesource;
BOOL	sv502_acceptdownlevelapis;
BOOL	sv502_lmannounce;
} SERVER_INFO_502,*PSERVER_INFO_502,*LPSERVER_INFO_502;
typedef struct _SERVER_INFO_503 {
DWORD	sv503_sessopens;
DWORD	sv503_sessvcs;
DWORD	sv503_opensearch;
DWORD	sv503_sizreqbuf;
DWORD	sv503_initworkitems;
DWORD	sv503_maxworkitems;
DWORD	sv503_rawworkitems;
DWORD	sv503_irpstacksize;
DWORD	sv503_maxrawbuflen;
DWORD	sv503_sessusers;
DWORD	sv503_sessconns;
DWORD	sv503_maxpagedmemoryusage;
DWORD	sv503_maxnonpagedmemoryusage;
BOOL	sv503_enablesoftcompat;
BOOL	sv503_enableforcedlogoff;
BOOL	sv503_timesource;
BOOL	sv503_acceptdownlevelapis;
BOOL	sv503_lmannounce;
LPWSTR	sv503_domain;
DWORD	sv503_maxcopyreadlen;
DWORD	sv503_maxcopywritelen;
DWORD	sv503_minkeepsearch;
DWORD	sv503_maxkeepsearch;
DWORD	sv503_minkeepcomplsearch;
DWORD	sv503_maxkeepcomplsearch;
DWORD	sv503_threadcountadd;
DWORD	sv503_numblockthreads;
DWORD	sv503_scavtimeout;
DWORD	sv503_minrcvqueue;
DWORD	sv503_minfreeworkitems;
DWORD	sv503_xactmemsize;
DWORD	sv503_threadpriority;
DWORD	sv503_maxmpxct;
DWORD	sv503_oplockbreakwait;
DWORD	sv503_oplockbreakresponsewait;
BOOL	sv503_enableoplocks;
BOOL	sv503_enableoplockforceclose;
BOOL	sv503_enablefcbopens;
BOOL	sv503_enableraw;
BOOL	sv503_enablesharednetdrives;
DWORD	sv503_minfreeconnections;
DWORD	sv503_maxfreeconnections;
} SERVER_INFO_503,*PSERVER_INFO_503,*LPSERVER_INFO_503;
typedef struct _SERVER_INFO_599 {
DWORD	sv599_sessopens;
DWORD	sv599_sessvcs;
DWORD	sv599_opensearch;
DWORD	sv599_sizreqbuf;
DWORD	sv599_initworkitems;
DWORD	sv599_maxworkitems;
DWORD	sv599_rawworkitems;
DWORD	sv599_irpstacksize;
DWORD	sv599_maxrawbuflen;
DWORD	sv599_sessusers;
DWORD	sv599_sessconns;
DWORD	sv599_maxpagedmemoryusage;
DWORD	sv599_maxnonpagedmemoryusage;
BOOL	sv599_enablesoftcompat;
BOOL	sv599_enableforcedlogoff;
BOOL	sv599_timesource;
BOOL	sv599_acceptdownlevelapis;
BOOL	sv599_lmannounce;
LPWSTR	sv599_domain;
DWORD	sv599_maxcopyreadlen;
DWORD	sv599_maxcopywritelen;
DWORD	sv599_minkeepsearch;
DWORD	sv599_maxkeepsearch;
DWORD	sv599_minkeepcomplsearch;
DWORD	sv599_maxkeepcomplsearch;
DWORD	sv599_threadcountadd;
DWORD	sv599_numblockthreads;
DWORD	sv599_scavtimeout;
DWORD	sv599_minrcvqueue;
DWORD	sv599_minfreeworkitems;
DWORD	sv599_xactmemsize;
DWORD	sv599_threadpriority;
DWORD	sv599_maxmpxct;
DWORD	sv599_oplockbreakwait;
DWORD	sv599_oplockbreakresponsewait;
BOOL	sv599_enableoplocks;
BOOL	sv599_enableoplockforceclose;
BOOL	sv599_enablefcbopens;
BOOL	sv599_enableraw;
BOOL	sv599_enablesharednetdrives;
DWORD	sv599_minfreeconnections;
DWORD	sv599_maxfreeconnections;
DWORD	sv599_initsesstable;
DWORD	sv599_initconntable;
DWORD	sv599_initfiletable;
DWORD	sv599_initsearchtable;
DWORD	sv599_alertschedule;
DWORD	sv599_errorthreshold;
DWORD	sv599_networkerrorthreshold;
DWORD	sv599_diskspacethreshold;
DWORD	sv599_reserved;
DWORD	sv599_maxlinkdelay;
DWORD	sv599_minlinkthroughput;
DWORD	sv599_linkinfovalidtime;
DWORD	sv599_scavqosinfoupdatetime;
DWORD	sv599_maxworkitemidletime;
} SERVER_INFO_599,*PSERVER_INFO_599,*LPSERVER_INFO_599;
typedef struct _SERVER_INFO_598 {
DWORD	sv598_maxrawworkitems;
DWORD	sv598_maxthreadsperqueue;
DWORD	sv598_producttype;
DWORD	sv598_serversize;
DWORD	sv598_connectionlessautodisc;
DWORD	sv598_sharingviolationretries;
DWORD	sv598_sharingviolationdelay;
DWORD	sv598_maxglobalopensearch;
DWORD	sv598_removeduplicatesearches;
DWORD	sv598_lockviolationoffset;
DWORD	sv598_lockviolationdelay;
DWORD	sv598_mdlreadswitchover;
DWORD	sv598_cachedopenlimit;
DWORD	sv598_otherqueueaffinity;
BOOL	sv598_restrictnullsessaccess;
BOOL	sv598_enablewfw311directipx;
DWORD	sv598_queuesamplesecs;
DWORD	sv598_balancecount;
DWORD	sv598_preferredaffinity;
DWORD	sv598_maxfreerfcbs;
DWORD	sv598_maxfreemfcbs;
DWORD	sv598_maxfreelfcbs;
DWORD	sv598_maxfreepagedpoolchunks;
DWORD	sv598_minpagedpoolchunksize;
DWORD	sv598_maxpagedpoolchunksize;
BOOL	sv598_sendsfrompreferredprocessor;
} SERVER_INFO_598,*PSERVER_INFO_598,*LPSERVER_INFO_598;
typedef struct _SERVER_INFO_1005 {LPWSTR sv1005_comment; } SERVER_INFO_1005,*PSERVER_INFO_1005,*LPSERVER_INFO_1005;
typedef struct _SERVER_INFO_1107 { DWORD sv1107_users; } SERVER_INFO_1107,*PSERVER_INFO_1107,*LPSERVER_INFO_1107;
typedef struct _SERVER_INFO_1010 { LONG sv1010_disc; } SERVER_INFO_1010,*PSERVER_INFO_1010,*LPSERVER_INFO_1010;
typedef struct _SERVER_INFO_1016 { BOOL sv1016_hidden; } SERVER_INFO_1016,*PSERVER_INFO_1016,*LPSERVER_INFO_1016;
typedef struct _SERVER_INFO_1017 { DWORD sv1017_announce; } SERVER_INFO_1017,*PSERVER_INFO_1017,*LPSERVER_INFO_1017;
typedef struct _SERVER_INFO_1018 { DWORD sv1018_anndelta; } SERVER_INFO_1018,*PSERVER_INFO_1018,*LPSERVER_INFO_1018;
typedef struct _SERVER_INFO_1501 { DWORD sv1501_sessopens; } SERVER_INFO_1501,*PSERVER_INFO_1501,*LPSERVER_INFO_1501;
typedef struct _SERVER_INFO_1502 { DWORD sv1502_sessvcs; } SERVER_INFO_1502,*PSERVER_INFO_1502,*LPSERVER_INFO_1502;
typedef struct _SERVER_INFO_1503 { DWORD sv1503_opensearch; } SERVER_INFO_1503,*PSERVER_INFO_1503,*LPSERVER_INFO_1503;
typedef struct _SERVER_INFO_1506 { DWORD sv1506_maxworkitems; } SERVER_INFO_1506,*PSERVER_INFO_1506,*LPSERVER_INFO_1506;
typedef struct _SERVER_INFO_1509 { DWORD sv1509_maxrawbuflen; } SERVER_INFO_1509,*PSERVER_INFO_1509,*LPSERVER_INFO_1509;
typedef struct _SERVER_INFO_1510 { DWORD sv1510_sessusers; } SERVER_INFO_1510,*PSERVER_INFO_1510,*LPSERVER_INFO_1510;
typedef struct _SERVER_INFO_1511 { DWORD sv1511_sessconns; } SERVER_INFO_1511,*PSERVER_INFO_1511,*LPSERVER_INFO_1511;
typedef struct _SERVER_INFO_1512 { DWORD sv1512_maxnonpagedmemoryusage; } SERVER_INFO_1512,*PSERVER_INFO_1512,*LPSERVER_INFO_1512;
typedef struct _SERVER_INFO_1513 { DWORD sv1513_maxpagedmemoryusage; } SERVER_INFO_1513,*PSERVER_INFO_1513,*LPSERVER_INFO_1513;
typedef struct _SERVER_INFO_1514 { BOOL sv1514_enablesoftcompat; } SERVER_INFO_1514,*PSERVER_INFO_1514,*LPSERVER_INFO_1514;
typedef struct _SERVER_INFO_1515 { BOOL sv1515_enableforcedlogoff; } SERVER_INFO_1515,*PSERVER_INFO_1515,*LPSERVER_INFO_1515;
typedef struct _SERVER_INFO_1516 { BOOL sv1516_timesource; } SERVER_INFO_1516,*PSERVER_INFO_1516,*LPSERVER_INFO_1516;
typedef struct _SERVER_INFO_1518 { BOOL sv1518_lmannounce; } SERVER_INFO_1518,*PSERVER_INFO_1518,*LPSERVER_INFO_1518;
typedef struct _SERVER_INFO_1520 { DWORD sv1520_maxcopyreadlen; } SERVER_INFO_1520,*PSERVER_INFO_1520,*LPSERVER_INFO_1520;
typedef struct _SERVER_INFO_1521 { DWORD sv1521_maxcopywritelen; } SERVER_INFO_1521,*PSERVER_INFO_1521,*LPSERVER_INFO_1521;
typedef struct _SERVER_INFO_1522 { DWORD sv1522_minkeepsearch; } SERVER_INFO_1522,*PSERVER_INFO_1522,*LPSERVER_INFO_1522;
typedef struct _SERVER_INFO_1523 { DWORD sv1523_maxkeepsearch; } SERVER_INFO_1523,*PSERVER_INFO_1523,*LPSERVER_INFO_1523;
typedef struct _SERVER_INFO_1524 { DWORD sv1524_minkeepcomplsearch; } SERVER_INFO_1524,*PSERVER_INFO_1524,*LPSERVER_INFO_1524;
typedef struct _SERVER_INFO_1525 { DWORD sv1525_maxkeepcomplsearch; } SERVER_INFO_1525,*PSERVER_INFO_1525,*LPSERVER_INFO_1525;
typedef struct _SERVER_INFO_1528 { DWORD sv1528_scavtimeout; } SERVER_INFO_1528,*PSERVER_INFO_1528,*LPSERVER_INFO_1528;
typedef struct _SERVER_INFO_1529 { DWORD sv1529_minrcvqueue; } SERVER_INFO_1529,*PSERVER_INFO_1529,*LPSERVER_INFO_1529;
typedef struct _SERVER_INFO_1530 { DWORD sv1530_minfreeworkitems; } SERVER_INFO_1530,*PSERVER_INFO_1530,*LPSERVER_INFO_1530;
typedef struct _SERVER_INFO_1533 { DWORD sv1533_maxmpxct; } SERVER_INFO_1533,*PSERVER_INFO_1533,*LPSERVER_INFO_1533;
typedef struct _SERVER_INFO_1534 { DWORD sv1534_oplockbreakwait; } SERVER_INFO_1534,*PSERVER_INFO_1534,*LPSERVER_INFO_1534;
typedef struct _SERVER_INFO_1535 { DWORD sv1535_oplockbreakresponsewait; } SERVER_INFO_1535,*PSERVER_INFO_1535,*LPSERVER_INFO_1535;
typedef struct _SERVER_INFO_1536 { BOOL sv1536_enableoplocks; } SERVER_INFO_1536,*PSERVER_INFO_1536,*LPSERVER_INFO_1536;
typedef struct _SERVER_INFO_1537 { BOOL sv1537_enableoplockforceclose; } SERVER_INFO_1537,*PSERVER_INFO_1537,*LPSERVER_INFO_1537;
typedef struct _SERVER_INFO_1538 { BOOL sv1538_enablefcbopens; } SERVER_INFO_1538,*PSERVER_INFO_1538,*LPSERVER_INFO_1538;
typedef struct _SERVER_INFO_1539 { BOOL sv1539_enableraw; } SERVER_INFO_1539,*PSERVER_INFO_1539,*LPSERVER_INFO_1539;
typedef struct _SERVER_INFO_1540 { BOOL sv1540_enablesharednetdrives; } SERVER_INFO_1540,*PSERVER_INFO_1540,*LPSERVER_INFO_1540;
typedef struct _SERVER_INFO_1541 { BOOL sv1541_minfreeconnections; } SERVER_INFO_1541,*PSERVER_INFO_1541,*LPSERVER_INFO_1541;
typedef struct _SERVER_INFO_1542 { BOOL sv1542_maxfreeconnections; } SERVER_INFO_1542,*PSERVER_INFO_1542,*LPSERVER_INFO_1542;
typedef struct _SERVER_INFO_1543 { DWORD sv1543_initsesstable; } SERVER_INFO_1543,*PSERVER_INFO_1543,*LPSERVER_INFO_1543;
typedef struct _SERVER_INFO_1544 { DWORD sv1544_initconntable; } SERVER_INFO_1544,*PSERVER_INFO_1544,*LPSERVER_INFO_1544;
typedef struct _SERVER_INFO_1545 { DWORD sv1545_initfiletable; } SERVER_INFO_1545,*PSERVER_INFO_1545,*LPSERVER_INFO_1545;
typedef struct _SERVER_INFO_1546 { DWORD sv1546_initsearchtable; } SERVER_INFO_1546,*PSERVER_INFO_1546,*LPSERVER_INFO_1546;
typedef struct _SERVER_INFO_1547 { DWORD sv1547_alertschedule; } SERVER_INFO_1547,*PSERVER_INFO_1547,*LPSERVER_INFO_1547;
typedef struct _SERVER_INFO_1548 { DWORD sv1548_errorthreshold; } SERVER_INFO_1548,*PSERVER_INFO_1548,*LPSERVER_INFO_1548;
typedef struct _SERVER_INFO_1549 { DWORD sv1549_networkerrorthreshold; } SERVER_INFO_1549,*PSERVER_INFO_1549,*LPSERVER_INFO_1549;
typedef struct _SERVER_INFO_1550 { DWORD sv1550_diskspacethreshold; } SERVER_INFO_1550,*PSERVER_INFO_1550,*LPSERVER_INFO_1550;
typedef struct _SERVER_INFO_1552 { DWORD sv1552_maxlinkdelay; } SERVER_INFO_1552,*PSERVER_INFO_1552,*LPSERVER_INFO_1552;
typedef struct _SERVER_INFO_1553 { DWORD sv1553_minlinkthroughput; } SERVER_INFO_1553,*PSERVER_INFO_1553,*LPSERVER_INFO_1553;
typedef struct _SERVER_INFO_1554 { DWORD sv1554_linkinfovalidtime; } SERVER_INFO_1554,*PSERVER_INFO_1554,*LPSERVER_INFO_1554;
typedef struct _SERVER_INFO_1555 { DWORD sv1555_scavqosinfoupdatetime; } SERVER_INFO_1555,*PSERVER_INFO_1555,*LPSERVER_INFO_1555;
typedef struct _SERVER_INFO_1556 { DWORD sv1556_maxworkitemidletime; } SERVER_INFO_1556,*PSERVER_INFO_1556,*LPSERVER_INFO_1556;
typedef struct _SERVER_INFO_1557 { DWORD sv1557_maxrawworkitems; } SERVER_INFO_1557,*PSERVER_INFO_1557,*LPSERVER_INFO_1557;
typedef struct _SERVER_INFO_1560 { DWORD sv1560_producttype; } SERVER_INFO_1560,*PSERVER_INFO_1560,*LPSERVER_INFO_1560;
typedef struct _SERVER_INFO_1561 { DWORD sv1561_serversize; } SERVER_INFO_1561,*PSERVER_INFO_1561,*LPSERVER_INFO_1561;
typedef struct _SERVER_INFO_1562 { DWORD sv1562_connectionlessautodisc; } SERVER_INFO_1562,*PSERVER_INFO_1562,*LPSERVER_INFO_1562;
typedef struct _SERVER_INFO_1563 { DWORD sv1563_sharingviolationretries; } SERVER_INFO_1563,*PSERVER_INFO_1563,*LPSERVER_INFO_1563;
typedef struct _SERVER_INFO_1564 { DWORD sv1564_sharingviolationdelay; } SERVER_INFO_1564,*PSERVER_INFO_1564,*LPSERVER_INFO_1564;
typedef struct _SERVER_INFO_1565 { DWORD sv1565_maxglobalopensearch; } SERVER_INFO_1565,*PSERVER_INFO_1565,*LPSERVER_INFO_1565;
typedef struct _SERVER_INFO_1566 { BOOL sv1566_removeduplicatesearches; } SERVER_INFO_1566,*PSERVER_INFO_1566,*LPSERVER_INFO_1566;
typedef struct _SERVER_INFO_1567 { DWORD sv1567_lockviolationretries; } SERVER_INFO_1567,*PSERVER_INFO_1567,*LPSERVER_INFO_1567;
typedef struct _SERVER_INFO_1568 { DWORD sv1568_lockviolationoffset; } SERVER_INFO_1568,*PSERVER_INFO_1568,*LPSERVER_INFO_1568;
typedef struct _SERVER_INFO_1569 { DWORD sv1569_lockviolationdelay; } SERVER_INFO_1569,*PSERVER_INFO_1569,*LPSERVER_INFO_1569;
typedef struct _SERVER_INFO_1570 { DWORD sv1570_mdlreadswitchover; } SERVER_INFO_1570,*PSERVER_INFO_1570,*LPSERVER_INFO_1570;
typedef struct _SERVER_INFO_1571 { DWORD sv1571_cachedopenlimit; } SERVER_INFO_1571,*PSERVER_INFO_1571,*LPSERVER_INFO_1571;
typedef struct _SERVER_INFO_1572 { DWORD sv1572_criticalthreads; } SERVER_INFO_1572,*PSERVER_INFO_1572,*LPSERVER_INFO_1572;
typedef struct _SERVER_INFO_1573 { DWORD sv1573_restrictnullsessaccess; } SERVER_INFO_1573,*PSERVER_INFO_1573,*LPSERVER_INFO_1573;
typedef struct _SERVER_INFO_1574 { DWORD sv1574_enablewfw311directipx;} SERVER_INFO_1574,*PSERVER_INFO_1574,*LPSERVER_INFO_1574;
typedef struct _SERVER_INFO_1575 { DWORD sv1575_otherqueueaffinity; } SERVER_INFO_1575,*PSERVER_INFO_1575,*LPSERVER_INFO_1575;
typedef struct _SERVER_INFO_1576 { DWORD sv1576_queuesamplesecs; } SERVER_INFO_1576,*PSERVER_INFO_1576,*LPSERVER_INFO_1576;
typedef struct _SERVER_INFO_1577 { DWORD sv1577_balancecount; } SERVER_INFO_1577,*PSERVER_INFO_1577,*LPSERVER_INFO_1577;
typedef struct _SERVER_INFO_1578 { DWORD sv1578_preferredaffinity; } SERVER_INFO_1578,*PSERVER_INFO_1578,*LPSERVER_INFO_1578;
typedef struct _SERVER_INFO_1579 { DWORD sv1579_maxfreerfcbs; } SERVER_INFO_1579,*PSERVER_INFO_1579,*LPSERVER_INFO_1579;
typedef struct _SERVER_INFO_1580 { DWORD sv1580_maxfreemfcbs; } SERVER_INFO_1580,*PSERVER_INFO_1580,*LPSERVER_INFO_1580;
typedef struct _SERVER_INFO_1581 { DWORD sv1581_maxfreemlcbs; } SERVER_INFO_1581,*PSERVER_INFO_1581,*LPSERVER_INFO_1581;
typedef struct _SERVER_INFO_1582 { DWORD sv1582_maxfreepagedpoolchunks; } SERVER_INFO_1582,*PSERVER_INFO_1582,*LPSERVER_INFO_1582;
typedef struct _SERVER_INFO_1583 { DWORD sv1583_minpagedpoolchunksize; } SERVER_INFO_1583,*PSERVER_INFO_1583,*LPSERVER_INFO_1583;
typedef struct _SERVER_INFO_1584 { DWORD sv1584_maxpagedpoolchunksize; } SERVER_INFO_1584,*PSERVER_INFO_1584,*LPSERVER_INFO_1584;
typedef struct _SERVER_INFO_1585 { BOOL sv1585_sendsfrompreferredprocessor; } SERVER_INFO_1585,*PSERVER_INFO_1585,*LPSERVER_INFO_1585;
typedef struct _SERVER_INFO_1586 { BOOL sv1586_maxthreadsperqueue; } SERVER_INFO_1586,*PSERVER_INFO_1586,*LPSERVER_INFO_1586;
typedef struct _SERVER_TRANSPORT_INFO_0 {
DWORD svti0_numberofvcs;
LPWSTR	svti0_transportname;
PBYTE	svti0_transportaddress;
DWORD	svti0_transportaddresslength;
LPWSTR	svti0_networkaddress;
} SERVER_TRANSPORT_INFO_0,*PSERVER_TRANSPORT_INFO_0,*LPSERVER_TRANSPORT_INFO_0;

NET_API_STATUS WINAPI NetServerEnum(LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,DWORD,LPCWSTR,PDWORD);
NET_API_STATUS WINAPI NetServerEnumEx(LPCWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,DWORD,LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetServerGetInfo(LPWSTR,DWORD,PBYTE*);
NET_API_STATUS WINAPI NetServerSetInfo(LPWSTR,DWORD,PBYTE,PDWORD);
NET_API_STATUS NetServerSetInfoCommandLine(WORD,LPWSTR*);
NET_API_STATUS WINAPI NetServerDiskEnum(LPWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
NET_API_STATUS WINAPI NetServerComputerNameAdd(LPWSTR,LPWSTR,LPWSTR);
NET_API_STATUS WINAPI NetServerComputerNameDel(LPWSTR,LPWSTR);
NET_API_STATUS WINAPI NetServerTransportAdd(LPWSTR,DWORD,PBYTE);
NET_API_STATUS WINAPI NetServerTransportAddEx(LPWSTR,DWORD,PBYTE);
NET_API_STATUS WINAPI NetServerTransportDel(LPWSTR,DWORD,PBYTE);
NET_API_STATUS WINAPI NetServerTransportEnum(LPWSTR,DWORD,PBYTE*,DWORD,PDWORD,PDWORD,PDWORD);
BOOL SetServiceBits(SERVICE_STATUS_HANDLE,DWORD,BOOL,BOOL);

#define SVI1_NUM_ELEMENTS	5
#define SVI2_NUM_ELEMENTS	40
#define SVI3_NUM_ELEMENTS	44
#define SV_MAX_CMD_LEN	PATHLEN
#define SW_AUTOPROF_LOAD_MASK 1
#define SW_AUTOPROF_SAVE_MASK 2
#define SV_MAX_SRV_HEUR_LEN	32
#define SV_USERS_PER_LICENSE	5
#define SV_PLATFORM_ID_OS2 400
#define SV_PLATFORM_ID_NT 500
#define MAJOR_VERSION_MASK 15
#define SV_TYPE_WORKSTATION	1
#define SV_TYPE_SERVER 2
#define SV_TYPE_SQLSERVER 4
#define SV_TYPE_DOMAIN_CTRL 8
#define SV_TYPE_DOMAIN_BAKCTRL 16
#define SV_TYPE_TIME_SOURCE 32
#define SV_TYPE_AFP 64
#define SV_TYPE_NOVELL 128
#define SV_TYPE_DOMAIN_MEMBER 256
#define SV_TYPE_PRINTQ_SERVER 512
#define SV_TYPE_DIALIN_SERVER 1024
#define SV_TYPE_XENIX_SERVER 2048
#define SV_TYPE_SERVER_UNIX	SV_TYPE_XENIX_SERVER
#define SV_TYPE_NT 4096
#define SV_TYPE_WFW 8192
#define SV_TYPE_SERVER_MFPN 16384
#define SV_TYPE_SERVER_NT 32768
#define SV_TYPE_POTENTIAL_BROWSER 65536
#define SV_TYPE_BACKUP_BROWSER	0x20000
#define SV_TYPE_MASTER_BROWSER	0x40000
#define SV_TYPE_DOMAIN_MASTER	0x80000
#define SV_TYPE_SERVER_OSF	0x100000
#define SV_TYPE_SERVER_VMS	0x200000
#define SV_TYPE_WINDOWS	0x400000
#define SV_TYPE_ALTERNATE_XPORT	0x20000000
#define SV_TYPE_LOCAL_LIST_ONLY	0x40000000
#define SV_TYPE_DOMAIN_ENUM	0x80000000
#define SV_TYPE_ALL	0xFFFFFFFF
#define SV_NODISC	(-1)
#define SV_USERSECURITY	1
#define SV_SHARESECURITY	0
#define SV_HIDDEN	1
#define SV_VISIBLE	0
#define SV_PLATFORM_ID_PARMNUM	101
#define SV_NAME_PARMNUM	102
#define SV_VERSION_MAJOR_PARMNUM	103
#define SV_VERSION_MINOR_PARMNUM	104
#define SV_TYPE_PARMNUM	105
#define SV_COMMENT_PARMNUM	5
#define SV_USERS_PARMNUM	107
#define SV_DISC_PARMNUM	10
#define SV_HIDDEN_PARMNUM	16
#define SV_ANNOUNCE_PARMNUM	17
#define SV_ANNDELTA_PARMNUM	18
#define SV_USERPATH_PARMNUM	112
#define SV_ULIST_MTIME_PARMNUM	401
#define SV_GLIST_MTIME_PARMNUM	402
#define SV_ALIST_MTIME_PARMNUM	403
#define SV_ALERTS_PARMNUM	11
#define SV_SECURITY_PARMNUM	405
#define SV_NUMADMIN_PARMNUM	406
#define SV_LANMASK_PARMNUM	407
#define SV_GUESTACC_PARMNUM	408
#define SV_CHDEVQ_PARMNUM	410
#define SV_CHDEVJOBS_PARMNUM	411
#define SV_CONNECTIONS_PARMNUM	412
#define SV_SHARES_PARMNUM	413
#define SV_OPENFILES_PARMNUM	414
#define SV_SESSREQS_PARMNUM	417
#define SV_ACTIVELOCKS_PARMNUM	419
#define SV_NUMREQBUF_PARMNUM	420
#define SV_NUMBIGBUF_PARMNUM	422
#define SV_NUMFILETASKS_PARMNUM	423
#define SV_ALERTSCHED_PARMNUM	37
#define SV_ERRORALERT_PARMNUM	38
#define SV_LOGONALERT_PARMNUM	39
#define SV_ACCESSALERT_PARMNUM	40
#define SV_DISKALERT_PARMNUM	41
#define SV_NETIOALERT_PARMNUM	42
#define SV_MAXAUDITSZ_PARMNUM	43
#define SV_SRVHEURISTICS_PARMNUM	431
#define SV_SESSOPENS_PARMNUM	501
#define SV_SESSVCS_PARMNUM	502
#define SV_OPENSEARCH_PARMNUM	503
#define SV_SIZREQBUF_PARMNUM	504
#define SV_INITWORKITEMS_PARMNUM	505
#define SV_MAXWORKITEMS_PARMNUM	506
#define SV_RAWWORKITEMS_PARMNUM	507
#define SV_IRPSTACKSIZE_PARMNUM	508
#define SV_MAXRAWBUFLEN_PARMNUM	509
#define SV_SESSUSERS_PARMNUM	510
#define SV_SESSCONNS_PARMNUM	511
#define SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM 512
#define SV_MAXPAGEDMEMORYUSAGE_PARMNUM	513
#define SV_ENABLESOFTCOMPAT_PARMNUM	514
#define SV_ENABLEFORCEDLOGOFF_PARMNUM	515
#define SV_TIMESOURCE_PARMNUM	516
#define SV_ACCEPTDOWNLEVELAPIS_PARMNUM	517
#define SV_LMANNOUNCE_PARMNUM	518
#define SV_DOMAIN_PARMNUM	519
#define SV_MAXCOPYREADLEN_PARMNUM	520
#define SV_MAXCOPYWRITELEN_PARMNUM	521
#define SV_MINKEEPSEARCH_PARMNUM	522
#define SV_MAXKEEPSEARCH_PARMNUM	523
#define SV_MINKEEPCOMPLSEARCH_PARMNUM	524
#define SV_MAXKEEPCOMPLSEARCH_PARMNUM	525
#define SV_THREADCOUNTADD_PARMNUM	526
#define SV_NUMBLOCKTHREADS_PARMNUM	527
#define SV_SCAVTIMEOUT_PARMNUM	528
#define SV_MINRCVQUEUE_PARMNUM	529
#define SV_MINFREEWORKITEMS_PARMNUM	530
#define SV_XACTMEMSIZE_PARMNUM	531
#define SV_THREADPRIORITY_PARMNUM	532
#define SV_MAXMPXCT_PARMNUM	533
#define SV_OPLOCKBREAKWAIT_PARMNUM	534
#define SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM 535
#define SV_ENABLEOPLOCKS_PARMNUM	536
#define SV_ENABLEOPLOCKFORCECLOSE_PARMNUM 537
#define SV_ENABLEFCBOPENS_PARMNUM	538
#define SV_ENABLERAW_PARMNUM	539
#define SV_ENABLESHAREDNETDRIVES_PARMNUM	540
#define SV_MINFREECONNECTIONS_PARMNUM	541
#define SV_MAXFREECONNECTIONS_PARMNUM	542
#define SV_INITSESSTABLE_PARMNUM	543
#define SV_INITCONNTABLE_PARMNUM	544
#define SV_INITFILETABLE_PARMNUM	545
#define SV_INITSEARCHTABLE_PARMNUM	546
#define SV_ALERTSCHEDULE_PARMNUM	547
#define SV_ERRORTHRESHOLD_PARMNUM	548
#define SV_NETWORKERRORTHRESHOLD_PARMNUM	549
#define SV_DISKSPACETHRESHOLD_PARMNUM	550
#define SV_MAXLINKDELAY_PARMNUM	552
#define SV_MINLINKTHROUGHPUT_PARMNUM	553
#define SV_LINKINFOVALIDTIME_PARMNUM	554
#define SV_SCAVQOSINFOUPDATETIME_PARMNUM	555
#define SV_MAXWORKITEMIDLETIME_PARMNUM	556
#define SV_MAXRAWWORKITEMS_PARMNUM	557
#define SV_PRODUCTTYPE_PARMNUM	560
#define SV_SERVERSIZE_PARMNUM	561
#define SV_CONNECTIONLESSAUTODISC_PARMNUM 562
#define SV_SHARINGVIOLATIONRETRIES_PARMNUM 563
#define SV_SHARINGVIOLATIONDELAY_PARMNUM	564
#define SV_MAXGLOBALOPENSEARCH_PARMNUM	565
#define SV_REMOVEDUPLICATESEARCHES_PARMNUM 566
#define SV_LOCKVIOLATIONRETRIES_PARMNUM	567
#define SV_LOCKVIOLATIONOFFSET_PARMNUM	568
#define SV_LOCKVIOLATIONDELAY_PARMNUM	569
#define SV_MDLREADSWITCHOVER_PARMNUM	570
#define SV_CACHEDOPENLIMIT_PARMNUM	571
#define SV_CRITICALTHREADS_PARMNUM	572
#define SV_RESTRICTNULLSESSACCESS_PARMNUM 573
#define SV_ENABLEWFW311DIRECTIPX_PARMNUM	574
#define SV_OTHERQUEUEAFFINITY_PARMNUM	575
#define SV_QUEUESAMPLESECS_PARMNUM	576
#define SV_BALANCECOUNT_PARMNUM	577
#define SV_PREFERREDAFFINITY_PARMNUM	578
#define SV_MAXFREERFCBS_PARMNUM	579
#define SV_MAXFREEMFCBS_PARMNUM	580
#define SV_MAXFREELFCBS_PARMNUM	581
#define SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM 582
#define SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM	583
#define SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM	584
#define SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM	585
#define SV_MAXTHREADSPERQUEUE_PARMNUM	586
#define SV_COMMENT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_COMMENT_PARMNUM)
#define SV_USERS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_USERS_PARMNUM)
#define SV_DISC_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_DISC_PARMNUM)
#define SV_HIDDEN_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_HIDDEN_PARMNUM)
#define SV_ANNOUNCE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ANNOUNCE_PARMNUM)
#define SV_ANNDELTA_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ANNDELTA_PARMNUM)
#define SV_SESSOPENS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SESSOPENS_PARMNUM)
#define SV_SESSVCS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SESSVCS_PARMNUM)
#define SV_OPENSEARCH_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_OPENSEARCH_PARMNUM)
#define SV_MAXWORKITEMS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXWORKITEMS_PARMNUM)
#define SV_MAXRAWBUFLEN_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXRAWBUFLEN_PARMNUM)
#define SV_SESSUSERS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SESSUSERS_PARMNUM)
#define SV_SESSCONNS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SESSCONNS_PARMNUM)
#define SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM)
#define SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXPAGEDMEMORYUSAGE_PARMNUM)
#define SV_ENABLESOFTCOMPAT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLESOFTCOMPAT_PARMNUM)
#define SV_ENABLEFORCEDLOGOFF_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_ENABLEFORCEDLOGOFF_PARMNUM)
#define SV_TIMESOURCE_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_TIMESOURCE_PARMNUM)
#define SV_LMANNOUNCE_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_LMANNOUNCE_PARMNUM)
#define SV_MAXCOPYREADLEN_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXCOPYREADLEN_PARMNUM)
#define SV_MAXCOPYWRITELEN_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXCOPYWRITELEN_PARMNUM)
#define SV_MINKEEPSEARCH_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINKEEPSEARCH_PARMNUM)
#define SV_MAXKEEPSEARCH_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXKEEPSEARCH_PARMNUM)
#define SV_MINKEEPCOMPLSEARCH_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_MINKEEPCOMPLSEARCH_PARMNUM)
#define SV_MAXKEEPCOMPLSEARCH_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_MAXKEEPCOMPLSEARCH_PARMNUM)
#define SV_SCAVTIMEOUT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SCAVTIMEOUT_PARMNUM)
#define SV_MINRCVQUEUE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINRCVQUEUE_PARMNUM)
#define SV_MINFREEWORKITEMS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINFREEWORKITEMS_PARMNUM)
#define SV_MAXMPXCT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXMPXCT_PARMNUM)
#define SV_OPLOCKBREAKWAIT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_OPLOCKBREAKWAIT_PARMNUM)
#define SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM)
#define SV_ENABLEOPLOCKS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLEOPLOCKS_PARMNUM)
#define SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLEOPLOCKFORCECLOSE_PARMNUM)
#define SV_ENABLEFCBOPENS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLEFCBOPENS_PARMNUM)
#define SV_ENABLERAW_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLERAW_PARMNUM)
#define SV_ENABLESHAREDNETDRIVES_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLESHAREDNETDRIVES_PARMNUM)
#define SV_MINFREECONNECTIONS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINFREECONNECTIONS_PARMNUM)
#define SV_MAXFREECONNECTIONS_INFOLEVEL	(PARMNUM_BASE_INFOLEVEL+SV_MAXFREECONNECTIONS_PARMNUM)
#define SV_INITSESSTABLE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_INITSESSTABLE_PARMNUM)
#define SV_INITCONNTABLE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_INITCONNTABLE_PARMNUM)
#define SV_INITFILETABLE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_INITFILETABLE_PARMNUM)
#define SV_INITSEARCHTABLE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_INITSEARCHTABLE_PARMNUM)
#define SV_ALERTSCHEDULE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ALERTSCHEDULE_PARMNUM)
#define SV_ERRORTHRESHOLD_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_ERRORTHRESHOLD_PARMNUM)
#define SV_NETWORKERRORTHRESHOLD_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_NETWORKERRORTHRESHOLD_PARMNUM)
#define SV_DISKSPACETHRESHOLD_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_DISKSPACETHRESHOLD_PARMNUM)
#define SV_MAXLINKDELAY_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXLINKDELAY_PARMNUM)
#define SV_MINLINKTHROUGHPUT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINLINKTHROUGHPUT_PARMNUM)
#define SV_LINKINFOVALIDTIME_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_LINKINFOVALIDTIME_PARMNUM)
#define SV_SCAVQOSINFOUPDATETIME_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SCAVQOSINFOUPDATETIME_PARMNUM)
#define SV_MAXWORKITEMIDLETIME_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXWORKITEMIDLETIME_PARMNUM)
#define SV_MAXRAWWORKITEMS_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXRAWWORKITEMS_PARMNUM)
#define SV_PRODUCTTYPE_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_PRODUCTTYPE_PARMNUM)
#define SV_SERVERSIZE_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_SERVERSIZE_PARMNUM)
#define SV_CONNECTIONLESSAUTODISC_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_CONNECTIONLESSAUTODISC_PARMNUM)
#define SV_SHARINGVIOLATIONRETRIES_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_SHARINGVIOLATIONRETRIES_PARMNUM)
#define SV_SHARINGVIOLATIONDELAY_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_SHARINGVIOLATIONDELAY_PARMNUM)
#define SV_MAXGLOBALOPENSEARCH_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXGLOBALOPENSEARCH_PARMNUM)
#define SV_REMOVEDUPLICATESEARCHES_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_REMOVEDUPLICATESEARCHES_PARMNUM)
#define SV_LOCKVIOLATIONRETRIES_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_LOCKVIOLATIONRETRIES_PARMNUM)
#define SV_LOCKVIOLATIONOFFSET_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_LOCKVIOLATIONOFFSET_PARMNUM)
#define SV_LOCKVIOLATIONDELAY_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_LOCKVIOLATIONDELAY_PARMNUM)
#define SV_MDLREADSWITCHOVER_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_MDLREADSWITCHOVER_PARMNUM)
#define SV_CACHEDOPENLIMIT_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_CACHEDOPENLIMIT_PARMNUM)
#define SV_CRITICALTHREADS_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_CRITICALTHREADS_PARMNUM)
#define SV_RESTRICTNULLSESSACCESS_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_RESTRICTNULLSESSACCESS_PARMNUM)
#define SV_ENABLEWFW311DIRECTIPX_INFOLOEVEL (PARMNUM_BASE_INFOLEVEL+SV_ENABLEWFW311DIRECTIPX_PARMNUM)
#define SV_OTHERQUEUEAFFINITY_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_OTHERQUEUEAFFINITY_PARMNUM)
#define SV_QUEUESAMPLESECS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_QUEUESAMPLESECS_PARMNUM)
#define SV_BALANCECOUNT_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_BALANCECOUNT_PARMNUM)
#define SV_PREFERREDAFFINITY_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_PREFERREDAFFINITY_PARMNUM)
#define SV_MAXFREERFCBS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXFREERFCBS_PARMNUM)
#define SV_MAXFREEMFCBS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXFREEMFCBS_PARMNUM)
#define SV_MAXFREELFCBS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXFREELFCBS_PARMNUM)
#define SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM)
#define SV_MINPAGEDPOOLCHUNKSIZE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM)
#define SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM)
#define SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM)
#define SV_MAXTHREADSPERQUEUE_INFOLEVEL (PARMNUM_BASE_INFOLEVEL+SV_MAXTHREADSPERQUEUE_PARMNUM)
#ifdef __cplusplus
}
#endif
#endif
