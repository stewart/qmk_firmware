#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

// Layers
#define QWERTY 0
#define MOD 1

// Useful shortcuts.
#define CTL_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Qwerty
	* ,-----------------------------------------------------------------------------------------------------------.
	* |  Tab   |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |    \   |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |Ctrl/Esc|    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    ;   |   '    |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |Shift/( |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   | Shift/)|
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
	* |  Ctrl  |   Gui  |        |   Alt  |  Mods  |  Space | Enter  |  Bksp  |    [   |   ]    |    -   |    _   |
	* `-----------------------------------------------------------------------------------------------------------'
	*/
	[QWERTY] = LAYOUT_planck_grid(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
		CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
		KC_LCTL, KC_LGUI, XXXXXXX, KC_LALT, MO(MOD), KC_SPC,  KC_ENT,  KC_BSPC, KC_LBRC, KC_RBRC, KC_MINS, KC_UNDS
	),

	/* Mods
	* ,----------------------------------------------------------------------------------------------------------.
	* |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |   +   |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
	* |    `   |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |   =   |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
	* |        |  Left  |  Down  |   Up   |  Right |  Home  |   End  | Pg Up  | Pg Dn  |  Vol-  |  Vol+  |  Mute |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
	* |        |        |        |        |        |        |        |        |        |  Prev  |  Next  |  Play |
	* `----------------------------------------------------------------------------------------------------------'
	*/
	[MOD] = LAYOUT_planck_grid(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL ,
		_______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_VOLD, KC_VOLU, KC_MUTE,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY
	)
};
