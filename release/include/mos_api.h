/*
 * Title:			AGON MOS - MOS C header interface
 * Author:			Jeroen Venema
 * Created:			15/10/2022
 * Last Updated:	18/04/2025
 * 
 * Modinfo:
 * 15/10/2022:		Added putch, getch
 * 22/10/2022:		Added waitvblank, mos_f* functions
 * 10/01/2023:      Added getsysvar_cursorX/Y functions, removed generic getsysvar8/16/24bit functions
 * 25/03/2023:      Added MOS 1.03 functions / sysvars
 * 16/04/2023:      Added MOS 1.03RC4 mos_fread / mos_fwrite / mos_flseek functions
 * 19/04/2023:		Added mos_getfil
 * 02/07/2023:      Added struct / union for RTC_DATA
 * 22/07/2023:      Added structure for SYSVAR
 * 18/11/2023:		Added mos_setkbvector, mos_getkbmap, mos_i2c_open, mos_i2c_close, mos_i2c_write, mos_i2c_read
 * 05/04/2024:		Added more mos sysvars, and expanded SYSVAR struct
 * 18/04/2025:      Added the remaining ffs_* functions as defined in MOS up to version 3.0
 *                  Changed RTC_DATA to SYSVAR_RTCDATA, added vdp_time_t struct
 */

#ifndef _MOS_H
#define _MOS_H
#include <stdint.h>

// FatFS Functional configurations as set during MOS compilation (see MOS ffconf.h)
#define FFCONF_DEF	86631	/* Revision ID */
#define FF_FS_READONLY	0
#define FF_FS_MINIMIZE	0
#define FF_USE_FIND		1
#define FF_USE_MKFS		0
#define FF_USE_FASTSEEK	0
#define FF_USE_EXPAND	0
#define FF_USE_CHMOD	0
#define FF_USE_LABEL	1
#define FF_USE_FORWARD	0
#define FF_USE_STRFUNC	1
#define FF_PRINT_LLI	0
#define FF_PRINT_FLOAT	0
#define FF_STRF_ENCODE	0
#define FF_CODE_PAGE	437
#define FF_USE_LFN		2
#define FF_MAX_LFN		255
#define FF_LFN_UNICODE	0
#define FF_LFN_BUF		255
#define FF_SFN_BUF		12
#define FF_FS_RPATH		2
#define FF_VOLUMES		1
#define FF_STR_VOLUME_ID	0
#define FF_VOLUME_STRS		"RAM","NAND","CF","SD","SD2","USB","USB2","USB3"
#define FF_MULTI_PARTITION	0
#define FF_MIN_SS		512
#define FF_MAX_SS		512
#define FF_LBA64		0
#define FF_MIN_GPT		0x10000000
#define FF_USE_TRIM		0
#define FF_FS_TINY		1
#define FF_FS_EXFAT		0
#define FF_FS_NORTC		0
#define FF_NORTC_MON	1
#define FF_NORTC_MDAY	1
#define FF_NORTC_YEAR	2020
#define FF_FS_NOFSINFO	0
#define FF_FS_LOCK		0
#define FF_FS_REENTRANT	0
#define FF_FS_TIMEOUT	1000
#define FF_SYNC_t		HANDLE

// File access modes - from mos_api.inc
#define FA_READ				    0x01
#define FA_WRITE			    0x02
#define FA_OPEN_EXISTING	    0x00
#define FA_CREATE_NEW		    0x04
#define FA_CREATE_ALWAYS	    0x08
#define FA_OPEN_ALWAYS		    0x10
#define FA_OPEN_APPEND		    0x30

// I2C frequency
#define I2C_SPEED_57600			0x01
#define I2C_SPEED_115200		0x02
#define I2C_SPEED_230400		0x03
// I2C return codes to caller
#define RET_OK			        0x00
#define RET_NORESPONSE	        0x01
#define RET_DATA_NACK	        0x02
#define RET_ARB_LOST	        0x04
#define RET_BUS_ERROR	        0x08

