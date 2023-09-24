/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Fira Code:size=10" };
/* Dracula theme */
static const char dark_grey[]       = "#282A36";
static const char medium_grey[]     = "#4D4D4D";
static const char light_grey[]      = "#BFBFBF";
static const char white[]           = "#E6E6E6";
static const char purple[]          = "#BD93F9";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { light_grey,dark_grey, medium_grey },
    [SchemeSel]  = { white,     purple,    purple  },
};

/* tagging */
static const char *tags[] = { "MISC", "WEB", "STUDY", "CHAT", "DEV" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "Signal",   NULL,       NULL,       1 << 3,       0,           -1 },
    { "Anki",     NULL,       NULL,       1 << 2,       1,           -1 },
    { "mullvadbrowser",NULL,  NULL,       1 << 1,       0,           -1 },
    { "Chromium-browser",NULL,NULL,       1 << 1,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_comma,  spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_h,      incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_l,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
    { MODKEY,                       XK_space,  zoom,           {0} },
    { MODKEY,                       XK_m,      view,           {0} },
    { MODKEY|ControlMask,           XK_k,      killclient,     {0} },
    { MODKEY,                       XK_Tab,    setlayout,      {0} },
    { MODKEY|ControlMask,           XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_n,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_n,      tag,            {.ui = ~0 } },
    TAGKEYS(                        XK_z,                      0)
    TAGKEYS(                        XK_x,                      1)
    TAGKEYS(                        XK_c,                      2)
    TAGKEYS(                        XK_v,                      3)
    TAGKEYS(                        XK_b,                      4)
    { MODKEY|ControlMask,           XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

