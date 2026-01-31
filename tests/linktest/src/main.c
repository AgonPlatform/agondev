#include <assert.h>
#include <alloca.h>
#include <byteswap.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#include <agon/mos.h>
#include <agon/joystick.h>
#include <agon/timer.h>
#include <agon/keyboard.h>
#include <agon/gpio.h>
#include <agon/vdp.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"

void handler() {
  return;
}

void handler2(int x, void *ptr) {
  return;
}

int compar(const void *a, const void *b) {
  return 0;
}

int main(int argc, char ** argv) {
    int c;
    char b[1024];
    int8_t  i8;
    int16_t i16;
    int24_t i24;
    int32_t i32;
    uint8_t u8;
    uint16_t u16;
    uint24_t u24;
    uint32_t u32;
    /* --- ctype.h --- */
    c = isalnum(c);
    c = isalpha(c);
    c = iscntrl(c);
    c = isdigit(c);
    c = isgraph(c);
    c = islower(c);
    c = isprint(c);
    c = ispunct(c);
    c = isspace(c);
    c = isupper(c);
    c = tolower(c);
    c = toupper(c);
    c = isascii(c);
    c = isxdigit(c);
    c = isblank(c);

    if(isblank(c)) { printf("Blank");}
    /* --- errno.h --- */
    //errno = 0;

    /* --- fenv.h --- */
    fexcept_t *fet;
    fenv_t *fenvt;

    feclearexcept(0);
    fegetexceptflag(fet, 0);
    feraiseexcept(0);
    fesetexceptflag(fet, 0);
    fetestexcept(0);
    fegetround();
    fesetround(0);
    fegetenv(fenvt);
    feholdexcept(fenvt);
    fesetenv(fenvt);
    feupdateenv(fenvt);

    /* --- inttypes.h --- */
    intmax_t imax;
    imaxdiv_t imaxdivt; 
    imax = imaxabs(imax);
    imaxdivt = imaxdiv(imax, imax);

    /* --- math.h --- */
    double d;
    float f;
    long double ld;
    _isinff(0.0);
     _isnanf(0.0);
     _isnormalf(0.0);
     _isfinitef(0.0);
    acos(0.0);
    acosf(0.0);
    acosl(0.0);
    acosh(0.0);
    acoshf(0.0);
    acoshl(0.0);
    asin(0.0);
    asinf(0.0);
    asinl(0.0);
    asinh(0.0);
    asinhf(0.0);
    asinhl(0.0);
    atan(0.0);
    atanf(0.0);
    atanl(0.0);
    atan2(0.0, 0.0);
    atan2f(0.0, 0.0);
    atan2l(0.0, 0.0);
    atanh(0.0);
    atanhf(0.0);
    atanhl(0.0);
    cbrt(0.0);
    cbrtf(0.0);
    cbrtl(0.0);
    ceil(0.0);
    ceilf(0.0);
    ceill(0.0);
    copysign(0.0, 0.0);
    copysignf(0.0, 0.0);
    copysignl(0.0, 0.0);
    cos(0.0);
    cosf(0.0);
    cosl(0.0);
    cosh(0.0);
    coshf(0.0);
    coshl(0.0);
    erf(0.0);
    erff(0.0);
    erfl(0.0);
    erfc(0.0);
    erfcf(0.0);
    erfcl(0.0);
    exp(0.0);
    expf(0.0);
    expl(0.0);
    exp2(0.0);
    exp2f(0.0);
    exp2l(0.0);
    expm1(0.0);
    expm1f(0.0);
    expm1l(0.0);
    fabs(0.0);
    fabsf(0.0);
    fabsl(0.0);
    fdim(0.0, 0.0);
    fdimf(0.0, 0.0);
    fdiml(0.0, 0.0);
    floor(0.0);
    floorf(0.0);
    floorl(0.0);
    fma(0.0, 0.0, 0.0);
    fmaf(0.0, 0.0, 0.0);
    fmal(0.0, 0.0, 0.0);
    fmax(0.0, 0.0);
    fmaxf(0.0, 0.0);
    fmaxl(0.0, 0.0);
    fmin(0.0, 0.0);
    fminf(0.0, 0.0);
    fminl(0.0, 0.0);
    fmod(0.0, 0.0);
    fmodf(0.0, 0.0);
    fmodl(0.0, 0.0);
    frexp(0.0, &c);
    frexpf(0.0, &c);
    frexpl(0.0, &c);
    hypot(0.0, 0.0);
    hypotf(0.0, 0.0);
    hypotl(0.0, 0.0);
    ilogb(0.0);
    ilogbf(0.0);
    ilogbl(0.0);
    ldexp(0.0, 0);
    ldexpf(0.0, 0);
    ldexpl(0.0, 0);
    lgamma(0.0);
    lgammaf(0.0);
    lgammal(0.0);
    llrint(0.0);
    llrintf(0.0);
    llrintl(0.0);
    llround(0.0);
    llroundf(0.0);
    llroundl(0.0);
    log(0.0);
    logf(0.0);
    logl(0.0);
    log10(0.0);
    log10f(0.0);
    log10l(0.0);
    log1p(0.0);
    log1pf(0.0);
    log1pl(0.0);
    log2(0.0);
    log2f(0.0);
    log2l(0.0);
    logb(0.0);
    logbf(0.0);
    logbl(0.0);
    lrint(0.0);
    lrintf(0.0);
    lrintl(0.0);
    lround(0.0);
    lroundf(0.0);
    lroundl(0.0);
    modf(0.0, &d);
    modff(0.0, &f);
    modfl(0.0, &ld);
    nan("nan");
    nanf("nan");
    nanl("nan");
    nearbyint(0.0);
    nearbyintf(0.0);
    nearbyintl(0.0);
    nextafter(0.0, 0.0);
    nextafterf(0.0, 0.0);
    nextafterl(0.0, 0.0);
    nexttoward(0.0, 0.0);
    nexttowardf(0.0, 0.0);
    nexttowardl(0.0, 0.0);
    pow(0.0, 0.0);
    powf(0.0, 0.0);
    powl(0.0, 0.0);
    remainder(0.0, 0.0);
    remainderf(0.0, 0.0);
    remainderl(0.0, 0.0);
    remquo(0.0, 0.0, &c);
    remquof(0.0, 0.0, &c);
    remquol(0.0, 0.0, &c);
    rint(0.0);
    rintf(0.0);
    rintl(0.0);
    round(0.0);
    roundf(0.0);
    roundl(0.0);
    roundeven(0.0);
    roundevenf(0.0);
    roundevenl(0.0);
    scalbln(0.0, 0);
    scalblnf(0.0, 0);
    scalblnl(0.0, 0);
    scalbn(0.0, 0);
    scalbnf(0.0, 0);
    scalbnl(0.0, 0);
    sin(0.0);
    sinf(0.0);
    sinl(0.0);
    sinh(0.0);
    sinhf(0.0);
    sinhl(0.0);
    sqrt(0.0);
    sqrtf(0.0);
    sqrtl(0.0);
    tan(0.0);
    tanf(0.0);
    tanl(0.0);
    tanh(0.0);
    tanhf(0.0);
    tanhl(0.0);
    tgamma(0.0);
    tgammaf(0.0);
    tgammal(0.0);
    trunc(0.0);
    truncf(0.0);
    truncl(0.0);

    /* --- setjmp.h --- */
    jmp_buf jbuf;
    setjmp(jbuf);
    longjmp(jbuf, 0);

    /* --- agon/gpio.h --- */
    outputMode(0,0); // Set one numbered pin (0-7) of a specified port as output pin
    outputModePinID(0); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as output pin

    inputMode(0,0); // Set one numbered pin (0-7) of a specified port as input pin
    inputModePinID(0); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as input pin

    outputHigh(0,0); // Set one numbered pin (0-7) of a specified port as High (1)
    outputHighPinID(0); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as High (1)

    outputLow(0,0); // Set one numbered pin (0-7) of a specified port as Low (0)
    outputLowPinID(0); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as Low (0)

    input(0,0); // Read logical state from a numbered pin (0-7) of a specified port
    inputPinID(0); // FAST - Read logical state from a single pinID

    inputPort(0); // Read the entire port from B (PB_DR), C (PB_DR) or D (PB_DR)

    /* --- agon/keyboard.h --- */
    struct keyboard_event_t *kbe;
    kbuf_init(0);
    kbuf_poll_event(kbe);
    kbuf_clear();
    kbuf_deinit();

    /* --- stdio.h --- */
    FILE *fp = fopen(0, 0);
    fclose(fp);
    fflush(fp);
    ferror(fp);
    feof(fp);
    fputs("test", fp);

    fread(0, 0, 0, fp);
    fwrite(0, 0, 0, fp);
    long t = ftell(fp);
    fseek(fp, 0, 0);

    fgetc(fp);
    fputc('a', fp);
    fgets(b, 1, fp);
    remove("filename");
    fgetsize(fp);
  
    getchar();
    putchar('a');
    puts("Test");
  
    printf("Test");
    snprintf(b, 1024, "Test");
    sprintf(b, "Test");
    fprintf(fp, "Test");

    gets_s("test", 1);

    scanf("%d", &c);
    sscanf(b, "%d", &c);
    fscanf(fp, "%d", &c);
    freopen("filename", "mode", fp);
    ungetc(c, fp);
 
    /* --- alloca.h --- */
    alloca(0);

    /* --- assert.h --- */
    //struct __assert_loc *__loc;
    //__assert_fail_loc(__loc);

    /* --- byteswap.h --- */
    bswap_16(0);
    bswap_32(0);
    bswap_64(0);

    /* --- stdlib.h --- */
    void *ptr;
    calloc(0,0);
    malloc(0);
    realloc(ptr, 0);
    free(ptr);
    atof("bla");
    atoi("bla");
    atol("bla");
    atoll("bla");
    strtof("bla", argv);
    strtod("bla", argv);
    strtol("bla", argv, 0);
    strtoll("bla", argv, 0);
    strtoul("bla", argv, 0);
    strtoull("bla", argv, 0);
    srand(0);
    rand();
    bsearch(0, 0, 0, 0, compar);
    qsort(0, 0, 0, compar);
    abort();
    atexit(handler);
    on_exit(handler2, 0);
    exit(0);
    at_quick_exit(handler);
    quick_exit(0);
    _Exit(0);
    abs(0);
    labs(0);
    llabs(0);
    div(0,0);
    ldiv(0,0);
    lldiv(0,0);

    /* --- string.h --- */
    memcpy(0,0,1);
    memmove(0,0,1);
    memset(0,1,1);
    memcmp(0,0,1);
    memchr(0,1,1);
    strcpy(b,b);
    strncpy(b,b,1);
    strcat(b,b);
    strncat(b,b,1);
    strchr(b,1);
    strrchr(b,1);
    strpbrk(b,b);
    strstr(b,b);
    strtok(b,b);
    strdup(b);
    strndup(b,1);
    strcspn(b,b);
    strspn(b,b);
    strlen(b);
    strnlen(b,1);
    strcmp(b,b);
    strncmp(b,b,1);
    strcasecmp(b,b);
    strncasecmp(b,b,1);
    /* --- time.h --- */
    time_t time1;
    struct tm time2;

    clock();
    difftime(time1, time1);
    mktime(&time2);
    time(&time1);
    localtime(&time1);
    gmtime(&time1);
    asctime(&time2);
    ctime(&time1);

    /* --- agon/mos.h --- */
    // Generic IO
    putch(0);
    getch();
    waitvblank();
    mos_puts(b,1,0);

    // Get system variables
    getsysvar_time();
    getsysvar_vdp_pflags();
    getsysvar_keyascii();
    getsysvar_keymods();
    getsysvar_cursorX();
    getsysvar_cursorY();
    getsysvar_scrchar();
    getsysvar_scrpixel();
    getsysvar_audioChannel();
    getsysvar_audioSuccess();
    getsysvar_scrwidth();
    getsysvar_scrheight();
    getsysvar_scrCols();
    getsysvar_scrRows();
    getsysvar_scrColours();
    getsysvar_scrpixelIndex();
    getsysvar_vkeycode();
    getsysvar_vkeydown();
    getsysvar_vkeycount();
    getsysvar_rtc();  // mos_getrtc() needs to be called to update the values
    getsysvar_keydelay();
    getsysvar_keyrate();
    getsysvar_keyled();
    getsysvar_mouseX();
    getsysvar_mouseY();
    getsysvar_mouseButtons();
    getsysvar_mouseWheel();
    getsysvar_mouseXDelta();
    getsysvar_mouseYDelta();

    // MOS API calls - https://agonconsole8.github.io/agon-docs/MOS-API/ for details
    mos_load("filename",0,1);
    mos_save("filename",0,1);
    mos_cd("path");
    mos_dir("path");
    mos_del("filename");
    mos_ren("old","new");
    mos_copy("src", "dst");
    mos_mkdir("path");
    mos_sysvars();
    mos_editline(b,1,0);
    mos_fopen("filename", 0);   // returns filehandle, or 0 on error
    mos_fclose(0);                                     // returns number of still open files
    mos_fgetc(0);                                          // returns character from file, or 0 on error
    mos_fputc(0,'a');                          // writes character to file
    mos_feof(0);                                       // returns 1 if EOF, 0 otherwise
    mos_getError(0, b, 1);
    mos_oscli("cmd", argv, 2);
    mos_getrtc(b);
    mos_setrtc(&u8);
    mos_setintvector(u8, handler);

    UART uartsettings;
    mos_uopen(&uartsettings);
    mos_uclose();
    mos_ugetc();                              // 0-255 valid character - >255 error
    mos_ugetc_nb();
    mos_uputc(c);                           // returns 0 if error
    mos_fread(u8, b, 1);
    mos_fwrite(u8, b, 1);
    mos_flseek(u8, 1);
    mos_getfil(u8);
    mos_setkbvector(handler, u8);   // length 0:24bit, 1:16bit
    mos_getkbmap(); // returns address of the keyboard map
    mos_i2c_open(u8);
    mos_i2c_close();
    mos_i2c_write(0,0, (unsigned char*)b);
    mos_i2c_read(0,0, (unsigned char*)b); 
    vdp_time_t vtb;
    mos_unpackrtc(&vtb, 0); // MOS 3.0+
    mos_flseek_p(0,0); // MOS 3.0+

    // String functions
    mos_pmatch("pattern", "string", 0); // MOS 3.0+
    mos_getargument(argv, argv, "src", 0); // MOS 3.0+
    mos_extractstring(argv, argv, "src", b, 0);; // MOS 3.0+
    uint24_t result;
    mos_extractnumber(&result, argv, "src", "dvd", 0); // MOS 3.0+
    mos_escapestring(&result, "src", b, 0); // MOS 3.0+

    // System variables and string translations
    mos_setvarval(b, (void*)&result, argv, &u8); // MOS 3.0+
    mos_readvarval("pattern", (void*)&result, argv, &c, &u8); // MOS 3.0+
    mos_gsinit("src", argv, 0); // MOS 3.0+
    mos_gsread(b, argv); // MOS 3.0+
    mos_gstrans(b, b, 0, &c, 0); // MOS 3.0+
    mos_substituteargs(b, b, b, 0, 0); // MOS 3.0+

    // File path functions
    DIR dir;
    mos_resolvepath(b, b, &c, &u8, &dir, 0); // MOS 3.0+
    mos_getdirforpath(b, b, &c, 0); // MOS 3.0+
    mos_getleafname("path"); // MOS 3.0+
    mos_isdirectory("path"); // MOS 3.0+
    mos_getabsolutepath("path", b, &c); // MOS 3.0+

    // VDP protocol, and miscellaneous functions
    mos_clearvdpflags(0); // MOS 3.0+
    mos_waitforvdpflags(0); // MOS 3.0+

    // Low-level SD card access
    sd_getunlockcode(); // MOS 3.0+
    sd_init(0); // MOS 3.0+
    sd_readblocks(0, &u8, u24); // MOS 3.0+
    sd_writeblocks(0, &u8, u24); // MOS 3.0+

    // MOS FatFS commands
    FIL *fh;
    DIR *dir_handle;
    FILINFO *fil_handle;
    FATFS *fs;

    ffs_fopen(fh, "filename", 0); // MOS 1.03+, returns fresult
    ffs_fclose(fh); // MOS 1.03+, returns fresult
    ffs_fread(fh, b, 0); // MOS 1.03+, returns number of bytes read
    ffs_fwrite(fh, b, 0); // MOS 1.03+, returns number of bytes written
    ffs_flseek(fh, 0); // MOS 1.03+, returns fresult
    ffs_ftruncate(fh); // MOS 2.3.0+, returns fresult
    ffs_fsync(fh); // MOS 3.0+, returns fresult
    ffs_fgets(fh, b, 0); // MOS 3.0+, returns pointer to the target buffer, or NULL if an error occurred
    ffs_fputc(fh, 'a'); // MOS 3.0+, returns number of bytes written
    ffs_fputs(fh, "string"); // MOS 3.0+, returns number of bytes written
    ffs_fprintf (fh, "string");
    ffs_ftell(fh, &u32); // MOS 3.0+, returns fresult
    ffs_feof(fh); // MOS 3.0+, returns 1 if at the end of the file, otherwise 0
    ffs_fsize(fh, &u32); // MOS 3.0+, returns fresult
    ffs_ferror(fh); // MOS 3.0+, returns fresult
    ffs_dopen(dir_handle, "path"); // MOS 2.2.0+, returns fresult
    ffs_dclose(dir_handle); // MOS 2.2.0+, returns fresult
    ffs_dread(dir_handle, fil_handle); // MOS 2.2.0+, returns fresult
    ffs_dfindfirst(dir_handle, fil_handle, "path", "pattern"); // MOS 3.0+, returns fresult
    ffs_dfindnext(dir_handle, fil_handle); // MOS 3.0+, returns fresult
    ffs_stat(fil_handle, "filename"); // MOS 1.03+, returns fresult
    ffs_unlink("path"); // MOS 3.0+, returns fresult
    ffs_rename("path", "path"); // MOS 3.0+, returns fresult
    ffs_mkdir("path"); // MOS 3.0+, returns fresult
    ffs_chdir("path"); // MOS 3.0+, returns fresult
    ffs_getcwd("path", 0); // MOS 2.2.0+, returns fresult
    ffs_mount(fs, "path", 0); // MOS 3.0+, returns fresult
    ffs_getfree("path", &u32, &u32); // MOS 3.0+, returns fresult
    ffs_getlabel("path", "label", &u32); // MOS 3.0+, returns fresult
    ffs_setlabel("label"); // MOS 3.0+, returns fresult
    ffs_flseek_p(fh, &u32); // MOS 3.0+, returns status code

    /* --- agon/timer.h --- */
    delay(0); // Blocking delay of <ms> milliseconds, makes use of timer0

    /* --- agon/vdp.h --- */
    // ========= VDU Commands ==========
    vdp_vdu_init();
    vdp_send_to_printer('a');
    vdp_enable_printer();
    vdp_disable_printer();
    vdp_write_at_text_cursor();
    vdp_write_at_graphics_cursor();
    vdp_enable_screen();
    vdp_bell();
    vdp_cursor_left();
    vdp_cursor_right();
    vdp_cursor_down();
    vdp_cursor_up();
    vdp_clear_screen();
    vdp_carriage_return();
    vdp_page_mode_on();
    vdp_page_mode_off();
    vdp_clear_graphics();
    vdp_set_text_colour( 0 );
    vdp_set_text_bg_colour( 0 ); // Automatically adds the BACKGROUND_COL_OFFSET offset to any given color
    vdp_set_graphics_colour( 0, 0 ); // colour 0-127 fg, 128-255 bg
    vdp_set_graphics_fg_colour( 0, 0 );
    vdp_set_graphics_bg_colour( 0, 0 );
    vdp_define_colour(0, 0,0,0,0);
    vdp_reset_graphics();
    vdp_disable_screen();
    vdp_mode(0);
    vdp_redefine_character(0,0,0,0,0,0,0,0,0);
    vdp_cursor_enable( true );
    vdp_scroll_screen(0,0);
    vdp_scroll_screen_extent(0,0,0);
    vdp_cursor_behaviour(0,0);
    vdp_set_line_thickness(0);
    vdp_set_graphics_viewport(0,0,0,0);
    vdp_plot( 0, 0, 0 );
    vdp_move_to( 0, 0 );
    vdp_line_to( 0, 0 );
    vdp_line(01, 01, 02, 02); // Line between (x1,y1) and (x2,y2), no need to first do vdp_move_to
    vdp_line_fill_leftright_to_nonbg( 0, 0 ); // Line fill left and right to non-background (from (x,y))
    vdp_line_fill_leftright_to_fg( 0, 0 ); // Line fill left and right to foreground (from (x,y))
    vdp_line_fill_right_to_bg( 0, 0 ); // Line fill right to background (from (x,y))
    vdp_line_fill_right_to_nonfg( 0, 0 ); // Line fill right to non-foreground (from (x,y))
    vdp_dotdash_line_to( 0, 0 );
    vdp_dotdash_line(01, 01, 02, 02); // Dotdash line between (x1,y1) and (x2,y2), no need to first do vdp_move_to
    vdp_set_dotdash_line_pattern(0,0,0,0,0,0,0,0); // VDU 23, 6, n1, n2, n3, n4, n5, n6, n7, n8: Set dotted line pattern
    vdp_set_dotdash_pattern_length(0); // VDU 23, 0, &F2, n: Set dot-dash pattern length
    vdp_point( 0, 0 );
    vdp_triangle( 01, 01, 02, 02, 03, 03 ); // Outline triangle between (x1,y1) - (x2,y2) - (x3,y3)
    vdp_filled_triangle( 01, 01, 02, 02, 03, 03 ); // Filled triangle between (x1,y1) - (x2,y2) - (x3,y3)
    vdp_circle( 0, 0, 0); // Outline circle centered at (x,y), with a given radius
    vdp_filled_circle( 0, 0, 0); // Filled circle centered at (x,y), with a given radius
    vdp_arc( 0,0,01, 01, 02, 02); // Draws an ARC using centre (centre_x, centre_y), and two points on the circumference of a circle
    vdp_segment(0,0,01, 01, 02, 02); // Draws a circle segment using centre (centre_x, centre_y), and two points on the circumference of a circle
    vdp_sector( 0,0,01, 01, 02, 02); // Draws an circle sector using centre (centre_x, centre_y), and two points on the circumference of a circle
    vdp_rectangle( 01, 01, 02, 02 ); // Outline rectangle between (x1,y1) and (x2,y2)
    vdp_filled_rectangle( 01, 01, 02, 02 ); // Filled rectangle between (x1,y1) and (x2,y2)
    vdp_parallelogram( 01, 01, 02, 02, 03, 03); // Outline parallelogram - use three SEQUENTIAL points (A-B-C, B-C-D, or C-D-A)
    vdp_filled_parallelogram( 01, 01, 02, 02, 03, 03); // Filled parallelogram. Point 4 will be calculated by VDP
    vdp_copy_rectangle( 0,0,0,0,0,0);
    vdp_move_rectangle( 0,0,0,0,0,0);
    vdp_fill_path(&c, 0); // Fill path using coordinates in the given array. Send the entire size of the array using sizeof(path)
    vdp_plot_bitmap(0, 0);
    vdp_reset_viewports();
    vdp_set_text_viewport(0,0,0,0);
    vdp_graphics_origin( 0, 0 );
    vdp_cursor_home();
    vdp_cursor_tab(0,0);
    vdp_set_cursor_start_line( 0 );
    vdp_set_cursor_end_line( 0 );
    vdp_set_keyboard_locale(0);
    vdp_request_text_cursor_position(true);
    vdp_return_text_cursor_position(&u8,&u8);
    vdp_request_ascii_code_at_position( 0, 0, true);
    vdp_return_ascii_code_at_position( 0, 0 );
    vdp_request_pixel_colour( 0, 0, true);
    vdp_return_pixel_colour( 0, 0 );
    vdp_get_scr_dims( true );
    vdp_request_rtc(true);
    vdp_keyboard_control( 0, 0, 0);
    vdp_set_cursor_start_column( 0 );
    vdp_set_cursor_end_column( 0 );
    vdp_move_cursor_relative( 0, 0 );
    vdp_redefine_character_special( 0,0,0,0,0,0,0,0,0);
    vdp_define_character( 0, &u8); // uses VDP2.3.0 redefine special char 23,0,0x90
    vdp_reset_system_font();
    vdp_map_char_to_bitmap( 0,0);
    vdp_request_ascii_code_at_graphics_position( 0, 0, true);
    vdp_return_ascii_code_at_graphics_position( 0, 0 );
    vdp_request_palette_entry( 0, true);
    vdp_return_palette_entry_colour( 0 );
    vdp_return_palette_entry_index( 0 );
    vdp_control_keys( true);
    vdp_set_text_viewport_via_plot();
    vdp_set_graphics_viewport_via_plot();
    vdp_set_graphics_origin_via_plot();
    vdp_move_graphics_origin_and_viewport();
    vdp_logical_scr_dims( true );
    vdp_set_pixel_coordinates(); // VDU 23, 0, &C0, 0
    vdp_set_logical_coordinates(); // VDU 23, 0 &C0, 1
    vdp_legacy_modes( true);
    vdp_get_scr_dims( true);
    vdp_swap();
    vdp_flush_drawing_commands();
    vdp_console_mode( true);
    vdp_terminal_mode();
    vdp_select_bitmap( 0 );
    vdp_load_bitmap( 0, 0, &u8);
    vdp_load_bitmap_file( "filename", 0, 0 );
    vdp_capture_bitmap(0,0,0,0,0);
    vdp_solid_bitmap( 0, 0, 0,0,0,0);
    vdp_draw_bitmap( 0, 0 );
    vdp_adv_select_bitmap(0);
    vdp_adv_bitmap_from_buffer(0, 0, 0);
    vdp_select_sprite( 0 );
    vdp_clear_sprite();
    vdp_add_sprite_bitmap( 0 );
    vdp_activate_sprites( 0 );
    vdp_next_sprite_frame();
    vdp_prev_sprite_frame();
    vdp_nth_sprite_frame( 0 );
    vdp_show_sprite();
    vdp_hide_sprite();
    vdp_move_sprite_to( 0, 0 );
    vdp_move_sprite_by( 0, 0 );
    vdp_refresh_sprites();
    vdp_reset_sprites();
    vdp_reset_sprites_only();
    vdp_replace_sprite_frame(0);
    vdp_set_sprite_paint_mode( 0 );
    vdp_adv_add_sprite_bitmap(0);
    vdp_load_sprite_bitmaps("name" , "format", 0,0,0,0);
    vdp_create_sprite(0,0,0);
    vdp_set_hardware_sprite();
    vdp_set_software_sprite();
    vdp_adv_write_block(0, 0);
    vdp_adv_write_block_data(0, 0, b);
    vdp_adv_call_buffer(0);
    vdp_adv_clear_buffer(0);
    vdp_adv_create(0, 0);
    vdp_adv_stream(0);
    vdp_adv_adjust(0, 0,0);
    vdp_adv_call_conditional(0, 0,0,0);
    vdp_adv_jump_buffer(0);
    vdp_adv_call_conditional(0, 0,0,0);
    vdp_adv_jump_offset( 0, 0);
    vdp_adv_jump_offset_block( 0, 0,0);
    vdp_adv_jump_offset_conditional( 0, 0);
    vdp_adv_jump_offset_block_conditional( 0, 0,0);
    vdp_adv_call_offset( 0, 0);
    vdp_adv_call_offset_block( 0, 0,0);
    vdp_adv_call_offset_conditional( 0, 0);
    vdp_adv_call_offset_block_conditional( 0, 0,0);
    vdp_adv_copy_multiple( 0, 0 );
    vdp_adv_consolidate(0);
    vdp_adv_split( 0, 0);
    vdp_adv_split_multiple( 0, 0, 0);
    vdp_adv_split_multiple_from( 0, 0,0);
    vdp_adv_split_by_width( 0, 0, 0);
    vdp_adv_split_by_width_multiple( 0, 0, 0);
    vdp_adv_split_by_width_multiple_from( 0, 0, 0,0);
    vdp_adv_spread_multiple( 0, 0);
    vdp_adv_spread_multiple_from( 0, 0);
    vdp_adv_reverse_block_order( 0 );
    vdp_adv_reverse_block_data( 0, 0,0,0);
    vdp_adv_copy_multiple_by_reference( 0, 0);
    vdp_adv_copy_multiple_consolidate( 0, 0);
    vdp_adv_compress_buffer( 0,0);
    vdp_adv_decompress_buffer( 0,0);
    vdp_adv_load_sprite_bitmaps( "prefix", "format", 0,0,0,0);
    vdp_adv_create_sprite( 0,0,0);
    vdp_audio_play_note( 0, 0, 0, 0);
    vdp_audio_play_sample( 0, 0);
    vdp_audio_status( 0 );
    vdp_audio_set_volume( 0, 0 );
    vdp_audio_set_frequency( 0, 0 );
    vdp_audio_set_waveform( 0, 0);
    vdp_audio_set_sample( 0, 0 );
    vdp_audio_load_sample( 0, 0, &u8);
    vdp_audio_clear_sample( 0 );
    vdp_audio_create_sample_from_buffer( 0, 0, 0);
    vdp_audio_set_sample_frequency( 0, 0 );
    vdp_audio_set_buffer_frequency( 0, 0, 0 );
    vdp_audio_set_sample_repeat_start( 0, 0 );
    vdp_audio_set_buffer_repeat_start( 0, 0, 0 );
    vdp_audio_set_sample_repeat_length( 0, 0 );
    vdp_audio_set_buffer_repeat_length( 0, 0, 0 );
    vdp_audio_volume_envelope_disable( 0 );
    vdp_audio_volume_envelope_ADSR( 0, 0, 0, 0, 0 );
    vdp_audio_volume_envelope_multiphase_ADSR( 0 ); // variable length parameters to be send separately
    vdp_audio_frequency_envelope_disable( 0 );
    vdp_audio_frequency_envelope_stepped( 0, 0,0,0);
    vdp_audio_enable_channel( 0 );
    vdp_audio_disable_channel( 0 );
    vdp_audio_reset_channel( 0 );
    vdp_audio_sample_seek( 0, 0 );
    vdp_audio_sample_duration( 0, 0 );
    vdp_audio_sample_rate( 0, 0 );
    vdp_audio_set_waveform_parameter( 0, 0, 0 );
    vdp_context_select( 0 );
    vdp_context_delete( 0 );
    vdp_context_reset( 0 );
    vdp_context_save();
    vdp_context_restore();
    vdp_context_save_copy( 0 );
    vdp_context_restore_all();
    vdp_context_clear_stack();
    vdp_font_select( 0 , 0);
    vdp_font_create( 0, 0, 0, 0, 0 );
    vdp_font_adjust( 0, 0, 0 );
    vdp_font_delete( 0 );
    vdp_font_copy( 0 );
    vdp_mouse_enable();
    vdp_mouse_disable();
    vdp_mouse_reset();
    vdp_mouse_set_cursor( 0 );
    vdp_mouse_set_position( 0, 0 );
    vdp_mouse_sample_rate( 0 );
    vdp_mouse_resolution(0);
    vdp_mouse_scaling(0);
    vdp_mouse_acceleration(0);
    vdp_mouse_wheel_accel(0);
    vdp_mouse_set_bitmap(0,0);
    vdp_getKeyMap(0); // pass in index offset to keyboard matrix and return its (bitfield) value
    vdp_waitKeyUp(); // wait for key up state before returning (blocking)
    vdp_waitKeyDown(); // wait for key down state before returning (blocking)
    vdp_getKeyCode(); // return ascii code of single key being pressed, or 0 if none (non-blocking)
    vdp_set_variable(0,0); // VDU 23, 0, &F8, variableId; value;: Set a VDP Variable
    vdp_clear_variable(0); // VDU 23, 0, &F9, variableId;: Clear a VDP Variable
    vdp_outchar(0);
    return 0;
}

#pragma clang diagnostic pop

