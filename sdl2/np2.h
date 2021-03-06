enum {
	MMXFLAG_DISABLE		= 1,
	MMXFLAG_NOTSUPPORT	= 2
};

enum {
	INTERP_NEAREST		= 0,
	INTERP_TILES		= 1,
	INTERP_BILINEAR		= 2,
	INTERP_HYPER		= 3
};

extern char hddfolder[MAX_PATH];
extern char fddfolder[MAX_PATH];
extern char bmpfilefolder[MAX_PATH];
extern UINT bmpfilenumber;
extern char modulefile[MAX_PATH];
extern char draw32bit;

enum {
	IMAGETYPE_UNKNOWN	= 0,
	IMAGETYPE_FDD,
	IMAGETYPE_SASI_IDE,
	IMAGETYPE_SASI_IDE_CD,
	IMAGETYPE_SCSI,
};

#if defined(__LIBRETRO__)
typedef struct {
	UINT8	NOWAIT;
	UINT8	DRAW_SKIP;

	UINT8	KEYBOARD;

	UINT16	lrjoybtn[12];

	UINT8	resume;
	UINT8	jastsnd;
	UINT8	I286SAVE;

	UINT8	snddrv;
	char	MIDIDEV[2][MAX_PATH];
	UINT32	MIDIWAIT;
} NP2OSCFG;

enum {
	FULLSCREEN_WIDTH	= 640,
	FULLSCREEN_HEIGHT	= 480
};

extern	NP2OSCFG	np2oscfg;

extern int np2_main(int argc, char *argv[]);
extern int np2_end();

extern int mmxflag;
int havemmx(void);

#else	/* __LIBRETRO__ */
#include <signal.h>

#include "joymng.h"

typedef struct {
	UINT8	NOWAIT;
	UINT8	DRAW_SKIP;

	UINT8	KEYBOARD;

	UINT8	JOYPAD1;
	UINT8	JOYPAD2;
	UINT8	JOY1BTN[JOY_NBUTTON];
	UINT8	JOYAXISMAP[2][JOY_NAXIS];
	UINT8	JOYBTNMAP[2][JOY_NBUTTON];
	char	JOYDEV[2][MAX_PATH];

	UINT8	resume;
	UINT8	jastsnd;
	UINT8	I286SAVE;

	UINT8	snddrv;
	char	MIDIDEV[2][MAX_PATH];
	UINT32	MIDIWAIT;
} NP2OSCFG;

#if defined(NP2_SIZE_QVGA)
enum {
	FULLSCREEN_WIDTH	= 320,
	FULLSCREEN_HEIGHT	= 240
};
#else
enum {
	FULLSCREEN_WIDTH	= 640,
	FULLSCREEN_HEIGHT	= 480
};
#endif

extern	NP2OSCFG	np2oscfg;

extern BOOL s98logging;
extern int s98log_count;

extern int np2_main(int argc, char *argv[]);
extern int np2_end();
#endif	/* __LIBRETRO__ */