/* FatFS File function return code (FRESULT) */

typedef enum {
    FR_OK = 0,              /* (0) Succeeded */
    FR_DISK_ERR,            /* (1) A hard error occurred in the low level disk I/O layer */
    FR_INT_ERR,             /* (2) Assertion failed */
    FR_NOT_READY,           /* (3) The physical drive cannot work */
    FR_NO_FILE,             /* (4) Could not find the file */
    FR_NO_PATH,             /* (5) Could not find the path */
    FR_INVALID_NAME,        /* (6) The path name format is invalid */
    FR_DENIED,              /* (7) Access denied due to prohibited access or directory full */
    FR_EXIST,               /* (8) Access denied due to prohibited access */
    FR_INVALID_OBJECT,      /* (9) The file/directory object is invalid */
    FR_WRITE_PROTECTED,     /* (10) The physical drive is write protected */
    FR_INVALID_DRIVE,       /* (11) The logical drive number is invalid */
    FR_NOT_ENABLED,         /* (12) The volume has no work area */
    FR_NO_FILESYSTEM,       /* (13) There is no valid FAT volume */
    FR_MKFS_ABORTED,        /* (14) The f_mkfs() aborted due to any problem */
    FR_TIMEOUT,             /* (15) Could not get a grant to access the volume within defined period */
    FR_LOCKED,              /* (16) The operation is rejected according to the file sharing policy */
    FR_NOT_ENOUGH_CORE,     /* (17) LFN working buffer could not be allocated */
    FR_TOO_MANY_OPEN_FILES, /* (18) Number of open files > FF_FS_LOCK */
    FR_INVALID_PARAMETER    /* (19) Given parameter is invalid */
} FRESULT;

// Indexes into sysvar - from mos_api.inc
#define sysvar_time			    0x00    // 4: Clock timer in centiseconds (incremented by 2 every VBLANK)
#define sysvar_vdp_pflags	    0x04    // 1: Flags to indicate completion of VDP commands
#define sysvar_keyascii		    0x05    // 1: ASCII keycode, or 0 if no key is pressed
#define sysvar_keymods		    0x06    // 1: Keycode modifiers
#define sysvar_cursorX		    0x07    // 1: Cursor X position
#define sysvar_cursorY		    0x08    // 1: Cursor Y position
#define sysvar_scrchar		    0x09    // 1: Character read from screen
#define sysvar_scrpixel		    0x0A    // 3: Pixel data read from screen (R,B,G)
#define sysvar_audioChannel	    0x0D    // 1: Audio channel
#define syscar_audioSuccess	    0x0E    // 1: Audio channel note queued (0 = no, 1 = yes)
#define sysvar_scrWidth	        0x0F	// 2: Screen width in pixels
#define sysvar_scrHeight	    0x11	// 2: Screen height in pixels
#define sysvar_scrCols		    0x13	// 1: Screen columns in characters
#define sysvar_scrRows		    0x14	// 1: Screen rows in characters
#define sysvar_scrColours	    0x15	// 1: Number of colours displayed
#define sysvar_scrpixelIndex    0x16	// 1: Index of pixel data read from screen
#define sysvar_vkeycode	        0x17	// 1: Virtual key code from FabGL
#define sysvar_vkeydown			0x18	// 1: Virtual key state from FabGL (0=up, 1=down)
#define sysvar_vkeycount	    0x19	// 1: Incremented every time a key packet is received
#define sysvar_rtc		        0x1A	// 6: Real time clock data
#define sysvar_spare            0x20    // 2: Spare, previously used by rtc
#define sysvar_keydelay	        0x22	// 2: Keyboard repeat delay
#define sysvar_keyrate		    0x24	// 2: Keyboard repeat reat
#define sysvar_keyled		    0x26	// 1: Keyboard LED status
//TODO: for scrMode and below, we need to write getters
#define sysvar_scrMode			0x27	// 1: Screen mode
#define sysvar_rtcEnable		0x28	// 1: RTC enable flag (0: disabled, 1: use ESP32 RTC)
#define sysvar_mouseX			0x29	// 2: Mouse X position
#define sysvar_mouseY			0x2B	// 2: Mouse Y position
#define sysvar_mouseButtons		0x2D	// 1: Mouse button state
#define sysvar_mouseWheel		0x2E	// 1: Mouse wheel delta
#define sysvar_mouseXDelta		0x2F	// 2: Mouse X delta
#define sysvar_mouseYDelta		0x31	// 2: Mouse Y delta
#define sysvar_gp               0x37	// 1: General poll packet data

