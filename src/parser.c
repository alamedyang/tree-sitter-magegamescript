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
#define STATE_COUNT 354
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 166
#define ALIAS_COUNT 2
#define TOKEN_COUNT 78
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 35
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 49

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
  anon_sym_pause = 67,
  anon_sym_unpause = 68,
  anon_sym_player = 69,
  anon_sym_self = 70,
  anon_sym_camera = 71,
  anon_sym_fade = 72,
  anon_sym_DASH_GT = 73,
  anon_sym_over = 74,
  anon_sym_in = 75,
  anon_sym_out = 76,
  anon_sym_shake = 77,
  sym_source_file = 78,
  sym_bareword_expansion = 79,
  sym_quoted_string_expansion = 80,
  sym_string_expansion = 81,
  sym_number_expansion = 82,
  sym_duration_expansion = 83,
  sym_distance_expansion = 84,
  sym_color_expansion = 85,
  sym_constant_expansion = 86,
  sym_constant_value_expansion = 87,
  sym__root = 88,
  sym_include_macro = 89,
  sym_constant_assignment = 90,
  sym_add_serial_dialog_settings = 91,
  sym_serial_dialog_parameter = 92,
  sym_add_dialog_settings = 93,
  sym_dialog_settings_block = 94,
  sym_dialog_parameter = 95,
  sym_dialog_definition = 96,
  sym_dialog_block = 97,
  sym_dialog = 98,
  sym_dialog_identifier = 99,
  sym_dialog_option = 100,
  sym_serial_dialog_definition = 101,
  sym_serial_dialog_block = 102,
  sym_serial_dialog = 103,
  sym_serial_dialog_option = 104,
  sym_script_definition = 105,
  sym_script_block = 106,
  sym__script_item = 107,
  sym_json_literal = 108,
  sym_json_array = 109,
  sym_json_object = 110,
  sym_json_name_value_pair = 111,
  sym__json_item = 112,
  sym_label = 113,
  sym_debug_macro = 114,
  sym_rand_macro = 115,
  sym_spread_macro = 116,
  sym__action_item = 117,
  sym_action_load_map = 118,
  sym_action_run_script = 119,
  sym_action_goto_label = 120,
  sym_action_goto_index = 121,
  sym_action_show_dialog = 122,
  sym_action_show_serial_dialog = 123,
  sym_action_concat_serial_dialog = 124,
  sym_action_delete_command = 125,
  sym_action_delete_command_arg = 126,
  sym_action_delete_alias = 127,
  sym_action_hide_command = 128,
  sym_action_unhide_command = 129,
  sym_action_save_slot = 130,
  sym_action_load_slot = 131,
  sym_action_erase_slot = 132,
  sym_action_blocking_delay = 133,
  sym_action_non_blocking_delay = 134,
  sym_action_close_dialog = 135,
  sym_action_close_serial_dialog = 136,
  sym_action_pause_script = 137,
  sym_action_unpause_script = 138,
  sym__map_or_entity_script = 139,
  sym_action_camera_fade = 140,
  sym_in_or_out = 141,
  sym_in_or_out_expansion = 142,
  sym_action_camera_shake = 143,
  aux_sym_source_file_repeat1 = 144,
  aux_sym_bareword_expansion_repeat1 = 145,
  aux_sym_quoted_string_expansion_repeat1 = 146,
  aux_sym_string_expansion_repeat1 = 147,
  aux_sym_number_expansion_repeat1 = 148,
  aux_sym_duration_expansion_repeat1 = 149,
  aux_sym_distance_expansion_repeat1 = 150,
  aux_sym_color_expansion_repeat1 = 151,
  aux_sym_constant_expansion_repeat1 = 152,
  aux_sym_constant_value_expansion_repeat1 = 153,
  aux_sym_add_serial_dialog_settings_repeat1 = 154,
  aux_sym_add_dialog_settings_repeat1 = 155,
  aux_sym_dialog_settings_block_repeat1 = 156,
  aux_sym_dialog_block_repeat1 = 157,
  aux_sym_dialog_repeat1 = 158,
  aux_sym_dialog_repeat2 = 159,
  aux_sym_serial_dialog_repeat1 = 160,
  aux_sym_serial_dialog_repeat2 = 161,
  aux_sym_script_block_repeat1 = 162,
  aux_sym_json_array_repeat1 = 163,
  aux_sym_json_object_repeat1 = 164,
  aux_sym_in_or_out_expansion_repeat1 = 165,
  alias_sym_entity_settings = 166,
  alias_sym_label_settings = 167,
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
  [anon_sym_pause] = "pause",
  [anon_sym_unpause] = "unpause",
  [anon_sym_player] = "player",
  [anon_sym_self] = "self",
  [anon_sym_camera] = "camera",
  [anon_sym_fade] = "fade",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_over] = "over",
  [anon_sym_in] = "in",
  [anon_sym_out] = "out",
  [anon_sym_shake] = "shake",
  [sym_source_file] = "source_file",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_duration_expansion] = "duration_expansion",
  [sym_distance_expansion] = "distance_expansion",
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
  [sym_action_pause_script] = "action_pause_script",
  [sym_action_unpause_script] = "action_unpause_script",
  [sym__map_or_entity_script] = "_map_or_entity_script",
  [sym_action_camera_fade] = "action_camera_fade",
  [sym_in_or_out] = "in_or_out",
  [sym_in_or_out_expansion] = "in_or_out_expansion",
  [sym_action_camera_shake] = "action_camera_shake",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
  [aux_sym_distance_expansion_repeat1] = "distance_expansion_repeat1",
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
  [aux_sym_in_or_out_expansion_repeat1] = "in_or_out_expansion_repeat1",
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
  [anon_sym_pause] = anon_sym_pause,
  [anon_sym_unpause] = anon_sym_unpause,
  [anon_sym_player] = anon_sym_player,
  [anon_sym_self] = anon_sym_self,
  [anon_sym_camera] = anon_sym_camera,
  [anon_sym_fade] = anon_sym_fade,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_over] = anon_sym_over,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_out] = anon_sym_out,
  [anon_sym_shake] = anon_sym_shake,
  [sym_source_file] = sym_source_file,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym_distance_expansion] = sym_distance_expansion,
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
  [sym_action_pause_script] = sym_action_pause_script,
  [sym_action_unpause_script] = sym_action_unpause_script,
  [sym__map_or_entity_script] = sym__map_or_entity_script,
  [sym_action_camera_fade] = sym_action_camera_fade,
  [sym_in_or_out] = sym_in_or_out,
  [sym_in_or_out_expansion] = sym_in_or_out_expansion,
  [sym_action_camera_shake] = sym_action_camera_shake,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
  [aux_sym_distance_expansion_repeat1] = aux_sym_distance_expansion_repeat1,
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
  [aux_sym_in_or_out_expansion_repeat1] = aux_sym_in_or_out_expansion_repeat1,
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
  [anon_sym_pause] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unpause] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_player] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_self] = {
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
  [sym_action_pause_script] = {
    .visible = true,
    .named = true,
  },
  [sym_action_unpause_script] = {
    .visible = true,
    .named = true,
  },
  [sym__map_or_entity_script] = {
    .visible = false,
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
  [aux_sym_in_or_out_expansion_repeat1] = {
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
  field_argument = 4,
  field_border_tileset = 5,
  field_color = 6,
  field_command = 7,
  field_dialog_name = 8,
  field_distance = 9,
  field_duration = 10,
  field_emote = 11,
  field_entity = 12,
  field_entity_script = 13,
  field_fade = 14,
  field_fileName = 15,
  field_index = 16,
  field_label = 17,
  field_map = 18,
  field_map_script = 19,
  field_message = 20,
  field_name = 21,
  field_option_type = 22,
  field_player_script = 23,
  field_portrait = 24,
  field_property = 25,
  field_script = 26,
  field_script_name = 27,
  field_self_script = 28,
  field_serial_dialog_name = 29,
  field_serial_message = 30,
  field_slot = 31,
  field_target_entity = 32,
  field_target_label = 33,
  field_value = 34,
  field_wrap = 35,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_alignment] = "alignment",
  [field_amplitude] = "amplitude",
  [field_argument] = "argument",
  [field_border_tileset] = "border_tileset",
  [field_color] = "color",
  [field_command] = "command",
  [field_dialog_name] = "dialog_name",
  [field_distance] = "distance",
  [field_duration] = "duration",
  [field_emote] = "emote",
  [field_entity] = "entity",
  [field_entity_script] = "entity_script",
  [field_fade] = "fade",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_map_script] = "map_script",
  [field_message] = "message",
  [field_name] = "name",
  [field_option_type] = "option_type",
  [field_player_script] = "player_script",
  [field_portrait] = "portrait",
  [field_property] = "property",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_self_script] = "self_script",
  [field_serial_dialog_name] = "serial_dialog_name",
  [field_serial_message] = "serial_message",
  [field_slot] = "slot",
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
  [9] = {.index = 8, .length = 5},
  [10] = {.index = 13, .length = 2},
  [11] = {.index = 15, .length = 1},
  [12] = {.index = 16, .length = 1},
  [13] = {.index = 17, .length = 1},
  [14] = {.index = 18, .length = 1},
  [15] = {.index = 19, .length = 1},
  [16] = {.index = 20, .length = 1},
  [17] = {.index = 21, .length = 1},
  [18] = {.index = 22, .length = 1},
  [19] = {.index = 23, .length = 1},
  [20] = {.index = 24, .length = 1},
  [21] = {.index = 25, .length = 1},
  [22] = {.index = 26, .length = 1},
  [23] = {.index = 27, .length = 1},
  [24] = {.index = 28, .length = 1},
  [25] = {.index = 29, .length = 1},
  [26] = {.index = 30, .length = 2},
  [27] = {.index = 32, .length = 1},
  [28] = {.index = 33, .length = 1},
  [29] = {.index = 34, .length = 1},
  [30] = {.index = 35, .length = 1},
  [31] = {.index = 36, .length = 2},
  [32] = {.index = 38, .length = 2},
  [33] = {.index = 40, .length = 4},
  [34] = {.index = 44, .length = 1},
  [35] = {.index = 45, .length = 1},
  [36] = {.index = 46, .length = 1},
  [37] = {.index = 47, .length = 1},
  [38] = {.index = 48, .length = 1},
  [39] = {.index = 49, .length = 2},
  [40] = {.index = 51, .length = 1},
  [41] = {.index = 52, .length = 2},
  [42] = {.index = 54, .length = 1},
  [43] = {.index = 55, .length = 1},
  [44] = {.index = 56, .length = 2},
  [45] = {.index = 58, .length = 3},
  [46] = {.index = 61, .length = 3},
  [47] = {.index = 64, .length = 3},
  [48] = {.index = 67, .length = 2},
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
    {field_entity, 1, .inherited = true},
    {field_entity_script, 1, .inherited = true},
    {field_map_script, 1, .inherited = true},
    {field_player_script, 1, .inherited = true},
    {field_self_script, 1, .inherited = true},
  [13] =
    {field_label, 0},
    {field_value, 2},
  [15] =
    {field_serial_message, 0},
  [16] =
    {field_serial_message, 0, .inherited = true},
  [17] =
    {field_map, 2},
  [18] =
    {field_slot, 2},
  [19] =
    {field_label, 2},
  [20] =
    {field_index, 2},
  [21] =
    {field_serial_dialog_name, 2},
  [22] =
    {field_dialog_name, 2},
  [23] =
    {field_command, 2},
  [24] =
    {field_alias, 2},
  [25] =
    {field_map_script, 1},
  [26] =
    {field_player_script, 1},
  [27] =
    {field_self_script, 1},
  [28] =
    {field_wrap, 1},
  [29] =
    {field_serial_message, 1, .inherited = true},
  [30] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [32] =
    {field_entity, 1},
  [33] =
    {field_name, 1},
  [34] =
    {field_message, 0},
  [35] =
    {field_message, 1, .inherited = true},
  [36] =
    {field_entity, 1},
    {field_entity_script, 2},
  [38] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [40] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [44] =
    {field_portrait, 1},
  [45] =
    {field_alignment, 1},
  [46] =
    {field_border_tileset, 1},
  [47] =
    {field_emote, 1},
  [48] =
    {field_message, 2, .inherited = true},
  [49] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [51] =
    {field_dialog_name, 3},
  [52] =
    {field_argument, 4},
    {field_command, 2},
  [54] =
    {field_target_label, 1},
  [55] =
    {field_target_entity, 1},
  [56] =
    {field_property, 0},
    {field_value, 2},
  [58] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [61] =
    {field_color, 4},
    {field_duration, 6},
    {field_fade, 2},
  [64] =
    {field_amplitude, 3},
    {field_distance, 4},
    {field_duration, 6},
  [67] =
    {field_label, 1},
    {field_script, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [42] = {
    [2] = alias_sym_label_settings,
  },
  [43] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(247);
      ADVANCE_MAP(
        '!', 466,
        '"', 7,
        '#', 453,
        '$', 244,
        '(', 467,
        ')', 468,
        '+', 489,
        ',', 410,
        '-', 14,
        '/', 10,
        ':', 458,
        ';', 427,
        '=', 428,
        '>', 451,
        'I', 154,
        '[', 409,
        ']', 411,
        '_', 452,
        'a', 55,
        'b', 133,
        'c', 18,
        'd', 69,
        'e', 149,
        'f', 28,
        'g', 170,
        'h', 117,
        'i', 155,
        'j', 196,
        'l', 19,
        'm', 20,
        'n', 43,
        'o', 156,
        'p', 21,
        'r', 33,
        's', 22,
        't', 111,
        'u', 157,
        'w', 34,
        'y', 99,
        '{', 434,
        '}', 435,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(413);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(249);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 7,
        '#', 241,
        '$', 244,
        '+', 489,
        '/', 10,
        ';', 427,
        '[', 409,
        ']', 411,
        'b', 338,
        'c', 343,
        'f', 264,
        'g', 378,
        'm', 262,
        'o', 315,
        'r', 310,
        't', 320,
        'w', 321,
        'y', 307,
        '{', 434,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(413);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(244);
      if (lookahead == ')') ADVANCE(468);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == 'w') ADVANCE(377);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 7,
        '$', 244,
        '/', 10,
        ';', 427,
        '>', 451,
        '[', 409,
        ']', 411,
        'e', 356,
        'n', 269,
        '}', 435,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(418);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(244);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == '[') ADVANCE(409);
      if (lookahead == 'i') ADVANCE(357);
      if (lookahead == 'l') ADVANCE(256);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '"', 7,
        ')', 468,
        '-', 15,
        '/', 10,
        'I', 154,
        '[', 409,
        ']', 411,
        'f', 41,
        'i', 161,
        'n', 223,
        'o', 225,
        't', 184,
        '{', 434,
        '}', 435,
        '#', 452,
        '_', 452,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(412);
      if (lookahead == '\\') ADVANCE(245);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '#', 241,
        '$', 244,
        '/', 10,
        '[', 409,
        ']', 411,
        'b', 136,
        'c', 239,
        'g', 183,
        'm', 39,
        'r', 93,
        'w', 112,
        'y', 99,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        '$', 244,
        ')', 468,
        ',', 410,
        '/', 10,
        '[', 409,
        ']', 411,
        'b', 340,
        'c', 253,
        'd', 294,
        'e', 372,
        'g', 363,
        'h', 327,
        'j', 380,
        'l', 367,
        'p', 257,
        'r', 259,
        's', 254,
        'u', 350,
        'w', 261,
        '}', 435,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(416);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(248);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 14:
      if (lookahead == '>') ADVANCE(515);
      if (lookahead == 'I') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      END_STATE();
    case 16:
      if (lookahead == '_') ADVANCE(65);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(216);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(152);
      if (lookahead == 'l') ADVANCE(173);
      if (lookahead == 'o') ADVANCE(148);
      if (lookahead == 'y') ADVANCE(36);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(110);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(230);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(186);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(232);
      if (lookahead == 'c') ADVANCE(187);
      if (lookahead == 'e') ADVANCE(137);
      if (lookahead == 'h') ADVANCE(25);
      if (lookahead == 'l') ADVANCE(177);
      if (lookahead == 'p') ADVANCE(190);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(240);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(420);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(132);
      if (lookahead == 'o') ADVANCE(234);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(178);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(512);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(140);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == 'u') ADVANCE(71);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(71);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(59);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(163);
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead == 'h') ADVANCE(121);
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(194);
      if (lookahead == 'g') ADVANCE(167);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(158);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(226);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(109);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(138);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(147);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(206);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(150);
      if (lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(198);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(164);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(127);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(231);
      END_STATE();
    case 49:
      if (lookahead == 'b') ADVANCE(224);
      if (lookahead == 'f') ADVANCE(38);
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 50:
      if (lookahead == 'b') ADVANCE(89);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(130);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(131);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(70);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead == 'l') ADVANCE(115);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(429);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(420);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(420);
      if (lookahead == 't') ADVANCE(227);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(475);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(469);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(471);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(488);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(72);
      if (lookahead == 'l') ADVANCE(199);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(73);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(128);
      END_STATE();
    case 66:
      if (lookahead == 'd') ADVANCE(84);
      END_STATE();
    case 67:
      if (lookahead == 'd') ADVANCE(85);
      END_STATE();
    case 68:
      if (lookahead == 'd') ADVANCE(95);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(49);
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(419);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(420);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(514);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(491);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(445);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(495);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(461);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(504);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(450);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(498);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(462);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(506);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(520);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(486);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(493);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(425);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(508);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(236);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(158);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(135);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(165);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(182);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(146);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(219);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(166);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(202);
      END_STATE();
    case 103:
      if (lookahead == 'f') ADVANCE(511);
      END_STATE();
    case 104:
      if (lookahead == 'f') ADVANCE(119);
      END_STATE();
    case 105:
      if (lookahead == 'g') ADVANCE(464);
      END_STATE();
    case 106:
      if (lookahead == 'g') ADVANCE(438);
      END_STATE();
    case 107:
      if (lookahead == 'g') ADVANCE(431);
      END_STATE();
    case 108:
      if (lookahead == 'g') ADVANCE(195);
      END_STATE();
    case 109:
      if (lookahead == 'g') ADVANCE(94);
      END_STATE();
    case 110:
      if (lookahead == 'g') ADVANCE(94);
      if (lookahead == 'p') ADVANCE(477);
      END_STATE();
    case 111:
      if (lookahead == 'h') ADVANCE(185);
      if (lookahead == 'r') ADVANCE(228);
      if (lookahead == 'w') ADVANCE(114);
      END_STATE();
    case 112:
      if (lookahead == 'h') ADVANCE(121);
      END_STATE();
    case 113:
      if (lookahead == 'h') ADVANCE(129);
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 114:
      if (lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 115:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(235);
      if (lookahead == 'x') ADVANCE(417);
      END_STATE();
    case 117:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 118:
      if (lookahead == 'i') ADVANCE(179);
      END_STATE();
    case 119:
      if (lookahead == 'i') ADVANCE(168);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(205);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(214);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(145);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(212);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(162);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(213);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(209);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 130:
      if (lookahead == 'k') ADVANCE(420);
      END_STATE();
    case 131:
      if (lookahead == 'k') ADVANCE(500);
      END_STATE();
    case 132:
      if (lookahead == 'k') ADVANCE(82);
      END_STATE();
    case 133:
      if (lookahead == 'l') ADVANCE(30);
      if (lookahead == 'o') ADVANCE(192);
      END_STATE();
    case 134:
      if (lookahead == 'l') ADVANCE(463);
      END_STATE();
    case 135:
      if (lookahead == 'l') ADVANCE(441);
      END_STATE();
    case 136:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 137:
      if (lookahead == 'l') ADVANCE(103);
      if (lookahead == 'r') ADVANCE(125);
      if (lookahead == 't') ADVANCE(220);
      END_STATE();
    case 138:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 139:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 140:
      if (lookahead == 'l') ADVANCE(172);
      END_STATE();
    case 141:
      if (lookahead == 'l') ADVANCE(171);
      END_STATE();
    case 142:
      if (lookahead == 'l') ADVANCE(229);
      END_STATE();
    case 143:
      if (lookahead == 'l') ADVANCE(175);
      END_STATE();
    case 144:
      if (lookahead == 'l') ADVANCE(208);
      END_STATE();
    case 145:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 146:
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 147:
      if (lookahead == 'l') ADVANCE(199);
      END_STATE();
    case 148:
      if (lookahead == 'm') ADVANCE(151);
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 149:
      if (lookahead == 'm') ADVANCE(174);
      if (lookahead == 'n') ADVANCE(222);
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 150:
      if (lookahead == 'm') ADVANCE(74);
      END_STATE();
    case 151:
      if (lookahead == 'm') ADVANCE(45);
      END_STATE();
    case 152:
      if (lookahead == 'm') ADVANCE(92);
      END_STATE();
    case 153:
      if (lookahead == 'm') ADVANCE(101);
      END_STATE();
    case 154:
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 155:
      if (lookahead == 'n') ADVANCE(518);
      END_STATE();
    case 156:
      if (lookahead == 'n') ADVANCE(54);
      if (lookahead == 'u') ADVANCE(203);
      if (lookahead == 'v') ADVANCE(90);
      END_STATE();
    case 157:
      if (lookahead == 'n') ADVANCE(113);
      END_STATE();
    case 158:
      if (lookahead == 'n') ADVANCE(420);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(456);
      END_STATE();
    case 160:
      if (lookahead == 'n') ADVANCE(473);
      END_STATE();
    case 161:
      if (lookahead == 'n') ADVANCE(517);
      END_STATE();
    case 162:
      if (lookahead == 'n') ADVANCE(108);
      END_STATE();
    case 163:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 164:
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(210);
      END_STATE();
    case 167:
      if (lookahead == 'n') ADVANCE(153);
      END_STATE();
    case 168:
      if (lookahead == 'n') ADVANCE(126);
      END_STATE();
    case 169:
      if (lookahead == 'o') ADVANCE(478);
      END_STATE();
    case 170:
      if (lookahead == 'o') ADVANCE(215);
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 171:
      if (lookahead == 'o') ADVANCE(233);
      END_STATE();
    case 172:
      if (lookahead == 'o') ADVANCE(106);
      END_STATE();
    case 173:
      if (lookahead == 'o') ADVANCE(197);
      END_STATE();
    case 174:
      if (lookahead == 'o') ADVANCE(218);
      END_STATE();
    case 175:
      if (lookahead == 'o') ADVANCE(107);
      END_STATE();
    case 176:
      if (lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 177:
      if (lookahead == 'o') ADVANCE(204);
      END_STATE();
    case 178:
      if (lookahead == 'p') ADVANCE(436);
      END_STATE();
    case 179:
      if (lookahead == 'p') ADVANCE(207);
      END_STATE();
    case 180:
      if (lookahead == 'r') ADVANCE(516);
      END_STATE();
    case 181:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 182:
      if (lookahead == 'r') ADVANCE(510);
      END_STATE();
    case 183:
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 184:
      if (lookahead == 'r') ADVANCE(228);
      END_STATE();
    case 185:
      if (lookahead == 'r') ADVANCE(114);
      END_STATE();
    case 186:
      if (lookahead == 'r') ADVANCE(221);
      END_STATE();
    case 187:
      if (lookahead == 'r') ADVANCE(118);
      END_STATE();
    case 188:
      if (lookahead == 'r') ADVANCE(160);
      END_STATE();
    case 189:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 190:
      if (lookahead == 'r') ADVANCE(97);
      END_STATE();
    case 191:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 192:
      if (lookahead == 'r') ADVANCE(68);
      END_STATE();
    case 193:
      if (lookahead == 's') ADVANCE(415);
      END_STATE();
    case 194:
      if (lookahead == 's') ADVANCE(490);
      END_STATE();
    case 195:
      if (lookahead == 's') ADVANCE(433);
      END_STATE();
    case 196:
      if (lookahead == 's') ADVANCE(176);
      END_STATE();
    case 197:
      if (lookahead == 's') ADVANCE(77);
      END_STATE();
    case 198:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 199:
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 200:
      if (lookahead == 's') ADVANCE(81);
      END_STATE();
    case 201:
      if (lookahead == 's') ADVANCE(86);
      END_STATE();
    case 202:
      if (lookahead == 's') ADVANCE(98);
      END_STATE();
    case 203:
      if (lookahead == 't') ADVANCE(519);
      END_STATE();
    case 204:
      if (lookahead == 't') ADVANCE(497);
      END_STATE();
    case 205:
      if (lookahead == 't') ADVANCE(502);
      END_STATE();
    case 206:
      if (lookahead == 't') ADVANCE(484);
      END_STATE();
    case 207:
      if (lookahead == 't') ADVANCE(454);
      END_STATE();
    case 208:
      if (lookahead == 't') ADVANCE(440);
      END_STATE();
    case 209:
      if (lookahead == 't') ADVANCE(447);
      END_STATE();
    case 210:
      if (lookahead == 't') ADVANCE(448);
      END_STATE();
    case 211:
      if (lookahead == 't') ADVANCE(449);
      END_STATE();
    case 212:
      if (lookahead == 't') ADVANCE(237);
      END_STATE();
    case 213:
      if (lookahead == 't') ADVANCE(238);
      END_STATE();
    case 214:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 215:
      if (lookahead == 't') ADVANCE(169);
      END_STATE();
    case 216:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 217:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 218:
      if (lookahead == 't') ADVANCE(78);
      END_STATE();
    case 219:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 220:
      if (lookahead == 't') ADVANCE(124);
      END_STATE();
    case 221:
      if (lookahead == 't') ADVANCE(191);
      END_STATE();
    case 222:
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 223:
      if (lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 224:
      if (lookahead == 'u') ADVANCE(105);
      END_STATE();
    case 225:
      if (lookahead == 'u') ADVANCE(203);
      END_STATE();
    case 226:
      if (lookahead == 'u') ADVANCE(144);
      END_STATE();
    case 227:
      if (lookahead == 'u') ADVANCE(188);
      END_STATE();
    case 228:
      if (lookahead == 'u') ADVANCE(76);
      END_STATE();
    case 229:
      if (lookahead == 'u') ADVANCE(67);
      END_STATE();
    case 230:
      if (lookahead == 'u') ADVANCE(200);
      END_STATE();
    case 231:
      if (lookahead == 'u') ADVANCE(201);
      END_STATE();
    case 232:
      if (lookahead == 'v') ADVANCE(75);
      END_STATE();
    case 233:
      if (lookahead == 'w') ADVANCE(420);
      END_STATE();
    case 234:
      if (lookahead == 'w') ADVANCE(482);
      END_STATE();
    case 235:
      if (lookahead == 'x') ADVANCE(417);
      END_STATE();
    case 236:
      if (lookahead == 'x') ADVANCE(480);
      END_STATE();
    case 237:
      if (lookahead == 'y') ADVANCE(443);
      END_STATE();
    case 238:
      if (lookahead == 'y') ADVANCE(459);
      END_STATE();
    case 239:
      if (lookahead == 'y') ADVANCE(36);
      END_STATE();
    case 240:
      if (lookahead == 'y') ADVANCE(96);
      END_STATE();
    case 241:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 242:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(423);
      END_STATE();
    case 243:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(242);
      END_STATE();
    case 244:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(424);
      END_STATE();
    case 245:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 246:
      if (eof) ADVANCE(247);
      ADVANCE_MAP(
        '$', 244,
        '/', 10,
        ';', 427,
        '[', 409,
        ']', 411,
        'a', 287,
        'd', 323,
        'i', 349,
        's', 275,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(246);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(13);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(346);
      if (lookahead == 'l') ADVANCE(364);
      if (lookahead == 'o') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(403);
      if (lookahead == 'h') ADVANCE(359);
      if (lookahead == 'p') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(513);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(370);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(354);
      if (lookahead == 'e') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(278);
      if (lookahead == 'u') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(347);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(398);
      if (lookahead == 'l') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(371);
      if (lookahead == 'e') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(476);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(470);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(472);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(496);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(505);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(487);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(314);
      if (lookahead == 'n') ADVANCE(280);
      if (lookahead == 'p') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(465);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(373);
      if (lookahead == 'r') ADVANCE(400);
      if (lookahead == 'w') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(330);
      if (lookahead == 'p') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(501);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(361);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(368);
      if (lookahead == 'y') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(479);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(485);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(483);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(481);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(193);
      if (lookahead == 'p') ADVANCE(116);
      if (lookahead == 's') ADVANCE(415);
      if (lookahead == 'x') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(413);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_DURATION);
      if (lookahead == 'm') ADVANCE(193);
      if (lookahead == 's') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(416);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_DISTANCE);
      if (lookahead == 'p') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(418);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(420);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(421);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(422);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(424);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_wrap);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(460);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_debug);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_debug);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_spread);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_spread);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(anon_sym_player);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(anon_sym_self);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(408);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(142);
      if (lookahead == 'd') ADVANCE(87);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 246},
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
  [22] = {.lex_state = 246},
  [23] = {.lex_state = 246},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 246},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 246},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 246},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 246},
  [39] = {.lex_state = 246},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 246},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 246},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 246},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 246},
  [54] = {.lex_state = 246},
  [55] = {.lex_state = 246},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 246},
  [58] = {.lex_state = 246},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 246},
  [61] = {.lex_state = 246},
  [62] = {.lex_state = 246},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 4},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 6},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 6},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 6},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 6},
  [101] = {.lex_state = 6},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 6},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 246},
  [109] = {.lex_state = 9},
  [110] = {.lex_state = 246},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 8},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 4},
  [119] = {.lex_state = 246},
  [120] = {.lex_state = 6},
  [121] = {.lex_state = 9},
  [122] = {.lex_state = 2},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 6},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 4},
  [130] = {.lex_state = 6},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 9},
  [135] = {.lex_state = 4},
  [136] = {.lex_state = 9},
  [137] = {.lex_state = 9},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 2},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 246},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 2},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 246},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 9},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 2},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 9},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 8},
  [175] = {.lex_state = 4},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 2},
  [181] = {.lex_state = 2},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 246},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 2},
  [189] = {.lex_state = 2},
  [190] = {.lex_state = 2},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 2},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 2},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 6},
  [201] = {.lex_state = 9},
  [202] = {.lex_state = 2},
  [203] = {.lex_state = 6},
  [204] = {.lex_state = 8},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 4},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 2},
  [209] = {.lex_state = 8},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 4},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 246},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 2},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 2},
  [234] = {.lex_state = 4},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 246},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 246},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 9},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 246},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 2},
  [252] = {.lex_state = 2},
  [253] = {.lex_state = 2},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 8},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 0},
  [272] = {.lex_state = 2},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 0},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 0},
  [286] = {.lex_state = 0},
  [287] = {.lex_state = 0},
  [288] = {.lex_state = 0},
  [289] = {.lex_state = 0},
  [290] = {.lex_state = 0},
  [291] = {.lex_state = 0},
  [292] = {.lex_state = 0},
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
  [310] = {.lex_state = 0},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 0},
  [313] = {.lex_state = 0},
  [314] = {.lex_state = 0},
  [315] = {.lex_state = 0},
  [316] = {.lex_state = 0},
  [317] = {.lex_state = 0},
  [318] = {.lex_state = 0},
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
  [332] = {.lex_state = 0},
  [333] = {.lex_state = 0},
  [334] = {.lex_state = 0},
  [335] = {.lex_state = 0},
  [336] = {.lex_state = 0},
  [337] = {.lex_state = 0},
  [338] = {.lex_state = 0},
  [339] = {.lex_state = 0},
  [340] = {.lex_state = 0},
  [341] = {.lex_state = 0},
  [342] = {.lex_state = 0},
  [343] = {.lex_state = 0},
  [344] = {.lex_state = 0},
  [345] = {.lex_state = 0},
  [346] = {.lex_state = 0},
  [347] = {.lex_state = 0},
  [348] = {.lex_state = 0},
  [349] = {.lex_state = 0},
  [350] = {.lex_state = 0},
  [351] = {.lex_state = 0},
  [352] = {.lex_state = 0},
  [353] = {.lex_state = 0},
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
    [anon_sym_pause] = ACTIONS(1),
    [anon_sym_unpause] = ACTIONS(1),
    [anon_sym_player] = ACTIONS(1),
    [anon_sym_self] = ACTIONS(1),
    [anon_sym_camera] = ACTIONS(1),
    [anon_sym_fade] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_out] = ACTIONS(1),
    [anon_sym_shake] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(311),
    [sym_constant_expansion] = STATE(321),
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
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 25,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(28), 1,
      anon_sym_json,
    ACTIONS(31), 1,
      anon_sym_debug,
    ACTIONS(34), 1,
      anon_sym_rand,
    ACTIONS(37), 1,
      anon_sym_spread,
    ACTIONS(40), 1,
      sym_return_statement,
    ACTIONS(43), 1,
      anon_sym_load,
    ACTIONS(46), 1,
      anon_sym_goto,
    ACTIONS(49), 1,
      anon_sym_show,
    ACTIONS(52), 1,
      anon_sym_concat,
    ACTIONS(55), 1,
      anon_sym_delete,
    ACTIONS(58), 1,
      anon_sym_hide,
    ACTIONS(61), 1,
      anon_sym_unhide,
    ACTIONS(64), 1,
      anon_sym_save,
    ACTIONS(67), 1,
      anon_sym_erase,
    ACTIONS(70), 1,
      anon_sym_block,
    ACTIONS(73), 1,
      anon_sym_wait,
    ACTIONS(76), 1,
      anon_sym_close,
    ACTIONS(79), 1,
      anon_sym_pause,
    ACTIONS(82), 1,
      anon_sym_unpause,
    ACTIONS(85), 1,
      anon_sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(26), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [107] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(90), 1,
      anon_sym_RBRACE,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [213] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [319] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(134), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [425] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(136), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [531] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(138), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [637] = 25,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(92), 1,
      anon_sym_json,
    ACTIONS(94), 1,
      anon_sym_debug,
    ACTIONS(96), 1,
      anon_sym_rand,
    ACTIONS(98), 1,
      anon_sym_spread,
    ACTIONS(100), 1,
      sym_return_statement,
    ACTIONS(102), 1,
      anon_sym_load,
    ACTIONS(104), 1,
      anon_sym_goto,
    ACTIONS(106), 1,
      anon_sym_show,
    ACTIONS(108), 1,
      anon_sym_concat,
    ACTIONS(110), 1,
      anon_sym_delete,
    ACTIONS(112), 1,
      anon_sym_hide,
    ACTIONS(114), 1,
      anon_sym_unhide,
    ACTIONS(116), 1,
      anon_sym_save,
    ACTIONS(118), 1,
      anon_sym_erase,
    ACTIONS(120), 1,
      anon_sym_block,
    ACTIONS(122), 1,
      anon_sym_wait,
    ACTIONS(124), 1,
      anon_sym_close,
    ACTIONS(126), 1,
      anon_sym_pause,
    ACTIONS(128), 1,
      anon_sym_unpause,
    ACTIONS(130), 1,
      anon_sym_camera,
    ACTIONS(140), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 7,
      sym__script_item,
      sym_json_literal,
      sym_label,
      sym_debug_macro,
      sym_rand_macro,
      sym_spread_macro,
      aux_sym_script_block_repeat1,
    STATE(271), 24,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_blocking_delay,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade,
      sym_action_camera_shake,
  [743] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(144), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(142), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [777] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(148), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(146), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [811] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(152), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(150), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [845] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(156), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(154), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [877] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(158), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [909] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(164), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(162), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [941] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(168), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(166), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [973] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(172), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(170), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1005] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(176), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(174), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1037] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(180), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(178), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1069] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(184), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(182), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1101] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(188), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(186), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1133] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(192), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(190), 21,
      sym_BAREWORD,
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
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1165] = 12,
    ACTIONS(194), 1,
      ts_builtin_sym_end,
    ACTIONS(196), 1,
      sym_BAREWORD,
    ACTIONS(199), 1,
      anon_sym_LBRACK,
    ACTIONS(202), 1,
      sym_CONSTANT,
    ACTIONS(205), 1,
      anon_sym_include,
    ACTIONS(208), 1,
      anon_sym_add,
    ACTIONS(211), 1,
      anon_sym_serial_dialog,
    ACTIONS(214), 1,
      anon_sym_dialog,
    ACTIONS(217), 1,
      anon_sym_script,
    STATE(321), 1,
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
  [1211] = 12,
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
    ACTIONS(220), 1,
      ts_builtin_sym_end,
    STATE(321), 1,
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
  [1257] = 11,
    ACTIONS(222), 1,
      sym_QUOTED_STRING,
    ACTIONS(224), 1,
      anon_sym_wrap,
    ACTIONS(226), 1,
      anon_sym_entity,
    ACTIONS(228), 1,
      anon_sym_name,
    ACTIONS(230), 1,
      anon_sym_portrait,
    ACTIONS(232), 1,
      anon_sym_alignment,
    ACTIONS(234), 1,
      anon_sym_border_tileset,
    ACTIONS(236), 1,
      anon_sym_emote,
    STATE(41), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(27), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1293] = 5,
    ACTIONS(240), 1,
      anon_sym_LBRACK,
    STATE(289), 1,
      sym_constant_value_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(238), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(242), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1317] = 6,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(246), 1,
      anon_sym_RBRACK,
    ACTIONS(250), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(213), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(248), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1343] = 11,
    ACTIONS(222), 1,
      sym_QUOTED_STRING,
    ACTIONS(224), 1,
      anon_sym_wrap,
    ACTIONS(226), 1,
      anon_sym_entity,
    ACTIONS(228), 1,
      anon_sym_name,
    ACTIONS(230), 1,
      anon_sym_portrait,
    ACTIONS(232), 1,
      anon_sym_alignment,
    ACTIONS(234), 1,
      anon_sym_border_tileset,
    ACTIONS(236), 1,
      anon_sym_emote,
    STATE(52), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(28), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1379] = 10,
    ACTIONS(254), 1,
      anon_sym_wrap,
    ACTIONS(257), 1,
      anon_sym_entity,
    ACTIONS(260), 1,
      anon_sym_name,
    ACTIONS(263), 1,
      anon_sym_portrait,
    ACTIONS(266), 1,
      anon_sym_alignment,
    ACTIONS(269), 1,
      anon_sym_border_tileset,
    ACTIONS(272), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(28), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1413] = 10,
    ACTIONS(224), 1,
      anon_sym_wrap,
    ACTIONS(226), 1,
      anon_sym_entity,
    ACTIONS(228), 1,
      anon_sym_name,
    ACTIONS(230), 1,
      anon_sym_portrait,
    ACTIONS(232), 1,
      anon_sym_alignment,
    ACTIONS(234), 1,
      anon_sym_border_tileset,
    ACTIONS(236), 1,
      anon_sym_emote,
    ACTIONS(275), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(28), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1446] = 4,
    ACTIONS(279), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(277), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(281), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1467] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(283), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(285), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1486] = 5,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(250), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(227), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(287), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1509] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(289), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(291), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1528] = 4,
    ACTIONS(293), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(277), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(281), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1549] = 10,
    ACTIONS(224), 1,
      anon_sym_wrap,
    ACTIONS(226), 1,
      anon_sym_entity,
    ACTIONS(228), 1,
      anon_sym_name,
    ACTIONS(230), 1,
      anon_sym_portrait,
    ACTIONS(232), 1,
      anon_sym_alignment,
    ACTIONS(234), 1,
      anon_sym_border_tileset,
    ACTIONS(236), 1,
      anon_sym_emote,
    ACTIONS(295), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(29), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [1582] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(297), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(299), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1601] = 5,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(250), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(239), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(301), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1624] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(305), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1643] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(307), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(309), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1661] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(311), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1677] = 7,
    ACTIONS(222), 1,
      sym_QUOTED_STRING,
    ACTIONS(315), 1,
      anon_sym_RBRACE,
    ACTIONS(317), 1,
      anon_sym_GT,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(70), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(313), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1703] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(319), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1719] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(321), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1735] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(323), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(325), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1753] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(327), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(329), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [1771] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(331), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(333), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1789] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(335), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1805] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(337), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1821] = 2,
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
  [1837] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [1853] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(343), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(345), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1871] = 7,
    ACTIONS(222), 1,
      sym_QUOTED_STRING,
    ACTIONS(317), 1,
      anon_sym_GT,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(73), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(347), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1897] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(351), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(353), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1915] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(355), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(357), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1933] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(359), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(361), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1951] = 9,
    ACTIONS(363), 1,
      sym_BAREWORD,
    ACTIONS(365), 1,
      sym_QUOTED_STRING,
    ACTIONS(367), 1,
      sym_CONSTANT,
    ACTIONS(369), 1,
      anon_sym_wrap,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
    STATE(67), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(325), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(104), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1981] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(373), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(375), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1999] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(377), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(379), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2017] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(277), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(281), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [2035] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(381), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
    ACTIONS(383), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2053] = 3,
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
  [2071] = 3,
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
  [2089] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [2104] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(395), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [2119] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [2134] = 7,
    ACTIONS(399), 1,
      sym_BAREWORD,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    ACTIONS(405), 1,
      anon_sym_label,
    ACTIONS(407), 1,
      anon_sym_index,
    STATE(347), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(403), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2158] = 6,
    ACTIONS(365), 1,
      sym_QUOTED_STRING,
    ACTIONS(411), 1,
      sym_serial_dialog_option_type,
    STATE(89), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(92), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2180] = 7,
    ACTIONS(413), 1,
      sym_BAREWORD,
    ACTIONS(415), 1,
      anon_sym_RBRACE,
    ACTIONS(417), 1,
      anon_sym_entity,
    ACTIONS(419), 1,
      anon_sym_name,
    STATE(24), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [2204] = 7,
    ACTIONS(365), 1,
      sym_QUOTED_STRING,
    ACTIONS(421), 1,
      anon_sym_RBRACE,
    ACTIONS(423), 1,
      anon_sym_wrap,
    STATE(67), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(318), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(104), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2228] = 5,
    ACTIONS(317), 1,
      anon_sym_GT,
    ACTIONS(427), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(76), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(425), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2248] = 6,
    ACTIONS(365), 1,
      sym_QUOTED_STRING,
    ACTIONS(411), 1,
      sym_serial_dialog_option_type,
    STATE(89), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(429), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(100), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2270] = 5,
    ACTIONS(433), 1,
      sym_QUOTED_STRING,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(436), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(431), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2290] = 5,
    ACTIONS(317), 1,
      anon_sym_GT,
    ACTIONS(440), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(76), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(438), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2310] = 7,
    ACTIONS(413), 1,
      sym_BAREWORD,
    ACTIONS(417), 1,
      anon_sym_entity,
    ACTIONS(419), 1,
      anon_sym_name,
    ACTIONS(442), 1,
      anon_sym_RBRACE,
    STATE(24), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(68), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [2334] = 7,
    ACTIONS(444), 1,
      sym_BAREWORD,
    ACTIONS(447), 1,
      anon_sym_RBRACE,
    ACTIONS(449), 1,
      anon_sym_entity,
    ACTIONS(452), 1,
      anon_sym_name,
    STATE(24), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [2358] = 5,
    ACTIONS(457), 1,
      anon_sym_RBRACE,
    ACTIONS(459), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(76), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(455), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2378] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(462), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [2391] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(464), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [2404] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [2417] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(468), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(470), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2432] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(472), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [2445] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(327), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(474), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2461] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(222), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(476), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2477] = 4,
    ACTIONS(478), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_in,
      anon_sym_out,
    STATE(344), 2,
      sym_in_or_out,
      sym_in_or_out_expansion,
  [2493] = 6,
    ACTIONS(482), 1,
      anon_sym_RBRACE,
    ACTIONS(484), 1,
      anon_sym_default,
    ACTIONS(486), 1,
      anon_sym_label,
    ACTIONS(488), 1,
      anon_sym_entity,
    STATE(99), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2513] = 6,
    ACTIONS(490), 1,
      anon_sym_entity,
    ACTIONS(492), 1,
      anon_sym_map,
    ACTIONS(494), 1,
      anon_sym_player,
    ACTIONS(496), 1,
      anon_sym_self,
    STATE(278), 1,
      sym__map_or_entity_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2533] = 4,
    ACTIONS(500), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(498), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(87), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2549] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(300), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(503), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2565] = 4,
    ACTIONS(505), 1,
      sym_QUOTED_STRING,
    STATE(89), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(508), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [2581] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(275), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(510), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2597] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(305), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(512), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2613] = 4,
    ACTIONS(411), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(101), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2629] = 6,
    ACTIONS(490), 1,
      anon_sym_entity,
    ACTIONS(492), 1,
      anon_sym_map,
    ACTIONS(494), 1,
      anon_sym_player,
    ACTIONS(496), 1,
      anon_sym_self,
    STATE(279), 1,
      sym__map_or_entity_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2649] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(102), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(516), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2665] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(314), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(518), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2681] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(522), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(520), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2695] = 6,
    ACTIONS(484), 1,
      anon_sym_default,
    ACTIONS(486), 1,
      anon_sym_label,
    ACTIONS(488), 1,
      anon_sym_entity,
    ACTIONS(524), 1,
      anon_sym_RBRACE,
    STATE(85), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2715] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(302), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(526), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2731] = 6,
    ACTIONS(528), 1,
      anon_sym_RBRACE,
    ACTIONS(530), 1,
      anon_sym_default,
    ACTIONS(533), 1,
      anon_sym_label,
    ACTIONS(536), 1,
      anon_sym_entity,
    STATE(99), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2751] = 4,
    ACTIONS(411), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(539), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(101), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2767] = 4,
    ACTIONS(543), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(541), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(101), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [2783] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(277), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(546), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2799] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(316), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(548), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2815] = 5,
    ACTIONS(365), 1,
      sym_QUOTED_STRING,
    ACTIONS(423), 1,
      anon_sym_wrap,
    STATE(71), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(87), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2833] = 4,
    ACTIONS(401), 1,
      anon_sym_LBRACK,
    STATE(309), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(550), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2849] = 4,
    ACTIONS(552), 1,
      anon_sym_RBRACK,
    STATE(248), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_in,
      anon_sym_out,
  [2864] = 4,
    ACTIONS(554), 1,
      anon_sym_LBRACK,
    STATE(285), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(556), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2879] = 4,
    ACTIONS(558), 1,
      anon_sym_LBRACK,
    STATE(353), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(560), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2894] = 4,
    ACTIONS(562), 1,
      anon_sym_LBRACK,
    STATE(261), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(564), 2,
      sym_DURATION,
      sym_CONSTANT,
  [2909] = 4,
    ACTIONS(558), 1,
      anon_sym_LBRACK,
    STATE(269), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(566), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2924] = 3,
    ACTIONS(570), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(568), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2937] = 3,
    ACTIONS(574), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2950] = 4,
    ACTIONS(578), 1,
      anon_sym_LBRACK,
    STATE(329), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(576), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2965] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(580), 4,
      anon_sym_LBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2976] = 4,
    ACTIONS(582), 1,
      anon_sym_LBRACK,
    STATE(284), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(584), 2,
      sym_COLOR,
      sym_CONSTANT,
  [2991] = 4,
    ACTIONS(586), 1,
      anon_sym_LBRACK,
    STATE(286), 1,
      sym_distance_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [3006] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(590), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3017] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(592), 4,
      anon_sym_LBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3028] = 4,
    ACTIONS(558), 1,
      anon_sym_LBRACK,
    STATE(265), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(594), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3043] = 4,
    ACTIONS(596), 1,
      anon_sym_RBRACK,
    STATE(172), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_in,
      anon_sym_out,
  [3058] = 4,
    ACTIONS(562), 1,
      anon_sym_LBRACK,
    STATE(116), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(598), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3073] = 4,
    ACTIONS(602), 1,
      anon_sym_LBRACE,
    STATE(274), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(600), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3088] = 4,
    ACTIONS(423), 1,
      anon_sym_wrap,
    ACTIONS(604), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(87), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3103] = 4,
    ACTIONS(608), 1,
      anon_sym_LBRACE,
    STATE(291), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(606), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3118] = 4,
    ACTIONS(423), 1,
      anon_sym_wrap,
    ACTIONS(610), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(123), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3133] = 4,
    ACTIONS(602), 1,
      anon_sym_LBRACE,
    STATE(294), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(612), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3148] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(614), 4,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [3159] = 3,
    ACTIONS(616), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3172] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(618), 4,
      anon_sym_LBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3183] = 4,
    ACTIONS(620), 1,
      anon_sym_RBRACK,
    STATE(248), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_in,
      anon_sym_out,
  [3198] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(622), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3209] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(624), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3220] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3231] = 4,
    ACTIONS(562), 1,
      anon_sym_LBRACK,
    STATE(346), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(628), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3246] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(630), 4,
      anon_sym_LBRACK,
      sym_DISTANCE,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3257] = 4,
    ACTIONS(562), 1,
      anon_sym_LBRACK,
    STATE(335), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(632), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3272] = 4,
    ACTIONS(562), 1,
      anon_sym_LBRACK,
    STATE(339), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(634), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3287] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(636), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [3298] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3308] = 4,
    ACTIONS(640), 1,
      anon_sym_COMMA,
    ACTIONS(642), 1,
      anon_sym_RBRACK,
    STATE(169), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3322] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(644), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3332] = 3,
    ACTIONS(646), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(648), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3344] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(650), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_DASH_GT,
  [3354] = 4,
    ACTIONS(652), 1,
      anon_sym_COMMA,
    ACTIONS(654), 1,
      anon_sym_RBRACK,
    STATE(163), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3368] = 4,
    ACTIONS(656), 1,
      anon_sym_COMMA,
    ACTIONS(658), 1,
      anon_sym_RBRACE,
    STATE(155), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3382] = 4,
    ACTIONS(279), 1,
      anon_sym_RBRACK,
    ACTIONS(660), 1,
      anon_sym_COMMA,
    STATE(182), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3396] = 3,
    ACTIONS(662), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3408] = 4,
    ACTIONS(666), 1,
      anon_sym_COMMA,
    ACTIONS(669), 1,
      anon_sym_RBRACK,
    STATE(148), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3422] = 4,
    ACTIONS(671), 1,
      anon_sym_COMMA,
    ACTIONS(674), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3436] = 4,
    ACTIONS(676), 1,
      anon_sym_COMMA,
    ACTIONS(678), 1,
      anon_sym_RBRACK,
    STATE(151), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3450] = 4,
    ACTIONS(574), 1,
      anon_sym_RBRACK,
    ACTIONS(680), 1,
      anon_sym_COMMA,
    STATE(166), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3464] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(682), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3474] = 4,
    ACTIONS(684), 1,
      anon_sym_COMMA,
    ACTIONS(686), 1,
      anon_sym_RBRACK,
    STATE(146), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3488] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(688), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3498] = 4,
    ACTIONS(656), 1,
      anon_sym_COMMA,
    ACTIONS(690), 1,
      anon_sym_RBRACE,
    STATE(185), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3512] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(692), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [3522] = 4,
    ACTIONS(694), 1,
      anon_sym_COMMA,
    ACTIONS(697), 1,
      anon_sym_RBRACK,
    STATE(157), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3536] = 3,
    ACTIONS(699), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3548] = 4,
    ACTIONS(699), 1,
      anon_sym_RBRACK,
    ACTIONS(701), 1,
      anon_sym_COMMA,
    STATE(148), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3562] = 4,
    ACTIONS(703), 1,
      anon_sym_COMMA,
    ACTIONS(705), 1,
      anon_sym_RBRACK,
    STATE(168), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3576] = 4,
    ACTIONS(707), 1,
      anon_sym_COMMA,
    ACTIONS(709), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3590] = 3,
    ACTIONS(711), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3602] = 4,
    ACTIONS(711), 1,
      anon_sym_RBRACK,
    ACTIONS(715), 1,
      anon_sym_COMMA,
    STATE(187), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3616] = 3,
    ACTIONS(717), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(719), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3628] = 4,
    ACTIONS(721), 1,
      sym_QUOTED_STRING,
    ACTIONS(723), 1,
      anon_sym_RBRACE,
    STATE(145), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3642] = 4,
    ACTIONS(725), 1,
      anon_sym_COMMA,
    ACTIONS(728), 1,
      anon_sym_RBRACK,
    STATE(166), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3656] = 3,
    ACTIONS(732), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3668] = 4,
    ACTIONS(732), 1,
      anon_sym_RBRACK,
    ACTIONS(734), 1,
      anon_sym_COMMA,
    STATE(191), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3682] = 4,
    ACTIONS(717), 1,
      anon_sym_RBRACK,
    ACTIONS(736), 1,
      anon_sym_COMMA,
    STATE(171), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3696] = 3,
    ACTIONS(738), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(719), 2,
      sym_DURATION,
      sym_CONSTANT,
  [3708] = 4,
    ACTIONS(740), 1,
      anon_sym_COMMA,
    ACTIONS(743), 1,
      anon_sym_RBRACK,
    STATE(171), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3722] = 4,
    ACTIONS(745), 1,
      anon_sym_COMMA,
    ACTIONS(747), 1,
      anon_sym_RBRACK,
    STATE(173), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3736] = 4,
    ACTIONS(620), 1,
      anon_sym_RBRACK,
    ACTIONS(749), 1,
      anon_sym_COMMA,
    STATE(194), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3750] = 3,
    ACTIONS(751), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(753), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3762] = 3,
    ACTIONS(755), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(757), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [3774] = 3,
    ACTIONS(759), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(761), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3786] = 4,
    ACTIONS(763), 1,
      anon_sym_COMMA,
    ACTIONS(765), 1,
      anon_sym_RBRACK,
    STATE(157), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3800] = 4,
    ACTIONS(767), 1,
      anon_sym_COMMA,
    ACTIONS(769), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3814] = 4,
    ACTIONS(771), 1,
      anon_sym_COMMA,
    ACTIONS(773), 1,
      anon_sym_RBRACK,
    STATE(159), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3828] = 3,
    ACTIONS(777), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(775), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3840] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(779), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3850] = 4,
    ACTIONS(781), 1,
      anon_sym_COMMA,
    ACTIONS(784), 1,
      anon_sym_RBRACK,
    STATE(182), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3864] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(786), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3874] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(788), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3884] = 4,
    ACTIONS(790), 1,
      anon_sym_COMMA,
    ACTIONS(793), 1,
      anon_sym_RBRACE,
    STATE(185), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3898] = 3,
    ACTIONS(795), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3910] = 4,
    ACTIONS(797), 1,
      anon_sym_COMMA,
    ACTIONS(800), 1,
      anon_sym_RBRACK,
    STATE(187), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3924] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(802), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3934] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3944] = 3,
    ACTIONS(804), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3956] = 4,
    ACTIONS(806), 1,
      anon_sym_COMMA,
    ACTIONS(809), 1,
      anon_sym_RBRACK,
    STATE(191), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3970] = 4,
    ACTIONS(602), 1,
      anon_sym_LBRACE,
    ACTIONS(811), 1,
      anon_sym_SEMI,
    STATE(290), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3984] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(813), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3994] = 4,
    ACTIONS(815), 1,
      anon_sym_COMMA,
    ACTIONS(818), 1,
      anon_sym_RBRACK,
    STATE(194), 1,
      aux_sym_in_or_out_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4008] = 4,
    ACTIONS(820), 1,
      anon_sym_COMMA,
    ACTIONS(822), 1,
      anon_sym_RBRACK,
    STATE(205), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4022] = 4,
    ACTIONS(608), 1,
      anon_sym_LBRACE,
    ACTIONS(824), 1,
      anon_sym_SEMI,
    STATE(307), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4036] = 4,
    ACTIONS(826), 1,
      anon_sym_COMMA,
    ACTIONS(828), 1,
      anon_sym_RBRACK,
    STATE(207), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4050] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(830), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4060] = 4,
    ACTIONS(602), 1,
      anon_sym_LBRACE,
    ACTIONS(832), 1,
      anon_sym_SEMI,
    STATE(331), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4074] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(834), 3,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
      anon_sym_RPAREN,
  [4084] = 3,
    ACTIONS(836), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(838), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4096] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(840), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4106] = 3,
    STATE(248), 1,
      sym_in_or_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_in,
      anon_sym_out,
  [4118] = 3,
    ACTIONS(842), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(844), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4130] = 4,
    ACTIONS(842), 1,
      anon_sym_RBRACK,
    ACTIONS(846), 1,
      anon_sym_COMMA,
    STATE(210), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4144] = 3,
    ACTIONS(848), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(850), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [4156] = 4,
    ACTIONS(848), 1,
      anon_sym_RBRACK,
    ACTIONS(852), 1,
      anon_sym_COMMA,
    STATE(212), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4170] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(854), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4180] = 3,
    ACTIONS(856), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(844), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4192] = 4,
    ACTIONS(858), 1,
      anon_sym_COMMA,
    ACTIONS(861), 1,
      anon_sym_RBRACK,
    STATE(210), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4206] = 3,
    ACTIONS(863), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(850), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [4218] = 4,
    ACTIONS(865), 1,
      anon_sym_COMMA,
    ACTIONS(868), 1,
      anon_sym_RBRACK,
    STATE(212), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4232] = 4,
    ACTIONS(763), 1,
      anon_sym_COMMA,
    ACTIONS(870), 1,
      anon_sym_RBRACK,
    STATE(177), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4246] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4255] = 3,
    ACTIONS(872), 1,
      anon_sym_LBRACE,
    STATE(58), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4266] = 3,
    ACTIONS(874), 1,
      anon_sym_serial_dialog,
    ACTIONS(876), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4277] = 3,
    ACTIONS(878), 1,
      anon_sym_command,
    ACTIONS(880), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4288] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(784), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4297] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4306] = 3,
    ACTIONS(882), 1,
      anon_sym_LBRACE,
    STATE(132), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4317] = 3,
    ACTIONS(882), 1,
      anon_sym_LBRACE,
    STATE(133), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4328] = 3,
    ACTIONS(884), 1,
      anon_sym_SEMI,
    ACTIONS(886), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4339] = 3,
    ACTIONS(888), 1,
      anon_sym_serial_dialog,
    ACTIONS(890), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4350] = 3,
    ACTIONS(892), 1,
      anon_sym_serial_dialog,
    ACTIONS(894), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4361] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(896), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4370] = 3,
    ACTIONS(721), 1,
      sym_QUOTED_STRING,
    STATE(240), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4381] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(697), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4390] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(669), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4399] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(728), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4408] = 3,
    ACTIONS(898), 1,
      anon_sym_RBRACK,
    ACTIONS(900), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4419] = 3,
    ACTIONS(902), 1,
      anon_sym_fade,
    ACTIONS(904), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4430] = 3,
    ACTIONS(882), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4441] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(906), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4450] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(850), 2,
      sym_DISTANCE,
      sym_CONSTANT,
  [4459] = 3,
    ACTIONS(769), 1,
      anon_sym_RBRACK,
    ACTIONS(908), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4470] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(674), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4479] = 3,
    ACTIONS(908), 1,
      sym_CONSTANT,
    ACTIONS(910), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4490] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(912), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4499] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(914), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [4508] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(793), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [4517] = 3,
    ACTIONS(602), 1,
      anon_sym_LBRACE,
    STATE(55), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4528] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(800), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4537] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(916), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4546] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(809), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4555] = 3,
    ACTIONS(608), 1,
      anon_sym_LBRACE,
    STATE(54), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4566] = 3,
    ACTIONS(872), 1,
      anon_sym_LBRACE,
    STATE(39), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4577] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(719), 2,
      sym_DURATION,
      sym_CONSTANT,
  [4586] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(818), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4595] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(918), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4604] = 3,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    STATE(13), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4615] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(920), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4624] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4633] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(922), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4642] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(861), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4651] = 3,
    ACTIONS(924), 1,
      anon_sym_map,
    ACTIONS(926), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4662] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(868), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4671] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(844), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4680] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(743), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4689] = 2,
    ACTIONS(928), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4697] = 2,
    ACTIONS(908), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4705] = 2,
    ACTIONS(930), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4713] = 2,
    ACTIONS(932), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4721] = 2,
    ACTIONS(934), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4729] = 2,
    ACTIONS(936), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4737] = 2,
    ACTIONS(938), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4745] = 2,
    ACTIONS(940), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4753] = 2,
    ACTIONS(942), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4761] = 2,
    ACTIONS(944), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4769] = 2,
    ACTIONS(946), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4777] = 2,
    ACTIONS(948), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4785] = 2,
    ACTIONS(950), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4793] = 2,
    ACTIONS(952), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4801] = 2,
    ACTIONS(954), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4809] = 2,
    ACTIONS(956), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4817] = 2,
    ACTIONS(958), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4825] = 2,
    ACTIONS(960), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4833] = 2,
    ACTIONS(962), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4841] = 2,
    ACTIONS(964), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4849] = 2,
    ACTIONS(966), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4857] = 2,
    ACTIONS(968), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4865] = 2,
    ACTIONS(970), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4873] = 2,
    ACTIONS(972), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4881] = 2,
    ACTIONS(974), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4889] = 2,
    ACTIONS(976), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4897] = 2,
    ACTIONS(978), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4905] = 2,
    ACTIONS(980), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4913] = 2,
    ACTIONS(982), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4921] = 2,
    ACTIONS(984), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4929] = 2,
    ACTIONS(986), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4937] = 2,
    ACTIONS(988), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4945] = 2,
    ACTIONS(990), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4953] = 2,
    ACTIONS(992), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4961] = 2,
    ACTIONS(994), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4969] = 2,
    ACTIONS(996), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4977] = 2,
    ACTIONS(998), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4985] = 2,
    ACTIONS(1000), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4993] = 2,
    ACTIONS(1002), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5001] = 2,
    ACTIONS(1004), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5009] = 2,
    ACTIONS(1006), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5017] = 2,
    ACTIONS(1008), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5025] = 2,
    ACTIONS(1010), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5033] = 2,
    ACTIONS(1012), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5041] = 2,
    ACTIONS(1014), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5049] = 2,
    ACTIONS(1016), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5057] = 2,
    ACTIONS(1018), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5065] = 2,
    ACTIONS(1020), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5073] = 2,
    ACTIONS(1022), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5081] = 2,
    ACTIONS(1024), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5089] = 2,
    ACTIONS(1026), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5097] = 2,
    ACTIONS(1028), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5105] = 2,
    ACTIONS(1030), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5113] = 2,
    ACTIONS(1032), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5121] = 2,
    ACTIONS(1034), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5129] = 2,
    ACTIONS(1036), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5137] = 2,
    ACTIONS(1038), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5145] = 2,
    ACTIONS(1040), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5153] = 2,
    ACTIONS(1042), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5161] = 2,
    ACTIONS(1044), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5169] = 2,
    ACTIONS(1046), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5177] = 2,
    ACTIONS(1048), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5185] = 2,
    ACTIONS(1050), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5193] = 2,
    ACTIONS(1052), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5201] = 2,
    ACTIONS(1054), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5209] = 2,
    ACTIONS(1056), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5217] = 2,
    ACTIONS(1058), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5225] = 2,
    ACTIONS(1060), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5233] = 2,
    ACTIONS(1062), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5241] = 2,
    ACTIONS(1064), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5249] = 2,
    ACTIONS(1066), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5257] = 2,
    ACTIONS(1068), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5265] = 2,
    ACTIONS(1070), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5273] = 2,
    ACTIONS(1072), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5281] = 2,
    ACTIONS(1074), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5289] = 2,
    ACTIONS(1076), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5297] = 2,
    ACTIONS(1078), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5305] = 2,
    ACTIONS(1080), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5313] = 2,
    ACTIONS(1082), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5321] = 2,
    ACTIONS(1084), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5329] = 2,
    ACTIONS(1086), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5337] = 2,
    ACTIONS(1088), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5345] = 2,
    ACTIONS(1090), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5353] = 2,
    ACTIONS(1092), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5361] = 2,
    ACTIONS(1094), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5369] = 2,
    ACTIONS(1096), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5377] = 2,
    ACTIONS(1098), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5385] = 2,
    ACTIONS(1100), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5393] = 2,
    ACTIONS(1102), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5401] = 2,
    ACTIONS(1104), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5409] = 2,
    ACTIONS(1106), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5417] = 2,
    ACTIONS(1108), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5425] = 2,
    ACTIONS(1110), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5433] = 2,
    ACTIONS(1112), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5441] = 2,
    ACTIONS(1114), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 107,
  [SMALL_STATE(4)] = 213,
  [SMALL_STATE(5)] = 319,
  [SMALL_STATE(6)] = 425,
  [SMALL_STATE(7)] = 531,
  [SMALL_STATE(8)] = 637,
  [SMALL_STATE(9)] = 743,
  [SMALL_STATE(10)] = 777,
  [SMALL_STATE(11)] = 811,
  [SMALL_STATE(12)] = 845,
  [SMALL_STATE(13)] = 877,
  [SMALL_STATE(14)] = 909,
  [SMALL_STATE(15)] = 941,
  [SMALL_STATE(16)] = 973,
  [SMALL_STATE(17)] = 1005,
  [SMALL_STATE(18)] = 1037,
  [SMALL_STATE(19)] = 1069,
  [SMALL_STATE(20)] = 1101,
  [SMALL_STATE(21)] = 1133,
  [SMALL_STATE(22)] = 1165,
  [SMALL_STATE(23)] = 1211,
  [SMALL_STATE(24)] = 1257,
  [SMALL_STATE(25)] = 1293,
  [SMALL_STATE(26)] = 1317,
  [SMALL_STATE(27)] = 1343,
  [SMALL_STATE(28)] = 1379,
  [SMALL_STATE(29)] = 1413,
  [SMALL_STATE(30)] = 1446,
  [SMALL_STATE(31)] = 1467,
  [SMALL_STATE(32)] = 1486,
  [SMALL_STATE(33)] = 1509,
  [SMALL_STATE(34)] = 1528,
  [SMALL_STATE(35)] = 1549,
  [SMALL_STATE(36)] = 1582,
  [SMALL_STATE(37)] = 1601,
  [SMALL_STATE(38)] = 1624,
  [SMALL_STATE(39)] = 1643,
  [SMALL_STATE(40)] = 1661,
  [SMALL_STATE(41)] = 1677,
  [SMALL_STATE(42)] = 1703,
  [SMALL_STATE(43)] = 1719,
  [SMALL_STATE(44)] = 1735,
  [SMALL_STATE(45)] = 1753,
  [SMALL_STATE(46)] = 1771,
  [SMALL_STATE(47)] = 1789,
  [SMALL_STATE(48)] = 1805,
  [SMALL_STATE(49)] = 1821,
  [SMALL_STATE(50)] = 1837,
  [SMALL_STATE(51)] = 1853,
  [SMALL_STATE(52)] = 1871,
  [SMALL_STATE(53)] = 1897,
  [SMALL_STATE(54)] = 1915,
  [SMALL_STATE(55)] = 1933,
  [SMALL_STATE(56)] = 1951,
  [SMALL_STATE(57)] = 1981,
  [SMALL_STATE(58)] = 1999,
  [SMALL_STATE(59)] = 2017,
  [SMALL_STATE(60)] = 2035,
  [SMALL_STATE(61)] = 2053,
  [SMALL_STATE(62)] = 2071,
  [SMALL_STATE(63)] = 2089,
  [SMALL_STATE(64)] = 2104,
  [SMALL_STATE(65)] = 2119,
  [SMALL_STATE(66)] = 2134,
  [SMALL_STATE(67)] = 2158,
  [SMALL_STATE(68)] = 2180,
  [SMALL_STATE(69)] = 2204,
  [SMALL_STATE(70)] = 2228,
  [SMALL_STATE(71)] = 2248,
  [SMALL_STATE(72)] = 2270,
  [SMALL_STATE(73)] = 2290,
  [SMALL_STATE(74)] = 2310,
  [SMALL_STATE(75)] = 2334,
  [SMALL_STATE(76)] = 2358,
  [SMALL_STATE(77)] = 2378,
  [SMALL_STATE(78)] = 2391,
  [SMALL_STATE(79)] = 2404,
  [SMALL_STATE(80)] = 2417,
  [SMALL_STATE(81)] = 2432,
  [SMALL_STATE(82)] = 2445,
  [SMALL_STATE(83)] = 2461,
  [SMALL_STATE(84)] = 2477,
  [SMALL_STATE(85)] = 2493,
  [SMALL_STATE(86)] = 2513,
  [SMALL_STATE(87)] = 2533,
  [SMALL_STATE(88)] = 2549,
  [SMALL_STATE(89)] = 2565,
  [SMALL_STATE(90)] = 2581,
  [SMALL_STATE(91)] = 2597,
  [SMALL_STATE(92)] = 2613,
  [SMALL_STATE(93)] = 2629,
  [SMALL_STATE(94)] = 2649,
  [SMALL_STATE(95)] = 2665,
  [SMALL_STATE(96)] = 2681,
  [SMALL_STATE(97)] = 2695,
  [SMALL_STATE(98)] = 2715,
  [SMALL_STATE(99)] = 2731,
  [SMALL_STATE(100)] = 2751,
  [SMALL_STATE(101)] = 2767,
  [SMALL_STATE(102)] = 2783,
  [SMALL_STATE(103)] = 2799,
  [SMALL_STATE(104)] = 2815,
  [SMALL_STATE(105)] = 2833,
  [SMALL_STATE(106)] = 2849,
  [SMALL_STATE(107)] = 2864,
  [SMALL_STATE(108)] = 2879,
  [SMALL_STATE(109)] = 2894,
  [SMALL_STATE(110)] = 2909,
  [SMALL_STATE(111)] = 2924,
  [SMALL_STATE(112)] = 2937,
  [SMALL_STATE(113)] = 2950,
  [SMALL_STATE(114)] = 2965,
  [SMALL_STATE(115)] = 2976,
  [SMALL_STATE(116)] = 2991,
  [SMALL_STATE(117)] = 3006,
  [SMALL_STATE(118)] = 3017,
  [SMALL_STATE(119)] = 3028,
  [SMALL_STATE(120)] = 3043,
  [SMALL_STATE(121)] = 3058,
  [SMALL_STATE(122)] = 3073,
  [SMALL_STATE(123)] = 3088,
  [SMALL_STATE(124)] = 3103,
  [SMALL_STATE(125)] = 3118,
  [SMALL_STATE(126)] = 3133,
  [SMALL_STATE(127)] = 3148,
  [SMALL_STATE(128)] = 3159,
  [SMALL_STATE(129)] = 3172,
  [SMALL_STATE(130)] = 3183,
  [SMALL_STATE(131)] = 3198,
  [SMALL_STATE(132)] = 3209,
  [SMALL_STATE(133)] = 3220,
  [SMALL_STATE(134)] = 3231,
  [SMALL_STATE(135)] = 3246,
  [SMALL_STATE(136)] = 3257,
  [SMALL_STATE(137)] = 3272,
  [SMALL_STATE(138)] = 3287,
  [SMALL_STATE(139)] = 3298,
  [SMALL_STATE(140)] = 3308,
  [SMALL_STATE(141)] = 3322,
  [SMALL_STATE(142)] = 3332,
  [SMALL_STATE(143)] = 3344,
  [SMALL_STATE(144)] = 3354,
  [SMALL_STATE(145)] = 3368,
  [SMALL_STATE(146)] = 3382,
  [SMALL_STATE(147)] = 3396,
  [SMALL_STATE(148)] = 3408,
  [SMALL_STATE(149)] = 3422,
  [SMALL_STATE(150)] = 3436,
  [SMALL_STATE(151)] = 3450,
  [SMALL_STATE(152)] = 3464,
  [SMALL_STATE(153)] = 3474,
  [SMALL_STATE(154)] = 3488,
  [SMALL_STATE(155)] = 3498,
  [SMALL_STATE(156)] = 3512,
  [SMALL_STATE(157)] = 3522,
  [SMALL_STATE(158)] = 3536,
  [SMALL_STATE(159)] = 3548,
  [SMALL_STATE(160)] = 3562,
  [SMALL_STATE(161)] = 3576,
  [SMALL_STATE(162)] = 3590,
  [SMALL_STATE(163)] = 3602,
  [SMALL_STATE(164)] = 3616,
  [SMALL_STATE(165)] = 3628,
  [SMALL_STATE(166)] = 3642,
  [SMALL_STATE(167)] = 3656,
  [SMALL_STATE(168)] = 3668,
  [SMALL_STATE(169)] = 3682,
  [SMALL_STATE(170)] = 3696,
  [SMALL_STATE(171)] = 3708,
  [SMALL_STATE(172)] = 3722,
  [SMALL_STATE(173)] = 3736,
  [SMALL_STATE(174)] = 3750,
  [SMALL_STATE(175)] = 3762,
  [SMALL_STATE(176)] = 3774,
  [SMALL_STATE(177)] = 3786,
  [SMALL_STATE(178)] = 3800,
  [SMALL_STATE(179)] = 3814,
  [SMALL_STATE(180)] = 3828,
  [SMALL_STATE(181)] = 3840,
  [SMALL_STATE(182)] = 3850,
  [SMALL_STATE(183)] = 3864,
  [SMALL_STATE(184)] = 3874,
  [SMALL_STATE(185)] = 3884,
  [SMALL_STATE(186)] = 3898,
  [SMALL_STATE(187)] = 3910,
  [SMALL_STATE(188)] = 3924,
  [SMALL_STATE(189)] = 3934,
  [SMALL_STATE(190)] = 3944,
  [SMALL_STATE(191)] = 3956,
  [SMALL_STATE(192)] = 3970,
  [SMALL_STATE(193)] = 3984,
  [SMALL_STATE(194)] = 3994,
  [SMALL_STATE(195)] = 4008,
  [SMALL_STATE(196)] = 4022,
  [SMALL_STATE(197)] = 4036,
  [SMALL_STATE(198)] = 4050,
  [SMALL_STATE(199)] = 4060,
  [SMALL_STATE(200)] = 4074,
  [SMALL_STATE(201)] = 4084,
  [SMALL_STATE(202)] = 4096,
  [SMALL_STATE(203)] = 4106,
  [SMALL_STATE(204)] = 4118,
  [SMALL_STATE(205)] = 4130,
  [SMALL_STATE(206)] = 4144,
  [SMALL_STATE(207)] = 4156,
  [SMALL_STATE(208)] = 4170,
  [SMALL_STATE(209)] = 4180,
  [SMALL_STATE(210)] = 4192,
  [SMALL_STATE(211)] = 4206,
  [SMALL_STATE(212)] = 4218,
  [SMALL_STATE(213)] = 4232,
  [SMALL_STATE(214)] = 4246,
  [SMALL_STATE(215)] = 4255,
  [SMALL_STATE(216)] = 4266,
  [SMALL_STATE(217)] = 4277,
  [SMALL_STATE(218)] = 4288,
  [SMALL_STATE(219)] = 4297,
  [SMALL_STATE(220)] = 4306,
  [SMALL_STATE(221)] = 4317,
  [SMALL_STATE(222)] = 4328,
  [SMALL_STATE(223)] = 4339,
  [SMALL_STATE(224)] = 4350,
  [SMALL_STATE(225)] = 4361,
  [SMALL_STATE(226)] = 4370,
  [SMALL_STATE(227)] = 4381,
  [SMALL_STATE(228)] = 4390,
  [SMALL_STATE(229)] = 4399,
  [SMALL_STATE(230)] = 4408,
  [SMALL_STATE(231)] = 4419,
  [SMALL_STATE(232)] = 4430,
  [SMALL_STATE(233)] = 4441,
  [SMALL_STATE(234)] = 4450,
  [SMALL_STATE(235)] = 4459,
  [SMALL_STATE(236)] = 4470,
  [SMALL_STATE(237)] = 4479,
  [SMALL_STATE(238)] = 4490,
  [SMALL_STATE(239)] = 4499,
  [SMALL_STATE(240)] = 4508,
  [SMALL_STATE(241)] = 4517,
  [SMALL_STATE(242)] = 4528,
  [SMALL_STATE(243)] = 4537,
  [SMALL_STATE(244)] = 4546,
  [SMALL_STATE(245)] = 4555,
  [SMALL_STATE(246)] = 4566,
  [SMALL_STATE(247)] = 4577,
  [SMALL_STATE(248)] = 4586,
  [SMALL_STATE(249)] = 4595,
  [SMALL_STATE(250)] = 4604,
  [SMALL_STATE(251)] = 4615,
  [SMALL_STATE(252)] = 4624,
  [SMALL_STATE(253)] = 4633,
  [SMALL_STATE(254)] = 4642,
  [SMALL_STATE(255)] = 4651,
  [SMALL_STATE(256)] = 4662,
  [SMALL_STATE(257)] = 4671,
  [SMALL_STATE(258)] = 4680,
  [SMALL_STATE(259)] = 4689,
  [SMALL_STATE(260)] = 4697,
  [SMALL_STATE(261)] = 4705,
  [SMALL_STATE(262)] = 4713,
  [SMALL_STATE(263)] = 4721,
  [SMALL_STATE(264)] = 4729,
  [SMALL_STATE(265)] = 4737,
  [SMALL_STATE(266)] = 4745,
  [SMALL_STATE(267)] = 4753,
  [SMALL_STATE(268)] = 4761,
  [SMALL_STATE(269)] = 4769,
  [SMALL_STATE(270)] = 4777,
  [SMALL_STATE(271)] = 4785,
  [SMALL_STATE(272)] = 4793,
  [SMALL_STATE(273)] = 4801,
  [SMALL_STATE(274)] = 4809,
  [SMALL_STATE(275)] = 4817,
  [SMALL_STATE(276)] = 4825,
  [SMALL_STATE(277)] = 4833,
  [SMALL_STATE(278)] = 4841,
  [SMALL_STATE(279)] = 4849,
  [SMALL_STATE(280)] = 4857,
  [SMALL_STATE(281)] = 4865,
  [SMALL_STATE(282)] = 4873,
  [SMALL_STATE(283)] = 4881,
  [SMALL_STATE(284)] = 4889,
  [SMALL_STATE(285)] = 4897,
  [SMALL_STATE(286)] = 4905,
  [SMALL_STATE(287)] = 4913,
  [SMALL_STATE(288)] = 4921,
  [SMALL_STATE(289)] = 4929,
  [SMALL_STATE(290)] = 4937,
  [SMALL_STATE(291)] = 4945,
  [SMALL_STATE(292)] = 4953,
  [SMALL_STATE(293)] = 4961,
  [SMALL_STATE(294)] = 4969,
  [SMALL_STATE(295)] = 4977,
  [SMALL_STATE(296)] = 4985,
  [SMALL_STATE(297)] = 4993,
  [SMALL_STATE(298)] = 5001,
  [SMALL_STATE(299)] = 5009,
  [SMALL_STATE(300)] = 5017,
  [SMALL_STATE(301)] = 5025,
  [SMALL_STATE(302)] = 5033,
  [SMALL_STATE(303)] = 5041,
  [SMALL_STATE(304)] = 5049,
  [SMALL_STATE(305)] = 5057,
  [SMALL_STATE(306)] = 5065,
  [SMALL_STATE(307)] = 5073,
  [SMALL_STATE(308)] = 5081,
  [SMALL_STATE(309)] = 5089,
  [SMALL_STATE(310)] = 5097,
  [SMALL_STATE(311)] = 5105,
  [SMALL_STATE(312)] = 5113,
  [SMALL_STATE(313)] = 5121,
  [SMALL_STATE(314)] = 5129,
  [SMALL_STATE(315)] = 5137,
  [SMALL_STATE(316)] = 5145,
  [SMALL_STATE(317)] = 5153,
  [SMALL_STATE(318)] = 5161,
  [SMALL_STATE(319)] = 5169,
  [SMALL_STATE(320)] = 5177,
  [SMALL_STATE(321)] = 5185,
  [SMALL_STATE(322)] = 5193,
  [SMALL_STATE(323)] = 5201,
  [SMALL_STATE(324)] = 5209,
  [SMALL_STATE(325)] = 5217,
  [SMALL_STATE(326)] = 5225,
  [SMALL_STATE(327)] = 5233,
  [SMALL_STATE(328)] = 5241,
  [SMALL_STATE(329)] = 5249,
  [SMALL_STATE(330)] = 5257,
  [SMALL_STATE(331)] = 5265,
  [SMALL_STATE(332)] = 5273,
  [SMALL_STATE(333)] = 5281,
  [SMALL_STATE(334)] = 5289,
  [SMALL_STATE(335)] = 5297,
  [SMALL_STATE(336)] = 5305,
  [SMALL_STATE(337)] = 5313,
  [SMALL_STATE(338)] = 5321,
  [SMALL_STATE(339)] = 5329,
  [SMALL_STATE(340)] = 5337,
  [SMALL_STATE(341)] = 5345,
  [SMALL_STATE(342)] = 5353,
  [SMALL_STATE(343)] = 5361,
  [SMALL_STATE(344)] = 5369,
  [SMALL_STATE(345)] = 5377,
  [SMALL_STATE(346)] = 5385,
  [SMALL_STATE(347)] = 5393,
  [SMALL_STATE(348)] = 5401,
  [SMALL_STATE(349)] = 5409,
  [SMALL_STATE(350)] = 5417,
  [SMALL_STATE(351)] = 5425,
  [SMALL_STATE(352)] = 5433,
  [SMALL_STATE(353)] = 5441,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(225),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(272),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(319),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(250),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(324),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(332),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(343),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(271),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(216),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(298),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(217),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(350),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(270),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(276),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(292),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(109),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(224),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(86),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(231),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(319),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(250),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(324),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(332),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(343),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(271),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(255),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(216),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(298),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(217),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(350),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(270),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(276),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(292),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 6),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 6),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 40),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 40),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 4, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_debug_macro, 5, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_spread_macro, 5, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(215),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(230),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(321),
  [205] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [208] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(223),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(225),
  [214] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(198),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(272),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(289),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [254] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(238),
  [257] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(183),
  [260] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [263] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(193),
  [266] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [269] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(208),
  [272] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(243),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [281] = {.entry = {.count = 1, .reusable = false}}, SHIFT(218),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 36),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 30),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 30),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 28),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 24),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [329] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 32),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 32),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 27),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 35),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 34),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 37),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [347] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 38),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 38),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [357] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [361] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(323),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [369] = {.entry = {.count = 1, .reusable = false}}, SHIFT(249),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [379] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [383] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [387] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [391] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 28),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 27),
  [399] = {.entry = {.count = 1, .reusable = false}}, SHIFT(347),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [405] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [407] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [413] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [417] = {.entry = {.count = 1, .reusable = false}}, SHIFT(251),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(253),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [425] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 30),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 30),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 25),
  [431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 39),
  [433] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 39), SHIFT_REPEAT(80),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 39),
  [438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 38),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 38),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [444] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [449] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(251),
  [452] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(253),
  [455] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [459] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(322),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 29),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 29),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [500] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(249),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [505] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 26), SHIFT_REPEAT(127),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 26),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 12),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [520] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 48),
  [522] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 48),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 33),
  [530] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 33), SHIFT_REPEAT(232),
  [533] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 33), SHIFT_REPEAT(233),
  [536] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 33), SHIFT_REPEAT(152),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 25),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [543] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(288),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [582] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 2, 0, 0),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [618] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [624] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 42),
  [626] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 43),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [630] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [644] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out, 1, 0, 0),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [666] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(219),
  [669] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [671] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [692] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 24),
  [694] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [697] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [725] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(189),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [736] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [740] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(247),
  [743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [757] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [781] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [784] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [788] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [790] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [793] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [797] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(214),
  [800] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [806] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(252),
  [809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 17),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [815] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(203),
  [818] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_in_or_out_expansion_repeat1, 2, 0, 0),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [824] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 18),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [832] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 17),
  [834] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 45),
  [836] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [858] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(257),
  [861] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [865] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(234),
  [868] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [878] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [882] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [884] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 3, 0, 19),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [890] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [892] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [894] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [896] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [898] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [900] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [902] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [904] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [912] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [914] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 44),
  [916] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [918] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [920] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [922] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [924] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [926] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [928] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 4, 0, 0),
  [930] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 8),
  [932] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 3, 0, 0),
  [934] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [936] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [938] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 16),
  [940] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [942] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [944] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [946] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 14),
  [948] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [950] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [952] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [954] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [956] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 3, 0, 0),
  [958] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 5, 0, 41),
  [960] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [962] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__map_or_entity_script, 3, 0, 31),
  [964] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 2, 0, 9),
  [966] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 2, 0, 9),
  [968] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 2, 0, 0),
  [970] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 3, 0, 0),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [974] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 3, 0, 0),
  [976] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [982] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 5, 0, 0),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [988] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 17),
  [990] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 0),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [994] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [996] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 3, 0, 0),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1000] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [1006] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [1008] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 3, 0, 20),
  [1010] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [1012] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 3, 0, 19),
  [1014] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1016] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [1018] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 3, 0, 19),
  [1020] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [1022] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 18),
  [1024] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1026] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 13),
  [1028] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 2, 0, 0),
  [1030] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1032] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [1034] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 4, 0, 0),
  [1036] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__map_or_entity_script, 2, 0, 21),
  [1038] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [1040] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__map_or_entity_script, 2, 0, 22),
  [1042] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1044] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1046] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1048] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [1058] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [1060] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [1062] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__map_or_entity_script, 2, 0, 23),
  [1064] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1066] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 15),
  [1068] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_in_or_out_expansion, 5, 0, 0),
  [1070] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 17),
  [1072] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [1074] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [1078] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade, 7, 0, 46),
  [1080] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [1082] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1084] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [1086] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 7, 0, 47),
  [1088] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [1090] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [1092] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 4, 0, 0),
  [1094] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1096] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1098] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [1100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 8),
  [1102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [1104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [1106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [1108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [1110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [1112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 5, 0, 0),
  [1114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 14),
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
