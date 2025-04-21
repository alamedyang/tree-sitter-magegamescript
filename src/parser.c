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
#define STATE_COUNT 666
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 189
#define ALIAS_COUNT 2
#define TOKEN_COUNT 84
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 37
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 106

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BAREWORD = 3,
  anon_sym_LBRACK = 4,
  anon_sym_COMMA = 5,
  anon_sym_RBRACK = 6,
  sym_QUOTED_STRING = 7,
  sym_NUMBER = 8,
  sym_DURATION = 9,
  sym_DISTANCE = 10,
  sym_QUANTITY = 11,
  sym_COLOR = 12,
  sym_BOOLEAN = 13,
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
  sym_source_file = 84,
  sym_bareword_expansion = 85,
  sym_quoted_string_expansion = 86,
  sym_string_expansion = 87,
  sym_number_expansion = 88,
  sym_duration_expansion = 89,
  sym_distance_expansion = 90,
  sym_quantity_expansion = 91,
  sym_color_expansion = 92,
  sym_constant_expansion = 93,
  sym_constant_value_expansion = 94,
  sym__root = 95,
  sym_include_macro = 96,
  sym_constant_assignment = 97,
  sym_add_serial_dialog_settings = 98,
  sym_serial_dialog_parameter = 99,
  sym_add_dialog_settings = 100,
  sym_dialog_settings_block = 101,
  sym_dialog_parameter = 102,
  sym_dialog_definition = 103,
  sym_dialog_block = 104,
  sym_dialog = 105,
  sym_dialog_identifier = 106,
  sym_dialog_option = 107,
  sym_serial_dialog_definition = 108,
  sym_serial_dialog_block = 109,
  sym_serial_dialog = 110,
  sym_serial_dialog_option = 111,
  sym_script_definition = 112,
  sym_script_block = 113,
  sym__script_item = 114,
  sym_json_literal = 115,
  sym_json_array = 116,
  sym_json_object = 117,
  sym_json_name_value_pair = 118,
  sym__json_item = 119,
  sym_label = 120,
  sym_debug_macro = 121,
  sym_rand_macro = 122,
  sym_spread_macro = 123,
  sym__action_item = 124,
  sym_action_load_map = 125,
  sym_action_run_script = 126,
  sym_action_goto_label = 127,
  sym_action_goto_index = 128,
  sym_action_show_dialog = 129,
  sym_action_show_serial_dialog = 130,
  sym_action_concat_serial_dialog = 131,
  sym_action_delete_command = 132,
  sym_action_delete_command_arg = 133,
  sym_action_delete_alias = 134,
  sym_action_hide_command = 135,
  sym_action_unhide_command = 136,
  sym_action_save_slot = 137,
  sym_action_load_slot = 138,
  sym_action_erase_slot = 139,
  sym_action_blocking_delay = 140,
  sym_action_non_blocking_delay = 141,
  sym_action_close_dialog = 142,
  sym_action_close_serial_dialog = 143,
  sym_entity_identifier_expansion = 144,
  sym_map = 145,
  sym_entity_or_map_identifier_expansion = 146,
  sym_action_pause_script = 147,
  sym_action_unpause_script = 148,
  sym_action_camera_fade = 149,
  sym_in_or_out = 150,
  sym_in_or_out_expansion = 151,
  sym_action_camera_shake = 152,
  sym_action_play_entity_animation = 153,
  sym_camera = 154,
  sym__origin_or_length = 155,
  sym_movable_identifier_expansion = 156,
  sym_polygon_identifier_expansion = 157,
  sym_complex_duration_expansion = 158,
  sym_action_move_over_time = 159,
  sym_action_set_position = 160,
  aux_sym_source_file_repeat1 = 161,
  aux_sym_bareword_expansion_repeat1 = 162,
  aux_sym_quoted_string_expansion_repeat1 = 163,
  aux_sym_string_expansion_repeat1 = 164,
  aux_sym_number_expansion_repeat1 = 165,
  aux_sym_duration_expansion_repeat1 = 166,
  aux_sym_distance_expansion_repeat1 = 167,
  aux_sym_quantity_expansion_repeat1 = 168,
  aux_sym_color_expansion_repeat1 = 169,
  aux_sym_constant_expansion_repeat1 = 170,
  aux_sym_constant_value_expansion_repeat1 = 171,
  aux_sym_add_serial_dialog_settings_repeat1 = 172,
  aux_sym_add_dialog_settings_repeat1 = 173,
  aux_sym_dialog_settings_block_repeat1 = 174,
  aux_sym_dialog_block_repeat1 = 175,
  aux_sym_dialog_repeat1 = 176,
  aux_sym_dialog_repeat2 = 177,
  aux_sym_serial_dialog_repeat1 = 178,
  aux_sym_serial_dialog_repeat2 = 179,
  aux_sym_script_block_repeat1 = 180,
  aux_sym_json_array_repeat1 = 181,
  aux_sym_json_object_repeat1 = 182,
  aux_sym_entity_identifier_expansion_repeat1 = 183,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 184,
  aux_sym_in_or_out_expansion_repeat1 = 185,
  aux_sym_movable_identifier_expansion_repeat1 = 186,
  aux_sym_polygon_identifier_expansion_repeat1 = 187,
  aux_sym_complex_duration_expansion_repeat1 = 188,
  alias_sym_entity_settings = 189,
  alias_sym_label_settings = 190,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BAREWORD] = "BAREWORD",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [sym_NUMBER] = "NUMBER",
  [sym_DURATION] = "DURATION",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym_COLOR] = "COLOR",
  [sym_BOOLEAN] = "BOOLEAN",
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
  [sym_source_file] = "source_file",
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
  [sym_action_move_over_time] = "action_move_over_time",
  [sym_action_set_position] = "action_set_position",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
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
  [sym_BAREWORD] = sym_BAREWORD,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [sym_NUMBER] = sym_NUMBER,
  [sym_DURATION] = sym_DURATION,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym_COLOR] = sym_COLOR,
  [sym_BOOLEAN] = sym_BOOLEAN,
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
  [sym_source_file] = sym_source_file,
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
  [sym_action_move_over_time] = sym_action_move_over_time,
  [sym_action_set_position] = sym_action_set_position,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [sym_BAREWORD] = {
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
  [sym_BOOLEAN] = {
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
  [sym_source_file] = {
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
  [sym_action_move_over_time] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_position] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
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
  field_border_tileset = 6,
  field_camera = 7,
  field_color = 8,
  field_command = 9,
  field_count = 10,
  field_dialog_name = 11,
  field_distance = 12,
  field_duration = 13,
  field_emote = 14,
  field_entity = 15,
  field_fade = 16,
  field_fileName = 17,
  field_forever = 18,
  field_geometry = 19,
  field_index = 20,
  field_label = 21,
  field_map = 22,
  field_message = 23,
  field_name = 24,
  field_option_type = 25,
  field_portrait = 26,
  field_property = 27,
  field_script = 28,
  field_script_name = 29,
  field_serial_dialog_name = 30,
  field_serial_message = 31,
  field_slot = 32,
  field_target = 33,
  field_target_entity = 34,
  field_target_label = 35,
  field_value = 36,
  field_wrap = 37,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_alignment] = "alignment",
  [field_amplitude] = "amplitude",
  [field_animation] = "animation",
  [field_argument] = "argument",
  [field_border_tileset] = "border_tileset",
  [field_camera] = "camera",
  [field_color] = "color",
  [field_command] = "command",
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
  [9] = {.index = 8, .length = 2},
  [10] = {.index = 10, .length = 1},
  [11] = {.index = 11, .length = 1},
  [12] = {.index = 12, .length = 1},
  [13] = {.index = 13, .length = 1},
  [14] = {.index = 14, .length = 1},
  [15] = {.index = 15, .length = 1},
  [16] = {.index = 16, .length = 1},
  [17] = {.index = 17, .length = 1},
  [18] = {.index = 18, .length = 1},
  [19] = {.index = 19, .length = 1},
  [20] = {.index = 20, .length = 1},
  [21] = {.index = 21, .length = 1},
  [22] = {.index = 22, .length = 1},
  [23] = {.index = 23, .length = 1},
  [24] = {.index = 24, .length = 1},
  [25] = {.index = 25, .length = 2},
  [26] = {.index = 27, .length = 1},
  [27] = {.index = 28, .length = 1},
  [28] = {.index = 29, .length = 1},
  [29] = {.index = 30, .length = 1},
  [30] = {.index = 31, .length = 1},
  [31] = {.index = 32, .length = 1},
  [32] = {.index = 33, .length = 2},
  [33] = {.index = 35, .length = 3},
  [34] = {.index = 38, .length = 4},
  [35] = {.index = 42, .length = 2},
  [36] = {.index = 44, .length = 2},
  [37] = {.index = 46, .length = 1},
  [38] = {.index = 47, .length = 2},
  [39] = {.index = 49, .length = 4},
  [40] = {.index = 53, .length = 1},
  [41] = {.index = 54, .length = 1},
  [42] = {.index = 55, .length = 1},
  [43] = {.index = 56, .length = 1},
  [44] = {.index = 57, .length = 1},
  [45] = {.index = 58, .length = 2},
  [46] = {.index = 60, .length = 2},
  [47] = {.index = 62, .length = 2},
  [48] = {.index = 64, .length = 1},
  [49] = {.index = 65, .length = 2},
  [50] = {.index = 67, .length = 2},
  [51] = {.index = 69, .length = 1},
  [52] = {.index = 70, .length = 2},
  [53] = {.index = 72, .length = 3},
  [54] = {.index = 75, .length = 2},
  [55] = {.index = 77, .length = 2},
  [56] = {.index = 79, .length = 1},
  [57] = {.index = 80, .length = 2},
  [58] = {.index = 82, .length = 1},
  [59] = {.index = 83, .length = 1},
  [60] = {.index = 84, .length = 1},
  [61] = {.index = 85, .length = 3},
  [62] = {.index = 88, .length = 3},
  [63] = {.index = 91, .length = 2},
  [64] = {.index = 93, .length = 2},
  [65] = {.index = 95, .length = 1},
  [66] = {.index = 96, .length = 2},
  [67] = {.index = 98, .length = 1},
  [68] = {.index = 99, .length = 1},
  [69] = {.index = 100, .length = 3},
  [70] = {.index = 103, .length = 2},
  [71] = {.index = 105, .length = 4},
  [72] = {.index = 109, .length = 1},
  [73] = {.index = 110, .length = 2},
  [74] = {.index = 112, .length = 3},
  [75] = {.index = 115, .length = 3},
  [76] = {.index = 118, .length = 2},
  [77] = {.index = 120, .length = 3},
  [78] = {.index = 123, .length = 2},
  [79] = {.index = 125, .length = 2},
  [80] = {.index = 127, .length = 2},
  [81] = {.index = 129, .length = 1},
  [82] = {.index = 130, .length = 3},
  [83] = {.index = 133, .length = 3},
  [84] = {.index = 136, .length = 3},
  [85] = {.index = 139, .length = 3},
  [86] = {.index = 142, .length = 6},
  [87] = {.index = 148, .length = 2},
  [88] = {.index = 150, .length = 3},
  [89] = {.index = 153, .length = 4},
  [90] = {.index = 157, .length = 1},
  [91] = {.index = 158, .length = 3},
  [92] = {.index = 161, .length = 4},
  [93] = {.index = 165, .length = 2},
  [94] = {.index = 167, .length = 3},
  [95] = {.index = 170, .length = 2},
  [96] = {.index = 172, .length = 3},
  [97] = {.index = 175, .length = 2},
  [98] = {.index = 177, .length = 4},
  [99] = {.index = 181, .length = 2},
  [100] = {.index = 183, .length = 3},
  [101] = {.index = 186, .length = 4},
  [102] = {.index = 190, .length = 5},
  [103] = {.index = 195, .length = 3},
  [104] = {.index = 198, .length = 3},
  [105] = {.index = 201, .length = 4},
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
    {field_label, 0},
    {field_value, 2},
  [10] =
    {field_serial_message, 0},
  [11] =
    {field_serial_message, 0, .inherited = true},
  [12] =
    {field_camera, 1},
  [13] =
    {field_map, 2},
  [14] =
    {field_slot, 2},
  [15] =
    {field_label, 2},
  [16] =
    {field_index, 2},
  [17] =
    {field_serial_dialog_name, 2},
  [18] =
    {field_dialog_name, 2},
  [19] =
    {field_command, 2},
  [20] =
    {field_alias, 2},
  [21] =
    {field_script, 2},
  [22] =
    {field_camera, 0},
  [23] =
    {field_wrap, 1},
  [24] =
    {field_serial_message, 1, .inherited = true},
  [25] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [27] =
    {field_entity, 1},
  [28] =
    {field_name, 1},
  [29] =
    {field_message, 0},
  [30] =
    {field_message, 1, .inherited = true},
  [31] =
    {field_entity, 2},
  [32] =
    {field_entity, 2, .inherited = true},
  [33] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
  [35] =
    {field_camera, 1},
    {field_camera, 2, .inherited = true},
    {field_entity, 2, .inherited = true},
  [38] =
    {field_camera, 0, .inherited = true},
    {field_camera, 1, .inherited = true},
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
  [42] =
    {field_entity, 2},
    {field_script, 3},
  [44] =
    {field_camera, 0},
    {field_forever, 3},
  [46] =
    {field_forever, 3},
  [47] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [49] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [53] =
    {field_portrait, 1},
  [54] =
    {field_alignment, 1},
  [55] =
    {field_border_tileset, 1},
  [56] =
    {field_emote, 1},
  [57] =
    {field_message, 2, .inherited = true},
  [58] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [60] =
    {field_entity, 2},
    {field_entity, 3, .inherited = true},
  [62] =
    {field_camera, 3, .inherited = true},
    {field_entity, 3, .inherited = true},
  [64] =
    {field_dialog_name, 3},
  [65] =
    {field_argument, 4},
    {field_command, 2},
  [67] =
    {field_animation, 3},
    {field_count, 4},
  [69] =
    {field_forever, 4},
  [70] =
    {field_camera, 0},
    {field_entity, 3},
  [72] =
    {field_camera, 0},
    {field_geometry, 3},
    {field_target, 4},
  [75] =
    {field_camera, 0},
    {field_forever, 4},
  [77] =
    {field_camera, 0},
    {field_duration, 4},
  [79] =
    {field_entity, 3},
  [80] =
    {field_geometry, 3},
    {field_target, 4},
  [82] =
    {field_duration, 4},
  [83] =
    {field_target_label, 1},
  [84] =
    {field_target_entity, 1},
  [85] =
    {field_camera, 4, .inherited = true},
    {field_entity, 2},
    {field_entity, 4, .inherited = true},
  [88] =
    {field_animation, 4},
    {field_count, 5},
    {field_entity, 1},
  [91] =
    {field_entity, 1},
    {field_forever, 5},
  [93] =
    {field_property, 0},
    {field_value, 2},
  [95] =
    {field_entity, 4},
  [96] =
    {field_geometry, 4},
    {field_target, 5},
  [98] =
    {field_forever, 5},
  [99] =
    {field_duration, 5},
  [100] =
    {field_camera, 0},
    {field_entity, 3},
    {field_forever, 5},
  [103] =
    {field_camera, 0},
    {field_duration, 5},
  [105] =
    {field_camera, 0},
    {field_forever, 5},
    {field_geometry, 3},
    {field_target, 4},
  [109] =
    {field_forever, 1},
  [110] =
    {field_entity, 3},
    {field_forever, 5},
  [112] =
    {field_forever, 5},
    {field_geometry, 3},
    {field_target, 4},
  [115] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [118] =
    {field_entity, 1},
    {field_entity, 5},
  [120] =
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
  [123] =
    {field_entity, 1},
    {field_forever, 6},
  [125] =
    {field_duration, 6},
    {field_entity, 1},
  [127] =
    {field_entity, 4},
    {field_forever, 6},
  [129] =
    {field_duration, 6},
  [130] =
    {field_forever, 6},
    {field_geometry, 4},
    {field_target, 5},
  [133] =
    {field_color, 4},
    {field_duration, 6},
    {field_fade, 2},
  [136] =
    {field_amplitude, 3},
    {field_distance, 4},
    {field_duration, 6},
  [139] =
    {field_entity, 3, .inherited = true},
    {field_geometry, 3, .inherited = true},
    {field_target, 3, .inherited = true},
  [142] =
    {field_entity, 0, .inherited = true},
    {field_entity, 1, .inherited = true},
    {field_geometry, 0, .inherited = true},
    {field_geometry, 1, .inherited = true},
    {field_target, 0, .inherited = true},
    {field_target, 1, .inherited = true},
  [148] =
    {field_geometry, 2},
    {field_target, 3},
  [150] =
    {field_camera, 0},
    {field_duration, 6},
    {field_entity, 3},
  [153] =
    {field_camera, 0},
    {field_duration, 6},
    {field_geometry, 3},
    {field_target, 4},
  [157] =
    {field_duration, 2},
  [158] =
    {field_duration, 2, .inherited = true},
    {field_forever, 1},
    {field_forever, 2, .inherited = true},
  [161] =
    {field_duration, 0, .inherited = true},
    {field_duration, 1, .inherited = true},
    {field_forever, 0, .inherited = true},
    {field_forever, 1, .inherited = true},
  [165] =
    {field_duration, 6},
    {field_entity, 3},
  [167] =
    {field_duration, 6},
    {field_geometry, 3},
    {field_target, 4},
  [170] =
    {field_label, 1},
    {field_script, 3},
  [172] =
    {field_entity, 1},
    {field_entity, 5},
    {field_forever, 7},
  [175] =
    {field_duration, 7},
    {field_entity, 1},
  [177] =
    {field_entity, 1},
    {field_forever, 7},
    {field_geometry, 5},
    {field_target, 6},
  [181] =
    {field_duration, 7},
    {field_entity, 4},
  [183] =
    {field_duration, 7},
    {field_geometry, 4},
    {field_target, 5},
  [186] =
    {field_entity, 2},
    {field_entity, 4, .inherited = true},
    {field_geometry, 4, .inherited = true},
    {field_target, 4, .inherited = true},
  [190] =
    {field_entity, 4, .inherited = true},
    {field_geometry, 2},
    {field_geometry, 4, .inherited = true},
    {field_target, 3},
    {field_target, 4, .inherited = true},
  [195] =
    {field_duration, 2},
    {field_duration, 3, .inherited = true},
    {field_forever, 3, .inherited = true},
  [198] =
    {field_duration, 8},
    {field_entity, 1},
    {field_entity, 5},
  [201] =
    {field_duration, 8},
    {field_entity, 1},
    {field_geometry, 5},
    {field_target, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [59] = {
    [2] = alias_sym_label_settings,
  },
  [60] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(278);
      ADVANCE_MAP(
        '!', 504,
        '"', 6,
        '#', 491,
        '$', 275,
        '(', 505,
        ')', 506,
        '+', 527,
        ',', 447,
        '-', 12,
        '/', 9,
        ':', 496,
        ';', 465,
        '=', 466,
        '>', 489,
        'I', 169,
        '[', 446,
        ']', 448,
        '_', 490,
        'a', 54,
        'b', 146,
        'c', 16,
        'd', 68,
        'e', 161,
        'f', 17,
        'g', 87,
        'h', 124,
        'i', 170,
        'j', 221,
        'l', 18,
        'm', 19,
        'n', 42,
        'o', 172,
        'p', 20,
        'r', 32,
        's', 21,
        't', 117,
        'u', 173,
        'w', 36,
        'y', 101,
        '{', 472,
        '}', 473,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(450);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 272,
        '$', 275,
        ',', 447,
        '/', 9,
        '[', 446,
        ']', 448,
        'b', 373,
        'c', 378,
        'f', 298,
        'g', 414,
        'm', 294,
        'o', 349,
        'r', 344,
        't', 354,
        'w', 355,
        'y', 342,
        '{', 472,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(450);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(275);
      if (lookahead == ')') ADVANCE(506);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'w') ADVANCE(413);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '"', 6,
        '$', 275,
        '/', 9,
        '>', 489,
        '[', 446,
        ']', 448,
        'e', 389,
        'n', 301,
        '}', 473,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(453);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(275);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '[') ADVANCE(446);
      if (lookahead == 'i') ADVANCE(393);
      if (lookahead == 'l') ADVANCE(288);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ')', 506,
        '-', 13,
        '/', 9,
        'I', 169,
        '[', 446,
        ']', 448,
        'f', 39,
        'i', 181,
        'n', 252,
        'o', 253,
        't', 207,
        '{', 472,
        '}', 473,
        '#', 490,
        '_', 490,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(449);
      if (lookahead == '\\') ADVANCE(276);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        '#', 272,
        '$', 275,
        '/', 9,
        ';', 465,
        '[', 446,
        ']', 448,
        'b', 149,
        'c', 270,
        'g', 206,
        'm', 38,
        'o', 171,
        'r', 94,
        't', 118,
        'w', 119,
        'y', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(457);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '$', 275,
        ')', 506,
        ',', 447,
        '/', 9,
        '[', 446,
        ']', 448,
        'b', 375,
        'c', 284,
        'd', 326,
        'e', 388,
        'g', 401,
        'h', 360,
        'j', 416,
        'l', 403,
        'p', 289,
        'r', 291,
        's', 285,
        'u', 385,
        'w', 293,
        '}', 473,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(451);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(280);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(279);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '>') ADVANCE(555);
      if (lookahead == 'I') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 13:
      if (lookahead == 'I') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(64);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(244);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(191);
      if (lookahead == 'o') ADVANCE(162);
      if (lookahead == 'y') ADVANCE(35);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == 'o') ADVANCE(211);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'e') ADVANCE(174);
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(114);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(259);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'o') ADVANCE(210);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(261);
      if (lookahead == 'c') ADVANCE(212);
      if (lookahead == 'e') ADVANCE(150);
      if (lookahead == 'h') ADVANCE(24);
      if (lookahead == 'l') ADVANCE(194);
      if (lookahead == 'p') ADVANCE(216);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(271);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(458);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(264);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(200);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(552);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(153);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(70);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'u') ADVANCE(70);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(219);
      if (lookahead == 'g') ADVANCE(187);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(182);
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(256);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(175);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(128);
      if (lookahead == 'h') ADVANCE(130);
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(151);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(113);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(160);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(184);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(232);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(164);
      if (lookahead == 'u') ADVANCE(152);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(223);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(156);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(137);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(260);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(251);
      END_STATE();
    case 48:
      if (lookahead == 'b') ADVANCE(254);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 49:
      if (lookahead == 'b') ADVANCE(90);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(143);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(144);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(69);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(55);
      if (lookahead == 'l') ADVANCE(122);
      if (lookahead == 'n') ADVANCE(125);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(467);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(458);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(458);
      if (lookahead == 't') ADVANCE(255);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(513);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(507);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(509);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(526);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(71);
      if (lookahead == 'l') ADVANCE(224);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(72);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(138);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(83);
      END_STATE();
    case 66:
      if (lookahead == 'd') ADVANCE(84);
      END_STATE();
    case 67:
      if (lookahead == 'd') ADVANCE(92);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(48);
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(456);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(458);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(554);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(529);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(483);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(533);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(499);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(542);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(488);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(536);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(500);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(548);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(560);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(524);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(531);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(463);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(550);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(266);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(199);
      if (lookahead == 'o') ADVANCE(241);
      if (lookahead == 'r') ADVANCE(93);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(202);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(214);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(148);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(175);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(203);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(204);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(205);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(185);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(242);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(33);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(159);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(262);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(247);
      END_STATE();
    case 104:
      if (lookahead == 'e') ADVANCE(186);
      END_STATE();
    case 105:
      if (lookahead == 'e') ADVANCE(227);
      END_STATE();
    case 106:
      if (lookahead == 'f') ADVANCE(546);
      END_STATE();
    case 107:
      if (lookahead == 'f') ADVANCE(129);
      END_STATE();
    case 108:
      if (lookahead == 'g') ADVANCE(502);
      END_STATE();
    case 109:
      if (lookahead == 'g') ADVANCE(476);
      END_STATE();
    case 110:
      if (lookahead == 'g') ADVANCE(469);
      END_STATE();
    case 111:
      if (lookahead == 'g') ADVANCE(220);
      END_STATE();
    case 112:
      if (lookahead == 'g') ADVANCE(231);
      END_STATE();
    case 113:
      if (lookahead == 'g') ADVANCE(97);
      END_STATE();
    case 114:
      if (lookahead == 'g') ADVANCE(97);
      if (lookahead == 'p') ADVANCE(515);
      END_STATE();
    case 115:
      if (lookahead == 'g') ADVANCE(133);
      END_STATE();
    case 116:
      if (lookahead == 'h') ADVANCE(564);
      END_STATE();
    case 117:
      if (lookahead == 'h') ADVANCE(209);
      if (lookahead == 'r') ADVANCE(257);
      if (lookahead == 'w') ADVANCE(121);
      END_STATE();
    case 118:
      if (lookahead == 'h') ADVANCE(209);
      if (lookahead == 'w') ADVANCE(121);
      END_STATE();
    case 119:
      if (lookahead == 'h') ADVANCE(130);
      END_STATE();
    case 120:
      if (lookahead == 'h') ADVANCE(141);
      if (lookahead == 'p') ADVANCE(46);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(265);
      if (lookahead == 'x') ADVANCE(454);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(115);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(201);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(230);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(188);
      END_STATE();
    case 130:
      if (lookahead == 'i') ADVANCE(240);
      END_STATE();
    case 131:
      if (lookahead == 'i') ADVANCE(158);
      END_STATE();
    case 132:
      if (lookahead == 'i') ADVANCE(238);
      END_STATE();
    case 133:
      if (lookahead == 'i') ADVANCE(177);
      END_STATE();
    case 134:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 135:
      if (lookahead == 'i') ADVANCE(183);
      END_STATE();
    case 136:
      if (lookahead == 'i') ADVANCE(239);
      END_STATE();
    case 137:
      if (lookahead == 'i') ADVANCE(235);
      END_STATE();
    case 138:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 139:
      if (lookahead == 'i') ADVANCE(197);
      END_STATE();
    case 140:
      if (lookahead == 'i') ADVANCE(243);
      END_STATE();
    case 141:
      if (lookahead == 'i') ADVANCE(65);
      END_STATE();
    case 142:
      if (lookahead == 'i') ADVANCE(198);
      END_STATE();
    case 143:
      if (lookahead == 'k') ADVANCE(458);
      END_STATE();
    case 144:
      if (lookahead == 'k') ADVANCE(538);
      END_STATE();
    case 145:
      if (lookahead == 'k') ADVANCE(81);
      END_STATE();
    case 146:
      if (lookahead == 'l') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(217);
      END_STATE();
    case 147:
      if (lookahead == 'l') ADVANCE(501);
      END_STATE();
    case 148:
      if (lookahead == 'l') ADVANCE(479);
      END_STATE();
    case 149:
      if (lookahead == 'l') ADVANCE(29);
      END_STATE();
    case 150:
      if (lookahead == 'l') ADVANCE(106);
      if (lookahead == 'r') ADVANCE(134);
      if (lookahead == 't') ADVANCE(250);
      END_STATE();
    case 151:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 152:
      if (lookahead == 'l') ADVANCE(147);
      END_STATE();
    case 153:
      if (lookahead == 'l') ADVANCE(193);
      END_STATE();
    case 154:
      if (lookahead == 'l') ADVANCE(258);
      END_STATE();
    case 155:
      if (lookahead == 'l') ADVANCE(190);
      END_STATE();
    case 156:
      if (lookahead == 'l') ADVANCE(195);
      END_STATE();
    case 157:
      if (lookahead == 'l') ADVANCE(234);
      END_STATE();
    case 158:
      if (lookahead == 'l') ADVANCE(105);
      END_STATE();
    case 159:
      if (lookahead == 'l') ADVANCE(155);
      END_STATE();
    case 160:
      if (lookahead == 'l') ADVANCE(224);
      END_STATE();
    case 161:
      if (lookahead == 'm') ADVANCE(192);
      if (lookahead == 'n') ADVANCE(249);
      if (lookahead == 'r') ADVANCE(43);
      END_STATE();
    case 162:
      if (lookahead == 'm') ADVANCE(166);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 163:
      if (lookahead == 'm') ADVANCE(47);
      END_STATE();
    case 164:
      if (lookahead == 'm') ADVANCE(73);
      END_STATE();
    case 165:
      if (lookahead == 'm') ADVANCE(98);
      END_STATE();
    case 166:
      if (lookahead == 'm') ADVANCE(40);
      END_STATE();
    case 167:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 168:
      if (lookahead == 'm') ADVANCE(104);
      END_STATE();
    case 169:
      if (lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 170:
      if (lookahead == 'n') ADVANCE(558);
      END_STATE();
    case 171:
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 172:
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 'r') ADVANCE(126);
      if (lookahead == 'u') ADVANCE(228);
      if (lookahead == 'v') ADVANCE(88);
      END_STATE();
    case 173:
      if (lookahead == 'n') ADVANCE(120);
      END_STATE();
    case 174:
      if (lookahead == 'n') ADVANCE(112);
      END_STATE();
    case 175:
      if (lookahead == 'n') ADVANCE(458);
      END_STATE();
    case 176:
      if (lookahead == 'n') ADVANCE(494);
      END_STATE();
    case 177:
      if (lookahead == 'n') ADVANCE(563);
      END_STATE();
    case 178:
      if (lookahead == 'n') ADVANCE(511);
      END_STATE();
    case 179:
      if (lookahead == 'n') ADVANCE(566);
      END_STATE();
    case 180:
      if (lookahead == 'n') ADVANCE(561);
      END_STATE();
    case 181:
      if (lookahead == 'n') ADVANCE(557);
      END_STATE();
    case 182:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 183:
      if (lookahead == 'n') ADVANCE(111);
      END_STATE();
    case 184:
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 185:
      if (lookahead == 'n') ADVANCE(245);
      END_STATE();
    case 186:
      if (lookahead == 'n') ADVANCE(236);
      END_STATE();
    case 187:
      if (lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 188:
      if (lookahead == 'n') ADVANCE(136);
      END_STATE();
    case 189:
      if (lookahead == 'o') ADVANCE(516);
      END_STATE();
    case 190:
      if (lookahead == 'o') ADVANCE(263);
      END_STATE();
    case 191:
      if (lookahead == 'o') ADVANCE(222);
      END_STATE();
    case 192:
      if (lookahead == 'o') ADVANCE(246);
      END_STATE();
    case 193:
      if (lookahead == 'o') ADVANCE(109);
      END_STATE();
    case 194:
      if (lookahead == 'o') ADVANCE(229);
      END_STATE();
    case 195:
      if (lookahead == 'o') ADVANCE(110);
      END_STATE();
    case 196:
      if (lookahead == 'o') ADVANCE(176);
      END_STATE();
    case 197:
      if (lookahead == 'o') ADVANCE(179);
      END_STATE();
    case 198:
      if (lookahead == 'o') ADVANCE(180);
      END_STATE();
    case 199:
      if (lookahead == 'o') ADVANCE(165);
      END_STATE();
    case 200:
      if (lookahead == 'p') ADVANCE(474);
      END_STATE();
    case 201:
      if (lookahead == 'p') ADVANCE(233);
      END_STATE();
    case 202:
      if (lookahead == 'r') ADVANCE(556);
      END_STATE();
    case 203:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 204:
      if (lookahead == 'r') ADVANCE(544);
      END_STATE();
    case 205:
      if (lookahead == 'r') ADVANCE(565);
      END_STATE();
    case 206:
      if (lookahead == 'r') ADVANCE(93);
      END_STATE();
    case 207:
      if (lookahead == 'r') ADVANCE(257);
      END_STATE();
    case 208:
      if (lookahead == 'r') ADVANCE(269);
      END_STATE();
    case 209:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 210:
      if (lookahead == 'r') ADVANCE(248);
      if (lookahead == 's') ADVANCE(140);
      END_STATE();
    case 211:
      if (lookahead == 'r') ADVANCE(102);
      END_STATE();
    case 212:
      if (lookahead == 'r') ADVANCE(127);
      END_STATE();
    case 213:
      if (lookahead == 'r') ADVANCE(178);
      END_STATE();
    case 214:
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 215:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 216:
      if (lookahead == 'r') ADVANCE(99);
      END_STATE();
    case 217:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 218:
      if (lookahead == 's') ADVANCE(452);
      END_STATE();
    case 219:
      if (lookahead == 's') ADVANCE(528);
      END_STATE();
    case 220:
      if (lookahead == 's') ADVANCE(471);
      END_STATE();
    case 221:
      if (lookahead == 's') ADVANCE(196);
      END_STATE();
    case 222:
      if (lookahead == 's') ADVANCE(76);
      END_STATE();
    case 223:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 224:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 225:
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 226:
      if (lookahead == 's') ADVANCE(85);
      END_STATE();
    case 227:
      if (lookahead == 's') ADVANCE(100);
      END_STATE();
    case 228:
      if (lookahead == 't') ADVANCE(559);
      END_STATE();
    case 229:
      if (lookahead == 't') ADVANCE(535);
      END_STATE();
    case 230:
      if (lookahead == 't') ADVANCE(540);
      END_STATE();
    case 231:
      if (lookahead == 't') ADVANCE(116);
      END_STATE();
    case 232:
      if (lookahead == 't') ADVANCE(522);
      END_STATE();
    case 233:
      if (lookahead == 't') ADVANCE(492);
      END_STATE();
    case 234:
      if (lookahead == 't') ADVANCE(478);
      END_STATE();
    case 235:
      if (lookahead == 't') ADVANCE(485);
      END_STATE();
    case 236:
      if (lookahead == 't') ADVANCE(486);
      END_STATE();
    case 237:
      if (lookahead == 't') ADVANCE(487);
      END_STATE();
    case 238:
      if (lookahead == 't') ADVANCE(267);
      END_STATE();
    case 239:
      if (lookahead == 't') ADVANCE(268);
      END_STATE();
    case 240:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 241:
      if (lookahead == 't') ADVANCE(189);
      END_STATE();
    case 242:
      if (lookahead == 't') ADVANCE(208);
      END_STATE();
    case 243:
      if (lookahead == 't') ADVANCE(139);
      END_STATE();
    case 244:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 245:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 246:
      if (lookahead == 't') ADVANCE(77);
      END_STATE();
    case 247:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 248:
      if (lookahead == 't') ADVANCE(215);
      END_STATE();
    case 249:
      if (lookahead == 't') ADVANCE(132);
      END_STATE();
    case 250:
      if (lookahead == 't') ADVANCE(135);
      END_STATE();
    case 251:
      if (lookahead == 't') ADVANCE(142);
      END_STATE();
    case 252:
      if (lookahead == 'u') ADVANCE(152);
      END_STATE();
    case 253:
      if (lookahead == 'u') ADVANCE(228);
      END_STATE();
    case 254:
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 255:
      if (lookahead == 'u') ADVANCE(213);
      END_STATE();
    case 256:
      if (lookahead == 'u') ADVANCE(157);
      END_STATE();
    case 257:
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 258:
      if (lookahead == 'u') ADVANCE(66);
      END_STATE();
    case 259:
      if (lookahead == 'u') ADVANCE(225);
      END_STATE();
    case 260:
      if (lookahead == 'u') ADVANCE(226);
      END_STATE();
    case 261:
      if (lookahead == 'v') ADVANCE(74);
      END_STATE();
    case 262:
      if (lookahead == 'v') ADVANCE(96);
      END_STATE();
    case 263:
      if (lookahead == 'w') ADVANCE(458);
      END_STATE();
    case 264:
      if (lookahead == 'w') ADVANCE(520);
      END_STATE();
    case 265:
      if (lookahead == 'x') ADVANCE(454);
      END_STATE();
    case 266:
      if (lookahead == 'x') ADVANCE(518);
      END_STATE();
    case 267:
      if (lookahead == 'y') ADVANCE(481);
      END_STATE();
    case 268:
      if (lookahead == 'y') ADVANCE(497);
      END_STATE();
    case 269:
      if (lookahead == 'y') ADVANCE(562);
      END_STATE();
    case 270:
      if (lookahead == 'y') ADVANCE(35);
      END_STATE();
    case 271:
      if (lookahead == 'y') ADVANCE(95);
      END_STATE();
    case 272:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(274);
      END_STATE();
    case 273:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(461);
      END_STATE();
    case 274:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(273);
      END_STATE();
    case 275:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(462);
      END_STATE();
    case 276:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 277:
      if (eof) ADVANCE(278);
      ADVANCE_MAP(
        '$', 275,
        ',', 447,
        '/', 9,
        ';', 465,
        '[', 446,
        ']', 448,
        'a', 319,
        'd', 357,
        'i', 384,
        's', 307,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(277);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(455);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(280);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(280);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(381);
      if (lookahead == 'l') ADVANCE(399);
      if (lookahead == 'o') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(439);
      if (lookahead == 'e') ADVANCE(372);
      if (lookahead == 'h') ADVANCE(395);
      if (lookahead == 'p') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(553);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(437);
      if (lookahead == 'l') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(391);
      if (lookahead == 'e') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(361);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(310);
      if (lookahead == 'u') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(425);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(434);
      if (lookahead == 'l') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(343);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(408);
      if (lookahead == 'e') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(368);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(370);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(514);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(510);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(530);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(534);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(543);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(537);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(549);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(525);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(532);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(551);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(547);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(347);
      if (lookahead == 'n') ADVANCE(312);
      if (lookahead == 'p') ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(470);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(409);
      if (lookahead == 'r') ADVANCE(436);
      if (lookahead == 'w') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(364);
      if (lookahead == 'p') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(539);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(404);
      if (lookahead == 'y') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(495);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(512);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(432);
      if (lookahead == 'r') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(517);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(475);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(545);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(493);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(541);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(523);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(443);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(521);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(482);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(218);
      if (lookahead == 'p') ADVANCE(123);
      if (lookahead == 's') ADVANCE(452);
      if (lookahead == 'x') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(450);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(451);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_DURATION);
      if (lookahead == 'm') ADVANCE(218);
      if (lookahead == 's') ADVANCE(452);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(453);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_DISTANCE);
      if (lookahead == 'p') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(455);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_QUANTITY);
      if (lookahead == 'x') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(457);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(458);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(459);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(462);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_wrap);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(274);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(498);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_debug);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_debug);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(anon_sym_spread);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(anon_sym_spread);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_player);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 549:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 550:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 551:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 552:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 553:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(445);
      END_STATE();
    case 554:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 555:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 556:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 557:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 558:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(154);
      if (lookahead == 'd') ADVANCE(86);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(anon_sym_animation);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(anon_sym_geometry);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(sym_origin);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(sym_length);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(sym_forever);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(anon_sym_position);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 277},
  [2] = {.lex_state = 8},
  [3] = {.lex_state = 8},
  [4] = {.lex_state = 8},
  [5] = {.lex_state = 8},
  [6] = {.lex_state = 8},
  [7] = {.lex_state = 8},
  [8] = {.lex_state = 8},
  [9] = {.lex_state = 8},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 8},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 8},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 8},
  [22] = {.lex_state = 277},
  [23] = {.lex_state = 277},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 5},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 277},
  [30] = {.lex_state = 277},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 277},
  [33] = {.lex_state = 277},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 277},
  [40] = {.lex_state = 277},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 277},
  [46] = {.lex_state = 277},
  [47] = {.lex_state = 277},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 277},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 277},
  [56] = {.lex_state = 277},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 277},
  [59] = {.lex_state = 277},
  [60] = {.lex_state = 277},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 277},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 5},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 277},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 277},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 277},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 277},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 5},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 1},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 5},
  [115] = {.lex_state = 1},
  [116] = {.lex_state = 1},
  [117] = {.lex_state = 1},
  [118] = {.lex_state = 1},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 5},
  [123] = {.lex_state = 5},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 1},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 1},
  [131] = {.lex_state = 3},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 5},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 5},
  [137] = {.lex_state = 8},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 3},
  [140] = {.lex_state = 5},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 1},
  [143] = {.lex_state = 1},
  [144] = {.lex_state = 1},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 7},
  [148] = {.lex_state = 1},
  [149] = {.lex_state = 7},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 1},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 3},
  [155] = {.lex_state = 7},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 7},
  [158] = {.lex_state = 1},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 3},
  [162] = {.lex_state = 1},
  [163] = {.lex_state = 1},
  [164] = {.lex_state = 1},
  [165] = {.lex_state = 1},
  [166] = {.lex_state = 1},
  [167] = {.lex_state = 5},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 3},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 3},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 7},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 277},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 3},
  [184] = {.lex_state = 7},
  [185] = {.lex_state = 3},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 8},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 1},
  [190] = {.lex_state = 3},
  [191] = {.lex_state = 1},
  [192] = {.lex_state = 1},
  [193] = {.lex_state = 3},
  [194] = {.lex_state = 5},
  [195] = {.lex_state = 3},
  [196] = {.lex_state = 3},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 3},
  [200] = {.lex_state = 3},
  [201] = {.lex_state = 3},
  [202] = {.lex_state = 3},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 3},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 7},
  [208] = {.lex_state = 3},
  [209] = {.lex_state = 3},
  [210] = {.lex_state = 1},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 8},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 3},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 3},
  [221] = {.lex_state = 3},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 8},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 8},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 1},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 3},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 1},
  [236] = {.lex_state = 1},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 1},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 8},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 1},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 1},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 3},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 7},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 1},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 3},
  [265] = {.lex_state = 1},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 1},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 7},
  [272] = {.lex_state = 277},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 1},
  [276] = {.lex_state = 1},
  [277] = {.lex_state = 1},
  [278] = {.lex_state = 1},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 1},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 0},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 3},
  [286] = {.lex_state = 1},
  [287] = {.lex_state = 1},
  [288] = {.lex_state = 0},
  [289] = {.lex_state = 1},
  [290] = {.lex_state = 1},
  [291] = {.lex_state = 0},
  [292] = {.lex_state = 1},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 1},
  [295] = {.lex_state = 0},
  [296] = {.lex_state = 0},
  [297] = {.lex_state = 1},
  [298] = {.lex_state = 8},
  [299] = {.lex_state = 0},
  [300] = {.lex_state = 1},
  [301] = {.lex_state = 1},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 1},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 0},
  [306] = {.lex_state = 1},
  [307] = {.lex_state = 0},
  [308] = {.lex_state = 0},
  [309] = {.lex_state = 0},
  [310] = {.lex_state = 0},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 0},
  [313] = {.lex_state = 1},
  [314] = {.lex_state = 0},
  [315] = {.lex_state = 0},
  [316] = {.lex_state = 1},
  [317] = {.lex_state = 0},
  [318] = {.lex_state = 1},
  [319] = {.lex_state = 0},
  [320] = {.lex_state = 0},
  [321] = {.lex_state = 0},
  [322] = {.lex_state = 0},
  [323] = {.lex_state = 0},
  [324] = {.lex_state = 0},
  [325] = {.lex_state = 0},
  [326] = {.lex_state = 0},
  [327] = {.lex_state = 0},
  [328] = {.lex_state = 0},
  [329] = {.lex_state = 0},
  [330] = {.lex_state = 0},
  [331] = {.lex_state = 0},
  [332] = {.lex_state = 5},
  [333] = {.lex_state = 1},
  [334] = {.lex_state = 0},
  [335] = {.lex_state = 0},
  [336] = {.lex_state = 1},
  [337] = {.lex_state = 0},
  [338] = {.lex_state = 7},
  [339] = {.lex_state = 0},
  [340] = {.lex_state = 0},
  [341] = {.lex_state = 0},
  [342] = {.lex_state = 0},
  [343] = {.lex_state = 5},
  [344] = {.lex_state = 7},
  [345] = {.lex_state = 0},
  [346] = {.lex_state = 277},
  [347] = {.lex_state = 0},
  [348] = {.lex_state = 0},
  [349] = {.lex_state = 0},
  [350] = {.lex_state = 0},
  [351] = {.lex_state = 8},
  [352] = {.lex_state = 1},
  [353] = {.lex_state = 1},
  [354] = {.lex_state = 0},
  [355] = {.lex_state = 1},
  [356] = {.lex_state = 0},
  [357] = {.lex_state = 0},
  [358] = {.lex_state = 1},
  [359] = {.lex_state = 0},
  [360] = {.lex_state = 0},
  [361] = {.lex_state = 0},
  [362] = {.lex_state = 1},
  [363] = {.lex_state = 0},
  [364] = {.lex_state = 0},
  [365] = {.lex_state = 1},
  [366] = {.lex_state = 1},
  [367] = {.lex_state = 1},
  [368] = {.lex_state = 7},
  [369] = {.lex_state = 0},
  [370] = {.lex_state = 7},
  [371] = {.lex_state = 0},
  [372] = {.lex_state = 277},
  [373] = {.lex_state = 0},
  [374] = {.lex_state = 0},
  [375] = {.lex_state = 0},
  [376] = {.lex_state = 1},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 0},
  [379] = {.lex_state = 1},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 0},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 1},
  [385] = {.lex_state = 1},
  [386] = {.lex_state = 0},
  [387] = {.lex_state = 0},
  [388] = {.lex_state = 0},
  [389] = {.lex_state = 8},
  [390] = {.lex_state = 0},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 1},
  [393] = {.lex_state = 0},
  [394] = {.lex_state = 0},
  [395] = {.lex_state = 0},
  [396] = {.lex_state = 0},
  [397] = {.lex_state = 0},
  [398] = {.lex_state = 0},
  [399] = {.lex_state = 0},
  [400] = {.lex_state = 0},
  [401] = {.lex_state = 0},
  [402] = {.lex_state = 0},
  [403] = {.lex_state = 0},
  [404] = {.lex_state = 0},
  [405] = {.lex_state = 0},
  [406] = {.lex_state = 0},
  [407] = {.lex_state = 0},
  [408] = {.lex_state = 0},
  [409] = {.lex_state = 0},
  [410] = {.lex_state = 0},
  [411] = {.lex_state = 0},
  [412] = {.lex_state = 0},
  [413] = {.lex_state = 0},
  [414] = {.lex_state = 0},
  [415] = {.lex_state = 0},
  [416] = {.lex_state = 0},
  [417] = {.lex_state = 0},
  [418] = {.lex_state = 0},
  [419] = {.lex_state = 0},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 0},
  [422] = {.lex_state = 0},
  [423] = {.lex_state = 0},
  [424] = {.lex_state = 3},
  [425] = {.lex_state = 0},
  [426] = {.lex_state = 0},
  [427] = {.lex_state = 0},
  [428] = {.lex_state = 0},
  [429] = {.lex_state = 0},
  [430] = {.lex_state = 0},
  [431] = {.lex_state = 0},
  [432] = {.lex_state = 0},
  [433] = {.lex_state = 0},
  [434] = {.lex_state = 8},
  [435] = {.lex_state = 1},
  [436] = {.lex_state = 0},
  [437] = {.lex_state = 0},
  [438] = {.lex_state = 0},
  [439] = {.lex_state = 0},
  [440] = {.lex_state = 0},
  [441] = {.lex_state = 0},
  [442] = {.lex_state = 0},
  [443] = {.lex_state = 1},
  [444] = {.lex_state = 0},
  [445] = {.lex_state = 8},
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
  [456] = {.lex_state = 1},
  [457] = {.lex_state = 0},
  [458] = {.lex_state = 0},
  [459] = {.lex_state = 0},
  [460] = {.lex_state = 1},
  [461] = {.lex_state = 8},
  [462] = {.lex_state = 0},
  [463] = {.lex_state = 0},
  [464] = {.lex_state = 7},
  [465] = {.lex_state = 7},
  [466] = {.lex_state = 277},
  [467] = {.lex_state = 0},
  [468] = {.lex_state = 0},
  [469] = {.lex_state = 0},
  [470] = {.lex_state = 0},
  [471] = {.lex_state = 0},
  [472] = {.lex_state = 0},
  [473] = {.lex_state = 0},
  [474] = {.lex_state = 0},
  [475] = {.lex_state = 0},
  [476] = {.lex_state = 0},
  [477] = {.lex_state = 0},
  [478] = {.lex_state = 0},
  [479] = {.lex_state = 0},
  [480] = {.lex_state = 0},
  [481] = {.lex_state = 0},
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
  [496] = {.lex_state = 0},
  [497] = {.lex_state = 0},
  [498] = {.lex_state = 0},
  [499] = {.lex_state = 0},
  [500] = {.lex_state = 0},
  [501] = {.lex_state = 0},
  [502] = {.lex_state = 0},
  [503] = {.lex_state = 0},
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
  [613] = {.lex_state = 1},
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
  },
  [1] = {
    [sym_source_file] = STATE(507),
    [sym_constant_expansion] = STATE(528),
    [sym__root] = STATE(23),
    [sym_include_macro] = STATE(23),
    [sym_constant_assignment] = STATE(23),
    [sym_add_serial_dialog_settings] = STATE(23),
    [sym_add_dialog_settings] = STATE(23),
    [sym_dialog_definition] = STATE(23),
    [sym_serial_dialog_definition] = STATE(23),
    [sym_script_definition] = STATE(23),
    [aux_sym_source_file_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(7),
    [anon_sym_LBRACK] = ACTIONS(9),
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
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(26),
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
  },
  [3] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_RBRACE] = ACTIONS(101),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
  [4] = {
    [sym__script_item] = STATE(3),
    [sym_json_literal] = STATE(3),
    [sym_label] = STATE(3),
    [sym_debug_macro] = STATE(3),
    [sym_rand_macro] = STATE(3),
    [sym_spread_macro] = STATE(3),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(3),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_RBRACE] = ACTIONS(147),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
  [5] = {
    [sym__script_item] = STATE(7),
    [sym_json_literal] = STATE(7),
    [sym_label] = STATE(7),
    [sym_debug_macro] = STATE(7),
    [sym_rand_macro] = STATE(7),
    [sym_spread_macro] = STATE(7),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(7),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_RPAREN] = ACTIONS(149),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
  [6] = {
    [sym__script_item] = STATE(8),
    [sym_json_literal] = STATE(8),
    [sym_label] = STATE(8),
    [sym_debug_macro] = STATE(8),
    [sym_rand_macro] = STATE(8),
    [sym_spread_macro] = STATE(8),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(8),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_RPAREN] = ACTIONS(151),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
  [7] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_RPAREN] = ACTIONS(153),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
  [8] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_label] = STATE(2),
    [sym_debug_macro] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_spread_macro] = STATE(2),
    [sym__action_item] = STATE(488),
    [sym_action_load_map] = STATE(488),
    [sym_action_run_script] = STATE(488),
    [sym_action_goto_label] = STATE(488),
    [sym_action_goto_index] = STATE(488),
    [sym_action_show_dialog] = STATE(488),
    [sym_action_show_serial_dialog] = STATE(488),
    [sym_action_concat_serial_dialog] = STATE(488),
    [sym_action_delete_command] = STATE(488),
    [sym_action_delete_command_arg] = STATE(488),
    [sym_action_delete_alias] = STATE(488),
    [sym_action_hide_command] = STATE(488),
    [sym_action_unhide_command] = STATE(488),
    [sym_action_save_slot] = STATE(488),
    [sym_action_load_slot] = STATE(488),
    [sym_action_erase_slot] = STATE(488),
    [sym_action_blocking_delay] = STATE(488),
    [sym_action_non_blocking_delay] = STATE(488),
    [sym_action_close_dialog] = STATE(488),
    [sym_action_close_serial_dialog] = STATE(488),
    [sym_entity_identifier_expansion] = STATE(553),
    [sym_action_pause_script] = STATE(488),
    [sym_action_unpause_script] = STATE(488),
    [sym_action_camera_fade] = STATE(488),
    [sym_action_camera_shake] = STATE(488),
    [sym_action_play_entity_animation] = STATE(488),
    [sym_camera] = STATE(406),
    [sym_movable_identifier_expansion] = STATE(414),
    [sym_action_move_over_time] = STATE(488),
    [sym_action_set_position] = STATE(488),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(97),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_entity] = ACTIONS(103),
    [anon_sym_json] = ACTIONS(105),
    [anon_sym_debug] = ACTIONS(107),
    [anon_sym_RPAREN] = ACTIONS(155),
    [anon_sym_rand] = ACTIONS(109),
    [anon_sym_spread] = ACTIONS(111),
    [sym_return_statement] = ACTIONS(113),
    [anon_sym_load] = ACTIONS(115),
    [anon_sym_goto] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [anon_sym_save] = ACTIONS(129),
    [anon_sym_erase] = ACTIONS(131),
    [anon_sym_block] = ACTIONS(133),
    [anon_sym_wait] = ACTIONS(135),
    [anon_sym_close] = ACTIONS(137),
    [sym_player] = ACTIONS(139),
    [sym_self] = ACTIONS(139),
    [anon_sym_pause] = ACTIONS(141),
    [anon_sym_unpause] = ACTIONS(143),
    [anon_sym_camera] = ACTIONS(145),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(159), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(157), 24,
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
  [38] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(163), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(161), 24,
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
  [76] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(167), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(165), 24,
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
  [114] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(169), 24,
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
  [150] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(175), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(173), 24,
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
  [186] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(179), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(177), 24,
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
  [222] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(183), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(181), 24,
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
  [258] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(187), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(185), 24,
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
  [294] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(191), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(189), 24,
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
  [330] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(193), 24,
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
  [366] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(199), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(197), 24,
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
  [402] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(203), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(201), 24,
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
  [438] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(207), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(205), 24,
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
  [474] = 12,
    ACTIONS(209), 1,
      ts_builtin_sym_end,
    ACTIONS(211), 1,
      sym_BAREWORD,
    ACTIONS(214), 1,
      anon_sym_LBRACK,
    ACTIONS(217), 1,
      sym_CONSTANT,
    ACTIONS(220), 1,
      anon_sym_include,
    ACTIONS(223), 1,
      anon_sym_add,
    ACTIONS(226), 1,
      anon_sym_serial_dialog,
    ACTIONS(229), 1,
      anon_sym_dialog,
    ACTIONS(232), 1,
      anon_sym_script,
    STATE(528), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(22), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [520] = 12,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      anon_sym_LBRACK,
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
    ACTIONS(235), 1,
      ts_builtin_sym_end,
    STATE(528), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(22), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [566] = 5,
    ACTIONS(239), 1,
      anon_sym_LBRACK,
    STATE(493), 1,
      sym_constant_value_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(237), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(241), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [590] = 6,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(245), 1,
      anon_sym_RBRACK,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(341), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(247), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [616] = 11,
    ACTIONS(251), 1,
      sym_QUOTED_STRING,
    ACTIONS(253), 1,
      anon_sym_wrap,
    ACTIONS(255), 1,
      anon_sym_entity,
    ACTIONS(257), 1,
      anon_sym_name,
    ACTIONS(259), 1,
      anon_sym_portrait,
    ACTIONS(261), 1,
      anon_sym_alignment,
    ACTIONS(263), 1,
      anon_sym_border_tileset,
    ACTIONS(265), 1,
      anon_sym_emote,
    STATE(44), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(28), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [652] = 10,
    ACTIONS(269), 1,
      anon_sym_wrap,
    ACTIONS(272), 1,
      anon_sym_entity,
    ACTIONS(275), 1,
      anon_sym_name,
    ACTIONS(278), 1,
      anon_sym_portrait,
    ACTIONS(281), 1,
      anon_sym_alignment,
    ACTIONS(284), 1,
      anon_sym_border_tileset,
    ACTIONS(287), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(267), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [686] = 11,
    ACTIONS(251), 1,
      sym_QUOTED_STRING,
    ACTIONS(253), 1,
      anon_sym_wrap,
    ACTIONS(255), 1,
      anon_sym_entity,
    ACTIONS(257), 1,
      anon_sym_name,
    ACTIONS(259), 1,
      anon_sym_portrait,
    ACTIONS(261), 1,
      anon_sym_alignment,
    ACTIONS(263), 1,
      anon_sym_border_tileset,
    ACTIONS(265), 1,
      anon_sym_emote,
    STATE(54), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [722] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(290), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(292), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [741] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(294), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(296), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [760] = 5,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(390), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(298), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [783] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(300), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(302), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [802] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(304), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(306), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [821] = 4,
    ACTIONS(310), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(308), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(312), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [842] = 10,
    ACTIONS(253), 1,
      anon_sym_wrap,
    ACTIONS(255), 1,
      anon_sym_entity,
    ACTIONS(257), 1,
      anon_sym_name,
    ACTIONS(259), 1,
      anon_sym_portrait,
    ACTIONS(261), 1,
      anon_sym_alignment,
    ACTIONS(263), 1,
      anon_sym_border_tileset,
    ACTIONS(265), 1,
      anon_sym_emote,
    ACTIONS(314), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(38), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [875] = 5,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(417), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(316), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [898] = 4,
    ACTIONS(318), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(308), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(312), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [919] = 10,
    ACTIONS(253), 1,
      anon_sym_wrap,
    ACTIONS(255), 1,
      anon_sym_entity,
    ACTIONS(257), 1,
      anon_sym_name,
    ACTIONS(259), 1,
      anon_sym_portrait,
    ACTIONS(261), 1,
      anon_sym_alignment,
    ACTIONS(263), 1,
      anon_sym_border_tileset,
    ACTIONS(265), 1,
      anon_sym_emote,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [952] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(322), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(324), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [970] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(326), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(328), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [988] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(330), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1004] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(332), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1020] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(334), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(336), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1038] = 7,
    ACTIONS(251), 1,
      sym_QUOTED_STRING,
    ACTIONS(340), 1,
      anon_sym_RBRACE,
    ACTIONS(342), 1,
      anon_sym_GT,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(73), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(338), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1064] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(344), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(346), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1082] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(348), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(350), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1100] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(352), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(354), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1118] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(356), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1134] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(358), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1150] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(360), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1166] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1182] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(364), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1198] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(368), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1216] = 7,
    ACTIONS(251), 1,
      sym_QUOTED_STRING,
    ACTIONS(342), 1,
      anon_sym_GT,
    ACTIONS(372), 1,
      anon_sym_RBRACE,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(77), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(370), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1242] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(374), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(376), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1260] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(378), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(380), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1278] = 9,
    ACTIONS(382), 1,
      sym_BAREWORD,
    ACTIONS(384), 1,
      sym_QUOTED_STRING,
    ACTIONS(386), 1,
      sym_CONSTANT,
    ACTIONS(388), 1,
      anon_sym_wrap,
    ACTIONS(390), 1,
      anon_sym_RPAREN,
    STATE(74), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(598), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(108), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1308] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(392), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(394), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1326] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(396), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(398), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1344] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(400), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(402), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1362] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(308), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(312), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1380] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(404), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(406), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1398] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(408), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1413] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(410), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1428] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(412), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1443] = 6,
    ACTIONS(414), 1,
      anon_sym_LBRACK,
    ACTIONS(416), 1,
      anon_sym_entity,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(420), 2,
      sym_player,
      sym_self,
    STATE(111), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [1465] = 7,
    ACTIONS(422), 1,
      sym_BAREWORD,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    ACTIONS(428), 1,
      anon_sym_label,
    ACTIONS(430), 1,
      anon_sym_index,
    STATE(577), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(426), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1489] = 6,
    ACTIONS(384), 1,
      sym_QUOTED_STRING,
    ACTIONS(434), 1,
      sym_serial_dialog_option_type,
    STATE(133), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(432), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(122), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1511] = 7,
    ACTIONS(436), 1,
      sym_BAREWORD,
    ACTIONS(439), 1,
      anon_sym_RBRACE,
    ACTIONS(441), 1,
      anon_sym_entity,
    ACTIONS(444), 1,
      anon_sym_name,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1535] = 7,
    ACTIONS(384), 1,
      sym_QUOTED_STRING,
    ACTIONS(447), 1,
      anon_sym_RBRACE,
    ACTIONS(449), 1,
      anon_sym_wrap,
    STATE(74), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(602), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(108), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1559] = 7,
    ACTIONS(451), 1,
      sym_BAREWORD,
    ACTIONS(453), 1,
      anon_sym_RBRACE,
    ACTIONS(455), 1,
      anon_sym_entity,
    ACTIONS(457), 1,
      anon_sym_name,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(76), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1583] = 5,
    ACTIONS(461), 1,
      sym_QUOTED_STRING,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(464), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(459), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1603] = 5,
    ACTIONS(342), 1,
      anon_sym_GT,
    ACTIONS(468), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(466), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1623] = 6,
    ACTIONS(384), 1,
      sym_QUOTED_STRING,
    ACTIONS(434), 1,
      sym_serial_dialog_option_type,
    STATE(133), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(470), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(109), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1645] = 6,
    ACTIONS(414), 1,
      anon_sym_LBRACK,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(472), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(474), 2,
      sym_player,
      sym_self,
    STATE(112), 2,
      sym_map,
      sym_entity_or_map_identifier_expansion,
  [1667] = 7,
    ACTIONS(451), 1,
      sym_BAREWORD,
    ACTIONS(455), 1,
      anon_sym_entity,
    ACTIONS(457), 1,
      anon_sym_name,
    ACTIONS(476), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1691] = 5,
    ACTIONS(342), 1,
      anon_sym_GT,
    ACTIONS(480), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(478), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1711] = 5,
    ACTIONS(484), 1,
      anon_sym_RBRACE,
    ACTIONS(486), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(78), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(482), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1731] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(491), 1,
      anon_sym_entity,
    ACTIONS(495), 1,
      anon_sym_geometry,
    STATE(543), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(493), 2,
      sym_player,
      sym_self,
  [1752] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(497), 1,
      anon_sym_entity,
    ACTIONS(501), 1,
      anon_sym_geometry,
    STATE(492), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(499), 2,
      sym_player,
      sym_self,
  [1773] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(503), 1,
      anon_sym_entity,
    ACTIONS(507), 1,
      anon_sym_geometry,
    STATE(520), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(505), 2,
      sym_player,
      sym_self,
  [1794] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(509), 1,
      anon_sym_entity,
    ACTIONS(513), 1,
      anon_sym_geometry,
    STATE(145), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(511), 2,
      sym_player,
      sym_self,
  [1815] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(515), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [1828] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(517), 1,
      anon_sym_entity,
    ACTIONS(521), 1,
      anon_sym_geometry,
    STATE(151), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(519), 2,
      sym_player,
      sym_self,
  [1849] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(523), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(525), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1864] = 6,
    ACTIONS(527), 1,
      anon_sym_RBRACK,
    ACTIONS(529), 1,
      anon_sym_entity,
    ACTIONS(533), 1,
      anon_sym_camera,
    STATE(349), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(531), 2,
      sym_player,
      sym_self,
  [1885] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(535), 1,
      anon_sym_entity,
    ACTIONS(539), 1,
      anon_sym_geometry,
    STATE(159), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(537), 2,
      sym_player,
      sym_self,
  [1906] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(541), 1,
      anon_sym_RBRACK,
    ACTIONS(543), 1,
      anon_sym_entity,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [1927] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    ACTIONS(547), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [1948] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    ACTIONS(549), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [1969] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    ACTIONS(551), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [1990] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(553), 1,
      anon_sym_entity,
    ACTIONS(557), 1,
      anon_sym_geometry,
    STATE(645), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(555), 2,
      sym_player,
      sym_self,
  [2011] = 6,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    ACTIONS(559), 1,
      anon_sym_entity,
    ACTIONS(563), 1,
      anon_sym_geometry,
    STATE(150), 1,
      sym_polygon_identifier_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(561), 2,
      sym_player,
      sym_self,
  [2032] = 6,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(565), 1,
      anon_sym_RBRACK,
    ACTIONS(567), 1,
      anon_sym_entity,
    STATE(253), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(569), 2,
      sym_player,
      sym_self,
  [2053] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(571), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2066] = 6,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(573), 1,
      anon_sym_RBRACK,
    ACTIONS(575), 1,
      anon_sym_entity,
    STATE(405), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_player,
      sym_self,
  [2087] = 6,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(575), 1,
      anon_sym_entity,
    ACTIONS(579), 1,
      anon_sym_RBRACK,
    STATE(405), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_player,
      sym_self,
  [2108] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    ACTIONS(581), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [2129] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(583), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2142] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(585), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2155] = 6,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    ACTIONS(587), 1,
      anon_sym_RBRACK,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [2176] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(589), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2189] = 6,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(575), 1,
      anon_sym_entity,
    ACTIONS(591), 1,
      anon_sym_RBRACK,
    STATE(405), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_player,
      sym_self,
  [2210] = 6,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(575), 1,
      anon_sym_entity,
    ACTIONS(593), 1,
      anon_sym_RBRACK,
    STATE(405), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_player,
      sym_self,
  [2231] = 5,
    ACTIONS(595), 1,
      anon_sym_RBRACK,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2249] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(634), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(603), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2265] = 6,
    ACTIONS(605), 1,
      anon_sym_RBRACE,
    ACTIONS(607), 1,
      anon_sym_default,
    ACTIONS(609), 1,
      anon_sym_label,
    ACTIONS(611), 1,
      anon_sym_entity,
    STATE(120), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2285] = 5,
    ACTIONS(384), 1,
      sym_QUOTED_STRING,
    ACTIONS(449), 1,
      anon_sym_wrap,
    STATE(68), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(124), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2303] = 4,
    ACTIONS(434), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(613), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(123), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2319] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(512), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(615), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2335] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(490), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2351] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(498), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(619), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2367] = 5,
    ACTIONS(533), 1,
      anon_sym_camera,
    ACTIONS(543), 1,
      anon_sym_entity,
    STATE(402), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_player,
      sym_self,
  [2385] = 4,
    ACTIONS(621), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      anon_sym_in,
      anon_sym_out,
    STATE(503), 2,
      sym_in_or_out,
      sym_in_or_out_expansion,
  [2401] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(644), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(625), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2417] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(407), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(627), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2433] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(623), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(629), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2449] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(624), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(631), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2465] = 5,
    ACTIONS(633), 1,
      anon_sym_RBRACK,
    ACTIONS(635), 1,
      anon_sym_entity,
    ACTIONS(639), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(637), 2,
      sym_player,
      sym_self,
  [2483] = 6,
    ACTIONS(607), 1,
      anon_sym_default,
    ACTIONS(609), 1,
      anon_sym_label,
    ACTIONS(611), 1,
      anon_sym_entity,
    ACTIONS(641), 1,
      anon_sym_RBRACE,
    STATE(121), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2503] = 6,
    ACTIONS(643), 1,
      anon_sym_RBRACE,
    ACTIONS(645), 1,
      anon_sym_default,
    ACTIONS(648), 1,
      anon_sym_label,
    ACTIONS(651), 1,
      anon_sym_entity,
    STATE(121), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2523] = 4,
    ACTIONS(434), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(654), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(123), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2539] = 4,
    ACTIONS(658), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(656), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(123), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2555] = 4,
    ACTIONS(663), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(661), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(124), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2571] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(510), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(666), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2587] = 5,
    ACTIONS(418), 1,
      anon_sym_map,
    ACTIONS(575), 1,
      anon_sym_entity,
    STATE(405), 1,
      sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_player,
      sym_self,
  [2605] = 5,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(668), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2623] = 5,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(670), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2641] = 5,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(672), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2659] = 4,
    ACTIONS(424), 1,
      anon_sym_LBRACK,
    STATE(475), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(674), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2675] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(678), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(676), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2689] = 5,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(680), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2707] = 4,
    ACTIONS(682), 1,
      sym_QUOTED_STRING,
    STATE(133), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(685), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [2723] = 5,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(687), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [2741] = 5,
    ACTIONS(689), 1,
      anon_sym_COMMA,
    ACTIONS(691), 1,
      anon_sym_RBRACK,
    ACTIONS(693), 1,
      anon_sym_position,
    STATE(310), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2758] = 4,
    ACTIONS(695), 1,
      anon_sym_RBRACK,
    STATE(309), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      anon_sym_in,
      anon_sym_out,
  [2773] = 4,
    ACTIONS(697), 1,
      anon_sym_LBRACK,
    STATE(636), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(699), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2788] = 4,
    ACTIONS(449), 1,
      anon_sym_wrap,
    ACTIONS(701), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(197), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2803] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(179), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(705), 2,
      sym_DURATION,
      sym_CONSTANT,
  [2818] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(707), 4,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [2829] = 4,
    ACTIONS(709), 1,
      anon_sym_LBRACK,
    STATE(547), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(711), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2844] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2855] = 4,
    ACTIONS(717), 1,
      anon_sym_LBRACE,
    STATE(579), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(715), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2870] = 4,
    ACTIONS(721), 1,
      anon_sym_LBRACE,
    STATE(604), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(719), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2885] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(725), 1,
      anon_sym_over,
    ACTIONS(727), 1,
      sym_forever,
    STATE(540), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2902] = 4,
    ACTIONS(729), 1,
      anon_sym_RBRACK,
    ACTIONS(731), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(733), 2,
      sym_player,
      sym_self,
  [2917] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(735), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2928] = 3,
    ACTIONS(739), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(737), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2941] = 4,
    ACTIONS(741), 1,
      anon_sym_LBRACK,
    STATE(476), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(743), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [2956] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(745), 1,
      anon_sym_over,
    ACTIONS(747), 1,
      sym_forever,
    STATE(485), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2973] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(749), 1,
      anon_sym_over,
    ACTIONS(751), 1,
      sym_forever,
    STATE(552), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2990] = 3,
    ACTIONS(755), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(753), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3003] = 4,
    ACTIONS(759), 1,
      anon_sym_fade,
    ACTIONS(761), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(757), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [3018] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(568), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(763), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3033] = 4,
    ACTIONS(741), 1,
      anon_sym_LBRACK,
    STATE(479), 1,
      sym_quantity_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(765), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [3048] = 5,
    ACTIONS(767), 1,
      anon_sym_COMMA,
    ACTIONS(769), 1,
      anon_sym_RBRACK,
    ACTIONS(771), 1,
      anon_sym_position,
    STATE(382), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3065] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(773), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3076] = 3,
    ACTIONS(775), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(737), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3089] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(777), 1,
      anon_sym_over,
    ACTIONS(779), 1,
      sym_forever,
    STATE(499), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3106] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(781), 1,
      anon_sym_over,
    ACTIONS(783), 1,
      sym_forever,
    STATE(509), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3123] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(511), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(785), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3138] = 4,
    ACTIONS(789), 1,
      anon_sym_LBRACK,
    STATE(533), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(787), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3153] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(791), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3164] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(793), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3175] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(795), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3186] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(797), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3197] = 4,
    ACTIONS(799), 1,
      anon_sym_RBRACK,
    STATE(426), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      anon_sym_in,
      anon_sym_out,
  [3212] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(801), 1,
      anon_sym_over,
    ACTIONS(803), 1,
      sym_forever,
    STATE(535), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3229] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(536), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(805), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3244] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(807), 1,
      anon_sym_over,
    ACTIONS(809), 1,
      sym_forever,
    STATE(469), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3261] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(326), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(811), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3276] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(813), 1,
      anon_sym_over,
    ACTIONS(815), 1,
      sym_forever,
    STATE(546), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3293] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(817), 1,
      anon_sym_over,
    ACTIONS(819), 1,
      sym_forever,
    STATE(549), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3310] = 4,
    ACTIONS(731), 1,
      anon_sym_entity,
    ACTIONS(821), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(733), 2,
      sym_player,
      sym_self,
  [3325] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(823), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3336] = 4,
    ACTIONS(825), 1,
      anon_sym_LBRACK,
    STATE(578), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(827), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3351] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(829), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3362] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(831), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3373] = 4,
    ACTIONS(833), 1,
      anon_sym_LBRACK,
    STATE(588), 1,
      sym_distance_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(835), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [3388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(837), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3399] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(839), 1,
      anon_sym_over,
    ACTIONS(841), 1,
      sym_forever,
    STATE(610), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3416] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(843), 1,
      anon_sym_over,
    ACTIONS(845), 1,
      sym_forever,
    STATE(559), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3433] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(561), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(847), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3448] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(849), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3459] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(628), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(851), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3474] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(853), 1,
      anon_sym_over,
    ACTIONS(855), 1,
      sym_forever,
    STATE(571), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3491] = 4,
    ACTIONS(697), 1,
      anon_sym_LBRACK,
    STATE(155), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(857), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3506] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(859), 1,
      anon_sym_over,
    ACTIONS(861), 1,
      sym_forever,
    STATE(575), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3523] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(863), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3534] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(637), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(865), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3549] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(867), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3560] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(869), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3571] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(595), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(871), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3586] = 4,
    ACTIONS(873), 1,
      anon_sym_RBRACK,
    STATE(426), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      anon_sym_in,
      anon_sym_out,
  [3601] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(582), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(875), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3616] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(586), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(877), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3631] = 4,
    ACTIONS(449), 1,
      anon_sym_wrap,
    ACTIONS(879), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(124), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3646] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(881), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3657] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(600), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(883), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3672] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(601), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(885), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3687] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(611), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(887), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3702] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(612), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(889), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3717] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(891), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3728] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(893), 1,
      anon_sym_over,
    ACTIONS(895), 1,
      sym_forever,
    STATE(616), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3745] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(617), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(897), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3760] = 5,
    ACTIONS(723), 1,
      anon_sym_LBRACK,
    ACTIONS(899), 1,
      anon_sym_over,
    ACTIONS(901), 1,
      sym_forever,
    STATE(620), 1,
      sym_complex_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3777] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(903), 4,
      anon_sym_LBRACK,
      sym_QUANTITY,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3788] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(625), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(905), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3803] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(626), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(907), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3818] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(909), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3829] = 4,
    ACTIONS(731), 1,
      anon_sym_entity,
    ACTIONS(911), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(733), 2,
      sym_player,
      sym_self,
  [3844] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(913), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3855] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(915), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3866] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(917), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3877] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(919), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3888] = 4,
    ACTIONS(697), 1,
      anon_sym_LBRACK,
    STATE(560), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(921), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3903] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(923), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3914] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(462), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(925), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3929] = 4,
    ACTIONS(731), 1,
      anon_sym_entity,
    ACTIONS(927), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(733), 2,
      sym_player,
      sym_self,
  [3944] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(652), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(929), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3959] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(653), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(931), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3974] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(933), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [3985] = 4,
    ACTIONS(697), 1,
      anon_sym_LBRACK,
    STATE(501), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(935), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4000] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(937), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4011] = 4,
    ACTIONS(697), 1,
      anon_sym_LBRACK,
    STATE(149), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(939), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4026] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(941), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4037] = 4,
    ACTIONS(597), 1,
      anon_sym_entity,
    ACTIONS(601), 1,
      anon_sym_geometry,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      sym_player,
      sym_self,
  [4052] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(943), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4063] = 4,
    ACTIONS(721), 1,
      anon_sym_LBRACE,
    STATE(565), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(945), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4078] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(947), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4089] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(949), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4100] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(951), 4,
      anon_sym_LBRACK,
      anon_sym_SEMI,
      anon_sym_over,
      sym_forever,
  [4111] = 4,
    ACTIONS(703), 1,
      anon_sym_LBRACK,
    STATE(572), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(953), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4126] = 3,
    STATE(431), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(955), 2,
      sym_origin,
      sym_length,
  [4138] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(957), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4148] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(959), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4158] = 4,
    ACTIONS(961), 1,
      anon_sym_COMMA,
    ACTIONS(963), 1,
      anon_sym_RBRACK,
    STATE(284), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4172] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(965), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4182] = 4,
    ACTIONS(967), 1,
      anon_sym_COMMA,
    ACTIONS(969), 1,
      anon_sym_RBRACE,
    STATE(296), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4196] = 4,
    ACTIONS(971), 1,
      anon_sym_COMMA,
    ACTIONS(973), 1,
      anon_sym_RBRACK,
    STATE(247), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4210] = 4,
    ACTIONS(975), 1,
      anon_sym_COMMA,
    ACTIONS(978), 1,
      anon_sym_RBRACK,
    STATE(241), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4224] = 4,
    ACTIONS(980), 1,
      anon_sym_COMMA,
    ACTIONS(982), 1,
      anon_sym_RBRACK,
    STATE(237), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4238] = 4,
    ACTIONS(984), 1,
      anon_sym_COMMA,
    ACTIONS(987), 1,
      anon_sym_RBRACK,
    STATE(243), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4252] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(989), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4262] = 4,
    ACTIONS(991), 1,
      anon_sym_COMMA,
    ACTIONS(993), 1,
      anon_sym_RBRACK,
    STATE(348), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4276] = 3,
    ACTIONS(995), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(997), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4288] = 4,
    ACTIONS(999), 1,
      anon_sym_COMMA,
    ACTIONS(1002), 1,
      anon_sym_RBRACK,
    STATE(247), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4302] = 4,
    ACTIONS(995), 1,
      anon_sym_RBRACK,
    ACTIONS(1004), 1,
      anon_sym_COMMA,
    STATE(299), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4316] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1006), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4326] = 4,
    ACTIONS(1008), 1,
      anon_sym_COMMA,
    ACTIONS(1011), 1,
      anon_sym_RBRACK,
    STATE(250), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4340] = 3,
    ACTIONS(1015), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4352] = 4,
    ACTIONS(1015), 1,
      anon_sym_RBRACK,
    ACTIONS(1017), 1,
      anon_sym_COMMA,
    STATE(302), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4366] = 4,
    ACTIONS(1019), 1,
      anon_sym_COMMA,
    ACTIONS(1021), 1,
      anon_sym_RBRACK,
    STATE(308), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4380] = 3,
    ACTIONS(1023), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1025), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4392] = 4,
    ACTIONS(1027), 1,
      anon_sym_COMMA,
    ACTIONS(1030), 1,
      anon_sym_RBRACK,
    STATE(255), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4406] = 3,
    ACTIONS(1032), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1034), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [4418] = 3,
    STATE(505), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1036), 2,
      sym_origin,
      sym_length,
  [4430] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1038), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4440] = 3,
    STATE(188), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1040), 2,
      sym_origin,
      sym_length,
  [4452] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1042), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4462] = 4,
    ACTIONS(967), 1,
      anon_sym_COMMA,
    ACTIONS(1044), 1,
      anon_sym_RBRACE,
    STATE(239), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4476] = 3,
    ACTIONS(1048), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1046), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [4488] = 4,
    ACTIONS(1050), 1,
      anon_sym_COMMA,
    ACTIONS(1052), 1,
      anon_sym_RBRACK,
    STATE(268), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4502] = 3,
    ACTIONS(1054), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1056), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4514] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1058), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4524] = 4,
    ACTIONS(1060), 1,
      anon_sym_COMMA,
    ACTIONS(1062), 1,
      anon_sym_RBRACK,
    STATE(241), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4538] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1064), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_DASH_GT,
  [4548] = 4,
    ACTIONS(1066), 1,
      anon_sym_COMMA,
    ACTIONS(1069), 1,
      anon_sym_RBRACK,
    STATE(268), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4562] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1071), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4572] = 4,
    ACTIONS(799), 1,
      anon_sym_RBRACK,
    ACTIONS(1073), 1,
      anon_sym_COMMA,
    STATE(314), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4586] = 3,
    ACTIONS(1075), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1077), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4598] = 3,
    ACTIONS(1079), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1081), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [4610] = 4,
    ACTIONS(1083), 1,
      anon_sym_COMMA,
    ACTIONS(1085), 1,
      anon_sym_RBRACK,
    STATE(322), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4624] = 3,
    STATE(323), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1087), 2,
      sym_origin,
      sym_length,
  [4636] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1089), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4646] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1091), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4656] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1093), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4666] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1095), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4676] = 4,
    ACTIONS(1097), 1,
      anon_sym_COMMA,
    ACTIONS(1099), 1,
      anon_sym_RBRACK,
    STATE(328), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4690] = 4,
    ACTIONS(1101), 1,
      anon_sym_COMMA,
    ACTIONS(1103), 1,
      anon_sym_RBRACK,
    STATE(248), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4704] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1105), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4714] = 4,
    ACTIONS(739), 1,
      anon_sym_RBRACK,
    ACTIONS(1107), 1,
      anon_sym_COMMA,
    STATE(250), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4728] = 4,
    ACTIONS(1109), 1,
      anon_sym_COMMA,
    ACTIONS(1111), 1,
      anon_sym_RBRACK,
    STATE(252), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4742] = 4,
    ACTIONS(1113), 1,
      anon_sym_COMMA,
    ACTIONS(1116), 1,
      anon_sym_RBRACK,
    STATE(284), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4756] = 3,
    ACTIONS(1118), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1025), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4768] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1120), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4778] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1122), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4788] = 4,
    ACTIONS(1118), 1,
      anon_sym_RBRACK,
    ACTIONS(1124), 1,
      anon_sym_COMMA,
    STATE(255), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4802] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1126), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4812] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1128), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4822] = 3,
    STATE(555), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1130), 2,
      sym_origin,
      sym_length,
  [4834] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1132), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4844] = 3,
    STATE(206), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1134), 2,
      sym_origin,
      sym_length,
  [4856] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1136), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4866] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1138), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4876] = 4,
    ACTIONS(1140), 1,
      anon_sym_COMMA,
    ACTIONS(1143), 1,
      anon_sym_RBRACE,
    STATE(296), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4890] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1145), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4900] = 3,
    ACTIONS(1147), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(997), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4912] = 4,
    ACTIONS(1149), 1,
      anon_sym_COMMA,
    ACTIONS(1152), 1,
      anon_sym_RBRACK,
    STATE(299), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4926] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(737), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4936] = 3,
    ACTIONS(1154), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4948] = 4,
    ACTIONS(1156), 1,
      anon_sym_COMMA,
    ACTIONS(1159), 1,
      anon_sym_RBRACK,
    STATE(302), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4962] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1161), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4972] = 4,
    ACTIONS(1163), 1,
      anon_sym_COMMA,
    ACTIONS(1165), 1,
      anon_sym_RBRACK,
    STATE(339), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4986] = 4,
    ACTIONS(1167), 1,
      anon_sym_COMMA,
    ACTIONS(1169), 1,
      anon_sym_RBRACK,
    STATE(263), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5000] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1171), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5010] = 4,
    ACTIONS(1173), 1,
      anon_sym_COMMA,
    ACTIONS(1175), 1,
      anon_sym_RBRACK,
    STATE(240), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5024] = 4,
    ACTIONS(1177), 1,
      anon_sym_COMMA,
    ACTIONS(1179), 1,
      anon_sym_RBRACK,
    STATE(268), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5038] = 4,
    ACTIONS(1181), 1,
      anon_sym_COMMA,
    ACTIONS(1183), 1,
      anon_sym_RBRACK,
    STATE(270), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5052] = 4,
    ACTIONS(1185), 1,
      anon_sym_COMMA,
    ACTIONS(1187), 1,
      anon_sym_RBRACK,
    STATE(243), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5066] = 4,
    ACTIONS(318), 1,
      anon_sym_RBRACK,
    ACTIONS(1189), 1,
      anon_sym_COMMA,
    STATE(335), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5080] = 3,
    ACTIONS(1191), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1193), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5092] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1195), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5102] = 4,
    ACTIONS(1197), 1,
      anon_sym_COMMA,
    ACTIONS(1200), 1,
      anon_sym_RBRACK,
    STATE(314), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5116] = 4,
    ACTIONS(1202), 1,
      anon_sym_COMMA,
    ACTIONS(1204), 1,
      anon_sym_RBRACK,
    STATE(345), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5130] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1206), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5140] = 4,
    ACTIONS(1208), 1,
      anon_sym_COMMA,
    ACTIONS(1210), 1,
      anon_sym_RBRACK,
    STATE(347), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5154] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1212), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5164] = 4,
    ACTIONS(1214), 1,
      anon_sym_COMMA,
    ACTIONS(1216), 1,
      anon_sym_RBRACK,
    STATE(350), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5178] = 4,
    ACTIONS(1218), 1,
      anon_sym_COMMA,
    ACTIONS(1221), 1,
      anon_sym_RBRACK,
    STATE(320), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5192] = 3,
    STATE(170), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1223), 2,
      sym_origin,
      sym_length,
  [5204] = 4,
    ACTIONS(1225), 1,
      anon_sym_COMMA,
    ACTIONS(1227), 1,
      anon_sym_RBRACK,
    STATE(356), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5218] = 4,
    ACTIONS(1229), 1,
      anon_sym_COMMA,
    ACTIONS(1231), 1,
      anon_sym_RBRACK,
    STATE(359), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5232] = 4,
    ACTIONS(1233), 1,
      anon_sym_RBRACK,
    ACTIONS(1235), 1,
      anon_sym_over,
    ACTIONS(1237), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5246] = 3,
    ACTIONS(1239), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1241), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5258] = 4,
    ACTIONS(1243), 1,
      anon_sym_COMMA,
    ACTIONS(1245), 1,
      anon_sym_RBRACK,
    STATE(361), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5272] = 4,
    ACTIONS(1247), 1,
      anon_sym_RBRACK,
    ACTIONS(1249), 1,
      anon_sym_over,
    ACTIONS(1251), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5286] = 4,
    ACTIONS(1253), 1,
      anon_sym_COMMA,
    ACTIONS(1255), 1,
      anon_sym_RBRACK,
    STATE(364), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5300] = 3,
    STATE(632), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1257), 2,
      sym_origin,
      sym_length,
  [5312] = 3,
    STATE(173), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1259), 2,
      sym_origin,
      sym_length,
  [5324] = 4,
    ACTIONS(1261), 1,
      anon_sym_COMMA,
    ACTIONS(1263), 1,
      anon_sym_RBRACK,
    STATE(247), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5338] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1265), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [5348] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1267), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5358] = 4,
    ACTIONS(1269), 1,
      anon_sym_COMMA,
    ACTIONS(1271), 1,
      anon_sym_RBRACK,
    STATE(311), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5372] = 4,
    ACTIONS(1273), 1,
      anon_sym_COMMA,
    ACTIONS(1276), 1,
      anon_sym_RBRACK,
    STATE(335), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5386] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1278), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5396] = 4,
    ACTIONS(1280), 1,
      sym_QUOTED_STRING,
    ACTIONS(1282), 1,
      anon_sym_RBRACE,
    STATE(261), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5410] = 3,
    ACTIONS(1284), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1286), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [5422] = 4,
    ACTIONS(1284), 1,
      anon_sym_RBRACK,
    ACTIONS(1288), 1,
      anon_sym_COMMA,
    STATE(369), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5436] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1290), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [5446] = 4,
    ACTIONS(1060), 1,
      anon_sym_COMMA,
    ACTIONS(1292), 1,
      anon_sym_RBRACK,
    STATE(266), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5460] = 3,
    ACTIONS(1294), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1193), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5472] = 3,
    STATE(426), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      anon_sym_in,
      anon_sym_out,
  [5484] = 3,
    ACTIONS(1296), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1298), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5496] = 4,
    ACTIONS(1296), 1,
      anon_sym_RBRACK,
    ACTIONS(1300), 1,
      anon_sym_COMMA,
    STATE(371), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5510] = 3,
    ACTIONS(1302), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1304), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [5522] = 4,
    ACTIONS(1302), 1,
      anon_sym_RBRACK,
    ACTIONS(1306), 1,
      anon_sym_COMMA,
    STATE(373), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5536] = 4,
    ACTIONS(1294), 1,
      anon_sym_RBRACK,
    ACTIONS(1308), 1,
      anon_sym_COMMA,
    STATE(320), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5550] = 4,
    ACTIONS(1310), 1,
      anon_sym_COMMA,
    ACTIONS(1312), 1,
      anon_sym_RBRACK,
    STATE(331), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5564] = 4,
    ACTIONS(1314), 1,
      anon_sym_COMMA,
    ACTIONS(1316), 1,
      anon_sym_RBRACK,
    STATE(356), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5578] = 3,
    ACTIONS(1318), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1320), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5590] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1322), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5600] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1324), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5610] = 4,
    ACTIONS(1326), 1,
      anon_sym_COMMA,
    ACTIONS(1328), 1,
      anon_sym_RBRACK,
    STATE(282), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5624] = 3,
    ACTIONS(1332), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1330), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5636] = 4,
    ACTIONS(1334), 1,
      anon_sym_COMMA,
    ACTIONS(1337), 1,
      anon_sym_RBRACK,
    STATE(356), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5650] = 4,
    ACTIONS(721), 1,
      anon_sym_LBRACE,
    ACTIONS(1339), 1,
      anon_sym_SEMI,
    STATE(657), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5664] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1341), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5674] = 4,
    ACTIONS(1343), 1,
      anon_sym_COMMA,
    ACTIONS(1345), 1,
      anon_sym_RBRACK,
    STATE(356), 1,
      aux_sym_polygon_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5688] = 4,
    ACTIONS(1249), 1,
      anon_sym_over,
    ACTIONS(1251), 1,
      sym_forever,
    ACTIONS(1347), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5702] = 4,
    ACTIONS(1349), 1,
      anon_sym_COMMA,
    ACTIONS(1351), 1,
      anon_sym_RBRACK,
    STATE(364), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5716] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1353), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5726] = 4,
    ACTIONS(1249), 1,
      anon_sym_over,
    ACTIONS(1251), 1,
      sym_forever,
    ACTIONS(1355), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5740] = 4,
    ACTIONS(1357), 1,
      anon_sym_COMMA,
    ACTIONS(1360), 1,
      anon_sym_RBRACK,
    STATE(364), 1,
      aux_sym_complex_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5754] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1362), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5764] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1364), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5774] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1366), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5784] = 3,
    ACTIONS(1368), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1286), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [5796] = 4,
    ACTIONS(1370), 1,
      anon_sym_COMMA,
    ACTIONS(1373), 1,
      anon_sym_RBRACK,
    STATE(369), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5810] = 3,
    ACTIONS(1375), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1298), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5822] = 4,
    ACTIONS(1377), 1,
      anon_sym_COMMA,
    ACTIONS(1380), 1,
      anon_sym_RBRACK,
    STATE(371), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5836] = 3,
    ACTIONS(1382), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1304), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [5848] = 4,
    ACTIONS(1384), 1,
      anon_sym_COMMA,
    ACTIONS(1387), 1,
      anon_sym_RBRACK,
    STATE(373), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5862] = 4,
    ACTIONS(717), 1,
      anon_sym_LBRACE,
    ACTIONS(1389), 1,
      anon_sym_SEMI,
    STATE(659), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5876] = 4,
    ACTIONS(721), 1,
      anon_sym_LBRACE,
    ACTIONS(1391), 1,
      anon_sym_SEMI,
    STATE(662), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5890] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1393), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5900] = 4,
    ACTIONS(1395), 1,
      anon_sym_COMMA,
    ACTIONS(1397), 1,
      anon_sym_RBRACK,
    STATE(247), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5914] = 4,
    ACTIONS(1399), 1,
      anon_sym_COMMA,
    ACTIONS(1401), 1,
      anon_sym_RBRACK,
    STATE(288), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5928] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1403), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5938] = 3,
    ACTIONS(731), 1,
      anon_sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(733), 2,
      sym_player,
      sym_self,
  [5950] = 4,
    ACTIONS(1405), 1,
      anon_sym_COMMA,
    ACTIONS(1407), 1,
      anon_sym_RBRACK,
    STATE(377), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5964] = 4,
    ACTIONS(1409), 1,
      anon_sym_COMMA,
    ACTIONS(1411), 1,
      anon_sym_RBRACK,
    STATE(243), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5978] = 4,
    ACTIONS(1249), 1,
      anon_sym_over,
    ACTIONS(1251), 1,
      sym_forever,
    ACTIONS(1413), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5992] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1415), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6002] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1417), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6012] = 3,
    STATE(597), 1,
      sym__origin_or_length,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1419), 2,
      sym_origin,
      sym_length,
  [6024] = 3,
    ACTIONS(1421), 1,
      anon_sym_serial_dialog,
    ACTIONS(1423), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6035] = 3,
    ACTIONS(1280), 1,
      sym_QUOTED_STRING,
    STATE(418), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6046] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1425), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6055] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(978), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6064] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1427), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6073] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1429), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6082] = 3,
    ACTIONS(1431), 1,
      anon_sym_EQ,
    ACTIONS(1433), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6093] = 3,
    ACTIONS(1435), 1,
      anon_sym_RBRACK,
    ACTIONS(1437), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6104] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1011), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6113] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1439), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [6122] = 3,
    ACTIONS(1441), 1,
      anon_sym_animation,
    ACTIONS(1443), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6133] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1445), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6142] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1447), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6151] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1030), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6160] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1449), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6169] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1451), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6178] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1453), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6187] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1455), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [6196] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1457), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6205] = 3,
    ACTIONS(1459), 1,
      anon_sym_EQ,
    ACTIONS(1461), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6216] = 3,
    ACTIONS(1463), 1,
      anon_sym_SEMI,
    ACTIONS(1465), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6227] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1467), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [6236] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1469), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6245] = 3,
    ACTIONS(1471), 1,
      anon_sym_EQ,
    ACTIONS(1473), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6256] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1475), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6265] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1477), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6274] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1479), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6283] = 3,
    ACTIONS(1481), 1,
      anon_sym_EQ,
    ACTIONS(1483), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6294] = 3,
    ACTIONS(721), 1,
      anon_sym_LBRACE,
    STATE(55), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6305] = 3,
    ACTIONS(963), 1,
      anon_sym_RBRACK,
    ACTIONS(1485), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6316] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1487), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [6325] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1143), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [6334] = 3,
    ACTIONS(717), 1,
      anon_sym_LBRACE,
    STATE(53), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6345] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1152), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6354] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1489), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [6363] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1159), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6372] = 3,
    ACTIONS(1491), 1,
      anon_sym_LBRACE,
    STATE(39), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6383] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1025), 2,
      sym_DURATION,
      sym_CONSTANT,
  [6392] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1493), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6401] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1200), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6410] = 3,
    ACTIONS(1491), 1,
      anon_sym_LBRACE,
    STATE(58), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6421] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1116), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6430] = 3,
    ACTIONS(1485), 1,
      sym_CONSTANT,
    ACTIONS(1495), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6441] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1497), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6450] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1499), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6459] = 3,
    ACTIONS(1501), 1,
      anon_sym_serial_dialog,
    ACTIONS(1503), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6470] = 3,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
    STATE(14), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6481] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(997), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6490] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [6499] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1193), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [6508] = 3,
    ACTIONS(1505), 1,
      anon_sym_LBRACE,
    STATE(177), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6519] = 3,
    ACTIONS(1505), 1,
      anon_sym_LBRACE,
    STATE(178), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6530] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1221), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6539] = 3,
    ACTIONS(1507), 1,
      anon_sym_map,
    ACTIONS(1509), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6550] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(757), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6559] = 3,
    ACTIONS(1505), 1,
      anon_sym_LBRACE,
    STATE(214), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6570] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1511), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [6579] = 3,
    ACTIONS(1513), 1,
      anon_sym_serial_dialog,
    ACTIONS(1515), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6590] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1517), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6599] = 3,
    ACTIONS(1519), 1,
      anon_sym_animation,
    ACTIONS(1521), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6610] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1523), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6619] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1525), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6628] = 3,
    ACTIONS(1527), 1,
      anon_sym_command,
    ACTIONS(1529), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6639] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1373), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6648] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1531), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6657] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1533), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6666] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1380), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6675] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1535), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6684] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1387), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6693] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1537), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6702] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1539), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6711] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1541), 2,
      anon_sym_EQ,
      anon_sym_DASH_GT,
  [6720] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1543), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6729] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1545), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [6738] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1547), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [6747] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1549), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6756] = 3,
    ACTIONS(1249), 1,
      anon_sym_over,
    ACTIONS(1251), 1,
      sym_forever,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6767] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1286), 2,
      sym_QUANTITY,
      sym_CONSTANT,
  [6776] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1298), 2,
      sym_COLOR,
      sym_CONSTANT,
  [6785] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1304), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [6794] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1551), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6803] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1276), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6812] = 2,
    ACTIONS(1553), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6820] = 2,
    ACTIONS(1555), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6828] = 2,
    ACTIONS(1557), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6836] = 2,
    ACTIONS(1559), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6844] = 2,
    ACTIONS(1561), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6852] = 2,
    ACTIONS(1563), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6860] = 2,
    ACTIONS(1565), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6868] = 2,
    ACTIONS(1567), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6876] = 2,
    ACTIONS(1569), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6884] = 2,
    ACTIONS(1571), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6892] = 2,
    ACTIONS(1573), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6900] = 2,
    ACTIONS(1575), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6908] = 2,
    ACTIONS(1577), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6916] = 2,
    ACTIONS(1579), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6924] = 2,
    ACTIONS(1581), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6932] = 2,
    ACTIONS(1583), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6940] = 2,
    ACTIONS(1585), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6948] = 2,
    ACTIONS(1587), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6956] = 2,
    ACTIONS(1589), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6964] = 2,
    ACTIONS(1591), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6972] = 2,
    ACTIONS(1593), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6980] = 2,
    ACTIONS(1595), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6988] = 2,
    ACTIONS(1597), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6996] = 2,
    ACTIONS(1599), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7004] = 2,
    ACTIONS(1601), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7012] = 2,
    ACTIONS(1603), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7020] = 2,
    ACTIONS(1605), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7028] = 2,
    ACTIONS(1607), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7036] = 2,
    ACTIONS(1609), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7044] = 2,
    ACTIONS(1611), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7052] = 2,
    ACTIONS(1613), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7060] = 2,
    ACTIONS(1615), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7068] = 2,
    ACTIONS(1617), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7076] = 2,
    ACTIONS(1619), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7084] = 2,
    ACTIONS(1621), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7092] = 2,
    ACTIONS(1623), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7100] = 2,
    ACTIONS(1625), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7108] = 2,
    ACTIONS(1627), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7116] = 2,
    ACTIONS(1629), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7124] = 2,
    ACTIONS(1631), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7132] = 2,
    ACTIONS(1633), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7140] = 2,
    ACTIONS(1635), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7148] = 2,
    ACTIONS(1637), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7156] = 2,
    ACTIONS(1639), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7164] = 2,
    ACTIONS(1641), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7172] = 2,
    ACTIONS(1643), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7180] = 2,
    ACTIONS(1645), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7188] = 2,
    ACTIONS(1647), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7196] = 2,
    ACTIONS(1649), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7204] = 2,
    ACTIONS(1651), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7212] = 2,
    ACTIONS(1653), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7220] = 2,
    ACTIONS(1655), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7228] = 2,
    ACTIONS(1657), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7236] = 2,
    ACTIONS(1659), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7244] = 2,
    ACTIONS(1661), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7252] = 2,
    ACTIONS(1663), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7260] = 2,
    ACTIONS(1665), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7268] = 2,
    ACTIONS(1667), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7276] = 2,
    ACTIONS(1669), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7284] = 2,
    ACTIONS(1671), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7292] = 2,
    ACTIONS(1673), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7300] = 2,
    ACTIONS(1675), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7308] = 2,
    ACTIONS(1677), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7316] = 2,
    ACTIONS(1679), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7324] = 2,
    ACTIONS(1681), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7332] = 2,
    ACTIONS(1683), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7340] = 2,
    ACTIONS(1685), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7348] = 2,
    ACTIONS(1687), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7356] = 2,
    ACTIONS(1689), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7364] = 2,
    ACTIONS(1691), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7372] = 2,
    ACTIONS(1693), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7380] = 2,
    ACTIONS(1695), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7388] = 2,
    ACTIONS(1697), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7396] = 2,
    ACTIONS(1699), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7404] = 2,
    ACTIONS(1701), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7412] = 2,
    ACTIONS(1703), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7420] = 2,
    ACTIONS(1705), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7428] = 2,
    ACTIONS(1707), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7436] = 2,
    ACTIONS(1709), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7444] = 2,
    ACTIONS(1711), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7452] = 2,
    ACTIONS(1713), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7460] = 2,
    ACTIONS(1715), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7468] = 2,
    ACTIONS(1717), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7476] = 2,
    ACTIONS(1719), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7484] = 2,
    ACTIONS(1441), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7492] = 2,
    ACTIONS(1721), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7500] = 2,
    ACTIONS(1723), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7508] = 2,
    ACTIONS(1725), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7516] = 2,
    ACTIONS(1727), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7524] = 2,
    ACTIONS(1729), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7532] = 2,
    ACTIONS(1731), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7540] = 2,
    ACTIONS(1733), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7548] = 2,
    ACTIONS(1735), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7556] = 2,
    ACTIONS(1737), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7564] = 2,
    ACTIONS(1739), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7572] = 2,
    ACTIONS(1741), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7580] = 2,
    ACTIONS(1743), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7588] = 2,
    ACTIONS(1745), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7596] = 2,
    ACTIONS(1747), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7604] = 2,
    ACTIONS(1749), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7612] = 2,
    ACTIONS(1751), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7620] = 2,
    ACTIONS(1753), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7628] = 2,
    ACTIONS(1755), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7636] = 2,
    ACTIONS(1757), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7644] = 2,
    ACTIONS(1485), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7652] = 2,
    ACTIONS(1759), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7660] = 2,
    ACTIONS(1761), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7668] = 2,
    ACTIONS(1763), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7676] = 2,
    ACTIONS(1765), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7684] = 2,
    ACTIONS(1767), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7692] = 2,
    ACTIONS(1769), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7700] = 2,
    ACTIONS(1771), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7708] = 2,
    ACTIONS(1773), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7716] = 2,
    ACTIONS(1775), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7724] = 2,
    ACTIONS(1777), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7732] = 2,
    ACTIONS(1779), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7740] = 2,
    ACTIONS(1781), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7748] = 2,
    ACTIONS(1783), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7756] = 2,
    ACTIONS(1785), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7764] = 2,
    ACTIONS(1787), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7772] = 2,
    ACTIONS(1789), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7780] = 2,
    ACTIONS(1791), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7788] = 2,
    ACTIONS(1793), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7796] = 2,
    ACTIONS(1795), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7804] = 2,
    ACTIONS(1797), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7812] = 2,
    ACTIONS(1799), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7820] = 2,
    ACTIONS(1801), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7828] = 2,
    ACTIONS(1803), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7836] = 2,
    ACTIONS(1805), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7844] = 2,
    ACTIONS(1807), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7852] = 2,
    ACTIONS(1809), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7860] = 2,
    ACTIONS(1811), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7868] = 2,
    ACTIONS(1813), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7876] = 2,
    ACTIONS(1815), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7884] = 2,
    ACTIONS(1817), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7892] = 2,
    ACTIONS(1819), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7900] = 2,
    ACTIONS(1821), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7908] = 2,
    ACTIONS(1823), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7916] = 2,
    ACTIONS(1825), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7924] = 2,
    ACTIONS(1827), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7932] = 2,
    ACTIONS(1829), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7940] = 2,
    ACTIONS(1831), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7948] = 2,
    ACTIONS(1833), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7956] = 2,
    ACTIONS(1835), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7964] = 2,
    ACTIONS(1837), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7972] = 2,
    ACTIONS(1839), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7980] = 2,
    ACTIONS(1841), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7988] = 2,
    ACTIONS(1843), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [7996] = 2,
    ACTIONS(1845), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8004] = 2,
    ACTIONS(1847), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8012] = 2,
    ACTIONS(1849), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8020] = 2,
    ACTIONS(1851), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8028] = 2,
    ACTIONS(1853), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8036] = 2,
    ACTIONS(1855), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8044] = 2,
    ACTIONS(1857), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8052] = 2,
    ACTIONS(1859), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8060] = 2,
    ACTIONS(1861), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8068] = 2,
    ACTIONS(1863), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8076] = 2,
    ACTIONS(1865), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8084] = 2,
    ACTIONS(1867), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8092] = 2,
    ACTIONS(1869), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8100] = 2,
    ACTIONS(1871), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8108] = 2,
    ACTIONS(1873), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8116] = 2,
    ACTIONS(1875), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8124] = 2,
    ACTIONS(1877), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8132] = 2,
    ACTIONS(1879), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8140] = 2,
    ACTIONS(1881), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8148] = 2,
    ACTIONS(1883), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8156] = 2,
    ACTIONS(1885), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8164] = 2,
    ACTIONS(1887), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8172] = 2,
    ACTIONS(1889), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8180] = 2,
    ACTIONS(1891), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8188] = 2,
    ACTIONS(1893), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8196] = 2,
    ACTIONS(1895), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8204] = 2,
    ACTIONS(1897), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8212] = 2,
    ACTIONS(1899), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8220] = 2,
    ACTIONS(1901), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8228] = 2,
    ACTIONS(1903), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8236] = 2,
    ACTIONS(1905), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8244] = 2,
    ACTIONS(1907), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8252] = 2,
    ACTIONS(1909), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8260] = 2,
    ACTIONS(1911), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8268] = 2,
    ACTIONS(1913), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8276] = 2,
    ACTIONS(1915), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8284] = 2,
    ACTIONS(1917), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8292] = 2,
    ACTIONS(1919), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8300] = 2,
    ACTIONS(1921), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8308] = 2,
    ACTIONS(1923), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8316] = 2,
    ACTIONS(1925), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8324] = 2,
    ACTIONS(1927), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8332] = 2,
    ACTIONS(1929), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8340] = 2,
    ACTIONS(1931), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8348] = 2,
    ACTIONS(1933), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8356] = 2,
    ACTIONS(1935), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8364] = 2,
    ACTIONS(1937), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8372] = 2,
    ACTIONS(1939), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [8380] = 2,
    ACTIONS(1941), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 38,
  [SMALL_STATE(11)] = 76,
  [SMALL_STATE(12)] = 114,
  [SMALL_STATE(13)] = 150,
  [SMALL_STATE(14)] = 186,
  [SMALL_STATE(15)] = 222,
  [SMALL_STATE(16)] = 258,
  [SMALL_STATE(17)] = 294,
  [SMALL_STATE(18)] = 330,
  [SMALL_STATE(19)] = 366,
  [SMALL_STATE(20)] = 402,
  [SMALL_STATE(21)] = 438,
  [SMALL_STATE(22)] = 474,
  [SMALL_STATE(23)] = 520,
  [SMALL_STATE(24)] = 566,
  [SMALL_STATE(25)] = 590,
  [SMALL_STATE(26)] = 616,
  [SMALL_STATE(27)] = 652,
  [SMALL_STATE(28)] = 686,
  [SMALL_STATE(29)] = 722,
  [SMALL_STATE(30)] = 741,
  [SMALL_STATE(31)] = 760,
  [SMALL_STATE(32)] = 783,
  [SMALL_STATE(33)] = 802,
  [SMALL_STATE(34)] = 821,
  [SMALL_STATE(35)] = 842,
  [SMALL_STATE(36)] = 875,
  [SMALL_STATE(37)] = 898,
  [SMALL_STATE(38)] = 919,
  [SMALL_STATE(39)] = 952,
  [SMALL_STATE(40)] = 970,
  [SMALL_STATE(41)] = 988,
  [SMALL_STATE(42)] = 1004,
  [SMALL_STATE(43)] = 1020,
  [SMALL_STATE(44)] = 1038,
  [SMALL_STATE(45)] = 1064,
  [SMALL_STATE(46)] = 1082,
  [SMALL_STATE(47)] = 1100,
  [SMALL_STATE(48)] = 1118,
  [SMALL_STATE(49)] = 1134,
  [SMALL_STATE(50)] = 1150,
  [SMALL_STATE(51)] = 1166,
  [SMALL_STATE(52)] = 1182,
  [SMALL_STATE(53)] = 1198,
  [SMALL_STATE(54)] = 1216,
  [SMALL_STATE(55)] = 1242,
  [SMALL_STATE(56)] = 1260,
  [SMALL_STATE(57)] = 1278,
  [SMALL_STATE(58)] = 1308,
  [SMALL_STATE(59)] = 1326,
  [SMALL_STATE(60)] = 1344,
  [SMALL_STATE(61)] = 1362,
  [SMALL_STATE(62)] = 1380,
  [SMALL_STATE(63)] = 1398,
  [SMALL_STATE(64)] = 1413,
  [SMALL_STATE(65)] = 1428,
  [SMALL_STATE(66)] = 1443,
  [SMALL_STATE(67)] = 1465,
  [SMALL_STATE(68)] = 1489,
  [SMALL_STATE(69)] = 1511,
  [SMALL_STATE(70)] = 1535,
  [SMALL_STATE(71)] = 1559,
  [SMALL_STATE(72)] = 1583,
  [SMALL_STATE(73)] = 1603,
  [SMALL_STATE(74)] = 1623,
  [SMALL_STATE(75)] = 1645,
  [SMALL_STATE(76)] = 1667,
  [SMALL_STATE(77)] = 1691,
  [SMALL_STATE(78)] = 1711,
  [SMALL_STATE(79)] = 1731,
  [SMALL_STATE(80)] = 1752,
  [SMALL_STATE(81)] = 1773,
  [SMALL_STATE(82)] = 1794,
  [SMALL_STATE(83)] = 1815,
  [SMALL_STATE(84)] = 1828,
  [SMALL_STATE(85)] = 1849,
  [SMALL_STATE(86)] = 1864,
  [SMALL_STATE(87)] = 1885,
  [SMALL_STATE(88)] = 1906,
  [SMALL_STATE(89)] = 1927,
  [SMALL_STATE(90)] = 1948,
  [SMALL_STATE(91)] = 1969,
  [SMALL_STATE(92)] = 1990,
  [SMALL_STATE(93)] = 2011,
  [SMALL_STATE(94)] = 2032,
  [SMALL_STATE(95)] = 2053,
  [SMALL_STATE(96)] = 2066,
  [SMALL_STATE(97)] = 2087,
  [SMALL_STATE(98)] = 2108,
  [SMALL_STATE(99)] = 2129,
  [SMALL_STATE(100)] = 2142,
  [SMALL_STATE(101)] = 2155,
  [SMALL_STATE(102)] = 2176,
  [SMALL_STATE(103)] = 2189,
  [SMALL_STATE(104)] = 2210,
  [SMALL_STATE(105)] = 2231,
  [SMALL_STATE(106)] = 2249,
  [SMALL_STATE(107)] = 2265,
  [SMALL_STATE(108)] = 2285,
  [SMALL_STATE(109)] = 2303,
  [SMALL_STATE(110)] = 2319,
  [SMALL_STATE(111)] = 2335,
  [SMALL_STATE(112)] = 2351,
  [SMALL_STATE(113)] = 2367,
  [SMALL_STATE(114)] = 2385,
  [SMALL_STATE(115)] = 2401,
  [SMALL_STATE(116)] = 2417,
  [SMALL_STATE(117)] = 2433,
  [SMALL_STATE(118)] = 2449,
  [SMALL_STATE(119)] = 2465,
  [SMALL_STATE(120)] = 2483,
  [SMALL_STATE(121)] = 2503,
  [SMALL_STATE(122)] = 2523,
  [SMALL_STATE(123)] = 2539,
  [SMALL_STATE(124)] = 2555,
  [SMALL_STATE(125)] = 2571,
  [SMALL_STATE(126)] = 2587,
  [SMALL_STATE(127)] = 2605,
  [SMALL_STATE(128)] = 2623,
  [SMALL_STATE(129)] = 2641,
  [SMALL_STATE(130)] = 2659,
  [SMALL_STATE(131)] = 2675,
  [SMALL_STATE(132)] = 2689,
  [SMALL_STATE(133)] = 2707,
  [SMALL_STATE(134)] = 2723,
  [SMALL_STATE(135)] = 2741,
  [SMALL_STATE(136)] = 2758,
  [SMALL_STATE(137)] = 2773,
  [SMALL_STATE(138)] = 2788,
  [SMALL_STATE(139)] = 2803,
  [SMALL_STATE(140)] = 2818,
  [SMALL_STATE(141)] = 2829,
  [SMALL_STATE(142)] = 2844,
  [SMALL_STATE(143)] = 2855,
  [SMALL_STATE(144)] = 2870,
  [SMALL_STATE(145)] = 2885,
  [SMALL_STATE(146)] = 2902,
  [SMALL_STATE(147)] = 2917,
  [SMALL_STATE(148)] = 2928,
  [SMALL_STATE(149)] = 2941,
  [SMALL_STATE(150)] = 2956,
  [SMALL_STATE(151)] = 2973,
  [SMALL_STATE(152)] = 2990,
  [SMALL_STATE(153)] = 3003,
  [SMALL_STATE(154)] = 3018,
  [SMALL_STATE(155)] = 3033,
  [SMALL_STATE(156)] = 3048,
  [SMALL_STATE(157)] = 3065,
  [SMALL_STATE(158)] = 3076,
  [SMALL_STATE(159)] = 3089,
  [SMALL_STATE(160)] = 3106,
  [SMALL_STATE(161)] = 3123,
  [SMALL_STATE(162)] = 3138,
  [SMALL_STATE(163)] = 3153,
  [SMALL_STATE(164)] = 3164,
  [SMALL_STATE(165)] = 3175,
  [SMALL_STATE(166)] = 3186,
  [SMALL_STATE(167)] = 3197,
  [SMALL_STATE(168)] = 3212,
  [SMALL_STATE(169)] = 3229,
  [SMALL_STATE(170)] = 3244,
  [SMALL_STATE(171)] = 3261,
  [SMALL_STATE(172)] = 3276,
  [SMALL_STATE(173)] = 3293,
  [SMALL_STATE(174)] = 3310,
  [SMALL_STATE(175)] = 3325,
  [SMALL_STATE(176)] = 3336,
  [SMALL_STATE(177)] = 3351,
  [SMALL_STATE(178)] = 3362,
  [SMALL_STATE(179)] = 3373,
  [SMALL_STATE(180)] = 3388,
  [SMALL_STATE(181)] = 3399,
  [SMALL_STATE(182)] = 3416,
  [SMALL_STATE(183)] = 3433,
  [SMALL_STATE(184)] = 3448,
  [SMALL_STATE(185)] = 3459,
  [SMALL_STATE(186)] = 3474,
  [SMALL_STATE(187)] = 3491,
  [SMALL_STATE(188)] = 3506,
  [SMALL_STATE(189)] = 3523,
  [SMALL_STATE(190)] = 3534,
  [SMALL_STATE(191)] = 3549,
  [SMALL_STATE(192)] = 3560,
  [SMALL_STATE(193)] = 3571,
  [SMALL_STATE(194)] = 3586,
  [SMALL_STATE(195)] = 3601,
  [SMALL_STATE(196)] = 3616,
  [SMALL_STATE(197)] = 3631,
  [SMALL_STATE(198)] = 3646,
  [SMALL_STATE(199)] = 3657,
  [SMALL_STATE(200)] = 3672,
  [SMALL_STATE(201)] = 3687,
  [SMALL_STATE(202)] = 3702,
  [SMALL_STATE(203)] = 3717,
  [SMALL_STATE(204)] = 3728,
  [SMALL_STATE(205)] = 3745,
  [SMALL_STATE(206)] = 3760,
  [SMALL_STATE(207)] = 3777,
  [SMALL_STATE(208)] = 3788,
  [SMALL_STATE(209)] = 3803,
  [SMALL_STATE(210)] = 3818,
  [SMALL_STATE(211)] = 3829,
  [SMALL_STATE(212)] = 3844,
  [SMALL_STATE(213)] = 3855,
  [SMALL_STATE(214)] = 3866,
  [SMALL_STATE(215)] = 3877,
  [SMALL_STATE(216)] = 3888,
  [SMALL_STATE(217)] = 3903,
  [SMALL_STATE(218)] = 3914,
  [SMALL_STATE(219)] = 3929,
  [SMALL_STATE(220)] = 3944,
  [SMALL_STATE(221)] = 3959,
  [SMALL_STATE(222)] = 3974,
  [SMALL_STATE(223)] = 3985,
  [SMALL_STATE(224)] = 4000,
  [SMALL_STATE(225)] = 4011,
  [SMALL_STATE(226)] = 4026,
  [SMALL_STATE(227)] = 4037,
  [SMALL_STATE(228)] = 4052,
  [SMALL_STATE(229)] = 4063,
  [SMALL_STATE(230)] = 4078,
  [SMALL_STATE(231)] = 4089,
  [SMALL_STATE(232)] = 4100,
  [SMALL_STATE(233)] = 4111,
  [SMALL_STATE(234)] = 4126,
  [SMALL_STATE(235)] = 4138,
  [SMALL_STATE(236)] = 4148,
  [SMALL_STATE(237)] = 4158,
  [SMALL_STATE(238)] = 4172,
  [SMALL_STATE(239)] = 4182,
  [SMALL_STATE(240)] = 4196,
  [SMALL_STATE(241)] = 4210,
  [SMALL_STATE(242)] = 4224,
  [SMALL_STATE(243)] = 4238,
  [SMALL_STATE(244)] = 4252,
  [SMALL_STATE(245)] = 4262,
  [SMALL_STATE(246)] = 4276,
  [SMALL_STATE(247)] = 4288,
  [SMALL_STATE(248)] = 4302,
  [SMALL_STATE(249)] = 4316,
  [SMALL_STATE(250)] = 4326,
  [SMALL_STATE(251)] = 4340,
  [SMALL_STATE(252)] = 4352,
  [SMALL_STATE(253)] = 4366,
  [SMALL_STATE(254)] = 4380,
  [SMALL_STATE(255)] = 4392,
  [SMALL_STATE(256)] = 4406,
  [SMALL_STATE(257)] = 4418,
  [SMALL_STATE(258)] = 4430,
  [SMALL_STATE(259)] = 4440,
  [SMALL_STATE(260)] = 4452,
  [SMALL_STATE(261)] = 4462,
  [SMALL_STATE(262)] = 4476,
  [SMALL_STATE(263)] = 4488,
  [SMALL_STATE(264)] = 4502,
  [SMALL_STATE(265)] = 4514,
  [SMALL_STATE(266)] = 4524,
  [SMALL_STATE(267)] = 4538,
  [SMALL_STATE(268)] = 4548,
  [SMALL_STATE(269)] = 4562,
  [SMALL_STATE(270)] = 4572,
  [SMALL_STATE(271)] = 4586,
  [SMALL_STATE(272)] = 4598,
  [SMALL_STATE(273)] = 4610,
  [SMALL_STATE(274)] = 4624,
  [SMALL_STATE(275)] = 4636,
  [SMALL_STATE(276)] = 4646,
  [SMALL_STATE(277)] = 4656,
  [SMALL_STATE(278)] = 4666,
  [SMALL_STATE(279)] = 4676,
  [SMALL_STATE(280)] = 4690,
  [SMALL_STATE(281)] = 4704,
  [SMALL_STATE(282)] = 4714,
  [SMALL_STATE(283)] = 4728,
  [SMALL_STATE(284)] = 4742,
  [SMALL_STATE(285)] = 4756,
  [SMALL_STATE(286)] = 4768,
  [SMALL_STATE(287)] = 4778,
  [SMALL_STATE(288)] = 4788,
  [SMALL_STATE(289)] = 4802,
  [SMALL_STATE(290)] = 4812,
  [SMALL_STATE(291)] = 4822,
  [SMALL_STATE(292)] = 4834,
  [SMALL_STATE(293)] = 4844,
  [SMALL_STATE(294)] = 4856,
  [SMALL_STATE(295)] = 4866,
  [SMALL_STATE(296)] = 4876,
  [SMALL_STATE(297)] = 4890,
  [SMALL_STATE(298)] = 4900,
  [SMALL_STATE(299)] = 4912,
  [SMALL_STATE(300)] = 4926,
  [SMALL_STATE(301)] = 4936,
  [SMALL_STATE(302)] = 4948,
  [SMALL_STATE(303)] = 4962,
  [SMALL_STATE(304)] = 4972,
  [SMALL_STATE(305)] = 4986,
  [SMALL_STATE(306)] = 5000,
  [SMALL_STATE(307)] = 5010,
  [SMALL_STATE(308)] = 5024,
  [SMALL_STATE(309)] = 5038,
  [SMALL_STATE(310)] = 5052,
  [SMALL_STATE(311)] = 5066,
  [SMALL_STATE(312)] = 5080,
  [SMALL_STATE(313)] = 5092,
  [SMALL_STATE(314)] = 5102,
  [SMALL_STATE(315)] = 5116,
  [SMALL_STATE(316)] = 5130,
  [SMALL_STATE(317)] = 5140,
  [SMALL_STATE(318)] = 5154,
  [SMALL_STATE(319)] = 5164,
  [SMALL_STATE(320)] = 5178,
  [SMALL_STATE(321)] = 5192,
  [SMALL_STATE(322)] = 5204,
  [SMALL_STATE(323)] = 5218,
  [SMALL_STATE(324)] = 5232,
  [SMALL_STATE(325)] = 5246,
  [SMALL_STATE(326)] = 5258,
  [SMALL_STATE(327)] = 5272,
  [SMALL_STATE(328)] = 5286,
  [SMALL_STATE(329)] = 5300,
  [SMALL_STATE(330)] = 5312,
  [SMALL_STATE(331)] = 5324,
  [SMALL_STATE(332)] = 5338,
  [SMALL_STATE(333)] = 5348,
  [SMALL_STATE(334)] = 5358,
  [SMALL_STATE(335)] = 5372,
  [SMALL_STATE(336)] = 5386,
  [SMALL_STATE(337)] = 5396,
  [SMALL_STATE(338)] = 5410,
  [SMALL_STATE(339)] = 5422,
  [SMALL_STATE(340)] = 5436,
  [SMALL_STATE(341)] = 5446,
  [SMALL_STATE(342)] = 5460,
  [SMALL_STATE(343)] = 5472,
  [SMALL_STATE(344)] = 5484,
  [SMALL_STATE(345)] = 5496,
  [SMALL_STATE(346)] = 5510,
  [SMALL_STATE(347)] = 5522,
  [SMALL_STATE(348)] = 5536,
  [SMALL_STATE(349)] = 5550,
  [SMALL_STATE(350)] = 5564,
  [SMALL_STATE(351)] = 5578,
  [SMALL_STATE(352)] = 5590,
  [SMALL_STATE(353)] = 5600,
  [SMALL_STATE(354)] = 5610,
  [SMALL_STATE(355)] = 5624,
  [SMALL_STATE(356)] = 5636,
  [SMALL_STATE(357)] = 5650,
  [SMALL_STATE(358)] = 5664,
  [SMALL_STATE(359)] = 5674,
  [SMALL_STATE(360)] = 5688,
  [SMALL_STATE(361)] = 5702,
  [SMALL_STATE(362)] = 5716,
  [SMALL_STATE(363)] = 5726,
  [SMALL_STATE(364)] = 5740,
  [SMALL_STATE(365)] = 5754,
  [SMALL_STATE(366)] = 5764,
  [SMALL_STATE(367)] = 5774,
  [SMALL_STATE(368)] = 5784,
  [SMALL_STATE(369)] = 5796,
  [SMALL_STATE(370)] = 5810,
  [SMALL_STATE(371)] = 5822,
  [SMALL_STATE(372)] = 5836,
  [SMALL_STATE(373)] = 5848,
  [SMALL_STATE(374)] = 5862,
  [SMALL_STATE(375)] = 5876,
  [SMALL_STATE(376)] = 5890,
  [SMALL_STATE(377)] = 5900,
  [SMALL_STATE(378)] = 5914,
  [SMALL_STATE(379)] = 5928,
  [SMALL_STATE(380)] = 5938,
  [SMALL_STATE(381)] = 5950,
  [SMALL_STATE(382)] = 5964,
  [SMALL_STATE(383)] = 5978,
  [SMALL_STATE(384)] = 5992,
  [SMALL_STATE(385)] = 6002,
  [SMALL_STATE(386)] = 6012,
  [SMALL_STATE(387)] = 6024,
  [SMALL_STATE(388)] = 6035,
  [SMALL_STATE(389)] = 6046,
  [SMALL_STATE(390)] = 6055,
  [SMALL_STATE(391)] = 6064,
  [SMALL_STATE(392)] = 6073,
  [SMALL_STATE(393)] = 6082,
  [SMALL_STATE(394)] = 6093,
  [SMALL_STATE(395)] = 6104,
  [SMALL_STATE(396)] = 6113,
  [SMALL_STATE(397)] = 6122,
  [SMALL_STATE(398)] = 6133,
  [SMALL_STATE(399)] = 6142,
  [SMALL_STATE(400)] = 6151,
  [SMALL_STATE(401)] = 6160,
  [SMALL_STATE(402)] = 6169,
  [SMALL_STATE(403)] = 6178,
  [SMALL_STATE(404)] = 6187,
  [SMALL_STATE(405)] = 6196,
  [SMALL_STATE(406)] = 6205,
  [SMALL_STATE(407)] = 6216,
  [SMALL_STATE(408)] = 6227,
  [SMALL_STATE(409)] = 6236,
  [SMALL_STATE(410)] = 6245,
  [SMALL_STATE(411)] = 6256,
  [SMALL_STATE(412)] = 6265,
  [SMALL_STATE(413)] = 6274,
  [SMALL_STATE(414)] = 6283,
  [SMALL_STATE(415)] = 6294,
  [SMALL_STATE(416)] = 6305,
  [SMALL_STATE(417)] = 6316,
  [SMALL_STATE(418)] = 6325,
  [SMALL_STATE(419)] = 6334,
  [SMALL_STATE(420)] = 6345,
  [SMALL_STATE(421)] = 6354,
  [SMALL_STATE(422)] = 6363,
  [SMALL_STATE(423)] = 6372,
  [SMALL_STATE(424)] = 6383,
  [SMALL_STATE(425)] = 6392,
  [SMALL_STATE(426)] = 6401,
  [SMALL_STATE(427)] = 6410,
  [SMALL_STATE(428)] = 6421,
  [SMALL_STATE(429)] = 6430,
  [SMALL_STATE(430)] = 6441,
  [SMALL_STATE(431)] = 6450,
  [SMALL_STATE(432)] = 6459,
  [SMALL_STATE(433)] = 6470,
  [SMALL_STATE(434)] = 6481,
  [SMALL_STATE(435)] = 6490,
  [SMALL_STATE(436)] = 6499,
  [SMALL_STATE(437)] = 6508,
  [SMALL_STATE(438)] = 6519,
  [SMALL_STATE(439)] = 6530,
  [SMALL_STATE(440)] = 6539,
  [SMALL_STATE(441)] = 6550,
  [SMALL_STATE(442)] = 6559,
  [SMALL_STATE(443)] = 6570,
  [SMALL_STATE(444)] = 6579,
  [SMALL_STATE(445)] = 6590,
  [SMALL_STATE(446)] = 6599,
  [SMALL_STATE(447)] = 6610,
  [SMALL_STATE(448)] = 6619,
  [SMALL_STATE(449)] = 6628,
  [SMALL_STATE(450)] = 6639,
  [SMALL_STATE(451)] = 6648,
  [SMALL_STATE(452)] = 6657,
  [SMALL_STATE(453)] = 6666,
  [SMALL_STATE(454)] = 6675,
  [SMALL_STATE(455)] = 6684,
  [SMALL_STATE(456)] = 6693,
  [SMALL_STATE(457)] = 6702,
  [SMALL_STATE(458)] = 6711,
  [SMALL_STATE(459)] = 6720,
  [SMALL_STATE(460)] = 6729,
  [SMALL_STATE(461)] = 6738,
  [SMALL_STATE(462)] = 6747,
  [SMALL_STATE(463)] = 6756,
  [SMALL_STATE(464)] = 6767,
  [SMALL_STATE(465)] = 6776,
  [SMALL_STATE(466)] = 6785,
  [SMALL_STATE(467)] = 6794,
  [SMALL_STATE(468)] = 6803,
  [SMALL_STATE(469)] = 6812,
  [SMALL_STATE(470)] = 6820,
  [SMALL_STATE(471)] = 6828,
  [SMALL_STATE(472)] = 6836,
  [SMALL_STATE(473)] = 6844,
  [SMALL_STATE(474)] = 6852,
  [SMALL_STATE(475)] = 6860,
  [SMALL_STATE(476)] = 6868,
  [SMALL_STATE(477)] = 6876,
  [SMALL_STATE(478)] = 6884,
  [SMALL_STATE(479)] = 6892,
  [SMALL_STATE(480)] = 6900,
  [SMALL_STATE(481)] = 6908,
  [SMALL_STATE(482)] = 6916,
  [SMALL_STATE(483)] = 6924,
  [SMALL_STATE(484)] = 6932,
  [SMALL_STATE(485)] = 6940,
  [SMALL_STATE(486)] = 6948,
  [SMALL_STATE(487)] = 6956,
  [SMALL_STATE(488)] = 6964,
  [SMALL_STATE(489)] = 6972,
  [SMALL_STATE(490)] = 6980,
  [SMALL_STATE(491)] = 6988,
  [SMALL_STATE(492)] = 6996,
  [SMALL_STATE(493)] = 7004,
  [SMALL_STATE(494)] = 7012,
  [SMALL_STATE(495)] = 7020,
  [SMALL_STATE(496)] = 7028,
  [SMALL_STATE(497)] = 7036,
  [SMALL_STATE(498)] = 7044,
  [SMALL_STATE(499)] = 7052,
  [SMALL_STATE(500)] = 7060,
  [SMALL_STATE(501)] = 7068,
  [SMALL_STATE(502)] = 7076,
  [SMALL_STATE(503)] = 7084,
  [SMALL_STATE(504)] = 7092,
  [SMALL_STATE(505)] = 7100,
  [SMALL_STATE(506)] = 7108,
  [SMALL_STATE(507)] = 7116,
  [SMALL_STATE(508)] = 7124,
  [SMALL_STATE(509)] = 7132,
  [SMALL_STATE(510)] = 7140,
  [SMALL_STATE(511)] = 7148,
  [SMALL_STATE(512)] = 7156,
  [SMALL_STATE(513)] = 7164,
  [SMALL_STATE(514)] = 7172,
  [SMALL_STATE(515)] = 7180,
  [SMALL_STATE(516)] = 7188,
  [SMALL_STATE(517)] = 7196,
  [SMALL_STATE(518)] = 7204,
  [SMALL_STATE(519)] = 7212,
  [SMALL_STATE(520)] = 7220,
  [SMALL_STATE(521)] = 7228,
  [SMALL_STATE(522)] = 7236,
  [SMALL_STATE(523)] = 7244,
  [SMALL_STATE(524)] = 7252,
  [SMALL_STATE(525)] = 7260,
  [SMALL_STATE(526)] = 7268,
  [SMALL_STATE(527)] = 7276,
  [SMALL_STATE(528)] = 7284,
  [SMALL_STATE(529)] = 7292,
  [SMALL_STATE(530)] = 7300,
  [SMALL_STATE(531)] = 7308,
  [SMALL_STATE(532)] = 7316,
  [SMALL_STATE(533)] = 7324,
  [SMALL_STATE(534)] = 7332,
  [SMALL_STATE(535)] = 7340,
  [SMALL_STATE(536)] = 7348,
  [SMALL_STATE(537)] = 7356,
  [SMALL_STATE(538)] = 7364,
  [SMALL_STATE(539)] = 7372,
  [SMALL_STATE(540)] = 7380,
  [SMALL_STATE(541)] = 7388,
  [SMALL_STATE(542)] = 7396,
  [SMALL_STATE(543)] = 7404,
  [SMALL_STATE(544)] = 7412,
  [SMALL_STATE(545)] = 7420,
  [SMALL_STATE(546)] = 7428,
  [SMALL_STATE(547)] = 7436,
  [SMALL_STATE(548)] = 7444,
  [SMALL_STATE(549)] = 7452,
  [SMALL_STATE(550)] = 7460,
  [SMALL_STATE(551)] = 7468,
  [SMALL_STATE(552)] = 7476,
  [SMALL_STATE(553)] = 7484,
  [SMALL_STATE(554)] = 7492,
  [SMALL_STATE(555)] = 7500,
  [SMALL_STATE(556)] = 7508,
  [SMALL_STATE(557)] = 7516,
  [SMALL_STATE(558)] = 7524,
  [SMALL_STATE(559)] = 7532,
  [SMALL_STATE(560)] = 7540,
  [SMALL_STATE(561)] = 7548,
  [SMALL_STATE(562)] = 7556,
  [SMALL_STATE(563)] = 7564,
  [SMALL_STATE(564)] = 7572,
  [SMALL_STATE(565)] = 7580,
  [SMALL_STATE(566)] = 7588,
  [SMALL_STATE(567)] = 7596,
  [SMALL_STATE(568)] = 7604,
  [SMALL_STATE(569)] = 7612,
  [SMALL_STATE(570)] = 7620,
  [SMALL_STATE(571)] = 7628,
  [SMALL_STATE(572)] = 7636,
  [SMALL_STATE(573)] = 7644,
  [SMALL_STATE(574)] = 7652,
  [SMALL_STATE(575)] = 7660,
  [SMALL_STATE(576)] = 7668,
  [SMALL_STATE(577)] = 7676,
  [SMALL_STATE(578)] = 7684,
  [SMALL_STATE(579)] = 7692,
  [SMALL_STATE(580)] = 7700,
  [SMALL_STATE(581)] = 7708,
  [SMALL_STATE(582)] = 7716,
  [SMALL_STATE(583)] = 7724,
  [SMALL_STATE(584)] = 7732,
  [SMALL_STATE(585)] = 7740,
  [SMALL_STATE(586)] = 7748,
  [SMALL_STATE(587)] = 7756,
  [SMALL_STATE(588)] = 7764,
  [SMALL_STATE(589)] = 7772,
  [SMALL_STATE(590)] = 7780,
  [SMALL_STATE(591)] = 7788,
  [SMALL_STATE(592)] = 7796,
  [SMALL_STATE(593)] = 7804,
  [SMALL_STATE(594)] = 7812,
  [SMALL_STATE(595)] = 7820,
  [SMALL_STATE(596)] = 7828,
  [SMALL_STATE(597)] = 7836,
  [SMALL_STATE(598)] = 7844,
  [SMALL_STATE(599)] = 7852,
  [SMALL_STATE(600)] = 7860,
  [SMALL_STATE(601)] = 7868,
  [SMALL_STATE(602)] = 7876,
  [SMALL_STATE(603)] = 7884,
  [SMALL_STATE(604)] = 7892,
  [SMALL_STATE(605)] = 7900,
  [SMALL_STATE(606)] = 7908,
  [SMALL_STATE(607)] = 7916,
  [SMALL_STATE(608)] = 7924,
  [SMALL_STATE(609)] = 7932,
  [SMALL_STATE(610)] = 7940,
  [SMALL_STATE(611)] = 7948,
  [SMALL_STATE(612)] = 7956,
  [SMALL_STATE(613)] = 7964,
  [SMALL_STATE(614)] = 7972,
  [SMALL_STATE(615)] = 7980,
  [SMALL_STATE(616)] = 7988,
  [SMALL_STATE(617)] = 7996,
  [SMALL_STATE(618)] = 8004,
  [SMALL_STATE(619)] = 8012,
  [SMALL_STATE(620)] = 8020,
  [SMALL_STATE(621)] = 8028,
  [SMALL_STATE(622)] = 8036,
  [SMALL_STATE(623)] = 8044,
  [SMALL_STATE(624)] = 8052,
  [SMALL_STATE(625)] = 8060,
  [SMALL_STATE(626)] = 8068,
  [SMALL_STATE(627)] = 8076,
  [SMALL_STATE(628)] = 8084,
  [SMALL_STATE(629)] = 8092,
  [SMALL_STATE(630)] = 8100,
  [SMALL_STATE(631)] = 8108,
  [SMALL_STATE(632)] = 8116,
  [SMALL_STATE(633)] = 8124,
  [SMALL_STATE(634)] = 8132,
  [SMALL_STATE(635)] = 8140,
  [SMALL_STATE(636)] = 8148,
  [SMALL_STATE(637)] = 8156,
  [SMALL_STATE(638)] = 8164,
  [SMALL_STATE(639)] = 8172,
  [SMALL_STATE(640)] = 8180,
  [SMALL_STATE(641)] = 8188,
  [SMALL_STATE(642)] = 8196,
  [SMALL_STATE(643)] = 8204,
  [SMALL_STATE(644)] = 8212,
  [SMALL_STATE(645)] = 8220,
  [SMALL_STATE(646)] = 8228,
  [SMALL_STATE(647)] = 8236,
  [SMALL_STATE(648)] = 8244,
  [SMALL_STATE(649)] = 8252,
  [SMALL_STATE(650)] = 8260,
  [SMALL_STATE(651)] = 8268,
  [SMALL_STATE(652)] = 8276,
  [SMALL_STATE(653)] = 8284,
  [SMALL_STATE(654)] = 8292,
  [SMALL_STATE(655)] = 8300,
  [SMALL_STATE(656)] = 8308,
  [SMALL_STATE(657)] = 8316,
  [SMALL_STATE(658)] = 8324,
  [SMALL_STATE(659)] = 8332,
  [SMALL_STATE(660)] = 8340,
  [SMALL_STATE(661)] = 8348,
  [SMALL_STATE(662)] = 8356,
  [SMALL_STATE(663)] = 8364,
  [SMALL_STATE(664)] = 8372,
  [SMALL_STATE(665)] = 8380,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(427),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(394),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(528),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(432),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(392),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(258),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(613),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(514),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(379),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(433),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(576),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(583),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(590),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(488),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(440),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(444),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(608),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(449),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(647),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(663),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(494),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(530),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(154),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(193),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(387),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(397),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(514),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(379),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(433),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(576),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(583),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(590),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(488),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(440),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(444),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(608),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(449),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(647),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(663),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(494),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(530),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(387),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(397),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 6),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 6),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 48),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 48),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(427),
  [214] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(394),
  [217] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(528),
  [220] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [223] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(432),
  [226] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(392),
  [229] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(258),
  [232] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(613),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(493),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(493),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(461),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(389),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [269] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(461),
  [272] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(358),
  [275] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(362),
  [278] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(365),
  [281] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(366),
  [284] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(367),
  [287] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(389),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(390),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(468),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(639),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(468),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(557),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 27),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 26),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [336] = {.entry = {.count = 1, .reusable = false}}, SHIFT(334),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 29),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 29),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(599),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [350] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 38),
  [354] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 38),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 23),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 41),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 40),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 42),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 43),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 44),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 44),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(594),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(594),
  [388] = {.entry = {.count = 1, .reusable = false}}, SHIFT(445),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [394] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [402] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [406] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 27),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 26),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [422] = {.entry = {.count = 1, .reusable = false}}, SHIFT(577),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(577),
  [428] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [430] = {.entry = {.count = 1, .reusable = false}}, SHIFT(216),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 24),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(614),
  [436] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [441] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(456),
  [444] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(460),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(445),
  [451] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [455] = {.entry = {.count = 1, .reusable = false}}, SHIFT(456),
  [457] = {.entry = {.count = 1, .reusable = false}}, SHIFT(460),
  [459] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 45),
  [461] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 45), SHIFT_REPEAT(85),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 45),
  [466] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 29),
  [468] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 29),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 11),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(376),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [478] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 44),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 44),
  [482] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [486] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(599),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(532),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(489),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(516),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(524),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 2, 0, 0),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(550),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [523] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 28),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 28),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(441),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(495),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(452),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(491),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(458),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(409),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(412),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(384),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(643),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(385),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(660),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(405),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(430),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(592),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(634),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(442),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(443),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 11),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(512),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(490),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(498),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(644),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(407),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(623),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(624),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(523),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [643] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 39),
  [645] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 39), SHIFT_REPEAT(442),
  [648] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 39), SHIFT_REPEAT(443),
  [651] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 39), SHIFT_REPEAT(336),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 24),
  [656] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [658] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(614),
  [661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [663] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(445),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(510),
  [668] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(475),
  [676] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 95),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 95),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [682] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 25), SHIFT_REPEAT(140),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 25),
  [687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(539),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(513),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(636),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 10),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(547),
  [713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(374),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(537),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(473),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(398),
  [735] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [737] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(396),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(476),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(484),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(551),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(404),
  [757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_camera, 1, 0, 0),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(500),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(568),
  [765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(479),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(515),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(381),
  [773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(496),
  [781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(508),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(511),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(533),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 30),
  [793] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [795] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [797] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 31),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(518),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(534),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(536),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(538),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(545),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(548),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(471),
  [823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(578),
  [829] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 59),
  [831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 60),
  [833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(588),
  [837] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 2, 0, 0),
  [839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(607),
  [843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(558),
  [847] = {.entry = {.count = 1, .reusable = true}}, SHIFT(561),
  [849] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(628),
  [853] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [855] = {.entry = {.count = 1, .reusable = true}}, SHIFT(570),
  [857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(574),
  [863] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 30),
  [865] = {.entry = {.count = 1, .reusable = true}}, SHIFT(637),
  [867] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 46),
  [869] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 31),
  [871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(595),
  [873] = {.entry = {.count = 1, .reusable = true}}, SHIFT(665),
  [875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(582),
  [877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(586),
  [879] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [881] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 4, 0, 0),
  [883] = {.entry = {.count = 1, .reusable = true}}, SHIFT(600),
  [885] = {.entry = {.count = 1, .reusable = true}}, SHIFT(601),
  [887] = {.entry = {.count = 1, .reusable = true}}, SHIFT(611),
  [889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(612),
  [891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(615),
  [897] = {.entry = {.count = 1, .reusable = true}}, SHIFT(617),
  [899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(619),
  [903] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(625),
  [907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(626),
  [909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 6, 0, 46),
  [911] = {.entry = {.count = 1, .reusable = true}}, SHIFT(606),
  [913] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 30),
  [915] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 0),
  [917] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 85),
  [921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(560),
  [923] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 5, 0, 87),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(462),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(633),
  [929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(652),
  [931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(653),
  [933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 30),
  [935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(501),
  [937] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 101),
  [939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [941] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 85),
  [943] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 87),
  [945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [947] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 6, 0, 102),
  [949] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 101),
  [951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_polygon_identifier_expansion, 7, 0, 102),
  [953] = {.entry = {.count = 1, .reusable = true}}, SHIFT(572),
  [955] = {.entry = {.count = 1, .reusable = true}}, SHIFT(431),
  [957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [959] = {.entry = {.count = 1, .reusable = true}}, SHIFT(451),
  [961] = {.entry = {.count = 1, .reusable = true}}, SHIFT(429),
  [963] = {.entry = {.count = 1, .reusable = true}}, SHIFT(531),
  [965] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [967] = {.entry = {.count = 1, .reusable = true}}, SHIFT(388),
  [969] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [971] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(454),
  [975] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [978] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(416),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(483),
  [984] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 32), SHIFT_REPEAT(380),
  [987] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 32),
  [989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(635),
  [991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [993] = {.entry = {.count = 1, .reusable = true}}, SHIFT(589),
  [995] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [997] = {.entry = {.count = 1, .reusable = true}}, SHIFT(420),
  [999] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 34), SHIFT_REPEAT(113),
  [1002] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 34),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [1006] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [1008] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(300),
  [1011] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(422),
  [1015] = {.entry = {.count = 1, .reusable = true}}, SHIFT(497),
  [1017] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [1019] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [1021] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [1025] = {.entry = {.count = 1, .reusable = true}}, SHIFT(400),
  [1027] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(424),
  [1030] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [1032] = {.entry = {.count = 1, .reusable = true}}, SHIFT(502),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [1036] = {.entry = {.count = 1, .reusable = true}}, SHIFT(505),
  [1038] = {.entry = {.count = 1, .reusable = true}}, SHIFT(419),
  [1040] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [1042] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [1044] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [1046] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 2, 0, 0),
  [1048] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(378),
  [1058] = {.entry = {.count = 1, .reusable = true}}, SHIFT(425),
  [1060] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1062] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [1064] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out, 1, 0, 0),
  [1066] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 32), SHIFT_REPEAT(126),
  [1069] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 32),
  [1071] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [1073] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [1075] = {.entry = {.count = 1, .reusable = true}}, SHIFT(522),
  [1077] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [1079] = {.entry = {.count = 1, .reusable = true}}, SHIFT(525),
  [1081] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [1085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [1087] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [1091] = {.entry = {.count = 1, .reusable = true}}, SHIFT(526),
  [1093] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [1095] = {.entry = {.count = 1, .reusable = true}}, SHIFT(529),
  [1097] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [1099] = {.entry = {.count = 1, .reusable = true}}, SHIFT(542),
  [1101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [1103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [1105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [1107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [1109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [1111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(562),
  [1113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(573),
  [1116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0),
  [1118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(541),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [1126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [1128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(481),
  [1130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(555),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [1136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(487),
  [1138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [1140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(388),
  [1143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [1145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [1147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [1149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(434),
  [1152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [1154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(564),
  [1156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(435),
  [1159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [1161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(544),
  [1163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [1165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(567),
  [1167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [1169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [1171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [1173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [1175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(399),
  [1177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [1181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [1183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(563),
  [1185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [1187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(474),
  [1189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(566),
  [1193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(439),
  [1195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(591),
  [1197] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(343),
  [1200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0),
  [1202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [1204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(580),
  [1206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [1208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(584),
  [1212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(480),
  [1214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [1216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(436),
  [1221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [1223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [1225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [1227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [1229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [1231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [1233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(622),
  [1235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [1237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [1239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(506),
  [1241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [1243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [1245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(603),
  [1247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(605),
  [1249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [1251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(447),
  [1253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(363),
  [1255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(609),
  [1257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(632),
  [1259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [1261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [1263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(403),
  [1265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 75),
  [1267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [1269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [1271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(581),
  [1273] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [1276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0),
  [1278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(438),
  [1280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(556),
  [1282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [1284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(621),
  [1286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(450),
  [1288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [1290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 23),
  [1292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(585),
  [1296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(627),
  [1298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(453),
  [1300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(370),
  [1302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(631),
  [1304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(455),
  [1306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(372),
  [1308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [1310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [1312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(391),
  [1314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [1316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [1318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [1320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [1322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(638),
  [1324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [1326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [1328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [1330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [1332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(655),
  [1334] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 86), SHIFT_REPEAT(227),
  [1337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 2, 0, 86),
  [1339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 17),
  [1341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [1343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [1347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(646),
  [1349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(383),
  [1351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(648),
  [1353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [1355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(650),
  [1357] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 92), SHIFT_REPEAT(463),
  [1360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 92),
  [1362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [1364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [1368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(654),
  [1370] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(464),
  [1373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0),
  [1375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(656),
  [1377] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(465),
  [1380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [1382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(658),
  [1384] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(466),
  [1387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [1389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 18),
  [1391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 17),
  [1393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [1395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [1397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(411),
  [1399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [1401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [1403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(446),
  [1405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [1407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(448),
  [1409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [1411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(618),
  [1413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(664),
  [1415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(477),
  [1417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [1419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(597),
  [1421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(640),
  [1423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(649),
  [1425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [1427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 3, 0, 12),
  [1429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(415),
  [1431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [1433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [1435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(593),
  [1437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [1439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [1441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(651),
  [1443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(410),
  [1445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0),
  [1447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 0),
  [1449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 12),
  [1451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 12),
  [1453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 33),
  [1455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [1457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [1459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [1461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [1463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 3, 0, 19),
  [1465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [1469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 30),
  [1471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [1473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1475] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 61),
  [1477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 6, 0, 47),
  [1479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 4, 0, 30),
  [1481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [1483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(428),
  [1487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 64),
  [1489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [1491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [1493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 3, 0, 30),
  [1495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(569),
  [1497] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 7, 0, 61),
  [1499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 87),
  [1501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(470),
  [1503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(472),
  [1505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [1507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [1509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [1511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(437),
  [1513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [1515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(486),
  [1521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(393),
  [1523] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 2, 0, 72),
  [1525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 30),
  [1527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [1529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [1531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 3, 0, 30),
  [1533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 0),
  [1535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 47),
  [1537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [1539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 3, 0, 0),
  [1541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 33),
  [1543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 3, 0, 0),
  [1545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [1547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_complex_duration_expansion_repeat1, 3, 0, 90),
  [1551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_polygon_identifier_expansion_repeat1, 4, 0, 30),
  [1553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 53),
  [1555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(517),
  [1557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [1559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(521),
  [1561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 6, 0, 46),
  [1563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 31),
  [1565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 13),
  [1567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 6, 0, 62),
  [1569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(554),
  [1571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 26),
  [1573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 5, 0, 50),
  [1575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [1577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(504),
  [1579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 0),
  [1581] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 3, 0, 0),
  [1583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 63),
  [1585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 26),
  [1587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [1589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [1591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [1593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(482),
  [1595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 3, 0, 21),
  [1597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(457),
  [1599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 0),
  [1601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(519),
  [1605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [1607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 51),
  [1609] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1611] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 3, 0, 21),
  [1613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 0),
  [1615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1617] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 14),
  [1619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 2, 0, 0),
  [1621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [1623] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 65),
  [1625] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 6, 0, 66),
  [1627] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [1629] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 67),
  [1633] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 0),
  [1635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 35),
  [1637] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 68),
  [1639] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 35),
  [1641] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 2, 0, 0),
  [1643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1645] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 30),
  [1647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(527),
  [1649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [1651] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 4, 0, 0),
  [1653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [1655] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 3, 0, 22),
  [1657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [1659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [1663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [1665] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(596),
  [1669] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 22),
  [1671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1673] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [1675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [1677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 4, 0, 0),
  [1679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(492),
  [1681] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 15),
  [1683] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 69),
  [1685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 52),
  [1687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 70),
  [1689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 36),
  [1691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 71),
  [1693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [1695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 22),
  [1697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(630),
  [1699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 3, 0, 72),
  [1701] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 3, 0, 0),
  [1703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [1705] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 73),
  [1707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 56),
  [1709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [1711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 74),
  [1713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 6, 0, 57),
  [1715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [1717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 37),
  [1719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 4, 0, 0),
  [1721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 76),
  [1723] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 7, 0, 77),
  [1725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [1727] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 4, 0, 0),
  [1729] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 78),
  [1731] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 26),
  [1733] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 16),
  [1735] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 79),
  [1737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1739] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 3, 0, 0),
  [1741] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 0),
  [1745] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [1747] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 3, 0, 0),
  [1749] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 8),
  [1751] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 5, 0, 0),
  [1753] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 80),
  [1755] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 65),
  [1757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 81),
  [1759] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 82),
  [1761] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 66),
  [1763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(629),
  [1765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [1767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [1769] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 0),
  [1771] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 3, 0, 0),
  [1775] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade, 7, 0, 83),
  [1777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(641),
  [1779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1781] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [1783] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 7, 0, 84),
  [1785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [1787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [1789] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(642),
  [1793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(319),
  [1795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(459),
  [1797] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 2, 0, 0),
  [1799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1801] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 8),
  [1803] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 52),
  [1805] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 53),
  [1807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [1809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(661),
  [1811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 88),
  [1813] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 89),
  [1815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1817] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 90),
  [1819] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 0),
  [1821] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 72),
  [1823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 30),
  [1825] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 54),
  [1827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [1829] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 4, 0, 91),
  [1831] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 22),
  [1833] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 93),
  [1835] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 7, 0, 94),
  [1837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [1839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(587),
  [1841] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 96),
  [1843] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 76),
  [1845] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 97),
  [1847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 46),
  [1849] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 98),
  [1851] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 77),
  [1853] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 4, 0, 0),
  [1855] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 2, 0, 0),
  [1857] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 3, 0, 20),
  [1859] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 3, 0, 19),
  [1861] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 99),
  [1863] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 8, 0, 100),
  [1865] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [1867] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 55),
  [1869] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [1871] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 56),
  [1873] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [1875] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 57),
  [1877] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 31),
  [1879] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 3, 0, 19),
  [1881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(413),
  [1883] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 14),
  [1885] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 5, 0, 58),
  [1887] = {.entry = {.count = 1, .reusable = true}}, SHIFT(467),
  [1889] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 5, 0, 0),
  [1891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [1893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [1895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1897] = {.entry = {.count = 1, .reusable = true}}, SHIFT(478),
  [1899] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 5, 0, 49),
  [1901] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 5, 0, 26),
  [1903] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 90),
  [1905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [1907] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 103),
  [1909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [1911] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 5, 0, 91),
  [1913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [1915] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 104),
  [1917] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_move_over_time, 9, 0, 105),
  [1919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 5, 0, 0),
  [1921] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [1923] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [1925] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 17),
  [1927] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [1929] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 18),
  [1931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [1933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [1935] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 17),
  [1937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [1939] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_complex_duration_expansion, 6, 0, 103),
  [1941] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 5, 0, 0),
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