// Flags for the VDP protocol - sysvar_vdp_pflags
#define vdp_pflag_cursor        0x01
#define vdp_pflag_scrchar       0x02
#define vdp_pflag_point         0x04
#define vdp_pflag_audio         0x08
#define vdp_pflag_mode          0x10
#define vdp_pflag_rtc           0x20
#define vdp_pflag_mouse			0x40

// Stucture for accessing sysvar RTC data used for mos_getrc / mos_setrtc
typedef struct {
    uint8_t year;               // offset since 1980
    uint8_t month;              // (0-11)
    uint8_t day;                // (1-31)
    uint8_t hour;               // (0-23)
    uint8_t minute;             // (0-59)
    uint8_t second;             // (0-59)
} SYSVAR_RTCDATA;

// Structure used in returning mos_unpackrtc MOS 3.0+
typedef struct {
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  dayOfWeek;
    uint16_t dayOfYear;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
} vdp_time_t;

// Structure for accesing SYSVAR

typedef struct {
    uint32_t time;
    uint8_t vdp_pflags;
    uint8_t keyascii;
    uint8_t keymods;
    uint8_t cursorX;
    uint8_t cursorY;
    uint8_t scrchar;
    union {
        uint24_t scrpixel;
        struct {
            uint8_t scrpixelR;
            uint8_t scrpixelB;
            uint8_t scrpixelG;
        };
    };
    uint8_t audioChannel;
    uint8_t audioSuccess;
    uint16_t scrWidth;
    uint16_t scrHeight;
    uint8_t scrCols;
    uint8_t scrRows;
    uint8_t scrColours;
    uint8_t scrpixelIndex;
    uint8_t vkeycode;
    uint8_t vkeydown;
    uint8_t vkeycount;
    SYSVAR_RTCDATA rtc;
    uint16_t spare;
    uint16_t keydelay;
    uint16_t keyrate;
    uint8_t keyled;
    uint8_t scrMode;
 	uint8_t rtcEnable;
	uint16_t mouseX;
	uint16_t mouseY;
	uint8_t mouseButtons;
	uint8_t mouseWheel;
	uint16_t mouseXDelta;
	uint16_t mouseYDelta;
} SYSVAR;


// UART settings for open_UART1
typedef struct {
   int24_t baudRate ;				    //!< The baudrate to be used.
   uint8_t dataBits ;				        //!< The number of databits per character to be used.
   uint8_t stopBits ;				        //!< The number of stopbits to be used.
   uint8_t parity ;				        //!< The parity bit option to be used.
   uint8_t flowcontrol ;
   uint8_t eir ;
} UART ;

// File Object ID and allocation information (FFOBJID)
typedef struct {
	uint24_t*   fs;		    /* Pointer to the hosting volume of this object */
	uint16_t	id;		    /* Hosting volume mount ID */
	uint8_t	    attr;		/* Object attribute */
	uint8_t	    stat;		/* Object chain status (b1-0: =0:not contiguous, =2:contiguous, =3:fragmented in this session, b2:sub-directory stretched) */
	uint32_t	sclust;	    /* Object data start cluster (0:no cluster or root directory) */
	uint32_t	objsize;    /* Object size (valid when sclust != 0) */
} FFOBJID;

