#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 867
#define LARGE_STATE_COUNT 20
#define SYMBOL_COUNT 269
#define ALIAS_COUNT 6
#define TOKEN_COUNT 126
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 43
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 131

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BOOL = 3,
  anon_sym_LBRACK = 4,
  anon_sym_COMMA = 5,
  anon_sym_RBRACK = 6,
  sym_BAREWORD = 7,
  sym_QUOTED_STRING = 8,
  sym_NUMBER = 9,
  sym_DURATION = 10,
  sym_DISTANCE = 11,
  sym_QUANTITY = 12,
  sym_COLOR = 13,
  sym_CONSTANT = 14,
  anon_sym_include = 15,
  anon_sym_SEMI = 16,
  anon_sym_EQ = 17,
  anon_sym_add = 18,
  anon_sym_serial_dialog = 19,
  anon_sym_settings = 20,
  anon_sym_LBRACE = 21,
  anon_sym_RBRACE = 22,
  anon_sym_wrap = 23,
  anon_sym_dialog = 24,
  anon_sym_default = 25,
  anon_sym_label = 26,
  anon_sym_entity = 27,
  anon_sym_name = 28,
  anon_sym_portrait = 29,
  anon_sym_alignment = 30,
  anon_sym_border_tileset = 31,
  anon_sym_emote = 32,
  anon_sym_GT = 33,
  sym_serial_dialog_option_type = 34,
  anon_sym_script = 35,
  anon_sym_json = 36,
  anon_sym_COLON = 37,
  sym_json_number = 38,
  anon_sym_true = 39,
  anon_sym_false = 40,
  anon_sym_null = 41,
  anon_sym_debug = 42,
  anon_sym_BANG = 43,
  anon_sym_LPAREN = 44,
  anon_sym_RPAREN = 45,
  anon_sym_rand = 46,
  anon_sym_spread = 47,
  sym_return_statement = 48,
  anon_sym_load = 49,
  anon_sym_map = 50,
  anon_sym_goto = 51,
  anon_sym_index = 52,
  anon_sym_show = 53,
  anon_sym_concat = 54,
  anon_sym_delete = 55,
  anon_sym_command = 56,
  anon_sym_PLUS = 57,
  anon_sym_alias = 58,
  anon_sym_hide = 59,
  anon_sym_unhide = 60,
  anon_sym_save = 61,
  anon_sym_slot = 62,
  anon_sym_erase = 63,
  anon_sym_block = 64,
  anon_sym_wait = 65,
  anon_sym_close = 66,
  sym_player = 67,
  sym_self = 68,
  anon_sym_pause = 69,
  anon_sym_unpause = 70,
  anon_sym_camera = 71,
  anon_sym_fade = 72,
  anon_sym_DASH_GT = 73,
  anon_sym_over = 74,
  anon_sym_in = 75,
  anon_sym_out = 76,
  anon_sym_shake = 77,
  anon_sym_animation = 78,
  anon_sym_geometry = 79,
  sym_origin = 80,
  sym_length = 81,
  sym_forever = 82,
  anon_sym_position = 83,
  sym_glitched = 84,
  anon_sym_light = 85,
  anon_sym_player_control = 86,
  anon_sym_lights_control = 87,
  anon_sym_hex_editor = 88,
  anon_sym_hex_dialog_mode = 89,
  anon_sym_hex_control = 90,
  anon_sym_hex_clipboard = 91,
  anon_sym_serial_control = 92,
  anon_sym_flagName = 93,
  sym_AND = 94,
  sym_OR = 95,
  anon_sym_GT_EQ = 96,
  anon_sym_LT = 97,
  anon_sym_LT_EQ = 98,
  anon_sym_EQ_EQ = 99,
  anon_sym_BANG_EQ = 100,
  anon_sym_if = 101,
  anon_sym_else = 102,
  anon_sym_break = 103,
  anon_sym_continue = 104,
  anon_sym_while = 105,
  anon_sym_for = 106,
  anon_sym_STAR = 107,
  anon_sym_SLASH = 108,
  anon_sym_PERCENT = 109,
  anon_sym_DASH = 110,
  anon_sym_x = 111,
  anon_sym_y = 112,
  anon_sym_primary_id = 113,
  anon_sym_secondary_id = 114,
  anon_sym_primary_id_type = 115,
  anon_sym_current_animation = 116,
  anon_sym_animation_frame = 117,
  anon_sym_strafe = 118,
  anon_sym_path = 119,
  anon_sym_on_tick = 120,
  anon_sym_on_look = 121,
  anon_sym_on_interact = 122,
  sym_fail = 123,
  anon_sym_serial_connect = 124,
  anon_sym_warp_state = 125,
  sym_source_file = 126,
  sym_bool_or_identifier_expansion = 127,
  sym_bareword_expansion = 128,
  sym_quoted_string_expansion = 129,
  sym_string_expansion = 130,
  sym_number_expansion = 131,
  sym_int_or_identifier_expansion = 132,
  sym_duration_expansion = 133,
  sym_distance_expansion = 134,
  sym_quantity_expansion = 135,
  sym_color_expansion = 136,
  sym_constant_expansion = 137,
  sym_constant_value_expansion = 138,
  sym__root = 139,
  sym_include_macro = 140,
  sym_constant_assignment = 141,
  sym_add_serial_dialog_settings = 142,
  sym_serial_dialog_parameter = 143,
  sym_add_dialog_settings = 144,
  sym_dialog_settings_block = 145,
  sym_dialog_parameter = 146,
  sym_dialog_definition = 147,
  sym_dialog_block = 148,
  sym_dialog = 149,
  sym_dialog_identifier = 150,
  sym_dialog_option = 151,
  sym_serial_dialog_definition = 152,
  sym_serial_dialog_block = 153,
  sym_serial_dialog = 154,
  sym_serial_dialog_option = 155,
  sym_script_definition = 156,
  sym_script_block = 157,
  sym__script_item = 158,
  sym_json_literal = 159,
  sym_json_array = 160,
  sym_json_object = 161,
  sym_json_name_value_pair = 162,
  sym__json_item = 163,
  sym_label = 164,
  sym_debug_macro = 165,
  sym_rand_macro = 166,
  sym_spread_macro = 167,
  sym__action_item = 168,
  sym_action_load_map = 169,
  sym_action_run_script = 170,
  sym_action_goto_label = 171,
  sym_action_goto_index = 172,
  sym_action_show_dialog = 173,
  sym_action_show_serial_dialog = 174,
  sym_action_concat_serial_dialog = 175,
  sym_action_delete_command = 176,
  sym_action_delete_command_arg = 177,
  sym_action_delete_alias = 178,
  sym_action_hide_command = 179,
  sym_action_unhide_command = 180,
  sym_action_save_slot = 181,
  sym_action_load_slot = 182,
  sym_action_erase_slot = 183,
  sym_action_blocking_delay = 184,
  sym_action_non_blocking_delay = 185,
  sym_action_close_dialog = 186,
  sym_action_close_serial_dialog = 187,
  sym_entity_identifier_expansion = 188,
  sym_map = 189,
  sym_entity_or_map_identifier_expansion = 190,
  sym_action_pause_script = 191,
  sym_action_unpause_script = 192,
  sym_action_camera_fade = 193,
  sym_in_or_out = 194,
  sym_in_or_out_expansion = 195,
  sym_action_camera_shake = 196,
  sym_action_play_entity_animation = 197,
  sym_camera = 198,
  sym__origin_or_length = 199,
  sym_movable_identifier_expansion = 200,
  sym_polygon_identifier_expansion = 201,
  sym_complex_duration_expansion = 202,
  sym_over_time_operator = 203,
  sym_action_move_over_time = 204,
  sym_assignmment_operator = 205,
  sym_action_set_position = 206,
  sym_bool_setable = 207,
  sym_action_set_bool = 208,
  sym_COMPARISON = 209,
  sym_EQUALITY = 210,
  sym__bool_expression = 211,
  sym_bool_unary_expression = 212,
  sym_bool_binary_expression = 213,
  sym_if_chain = 214,
  sym_if_block = 215,
  sym_if_else_block = 216,
  sym_else_block = 217,
  sym_condition = 218,
  sym_looping_block = 219,
  sym_while_block = 220,
  sym_for_block = 221,
  sym_int_setable = 222,
  sym_action_set_int = 223,
  sym_mul_div_mod = 224,
  sym_add_sub = 225,
  sym__int_expression = 226,
  sym_int_unary_expression = 227,
  sym_int_binary_expression = 228,
  sym_entity_property_int = 229,
  sym_entity_property_int_expansion = 230,
  sym_entity_property_string = 231,
  sym_entity_property_string_expansion = 232,
  sym_string_setable = 233,
  sym_action_set_string = 234,
  aux_sym_source_file_repeat1 = 235,
  aux_sym_bool_or_identifier_expansion_repeat1 = 236,
  aux_sym_bareword_expansion_repeat1 = 237,
  aux_sym_quoted_string_expansion_repeat1 = 238,
  aux_sym_string_expansion_repeat1 = 239,
  aux_sym_number_expansion_repeat1 = 240,
  aux_sym_int_or_identifier_expansion_repeat1 = 241,
  aux_sym_duration_expansion_repeat1 = 242,
  aux_sym_distance_expansion_repeat1 = 243,
  aux_sym_quantity_expansion_repeat1 = 244,
  aux_sym_color_expansion_repeat1 = 245,
  aux_sym_constant_expansion_repeat1 = 246,
  aux_sym_constant_value_expansion_repeat1 = 247,
  aux_sym_add_serial_dialog_settings_repeat1 = 248,
  aux_sym_add_dialog_settings_repeat1 = 249,
  aux_sym_dialog_settings_block_repeat1 = 250,
  aux_sym_dialog_block_repeat1 = 251,
  aux_sym_dialog_repeat1 = 252,
  aux_sym_dialog_repeat2 = 253,
  aux_sym_serial_dialog_repeat1 = 254,
  aux_sym_serial_dialog_repeat2 = 255,
  aux_sym_script_block_repeat1 = 256,
  aux_sym_json_array_repeat1 = 257,
  aux_sym_json_object_repeat1 = 258,
  aux_sym_entity_identifier_expansion_repeat1 = 259,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 260,
  aux_sym_in_or_out_expansion_repeat1 = 261,
  aux_sym_movable_identifier_expansion_repeat1 = 262,
  aux_sym_polygon_identifier_expansion_repeat1 = 263,
  aux_sym_complex_duration_expansion_repeat1 = 264,
  aux_sym_if_chain_repeat1 = 265,
  aux_sym_looping_block_repeat1 = 266,
  aux_sym_entity_property_int_expansion_repeat1 = 267,
  aux_sym_entity_property_string_expansion_repeat1 = 268,
  alias_sym_else_body = 269,
  alias_sym_entity_settings = 270,
  alias_sym_for_body = 271,
  alias_sym_if_body = 272,
  alias_sym_if_else_body = 273,
  alias_sym_label_settings = 274,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BOOL] = "BOOL",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_BAREWORD] = "BAREWORD",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [sym_NUMBER] = "NUMBER",
  [sym_DURATION] = "DURATION",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym_COLOR] = "COLOR",
  [sym_CONSTANT] = "CONSTANT",
  [anon_sym_include] = "include",
  [anon_sym_SEMI] = ";",
  [anon_sym_EQ] = "=",
  [anon_sym_add] = "add",
  [anon_sym_serial_dialog] = "serial_dialog",
  [anon_sym_settings] = "settings",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_wrap] = "wrap",
  [anon_sym_dialog] = "dialog",
  [anon_sym_default] = "default",
  [anon_sym_label] = "label",
  [anon_sym_entity] = "entity",
  [anon_sym_name] = "name",
  [anon_sym_portrait] = "portrait",
  [anon_sym_alignment] = "alignment",
  [anon_sym_border_tileset] = "border_tileset",
  [anon_sym_emote] = "emote",
  [anon_sym_GT] = ">",
  [sym_serial_dialog_option_type] = "serial_dialog_option_type",
  [anon_sym_script] = "script",
  [anon_sym_json] = "json",
  [anon_sym_COLON] = ":",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [anon_sym_debug] = "debug",
  [anon_sym_BANG] = "!",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_rand] = "rand",
  [anon_sym_spread] = "spread",
  [sym_return_statement] = "return_statement",
  [anon_sym_load] = "load",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
  [anon_sym_index] = "index",
  [anon_sym_show] = "show",
  [anon_sym_concat] = "concat",
  [anon_sym_delete] = "delete",
  [anon_sym_command] = "command",
  [anon_sym_PLUS] = "+",
  [anon_sym_alias] = "alias",
  [anon_sym_hide] = "hide",
  [anon_sym_unhide] = "unhide",
  [anon_sym_save] = "save",
  [anon_sym_slot] = "slot",
  [anon_sym_erase] = "erase",
  [anon_sym_block] = "block",
  [anon_sym_wait] = "wait",
  [anon_sym_close] = "close",
  [sym_player] = "player",
  [sym_self] = "self",
  [anon_sym_pause] = "pause",
  [anon_sym_unpause] = "unpause",
  [anon_sym_camera] = "camera",
  [anon_sym_fade] = "fade",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_over] = "over",
  [anon_sym_in] = "in",
  [anon_sym_out] = "out",
  [anon_sym_shake] = "shake",
  [anon_sym_animation] = "animation",
  [anon_sym_geometry] = "geometry",
  [sym_origin] = "origin",
  [sym_length] = "length",
  [sym_forever] = "forever",
  [anon_sym_position] = "position",
  [sym_glitched] = "glitched",
  [anon_sym_light] = "light",
  [anon_sym_player_control] = "player_control",
  [anon_sym_lights_control] = "lights_control",
  [anon_sym_hex_editor] = "hex_editor",
  [anon_sym_hex_dialog_mode] = "hex_dialog_mode",
  [anon_sym_hex_control] = "hex_control",
  [anon_sym_hex_clipboard] = "hex_clipboard",
  [anon_sym_serial_control] = "serial_control",
  [anon_sym_flagName] = "flagName",
  [sym_AND] = "AND",
  [sym_OR] = "OR",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_break] = "break",
  [anon_sym_continue] = "continue",
  [anon_sym_while] = "while",
  [anon_sym_for] = "for",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_DASH] = "-",
  [anon_sym_x] = "x",
  [anon_sym_y] = "y",
  [anon_sym_primary_id] = "primary_id",
  [anon_sym_secondary_id] = "secondary_id",
  [anon_sym_primary_id_type] = "primary_id_type",
  [anon_sym_current_animation] = "current_animation",
  [anon_sym_animation_frame] = "animation_frame",
  [anon_sym_strafe] = "strafe",
  [anon_sym_path] = "path",
  [anon_sym_on_tick] = "on_tick",
  [anon_sym_on_look] = "on_look",
  [anon_sym_on_interact] = "on_interact",
  [sym_fail] = "fail",
  [anon_sym_serial_connect] = "serial_connect",
  [anon_sym_warp_state] = "warp_state",
  [sym_source_file] = "source_file",
  [sym_bool_or_identifier_expansion] = "bool_or_identifier_expansion",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_int_or_identifier_expansion] = "int_or_identifier_expansion",
  [sym_duration_expansion] = "duration_expansion",
  [sym_distance_expansion] = "distance_expansion",
  [sym_quantity_expansion] = "quantity_expansion",
  [sym_color_expansion] = "color_expansion",
  [sym_constant_expansion] = "constant_expansion",
  [sym_constant_value_expansion] = "constant_value_expansion",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [sym_constant_assignment] = "constant_assignment",
  [sym_add_serial_dialog_settings] = "add_serial_dialog_settings",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [sym_add_dialog_settings] = "add_dialog_settings",
  [sym_dialog_settings_block] = "default_settings",
  [sym_dialog_parameter] = "dialog_parameter",
  [sym_dialog_definition] = "dialog_definition",
  [sym_dialog_block] = "dialog_block",
  [sym_dialog] = "dialog",
  [sym_dialog_identifier] = "dialog_identifier",
  [sym_dialog_option] = "dialog_option",
  [sym_serial_dialog_definition] = "serial_dialog_definition",
  [sym_serial_dialog_block] = "serial_dialog_block",
  [sym_serial_dialog] = "serial_dialog",
  [sym_serial_dialog_option] = "serial_dialog_option",
  [sym_script_definition] = "script_definition",
  [sym_script_block] = "script_block",
  [sym__script_item] = "_script_item",
  [sym_json_literal] = "json_literal",
  [sym_json_array] = "json_array",
  [sym_json_object] = "json_object",
  [sym_json_name_value_pair] = "json_name_value_pair",
  [sym__json_item] = "_json_item",
  [sym_label] = "label",
  [sym_debug_macro] = "debug_macro",
  [sym_rand_macro] = "rand_macro",
  [sym_spread_macro] = "spread_macro",
  [sym__action_item] = "_action_item",
  [sym_action_load_map] = "action_load_map",
  [sym_action_run_script] = "action_run_script",
  [sym_action_goto_label] = "action_goto_label",
  [sym_action_goto_index] = "action_goto_index",
  [sym_action_show_dialog] = "action_show_dialog",
  [sym_action_show_serial_dialog] = "action_show_serial_dialog",
  [sym_action_concat_serial_dialog] = "action_concat_serial_dialog",
  [sym_action_delete_command] = "action_delete_command",
  [sym_action_delete_command_arg] = "action_delete_command_arg",
  [sym_action_delete_alias] = "action_delete_alias",
  [sym_action_hide_command] = "action_hide_command",
  [sym_action_unhide_command] = "action_unhide_command",
  [sym_action_save_slot] = "action_save_slot",
  [sym_action_load_slot] = "action_load_slot",
  [sym_action_erase_slot] = "action_erase_slot",
  [sym_action_blocking_delay] = "action_blocking_delay",
  [sym_action_non_blocking_delay] = "action_non_blocking_delay",
  [sym_action_close_dialog] = "action_close_dialog",
  [sym_action_close_serial_dialog] = "action_close_serial_dialog",
  [sym_entity_identifier_expansion] = "entity_identifier_expansion",
  [sym_map] = "map",
  [sym_entity_or_map_identifier_expansion] = "entity_or_map_identifier_expansion",
  [sym_action_pause_script] = "action_pause_script",
  [sym_action_unpause_script] = "action_unpause_script",
  [sym_action_camera_fade] = "action_camera_fade",
  [sym_in_or_out] = "in_or_out",
  [sym_in_or_out_expansion] = "in_or_out_expansion",
  [sym_action_camera_shake] = "action_camera_shake",
  [sym_action_play_entity_animation] = "action_play_entity_animation",
  [sym_camera] = "camera",
  [sym__origin_or_length] = "_origin_or_length",
  [sym_movable_identifier_expansion] = "movable_identifier_expansion",
  [sym_polygon_identifier_expansion] = "polygon_identifier_expansion",
  [sym_complex_duration_expansion] = "complex_duration_expansion",
  [sym_over_time_operator] = "over_time_operator",
  [sym_action_move_over_time] = "action_move_over_time",
  [sym_assignmment_operator] = "assignmment_operator",
  [sym_action_set_position] = "action_set_position",
  [sym_bool_setable] = "bool_setable",
  [sym_action_set_bool] = "action_set_bool",
  [sym_COMPARISON] = "COMPARISON",
  [sym_EQUALITY] = "EQUALITY",
  [sym__bool_expression] = "_bool_expression",
  [sym_bool_unary_expression] = "bool_unary_expression",
  [sym_bool_binary_expression] = "bool_binary_expression",
  [sym_if_chain] = "if_chain",
  [sym_if_block] = "if_block",
  [sym_if_else_block] = "if_else_block",
  [sym_else_block] = "else_block",
  [sym_condition] = "condition",
  [sym_looping_block] = "while_body",
  [sym_while_block] = "while_block",
  [sym_for_block] = "for_block",
  [sym_int_setable] = "int_setable",
  [sym_action_set_int] = "action_set_int",
  [sym_mul_div_mod] = "mul_div_mod",
  [sym_add_sub] = "add_sub",
  [sym__int_expression] = "_int_expression",
  [sym_int_unary_expression] = "int_unary_expression",
  [sym_int_binary_expression] = "int_binary_expression",
  [sym_entity_property_int] = "entity_property_int",
  [sym_entity_property_int_expansion] = "entity_property_int_expansion",
  [sym_entity_property_string] = "entity_property_string",
  [sym_entity_property_string_expansion] = "entity_property_string_expansion",
  [sym_string_setable] = "string_setable",
  [sym_action_set_string] = "action_set_string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_bool_or_identifier_expansion_repeat1] = "bool_or_identifier_expansion_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_int_or_identifier_expansion_repeat1] = "int_or_identifier_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
  [aux_sym_distance_expansion_repeat1] = "distance_expansion_repeat1",
  [aux_sym_quantity_expansion_repeat1] = "quantity_expansion_repeat1",
  [aux_sym_color_expansion_repeat1] = "color_expansion_repeat1",
  [aux_sym_constant_expansion_repeat1] = "constant_expansion_repeat1",
  [aux_sym_constant_value_expansion_repeat1] = "constant_value_expansion_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_repeat1] = "add_dialog_settings_repeat1",
  [aux_sym_dialog_settings_block_repeat1] = "dialog_settings_block_repeat1",
  [aux_sym_dialog_block_repeat1] = "dialog_block_repeat1",
  [aux_sym_dialog_repeat1] = "dialog_repeat1",
  [aux_sym_dialog_repeat2] = "dialog_repeat2",
  [aux_sym_serial_dialog_repeat1] = "serial_dialog_repeat1",
  [aux_sym_serial_dialog_repeat2] = "serial_dialog_repeat2",
  [aux_sym_script_block_repeat1] = "script_block_repeat1",
  [aux_sym_json_array_repeat1] = "json_array_repeat1",
  [aux_sym_json_object_repeat1] = "json_object_repeat1",
  [aux_sym_entity_identifier_expansion_repeat1] = "entity_identifier_expansion_repeat1",
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = "entity_or_map_identifier_expansion_repeat1",
  [aux_sym_in_or_out_expansion_repeat1] = "in_or_out_expansion_repeat1",
  [aux_sym_movable_identifier_expansion_repeat1] = "movable_identifier_expansion_repeat1",
  [aux_sym_polygon_identifier_expansion_repeat1] = "polygon_identifier_expansion_repeat1",
  [aux_sym_complex_duration_expansion_repeat1] = "complex_duration_expansion_repeat1",
  [aux_sym_if_chain_repeat1] = "if_chain_repeat1",
  [aux_sym_looping_block_repeat1] = "looping_block_repeat1",
  [aux_sym_entity_property_int_expansion_repeat1] = "entity_property_int_expansion_repeat1",
  [aux_sym_entity_property_string_expansion_repeat1] = "entity_property_string_expansion_repeat1",
  [alias_sym_else_body] = "else_body",
  [alias_sym_entity_settings] = "entity_settings",
  [alias_sym_for_body] = "for_body",
  [alias_sym_if_body] = "if_body",
  [alias_sym_if_else_body] = "if_else_body",
  [alias_sym_label_settings] = "label_settings",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_BOOL] = sym_BOOL,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_BAREWORD] = sym_BAREWORD,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [sym_NUMBER] = sym_NUMBER,
  [sym_DURATION] = sym_DURATION,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym_COLOR] = sym_COLOR,
  [sym_CONSTANT] = sym_CONSTANT,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_add] = anon_sym_add,
  [anon_sym_serial_dialog] = anon_sym_serial_dialog,
  [anon_sym_settings] = anon_sym_settings,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_wrap] = anon_sym_wrap,
  [anon_sym_dialog] = anon_sym_dialog,
  [anon_sym_default] = anon_sym_default,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_name] = anon_sym_name,
  [anon_sym_portrait] = anon_sym_portrait,
  [anon_sym_alignment] = anon_sym_alignment,
  [anon_sym_border_tileset] = anon_sym_border_tileset,
  [anon_sym_emote] = anon_sym_emote,
  [anon_sym_GT] = anon_sym_GT,
  [sym_serial_dialog_option_type] = sym_serial_dialog_option_type,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_json] = anon_sym_json,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_debug] = anon_sym_debug,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_rand] = anon_sym_rand,
  [anon_sym_spread] = anon_sym_spread,
  [sym_return_statement] = sym_return_statement,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_index] = anon_sym_index,
  [anon_sym_show] = anon_sym_show,
  [anon_sym_concat] = anon_sym_concat,
  [anon_sym_delete] = anon_sym_delete,
  [anon_sym_command] = anon_sym_command,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_hide] = anon_sym_hide,
  [anon_sym_unhide] = anon_sym_unhide,
  [anon_sym_save] = anon_sym_save,
  [anon_sym_slot] = anon_sym_slot,
  [anon_sym_erase] = anon_sym_erase,
  [anon_sym_block] = anon_sym_block,
  [anon_sym_wait] = anon_sym_wait,
  [anon_sym_close] = anon_sym_close,
  [sym_player] = sym_player,
  [sym_self] = sym_self,
  [anon_sym_pause] = anon_sym_pause,
  [anon_sym_unpause] = anon_sym_unpause,
  [anon_sym_camera] = anon_sym_camera,
  [anon_sym_fade] = anon_sym_fade,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_over] = anon_sym_over,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_out] = anon_sym_out,
  [anon_sym_shake] = anon_sym_shake,
  [anon_sym_animation] = anon_sym_animation,
  [anon_sym_geometry] = anon_sym_geometry,
  [sym_origin] = sym_origin,
  [sym_length] = sym_length,
  [sym_forever] = sym_forever,
  [anon_sym_position] = anon_sym_position,
  [sym_glitched] = sym_glitched,
  [anon_sym_light] = anon_sym_light,
  [anon_sym_player_control] = anon_sym_player_control,
  [anon_sym_lights_control] = anon_sym_lights_control,
  [anon_sym_hex_editor] = anon_sym_hex_editor,
  [anon_sym_hex_dialog_mode] = anon_sym_hex_dialog_mode,
  [anon_sym_hex_control] = anon_sym_hex_control,
  [anon_sym_hex_clipboard] = anon_sym_hex_clipboard,
  [anon_sym_serial_control] = anon_sym_serial_control,
  [anon_sym_flagName] = anon_sym_flagName,
  [sym_AND] = sym_AND,
  [sym_OR] = sym_OR,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_x] = anon_sym_x,
  [anon_sym_y] = anon_sym_y,
  [anon_sym_primary_id] = anon_sym_primary_id,
  [anon_sym_secondary_id] = anon_sym_secondary_id,
  [anon_sym_primary_id_type] = anon_sym_primary_id_type,
  [anon_sym_current_animation] = anon_sym_current_animation,
  [anon_sym_animation_frame] = anon_sym_animation_frame,
  [anon_sym_strafe] = anon_sym_strafe,
  [anon_sym_path] = anon_sym_path,
  [anon_sym_on_tick] = anon_sym_on_tick,
  [anon_sym_on_look] = anon_sym_on_look,
  [anon_sym_on_interact] = anon_sym_on_interact,
  [sym_fail] = sym_fail,
  [anon_sym_serial_connect] = anon_sym_serial_connect,
  [anon_sym_warp_state] = anon_sym_warp_state,
  [sym_source_file] = sym_source_file,
  [sym_bool_or_identifier_expansion] = sym_bool_or_identifier_expansion,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_int_or_identifier_expansion] = sym_int_or_identifier_expansion,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym_distance_expansion] = sym_distance_expansion,
  [sym_quantity_expansion] = sym_quantity_expansion,
  [sym_color_expansion] = sym_color_expansion,
  [sym_constant_expansion] = sym_constant_expansion,
  [sym_constant_value_expansion] = sym_constant_value_expansion,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_add_serial_dialog_settings] = sym_add_serial_dialog_settings,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [sym_add_dialog_settings] = sym_add_dialog_settings,
  [sym_dialog_settings_block] = sym_dialog_settings_block,
  [sym_dialog_parameter] = sym_dialog_parameter,
  [sym_dialog_definition] = sym_dialog_definition,
  [sym_dialog_block] = sym_dialog_block,
  [sym_dialog] = sym_dialog,
  [sym_dialog_identifier] = sym_dialog_identifier,
  [sym_dialog_option] = sym_dialog_option,
  [sym_serial_dialog_definition] = sym_serial_dialog_definition,
  [sym_serial_dialog_block] = sym_serial_dialog_block,
  [sym_serial_dialog] = sym_serial_dialog,
  [sym_serial_dialog_option] = sym_serial_dialog_option,
  [sym_script_definition] = sym_script_definition,
  [sym_script_block] = sym_script_block,
  [sym__script_item] = sym__script_item,
  [sym_json_literal] = sym_json_literal,
  [sym_json_array] = sym_json_array,
  [sym_json_object] = sym_json_object,
  [sym_json_name_value_pair] = sym_json_name_value_pair,
  [sym__json_item] = sym__json_item,
  [sym_label] = sym_label,
  [sym_debug_macro] = sym_debug_macro,
  [sym_rand_macro] = sym_rand_macro,
  [sym_spread_macro] = sym_spread_macro,
  [sym__action_item] = sym__action_item,
  [sym_action_load_map] = sym_action_load_map,
  [sym_action_run_script] = sym_action_run_script,
  [sym_action_goto_label] = sym_action_goto_label,
  [sym_action_goto_index] = sym_action_goto_index,
  [sym_action_show_dialog] = sym_action_show_dialog,
  [sym_action_show_serial_dialog] = sym_action_show_serial_dialog,
  [sym_action_concat_serial_dialog] = sym_action_concat_serial_dialog,
  [sym_action_delete_command] = sym_action_delete_command,
  [sym_action_delete_command_arg] = sym_action_delete_command_arg,
  [sym_action_delete_alias] = sym_action_delete_alias,
  [sym_action_hide_command] = sym_action_hide_command,
  [sym_action_unhide_command] = sym_action_unhide_command,
  [sym_action_save_slot] = sym_action_save_slot,
  [sym_action_load_slot] = sym_action_load_slot,
  [sym_action_erase_slot] = sym_action_erase_slot,
  [sym_action_blocking_delay] = sym_action_blocking_delay,
  [sym_action_non_blocking_delay] = sym_action_non_blocking_delay,
  [sym_action_close_dialog] = sym_action_close_dialog,
  [sym_action_close_serial_dialog] = sym_action_close_serial_dialog,
  [sym_entity_identifier_expansion] = sym_entity_identifier_expansion,
  [sym_map] = sym_map,
  [sym_entity_or_map_identifier_expansion] = sym_entity_or_map_identifier_expansion,
  [sym_action_pause_script] = sym_action_pause_script,
  [sym_action_unpause_script] = sym_action_unpause_script,
  [sym_action_camera_fade] = sym_action_camera_fade,
  [sym_in_or_out] = sym_in_or_out,
  [sym_in_or_out_expansion] = sym_in_or_out_expansion,
  [sym_action_camera_shake] = sym_action_camera_shake,
  [sym_action_play_entity_animation] = sym_action_play_entity_animation,
  [sym_camera] = sym_camera,
  [sym__origin_or_length] = sym__origin_or_length,
  [sym_movable_identifier_expansion] = sym_movable_identifier_expansion,
  [sym_polygon_identifier_expansion] = sym_polygon_identifier_expansion,
  [sym_complex_duration_expansion] = sym_complex_duration_expansion,
  [sym_over_time_operator] = sym_over_time_operator,
  [sym_action_move_over_time] = sym_action_move_over_time,
  [sym_assignmment_operator] = sym_assignmment_operator,
  [sym_action_set_position] = sym_action_set_position,
  [sym_bool_setable] = sym_bool_setable,
  [sym_action_set_bool] = sym_action_set_bool,
  [sym_COMPARISON] = sym_COMPARISON,
  [sym_EQUALITY] = sym_EQUALITY,
  [sym__bool_expression] = sym__bool_expression,
  [sym_bool_unary_expression] = sym_bool_unary_expression,
  [sym_bool_binary_expression] = sym_bool_binary_expression,
  [sym_if_chain] = sym_if_chain,
  [sym_if_block] = sym_if_block,
  [sym_if_else_block] = sym_if_else_block,
  [sym_else_block] = sym_else_block,
  [sym_condition] = sym_condition,
  [sym_looping_block] = sym_looping_block,
  [sym_while_block] = sym_while_block,
  [sym_for_block] = sym_for_block,
  [sym_int_setable] = sym_int_setable,
  [sym_action_set_int] = sym_action_set_int,
  [sym_mul_div_mod] = sym_mul_div_mod,
  [sym_add_sub] = sym_add_sub,
  [sym__int_expression] = sym__int_expression,
  [sym_int_unary_expression] = sym_int_unary_expression,
  [sym_int_binary_expression] = sym_int_binary_expression,
  [sym_entity_property_int] = sym_entity_property_int,
  [sym_entity_property_int_expansion] = sym_entity_property_int_expansion,
  [sym_entity_property_string] = sym_entity_property_string,
  [sym_entity_property_string_expansion] = sym_entity_property_string_expansion,
  [sym_string_setable] = sym_string_setable,
  [sym_action_set_string] = sym_action_set_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_bool_or_identifier_expansion_repeat1] = aux_sym_bool_or_identifier_expansion_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_int_or_identifier_expansion_repeat1] = aux_sym_int_or_identifier_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
  [aux_sym_distance_expansion_repeat1] = aux_sym_distance_expansion_repeat1,
  [aux_sym_quantity_expansion_repeat1] = aux_sym_quantity_expansion_repeat1,
  [aux_sym_color_expansion_repeat1] = aux_sym_color_expansion_repeat1,
  [aux_sym_constant_expansion_repeat1] = aux_sym_constant_expansion_repeat1,
  [aux_sym_constant_value_expansion_repeat1] = aux_sym_constant_value_expansion_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_repeat1] = aux_sym_add_dialog_settings_repeat1,
  [aux_sym_dialog_settings_block_repeat1] = aux_sym_dialog_settings_block_repeat1,
  [aux_sym_dialog_block_repeat1] = aux_sym_dialog_block_repeat1,
  [aux_sym_dialog_repeat1] = aux_sym_dialog_repeat1,
  [aux_sym_dialog_repeat2] = aux_sym_dialog_repeat2,
  [aux_sym_serial_dialog_repeat1] = aux_sym_serial_dialog_repeat1,
  [aux_sym_serial_dialog_repeat2] = aux_sym_serial_dialog_repeat2,
  [aux_sym_script_block_repeat1] = aux_sym_script_block_repeat1,
  [aux_sym_json_array_repeat1] = aux_sym_json_array_repeat1,
  [aux_sym_json_object_repeat1] = aux_sym_json_object_repeat1,
  [aux_sym_entity_identifier_expansion_repeat1] = aux_sym_entity_identifier_expansion_repeat1,
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = aux_sym_entity_or_map_identifier_expansion_repeat1,
  [aux_sym_in_or_out_expansion_repeat1] = aux_sym_in_or_out_expansion_repeat1,
  [aux_sym_movable_identifier_expansion_repeat1] = aux_sym_movable_identifier_expansion_repeat1,
  [aux_sym_polygon_identifier_expansion_repeat1] = aux_sym_polygon_identifier_expansion_repeat1,
  [aux_sym_complex_duration_expansion_repeat1] = aux_sym_complex_duration_expansion_repeat1,
  [aux_sym_if_chain_repeat1] = aux_sym_if_chain_repeat1,
  [aux_sym_looping_block_repeat1] = aux_sym_looping_block_repeat1,
  [aux_sym_entity_property_int_expansion_repeat1] = aux_sym_entity_property_int_expansion_repeat1,
  [aux_sym_entity_property_string_expansion_repeat1] = aux_sym_entity_property_string_expansion_repeat1,
  [alias_sym_else_body] = alias_sym_else_body,
  [alias_sym_entity_settings] = alias_sym_entity_settings,
  [alias_sym_for_body] = alias_sym_for_body,
  [alias_sym_if_body] = alias_sym_if_body,
  [alias_sym_if_else_body] = alias_sym_if_else_body,
  [alias_sym_label_settings] = alias_sym_label_settings,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_BOOL] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_BAREWORD] = {
    .visible = true,
    .named = true,
  },
  [sym_QUOTED_STRING] = {
    .visible = true,
    .named = true,
  },
  [sym_NUMBER] = {
    .visible = true,
    .named = true,
  },
  [sym_DURATION] = {
    .visible = true,
    .named = true,
  },
  [sym_DISTANCE] = {
    .visible = true,
    .named = true,
  },
  [sym_QUANTITY] = {
    .visible = true,
    .named = true,
  },
  [sym_COLOR] = {
    .visible = true,
    .named = true,
  },
  [sym_CONSTANT] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_add] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_serial_dialog] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_settings] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_wrap] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dialog] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_default] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_name] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_portrait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alignment] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_border_tileset] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_emote] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_serial_dialog_option_type] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_script] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_json] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_json_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_debug] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rand] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_spread] = {
    .visible = true,
    .named = false,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_load] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_map] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_goto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_index] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_show] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_concat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_delete] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_command] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hide] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unhide] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_save] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_slot] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_erase] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_block] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_wait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_close] = {
    .visible = true,
    .named = false,
  },
  [sym_player] = {
    .visible = true,
    .named = true,
  },
  [sym_self] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_pause] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unpause] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_camera] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fade] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_over] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_out] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shake] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_animation] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_geometry] = {
    .visible = true,
    .named = false,
  },
  [sym_origin] = {
    .visible = true,
    .named = true,
  },
  [sym_length] = {
    .visible = true,
    .named = true,
  },
  [sym_forever] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_position] = {
    .visible = true,
    .named = false,
  },
  [sym_glitched] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_light] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_player_control] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lights_control] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hex_editor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hex_dialog_mode] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hex_control] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hex_clipboard] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_serial_control] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_flagName] = {
    .visible = true,
    .named = false,
  },
  [sym_AND] = {
    .visible = true,
    .named = true,
  },
  [sym_OR] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_x] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_y] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_primary_id] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_secondary_id] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_primary_id_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_current_animation] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_animation_frame] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_strafe] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_path] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_on_tick] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_on_look] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_on_interact] = {
    .visible = true,
    .named = false,
  },
  [sym_fail] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_serial_connect] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_warp_state] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_or_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_bareword_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_number_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_int_or_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_distance_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_quantity_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_color_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_value_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym__root] = {
    .visible = false,
    .named = true,
  },
  [sym_include_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_add_serial_dialog_settings] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_add_dialog_settings] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_settings_block] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_block] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_option] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_block] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_option] = {
    .visible = true,
    .named = true,
  },
  [sym_script_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_script_block] = {
    .visible = true,
    .named = true,
  },
  [sym__script_item] = {
    .visible = false,
    .named = true,
  },
  [sym_json_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_json_array] = {
    .visible = true,
    .named = true,
  },
  [sym_json_object] = {
    .visible = true,
    .named = true,
  },
  [sym_json_name_value_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__json_item] = {
    .visible = false,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_debug_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_rand_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_spread_macro] = {
    .visible = true,
    .named = true,
  },
  [sym__action_item] = {
    .visible = false,
    .named = true,
  },
  [sym_action_load_map] = {
    .visible = true,
    .named = true,
  },
  [sym_action_run_script] = {
    .visible = true,
    .named = true,
  },
  [sym_action_goto_label] = {
    .visible = true,
    .named = true,
  },
  [sym_action_goto_index] = {
    .visible = true,
    .named = true,
  },
  [sym_action_show_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_show_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_concat_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_delete_command] = {
    .visible = true,
    .named = true,
  },
  [sym_action_delete_command_arg] = {
    .visible = true,
    .named = true,
  },
  [sym_action_delete_alias] = {
    .visible = true,
    .named = true,
  },
  [sym_action_hide_command] = {
    .visible = true,
    .named = true,
  },
  [sym_action_unhide_command] = {
    .visible = true,
    .named = true,
  },
  [sym_action_save_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_load_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_erase_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_blocking_delay] = {
    .visible = true,
    .named = true,
  },
  [sym_action_non_blocking_delay] = {
    .visible = true,
    .named = true,
  },
  [sym_action_close_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_close_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_map] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_or_map_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_action_pause_script] = {
    .visible = true,
    .named = true,
  },
  [sym_action_unpause_script] = {
    .visible = true,
    .named = true,
  },
  [sym_action_camera_fade] = {
    .visible = true,
    .named = true,
  },
  [sym_in_or_out] = {
    .visible = true,
    .named = true,
  },
  [sym_in_or_out_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_action_camera_shake] = {
    .visible = true,
    .named = true,
  },
  [sym_action_play_entity_animation] = {
    .visible = true,
    .named = true,
  },
  [sym_camera] = {
    .visible = true,
    .named = true,
  },
  [sym__origin_or_length] = {
    .visible = false,
    .named = true,
  },
  [sym_movable_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_polygon_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_complex_duration_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_over_time_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_action_move_over_time] = {
    .visible = true,
    .named = true,
  },
  [sym_assignmment_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_position] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_setable] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_bool] = {
    .visible = true,
    .named = true,
  },
  [sym_COMPARISON] = {
    .visible = true,
    .named = true,
  },
  [sym_EQUALITY] = {
    .visible = true,
    .named = true,
  },
  [sym__bool_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_bool_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_if_chain] = {
    .visible = true,
    .named = true,
  },
  [sym_if_block] = {
    .visible = true,
    .named = true,
  },
  [sym_if_else_block] = {
    .visible = true,
    .named = true,
  },
  [sym_else_block] = {
    .visible = true,
    .named = true,
  },
  [sym_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_looping_block] = {
    .visible = true,
    .named = true,
  },
  [sym_while_block] = {
    .visible = true,
    .named = true,
  },
  [sym_for_block] = {
    .visible = true,
    .named = true,
  },
  [sym_int_setable] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_int] = {
    .visible = true,
    .named = true,
  },
  [sym_mul_div_mod] = {
    .visible = true,
    .named = true,
  },
  [sym_add_sub] = {
    .visible = true,
    .named = true,
  },
  [sym__int_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_int_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_int_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_property_int] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_property_int_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_property_string] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_property_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_string_setable] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bool_or_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bareword_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_number_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_int_or_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_duration_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_distance_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quantity_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_color_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_value_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_serial_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_settings_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_serial_dialog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_serial_dialog_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_script_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_object_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_in_or_out_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_movable_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_polygon_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_complex_duration_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_chain_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_looping_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_property_int_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_property_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_else_body] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_entity_settings] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_for_body] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_if_body] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_if_else_body] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_label_settings] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_alias = 1,
  field_alignment = 2,
  field_amplitude = 3,
  field_animation = 4,
  field_argument = 5,
  field_binary_operator = 6,
  field_bool = 7,
  field_border_tileset = 8,
  field_color = 9,
  field_command = 10,
  field_constant = 11,
  field_count = 12,
  field_dialog_name = 13,
  field_distance = 14,
  field_duration = 15,
  field_emote = 16,
  field_entity = 17,
  field_fade = 18,
  field_fileName = 19,
  field_forever = 20,
  field_geometry = 21,
  field_glitched = 22,
  field_identifier = 23,
  field_index = 24,
  field_int = 25,
  field_label = 26,
  field_light = 27,
  field_map = 28,
  field_message = 29,
  field_name = 30,
  field_option_type = 31,
  field_portrait = 32,
  field_property = 33,
  field_script = 34,
  field_script_name = 35,
  field_serial_dialog_name = 36,
  field_serial_message = 37,
  field_slot = 38,
  field_target = 39,
  field_target_entity = 40,
  field_target_label = 41,
  field_value = 42,
  field_wrap = 43,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_alignment] = "alignment",
  [field_amplitude] = "amplitude",
  [field_animation] = "animation",
  [field_argument] = "argument",
  [field_binary_operator] = "binary_operator",
  [field_bool] = "bool",
  [field_border_tileset] = "border_tileset",
  [field_color] = "color",
  [field_command] = "command",
  [field_constant] = "constant",
  [field_count] = "count",
  [field_dialog_name] = "dialog_name",
  [field_distance] = "distance",
  [field_duration] = "duration",
  [field_emote] = "emote",
  [field_entity] = "entity",
  [field_fade] = "fade",
  [field_fileName] = "fileName",
  [field_forever] = "forever",
  [field_geometry] = "geometry",
  [field_glitched] = "glitched",
  [field_identifier] = "identifier",
  [field_index] = "index",
  [field_int] = "int",
  [field_label] = "label",
  [field_light] = "light",
  [field_map] = "map",
  [field_message] = "message",
  [field_name] = "name",
  [field_option_type] = "option_type",
  [field_portrait] = "portrait",
  [field_property] = "property",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_serial_dialog_name] = "serial_dialog_name",
  [field_serial_message] = "serial_message",
  [field_slot] = "slot",
  [field_target] = "target",
  [field_target_entity] = "target_entity",
  [field_target_label] = "target_label",
  [field_value] = "value",
  [field_wrap] = "wrap",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 1},
  [9] = {.index = 8, .length = 1},
  [10] = {.index = 9, .length = 1},
  [11] = {.index = 10, .length = 1},
  [12] = {.index = 11, .length = 1},
  [13] = {.index = 12, .length = 1},
  [14] = {.index = 13, .length = 1},
  [15] = {.index = 14, .length = 2},
  [16] = {.index = 16, .length = 1},
  [17] = {.index = 17, .length = 1},
  [18] = {.index = 18, .length = 2},
  [19] = {.index = 20, .length = 1},
  [20] = {.index = 21, .length = 2},
  [21] = {.index = 23, .length = 1},
  [22] = {.index = 24, .length = 1},
  [23] = {.index = 25, .length = 1},
  [24] = {.index = 26, .length = 1},
  [25] = {.index = 27, .length = 1},
  [26] = {.index = 28, .length = 1},
  [27] = {.index = 29, .length = 1},
  [28] = {.index = 30, .length = 1},
  [29] = {.index = 31, .length = 1},
  [30] = {.index = 32, .length = 1},
  [31] = {.index = 33, .length = 1},
  [32] = {.index = 34, .length = 3},
  [33] = {.index = 37, .length = 1},
  [34] = {.index = 38, .length = 1},
  [35] = {.index = 39, .length = 1},
  [36] = {.index = 40, .length = 3},
  [38] = {.index = 43, .length = 1},
  [39] = {.index = 44, .length = 1},
  [40] = {.index = 45, .length = 3},
  [41] = {.index = 48, .length = 1},
  [42] = {.index = 49, .length = 1},
  [43] = {.index = 50, .length = 2},
  [44] = {.index = 52, .length = 1},
  [45] = {.index = 53, .length = 1},
  [46] = {.index = 54, .length = 1},
  [47] = {.index = 55, .length = 1},
  [48] = {.index = 56, .length = 1},
  [49] = {.index = 57, .length = 2},
  [50] = {.index = 59, .length = 2},
  [51] = {.index = 61, .length = 2},
  [52] = {.index = 63, .length = 3},
  [53] = {.index = 66, .length = 1},
  [54] = {.index = 67, .length = 3},
  [55] = {.index = 70, .length = 2},
  [56] = {.index = 72, .length = 4},
  [57] = {.index = 76, .length = 1},
  [58] = {.index = 77, .length = 1},
  [59] = {.index = 78, .length = 1},
  [60] = {.index = 79, .length = 1},
  [61] = {.index = 80, .length = 1},
  [62] = {.index = 81, .length = 2},
  [63] = {.index = 83, .length = 2},
  [64] = {.index = 85, .length = 1},
  [65] = {.index = 86, .length = 1},
  [66] = {.index = 87, .length = 2},
  [67] = {.index = 89, .length = 2},
  [68] = {.index = 91, .length = 1},
  [69] = {.index = 92, .length = 7},
  [71] = {.index = 99, .length = 1},
  [72] = {.index = 100, .length = 1},
  [73] = {.index = 101, .length = 2},
  [74] = {.index = 103, .length = 1},
  [75] = {.index = 104, .length = 1},
  [76] = {.index = 105, .length = 1},
  [77] = {.index = 106, .length = 1},
  [78] = {.index = 107, .length = 7},
  [79] = {.index = 114, .length = 1},
  [80] = {.index = 115, .length = 1},
  [81] = {.index = 116, .length = 2},
  [82] = {.index = 118, .length = 3},
  [83] = {.index = 121, .length = 2},
  [84] = {.index = 123, .length = 2},
  [85] = {.index = 125, .length = 1},
  [86] = {.index = 126, .length = 1},
  [87] = {.index = 127, .length = 1},
  [88] = {.index = 128, .length = 2},
  [89] = {.index = 130, .length = 2},
  [90] = {.index = 132, .length = 3},
  [91] = {.index = 135, .length = 1},
  [92] = {.index = 136, .length = 4},
  [93] = {.index = 140, .length = 6},
  [94] = {.index = 146, .length = 4},
  [95] = {.index = 150, .length = 4},
  [96] = {.index = 154, .length = 4},
  [97] = {.index = 158, .length = 6},
  [98] = {.index = 164, .length = 4},
  [99] = {.index = 168, .length = 4},
  [100] = {.index = 172, .length = 3},
  [101] = {.index = 175, .length = 2},
  [102] = {.index = 177, .length = 2},
  [103] = {.index = 179, .length = 2},
  [104] = {.index = 181, .length = 3},
  [105] = {.index = 184, .length = 2},
  [106] = {.index = 186, .length = 1},
  [107] = {.index = 187, .length = 3},
  [108] = {.index = 190, .length = 3},
  [109] = {.index = 193, .length = 3},
  [110] = {.index = 196, .length = 3},
  [111] = {.index = 199, .length = 6},
  [112] = {.index = 205, .length = 2},
  [113] = {.index = 207, .length = 2},
  [114] = {.index = 209, .length = 3},
  [115] = {.index = 212, .length = 1},
  [116] = {.index = 213, .length = 3},
  [117] = {.index = 216, .length = 4},
  [119] = {.index = 220, .length = 2},
  [120] = {.index = 222, .length = 3},
  [121] = {.index = 225, .length = 2},
  [122] = {.index = 227, .length = 4},
  [123] = {.index = 231, .length = 2},
  [124] = {.index = 233, .length = 3},
  [125] = {.index = 236, .length = 4},
  [126] = {.index = 240, .length = 5},
  [127] = {.index = 245, .length = 3},
  [128] = {.index = 248, .length = 3},
  [129] = {.index = 251, .length = 4},
  [130] = {.index = 255, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_identifier, 0},
  [2] =
    {field_fileName, 1},
  [3] =
    {field_serial_dialog_name, 1},
  [4] =
    {field_dialog_name, 1},
  [5] =
    {field_script_name, 1},
  [6] =
    {field_label, 0},
  [7] =
    {field_script, 1},
  [8] =
    {field_command, 1},
  [9] =
    {field_alias, 1},
  [10] =
    {field_duration, 1},
  [11] =
    {field_glitched, 1},
  [12] =
    {field_property, 1},
  [13] =
    {field_light, 1},
  [14] =
    {field_label, 0},
    {field_value, 2},
  [16] =
    {field_serial_message, 0},
  [17] =
    {field_serial_message, 0, .inherited = true},
  [18] =
    {field_entity, 1},
    {field_glitched, 2},
  [20] =
    {field_entity, 1},
  [21] =
    {field_entity, 1},
    {field_property, 2},
  [23] =
    {field_map, 2},
  [24] =
    {field_slot, 2},
  [25] =
    {field_label, 2},
  [26] =
    {field_index, 2},
  [27] =
    {field_serial_dialog_name, 2},
  [28] =
    {field_dialog_name, 2},
  [29] =
    {field_command, 2},
  [30] =
    {field_alias, 2},
  [31] =
    {field_script, 2},
  [32] =
    {field_bool, 0},
  [33] =
    {field_constant, 0},
  [34] =
    {field_bool, 0, .inherited = true},
    {field_constant, 0, .inherited = true},
    {field_identifier, 0, .inherited = true},
  [37] =
    {field_bool, 2},
  [38] =
    {field_identifier, 2},
  [39] =
    {field_constant, 2},
  [40] =
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [43] =
    {field_int, 0},
  [44] =
    {field_int, 2},
  [45] =
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
    {field_int, 2, .inherited = true},
  [48] =
    {field_wrap, 1},
  [49] =
    {field_serial_message, 1, .inherited = true},
  [50] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [52] =
    {field_name, 1},
  [53] =
    {field_message, 0},
  [54] =
    {field_message, 1, .inherited = true},
  [55] =
    {field_entity, 2},
  [56] =
    {field_entity, 2, .inherited = true},
  [57] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
  [59] =
    {field_argument, 3},
    {field_command, 1},
  [61] =
    {field_entity, 2},
    {field_script, 3},
  [63] =
    {field_bool, 1, .inherited = true},
    {field_constant, 1, .inherited = true},
    {field_identifier, 1, .inherited = true},
  [66] =
    {field_forever, 3},
  [67] =
    {field_constant, 1, .inherited = true},
    {field_identifier, 1, .inherited = true},
    {field_int, 1, .inherited = true},
  [70] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [72] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [76] =
    {field_portrait, 1},
  [77] =
    {field_alignment, 1},
  [78] =
    {field_border_tileset, 1},
  [79] =
    {field_emote, 1},
  [80] =
    {field_message, 2, .inherited = true},
  [81] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [83] =
    {field_entity, 2},
    {field_entity, 3, .inherited = true},
  [85] =
    {field_entity, 3, .inherited = true},
  [86] =
    {field_dialog_name, 3},
  [87] =
    {field_argument, 4},
    {field_command, 2},
  [89] =
    {field_animation, 3},
    {field_count, 4},
  [91] =
    {field_forever, 4},
  [92] =
    {field_binary_operator, 1},
    {field_bool, 0, .inherited = true},
    {field_bool, 2, .inherited = true},
    {field_constant, 0, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [99] =
    {field_duration, 4},
  [100] =
    {field_entity, 3},
  [101] =
    {field_geometry, 3},
    {field_target, 4},
  [103] =
    {field_bool, 1},
  [104] =
    {field_identifier, 1},
  [105] =
    {field_constant, 1},
  [106] =
    {field_int, 1},
  [107] =
    {field_binary_operator, 1},
    {field_constant, 0, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 2, .inherited = true},
    {field_int, 0, .inherited = true},
    {field_int, 2, .inherited = true},
  [114] =
    {field_target_label, 1},
  [115] =
    {field_target_entity, 1},
  [116] =
    {field_entity, 2},
    {field_entity, 4, .inherited = true},
  [118] =
    {field_animation, 4},
    {field_count, 5},
    {field_entity, 1},
  [121] =
    {field_entity, 1},
    {field_forever, 5},
  [123] =
    {field_property, 0},
    {field_value, 2},
  [125] =
    {field_forever, 5},
  [126] =
    {field_duration, 5},
  [127] =
    {field_entity, 4},
  [128] =
    {field_geometry, 4},
    {field_target, 5},
  [130] =
    {field_entity, 3},
    {field_forever, 5},
  [132] =
    {field_forever, 5},
    {field_geometry, 3},
    {field_target, 4},
  [135] =
    {field_forever, 1},
  [136] =
    {field_bool, 1},
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [140] =
    {field_bool, 0, .inherited = true},
    {field_bool, 1, .inherited = true},
    {field_constant, 0, .inherited = true},
    {field_constant, 1, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 1, .inherited = true},
  [146] =
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 1},
    {field_identifier, 2, .inherited = true},
  [150] =
    {field_bool, 2, .inherited = true},
    {field_constant, 1},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [154] =
    {field_constant, 2, .inherited = true},
    {field_identifier, 1},
    {field_identifier, 2, .inherited = true},
    {field_int, 2, .inherited = true},
  [158] =
    {field_constant, 0, .inherited = true},
    {field_constant, 1, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 1, .inherited = true},
    {field_int, 0, .inherited = true},
    {field_int, 1, .inherited = true},
  [164] =
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
    {field_int, 1},
    {field_int, 2, .inherited = true},
  [168] =
    {field_constant, 1},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
    {field_int, 2, .inherited = true},
  [172] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [175] =
    {field_entity, 1},
    {field_forever, 6},
  [177] =
    {field_duration, 6},
    {field_entity, 1},
  [179] =
    {field_entity, 1},
    {field_entity, 5},
  [181] =
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
  [184] =
    {field_entity, 4},
    {field_forever, 6},
  [186] =
    {field_duration, 6},
  [187] =
    {field_forever, 6},
    {field_geometry, 4},
    {field_target, 5},
  [190] =
    {field_color, 4},
    {field_duration, 6},
    {field_fade, 2},
  [193] =
    {field_amplitude, 3},
    {field_distance, 4},
    {field_duration, 6},
  [196] =
    {field_entity, 3, .inherited = true},
    {field_geometry, 3, .inherited = true},
    {field_target, 3, .inherited = true},
  [199] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
    {field_geometry, 0, .inherited = true},
    {field_geometry, 1, .inherited = true},
    {field_target, 0, .inherited = true},
    {field_target, 1, .inherited = true},
  [205] =
    {field_geometry, 2},
    {field_target, 3},
  [207] =
    {field_duration, 6},
    {field_entity, 3},
  [209] =
    {field_duration, 6},
    {field_geometry, 3},
    {field_target, 4},
  [212] =
    {field_duration, 2},
  [213] =
    {field_duration, 2, .inherited = true},
    {field_forever, 1},
    {field_forever, 2, .inherited = true},
  [216] =
    {field_duration, 0, .inherited = true},
    {field_duration, 1, .inherited = true},
    {field_forever, 0, .inherited = true},
    {field_forever, 1, .inherited = true},
  [220] =
    {field_label, 1},
    {field_script, 3},
  [222] =
    {field_entity, 1},
    {field_entity, 5},
    {field_forever, 7},
  [225] =
    {field_duration, 7},
    {field_entity, 1},
  [227] =
    {field_entity, 1},
    {field_forever, 7},
    {field_geometry, 5},
    {field_target, 6},
  [231] =
    {field_duration, 7},
    {field_entity, 4},
  [233] =
    {field_duration, 7},
    {field_geometry, 4},
    {field_target, 5},
  [236] =
    {field_entity, 2},
    {field_entity, 4, .inherited = true},
    {field_geometry, 4, .inherited = true},
    {field_target, 4, .inherited = true},
  [240] =
    {field_entity, 4, .inherited = true},
    {field_geometry, 2},
    {field_geometry, 4, .inherited = true},
    {field_target, 3},
    {field_target, 4, .inherited = true},
  [245] =
    {field_duration, 2},
    {field_duration, 3, .inherited = true},
    {field_forever, 3, .inherited = true},
  [248] =
    {field_duration, 8},
    {field_entity, 1},
    {field_entity, 5},
  [251] =
    {field_duration, 8},
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
  [255] =
    {field_bool, 4, .inherited = true},
    {field_constant, 4, .inherited = true},
    {field_identifier, 4, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [37] = {
    [1] = alias_sym_else_body,
  },
  [70] = {
    [4] = alias_sym_if_body,
  },
  [79] = {
    [2] = alias_sym_label_settings,
  },
  [80] = {
    [2] = alias_sym_entity_settings,
  },
  [118] = {
    [5] = alias_sym_if_else_body,
  },
  [130] = {
    [8] = alias_sym_for_body,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_dialog_settings_block, 3,
    sym_dialog_settings_block,
    alias_sym_entity_settings,
    alias_sym_label_settings,
  sym_script_block, 4,
    sym_script_block,
    alias_sym_else_body,
    alias_sym_if_body,
    alias_sym_if_else_body,
  sym_looping_block, 2,
    sym_looping_block,
    alias_sym_for_body,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 7,
  [12] = 12,
  [13] = 12,
  [14] = 6,
  [15] = 9,
  [16] = 8,
  [17] = 10,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 20,
  [29] = 21,
  [30] = 30,
  [31] = 31,
  [32] = 22,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 25,
  [38] = 33,
  [39] = 34,
  [40] = 27,
  [41] = 35,
  [42] = 24,
  [43] = 31,
  [44] = 30,
  [45] = 26,
  [46] = 23,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 61,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 122,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 151,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 211,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 151,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 222,
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 261,
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 270,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 274,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
  [280] = 280,
  [281] = 281,
  [282] = 282,
  [283] = 283,
  [284] = 284,
  [285] = 285,
  [286] = 286,
  [287] = 287,
  [288] = 288,
  [289] = 289,
  [290] = 290,
  [291] = 291,
  [292] = 292,
  [293] = 293,
  [294] = 294,
  [295] = 295,
  [296] = 296,
  [297] = 297,
  [298] = 298,
  [299] = 299,
  [300] = 300,
  [301] = 301,
  [302] = 302,
  [303] = 303,
  [304] = 304,
  [305] = 305,
  [306] = 306,
  [307] = 307,
  [308] = 308,
  [309] = 309,
  [310] = 310,
  [311] = 311,
  [312] = 312,
  [313] = 313,
  [314] = 314,
  [315] = 315,
  [316] = 316,
  [317] = 317,
  [318] = 318,
  [319] = 319,
  [320] = 320,
  [321] = 321,
  [322] = 322,
  [323] = 323,
  [324] = 324,
  [325] = 325,
  [326] = 326,
  [327] = 327,
  [328] = 328,
  [329] = 329,
  [330] = 330,
  [331] = 331,
  [332] = 332,
  [333] = 137,
  [334] = 334,
  [335] = 335,
  [336] = 336,
  [337] = 337,
  [338] = 338,
  [339] = 339,
  [340] = 340,
  [341] = 341,
  [342] = 342,
  [343] = 343,
  [344] = 344,
  [345] = 345,
  [346] = 346,
  [347] = 347,
  [348] = 348,
  [349] = 349,
  [350] = 350,
  [351] = 351,
  [352] = 352,
  [353] = 353,
  [354] = 354,
  [355] = 355,
  [356] = 356,
  [357] = 357,
  [358] = 358,
  [359] = 359,
  [360] = 360,
  [361] = 361,
  [362] = 362,
  [363] = 363,
  [364] = 364,
  [365] = 365,
  [366] = 366,
  [367] = 367,
  [368] = 368,
  [369] = 369,
  [370] = 370,
  [371] = 371,
  [372] = 372,
  [373] = 373,
  [374] = 374,
  [375] = 375,
  [376] = 376,
  [377] = 377,
  [378] = 378,
  [379] = 379,
  [380] = 380,
  [381] = 381,
  [382] = 382,
  [383] = 383,
  [384] = 384,
  [385] = 385,
  [386] = 386,
  [387] = 387,
  [388] = 388,
  [389] = 389,
  [390] = 390,
  [391] = 391,
  [392] = 392,
  [393] = 393,
  [394] = 394,
  [395] = 395,
  [396] = 396,
  [397] = 397,
  [398] = 398,
  [399] = 399,
  [400] = 400,
  [401] = 401,
  [402] = 402,
  [403] = 403,
  [404] = 404,
  [405] = 405,
  [406] = 406,
  [407] = 407,
  [408] = 408,
  [409] = 409,
  [410] = 410,
  [411] = 411,
  [412] = 412,
  [413] = 413,
  [414] = 414,
  [415] = 415,
  [416] = 416,
  [417] = 417,
  [418] = 418,
  [419] = 419,
  [420] = 420,
  [421] = 421,
  [422] = 422,
  [423] = 423,
  [424] = 424,
  [425] = 425,
  [426] = 426,
  [427] = 427,
  [428] = 428,
  [429] = 429,
  [430] = 430,
  [431] = 431,
  [432] = 432,
  [433] = 433,
  [434] = 434,
  [435] = 435,
  [436] = 436,
  [437] = 437,
  [438] = 438,
  [439] = 439,
  [440] = 440,
  [441] = 441,
  [442] = 442,
  [443] = 443,
  [444] = 444,
  [445] = 445,
  [446] = 446,
  [447] = 447,
  [448] = 448,
  [449] = 449,
  [450] = 450,
  [451] = 451,
  [452] = 452,
  [453] = 453,
  [454] = 454,
  [455] = 455,
  [456] = 456,
  [457] = 457,
  [458] = 458,
  [459] = 459,
  [460] = 460,
  [461] = 461,
  [462] = 462,
  [463] = 463,
  [464] = 464,
  [465] = 465,
  [466] = 466,
  [467] = 467,
  [468] = 468,
  [469] = 469,
  [470] = 470,
  [471] = 471,
  [472] = 472,
  [473] = 473,
  [474] = 474,
  [475] = 475,
  [476] = 476,
  [477] = 477,
  [478] = 478,
  [479] = 479,
  [480] = 480,
  [481] = 481,
  [482] = 482,
  [483] = 483,
  [484] = 484,
  [485] = 485,
  [486] = 486,
  [487] = 487,
  [488] = 488,
  [489] = 489,
  [490] = 490,
  [491] = 491,
  [492] = 492,
  [493] = 493,
  [494] = 494,
  [495] = 495,
  [496] = 496,
  [497] = 497,
  [498] = 498,
  [499] = 499,
  [500] = 500,
  [501] = 501,
  [502] = 502,
  [503] = 503,
  [504] = 504,
  [505] = 505,
  [506] = 506,
  [507] = 507,
  [508] = 508,
  [509] = 509,
  [510] = 510,
  [511] = 511,
  [512] = 512,
  [513] = 513,
  [514] = 514,
  [515] = 515,
  [516] = 516,
  [517] = 517,
  [518] = 518,
  [519] = 519,
  [520] = 520,
  [521] = 72,
  [522] = 522,
  [523] = 62,
  [524] = 524,
  [525] = 525,
  [526] = 526,
  [527] = 527,
  [528] = 454,
  [529] = 529,
  [530] = 530,
  [531] = 531,
  [532] = 532,
  [533] = 392,
  [534] = 534,
  [535] = 535,
  [536] = 536,
  [537] = 537,
  [538] = 538,
  [539] = 539,
  [540] = 540,
  [541] = 541,
  [542] = 542,
  [543] = 543,
  [544] = 544,
  [545] = 545,
  [546] = 546,
  [547] = 547,
  [548] = 548,
  [549] = 549,
  [550] = 550,
  [551] = 551,
  [552] = 552,
  [553] = 553,
  [554] = 554,
  [555] = 555,
  [556] = 556,
  [557] = 557,
  [558] = 558,
  [559] = 559,
  [560] = 560,
  [561] = 561,
  [562] = 562,
  [563] = 563,
  [564] = 564,
  [565] = 565,
  [566] = 566,
  [567] = 567,
  [568] = 568,
  [569] = 569,
  [570] = 570,
  [571] = 571,
  [572] = 572,
  [573] = 573,
  [574] = 574,
  [575] = 575,
  [576] = 576,
  [577] = 577,
  [578] = 578,
  [579] = 579,
  [580] = 580,
  [581] = 581,
  [582] = 582,
  [583] = 583,
  [584] = 584,
  [585] = 585,
  [586] = 586,
  [587] = 587,
  [588] = 588,
  [589] = 589,
  [590] = 590,
  [591] = 591,
  [592] = 592,
  [593] = 593,
  [594] = 594,
  [595] = 595,
  [596] = 596,
  [597] = 597,
  [598] = 598,
  [599] = 599,
  [600] = 600,
  [601] = 601,
  [602] = 602,
  [603] = 603,
  [604] = 604,
  [605] = 605,
  [606] = 606,
  [607] = 607,
  [608] = 608,
  [609] = 609,
  [610] = 610,
  [611] = 611,
  [612] = 612,
  [613] = 613,
  [614] = 614,
  [615] = 615,
  [616] = 616,
  [617] = 617,
  [618] = 618,
  [619] = 619,
  [620] = 620,
  [621] = 621,
  [622] = 622,
  [623] = 623,
  [624] = 624,
  [625] = 625,
  [626] = 626,
  [627] = 627,
  [628] = 628,
  [629] = 629,
  [630] = 630,
  [631] = 631,
  [632] = 632,
  [633] = 633,
  [634] = 634,
  [635] = 635,
  [636] = 636,
  [637] = 637,
  [638] = 638,
  [639] = 639,
  [640] = 640,
  [641] = 641,
  [642] = 642,
  [643] = 643,
  [644] = 644,
  [645] = 645,
  [646] = 646,
  [647] = 647,
  [648] = 648,
  [649] = 649,
  [650] = 650,
  [651] = 651,
  [652] = 652,
  [653] = 653,
  [654] = 654,
  [655] = 655,
  [656] = 656,
  [657] = 657,
  [658] = 658,
  [659] = 659,
  [660] = 660,
  [661] = 661,
  [662] = 662,
  [663] = 663,
  [664] = 664,
  [665] = 665,
  [666] = 666,
  [667] = 667,
  [668] = 668,
  [669] = 669,
  [670] = 670,
  [671] = 671,
  [672] = 672,
  [673] = 673,
  [674] = 674,
  [675] = 675,
  [676] = 676,
  [677] = 677,
  [678] = 678,
  [679] = 679,
  [680] = 680,
  [681] = 681,
  [682] = 682,
  [683] = 683,
  [684] = 684,
  [685] = 685,
  [686] = 686,
  [687] = 687,
  [688] = 688,
  [689] = 689,
  [690] = 690,
  [691] = 691,
  [692] = 692,
  [693] = 693,
  [694] = 694,
  [695] = 695,
  [696] = 696,
  [697] = 697,
  [698] = 698,
  [699] = 699,
  [700] = 700,
  [701] = 701,
  [702] = 702,
  [703] = 703,
  [704] = 704,
  [705] = 705,
  [706] = 706,
  [707] = 707,
  [708] = 708,
  [709] = 709,
  [710] = 710,
  [711] = 711,
  [712] = 712,
  [713] = 713,
  [714] = 714,
  [715] = 715,
  [716] = 716,
  [717] = 717,
  [718] = 718,
  [719] = 719,
  [720] = 720,
  [721] = 721,
  [722] = 722,
  [723] = 723,
  [724] = 724,
  [725] = 725,
  [726] = 726,
  [727] = 727,
  [728] = 728,
  [729] = 729,
  [730] = 730,
  [731] = 731,
  [732] = 732,
  [733] = 733,
  [734] = 734,
  [735] = 735,
  [736] = 736,
  [737] = 737,
  [738] = 738,
  [739] = 739,
  [740] = 740,
  [741] = 741,
  [742] = 673,
  [743] = 553,
  [744] = 744,
  [745] = 745,
  [746] = 746,
  [747] = 747,
  [748] = 748,
  [749] = 749,
  [750] = 750,
  [751] = 751,
  [752] = 752,
  [753] = 753,
  [754] = 754,
  [755] = 755,
  [756] = 756,
  [757] = 757,
  [758] = 758,
  [759] = 759,
  [760] = 760,
  [761] = 761,
  [762] = 762,
  [763] = 763,
  [764] = 764,
  [765] = 765,
  [766] = 766,
  [767] = 767,
  [768] = 768,
  [769] = 769,
  [770] = 770,
  [771] = 771,
  [772] = 772,
  [773] = 773,
  [774] = 774,
  [775] = 775,
  [776] = 776,
  [777] = 777,
  [778] = 778,
  [779] = 779,
  [780] = 780,
  [781] = 781,
  [782] = 782,
  [783] = 783,
  [784] = 784,
  [785] = 785,
  [786] = 786,
  [787] = 787,
  [788] = 788,
  [789] = 789,
  [790] = 790,
  [791] = 791,
  [792] = 792,
  [793] = 793,
  [794] = 794,
  [795] = 795,
  [796] = 796,
  [797] = 797,
  [798] = 798,
  [799] = 799,
  [800] = 800,
  [801] = 801,
  [802] = 802,
  [803] = 803,
  [804] = 804,
  [805] = 805,
  [806] = 806,
  [807] = 807,
  [808] = 808,
  [809] = 809,
  [810] = 810,
  [811] = 811,
  [812] = 812,
  [813] = 813,
  [814] = 814,
  [815] = 815,
  [816] = 816,
  [817] = 817,
  [818] = 818,
  [819] = 819,
  [820] = 820,
  [821] = 821,
  [822] = 822,
  [823] = 823,
  [824] = 824,
  [825] = 825,
  [826] = 826,
  [827] = 827,
  [828] = 828,
  [829] = 829,
  [830] = 830,
  [831] = 831,
  [832] = 832,
  [833] = 833,
  [834] = 834,
  [835] = 835,
  [836] = 836,
  [837] = 837,
  [838] = 838,
  [839] = 839,
  [840] = 840,
  [841] = 841,
  [842] = 842,
  [843] = 843,
  [844] = 844,
  [845] = 845,
  [846] = 846,
  [847] = 847,
  [848] = 800,
  [849] = 849,
  [850] = 850,
  [851] = 851,
  [852] = 852,
  [853] = 853,
  [854] = 854,
  [855] = 855,
  [856] = 839,
  [857] = 841,
  [858] = 858,
  [859] = 859,
  [860] = 813,
  [861] = 752,
  [862] = 748,
  [863] = 850,
  [864] = 760,
  [865] = 763,
  [866] = 866,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(453);
      ADVANCE_MAP(
        '!', 804,
        '"', 8,
        '#', 790,
        '$', 450,
        '%', 911,
        '&', 13,
        '(', 805,
        ')', 806,
        '*', 909,
        '+', 829,
        ',', 459,
        '-', 913,
        '/', 910,
        ':', 795,
        ';', 762,
        '<', 894,
        '=', 764,
        '>', 788,
        '[', 458,
        ']', 460,
        '_', 789,
        'a', 100,
        'b', 240,
        'c', 33,
        'd', 120,
        'e', 248,
        'f', 35,
        'g', 150,
        'h', 121,
        'i', 176,
        'j', 373,
        'l', 37,
        'm', 38,
        'n', 70,
        'o', 275,
        'p', 39,
        'r', 53,
        's', 40,
        't', 197,
        'u', 276,
        'w', 41,
        'x', 914,
        'y', 916,
        '{', 770,
        '|', 446,
        '}', 771,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(747);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '!', 803,
        '"', 8,
        '#', 447,
        '$', 450,
        '(', 805,
        '/', 14,
        '[', 458,
        ']', 460,
        'b', 616,
        'c', 629,
        'f', 495,
        'g', 699,
        'm', 490,
        'o', 577,
        'r', 564,
        't', 587,
        'w', 588,
        'y', 567,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(747);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '!', 803,
        '$', 450,
        ')', 806,
        ',', 459,
        '-', 19,
        '/', 14,
        ':', 795,
        ';', 762,
        '=', 763,
        '[', 458,
        ']', 460,
        'a', 627,
        'b', 620,
        'c', 470,
        'd', 538,
        'e', 649,
        'f', 622,
        'g', 667,
        'h', 539,
        'i', 574,
        'j', 704,
        'l', 591,
        'm', 479,
        'p', 478,
        'r', 482,
        's', 473,
        'u', 644,
        'w', 475,
        '}', 771,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(748);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('k' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '"', 8,
        '$', 450,
        '(', 805,
        '-', 912,
        '/', 14,
        '[', 458,
        ']', 460,
        '{', 770,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(748);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(8);
      if (lookahead == '$') ADVANCE(450);
      if (lookahead == ')') ADVANCE(806);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == 'w') ADVANCE(700);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(8);
      if (lookahead == '$') ADVANCE(450);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '[') ADVANCE(458);
      if (lookahead == 'i') ADVANCE(659);
      if (lookahead == 'l') ADVANCE(481);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '"', 8,
        ')', 806,
        '+', 829,
        '-', 20,
        '/', 14,
        ';', 762,
        '=', 763,
        'I', 290,
        '[', 458,
        ']', 460,
        'a', 286,
        'c', 34,
        'e', 274,
        'f', 36,
        'g', 149,
        'i', 285,
        'm', 61,
        'n', 70,
        'o', 294,
        'p', 68,
        's', 148,
        't', 339,
        'x', 914,
        'y', 915,
        '{', 770,
        '}', 771,
        '#', 789,
        '_', 789,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(797);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(8);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '>') ADVANCE(787);
      if (lookahead == 'e') ADVANCE(650);
      if (lookahead == 'n') ADVANCE(500);
      if (lookahead == '}') ADVANCE(771);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(746);
      if (lookahead == '\\') ADVANCE(451);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '#', 447,
        '$', 450,
        ')', 806,
        '/', 14,
        ';', 762,
        '[', 458,
        ']', 460,
        'b', 249,
        'c', 440,
        'g', 346,
        'm', 64,
        'o', 287,
        'r', 161,
        't', 198,
        'w', 199,
        'y', 167,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(754);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        '$', 450,
        ')', 806,
        ',', 459,
        '/', 14,
        '[', 458,
        ']', 460,
        'a', 627,
        'b', 621,
        'c', 471,
        'd', 538,
        'e', 649,
        'f', 622,
        'g', 667,
        'h', 539,
        'i', 574,
        'j', 704,
        'l', 591,
        'm', 479,
        'p', 478,
        'r', 482,
        's', 473,
        'u', 644,
        'w', 475,
        '}', 771,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(750);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('k' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 11:
      ADVANCE_MAP(
        '$', 450,
        '/', 14,
        '[', 458,
        'a', 627,
        'b', 621,
        'c', 471,
        'd', 572,
        'e', 649,
        'f', 622,
        'g', 667,
        'h', 539,
        'i', 574,
        'l', 591,
        'm', 479,
        'p', 478,
        'r', 557,
        's', 474,
        'u', 644,
        'w', 475,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('j' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 12:
      if (lookahead == '$') ADVANCE(450);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == ']') ADVANCE(460);
      if (lookahead == 'c') ADVANCE(472);
      if (lookahead == 'e') ADVANCE(650);
      if (lookahead == 'p') ADVANCE(634);
      if (lookahead == 's') ADVANCE(568);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 13:
      if (lookahead == '&') ADVANCE(891);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '/') ADVANCE(455);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(15);
      if (lookahead == '/') ADVANCE(454);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '=') ADVANCE(897);
      END_STATE();
    case 18:
      if (lookahead == '=') ADVANCE(896);
      END_STATE();
    case 19:
      if (lookahead == '>') ADVANCE(860);
      END_STATE();
    case 20:
      if (lookahead == '>') ADVANCE(860);
      if (lookahead == 'I') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(797);
      END_STATE();
    case 21:
      if (lookahead == 'N') ADVANCE(77);
      END_STATE();
    case 22:
      if (lookahead == '_') ADVANCE(226);
      END_STATE();
    case 23:
      if (lookahead == '_') ADVANCE(226);
      if (lookahead == 'c') ADVANCE(122);
      END_STATE();
    case 24:
      if (lookahead == '_') ADVANCE(86);
      END_STATE();
    case 25:
      if (lookahead == '_') ADVANCE(98);
      END_STATE();
    case 26:
      if (lookahead == '_') ADVANCE(266);
      END_STATE();
    case 27:
      if (lookahead == '_') ADVANCE(97);
      END_STATE();
    case 28:
      if (lookahead == '_') ADVANCE(382);
      END_STATE();
    case 29:
      if (lookahead == '_') ADVANCE(214);
      END_STATE();
    case 30:
      if (lookahead == '_') ADVANCE(215);
      END_STATE();
    case 31:
      if (lookahead == '_') ADVANCE(67);
      END_STATE();
    case 32:
      if (lookahead == '_') ADVANCE(412);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(271);
      if (lookahead == 'l') ADVANCE(327);
      if (lookahead == 'o') ADVANCE(262);
      if (lookahead == 'u') ADVANCE(352);
      if (lookahead == 'y') ADVANCE(56);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(271);
      if (lookahead == 'u') ADVANCE(352);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 'l') ADVANCE(49);
      if (lookahead == 'o') ADVANCE(340);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 'o') ADVANCE(364);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'e') ADVANCE(288);
      if (lookahead == 'i') ADVANCE(181);
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(190);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(396);
      if (lookahead == 'l') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(351);
      if (lookahead == 'r') ADVANCE(222);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(430);
      if (lookahead == 'c') ADVANCE(353);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead == 'h') ADVANCE(47);
      if (lookahead == 'l') ADVANCE(313);
      if (lookahead == 'p') ADVANCE(365);
      if (lookahead == 't') ADVANCE(355);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(210);
      if (lookahead == 'h') ADVANCE(201);
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(87);
      if (lookahead == 'o') ADVANCE(89);
      if (lookahead == 'u') ADVANCE(123);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(87);
      if (lookahead == 'u') ADVANCE(123);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(444);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(755);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(239);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(239);
      if (lookahead == 'o') ADVANCE(433);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(857);
      END_STATE();
    case 49:
      if (lookahead == 'a') ADVANCE(182);
      END_STATE();
    case 50:
      if (lookahead == 'a') ADVANCE(253);
      END_STATE();
    case 51:
      if (lookahead == 'a') ADVANCE(179);
      END_STATE();
    case 52:
      if (lookahead == 'a') ADVANCE(334);
      END_STATE();
    case 53:
      if (lookahead == 'a') ADVANCE(289);
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 54:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 55:
      if (lookahead == 'a') ADVANCE(371);
      if (lookahead == 'g') ADVANCE(303);
      END_STATE();
    case 56:
      if (lookahead == 'a') ADVANCE(277);
      END_STATE();
    case 57:
      if (lookahead == 'a') ADVANCE(424);
      END_STATE();
    case 58:
      if (lookahead == 'a') ADVANCE(236);
      END_STATE();
    case 59:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 60:
      if (lookahead == 'a') ADVANCE(429);
      END_STATE();
    case 61:
      if (lookahead == 'a') ADVANCE(333);
      END_STATE();
    case 62:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 63:
      if (lookahead == 'a') ADVANCE(252);
      END_STATE();
    case 64:
      if (lookahead == 'a') ADVANCE(189);
      END_STATE();
    case 65:
      if (lookahead == 'a') ADVANCE(348);
      END_STATE();
    case 66:
      if (lookahead == 'a') ADVANCE(387);
      END_STATE();
    case 67:
      if (lookahead == 'a') ADVANCE(306);
      END_STATE();
    case 68:
      if (lookahead == 'a') ADVANCE(395);
      if (lookahead == 'l') ADVANCE(79);
      if (lookahead == 'o') ADVANCE(375);
      if (lookahead == 'r') ADVANCE(222);
      END_STATE();
    case 69:
      if (lookahead == 'a') ADVANCE(356);
      END_STATE();
    case 70:
      if (lookahead == 'a') ADVANCE(264);
      if (lookahead == 'u') ADVANCE(250);
      END_STATE();
    case 71:
      if (lookahead == 'a') ADVANCE(377);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(255);
      END_STATE();
    case 73:
      if (lookahead == 'a') ADVANCE(293);
      END_STATE();
    case 74:
      if (lookahead == 'a') ADVANCE(218);
      END_STATE();
    case 75:
      if (lookahead == 'a') ADVANCE(416);
      END_STATE();
    case 76:
      if (lookahead == 'a') ADVANCE(256);
      END_STATE();
    case 77:
      if (lookahead == 'a') ADVANCE(268);
      END_STATE();
    case 78:
      if (lookahead == 'a') ADVANCE(269);
      END_STATE();
    case 79:
      if (lookahead == 'a') ADVANCE(445);
      END_STATE();
    case 80:
      if (lookahead == 'a') ADVANCE(368);
      END_STATE();
    case 81:
      if (lookahead == 'a') ADVANCE(420);
      END_STATE();
    case 82:
      if (lookahead == 'a') ADVANCE(422);
      END_STATE();
    case 83:
      if (lookahead == 'b') ADVANCE(423);
      if (lookahead == 'f') ADVANCE(57);
      if (lookahead == 'l') ADVANCE(169);
      END_STATE();
    case 84:
      if (lookahead == 'b') ADVANCE(153);
      END_STATE();
    case 85:
      if (lookahead == 'b') ADVANCE(326);
      END_STATE();
    case 86:
      if (lookahead == 'c') ADVANCE(257);
      if (lookahead == 'd') ADVANCE(224);
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 87:
      if (lookahead == 'c') ADVANCE(234);
      END_STATE();
    case 88:
      if (lookahead == 'c') ADVANCE(196);
      END_STATE();
    case 89:
      if (lookahead == 'c') ADVANCE(235);
      END_STATE();
    case 90:
      if (lookahead == 'c') ADVANCE(328);
      if (lookahead == 'l') ADVANCE(177);
      END_STATE();
    case 91:
      if (lookahead == 'c') ADVANCE(328);
      if (lookahead == 'l') ADVANCE(177);
      if (lookahead == 'r') ADVANCE(216);
      if (lookahead == 't') ADVANCE(406);
      END_STATE();
    case 92:
      if (lookahead == 'c') ADVANCE(238);
      END_STATE();
    case 93:
      if (lookahead == 'c') ADVANCE(66);
      if (lookahead == 't') ADVANCE(209);
      END_STATE();
    case 94:
      if (lookahead == 'c') ADVANCE(122);
      END_STATE();
    case 95:
      if (lookahead == 'c') ADVANCE(392);
      END_STATE();
    case 96:
      if (lookahead == 'c') ADVANCE(394);
      END_STATE();
    case 97:
      if (lookahead == 'c') ADVANCE(331);
      END_STATE();
    case 98:
      if (lookahead == 'c') ADVANCE(323);
      if (lookahead == 'd') ADVANCE(232);
      END_STATE();
    case 99:
      if (lookahead == 'c') ADVANCE(332);
      END_STATE();
    case 100:
      if (lookahead == 'd') ADVANCE(101);
      if (lookahead == 'l') ADVANCE(200);
      if (lookahead == 'n') ADVANCE(202);
      END_STATE();
    case 101:
      if (lookahead == 'd') ADVANCE(765);
      END_STATE();
    case 102:
      if (lookahead == 'd') ADVANCE(755);
      END_STATE();
    case 103:
      if (lookahead == 'd') ADVANCE(755);
      if (lookahead == 't') ADVANCE(425);
      END_STATE();
    case 104:
      if (lookahead == 'd') ADVANCE(813);
      END_STATE();
    case 105:
      if (lookahead == 'd') ADVANCE(807);
      END_STATE();
    case 106:
      if (lookahead == 'd') ADVANCE(809);
      END_STATE();
    case 107:
      if (lookahead == 'd') ADVANCE(827);
      END_STATE();
    case 108:
      if (lookahead == 'd') ADVANCE(872);
      END_STATE();
    case 109:
      if (lookahead == 'd') ADVANCE(917);
      END_STATE();
    case 110:
      if (lookahead == 'd') ADVANCE(918);
      END_STATE();
    case 111:
      if (lookahead == 'd') ADVANCE(885);
      END_STATE();
    case 112:
      if (lookahead == 'd') ADVANCE(125);
      if (lookahead == 'i') ADVANCE(241);
      if (lookahead == 'l') ADVANCE(378);
      END_STATE();
    case 113:
      if (lookahead == 'd') ADVANCE(126);
      END_STATE();
    case 114:
      if (lookahead == 'd') ADVANCE(223);
      END_STATE();
    case 115:
      if (lookahead == 'd') ADVANCE(139);
      END_STATE();
    case 116:
      if (lookahead == 'd') ADVANCE(140);
      END_STATE();
    case 117:
      if (lookahead == 'd') ADVANCE(146);
      END_STATE();
    case 118:
      if (lookahead == 'd') ADVANCE(159);
      END_STATE();
    case 119:
      if (lookahead == 'd') ADVANCE(80);
      END_STATE();
    case 120:
      if (lookahead == 'e') ADVANCE(83);
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 121:
      if (lookahead == 'e') ADVANCE(434);
      if (lookahead == 'i') ADVANCE(113);
      END_STATE();
    case 122:
      if (lookahead == 'e') ADVANCE(753);
      END_STATE();
    case 123:
      if (lookahead == 'e') ADVANCE(755);
      END_STATE();
    case 124:
      if (lookahead == 'e') ADVANCE(900);
      END_STATE();
    case 125:
      if (lookahead == 'e') ADVANCE(859);
      END_STATE();
    case 126:
      if (lookahead == 'e') ADVANCE(832);
      END_STATE();
    case 127:
      if (lookahead == 'e') ADVANCE(781);
      END_STATE();
    case 128:
      if (lookahead == 'e') ADVANCE(836);
      END_STATE();
    case 129:
      if (lookahead == 'e') ADVANCE(798);
      END_STATE();
    case 130:
      if (lookahead == 'e') ADVANCE(845);
      END_STATE();
    case 131:
      if (lookahead == 'e') ADVANCE(786);
      END_STATE();
    case 132:
      if (lookahead == 'e') ADVANCE(839);
      END_STATE();
    case 133:
      if (lookahead == 'e') ADVANCE(799);
      END_STATE();
    case 134:
      if (lookahead == 'e') ADVANCE(853);
      END_STATE();
    case 135:
      if (lookahead == 'e') ADVANCE(865);
      END_STATE();
    case 136:
      if (lookahead == 'e') ADVANCE(905);
      END_STATE();
    case 137:
      if (lookahead == 'e') ADVANCE(825);
      END_STATE();
    case 138:
      if (lookahead == 'e') ADVANCE(922);
      END_STATE();
    case 139:
      if (lookahead == 'e') ADVANCE(834);
      END_STATE();
    case 140:
      if (lookahead == 'e') ADVANCE(760);
      END_STATE();
    case 141:
      if (lookahead == 'e') ADVANCE(855);
      END_STATE();
    case 142:
      if (lookahead == 'e') ADVANCE(903);
      END_STATE();
    case 143:
      if (lookahead == 'e') ADVANCE(889);
      END_STATE();
    case 144:
      if (lookahead == 'e') ADVANCE(930);
      END_STATE();
    case 145:
      if (lookahead == 'e') ADVANCE(921);
      END_STATE();
    case 146:
      if (lookahead == 'e') ADVANCE(881);
      END_STATE();
    case 147:
      if (lookahead == 'e') ADVANCE(919);
      END_STATE();
    case 148:
      if (lookahead == 'e') ADVANCE(90);
      if (lookahead == 'h') ADVANCE(46);
      if (lookahead == 't') ADVANCE(355);
      END_STATE();
    case 149:
      if (lookahead == 'e') ADVANCE(329);
      if (lookahead == 'l') ADVANCE(208);
      END_STATE();
    case 150:
      if (lookahead == 'e') ADVANCE(329);
      if (lookahead == 'l') ADVANCE(208);
      if (lookahead == 'o') ADVANCE(401);
      if (lookahead == 'r') ADVANCE(156);
      END_STATE();
    case 151:
      if (lookahead == 'e') ADVANCE(436);
      END_STATE();
    case 152:
      if (lookahead == 'e') ADVANCE(277);
      END_STATE();
    case 153:
      if (lookahead == 'e') ADVANCE(243);
      END_STATE();
    case 154:
      if (lookahead == 'e') ADVANCE(295);
      END_STATE();
    case 155:
      if (lookahead == 'e') ADVANCE(341);
      END_STATE();
    case 156:
      if (lookahead == 'e') ADVANCE(152);
      END_STATE();
    case 157:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 158:
      if (lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 159:
      if (lookahead == 'e') ADVANCE(347);
      END_STATE();
    case 160:
      if (lookahead == 'e') ADVANCE(342);
      END_STATE();
    case 161:
      if (lookahead == 'e') ADVANCE(102);
      END_STATE();
    case 162:
      if (lookahead == 'e') ADVANCE(343);
      END_STATE();
    case 163:
      if (lookahead == 'e') ADVANCE(407);
      END_STATE();
    case 164:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 165:
      if (lookahead == 'e') ADVANCE(345);
      END_STATE();
    case 166:
      if (lookahead == 'e') ADVANCE(393);
      END_STATE();
    case 167:
      if (lookahead == 'e') ADVANCE(261);
      END_STATE();
    case 168:
      if (lookahead == 'e') ADVANCE(431);
      END_STATE();
    case 169:
      if (lookahead == 'e') ADVANCE(415);
      END_STATE();
    case 170:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 171:
      if (lookahead == 'e') ADVANCE(359);
      END_STATE();
    case 172:
      if (lookahead == 'e') ADVANCE(297);
      END_STATE();
    case 173:
      if (lookahead == 'e') ADVANCE(363);
      END_STATE();
    case 174:
      if (lookahead == 'e') ADVANCE(298);
      END_STATE();
    case 175:
      if (lookahead == 'e') ADVANCE(381);
      END_STATE();
    case 176:
      if (lookahead == 'f') ADVANCE(898);
      if (lookahead == 'n') ADVANCE(863);
      END_STATE();
    case 177:
      if (lookahead == 'f') ADVANCE(851);
      END_STATE();
    case 178:
      if (lookahead == 'f') ADVANCE(217);
      END_STATE();
    case 179:
      if (lookahead == 'f') ADVANCE(138);
      END_STATE();
    case 180:
      if (lookahead == 'f') ADVANCE(369);
      END_STATE();
    case 181:
      if (lookahead == 'g') ADVANCE(195);
      END_STATE();
    case 182:
      if (lookahead == 'g') ADVANCE(21);
      END_STATE();
    case 183:
      if (lookahead == 'g') ADVANCE(801);
      END_STATE();
    case 184:
      if (lookahead == 'g') ADVANCE(774);
      END_STATE();
    case 185:
      if (lookahead == 'g') ADVANCE(767);
      END_STATE();
    case 186:
      if (lookahead == 'g') ADVANCE(372);
      END_STATE();
    case 187:
      if (lookahead == 'g') ADVANCE(26);
      END_STATE();
    case 188:
      if (lookahead == 'g') ADVANCE(400);
      END_STATE();
    case 189:
      if (lookahead == 'g') ADVANCE(154);
      END_STATE();
    case 190:
      if (lookahead == 'g') ADVANCE(154);
      if (lookahead == 'p') ADVANCE(815);
      END_STATE();
    case 191:
      if (lookahead == 'g') ADVANCE(211);
      END_STATE();
    case 192:
      if (lookahead == 'h') ADVANCE(923);
      END_STATE();
    case 193:
      if (lookahead == 'h') ADVANCE(869);
      END_STATE();
    case 194:
      if (lookahead == 'h') ADVANCE(229);
      if (lookahead == 'p') ADVANCE(60);
      END_STATE();
    case 195:
      if (lookahead == 'h') ADVANCE(386);
      END_STATE();
    case 196:
      if (lookahead == 'h') ADVANCE(158);
      END_STATE();
    case 197:
      if (lookahead == 'h') ADVANCE(350);
      if (lookahead == 'r') ADVANCE(426);
      if (lookahead == 'w') ADVANCE(204);
      END_STATE();
    case 198:
      if (lookahead == 'h') ADVANCE(350);
      if (lookahead == 'w') ADVANCE(204);
      END_STATE();
    case 199:
      if (lookahead == 'h') ADVANCE(220);
      END_STATE();
    case 200:
      if (lookahead == 'i') ADVANCE(55);
      END_STATE();
    case 201:
      if (lookahead == 'i') ADVANCE(259);
      END_STATE();
    case 202:
      if (lookahead == 'i') ADVANCE(263);
      END_STATE();
    case 203:
      if (lookahead == 'i') ADVANCE(435);
      if (lookahead == 'x') ADVANCE(751);
      END_STATE();
    case 204:
      if (lookahead == 'i') ADVANCE(94);
      END_STATE();
    case 205:
      if (lookahead == 'i') ADVANCE(337);
      END_STATE();
    case 206:
      if (lookahead == 'i') ADVANCE(191);
      END_STATE();
    case 207:
      if (lookahead == 'i') ADVANCE(335);
      END_STATE();
    case 208:
      if (lookahead == 'i') ADVANCE(398);
      END_STATE();
    case 209:
      if (lookahead == 'i') ADVANCE(300);
      END_STATE();
    case 210:
      if (lookahead == 'i') ADVANCE(385);
      if (lookahead == 'r') ADVANCE(336);
      END_STATE();
    case 211:
      if (lookahead == 'i') ADVANCE(279);
      END_STATE();
    case 212:
      if (lookahead == 'i') ADVANCE(397);
      END_STATE();
    case 213:
      if (lookahead == 'i') ADVANCE(260);
      END_STATE();
    case 214:
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 215:
      if (lookahead == 'i') ADVANCE(110);
      END_STATE();
    case 216:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 217:
      if (lookahead == 'i') ADVANCE(304);
      END_STATE();
    case 218:
      if (lookahead == 'i') ADVANCE(390);
      END_STATE();
    case 219:
      if (lookahead == 'i') ADVANCE(404);
      END_STATE();
    case 220:
      if (lookahead == 'i') ADVANCE(399);
      END_STATE();
    case 221:
      if (lookahead == 'i') ADVANCE(292);
      END_STATE();
    case 222:
      if (lookahead == 'i') ADVANCE(265);
      END_STATE();
    case 223:
      if (lookahead == 'i') ADVANCE(405);
      END_STATE();
    case 224:
      if (lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 225:
      if (lookahead == 'i') ADVANCE(318);
      END_STATE();
    case 226:
      if (lookahead == 'i') ADVANCE(296);
      if (lookahead == 'l') ADVANCE(316);
      if (lookahead == 't') ADVANCE(228);
      END_STATE();
    case 227:
      if (lookahead == 'i') ADVANCE(409);
      END_STATE();
    case 228:
      if (lookahead == 'i') ADVANCE(92);
      END_STATE();
    case 229:
      if (lookahead == 'i') ADVANCE(115);
      END_STATE();
    case 230:
      if (lookahead == 'i') ADVANCE(320);
      END_STATE();
    case 231:
      if (lookahead == 'i') ADVANCE(324);
      END_STATE();
    case 232:
      if (lookahead == 'i') ADVANCE(76);
      END_STATE();
    case 233:
      if (lookahead == 'i') ADVANCE(273);
      END_STATE();
    case 234:
      if (lookahead == 'k') ADVANCE(755);
      END_STATE();
    case 235:
      if (lookahead == 'k') ADVANCE(841);
      END_STATE();
    case 236:
      if (lookahead == 'k') ADVANCE(901);
      END_STATE();
    case 237:
      if (lookahead == 'k') ADVANCE(925);
      END_STATE();
    case 238:
      if (lookahead == 'k') ADVANCE(924);
      END_STATE();
    case 239:
      if (lookahead == 'k') ADVANCE(135);
      END_STATE();
    case 240:
      if (lookahead == 'l') ADVANCE(42);
      if (lookahead == 'o') ADVANCE(366);
      if (lookahead == 'r') ADVANCE(157);
      END_STATE();
    case 241:
      if (lookahead == 'l') ADVANCE(927);
      END_STATE();
    case 242:
      if (lookahead == 'l') ADVANCE(800);
      END_STATE();
    case 243:
      if (lookahead == 'l') ADVANCE(777);
      END_STATE();
    case 244:
      if (lookahead == 'l') ADVANCE(883);
      END_STATE();
    case 245:
      if (lookahead == 'l') ADVANCE(877);
      END_STATE();
    case 246:
      if (lookahead == 'l') ADVANCE(875);
      END_STATE();
    case 247:
      if (lookahead == 'l') ADVANCE(887);
      END_STATE();
    case 248:
      if (lookahead == 'l') ADVANCE(374);
      if (lookahead == 'm') ADVANCE(309);
      if (lookahead == 'n') ADVANCE(417);
      if (lookahead == 'r') ADVANCE(71);
      END_STATE();
    case 249:
      if (lookahead == 'l') ADVANCE(43);
      END_STATE();
    case 250:
      if (lookahead == 'l') ADVANCE(242);
      END_STATE();
    case 251:
      if (lookahead == 'l') ADVANCE(428);
      END_STATE();
    case 252:
      if (lookahead == 'l') ADVANCE(25);
      END_STATE();
    case 253:
      if (lookahead == 'l') ADVANCE(312);
      END_STATE();
    case 254:
      if (lookahead == 'l') ADVANCE(308);
      END_STATE();
    case 255:
      if (lookahead == 'l') ADVANCE(314);
      END_STATE();
    case 256:
      if (lookahead == 'l') ADVANCE(315);
      END_STATE();
    case 257:
      if (lookahead == 'l') ADVANCE(207);
      if (lookahead == 'o') ADVANCE(301);
      END_STATE();
    case 258:
      if (lookahead == 'l') ADVANCE(389);
      END_STATE();
    case 259:
      if (lookahead == 'l') ADVANCE(136);
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 260:
      if (lookahead == 'l') ADVANCE(175);
      END_STATE();
    case 261:
      if (lookahead == 'l') ADVANCE(254);
      END_STATE();
    case 262:
      if (lookahead == 'm') ADVANCE(270);
      if (lookahead == 'n') ADVANCE(93);
      END_STATE();
    case 263:
      if (lookahead == 'm') ADVANCE(81);
      END_STATE();
    case 264:
      if (lookahead == 'm') ADVANCE(127);
      END_STATE();
    case 265:
      if (lookahead == 'm') ADVANCE(65);
      END_STATE();
    case 266:
      if (lookahead == 'm') ADVANCE(330);
      END_STATE();
    case 267:
      if (lookahead == 'm') ADVANCE(163);
      END_STATE();
    case 268:
      if (lookahead == 'm') ADVANCE(143);
      END_STATE();
    case 269:
      if (lookahead == 'm') ADVANCE(145);
      END_STATE();
    case 270:
      if (lookahead == 'm') ADVANCE(73);
      END_STATE();
    case 271:
      if (lookahead == 'm') ADVANCE(171);
      END_STATE();
    case 272:
      if (lookahead == 'm') ADVANCE(174);
      END_STATE();
    case 273:
      if (lookahead == 'm') ADVANCE(82);
      END_STATE();
    case 274:
      if (lookahead == 'n') ADVANCE(417);
      END_STATE();
    case 275:
      if (lookahead == 'n') ADVANCE(23);
      if (lookahead == 'r') ADVANCE(206);
      if (lookahead == 'u') ADVANCE(383);
      if (lookahead == 'v') ADVANCE(155);
      END_STATE();
    case 276:
      if (lookahead == 'n') ADVANCE(194);
      END_STATE();
    case 277:
      if (lookahead == 'n') ADVANCE(755);
      END_STATE();
    case 278:
      if (lookahead == 'n') ADVANCE(793);
      END_STATE();
    case 279:
      if (lookahead == 'n') ADVANCE(868);
      END_STATE();
    case 280:
      if (lookahead == 'n') ADVANCE(811);
      END_STATE();
    case 281:
      if (lookahead == 'n') ADVANCE(871);
      END_STATE();
    case 282:
      if (lookahead == 'n') ADVANCE(866);
      END_STATE();
    case 283:
      if (lookahead == 'n') ADVANCE(299);
      END_STATE();
    case 284:
      if (lookahead == 'n') ADVANCE(920);
      END_STATE();
    case 285:
      if (lookahead == 'n') ADVANCE(862);
      END_STATE();
    case 286:
      if (lookahead == 'n') ADVANCE(202);
      END_STATE();
    case 287:
      if (lookahead == 'n') ADVANCE(94);
      END_STATE();
    case 288:
      if (lookahead == 'n') ADVANCE(188);
      END_STATE();
    case 289:
      if (lookahead == 'n') ADVANCE(105);
      END_STATE();
    case 290:
      if (lookahead == 'n') ADVANCE(178);
      END_STATE();
    case 291:
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 292:
      if (lookahead == 'n') ADVANCE(186);
      END_STATE();
    case 293:
      if (lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 294:
      if (lookahead == 'n') ADVANCE(22);
      if (lookahead == 'u') ADVANCE(383);
      if (lookahead == 'v') ADVANCE(155);
      END_STATE();
    case 295:
      if (lookahead == 'n') ADVANCE(413);
      END_STATE();
    case 296:
      if (lookahead == 'n') ADVANCE(421);
      END_STATE();
    case 297:
      if (lookahead == 'n') ADVANCE(403);
      END_STATE();
    case 298:
      if (lookahead == 'n') ADVANCE(391);
      END_STATE();
    case 299:
      if (lookahead == 'n') ADVANCE(170);
      if (lookahead == 't') ADVANCE(361);
      END_STATE();
    case 300:
      if (lookahead == 'n') ADVANCE(427);
      END_STATE();
    case 301:
      if (lookahead == 'n') ADVANCE(408);
      END_STATE();
    case 302:
      if (lookahead == 'n') ADVANCE(410);
      END_STATE();
    case 303:
      if (lookahead == 'n') ADVANCE(272);
      END_STATE();
    case 304:
      if (lookahead == 'n') ADVANCE(219);
      END_STATE();
    case 305:
      if (lookahead == 'n') ADVANCE(418);
      END_STATE();
    case 306:
      if (lookahead == 'n') ADVANCE(233);
      END_STATE();
    case 307:
      if (lookahead == 'o') ADVANCE(817);
      END_STATE();
    case 308:
      if (lookahead == 'o') ADVANCE(432);
      END_STATE();
    case 309:
      if (lookahead == 'o') ADVANCE(411);
      END_STATE();
    case 310:
      if (lookahead == 'o') ADVANCE(278);
      END_STATE();
    case 311:
      if (lookahead == 'o') ADVANCE(237);
      END_STATE();
    case 312:
      if (lookahead == 'o') ADVANCE(184);
      END_STATE();
    case 313:
      if (lookahead == 'o') ADVANCE(384);
      END_STATE();
    case 314:
      if (lookahead == 'o') ADVANCE(187);
      END_STATE();
    case 315:
      if (lookahead == 'o') ADVANCE(185);
      END_STATE();
    case 316:
      if (lookahead == 'o') ADVANCE(311);
      END_STATE();
    case 317:
      if (lookahead == 'o') ADVANCE(244);
      END_STATE();
    case 318:
      if (lookahead == 'o') ADVANCE(281);
      END_STATE();
    case 319:
      if (lookahead == 'o') ADVANCE(245);
      END_STATE();
    case 320:
      if (lookahead == 'o') ADVANCE(282);
      END_STATE();
    case 321:
      if (lookahead == 'o') ADVANCE(246);
      END_STATE();
    case 322:
      if (lookahead == 'o') ADVANCE(247);
      END_STATE();
    case 323:
      if (lookahead == 'o') ADVANCE(283);
      END_STATE();
    case 324:
      if (lookahead == 'o') ADVANCE(284);
      END_STATE();
    case 325:
      if (lookahead == 'o') ADVANCE(344);
      END_STATE();
    case 326:
      if (lookahead == 'o') ADVANCE(69);
      END_STATE();
    case 327:
      if (lookahead == 'o') ADVANCE(376);
      END_STATE();
    case 328:
      if (lookahead == 'o') ADVANCE(291);
      END_STATE();
    case 329:
      if (lookahead == 'o') ADVANCE(267);
      END_STATE();
    case 330:
      if (lookahead == 'o') ADVANCE(117);
      END_STATE();
    case 331:
      if (lookahead == 'o') ADVANCE(302);
      END_STATE();
    case 332:
      if (lookahead == 'o') ADVANCE(305);
      END_STATE();
    case 333:
      if (lookahead == 'p') ADVANCE(815);
      END_STATE();
    case 334:
      if (lookahead == 'p') ADVANCE(772);
      END_STATE();
    case 335:
      if (lookahead == 'p') ADVANCE(85);
      END_STATE();
    case 336:
      if (lookahead == 'p') ADVANCE(28);
      END_STATE();
    case 337:
      if (lookahead == 'p') ADVANCE(388);
      END_STATE();
    case 338:
      if (lookahead == 'p') ADVANCE(147);
      END_STATE();
    case 339:
      if (lookahead == 'r') ADVANCE(426);
      END_STATE();
    case 340:
      if (lookahead == 'r') ADVANCE(907);
      END_STATE();
    case 341:
      if (lookahead == 'r') ADVANCE(861);
      END_STATE();
    case 342:
      if (lookahead == 'r') ADVANCE(848);
      END_STATE();
    case 343:
      if (lookahead == 'r') ADVANCE(870);
      END_STATE();
    case 344:
      if (lookahead == 'r') ADVANCE(879);
      END_STATE();
    case 345:
      if (lookahead == 'r') ADVANCE(847);
      END_STATE();
    case 346:
      if (lookahead == 'r') ADVANCE(156);
      END_STATE();
    case 347:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 348:
      if (lookahead == 'r') ADVANCE(442);
      END_STATE();
    case 349:
      if (lookahead == 'r') ADVANCE(438);
      END_STATE();
    case 350:
      if (lookahead == 'r') ADVANCE(204);
      END_STATE();
    case 351:
      if (lookahead == 'r') ADVANCE(419);
      if (lookahead == 's') ADVANCE(227);
      END_STATE();
    case 352:
      if (lookahead == 'r') ADVANCE(367);
      END_STATE();
    case 353:
      if (lookahead == 'r') ADVANCE(205);
      END_STATE();
    case 354:
      if (lookahead == 'r') ADVANCE(280);
      END_STATE();
    case 355:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 356:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 357:
      if (lookahead == 'r') ADVANCE(317);
      END_STATE();
    case 358:
      if (lookahead == 'r') ADVANCE(319);
      END_STATE();
    case 359:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 360:
      if (lookahead == 'r') ADVANCE(321);
      END_STATE();
    case 361:
      if (lookahead == 'r') ADVANCE(322);
      END_STATE();
    case 362:
      if (lookahead == 'r') ADVANCE(74);
      END_STATE();
    case 363:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 364:
      if (lookahead == 'r') ADVANCE(168);
      END_STATE();
    case 365:
      if (lookahead == 'r') ADVANCE(164);
      END_STATE();
    case 366:
      if (lookahead == 'r') ADVANCE(118);
      END_STATE();
    case 367:
      if (lookahead == 'r') ADVANCE(172);
      END_STATE();
    case 368:
      if (lookahead == 'r') ADVANCE(443);
      END_STATE();
    case 369:
      if (lookahead == 'r') ADVANCE(78);
      END_STATE();
    case 370:
      if (lookahead == 's') ADVANCE(749);
      END_STATE();
    case 371:
      if (lookahead == 's') ADVANCE(830);
      END_STATE();
    case 372:
      if (lookahead == 's') ADVANCE(769);
      END_STATE();
    case 373:
      if (lookahead == 's') ADVANCE(310);
      END_STATE();
    case 374:
      if (lookahead == 's') ADVANCE(124);
      END_STATE();
    case 375:
      if (lookahead == 's') ADVANCE(227);
      END_STATE();
    case 376:
      if (lookahead == 's') ADVANCE(130);
      END_STATE();
    case 377:
      if (lookahead == 's') ADVANCE(132);
      END_STATE();
    case 378:
      if (lookahead == 's') ADVANCE(133);
      END_STATE();
    case 379:
      if (lookahead == 's') ADVANCE(134);
      END_STATE();
    case 380:
      if (lookahead == 's') ADVANCE(141);
      END_STATE();
    case 381:
      if (lookahead == 's') ADVANCE(166);
      END_STATE();
    case 382:
      if (lookahead == 's') ADVANCE(414);
      END_STATE();
    case 383:
      if (lookahead == 't') ADVANCE(864);
      END_STATE();
    case 384:
      if (lookahead == 't') ADVANCE(838);
      END_STATE();
    case 385:
      if (lookahead == 't') ADVANCE(843);
      END_STATE();
    case 386:
      if (lookahead == 't') ADVANCE(873);
      END_STATE();
    case 387:
      if (lookahead == 't') ADVANCE(823);
      END_STATE();
    case 388:
      if (lookahead == 't') ADVANCE(791);
      END_STATE();
    case 389:
      if (lookahead == 't') ADVANCE(776);
      END_STATE();
    case 390:
      if (lookahead == 't') ADVANCE(783);
      END_STATE();
    case 391:
      if (lookahead == 't') ADVANCE(784);
      END_STATE();
    case 392:
      if (lookahead == 't') ADVANCE(926);
      END_STATE();
    case 393:
      if (lookahead == 't') ADVANCE(785);
      END_STATE();
    case 394:
      if (lookahead == 't') ADVANCE(928);
      END_STATE();
    case 395:
      if (lookahead == 't') ADVANCE(192);
      END_STATE();
    case 396:
      if (lookahead == 't') ADVANCE(192);
      if (lookahead == 'u') ADVANCE(379);
      END_STATE();
    case 397:
      if (lookahead == 't') ADVANCE(437);
      END_STATE();
    case 398:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 399:
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 400:
      if (lookahead == 't') ADVANCE(193);
      END_STATE();
    case 401:
      if (lookahead == 't') ADVANCE(307);
      END_STATE();
    case 402:
      if (lookahead == 't') ADVANCE(441);
      END_STATE();
    case 403:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 404:
      if (lookahead == 't') ADVANCE(439);
      END_STATE();
    case 405:
      if (lookahead == 't') ADVANCE(325);
      END_STATE();
    case 406:
      if (lookahead == 't') ADVANCE(221);
      END_STATE();
    case 407:
      if (lookahead == 't') ADVANCE(349);
      END_STATE();
    case 408:
      if (lookahead == 't') ADVANCE(357);
      END_STATE();
    case 409:
      if (lookahead == 't') ADVANCE(225);
      END_STATE();
    case 410:
      if (lookahead == 't') ADVANCE(358);
      END_STATE();
    case 411:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 412:
      if (lookahead == 't') ADVANCE(213);
      END_STATE();
    case 413:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 414:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 415:
      if (lookahead == 't') ADVANCE(137);
      END_STATE();
    case 416:
      if (lookahead == 't') ADVANCE(144);
      END_STATE();
    case 417:
      if (lookahead == 't') ADVANCE(212);
      END_STATE();
    case 418:
      if (lookahead == 't') ADVANCE(360);
      END_STATE();
    case 419:
      if (lookahead == 't') ADVANCE(362);
      END_STATE();
    case 420:
      if (lookahead == 't') ADVANCE(230);
      END_STATE();
    case 421:
      if (lookahead == 't') ADVANCE(173);
      END_STATE();
    case 422:
      if (lookahead == 't') ADVANCE(231);
      END_STATE();
    case 423:
      if (lookahead == 'u') ADVANCE(183);
      END_STATE();
    case 424:
      if (lookahead == 'u') ADVANCE(258);
      END_STATE();
    case 425:
      if (lookahead == 'u') ADVANCE(354);
      END_STATE();
    case 426:
      if (lookahead == 'u') ADVANCE(129);
      END_STATE();
    case 427:
      if (lookahead == 'u') ADVANCE(142);
      END_STATE();
    case 428:
      if (lookahead == 'u') ADVANCE(116);
      END_STATE();
    case 429:
      if (lookahead == 'u') ADVANCE(380);
      END_STATE();
    case 430:
      if (lookahead == 'v') ADVANCE(128);
      END_STATE();
    case 431:
      if (lookahead == 'v') ADVANCE(162);
      END_STATE();
    case 432:
      if (lookahead == 'w') ADVANCE(755);
      END_STATE();
    case 433:
      if (lookahead == 'w') ADVANCE(821);
      END_STATE();
    case 434:
      if (lookahead == 'x') ADVANCE(24);
      END_STATE();
    case 435:
      if (lookahead == 'x') ADVANCE(751);
      END_STATE();
    case 436:
      if (lookahead == 'x') ADVANCE(819);
      END_STATE();
    case 437:
      if (lookahead == 'y') ADVANCE(779);
      END_STATE();
    case 438:
      if (lookahead == 'y') ADVANCE(867);
      END_STATE();
    case 439:
      if (lookahead == 'y') ADVANCE(796);
      END_STATE();
    case 440:
      if (lookahead == 'y') ADVANCE(56);
      END_STATE();
    case 441:
      if (lookahead == 'y') ADVANCE(338);
      END_STATE();
    case 442:
      if (lookahead == 'y') ADVANCE(29);
      END_STATE();
    case 443:
      if (lookahead == 'y') ADVANCE(30);
      END_STATE();
    case 444:
      if (lookahead == 'y') ADVANCE(160);
      END_STATE();
    case 445:
      if (lookahead == 'y') ADVANCE(165);
      END_STATE();
    case 446:
      if (lookahead == '|') ADVANCE(892);
      END_STATE();
    case 447:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(449);
      END_STATE();
    case 448:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(758);
      END_STATE();
    case 449:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(448);
      END_STATE();
    case 450:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(759);
      END_STATE();
    case 451:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 452:
      if (eof) ADVANCE(453);
      ADVANCE_MAP(
        '!', 17,
        '$', 450,
        '%', 911,
        '&', 13,
        ')', 806,
        '*', 909,
        '+', 829,
        ',', 459,
        '-', 912,
        '/', 910,
        ';', 762,
        '<', 894,
        '=', 18,
        '>', 788,
        '[', 458,
        ']', 460,
        'a', 529,
        'd', 589,
        'i', 643,
        's', 508,
        '|', 446,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(452);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(752);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(455);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(455);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(536);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'N') ADVANCE(496);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(511);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(513);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(639);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(535);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(707);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(514);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(609);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(637);
      if (lookahead == 'l') ADVANCE(665);
      if (lookahead == 'o') ADVANCE(635);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(637);
      if (lookahead == 'l') ADVANCE(665);
      if (lookahead == 'o') ADVANCE(636);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(637);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(737);
      if (lookahead == 'e') ADVANCE(618);
      if (lookahead == 'h') ADVANCE(661);
      if (lookahead == 'p') ADVANCE(701);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(737);
      if (lookahead == 'e') ADVANCE(618);
      if (lookahead == 'h') ADVANCE(661);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(595);
      if (lookahead == 'h') ADVANCE(594);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(743);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(858);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(735);
      if (lookahead == 'l') ADVANCE(476);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(682);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(608);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(652);
      if (lookahead == 'e') ADVANCE(719);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(611);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(703);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(581);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(684);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(523);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(512);
      if (lookahead == 'u') ADVANCE(536);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(630);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(584);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(525);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(642);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(715);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(693);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(633);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(640);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(706);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(653);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(726);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(641);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(628);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(744);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(736);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(632);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(731);
      if (lookahead == 'l') ADVANCE(559);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(676);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(569);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(690);
      if (lookahead == 'e') ADVANCE(702);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(607);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(610);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(624);
      if (lookahead == 'd') ADVANCE(605);
      if (lookahead == 'e') ADVANCE(531);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(679);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(671);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(493);
      if (lookahead == 't') ADVANCE(593);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(493);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(716);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(536);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(680);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(766);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(537);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(814);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(808);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(810);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(828);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(886);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(521);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(540);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(600);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(547);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(552);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(555);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(604);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(761);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(505);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(741);
      if (lookahead == 'i') ADVANCE(530);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(833);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(837);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(846);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(840);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(854);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(906);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(826);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(835);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(856);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 549:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(904);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 550:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(890);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 551:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(931);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 552:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(882);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 553:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 554:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(782);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 555:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(740);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 556:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(517);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 557:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(719);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 558:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(694);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(723);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(687);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(642);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(648);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(520);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(528);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(689);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 567:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(631);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 568:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(619);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(617);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 570:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(562);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 571:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(491);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 572:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(623);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 573:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(656);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 574:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(899);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 575:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(852);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 576:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 577:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(576);
      if (lookahead == 'n') ADVANCE(456);
      if (lookahead == 'p') ADVANCE(563);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 578:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(775);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 579:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(768);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 580:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(586);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 581:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(461);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 582:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(802);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 583:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 584:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(573);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 585:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(601);
      if (lookahead == 'p') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 586:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(714);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 587:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(692);
      if (lookahead == 'r') ADVANCE(734);
      if (lookahead == 'w') ADVANCE(597);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 588:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(603);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 589:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 590:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(681);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 591:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(580);
      if (lookahead == 'o') ADVANCE(487);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 592:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(683);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 593:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(651);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 594:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(625);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 595:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(713);
      if (lookahead == 'r') ADVANCE(685);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 596:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 597:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(518);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 598:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(717);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 599:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(483);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 600:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(722);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 601:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(532);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 602:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(489);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 603:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(727);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 604:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(501);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 605:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(504);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 606:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 607:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(842);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 608:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(902);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 609:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(660);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 610:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(730);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 611:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(465);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 612:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(884);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 613:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(878);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 614:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(876);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 615:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(888);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 616:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(488);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 617:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(778);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 618:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(575);
      if (lookahead == 'r') ADVANCE(602);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 619:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(575);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 620:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(663);
      if (lookahead == 'r') ADVANCE(561);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 621:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(663);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 622:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(485);
      if (lookahead == 'o') ADVANCE(686);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 623:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(559);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 624:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(592);
      if (lookahead == 'o') ADVANCE(654);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 625:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(545);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 626:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(666);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 627:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(596);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 628:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(664);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 629:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(678);
      if (lookahead == 'y') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 630:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 631:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(626);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 632:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(669);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 633:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(710);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 634:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(502);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 635:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(638);
      if (lookahead == 'n') ADVANCE(515);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 636:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(638);
      if (lookahead == 'n') ADVANCE(516);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 637:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(558);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 638:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(498);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 639:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(677);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 640:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(550);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 641:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(554);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 642:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 643:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(510);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 644:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(585);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 645:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(794);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 646:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(812);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 647:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(655);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 648:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 649:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(718);
      if (lookahead == 'r') ADVANCE(497);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 650:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(718);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 651:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(733);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 652:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(524);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 653:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(526);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 654:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(721);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 655:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(556);
      if (lookahead == 't') ADVANCE(698);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 656:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(725);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 657:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(728);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 658:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(729);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 659:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(534);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 660:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(578);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 661:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(739);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 662:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(818);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 663:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 664:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(579);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 665:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(705);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 666:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(738);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 667:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(720);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 668:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(645);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 669:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(583);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 670:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(612);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 671:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(647);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 672:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(613);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 673:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(688);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 674:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(614);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 675:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(615);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 676:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 677:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(533);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 678:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(711);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 679:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(657);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 680:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(658);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 681:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(712);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 682:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(816);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 683:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(506);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 684:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(773);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 685:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 686:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(908);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 687:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(849);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 688:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(880);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 689:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(850);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 690:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(590);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 691:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(646);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 692:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(597);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 693:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(527);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 694:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 695:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(670);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 696:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(672);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 697:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(674);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 698:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(675);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 699:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(570);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 700:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(486);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 701:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(571);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 702:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(599);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 703:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(831);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 704:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(668);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 705:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(542);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 706:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(543);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 707:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(724);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 708:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(544);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 709:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(548);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 710:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(553);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 711:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(565);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 712:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(792);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 713:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(844);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 714:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(874);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 715:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(824);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 716:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(929);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 717:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(742);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 718:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(598);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 719:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(732);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 720:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(662);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 721:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(695);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 722:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(673);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 723:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(546);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 724:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 725:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 726:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(551);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 727:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(536);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 728:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(696);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 729:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(697);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 730:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(522);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 731:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(582);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 732:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(691);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 733:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(549);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 734:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(553);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 735:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(708);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 736:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(709);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 737:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(541);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 738:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(745);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 739:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(822);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 740:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(820);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 741:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(462);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 742:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(780);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 743:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(560);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 744:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(566);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 745:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 746:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 747:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(370);
      if (lookahead == 'p') ADVANCE(203);
      if (lookahead == 's') ADVANCE(749);
      if (lookahead == 'x') ADVANCE(753);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(747);
      END_STATE();
    case 748:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(748);
      END_STATE();
    case 749:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 750:
      ACCEPT_TOKEN(sym_DURATION);
      if (lookahead == 'm') ADVANCE(370);
      if (lookahead == 's') ADVANCE(749);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(750);
      END_STATE();
    case 751:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 752:
      ACCEPT_TOKEN(sym_DISTANCE);
      if (lookahead == 'p') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(752);
      END_STATE();
    case 753:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 754:
      ACCEPT_TOKEN(sym_QUANTITY);
      if (lookahead == 'x') ADVANCE(753);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(754);
      END_STATE();
    case 755:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 756:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(755);
      END_STATE();
    case 757:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(756);
      END_STATE();
    case 758:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(757);
      END_STATE();
    case 759:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(759);
      END_STATE();
    case 760:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 761:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 762:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 763:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 764:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(896);
      END_STATE();
    case 765:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 766:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 767:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 768:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 769:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 770:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 771:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 772:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 773:
      ACCEPT_TOKEN(anon_sym_wrap);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 774:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 775:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 776:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 777:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 778:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 779:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 780:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 781:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 782:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 783:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 784:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 785:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 786:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 787:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 788:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(893);
      END_STATE();
    case 789:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 790:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(449);
      END_STATE();
    case 791:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 792:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 793:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 794:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 795:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 796:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 797:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(797);
      END_STATE();
    case 798:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 799:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 800:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 801:
      ACCEPT_TOKEN(anon_sym_debug);
      END_STATE();
    case 802:
      ACCEPT_TOKEN(anon_sym_debug);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 803:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 804:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(897);
      END_STATE();
    case 805:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 806:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 807:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 808:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 809:
      ACCEPT_TOKEN(anon_sym_spread);
      END_STATE();
    case 810:
      ACCEPT_TOKEN(anon_sym_spread);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 811:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 812:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 813:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 814:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 815:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 816:
      ACCEPT_TOKEN(anon_sym_map);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 817:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 818:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 819:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 820:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 821:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 822:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 823:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 824:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 825:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 826:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 827:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 828:
      ACCEPT_TOKEN(anon_sym_command);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 829:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 830:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 831:
      ACCEPT_TOKEN(anon_sym_alias);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 832:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 833:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 834:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 835:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 836:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 837:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 838:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 839:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 840:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 841:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 842:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 843:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 844:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 845:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 846:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 847:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 848:
      ACCEPT_TOKEN(sym_player);
      if (lookahead == '_') ADVANCE(99);
      END_STATE();
    case 849:
      ACCEPT_TOKEN(sym_player);
      if (lookahead == '_') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 850:
      ACCEPT_TOKEN(sym_player);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 851:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 852:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 853:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 854:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 855:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 856:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 857:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 858:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 859:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 860:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 861:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 862:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 863:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(251);
      if (lookahead == 'd') ADVANCE(151);
      END_STATE();
    case 864:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 865:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    case 866:
      ACCEPT_TOKEN(anon_sym_animation);
      if (lookahead == '_') ADVANCE(180);
      END_STATE();
    case 867:
      ACCEPT_TOKEN(anon_sym_geometry);
      END_STATE();
    case 868:
      ACCEPT_TOKEN(sym_origin);
      END_STATE();
    case 869:
      ACCEPT_TOKEN(sym_length);
      END_STATE();
    case 870:
      ACCEPT_TOKEN(sym_forever);
      END_STATE();
    case 871:
      ACCEPT_TOKEN(anon_sym_position);
      END_STATE();
    case 872:
      ACCEPT_TOKEN(sym_glitched);
      END_STATE();
    case 873:
      ACCEPT_TOKEN(anon_sym_light);
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 874:
      ACCEPT_TOKEN(anon_sym_light);
      if (lookahead == 's') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 875:
      ACCEPT_TOKEN(anon_sym_player_control);
      END_STATE();
    case 876:
      ACCEPT_TOKEN(anon_sym_player_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 877:
      ACCEPT_TOKEN(anon_sym_lights_control);
      END_STATE();
    case 878:
      ACCEPT_TOKEN(anon_sym_lights_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 879:
      ACCEPT_TOKEN(anon_sym_hex_editor);
      END_STATE();
    case 880:
      ACCEPT_TOKEN(anon_sym_hex_editor);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 881:
      ACCEPT_TOKEN(anon_sym_hex_dialog_mode);
      END_STATE();
    case 882:
      ACCEPT_TOKEN(anon_sym_hex_dialog_mode);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 883:
      ACCEPT_TOKEN(anon_sym_hex_control);
      END_STATE();
    case 884:
      ACCEPT_TOKEN(anon_sym_hex_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 885:
      ACCEPT_TOKEN(anon_sym_hex_clipboard);
      END_STATE();
    case 886:
      ACCEPT_TOKEN(anon_sym_hex_clipboard);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 887:
      ACCEPT_TOKEN(anon_sym_serial_control);
      END_STATE();
    case 888:
      ACCEPT_TOKEN(anon_sym_serial_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 889:
      ACCEPT_TOKEN(anon_sym_flagName);
      END_STATE();
    case 890:
      ACCEPT_TOKEN(anon_sym_flagName);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 891:
      ACCEPT_TOKEN(sym_AND);
      END_STATE();
    case 892:
      ACCEPT_TOKEN(sym_OR);
      END_STATE();
    case 893:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 894:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(895);
      END_STATE();
    case 895:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 896:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 897:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 898:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 899:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 900:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 901:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 902:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 903:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 904:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 905:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 906:
      ACCEPT_TOKEN(anon_sym_while);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 907:
      ACCEPT_TOKEN(anon_sym_for);
      if (lookahead == 'e') ADVANCE(431);
      END_STATE();
    case 908:
      ACCEPT_TOKEN(anon_sym_for);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 909:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 910:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '/') ADVANCE(455);
      END_STATE();
    case 911:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 912:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 913:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(860);
      END_STATE();
    case 914:
      ACCEPT_TOKEN(anon_sym_x);
      END_STATE();
    case 915:
      ACCEPT_TOKEN(anon_sym_y);
      END_STATE();
    case 916:
      ACCEPT_TOKEN(anon_sym_y);
      if (lookahead == 'e') ADVANCE(261);
      END_STATE();
    case 917:
      ACCEPT_TOKEN(anon_sym_primary_id);
      if (lookahead == '_') ADVANCE(402);
      END_STATE();
    case 918:
      ACCEPT_TOKEN(anon_sym_secondary_id);
      END_STATE();
    case 919:
      ACCEPT_TOKEN(anon_sym_primary_id_type);
      END_STATE();
    case 920:
      ACCEPT_TOKEN(anon_sym_current_animation);
      END_STATE();
    case 921:
      ACCEPT_TOKEN(anon_sym_animation_frame);
      END_STATE();
    case 922:
      ACCEPT_TOKEN(anon_sym_strafe);
      END_STATE();
    case 923:
      ACCEPT_TOKEN(anon_sym_path);
      END_STATE();
    case 924:
      ACCEPT_TOKEN(anon_sym_on_tick);
      END_STATE();
    case 925:
      ACCEPT_TOKEN(anon_sym_on_look);
      END_STATE();
    case 926:
      ACCEPT_TOKEN(anon_sym_on_interact);
      END_STATE();
    case 927:
      ACCEPT_TOKEN(sym_fail);
      END_STATE();
    case 928:
      ACCEPT_TOKEN(anon_sym_serial_connect);
      END_STATE();
    case 929:
      ACCEPT_TOKEN(anon_sym_serial_connect);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    case 930:
      ACCEPT_TOKEN(anon_sym_warp_state);
      END_STATE();
    case 931:
      ACCEPT_TOKEN(anon_sym_warp_state);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(745);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 452},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 10},
  [6] = {.lex_state = 10},
  [7] = {.lex_state = 10},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 10},
  [10] = {.lex_state = 10},
  [11] = {.lex_state = 10},
  [12] = {.lex_state = 10},
  [13] = {.lex_state = 10},
  [14] = {.lex_state = 10},
  [15] = {.lex_state = 10},
  [16] = {.lex_state = 10},
  [17] = {.lex_state = 10},
  [18] = {.lex_state = 11},
  [19] = {.lex_state = 11},
  [20] = {.lex_state = 10},
  [21] = {.lex_state = 10},
  [22] = {.lex_state = 10},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 10},
  [38] = {.lex_state = 10},
  [39] = {.lex_state = 10},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 10},
  [42] = {.lex_state = 10},
  [43] = {.lex_state = 10},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 10},
  [46] = {.lex_state = 10},
  [47] = {.lex_state = 6},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 452},
  [50] = {.lex_state = 452},
  [51] = {.lex_state = 6},
  [52] = {.lex_state = 452},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 452},
  [55] = {.lex_state = 452},
  [56] = {.lex_state = 452},
  [57] = {.lex_state = 452},
  [58] = {.lex_state = 6},
  [59] = {.lex_state = 452},
  [60] = {.lex_state = 452},
  [61] = {.lex_state = 6},
  [62] = {.lex_state = 452},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 452},
  [65] = {.lex_state = 452},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 452},
  [68] = {.lex_state = 452},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 452},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 452},
  [73] = {.lex_state = 6},
  [74] = {.lex_state = 452},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 452},
  [78] = {.lex_state = 452},
  [79] = {.lex_state = 452},
  [80] = {.lex_state = 6},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 6},
  [83] = {.lex_state = 6},
  [84] = {.lex_state = 6},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 6},
  [88] = {.lex_state = 6},
  [89] = {.lex_state = 6},
  [90] = {.lex_state = 6},
  [91] = {.lex_state = 6},
  [92] = {.lex_state = 452},
  [93] = {.lex_state = 6},
  [94] = {.lex_state = 452},
  [95] = {.lex_state = 452},
  [96] = {.lex_state = 452},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 6},
  [99] = {.lex_state = 6},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 6},
  [102] = {.lex_state = 452},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 452},
  [105] = {.lex_state = 452},
  [106] = {.lex_state = 452},
  [107] = {.lex_state = 452},
  [108] = {.lex_state = 452},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 452},
  [118] = {.lex_state = 7},
  [119] = {.lex_state = 452},
  [120] = {.lex_state = 452},
  [121] = {.lex_state = 452},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 452},
  [124] = {.lex_state = 452},
  [125] = {.lex_state = 452},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 452},
  [128] = {.lex_state = 1},
  [129] = {.lex_state = 1},
  [130] = {.lex_state = 4},
  [131] = {.lex_state = 1},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 1},
  [134] = {.lex_state = 1},
  [135] = {.lex_state = 1},
  [136] = {.lex_state = 3},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 3},
  [139] = {.lex_state = 1},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 1},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 1},
  [145] = {.lex_state = 12},
  [146] = {.lex_state = 452},
  [147] = {.lex_state = 1},
  [148] = {.lex_state = 3},
  [149] = {.lex_state = 3},
  [150] = {.lex_state = 6},
  [151] = {.lex_state = 3},
  [152] = {.lex_state = 452},
  [153] = {.lex_state = 452},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 452},
  [157] = {.lex_state = 452},
  [158] = {.lex_state = 452},
  [159] = {.lex_state = 6},
  [160] = {.lex_state = 452},
  [161] = {.lex_state = 452},
  [162] = {.lex_state = 452},
  [163] = {.lex_state = 7},
  [164] = {.lex_state = 7},
  [165] = {.lex_state = 7},
  [166] = {.lex_state = 7},
  [167] = {.lex_state = 6},
  [168] = {.lex_state = 452},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 5},
  [171] = {.lex_state = 6},
  [172] = {.lex_state = 452},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 7},
  [175] = {.lex_state = 7},
  [176] = {.lex_state = 7},
  [177] = {.lex_state = 452},
  [178] = {.lex_state = 6},
  [179] = {.lex_state = 6},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 6},
  [182] = {.lex_state = 6},
  [183] = {.lex_state = 6},
  [184] = {.lex_state = 6},
  [185] = {.lex_state = 6},
  [186] = {.lex_state = 7},
  [187] = {.lex_state = 6},
  [188] = {.lex_state = 6},
  [189] = {.lex_state = 6},
  [190] = {.lex_state = 6},
  [191] = {.lex_state = 6},
  [192] = {.lex_state = 6},
  [193] = {.lex_state = 6},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 6},
  [196] = {.lex_state = 1},
  [197] = {.lex_state = 6},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 6},
  [200] = {.lex_state = 6},
  [201] = {.lex_state = 6},
  [202] = {.lex_state = 3},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 3},
  [205] = {.lex_state = 9},
  [206] = {.lex_state = 1},
  [207] = {.lex_state = 6},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 1},
  [211] = {.lex_state = 9},
  [212] = {.lex_state = 6},
  [213] = {.lex_state = 6},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 6},
  [216] = {.lex_state = 6},
  [217] = {.lex_state = 6},
  [218] = {.lex_state = 3},
  [219] = {.lex_state = 3},
  [220] = {.lex_state = 6},
  [221] = {.lex_state = 3},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 3},
  [224] = {.lex_state = 3},
  [225] = {.lex_state = 3},
  [226] = {.lex_state = 9},
  [227] = {.lex_state = 6},
  [228] = {.lex_state = 6},
  [229] = {.lex_state = 6},
  [230] = {.lex_state = 6},
  [231] = {.lex_state = 6},
  [232] = {.lex_state = 6},
  [233] = {.lex_state = 9},
  [234] = {.lex_state = 6},
  [235] = {.lex_state = 6},
  [236] = {.lex_state = 6},
  [237] = {.lex_state = 6},
  [238] = {.lex_state = 6},
  [239] = {.lex_state = 6},
  [240] = {.lex_state = 6},
  [241] = {.lex_state = 7},
  [242] = {.lex_state = 6},
  [243] = {.lex_state = 6},
  [244] = {.lex_state = 6},
  [245] = {.lex_state = 6},
  [246] = {.lex_state = 6},
  [247] = {.lex_state = 6},
  [248] = {.lex_state = 6},
  [249] = {.lex_state = 6},
  [250] = {.lex_state = 6},
  [251] = {.lex_state = 3},
  [252] = {.lex_state = 3},
  [253] = {.lex_state = 3},
  [254] = {.lex_state = 3},
  [255] = {.lex_state = 3},
  [256] = {.lex_state = 3},
  [257] = {.lex_state = 3},
  [258] = {.lex_state = 3},
  [259] = {.lex_state = 6},
  [260] = {.lex_state = 3},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 6},
  [263] = {.lex_state = 2},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 2},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 3},
  [269] = {.lex_state = 10},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 6},
  [272] = {.lex_state = 6},
  [273] = {.lex_state = 10},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 6},
  [276] = {.lex_state = 9},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 6},
  [279] = {.lex_state = 6},
  [280] = {.lex_state = 10},
  [281] = {.lex_state = 6},
  [282] = {.lex_state = 3},
  [283] = {.lex_state = 452},
  [284] = {.lex_state = 3},
  [285] = {.lex_state = 3},
  [286] = {.lex_state = 3},
  [287] = {.lex_state = 6},
  [288] = {.lex_state = 10},
  [289] = {.lex_state = 10},
  [290] = {.lex_state = 2},
  [291] = {.lex_state = 3},
  [292] = {.lex_state = 0},
  [293] = {.lex_state = 3},
  [294] = {.lex_state = 10},
  [295] = {.lex_state = 10},
  [296] = {.lex_state = 1},
  [297] = {.lex_state = 1},
  [298] = {.lex_state = 1},
  [299] = {.lex_state = 3},
  [300] = {.lex_state = 3},
  [301] = {.lex_state = 3},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 6},
  [304] = {.lex_state = 10},
  [305] = {.lex_state = 6},
  [306] = {.lex_state = 9},
  [307] = {.lex_state = 10},
  [308] = {.lex_state = 10},
  [309] = {.lex_state = 3},
  [310] = {.lex_state = 3},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 6},
  [313] = {.lex_state = 0},
  [314] = {.lex_state = 10},
  [315] = {.lex_state = 6},
  [316] = {.lex_state = 3},
  [317] = {.lex_state = 3},
  [318] = {.lex_state = 6},
  [319] = {.lex_state = 10},
  [320] = {.lex_state = 3},
  [321] = {.lex_state = 10},
  [322] = {.lex_state = 10},
  [323] = {.lex_state = 6},
  [324] = {.lex_state = 6},
  [325] = {.lex_state = 6},
  [326] = {.lex_state = 10},
  [327] = {.lex_state = 6},
  [328] = {.lex_state = 3},
  [329] = {.lex_state = 0},
  [330] = {.lex_state = 3},
  [331] = {.lex_state = 9},
  [332] = {.lex_state = 6},
  [333] = {.lex_state = 3},
  [334] = {.lex_state = 3},
  [335] = {.lex_state = 3},
  [336] = {.lex_state = 3},
  [337] = {.lex_state = 1},
  [338] = {.lex_state = 6},
  [339] = {.lex_state = 10},
  [340] = {.lex_state = 1},
  [341] = {.lex_state = 1},
  [342] = {.lex_state = 2},
  [343] = {.lex_state = 1},
  [344] = {.lex_state = 2},
  [345] = {.lex_state = 3},
  [346] = {.lex_state = 3},
  [347] = {.lex_state = 3},
  [348] = {.lex_state = 0},
  [349] = {.lex_state = 6},
  [350] = {.lex_state = 0},
  [351] = {.lex_state = 2},
  [352] = {.lex_state = 6},
  [353] = {.lex_state = 6},
  [354] = {.lex_state = 10},
  [355] = {.lex_state = 10},
  [356] = {.lex_state = 2},
  [357] = {.lex_state = 2},
  [358] = {.lex_state = 0},
  [359] = {.lex_state = 10},
  [360] = {.lex_state = 0},
  [361] = {.lex_state = 0},
  [362] = {.lex_state = 0},
  [363] = {.lex_state = 3},
  [364] = {.lex_state = 3},
  [365] = {.lex_state = 3},
  [366] = {.lex_state = 3},
  [367] = {.lex_state = 3},
  [368] = {.lex_state = 0},
  [369] = {.lex_state = 0},
  [370] = {.lex_state = 0},
  [371] = {.lex_state = 3},
  [372] = {.lex_state = 2},
  [373] = {.lex_state = 0},
  [374] = {.lex_state = 0},
  [375] = {.lex_state = 0},
  [376] = {.lex_state = 0},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 3},
  [379] = {.lex_state = 3},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 6},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 0},
  [385] = {.lex_state = 0},
  [386] = {.lex_state = 0},
  [387] = {.lex_state = 0},
  [388] = {.lex_state = 0},
  [389] = {.lex_state = 0},
  [390] = {.lex_state = 3},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 0},
  [393] = {.lex_state = 0},
  [394] = {.lex_state = 0},
  [395] = {.lex_state = 2},
  [396] = {.lex_state = 0},
  [397] = {.lex_state = 3},
  [398] = {.lex_state = 0},
  [399] = {.lex_state = 2},
  [400] = {.lex_state = 0},
  [401] = {.lex_state = 0},
  [402] = {.lex_state = 6},
  [403] = {.lex_state = 0},
  [404] = {.lex_state = 3},
  [405] = {.lex_state = 3},
  [406] = {.lex_state = 0},
  [407] = {.lex_state = 3},
  [408] = {.lex_state = 3},
  [409] = {.lex_state = 0},
  [410] = {.lex_state = 0},
  [411] = {.lex_state = 0},
  [412] = {.lex_state = 3},
  [413] = {.lex_state = 0},
  [414] = {.lex_state = 2},
  [415] = {.lex_state = 0},
  [416] = {.lex_state = 0},
  [417] = {.lex_state = 10},
  [418] = {.lex_state = 0},
  [419] = {.lex_state = 0},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 2},
  [422] = {.lex_state = 0},
  [423] = {.lex_state = 9},
  [424] = {.lex_state = 0},
  [425] = {.lex_state = 0},
  [426] = {.lex_state = 6},
  [427] = {.lex_state = 3},
  [428] = {.lex_state = 0},
  [429] = {.lex_state = 0},
  [430] = {.lex_state = 9},
  [431] = {.lex_state = 452},
  [432] = {.lex_state = 0},
  [433] = {.lex_state = 3},
  [434] = {.lex_state = 0},
  [435] = {.lex_state = 0},
  [436] = {.lex_state = 3},
  [437] = {.lex_state = 3},
  [438] = {.lex_state = 0},
  [439] = {.lex_state = 0},
  [440] = {.lex_state = 3},
  [441] = {.lex_state = 0},
  [442] = {.lex_state = 0},
  [443] = {.lex_state = 0},
  [444] = {.lex_state = 10},
  [445] = {.lex_state = 0},
  [446] = {.lex_state = 0},
  [447] = {.lex_state = 3},
  [448] = {.lex_state = 2},
  [449] = {.lex_state = 0},
  [450] = {.lex_state = 2},
  [451] = {.lex_state = 0},
  [452] = {.lex_state = 0},
  [453] = {.lex_state = 0},
  [454] = {.lex_state = 0},
  [455] = {.lex_state = 2},
  [456] = {.lex_state = 0},
  [457] = {.lex_state = 3},
  [458] = {.lex_state = 0},
  [459] = {.lex_state = 0},
  [460] = {.lex_state = 0},
  [461] = {.lex_state = 0},
  [462] = {.lex_state = 3},
  [463] = {.lex_state = 0},
  [464] = {.lex_state = 0},
  [465] = {.lex_state = 3},
  [466] = {.lex_state = 0},
  [467] = {.lex_state = 3},
  [468] = {.lex_state = 0},
  [469] = {.lex_state = 0},
  [470] = {.lex_state = 0},
  [471] = {.lex_state = 0},
  [472] = {.lex_state = 0},
  [473] = {.lex_state = 6},
  [474] = {.lex_state = 0},
  [475] = {.lex_state = 0},
  [476] = {.lex_state = 0},
  [477] = {.lex_state = 3},
  [478] = {.lex_state = 3},
  [479] = {.lex_state = 6},
  [480] = {.lex_state = 3},
  [481] = {.lex_state = 3},
  [482] = {.lex_state = 3},
  [483] = {.lex_state = 3},
  [484] = {.lex_state = 9},
  [485] = {.lex_state = 0},
  [486] = {.lex_state = 6},
  [487] = {.lex_state = 9},
  [488] = {.lex_state = 0},
  [489] = {.lex_state = 452},
  [490] = {.lex_state = 0},
  [491] = {.lex_state = 2},
  [492] = {.lex_state = 3},
  [493] = {.lex_state = 0},
  [494] = {.lex_state = 0},
  [495] = {.lex_state = 3},
  [496] = {.lex_state = 3},
  [497] = {.lex_state = 0},
  [498] = {.lex_state = 0},
  [499] = {.lex_state = 0},
  [500] = {.lex_state = 0},
  [501] = {.lex_state = 6},
  [502] = {.lex_state = 0},
  [503] = {.lex_state = 6},
  [504] = {.lex_state = 0},
  [505] = {.lex_state = 1},
  [506] = {.lex_state = 0},
  [507] = {.lex_state = 3},
  [508] = {.lex_state = 3},
  [509] = {.lex_state = 0},
  [510] = {.lex_state = 9},
  [511] = {.lex_state = 0},
  [512] = {.lex_state = 9},
  [513] = {.lex_state = 0},
  [514] = {.lex_state = 452},
  [515] = {.lex_state = 0},
  [516] = {.lex_state = 0},
  [517] = {.lex_state = 0},
  [518] = {.lex_state = 0},
  [519] = {.lex_state = 3},
  [520] = {.lex_state = 6},
  [521] = {.lex_state = 0},
  [522] = {.lex_state = 0},
  [523] = {.lex_state = 0},
  [524] = {.lex_state = 0},
  [525] = {.lex_state = 0},
  [526] = {.lex_state = 0},
  [527] = {.lex_state = 0},
  [528] = {.lex_state = 0},
  [529] = {.lex_state = 0},
  [530] = {.lex_state = 0},
  [531] = {.lex_state = 0},
  [532] = {.lex_state = 0},
  [533] = {.lex_state = 0},
  [534] = {.lex_state = 3},
  [535] = {.lex_state = 0},
  [536] = {.lex_state = 0},
  [537] = {.lex_state = 0},
  [538] = {.lex_state = 0},
  [539] = {.lex_state = 0},
  [540] = {.lex_state = 0},
  [541] = {.lex_state = 0},
  [542] = {.lex_state = 0},
  [543] = {.lex_state = 0},
  [544] = {.lex_state = 3},
  [545] = {.lex_state = 0},
  [546] = {.lex_state = 0},
  [547] = {.lex_state = 0},
  [548] = {.lex_state = 0},
  [549] = {.lex_state = 0},
  [550] = {.lex_state = 0},
  [551] = {.lex_state = 0},
  [552] = {.lex_state = 0},
  [553] = {.lex_state = 0},
  [554] = {.lex_state = 0},
  [555] = {.lex_state = 0},
  [556] = {.lex_state = 0},
  [557] = {.lex_state = 0},
  [558] = {.lex_state = 0},
  [559] = {.lex_state = 0},
  [560] = {.lex_state = 0},
  [561] = {.lex_state = 0},
  [562] = {.lex_state = 0},
  [563] = {.lex_state = 0},
  [564] = {.lex_state = 0},
  [565] = {.lex_state = 0},
  [566] = {.lex_state = 0},
  [567] = {.lex_state = 0},
  [568] = {.lex_state = 0},
  [569] = {.lex_state = 0},
  [570] = {.lex_state = 0},
  [571] = {.lex_state = 0},
  [572] = {.lex_state = 0},
  [573] = {.lex_state = 0},
  [574] = {.lex_state = 0},
  [575] = {.lex_state = 2},
  [576] = {.lex_state = 0},
  [577] = {.lex_state = 2},
  [578] = {.lex_state = 2},
  [579] = {.lex_state = 0},
  [580] = {.lex_state = 0},
  [581] = {.lex_state = 0},
  [582] = {.lex_state = 0},
  [583] = {.lex_state = 0},
  [584] = {.lex_state = 0},
  [585] = {.lex_state = 0},
  [586] = {.lex_state = 0},
  [587] = {.lex_state = 0},
  [588] = {.lex_state = 0},
  [589] = {.lex_state = 0},
  [590] = {.lex_state = 0},
  [591] = {.lex_state = 0},
  [592] = {.lex_state = 0},
  [593] = {.lex_state = 0},
  [594] = {.lex_state = 10},
  [595] = {.lex_state = 0},
  [596] = {.lex_state = 0},
  [597] = {.lex_state = 0},
  [598] = {.lex_state = 0},
  [599] = {.lex_state = 3},
  [600] = {.lex_state = 0},
  [601] = {.lex_state = 0},
  [602] = {.lex_state = 0},
  [603] = {.lex_state = 0},
  [604] = {.lex_state = 0},
  [605] = {.lex_state = 0},
  [606] = {.lex_state = 0},
  [607] = {.lex_state = 3},
  [608] = {.lex_state = 2},
  [609] = {.lex_state = 0},
  [610] = {.lex_state = 0},
  [611] = {.lex_state = 0},
  [612] = {.lex_state = 0},
  [613] = {.lex_state = 2},
  [614] = {.lex_state = 2},
  [615] = {.lex_state = 0},
  [616] = {.lex_state = 0},
  [617] = {.lex_state = 0},
  [618] = {.lex_state = 0},
  [619] = {.lex_state = 0},
  [620] = {.lex_state = 0},
  [621] = {.lex_state = 0},
  [622] = {.lex_state = 0},
  [623] = {.lex_state = 0},
  [624] = {.lex_state = 0},
  [625] = {.lex_state = 0},
  [626] = {.lex_state = 0},
  [627] = {.lex_state = 2},
  [628] = {.lex_state = 0},
  [629] = {.lex_state = 0},
  [630] = {.lex_state = 0},
  [631] = {.lex_state = 0},
  [632] = {.lex_state = 0},
  [633] = {.lex_state = 0},
  [634] = {.lex_state = 0},
  [635] = {.lex_state = 0},
  [636] = {.lex_state = 0},
  [637] = {.lex_state = 0},
  [638] = {.lex_state = 0},
  [639] = {.lex_state = 2},
  [640] = {.lex_state = 0},
  [641] = {.lex_state = 0},
  [642] = {.lex_state = 0},
  [643] = {.lex_state = 3},
  [644] = {.lex_state = 2},
  [645] = {.lex_state = 2},
  [646] = {.lex_state = 0},
  [647] = {.lex_state = 0},
  [648] = {.lex_state = 0},
  [649] = {.lex_state = 0},
  [650] = {.lex_state = 0},
  [651] = {.lex_state = 2},
  [652] = {.lex_state = 2},
  [653] = {.lex_state = 0},
  [654] = {.lex_state = 0},
  [655] = {.lex_state = 0},
  [656] = {.lex_state = 0},
  [657] = {.lex_state = 0},
  [658] = {.lex_state = 0},
  [659] = {.lex_state = 0},
  [660] = {.lex_state = 0},
  [661] = {.lex_state = 0},
  [662] = {.lex_state = 0},
  [663] = {.lex_state = 0},
  [664] = {.lex_state = 0},
  [665] = {.lex_state = 0},
  [666] = {.lex_state = 0},
  [667] = {.lex_state = 0},
  [668] = {.lex_state = 0},
  [669] = {.lex_state = 0},
  [670] = {.lex_state = 0},
  [671] = {.lex_state = 0},
  [672] = {.lex_state = 0},
  [673] = {.lex_state = 2},
  [674] = {.lex_state = 0},
  [675] = {.lex_state = 0},
  [676] = {.lex_state = 0},
  [677] = {.lex_state = 2},
  [678] = {.lex_state = 3},
  [679] = {.lex_state = 0},
  [680] = {.lex_state = 0},
  [681] = {.lex_state = 0},
  [682] = {.lex_state = 0},
  [683] = {.lex_state = 0},
  [684] = {.lex_state = 0},
  [685] = {.lex_state = 0},
  [686] = {.lex_state = 0},
  [687] = {.lex_state = 2},
  [688] = {.lex_state = 0},
  [689] = {.lex_state = 0},
  [690] = {.lex_state = 0},
  [691] = {.lex_state = 0},
  [692] = {.lex_state = 0},
  [693] = {.lex_state = 0},
  [694] = {.lex_state = 0},
  [695] = {.lex_state = 0},
  [696] = {.lex_state = 0},
  [697] = {.lex_state = 0},
  [698] = {.lex_state = 0},
  [699] = {.lex_state = 0},
  [700] = {.lex_state = 0},
  [701] = {.lex_state = 0},
  [702] = {.lex_state = 0},
  [703] = {.lex_state = 0},
  [704] = {.lex_state = 0},
  [705] = {.lex_state = 0},
  [706] = {.lex_state = 0},
  [707] = {.lex_state = 0},
  [708] = {.lex_state = 0},
  [709] = {.lex_state = 0},
  [710] = {.lex_state = 0},
  [711] = {.lex_state = 0},
  [712] = {.lex_state = 0},
  [713] = {.lex_state = 0},
  [714] = {.lex_state = 0},
  [715] = {.lex_state = 0},
  [716] = {.lex_state = 2},
  [717] = {.lex_state = 0},
  [718] = {.lex_state = 0},
  [719] = {.lex_state = 2},
  [720] = {.lex_state = 0},
  [721] = {.lex_state = 0},
  [722] = {.lex_state = 0},
  [723] = {.lex_state = 0},
  [724] = {.lex_state = 0},
  [725] = {.lex_state = 0},
  [726] = {.lex_state = 6},
  [727] = {.lex_state = 0},
  [728] = {.lex_state = 0},
  [729] = {.lex_state = 0},
  [730] = {.lex_state = 9},
  [731] = {.lex_state = 9},
  [732] = {.lex_state = 452},
  [733] = {.lex_state = 0},
  [734] = {.lex_state = 0},
  [735] = {.lex_state = 0},
  [736] = {.lex_state = 0},
  [737] = {.lex_state = 2},
  [738] = {.lex_state = 0},
  [739] = {.lex_state = 0},
  [740] = {.lex_state = 0},
  [741] = {.lex_state = 0},
  [742] = {.lex_state = 2},
  [743] = {.lex_state = 0},
  [744] = {.lex_state = 0},
  [745] = {.lex_state = 2},
  [746] = {.lex_state = 0},
  [747] = {.lex_state = 0},
  [748] = {.lex_state = 0},
  [749] = {.lex_state = 0},
  [750] = {.lex_state = 2},
  [751] = {.lex_state = 2},
  [752] = {.lex_state = 0},
  [753] = {.lex_state = 0},
  [754] = {.lex_state = 2},
  [755] = {.lex_state = 0},
  [756] = {.lex_state = 0},
  [757] = {.lex_state = 2},
  [758] = {.lex_state = 0},
  [759] = {.lex_state = 2},
  [760] = {.lex_state = 2},
  [761] = {.lex_state = 2},
  [762] = {.lex_state = 2},
  [763] = {.lex_state = 2},
  [764] = {.lex_state = 2},
  [765] = {.lex_state = 2},
  [766] = {.lex_state = 0},
  [767] = {.lex_state = 2},
  [768] = {.lex_state = 2},
  [769] = {.lex_state = 2},
  [770] = {.lex_state = 0},
  [771] = {.lex_state = 0},
  [772] = {.lex_state = 2},
  [773] = {.lex_state = 2},
  [774] = {.lex_state = 0},
  [775] = {.lex_state = 0},
  [776] = {.lex_state = 0},
  [777] = {.lex_state = 0},
  [778] = {.lex_state = 2},
  [779] = {.lex_state = 0},
  [780] = {.lex_state = 2},
  [781] = {.lex_state = 2},
  [782] = {.lex_state = 0},
  [783] = {.lex_state = 0},
  [784] = {.lex_state = 0},
  [785] = {.lex_state = 0},
  [786] = {.lex_state = 0},
  [787] = {.lex_state = 0},
  [788] = {.lex_state = 3},
  [789] = {.lex_state = 2},
  [790] = {.lex_state = 2},
  [791] = {.lex_state = 0},
  [792] = {.lex_state = 2},
  [793] = {.lex_state = 0},
  [794] = {.lex_state = 0},
  [795] = {.lex_state = 0},
  [796] = {.lex_state = 0},
  [797] = {.lex_state = 2},
  [798] = {.lex_state = 0},
  [799] = {.lex_state = 0},
  [800] = {.lex_state = 0},
  [801] = {.lex_state = 2},
  [802] = {.lex_state = 0},
  [803] = {.lex_state = 0},
  [804] = {.lex_state = 0},
  [805] = {.lex_state = 0},
  [806] = {.lex_state = 0},
  [807] = {.lex_state = 0},
  [808] = {.lex_state = 0},
  [809] = {.lex_state = 2},
  [810] = {.lex_state = 2},
  [811] = {.lex_state = 0},
  [812] = {.lex_state = 2},
  [813] = {.lex_state = 0},
  [814] = {.lex_state = 0},
  [815] = {.lex_state = 0},
  [816] = {.lex_state = 0},
  [817] = {.lex_state = 0},
  [818] = {.lex_state = 2},
  [819] = {.lex_state = 0},
  [820] = {.lex_state = 0},
  [821] = {.lex_state = 0},
  [822] = {.lex_state = 2},
  [823] = {.lex_state = 0},
  [824] = {.lex_state = 0},
  [825] = {.lex_state = 0},
  [826] = {.lex_state = 0},
  [827] = {.lex_state = 0},
  [828] = {.lex_state = 0},
  [829] = {.lex_state = 0},
  [830] = {.lex_state = 2},
  [831] = {.lex_state = 0},
  [832] = {.lex_state = 0},
  [833] = {.lex_state = 0},
  [834] = {.lex_state = 0},
  [835] = {.lex_state = 0},
  [836] = {.lex_state = 0},
  [837] = {.lex_state = 2},
  [838] = {.lex_state = 0},
  [839] = {.lex_state = 0},
  [840] = {.lex_state = 0},
  [841] = {.lex_state = 0},
  [842] = {.lex_state = 0},
  [843] = {.lex_state = 2},
  [844] = {.lex_state = 2},
  [845] = {.lex_state = 0},
  [846] = {.lex_state = 0},
  [847] = {.lex_state = 2},
  [848] = {.lex_state = 0},
  [849] = {.lex_state = 0},
  [850] = {.lex_state = 2},
  [851] = {.lex_state = 2},
  [852] = {.lex_state = 2},
  [853] = {.lex_state = 0},
  [854] = {.lex_state = 2},
  [855] = {.lex_state = 0},
  [856] = {.lex_state = 0},
  [857] = {.lex_state = 0},
  [858] = {.lex_state = 0},
  [859] = {.lex_state = 2},
  [860] = {.lex_state = 0},
  [861] = {.lex_state = 0},
  [862] = {.lex_state = 0},
  [863] = {.lex_state = 2},
  [864] = {.lex_state = 2},
  [865] = {.lex_state = 2},
  [866] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_QUOTED_STRING] = ACTIONS(1),
    [sym_NUMBER] = ACTIONS(1),
    [sym_DURATION] = ACTIONS(1),
    [sym_DISTANCE] = ACTIONS(1),
    [sym_QUANTITY] = ACTIONS(1),
    [sym_COLOR] = ACTIONS(1),
    [sym_CONSTANT] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_add] = ACTIONS(1),
    [anon_sym_serial_dialog] = ACTIONS(1),
    [anon_sym_settings] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_wrap] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_name] = ACTIONS(1),
    [anon_sym_portrait] = ACTIONS(1),
    [anon_sym_alignment] = ACTIONS(1),
    [anon_sym_border_tileset] = ACTIONS(1),
    [anon_sym_emote] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym_serial_dialog_option_type] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_debug] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_rand] = ACTIONS(1),
    [anon_sym_spread] = ACTIONS(1),
    [sym_return_statement] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
    [anon_sym_show] = ACTIONS(1),
    [anon_sym_concat] = ACTIONS(1),
    [anon_sym_delete] = ACTIONS(1),
    [anon_sym_command] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_hide] = ACTIONS(1),
    [anon_sym_unhide] = ACTIONS(1),
    [anon_sym_save] = ACTIONS(1),
    [anon_sym_slot] = ACTIONS(1),
    [anon_sym_erase] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
    [anon_sym_wait] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [sym_player] = ACTIONS(1),
    [sym_self] = ACTIONS(1),
    [anon_sym_pause] = ACTIONS(1),
    [anon_sym_unpause] = ACTIONS(1),
    [anon_sym_camera] = ACTIONS(1),
    [anon_sym_fade] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_out] = ACTIONS(1),
    [anon_sym_shake] = ACTIONS(1),
    [anon_sym_animation] = ACTIONS(1),
    [anon_sym_geometry] = ACTIONS(1),
    [sym_origin] = ACTIONS(1),
    [sym_length] = ACTIONS(1),
    [sym_forever] = ACTIONS(1),
    [anon_sym_position] = ACTIONS(1),
    [sym_glitched] = ACTIONS(1),
    [anon_sym_light] = ACTIONS(1),
    [anon_sym_player_control] = ACTIONS(1),
    [anon_sym_lights_control] = ACTIONS(1),
    [anon_sym_hex_editor] = ACTIONS(1),
    [anon_sym_hex_dialog_mode] = ACTIONS(1),
    [anon_sym_hex_control] = ACTIONS(1),
    [anon_sym_hex_clipboard] = ACTIONS(1),
    [anon_sym_serial_control] = ACTIONS(1),
    [anon_sym_flagName] = ACTIONS(1),
    [sym_AND] = ACTIONS(1),
    [sym_OR] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_x] = ACTIONS(1),
    [anon_sym_y] = ACTIONS(1),
    [anon_sym_primary_id] = ACTIONS(1),
    [anon_sym_secondary_id] = ACTIONS(1),
    [anon_sym_primary_id_type] = ACTIONS(1),
    [anon_sym_current_animation] = ACTIONS(1),
    [anon_sym_animation_frame] = ACTIONS(1),
    [anon_sym_strafe] = ACTIONS(1),
    [anon_sym_path] = ACTIONS(1),
    [anon_sym_on_tick] = ACTIONS(1),
    [anon_sym_on_look] = ACTIONS(1),
    [anon_sym_on_interact] = ACTIONS(1),
    [sym_fail] = ACTIONS(1),
    [anon_sym_serial_connect] = ACTIONS(1),
    [anon_sym_warp_state] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(782),
    [sym_constant_expansion] = STATE(854),
    [sym__root] = STATE(49),
    [sym_include_macro] = STATE(49),
    [sym_constant_assignment] = STATE(49),
    [sym_add_serial_dialog_settings] = STATE(49),
    [sym_add_dialog_settings] = STATE(49),
    [sym_dialog_definition] = STATE(49),
    [sym_serial_dialog_definition] = STATE(49),
    [sym_script_definition] = STATE(49),
    [aux_sym_source_file_repeat1] = STATE(49),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(7),
    [sym_BAREWORD] = ACTIONS(9),
    [sym_CONSTANT] = ACTIONS(11),
    [anon_sym_include] = ACTIONS(13),
    [anon_sym_add] = ACTIONS(15),
    [anon_sym_serial_dialog] = ACTIONS(17),
    [anon_sym_dialog] = ACTIONS(19),
    [anon_sym_script] = ACTIONS(21),
  },
  [2] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(4),
    [sym_json_literal] = STATE(4),
    [sym_label] = STATE(4),
    [sym_debug_macro] = STATE(4),
    [sym_rand_macro] = STATE(4),
    [sym_spread_macro] = STATE(4),
    [sym__action_item] = STATE(848),
    [sym_action_load_map] = STATE(848),
    [sym_action_run_script] = STATE(848),
    [sym_action_goto_label] = STATE(848),
    [sym_action_goto_index] = STATE(848),
    [sym_action_show_dialog] = STATE(848),
    [sym_action_show_serial_dialog] = STATE(848),
    [sym_action_concat_serial_dialog] = STATE(848),
    [sym_action_delete_command] = STATE(848),
    [sym_action_delete_command_arg] = STATE(848),
    [sym_action_delete_alias] = STATE(848),
    [sym_action_hide_command] = STATE(848),
    [sym_action_unhide_command] = STATE(848),
    [sym_action_save_slot] = STATE(848),
    [sym_action_load_slot] = STATE(848),
    [sym_action_erase_slot] = STATE(848),
    [sym_action_blocking_delay] = STATE(848),
    [sym_action_non_blocking_delay] = STATE(848),
    [sym_action_close_dialog] = STATE(848),
    [sym_action_close_serial_dialog] = STATE(848),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(848),
    [sym_action_unpause_script] = STATE(848),
    [sym_action_camera_fade] = STATE(848),
    [sym_action_camera_shake] = STATE(848),
    [sym_action_play_entity_animation] = STATE(848),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(848),
    [sym_action_set_position] = STATE(848),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(848),
    [sym_if_chain] = STATE(848),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(848),
    [sym_for_block] = STATE(848),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(848),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(848),
    [aux_sym_looping_block_repeat1] = STATE(4),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(25),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(29),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(33),
    [anon_sym_debug] = ACTIONS(35),
    [anon_sym_rand] = ACTIONS(37),
    [anon_sym_spread] = ACTIONS(39),
    [sym_return_statement] = ACTIONS(41),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_break] = ACTIONS(87),
    [anon_sym_continue] = ACTIONS(87),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [3] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(3),
    [sym_json_literal] = STATE(3),
    [sym_label] = STATE(3),
    [sym_debug_macro] = STATE(3),
    [sym_rand_macro] = STATE(3),
    [sym_spread_macro] = STATE(3),
    [sym__action_item] = STATE(848),
    [sym_action_load_map] = STATE(848),
    [sym_action_run_script] = STATE(848),
    [sym_action_goto_label] = STATE(848),
    [sym_action_goto_index] = STATE(848),
    [sym_action_show_dialog] = STATE(848),
    [sym_action_show_serial_dialog] = STATE(848),
    [sym_action_concat_serial_dialog] = STATE(848),
    [sym_action_delete_command] = STATE(848),
    [sym_action_delete_command_arg] = STATE(848),
    [sym_action_delete_alias] = STATE(848),
    [sym_action_hide_command] = STATE(848),
    [sym_action_unhide_command] = STATE(848),
    [sym_action_save_slot] = STATE(848),
    [sym_action_load_slot] = STATE(848),
    [sym_action_erase_slot] = STATE(848),
    [sym_action_blocking_delay] = STATE(848),
    [sym_action_non_blocking_delay] = STATE(848),
    [sym_action_close_dialog] = STATE(848),
    [sym_action_close_serial_dialog] = STATE(848),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(848),
    [sym_action_unpause_script] = STATE(848),
    [sym_action_camera_fade] = STATE(848),
    [sym_action_camera_shake] = STATE(848),
    [sym_action_play_entity_animation] = STATE(848),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(848),
    [sym_action_set_position] = STATE(848),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(848),
    [sym_if_chain] = STATE(848),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(848),
    [sym_for_block] = STATE(848),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(848),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(848),
    [aux_sym_looping_block_repeat1] = STATE(3),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(95),
    [sym_BAREWORD] = ACTIONS(98),
    [sym_CONSTANT] = ACTIONS(101),
    [anon_sym_RBRACE] = ACTIONS(104),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(109),
    [anon_sym_debug] = ACTIONS(112),
    [anon_sym_rand] = ACTIONS(115),
    [anon_sym_spread] = ACTIONS(118),
    [sym_return_statement] = ACTIONS(121),
    [anon_sym_load] = ACTIONS(124),
    [anon_sym_map] = ACTIONS(127),
    [anon_sym_goto] = ACTIONS(130),
    [anon_sym_show] = ACTIONS(133),
    [anon_sym_concat] = ACTIONS(136),
    [anon_sym_delete] = ACTIONS(139),
    [anon_sym_command] = ACTIONS(142),
    [anon_sym_alias] = ACTIONS(145),
    [anon_sym_hide] = ACTIONS(148),
    [anon_sym_unhide] = ACTIONS(151),
    [anon_sym_save] = ACTIONS(154),
    [anon_sym_erase] = ACTIONS(157),
    [anon_sym_block] = ACTIONS(160),
    [anon_sym_wait] = ACTIONS(163),
    [anon_sym_close] = ACTIONS(166),
    [sym_player] = ACTIONS(169),
    [sym_self] = ACTIONS(169),
    [anon_sym_pause] = ACTIONS(172),
    [anon_sym_unpause] = ACTIONS(175),
    [anon_sym_camera] = ACTIONS(178),
    [anon_sym_light] = ACTIONS(181),
    [anon_sym_player_control] = ACTIONS(184),
    [anon_sym_lights_control] = ACTIONS(184),
    [anon_sym_hex_editor] = ACTIONS(184),
    [anon_sym_hex_dialog_mode] = ACTIONS(184),
    [anon_sym_hex_control] = ACTIONS(184),
    [anon_sym_hex_clipboard] = ACTIONS(184),
    [anon_sym_serial_control] = ACTIONS(184),
    [anon_sym_flagName] = ACTIONS(184),
    [anon_sym_if] = ACTIONS(187),
    [anon_sym_break] = ACTIONS(190),
    [anon_sym_continue] = ACTIONS(190),
    [anon_sym_while] = ACTIONS(193),
    [anon_sym_for] = ACTIONS(196),
    [anon_sym_serial_connect] = ACTIONS(199),
    [anon_sym_warp_state] = ACTIONS(199),
  },
  [4] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(3),
    [sym_json_literal] = STATE(3),
    [sym_label] = STATE(3),
    [sym_debug_macro] = STATE(3),
    [sym_rand_macro] = STATE(3),
    [sym_spread_macro] = STATE(3),
    [sym__action_item] = STATE(848),
    [sym_action_load_map] = STATE(848),
    [sym_action_run_script] = STATE(848),
    [sym_action_goto_label] = STATE(848),
    [sym_action_goto_index] = STATE(848),
    [sym_action_show_dialog] = STATE(848),
    [sym_action_show_serial_dialog] = STATE(848),
    [sym_action_concat_serial_dialog] = STATE(848),
    [sym_action_delete_command] = STATE(848),
    [sym_action_delete_command_arg] = STATE(848),
    [sym_action_delete_alias] = STATE(848),
    [sym_action_hide_command] = STATE(848),
    [sym_action_unhide_command] = STATE(848),
    [sym_action_save_slot] = STATE(848),
    [sym_action_load_slot] = STATE(848),
    [sym_action_erase_slot] = STATE(848),
    [sym_action_blocking_delay] = STATE(848),
    [sym_action_non_blocking_delay] = STATE(848),
    [sym_action_close_dialog] = STATE(848),
    [sym_action_close_serial_dialog] = STATE(848),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(848),
    [sym_action_unpause_script] = STATE(848),
    [sym_action_camera_fade] = STATE(848),
    [sym_action_camera_shake] = STATE(848),
    [sym_action_play_entity_animation] = STATE(848),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(848),
    [sym_action_set_position] = STATE(848),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(848),
    [sym_if_chain] = STATE(848),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(848),
    [sym_for_block] = STATE(848),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(848),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(848),
    [aux_sym_looping_block_repeat1] = STATE(3),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(25),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(202),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(33),
    [anon_sym_debug] = ACTIONS(35),
    [anon_sym_rand] = ACTIONS(37),
    [anon_sym_spread] = ACTIONS(39),
    [sym_return_statement] = ACTIONS(41),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_break] = ACTIONS(87),
    [anon_sym_continue] = ACTIONS(87),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [5] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(204),
    [sym_BAREWORD] = ACTIONS(207),
    [sym_CONSTANT] = ACTIONS(210),
    [anon_sym_RBRACE] = ACTIONS(213),
    [anon_sym_entity] = ACTIONS(215),
    [anon_sym_json] = ACTIONS(218),
    [anon_sym_debug] = ACTIONS(221),
    [anon_sym_RPAREN] = ACTIONS(213),
    [anon_sym_rand] = ACTIONS(224),
    [anon_sym_spread] = ACTIONS(227),
    [sym_return_statement] = ACTIONS(230),
    [anon_sym_load] = ACTIONS(233),
    [anon_sym_map] = ACTIONS(236),
    [anon_sym_goto] = ACTIONS(239),
    [anon_sym_show] = ACTIONS(242),
    [anon_sym_concat] = ACTIONS(245),
    [anon_sym_delete] = ACTIONS(248),
    [anon_sym_command] = ACTIONS(251),
    [anon_sym_alias] = ACTIONS(254),
    [anon_sym_hide] = ACTIONS(257),
    [anon_sym_unhide] = ACTIONS(260),
    [anon_sym_save] = ACTIONS(263),
    [anon_sym_erase] = ACTIONS(266),
    [anon_sym_block] = ACTIONS(269),
    [anon_sym_wait] = ACTIONS(272),
    [anon_sym_close] = ACTIONS(275),
    [sym_player] = ACTIONS(278),
    [sym_self] = ACTIONS(278),
    [anon_sym_pause] = ACTIONS(281),
    [anon_sym_unpause] = ACTIONS(284),
    [anon_sym_camera] = ACTIONS(287),
    [anon_sym_light] = ACTIONS(290),
    [anon_sym_player_control] = ACTIONS(293),
    [anon_sym_lights_control] = ACTIONS(293),
    [anon_sym_hex_editor] = ACTIONS(293),
    [anon_sym_hex_dialog_mode] = ACTIONS(293),
    [anon_sym_hex_control] = ACTIONS(293),
    [anon_sym_hex_clipboard] = ACTIONS(293),
    [anon_sym_serial_control] = ACTIONS(293),
    [anon_sym_flagName] = ACTIONS(293),
    [anon_sym_if] = ACTIONS(296),
    [anon_sym_while] = ACTIONS(299),
    [anon_sym_for] = ACTIONS(302),
    [anon_sym_serial_connect] = ACTIONS(305),
    [anon_sym_warp_state] = ACTIONS(305),
  },
  [6] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(9),
    [sym_json_literal] = STATE(9),
    [sym_label] = STATE(9),
    [sym_debug_macro] = STATE(9),
    [sym_rand_macro] = STATE(9),
    [sym_spread_macro] = STATE(9),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(9),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(310),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [7] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(322),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [8] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(11),
    [sym_json_literal] = STATE(11),
    [sym_label] = STATE(11),
    [sym_debug_macro] = STATE(11),
    [sym_rand_macro] = STATE(11),
    [sym_spread_macro] = STATE(11),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(11),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(324),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [9] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(326),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [10] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(12),
    [sym_json_literal] = STATE(12),
    [sym_label] = STATE(12),
    [sym_debug_macro] = STATE(12),
    [sym_rand_macro] = STATE(12),
    [sym_spread_macro] = STATE(12),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(12),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(328),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [11] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(330),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [12] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(332),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [13] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(334),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [14] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(15),
    [sym_json_literal] = STATE(15),
    [sym_label] = STATE(15),
    [sym_debug_macro] = STATE(15),
    [sym_rand_macro] = STATE(15),
    [sym_spread_macro] = STATE(15),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(15),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(336),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [15] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_label] = STATE(5),
    [sym_debug_macro] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_spread_macro] = STATE(5),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_RBRACE] = ACTIONS(338),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [16] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(7),
    [sym_json_literal] = STATE(7),
    [sym_label] = STATE(7),
    [sym_debug_macro] = STATE(7),
    [sym_rand_macro] = STATE(7),
    [sym_spread_macro] = STATE(7),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(7),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(340),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [17] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__script_item] = STATE(13),
    [sym_json_literal] = STATE(13),
    [sym_label] = STATE(13),
    [sym_debug_macro] = STATE(13),
    [sym_rand_macro] = STATE(13),
    [sym_spread_macro] = STATE(13),
    [sym__action_item] = STATE(800),
    [sym_action_load_map] = STATE(800),
    [sym_action_run_script] = STATE(800),
    [sym_action_goto_label] = STATE(800),
    [sym_action_goto_index] = STATE(800),
    [sym_action_show_dialog] = STATE(800),
    [sym_action_show_serial_dialog] = STATE(800),
    [sym_action_concat_serial_dialog] = STATE(800),
    [sym_action_delete_command] = STATE(800),
    [sym_action_delete_command_arg] = STATE(800),
    [sym_action_delete_alias] = STATE(800),
    [sym_action_hide_command] = STATE(800),
    [sym_action_unhide_command] = STATE(800),
    [sym_action_save_slot] = STATE(800),
    [sym_action_load_slot] = STATE(800),
    [sym_action_erase_slot] = STATE(800),
    [sym_action_blocking_delay] = STATE(800),
    [sym_action_non_blocking_delay] = STATE(800),
    [sym_action_close_dialog] = STATE(800),
    [sym_action_close_serial_dialog] = STATE(800),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(800),
    [sym_action_unpause_script] = STATE(800),
    [sym_action_camera_fade] = STATE(800),
    [sym_action_camera_shake] = STATE(800),
    [sym_action_play_entity_animation] = STATE(800),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(800),
    [sym_action_set_position] = STATE(800),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(800),
    [sym_if_chain] = STATE(800),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(800),
    [sym_for_block] = STATE(800),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(800),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(800),
    [aux_sym_script_block_repeat1] = STATE(13),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(308),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(312),
    [anon_sym_debug] = ACTIONS(314),
    [anon_sym_RPAREN] = ACTIONS(342),
    [anon_sym_rand] = ACTIONS(316),
    [anon_sym_spread] = ACTIONS(318),
    [sym_return_statement] = ACTIONS(320),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [18] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__action_item] = STATE(836),
    [sym_action_load_map] = STATE(836),
    [sym_action_run_script] = STATE(836),
    [sym_action_goto_label] = STATE(836),
    [sym_action_goto_index] = STATE(836),
    [sym_action_show_dialog] = STATE(836),
    [sym_action_show_serial_dialog] = STATE(836),
    [sym_action_concat_serial_dialog] = STATE(836),
    [sym_action_delete_command] = STATE(836),
    [sym_action_delete_command_arg] = STATE(836),
    [sym_action_delete_alias] = STATE(836),
    [sym_action_hide_command] = STATE(836),
    [sym_action_unhide_command] = STATE(836),
    [sym_action_save_slot] = STATE(836),
    [sym_action_load_slot] = STATE(836),
    [sym_action_erase_slot] = STATE(836),
    [sym_action_blocking_delay] = STATE(836),
    [sym_action_non_blocking_delay] = STATE(836),
    [sym_action_close_dialog] = STATE(836),
    [sym_action_close_serial_dialog] = STATE(836),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(836),
    [sym_action_unpause_script] = STATE(836),
    [sym_action_camera_fade] = STATE(836),
    [sym_action_camera_shake] = STATE(836),
    [sym_action_play_entity_animation] = STATE(836),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(836),
    [sym_action_set_position] = STATE(836),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(836),
    [sym_if_chain] = STATE(836),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(836),
    [sym_for_block] = STATE(836),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(836),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(836),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(344),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [sym_return_statement] = ACTIONS(346),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
  [19] = {
    [sym_bareword_expansion] = STATE(801),
    [sym__action_item] = STATE(833),
    [sym_action_load_map] = STATE(833),
    [sym_action_run_script] = STATE(833),
    [sym_action_goto_label] = STATE(833),
    [sym_action_goto_index] = STATE(833),
    [sym_action_show_dialog] = STATE(833),
    [sym_action_show_serial_dialog] = STATE(833),
    [sym_action_concat_serial_dialog] = STATE(833),
    [sym_action_delete_command] = STATE(833),
    [sym_action_delete_command_arg] = STATE(833),
    [sym_action_delete_alias] = STATE(833),
    [sym_action_hide_command] = STATE(833),
    [sym_action_unhide_command] = STATE(833),
    [sym_action_save_slot] = STATE(833),
    [sym_action_load_slot] = STATE(833),
    [sym_action_erase_slot] = STATE(833),
    [sym_action_blocking_delay] = STATE(833),
    [sym_action_non_blocking_delay] = STATE(833),
    [sym_action_close_dialog] = STATE(833),
    [sym_action_close_serial_dialog] = STATE(833),
    [sym_entity_identifier_expansion] = STATE(58),
    [sym_map] = STATE(132),
    [sym_action_pause_script] = STATE(833),
    [sym_action_unpause_script] = STATE(833),
    [sym_action_camera_fade] = STATE(833),
    [sym_action_camera_shake] = STATE(833),
    [sym_action_play_entity_animation] = STATE(833),
    [sym_camera] = STATE(351),
    [sym_movable_identifier_expansion] = STATE(351),
    [sym_action_move_over_time] = STATE(833),
    [sym_action_set_position] = STATE(833),
    [sym_bool_setable] = STATE(677),
    [sym_action_set_bool] = STATE(833),
    [sym_if_chain] = STATE(833),
    [sym_if_block] = STATE(198),
    [sym_while_block] = STATE(833),
    [sym_for_block] = STATE(833),
    [sym_int_setable] = STATE(687),
    [sym_action_set_int] = STATE(833),
    [sym_string_setable] = STATE(719),
    [sym_action_set_string] = STATE(833),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(344),
    [sym_CONSTANT] = ACTIONS(27),
    [anon_sym_entity] = ACTIONS(31),
    [sym_return_statement] = ACTIONS(348),
    [anon_sym_load] = ACTIONS(43),
    [anon_sym_map] = ACTIONS(45),
    [anon_sym_goto] = ACTIONS(47),
    [anon_sym_show] = ACTIONS(49),
    [anon_sym_concat] = ACTIONS(51),
    [anon_sym_delete] = ACTIONS(53),
    [anon_sym_command] = ACTIONS(55),
    [anon_sym_alias] = ACTIONS(57),
    [anon_sym_hide] = ACTIONS(59),
    [anon_sym_unhide] = ACTIONS(61),
    [anon_sym_save] = ACTIONS(63),
    [anon_sym_erase] = ACTIONS(65),
    [anon_sym_block] = ACTIONS(67),
    [anon_sym_wait] = ACTIONS(69),
    [anon_sym_close] = ACTIONS(71),
    [sym_player] = ACTIONS(73),
    [sym_self] = ACTIONS(73),
    [anon_sym_pause] = ACTIONS(75),
    [anon_sym_unpause] = ACTIONS(77),
    [anon_sym_camera] = ACTIONS(79),
    [anon_sym_light] = ACTIONS(81),
    [anon_sym_player_control] = ACTIONS(83),
    [anon_sym_lights_control] = ACTIONS(83),
    [anon_sym_hex_editor] = ACTIONS(83),
    [anon_sym_hex_dialog_mode] = ACTIONS(83),
    [anon_sym_hex_control] = ACTIONS(83),
    [anon_sym_hex_clipboard] = ACTIONS(83),
    [anon_sym_serial_control] = ACTIONS(83),
    [anon_sym_flagName] = ACTIONS(83),
    [anon_sym_if] = ACTIONS(85),
    [anon_sym_while] = ACTIONS(89),
    [anon_sym_for] = ACTIONS(91),
    [anon_sym_serial_connect] = ACTIONS(93),
    [anon_sym_warp_state] = ACTIONS(93),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(350), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(352), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [56] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(354), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(356), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [112] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(358), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(360), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [168] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(364), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [223] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(368), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [278] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(372), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [333] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(374), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(376), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [388] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(378), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(380), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [443] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(350), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(352), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [498] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(354), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(356), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [553] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(382), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(384), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [608] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(386), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(388), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [663] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(358), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(360), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [718] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(390), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(392), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [773] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(396), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [828] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(398), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(400), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [883] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(104), 3,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
    ACTIONS(402), 43,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [938] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(372), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [992] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(390), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(392), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1046] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(396), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1100] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(378), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(380), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1154] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(398), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(400), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1208] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(368), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1262] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(386), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(388), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1316] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(382), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(384), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1370] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(374), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(376), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1424] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(364), 41,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_map,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_command,
      anon_sym_alias,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_save,
      anon_sym_erase,
      anon_sym_block,
      anon_sym_wait,
      anon_sym_close,
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
      anon_sym_light,
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_serial_connect,
      anon_sym_warp_state,
  [1478] = 10,
    ACTIONS(404), 1,
      anon_sym_LBRACK,
    ACTIONS(408), 1,
      anon_sym_animation,
    ACTIONS(410), 1,
      anon_sym_position,
    ACTIONS(412), 1,
      sym_glitched,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(818), 2,
      sym_entity_property_int,
      sym_entity_property_int_expansion,
    STATE(851), 2,
      sym_entity_property_string,
      sym_entity_property_string_expansion,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [1522] = 10,
    ACTIONS(404), 1,
      anon_sym_LBRACK,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(418), 1,
      anon_sym_animation,
    ACTIONS(420), 1,
      anon_sym_position,
    ACTIONS(422), 1,
      sym_glitched,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(843), 2,
      sym_entity_property_int,
      sym_entity_property_int_expansion,
    STATE(844), 2,
      sym_entity_property_string,
      sym_entity_property_string_expansion,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [1566] = 12,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      sym_BAREWORD,
    ACTIONS(11), 1,
      sym_CONSTANT,
    ACTIONS(13), 1,
      anon_sym_include,
    ACTIONS(15), 1,
      anon_sym_add,
    ACTIONS(17), 1,
      anon_sym_serial_dialog,
    ACTIONS(19), 1,
      anon_sym_dialog,
    ACTIONS(21), 1,
      anon_sym_script,
    ACTIONS(424), 1,
      ts_builtin_sym_end,
    STATE(854), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [1612] = 12,
    ACTIONS(426), 1,
      ts_builtin_sym_end,
    ACTIONS(428), 1,
      anon_sym_LBRACK,
    ACTIONS(431), 1,
      sym_BAREWORD,
    ACTIONS(434), 1,
      sym_CONSTANT,
    ACTIONS(437), 1,
      anon_sym_include,
    ACTIONS(440), 1,
      anon_sym_add,
    ACTIONS(443), 1,
      anon_sym_serial_dialog,
    ACTIONS(446), 1,
      anon_sym_dialog,
    ACTIONS(449), 1,
      anon_sym_script,
    STATE(854), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [1658] = 7,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(452), 1,
      anon_sym_RBRACK,
    STATE(403), 1,
      sym_entity_property_int,
    STATE(406), 1,
      sym_entity_property_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [1691] = 5,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(456), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(454), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1716] = 4,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(460), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
    ACTIONS(462), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(458), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [1739] = 9,
    ACTIONS(468), 1,
      sym_AND,
    ACTIONS(470), 1,
      sym_OR,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(464), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1772] = 8,
    ACTIONS(468), 1,
      sym_AND,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(476), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_OR,
  [1803] = 7,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(476), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [1832] = 6,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(476), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1859] = 6,
    ACTIONS(408), 1,
      anon_sym_animation,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(478), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(818), 2,
      sym_entity_property_int,
      sym_entity_property_int_expansion,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [1886] = 5,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(476), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1911] = 9,
    ACTIONS(468), 1,
      sym_AND,
    ACTIONS(470), 1,
      sym_OR,
    ACTIONS(482), 1,
      anon_sym_RPAREN,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1943] = 6,
    ACTIONS(484), 1,
      anon_sym_LBRACK,
    ACTIONS(486), 1,
      anon_sym_RBRACK,
    ACTIONS(490), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(533), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(488), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1969] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(492), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(494), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1989] = 5,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(829), 1,
      sym_constant_value_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(500), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(496), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [2013] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(502), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(504), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2033] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(506), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(508), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2053] = 11,
    ACTIONS(510), 1,
      sym_QUOTED_STRING,
    ACTIONS(512), 1,
      anon_sym_wrap,
    ACTIONS(514), 1,
      anon_sym_entity,
    ACTIONS(516), 1,
      anon_sym_name,
    ACTIONS(518), 1,
      anon_sym_portrait,
    ACTIONS(520), 1,
      anon_sym_alignment,
    ACTIONS(522), 1,
      anon_sym_border_tileset,
    ACTIONS(524), 1,
      anon_sym_emote,
    STATE(118), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [2089] = 9,
    ACTIONS(468), 1,
      sym_AND,
    ACTIONS(470), 1,
      sym_OR,
    ACTIONS(526), 1,
      anon_sym_RPAREN,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2121] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(528), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(530), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2141] = 11,
    ACTIONS(510), 1,
      sym_QUOTED_STRING,
    ACTIONS(512), 1,
      anon_sym_wrap,
    ACTIONS(514), 1,
      anon_sym_entity,
    ACTIONS(516), 1,
      anon_sym_name,
    ACTIONS(518), 1,
      anon_sym_portrait,
    ACTIONS(520), 1,
      anon_sym_alignment,
    ACTIONS(522), 1,
      anon_sym_border_tileset,
    ACTIONS(524), 1,
      anon_sym_emote,
    STATE(116), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(71), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [2177] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(534), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2197] = 10,
    ACTIONS(538), 1,
      anon_sym_wrap,
    ACTIONS(541), 1,
      anon_sym_entity,
    ACTIONS(544), 1,
      anon_sym_name,
    ACTIONS(547), 1,
      anon_sym_portrait,
    ACTIONS(550), 1,
      anon_sym_alignment,
    ACTIONS(553), 1,
      anon_sym_border_tileset,
    ACTIONS(556), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(536), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(71), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [2231] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(559), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(561), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2251] = 6,
    ACTIONS(484), 1,
      anon_sym_LBRACK,
    ACTIONS(490), 1,
      anon_sym_LBRACE,
    ACTIONS(563), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(392), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(565), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2277] = 9,
    ACTIONS(468), 1,
      sym_AND,
    ACTIONS(470), 1,
      sym_OR,
    ACTIONS(567), 1,
      anon_sym_SEMI,
    STATE(133), 1,
      sym_COMPARISON,
    STATE(134), 1,
      sym_EQUALITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(472), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(474), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2309] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(571), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(569), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2328] = 9,
    ACTIONS(573), 1,
      anon_sym_LBRACK,
    ACTIONS(575), 1,
      sym_BAREWORD,
    ACTIONS(577), 1,
      sym_NUMBER,
    ACTIONS(579), 1,
      sym_CONSTANT,
    ACTIONS(581), 1,
      anon_sym_LPAREN,
    ACTIONS(583), 1,
      anon_sym_DASH,
    STATE(582), 1,
      sym_int_or_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(123), 3,
      sym__int_expression,
      sym_int_unary_expression,
      sym_int_binary_expression,
  [2359] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(587), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(585), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2378] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(591), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(589), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2397] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(595), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(593), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2416] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(597), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2435] = 9,
    ACTIONS(601), 1,
      sym_BOOL,
    ACTIONS(603), 1,
      anon_sym_LBRACK,
    ACTIONS(605), 1,
      sym_BAREWORD,
    ACTIONS(607), 1,
      sym_CONSTANT,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    STATE(567), 1,
      sym_bool_or_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(54), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [2466] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(615), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(613), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2485] = 5,
    ACTIONS(484), 1,
      anon_sym_LBRACK,
    ACTIONS(490), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(667), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(617), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2508] = 5,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(619), 1,
      anon_sym_RBRACK,
    STATE(708), 1,
      sym_entity_property_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2531] = 4,
    ACTIONS(623), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(625), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(621), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [2552] = 10,
    ACTIONS(512), 1,
      anon_sym_wrap,
    ACTIONS(514), 1,
      anon_sym_entity,
    ACTIONS(516), 1,
      anon_sym_name,
    ACTIONS(518), 1,
      anon_sym_portrait,
    ACTIONS(520), 1,
      anon_sym_alignment,
    ACTIONS(522), 1,
      anon_sym_border_tileset,
    ACTIONS(524), 1,
      anon_sym_emote,
    ACTIONS(627), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(97), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [2585] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(631), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(629), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2604] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(635), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(633), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2623] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(639), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(637), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2642] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(643), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(641), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2661] = 5,
    ACTIONS(484), 1,
      anon_sym_LBRACK,
    ACTIONS(490), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(587), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(645), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2684] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(587), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(585), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2703] = 5,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(647), 1,
      anon_sym_RBRACK,
    STATE(708), 1,
      sym_entity_property_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2726] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(651), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(649), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2745] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(591), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(589), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2764] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(595), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(593), 8,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [2783] = 10,
    ACTIONS(512), 1,
      anon_sym_wrap,
    ACTIONS(514), 1,
      anon_sym_entity,
    ACTIONS(516), 1,
      anon_sym_name,
    ACTIONS(518), 1,
      anon_sym_portrait,
    ACTIONS(520), 1,
      anon_sym_alignment,
    ACTIONS(522), 1,
      anon_sym_border_tileset,
    ACTIONS(524), 1,
      anon_sym_emote,
    ACTIONS(653), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(71), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [2816] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(657), 2,
      anon_sym_animation,
      anon_sym_primary_id,
    ACTIONS(655), 8,
      anon_sym_LBRACK,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2835] = 5,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    ACTIONS(659), 1,
      anon_sym_RBRACK,
    STATE(403), 1,
      sym_entity_property_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2858] = 4,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(625), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(621), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [2879] = 4,
    ACTIONS(416), 1,
      anon_sym_primary_id,
    STATE(708), 1,
      sym_entity_property_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 7,
      anon_sym_x,
      anon_sym_y,
      anon_sym_secondary_id,
      anon_sym_primary_id_type,
      anon_sym_current_animation,
      anon_sym_animation_frame,
      anon_sym_strafe,
  [2899] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(663), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(665), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2917] = 8,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    STATE(858), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(67), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [2945] = 5,
    ACTIONS(675), 1,
      anon_sym_SLASH,
    STATE(148), 1,
      sym_mul_div_mod,
    STATE(149), 1,
      sym_add_sub,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(673), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [2967] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(677), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(679), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2985] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(681), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(683), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3003] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(685), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(687), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3021] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(689), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(691), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3039] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3055] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(695), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3071] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(697), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3087] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(699), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3103] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(701), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3119] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(703), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3135] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(705), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3151] = 7,
    ACTIONS(510), 1,
      sym_QUOTED_STRING,
    ACTIONS(709), 1,
      anon_sym_RBRACE,
    ACTIONS(711), 1,
      anon_sym_GT,
    STATE(164), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(175), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(707), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [3177] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(715), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3195] = 7,
    ACTIONS(510), 1,
      sym_QUOTED_STRING,
    ACTIONS(711), 1,
      anon_sym_GT,
    ACTIONS(719), 1,
      anon_sym_RBRACE,
    STATE(164), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(165), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(717), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [3221] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(721), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(723), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3239] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(725), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(727), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3257] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(729), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(731), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3275] = 9,
    ACTIONS(733), 1,
      sym_BAREWORD,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(737), 1,
      sym_CONSTANT,
    ACTIONS(739), 1,
      anon_sym_wrap,
    ACTIONS(741), 1,
      anon_sym_RPAREN,
    STATE(159), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(841), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(222), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3305] = 7,
    ACTIONS(749), 1,
      anon_sym_SLASH,
    STATE(148), 1,
      sym_mul_div_mod,
    STATE(149), 1,
      sym_add_sub,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(743), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(745), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(747), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
  [3331] = 5,
    ACTIONS(753), 1,
      anon_sym_SLASH,
    STATE(148), 1,
      sym_mul_div_mod,
    STATE(149), 1,
      sym_add_sub,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(751), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [3353] = 6,
    ACTIONS(749), 1,
      anon_sym_SLASH,
    STATE(148), 1,
      sym_mul_div_mod,
    STATE(149), 1,
      sym_add_sub,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(747), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(751), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
  [3377] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(625), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(621), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [3395] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(755), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(757), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [3413] = 8,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    STATE(807), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(67), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3441] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(761), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(759), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [3459] = 9,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(739), 1,
      anon_sym_wrap,
    ACTIONS(763), 1,
      sym_BAREWORD,
    ACTIONS(765), 1,
      sym_CONSTANT,
    ACTIONS(767), 1,
      anon_sym_RPAREN,
    STATE(159), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(857), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(222), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3489] = 8,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    STATE(824), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(67), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3517] = 4,
    ACTIONS(769), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(851), 2,
      sym_entity_property_string,
      sym_entity_property_string_expansion,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [3536] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(59), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3561] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(57), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3586] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(52), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3611] = 7,
    ACTIONS(581), 1,
      anon_sym_LPAREN,
    ACTIONS(583), 1,
      anon_sym_DASH,
    ACTIONS(771), 1,
      sym_BAREWORD,
    ACTIONS(773), 1,
      sym_NUMBER,
    ACTIONS(775), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(146), 3,
      sym__int_expression,
      sym_int_unary_expression,
      sym_int_binary_expression,
  [3636] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(777), 8,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [3651] = 7,
    ACTIONS(581), 1,
      anon_sym_LPAREN,
    ACTIONS(583), 1,
      anon_sym_DASH,
    ACTIONS(771), 1,
      sym_BAREWORD,
    ACTIONS(773), 1,
      sym_NUMBER,
    ACTIONS(775), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(104), 3,
      sym__int_expression,
      sym_int_unary_expression,
      sym_int_binary_expression,
  [3676] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(74), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3701] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(779), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3716] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(56), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3741] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(781), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3756] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(783), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [3771] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(60), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3796] = 8,
    ACTIONS(785), 1,
      anon_sym_RBRACK,
    ACTIONS(787), 1,
      sym_BAREWORD,
    ACTIONS(789), 1,
      sym_CONSTANT,
    ACTIONS(791), 1,
      anon_sym_entity,
    ACTIONS(795), 1,
      anon_sym_camera,
    STATE(393), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(793), 2,
      sym_player,
      sym_self,
  [3823] = 7,
    ACTIONS(749), 1,
      anon_sym_SLASH,
    ACTIONS(797), 1,
      anon_sym_RPAREN,
    STATE(148), 1,
      sym_mul_div_mod,
    STATE(149), 1,
      sym_add_sub,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(745), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(747), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
  [3848] = 7,
    ACTIONS(609), 1,
      anon_sym_BANG,
    ACTIONS(611), 1,
      anon_sym_LPAREN,
    ACTIONS(667), 1,
      sym_BOOL,
    ACTIONS(669), 1,
      sym_BAREWORD,
    ACTIONS(671), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(55), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [3873] = 7,
    ACTIONS(581), 1,
      anon_sym_LPAREN,
    ACTIONS(583), 1,
      anon_sym_DASH,
    ACTIONS(771), 1,
      sym_BAREWORD,
    ACTIONS(773), 1,
      sym_NUMBER,
    ACTIONS(775), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(124), 3,
      sym__int_expression,
      sym_int_unary_expression,
      sym_int_binary_expression,
  [3898] = 7,
    ACTIONS(581), 1,
      anon_sym_LPAREN,
    ACTIONS(583), 1,
      anon_sym_DASH,
    ACTIONS(771), 1,
      sym_BAREWORD,
    ACTIONS(773), 1,
      sym_NUMBER,
    ACTIONS(775), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(125), 3,
      sym__int_expression,
      sym_int_unary_expression,
      sym_int_binary_expression,
  [3923] = 6,
    ACTIONS(799), 1,
      anon_sym_LBRACK,
    ACTIONS(801), 1,
      anon_sym_entity,
    ACTIONS(803), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(805), 2,
      sym_player,
      sym_self,
    STATE(257), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [3945] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(807), 7,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [3959] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(809), 7,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [3973] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(811), 7,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [3987] = 4,
    ACTIONS(813), 1,
      anon_sym_RBRACK,
    STATE(714), 1,
      sym_entity_property_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [4005] = 7,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(815), 1,
      anon_sym_RBRACE,
    ACTIONS(817), 1,
      anon_sym_wrap,
    STATE(159), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(766), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(222), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [4029] = 3,
    ACTIONS(821), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(819), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4045] = 3,
    ACTIONS(825), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(823), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4061] = 3,
    ACTIONS(829), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(827), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4077] = 6,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(833), 1,
      sym_serial_dialog_option_type,
    STATE(213), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(831), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(216), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [4099] = 3,
    ACTIONS(821), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(819), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4115] = 3,
    ACTIONS(825), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(823), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4131] = 3,
    ACTIONS(829), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(827), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4147] = 7,
    ACTIONS(835), 1,
      sym_BAREWORD,
    ACTIONS(837), 1,
      anon_sym_RBRACE,
    ACTIONS(839), 1,
      anon_sym_entity,
    ACTIONS(841), 1,
      anon_sym_name,
    STATE(66), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(174), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [4171] = 5,
    ACTIONS(845), 1,
      sym_QUOTED_STRING,
    STATE(164), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(848), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(843), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [4191] = 5,
    ACTIONS(711), 1,
      anon_sym_GT,
    ACTIONS(852), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(176), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(850), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [4211] = 7,
    ACTIONS(835), 1,
      sym_BAREWORD,
    ACTIONS(839), 1,
      anon_sym_entity,
    ACTIONS(841), 1,
      anon_sym_name,
    ACTIONS(854), 1,
      anon_sym_RBRACE,
    STATE(66), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(163), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [4235] = 6,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(833), 1,
      sym_serial_dialog_option_type,
    STATE(213), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(856), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(228), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [4257] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(858), 7,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [4271] = 4,
    ACTIONS(860), 1,
      anon_sym_RBRACK,
    STATE(714), 1,
      sym_entity_property_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [4289] = 7,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    ACTIONS(864), 1,
      sym_BAREWORD,
    ACTIONS(868), 1,
      anon_sym_label,
    ACTIONS(870), 1,
      anon_sym_index,
    STATE(674), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(866), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4313] = 6,
    ACTIONS(799), 1,
      anon_sym_LBRACK,
    ACTIONS(803), 1,
      anon_sym_map,
    ACTIONS(872), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(874), 2,
      sym_player,
      sym_self,
    STATE(258), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [4335] = 3,
    ACTIONS(878), 1,
      anon_sym_SLASH,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(876), 6,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_DASH,
  [4351] = 4,
    ACTIONS(880), 1,
      anon_sym_RBRACK,
    STATE(406), 1,
      sym_entity_property_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [4369] = 7,
    ACTIONS(882), 1,
      sym_BAREWORD,
    ACTIONS(885), 1,
      anon_sym_RBRACE,
    ACTIONS(887), 1,
      anon_sym_entity,
    ACTIONS(890), 1,
      anon_sym_name,
    STATE(66), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(174), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [4393] = 5,
    ACTIONS(711), 1,
      anon_sym_GT,
    ACTIONS(895), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(176), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(893), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [4413] = 5,
    ACTIONS(899), 1,
      anon_sym_RBRACE,
    ACTIONS(901), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(176), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(897), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [4433] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(904), 7,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [4447] = 6,
    ACTIONS(906), 1,
      anon_sym_RBRACK,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4468] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(916), 1,
      anon_sym_entity,
    ACTIONS(920), 1,
      anon_sym_geometry,
    STATE(349), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(918), 2,
      sym_player,
      sym_self,
  [4489] = 5,
    ACTIONS(924), 1,
      anon_sym_else,
    STATE(570), 1,
      sym_else_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(922), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(203), 2,
      sym_if_else_block,
      aux_sym_if_chain_repeat1,
  [4508] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(926), 1,
      anon_sym_entity,
    ACTIONS(930), 1,
      anon_sym_geometry,
    STATE(615), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(928), 2,
      sym_player,
      sym_self,
  [4529] = 6,
    ACTIONS(932), 1,
      anon_sym_RBRACK,
    ACTIONS(934), 1,
      anon_sym_entity,
    ACTIONS(936), 1,
      anon_sym_map,
    STATE(744), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(938), 2,
      sym_player,
      sym_self,
  [4550] = 6,
    ACTIONS(934), 1,
      anon_sym_entity,
    ACTIONS(936), 1,
      anon_sym_map,
    ACTIONS(940), 1,
      anon_sym_RBRACK,
    STATE(744), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(938), 2,
      sym_player,
      sym_self,
  [4571] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(942), 1,
      anon_sym_entity,
    ACTIONS(946), 1,
      anon_sym_geometry,
    STATE(655), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(944), 2,
      sym_player,
      sym_self,
  [4592] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(948), 1,
      anon_sym_entity,
    ACTIONS(952), 1,
      anon_sym_geometry,
    STATE(324), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(950), 2,
      sym_player,
      sym_self,
  [4613] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(954), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(956), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [4628] = 6,
    ACTIONS(934), 1,
      anon_sym_entity,
    ACTIONS(936), 1,
      anon_sym_map,
    ACTIONS(958), 1,
      anon_sym_RBRACK,
    STATE(744), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(938), 2,
      sym_player,
      sym_self,
  [4649] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(960), 1,
      anon_sym_entity,
    ACTIONS(964), 1,
      anon_sym_geometry,
    STATE(557), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(962), 2,
      sym_player,
      sym_self,
  [4670] = 6,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    ACTIONS(966), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4691] = 6,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    ACTIONS(968), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4712] = 6,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    ACTIONS(970), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4733] = 6,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    ACTIONS(972), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4754] = 6,
    ACTIONS(914), 1,
      anon_sym_LBRACK,
    ACTIONS(974), 1,
      anon_sym_entity,
    ACTIONS(978), 1,
      anon_sym_geometry,
    STATE(278), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(976), 2,
      sym_player,
      sym_self,
  [4775] = 3,
    STATE(714), 1,
      sym_entity_property_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 5,
      anon_sym_name,
      anon_sym_path,
      anon_sym_on_tick,
      anon_sym_on_look,
      anon_sym_on_interact,
  [4790] = 6,
    ACTIONS(934), 1,
      anon_sym_entity,
    ACTIONS(936), 1,
      anon_sym_map,
    ACTIONS(980), 1,
      anon_sym_RBRACK,
    STATE(744), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(938), 2,
      sym_player,
      sym_self,
  [4811] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(982), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(807), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_BANG,
      anon_sym_LPAREN,
  [4826] = 6,
    ACTIONS(936), 1,
      anon_sym_map,
    ACTIONS(984), 1,
      anon_sym_RBRACK,
    ACTIONS(986), 1,
      anon_sym_entity,
    STATE(413), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(988), 2,
      sym_player,
      sym_self,
  [4847] = 5,
    ACTIONS(924), 1,
      anon_sym_else,
    STATE(717), 1,
      sym_else_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(990), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(180), 2,
      sym_if_else_block,
      aux_sym_if_chain_repeat1,
  [4866] = 6,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    ACTIONS(992), 1,
      anon_sym_RBRACK,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [4887] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(994), 5,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      sym_fail,
  [4899] = 4,
    ACTIONS(998), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(996), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(201), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [4915] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(822), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1001), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4931] = 4,
    ACTIONS(1005), 1,
      anon_sym_else,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1003), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    STATE(203), 2,
      sym_if_else_block,
      aux_sym_if_chain_repeat1,
  [4947] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(679), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1008), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4963] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1010), 5,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [4975] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1012), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(1014), 3,
      sym_CONSTANT,
      anon_sym_BANG,
      anon_sym_LPAREN,
  [4989] = 5,
    ACTIONS(908), 1,
      anon_sym_entity,
    ACTIONS(912), 1,
      anon_sym_camera,
    STATE(721), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_player,
      sym_self,
  [5007] = 6,
    ACTIONS(1016), 1,
      anon_sym_RBRACE,
    ACTIONS(1018), 1,
      anon_sym_default,
    ACTIONS(1020), 1,
      anon_sym_label,
    ACTIONS(1022), 1,
      anon_sym_entity,
    STATE(261), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5027] = 4,
    ACTIONS(1026), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1024), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(209), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [5043] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1029), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(1031), 3,
      sym_CONSTANT,
      anon_sym_BANG,
      anon_sym_LPAREN,
  [5057] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1033), 5,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [5069] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1035), 5,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      sym_fail,
  [5081] = 4,
    ACTIONS(1037), 1,
      sym_QUOTED_STRING,
    STATE(213), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1040), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [5097] = 6,
    ACTIONS(1018), 1,
      anon_sym_default,
    ACTIONS(1020), 1,
      anon_sym_label,
    ACTIONS(1022), 1,
      anon_sym_entity,
    ACTIONS(1042), 1,
      anon_sym_RBRACE,
    STATE(208), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5117] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1044), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5129] = 4,
    ACTIONS(833), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1046), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(201), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [5145] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(807), 5,
      anon_sym_LBRACK,
      anon_sym_entity,
      sym_player,
      sym_self,
      anon_sym_geometry,
  [5157] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(426), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1048), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5173] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(548), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1050), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5189] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1052), 5,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      sym_fail,
  [5201] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(690), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1054), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5217] = 5,
    ACTIONS(735), 1,
      sym_QUOTED_STRING,
    ACTIONS(817), 1,
      anon_sym_wrap,
    STATE(167), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(209), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [5235] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(675), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1056), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5251] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1058), 5,
      sym_BAREWORD,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [5263] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1060), 5,
      sym_BAREWORD,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_LPAREN,
      anon_sym_DASH,
  [5275] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1062), 5,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [5287] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1064), 5,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      sym_fail,
  [5299] = 4,
    ACTIONS(833), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1066), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(201), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [5315] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1068), 5,
      anon_sym_LBRACK,
      anon_sym_entity,
      sym_player,
      sym_self,
      anon_sym_geometry,
  [5327] = 5,
    ACTIONS(934), 1,
      anon_sym_entity,
    ACTIONS(936), 1,
      anon_sym_map,
    STATE(744), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(938), 2,
      sym_player,
      sym_self,
  [5345] = 5,
    ACTIONS(1070), 1,
      anon_sym_RBRACK,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5363] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1078), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1080), 5,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [5387] = 5,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(1082), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5405] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1084), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5417] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1086), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5429] = 5,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(1088), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5447] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1090), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5459] = 5,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(1092), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5477] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1094), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5489] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1098), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(1096), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [5503] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1100), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5515] = 5,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(1102), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5533] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1104), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5545] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1106), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5557] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1108), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5569] = 5,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(1110), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [5587] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1112), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5599] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1114), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5611] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1116), 5,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_over,
      sym_forever,
  [5623] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(398), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1118), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5639] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(593), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1120), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5655] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(603), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1122), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5671] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(609), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1124), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5687] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(852), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1126), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5703] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(592), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1128), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5719] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(681), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1130), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5735] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(692), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1132), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5751] = 4,
    ACTIONS(1134), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 2,
      anon_sym_in,
      anon_sym_out,
    STATE(866), 2,
      sym_in_or_out,
      sym_in_or_out_expansion,
  [5767] = 4,
    ACTIONS(862), 1,
      anon_sym_LBRACK,
    STATE(761), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1138), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5783] = 6,
    ACTIONS(1140), 1,
      anon_sym_RBRACE,
    ACTIONS(1142), 1,
      anon_sym_default,
    ACTIONS(1145), 1,
      anon_sym_label,
    ACTIONS(1148), 1,
      anon_sym_entity,
    STATE(261), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5803] = 5,
    ACTIONS(1151), 1,
      anon_sym_RBRACK,
    ACTIONS(1153), 1,
      anon_sym_entity,
    ACTIONS(1157), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1155), 2,
      sym_player,
      sym_self,
  [5821] = 4,
    ACTIONS(1159), 1,
      anon_sym_LBRACK,
    STATE(559), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1161), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5836] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1163), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [5847] = 5,
    ACTIONS(1165), 1,
      anon_sym_EQ,
    ACTIONS(1167), 1,
      anon_sym_DASH_GT,
    STATE(179), 1,
      sym_over_time_operator,
    STATE(184), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5864] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1169), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [5875] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1171), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [5886] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1173), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5897] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(283), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1177), 2,
      sym_DURATION,
      sym_CONSTANT,
  [5912] = 4,
    ACTIONS(1179), 1,
      anon_sym_LBRACK,
    STATE(771), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1181), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5927] = 4,
    ACTIONS(1183), 1,
      anon_sym_RBRACK,
    ACTIONS(1185), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1187), 2,
      sym_player,
      sym_self,
  [5942] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1191), 1,
      anon_sym_over,
    ACTIONS(1193), 1,
      sym_forever,
    STATE(647), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5959] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(648), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1195), 2,
      sym_DURATION,
      sym_CONSTANT,
  [5974] = 5,
    ACTIONS(1197), 1,
      anon_sym_COMMA,
    ACTIONS(1199), 1,
      anon_sym_RBRACK,
    ACTIONS(1201), 1,
      anon_sym_position,
    STATE(499), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5991] = 4,
    ACTIONS(1185), 1,
      anon_sym_entity,
    ACTIONS(1203), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1187), 2,
      sym_player,
      sym_self,
  [6006] = 4,
    ACTIONS(1205), 1,
      anon_sym_LBRACK,
    STATE(783), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1207), 2,
      sym_COLOR,
      sym_CONSTANT,
  [6021] = 4,
    ACTIONS(1211), 1,
      anon_sym_LBRACE,
    STATE(537), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1209), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [6036] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1213), 1,
      anon_sym_over,
    ACTIONS(1215), 1,
      sym_forever,
    STATE(665), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6053] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1217), 1,
      anon_sym_over,
    ACTIONS(1219), 1,
      sym_forever,
    STATE(657), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6070] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(747), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1221), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6085] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1223), 1,
      anon_sym_over,
    ACTIONS(1225), 1,
      sym_forever,
    STATE(661), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6102] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1227), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6113] = 4,
    ACTIONS(1229), 1,
      anon_sym_LBRACK,
    STATE(816), 1,
      sym_distance_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1231), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [6128] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1233), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6139] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1235), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6150] = 3,
    ACTIONS(1237), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1239), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6163] = 4,
    ACTIONS(1241), 1,
      anon_sym_RBRACK,
    STATE(606), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 2,
      anon_sym_in,
      anon_sym_out,
  [6178] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(666), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1243), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6193] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(668), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1245), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6208] = 4,
    ACTIONS(1159), 1,
      anon_sym_LBRACK,
    STATE(331), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1247), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6223] = 3,
    ACTIONS(1249), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1251), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6236] = 4,
    ACTIONS(817), 1,
      anon_sym_wrap,
    ACTIONS(1253), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(329), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [6251] = 5,
    ACTIONS(1255), 1,
      anon_sym_RBRACK,
    ACTIONS(1257), 1,
      sym_BAREWORD,
    ACTIONS(1259), 1,
      sym_NUMBER,
    ACTIONS(1261), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6268] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(682), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1263), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6283] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(683), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1265), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6298] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1269), 1,
      anon_sym_RBRACK,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6315] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(1275), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6332] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(1277), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6349] = 5,
    ACTIONS(1279), 1,
      anon_sym_RBRACK,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6366] = 5,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(1287), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6383] = 5,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(1289), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6400] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1291), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [6411] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1293), 1,
      anon_sym_over,
    ACTIONS(1295), 1,
      sym_forever,
    STATE(702), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6428] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(703), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1297), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6443] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1299), 1,
      anon_sym_over,
    ACTIONS(1301), 1,
      sym_forever,
    STATE(705), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6460] = 4,
    ACTIONS(1303), 1,
      anon_sym_LBRACK,
    STATE(720), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1305), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [6475] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(710), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1307), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6490] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(711), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1309), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6505] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1311), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6516] = 4,
    ACTIONS(1313), 1,
      anon_sym_LBRACK,
    STATE(573), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1315), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [6531] = 4,
    ACTIONS(1319), 1,
      anon_sym_LBRACE,
    STATE(538), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1317), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [6546] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1321), 1,
      anon_sym_over,
    ACTIONS(1323), 1,
      sym_forever,
    STATE(598), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6563] = 5,
    ACTIONS(1325), 1,
      anon_sym_COMMA,
    ACTIONS(1327), 1,
      anon_sym_RBRACK,
    ACTIONS(1329), 1,
      anon_sym_position,
    STATE(376), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6580] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(600), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1331), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6595] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1333), 4,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [6606] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1335), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6617] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1337), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6628] = 4,
    ACTIONS(1185), 1,
      anon_sym_entity,
    ACTIONS(1339), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1187), 2,
      sym_player,
      sym_self,
  [6643] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(724), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1341), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6658] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1343), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6669] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(727), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1345), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6684] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(728), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1347), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6699] = 4,
    ACTIONS(1349), 1,
      anon_sym_RBRACK,
    STATE(606), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 2,
      anon_sym_in,
      anon_sym_out,
  [6714] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1351), 1,
      anon_sym_over,
    ACTIONS(1353), 1,
      sym_forever,
    STATE(740), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6731] = 4,
    ACTIONS(1355), 1,
      anon_sym_RBRACK,
    STATE(370), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 2,
      anon_sym_in,
      anon_sym_out,
  [6746] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(549), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1357), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6761] = 4,
    ACTIONS(1072), 1,
      anon_sym_entity,
    ACTIONS(1076), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1074), 2,
      sym_player,
      sym_self,
  [6776] = 3,
    ACTIONS(1359), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1239), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6789] = 4,
    ACTIONS(817), 1,
      anon_sym_wrap,
    ACTIONS(1361), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(209), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [6804] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1363), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6815] = 4,
    ACTIONS(1303), 1,
      anon_sym_LBRACK,
    STATE(580), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1365), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [6830] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1367), 1,
      anon_sym_over,
    ACTIONS(1369), 1,
      sym_forever,
    STATE(617), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6847] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(777), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6858] = 4,
    ACTIONS(1319), 1,
      anon_sym_LBRACE,
    STATE(581), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1371), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6873] = 4,
    ACTIONS(1211), 1,
      anon_sym_LBRACE,
    STATE(586), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1373), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6888] = 4,
    ACTIONS(1319), 1,
      anon_sym_LBRACE,
    STATE(589), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1375), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6903] = 5,
    ACTIONS(1377), 1,
      sym_BOOL,
    ACTIONS(1379), 1,
      anon_sym_RBRACK,
    ACTIONS(1381), 1,
      sym_BAREWORD,
    ACTIONS(1383), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6920] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1385), 1,
      anon_sym_over,
    ACTIONS(1387), 1,
      sym_forever,
    STATE(619), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6937] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(472), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1389), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6952] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(1391), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6969] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(1393), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6986] = 4,
    ACTIONS(1159), 1,
      anon_sym_LBRACK,
    STATE(610), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1395), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7001] = 5,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(1397), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7018] = 5,
    ACTIONS(1165), 1,
      anon_sym_EQ,
    ACTIONS(1167), 1,
      anon_sym_DASH_GT,
    STATE(181), 1,
      sym_assignmment_operator,
    STATE(185), 1,
      sym_over_time_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7035] = 5,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(1399), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7052] = 5,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(1401), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7069] = 5,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(1403), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7086] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1405), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [7097] = 5,
    ACTIONS(1189), 1,
      anon_sym_LBRACK,
    ACTIONS(1407), 1,
      anon_sym_over,
    ACTIONS(1409), 1,
      sym_forever,
    STATE(584), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7114] = 4,
    ACTIONS(1319), 1,
      anon_sym_LBRACE,
    STATE(658), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1411), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [7129] = 5,
    ACTIONS(1165), 1,
      anon_sym_EQ,
    ACTIONS(1167), 1,
      anon_sym_DASH_GT,
    STATE(188), 1,
      sym_assignmment_operator,
    STATE(193), 1,
      sym_over_time_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7146] = 4,
    ACTIONS(1185), 1,
      anon_sym_entity,
    ACTIONS(1413), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1187), 2,
      sym_player,
      sym_self,
  [7161] = 4,
    ACTIONS(1417), 1,
      anon_sym_fade,
    ACTIONS(1419), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1415), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7176] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(563), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1421), 2,
      sym_DURATION,
      sym_CONSTANT,
  [7191] = 4,
    ACTIONS(1175), 1,
      anon_sym_LBRACK,
    STATE(566), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1423), 2,
      sym_DURATION,
      sym_CONSTANT,
  [7206] = 4,
    ACTIONS(1159), 1,
      anon_sym_LBRACK,
    STATE(306), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1425), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7221] = 4,
    ACTIONS(1159), 1,
      anon_sym_LBRACK,
    STATE(574), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1427), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7236] = 3,
    STATE(281), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1429), 2,
      sym_origin,
      sym_length,
  [7248] = 3,
    ACTIONS(1431), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1433), 2,
      sym_DURATION,
      sym_CONSTANT,
  [7260] = 4,
    ACTIONS(1431), 1,
      anon_sym_RBRACK,
    ACTIONS(1435), 1,
      anon_sym_COMMA,
    STATE(418), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7274] = 4,
    ACTIONS(619), 1,
      anon_sym_RBRACK,
    ACTIONS(1437), 1,
      anon_sym_COMMA,
    STATE(420), 1,
      aux_sym_entity_property_int_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7288] = 4,
    ACTIONS(813), 1,
      anon_sym_RBRACK,
    ACTIONS(1439), 1,
      anon_sym_COMMA,
    STATE(422), 1,
      aux_sym_entity_property_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7302] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1441), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7312] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1443), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7322] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1445), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7332] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1447), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7342] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1449), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7352] = 4,
    ACTIONS(1451), 1,
      anon_sym_COMMA,
    ACTIONS(1453), 1,
      anon_sym_RBRACK,
    STATE(425), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7366] = 4,
    ACTIONS(1455), 1,
      anon_sym_COMMA,
    ACTIONS(1457), 1,
      anon_sym_RBRACK,
    STATE(428), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7380] = 4,
    ACTIONS(1459), 1,
      anon_sym_COMMA,
    ACTIONS(1461), 1,
      anon_sym_RBRACK,
    STATE(429), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7394] = 3,
    ACTIONS(1463), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1465), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [7406] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1467), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [7416] = 4,
    ACTIONS(1463), 1,
      anon_sym_RBRACK,
    ACTIONS(1469), 1,
      anon_sym_COMMA,
    STATE(494), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7430] = 4,
    ACTIONS(1471), 1,
      anon_sym_COMMA,
    ACTIONS(1474), 1,
      anon_sym_RBRACK,
    STATE(374), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7444] = 4,
    ACTIONS(968), 1,
      anon_sym_RBRACK,
    ACTIONS(1476), 1,
      anon_sym_COMMA,
    STATE(516), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7458] = 4,
    ACTIONS(1478), 1,
      anon_sym_COMMA,
    ACTIONS(1480), 1,
      anon_sym_RBRACK,
    STATE(518), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7472] = 4,
    ACTIONS(1482), 1,
      anon_sym_COMMA,
    ACTIONS(1484), 1,
      anon_sym_RBRACK,
    STATE(373), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7486] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1486), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7496] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1488), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7506] = 3,
    STATE(338), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1490), 2,
      sym_origin,
      sym_length,
  [7518] = 4,
    ACTIONS(1492), 1,
      anon_sym_RBRACK,
    ACTIONS(1494), 1,
      anon_sym_over,
    ACTIONS(1496), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7532] = 3,
    STATE(551), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1498), 2,
      sym_origin,
      sym_length,
  [7544] = 4,
    ACTIONS(1500), 1,
      anon_sym_COMMA,
    ACTIONS(1502), 1,
      anon_sym_RBRACK,
    STATE(439), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7558] = 4,
    ACTIONS(1504), 1,
      anon_sym_COMMA,
    ACTIONS(1506), 1,
      anon_sym_RBRACK,
    STATE(441), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7572] = 4,
    ACTIONS(1508), 1,
      anon_sym_COMMA,
    ACTIONS(1510), 1,
      anon_sym_RBRACK,
    STATE(442), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7586] = 4,
    ACTIONS(1512), 1,
      anon_sym_COMMA,
    ACTIONS(1514), 1,
      anon_sym_RBRACK,
    STATE(522), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7600] = 4,
    ACTIONS(1516), 1,
      anon_sym_COMMA,
    ACTIONS(1518), 1,
      anon_sym_RBRACK,
    STATE(443), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7614] = 4,
    ACTIONS(1520), 1,
      anon_sym_COMMA,
    ACTIONS(1522), 1,
      anon_sym_RBRACK,
    STATE(445), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7628] = 4,
    ACTIONS(1524), 1,
      anon_sym_COMMA,
    ACTIONS(1526), 1,
      anon_sym_RBRACK,
    STATE(446), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7642] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1528), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7652] = 4,
    ACTIONS(1530), 1,
      sym_QUOTED_STRING,
    ACTIONS(1532), 1,
      anon_sym_RBRACE,
    STATE(525), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7666] = 4,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    ACTIONS(1536), 1,
      anon_sym_RBRACK,
    STATE(528), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7680] = 4,
    ACTIONS(1538), 1,
      anon_sym_COMMA,
    ACTIONS(1540), 1,
      anon_sym_RBRACK,
    STATE(386), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7694] = 4,
    ACTIONS(1542), 1,
      anon_sym_COMMA,
    ACTIONS(1545), 1,
      anon_sym_RBRACK,
    STATE(394), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7708] = 3,
    ACTIONS(1547), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1549), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7720] = 4,
    ACTIONS(1551), 1,
      anon_sym_COMMA,
    ACTIONS(1553), 1,
      anon_sym_RBRACK,
    STATE(535), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7734] = 3,
    ACTIONS(1555), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(789), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [7746] = 3,
    ACTIONS(1559), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1557), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [7758] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1561), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [7768] = 4,
    ACTIONS(1563), 1,
      anon_sym_COMMA,
    ACTIONS(1565), 1,
      anon_sym_RBRACK,
    STATE(522), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7782] = 4,
    ACTIONS(1567), 1,
      anon_sym_COMMA,
    ACTIONS(1569), 1,
      anon_sym_RBRACK,
    STATE(360), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7796] = 3,
    ACTIONS(1185), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1187), 2,
      sym_player,
      sym_self,
  [7808] = 4,
    ACTIONS(1571), 1,
      anon_sym_COMMA,
    ACTIONS(1573), 1,
      anon_sym_RBRACK,
    STATE(361), 1,
      aux_sym_entity_property_int_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7822] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1575), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7832] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1577), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7842] = 4,
    ACTIONS(1579), 1,
      anon_sym_COMMA,
    ACTIONS(1581), 1,
      anon_sym_RBRACK,
    STATE(362), 1,
      aux_sym_entity_property_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7856] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1583), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7866] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1585), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7876] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1587), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [7886] = 4,
    ACTIONS(1589), 1,
      anon_sym_COMMA,
    ACTIONS(1591), 1,
      anon_sym_RBRACE,
    STATE(536), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7900] = 4,
    ACTIONS(1593), 1,
      anon_sym_COMMA,
    ACTIONS(1596), 1,
      anon_sym_RBRACK,
    STATE(411), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7914] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1598), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7924] = 4,
    ACTIONS(1600), 1,
      anon_sym_COMMA,
    ACTIONS(1602), 1,
      anon_sym_RBRACK,
    STATE(369), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7938] = 3,
    ACTIONS(1604), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1606), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7950] = 4,
    ACTIONS(1604), 1,
      anon_sym_RBRACK,
    ACTIONS(1608), 1,
      anon_sym_COMMA,
    STATE(456), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7964] = 4,
    ACTIONS(1610), 1,
      anon_sym_COMMA,
    ACTIONS(1613), 1,
      anon_sym_RBRACK,
    STATE(416), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7978] = 3,
    ACTIONS(1615), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1433), 2,
      sym_DURATION,
      sym_CONSTANT,
  [7990] = 4,
    ACTIONS(1617), 1,
      anon_sym_COMMA,
    ACTIONS(1620), 1,
      anon_sym_RBRACK,
    STATE(418), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8004] = 4,
    ACTIONS(1622), 1,
      anon_sym_COMMA,
    ACTIONS(1624), 1,
      anon_sym_RBRACK,
    STATE(531), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8018] = 4,
    ACTIONS(1626), 1,
      anon_sym_COMMA,
    ACTIONS(1629), 1,
      anon_sym_RBRACK,
    STATE(420), 1,
      aux_sym_entity_property_int_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8032] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1631), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_DASH_GT,
  [8042] = 4,
    ACTIONS(1633), 1,
      anon_sym_COMMA,
    ACTIONS(1636), 1,
      anon_sym_RBRACK,
    STATE(422), 1,
      aux_sym_entity_property_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8056] = 3,
    ACTIONS(1638), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1640), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [8068] = 3,
    STATE(602), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1642), 2,
      sym_origin,
      sym_length,
  [8080] = 4,
    ACTIONS(1644), 1,
      anon_sym_COMMA,
    ACTIONS(1646), 1,
      anon_sym_RBRACK,
    STATE(428), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8094] = 4,
    ACTIONS(1648), 1,
      anon_sym_EQ,
    ACTIONS(1650), 1,
      anon_sym_PLUS,
    ACTIONS(1652), 1,
      sym_fail,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8108] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1654), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8118] = 4,
    ACTIONS(1656), 1,
      anon_sym_COMMA,
    ACTIONS(1659), 1,
      anon_sym_RBRACK,
    STATE(428), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8132] = 4,
    ACTIONS(1349), 1,
      anon_sym_RBRACK,
    ACTIONS(1661), 1,
      anon_sym_COMMA,
    STATE(463), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8146] = 3,
    ACTIONS(1663), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1665), 2,
      sym_COLOR,
      sym_CONSTANT,
  [8158] = 3,
    ACTIONS(1667), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1669), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [8170] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1671), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_else,
  [8180] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1673), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8190] = 4,
    ACTIONS(1675), 1,
      anon_sym_COMMA,
    ACTIONS(1677), 1,
      anon_sym_RBRACK,
    STATE(470), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8204] = 3,
    STATE(471), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1679), 2,
      sym_origin,
      sym_length,
  [8216] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1681), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8226] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1683), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8236] = 4,
    ACTIONS(1685), 1,
      anon_sym_COMMA,
    ACTIONS(1687), 1,
      anon_sym_RBRACK,
    STATE(474), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8250] = 4,
    ACTIONS(1689), 1,
      anon_sym_COMMA,
    ACTIONS(1691), 1,
      anon_sym_RBRACK,
    STATE(475), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8264] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1693), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8274] = 4,
    ACTIONS(1695), 1,
      anon_sym_COMMA,
    ACTIONS(1697), 1,
      anon_sym_RBRACK,
    STATE(475), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8288] = 4,
    ACTIONS(1699), 1,
      anon_sym_COMMA,
    ACTIONS(1701), 1,
      anon_sym_RBRACK,
    STATE(475), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8302] = 4,
    ACTIONS(1703), 1,
      anon_sym_COMMA,
    ACTIONS(1705), 1,
      anon_sym_RBRACK,
    STATE(476), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8316] = 3,
    ACTIONS(1707), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1709), 2,
      sym_DURATION,
      sym_CONSTANT,
  [8328] = 4,
    ACTIONS(1711), 1,
      anon_sym_COMMA,
    ACTIONS(1713), 1,
      anon_sym_RBRACK,
    STATE(476), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8342] = 4,
    ACTIONS(1715), 1,
      anon_sym_COMMA,
    ACTIONS(1717), 1,
      anon_sym_RBRACK,
    STATE(476), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8356] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1719), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8366] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1721), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_EQ,
  [8376] = 3,
    ACTIONS(1723), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1725), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1727), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_EQ,
  [8398] = 3,
    STATE(305), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1729), 2,
      sym_origin,
      sym_length,
  [8410] = 3,
    STATE(650), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1731), 2,
      sym_origin,
      sym_length,
  [8422] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1733), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [8432] = 4,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    ACTIONS(1735), 1,
      anon_sym_RBRACK,
    STATE(411), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8446] = 3,
    ACTIONS(1737), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1606), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [8458] = 4,
    ACTIONS(1739), 1,
      anon_sym_COMMA,
    ACTIONS(1742), 1,
      anon_sym_RBRACK,
    STATE(456), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8472] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1239), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8482] = 4,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    ACTIONS(1744), 1,
      anon_sym_COMMA,
    STATE(394), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8496] = 4,
    ACTIONS(1746), 1,
      anon_sym_COMMA,
    ACTIONS(1748), 1,
      anon_sym_RBRACK,
    STATE(485), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8510] = 3,
    ACTIONS(1750), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1752), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8522] = 4,
    ACTIONS(1754), 1,
      anon_sym_COMMA,
    ACTIONS(1757), 1,
      anon_sym_RBRACK,
    STATE(461), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8536] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1759), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8546] = 4,
    ACTIONS(1761), 1,
      anon_sym_COMMA,
    ACTIONS(1764), 1,
      anon_sym_RBRACK,
    STATE(463), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8560] = 4,
    ACTIONS(1766), 1,
      anon_sym_COMMA,
    ACTIONS(1768), 1,
      anon_sym_RBRACK,
    STATE(488), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8574] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1770), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8584] = 4,
    ACTIONS(1772), 1,
      anon_sym_COMMA,
    ACTIONS(1774), 1,
      anon_sym_RBRACK,
    STATE(490), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8598] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1776), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8608] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1778), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [8618] = 4,
    ACTIONS(1780), 1,
      anon_sym_COMMA,
    ACTIONS(1782), 1,
      anon_sym_RBRACK,
    STATE(493), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8632] = 4,
    ACTIONS(1784), 1,
      anon_sym_COMMA,
    ACTIONS(1786), 1,
      anon_sym_RBRACK,
    STATE(497), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8646] = 4,
    ACTIONS(1788), 1,
      anon_sym_COMMA,
    ACTIONS(1790), 1,
      anon_sym_RBRACK,
    STATE(500), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8660] = 4,
    ACTIONS(1792), 1,
      anon_sym_COMMA,
    ACTIONS(1794), 1,
      anon_sym_RBRACK,
    STATE(502), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8674] = 4,
    ACTIONS(1796), 1,
      anon_sym_RBRACK,
    ACTIONS(1798), 1,
      anon_sym_over,
    ACTIONS(1800), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8688] = 4,
    ACTIONS(1802), 1,
      anon_sym_COMMA,
    ACTIONS(1804), 1,
      anon_sym_RBRACK,
    STATE(504), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8702] = 4,
    ACTIONS(1806), 1,
      anon_sym_COMMA,
    ACTIONS(1809), 1,
      anon_sym_RBRACK,
    STATE(475), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8716] = 4,
    ACTIONS(1811), 1,
      anon_sym_COMMA,
    ACTIONS(1814), 1,
      anon_sym_RBRACK,
    STATE(476), 1,
      aux_sym_int_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8730] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1816), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8740] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1818), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8750] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1820), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [8760] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1822), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8770] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1824), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8780] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1826), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8790] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1828), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8800] = 3,
    ACTIONS(1830), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1832), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [8812] = 4,
    ACTIONS(1830), 1,
      anon_sym_RBRACK,
    ACTIONS(1834), 1,
      anon_sym_COMMA,
    STATE(511), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8826] = 3,
    STATE(606), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 2,
      anon_sym_in,
      anon_sym_out,
  [8838] = 3,
    ACTIONS(1836), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1838), 2,
      sym_COLOR,
      sym_CONSTANT,
  [8850] = 4,
    ACTIONS(1836), 1,
      anon_sym_RBRACK,
    ACTIONS(1840), 1,
      anon_sym_COMMA,
    STATE(513), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8864] = 3,
    ACTIONS(1842), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1844), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [8876] = 4,
    ACTIONS(1842), 1,
      anon_sym_RBRACK,
    ACTIONS(1846), 1,
      anon_sym_COMMA,
    STATE(515), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8890] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1848), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [8900] = 3,
    ACTIONS(1850), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1465), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [8912] = 4,
    ACTIONS(1852), 1,
      anon_sym_COMMA,
    ACTIONS(1854), 1,
      anon_sym_RBRACK,
    STATE(497), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8926] = 4,
    ACTIONS(1856), 1,
      anon_sym_COMMA,
    ACTIONS(1859), 1,
      anon_sym_RBRACK,
    STATE(494), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8940] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1861), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8950] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1863), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [8960] = 4,
    ACTIONS(1865), 1,
      anon_sym_COMMA,
    ACTIONS(1868), 1,
      anon_sym_RBRACK,
    STATE(497), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8974] = 4,
    ACTIONS(1870), 1,
      anon_sym_COMMA,
    ACTIONS(1872), 1,
      anon_sym_RBRACK,
    STATE(400), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8988] = 4,
    ACTIONS(1874), 1,
      anon_sym_COMMA,
    ACTIONS(1876), 1,
      anon_sym_RBRACK,
    STATE(518), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9002] = 4,
    ACTIONS(1878), 1,
      anon_sym_COMMA,
    ACTIONS(1880), 1,
      anon_sym_RBRACK,
    STATE(497), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9016] = 4,
    ACTIONS(1798), 1,
      anon_sym_over,
    ACTIONS(1800), 1,
      sym_forever,
    ACTIONS(1882), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9030] = 4,
    ACTIONS(1884), 1,
      anon_sym_COMMA,
    ACTIONS(1886), 1,
      anon_sym_RBRACK,
    STATE(504), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9044] = 4,
    ACTIONS(1798), 1,
      anon_sym_over,
    ACTIONS(1800), 1,
      sym_forever,
    ACTIONS(1888), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9058] = 4,
    ACTIONS(1890), 1,
      anon_sym_COMMA,
    ACTIONS(1893), 1,
      anon_sym_RBRACK,
    STATE(504), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9072] = 4,
    ACTIONS(1267), 1,
      sym_BOOL,
    ACTIONS(1271), 1,
      sym_BAREWORD,
    ACTIONS(1273), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9086] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1895), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_else,
  [9096] = 4,
    ACTIONS(1281), 1,
      sym_BAREWORD,
    ACTIONS(1283), 1,
      sym_NUMBER,
    ACTIONS(1285), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9110] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1897), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [9120] = 4,
    ACTIONS(1899), 1,
      anon_sym_LBRACE,
    ACTIONS(1901), 1,
      anon_sym_if,
    STATE(569), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9134] = 3,
    ACTIONS(1903), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1832), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [9146] = 4,
    ACTIONS(1905), 1,
      anon_sym_COMMA,
    ACTIONS(1908), 1,
      anon_sym_RBRACK,
    STATE(511), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9160] = 3,
    ACTIONS(1910), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1838), 2,
      sym_COLOR,
      sym_CONSTANT,
  [9172] = 4,
    ACTIONS(1912), 1,
      anon_sym_COMMA,
    ACTIONS(1915), 1,
      anon_sym_RBRACK,
    STATE(513), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9186] = 3,
    ACTIONS(1917), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1844), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [9198] = 4,
    ACTIONS(1919), 1,
      anon_sym_COMMA,
    ACTIONS(1922), 1,
      anon_sym_RBRACK,
    STATE(515), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9212] = 4,
    ACTIONS(1924), 1,
      anon_sym_COMMA,
    ACTIONS(1926), 1,
      anon_sym_RBRACK,
    STATE(522), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9226] = 3,
    STATE(736), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1928), 2,
      sym_origin,
      sym_length,
  [9238] = 4,
    ACTIONS(1930), 1,
      anon_sym_COMMA,
    ACTIONS(1933), 1,
      anon_sym_RBRACK,
    STATE(518), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9252] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1935), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [9262] = 4,
    ACTIONS(1798), 1,
      anon_sym_over,
    ACTIONS(1800), 1,
      sym_forever,
    ACTIONS(1937), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9276] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(559), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_else,
  [9286] = 4,
    ACTIONS(1939), 1,
      anon_sym_COMMA,
    ACTIONS(1942), 1,
      anon_sym_RBRACK,
    STATE(522), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9300] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(492), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_else,
  [9310] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1944), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [9320] = 4,
    ACTIONS(1589), 1,
      anon_sym_COMMA,
    ACTIONS(1946), 1,
      anon_sym_RBRACE,
    STATE(410), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9334] = 4,
    ACTIONS(1948), 1,
      anon_sym_COMMA,
    ACTIONS(1950), 1,
      anon_sym_RBRACK,
    STATE(530), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9348] = 4,
    ACTIONS(1952), 1,
      anon_sym_COMMA,
    ACTIONS(1954), 1,
      anon_sym_RBRACK,
    STATE(458), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9362] = 4,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    ACTIONS(1956), 1,
      anon_sym_RBRACK,
    STATE(411), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9376] = 3,
    ACTIONS(1958), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1752), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [9388] = 4,
    ACTIONS(1958), 1,
      anon_sym_RBRACK,
    ACTIONS(1960), 1,
      anon_sym_COMMA,
    STATE(461), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9402] = 4,
    ACTIONS(1962), 1,
      anon_sym_COMMA,
    ACTIONS(1964), 1,
      anon_sym_RBRACK,
    STATE(374), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9416] = 4,
    ACTIONS(1966), 1,
      anon_sym_COMMA,
    ACTIONS(1968), 1,
      anon_sym_RBRACK,
    STATE(415), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9430] = 4,
    ACTIONS(1534), 1,
      anon_sym_COMMA,
    ACTIONS(1970), 1,
      anon_sym_RBRACK,
    STATE(454), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9444] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1972), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [9454] = 4,
    ACTIONS(1359), 1,
      anon_sym_RBRACK,
    ACTIONS(1974), 1,
      anon_sym_COMMA,
    STATE(416), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9468] = 4,
    ACTIONS(1976), 1,
      anon_sym_COMMA,
    ACTIONS(1979), 1,
      anon_sym_RBRACE,
    STATE(536), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9482] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1981), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9491] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1983), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9500] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1415), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [9509] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1545), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [9518] = 3,
    ACTIONS(1985), 1,
      anon_sym_RBRACK,
    ACTIONS(1987), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9529] = 3,
    ACTIONS(1989), 1,
      anon_sym_RBRACK,
    ACTIONS(1991), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9540] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1993), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9549] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1995), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [9558] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1752), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [9567] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1997), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9576] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1999), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9585] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2001), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9594] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2003), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9603] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2005), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9612] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2007), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9621] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2009), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9630] = 3,
    ACTIONS(484), 1,
      anon_sym_LBRACK,
    STATE(45), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9641] = 3,
    ACTIONS(2011), 1,
      anon_sym_LBRACE,
    STATE(266), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9652] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2013), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9661] = 3,
    ACTIONS(2011), 1,
      anon_sym_LBRACE,
    STATE(267), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9672] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2015), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9681] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2017), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9690] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2019), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9699] = 3,
    ACTIONS(2021), 1,
      anon_sym_serial_dialog,
    ACTIONS(2023), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9710] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2025), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9719] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2027), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9728] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2029), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9737] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2031), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9746] = 3,
    ACTIONS(2033), 1,
      anon_sym_LBRACE,
    STATE(432), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9757] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2035), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9766] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2037), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9775] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2039), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9784] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2041), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9793] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2043), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9802] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2045), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9811] = 3,
    ACTIONS(2047), 1,
      anon_sym_serial_dialog,
    ACTIONS(2049), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9822] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2051), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9831] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2053), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9840] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2055), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [9849] = 3,
    ACTIONS(2057), 1,
      anon_sym_map,
    ACTIONS(2059), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9860] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2061), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [9869] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2063), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [9878] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2065), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [9887] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2067), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9896] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2069), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9905] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2071), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9914] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2073), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9923] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2075), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9932] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2077), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9941] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2079), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9950] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2081), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [9959] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1979), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [9968] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2083), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [9977] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1742), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [9986] = 3,
    ACTIONS(2085), 1,
      anon_sym_LBRACE,
    STATE(543), 1,
      sym_looping_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9997] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2087), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10006] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2089), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10015] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1433), 2,
      sym_DURATION,
      sym_CONSTANT,
  [10024] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2091), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10033] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1757), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10042] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2093), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10051] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2095), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10060] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1465), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [10069] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2097), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10078] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2099), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10087] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2101), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10096] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2103), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10105] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2105), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10114] = 3,
    ACTIONS(2011), 1,
      anon_sym_LBRACE,
    STATE(348), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10125] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1764), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10134] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2107), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [10143] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2109), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10152] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2111), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10161] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2113), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10170] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2115), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10179] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2117), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10188] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2119), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10197] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2121), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10206] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2123), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10215] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2125), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10224] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2127), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10233] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2129), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10242] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2131), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10251] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2133), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10260] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2135), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10269] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2137), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10278] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2139), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10287] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2141), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10296] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2143), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10305] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2145), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10314] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2147), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10323] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2149), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10332] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2151), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10341] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2153), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10350] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2155), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10359] = 3,
    ACTIONS(2033), 1,
      anon_sym_LBRACE,
    STATE(506), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10370] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2157), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10379] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2159), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2161), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10397] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2163), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10406] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2165), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10415] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2167), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10424] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2169), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [10433] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2171), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10442] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2173), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10451] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2175), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10460] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2177), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [10469] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2179), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10478] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2181), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [10487] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2183), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10496] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2185), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10505] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2187), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10514] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2189), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10523] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2191), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10532] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2193), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [10541] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1606), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [10550] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2195), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10559] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2197), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10568] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2199), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10577] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2201), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10586] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2203), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10595] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2205), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10604] = 3,
    ACTIONS(1319), 1,
      anon_sym_LBRACE,
    STATE(119), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10615] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2207), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10624] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2209), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10633] = 3,
    ACTIONS(1211), 1,
      anon_sym_LBRACE,
    STATE(120), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10644] = 3,
    ACTIONS(1899), 1,
      anon_sym_LBRACE,
    STATE(127), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10655] = 3,
    ACTIONS(1530), 1,
      sym_QUOTED_STRING,
    STATE(588), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10666] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2211), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10675] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2213), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10684] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1596), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10693] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2215), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10702] = 3,
    ACTIONS(1899), 1,
      anon_sym_LBRACE,
    STATE(121), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10713] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2217), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10722] = 3,
    ACTIONS(2219), 1,
      anon_sym_serial_dialog,
    ACTIONS(2221), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10733] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1859), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10742] = 3,
    ACTIONS(2223), 1,
      anon_sym_EQ,
    ACTIONS(2225), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10753] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2227), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10762] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2229), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10771] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2231), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10780] = 3,
    ACTIONS(2233), 1,
      anon_sym_EQ,
    STATE(81), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10791] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2235), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [10800] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2237), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10809] = 3,
    ACTIONS(2239), 1,
      anon_sym_command,
    ACTIONS(2241), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10820] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2243), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10829] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2245), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10838] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2247), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10847] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1613), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10856] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2249), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10865] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2251), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10874] = 3,
    ACTIONS(2253), 1,
      anon_sym_EQ,
    STATE(76), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [10885] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2255), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10894] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2257), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10903] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2259), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10912] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2261), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10921] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2263), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10930] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2265), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10939] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2267), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10948] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1620), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [10957] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2269), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10966] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2271), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10975] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2273), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10984] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2275), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [10993] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2277), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11002] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2279), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11011] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2281), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11020] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2283), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11029] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2285), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11038] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2287), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11047] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2289), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11056] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1908), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11065] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1629), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11074] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1474), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11083] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2291), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11092] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2293), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11101] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1915), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11110] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1922), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11119] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1636), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11128] = 3,
    ACTIONS(2085), 1,
      anon_sym_LBRACE,
    STATE(733), 1,
      sym_looping_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11139] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2295), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [11148] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(922), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11157] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2297), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11166] = 3,
    ACTIONS(2253), 1,
      anon_sym_EQ,
    STATE(256), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11177] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2299), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11186] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2301), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11195] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2303), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11204] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2305), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11213] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2307), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11222] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2309), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11231] = 3,
    ACTIONS(1798), 1,
      anon_sym_over,
    ACTIONS(1800), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11242] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2311), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11251] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2313), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11260] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2315), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11269] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1832), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [11278] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1838), 2,
      sym_COLOR,
      sym_CONSTANT,
  [11287] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1844), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [11296] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2317), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11305] = 3,
    ACTIONS(1964), 1,
      anon_sym_RBRACK,
    ACTIONS(1991), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11316] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2319), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11325] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2321), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11334] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2323), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [11343] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2325), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11352] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2327), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11361] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2329), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11370] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2331), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11379] = 3,
    ACTIONS(2223), 1,
      anon_sym_EQ,
    ACTIONS(2333), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11390] = 3,
    ACTIONS(2335), 1,
      anon_sym_LBRACK,
    STATE(26), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11401] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2337), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [11410] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2339), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [11419] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2341), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11428] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(2343), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [11437] = 2,
    ACTIONS(2345), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11445] = 2,
    ACTIONS(2347), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11453] = 2,
    ACTIONS(2349), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11461] = 2,
    ACTIONS(2351), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11469] = 2,
    ACTIONS(2353), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11477] = 2,
    ACTIONS(2355), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11485] = 2,
    ACTIONS(2357), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11493] = 2,
    ACTIONS(2359), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11501] = 2,
    ACTIONS(2361), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11509] = 2,
    ACTIONS(2363), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11517] = 2,
    ACTIONS(2365), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11525] = 2,
    ACTIONS(2367), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11533] = 2,
    ACTIONS(2369), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11541] = 2,
    ACTIONS(2371), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11549] = 2,
    ACTIONS(2373), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11557] = 2,
    ACTIONS(2375), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11565] = 2,
    ACTIONS(2377), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11573] = 2,
    ACTIONS(2379), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11581] = 2,
    ACTIONS(2381), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11589] = 2,
    ACTIONS(2383), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11597] = 2,
    ACTIONS(2385), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11605] = 2,
    ACTIONS(2387), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11613] = 2,
    ACTIONS(1901), 1,
      anon_sym_if,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11621] = 2,
    ACTIONS(2389), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11629] = 2,
    ACTIONS(2391), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11637] = 2,
    ACTIONS(2393), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11645] = 2,
    ACTIONS(2395), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11653] = 2,
    ACTIONS(2397), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11661] = 2,
    ACTIONS(2399), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11669] = 2,
    ACTIONS(2401), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11677] = 2,
    ACTIONS(2403), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11685] = 2,
    ACTIONS(2405), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11693] = 2,
    ACTIONS(2407), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11701] = 2,
    ACTIONS(2409), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11709] = 2,
    ACTIONS(2411), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11717] = 2,
    ACTIONS(2413), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11725] = 2,
    ACTIONS(2415), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11733] = 2,
    ACTIONS(2417), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11741] = 2,
    ACTIONS(2419), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11749] = 2,
    ACTIONS(2421), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11757] = 2,
    ACTIONS(2423), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11765] = 2,
    ACTIONS(2425), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11773] = 2,
    ACTIONS(2427), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11781] = 2,
    ACTIONS(2429), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11789] = 2,
    ACTIONS(2431), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11797] = 2,
    ACTIONS(2433), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11805] = 2,
    ACTIONS(1991), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11813] = 2,
    ACTIONS(2435), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11821] = 2,
    ACTIONS(2437), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11829] = 2,
    ACTIONS(2439), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11837] = 2,
    ACTIONS(2441), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11845] = 2,
    ACTIONS(2443), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11853] = 2,
    ACTIONS(2445), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11861] = 2,
    ACTIONS(2223), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11869] = 2,
    ACTIONS(2447), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11877] = 2,
    ACTIONS(2449), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11885] = 2,
    ACTIONS(2451), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11893] = 2,
    ACTIONS(2453), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11901] = 2,
    ACTIONS(2455), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11909] = 2,
    ACTIONS(2457), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11917] = 2,
    ACTIONS(2459), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11925] = 2,
    ACTIONS(2461), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11933] = 2,
    ACTIONS(2463), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11941] = 2,
    ACTIONS(2465), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11949] = 2,
    ACTIONS(2467), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11957] = 2,
    ACTIONS(2469), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11965] = 2,
    ACTIONS(2471), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11973] = 2,
    ACTIONS(2473), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11981] = 2,
    ACTIONS(2475), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11989] = 2,
    ACTIONS(2477), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [11997] = 2,
    ACTIONS(2479), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12005] = 2,
    ACTIONS(2481), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12013] = 2,
    ACTIONS(2483), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12021] = 2,
    ACTIONS(2485), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12029] = 2,
    ACTIONS(2487), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12037] = 2,
    ACTIONS(2489), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12045] = 2,
    ACTIONS(2491), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12053] = 2,
    ACTIONS(2493), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12061] = 2,
    ACTIONS(2495), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12069] = 2,
    ACTIONS(2497), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12077] = 2,
    ACTIONS(2499), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12085] = 2,
    ACTIONS(2501), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12093] = 2,
    ACTIONS(2503), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12101] = 2,
    ACTIONS(2505), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12109] = 2,
    ACTIONS(2507), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12117] = 2,
    ACTIONS(2509), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12125] = 2,
    ACTIONS(2511), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12133] = 2,
    ACTIONS(2513), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12141] = 2,
    ACTIONS(2515), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12149] = 2,
    ACTIONS(2517), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12157] = 2,
    ACTIONS(2519), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12165] = 2,
    ACTIONS(2521), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12173] = 2,
    ACTIONS(2523), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12181] = 2,
    ACTIONS(2525), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12189] = 2,
    ACTIONS(2527), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12197] = 2,
    ACTIONS(2529), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12205] = 2,
    ACTIONS(2531), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12213] = 2,
    ACTIONS(2533), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12221] = 2,
    ACTIONS(2535), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12229] = 2,
    ACTIONS(2383), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12237] = 2,
    ACTIONS(2537), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12245] = 2,
    ACTIONS(2539), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12253] = 2,
    ACTIONS(2541), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12261] = 2,
    ACTIONS(2543), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12269] = 2,
    ACTIONS(2545), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12277] = 2,
    ACTIONS(2547), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12285] = 2,
    ACTIONS(2549), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12293] = 2,
    ACTIONS(2551), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12301] = 2,
    ACTIONS(2553), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12309] = 2,
    ACTIONS(2555), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12317] = 2,
    ACTIONS(2557), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12325] = 2,
    ACTIONS(2559), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12333] = 2,
    ACTIONS(2561), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12341] = 2,
    ACTIONS(2563), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12349] = 2,
    ACTIONS(2565), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12357] = 2,
    ACTIONS(2567), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12365] = 2,
    ACTIONS(2569), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12373] = 2,
    ACTIONS(2571), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [12381] = 2,
    ACTIONS(2573), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(20)] = 0,
  [SMALL_STATE(21)] = 56,
  [SMALL_STATE(22)] = 112,
  [SMALL_STATE(23)] = 168,
  [SMALL_STATE(24)] = 223,
  [SMALL_STATE(25)] = 278,
  [SMALL_STATE(26)] = 333,
  [SMALL_STATE(27)] = 388,
  [SMALL_STATE(28)] = 443,
  [SMALL_STATE(29)] = 498,
  [SMALL_STATE(30)] = 553,
  [SMALL_STATE(31)] = 608,
  [SMALL_STATE(32)] = 663,
  [SMALL_STATE(33)] = 718,
  [SMALL_STATE(34)] = 773,
  [SMALL_STATE(35)] = 828,
  [SMALL_STATE(36)] = 883,
  [SMALL_STATE(37)] = 938,
  [SMALL_STATE(38)] = 992,
  [SMALL_STATE(39)] = 1046,
  [SMALL_STATE(40)] = 1100,
  [SMALL_STATE(41)] = 1154,
  [SMALL_STATE(42)] = 1208,
  [SMALL_STATE(43)] = 1262,
  [SMALL_STATE(44)] = 1316,
  [SMALL_STATE(45)] = 1370,
  [SMALL_STATE(46)] = 1424,
  [SMALL_STATE(47)] = 1478,
  [SMALL_STATE(48)] = 1522,
  [SMALL_STATE(49)] = 1566,
  [SMALL_STATE(50)] = 1612,
  [SMALL_STATE(51)] = 1658,
  [SMALL_STATE(52)] = 1691,
  [SMALL_STATE(53)] = 1716,
  [SMALL_STATE(54)] = 1739,
  [SMALL_STATE(55)] = 1772,
  [SMALL_STATE(56)] = 1803,
  [SMALL_STATE(57)] = 1832,
  [SMALL_STATE(58)] = 1859,
  [SMALL_STATE(59)] = 1886,
  [SMALL_STATE(60)] = 1911,
  [SMALL_STATE(61)] = 1943,
  [SMALL_STATE(62)] = 1969,
  [SMALL_STATE(63)] = 1989,
  [SMALL_STATE(64)] = 2013,
  [SMALL_STATE(65)] = 2033,
  [SMALL_STATE(66)] = 2053,
  [SMALL_STATE(67)] = 2089,
  [SMALL_STATE(68)] = 2121,
  [SMALL_STATE(69)] = 2141,
  [SMALL_STATE(70)] = 2177,
  [SMALL_STATE(71)] = 2197,
  [SMALL_STATE(72)] = 2231,
  [SMALL_STATE(73)] = 2251,
  [SMALL_STATE(74)] = 2277,
  [SMALL_STATE(75)] = 2309,
  [SMALL_STATE(76)] = 2328,
  [SMALL_STATE(77)] = 2359,
  [SMALL_STATE(78)] = 2378,
  [SMALL_STATE(79)] = 2397,
  [SMALL_STATE(80)] = 2416,
  [SMALL_STATE(81)] = 2435,
  [SMALL_STATE(82)] = 2466,
  [SMALL_STATE(83)] = 2485,
  [SMALL_STATE(84)] = 2508,
  [SMALL_STATE(85)] = 2531,
  [SMALL_STATE(86)] = 2552,
  [SMALL_STATE(87)] = 2585,
  [SMALL_STATE(88)] = 2604,
  [SMALL_STATE(89)] = 2623,
  [SMALL_STATE(90)] = 2642,
  [SMALL_STATE(91)] = 2661,
  [SMALL_STATE(92)] = 2684,
  [SMALL_STATE(93)] = 2703,
  [SMALL_STATE(94)] = 2726,
  [SMALL_STATE(95)] = 2745,
  [SMALL_STATE(96)] = 2764,
  [SMALL_STATE(97)] = 2783,
  [SMALL_STATE(98)] = 2816,
  [SMALL_STATE(99)] = 2835,
  [SMALL_STATE(100)] = 2858,
  [SMALL_STATE(101)] = 2879,
  [SMALL_STATE(102)] = 2899,
  [SMALL_STATE(103)] = 2917,
  [SMALL_STATE(104)] = 2945,
  [SMALL_STATE(105)] = 2967,
  [SMALL_STATE(106)] = 2985,
  [SMALL_STATE(107)] = 3003,
  [SMALL_STATE(108)] = 3021,
  [SMALL_STATE(109)] = 3039,
  [SMALL_STATE(110)] = 3055,
  [SMALL_STATE(111)] = 3071,
  [SMALL_STATE(112)] = 3087,
  [SMALL_STATE(113)] = 3103,
  [SMALL_STATE(114)] = 3119,
  [SMALL_STATE(115)] = 3135,
  [SMALL_STATE(116)] = 3151,
  [SMALL_STATE(117)] = 3177,
  [SMALL_STATE(118)] = 3195,
  [SMALL_STATE(119)] = 3221,
  [SMALL_STATE(120)] = 3239,
  [SMALL_STATE(121)] = 3257,
  [SMALL_STATE(122)] = 3275,
  [SMALL_STATE(123)] = 3305,
  [SMALL_STATE(124)] = 3331,
  [SMALL_STATE(125)] = 3353,
  [SMALL_STATE(126)] = 3377,
  [SMALL_STATE(127)] = 3395,
  [SMALL_STATE(128)] = 3413,
  [SMALL_STATE(129)] = 3441,
  [SMALL_STATE(130)] = 3459,
  [SMALL_STATE(131)] = 3489,
  [SMALL_STATE(132)] = 3517,
  [SMALL_STATE(133)] = 3536,
  [SMALL_STATE(134)] = 3561,
  [SMALL_STATE(135)] = 3586,
  [SMALL_STATE(136)] = 3611,
  [SMALL_STATE(137)] = 3636,
  [SMALL_STATE(138)] = 3651,
  [SMALL_STATE(139)] = 3676,
  [SMALL_STATE(140)] = 3701,
  [SMALL_STATE(141)] = 3716,
  [SMALL_STATE(142)] = 3741,
  [SMALL_STATE(143)] = 3756,
  [SMALL_STATE(144)] = 3771,
  [SMALL_STATE(145)] = 3796,
  [SMALL_STATE(146)] = 3823,
  [SMALL_STATE(147)] = 3848,
  [SMALL_STATE(148)] = 3873,
  [SMALL_STATE(149)] = 3898,
  [SMALL_STATE(150)] = 3923,
  [SMALL_STATE(151)] = 3945,
  [SMALL_STATE(152)] = 3959,
  [SMALL_STATE(153)] = 3973,
  [SMALL_STATE(154)] = 3987,
  [SMALL_STATE(155)] = 4005,
  [SMALL_STATE(156)] = 4029,
  [SMALL_STATE(157)] = 4045,
  [SMALL_STATE(158)] = 4061,
  [SMALL_STATE(159)] = 4077,
  [SMALL_STATE(160)] = 4099,
  [SMALL_STATE(161)] = 4115,
  [SMALL_STATE(162)] = 4131,
  [SMALL_STATE(163)] = 4147,
  [SMALL_STATE(164)] = 4171,
  [SMALL_STATE(165)] = 4191,
  [SMALL_STATE(166)] = 4211,
  [SMALL_STATE(167)] = 4235,
  [SMALL_STATE(168)] = 4257,
  [SMALL_STATE(169)] = 4271,
  [SMALL_STATE(170)] = 4289,
  [SMALL_STATE(171)] = 4313,
  [SMALL_STATE(172)] = 4335,
  [SMALL_STATE(173)] = 4351,
  [SMALL_STATE(174)] = 4369,
  [SMALL_STATE(175)] = 4393,
  [SMALL_STATE(176)] = 4413,
  [SMALL_STATE(177)] = 4433,
  [SMALL_STATE(178)] = 4447,
  [SMALL_STATE(179)] = 4468,
  [SMALL_STATE(180)] = 4489,
  [SMALL_STATE(181)] = 4508,
  [SMALL_STATE(182)] = 4529,
  [SMALL_STATE(183)] = 4550,
  [SMALL_STATE(184)] = 4571,
  [SMALL_STATE(185)] = 4592,
  [SMALL_STATE(186)] = 4613,
  [SMALL_STATE(187)] = 4628,
  [SMALL_STATE(188)] = 4649,
  [SMALL_STATE(189)] = 4670,
  [SMALL_STATE(190)] = 4691,
  [SMALL_STATE(191)] = 4712,
  [SMALL_STATE(192)] = 4733,
  [SMALL_STATE(193)] = 4754,
  [SMALL_STATE(194)] = 4775,
  [SMALL_STATE(195)] = 4790,
  [SMALL_STATE(196)] = 4811,
  [SMALL_STATE(197)] = 4826,
  [SMALL_STATE(198)] = 4847,
  [SMALL_STATE(199)] = 4866,
  [SMALL_STATE(200)] = 4887,
  [SMALL_STATE(201)] = 4899,
  [SMALL_STATE(202)] = 4915,
  [SMALL_STATE(203)] = 4931,
  [SMALL_STATE(204)] = 4947,
  [SMALL_STATE(205)] = 4963,
  [SMALL_STATE(206)] = 4975,
  [SMALL_STATE(207)] = 4989,
  [SMALL_STATE(208)] = 5007,
  [SMALL_STATE(209)] = 5027,
  [SMALL_STATE(210)] = 5043,
  [SMALL_STATE(211)] = 5057,
  [SMALL_STATE(212)] = 5069,
  [SMALL_STATE(213)] = 5081,
  [SMALL_STATE(214)] = 5097,
  [SMALL_STATE(215)] = 5117,
  [SMALL_STATE(216)] = 5129,
  [SMALL_STATE(217)] = 5145,
  [SMALL_STATE(218)] = 5157,
  [SMALL_STATE(219)] = 5173,
  [SMALL_STATE(220)] = 5189,
  [SMALL_STATE(221)] = 5201,
  [SMALL_STATE(222)] = 5217,
  [SMALL_STATE(223)] = 5235,
  [SMALL_STATE(224)] = 5251,
  [SMALL_STATE(225)] = 5263,
  [SMALL_STATE(226)] = 5275,
  [SMALL_STATE(227)] = 5287,
  [SMALL_STATE(228)] = 5299,
  [SMALL_STATE(229)] = 5315,
  [SMALL_STATE(230)] = 5327,
  [SMALL_STATE(231)] = 5345,
  [SMALL_STATE(232)] = 5363,
  [SMALL_STATE(233)] = 5375,
  [SMALL_STATE(234)] = 5387,
  [SMALL_STATE(235)] = 5405,
  [SMALL_STATE(236)] = 5417,
  [SMALL_STATE(237)] = 5429,
  [SMALL_STATE(238)] = 5447,
  [SMALL_STATE(239)] = 5459,
  [SMALL_STATE(240)] = 5477,
  [SMALL_STATE(241)] = 5489,
  [SMALL_STATE(242)] = 5503,
  [SMALL_STATE(243)] = 5515,
  [SMALL_STATE(244)] = 5533,
  [SMALL_STATE(245)] = 5545,
  [SMALL_STATE(246)] = 5557,
  [SMALL_STATE(247)] = 5569,
  [SMALL_STATE(248)] = 5587,
  [SMALL_STATE(249)] = 5599,
  [SMALL_STATE(250)] = 5611,
  [SMALL_STATE(251)] = 5623,
  [SMALL_STATE(252)] = 5639,
  [SMALL_STATE(253)] = 5655,
  [SMALL_STATE(254)] = 5671,
  [SMALL_STATE(255)] = 5687,
  [SMALL_STATE(256)] = 5703,
  [SMALL_STATE(257)] = 5719,
  [SMALL_STATE(258)] = 5735,
  [SMALL_STATE(259)] = 5751,
  [SMALL_STATE(260)] = 5767,
  [SMALL_STATE(261)] = 5783,
  [SMALL_STATE(262)] = 5803,
  [SMALL_STATE(263)] = 5821,
  [SMALL_STATE(264)] = 5836,
  [SMALL_STATE(265)] = 5847,
  [SMALL_STATE(266)] = 5864,
  [SMALL_STATE(267)] = 5875,
  [SMALL_STATE(268)] = 5886,
  [SMALL_STATE(269)] = 5897,
  [SMALL_STATE(270)] = 5912,
  [SMALL_STATE(271)] = 5927,
  [SMALL_STATE(272)] = 5942,
  [SMALL_STATE(273)] = 5959,
  [SMALL_STATE(274)] = 5974,
  [SMALL_STATE(275)] = 5991,
  [SMALL_STATE(276)] = 6006,
  [SMALL_STATE(277)] = 6021,
  [SMALL_STATE(278)] = 6036,
  [SMALL_STATE(279)] = 6053,
  [SMALL_STATE(280)] = 6070,
  [SMALL_STATE(281)] = 6085,
  [SMALL_STATE(282)] = 6102,
  [SMALL_STATE(283)] = 6113,
  [SMALL_STATE(284)] = 6128,
  [SMALL_STATE(285)] = 6139,
  [SMALL_STATE(286)] = 6150,
  [SMALL_STATE(287)] = 6163,
  [SMALL_STATE(288)] = 6178,
  [SMALL_STATE(289)] = 6193,
  [SMALL_STATE(290)] = 6208,
  [SMALL_STATE(291)] = 6223,
  [SMALL_STATE(292)] = 6236,
  [SMALL_STATE(293)] = 6251,
  [SMALL_STATE(294)] = 6268,
  [SMALL_STATE(295)] = 6283,
  [SMALL_STATE(296)] = 6298,
  [SMALL_STATE(297)] = 6315,
  [SMALL_STATE(298)] = 6332,
  [SMALL_STATE(299)] = 6349,
  [SMALL_STATE(300)] = 6366,
  [SMALL_STATE(301)] = 6383,
  [SMALL_STATE(302)] = 6400,
  [SMALL_STATE(303)] = 6411,
  [SMALL_STATE(304)] = 6428,
  [SMALL_STATE(305)] = 6443,
  [SMALL_STATE(306)] = 6460,
  [SMALL_STATE(307)] = 6475,
  [SMALL_STATE(308)] = 6490,
  [SMALL_STATE(309)] = 6505,
  [SMALL_STATE(310)] = 6516,
  [SMALL_STATE(311)] = 6531,
  [SMALL_STATE(312)] = 6546,
  [SMALL_STATE(313)] = 6563,
  [SMALL_STATE(314)] = 6580,
  [SMALL_STATE(315)] = 6595,
  [SMALL_STATE(316)] = 6606,
  [SMALL_STATE(317)] = 6617,
  [SMALL_STATE(318)] = 6628,
  [SMALL_STATE(319)] = 6643,
  [SMALL_STATE(320)] = 6658,
  [SMALL_STATE(321)] = 6669,
  [SMALL_STATE(322)] = 6684,
  [SMALL_STATE(323)] = 6699,
  [SMALL_STATE(324)] = 6714,
  [SMALL_STATE(325)] = 6731,
  [SMALL_STATE(326)] = 6746,
  [SMALL_STATE(327)] = 6761,
  [SMALL_STATE(328)] = 6776,
  [SMALL_STATE(329)] = 6789,
  [SMALL_STATE(330)] = 6804,
  [SMALL_STATE(331)] = 6815,
  [SMALL_STATE(332)] = 6830,
  [SMALL_STATE(333)] = 6847,
  [SMALL_STATE(334)] = 6858,
  [SMALL_STATE(335)] = 6873,
  [SMALL_STATE(336)] = 6888,
  [SMALL_STATE(337)] = 6903,
  [SMALL_STATE(338)] = 6920,
  [SMALL_STATE(339)] = 6937,
  [SMALL_STATE(340)] = 6952,
  [SMALL_STATE(341)] = 6969,
  [SMALL_STATE(342)] = 6986,
  [SMALL_STATE(343)] = 7001,
  [SMALL_STATE(344)] = 7018,
  [SMALL_STATE(345)] = 7035,
  [SMALL_STATE(346)] = 7052,
  [SMALL_STATE(347)] = 7069,
  [SMALL_STATE(348)] = 7086,
  [SMALL_STATE(349)] = 7097,
  [SMALL_STATE(350)] = 7114,
  [SMALL_STATE(351)] = 7129,
  [SMALL_STATE(352)] = 7146,
  [SMALL_STATE(353)] = 7161,
  [SMALL_STATE(354)] = 7176,
  [SMALL_STATE(355)] = 7191,
  [SMALL_STATE(356)] = 7206,
  [SMALL_STATE(357)] = 7221,
  [SMALL_STATE(358)] = 7236,
  [SMALL_STATE(359)] = 7248,
  [SMALL_STATE(360)] = 7260,
  [SMALL_STATE(361)] = 7274,
  [SMALL_STATE(362)] = 7288,
  [SMALL_STATE(363)] = 7302,
  [SMALL_STATE(364)] = 7312,
  [SMALL_STATE(365)] = 7322,
  [SMALL_STATE(366)] = 7332,
  [SMALL_STATE(367)] = 7342,
  [SMALL_STATE(368)] = 7352,
  [SMALL_STATE(369)] = 7366,
  [SMALL_STATE(370)] = 7380,
  [SMALL_STATE(371)] = 7394,
  [SMALL_STATE(372)] = 7406,
  [SMALL_STATE(373)] = 7416,
  [SMALL_STATE(374)] = 7430,
  [SMALL_STATE(375)] = 7444,
  [SMALL_STATE(376)] = 7458,
  [SMALL_STATE(377)] = 7472,
  [SMALL_STATE(378)] = 7486,
  [SMALL_STATE(379)] = 7496,
  [SMALL_STATE(380)] = 7506,
  [SMALL_STATE(381)] = 7518,
  [SMALL_STATE(382)] = 7532,
  [SMALL_STATE(383)] = 7544,
  [SMALL_STATE(384)] = 7558,
  [SMALL_STATE(385)] = 7572,
  [SMALL_STATE(386)] = 7586,
  [SMALL_STATE(387)] = 7600,
  [SMALL_STATE(388)] = 7614,
  [SMALL_STATE(389)] = 7628,
  [SMALL_STATE(390)] = 7642,
  [SMALL_STATE(391)] = 7652,
  [SMALL_STATE(392)] = 7666,
  [SMALL_STATE(393)] = 7680,
  [SMALL_STATE(394)] = 7694,
  [SMALL_STATE(395)] = 7708,
  [SMALL_STATE(396)] = 7720,
  [SMALL_STATE(397)] = 7734,
  [SMALL_STATE(398)] = 7746,
  [SMALL_STATE(399)] = 7758,
  [SMALL_STATE(400)] = 7768,
  [SMALL_STATE(401)] = 7782,
  [SMALL_STATE(402)] = 7796,
  [SMALL_STATE(403)] = 7808,
  [SMALL_STATE(404)] = 7822,
  [SMALL_STATE(405)] = 7832,
  [SMALL_STATE(406)] = 7842,
  [SMALL_STATE(407)] = 7856,
  [SMALL_STATE(408)] = 7866,
  [SMALL_STATE(409)] = 7876,
  [SMALL_STATE(410)] = 7886,
  [SMALL_STATE(411)] = 7900,
  [SMALL_STATE(412)] = 7914,
  [SMALL_STATE(413)] = 7924,
  [SMALL_STATE(414)] = 7938,
  [SMALL_STATE(415)] = 7950,
  [SMALL_STATE(416)] = 7964,
  [SMALL_STATE(417)] = 7978,
  [SMALL_STATE(418)] = 7990,
  [SMALL_STATE(419)] = 8004,
  [SMALL_STATE(420)] = 8018,
  [SMALL_STATE(421)] = 8032,
  [SMALL_STATE(422)] = 8042,
  [SMALL_STATE(423)] = 8056,
  [SMALL_STATE(424)] = 8068,
  [SMALL_STATE(425)] = 8080,
  [SMALL_STATE(426)] = 8094,
  [SMALL_STATE(427)] = 8108,
  [SMALL_STATE(428)] = 8118,
  [SMALL_STATE(429)] = 8132,
  [SMALL_STATE(430)] = 8146,
  [SMALL_STATE(431)] = 8158,
  [SMALL_STATE(432)] = 8170,
  [SMALL_STATE(433)] = 8180,
  [SMALL_STATE(434)] = 8190,
  [SMALL_STATE(435)] = 8204,
  [SMALL_STATE(436)] = 8216,
  [SMALL_STATE(437)] = 8226,
  [SMALL_STATE(438)] = 8236,
  [SMALL_STATE(439)] = 8250,
  [SMALL_STATE(440)] = 8264,
  [SMALL_STATE(441)] = 8274,
  [SMALL_STATE(442)] = 8288,
  [SMALL_STATE(443)] = 8302,
  [SMALL_STATE(444)] = 8316,
  [SMALL_STATE(445)] = 8328,
  [SMALL_STATE(446)] = 8342,
  [SMALL_STATE(447)] = 8356,
  [SMALL_STATE(448)] = 8366,
  [SMALL_STATE(449)] = 8376,
  [SMALL_STATE(450)] = 8388,
  [SMALL_STATE(451)] = 8398,
  [SMALL_STATE(452)] = 8410,
  [SMALL_STATE(453)] = 8422,
  [SMALL_STATE(454)] = 8432,
  [SMALL_STATE(455)] = 8446,
  [SMALL_STATE(456)] = 8458,
  [SMALL_STATE(457)] = 8472,
  [SMALL_STATE(458)] = 8482,
  [SMALL_STATE(459)] = 8496,
  [SMALL_STATE(460)] = 8510,
  [SMALL_STATE(461)] = 8522,
  [SMALL_STATE(462)] = 8536,
  [SMALL_STATE(463)] = 8546,
  [SMALL_STATE(464)] = 8560,
  [SMALL_STATE(465)] = 8574,
  [SMALL_STATE(466)] = 8584,
  [SMALL_STATE(467)] = 8598,
  [SMALL_STATE(468)] = 8608,
  [SMALL_STATE(469)] = 8618,
  [SMALL_STATE(470)] = 8632,
  [SMALL_STATE(471)] = 8646,
  [SMALL_STATE(472)] = 8660,
  [SMALL_STATE(473)] = 8674,
  [SMALL_STATE(474)] = 8688,
  [SMALL_STATE(475)] = 8702,
  [SMALL_STATE(476)] = 8716,
  [SMALL_STATE(477)] = 8730,
  [SMALL_STATE(478)] = 8740,
  [SMALL_STATE(479)] = 8750,
  [SMALL_STATE(480)] = 8760,
  [SMALL_STATE(481)] = 8770,
  [SMALL_STATE(482)] = 8780,
  [SMALL_STATE(483)] = 8790,
  [SMALL_STATE(484)] = 8800,
  [SMALL_STATE(485)] = 8812,
  [SMALL_STATE(486)] = 8826,
  [SMALL_STATE(487)] = 8838,
  [SMALL_STATE(488)] = 8850,
  [SMALL_STATE(489)] = 8864,
  [SMALL_STATE(490)] = 8876,
  [SMALL_STATE(491)] = 8890,
  [SMALL_STATE(492)] = 8900,
  [SMALL_STATE(493)] = 8912,
  [SMALL_STATE(494)] = 8926,
  [SMALL_STATE(495)] = 8940,
  [SMALL_STATE(496)] = 8950,
  [SMALL_STATE(497)] = 8960,
  [SMALL_STATE(498)] = 8974,
  [SMALL_STATE(499)] = 8988,
  [SMALL_STATE(500)] = 9002,
  [SMALL_STATE(501)] = 9016,
  [SMALL_STATE(502)] = 9030,
  [SMALL_STATE(503)] = 9044,
  [SMALL_STATE(504)] = 9058,
  [SMALL_STATE(505)] = 9072,
  [SMALL_STATE(506)] = 9086,
  [SMALL_STATE(507)] = 9096,
  [SMALL_STATE(508)] = 9110,
  [SMALL_STATE(509)] = 9120,
  [SMALL_STATE(510)] = 9134,
  [SMALL_STATE(511)] = 9146,
  [SMALL_STATE(512)] = 9160,
  [SMALL_STATE(513)] = 9172,
  [SMALL_STATE(514)] = 9186,
  [SMALL_STATE(515)] = 9198,
  [SMALL_STATE(516)] = 9212,
  [SMALL_STATE(517)] = 9226,
  [SMALL_STATE(518)] = 9238,
  [SMALL_STATE(519)] = 9252,
  [SMALL_STATE(520)] = 9262,
  [SMALL_STATE(521)] = 9276,
  [SMALL_STATE(522)] = 9286,
  [SMALL_STATE(523)] = 9300,
  [SMALL_STATE(524)] = 9310,
  [SMALL_STATE(525)] = 9320,
  [SMALL_STATE(526)] = 9334,
  [SMALL_STATE(527)] = 9348,
  [SMALL_STATE(528)] = 9362,
  [SMALL_STATE(529)] = 9376,
  [SMALL_STATE(530)] = 9388,
  [SMALL_STATE(531)] = 9402,
  [SMALL_STATE(532)] = 9416,
  [SMALL_STATE(533)] = 9430,
  [SMALL_STATE(534)] = 9444,
  [SMALL_STATE(535)] = 9454,
  [SMALL_STATE(536)] = 9468,
  [SMALL_STATE(537)] = 9482,
  [SMALL_STATE(538)] = 9491,
  [SMALL_STATE(539)] = 9500,
  [SMALL_STATE(540)] = 9509,
  [SMALL_STATE(541)] = 9518,
  [SMALL_STATE(542)] = 9529,
  [SMALL_STATE(543)] = 9540,
  [SMALL_STATE(544)] = 9549,
  [SMALL_STATE(545)] = 9558,
  [SMALL_STATE(546)] = 9567,
  [SMALL_STATE(547)] = 9576,
  [SMALL_STATE(548)] = 9585,
  [SMALL_STATE(549)] = 9594,
  [SMALL_STATE(550)] = 9603,
  [SMALL_STATE(551)] = 9612,
  [SMALL_STATE(552)] = 9621,
  [SMALL_STATE(553)] = 9630,
  [SMALL_STATE(554)] = 9641,
  [SMALL_STATE(555)] = 9652,
  [SMALL_STATE(556)] = 9661,
  [SMALL_STATE(557)] = 9672,
  [SMALL_STATE(558)] = 9681,
  [SMALL_STATE(559)] = 9690,
  [SMALL_STATE(560)] = 9699,
  [SMALL_STATE(561)] = 9710,
  [SMALL_STATE(562)] = 9719,
  [SMALL_STATE(563)] = 9728,
  [SMALL_STATE(564)] = 9737,
  [SMALL_STATE(565)] = 9746,
  [SMALL_STATE(566)] = 9757,
  [SMALL_STATE(567)] = 9766,
  [SMALL_STATE(568)] = 9775,
  [SMALL_STATE(569)] = 9784,
  [SMALL_STATE(570)] = 9793,
  [SMALL_STATE(571)] = 9802,
  [SMALL_STATE(572)] = 9811,
  [SMALL_STATE(573)] = 9822,
  [SMALL_STATE(574)] = 9831,
  [SMALL_STATE(575)] = 9840,
  [SMALL_STATE(576)] = 9849,
  [SMALL_STATE(577)] = 9860,
  [SMALL_STATE(578)] = 9869,
  [SMALL_STATE(579)] = 9878,
  [SMALL_STATE(580)] = 9887,
  [SMALL_STATE(581)] = 9896,
  [SMALL_STATE(582)] = 9905,
  [SMALL_STATE(583)] = 9914,
  [SMALL_STATE(584)] = 9923,
  [SMALL_STATE(585)] = 9932,
  [SMALL_STATE(586)] = 9941,
  [SMALL_STATE(587)] = 9950,
  [SMALL_STATE(588)] = 9959,
  [SMALL_STATE(589)] = 9968,
  [SMALL_STATE(590)] = 9977,
  [SMALL_STATE(591)] = 9986,
  [SMALL_STATE(592)] = 9997,
  [SMALL_STATE(593)] = 10006,
  [SMALL_STATE(594)] = 10015,
  [SMALL_STATE(595)] = 10024,
  [SMALL_STATE(596)] = 10033,
  [SMALL_STATE(597)] = 10042,
  [SMALL_STATE(598)] = 10051,
  [SMALL_STATE(599)] = 10060,
  [SMALL_STATE(600)] = 10069,
  [SMALL_STATE(601)] = 10078,
  [SMALL_STATE(602)] = 10087,
  [SMALL_STATE(603)] = 10096,
  [SMALL_STATE(604)] = 10105,
  [SMALL_STATE(605)] = 10114,
  [SMALL_STATE(606)] = 10125,
  [SMALL_STATE(607)] = 10134,
  [SMALL_STATE(608)] = 10143,
  [SMALL_STATE(609)] = 10152,
  [SMALL_STATE(610)] = 10161,
  [SMALL_STATE(611)] = 10170,
  [SMALL_STATE(612)] = 10179,
  [SMALL_STATE(613)] = 10188,
  [SMALL_STATE(614)] = 10197,
  [SMALL_STATE(615)] = 10206,
  [SMALL_STATE(616)] = 10215,
  [SMALL_STATE(617)] = 10224,
  [SMALL_STATE(618)] = 10233,
  [SMALL_STATE(619)] = 10242,
  [SMALL_STATE(620)] = 10251,
  [SMALL_STATE(621)] = 10260,
  [SMALL_STATE(622)] = 10269,
  [SMALL_STATE(623)] = 10278,
  [SMALL_STATE(624)] = 10287,
  [SMALL_STATE(625)] = 10296,
  [SMALL_STATE(626)] = 10305,
  [SMALL_STATE(627)] = 10314,
  [SMALL_STATE(628)] = 10323,
  [SMALL_STATE(629)] = 10332,
  [SMALL_STATE(630)] = 10341,
  [SMALL_STATE(631)] = 10350,
  [SMALL_STATE(632)] = 10359,
  [SMALL_STATE(633)] = 10370,
  [SMALL_STATE(634)] = 10379,
  [SMALL_STATE(635)] = 10388,
  [SMALL_STATE(636)] = 10397,
  [SMALL_STATE(637)] = 10406,
  [SMALL_STATE(638)] = 10415,
  [SMALL_STATE(639)] = 10424,
  [SMALL_STATE(640)] = 10433,
  [SMALL_STATE(641)] = 10442,
  [SMALL_STATE(642)] = 10451,
  [SMALL_STATE(643)] = 10460,
  [SMALL_STATE(644)] = 10469,
  [SMALL_STATE(645)] = 10478,
  [SMALL_STATE(646)] = 10487,
  [SMALL_STATE(647)] = 10496,
  [SMALL_STATE(648)] = 10505,
  [SMALL_STATE(649)] = 10514,
  [SMALL_STATE(650)] = 10523,
  [SMALL_STATE(651)] = 10532,
  [SMALL_STATE(652)] = 10541,
  [SMALL_STATE(653)] = 10550,
  [SMALL_STATE(654)] = 10559,
  [SMALL_STATE(655)] = 10568,
  [SMALL_STATE(656)] = 10577,
  [SMALL_STATE(657)] = 10586,
  [SMALL_STATE(658)] = 10595,
  [SMALL_STATE(659)] = 10604,
  [SMALL_STATE(660)] = 10615,
  [SMALL_STATE(661)] = 10624,
  [SMALL_STATE(662)] = 10633,
  [SMALL_STATE(663)] = 10644,
  [SMALL_STATE(664)] = 10655,
  [SMALL_STATE(665)] = 10666,
  [SMALL_STATE(666)] = 10675,
  [SMALL_STATE(667)] = 10684,
  [SMALL_STATE(668)] = 10693,
  [SMALL_STATE(669)] = 10702,
  [SMALL_STATE(670)] = 10713,
  [SMALL_STATE(671)] = 10722,
  [SMALL_STATE(672)] = 10733,
  [SMALL_STATE(673)] = 10742,
  [SMALL_STATE(674)] = 10753,
  [SMALL_STATE(675)] = 10762,
  [SMALL_STATE(676)] = 10771,
  [SMALL_STATE(677)] = 10780,
  [SMALL_STATE(678)] = 10791,
  [SMALL_STATE(679)] = 10800,
  [SMALL_STATE(680)] = 10809,
  [SMALL_STATE(681)] = 10820,
  [SMALL_STATE(682)] = 10829,
  [SMALL_STATE(683)] = 10838,
  [SMALL_STATE(684)] = 10847,
  [SMALL_STATE(685)] = 10856,
  [SMALL_STATE(686)] = 10865,
  [SMALL_STATE(687)] = 10874,
  [SMALL_STATE(688)] = 10885,
  [SMALL_STATE(689)] = 10894,
  [SMALL_STATE(690)] = 10903,
  [SMALL_STATE(691)] = 10912,
  [SMALL_STATE(692)] = 10921,
  [SMALL_STATE(693)] = 10930,
  [SMALL_STATE(694)] = 10939,
  [SMALL_STATE(695)] = 10948,
  [SMALL_STATE(696)] = 10957,
  [SMALL_STATE(697)] = 10966,
  [SMALL_STATE(698)] = 10975,
  [SMALL_STATE(699)] = 10984,
  [SMALL_STATE(700)] = 10993,
  [SMALL_STATE(701)] = 11002,
  [SMALL_STATE(702)] = 11011,
  [SMALL_STATE(703)] = 11020,
  [SMALL_STATE(704)] = 11029,
  [SMALL_STATE(705)] = 11038,
  [SMALL_STATE(706)] = 11047,
  [SMALL_STATE(707)] = 11056,
  [SMALL_STATE(708)] = 11065,
  [SMALL_STATE(709)] = 11074,
  [SMALL_STATE(710)] = 11083,
  [SMALL_STATE(711)] = 11092,
  [SMALL_STATE(712)] = 11101,
  [SMALL_STATE(713)] = 11110,
  [SMALL_STATE(714)] = 11119,
  [SMALL_STATE(715)] = 11128,
  [SMALL_STATE(716)] = 11139,
  [SMALL_STATE(717)] = 11148,
  [SMALL_STATE(718)] = 11157,
  [SMALL_STATE(719)] = 11166,
  [SMALL_STATE(720)] = 11177,
  [SMALL_STATE(721)] = 11186,
  [SMALL_STATE(722)] = 11195,
  [SMALL_STATE(723)] = 11204,
  [SMALL_STATE(724)] = 11213,
  [SMALL_STATE(725)] = 11222,
  [SMALL_STATE(726)] = 11231,
  [SMALL_STATE(727)] = 11242,
  [SMALL_STATE(728)] = 11251,
  [SMALL_STATE(729)] = 11260,
  [SMALL_STATE(730)] = 11269,
  [SMALL_STATE(731)] = 11278,
  [SMALL_STATE(732)] = 11287,
  [SMALL_STATE(733)] = 11296,
  [SMALL_STATE(734)] = 11305,
  [SMALL_STATE(735)] = 11316,
  [SMALL_STATE(736)] = 11325,
  [SMALL_STATE(737)] = 11334,
  [SMALL_STATE(738)] = 11343,
  [SMALL_STATE(739)] = 11352,
  [SMALL_STATE(740)] = 11361,
  [SMALL_STATE(741)] = 11370,
  [SMALL_STATE(742)] = 11379,
  [SMALL_STATE(743)] = 11390,
  [SMALL_STATE(744)] = 11401,
  [SMALL_STATE(745)] = 11410,
  [SMALL_STATE(746)] = 11419,
  [SMALL_STATE(747)] = 11428,
  [SMALL_STATE(748)] = 11437,
  [SMALL_STATE(749)] = 11445,
  [SMALL_STATE(750)] = 11453,
  [SMALL_STATE(751)] = 11461,
  [SMALL_STATE(752)] = 11469,
  [SMALL_STATE(753)] = 11477,
  [SMALL_STATE(754)] = 11485,
  [SMALL_STATE(755)] = 11493,
  [SMALL_STATE(756)] = 11501,
  [SMALL_STATE(757)] = 11509,
  [SMALL_STATE(758)] = 11517,
  [SMALL_STATE(759)] = 11525,
  [SMALL_STATE(760)] = 11533,
  [SMALL_STATE(761)] = 11541,
  [SMALL_STATE(762)] = 11549,
  [SMALL_STATE(763)] = 11557,
  [SMALL_STATE(764)] = 11565,
  [SMALL_STATE(765)] = 11573,
  [SMALL_STATE(766)] = 11581,
  [SMALL_STATE(767)] = 11589,
  [SMALL_STATE(768)] = 11597,
  [SMALL_STATE(769)] = 11605,
  [SMALL_STATE(770)] = 11613,
  [SMALL_STATE(771)] = 11621,
  [SMALL_STATE(772)] = 11629,
  [SMALL_STATE(773)] = 11637,
  [SMALL_STATE(774)] = 11645,
  [SMALL_STATE(775)] = 11653,
  [SMALL_STATE(776)] = 11661,
  [SMALL_STATE(777)] = 11669,
  [SMALL_STATE(778)] = 11677,
  [SMALL_STATE(779)] = 11685,
  [SMALL_STATE(780)] = 11693,
  [SMALL_STATE(781)] = 11701,
  [SMALL_STATE(782)] = 11709,
  [SMALL_STATE(783)] = 11717,
  [SMALL_STATE(784)] = 11725,
  [SMALL_STATE(785)] = 11733,
  [SMALL_STATE(786)] = 11741,
  [SMALL_STATE(787)] = 11749,
  [SMALL_STATE(788)] = 11757,
  [SMALL_STATE(789)] = 11765,
  [SMALL_STATE(790)] = 11773,
  [SMALL_STATE(791)] = 11781,
  [SMALL_STATE(792)] = 11789,
  [SMALL_STATE(793)] = 11797,
  [SMALL_STATE(794)] = 11805,
  [SMALL_STATE(795)] = 11813,
  [SMALL_STATE(796)] = 11821,
  [SMALL_STATE(797)] = 11829,
  [SMALL_STATE(798)] = 11837,
  [SMALL_STATE(799)] = 11845,
  [SMALL_STATE(800)] = 11853,
  [SMALL_STATE(801)] = 11861,
  [SMALL_STATE(802)] = 11869,
  [SMALL_STATE(803)] = 11877,
  [SMALL_STATE(804)] = 11885,
  [SMALL_STATE(805)] = 11893,
  [SMALL_STATE(806)] = 11901,
  [SMALL_STATE(807)] = 11909,
  [SMALL_STATE(808)] = 11917,
  [SMALL_STATE(809)] = 11925,
  [SMALL_STATE(810)] = 11933,
  [SMALL_STATE(811)] = 11941,
  [SMALL_STATE(812)] = 11949,
  [SMALL_STATE(813)] = 11957,
  [SMALL_STATE(814)] = 11965,
  [SMALL_STATE(815)] = 11973,
  [SMALL_STATE(816)] = 11981,
  [SMALL_STATE(817)] = 11989,
  [SMALL_STATE(818)] = 11997,
  [SMALL_STATE(819)] = 12005,
  [SMALL_STATE(820)] = 12013,
  [SMALL_STATE(821)] = 12021,
  [SMALL_STATE(822)] = 12029,
  [SMALL_STATE(823)] = 12037,
  [SMALL_STATE(824)] = 12045,
  [SMALL_STATE(825)] = 12053,
  [SMALL_STATE(826)] = 12061,
  [SMALL_STATE(827)] = 12069,
  [SMALL_STATE(828)] = 12077,
  [SMALL_STATE(829)] = 12085,
  [SMALL_STATE(830)] = 12093,
  [SMALL_STATE(831)] = 12101,
  [SMALL_STATE(832)] = 12109,
  [SMALL_STATE(833)] = 12117,
  [SMALL_STATE(834)] = 12125,
  [SMALL_STATE(835)] = 12133,
  [SMALL_STATE(836)] = 12141,
  [SMALL_STATE(837)] = 12149,
  [SMALL_STATE(838)] = 12157,
  [SMALL_STATE(839)] = 12165,
  [SMALL_STATE(840)] = 12173,
  [SMALL_STATE(841)] = 12181,
  [SMALL_STATE(842)] = 12189,
  [SMALL_STATE(843)] = 12197,
  [SMALL_STATE(844)] = 12205,
  [SMALL_STATE(845)] = 12213,
  [SMALL_STATE(846)] = 12221,
  [SMALL_STATE(847)] = 12229,
  [SMALL_STATE(848)] = 12237,
  [SMALL_STATE(849)] = 12245,
  [SMALL_STATE(850)] = 12253,
  [SMALL_STATE(851)] = 12261,
  [SMALL_STATE(852)] = 12269,
  [SMALL_STATE(853)] = 12277,
  [SMALL_STATE(854)] = 12285,
  [SMALL_STATE(855)] = 12293,
  [SMALL_STATE(856)] = 12301,
  [SMALL_STATE(857)] = 12309,
  [SMALL_STATE(858)] = 12317,
  [SMALL_STATE(859)] = 12325,
  [SMALL_STATE(860)] = 12333,
  [SMALL_STATE(861)] = 12341,
  [SMALL_STATE(862)] = 12349,
  [SMALL_STATE(863)] = 12357,
  [SMALL_STATE(864)] = 12365,
  [SMALL_STATE(865)] = 12373,
  [SMALL_STATE(866)] = 12381,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(541),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(663),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(854),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(270),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(572),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(678),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(534),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(788),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(742),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(801),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(612),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(363),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(743),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(863),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(864),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(865),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(848),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(576),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(671),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(846),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(680),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(218),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(255),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(827),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(828),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(838),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(840),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(354),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(355),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(560),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(353),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(809),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(808),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(802),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(753),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(756),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(765),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(742),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(801),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(363),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(743),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(863),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(864),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(865),
  [121] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(848),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(576),
  [127] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(671),
  [136] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(846),
  [139] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(680),
  [142] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [148] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(827),
  [151] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(828),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(838),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(840),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(354),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(355),
  [166] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(560),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [172] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [175] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [178] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(353),
  [181] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [184] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(809),
  [187] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(808),
  [190] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(802),
  [193] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(753),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(756),
  [199] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0), SHIFT_REPEAT(765),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(670),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [207] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(673),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(801),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [215] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(363),
  [218] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(553),
  [221] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(850),
  [224] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(760),
  [227] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(763),
  [230] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(800),
  [233] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(576),
  [236] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [239] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [242] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(671),
  [245] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(846),
  [248] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(680),
  [251] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [254] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [257] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(827),
  [260] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(828),
  [263] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(838),
  [266] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(840),
  [269] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(354),
  [272] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(355),
  [275] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(560),
  [278] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [281] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [284] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [287] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(353),
  [290] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [293] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(809),
  [296] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(808),
  [299] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(753),
  [302] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(756),
  [305] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(765),
  [308] = {.entry = {.count = 1, .reusable = false}}, SHIFT(673),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(553),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(850),
  [316] = {.entry = {.count = 1, .reusable = false}}, SHIFT(760),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(763),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(800),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(521),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(523),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(801),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(836),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(833),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 7),
  [372] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 7),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 65),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 65),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [396] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [400] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [402] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_looping_block_repeat1, 2, 0, 0),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(448),
  [408] = {.entry = {.count = 1, .reusable = false}}, SHIFT(759),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(764),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(450),
  [416] = {.entry = {.count = 1, .reusable = false}}, SHIFT(450),
  [418] = {.entry = {.count = 1, .reusable = false}}, SHIFT(797),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(837),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [428] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(541),
  [431] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(663),
  [434] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(854),
  [437] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(270),
  [440] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(572),
  [443] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(678),
  [446] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(534),
  [449] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(788),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(767),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_unary_expression, 2, 0, 52),
  [456] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_unary_expression, 2, 0, 52),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 2, 0, 0),
  [462] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_bool, 3, 0, 36),
  [466] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_binary_expression, 3, 0, 69),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [480] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_binary_expression, 3, 0, 69),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(391),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = false}}, SHIFT(829),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(829),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [504] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(639),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(477),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(478),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(481),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(482),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(483),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(651),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 1, 0, 32),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [530] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [534] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [538] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(639),
  [541] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(477),
  [544] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(478),
  [547] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(481),
  [550] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(482),
  [553] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(483),
  [556] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(651),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [561] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(392),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 30),
  [587] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bool_expression, 1, 0, 30),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 2),
  [591] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bool_expression, 1, 0, 2),
  [593] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 31),
  [595] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bool_expression, 1, 0, 31),
  [597] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 47),
  [599] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 47),
  [601] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [605] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 48),
  [615] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 48),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(667),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(778),
  [621] = {.entry = {.count = 1, .reusable = false}}, SHIFT(540),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(803),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(540),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [631] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [633] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 47),
  [635] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 47),
  [637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 63),
  [639] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 63),
  [641] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 48),
  [643] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 48),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(587),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(859),
  [649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 3, 0, 52),
  [651] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bool_expression, 3, 0, 52),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [655] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 6, 0, 63),
  [657] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_identifier_expansion, 6, 0, 63),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(847),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(779),
  [663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 3),
  [665] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 3),
  [667] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [669] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_unary_expression, 2, 0, 54),
  [675] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_int_unary_expression, 2, 0, 54),
  [677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [679] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [681] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [683] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [687] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 55),
  [691] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 55),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 41),
  [695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [697] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 44),
  [699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 57),
  [701] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 58),
  [703] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 59),
  [705] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 60),
  [707] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 61),
  [709] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 61),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(834),
  [713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 15),
  [715] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 15),
  [717] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 46),
  [719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 46),
  [721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 4),
  [723] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 4),
  [725] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 5),
  [727] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 5),
  [729] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 6),
  [731] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 6),
  [733] = {.entry = {.count = 1, .reusable = false}}, SHIFT(839),
  [735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(839),
  [739] = {.entry = {.count = 1, .reusable = false}}, SHIFT(745),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_int, 3, 0, 40),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [749] = {.entry = {.count = 1, .reusable = false}}, SHIFT(225),
  [751] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_binary_expression, 3, 0, 78),
  [753] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_int_binary_expression, 3, 0, 78),
  [755] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [757] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [759] = {.entry = {.count = 1, .reusable = false}}, SHIFT(527),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(527),
  [763] = {.entry = {.count = 1, .reusable = false}}, SHIFT(856),
  [765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(856),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [777] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 7),
  [781] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 19),
  [783] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 44),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [787] = {.entry = {.count = 1, .reusable = false}}, SHIFT(377),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(377),
  [791] = {.entry = {.count = 1, .reusable = false}}, SHIFT(390),
  [793] = {.entry = {.count = 1, .reusable = false}}, SHIFT(313),
  [795] = {.entry = {.count = 1, .reusable = false}}, SHIFT(539),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(462),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [807] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignmment_operator, 1, 0, 0),
  [809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 2, 0, 0),
  [811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(790),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(745),
  [819] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__int_expression, 1, 0, 2),
  [821] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__int_expression, 1, 0, 2),
  [823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__int_expression, 1, 0, 38),
  [825] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__int_expression, 1, 0, 38),
  [827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__int_expression, 1, 0, 31),
  [829] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__int_expression, 1, 0, 31),
  [831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 17),
  [833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(814),
  [835] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [839] = {.entry = {.count = 1, .reusable = false}}, SHIFT(544),
  [841] = {.entry = {.count = 1, .reusable = false}}, SHIFT(643),
  [843] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 62),
  [845] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 62), SHIFT_REPEAT(186),
  [848] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 62),
  [850] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 46),
  [852] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 46),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [856] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 42),
  [858] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [860] = {.entry = {.count = 1, .reusable = true}}, SHIFT(750),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [864] = {.entry = {.count = 1, .reusable = false}}, SHIFT(674),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(674),
  [868] = {.entry = {.count = 1, .reusable = false}}, SHIFT(310),
  [870] = {.entry = {.count = 1, .reusable = false}}, SHIFT(357),
  [872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(467),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [876] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__int_expression, 3, 0, 54),
  [878] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__int_expression, 3, 0, 54),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(762),
  [882] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [885] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [887] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(544),
  [890] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(643),
  [893] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 61),
  [895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 61),
  [897] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [899] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [901] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(834),
  [904] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(575),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(519),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(805),
  [912] = {.entry = {.count = 1, .reusable = true}}, SHIFT(539),
  [914] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [916] = {.entry = {.count = 1, .reusable = true}}, SHIFT(404),
  [918] = {.entry = {.count = 1, .reusable = true}}, SHIFT(776),
  [920] = {.entry = {.count = 1, .reusable = true}}, SHIFT(405),
  [922] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_chain, 2, 0, 0),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(509),
  [926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [928] = {.entry = {.count = 1, .reusable = true}}, SHIFT(755),
  [930] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [932] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [934] = {.entry = {.count = 1, .reusable = true}}, SHIFT(427),
  [936] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [938] = {.entry = {.count = 1, .reusable = true}}, SHIFT(744),
  [940] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [942] = {.entry = {.count = 1, .reusable = true}}, SHIFT(407),
  [944] = {.entry = {.count = 1, .reusable = true}}, SHIFT(784),
  [946] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [948] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(855),
  [952] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [954] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 45),
  [956] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 45),
  [958] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [960] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [962] = {.entry = {.count = 1, .reusable = true}}, SHIFT(785),
  [964] = {.entry = {.count = 1, .reusable = true}}, SHIFT(440),
  [966] = {.entry = {.count = 1, .reusable = true}}, SHIFT(627),
  [968] = {.entry = {.count = 1, .reusable = true}}, SHIFT(716),
  [970] = {.entry = {.count = 1, .reusable = true}}, SHIFT(578),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(644),
  [974] = {.entry = {.count = 1, .reusable = true}}, SHIFT(433),
  [976] = {.entry = {.count = 1, .reusable = true}}, SHIFT(796),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(436),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [982] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignmment_operator, 1, 0, 0),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(412),
  [988] = {.entry = {.count = 1, .reusable = true}}, SHIFT(413),
  [990] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_chain, 1, 0, 0),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(613),
  [994] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [996] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [998] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(814),
  [1001] = {.entry = {.count = 1, .reusable = true}}, SHIFT(822),
  [1003] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_chain_repeat1, 2, 0, 0),
  [1005] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_if_chain_repeat1, 2, 0, 0), SHIFT_REPEAT(770),
  [1008] = {.entry = {.count = 1, .reusable = true}}, SHIFT(679),
  [1010] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [1012] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_COMPARISON, 1, 0, 0),
  [1014] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_COMPARISON, 1, 0, 0),
  [1016] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [1018] = {.entry = {.count = 1, .reusable = true}}, SHIFT(605),
  [1020] = {.entry = {.count = 1, .reusable = true}}, SHIFT(607),
  [1022] = {.entry = {.count = 1, .reusable = true}}, SHIFT(465),
  [1024] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [1026] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(745),
  [1029] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_EQUALITY, 1, 0, 0),
  [1031] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_EQUALITY, 1, 0, 0),
  [1033] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [1035] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [1037] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 43), SHIFT_REPEAT(315),
  [1040] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 43),
  [1042] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [1044] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 2, 0, 0),
  [1046] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 17),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(426),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(548),
  [1052] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(690),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(675),
  [1058] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_sub, 1, 0, 0),
  [1060] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mul_div_mod, 1, 0, 0),
  [1062] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [1064] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [1066] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 42),
  [1068] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_over_time_operator, 1, 0, 0),
  [1070] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [1072] = {.entry = {.count = 1, .reusable = true}}, SHIFT(495),
  [1074] = {.entry = {.count = 1, .reusable = true}}, SHIFT(853),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(496),
  [1078] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 4, 0, 0),
  [1080] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [1082] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [1084] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 47),
  [1086] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 0),
  [1088] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [1090] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 110),
  [1092] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [1094] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 112),
  [1096] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 119),
  [1098] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 119),
  [1100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 47),
  [1102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [1104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 125),
  [1106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 110),
  [1108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 112),
  [1110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [1112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 126),
  [1114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 125),
  [1116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 126),
  [1118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(398),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(593),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(603),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(609),
  [1126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(852),
  [1128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(592),
  [1130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(681),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(692),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [1136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [1138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(761),
  [1140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 56),
  [1142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 56), SHIFT_REPEAT(605),
  [1145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 56), SHIFT_REPEAT(607),
  [1148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 56), SHIFT_REPEAT(465),
  [1151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [1153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(378),
  [1155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(825),
  [1157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(379),
  [1159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [1161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(559),
  [1163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [1165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [1167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [1169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 79),
  [1171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 80),
  [1173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [1175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(444),
  [1177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [1179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(449),
  [1181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(771),
  [1183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [1185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(508),
  [1187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(700),
  [1189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(381),
  [1191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [1193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(646),
  [1195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(648),
  [1197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [1199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [1201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(498),
  [1203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [1205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(430),
  [1207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(783),
  [1209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 26),
  [1211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [1213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [1215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(653),
  [1217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [1219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(656),
  [1221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(747),
  [1223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [1225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(660),
  [1227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 47),
  [1229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(431),
  [1231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(816),
  [1233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 63),
  [1235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 48),
  [1237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [1239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(684),
  [1241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(812),
  [1243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(666),
  [1245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(668),
  [1247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [1249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [1251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(396),
  [1253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(699),
  [1257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(387),
  [1259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(388),
  [1261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(389),
  [1263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(682),
  [1265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(683),
  [1267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(622),
  [1269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(691),
  [1271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(624),
  [1273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(625),
  [1275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(693),
  [1277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(694),
  [1279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(696),
  [1281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(634),
  [1283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(635),
  [1285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(636),
  [1287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(697),
  [1289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(698),
  [1291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [1293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [1295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(701),
  [1297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(703),
  [1299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [1301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(704),
  [1303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [1305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(720),
  [1307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(710),
  [1309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(711),
  [1311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 6, 0, 63),
  [1313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(397),
  [1315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(573),
  [1317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 25),
  [1319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [1321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [1323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(597),
  [1325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [1327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [1331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(600),
  [1333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 16),
  [1335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 47),
  [1337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [1339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [1341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(724),
  [1343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 48),
  [1345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(727),
  [1347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(728),
  [1349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(781),
  [1351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [1353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(739),
  [1355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(751),
  [1357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(549),
  [1359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [1363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [1365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(580),
  [1367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [1369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(616),
  [1371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [1373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [1375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [1377] = {.entry = {.count = 1, .reusable = false}}, SHIFT(383),
  [1379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(676),
  [1381] = {.entry = {.count = 1, .reusable = false}}, SHIFT(384),
  [1383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(385),
  [1385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [1387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(618),
  [1389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(472),
  [1391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(623),
  [1393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(628),
  [1395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(610),
  [1397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [1399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(633),
  [1401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(638),
  [1403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(641),
  [1405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [1407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [1409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(583),
  [1411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 25),
  [1413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [1415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_camera, 1, 0, 0),
  [1417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [1419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(810),
  [1421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(563),
  [1423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(566),
  [1425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [1427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(574),
  [1429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [1431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [1433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(695),
  [1435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [1437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [1439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [1441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(804),
  [1445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [1447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(835),
  [1449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(424),
  [1451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [1453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [1455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [1457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [1459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [1461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(768),
  [1463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(491),
  [1465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(672),
  [1467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(492),
  [1471] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(794),
  [1474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0),
  [1476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [1478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [1480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [1482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [1484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(372),
  [1486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(798),
  [1488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(435),
  [1490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [1492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(547),
  [1494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [1496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(438),
  [1498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [1500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(552),
  [1504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [1506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(555),
  [1508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [1510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(558),
  [1512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [1514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(737),
  [1516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [1518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(561),
  [1520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(562),
  [1524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [1526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(564),
  [1528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [1530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(832),
  [1532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(524),
  [1534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [1538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [1540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(645),
  [1542] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(126),
  [1545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0),
  [1547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [1549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(532),
  [1551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [1553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [1555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(746),
  [1557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 3, 0, 27),
  [1559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [1561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [1565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(577),
  [1567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [1569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [1571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(792),
  [1575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(774),
  [1577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(451),
  [1579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [1581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(773),
  [1583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(795),
  [1585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(452),
  [1587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [1589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(664),
  [1591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(453),
  [1593] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [1596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [1598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [1600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [1602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [1604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [1606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(590),
  [1608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(455),
  [1610] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(457),
  [1613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [1615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [1617] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(594),
  [1620] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [1622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(734),
  [1624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(830),
  [1626] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_property_int_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [1629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_property_int_expansion_repeat1, 2, 0, 0),
  [1631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out, 1, 0, 0),
  [1633] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_property_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [1636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_property_string_expansion_repeat1, 2, 0, 0),
  [1638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(595),
  [1640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(459),
  [1642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(602),
  [1644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [1646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [1648] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 2, 0, 9),
  [1650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [1652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(769),
  [1654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(604),
  [1656] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 49), SHIFT_REPEAT(230),
  [1659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 49),
  [1661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [1663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(786),
  [1665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(464),
  [1667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(793),
  [1669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(466),
  [1671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 5, 0, 70),
  [1673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(775),
  [1675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [1677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [1679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(471),
  [1681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(380),
  [1683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(820),
  [1685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(473),
  [1687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(620),
  [1689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [1691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(626),
  [1693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(382),
  [1695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [1697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(629),
  [1699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [1701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [1705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [1707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [1709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [1711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [1713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [1715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [1717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(642),
  [1719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(479),
  [1721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_string, 1, 0, 0),
  [1723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(831),
  [1725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(526),
  [1727] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_int, 1, 0, 0),
  [1729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [1731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(650),
  [1733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [1735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [1739] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(652),
  [1742] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [1744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [1746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(484),
  [1748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(654),
  [1750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(823),
  [1752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(596),
  [1754] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(545),
  [1757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [1759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [1761] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(486),
  [1764] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0),
  [1766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(487),
  [1768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(815),
  [1770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(556),
  [1772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(489),
  [1774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(821),
  [1776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [1778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 41),
  [1780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [1782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [1784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [1786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [1788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [1790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [1792] = {.entry = {.count = 1, .reusable = true}}, SHIFT(501),
  [1794] = {.entry = {.count = 1, .reusable = true}}, SHIFT(685),
  [1796] = {.entry = {.count = 1, .reusable = true}}, SHIFT(686),
  [1798] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [1800] = {.entry = {.count = 1, .reusable = true}}, SHIFT(688),
  [1802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(503),
  [1804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(689),
  [1806] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 93), SHIFT_REPEAT(505),
  [1809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 93),
  [1811] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_int_or_identifier_expansion_repeat1, 2, 0, 97), SHIFT_REPEAT(507),
  [1814] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_int_or_identifier_expansion_repeat1, 2, 0, 97),
  [1816] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [1818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [1820] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 100),
  [1822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [1824] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [1826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [1828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [1830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(706),
  [1832] = {.entry = {.count = 1, .reusable = true}}, SHIFT(707),
  [1834] = {.entry = {.count = 1, .reusable = true}}, SHIFT(510),
  [1836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(787),
  [1838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(712),
  [1840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(512),
  [1842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(791),
  [1844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(713),
  [1846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(514),
  [1848] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(399),
  [1852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [1854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [1856] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(599),
  [1859] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [1861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(799),
  [1863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(517),
  [1865] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 111), SHIFT_REPEAT(327),
  [1868] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 111),
  [1870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [1872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(608),
  [1874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [1876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [1878] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [1880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [1882] = {.entry = {.count = 1, .reusable = true}}, SHIFT(722),
  [1884] = {.entry = {.count = 1, .reusable = true}}, SHIFT(520),
  [1886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(723),
  [1888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(725),
  [1890] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 117), SHIFT_REPEAT(726),
  [1893] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 117),
  [1895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_else_block, 6, 0, 118),
  [1897] = {.entry = {.count = 1, .reusable = true}}, SHIFT(611),
  [1899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(811),
  [1903] = {.entry = {.count = 1, .reusable = true}}, SHIFT(729),
  [1905] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(730),
  [1908] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0),
  [1910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(817),
  [1912] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(731),
  [1915] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [1917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(819),
  [1919] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(732),
  [1922] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [1924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [1926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(614),
  [1928] = {.entry = {.count = 1, .reusable = true}}, SHIFT(736),
  [1930] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 49), SHIFT_REPEAT(402),
  [1933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 49),
  [1935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(826),
  [1937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(738),
  [1939] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 49), SHIFT_REPEAT(207),
  [1942] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 49),
  [1944] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [1946] = {.entry = {.count = 1, .reusable = true}}, SHIFT(409),
  [1948] = {.entry = {.count = 1, .reusable = true}}, SHIFT(529),
  [1950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(842),
  [1952] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [1954] = {.entry = {.count = 1, .reusable = true}}, SHIFT(749),
  [1956] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [1958] = {.entry = {.count = 1, .reusable = true}}, SHIFT(758),
  [1960] = {.entry = {.count = 1, .reusable = true}}, SHIFT(460),
  [1962] = {.entry = {.count = 1, .reusable = true}}, SHIFT(542),
  [1964] = {.entry = {.count = 1, .reusable = true}}, SHIFT(780),
  [1966] = {.entry = {.count = 1, .reusable = true}}, SHIFT(414),
  [1968] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [1970] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [1972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(662),
  [1974] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [1976] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(664),
  [1979] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [1981] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 26),
  [1983] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 25),
  [1985] = {.entry = {.count = 1, .reusable = true}}, SHIFT(757),
  [1987] = {.entry = {.count = 1, .reusable = true}}, SHIFT(419),
  [1989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(789),
  [1991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(709),
  [1993] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_block, 5, 0, 0),
  [1995] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [1997] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [1999] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 2, 0, 0),
  [2001] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 21),
  [2003] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 71),
  [2005] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 72),
  [2007] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 73),
  [2009] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 74),
  [2011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [2013] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 75),
  [2015] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 3, 0, 0),
  [2017] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 76),
  [2019] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 22),
  [2021] = {.entry = {.count = 1, .reusable = true}}, SHIFT(568),
  [2023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(571),
  [2025] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 3, 0, 75),
  [2027] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 3, 0, 77),
  [2029] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 11),
  [2031] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 3, 0, 76),
  [2033] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [2035] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 11),
  [2037] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_bool, 3, 0, 0),
  [2039] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [2041] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_block, 2, 0, 37),
  [2043] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_chain, 3, 0, 0),
  [2045] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [2047] = {.entry = {.count = 1, .reusable = true}}, SHIFT(777),
  [2049] = {.entry = {.count = 1, .reusable = true}}, SHIFT(806),
  [2051] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 23),
  [2053] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 24),
  [2055] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 47),
  [2057] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [2059] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [2061] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 81),
  [2063] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 64),
  [2065] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 4, 0, 47),
  [2067] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 6, 0, 82),
  [2069] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 0),
  [2071] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_int, 3, 0, 0),
  [2073] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 83),
  [2075] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 19),
  [2077] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 19),
  [2079] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 0),
  [2081] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 84),
  [2083] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 0),
  [2085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [2087] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_string, 3, 0, 0),
  [2089] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 3, 0, 28),
  [2091] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 2, 0, 0),
  [2093] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 85),
  [2095] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 0),
  [2097] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 86),
  [2099] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 87),
  [2101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 88),
  [2103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 3, 0, 27),
  [2105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 3, 0, 47),
  [2107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(554),
  [2109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 47),
  [2111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 3, 0, 27),
  [2113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 22),
  [2115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 3, 0, 47),
  [2117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_looping_block, 2, 0, 0),
  [2119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 0),
  [2121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 64),
  [2123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 0),
  [2125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 89),
  [2127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 72),
  [2129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 90),
  [2131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 73),
  [2133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 3, 0, 91),
  [2135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 3, 0, 0),
  [2137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 74),
  [2139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 74),
  [2141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 75),
  [2143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 76),
  [2145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 92),
  [2147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 48),
  [2149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 75),
  [2151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 94),
  [2153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 76),
  [2155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 95),
  [2157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 75),
  [2159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_int_or_identifier_expansion_repeat1, 2, 0, 75),
  [2161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_int_or_identifier_expansion_repeat1, 2, 0, 77),
  [2163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_int_or_identifier_expansion_repeat1, 2, 0, 76),
  [2165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 96),
  [2167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 77),
  [2169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [2171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 98),
  [2173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 76),
  [2175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 4, 0, 99),
  [2177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [2179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 7, 0, 81),
  [2181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 3, 0, 0),
  [2183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 101),
  [2185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 19),
  [2187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 102),
  [2189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 103),
  [2191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 104),
  [2193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [2195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 53),
  [2197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 3, 0, 0),
  [2199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 19),
  [2201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 105),
  [2203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 87),
  [2205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 25),
  [2207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 107),
  [2209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 88),
  [2211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 0),
  [2213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade, 7, 0, 108),
  [2215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 7, 0, 109),
  [2217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_looping_block, 3, 0, 0),
  [2219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [2221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [2223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_setable, 1, 0, 2),
  [2225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [2227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 8),
  [2229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 51),
  [2231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 2, 0, 0),
  [2233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [2235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(659),
  [2237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 51),
  [2239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [2241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [2243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 3, 0, 29),
  [2245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 113),
  [2247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 114),
  [2249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 115),
  [2251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 91),
  [2253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [2255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 91),
  [2257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 116),
  [2259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 5, 0, 66),
  [2261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 92),
  [2263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 3, 0, 29),
  [2265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 94),
  [2267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 95),
  [2269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 5, 0, 96),
  [2271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 5, 0, 98),
  [2273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 5, 0, 99),
  [2275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_or_identifier_expansion, 2, 0, 0),
  [2277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0),
  [2279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 120),
  [2281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 103),
  [2283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 121),
  [2285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 122),
  [2287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 104),
  [2289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 4, 0, 0),
  [2291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 123),
  [2293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 124),
  [2295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 0),
  [2297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 3, 0, 0),
  [2299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 5, 0, 67),
  [2301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 0),
  [2303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 115),
  [2305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 127),
  [2307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 3, 0, 115),
  [2309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 116),
  [2311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 128),
  [2313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 129),
  [2315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 5, 0, 0),
  [2317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_block, 9, 0, 130),
  [2319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 47),
  [2321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 112),
  [2323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 48),
  [2325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 6, 0, 127),
  [2327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 68),
  [2329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 0),
  [2331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 0),
  [2333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [2335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [2337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [2339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(468),
  [2341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [2343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 106),
  [2345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [2347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 3, 0, 0),
  [2349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_string_expansion, 5, 0, 0),
  [2351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 2, 0, 0),
  [2353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [2355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [2357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(480),
  [2359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(741),
  [2361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [2363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 2, 0, 0),
  [2365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [2367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [2369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(752),
  [2371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 4, 0, 50),
  [2373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_string_expansion, 2, 0, 0),
  [2375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(748),
  [2377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_setable, 2, 0, 12),
  [2379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 1, 0, 0),
  [2381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [2383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_int_expansion, 2, 0, 0),
  [2385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 3, 0, 0),
  [2387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 3, 0, 9),
  [2389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [2391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(447),
  [2393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_string_expansion, 3, 0, 0),
  [2395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [2397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [2399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [2401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(845),
  [2403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_int_expansion, 4, 0, 0),
  [2405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 4, 0, 0),
  [2407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 4, 0, 0),
  [2409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 4, 0, 0),
  [2411] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [2413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [2415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(585),
  [2417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(615),
  [2419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [2421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [2423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(669),
  [2425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 5, 0, 0),
  [2427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_string_expansion, 4, 0, 0),
  [2429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [2431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_int_expansion, 3, 0, 0),
  [2433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [2435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(649),
  [2437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [2439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [2441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(469),
  [2443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(735),
  [2445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [2447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [2449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 5, 0, 0),
  [2451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [2453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [2455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(849),
  [2457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(565),
  [2459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [2461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_setable, 1, 0, 0),
  [2463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [2465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [2467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 5, 0, 0),
  [2469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [2471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(772),
  [2473] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [2475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [2477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [2479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_setable, 2, 0, 0),
  [2481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [2483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(550),
  [2485] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [2487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_setable, 2, 0, 14),
  [2489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [2491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(591),
  [2493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(434),
  [2495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(579),
  [2497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [2499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [2501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [2503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 3, 0, 0),
  [2505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [2507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [2509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(715),
  [2511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(754),
  [2513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(601),
  [2515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [2517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_setable, 3, 0, 18),
  [2519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(546),
  [2521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [2523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [2525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [2527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [2529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_int_setable, 3, 0, 19),
  [2531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 3, 0, 20),
  [2533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [2535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [2537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [2539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [2541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(813),
  [2543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 2, 0, 13),
  [2545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_setable, 2, 0, 10),
  [2547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(718),
  [2549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [2551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [2553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [2555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [2557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(632),
  [2559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_property_int_expansion, 5, 0, 0),
  [2561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [2563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [2565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [2567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(860),
  [2569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(861),
  [2571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(862),
  [2573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_magegamescript(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
