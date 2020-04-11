#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Tab   |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Esc   |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    ;   |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |Shift/( |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   | Shift/)|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |   Alt  |        |  Gui   | Lower  |  Space | Enter  | Raise  |    [   |   ]    |   \    |  Play  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LALT, _______, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LBRC, KC_RBRC, KC_BSLS, KC_MPLY
),

/* Lower
 * ,----------------------------------------------------------------------------------------------------------.
 * |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |  Bksp |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |  Del   |  Left  |  Down  |   Up   |  Right |        |        |    _   |    +   |    {   |    }   |   |   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        |        |        |        |        |        |        |  Prev  |  Next  |       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        |        |        |        |        |        |  Mute  |  Vol-  |  Vol+  |  Play |
 * `----------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,----------------------------------------------------------------------------------------------------------.
 * |    `   |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |  Bksp |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |  Del   |  Left  |  Down  |   Up   |  Right |        |        |    -   |    =   |    [   |    ]   |   \   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        |        |        |        |        |  Home  |   End  | Pg Up  | Pg Dn  |       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        |        |        |                 |        |  Next  |  Vol-  |  Vol+  |  Play |
 * `----------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,----------------------------------------------------------------------------------------------------------.
 * |        |  Reset |        |        |        |        |        |        |        |        |        |   Del |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        | Aud on | Audoff | AGnorm | AGswap | Qwerty |        |        |        |       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        | Voice- | Voice+ | Mus on | Musoff | MIDIon | MIDIof |        |        |        |        |       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
 * |        |        |        |        |        |                 |        |        |        |        |       |
 * `----------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }

  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