// File object structure (FIL)
typedef struct {
	FFOBJID	    obj;       /* Object identifier (must be the 1st member to detect invalid object pointer) */
	uint8_t	    flag;      /* File status flags */
	uint8_t	    err;       /* Abort flag (error code) */
	uint32_t	fptr;      /* File read/write pointer (Zeroed on file open) */
	uint32_t	clust;     /* Current cluster of fpter (invalid when fptr is 0) */
	uint32_t	sect;      /* Sector number appearing in buf[] (0:invalid) */
	uint32_t	dir_sect;  /* Sector number containing the directory entry (not used at exFAT) */ 
	uint24_t*	dir_ptr;   /* Pointer to the directory entry in the win[] (not used at exFAT) */
} FIL;

/* File information structure (FILINFO) */
typedef struct {
	uint32_t	fsize;			/* File size */
	uint16_t	fdate;			/* Modified date */
	uint16_t	ftime;			/* Modified time */
	uint8_t	    fattrib;		/* File attribute */
	char	    altname[13];	/* Alternative file name */
	char	    fname[256]; 	/* Primary file name */
} FILINFO;

/* Directory information structure (DIR) */
typedef struct {
	FFOBJID	    obj;			/* Object identifier */
	uint32_t	dptr;			/* Current read/write offset */
	uint32_t	clust;			/* Current cluster */
	uint32_t	sect;			/* Current sector (0:Read operation has terminated) */
	uint8_t*	dir;			/* Pointer to the directory item in the win[] */
	uint8_t	    fn[12];			/* SFN (in/out) {body[8],ext[3],status[1]} */
	const char* pat;		    /* Pointer to the name matching pattern */
} DIR;

/* Filesystem object structure (FATFS) */
typedef struct {
	uint8_t     fs_type;		/* Filesystem type (0:not mounted) */
	uint8_t	    pdrv;			/* Associated physical drive */
	uint8_t	    n_fats;			/* Number of FATs (1 or 2) */
	uint8_t	    wflag;			/* win[] flag (b0:dirty) */
	uint8_t	    fsi_flag;		/* FSINFO flags (b7:disabled, b0:dirty) */
	uint16_t	id;				/* Volume mount ID */
	uint16_t	n_rootdir;		/* Number of root directory entries (FAT12/16) */
	uint16_t	csize;			/* Cluster size [sectors] */
#if FF_MAX_SS != FF_MIN_SS
	uint16_t	ssize;			/* Sector size (512, 1024, 2048 or 4096) */
#endif
#if FF_USE_LFN
	uint16_t*	lfnbuf;			/* LFN working buffer */
#endif
#if FF_FS_EXFAT
	uint8_t*	dirbuf;			/* Directory entry block scratchpad buffer for exFAT */
#endif
#if FF_FS_REENTRANT
	FF_SYNC_t	sobj;		    /* Identifier of sync object */
#endif
#if !FF_FS_READONLY
	uint32_t	last_clst;		/* Last allocated cluster */
	uint32_t	free_clst;		/* Number of free clusters */
#endif
#if FF_FS_RPATH
	uint32_t	cdir;			/* Current directory start cluster (0:root) */
#if FF_FS_EXFAT
	uint32_t	cdc_scl;		/* Containing directory start cluster (invalid when cdir is 0) */
	uint32_t	cdc_size;		/* b31-b8:Size of containing directory, b7-b0: Chain status */
	uint32_t	cdc_ofs;		/* Offset in the containing directory (invalid when cdir is 0) */
#endif
#endif
	uint32_t	n_fatent;		/* Number of FAT entries (number of clusters + 2) */
	uint32_t	fsize;			/* Size of an FAT [sectors] */
	uint32_t	volbase;		/* Volume base sector */
	uint32_t	fatbase;		/* FAT base sector */
	uint32_t	dirbase;		/* Root directory base sector/cluster */
	uint32_t	database;		/* Data base sector */
#if FF_FS_EXFAT
	uint32_t	bitbase;		/* Allocation bitmap base sector */
#endif
	uint32_t	winsect;		/* Current sector appearing in the win[] */
	uint8_t	    win[FF_MAX_SS];	/* Disk access window for Directory, FAT (and file data at tiny cfg) */
} FATFS;

