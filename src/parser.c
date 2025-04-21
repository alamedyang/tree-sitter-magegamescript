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
#define STATE_COUNT 722
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 209
#define ALIAS_COUNT 2
#define TOKEN_COUNT 95
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 43
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 125

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
  anon_sym_player_control = 85,
  anon_sym_lights_control = 86,
  anon_sym_hex_editor = 87,
  anon_sym_hex_dialog_mode = 88,
  anon_sym_hex_control = 89,
  anon_sym_hex_clipboard = 90,
  anon_sym_serial_control = 91,
  anon_sym_flagName = 92,
  sym_AND = 93,
  sym_OR = 94,
  sym_source_file = 95,
  sym_bool_or_identifier_expansion = 96,
  sym_bareword_expansion = 97,
  sym_quoted_string_expansion = 98,
  sym_string_expansion = 99,
  sym_number_expansion = 100,
  sym_duration_expansion = 101,
  sym_distance_expansion = 102,
  sym_quantity_expansion = 103,
  sym_color_expansion = 104,
  sym_constant_expansion = 105,
  sym_constant_value_expansion = 106,
  sym__root = 107,
  sym_include_macro = 108,
  sym_constant_assignment = 109,
  sym_add_serial_dialog_settings = 110,
  sym_serial_dialog_parameter = 111,
  sym_add_dialog_settings = 112,
  sym_dialog_settings_block = 113,
  sym_dialog_parameter = 114,
  sym_dialog_definition = 115,
  sym_dialog_block = 116,
  sym_dialog = 117,
  sym_dialog_identifier = 118,
  sym_dialog_option = 119,
  sym_serial_dialog_definition = 120,
  sym_serial_dialog_block = 121,
  sym_serial_dialog = 122,
  sym_serial_dialog_option = 123,
  sym_script_definition = 124,
  sym_script_block = 125,
  sym__script_item = 126,
  sym_json_literal = 127,
  sym_json_array = 128,
  sym_json_object = 129,
  sym_json_name_value_pair = 130,
  sym__json_item = 131,
  sym_label = 132,
  sym_debug_macro = 133,
  sym_rand_macro = 134,
  sym_spread_macro = 135,
  sym__action_item = 136,
  sym_action_load_map = 137,
  sym_action_run_script = 138,
  sym_action_goto_label = 139,
  sym_action_goto_index = 140,
  sym_action_show_dialog = 141,
  sym_action_show_serial_dialog = 142,
  sym_action_concat_serial_dialog = 143,
  sym_action_delete_command = 144,
  sym_action_delete_command_arg = 145,
  sym_action_delete_alias = 146,
  sym_action_hide_command = 147,
  sym_action_unhide_command = 148,
  sym_action_save_slot = 149,
  sym_action_load_slot = 150,
  sym_action_erase_slot = 151,
  sym_action_blocking_delay = 152,
  sym_action_non_blocking_delay = 153,
  sym_action_close_dialog = 154,
  sym_action_close_serial_dialog = 155,
  sym_entity_identifier_expansion = 156,
  sym_map = 157,
  sym_entity_or_map_identifier_expansion = 158,
  sym_action_pause_script = 159,
  sym_action_unpause_script = 160,
  sym_action_camera_fade = 161,
  sym_in_or_out = 162,
  sym_in_or_out_expansion = 163,
  sym_action_camera_shake = 164,
  sym_action_play_entity_animation = 165,
  sym_camera = 166,
  sym__origin_or_length = 167,
  sym_movable_identifier_expansion = 168,
  sym_polygon_identifier_expansion = 169,
  sym_complex_duration_expansion = 170,
  sym_over_time_operator = 171,
  sym_action_move_over_time = 172,
  sym_assignmment_operator = 173,
  sym_action_set_position = 174,
  sym_setable = 175,
  sym_action_set_bool = 176,
  sym__bool_expression = 177,
  sym_bool_unary_expression = 178,
  sym_bool_binary_expression = 179,
  aux_sym_source_file_repeat1 = 180,
  aux_sym_bool_or_identifier_expansion_repeat1 = 181,
  aux_sym_bareword_expansion_repeat1 = 182,
  aux_sym_quoted_string_expansion_repeat1 = 183,
  aux_sym_string_expansion_repeat1 = 184,
  aux_sym_number_expansion_repeat1 = 185,
  aux_sym_duration_expansion_repeat1 = 186,
  aux_sym_distance_expansion_repeat1 = 187,
  aux_sym_quantity_expansion_repeat1 = 188,
  aux_sym_color_expansion_repeat1 = 189,
  aux_sym_constant_expansion_repeat1 = 190,
  aux_sym_constant_value_expansion_repeat1 = 191,
  aux_sym_add_serial_dialog_settings_repeat1 = 192,
  aux_sym_add_dialog_settings_repeat1 = 193,
  aux_sym_dialog_settings_block_repeat1 = 194,
  aux_sym_dialog_block_repeat1 = 195,
  aux_sym_dialog_repeat1 = 196,
  aux_sym_dialog_repeat2 = 197,
  aux_sym_serial_dialog_repeat1 = 198,
  aux_sym_serial_dialog_repeat2 = 199,
  aux_sym_script_block_repeat1 = 200,
  aux_sym_json_array_repeat1 = 201,
  aux_sym_json_object_repeat1 = 202,
  aux_sym_entity_identifier_expansion_repeat1 = 203,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 204,
  aux_sym_in_or_out_expansion_repeat1 = 205,
  aux_sym_movable_identifier_expansion_repeat1 = 206,
  aux_sym_polygon_identifier_expansion_repeat1 = 207,
  aux_sym_complex_duration_expansion_repeat1 = 208,
  alias_sym_entity_settings = 209,
  alias_sym_label_settings = 210,
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
  [sym_source_file] = "source_file",
  [sym_bool_or_identifier_expansion] = "bool_or_identifier_expansion",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
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
  [sym_setable] = "setable",
  [sym_action_set_bool] = "action_set_bool",
  [sym__bool_expression] = "_bool_expression",
  [sym_bool_unary_expression] = "bool_unary_expression",
  [sym_bool_binary_expression] = "bool_binary_expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_bool_or_identifier_expansion_repeat1] = "bool_or_identifier_expansion_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
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
  [alias_sym_entity_settings] = "entity_settings",
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
  [sym_source_file] = sym_source_file,
  [sym_bool_or_identifier_expansion] = sym_bool_or_identifier_expansion,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
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
  [sym_setable] = sym_setable,
  [sym_action_set_bool] = sym_action_set_bool,
  [sym__bool_expression] = sym__bool_expression,
  [sym_bool_unary_expression] = sym_bool_unary_expression,
  [sym_bool_binary_expression] = sym_bool_binary_expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_bool_or_identifier_expansion_repeat1] = aux_sym_bool_or_identifier_expansion_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
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
  [alias_sym_entity_settings] = alias_sym_entity_settings,
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
  [sym_setable] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_bool] = {
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
  [alias_sym_entity_settings] = {
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
  field_camera = 9,
  field_color = 10,
  field_command = 11,
  field_constant = 12,
  field_count = 13,
  field_dialog_name = 14,
  field_distance = 15,
  field_duration = 16,
  field_emote = 17,
  field_entity = 18,
  field_fade = 19,
  field_fileName = 20,
  field_forever = 21,
  field_geometry = 22,
  field_glitched = 23,
  field_identifier = 24,
  field_index = 25,
  field_label = 26,
  field_map = 27,
  field_message = 28,
  field_name = 29,
  field_option_type = 30,
  field_portrait = 31,
  field_property = 32,
  field_script = 33,
  field_script_name = 34,
  field_serial_dialog_name = 35,
  field_serial_message = 36,
  field_setable = 37,
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
  [field_camera] = "camera",
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
  [field_label] = "label",
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
  [field_setable] = "setable",
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
  [10] = {.index = 9, .length = 2},
  [11] = {.index = 11, .length = 1},
  [12] = {.index = 12, .length = 1},
  [13] = {.index = 13, .length = 1},
  [14] = {.index = 14, .length = 2},
  [15] = {.index = 16, .length = 1},
  [16] = {.index = 17, .length = 1},
  [17] = {.index = 18, .length = 1},
  [18] = {.index = 19, .length = 1},
  [19] = {.index = 20, .length = 1},
  [20] = {.index = 21, .length = 1},
  [21] = {.index = 22, .length = 1},
  [22] = {.index = 23, .length = 1},
  [23] = {.index = 24, .length = 1},
  [24] = {.index = 25, .length = 1},
  [25] = {.index = 26, .length = 1},
  [26] = {.index = 27, .length = 2},
  [27] = {.index = 29, .length = 1},
  [28] = {.index = 30, .length = 2},
  [29] = {.index = 32, .length = 1},
  [30] = {.index = 33, .length = 2},
  [31] = {.index = 35, .length = 1},
  [32] = {.index = 36, .length = 4},
  [33] = {.index = 40, .length = 1},
  [34] = {.index = 41, .length = 1},
  [35] = {.index = 42, .length = 2},
  [36] = {.index = 44, .length = 1},
  [37] = {.index = 45, .length = 1},
  [38] = {.index = 46, .length = 1},
  [39] = {.index = 47, .length = 1},
  [40] = {.index = 48, .length = 1},
  [41] = {.index = 49, .length = 1},
  [42] = {.index = 50, .length = 2},
  [43] = {.index = 52, .length = 3},
  [44] = {.index = 55, .length = 4},
  [45] = {.index = 59, .length = 2},
  [46] = {.index = 61, .length = 2},
  [47] = {.index = 63, .length = 1},
  [48] = {.index = 64, .length = 3},
  [49] = {.index = 67, .length = 2},
  [50] = {.index = 69, .length = 4},
  [51] = {.index = 73, .length = 1},
  [52] = {.index = 74, .length = 1},
  [53] = {.index = 75, .length = 1},
  [54] = {.index = 76, .length = 1},
  [55] = {.index = 77, .length = 1},
  [56] = {.index = 78, .length = 2},
  [57] = {.index = 80, .length = 2},
  [58] = {.index = 82, .length = 2},
  [59] = {.index = 84, .length = 1},
  [60] = {.index = 85, .length = 2},
  [61] = {.index = 87, .length = 2},
  [62] = {.index = 89, .length = 1},
  [63] = {.index = 90, .length = 2},
  [64] = {.index = 92, .length = 2},
  [65] = {.index = 94, .length = 2},
  [66] = {.index = 96, .length = 3},
  [67] = {.index = 99, .length = 1},
  [68] = {.index = 100, .length = 1},
  [69] = {.index = 101, .length = 2},
  [70] = {.index = 103, .length = 1},
  [71] = {.index = 104, .length = 1},
  [72] = {.index = 105, .length = 1},
  [73] = {.index = 106, .length = 7},
  [74] = {.index = 113, .length = 1},
  [75] = {.index = 114, .length = 1},
  [76] = {.index = 115, .length = 3},
  [77] = {.index = 118, .length = 3},
  [78] = {.index = 121, .length = 2},
  [79] = {.index = 123, .length = 2},
  [80] = {.index = 125, .length = 1},
  [81] = {.index = 126, .length = 1},
  [82] = {.index = 127, .length = 1},
  [83] = {.index = 128, .length = 2},
  [84] = {.index = 130, .length = 3},
  [85] = {.index = 133, .length = 2},
  [86] = {.index = 135, .length = 4},
  [87] = {.index = 139, .length = 1},
  [88] = {.index = 140, .length = 2},
  [89] = {.index = 142, .length = 3},
  [90] = {.index = 145, .length = 4},
  [91] = {.index = 149, .length = 6},
  [92] = {.index = 155, .length = 4},
  [93] = {.index = 159, .length = 4},
  [94] = {.index = 163, .length = 3},
  [95] = {.index = 166, .length = 2},
  [96] = {.index = 168, .length = 2},
  [97] = {.index = 170, .length = 2},
  [98] = {.index = 172, .length = 3},
  [99] = {.index = 175, .length = 2},
  [100] = {.index = 177, .length = 1},
  [101] = {.index = 178, .length = 3},
  [102] = {.index = 181, .length = 3},
  [103] = {.index = 184, .length = 3},
  [104] = {.index = 187, .length = 3},
  [105] = {.index = 190, .length = 6},
  [106] = {.index = 196, .length = 2},
  [107] = {.index = 198, .length = 3},
  [108] = {.index = 201, .length = 4},
  [109] = {.index = 205, .length = 1},
  [110] = {.index = 206, .length = 3},
  [111] = {.index = 209, .length = 4},
  [112] = {.index = 213, .length = 2},
  [113] = {.index = 215, .length = 3},
  [114] = {.index = 218, .length = 2},
  [115] = {.index = 220, .length = 3},
  [116] = {.index = 223, .length = 2},
  [117] = {.index = 225, .length = 4},
  [118] = {.index = 229, .length = 2},
  [119] = {.index = 231, .length = 3},
  [120] = {.index = 234, .length = 4},
  [121] = {.index = 238, .length = 5},
  [122] = {.index = 243, .length = 3},
  [123] = {.index = 246, .length = 3},
  [124] = {.index = 249, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_fileName, 1},
  [2] =
    {field_serial_dialog_name, 1},
  [3] =
    {field_dialog_name, 1},
  [4] =
    {field_script_name, 1},
  [5] =
    {field_label, 0},
  [6] =
    {field_script, 1},
  [7] =
    {field_duration, 1},
  [8] =
    {field_glitched, 1},
  [9] =
    {field_label, 0},
    {field_value, 2},
  [11] =
    {field_serial_message, 0},
  [12] =
    {field_serial_message, 0, .inherited = true},
  [13] =
    {field_camera, 1},
  [14] =
    {field_entity, 1},
    {field_glitched, 2},
  [16] =
    {field_map, 2},
  [17] =
    {field_slot, 2},
  [18] =
    {field_label, 2},
  [19] =
    {field_index, 2},
  [20] =
    {field_serial_dialog_name, 2},
  [21] =
    {field_dialog_name, 2},
  [22] =
    {field_command, 2},
  [23] =
    {field_alias, 2},
  [24] =
    {field_script, 2},
  [25] =
    {field_camera, 0},
  [26] =
    {field_bool, 0},
  [27] =
    {field_bool, 2},
    {field_setable, 0},
  [29] =
    {field_identifier, 0},
  [30] =
    {field_identifier, 2},
    {field_setable, 0},
  [32] =
    {field_constant, 0},
  [33] =
    {field_constant, 2},
    {field_setable, 0},
  [35] =
    {field_setable, 0},
  [36] =
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
    {field_setable, 0},
  [40] =
    {field_wrap, 1},
  [41] =
    {field_serial_message, 1, .inherited = true},
  [42] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [44] =
    {field_entity, 1},
  [45] =
    {field_name, 1},
  [46] =
    {field_message, 0},
  [47] =
    {field_message, 1, .inherited = true},
  [48] =
    {field_entity, 2},
  [49] =
    {field_entity, 2, .inherited = true},
  [50] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
  [52] =
    {field_camera, 1},
    {field_camera, 2, .inherited = true},
    {field_entity, 2, .inherited = true},
  [55] =
    {field_camera, 0, .inherited = true},
    {field_camera, 1, .inherited = true},
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
  [59] =
    {field_entity, 2},
    {field_script, 3},
  [61] =
    {field_camera, 0},
    {field_forever, 3},
  [63] =
    {field_forever, 3},
  [64] =
    {field_bool, 1, .inherited = true},
    {field_constant, 1, .inherited = true},
    {field_identifier, 1, .inherited = true},
  [67] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [69] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [73] =
    {field_portrait, 1},
  [74] =
    {field_alignment, 1},
  [75] =
    {field_border_tileset, 1},
  [76] =
    {field_emote, 1},
  [77] =
    {field_message, 2, .inherited = true},
  [78] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [80] =
    {field_entity, 2},
    {field_entity, 3, .inherited = true},
  [82] =
    {field_camera, 3, .inherited = true},
    {field_entity, 3, .inherited = true},
  [84] =
    {field_dialog_name, 3},
  [85] =
    {field_argument, 4},
    {field_command, 2},
  [87] =
    {field_animation, 3},
    {field_count, 4},
  [89] =
    {field_forever, 4},
  [90] =
    {field_camera, 0},
    {field_forever, 4},
  [92] =
    {field_camera, 0},
    {field_duration, 4},
  [94] =
    {field_camera, 0},
    {field_entity, 3},
  [96] =
    {field_camera, 0},
    {field_geometry, 3},
    {field_target, 4},
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
    {field_binary_operator, 1},
    {field_bool, 0, .inherited = true},
    {field_bool, 2, .inherited = true},
    {field_constant, 0, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [113] =
    {field_target_label, 1},
  [114] =
    {field_target_entity, 1},
  [115] =
    {field_camera, 4, .inherited = true},
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
    {field_camera, 0},
    {field_entity, 3},
    {field_forever, 5},
  [133] =
    {field_camera, 0},
    {field_duration, 5},
  [135] =
    {field_camera, 0},
    {field_forever, 5},
    {field_geometry, 3},
    {field_target, 4},
  [139] =
    {field_forever, 1},
  [140] =
    {field_entity, 3},
    {field_forever, 5},
  [142] =
    {field_forever, 5},
    {field_geometry, 3},
    {field_target, 4},
  [145] =
    {field_bool, 1},
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [149] =
    {field_bool, 0, .inherited = true},
    {field_bool, 1, .inherited = true},
    {field_constant, 0, .inherited = true},
    {field_constant, 1, .inherited = true},
    {field_identifier, 0, .inherited = true},
    {field_identifier, 1, .inherited = true},
  [155] =
    {field_bool, 2, .inherited = true},
    {field_constant, 2, .inherited = true},
    {field_identifier, 1},
    {field_identifier, 2, .inherited = true},
  [159] =
    {field_bool, 2, .inherited = true},
    {field_constant, 1},
    {field_constant, 2, .inherited = true},
    {field_identifier, 2, .inherited = true},
  [163] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [166] =
    {field_entity, 1},
    {field_forever, 6},
  [168] =
    {field_duration, 6},
    {field_entity, 1},
  [170] =
    {field_entity, 1},
    {field_entity, 5},
  [172] =
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
  [175] =
    {field_entity, 4},
    {field_forever, 6},
  [177] =
    {field_duration, 6},
  [178] =
    {field_forever, 6},
    {field_geometry, 4},
    {field_target, 5},
  [181] =
    {field_color, 4},
    {field_duration, 6},
    {field_fade, 2},
  [184] =
    {field_amplitude, 3},
    {field_distance, 4},
    {field_duration, 6},
  [187] =
    {field_entity, 3, .inherited = true},
    {field_geometry, 3, .inherited = true},
    {field_target, 3, .inherited = true},
  [190] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
    {field_geometry, 0, .inherited = true},
    {field_geometry, 1, .inherited = true},
    {field_target, 0, .inherited = true},
    {field_target, 1, .inherited = true},
  [196] =
    {field_geometry, 2},
    {field_target, 3},
  [198] =
    {field_camera, 0},
    {field_duration, 6},
    {field_entity, 3},
  [201] =
    {field_camera, 0},
    {field_duration, 6},
    {field_geometry, 3},
    {field_target, 4},
  [205] =
    {field_duration, 2},
  [206] =
    {field_duration, 2, .inherited = true},
    {field_forever, 1},
    {field_forever, 2, .inherited = true},
  [209] =
    {field_duration, 0, .inherited = true},
    {field_duration, 1, .inherited = true},
    {field_forever, 0, .inherited = true},
    {field_forever, 1, .inherited = true},
  [213] =
    {field_duration, 6},
    {field_entity, 3},
  [215] =
    {field_duration, 6},
    {field_geometry, 3},
    {field_target, 4},
  [218] =
    {field_label, 1},
    {field_script, 3},
  [220] =
    {field_entity, 1},
    {field_entity, 5},
    {field_forever, 7},
  [223] =
    {field_duration, 7},
    {field_entity, 1},
  [225] =
    {field_entity, 1},
    {field_forever, 7},
    {field_geometry, 5},
    {field_target, 6},
  [229] =
    {field_duration, 7},
    {field_entity, 4},
  [231] =
    {field_duration, 7},
    {field_geometry, 4},
    {field_target, 5},
  [234] =
    {field_entity, 2},
    {field_entity, 4, .inherited = true},
    {field_geometry, 4, .inherited = true},
    {field_target, 4, .inherited = true},
  [238] =
    {field_entity, 4, .inherited = true},
    {field_geometry, 2},
    {field_geometry, 4, .inherited = true},
    {field_target, 3},
    {field_target, 4, .inherited = true},
  [243] =
    {field_duration, 2},
    {field_duration, 3, .inherited = true},
    {field_forever, 3, .inherited = true},
  [246] =
    {field_duration, 8},
    {field_entity, 1},
    {field_entity, 5},
  [249] =
    {field_duration, 8},
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [74] = {
    [2] = alias_sym_label_settings,
  },
  [75] = {
    [2] = alias_sym_entity_settings,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_dialog_settings_block, 3,
    sym_dialog_settings_block,
    alias_sym_entity_settings,
    alias_sym_label_settings,
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
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
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
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
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
  [73] = 73,
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
  [115] = 103,
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
  [130] = 130,
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
  [196] = 196,
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
  [217] = 217,
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
  [333] = 333,
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
  [521] = 521,
  [522] = 522,
  [523] = 523,
  [524] = 524,
  [525] = 525,
  [526] = 526,
  [527] = 527,
  [528] = 528,
  [529] = 529,
  [530] = 530,
  [531] = 531,
  [532] = 532,
  [533] = 533,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(361);
      ADVANCE_MAP(
        '!', 662,
        '"', 7,
        '#', 649,
        '$', 358,
        '&', 10,
        '(', 663,
        ')', 664,
        '+', 685,
        ',', 367,
        '-', 14,
        '/', 11,
        ':', 654,
        ';', 623,
        '=', 624,
        '>', 647,
        'I', 216,
        '[', 366,
        ']', 368,
        '_', 648,
        'a', 73,
        'b', 183,
        'c', 23,
        'd', 90,
        'e', 206,
        'f', 24,
        'g', 112,
        'h', 91,
        'i', 218,
        'j', 294,
        'l', 25,
        'm', 26,
        'n', 51,
        'o', 220,
        'p', 27,
        'r', 41,
        's', 28,
        't', 152,
        'u', 221,
        'w', 53,
        'y', 130,
        '{', 630,
        '|', 354,
        '}', 631,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(608);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '!', 662,
        '"', 7,
        '#', 355,
        '$', 358,
        '(', 663,
        '/', 11,
        '[', 366,
        ']', 368,
        'b', 498,
        'c', 505,
        'f', 396,
        'g', 567,
        'm', 392,
        'o', 462,
        'r', 453,
        't', 472,
        'w', 473,
        'y', 455,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(608);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(358);
      if (lookahead == ')') ADVANCE(664);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '[') ADVANCE(366);
      if (lookahead == ']') ADVANCE(368);
      if (lookahead == 'w') ADVANCE(564);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(611);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(358);
      if (lookahead == ',') ADVANCE(367);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '[') ADVANCE(366);
      if (lookahead == ']') ADVANCE(368);
      if (lookahead == '{') ADVANCE(630);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(358);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '[') ADVANCE(366);
      if (lookahead == 'i') ADVANCE(528);
      if (lookahead == 'l') ADVANCE(382);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 7,
        ')', 664,
        '-', 15,
        '/', 11,
        'I', 216,
        '[', 366,
        ']', 368,
        'c', 22,
        'e', 217,
        'f', 49,
        'g', 111,
        'i', 228,
        'm', 40,
        'n', 332,
        'o', 333,
        'p', 205,
        's', 127,
        't', 273,
        '{', 630,
        '}', 631,
        '#', 648,
        '_', 648,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(656);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '>') ADVANCE(647);
      if (lookahead == 'e') ADVANCE(521);
      if (lookahead == 'n') ADVANCE(399);
      if (lookahead == '}') ADVANCE(631);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(607);
      if (lookahead == '\\') ADVANCE(359);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '#', 355,
        '$', 358,
        '/', 11,
        ';', 623,
        '[', 366,
        ']', 368,
        'b', 190,
        'c', 351,
        'g', 272,
        'm', 46,
        'o', 219,
        'r', 124,
        't', 153,
        'w', 154,
        'y', 130,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(615);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '$', 358,
        ')', 664,
        ',', 367,
        '/', 11,
        '[', 366,
        ']', 368,
        'b', 500,
        'c', 377,
        'd', 433,
        'e', 520,
        'f', 501,
        'g', 537,
        'h', 434,
        'j', 570,
        'l', 477,
        'p', 381,
        'r', 384,
        's', 378,
        'u', 516,
        'w', 383,
        '}', 631,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(609);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 10:
      if (lookahead == '&') ADVANCE(743);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(363);
      END_STATE();
    case 12:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead == '/') ADVANCE(362);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '>') ADVANCE(714);
      if (lookahead == 'I') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(656);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(656);
      END_STATE();
    case 16:
      if (lookahead == 'N') ADVANCE(54);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(64);
      END_STATE();
    case 18:
      if (lookahead == '_') ADVANCE(72);
      END_STATE();
    case 19:
      if (lookahead == '_') ADVANCE(209);
      END_STATE();
    case 20:
      if (lookahead == '_') ADVANCE(70);
      END_STATE();
    case 21:
      if (lookahead == '_') ADVANCE(323);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(214);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(214);
      if (lookahead == 'l') ADVANCE(243);
      if (lookahead == 'o') ADVANCE(207);
      if (lookahead == 'y') ADVANCE(43);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(83);
      if (lookahead == 'l') ADVANCE(34);
      if (lookahead == 'o') ADVANCE(278);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(63);
      if (lookahead == 'e') ADVANCE(229);
      if (lookahead == 'i') ADVANCE(137);
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(145);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(339);
      if (lookahead == 'l') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(277);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(341);
      if (lookahead == 'c') ADVANCE(279);
      if (lookahead == 'e') ADVANCE(192);
      if (lookahead == 'h') ADVANCE(31);
      if (lookahead == 'l') ADVANCE(247);
      if (lookahead == 'p') ADVANCE(287);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(352);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(616);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(182);
      if (lookahead == 'o') ADVANCE(344);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(264);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(711);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(138);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(195);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(66);
      if (lookahead == 'o') ADVANCE(67);
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(66);
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(291);
      if (lookahead == 'g') ADVANCE(239);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(263);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(230);
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(336);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(222);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(79);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(194);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(144);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(231);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(304);
      END_STATE();
    case 49:
      if (lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 50:
      if (lookahead == 'a') ADVANCE(280);
      END_STATE();
    case 51:
      if (lookahead == 'a') ADVANCE(210);
      if (lookahead == 'u') ADVANCE(193);
      END_STATE();
    case 52:
      if (lookahead == 'a') ADVANCE(296);
      END_STATE();
    case 53:
      if (lookahead == 'a') ADVANCE(164);
      if (lookahead == 'h') ADVANCE(166);
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 54:
      if (lookahead == 'a') ADVANCE(212);
      END_STATE();
    case 55:
      if (lookahead == 'a') ADVANCE(172);
      END_STATE();
    case 56:
      if (lookahead == 'a') ADVANCE(340);
      END_STATE();
    case 57:
      if (lookahead == 'a') ADVANCE(353);
      END_STATE();
    case 58:
      if (lookahead == 'a') ADVANCE(202);
      END_STATE();
    case 59:
      if (lookahead == 'a') ADVANCE(331);
      END_STATE();
    case 60:
      if (lookahead == 'a') ADVANCE(204);
      END_STATE();
    case 61:
      if (lookahead == 'b') ADVANCE(334);
      if (lookahead == 'f') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(132);
      END_STATE();
    case 62:
      if (lookahead == 'b') ADVANCE(257);
      END_STATE();
    case 63:
      if (lookahead == 'b') ADVANCE(116);
      END_STATE();
    case 64:
      if (lookahead == 'c') ADVANCE(198);
      if (lookahead == 'd') ADVANCE(178);
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 65:
      if (lookahead == 'c') ADVANCE(151);
      END_STATE();
    case 66:
      if (lookahead == 'c') ADVANCE(180);
      END_STATE();
    case 67:
      if (lookahead == 'c') ADVANCE(181);
      END_STATE();
    case 68:
      if (lookahead == 'c') ADVANCE(48);
      END_STATE();
    case 69:
      if (lookahead == 'c') ADVANCE(92);
      END_STATE();
    case 70:
      if (lookahead == 'c') ADVANCE(259);
      END_STATE();
    case 71:
      if (lookahead == 'c') ADVANCE(261);
      END_STATE();
    case 72:
      if (lookahead == 'c') ADVANCE(262);
      if (lookahead == 'd') ADVANCE(179);
      END_STATE();
    case 73:
      if (lookahead == 'd') ADVANCE(74);
      if (lookahead == 'l') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(157);
      END_STATE();
    case 74:
      if (lookahead == 'd') ADVANCE(625);
      END_STATE();
    case 75:
      if (lookahead == 'd') ADVANCE(616);
      END_STATE();
    case 76:
      if (lookahead == 'd') ADVANCE(616);
      if (lookahead == 't') ADVANCE(335);
      END_STATE();
    case 77:
      if (lookahead == 'd') ADVANCE(671);
      END_STATE();
    case 78:
      if (lookahead == 'd') ADVANCE(665);
      END_STATE();
    case 79:
      if (lookahead == 'd') ADVANCE(667);
      END_STATE();
    case 80:
      if (lookahead == 'd') ADVANCE(684);
      END_STATE();
    case 81:
      if (lookahead == 'd') ADVANCE(726);
      END_STATE();
    case 82:
      if (lookahead == 'd') ADVANCE(737);
      END_STATE();
    case 83:
      if (lookahead == 'd') ADVANCE(94);
      if (lookahead == 'l') ADVANCE(297);
      END_STATE();
    case 84:
      if (lookahead == 'd') ADVANCE(95);
      END_STATE();
    case 85:
      if (lookahead == 'd') ADVANCE(173);
      END_STATE();
    case 86:
      if (lookahead == 'd') ADVANCE(106);
      END_STATE();
    case 87:
      if (lookahead == 'd') ADVANCE(107);
      END_STATE();
    case 88:
      if (lookahead == 'd') ADVANCE(110);
      END_STATE();
    case 89:
      if (lookahead == 'd') ADVANCE(118);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(345);
      if (lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(614);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(616);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(713);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(687);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(641);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(691);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(657);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(700);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(646);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(694);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(658);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(707);
      END_STATE();
    case 104:
      if (lookahead == 'e') ADVANCE(719);
      END_STATE();
    case 105:
      if (lookahead == 'e') ADVANCE(682);
      END_STATE();
    case 106:
      if (lookahead == 'e') ADVANCE(689);
      END_STATE();
    case 107:
      if (lookahead == 'e') ADVANCE(621);
      END_STATE();
    case 108:
      if (lookahead == 'e') ADVANCE(709);
      END_STATE();
    case 109:
      if (lookahead == 'e') ADVANCE(741);
      END_STATE();
    case 110:
      if (lookahead == 'e') ADVANCE(733);
      END_STATE();
    case 111:
      if (lookahead == 'e') ADVANCE(258);
      END_STATE();
    case 112:
      if (lookahead == 'e') ADVANCE(258);
      if (lookahead == 'l') ADVANCE(162);
      if (lookahead == 'o') ADVANCE(316);
      if (lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 113:
      if (lookahead == 'e') ADVANCE(347);
      END_STATE();
    case 114:
      if (lookahead == 'e') ADVANCE(267);
      END_STATE();
    case 115:
      if (lookahead == 'e') ADVANCE(286);
      END_STATE();
    case 116:
      if (lookahead == 'e') ADVANCE(185);
      END_STATE();
    case 117:
      if (lookahead == 'e') ADVANCE(222);
      END_STATE();
    case 118:
      if (lookahead == 'e') ADVANCE(274);
      END_STATE();
    case 119:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 120:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 121:
      if (lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 122:
      if (lookahead == 'e') ADVANCE(269);
      END_STATE();
    case 123:
      if (lookahead == 'e') ADVANCE(233);
      END_STATE();
    case 124:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 125:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 126:
      if (lookahead == 'e') ADVANCE(318);
      END_STATE();
    case 127:
      if (lookahead == 'e') ADVANCE(191);
      END_STATE();
    case 128:
      if (lookahead == 'e') ADVANCE(271);
      END_STATE();
    case 129:
      if (lookahead == 'e') ADVANCE(309);
      END_STATE();
    case 130:
      if (lookahead == 'e') ADVANCE(201);
      END_STATE();
    case 131:
      if (lookahead == 'e') ADVANCE(342);
      END_STATE();
    case 132:
      if (lookahead == 'e') ADVANCE(327);
      END_STATE();
    case 133:
      if (lookahead == 'e') ADVANCE(235);
      END_STATE();
    case 134:
      if (lookahead == 'e') ADVANCE(300);
      END_STATE();
    case 135:
      if (lookahead == 'f') ADVANCE(705);
      END_STATE();
    case 136:
      if (lookahead == 'f') ADVANCE(163);
      END_STATE();
    case 137:
      if (lookahead == 'g') ADVANCE(150);
      END_STATE();
    case 138:
      if (lookahead == 'g') ADVANCE(16);
      END_STATE();
    case 139:
      if (lookahead == 'g') ADVANCE(660);
      END_STATE();
    case 140:
      if (lookahead == 'g') ADVANCE(634);
      END_STATE();
    case 141:
      if (lookahead == 'g') ADVANCE(627);
      END_STATE();
    case 142:
      if (lookahead == 'g') ADVANCE(19);
      END_STATE();
    case 143:
      if (lookahead == 'g') ADVANCE(292);
      END_STATE();
    case 144:
      if (lookahead == 'g') ADVANCE(123);
      END_STATE();
    case 145:
      if (lookahead == 'g') ADVANCE(123);
      if (lookahead == 'p') ADVANCE(673);
      END_STATE();
    case 146:
      if (lookahead == 'g') ADVANCE(311);
      END_STATE();
    case 147:
      if (lookahead == 'g') ADVANCE(168);
      END_STATE();
    case 148:
      if (lookahead == 'h') ADVANCE(723);
      END_STATE();
    case 149:
      if (lookahead == 'h') ADVANCE(176);
      if (lookahead == 'p') ADVANCE(56);
      END_STATE();
    case 150:
      if (lookahead == 'h') ADVANCE(315);
      END_STATE();
    case 151:
      if (lookahead == 'h') ADVANCE(120);
      END_STATE();
    case 152:
      if (lookahead == 'h') ADVANCE(276);
      if (lookahead == 'r') ADVANCE(337);
      if (lookahead == 'w') ADVANCE(155);
      END_STATE();
    case 153:
      if (lookahead == 'h') ADVANCE(276);
      if (lookahead == 'w') ADVANCE(155);
      END_STATE();
    case 154:
      if (lookahead == 'h') ADVANCE(166);
      END_STATE();
    case 155:
      if (lookahead == 'i') ADVANCE(69);
      END_STATE();
    case 156:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 157:
      if (lookahead == 'i') ADVANCE(208);
      END_STATE();
    case 158:
      if (lookahead == 'i') ADVANCE(346);
      if (lookahead == 'x') ADVANCE(612);
      END_STATE();
    case 159:
      if (lookahead == 'i') ADVANCE(266);
      END_STATE();
    case 160:
      if (lookahead == 'i') ADVANCE(265);
      END_STATE();
    case 161:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 162:
      if (lookahead == 'i') ADVANCE(314);
      END_STATE();
    case 163:
      if (lookahead == 'i') ADVANCE(240);
      END_STATE();
    case 164:
      if (lookahead == 'i') ADVANCE(303);
      END_STATE();
    case 165:
      if (lookahead == 'i') ADVANCE(200);
      END_STATE();
    case 166:
      if (lookahead == 'i') ADVANCE(313);
      END_STATE();
    case 167:
      if (lookahead == 'i') ADVANCE(310);
      END_STATE();
    case 168:
      if (lookahead == 'i') ADVANCE(224);
      END_STATE();
    case 169:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 170:
      if (lookahead == 'i') ADVANCE(232);
      END_STATE();
    case 171:
      if (lookahead == 'i') ADVANCE(312);
      END_STATE();
    case 172:
      if (lookahead == 'i') ADVANCE(307);
      END_STATE();
    case 173:
      if (lookahead == 'i') ADVANCE(317);
      END_STATE();
    case 174:
      if (lookahead == 'i') ADVANCE(255);
      END_STATE();
    case 175:
      if (lookahead == 'i') ADVANCE(320);
      END_STATE();
    case 176:
      if (lookahead == 'i') ADVANCE(86);
      END_STATE();
    case 177:
      if (lookahead == 'i') ADVANCE(256);
      END_STATE();
    case 178:
      if (lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 179:
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 180:
      if (lookahead == 'k') ADVANCE(616);
      END_STATE();
    case 181:
      if (lookahead == 'k') ADVANCE(696);
      END_STATE();
    case 182:
      if (lookahead == 'k') ADVANCE(104);
      END_STATE();
    case 183:
      if (lookahead == 'l') ADVANCE(36);
      if (lookahead == 'o') ADVANCE(289);
      END_STATE();
    case 184:
      if (lookahead == 'l') ADVANCE(659);
      END_STATE();
    case 185:
      if (lookahead == 'l') ADVANCE(637);
      END_STATE();
    case 186:
      if (lookahead == 'l') ADVANCE(735);
      END_STATE();
    case 187:
      if (lookahead == 'l') ADVANCE(729);
      END_STATE();
    case 188:
      if (lookahead == 'l') ADVANCE(727);
      END_STATE();
    case 189:
      if (lookahead == 'l') ADVANCE(739);
      END_STATE();
    case 190:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 191:
      if (lookahead == 'l') ADVANCE(135);
      END_STATE();
    case 192:
      if (lookahead == 'l') ADVANCE(135);
      if (lookahead == 'r') ADVANCE(169);
      if (lookahead == 't') ADVANCE(329);
      END_STATE();
    case 193:
      if (lookahead == 'l') ADVANCE(184);
      END_STATE();
    case 194:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 195:
      if (lookahead == 'l') ADVANCE(245);
      END_STATE();
    case 196:
      if (lookahead == 'l') ADVANCE(338);
      END_STATE();
    case 197:
      if (lookahead == 'l') ADVANCE(242);
      END_STATE();
    case 198:
      if (lookahead == 'l') ADVANCE(160);
      if (lookahead == 'o') ADVANCE(234);
      END_STATE();
    case 199:
      if (lookahead == 'l') ADVANCE(306);
      END_STATE();
    case 200:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 201:
      if (lookahead == 'l') ADVANCE(197);
      END_STATE();
    case 202:
      if (lookahead == 'l') ADVANCE(248);
      END_STATE();
    case 203:
      if (lookahead == 'l') ADVANCE(297);
      END_STATE();
    case 204:
      if (lookahead == 'l') ADVANCE(249);
      END_STATE();
    case 205:
      if (lookahead == 'l') ADVANCE(57);
      END_STATE();
    case 206:
      if (lookahead == 'm') ADVANCE(244);
      if (lookahead == 'n') ADVANCE(330);
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 207:
      if (lookahead == 'm') ADVANCE(213);
      if (lookahead == 'n') ADVANCE(68);
      END_STATE();
    case 208:
      if (lookahead == 'm') ADVANCE(59);
      END_STATE();
    case 209:
      if (lookahead == 'm') ADVANCE(260);
      END_STATE();
    case 210:
      if (lookahead == 'm') ADVANCE(96);
      END_STATE();
    case 211:
      if (lookahead == 'm') ADVANCE(126);
      END_STATE();
    case 212:
      if (lookahead == 'm') ADVANCE(109);
      END_STATE();
    case 213:
      if (lookahead == 'm') ADVANCE(47);
      END_STATE();
    case 214:
      if (lookahead == 'm') ADVANCE(115);
      END_STATE();
    case 215:
      if (lookahead == 'm') ADVANCE(133);
      END_STATE();
    case 216:
      if (lookahead == 'n') ADVANCE(136);
      END_STATE();
    case 217:
      if (lookahead == 'n') ADVANCE(330);
      END_STATE();
    case 218:
      if (lookahead == 'n') ADVANCE(717);
      END_STATE();
    case 219:
      if (lookahead == 'n') ADVANCE(69);
      END_STATE();
    case 220:
      if (lookahead == 'n') ADVANCE(69);
      if (lookahead == 'r') ADVANCE(161);
      if (lookahead == 'u') ADVANCE(301);
      if (lookahead == 'v') ADVANCE(114);
      END_STATE();
    case 221:
      if (lookahead == 'n') ADVANCE(149);
      END_STATE();
    case 222:
      if (lookahead == 'n') ADVANCE(616);
      END_STATE();
    case 223:
      if (lookahead == 'n') ADVANCE(652);
      END_STATE();
    case 224:
      if (lookahead == 'n') ADVANCE(722);
      END_STATE();
    case 225:
      if (lookahead == 'n') ADVANCE(669);
      END_STATE();
    case 226:
      if (lookahead == 'n') ADVANCE(725);
      END_STATE();
    case 227:
      if (lookahead == 'n') ADVANCE(720);
      END_STATE();
    case 228:
      if (lookahead == 'n') ADVANCE(716);
      END_STATE();
    case 229:
      if (lookahead == 'n') ADVANCE(146);
      END_STATE();
    case 230:
      if (lookahead == 'n') ADVANCE(78);
      END_STATE();
    case 231:
      if (lookahead == 'n') ADVANCE(80);
      END_STATE();
    case 232:
      if (lookahead == 'n') ADVANCE(143);
      END_STATE();
    case 233:
      if (lookahead == 'n') ADVANCE(325);
      END_STATE();
    case 234:
      if (lookahead == 'n') ADVANCE(319);
      END_STATE();
    case 235:
      if (lookahead == 'n') ADVANCE(308);
      END_STATE();
    case 236:
      if (lookahead == 'n') ADVANCE(321);
      END_STATE();
    case 237:
      if (lookahead == 'n') ADVANCE(322);
      END_STATE();
    case 238:
      if (lookahead == 'n') ADVANCE(324);
      END_STATE();
    case 239:
      if (lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 240:
      if (lookahead == 'n') ADVANCE(171);
      END_STATE();
    case 241:
      if (lookahead == 'o') ADVANCE(674);
      END_STATE();
    case 242:
      if (lookahead == 'o') ADVANCE(343);
      END_STATE();
    case 243:
      if (lookahead == 'o') ADVANCE(295);
      END_STATE();
    case 244:
      if (lookahead == 'o') ADVANCE(326);
      END_STATE();
    case 245:
      if (lookahead == 'o') ADVANCE(140);
      END_STATE();
    case 246:
      if (lookahead == 'o') ADVANCE(223);
      END_STATE();
    case 247:
      if (lookahead == 'o') ADVANCE(302);
      END_STATE();
    case 248:
      if (lookahead == 'o') ADVANCE(142);
      END_STATE();
    case 249:
      if (lookahead == 'o') ADVANCE(141);
      END_STATE();
    case 250:
      if (lookahead == 'o') ADVANCE(186);
      END_STATE();
    case 251:
      if (lookahead == 'o') ADVANCE(187);
      END_STATE();
    case 252:
      if (lookahead == 'o') ADVANCE(188);
      END_STATE();
    case 253:
      if (lookahead == 'o') ADVANCE(270);
      END_STATE();
    case 254:
      if (lookahead == 'o') ADVANCE(189);
      END_STATE();
    case 255:
      if (lookahead == 'o') ADVANCE(226);
      END_STATE();
    case 256:
      if (lookahead == 'o') ADVANCE(227);
      END_STATE();
    case 257:
      if (lookahead == 'o') ADVANCE(50);
      END_STATE();
    case 258:
      if (lookahead == 'o') ADVANCE(211);
      END_STATE();
    case 259:
      if (lookahead == 'o') ADVANCE(236);
      END_STATE();
    case 260:
      if (lookahead == 'o') ADVANCE(88);
      END_STATE();
    case 261:
      if (lookahead == 'o') ADVANCE(237);
      END_STATE();
    case 262:
      if (lookahead == 'o') ADVANCE(238);
      END_STATE();
    case 263:
      if (lookahead == 'p') ADVANCE(673);
      END_STATE();
    case 264:
      if (lookahead == 'p') ADVANCE(632);
      END_STATE();
    case 265:
      if (lookahead == 'p') ADVANCE(62);
      END_STATE();
    case 266:
      if (lookahead == 'p') ADVANCE(305);
      END_STATE();
    case 267:
      if (lookahead == 'r') ADVANCE(715);
      END_STATE();
    case 268:
      if (lookahead == 'r') ADVANCE(703);
      END_STATE();
    case 269:
      if (lookahead == 'r') ADVANCE(724);
      END_STATE();
    case 270:
      if (lookahead == 'r') ADVANCE(731);
      END_STATE();
    case 271:
      if (lookahead == 'r') ADVANCE(702);
      END_STATE();
    case 272:
      if (lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 273:
      if (lookahead == 'r') ADVANCE(337);
      END_STATE();
    case 274:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 275:
      if (lookahead == 'r') ADVANCE(350);
      END_STATE();
    case 276:
      if (lookahead == 'r') ADVANCE(155);
      END_STATE();
    case 277:
      if (lookahead == 'r') ADVANCE(328);
      if (lookahead == 's') ADVANCE(175);
      END_STATE();
    case 278:
      if (lookahead == 'r') ADVANCE(131);
      END_STATE();
    case 279:
      if (lookahead == 'r') ADVANCE(159);
      END_STATE();
    case 280:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 281:
      if (lookahead == 'r') ADVANCE(250);
      END_STATE();
    case 282:
      if (lookahead == 'r') ADVANCE(251);
      END_STATE();
    case 283:
      if (lookahead == 'r') ADVANCE(225);
      END_STATE();
    case 284:
      if (lookahead == 'r') ADVANCE(252);
      END_STATE();
    case 285:
      if (lookahead == 'r') ADVANCE(254);
      END_STATE();
    case 286:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 287:
      if (lookahead == 'r') ADVANCE(125);
      END_STATE();
    case 288:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 289:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 290:
      if (lookahead == 's') ADVANCE(610);
      END_STATE();
    case 291:
      if (lookahead == 's') ADVANCE(686);
      END_STATE();
    case 292:
      if (lookahead == 's') ADVANCE(629);
      END_STATE();
    case 293:
      if (lookahead == 's') ADVANCE(20);
      END_STATE();
    case 294:
      if (lookahead == 's') ADVANCE(246);
      END_STATE();
    case 295:
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 296:
      if (lookahead == 's') ADVANCE(101);
      END_STATE();
    case 297:
      if (lookahead == 's') ADVANCE(102);
      END_STATE();
    case 298:
      if (lookahead == 's') ADVANCE(103);
      END_STATE();
    case 299:
      if (lookahead == 's') ADVANCE(108);
      END_STATE();
    case 300:
      if (lookahead == 's') ADVANCE(129);
      END_STATE();
    case 301:
      if (lookahead == 't') ADVANCE(718);
      END_STATE();
    case 302:
      if (lookahead == 't') ADVANCE(693);
      END_STATE();
    case 303:
      if (lookahead == 't') ADVANCE(698);
      END_STATE();
    case 304:
      if (lookahead == 't') ADVANCE(680);
      END_STATE();
    case 305:
      if (lookahead == 't') ADVANCE(650);
      END_STATE();
    case 306:
      if (lookahead == 't') ADVANCE(636);
      END_STATE();
    case 307:
      if (lookahead == 't') ADVANCE(643);
      END_STATE();
    case 308:
      if (lookahead == 't') ADVANCE(644);
      END_STATE();
    case 309:
      if (lookahead == 't') ADVANCE(645);
      END_STATE();
    case 310:
      if (lookahead == 't') ADVANCE(348);
      END_STATE();
    case 311:
      if (lookahead == 't') ADVANCE(148);
      END_STATE();
    case 312:
      if (lookahead == 't') ADVANCE(349);
      END_STATE();
    case 313:
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 314:
      if (lookahead == 't') ADVANCE(65);
      END_STATE();
    case 315:
      if (lookahead == 't') ADVANCE(293);
      END_STATE();
    case 316:
      if (lookahead == 't') ADVANCE(241);
      END_STATE();
    case 317:
      if (lookahead == 't') ADVANCE(253);
      END_STATE();
    case 318:
      if (lookahead == 't') ADVANCE(275);
      END_STATE();
    case 319:
      if (lookahead == 't') ADVANCE(281);
      END_STATE();
    case 320:
      if (lookahead == 't') ADVANCE(174);
      END_STATE();
    case 321:
      if (lookahead == 't') ADVANCE(282);
      END_STATE();
    case 322:
      if (lookahead == 't') ADVANCE(284);
      END_STATE();
    case 323:
      if (lookahead == 't') ADVANCE(165);
      END_STATE();
    case 324:
      if (lookahead == 't') ADVANCE(285);
      END_STATE();
    case 325:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 326:
      if (lookahead == 't') ADVANCE(100);
      END_STATE();
    case 327:
      if (lookahead == 't') ADVANCE(105);
      END_STATE();
    case 328:
      if (lookahead == 't') ADVANCE(288);
      END_STATE();
    case 329:
      if (lookahead == 't') ADVANCE(170);
      END_STATE();
    case 330:
      if (lookahead == 't') ADVANCE(167);
      END_STATE();
    case 331:
      if (lookahead == 't') ADVANCE(177);
      END_STATE();
    case 332:
      if (lookahead == 'u') ADVANCE(193);
      END_STATE();
    case 333:
      if (lookahead == 'u') ADVANCE(301);
      END_STATE();
    case 334:
      if (lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 335:
      if (lookahead == 'u') ADVANCE(283);
      END_STATE();
    case 336:
      if (lookahead == 'u') ADVANCE(199);
      END_STATE();
    case 337:
      if (lookahead == 'u') ADVANCE(98);
      END_STATE();
    case 338:
      if (lookahead == 'u') ADVANCE(87);
      END_STATE();
    case 339:
      if (lookahead == 'u') ADVANCE(298);
      END_STATE();
    case 340:
      if (lookahead == 'u') ADVANCE(299);
      END_STATE();
    case 341:
      if (lookahead == 'v') ADVANCE(97);
      END_STATE();
    case 342:
      if (lookahead == 'v') ADVANCE(122);
      END_STATE();
    case 343:
      if (lookahead == 'w') ADVANCE(616);
      END_STATE();
    case 344:
      if (lookahead == 'w') ADVANCE(678);
      END_STATE();
    case 345:
      if (lookahead == 'x') ADVANCE(17);
      END_STATE();
    case 346:
      if (lookahead == 'x') ADVANCE(612);
      END_STATE();
    case 347:
      if (lookahead == 'x') ADVANCE(676);
      END_STATE();
    case 348:
      if (lookahead == 'y') ADVANCE(639);
      END_STATE();
    case 349:
      if (lookahead == 'y') ADVANCE(655);
      END_STATE();
    case 350:
      if (lookahead == 'y') ADVANCE(721);
      END_STATE();
    case 351:
      if (lookahead == 'y') ADVANCE(43);
      END_STATE();
    case 352:
      if (lookahead == 'y') ADVANCE(121);
      END_STATE();
    case 353:
      if (lookahead == 'y') ADVANCE(128);
      END_STATE();
    case 354:
      if (lookahead == '|') ADVANCE(744);
      END_STATE();
    case 355:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 356:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(619);
      END_STATE();
    case 357:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(356);
      END_STATE();
    case 358:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(620);
      END_STATE();
    case 359:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 360:
      if (eof) ADVANCE(361);
      ADVANCE_MAP(
        '$', 358,
        ',', 367,
        '/', 11,
        ';', 623,
        '[', 366,
        ']', 368,
        'a', 424,
        'd', 474,
        'i', 515,
        's', 406,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(360);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(613);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(363);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(363);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'N') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(511);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(490);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(510);
      if (lookahead == 'l') ADVANCE(535);
      if (lookahead == 'o') ADVANCE(522);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(599);
      if (lookahead == 'e') ADVANCE(493);
      if (lookahead == 'h') ADVANCE(531);
      if (lookahead == 'p') ADVANCE(559);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(605);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(712);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(597);
      if (lookahead == 'l') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(478);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(523);
      if (lookahead == 'e') ADVANCE(582);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(553);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(410);
      if (lookahead == 'u') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(514);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(561);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(579);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(512);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(572);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(513);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(504);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(598);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(595);
      if (lookahead == 'l') ADVANCE(450);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(545);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(556);
      if (lookahead == 'e') ADVANCE(568);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(489);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(502);
      if (lookahead == 'd') ADVANCE(487);
      if (lookahead == 'e') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(491);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(488);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(548);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(549);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(550);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(626);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(672);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(666);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(668);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(738);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(447);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(482);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(486);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(622);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(603);
      if (lookahead == 'i') ADVANCE(425);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(688);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(692);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(701);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(695);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(708);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(683);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(690);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(710);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(742);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(734);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(642);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(602);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(560);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(554);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(586);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(514);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(506);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(525);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(706);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(461);
      if (lookahead == 'n') ADVANCE(364);
      if (lookahead == 'p') ADVANCE(452);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(635);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(628);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(471);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(661);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(483);
      if (lookahead == 'p') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(581);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(558);
      if (lookahead == 'r') ADVANCE(596);
      if (lookahead == 'w') ADVANCE(479);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(551);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(552);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(465);
      if (lookahead == 'o') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(578);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(580);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(585);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(588);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(697);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(530);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(593);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(460);
      if (lookahead == 'r') ADVANCE(485);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(736);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(730);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(728);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(740);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(638);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(533);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(476);
      if (lookahead == 'o') ADVANCE(524);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(536);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(534);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(547);
      if (lookahead == 'y') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(540);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(575);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(448);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(546);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(443);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(470);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(653);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(670);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(589);
      if (lookahead == 'r') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(589);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(583);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(587);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(590);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(591);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(592);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(601);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(675);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(571);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(600);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(584);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(517);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(495);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(555);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(496);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(497);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(576);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(526);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 549:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(527);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 550:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(529);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 551:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(577);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 552:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 553:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(633);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 554:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(704);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 555:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(732);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 556:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(475);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 557:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(518);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 558:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(479);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(539);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(541);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(543);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(544);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 567:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 568:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(481);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 570:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(538);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 571:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 572:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 573:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 574:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 575:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 576:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(454);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 577:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(651);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 578:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(699);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 579:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(681);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 580:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(604);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 581:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(569);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 582:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(594);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 583:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(562);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 584:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(532);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 585:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(542);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 586:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 587:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 588:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 589:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 590:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(563);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 591:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(565);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 592:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(566);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 593:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 594:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(557);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 595:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 596:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 597:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(573);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 598:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(574);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 599:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 600:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(606);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 601:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(679);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 602:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(677);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 603:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(370);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 604:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(640);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 605:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(449);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 606:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 607:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 608:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(290);
      if (lookahead == 'p') ADVANCE(158);
      if (lookahead == 's') ADVANCE(610);
      if (lookahead == 'x') ADVANCE(614);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(608);
      END_STATE();
    case 609:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(609);
      END_STATE();
    case 610:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 611:
      ACCEPT_TOKEN(sym_DURATION);
      if (lookahead == 'm') ADVANCE(290);
      if (lookahead == 's') ADVANCE(610);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(611);
      END_STATE();
    case 612:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 613:
      ACCEPT_TOKEN(sym_DISTANCE);
      if (lookahead == 'p') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(613);
      END_STATE();
    case 614:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 615:
      ACCEPT_TOKEN(sym_QUANTITY);
      if (lookahead == 'x') ADVANCE(614);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(615);
      END_STATE();
    case 616:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 617:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(616);
      END_STATE();
    case 618:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(617);
      END_STATE();
    case 619:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(618);
      END_STATE();
    case 620:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(620);
      END_STATE();
    case 621:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 622:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 623:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 624:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 625:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 626:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 627:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 628:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 629:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 630:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 631:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 632:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 633:
      ACCEPT_TOKEN(anon_sym_wrap);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 634:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 635:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 636:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 637:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 638:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 639:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 640:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 641:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 642:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 643:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 644:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 645:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 646:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 647:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 648:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 649:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 650:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 651:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 652:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 653:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 654:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 655:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 656:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(656);
      END_STATE();
    case 657:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 658:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 659:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 660:
      ACCEPT_TOKEN(anon_sym_debug);
      END_STATE();
    case 661:
      ACCEPT_TOKEN(anon_sym_debug);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 662:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 663:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 664:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 665:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 666:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 667:
      ACCEPT_TOKEN(anon_sym_spread);
      END_STATE();
    case 668:
      ACCEPT_TOKEN(anon_sym_spread);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 669:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 670:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 671:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 672:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 673:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 674:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 675:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 676:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 677:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 678:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 679:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 680:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 681:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 682:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 683:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 684:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 685:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 686:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 687:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 688:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 689:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 690:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 691:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 692:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 693:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 694:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 695:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 696:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 697:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 698:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 699:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 700:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 701:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 702:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 703:
      ACCEPT_TOKEN(sym_player);
      if (lookahead == '_') ADVANCE(71);
      END_STATE();
    case 704:
      ACCEPT_TOKEN(sym_player);
      if (lookahead == '_') ADVANCE(414);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 705:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 706:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 707:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 708:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 709:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 710:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 711:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 712:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 713:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 714:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 715:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 716:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 717:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(196);
      if (lookahead == 'd') ADVANCE(113);
      END_STATE();
    case 718:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 719:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    case 720:
      ACCEPT_TOKEN(anon_sym_animation);
      END_STATE();
    case 721:
      ACCEPT_TOKEN(anon_sym_geometry);
      END_STATE();
    case 722:
      ACCEPT_TOKEN(sym_origin);
      END_STATE();
    case 723:
      ACCEPT_TOKEN(sym_length);
      END_STATE();
    case 724:
      ACCEPT_TOKEN(sym_forever);
      END_STATE();
    case 725:
      ACCEPT_TOKEN(anon_sym_position);
      END_STATE();
    case 726:
      ACCEPT_TOKEN(sym_glitched);
      END_STATE();
    case 727:
      ACCEPT_TOKEN(anon_sym_player_control);
      END_STATE();
    case 728:
      ACCEPT_TOKEN(anon_sym_player_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 729:
      ACCEPT_TOKEN(anon_sym_lights_control);
      END_STATE();
    case 730:
      ACCEPT_TOKEN(anon_sym_lights_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 731:
      ACCEPT_TOKEN(anon_sym_hex_editor);
      END_STATE();
    case 732:
      ACCEPT_TOKEN(anon_sym_hex_editor);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 733:
      ACCEPT_TOKEN(anon_sym_hex_dialog_mode);
      END_STATE();
    case 734:
      ACCEPT_TOKEN(anon_sym_hex_dialog_mode);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 735:
      ACCEPT_TOKEN(anon_sym_hex_control);
      END_STATE();
    case 736:
      ACCEPT_TOKEN(anon_sym_hex_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 737:
      ACCEPT_TOKEN(anon_sym_hex_clipboard);
      END_STATE();
    case 738:
      ACCEPT_TOKEN(anon_sym_hex_clipboard);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 739:
      ACCEPT_TOKEN(anon_sym_serial_control);
      END_STATE();
    case 740:
      ACCEPT_TOKEN(anon_sym_serial_control);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 741:
      ACCEPT_TOKEN(anon_sym_flagName);
      END_STATE();
    case 742:
      ACCEPT_TOKEN(anon_sym_flagName);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(606);
      END_STATE();
    case 743:
      ACCEPT_TOKEN(sym_AND);
      END_STATE();
    case 744:
      ACCEPT_TOKEN(sym_OR);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 360},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 9},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 9},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 9},
  [13] = {.lex_state = 9},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 9},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 360},
  [23] = {.lex_state = 360},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 5},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 360},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 360},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 360},
  [39] = {.lex_state = 360},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 360},
  [42] = {.lex_state = 360},
  [43] = {.lex_state = 360},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 360},
  [47] = {.lex_state = 360},
  [48] = {.lex_state = 360},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 360},
  [51] = {.lex_state = 360},
  [52] = {.lex_state = 360},
  [53] = {.lex_state = 360},
  [54] = {.lex_state = 360},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 6},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 360},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 6},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 6},
  [76] = {.lex_state = 5},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 6},
  [79] = {.lex_state = 5},
  [80] = {.lex_state = 6},
  [81] = {.lex_state = 6},
  [82] = {.lex_state = 6},
  [83] = {.lex_state = 6},
  [84] = {.lex_state = 360},
  [85] = {.lex_state = 6},
  [86] = {.lex_state = 5},
  [87] = {.lex_state = 5},
  [88] = {.lex_state = 5},
  [89] = {.lex_state = 5},
  [90] = {.lex_state = 5},
  [91] = {.lex_state = 5},
  [92] = {.lex_state = 5},
  [93] = {.lex_state = 5},
  [94] = {.lex_state = 5},
  [95] = {.lex_state = 360},
  [96] = {.lex_state = 5},
  [97] = {.lex_state = 5},
  [98] = {.lex_state = 360},
  [99] = {.lex_state = 5},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 5},
  [102] = {.lex_state = 5},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 5},
  [105] = {.lex_state = 5},
  [106] = {.lex_state = 5},
  [107] = {.lex_state = 5},
  [108] = {.lex_state = 360},
  [109] = {.lex_state = 5},
  [110] = {.lex_state = 5},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 5},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 5},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 5},
  [119] = {.lex_state = 3},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 5},
  [122] = {.lex_state = 3},
  [123] = {.lex_state = 3},
  [124] = {.lex_state = 3},
  [125] = {.lex_state = 3},
  [126] = {.lex_state = 5},
  [127] = {.lex_state = 3},
  [128] = {.lex_state = 5},
  [129] = {.lex_state = 3},
  [130] = {.lex_state = 5},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 5},
  [133] = {.lex_state = 5},
  [134] = {.lex_state = 3},
  [135] = {.lex_state = 5},
  [136] = {.lex_state = 5},
  [137] = {.lex_state = 5},
  [138] = {.lex_state = 5},
  [139] = {.lex_state = 5},
  [140] = {.lex_state = 6},
  [141] = {.lex_state = 5},
  [142] = {.lex_state = 5},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 3},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 1},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 5},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 5},
  [153] = {.lex_state = 5},
  [154] = {.lex_state = 9},
  [155] = {.lex_state = 3},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 9},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 9},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 5},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 2},
  [166] = {.lex_state = 8},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 3},
  [169] = {.lex_state = 3},
  [170] = {.lex_state = 3},
  [171] = {.lex_state = 3},
  [172] = {.lex_state = 8},
  [173] = {.lex_state = 3},
  [174] = {.lex_state = 8},
  [175] = {.lex_state = 3},
  [176] = {.lex_state = 5},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 2},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 3},
  [181] = {.lex_state = 3},
  [182] = {.lex_state = 8},
  [183] = {.lex_state = 3},
  [184] = {.lex_state = 5},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 2},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 2},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 1},
  [192] = {.lex_state = 1},
  [193] = {.lex_state = 1},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 5},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 3},
  [203] = {.lex_state = 9},
  [204] = {.lex_state = 360},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 8},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 2},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 3},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 3},
  [215] = {.lex_state = 3},
  [216] = {.lex_state = 2},
  [217] = {.lex_state = 5},
  [218] = {.lex_state = 2},
  [219] = {.lex_state = 2},
  [220] = {.lex_state = 2},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 2},
  [223] = {.lex_state = 2},
  [224] = {.lex_state = 2},
  [225] = {.lex_state = 2},
  [226] = {.lex_state = 1},
  [227] = {.lex_state = 1},
  [228] = {.lex_state = 1},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 2},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 8},
  [234] = {.lex_state = 2},
  [235] = {.lex_state = 2},
  [236] = {.lex_state = 3},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 2},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 2},
  [247] = {.lex_state = 2},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 2},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 5},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 9},
  [259] = {.lex_state = 8},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 3},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 3},
  [268] = {.lex_state = 3},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 0},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 3},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 2},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 3},
  [282] = {.lex_state = 3},
  [283] = {.lex_state = 0},
  [284] = {.lex_state = 3},
  [285] = {.lex_state = 3},
  [286] = {.lex_state = 0},
  [287] = {.lex_state = 0},
  [288] = {.lex_state = 0},
  [289] = {.lex_state = 0},
  [290] = {.lex_state = 0},
  [291] = {.lex_state = 3},
  [292] = {.lex_state = 3},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 0},
  [295] = {.lex_state = 0},
  [296] = {.lex_state = 0},
  [297] = {.lex_state = 0},
  [298] = {.lex_state = 0},
  [299] = {.lex_state = 0},
  [300] = {.lex_state = 0},
  [301] = {.lex_state = 0},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 0},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 0},
  [306] = {.lex_state = 0},
  [307] = {.lex_state = 0},
  [308] = {.lex_state = 0},
  [309] = {.lex_state = 0},
  [310] = {.lex_state = 3},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 0},
  [313] = {.lex_state = 5},
  [314] = {.lex_state = 9},
  [315] = {.lex_state = 3},
  [316] = {.lex_state = 3},
  [317] = {.lex_state = 3},
  [318] = {.lex_state = 3},
  [319] = {.lex_state = 0},
  [320] = {.lex_state = 0},
  [321] = {.lex_state = 0},
  [322] = {.lex_state = 3},
  [323] = {.lex_state = 0},
  [324] = {.lex_state = 0},
  [325] = {.lex_state = 9},
  [326] = {.lex_state = 0},
  [327] = {.lex_state = 0},
  [328] = {.lex_state = 0},
  [329] = {.lex_state = 3},
  [330] = {.lex_state = 0},
  [331] = {.lex_state = 0},
  [332] = {.lex_state = 2},
  [333] = {.lex_state = 0},
  [334] = {.lex_state = 8},
  [335] = {.lex_state = 0},
  [336] = {.lex_state = 0},
  [337] = {.lex_state = 0},
  [338] = {.lex_state = 3},
  [339] = {.lex_state = 0},
  [340] = {.lex_state = 0},
  [341] = {.lex_state = 0},
  [342] = {.lex_state = 0},
  [343] = {.lex_state = 8},
  [344] = {.lex_state = 360},
  [345] = {.lex_state = 0},
  [346] = {.lex_state = 0},
  [347] = {.lex_state = 3},
  [348] = {.lex_state = 0},
  [349] = {.lex_state = 0},
  [350] = {.lex_state = 3},
  [351] = {.lex_state = 0},
  [352] = {.lex_state = 0},
  [353] = {.lex_state = 0},
  [354] = {.lex_state = 0},
  [355] = {.lex_state = 0},
  [356] = {.lex_state = 3},
  [357] = {.lex_state = 3},
  [358] = {.lex_state = 3},
  [359] = {.lex_state = 3},
  [360] = {.lex_state = 3},
  [361] = {.lex_state = 0},
  [362] = {.lex_state = 3},
  [363] = {.lex_state = 0},
  [364] = {.lex_state = 0},
  [365] = {.lex_state = 0},
  [366] = {.lex_state = 9},
  [367] = {.lex_state = 0},
  [368] = {.lex_state = 3},
  [369] = {.lex_state = 3},
  [370] = {.lex_state = 0},
  [371] = {.lex_state = 3},
  [372] = {.lex_state = 0},
  [373] = {.lex_state = 3},
  [374] = {.lex_state = 3},
  [375] = {.lex_state = 3},
  [376] = {.lex_state = 0},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 0},
  [379] = {.lex_state = 0},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 0},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 0},
  [385] = {.lex_state = 0},
  [386] = {.lex_state = 0},
  [387] = {.lex_state = 0},
  [388] = {.lex_state = 0},
  [389] = {.lex_state = 0},
  [390] = {.lex_state = 0},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 5},
  [393] = {.lex_state = 3},
  [394] = {.lex_state = 0},
  [395] = {.lex_state = 8},
  [396] = {.lex_state = 0},
  [397] = {.lex_state = 3},
  [398] = {.lex_state = 5},
  [399] = {.lex_state = 8},
  [400] = {.lex_state = 0},
  [401] = {.lex_state = 360},
  [402] = {.lex_state = 0},
  [403] = {.lex_state = 0},
  [404] = {.lex_state = 0},
  [405] = {.lex_state = 3},
  [406] = {.lex_state = 3},
  [407] = {.lex_state = 0},
  [408] = {.lex_state = 2},
  [409] = {.lex_state = 0},
  [410] = {.lex_state = 0},
  [411] = {.lex_state = 0},
  [412] = {.lex_state = 0},
  [413] = {.lex_state = 0},
  [414] = {.lex_state = 1},
  [415] = {.lex_state = 8},
  [416] = {.lex_state = 0},
  [417] = {.lex_state = 8},
  [418] = {.lex_state = 0},
  [419] = {.lex_state = 360},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 3},
  [422] = {.lex_state = 3},
  [423] = {.lex_state = 0},
  [424] = {.lex_state = 3},
  [425] = {.lex_state = 3},
  [426] = {.lex_state = 3},
  [427] = {.lex_state = 0},
  [428] = {.lex_state = 0},
  [429] = {.lex_state = 0},
  [430] = {.lex_state = 0},
  [431] = {.lex_state = 0},
  [432] = {.lex_state = 9},
  [433] = {.lex_state = 0},
  [434] = {.lex_state = 0},
  [435] = {.lex_state = 0},
  [436] = {.lex_state = 0},
  [437] = {.lex_state = 0},
  [438] = {.lex_state = 0},
  [439] = {.lex_state = 0},
  [440] = {.lex_state = 3},
  [441] = {.lex_state = 3},
  [442] = {.lex_state = 0},
  [443] = {.lex_state = 3},
  [444] = {.lex_state = 0},
  [445] = {.lex_state = 0},
  [446] = {.lex_state = 0},
  [447] = {.lex_state = 0},
  [448] = {.lex_state = 0},
  [449] = {.lex_state = 0},
  [450] = {.lex_state = 0},
  [451] = {.lex_state = 0},
  [452] = {.lex_state = 0},
  [453] = {.lex_state = 0},
  [454] = {.lex_state = 0},
  [455] = {.lex_state = 0},
  [456] = {.lex_state = 0},
  [457] = {.lex_state = 0},
  [458] = {.lex_state = 2},
  [459] = {.lex_state = 0},
  [460] = {.lex_state = 0},
  [461] = {.lex_state = 0},
  [462] = {.lex_state = 0},
  [463] = {.lex_state = 0},
  [464] = {.lex_state = 0},
  [465] = {.lex_state = 0},
  [466] = {.lex_state = 0},
  [467] = {.lex_state = 0},
  [468] = {.lex_state = 0},
  [469] = {.lex_state = 0},
  [470] = {.lex_state = 0},
  [471] = {.lex_state = 0},
  [472] = {.lex_state = 0},
  [473] = {.lex_state = 0},
  [474] = {.lex_state = 0},
  [475] = {.lex_state = 0},
  [476] = {.lex_state = 9},
  [477] = {.lex_state = 3},
  [478] = {.lex_state = 0},
  [479] = {.lex_state = 0},
  [480] = {.lex_state = 0},
  [481] = {.lex_state = 3},
  [482] = {.lex_state = 0},
  [483] = {.lex_state = 0},
  [484] = {.lex_state = 0},
  [485] = {.lex_state = 0},
  [486] = {.lex_state = 0},
  [487] = {.lex_state = 0},
  [488] = {.lex_state = 0},
  [489] = {.lex_state = 0},
  [490] = {.lex_state = 0},
  [491] = {.lex_state = 0},
  [492] = {.lex_state = 0},
  [493] = {.lex_state = 0},
  [494] = {.lex_state = 0},
  [495] = {.lex_state = 0},
  [496] = {.lex_state = 9},
  [497] = {.lex_state = 0},
  [498] = {.lex_state = 9},
  [499] = {.lex_state = 0},
  [500] = {.lex_state = 0},
  [501] = {.lex_state = 8},
  [502] = {.lex_state = 8},
  [503] = {.lex_state = 360},
  [504] = {.lex_state = 0},
  [505] = {.lex_state = 0},
  [506] = {.lex_state = 0},
  [507] = {.lex_state = 0},
  [508] = {.lex_state = 0},
  [509] = {.lex_state = 0},
  [510] = {.lex_state = 0},
  [511] = {.lex_state = 0},
  [512] = {.lex_state = 0},
  [513] = {.lex_state = 0},
  [514] = {.lex_state = 0},
  [515] = {.lex_state = 0},
  [516] = {.lex_state = 0},
  [517] = {.lex_state = 0},
  [518] = {.lex_state = 0},
  [519] = {.lex_state = 0},
  [520] = {.lex_state = 0},
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
  [534] = {.lex_state = 0},
  [535] = {.lex_state = 0},
  [536] = {.lex_state = 0},
  [537] = {.lex_state = 0},
  [538] = {.lex_state = 0},
  [539] = {.lex_state = 0},
  [540] = {.lex_state = 0},
  [541] = {.lex_state = 0},
  [542] = {.lex_state = 0},
  [543] = {.lex_state = 0},
  [544] = {.lex_state = 0},
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
  [575] = {.lex_state = 0},
  [576] = {.lex_state = 0},
  [577] = {.lex_state = 0},
  [578] = {.lex_state = 0},
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
  [594] = {.lex_state = 0},
  [595] = {.lex_state = 0},
  [596] = {.lex_state = 0},
  [597] = {.lex_state = 0},
  [598] = {.lex_state = 0},
  [599] = {.lex_state = 0},
  [600] = {.lex_state = 0},
  [601] = {.lex_state = 0},
  [602] = {.lex_state = 0},
  [603] = {.lex_state = 0},
  [604] = {.lex_state = 0},
  [605] = {.lex_state = 0},
  [606] = {.lex_state = 0},
  [607] = {.lex_state = 0},
  [608] = {.lex_state = 0},
  [609] = {.lex_state = 0},
  [610] = {.lex_state = 0},
  [611] = {.lex_state = 0},
  [612] = {.lex_state = 0},
  [613] = {.lex_state = 3},
  [614] = {.lex_state = 0},
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
  [627] = {.lex_state = 0},
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
  [639] = {.lex_state = 0},
  [640] = {.lex_state = 0},
  [641] = {.lex_state = 0},
  [642] = {.lex_state = 0},
  [643] = {.lex_state = 0},
  [644] = {.lex_state = 0},
  [645] = {.lex_state = 0},
  [646] = {.lex_state = 0},
  [647] = {.lex_state = 0},
  [648] = {.lex_state = 0},
  [649] = {.lex_state = 0},
  [650] = {.lex_state = 0},
  [651] = {.lex_state = 0},
  [652] = {.lex_state = 0},
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
  [673] = {.lex_state = 0},
  [674] = {.lex_state = 0},
  [675] = {.lex_state = 0},
  [676] = {.lex_state = 0},
  [677] = {.lex_state = 0},
  [678] = {.lex_state = 0},
  [679] = {.lex_state = 0},
  [680] = {.lex_state = 0},
  [681] = {.lex_state = 0},
  [682] = {.lex_state = 0},
  [683] = {.lex_state = 0},
  [684] = {.lex_state = 0},
  [685] = {.lex_state = 0},
  [686] = {.lex_state = 0},
  [687] = {.lex_state = 0},
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
  [716] = {.lex_state = 0},
  [717] = {.lex_state = 0},
  [718] = {.lex_state = 0},
  [719] = {.lex_state = 0},
  [720] = {.lex_state = 0},
  [721] = {.lex_state = 0},
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
    [sym_json_number] = ACTIONS(1),
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
  },
  [1] = {
    [sym_source_file] = STATE(582),
    [sym_constant_expansion] = STATE(594),
    [sym__root] = STATE(22),
    [sym_include_macro] = STATE(22),
    [sym_constant_assignment] = STATE(22),
    [sym_add_serial_dialog_settings] = STATE(22),
    [sym_add_dialog_settings] = STATE(22),
    [sym_dialog_definition] = STATE(22),
    [sym_serial_dialog_definition] = STATE(22),
    [sym_script_definition] = STATE(22),
    [aux_sym_source_file_repeat1] = STATE(22),
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
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_BAREWORD] = ACTIONS(26),
    [anon_sym_RBRACE] = ACTIONS(29),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(34),
    [anon_sym_debug] = ACTIONS(37),
    [anon_sym_RPAREN] = ACTIONS(29),
    [anon_sym_rand] = ACTIONS(40),
    [anon_sym_spread] = ACTIONS(43),
    [sym_return_statement] = ACTIONS(46),
    [anon_sym_load] = ACTIONS(49),
    [anon_sym_goto] = ACTIONS(52),
    [anon_sym_show] = ACTIONS(55),
    [anon_sym_concat] = ACTIONS(58),
    [anon_sym_delete] = ACTIONS(61),
    [anon_sym_hide] = ACTIONS(64),
    [anon_sym_unhide] = ACTIONS(67),
    [anon_sym_save] = ACTIONS(70),
    [anon_sym_erase] = ACTIONS(73),
    [anon_sym_block] = ACTIONS(76),
    [anon_sym_wait] = ACTIONS(79),
    [anon_sym_close] = ACTIONS(82),
    [sym_player] = ACTIONS(85),
    [sym_self] = ACTIONS(85),
    [anon_sym_pause] = ACTIONS(88),
    [anon_sym_unpause] = ACTIONS(91),
    [anon_sym_camera] = ACTIONS(94),
    [anon_sym_player_control] = ACTIONS(97),
    [anon_sym_lights_control] = ACTIONS(97),
    [anon_sym_hex_editor] = ACTIONS(97),
    [anon_sym_hex_dialog_mode] = ACTIONS(97),
    [anon_sym_hex_control] = ACTIONS(97),
    [anon_sym_hex_clipboard] = ACTIONS(97),
    [anon_sym_serial_control] = ACTIONS(97),
    [anon_sym_flagName] = ACTIONS(97),
  },
  [3] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_RBRACE] = ACTIONS(104),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
  [4] = {
    [sym__script_item] = STATE(3),
    [sym_json_literal] = STATE(3),
    [sym_label] = STATE(3),
    [sym_debug_macro] = STATE(3),
    [sym_rand_macro] = STATE(3),
    [sym_spread_macro] = STATE(3),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(3),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_RBRACE] = ACTIONS(152),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
  [5] = {
    [sym__script_item] = STATE(8),
    [sym_json_literal] = STATE(8),
    [sym_label] = STATE(8),
    [sym_debug_macro] = STATE(8),
    [sym_rand_macro] = STATE(8),
    [sym_spread_macro] = STATE(8),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(8),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_RPAREN] = ACTIONS(154),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
  [6] = {
    [sym__script_item] = STATE(7),
    [sym_json_literal] = STATE(7),
    [sym_label] = STATE(7),
    [sym_debug_macro] = STATE(7),
    [sym_rand_macro] = STATE(7),
    [sym_spread_macro] = STATE(7),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(7),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_RPAREN] = ACTIONS(156),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
  [7] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_RPAREN] = ACTIONS(158),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
  [8] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(690),
    [sym_action_load_map] = STATE(690),
    [sym_action_run_script] = STATE(690),
    [sym_action_goto_label] = STATE(690),
    [sym_action_goto_index] = STATE(690),
    [sym_action_show_dialog] = STATE(690),
    [sym_action_show_serial_dialog] = STATE(690),
    [sym_action_concat_serial_dialog] = STATE(690),
    [sym_action_delete_command] = STATE(690),
    [sym_action_delete_command_arg] = STATE(690),
    [sym_action_delete_alias] = STATE(690),
    [sym_action_hide_command] = STATE(690),
    [sym_action_unhide_command] = STATE(690),
    [sym_action_save_slot] = STATE(690),
    [sym_action_load_slot] = STATE(690),
    [sym_action_erase_slot] = STATE(690),
    [sym_action_blocking_delay] = STATE(690),
    [sym_action_non_blocking_delay] = STATE(690),
    [sym_action_close_dialog] = STATE(690),
    [sym_action_close_serial_dialog] = STATE(690),
    [sym_entity_identifier_expansion] = STATE(509),
    [sym_action_pause_script] = STATE(690),
    [sym_action_unpause_script] = STATE(690),
    [sym_action_camera_fade] = STATE(690),
    [sym_action_camera_shake] = STATE(690),
    [sym_action_play_entity_animation] = STATE(690),
    [sym_camera] = STATE(159),
    [sym_movable_identifier_expansion] = STATE(149),
    [sym_action_move_over_time] = STATE(690),
    [sym_action_set_position] = STATE(690),
    [sym_setable] = STATE(434),
    [sym_action_set_bool] = STATE(690),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(100),
    [sym_BAREWORD] = ACTIONS(102),
    [anon_sym_entity] = ACTIONS(106),
    [anon_sym_json] = ACTIONS(108),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_RPAREN] = ACTIONS(160),
    [anon_sym_rand] = ACTIONS(112),
    [anon_sym_spread] = ACTIONS(114),
    [sym_return_statement] = ACTIONS(116),
    [anon_sym_load] = ACTIONS(118),
    [anon_sym_goto] = ACTIONS(120),
    [anon_sym_show] = ACTIONS(122),
    [anon_sym_concat] = ACTIONS(124),
    [anon_sym_delete] = ACTIONS(126),
    [anon_sym_hide] = ACTIONS(128),
    [anon_sym_unhide] = ACTIONS(130),
    [anon_sym_save] = ACTIONS(132),
    [anon_sym_erase] = ACTIONS(134),
    [anon_sym_block] = ACTIONS(136),
    [anon_sym_wait] = ACTIONS(138),
    [anon_sym_close] = ACTIONS(140),
    [sym_player] = ACTIONS(142),
    [sym_self] = ACTIONS(142),
    [anon_sym_pause] = ACTIONS(144),
    [anon_sym_unpause] = ACTIONS(146),
    [anon_sym_camera] = ACTIONS(148),
    [anon_sym_player_control] = ACTIONS(150),
    [anon_sym_lights_control] = ACTIONS(150),
    [anon_sym_hex_editor] = ACTIONS(150),
    [anon_sym_hex_dialog_mode] = ACTIONS(150),
    [anon_sym_hex_control] = ACTIONS(150),
    [anon_sym_hex_clipboard] = ACTIONS(150),
    [anon_sym_serial_control] = ACTIONS(150),
    [anon_sym_flagName] = ACTIONS(150),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(162), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(164), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [46] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(168), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [92] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(170), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(172), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [138] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(174), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(176), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [182] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(178), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(180), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [226] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(182), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(184), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [270] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(186), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(188), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [314] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(190), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(192), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [358] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(194), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(196), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [402] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(198), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(200), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [446] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(202), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(204), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [490] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(206), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(208), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [534] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(210), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(212), 32,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_json,
      anon_sym_debug,
      anon_sym_rand,
      anon_sym_spread,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
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
      anon_sym_player_control,
      anon_sym_lights_control,
      anon_sym_hex_editor,
      anon_sym_hex_dialog_mode,
      anon_sym_hex_control,
      anon_sym_hex_clipboard,
      anon_sym_serial_control,
      anon_sym_flagName,
  [578] = 12,
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
    ACTIONS(214), 1,
      ts_builtin_sym_end,
    STATE(594), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(23), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [624] = 12,
    ACTIONS(216), 1,
      ts_builtin_sym_end,
    ACTIONS(218), 1,
      anon_sym_LBRACK,
    ACTIONS(221), 1,
      sym_BAREWORD,
    ACTIONS(224), 1,
      sym_CONSTANT,
    ACTIONS(227), 1,
      anon_sym_include,
    ACTIONS(230), 1,
      anon_sym_add,
    ACTIONS(233), 1,
      anon_sym_serial_dialog,
    ACTIONS(236), 1,
      anon_sym_dialog,
    ACTIONS(239), 1,
      anon_sym_script,
    STATE(594), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(23), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [670] = 5,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    STATE(566), 1,
      sym_constant_value_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(246), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(242), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [694] = 6,
    ACTIONS(248), 1,
      anon_sym_LBRACK,
    ACTIONS(250), 1,
      anon_sym_RBRACK,
    ACTIONS(254), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(309), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(252), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [720] = 11,
    ACTIONS(256), 1,
      sym_QUOTED_STRING,
    ACTIONS(258), 1,
      anon_sym_wrap,
    ACTIONS(260), 1,
      anon_sym_entity,
    ACTIONS(262), 1,
      anon_sym_name,
    ACTIONS(264), 1,
      anon_sym_portrait,
    ACTIONS(266), 1,
      anon_sym_alignment,
    ACTIONS(268), 1,
      anon_sym_border_tileset,
    ACTIONS(270), 1,
      anon_sym_emote,
    STATE(49), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(28), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [756] = 10,
    ACTIONS(274), 1,
      anon_sym_wrap,
    ACTIONS(277), 1,
      anon_sym_entity,
    ACTIONS(280), 1,
      anon_sym_name,
    ACTIONS(283), 1,
      anon_sym_portrait,
    ACTIONS(286), 1,
      anon_sym_alignment,
    ACTIONS(289), 1,
      anon_sym_border_tileset,
    ACTIONS(292), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(272), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [790] = 11,
    ACTIONS(256), 1,
      sym_QUOTED_STRING,
    ACTIONS(258), 1,
      anon_sym_wrap,
    ACTIONS(260), 1,
      anon_sym_entity,
    ACTIONS(262), 1,
      anon_sym_name,
    ACTIONS(264), 1,
      anon_sym_portrait,
    ACTIONS(266), 1,
      anon_sym_alignment,
    ACTIONS(268), 1,
      anon_sym_border_tileset,
    ACTIONS(270), 1,
      anon_sym_emote,
    STATE(61), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [826] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(295), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(297), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [845] = 4,
    ACTIONS(301), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(299), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [866] = 10,
    ACTIONS(258), 1,
      anon_sym_wrap,
    ACTIONS(260), 1,
      anon_sym_entity,
    ACTIONS(262), 1,
      anon_sym_name,
    ACTIONS(264), 1,
      anon_sym_portrait,
    ACTIONS(266), 1,
      anon_sym_alignment,
    ACTIONS(268), 1,
      anon_sym_border_tileset,
    ACTIONS(270), 1,
      anon_sym_emote,
    ACTIONS(305), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(37), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [899] = 5,
    ACTIONS(248), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(493), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(307), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [922] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(309), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(311), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [941] = 5,
    ACTIONS(248), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(449), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(313), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [964] = 9,
    ACTIONS(315), 1,
      sym_BOOL,
    ACTIONS(317), 1,
      anon_sym_LBRACK,
    ACTIONS(319), 1,
      sym_BAREWORD,
    ACTIONS(321), 1,
      sym_CONSTANT,
    ACTIONS(323), 1,
      anon_sym_BANG,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    STATE(571), 1,
      sym_bool_or_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(385), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [995] = 4,
    ACTIONS(327), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(299), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [1016] = 10,
    ACTIONS(258), 1,
      anon_sym_wrap,
    ACTIONS(260), 1,
      anon_sym_entity,
    ACTIONS(262), 1,
      anon_sym_name,
    ACTIONS(264), 1,
      anon_sym_portrait,
    ACTIONS(266), 1,
      anon_sym_alignment,
    ACTIONS(268), 1,
      anon_sym_border_tileset,
    ACTIONS(270), 1,
      anon_sym_emote,
    ACTIONS(329), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1049] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(331), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(333), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1068] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(335), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(337), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1087] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(339), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1103] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(343), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1121] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(345), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(347), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1139] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(349), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(351), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1157] = 9,
    ACTIONS(353), 1,
      sym_BAREWORD,
    ACTIONS(355), 1,
      sym_QUOTED_STRING,
    ACTIONS(357), 1,
      sym_CONSTANT,
    ACTIONS(359), 1,
      anon_sym_wrap,
    ACTIONS(361), 1,
      anon_sym_RPAREN,
    STATE(73), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(535), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(117), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1187] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(365), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(363), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [1205] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(367), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(369), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1223] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(371), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(373), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1241] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(377), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1259] = 7,
    ACTIONS(256), 1,
      sym_QUOTED_STRING,
    ACTIONS(381), 1,
      anon_sym_RBRACE,
    ACTIONS(383), 1,
      anon_sym_GT,
    STATE(80), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(81), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(379), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1285] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(385), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(387), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1303] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(389), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(391), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1321] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(395), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1339] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(399), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1357] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(401), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(403), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(405), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1391] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(407), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1407] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1423] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(411), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1439] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(413), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1455] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(415), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1471] = 7,
    ACTIONS(256), 1,
      sym_QUOTED_STRING,
    ACTIONS(383), 1,
      anon_sym_GT,
    ACTIONS(419), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(83), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(417), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1497] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(299), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [1515] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(421), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(423), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1533] = 7,
    ACTIONS(323), 1,
      anon_sym_BANG,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      sym_BOOL,
    ACTIONS(427), 1,
      sym_BAREWORD,
    ACTIONS(429), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(301), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [1558] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(431), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1573] = 7,
    ACTIONS(323), 1,
      anon_sym_BANG,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      sym_BOOL,
    ACTIONS(427), 1,
      sym_BAREWORD,
    ACTIONS(429), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(245), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [1598] = 7,
    ACTIONS(323), 1,
      anon_sym_BANG,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      sym_BOOL,
    ACTIONS(427), 1,
      sym_BAREWORD,
    ACTIONS(429), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(196), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [1623] = 7,
    ACTIONS(323), 1,
      anon_sym_BANG,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      sym_BOOL,
    ACTIONS(427), 1,
      sym_BAREWORD,
    ACTIONS(429), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(195), 3,
      sym__bool_expression,
      sym_bool_unary_expression,
      sym_bool_binary_expression,
  [1648] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1663] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(435), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1678] = 6,
    ACTIONS(437), 1,
      anon_sym_LBRACK,
    ACTIONS(439), 1,
      anon_sym_entity,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(443), 2,
      sym_player,
      sym_self,
    STATE(111), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [1700] = 7,
    ACTIONS(445), 1,
      sym_BAREWORD,
    ACTIONS(448), 1,
      anon_sym_RBRACE,
    ACTIONS(450), 1,
      anon_sym_entity,
    ACTIONS(453), 1,
      anon_sym_name,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(72), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1724] = 6,
    ACTIONS(355), 1,
      sym_QUOTED_STRING,
    ACTIONS(458), 1,
      sym_serial_dialog_option_type,
    STATE(118), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(456), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(128), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1746] = 7,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    ACTIONS(462), 1,
      sym_BAREWORD,
    ACTIONS(466), 1,
      anon_sym_label,
    ACTIONS(468), 1,
      anon_sym_index,
    STATE(546), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(464), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1770] = 7,
    ACTIONS(470), 1,
      sym_BAREWORD,
    ACTIONS(472), 1,
      anon_sym_RBRACE,
    ACTIONS(474), 1,
      anon_sym_entity,
    ACTIONS(476), 1,
      anon_sym_name,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(72), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1794] = 6,
    ACTIONS(355), 1,
      sym_QUOTED_STRING,
    ACTIONS(458), 1,
      sym_serial_dialog_option_type,
    STATE(118), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(478), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(132), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1816] = 7,
    ACTIONS(355), 1,
      sym_QUOTED_STRING,
    ACTIONS(480), 1,
      anon_sym_RBRACE,
    ACTIONS(482), 1,
      anon_sym_wrap,
    STATE(73), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(588), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(117), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1840] = 5,
    ACTIONS(486), 1,
      anon_sym_RBRACE,
    ACTIONS(488), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(484), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1860] = 6,
    ACTIONS(437), 1,
      anon_sym_LBRACK,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(491), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(493), 2,
      sym_player,
      sym_self,
    STATE(134), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [1882] = 5,
    ACTIONS(497), 1,
      sym_QUOTED_STRING,
    STATE(80), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(500), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(495), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1902] = 5,
    ACTIONS(383), 1,
      anon_sym_GT,
    ACTIONS(504), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(502), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1922] = 7,
    ACTIONS(470), 1,
      sym_BAREWORD,
    ACTIONS(474), 1,
      anon_sym_entity,
    ACTIONS(476), 1,
      anon_sym_name,
    ACTIONS(506), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1946] = 5,
    ACTIONS(383), 1,
      anon_sym_GT,
    ACTIONS(510), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(508), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1966] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(512), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [1979] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(516), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1994] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(520), 1,
      anon_sym_entity,
    ACTIONS(524), 1,
      anon_sym_geometry,
    STATE(528), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(522), 2,
      sym_player,
      sym_self,
  [2015] = 6,
    ACTIONS(526), 1,
      anon_sym_RBRACK,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2036] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(534), 1,
      anon_sym_entity,
    ACTIONS(538), 1,
      anon_sym_geometry,
    STATE(147), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(536), 2,
      sym_player,
      sym_self,
  [2057] = 6,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(540), 1,
      anon_sym_RBRACK,
    ACTIONS(542), 1,
      anon_sym_entity,
    STATE(339), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_player,
      sym_self,
  [2078] = 6,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(546), 1,
      anon_sym_RBRACK,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2099] = 6,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(548), 1,
      anon_sym_RBRACK,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2120] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(550), 1,
      anon_sym_entity,
    ACTIONS(554), 1,
      anon_sym_geometry,
    STATE(167), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(552), 2,
      sym_player,
      sym_self,
  [2141] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(556), 1,
      anon_sym_entity,
    ACTIONS(560), 1,
      anon_sym_geometry,
    STATE(661), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(558), 2,
      sym_player,
      sym_self,
  [2162] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(562), 1,
      anon_sym_entity,
    ACTIONS(566), 1,
      anon_sym_geometry,
    STATE(554), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(564), 2,
      sym_player,
      sym_self,
  [2183] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(568), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2196] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(570), 1,
      anon_sym_entity,
    ACTIONS(574), 1,
      anon_sym_geometry,
    STATE(197), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 2,
      sym_player,
      sym_self,
  [2217] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(576), 1,
      anon_sym_entity,
    ACTIONS(580), 1,
      anon_sym_geometry,
    STATE(659), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(578), 2,
      sym_player,
      sym_self,
  [2238] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(582), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2251] = 6,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(584), 1,
      anon_sym_RBRACK,
    ACTIONS(586), 1,
      anon_sym_entity,
    STATE(433), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_player,
      sym_self,
  [2272] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(590), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2285] = 6,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(592), 1,
      anon_sym_RBRACK,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2306] = 6,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(594), 1,
      anon_sym_RBRACK,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2327] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(596), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(598), 4,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_BANG,
      anon_sym_LPAREN,
  [2342] = 6,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(586), 1,
      anon_sym_entity,
    ACTIONS(600), 1,
      anon_sym_RBRACK,
    STATE(433), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_player,
      sym_self,
  [2363] = 6,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(586), 1,
      anon_sym_entity,
    ACTIONS(602), 1,
      anon_sym_RBRACK,
    STATE(433), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_player,
      sym_self,
  [2384] = 6,
    ACTIONS(518), 1,
      anon_sym_LBRACK,
    ACTIONS(604), 1,
      anon_sym_entity,
    ACTIONS(608), 1,
      anon_sym_geometry,
    STATE(144), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(606), 2,
      sym_player,
      sym_self,
  [2405] = 6,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    ACTIONS(610), 1,
      anon_sym_RBRACK,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2426] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(612), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2439] = 6,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(586), 1,
      anon_sym_entity,
    ACTIONS(614), 1,
      anon_sym_RBRACK,
    STATE(433), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_player,
      sym_self,
  [2460] = 6,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(616), 1,
      anon_sym_RBRACK,
    ACTIONS(618), 1,
      anon_sym_entity,
    STATE(351), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(620), 2,
      sym_player,
      sym_self,
  [2481] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(687), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(622), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2497] = 4,
    ACTIONS(624), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      anon_sym_in,
      anon_sym_out,
    STATE(699), 2,
      sym_in_or_out,
      sym_in_or_out_expansion,
  [2513] = 6,
    ACTIONS(628), 1,
      anon_sym_RBRACE,
    ACTIONS(630), 1,
      anon_sym_default,
    ACTIONS(632), 1,
      anon_sym_label,
    ACTIONS(634), 1,
      anon_sym_entity,
    STATE(114), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2533] = 6,
    ACTIONS(630), 1,
      anon_sym_default,
    ACTIONS(632), 1,
      anon_sym_label,
    ACTIONS(634), 1,
      anon_sym_entity,
    ACTIONS(636), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2553] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(598), 5,
      anon_sym_LBRACK,
      anon_sym_entity,
      sym_player,
      sym_self,
      anon_sym_geometry,
  [2565] = 4,
    ACTIONS(640), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(116), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2581] = 5,
    ACTIONS(355), 1,
      sym_QUOTED_STRING,
    ACTIONS(482), 1,
      anon_sym_wrap,
    STATE(76), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(116), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2599] = 4,
    ACTIONS(643), 1,
      sym_QUOTED_STRING,
    STATE(118), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(646), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [2615] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(568), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(648), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2631] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(689), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(650), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2647] = 5,
    ACTIONS(528), 1,
      anon_sym_entity,
    ACTIONS(532), 1,
      anon_sym_camera,
    STATE(436), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(530), 2,
      sym_player,
      sym_self,
  [2665] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(431), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(652), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2681] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(525), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(654), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2697] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(526), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(656), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2713] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(695), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(658), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2729] = 5,
    ACTIONS(660), 1,
      anon_sym_RBRACK,
    ACTIONS(662), 1,
      anon_sym_entity,
    ACTIONS(666), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      sym_player,
      sym_self,
  [2747] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(627), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(668), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2763] = 4,
    ACTIONS(458), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(670), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(133), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2779] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(530), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(672), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2795] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(674), 5,
      anon_sym_LBRACK,
      anon_sym_entity,
      sym_player,
      sym_self,
      anon_sym_geometry,
  [2807] = 6,
    ACTIONS(676), 1,
      anon_sym_RBRACE,
    ACTIONS(678), 1,
      anon_sym_default,
    ACTIONS(681), 1,
      anon_sym_label,
    ACTIONS(684), 1,
      anon_sym_entity,
    STATE(131), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2827] = 4,
    ACTIONS(458), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(687), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(133), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2843] = 4,
    ACTIONS(691), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(689), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(133), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2859] = 4,
    ACTIONS(460), 1,
      anon_sym_LBRACK,
    STATE(665), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(694), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2875] = 5,
    ACTIONS(441), 1,
      anon_sym_map,
    ACTIONS(586), 1,
      anon_sym_entity,
    STATE(433), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_player,
      sym_self,
  [2893] = 5,
    ACTIONS(696), 1,
      anon_sym_RBRACK,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [2911] = 5,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(704), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [2929] = 5,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(706), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [2947] = 5,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(708), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [2965] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(712), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(710), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2979] = 5,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(714), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [2997] = 5,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(716), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [3015] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(718), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3026] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(722), 1,
      anon_sym_over,
    ACTIONS(724), 1,
      sym_forever,
    STATE(538), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3043] = 3,
    ACTIONS(726), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(728), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3056] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3067] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(732), 1,
      anon_sym_over,
    ACTIONS(734), 1,
      sym_forever,
    STATE(591), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3084] = 5,
    ACTIONS(736), 1,
      sym_BOOL,
    ACTIONS(738), 1,
      anon_sym_RBRACK,
    ACTIONS(740), 1,
      sym_BAREWORD,
    ACTIONS(742), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3101] = 5,
    ACTIONS(744), 1,
      anon_sym_EQ,
    ACTIONS(746), 1,
      anon_sym_DASH_GT,
    STATE(88), 1,
      sym_over_time_operator,
    STATE(94), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3118] = 4,
    ACTIONS(748), 1,
      anon_sym_RBRACK,
    ACTIONS(750), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_player,
      sym_self,
  [3133] = 5,
    ACTIONS(744), 1,
      anon_sym_EQ,
    ACTIONS(746), 1,
      anon_sym_DASH_GT,
    STATE(96), 1,
      sym_over_time_operator,
    STATE(97), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3150] = 4,
    ACTIONS(750), 1,
      anon_sym_entity,
    ACTIONS(754), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_player,
      sym_self,
  [3165] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(756), 4,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [3176] = 4,
    ACTIONS(758), 1,
      anon_sym_LBRACK,
    STATE(166), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(760), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3191] = 4,
    ACTIONS(762), 1,
      anon_sym_LBRACK,
    STATE(691), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(764), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3206] = 4,
    ACTIONS(768), 1,
      anon_sym_fade,
    ACTIONS(770), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(766), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [3221] = 4,
    ACTIONS(482), 1,
      anon_sym_wrap,
    ACTIONS(772), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(116), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3236] = 4,
    ACTIONS(758), 1,
      anon_sym_LBRACK,
    STATE(692), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(774), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3251] = 5,
    ACTIONS(744), 1,
      anon_sym_EQ,
    ACTIONS(746), 1,
      anon_sym_DASH_GT,
    STATE(86), 1,
      sym_assignmment_operator,
    STATE(106), 1,
      sym_over_time_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3268] = 4,
    ACTIONS(758), 1,
      anon_sym_LBRACK,
    STATE(182), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(776), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3283] = 5,
    ACTIONS(778), 1,
      anon_sym_COMMA,
    ACTIONS(780), 1,
      anon_sym_RBRACK,
    ACTIONS(782), 1,
      anon_sym_position,
    STATE(304), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3300] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(668), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(786), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3315] = 4,
    ACTIONS(750), 1,
      anon_sym_entity,
    ACTIONS(788), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_player,
      sym_self,
  [3330] = 5,
    ACTIONS(790), 1,
      anon_sym_COMMA,
    ACTIONS(792), 1,
      anon_sym_RBRACK,
    ACTIONS(794), 1,
      anon_sym_position,
    STATE(263), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3347] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(657), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(796), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3362] = 4,
    ACTIONS(798), 1,
      anon_sym_LBRACK,
    STATE(514), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(800), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [3377] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(802), 1,
      anon_sym_over,
    ACTIONS(804), 1,
      sym_forever,
    STATE(520), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3394] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    STATE(696), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(806), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3409] = 4,
    ACTIONS(812), 1,
      anon_sym_LBRACE,
    STATE(510), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(810), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3424] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    STATE(624), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(814), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3439] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(816), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3450] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(818), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3461] = 3,
    ACTIONS(820), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(822), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3474] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(824), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3485] = 3,
    ACTIONS(826), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(822), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3498] = 4,
    ACTIONS(750), 1,
      anon_sym_entity,
    ACTIONS(828), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_player,
      sym_self,
  [3513] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(830), 1,
      anon_sym_over,
    ACTIONS(832), 1,
      sym_forever,
    STATE(545), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3530] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(547), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(834), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3545] = 4,
    ACTIONS(482), 1,
      anon_sym_wrap,
    ACTIONS(836), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(157), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3560] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(838), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3571] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(840), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3582] = 4,
    ACTIONS(798), 1,
      anon_sym_LBRACK,
    STATE(710), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(842), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [3597] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(844), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3608] = 4,
    ACTIONS(846), 1,
      anon_sym_RBRACK,
    STATE(461), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      anon_sym_in,
      anon_sym_out,
  [3623] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(848), 1,
      anon_sym_over,
    ACTIONS(850), 1,
      sym_forever,
    STATE(573), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3640] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(574), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(852), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3655] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(854), 1,
      anon_sym_over,
    ACTIONS(856), 1,
      sym_forever,
    STATE(577), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3672] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(386), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(858), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3687] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(860), 1,
      anon_sym_over,
    ACTIONS(862), 1,
      sym_forever,
    STATE(584), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3704] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(864), 1,
      anon_sym_over,
    ACTIONS(866), 1,
      sym_forever,
    STATE(508), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3721] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(870), 1,
      anon_sym_RBRACK,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3738] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(876), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3755] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(878), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3772] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(880), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [3783] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(882), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [3794] = 3,
    ACTIONS(884), 1,
      sym_AND,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(882), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_OR,
  [3807] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(886), 1,
      anon_sym_over,
    ACTIONS(888), 1,
      sym_forever,
    STATE(513), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3824] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(890), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3835] = 4,
    ACTIONS(892), 1,
      anon_sym_RBRACK,
    STATE(289), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      anon_sym_in,
      anon_sym_out,
  [3850] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(894), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3861] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(896), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3872] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(898), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3883] = 4,
    ACTIONS(758), 1,
      anon_sym_LBRACK,
    STATE(537), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(900), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3898] = 4,
    ACTIONS(902), 1,
      anon_sym_LBRACK,
    STATE(570), 1,
      sym_distance_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(904), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [3913] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(906), 1,
      anon_sym_over,
    ACTIONS(908), 1,
      sym_forever,
    STATE(608), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3930] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(610), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(910), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3945] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(912), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3956] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(914), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3967] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(916), 1,
      anon_sym_over,
    ACTIONS(918), 1,
      sym_forever,
    STATE(622), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3984] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(623), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(920), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3999] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(922), 1,
      anon_sym_over,
    ACTIONS(924), 1,
      sym_forever,
    STATE(626), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4016] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(926), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4027] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(928), 1,
      anon_sym_over,
    ACTIONS(930), 1,
      sym_forever,
    STATE(603), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4044] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(932), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4055] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(934), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4066] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(616), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(936), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4081] = 4,
    ACTIONS(938), 1,
      anon_sym_RBRACK,
    STATE(461), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      anon_sym_in,
      anon_sym_out,
  [4096] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(633), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(940), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4111] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(637), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(942), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4126] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(629), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(944), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4141] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(946), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4152] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(651), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(948), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4167] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(652), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(950), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4182] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(662), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(952), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4197] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(663), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(954), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4212] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(956), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4229] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(958), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4246] = 5,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(960), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4263] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(962), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [4274] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(964), 1,
      anon_sym_over,
    ACTIONS(966), 1,
      sym_forever,
    STATE(671), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4291] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(672), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(968), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4306] = 5,
    ACTIONS(720), 1,
      anon_sym_LBRACK,
    ACTIONS(970), 1,
      anon_sym_over,
    ACTIONS(972), 1,
      sym_forever,
    STATE(675), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4323] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(974), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [4334] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(680), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(976), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4349] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(681), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(978), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4364] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(980), 4,
      anon_sym_LBRACK,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(982), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [4386] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(984), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4397] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(986), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4408] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(988), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [4419] = 4,
    ACTIONS(990), 1,
      anon_sym_LBRACK,
    STATE(557), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(992), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4434] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(994), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [4445] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(996), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4456] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(499), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(998), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4471] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1000), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      sym_AND,
      sym_OR,
  [4482] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(707), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1002), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4497] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(708), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1004), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4512] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1006), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4523] = 4,
    ACTIONS(784), 1,
      anon_sym_LBRACK,
    STATE(204), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1008), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4538] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1010), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4549] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1012), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4560] = 4,
    ACTIONS(698), 1,
      anon_sym_entity,
    ACTIONS(702), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_player,
      sym_self,
  [4575] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1014), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4586] = 5,
    ACTIONS(744), 1,
      anon_sym_EQ,
    ACTIONS(746), 1,
      anon_sym_DASH_GT,
    STATE(92), 1,
      sym_over_time_operator,
    STATE(93), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4603] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1016), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4614] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1018), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4625] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1020), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4636] = 4,
    ACTIONS(758), 1,
      anon_sym_LBRACK,
    STATE(642), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1022), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4651] = 4,
    ACTIONS(1024), 1,
      anon_sym_LBRACK,
    STATE(562), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1026), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4666] = 4,
    ACTIONS(1028), 1,
      anon_sym_animation,
    ACTIONS(1030), 1,
      anon_sym_position,
    ACTIONS(1032), 1,
      sym_glitched,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4680] = 4,
    ACTIONS(1034), 1,
      anon_sym_RBRACK,
    ACTIONS(1036), 1,
      anon_sym_over,
    ACTIONS(1038), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4694] = 4,
    ACTIONS(1040), 1,
      anon_sym_COMMA,
    ACTIONS(1042), 1,
      anon_sym_RBRACK,
    STATE(312), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4708] = 4,
    ACTIONS(1044), 1,
      anon_sym_COMMA,
    ACTIONS(1046), 1,
      anon_sym_RBRACK,
    STATE(266), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4722] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1048), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4732] = 4,
    ACTIONS(1050), 1,
      anon_sym_COMMA,
    ACTIONS(1052), 1,
      anon_sym_RBRACK,
    STATE(269), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4746] = 4,
    ACTIONS(1054), 1,
      anon_sym_COMMA,
    ACTIONS(1057), 1,
      anon_sym_RBRACK,
    STATE(266), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4760] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1059), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4770] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1061), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4780] = 4,
    ACTIONS(1063), 1,
      anon_sym_COMMA,
    ACTIONS(1066), 1,
      anon_sym_RBRACK,
    STATE(269), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4794] = 4,
    ACTIONS(1068), 1,
      anon_sym_COMMA,
    ACTIONS(1070), 1,
      anon_sym_RBRACK,
    STATE(311), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4808] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1072), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4818] = 4,
    ACTIONS(1074), 1,
      anon_sym_COMMA,
    ACTIONS(1076), 1,
      anon_sym_RBRACE,
    STATE(321), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4832] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1078), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4842] = 3,
    ACTIONS(1080), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1082), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4854] = 4,
    ACTIONS(1084), 1,
      anon_sym_COMMA,
    ACTIONS(1086), 1,
      anon_sym_RBRACK,
    STATE(327), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4868] = 4,
    ACTIONS(820), 1,
      anon_sym_RBRACK,
    ACTIONS(1088), 1,
      anon_sym_COMMA,
    STATE(328), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4882] = 4,
    ACTIONS(1090), 1,
      anon_sym_COMMA,
    ACTIONS(1092), 1,
      anon_sym_RBRACK,
    STATE(330), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4896] = 3,
    ACTIONS(1094), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1096), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4908] = 4,
    ACTIONS(1094), 1,
      anon_sym_RBRACK,
    ACTIONS(1098), 1,
      anon_sym_COMMA,
    STATE(333), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4922] = 4,
    ACTIONS(1100), 1,
      anon_sym_COMMA,
    ACTIONS(1102), 1,
      anon_sym_RBRACK,
    STATE(389), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4936] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1104), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1106), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4956] = 3,
    ACTIONS(1108), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1110), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4968] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1112), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4978] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1114), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4988] = 4,
    ACTIONS(1116), 1,
      anon_sym_COMMA,
    ACTIONS(1118), 1,
      anon_sym_RBRACK,
    STATE(337), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5002] = 4,
    ACTIONS(1108), 1,
      anon_sym_RBRACK,
    ACTIONS(1120), 1,
      anon_sym_COMMA,
    STATE(394), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5016] = 4,
    ACTIONS(1122), 1,
      anon_sym_COMMA,
    ACTIONS(1124), 1,
      anon_sym_RBRACK,
    STATE(340), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5030] = 4,
    ACTIONS(1126), 1,
      anon_sym_COMMA,
    ACTIONS(1128), 1,
      anon_sym_RBRACK,
    STATE(342), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5044] = 4,
    ACTIONS(1130), 1,
      anon_sym_COMMA,
    ACTIONS(1132), 1,
      anon_sym_RBRACK,
    STATE(287), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5058] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1134), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5068] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5078] = 3,
    STATE(187), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1138), 2,
      sym_origin,
      sym_length,
  [5090] = 4,
    ACTIONS(1140), 1,
      anon_sym_RBRACK,
    ACTIONS(1142), 1,
      anon_sym_over,
    ACTIONS(1144), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5104] = 3,
    STATE(619), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1146), 2,
      sym_origin,
      sym_length,
  [5116] = 3,
    STATE(190), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1148), 2,
      sym_origin,
      sym_length,
  [5128] = 3,
    STATE(639), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1150), 2,
      sym_origin,
      sym_length,
  [5140] = 4,
    ACTIONS(1152), 1,
      anon_sym_COMMA,
    ACTIONS(1154), 1,
      anon_sym_RBRACK,
    STATE(352), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5154] = 4,
    ACTIONS(1156), 1,
      anon_sym_COMMA,
    ACTIONS(1158), 1,
      anon_sym_RBRACK,
    STATE(353), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5168] = 4,
    ACTIONS(1160), 1,
      anon_sym_COMMA,
    ACTIONS(1162), 1,
      anon_sym_RBRACK,
    STATE(354), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5182] = 4,
    ACTIONS(884), 1,
      sym_AND,
    ACTIONS(1164), 1,
      anon_sym_RPAREN,
    ACTIONS(1166), 1,
      sym_OR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5196] = 4,
    ACTIONS(1168), 1,
      anon_sym_COMMA,
    ACTIONS(1171), 1,
      anon_sym_RBRACK,
    STATE(302), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5210] = 4,
    ACTIONS(1173), 1,
      anon_sym_COMMA,
    ACTIONS(1175), 1,
      anon_sym_RBRACK,
    STATE(265), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5224] = 4,
    ACTIONS(1177), 1,
      anon_sym_COMMA,
    ACTIONS(1179), 1,
      anon_sym_RBRACK,
    STATE(266), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5238] = 4,
    ACTIONS(1181), 1,
      anon_sym_COMMA,
    ACTIONS(1183), 1,
      anon_sym_RBRACK,
    STATE(269), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5252] = 4,
    ACTIONS(1185), 1,
      anon_sym_COMMA,
    ACTIONS(1188), 1,
      anon_sym_RBRACK,
    STATE(306), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5266] = 3,
    ACTIONS(1192), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1190), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [5278] = 4,
    ACTIONS(1194), 1,
      sym_QUOTED_STRING,
    ACTIONS(1196), 1,
      anon_sym_RBRACE,
    STATE(272), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5292] = 4,
    ACTIONS(1198), 1,
      anon_sym_COMMA,
    ACTIONS(1200), 1,
      anon_sym_RBRACK,
    STATE(427), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5306] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1202), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5316] = 4,
    ACTIONS(1204), 1,
      anon_sym_COMMA,
    ACTIONS(1206), 1,
      anon_sym_RBRACK,
    STATE(306), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5330] = 4,
    ACTIONS(1208), 1,
      anon_sym_COMMA,
    ACTIONS(1210), 1,
      anon_sym_RBRACK,
    STATE(269), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5344] = 3,
    ACTIONS(750), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_player,
      sym_self,
  [5356] = 3,
    ACTIONS(1212), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1214), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5368] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1216), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5378] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1218), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1220), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5398] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1222), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5408] = 4,
    ACTIONS(1224), 1,
      anon_sym_COMMA,
    ACTIONS(1226), 1,
      anon_sym_RBRACK,
    STATE(276), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5422] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1228), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [5432] = 4,
    ACTIONS(1074), 1,
      anon_sym_COMMA,
    ACTIONS(1230), 1,
      anon_sym_RBRACE,
    STATE(365), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5446] = 3,
    ACTIONS(1232), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1234), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5458] = 4,
    ACTIONS(1236), 1,
      anon_sym_COMMA,
    ACTIONS(1239), 1,
      anon_sym_RBRACK,
    STATE(323), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5472] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    ACTIONS(1241), 1,
      anon_sym_SEMI,
    STATE(555), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5486] = 3,
    ACTIONS(1243), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1245), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5498] = 4,
    ACTIONS(812), 1,
      anon_sym_LBRACE,
    ACTIONS(1247), 1,
      anon_sym_SEMI,
    STATE(559), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5512] = 4,
    ACTIONS(1243), 1,
      anon_sym_RBRACK,
    ACTIONS(1249), 1,
      anon_sym_COMMA,
    STATE(367), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5526] = 4,
    ACTIONS(1251), 1,
      anon_sym_COMMA,
    ACTIONS(1254), 1,
      anon_sym_RBRACK,
    STATE(328), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5540] = 3,
    ACTIONS(1256), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1258), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5552] = 4,
    ACTIONS(1256), 1,
      anon_sym_RBRACK,
    ACTIONS(1260), 1,
      anon_sym_COMMA,
    STATE(370), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5566] = 4,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    ACTIONS(1262), 1,
      anon_sym_SEMI,
    STATE(564), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5580] = 3,
    ACTIONS(1264), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1096), 2,
      sym_DURATION,
      sym_CONSTANT,
  [5592] = 4,
    ACTIONS(1266), 1,
      anon_sym_COMMA,
    ACTIONS(1269), 1,
      anon_sym_RBRACK,
    STATE(333), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5606] = 3,
    ACTIONS(1271), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1273), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [5618] = 3,
    STATE(211), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1275), 2,
      sym_origin,
      sym_length,
  [5630] = 3,
    STATE(549), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1277), 2,
      sym_origin,
      sym_length,
  [5642] = 4,
    ACTIONS(1279), 1,
      anon_sym_COMMA,
    ACTIONS(1281), 1,
      anon_sym_RBRACK,
    STATE(340), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5656] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1283), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5666] = 4,
    ACTIONS(1285), 1,
      anon_sym_COMMA,
    ACTIONS(1287), 1,
      anon_sym_RBRACK,
    STATE(305), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5680] = 4,
    ACTIONS(1289), 1,
      anon_sym_COMMA,
    ACTIONS(1292), 1,
      anon_sym_RBRACK,
    STATE(340), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5694] = 4,
    ACTIONS(1294), 1,
      anon_sym_COMMA,
    ACTIONS(1296), 1,
      anon_sym_RBRACK,
    STATE(279), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5708] = 4,
    ACTIONS(846), 1,
      anon_sym_RBRACK,
    ACTIONS(1298), 1,
      anon_sym_COMMA,
    STATE(377), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5722] = 3,
    ACTIONS(1300), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1302), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5734] = 3,
    ACTIONS(1304), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1306), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [5746] = 4,
    ACTIONS(1308), 1,
      anon_sym_COMMA,
    ACTIONS(1310), 1,
      anon_sym_RBRACK,
    STATE(383), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5760] = 3,
    STATE(384), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1312), 2,
      sym_origin,
      sym_length,
  [5772] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1314), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5782] = 4,
    ACTIONS(1316), 1,
      anon_sym_animation,
    ACTIONS(1318), 1,
      anon_sym_position,
    ACTIONS(1320), 1,
      sym_glitched,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5796] = 4,
    ACTIONS(1322), 1,
      anon_sym_COMMA,
    ACTIONS(1324), 1,
      anon_sym_RBRACK,
    STATE(388), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5810] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1326), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5820] = 4,
    ACTIONS(1328), 1,
      anon_sym_COMMA,
    ACTIONS(1330), 1,
      anon_sym_RBRACK,
    STATE(288), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5834] = 4,
    ACTIONS(1332), 1,
      anon_sym_COMMA,
    ACTIONS(1334), 1,
      anon_sym_RBRACK,
    STATE(390), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5848] = 4,
    ACTIONS(1336), 1,
      anon_sym_COMMA,
    ACTIONS(1338), 1,
      anon_sym_RBRACK,
    STATE(390), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5862] = 4,
    ACTIONS(1340), 1,
      anon_sym_COMMA,
    ACTIONS(1342), 1,
      anon_sym_RBRACK,
    STATE(390), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5876] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1344), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_DASH_GT,
  [5886] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1346), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5896] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1348), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5906] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1350), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5916] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1352), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5926] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1354), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5936] = 3,
    STATE(232), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1356), 2,
      sym_origin,
      sym_length,
  [5948] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1358), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5958] = 3,
    STATE(612), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1360), 2,
      sym_origin,
      sym_length,
  [5970] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1362), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [5980] = 4,
    ACTIONS(1364), 1,
      anon_sym_COMMA,
    ACTIONS(1367), 1,
      anon_sym_RBRACE,
    STATE(365), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5994] = 3,
    ACTIONS(1369), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1245), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6006] = 4,
    ACTIONS(1371), 1,
      anon_sym_COMMA,
    ACTIONS(1374), 1,
      anon_sym_RBRACK,
    STATE(367), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6020] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(822), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6030] = 3,
    ACTIONS(1376), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1258), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [6042] = 4,
    ACTIONS(1378), 1,
      anon_sym_COMMA,
    ACTIONS(1381), 1,
      anon_sym_RBRACK,
    STATE(370), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6056] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1383), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6066] = 4,
    ACTIONS(1385), 1,
      anon_sym_COMMA,
    ACTIONS(1387), 1,
      anon_sym_RBRACK,
    STATE(396), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6080] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1389), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6090] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1391), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6100] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1393), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6110] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(982), 3,
      anon_sym_SEMI,
      sym_AND,
      sym_OR,
  [6120] = 4,
    ACTIONS(1395), 1,
      anon_sym_COMMA,
    ACTIONS(1398), 1,
      anon_sym_RBRACK,
    STATE(377), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6134] = 4,
    ACTIONS(1400), 1,
      anon_sym_COMMA,
    ACTIONS(1402), 1,
      anon_sym_RBRACK,
    STATE(400), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6148] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(988), 3,
      anon_sym_SEMI,
      sym_AND,
      sym_OR,
  [6158] = 4,
    ACTIONS(1404), 1,
      anon_sym_COMMA,
    ACTIONS(1406), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6172] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(994), 3,
      anon_sym_SEMI,
      sym_AND,
      sym_OR,
  [6182] = 4,
    ACTIONS(1408), 1,
      anon_sym_COMMA,
    ACTIONS(1410), 1,
      anon_sym_RBRACK,
    STATE(404), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6196] = 4,
    ACTIONS(1412), 1,
      anon_sym_COMMA,
    ACTIONS(1414), 1,
      anon_sym_RBRACK,
    STATE(407), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6210] = 4,
    ACTIONS(1416), 1,
      anon_sym_COMMA,
    ACTIONS(1418), 1,
      anon_sym_RBRACK,
    STATE(409), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6224] = 4,
    ACTIONS(884), 1,
      sym_AND,
    ACTIONS(1166), 1,
      sym_OR,
    ACTIONS(1420), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6238] = 4,
    ACTIONS(1422), 1,
      anon_sym_COMMA,
    ACTIONS(1424), 1,
      anon_sym_RBRACK,
    STATE(411), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6252] = 4,
    ACTIONS(1036), 1,
      anon_sym_over,
    ACTIONS(1038), 1,
      sym_forever,
    ACTIONS(1426), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6266] = 4,
    ACTIONS(1428), 1,
      anon_sym_COMMA,
    ACTIONS(1430), 1,
      anon_sym_RBRACK,
    STATE(413), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6280] = 4,
    ACTIONS(327), 1,
      anon_sym_RBRACK,
    ACTIONS(1432), 1,
      anon_sym_COMMA,
    STATE(302), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6294] = 4,
    ACTIONS(1434), 1,
      anon_sym_COMMA,
    ACTIONS(1437), 1,
      anon_sym_RBRACK,
    STATE(390), 1,
      aux_sym_bool_or_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6308] = 3,
    ACTIONS(1439), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1110), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6320] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1441), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [6330] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1443), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6340] = 4,
    ACTIONS(1445), 1,
      anon_sym_COMMA,
    ACTIONS(1448), 1,
      anon_sym_RBRACK,
    STATE(394), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6354] = 3,
    ACTIONS(1450), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1452), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [6366] = 4,
    ACTIONS(1450), 1,
      anon_sym_RBRACK,
    ACTIONS(1454), 1,
      anon_sym_COMMA,
    STATE(416), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6380] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1456), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6390] = 3,
    STATE(461), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      anon_sym_in,
      anon_sym_out,
  [6402] = 3,
    ACTIONS(1458), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1460), 2,
      sym_COLOR,
      sym_CONSTANT,
  [6414] = 4,
    ACTIONS(1458), 1,
      anon_sym_RBRACK,
    ACTIONS(1462), 1,
      anon_sym_COMMA,
    STATE(418), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6428] = 3,
    ACTIONS(1464), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1466), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [6440] = 4,
    ACTIONS(1464), 1,
      anon_sym_RBRACK,
    ACTIONS(1468), 1,
      anon_sym_COMMA,
    STATE(420), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6454] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1470), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [6464] = 4,
    ACTIONS(1472), 1,
      anon_sym_COMMA,
    ACTIONS(1474), 1,
      anon_sym_RBRACK,
    STATE(407), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6478] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1476), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6488] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1478), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6498] = 4,
    ACTIONS(1480), 1,
      anon_sym_COMMA,
    ACTIONS(1483), 1,
      anon_sym_RBRACK,
    STATE(407), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6512] = 3,
    ACTIONS(1485), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1487), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6524] = 4,
    ACTIONS(1489), 1,
      anon_sym_COMMA,
    ACTIONS(1491), 1,
      anon_sym_RBRACK,
    STATE(407), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6538] = 4,
    ACTIONS(1036), 1,
      anon_sym_over,
    ACTIONS(1038), 1,
      sym_forever,
    ACTIONS(1493), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6552] = 4,
    ACTIONS(1495), 1,
      anon_sym_COMMA,
    ACTIONS(1497), 1,
      anon_sym_RBRACK,
    STATE(413), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6566] = 4,
    ACTIONS(1036), 1,
      anon_sym_over,
    ACTIONS(1038), 1,
      sym_forever,
    ACTIONS(1499), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6580] = 4,
    ACTIONS(1501), 1,
      anon_sym_COMMA,
    ACTIONS(1504), 1,
      anon_sym_RBRACK,
    STATE(413), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6594] = 4,
    ACTIONS(868), 1,
      sym_BOOL,
    ACTIONS(872), 1,
      sym_BAREWORD,
    ACTIONS(874), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6608] = 3,
    ACTIONS(1506), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1452), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [6620] = 4,
    ACTIONS(1508), 1,
      anon_sym_COMMA,
    ACTIONS(1511), 1,
      anon_sym_RBRACK,
    STATE(416), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6634] = 3,
    ACTIONS(1513), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1460), 2,
      sym_COLOR,
      sym_CONSTANT,
  [6646] = 4,
    ACTIONS(1515), 1,
      anon_sym_COMMA,
    ACTIONS(1518), 1,
      anon_sym_RBRACK,
    STATE(418), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6660] = 3,
    ACTIONS(1520), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1466), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [6672] = 4,
    ACTIONS(1522), 1,
      anon_sym_COMMA,
    ACTIONS(1525), 1,
      anon_sym_RBRACK,
    STATE(420), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6686] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1527), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6696] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1529), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6706] = 3,
    STATE(505), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1531), 2,
      sym_origin,
      sym_length,
  [6718] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1533), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6728] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1535), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6738] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1537), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6748] = 4,
    ACTIONS(1198), 1,
      anon_sym_COMMA,
    ACTIONS(1539), 1,
      anon_sym_RBRACK,
    STATE(323), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6762] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1541), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6771] = 3,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    STATE(63), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6782] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1269), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6791] = 3,
    ACTIONS(1543), 1,
      anon_sym_SEMI,
    ACTIONS(1545), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6802] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1547), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6811] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1549), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6820] = 3,
    ACTIONS(1551), 1,
      anon_sym_EQ,
    STATE(35), 1,
      sym_assignmment_operator,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6831] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1553), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [6840] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1555), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6849] = 3,
    ACTIONS(812), 1,
      anon_sym_LBRACE,
    STATE(50), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6860] = 3,
    ACTIONS(1557), 1,
      anon_sym_LBRACE,
    STATE(51), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6871] = 3,
    ACTIONS(248), 1,
      anon_sym_LBRACK,
    STATE(13), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6882] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1559), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6891] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1561), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6900] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1563), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6909] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1565), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6918] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1567), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6927] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1569), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6936] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1571), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6945] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1171), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6954] = 3,
    ACTIONS(1206), 1,
      anon_sym_RBRACK,
    ACTIONS(1573), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6965] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1575), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [6974] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1367), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [6983] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1577), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6992] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1374), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7001] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1110), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [7010] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1579), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [7019] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1381), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7028] = 3,
    ACTIONS(1581), 1,
      anon_sym_LBRACE,
    STATE(200), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7039] = 3,
    ACTIONS(1581), 1,
      anon_sym_LBRACE,
    STATE(201), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7050] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1096), 2,
      sym_DURATION,
      sym_CONSTANT,
  [7059] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1188), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7068] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1583), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7077] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1398), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7086] = 3,
    ACTIONS(1573), 1,
      sym_CONSTANT,
    ACTIONS(1585), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7097] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1587), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7106] = 3,
    ACTIONS(1589), 1,
      anon_sym_map,
    ACTIONS(1591), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7117] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1593), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7126] = 3,
    ACTIONS(1595), 1,
      anon_sym_serial_dialog,
    ACTIONS(1597), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7137] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1599), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7146] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1254), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7155] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1601), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7164] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1448), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7173] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1603), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [7182] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(766), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7191] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1605), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7200] = 3,
    ACTIONS(1607), 1,
      anon_sym_serial_dialog,
    ACTIONS(1609), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7211] = 3,
    ACTIONS(1611), 1,
      anon_sym_command,
    ACTIONS(1613), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7222] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1245), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7231] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1258), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [7240] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1615), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7249] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1617), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7258] = 3,
    ACTIONS(1581), 1,
      anon_sym_LBRACE,
    STATE(146), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7269] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1619), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [7278] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1621), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7287] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1623), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7296] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1625), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7305] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1627), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [7314] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1629), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7323] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1631), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7332] = 3,
    ACTIONS(1633), 1,
      anon_sym_RBRACK,
    ACTIONS(1635), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7343] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1511), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7352] = 3,
    ACTIONS(1194), 1,
      sym_QUOTED_STRING,
    STATE(450), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7363] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1518), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7372] = 3,
    ACTIONS(1637), 1,
      anon_sym_serial_dialog,
    ACTIONS(1639), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7383] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1239), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7392] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1525), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7401] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1641), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [7410] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1643), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7419] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1645), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7428] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1647), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [7437] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1649), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7446] = 3,
    ACTIONS(1036), 1,
      anon_sym_over,
    ACTIONS(1038), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7457] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1452), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [7466] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1460), 2,
      sym_COLOR,
      sym_CONSTANT,
  [7475] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1466), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [7484] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1651), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7493] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1653), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7502] = 3,
    ACTIONS(1557), 1,
      anon_sym_LBRACE,
    STATE(41), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7513] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1655), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7522] = 2,
    ACTIONS(1657), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7530] = 2,
    ACTIONS(1028), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7538] = 2,
    ACTIONS(1659), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7546] = 2,
    ACTIONS(1661), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7554] = 2,
    ACTIONS(1663), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7562] = 2,
    ACTIONS(1665), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7570] = 2,
    ACTIONS(1667), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7578] = 2,
    ACTIONS(1669), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7586] = 2,
    ACTIONS(1671), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7594] = 2,
    ACTIONS(1673), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7602] = 2,
    ACTIONS(1675), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7610] = 2,
    ACTIONS(1677), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7618] = 2,
    ACTIONS(1679), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7626] = 2,
    ACTIONS(1681), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7634] = 2,
    ACTIONS(1683), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7642] = 2,
    ACTIONS(1685), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7650] = 2,
    ACTIONS(1687), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7658] = 2,
    ACTIONS(1689), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7666] = 2,
    ACTIONS(1691), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7674] = 2,
    ACTIONS(1693), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7682] = 2,
    ACTIONS(1695), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7690] = 2,
    ACTIONS(1697), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7698] = 2,
    ACTIONS(1699), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7706] = 2,
    ACTIONS(1701), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7714] = 2,
    ACTIONS(1703), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7722] = 2,
    ACTIONS(1705), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7730] = 2,
    ACTIONS(1707), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7738] = 2,
    ACTIONS(1709), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7746] = 2,
    ACTIONS(1573), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7754] = 2,
    ACTIONS(1711), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7762] = 2,
    ACTIONS(1713), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7770] = 2,
    ACTIONS(1715), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7778] = 2,
    ACTIONS(1717), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7786] = 2,
    ACTIONS(1719), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7794] = 2,
    ACTIONS(1721), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7802] = 2,
    ACTIONS(1723), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7810] = 2,
    ACTIONS(1725), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7818] = 2,
    ACTIONS(1727), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7826] = 2,
    ACTIONS(1729), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7834] = 2,
    ACTIONS(1731), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7842] = 2,
    ACTIONS(1733), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7850] = 2,
    ACTIONS(1735), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7858] = 2,
    ACTIONS(1737), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7866] = 2,
    ACTIONS(1739), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7874] = 2,
    ACTIONS(1741), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7882] = 2,
    ACTIONS(1743), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7890] = 2,
    ACTIONS(1745), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7898] = 2,
    ACTIONS(1747), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7906] = 2,
    ACTIONS(1749), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7914] = 2,
    ACTIONS(1751), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7922] = 2,
    ACTIONS(1753), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7930] = 2,
    ACTIONS(1755), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7938] = 2,
    ACTIONS(1757), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7946] = 2,
    ACTIONS(1759), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7954] = 2,
    ACTIONS(1761), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7962] = 2,
    ACTIONS(1763), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7970] = 2,
    ACTIONS(1765), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7978] = 2,
    ACTIONS(1767), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7986] = 2,
    ACTIONS(1769), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7994] = 2,
    ACTIONS(1771), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8002] = 2,
    ACTIONS(1773), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8010] = 2,
    ACTIONS(1775), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8018] = 2,
    ACTIONS(1777), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8026] = 2,
    ACTIONS(1779), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8034] = 2,
    ACTIONS(1781), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8042] = 2,
    ACTIONS(1783), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8050] = 2,
    ACTIONS(1785), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8058] = 2,
    ACTIONS(1787), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8066] = 2,
    ACTIONS(1789), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8074] = 2,
    ACTIONS(1791), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8082] = 2,
    ACTIONS(1793), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8090] = 2,
    ACTIONS(1795), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8098] = 2,
    ACTIONS(1797), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8106] = 2,
    ACTIONS(1799), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8114] = 2,
    ACTIONS(1801), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8122] = 2,
    ACTIONS(1803), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8130] = 2,
    ACTIONS(1805), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8138] = 2,
    ACTIONS(1807), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8146] = 2,
    ACTIONS(1809), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8154] = 2,
    ACTIONS(1811), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8162] = 2,
    ACTIONS(1813), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8170] = 2,
    ACTIONS(1815), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8178] = 2,
    ACTIONS(1817), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8186] = 2,
    ACTIONS(1819), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8194] = 2,
    ACTIONS(1821), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8202] = 2,
    ACTIONS(1823), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8210] = 2,
    ACTIONS(1825), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8218] = 2,
    ACTIONS(1827), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8226] = 2,
    ACTIONS(1829), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8234] = 2,
    ACTIONS(1831), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8242] = 2,
    ACTIONS(1833), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8250] = 2,
    ACTIONS(1835), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8258] = 2,
    ACTIONS(1837), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8266] = 2,
    ACTIONS(1839), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8274] = 2,
    ACTIONS(1841), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8282] = 2,
    ACTIONS(1843), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8290] = 2,
    ACTIONS(1845), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8298] = 2,
    ACTIONS(1847), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8306] = 2,
    ACTIONS(1849), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8314] = 2,
    ACTIONS(1851), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8322] = 2,
    ACTIONS(1853), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8330] = 2,
    ACTIONS(1855), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8338] = 2,
    ACTIONS(1857), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8346] = 2,
    ACTIONS(1859), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8354] = 2,
    ACTIONS(1861), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8362] = 2,
    ACTIONS(1863), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8370] = 2,
    ACTIONS(1865), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8378] = 2,
    ACTIONS(1867), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8386] = 2,
    ACTIONS(1869), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8394] = 2,
    ACTIONS(1871), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8402] = 2,
    ACTIONS(1873), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8410] = 2,
    ACTIONS(1875), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8418] = 2,
    ACTIONS(1877), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8426] = 2,
    ACTIONS(1879), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8434] = 2,
    ACTIONS(1881), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8442] = 2,
    ACTIONS(1883), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8450] = 2,
    ACTIONS(1885), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8458] = 2,
    ACTIONS(1887), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8466] = 2,
    ACTIONS(1889), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8474] = 2,
    ACTIONS(1891), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8482] = 2,
    ACTIONS(1893), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8490] = 2,
    ACTIONS(1895), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8498] = 2,
    ACTIONS(1897), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8506] = 2,
    ACTIONS(1899), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8514] = 2,
    ACTIONS(1901), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8522] = 2,
    ACTIONS(1903), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8530] = 2,
    ACTIONS(1905), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8538] = 2,
    ACTIONS(1907), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8546] = 2,
    ACTIONS(1909), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8554] = 2,
    ACTIONS(1911), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8562] = 2,
    ACTIONS(1913), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8570] = 2,
    ACTIONS(1915), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8578] = 2,
    ACTIONS(1917), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8586] = 2,
    ACTIONS(1919), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8594] = 2,
    ACTIONS(1921), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8602] = 2,
    ACTIONS(1923), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8610] = 2,
    ACTIONS(1925), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8618] = 2,
    ACTIONS(1927), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8626] = 2,
    ACTIONS(1929), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8634] = 2,
    ACTIONS(1931), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8642] = 2,
    ACTIONS(1933), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8650] = 2,
    ACTIONS(1935), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8658] = 2,
    ACTIONS(1937), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8666] = 2,
    ACTIONS(1939), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8674] = 2,
    ACTIONS(1941), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8682] = 2,
    ACTIONS(1943), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8690] = 2,
    ACTIONS(1945), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8698] = 2,
    ACTIONS(1947), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8706] = 2,
    ACTIONS(1949), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8714] = 2,
    ACTIONS(1951), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8722] = 2,
    ACTIONS(1953), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8730] = 2,
    ACTIONS(1955), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8738] = 2,
    ACTIONS(1957), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8746] = 2,
    ACTIONS(1959), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8754] = 2,
    ACTIONS(1961), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8762] = 2,
    ACTIONS(1963), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8770] = 2,
    ACTIONS(1965), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8778] = 2,
    ACTIONS(1967), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8786] = 2,
    ACTIONS(1969), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8794] = 2,
    ACTIONS(1971), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8802] = 2,
    ACTIONS(1973), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8810] = 2,
    ACTIONS(1975), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8818] = 2,
    ACTIONS(1977), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8826] = 2,
    ACTIONS(1979), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8834] = 2,
    ACTIONS(1981), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8842] = 2,
    ACTIONS(1983), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8850] = 2,
    ACTIONS(1985), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8858] = 2,
    ACTIONS(1987), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8866] = 2,
    ACTIONS(1989), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8874] = 2,
    ACTIONS(1991), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8882] = 2,
    ACTIONS(1993), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8890] = 2,
    ACTIONS(1995), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8898] = 2,
    ACTIONS(1997), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8906] = 2,
    ACTIONS(1999), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8914] = 2,
    ACTIONS(2001), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8922] = 2,
    ACTIONS(2003), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8930] = 2,
    ACTIONS(2005), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8938] = 2,
    ACTIONS(2007), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8946] = 2,
    ACTIONS(2009), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8954] = 2,
    ACTIONS(2011), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8962] = 2,
    ACTIONS(2013), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8970] = 2,
    ACTIONS(2015), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8978] = 2,
    ACTIONS(2017), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8986] = 2,
    ACTIONS(2019), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8994] = 2,
    ACTIONS(2021), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9002] = 2,
    ACTIONS(2023), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9010] = 2,
    ACTIONS(2025), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9018] = 2,
    ACTIONS(2027), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9026] = 2,
    ACTIONS(2029), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9034] = 2,
    ACTIONS(2031), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9042] = 2,
    ACTIONS(2033), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9050] = 2,
    ACTIONS(2035), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9058] = 2,
    ACTIONS(2037), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9066] = 2,
    ACTIONS(2039), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9074] = 2,
    ACTIONS(2041), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9082] = 2,
    ACTIONS(2043), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9090] = 2,
    ACTIONS(2045), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9098] = 2,
    ACTIONS(2047), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9106] = 2,
    ACTIONS(2049), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9114] = 2,
    ACTIONS(2051), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9122] = 2,
    ACTIONS(2053), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9130] = 2,
    ACTIONS(2055), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9138] = 2,
    ACTIONS(2057), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9146] = 2,
    ACTIONS(2059), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9154] = 2,
    ACTIONS(2061), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9162] = 2,
    ACTIONS(2063), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9170] = 2,
    ACTIONS(2065), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9178] = 2,
    ACTIONS(2067), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9186] = 2,
    ACTIONS(2069), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9194] = 2,
    ACTIONS(2071), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9202] = 2,
    ACTIONS(2073), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9210] = 2,
    ACTIONS(2075), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9218] = 2,
    ACTIONS(2077), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [9226] = 2,
    ACTIONS(2079), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 46,
  [SMALL_STATE(11)] = 92,
  [SMALL_STATE(12)] = 138,
  [SMALL_STATE(13)] = 182,
  [SMALL_STATE(14)] = 226,
  [SMALL_STATE(15)] = 270,
  [SMALL_STATE(16)] = 314,
  [SMALL_STATE(17)] = 358,
  [SMALL_STATE(18)] = 402,
  [SMALL_STATE(19)] = 446,
  [SMALL_STATE(20)] = 490,
  [SMALL_STATE(21)] = 534,
  [SMALL_STATE(22)] = 578,
  [SMALL_STATE(23)] = 624,
  [SMALL_STATE(24)] = 670,
  [SMALL_STATE(25)] = 694,
  [SMALL_STATE(26)] = 720,
  [SMALL_STATE(27)] = 756,
  [SMALL_STATE(28)] = 790,
  [SMALL_STATE(29)] = 826,
  [SMALL_STATE(30)] = 845,
  [SMALL_STATE(31)] = 866,
  [SMALL_STATE(32)] = 899,
  [SMALL_STATE(33)] = 922,
  [SMALL_STATE(34)] = 941,
  [SMALL_STATE(35)] = 964,
  [SMALL_STATE(36)] = 995,
  [SMALL_STATE(37)] = 1016,
  [SMALL_STATE(38)] = 1049,
  [SMALL_STATE(39)] = 1068,
  [SMALL_STATE(40)] = 1087,
  [SMALL_STATE(41)] = 1103,
  [SMALL_STATE(42)] = 1121,
  [SMALL_STATE(43)] = 1139,
  [SMALL_STATE(44)] = 1157,
  [SMALL_STATE(45)] = 1187,
  [SMALL_STATE(46)] = 1205,
  [SMALL_STATE(47)] = 1223,
  [SMALL_STATE(48)] = 1241,
  [SMALL_STATE(49)] = 1259,
  [SMALL_STATE(50)] = 1285,
  [SMALL_STATE(51)] = 1303,
  [SMALL_STATE(52)] = 1321,
  [SMALL_STATE(53)] = 1339,
  [SMALL_STATE(54)] = 1357,
  [SMALL_STATE(55)] = 1375,
  [SMALL_STATE(56)] = 1391,
  [SMALL_STATE(57)] = 1407,
  [SMALL_STATE(58)] = 1423,
  [SMALL_STATE(59)] = 1439,
  [SMALL_STATE(60)] = 1455,
  [SMALL_STATE(61)] = 1471,
  [SMALL_STATE(62)] = 1497,
  [SMALL_STATE(63)] = 1515,
  [SMALL_STATE(64)] = 1533,
  [SMALL_STATE(65)] = 1558,
  [SMALL_STATE(66)] = 1573,
  [SMALL_STATE(67)] = 1598,
  [SMALL_STATE(68)] = 1623,
  [SMALL_STATE(69)] = 1648,
  [SMALL_STATE(70)] = 1663,
  [SMALL_STATE(71)] = 1678,
  [SMALL_STATE(72)] = 1700,
  [SMALL_STATE(73)] = 1724,
  [SMALL_STATE(74)] = 1746,
  [SMALL_STATE(75)] = 1770,
  [SMALL_STATE(76)] = 1794,
  [SMALL_STATE(77)] = 1816,
  [SMALL_STATE(78)] = 1840,
  [SMALL_STATE(79)] = 1860,
  [SMALL_STATE(80)] = 1882,
  [SMALL_STATE(81)] = 1902,
  [SMALL_STATE(82)] = 1922,
  [SMALL_STATE(83)] = 1946,
  [SMALL_STATE(84)] = 1966,
  [SMALL_STATE(85)] = 1979,
  [SMALL_STATE(86)] = 1994,
  [SMALL_STATE(87)] = 2015,
  [SMALL_STATE(88)] = 2036,
  [SMALL_STATE(89)] = 2057,
  [SMALL_STATE(90)] = 2078,
  [SMALL_STATE(91)] = 2099,
  [SMALL_STATE(92)] = 2120,
  [SMALL_STATE(93)] = 2141,
  [SMALL_STATE(94)] = 2162,
  [SMALL_STATE(95)] = 2183,
  [SMALL_STATE(96)] = 2196,
  [SMALL_STATE(97)] = 2217,
  [SMALL_STATE(98)] = 2238,
  [SMALL_STATE(99)] = 2251,
  [SMALL_STATE(100)] = 2272,
  [SMALL_STATE(101)] = 2285,
  [SMALL_STATE(102)] = 2306,
  [SMALL_STATE(103)] = 2327,
  [SMALL_STATE(104)] = 2342,
  [SMALL_STATE(105)] = 2363,
  [SMALL_STATE(106)] = 2384,
  [SMALL_STATE(107)] = 2405,
  [SMALL_STATE(108)] = 2426,
  [SMALL_STATE(109)] = 2439,
  [SMALL_STATE(110)] = 2460,
  [SMALL_STATE(111)] = 2481,
  [SMALL_STATE(112)] = 2497,
  [SMALL_STATE(113)] = 2513,
  [SMALL_STATE(114)] = 2533,
  [SMALL_STATE(115)] = 2553,
  [SMALL_STATE(116)] = 2565,
  [SMALL_STATE(117)] = 2581,
  [SMALL_STATE(118)] = 2599,
  [SMALL_STATE(119)] = 2615,
  [SMALL_STATE(120)] = 2631,
  [SMALL_STATE(121)] = 2647,
  [SMALL_STATE(122)] = 2665,
  [SMALL_STATE(123)] = 2681,
  [SMALL_STATE(124)] = 2697,
  [SMALL_STATE(125)] = 2713,
  [SMALL_STATE(126)] = 2729,
  [SMALL_STATE(127)] = 2747,
  [SMALL_STATE(128)] = 2763,
  [SMALL_STATE(129)] = 2779,
  [SMALL_STATE(130)] = 2795,
  [SMALL_STATE(131)] = 2807,
  [SMALL_STATE(132)] = 2827,
  [SMALL_STATE(133)] = 2843,
  [SMALL_STATE(134)] = 2859,
  [SMALL_STATE(135)] = 2875,
  [SMALL_STATE(136)] = 2893,
  [SMALL_STATE(137)] = 2911,
  [SMALL_STATE(138)] = 2929,
  [SMALL_STATE(139)] = 2947,
  [SMALL_STATE(140)] = 2965,
  [SMALL_STATE(141)] = 2979,
  [SMALL_STATE(142)] = 2997,
  [SMALL_STATE(143)] = 3015,
  [SMALL_STATE(144)] = 3026,
  [SMALL_STATE(145)] = 3043,
  [SMALL_STATE(146)] = 3056,
  [SMALL_STATE(147)] = 3067,
  [SMALL_STATE(148)] = 3084,
  [SMALL_STATE(149)] = 3101,
  [SMALL_STATE(150)] = 3118,
  [SMALL_STATE(151)] = 3133,
  [SMALL_STATE(152)] = 3150,
  [SMALL_STATE(153)] = 3165,
  [SMALL_STATE(154)] = 3176,
  [SMALL_STATE(155)] = 3191,
  [SMALL_STATE(156)] = 3206,
  [SMALL_STATE(157)] = 3221,
  [SMALL_STATE(158)] = 3236,
  [SMALL_STATE(159)] = 3251,
  [SMALL_STATE(160)] = 3268,
  [SMALL_STATE(161)] = 3283,
  [SMALL_STATE(162)] = 3300,
  [SMALL_STATE(163)] = 3315,
  [SMALL_STATE(164)] = 3330,
  [SMALL_STATE(165)] = 3347,
  [SMALL_STATE(166)] = 3362,
  [SMALL_STATE(167)] = 3377,
  [SMALL_STATE(168)] = 3394,
  [SMALL_STATE(169)] = 3409,
  [SMALL_STATE(170)] = 3424,
  [SMALL_STATE(171)] = 3439,
  [SMALL_STATE(172)] = 3450,
  [SMALL_STATE(173)] = 3461,
  [SMALL_STATE(174)] = 3474,
  [SMALL_STATE(175)] = 3485,
  [SMALL_STATE(176)] = 3498,
  [SMALL_STATE(177)] = 3513,
  [SMALL_STATE(178)] = 3530,
  [SMALL_STATE(179)] = 3545,
  [SMALL_STATE(180)] = 3560,
  [SMALL_STATE(181)] = 3571,
  [SMALL_STATE(182)] = 3582,
  [SMALL_STATE(183)] = 3597,
  [SMALL_STATE(184)] = 3608,
  [SMALL_STATE(185)] = 3623,
  [SMALL_STATE(186)] = 3640,
  [SMALL_STATE(187)] = 3655,
  [SMALL_STATE(188)] = 3672,
  [SMALL_STATE(189)] = 3687,
  [SMALL_STATE(190)] = 3704,
  [SMALL_STATE(191)] = 3721,
  [SMALL_STATE(192)] = 3738,
  [SMALL_STATE(193)] = 3755,
  [SMALL_STATE(194)] = 3772,
  [SMALL_STATE(195)] = 3783,
  [SMALL_STATE(196)] = 3794,
  [SMALL_STATE(197)] = 3807,
  [SMALL_STATE(198)] = 3824,
  [SMALL_STATE(199)] = 3835,
  [SMALL_STATE(200)] = 3850,
  [SMALL_STATE(201)] = 3861,
  [SMALL_STATE(202)] = 3872,
  [SMALL_STATE(203)] = 3883,
  [SMALL_STATE(204)] = 3898,
  [SMALL_STATE(205)] = 3913,
  [SMALL_STATE(206)] = 3930,
  [SMALL_STATE(207)] = 3945,
  [SMALL_STATE(208)] = 3956,
  [SMALL_STATE(209)] = 3967,
  [SMALL_STATE(210)] = 3984,
  [SMALL_STATE(211)] = 3999,
  [SMALL_STATE(212)] = 4016,
  [SMALL_STATE(213)] = 4027,
  [SMALL_STATE(214)] = 4044,
  [SMALL_STATE(215)] = 4055,
  [SMALL_STATE(216)] = 4066,
  [SMALL_STATE(217)] = 4081,
  [SMALL_STATE(218)] = 4096,
  [SMALL_STATE(219)] = 4111,
  [SMALL_STATE(220)] = 4126,
  [SMALL_STATE(221)] = 4141,
  [SMALL_STATE(222)] = 4152,
  [SMALL_STATE(223)] = 4167,
  [SMALL_STATE(224)] = 4182,
  [SMALL_STATE(225)] = 4197,
  [SMALL_STATE(226)] = 4212,
  [SMALL_STATE(227)] = 4229,
  [SMALL_STATE(228)] = 4246,
  [SMALL_STATE(229)] = 4263,
  [SMALL_STATE(230)] = 4274,
  [SMALL_STATE(231)] = 4291,
  [SMALL_STATE(232)] = 4306,
  [SMALL_STATE(233)] = 4323,
  [SMALL_STATE(234)] = 4334,
  [SMALL_STATE(235)] = 4349,
  [SMALL_STATE(236)] = 4364,
  [SMALL_STATE(237)] = 4375,
  [SMALL_STATE(238)] = 4386,
  [SMALL_STATE(239)] = 4397,
  [SMALL_STATE(240)] = 4408,
  [SMALL_STATE(241)] = 4419,
  [SMALL_STATE(242)] = 4434,
  [SMALL_STATE(243)] = 4445,
  [SMALL_STATE(244)] = 4456,
  [SMALL_STATE(245)] = 4471,
  [SMALL_STATE(246)] = 4482,
  [SMALL_STATE(247)] = 4497,
  [SMALL_STATE(248)] = 4512,
  [SMALL_STATE(249)] = 4523,
  [SMALL_STATE(250)] = 4538,
  [SMALL_STATE(251)] = 4549,
  [SMALL_STATE(252)] = 4560,
  [SMALL_STATE(253)] = 4575,
  [SMALL_STATE(254)] = 4586,
  [SMALL_STATE(255)] = 4603,
  [SMALL_STATE(256)] = 4614,
  [SMALL_STATE(257)] = 4625,
  [SMALL_STATE(258)] = 4636,
  [SMALL_STATE(259)] = 4651,
  [SMALL_STATE(260)] = 4666,
  [SMALL_STATE(261)] = 4680,
  [SMALL_STATE(262)] = 4694,
  [SMALL_STATE(263)] = 4708,
  [SMALL_STATE(264)] = 4722,
  [SMALL_STATE(265)] = 4732,
  [SMALL_STATE(266)] = 4746,
  [SMALL_STATE(267)] = 4760,
  [SMALL_STATE(268)] = 4770,
  [SMALL_STATE(269)] = 4780,
  [SMALL_STATE(270)] = 4794,
  [SMALL_STATE(271)] = 4808,
  [SMALL_STATE(272)] = 4818,
  [SMALL_STATE(273)] = 4832,
  [SMALL_STATE(274)] = 4842,
  [SMALL_STATE(275)] = 4854,
  [SMALL_STATE(276)] = 4868,
  [SMALL_STATE(277)] = 4882,
  [SMALL_STATE(278)] = 4896,
  [SMALL_STATE(279)] = 4908,
  [SMALL_STATE(280)] = 4922,
  [SMALL_STATE(281)] = 4936,
  [SMALL_STATE(282)] = 4946,
  [SMALL_STATE(283)] = 4956,
  [SMALL_STATE(284)] = 4968,
  [SMALL_STATE(285)] = 4978,
  [SMALL_STATE(286)] = 4988,
  [SMALL_STATE(287)] = 5002,
  [SMALL_STATE(288)] = 5016,
  [SMALL_STATE(289)] = 5030,
  [SMALL_STATE(290)] = 5044,
  [SMALL_STATE(291)] = 5058,
  [SMALL_STATE(292)] = 5068,
  [SMALL_STATE(293)] = 5078,
  [SMALL_STATE(294)] = 5090,
  [SMALL_STATE(295)] = 5104,
  [SMALL_STATE(296)] = 5116,
  [SMALL_STATE(297)] = 5128,
  [SMALL_STATE(298)] = 5140,
  [SMALL_STATE(299)] = 5154,
  [SMALL_STATE(300)] = 5168,
  [SMALL_STATE(301)] = 5182,
  [SMALL_STATE(302)] = 5196,
  [SMALL_STATE(303)] = 5210,
  [SMALL_STATE(304)] = 5224,
  [SMALL_STATE(305)] = 5238,
  [SMALL_STATE(306)] = 5252,
  [SMALL_STATE(307)] = 5266,
  [SMALL_STATE(308)] = 5278,
  [SMALL_STATE(309)] = 5292,
  [SMALL_STATE(310)] = 5306,
  [SMALL_STATE(311)] = 5316,
  [SMALL_STATE(312)] = 5330,
  [SMALL_STATE(313)] = 5344,
  [SMALL_STATE(314)] = 5356,
  [SMALL_STATE(315)] = 5368,
  [SMALL_STATE(316)] = 5378,
  [SMALL_STATE(317)] = 5388,
  [SMALL_STATE(318)] = 5398,
  [SMALL_STATE(319)] = 5408,
  [SMALL_STATE(320)] = 5422,
  [SMALL_STATE(321)] = 5432,
  [SMALL_STATE(322)] = 5446,
  [SMALL_STATE(323)] = 5458,
  [SMALL_STATE(324)] = 5472,
  [SMALL_STATE(325)] = 5486,
  [SMALL_STATE(326)] = 5498,
  [SMALL_STATE(327)] = 5512,
  [SMALL_STATE(328)] = 5526,
  [SMALL_STATE(329)] = 5540,
  [SMALL_STATE(330)] = 5552,
  [SMALL_STATE(331)] = 5566,
  [SMALL_STATE(332)] = 5580,
  [SMALL_STATE(333)] = 5592,
  [SMALL_STATE(334)] = 5606,
  [SMALL_STATE(335)] = 5618,
  [SMALL_STATE(336)] = 5630,
  [SMALL_STATE(337)] = 5642,
  [SMALL_STATE(338)] = 5656,
  [SMALL_STATE(339)] = 5666,
  [SMALL_STATE(340)] = 5680,
  [SMALL_STATE(341)] = 5694,
  [SMALL_STATE(342)] = 5708,
  [SMALL_STATE(343)] = 5722,
  [SMALL_STATE(344)] = 5734,
  [SMALL_STATE(345)] = 5746,
  [SMALL_STATE(346)] = 5760,
  [SMALL_STATE(347)] = 5772,
  [SMALL_STATE(348)] = 5782,
  [SMALL_STATE(349)] = 5796,
  [SMALL_STATE(350)] = 5810,
  [SMALL_STATE(351)] = 5820,
  [SMALL_STATE(352)] = 5834,
  [SMALL_STATE(353)] = 5848,
  [SMALL_STATE(354)] = 5862,
  [SMALL_STATE(355)] = 5876,
  [SMALL_STATE(356)] = 5886,
  [SMALL_STATE(357)] = 5896,
  [SMALL_STATE(358)] = 5906,
  [SMALL_STATE(359)] = 5916,
  [SMALL_STATE(360)] = 5926,
  [SMALL_STATE(361)] = 5936,
  [SMALL_STATE(362)] = 5948,
  [SMALL_STATE(363)] = 5958,
  [SMALL_STATE(364)] = 5970,
  [SMALL_STATE(365)] = 5980,
  [SMALL_STATE(366)] = 5994,
  [SMALL_STATE(367)] = 6006,
  [SMALL_STATE(368)] = 6020,
  [SMALL_STATE(369)] = 6030,
  [SMALL_STATE(370)] = 6042,
  [SMALL_STATE(371)] = 6056,
  [SMALL_STATE(372)] = 6066,
  [SMALL_STATE(373)] = 6080,
  [SMALL_STATE(374)] = 6090,
  [SMALL_STATE(375)] = 6100,
  [SMALL_STATE(376)] = 6110,
  [SMALL_STATE(377)] = 6120,
  [SMALL_STATE(378)] = 6134,
  [SMALL_STATE(379)] = 6148,
  [SMALL_STATE(380)] = 6158,
  [SMALL_STATE(381)] = 6172,
  [SMALL_STATE(382)] = 6182,
  [SMALL_STATE(383)] = 6196,
  [SMALL_STATE(384)] = 6210,
  [SMALL_STATE(385)] = 6224,
  [SMALL_STATE(386)] = 6238,
  [SMALL_STATE(387)] = 6252,
  [SMALL_STATE(388)] = 6266,
  [SMALL_STATE(389)] = 6280,
  [SMALL_STATE(390)] = 6294,
  [SMALL_STATE(391)] = 6308,
  [SMALL_STATE(392)] = 6320,
  [SMALL_STATE(393)] = 6330,
  [SMALL_STATE(394)] = 6340,
  [SMALL_STATE(395)] = 6354,
  [SMALL_STATE(396)] = 6366,
  [SMALL_STATE(397)] = 6380,
  [SMALL_STATE(398)] = 6390,
  [SMALL_STATE(399)] = 6402,
  [SMALL_STATE(400)] = 6414,
  [SMALL_STATE(401)] = 6428,
  [SMALL_STATE(402)] = 6440,
  [SMALL_STATE(403)] = 6454,
  [SMALL_STATE(404)] = 6464,
  [SMALL_STATE(405)] = 6478,
  [SMALL_STATE(406)] = 6488,
  [SMALL_STATE(407)] = 6498,
  [SMALL_STATE(408)] = 6512,
  [SMALL_STATE(409)] = 6524,
  [SMALL_STATE(410)] = 6538,
  [SMALL_STATE(411)] = 6552,
  [SMALL_STATE(412)] = 6566,
  [SMALL_STATE(413)] = 6580,
  [SMALL_STATE(414)] = 6594,
  [SMALL_STATE(415)] = 6608,
  [SMALL_STATE(416)] = 6620,
  [SMALL_STATE(417)] = 6634,
  [SMALL_STATE(418)] = 6646,
  [SMALL_STATE(419)] = 6660,
  [SMALL_STATE(420)] = 6672,
  [SMALL_STATE(421)] = 6686,
  [SMALL_STATE(422)] = 6696,
  [SMALL_STATE(423)] = 6706,
  [SMALL_STATE(424)] = 6718,
  [SMALL_STATE(425)] = 6728,
  [SMALL_STATE(426)] = 6738,
  [SMALL_STATE(427)] = 6748,
  [SMALL_STATE(428)] = 6762,
  [SMALL_STATE(429)] = 6771,
  [SMALL_STATE(430)] = 6782,
  [SMALL_STATE(431)] = 6791,
  [SMALL_STATE(432)] = 6802,
  [SMALL_STATE(433)] = 6811,
  [SMALL_STATE(434)] = 6820,
  [SMALL_STATE(435)] = 6831,
  [SMALL_STATE(436)] = 6840,
  [SMALL_STATE(437)] = 6849,
  [SMALL_STATE(438)] = 6860,
  [SMALL_STATE(439)] = 6871,
  [SMALL_STATE(440)] = 6882,
  [SMALL_STATE(441)] = 6891,
  [SMALL_STATE(442)] = 6900,
  [SMALL_STATE(443)] = 6909,
  [SMALL_STATE(444)] = 6918,
  [SMALL_STATE(445)] = 6927,
  [SMALL_STATE(446)] = 6936,
  [SMALL_STATE(447)] = 6945,
  [SMALL_STATE(448)] = 6954,
  [SMALL_STATE(449)] = 6965,
  [SMALL_STATE(450)] = 6974,
  [SMALL_STATE(451)] = 6983,
  [SMALL_STATE(452)] = 6992,
  [SMALL_STATE(453)] = 7001,
  [SMALL_STATE(454)] = 7010,
  [SMALL_STATE(455)] = 7019,
  [SMALL_STATE(456)] = 7028,
  [SMALL_STATE(457)] = 7039,
  [SMALL_STATE(458)] = 7050,
  [SMALL_STATE(459)] = 7059,
  [SMALL_STATE(460)] = 7068,
  [SMALL_STATE(461)] = 7077,
  [SMALL_STATE(462)] = 7086,
  [SMALL_STATE(463)] = 7097,
  [SMALL_STATE(464)] = 7106,
  [SMALL_STATE(465)] = 7117,
  [SMALL_STATE(466)] = 7126,
  [SMALL_STATE(467)] = 7137,
  [SMALL_STATE(468)] = 7146,
  [SMALL_STATE(469)] = 7155,
  [SMALL_STATE(470)] = 7164,
  [SMALL_STATE(471)] = 7173,
  [SMALL_STATE(472)] = 7182,
  [SMALL_STATE(473)] = 7191,
  [SMALL_STATE(474)] = 7200,
  [SMALL_STATE(475)] = 7211,
  [SMALL_STATE(476)] = 7222,
  [SMALL_STATE(477)] = 7231,
  [SMALL_STATE(478)] = 7240,
  [SMALL_STATE(479)] = 7249,
  [SMALL_STATE(480)] = 7258,
  [SMALL_STATE(481)] = 7269,
  [SMALL_STATE(482)] = 7278,
  [SMALL_STATE(483)] = 7287,
  [SMALL_STATE(484)] = 7296,
  [SMALL_STATE(485)] = 7305,
  [SMALL_STATE(486)] = 7314,
  [SMALL_STATE(487)] = 7323,
  [SMALL_STATE(488)] = 7332,
  [SMALL_STATE(489)] = 7343,
  [SMALL_STATE(490)] = 7352,
  [SMALL_STATE(491)] = 7363,
  [SMALL_STATE(492)] = 7372,
  [SMALL_STATE(493)] = 7383,
  [SMALL_STATE(494)] = 7392,
  [SMALL_STATE(495)] = 7401,
  [SMALL_STATE(496)] = 7410,
  [SMALL_STATE(497)] = 7419,
  [SMALL_STATE(498)] = 7428,
  [SMALL_STATE(499)] = 7437,
  [SMALL_STATE(500)] = 7446,
  [SMALL_STATE(501)] = 7457,
  [SMALL_STATE(502)] = 7466,
  [SMALL_STATE(503)] = 7475,
  [SMALL_STATE(504)] = 7484,
  [SMALL_STATE(505)] = 7493,
  [SMALL_STATE(506)] = 7502,
  [SMALL_STATE(507)] = 7513,
  [SMALL_STATE(508)] = 7522,
  [SMALL_STATE(509)] = 7530,
  [SMALL_STATE(510)] = 7538,
  [SMALL_STATE(511)] = 7546,
  [SMALL_STATE(512)] = 7554,
  [SMALL_STATE(513)] = 7562,
  [SMALL_STATE(514)] = 7570,
  [SMALL_STATE(515)] = 7578,
  [SMALL_STATE(516)] = 7586,
  [SMALL_STATE(517)] = 7594,
  [SMALL_STATE(518)] = 7602,
  [SMALL_STATE(519)] = 7610,
  [SMALL_STATE(520)] = 7618,
  [SMALL_STATE(521)] = 7626,
  [SMALL_STATE(522)] = 7634,
  [SMALL_STATE(523)] = 7642,
  [SMALL_STATE(524)] = 7650,
  [SMALL_STATE(525)] = 7658,
  [SMALL_STATE(526)] = 7666,
  [SMALL_STATE(527)] = 7674,
  [SMALL_STATE(528)] = 7682,
  [SMALL_STATE(529)] = 7690,
  [SMALL_STATE(530)] = 7698,
  [SMALL_STATE(531)] = 7706,
  [SMALL_STATE(532)] = 7714,
  [SMALL_STATE(533)] = 7722,
  [SMALL_STATE(534)] = 7730,
  [SMALL_STATE(535)] = 7738,
  [SMALL_STATE(536)] = 7746,
  [SMALL_STATE(537)] = 7754,
  [SMALL_STATE(538)] = 7762,
  [SMALL_STATE(539)] = 7770,
  [SMALL_STATE(540)] = 7778,
  [SMALL_STATE(541)] = 7786,
  [SMALL_STATE(542)] = 7794,
  [SMALL_STATE(543)] = 7802,
  [SMALL_STATE(544)] = 7810,
  [SMALL_STATE(545)] = 7818,
  [SMALL_STATE(546)] = 7826,
  [SMALL_STATE(547)] = 7834,
  [SMALL_STATE(548)] = 7842,
  [SMALL_STATE(549)] = 7850,
  [SMALL_STATE(550)] = 7858,
  [SMALL_STATE(551)] = 7866,
  [SMALL_STATE(552)] = 7874,
  [SMALL_STATE(553)] = 7882,
  [SMALL_STATE(554)] = 7890,
  [SMALL_STATE(555)] = 7898,
  [SMALL_STATE(556)] = 7906,
  [SMALL_STATE(557)] = 7914,
  [SMALL_STATE(558)] = 7922,
  [SMALL_STATE(559)] = 7930,
  [SMALL_STATE(560)] = 7938,
  [SMALL_STATE(561)] = 7946,
  [SMALL_STATE(562)] = 7954,
  [SMALL_STATE(563)] = 7962,
  [SMALL_STATE(564)] = 7970,
  [SMALL_STATE(565)] = 7978,
  [SMALL_STATE(566)] = 7986,
  [SMALL_STATE(567)] = 7994,
  [SMALL_STATE(568)] = 8002,
  [SMALL_STATE(569)] = 8010,
  [SMALL_STATE(570)] = 8018,
  [SMALL_STATE(571)] = 8026,
  [SMALL_STATE(572)] = 8034,
  [SMALL_STATE(573)] = 8042,
  [SMALL_STATE(574)] = 8050,
  [SMALL_STATE(575)] = 8058,
  [SMALL_STATE(576)] = 8066,
  [SMALL_STATE(577)] = 8074,
  [SMALL_STATE(578)] = 8082,
  [SMALL_STATE(579)] = 8090,
  [SMALL_STATE(580)] = 8098,
  [SMALL_STATE(581)] = 8106,
  [SMALL_STATE(582)] = 8114,
  [SMALL_STATE(583)] = 8122,
  [SMALL_STATE(584)] = 8130,
  [SMALL_STATE(585)] = 8138,
  [SMALL_STATE(586)] = 8146,
  [SMALL_STATE(587)] = 8154,
  [SMALL_STATE(588)] = 8162,
  [SMALL_STATE(589)] = 8170,
  [SMALL_STATE(590)] = 8178,
  [SMALL_STATE(591)] = 8186,
  [SMALL_STATE(592)] = 8194,
  [SMALL_STATE(593)] = 8202,
  [SMALL_STATE(594)] = 8210,
  [SMALL_STATE(595)] = 8218,
  [SMALL_STATE(596)] = 8226,
  [SMALL_STATE(597)] = 8234,
  [SMALL_STATE(598)] = 8242,
  [SMALL_STATE(599)] = 8250,
  [SMALL_STATE(600)] = 8258,
  [SMALL_STATE(601)] = 8266,
  [SMALL_STATE(602)] = 8274,
  [SMALL_STATE(603)] = 8282,
  [SMALL_STATE(604)] = 8290,
  [SMALL_STATE(605)] = 8298,
  [SMALL_STATE(606)] = 8306,
  [SMALL_STATE(607)] = 8314,
  [SMALL_STATE(608)] = 8322,
  [SMALL_STATE(609)] = 8330,
  [SMALL_STATE(610)] = 8338,
  [SMALL_STATE(611)] = 8346,
  [SMALL_STATE(612)] = 8354,
  [SMALL_STATE(613)] = 8362,
  [SMALL_STATE(614)] = 8370,
  [SMALL_STATE(615)] = 8378,
  [SMALL_STATE(616)] = 8386,
  [SMALL_STATE(617)] = 8394,
  [SMALL_STATE(618)] = 8402,
  [SMALL_STATE(619)] = 8410,
  [SMALL_STATE(620)] = 8418,
  [SMALL_STATE(621)] = 8426,
  [SMALL_STATE(622)] = 8434,
  [SMALL_STATE(623)] = 8442,
  [SMALL_STATE(624)] = 8450,
  [SMALL_STATE(625)] = 8458,
  [SMALL_STATE(626)] = 8466,
  [SMALL_STATE(627)] = 8474,
  [SMALL_STATE(628)] = 8482,
  [SMALL_STATE(629)] = 8490,
  [SMALL_STATE(630)] = 8498,
  [SMALL_STATE(631)] = 8506,
  [SMALL_STATE(632)] = 8514,
  [SMALL_STATE(633)] = 8522,
  [SMALL_STATE(634)] = 8530,
  [SMALL_STATE(635)] = 8538,
  [SMALL_STATE(636)] = 8546,
  [SMALL_STATE(637)] = 8554,
  [SMALL_STATE(638)] = 8562,
  [SMALL_STATE(639)] = 8570,
  [SMALL_STATE(640)] = 8578,
  [SMALL_STATE(641)] = 8586,
  [SMALL_STATE(642)] = 8594,
  [SMALL_STATE(643)] = 8602,
  [SMALL_STATE(644)] = 8610,
  [SMALL_STATE(645)] = 8618,
  [SMALL_STATE(646)] = 8626,
  [SMALL_STATE(647)] = 8634,
  [SMALL_STATE(648)] = 8642,
  [SMALL_STATE(649)] = 8650,
  [SMALL_STATE(650)] = 8658,
  [SMALL_STATE(651)] = 8666,
  [SMALL_STATE(652)] = 8674,
  [SMALL_STATE(653)] = 8682,
  [SMALL_STATE(654)] = 8690,
  [SMALL_STATE(655)] = 8698,
  [SMALL_STATE(656)] = 8706,
  [SMALL_STATE(657)] = 8714,
  [SMALL_STATE(658)] = 8722,
  [SMALL_STATE(659)] = 8730,
  [SMALL_STATE(660)] = 8738,
  [SMALL_STATE(661)] = 8746,
  [SMALL_STATE(662)] = 8754,
  [SMALL_STATE(663)] = 8762,
  [SMALL_STATE(664)] = 8770,
  [SMALL_STATE(665)] = 8778,
  [SMALL_STATE(666)] = 8786,
  [SMALL_STATE(667)] = 8794,
  [SMALL_STATE(668)] = 8802,
  [SMALL_STATE(669)] = 8810,
  [SMALL_STATE(670)] = 8818,
  [SMALL_STATE(671)] = 8826,
  [SMALL_STATE(672)] = 8834,
  [SMALL_STATE(673)] = 8842,
  [SMALL_STATE(674)] = 8850,
  [SMALL_STATE(675)] = 8858,
  [SMALL_STATE(676)] = 8866,
  [SMALL_STATE(677)] = 8874,
  [SMALL_STATE(678)] = 8882,
  [SMALL_STATE(679)] = 8890,
  [SMALL_STATE(680)] = 8898,
  [SMALL_STATE(681)] = 8906,
  [SMALL_STATE(682)] = 8914,
  [SMALL_STATE(683)] = 8922,
  [SMALL_STATE(684)] = 8930,
  [SMALL_STATE(685)] = 8938,
  [SMALL_STATE(686)] = 8946,
  [SMALL_STATE(687)] = 8954,
  [SMALL_STATE(688)] = 8962,
  [SMALL_STATE(689)] = 8970,
  [SMALL_STATE(690)] = 8978,
  [SMALL_STATE(691)] = 8986,
  [SMALL_STATE(692)] = 8994,
  [SMALL_STATE(693)] = 9002,
  [SMALL_STATE(694)] = 9010,
  [SMALL_STATE(695)] = 9018,
  [SMALL_STATE(696)] = 9026,
  [SMALL_STATE(697)] = 9034,
  [SMALL_STATE(698)] = 9042,
  [SMALL_STATE(699)] = 9050,
  [SMALL_STATE(700)] = 9058,
  [SMALL_STATE(701)] = 9066,
  [SMALL_STATE(702)] = 9074,
  [SMALL_STATE(703)] = 9082,
  [SMALL_STATE(704)] = 9090,
  [SMALL_STATE(705)] = 9098,
  [SMALL_STATE(706)] = 9106,
  [SMALL_STATE(707)] = 9114,
  [SMALL_STATE(708)] = 9122,
  [SMALL_STATE(709)] = 9130,
  [SMALL_STATE(710)] = 9138,
  [SMALL_STATE(711)] = 9146,
  [SMALL_STATE(712)] = 9154,
  [SMALL_STATE(713)] = 9162,
  [SMALL_STATE(714)] = 9170,
  [SMALL_STATE(715)] = 9178,
  [SMALL_STATE(716)] = 9186,
  [SMALL_STATE(717)] = 9194,
  [SMALL_STATE(718)] = 9202,
  [SMALL_STATE(719)] = 9210,
  [SMALL_STATE(720)] = 9218,
  [SMALL_STATE(721)] = 9226,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(488),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(506),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(594),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(241),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(492),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(440),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(347),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(613),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(604),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(356),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(439),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(720),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(558),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(567),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(690),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(464),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(474),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(609),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(475),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(638),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(641),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(646),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(715),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(162),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(466),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(156),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(678),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(604),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(356),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(439),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(720),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(558),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(567),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(690),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(464),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(474),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(609),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(475),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(638),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(641),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(646),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(715),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(466),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(678),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 6),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 6),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 59),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 59),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(488),
  [221] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(506),
  [224] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(594),
  [227] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(241),
  [230] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(492),
  [233] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(440),
  [236] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(347),
  [239] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(613),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(566),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(566),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(496),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(422),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(424),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(425),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(426),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(498),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [274] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(496),
  [277] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(421),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(422),
  [283] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(424),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(425),
  [289] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(426),
  [292] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(498),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = false}}, SHIFT(447),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(694),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(447),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(493),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(449),
  [315] = {.entry = {.count = 1, .reusable = false}}, SHIFT(376),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [319] = {.entry = {.count = 1, .reusable = false}}, SHIFT(379),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(381),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(518),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 52),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [343] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [347] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [351] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(698),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(698),
  [359] = {.entry = {.count = 1, .reusable = false}}, SHIFT(432),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(280),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [369] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [373] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [379] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 39),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 39),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(578),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [387] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [391] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [395] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 49),
  [403] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 49),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 33),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 36),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 37),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 51),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 53),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 54),
  [417] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 55),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 55),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [423] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [425] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [427] = {.entry = {.count = 1, .reusable = false}}, SHIFT(240),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 37),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 36),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [445] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [450] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(441),
  [453] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(443),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(648),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [462] = {.entry = {.count = 1, .reusable = false}}, SHIFT(546),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(546),
  [466] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [468] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [470] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [474] = {.entry = {.count = 1, .reusable = false}}, SHIFT(441),
  [476] = {.entry = {.count = 1, .reusable = false}}, SHIFT(443),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 34),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(432),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [488] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(578),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [495] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 56),
  [497] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 56), SHIFT_REPEAT(85),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 56),
  [502] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 39),
  [504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 39),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 55),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 55),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [514] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 38),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 38),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(516),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(495),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(614),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(472),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(542),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(373),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(479),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(484),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(647),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(655),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(374),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 2, 0, 0),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(602),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(649),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [582] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(433),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(442),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(445),
  [596] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignmment_operator, 1, 0, 0),
  [598] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignmment_operator, 1, 0, 0),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(712),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(473),
  [612] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(687),
  [624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(480),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(481),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(397),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [638] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [640] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(432),
  [643] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 35), SHIFT_REPEAT(153),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 35),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(568),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(689),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(431),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(525),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(526),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(695),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(658),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [668] = {.entry = {.count = 1, .reusable = true}}, SHIFT(627),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 12),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(530),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_over_time_operator, 1, 0, 0),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 50),
  [678] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 50), SHIFT_REPEAT(480),
  [681] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 50), SHIFT_REPEAT(481),
  [684] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 50), SHIFT_REPEAT(397),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 34),
  [689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [691] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(648),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(665),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(405),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(643),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(406),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [710] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 114),
  [712] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 114),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 104),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [724] = {.entry = {.count = 1, .reusable = true}}, SHIFT(532),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(485),
  [728] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [730] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(590),
  [736] = {.entry = {.count = 1, .reusable = false}}, SHIFT(298),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(721),
  [740] = {.entry = {.count = 1, .reusable = false}}, SHIFT(299),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(592),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(486),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [760] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(691),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_camera, 1, 0, 0),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(632),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(692),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(550),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(668),
  [788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(511),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [792] = {.entry = {.count = 1, .reusable = true}}, SHIFT(587),
  [794] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [796] = {.entry = {.count = 1, .reusable = true}}, SHIFT(657),
  [798] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [800] = {.entry = {.count = 1, .reusable = true}}, SHIFT(514),
  [802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(519),
  [806] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [808] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [810] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [812] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [814] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [816] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [818] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(471),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(468),
  [824] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(454),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(579),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [832] = {.entry = {.count = 1, .reusable = true}}, SHIFT(544),
  [834] = {.entry = {.count = 1, .reusable = true}}, SHIFT(547),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [838] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 40),
  [840] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(710),
  [844] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 41),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(556),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(572),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(574),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(576),
  [858] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [860] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(583),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(586),
  [868] = {.entry = {.count = 1, .reusable = false}}, SHIFT(467),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(589),
  [872] = {.entry = {.count = 1, .reusable = false}}, SHIFT(507),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(469),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(595),
  [878] = {.entry = {.count = 1, .reusable = true}}, SHIFT(598),
  [880] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 3, 0, 48),
  [882] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_binary_expression, 3, 0, 73),
  [884] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(512),
  [890] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [892] = {.entry = {.count = 1, .reusable = true}}, SHIFT(697),
  [894] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 74),
  [896] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 75),
  [898] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [900] = {.entry = {.count = 1, .reusable = true}}, SHIFT(537),
  [902] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [904] = {.entry = {.count = 1, .reusable = true}}, SHIFT(570),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(607),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(610),
  [912] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [914] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 2, 0, 0),
  [916] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [918] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [920] = {.entry = {.count = 1, .reusable = true}}, SHIFT(623),
  [922] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(625),
  [926] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 40),
  [928] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [930] = {.entry = {.count = 1, .reusable = true}}, SHIFT(601),
  [932] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 57),
  [934] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 41),
  [936] = {.entry = {.count = 1, .reusable = true}}, SHIFT(616),
  [938] = {.entry = {.count = 1, .reusable = true}}, SHIFT(628),
  [940] = {.entry = {.count = 1, .reusable = true}}, SHIFT(633),
  [942] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [944] = {.entry = {.count = 1, .reusable = true}}, SHIFT(629),
  [946] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 4, 0, 0),
  [948] = {.entry = {.count = 1, .reusable = true}}, SHIFT(651),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(652),
  [952] = {.entry = {.count = 1, .reusable = true}}, SHIFT(662),
  [954] = {.entry = {.count = 1, .reusable = true}}, SHIFT(663),
  [956] = {.entry = {.count = 1, .reusable = true}}, SHIFT(664),
  [958] = {.entry = {.count = 1, .reusable = true}}, SHIFT(666),
  [960] = {.entry = {.count = 1, .reusable = true}}, SHIFT(667),
  [962] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [964] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [966] = {.entry = {.count = 1, .reusable = true}}, SHIFT(670),
  [968] = {.entry = {.count = 1, .reusable = true}}, SHIFT(672),
  [970] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(674),
  [974] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [976] = {.entry = {.count = 1, .reusable = true}}, SHIFT(680),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(681),
  [980] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 6, 0, 57),
  [982] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 25),
  [984] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 40),
  [986] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 0),
  [988] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 27),
  [990] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(557),
  [994] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bool_expression, 1, 0, 29),
  [996] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 106),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(499),
  [1000] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_unary_expression, 2, 0, 48),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(707),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(708),
  [1006] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 40),
  [1008] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [1010] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 120),
  [1012] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 104),
  [1014] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 106),
  [1016] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 121),
  [1018] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 120),
  [1020] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 121),
  [1022] = {.entry = {.count = 1, .reusable = true}}, SHIFT(642),
  [1024] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [1026] = {.entry = {.count = 1, .reusable = true}}, SHIFT(562),
  [1028] = {.entry = {.count = 1, .reusable = true}}, SHIFT(700),
  [1030] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [1032] = {.entry = {.count = 1, .reusable = true}}, SHIFT(718),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(719),
  [1036] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [1038] = {.entry = {.count = 1, .reusable = true}}, SHIFT(487),
  [1040] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [1042] = {.entry = {.count = 1, .reusable = true}}, SHIFT(428),
  [1044] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [1046] = {.entry = {.count = 1, .reusable = true}}, SHIFT(605),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(478),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(482),
  [1054] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 42), SHIFT_REPEAT(313),
  [1057] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 42),
  [1059] = {.entry = {.count = 1, .reusable = true}}, SHIFT(634),
  [1061] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [1063] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 44), SHIFT_REPEAT(121),
  [1066] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 44),
  [1068] = {.entry = {.count = 1, .reusable = true}}, SHIFT(448),
  [1070] = {.entry = {.count = 1, .reusable = true}}, SHIFT(531),
  [1072] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [1074] = {.entry = {.count = 1, .reusable = true}}, SHIFT(490),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [1078] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [1080] = {.entry = {.count = 1, .reusable = true}}, SHIFT(702),
  [1082] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [1084] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [1086] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [1088] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [1090] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [1092] = {.entry = {.count = 1, .reusable = true}}, SHIFT(529),
  [1094] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1096] = {.entry = {.count = 1, .reusable = true}}, SHIFT(430),
  [1098] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [1100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [1102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(585),
  [1104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(716),
  [1106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [1108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(596),
  [1110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(470),
  [1112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(517),
  [1114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [1116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [1118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(391),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [1126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [1128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(553),
  [1130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(679),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(581),
  [1136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [1140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(606),
  [1142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [1144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [1146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(619),
  [1148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [1150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(639),
  [1152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [1154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(653),
  [1156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [1158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(677),
  [1160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [1162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(684),
  [1164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [1166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [1171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0),
  [1173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [1175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(451),
  [1177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [1179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(644),
  [1181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [1183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(465),
  [1185] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(536),
  [1188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0),
  [1190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 2, 0, 0),
  [1192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [1194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [1196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [1198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [1202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [1204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(462),
  [1206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(541),
  [1208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [1210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(444),
  [1212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [1214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [1216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(515),
  [1218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(361),
  [1220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(521),
  [1222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(363),
  [1224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [1226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(435),
  [1228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [1230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [1232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(714),
  [1234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [1236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [1239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [1241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 19),
  [1243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [1245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(452),
  [1247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 20),
  [1249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [1251] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(368),
  [1254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [1256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(534),
  [1258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(455),
  [1260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(369),
  [1262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 19),
  [1264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [1266] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(458),
  [1269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [1271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(540),
  [1273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(372),
  [1275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [1277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(549),
  [1279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [1281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [1283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(460),
  [1285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(463),
  [1289] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 42), SHIFT_REPEAT(135),
  [1292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 42),
  [1294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [1296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [1298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [1300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(560),
  [1302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(378),
  [1304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(563),
  [1306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(380),
  [1308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [1310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [1312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(384),
  [1314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [1316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(565),
  [1318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [1320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(569),
  [1322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(387),
  [1324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(580),
  [1326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [1328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [1330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [1332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [1334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(593),
  [1336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [1338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(597),
  [1340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [1342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(600),
  [1344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out, 1, 0, 0),
  [1346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [1348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(704),
  [1350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(392),
  [1352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [1354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(539),
  [1356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [1358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [1360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(612),
  [1362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [1364] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(490),
  [1367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [1369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [1371] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(476),
  [1374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [1376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(615),
  [1378] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(477),
  [1381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [1383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(561),
  [1385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [1387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(618),
  [1389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [1391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(599),
  [1393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [1395] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(398),
  [1398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0),
  [1400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(399),
  [1402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [1406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(635),
  [1408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [1410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [1412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [1414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [1420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_bool, 3, 0, 32),
  [1422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(410),
  [1424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(654),
  [1426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(656),
  [1428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(412),
  [1430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(660),
  [1432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1434] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 91), SHIFT_REPEAT(414),
  [1437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 91),
  [1439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(527),
  [1441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 94),
  [1443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [1445] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(453),
  [1448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [1450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(676),
  [1452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(489),
  [1454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(415),
  [1456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(457),
  [1458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(682),
  [1460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(491),
  [1462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [1464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(686),
  [1466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(494),
  [1468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(419),
  [1470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 33),
  [1472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [1474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [1476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(693),
  [1478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [1480] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 105), SHIFT_REPEAT(252),
  [1483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 105),
  [1485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [1487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [1489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [1491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [1493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(701),
  [1495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [1497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(703),
  [1499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(705),
  [1501] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 111), SHIFT_REPEAT(500),
  [1504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 111),
  [1506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(709),
  [1508] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(501),
  [1511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0),
  [1513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(711),
  [1515] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(502),
  [1518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [1520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(713),
  [1522] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(503),
  [1525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [1527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [1529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [1531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(505),
  [1533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [1535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [1539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 40),
  [1543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 3, 0, 21),
  [1545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(403),
  [1549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [1551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [1553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [1555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 13),
  [1557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [1559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(429),
  [1561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [1563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 40),
  [1565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [1567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 76),
  [1569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 58),
  [1571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 4, 0, 40),
  [1573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(459),
  [1575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 79),
  [1577] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 0),
  [1579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [1581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 3, 0, 40),
  [1585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [1587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 3, 0, 13),
  [1589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [1591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [1593] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 43),
  [1595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(669),
  [1597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(673),
  [1599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 70),
  [1601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 72),
  [1603] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [1605] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 7, 0, 76),
  [1607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [1609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [1611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [1615] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 3, 0, 40),
  [1617] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 0),
  [1619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(456),
  [1621] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 58),
  [1623] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 3, 0, 0),
  [1625] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 43),
  [1627] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [1629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0),
  [1631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 87),
  [1633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(524),
  [1635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [1637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(620),
  [1639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(575),
  [1641] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 13),
  [1643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1645] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 3, 0, 0),
  [1647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [1649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 3, 0, 109),
  [1651] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 40),
  [1653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 106),
  [1655] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bool_or_identifier_expansion_repeat1, 2, 0, 71),
  [1657] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 69),
  [1659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 0),
  [1661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 6, 0, 57),
  [1663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 62),
  [1665] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 0),
  [1667] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 6, 0, 77),
  [1669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [1671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(543),
  [1673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(548),
  [1675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 4, 0, 0),
  [1677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 78),
  [1679] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 36),
  [1681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(611),
  [1683] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 36),
  [1685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 0),
  [1687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 2, 0, 0),
  [1689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 3, 0, 22),
  [1691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 3, 0, 21),
  [1693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [1695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 3, 0, 24),
  [1697] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 3, 0, 21),
  [1701] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 3, 0, 0),
  [1703] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 46),
  [1705] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 5, 0, 0),
  [1707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 16),
  [1713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 24),
  [1715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(617),
  [1717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 2, 0, 0),
  [1719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 4, 0, 0),
  [1721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [1723] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 24),
  [1725] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 80),
  [1727] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 0),
  [1729] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [1731] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 81),
  [1733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 82),
  [1735] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 83),
  [1737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [1739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(659),
  [1741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [1743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 3, 0, 0),
  [1745] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 3, 0, 0),
  [1747] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 19),
  [1749] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 4, 0, 0),
  [1751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [1753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(683),
  [1755] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 20),
  [1757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [1761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [1763] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 19),
  [1767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [1769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(688),
  [1773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 5, 0, 60),
  [1775] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_setable, 3, 0, 14),
  [1777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [1779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_bool, 3, 0, 31),
  [1781] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 84),
  [1783] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 65),
  [1785] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 85),
  [1787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(685),
  [1789] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 86),
  [1791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 66),
  [1793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(717),
  [1795] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [1797] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 3, 0, 87),
  [1799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(382),
  [1801] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1803] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 88),
  [1805] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 68),
  [1807] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 3, 0, 0),
  [1809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 89),
  [1811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 40),
  [1813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [1815] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 70),
  [1817] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 47),
  [1819] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 0),
  [1821] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 40),
  [1823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 90),
  [1825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1827] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 71),
  [1829] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [1831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 92),
  [1833] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 72),
  [1835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(636),
  [1837] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 4, 0, 93),
  [1839] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 63),
  [1841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [1843] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 24),
  [1845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 57),
  [1849] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 2, 0, 0),
  [1851] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 95),
  [1853] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 36),
  [1855] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [1857] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 96),
  [1859] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 97),
  [1861] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 98),
  [1863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(438),
  [1865] = {.entry = {.count = 1, .reusable = true}}, SHIFT(483),
  [1867] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1869] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 64),
  [1871] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 65),
  [1873] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 3, 0, 0),
  [1875] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 66),
  [1877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(706),
  [1879] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 99),
  [1881] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 82),
  [1883] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 100),
  [1885] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 0),
  [1887] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 101),
  [1889] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 83),
  [1891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 15),
  [1893] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 5, 0, 0),
  [1895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 67),
  [1897] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 41),
  [1899] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [1903] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade, 7, 0, 102),
  [1905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(446),
  [1907] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 68),
  [1911] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 7, 0, 103),
  [1913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [1915] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 69),
  [1917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [1921] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 16),
  [1923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(497),
  [1925] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 41),
  [1927] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [1929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(645),
  [1931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [1933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(552),
  [1935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(523),
  [1937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [1939] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 107),
  [1941] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 108),
  [1943] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 70),
  [1945] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 109),
  [1947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(522),
  [1949] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 87),
  [1951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 8),
  [1953] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [1955] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 0),
  [1957] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 110),
  [1959] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 36),
  [1961] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 112),
  [1963] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 113),
  [1965] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 90),
  [1967] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 3, 0, 23),
  [1969] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 92),
  [1971] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 5, 0, 93),
  [1973] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 8),
  [1975] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [1977] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 115),
  [1979] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 97),
  [1981] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 116),
  [1983] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [1985] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 117),
  [1987] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 98),
  [1989] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 4, 0, 0),
  [1991] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 71),
  [1993] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_setable, 1, 0, 0),
  [1995] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1997] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 118),
  [1999] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 119),
  [2001] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [2003] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [2005] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 3, 0, 72),
  [2007] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [2009] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [2011] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 3, 0, 23),
  [2013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [2015] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 45),
  [2017] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [2019] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 17),
  [2021] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 18),
  [2023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(504),
  [2025] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 5, 0, 0),
  [2027] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 45),
  [2029] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 0),
  [2031] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 2, 0, 0),
  [2033] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [2035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [2037] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [2039] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 109),
  [2041] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [2043] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 122),
  [2045] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [2047] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 110),
  [2049] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [2051] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 123),
  [2053] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 124),
  [2055] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 5, 0, 0),
  [2057] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 5, 0, 61),
  [2059] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [2061] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [2063] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [2065] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [2067] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [2069] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [2071] = {.entry = {.count = 1, .reusable = true}}, SHIFT(393),
  [2073] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_setable, 2, 0, 9),
  [2075] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 6, 0, 122),
  [2077] = {.entry = {.count = 1, .reusable = true}}, SHIFT(650),
  [2079] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_or_identifier_expansion, 2, 0, 0),
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