#ifdef __cplusplus
extern "C" {
#endif

// Generic IO
extern int   putch(int a);
extern char  getch(void);
extern void  waitvblank(void);
extern void  mos_puts(char * buffer, uint24_t size, char delimiter);

// Get system variables
extern uint32_t getsysvar_time();
extern uint8_t  getsysvar_vdp_pflags();
extern uint8_t  getsysvar_keyascii();
extern uint8_t  getsysvar_keymods();
extern uint8_t  getsysvar_cursorX();
extern uint8_t  getsysvar_cursorY();
extern uint8_t  getsysvar_scrchar();
extern uint24_t getsysvar_scrpixel();
extern uint8_t  getsysvar_audioChannel();
extern uint8_t  getsysvar_audioSuccess();
extern uint16_t getsysvar_scrwidth();
extern uint16_t getsysvar_scrheight();
extern uint8_t  getsysvar_scrCols();
extern uint8_t  getsysvar_scrRows();
extern uint8_t  getsysvar_scrColours();
extern uint8_t  getsysvar_scrpixelIndex();
extern uint8_t  getsysvar_vkeycode();
extern uint8_t  getsysvar_vkeydown();
extern uint8_t  getsysvar_vkeycount();
extern volatile SYSVAR_RTCDATA* getsysvar_rtc();  // mos_getrtc() needs to be called to update the values
extern uint16_t getsysvar_keydelay();
extern uint16_t getsysvar_keyrate();
extern uint8_t  getsysvar_keyled();

// MOS API calls - https://agonconsole8.github.io/agon-docs/MOS-API/ for details
extern uint8_t  mos_load(const char *filename, uint24_t address, uint24_t maxsize);
extern uint8_t  mos_save(const char *filename, uint24_t address, uint24_t nbytes);
extern uint8_t  mos_cd(const char *path);
extern uint8_t  mos_dir(const char *path);
extern uint8_t  mos_del(const char *filename);
extern uint8_t  mos_ren(const char *filename, const char *newname);
extern uint8_t  mos_copy(const char *source, const char *destination);
extern uint8_t  mos_mkdir(const char *path);
extern uint8_t* mos_sysvars(void);
extern uint8_t  mos_editline(char *buffer, uint24_t bufferlength, uint8_t clearbuffer);
extern uint8_t  mos_fopen(const char * filename, uint8_t mode);   // returns filehandle, or 0 on error
extern uint8_t  mos_fclose(uint8_t fh);					    // returns number of still open files
extern char	    mos_fgetc(uint8_t fh);					    // returns character from file, or 0 on error
extern void	    mos_fputc(uint8_t fh, char c);			    // writes character to file
extern uint8_t  mos_feof(uint8_t fh);					    // returns 1 if EOF, 0 otherwise
extern void     mos_getError(uint8_t code, char *buffer, uint24_t bufferlength);
extern uint8_t  mos_oscli(char *command, char **argv, uint24_t argc);
extern uint8_t  mos_getrtc(char *buffer);
extern void     mos_setrtc(uint8_t *timedata);
extern void*    mos_setintvector(uint8_t vector, void(*handler)(void));
extern uint8_t  mos_uopen(UART *settings);
extern void     mos_uclose(void);
extern int      mos_ugetc(void);                              // 0-255 valid character - >255 error
extern uint8_t  mos_uputc(int a);                           // returns 0 if error
extern uint24_t mos_fread(uint8_t fh, char *buffer, uint24_t numbytes);
extern uint24_t mos_fwrite(uint8_t fh, char *buffer, uint24_t numbytes);
extern uint8_t  mos_flseek(uint8_t fh, uint32_t offset);
extern FIL*     mos_getfil(uint8_t fh);
extern void     mos_setkbvector(void(*handler)(void), uint8_t addresslength);   // length 0:24bit, 1:16bit
extern uint8_t* mos_getkbmap(void); // returns address of the keyboard map
extern void     mos_i2c_open(uint8_t frequency);
extern void     mos_i2c_close(void);
extern uint8_t  mos_i2c_write(uint8_t i2c_address, uint8_t size, unsigned char * buffer);
extern uint8_t  mos_i2c_read(uint8_t i2c_address, uint8_t size, unsigned char * buffer);
extern uint8_t  mos_port_read(uint8_t port); 	// read from the GPIO port specified
extern uint8_t  mos_port_write(uint8_t port, uint8_t data); 	// write data to the GPIO port specified
extern void     mos_unpackrtc(vdp_time_t *buffer, uint8_t flags); // MOS 3.0+
extern uint8_t  mos_flseek_p(uint8_t filehandle, uint32_t offset); // MOS 3.0+

// String functions
extern int8_t   mos_pmatch(const char *pattern, const char *string, uint8_t flags); // MOS 3.0+
extern void     mos_getargument(char **arg, char **argend, const char *source, uint24_t argnumber); // MOS 3.0+
extern uint8_t  mos_extractstring(char **result, char **next, const char *source, const char *dividers, uint8_t flags); // MOS 3.0+
extern uint8_t  mos_extractnumber(uint24_t *result, char **next, const char *source, const char *dividers, uint8_t flags); // MOS 3.0+
extern uint8_t  mos_escapestring(uint24_t *resultlength, const char *source, char *buffer, uint24_t bufferlength); // MOS 3.0+

// System variables and string translations
extern int      mos_setvarval(char * name, void * value, char ** actualName, uint8_t * type); // MOS 3.0+
extern int      mos_readvarval(char * namePattern, void * value, char ** actualName, int * length, uint8_t * typeFlag); // MOS 3.0+
extern uint8_t  mos_gsinit(const char *source, char **transinfo_ptr, uint8_t flags); // MOS 3.0+
extern uint8_t  mos_gsread(char *char_read, char **transinfo_ptr); // MOS 3.0+
extern int      mos_gstrans(char * source, char * dest, int destLen, int * read, uint8_t flags); // MOS 3.0+
extern int      mos_substituteargs(char * tpl, char * args, char * dest, int length, uint8_t flags); // MOS 3.0+

// File path functions
extern int      mos_resolvepath(char * filepath, char * resolvedPath, int * length, uint8_t * index, DIR * dir, uint8_t flags); // MOS 3.0+
extern int      mos_getdirforpath(char * srcPath, char * dir, int * length, uint8_t index); // MOS 3.0+
extern char*    mos_getleafname(const char *pathname); // MOS 3.0+
extern uint8_t  mos_isdirectory(const char *pathname); // MOS 3.0+
extern int      mos_getabsolutepath(char * path, char * resolved, int * length); // MOS 3.0+

// VDP protocol, and miscellaneous functions
extern uint8_t  mos_clearvdpflags(uint8_t bitmask); // MOS 3.0+
extern uint8_t  mos_waitforvdpflags(uint8_t bitmask); // MOS 3.0+

// Low-level SD card access
extern uint24_t sd_getunlockcode(void); // MOS 3.0+
extern uint8_t  sd_init(uint24_t unlockcode); // MOS 3.0+
extern uint8_t  sd_readblocks(uint32_t sector, uint8_t *buf, uint24_t count); // MOS 3.0+
extern uint8_t  sd_writeblocks(uint32_t sector, uint8_t *buf, uint24_t count); // MOS 3.0+

// MOS FatFS commands
extern uint8_t  ffs_fopen(FIL *fh, const char *filename, uint8_t mode); // MOS 1.03+, returns fresult
extern uint8_t  ffs_fclose(FIL *fh); // MOS 1.03+, returns fresult
extern uint24_t ffs_fread(FIL *fh, char *buffer, uint24_t numbytes); // MOS 1.03+, returns number of bytes read
extern uint24_t ffs_fwrite(FIL *fh, const char *buffer, uint24_t numbytes); // MOS 1.03+, returns number of bytes written
extern uint8_t  ffs_flseek(FIL *fh, uint32_t offset); // MOS 1.03+, returns fresult
extern uint8_t  ffs_ftruncate(FIL *fh); // MOS 2.3.0+, returns fresult
extern uint8_t  ffs_fsync(FIL *fh); // MOS 3.0+, returns fresult
extern uint8_t* ffs_fgets(FIL *fh, char *buffer, uint24_t buffersize); // MOS 3.0+, returns pointer to the target buffer, or NULL if an error occurred
extern uint24_t ffs_fputc(FIL *fh, char c); // MOS 3.0+, returns number of bytes written
extern uint24_t ffs_fputs(FIL *fh, const char *string); // MOS 3.0+, returns number of bytes written
extern int      ffs_fprintf (FIL* fp, const char* str, ...);
extern uint8_t  ffs_ftell(FIL *fh, uint32_t *result); // MOS 3.0+, returns fresult
extern uint8_t  ffs_feof(FIL *fh); // MOS 3.0+, returns 1 if at the end of the file, otherwise 0
extern uint8_t  ffs_fsize(FIL *fh, uint32_t *result); // MOS 3.0+, returns fresult
extern uint8_t  ffs_ferror(FIL *fh); // MOS 3.0+, returns fresult
extern uint8_t  ffs_dopen(DIR *dir_handle, const char * dir_path); // MOS 2.2.0+, returns fresult
extern uint8_t  ffs_dclose(DIR *dir_handle); // MOS 2.2.0+, returns fresult
extern uint8_t  ffs_dread(DIR *dir_handle, FILINFO *fil_handle); // MOS 2.2.0+, returns fresult
extern uint8_t  ffs_dfindfirst(DIR *dir_handle, FILINFO *fil_handle, const char *dirpath, const char *pattern); // MOS 3.0+, returns fresult
extern uint8_t  ffs_dfindnext(DIR *dir_handle, FILINFO *fil_handle); // MOS 3.0+, returns fresult
extern uint8_t  ffs_stat(FILINFO *fil_handle, const char *filename); // MOS 1.03+, returns fresult
extern uint8_t  ffs_unlink(const char *filepath); // MOS 3.0+, returns fresult
extern uint8_t  ffs_rename(const char *sourcefilepath, const char *destfilepath); // MOS 3.0+, returns fresult
extern uint8_t  ffs_mkdir(const char *dirname); // MOS 3.0+, returns fresult
extern uint8_t  ffs_chdir(const char *dirname); // MOS 3.0+, returns fresult
extern uint8_t  ffs_getcwd(char *dirpath, uint24_t bufferlength); // MOS 2.2.0+, returns fresult
extern uint8_t  ffs_mount(FATFS *fs, const char *volpath, uint8_t options); // MOS 3.0+, returns fresult
extern uint8_t  ffs_getfree(char *path, uint32_t *freeclusters, uint32_t *clustersize); // MOS 3.0+, returns fresult
extern uint8_t  ffs_getlabel(char *path, char *label, uint32_t *volserial); // MOS 3.0+, returns fresult
extern uint8_t  ffs_setlabel(const char *volumelabel); // MOS 3.0+, returns fresult
extern uint8_t  ffs_flseek_p(FIL *fh, uint32_t *offset); // MOS 3.0+, returns status code

//extern ffs_fforward(); - not implemented by MOS API
//extern ffs_expand(); - not implemented by MOS API
//extern ffs_chmod(); // not implemented by MOS API
//extern ffs_utime(); // not implemented by MOS API
//extern ffs_chdrive(); // not implemented by MOS API
//extern ffs_mkfs(); // not implemented by MOS API
//extern ffs_fdisk(); // not implemented by MOS API
//extern ffs_setcp(); // not implemented by MOS API

#ifdef __cplusplus
}
#endif

#endif // _MOS_H
