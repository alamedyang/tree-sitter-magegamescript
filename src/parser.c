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
#define STATE_COUNT 351
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 172
#define ALIAS_COUNT 0
#define TOKEN_COUNT 78
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 33
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 62

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BOOL = 3,
  sym_BAREWORD = 4,
  anon_sym_LBRACK = 5,
  anon_sym_COMMA = 6,
  anon_sym_RBRACK = 7,
  sym_QUOTED_STRING = 8,
  sym_NUMBER = 9,
  sym_duration_suffix = 10,
  sym_distance_suffix = 11,
  sym_quantity_suffix = 12,
  aux_sym_QUANTITY_token1 = 13,
  sym_COLOR = 14,
  sym_CONSTANT = 15,
  anon_sym_include = 16,
  anon_sym_SEMI = 17,
  anon_sym_EQ = 18,
  anon_sym_add = 19,
  anon_sym_serial_dialog = 20,
  anon_sym_settings = 21,
  anon_sym_LBRACE = 22,
  anon_sym_RBRACE = 23,
  anon_sym_wrap = 24,
  anon_sym_dialog = 25,
  sym_target_default = 26,
  anon_sym_label = 27,
  anon_sym_entity = 28,
  anon_sym_emote = 29,
  anon_sym_name = 30,
  anon_sym_portrait = 31,
  anon_sym_alignment = 32,
  anon_sym_border_tileset = 33,
  sym_identifier_type = 34,
  anon_sym_GT = 35,
  sym_serial_dialog_option_type = 36,
  anon_sym_script = 37,
  anon_sym_json = 38,
  anon_sym_COLON = 39,
  sym_json_number = 40,
  anon_sym_true = 41,
  anon_sym_false = 42,
  anon_sym_null = 43,
  anon_sym_rand = 44,
  anon_sym_BANG = 45,
  anon_sym_LPAREN = 46,
  anon_sym_RPAREN = 47,
  anon_sym_return = 48,
  anon_sym_close = 49,
  anon_sym_save = 50,
  anon_sym_slot = 51,
  anon_sym_load = 52,
  anon_sym_erase = 53,
  anon_sym_map = 54,
  anon_sym_goto = 55,
  anon_sym_index = 56,
  anon_sym_wait = 57,
  anon_sym_block = 58,
  anon_sym_show = 59,
  anon_sym_concat = 60,
  anon_sym_delete = 61,
  anon_sym_command = 62,
  anon_sym_PLUS = 63,
  anon_sym_alias = 64,
  anon_sym_hide = 65,
  anon_sym_unhide = 66,
  sym_player = 67,
  sym_self = 68,
  anon_sym_pause = 69,
  anon_sym_unpause = 70,
  anon_sym_camera = 71,
  anon_sym_fade = 72,
  anon_sym_in = 73,
  anon_sym_DASH_GT = 74,
  anon_sym_over = 75,
  anon_sym_out = 76,
  anon_sym_shake = 77,
  sym_document = 78,
  sym_bareword_expansion = 79,
  sym_quoted_string_expansion = 80,
  sym_string_expansion = 81,
  sym_number_expansion = 82,
  sym_DURATION = 83,
  sym_duration_expansion = 84,
  sym_DISTANCE = 85,
  sym_distance_expansion = 86,
  sym_QUANTITY = 87,
  sym_color_expansion = 88,
  sym__root = 89,
  sym_include_macro = 90,
  sym_constant_assignment = 91,
  sym_add_serial_dialog_settings = 92,
  sym_serial_dialog_parameter_int = 93,
  sym_serial_dialog_parameter = 94,
  sym_add_dialog_settings = 95,
  sym_target_label = 96,
  sym_target_entity = 97,
  sym_add_dialog_settings_target = 98,
  sym__dialog_parameter_int = 99,
  sym__dialog_parameter_string = 100,
  sym_dialog_parameter = 101,
  sym_dialog_definition = 102,
  sym__dialog_block = 103,
  sym_dialog = 104,
  sym_dialog_identifier = 105,
  sym_dialog_option = 106,
  sym_serial_dialog_definition = 107,
  sym__serial_dialog_block = 108,
  sym_serial_dialog = 109,
  sym_serial_dialog_option = 110,
  sym_script_definition = 111,
  sym_script_block = 112,
  sym__script_item = 113,
  sym_json_literal = 114,
  sym_json_array = 115,
  sym_json_object = 116,
  sym_json_name_value_pair = 117,
  sym__json_item = 118,
  sym_rand_macro = 119,
  sym_label_definition = 120,
  sym__action_item = 121,
  sym_action_return_statement = 122,
  sym_action_close_dialog = 123,
  sym_action_close_serial_dialog = 124,
  sym_action_save_slot = 125,
  sym_action_load_slot = 126,
  sym_action_erase_slot = 127,
  sym_action_load_map = 128,
  sym_action_run_script = 129,
  sym_action_goto_label = 130,
  sym_action_goto_index = 131,
  sym_action_non_blocking_delay = 132,
  sym_action_blocking_delay = 133,
  sym_action_show_dialog = 134,
  sym_action_show_serial_dialog = 135,
  sym_action_concat_serial_dialog = 136,
  sym_action_delete_command = 137,
  sym_action_delete_command_arg = 138,
  sym_action_delete_alias = 139,
  sym_action_hide_command = 140,
  sym_action_unhide_command = 141,
  sym_entity = 142,
  sym_map = 143,
  sym_entity_or_map_identifier = 144,
  sym_entity_or_map_identifier_expansion = 145,
  sym_action_pause_script = 146,
  sym_action_unpause_script = 147,
  sym_action_camera_fade_in = 148,
  sym_action_camera_fade_out = 149,
  sym_action_camera_shake = 150,
  aux_sym_document_repeat1 = 151,
  aux_sym_bareword_expansion_repeat1 = 152,
  aux_sym_quoted_string_expansion_repeat1 = 153,
  aux_sym_string_expansion_repeat1 = 154,
  aux_sym_number_expansion_repeat1 = 155,
  aux_sym_duration_expansion_repeat1 = 156,
  aux_sym_distance_expansion_repeat1 = 157,
  aux_sym_color_expansion_repeat1 = 158,
  aux_sym_add_serial_dialog_settings_repeat1 = 159,
  aux_sym_add_dialog_settings_repeat1 = 160,
  aux_sym_add_dialog_settings_target_repeat1 = 161,
  aux_sym__dialog_block_repeat1 = 162,
  aux_sym_dialog_repeat1 = 163,
  aux_sym_dialog_repeat2 = 164,
  aux_sym_serial_dialog_repeat1 = 165,
  aux_sym_serial_dialog_repeat2 = 166,
  aux_sym_serial_dialog_repeat3 = 167,
  aux_sym_script_block_repeat1 = 168,
  aux_sym_json_array_repeat1 = 169,
  aux_sym_json_object_repeat1 = 170,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 171,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BOOL] = "BOOL",
  [sym_BAREWORD] = "BAREWORD",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [sym_NUMBER] = "NUMBER",
  [sym_duration_suffix] = "duration_suffix",
  [sym_distance_suffix] = "distance_suffix",
  [sym_quantity_suffix] = "quantity_suffix",
  [aux_sym_QUANTITY_token1] = "QUANTITY_token1",
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
  [sym_target_default] = "target_default",
  [anon_sym_label] = "label",
  [anon_sym_entity] = "entity",
  [anon_sym_emote] = "emote",
  [anon_sym_name] = "name",
  [anon_sym_portrait] = "portrait",
  [anon_sym_alignment] = "alignment",
  [anon_sym_border_tileset] = "border_tileset",
  [sym_identifier_type] = "identifier_type",
  [anon_sym_GT] = ">",
  [sym_serial_dialog_option_type] = "serial_dialog_option_type",
  [anon_sym_script] = "script",
  [anon_sym_json] = "json",
  [anon_sym_COLON] = ":",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [anon_sym_rand] = "rand",
  [anon_sym_BANG] = "!",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_return] = "return",
  [anon_sym_close] = "close",
  [anon_sym_save] = "save",
  [anon_sym_slot] = "slot",
  [anon_sym_load] = "load",
  [anon_sym_erase] = "erase",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
  [anon_sym_index] = "index",
  [anon_sym_wait] = "wait",
  [anon_sym_block] = "block",
  [anon_sym_show] = "show",
  [anon_sym_concat] = "concat",
  [anon_sym_delete] = "delete",
  [anon_sym_command] = "command",
  [anon_sym_PLUS] = "+",
  [anon_sym_alias] = "alias",
  [anon_sym_hide] = "hide",
  [anon_sym_unhide] = "unhide",
  [sym_player] = "player",
  [sym_self] = "self",
  [anon_sym_pause] = "pause",
  [anon_sym_unpause] = "unpause",
  [anon_sym_camera] = "camera",
  [anon_sym_fade] = "fade",
  [anon_sym_in] = "in",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_over] = "over",
  [anon_sym_out] = "out",
  [anon_sym_shake] = "shake",
  [sym_document] = "document",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_DURATION] = "DURATION",
  [sym_duration_expansion] = "duration_expansion",
  [sym_DISTANCE] = "DISTANCE",
  [sym_distance_expansion] = "distance_expansion",
  [sym_QUANTITY] = "QUANTITY",
  [sym_color_expansion] = "color_expansion",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [sym_constant_assignment] = "constant_assignment",
  [sym_add_serial_dialog_settings] = "add_serial_dialog_settings",
  [sym_serial_dialog_parameter_int] = "BAREWORD",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [sym_add_dialog_settings] = "add_dialog_settings",
  [sym_target_label] = "target_label",
  [sym_target_entity] = "target_entity",
  [sym_add_dialog_settings_target] = "add_dialog_settings_target",
  [sym__dialog_parameter_int] = "_dialog_parameter_int",
  [sym__dialog_parameter_string] = "_dialog_parameter_string",
  [sym_dialog_parameter] = "dialog_parameter",
  [sym_dialog_definition] = "dialog_definition",
  [sym__dialog_block] = "_dialog_block",
  [sym_dialog] = "dialog",
  [sym_dialog_identifier] = "dialog_identifier",
  [sym_dialog_option] = "dialog_option",
  [sym_serial_dialog_definition] = "serial_dialog_definition",
  [sym__serial_dialog_block] = "_serial_dialog_block",
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
  [sym_rand_macro] = "rand_macro",
  [sym_label_definition] = "label_definition",
  [sym__action_item] = "_action_item",
  [sym_action_return_statement] = "action_return_statement",
  [sym_action_close_dialog] = "action_close_dialog",
  [sym_action_close_serial_dialog] = "action_close_serial_dialog",
  [sym_action_save_slot] = "action_save_slot",
  [sym_action_load_slot] = "action_load_slot",
  [sym_action_erase_slot] = "action_erase_slot",
  [sym_action_load_map] = "action_load_map",
  [sym_action_run_script] = "action_run_script",
  [sym_action_goto_label] = "action_goto_label",
  [sym_action_goto_index] = "action_goto_index",
  [sym_action_non_blocking_delay] = "action_non_blocking_delay",
  [sym_action_blocking_delay] = "action_blocking_delay",
  [sym_action_show_dialog] = "action_show_dialog",
  [sym_action_show_serial_dialog] = "action_show_serial_dialog",
  [sym_action_concat_serial_dialog] = "action_concat_serial_dialog",
  [sym_action_delete_command] = "action_delete_command",
  [sym_action_delete_command_arg] = "action_delete_command_arg",
  [sym_action_delete_alias] = "action_delete_alias",
  [sym_action_hide_command] = "action_hide_command",
  [sym_action_unhide_command] = "action_unhide_command",
  [sym_entity] = "entity",
  [sym_map] = "map",
  [sym_entity_or_map_identifier] = "entity_or_map_identifier",
  [sym_entity_or_map_identifier_expansion] = "entity_or_map_identifier_expansion",
  [sym_action_pause_script] = "action_pause_script",
  [sym_action_unpause_script] = "action_unpause_script",
  [sym_action_camera_fade_in] = "action_camera_fade_in",
  [sym_action_camera_fade_out] = "action_camera_fade_out",
  [sym_action_camera_shake] = "action_camera_shake",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
  [aux_sym_distance_expansion_repeat1] = "distance_expansion_repeat1",
  [aux_sym_color_expansion_repeat1] = "color_expansion_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_repeat1] = "add_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_target_repeat1] = "add_dialog_settings_target_repeat1",
  [aux_sym__dialog_block_repeat1] = "_dialog_block_repeat1",
  [aux_sym_dialog_repeat1] = "dialog_repeat1",
  [aux_sym_dialog_repeat2] = "dialog_repeat2",
  [aux_sym_serial_dialog_repeat1] = "serial_dialog_repeat1",
  [aux_sym_serial_dialog_repeat2] = "serial_dialog_repeat2",
  [aux_sym_serial_dialog_repeat3] = "serial_dialog_repeat3",
  [aux_sym_script_block_repeat1] = "script_block_repeat1",
  [aux_sym_json_array_repeat1] = "json_array_repeat1",
  [aux_sym_json_object_repeat1] = "json_object_repeat1",
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = "entity_or_map_identifier_expansion_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_BOOL] = sym_BOOL,
  [sym_BAREWORD] = sym_BAREWORD,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [sym_NUMBER] = sym_NUMBER,
  [sym_duration_suffix] = sym_duration_suffix,
  [sym_distance_suffix] = sym_distance_suffix,
  [sym_quantity_suffix] = sym_quantity_suffix,
  [aux_sym_QUANTITY_token1] = aux_sym_QUANTITY_token1,
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
  [sym_target_default] = sym_target_default,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_emote] = anon_sym_emote,
  [anon_sym_name] = anon_sym_name,
  [anon_sym_portrait] = anon_sym_portrait,
  [anon_sym_alignment] = anon_sym_alignment,
  [anon_sym_border_tileset] = anon_sym_border_tileset,
  [sym_identifier_type] = sym_identifier_type,
  [anon_sym_GT] = anon_sym_GT,
  [sym_serial_dialog_option_type] = sym_serial_dialog_option_type,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_json] = anon_sym_json,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_rand] = anon_sym_rand,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_save] = anon_sym_save,
  [anon_sym_slot] = anon_sym_slot,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_erase] = anon_sym_erase,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_index] = anon_sym_index,
  [anon_sym_wait] = anon_sym_wait,
  [anon_sym_block] = anon_sym_block,
  [anon_sym_show] = anon_sym_show,
  [anon_sym_concat] = anon_sym_concat,
  [anon_sym_delete] = anon_sym_delete,
  [anon_sym_command] = anon_sym_command,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_hide] = anon_sym_hide,
  [anon_sym_unhide] = anon_sym_unhide,
  [sym_player] = sym_player,
  [sym_self] = sym_self,
  [anon_sym_pause] = anon_sym_pause,
  [anon_sym_unpause] = anon_sym_unpause,
  [anon_sym_camera] = anon_sym_camera,
  [anon_sym_fade] = anon_sym_fade,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_over] = anon_sym_over,
  [anon_sym_out] = anon_sym_out,
  [anon_sym_shake] = anon_sym_shake,
  [sym_document] = sym_document,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_DURATION] = sym_DURATION,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_distance_expansion] = sym_distance_expansion,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym_color_expansion] = sym_color_expansion,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_add_serial_dialog_settings] = sym_add_serial_dialog_settings,
  [sym_serial_dialog_parameter_int] = sym_BAREWORD,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [sym_add_dialog_settings] = sym_add_dialog_settings,
  [sym_target_label] = sym_target_label,
  [sym_target_entity] = sym_target_entity,
  [sym_add_dialog_settings_target] = sym_add_dialog_settings_target,
  [sym__dialog_parameter_int] = sym__dialog_parameter_int,
  [sym__dialog_parameter_string] = sym__dialog_parameter_string,
  [sym_dialog_parameter] = sym_dialog_parameter,
  [sym_dialog_definition] = sym_dialog_definition,
  [sym__dialog_block] = sym__dialog_block,
  [sym_dialog] = sym_dialog,
  [sym_dialog_identifier] = sym_dialog_identifier,
  [sym_dialog_option] = sym_dialog_option,
  [sym_serial_dialog_definition] = sym_serial_dialog_definition,
  [sym__serial_dialog_block] = sym__serial_dialog_block,
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
  [sym_rand_macro] = sym_rand_macro,
  [sym_label_definition] = sym_label_definition,
  [sym__action_item] = sym__action_item,
  [sym_action_return_statement] = sym_action_return_statement,
  [sym_action_close_dialog] = sym_action_close_dialog,
  [sym_action_close_serial_dialog] = sym_action_close_serial_dialog,
  [sym_action_save_slot] = sym_action_save_slot,
  [sym_action_load_slot] = sym_action_load_slot,
  [sym_action_erase_slot] = sym_action_erase_slot,
  [sym_action_load_map] = sym_action_load_map,
  [sym_action_run_script] = sym_action_run_script,
  [sym_action_goto_label] = sym_action_goto_label,
  [sym_action_goto_index] = sym_action_goto_index,
  [sym_action_non_blocking_delay] = sym_action_non_blocking_delay,
  [sym_action_blocking_delay] = sym_action_blocking_delay,
  [sym_action_show_dialog] = sym_action_show_dialog,
  [sym_action_show_serial_dialog] = sym_action_show_serial_dialog,
  [sym_action_concat_serial_dialog] = sym_action_concat_serial_dialog,
  [sym_action_delete_command] = sym_action_delete_command,
  [sym_action_delete_command_arg] = sym_action_delete_command_arg,
  [sym_action_delete_alias] = sym_action_delete_alias,
  [sym_action_hide_command] = sym_action_hide_command,
  [sym_action_unhide_command] = sym_action_unhide_command,
  [sym_entity] = sym_entity,
  [sym_map] = sym_map,
  [sym_entity_or_map_identifier] = sym_entity_or_map_identifier,
  [sym_entity_or_map_identifier_expansion] = sym_entity_or_map_identifier_expansion,
  [sym_action_pause_script] = sym_action_pause_script,
  [sym_action_unpause_script] = sym_action_unpause_script,
  [sym_action_camera_fade_in] = sym_action_camera_fade_in,
  [sym_action_camera_fade_out] = sym_action_camera_fade_out,
  [sym_action_camera_shake] = sym_action_camera_shake,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
  [aux_sym_distance_expansion_repeat1] = aux_sym_distance_expansion_repeat1,
  [aux_sym_color_expansion_repeat1] = aux_sym_color_expansion_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_repeat1] = aux_sym_add_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_target_repeat1] = aux_sym_add_dialog_settings_target_repeat1,
  [aux_sym__dialog_block_repeat1] = aux_sym__dialog_block_repeat1,
  [aux_sym_dialog_repeat1] = aux_sym_dialog_repeat1,
  [aux_sym_dialog_repeat2] = aux_sym_dialog_repeat2,
  [aux_sym_serial_dialog_repeat1] = aux_sym_serial_dialog_repeat1,
  [aux_sym_serial_dialog_repeat2] = aux_sym_serial_dialog_repeat2,
  [aux_sym_serial_dialog_repeat3] = aux_sym_serial_dialog_repeat3,
  [aux_sym_script_block_repeat1] = aux_sym_script_block_repeat1,
  [aux_sym_json_array_repeat1] = aux_sym_json_array_repeat1,
  [aux_sym_json_object_repeat1] = aux_sym_json_object_repeat1,
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = aux_sym_entity_or_map_identifier_expansion_repeat1,
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
  [sym_duration_suffix] = {
    .visible = true,
    .named = true,
  },
  [sym_distance_suffix] = {
    .visible = true,
    .named = true,
  },
  [sym_quantity_suffix] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_QUANTITY_token1] = {
    .visible = false,
    .named = false,
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
  [sym_target_default] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_emote] = {
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
  [sym_identifier_type] = {
    .visible = true,
    .named = true,
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
  [anon_sym_rand] = {
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
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_close] = {
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
  [anon_sym_load] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_erase] = {
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
  [anon_sym_wait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_block] = {
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
  [anon_sym_in] = {
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
  [anon_sym_out] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shake] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
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
  [sym_DURATION] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_DISTANCE] = {
    .visible = true,
    .named = true,
  },
  [sym_distance_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_QUANTITY] = {
    .visible = true,
    .named = true,
  },
  [sym_color_expansion] = {
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
  [sym_serial_dialog_parameter_int] = {
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
  [sym_target_label] = {
    .visible = true,
    .named = true,
  },
  [sym_target_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_add_dialog_settings_target] = {
    .visible = true,
    .named = true,
  },
  [sym__dialog_parameter_int] = {
    .visible = false,
    .named = true,
  },
  [sym__dialog_parameter_string] = {
    .visible = false,
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
  [sym__dialog_block] = {
    .visible = false,
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
  [sym__serial_dialog_block] = {
    .visible = false,
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
  [sym_rand_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_label_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__action_item] = {
    .visible = false,
    .named = true,
  },
  [sym_action_return_statement] = {
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
  [sym_action_non_blocking_delay] = {
    .visible = true,
    .named = true,
  },
  [sym_action_blocking_delay] = {
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
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_map] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_or_map_identifier] = {
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
  [sym_action_camera_fade_in] = {
    .visible = true,
    .named = true,
  },
  [sym_action_camera_fade_out] = {
    .visible = true,
    .named = true,
  },
  [sym_action_camera_shake] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
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
  [aux_sym_add_serial_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_dialog_settings_target_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__dialog_block_repeat1] = {
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
  [aux_sym_serial_dialog_repeat3] = {
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
  [aux_sym_entity_or_map_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_alias = 1,
  field_amplitude = 2,
  field_argument = 3,
  field_color = 4,
  field_command = 5,
  field_dialog = 6,
  field_dialog_identifier = 7,
  field_dialog_name = 8,
  field_dialog_option = 9,
  field_dialog_parameter = 10,
  field_distance = 11,
  field_duration = 12,
  field_entity = 13,
  field_entity_or_map = 14,
  field_fileName = 15,
  field_index = 16,
  field_label = 17,
  field_map = 18,
  field_message = 19,
  field_option_type = 20,
  field_property = 21,
  field_script = 22,
  field_script_name = 23,
  field_serial_dialog = 24,
  field_serial_dialog_name = 25,
  field_serial_dialog_option = 26,
  field_serial_dialog_parameter = 27,
  field_serial_message = 28,
  field_slot = 29,
  field_suffix = 30,
  field_target = 31,
  field_type = 32,
  field_value = 33,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_amplitude] = "amplitude",
  [field_argument] = "argument",
  [field_color] = "color",
  [field_command] = "command",
  [field_dialog] = "dialog",
  [field_dialog_identifier] = "dialog_identifier",
  [field_dialog_name] = "dialog_name",
  [field_dialog_option] = "dialog_option",
  [field_dialog_parameter] = "dialog_parameter",
  [field_distance] = "distance",
  [field_duration] = "duration",
  [field_entity] = "entity",
  [field_entity_or_map] = "entity_or_map",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_message] = "message",
  [field_option_type] = "option_type",
  [field_property] = "property",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_serial_dialog] = "serial_dialog",
  [field_serial_dialog_name] = "serial_dialog_name",
  [field_serial_dialog_option] = "serial_dialog_option",
  [field_serial_dialog_parameter] = "serial_dialog_parameter",
  [field_serial_message] = "serial_message",
  [field_slot] = "slot",
  [field_suffix] = "suffix",
  [field_target] = "target",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 1},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 2},
  [9] = {.index = 11, .length = 1},
  [10] = {.index = 12, .length = 1},
  [11] = {.index = 13, .length = 1},
  [12] = {.index = 14, .length = 1},
  [13] = {.index = 15, .length = 1},
  [14] = {.index = 16, .length = 1},
  [15] = {.index = 17, .length = 1},
  [16] = {.index = 18, .length = 2},
  [17] = {.index = 20, .length = 2},
  [18] = {.index = 22, .length = 1},
  [19] = {.index = 23, .length = 2},
  [20] = {.index = 25, .length = 2},
  [21] = {.index = 27, .length = 1},
  [22] = {.index = 28, .length = 2},
  [23] = {.index = 30, .length = 2},
  [24] = {.index = 32, .length = 2},
  [25] = {.index = 34, .length = 1},
  [26] = {.index = 35, .length = 1},
  [27] = {.index = 36, .length = 2},
  [28] = {.index = 38, .length = 1},
  [29] = {.index = 39, .length = 2},
  [30] = {.index = 41, .length = 1},
  [31] = {.index = 42, .length = 1},
  [32] = {.index = 43, .length = 1},
  [33] = {.index = 44, .length = 1},
  [34] = {.index = 45, .length = 1},
  [35] = {.index = 46, .length = 1},
  [36] = {.index = 47, .length = 1},
  [37] = {.index = 48, .length = 1},
  [38] = {.index = 49, .length = 1},
  [39] = {.index = 50, .length = 1},
  [40] = {.index = 51, .length = 2},
  [41] = {.index = 53, .length = 3},
  [42] = {.index = 56, .length = 2},
  [43] = {.index = 58, .length = 2},
  [44] = {.index = 60, .length = 3},
  [45] = {.index = 63, .length = 1},
  [46] = {.index = 64, .length = 2},
  [47] = {.index = 66, .length = 3},
  [48] = {.index = 69, .length = 2},
  [49] = {.index = 71, .length = 2},
  [50] = {.index = 73, .length = 1},
  [51] = {.index = 74, .length = 4},
  [52] = {.index = 78, .length = 2},
  [53] = {.index = 80, .length = 2},
  [54] = {.index = 82, .length = 2},
  [55] = {.index = 84, .length = 2},
  [56] = {.index = 86, .length = 2},
  [57] = {.index = 88, .length = 3},
  [58] = {.index = 91, .length = 3},
  [59] = {.index = 94, .length = 3},
  [60] = {.index = 97, .length = 2},
  [61] = {.index = 99, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_fileName, 1},
  [2] =
    {field_serial_dialog, 2, .inherited = true},
    {field_serial_dialog_name, 1},
  [4] =
    {field_dialog, 2, .inherited = true},
    {field_dialog_name, 1},
  [6] =
    {field_script_name, 1},
  [7] =
    {field_label, 0},
  [8] =
    {field_target, 0},
  [9] =
    {field_label, 0},
    {field_value, 2},
  [11] =
    {field_suffix, 1},
  [12] =
    {field_serial_message, 0},
  [13] =
    {field_serial_dialog_parameter, 0},
  [14] =
    {field_serial_message, 0, .inherited = true},
  [15] =
    {field_dialog, 0},
  [16] =
    {field_script, 1},
  [17] =
    {field_duration, 1},
  [18] =
    {field_entity, 1},
    {field_target, 0},
  [20] =
    {field_property, 0},
    {field_value, 1},
  [22] =
    {field_serial_dialog, 1},
  [23] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [25] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [27] =
    {field_serial_dialog_option, 0},
  [28] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [30] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [32] =
    {field_type, 0},
    {field_value, 1},
  [34] =
    {field_message, 0},
  [35] =
    {field_dialog_parameter, 0},
  [36] =
    {field_dialog_identifier, 0},
    {field_message, 1, .inherited = true},
  [38] =
    {field_dialog, 1, .inherited = true},
  [39] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [41] =
    {field_slot, 2},
  [42] =
    {field_map, 2},
  [43] =
    {field_label, 2},
  [44] =
    {field_index, 2},
  [45] =
    {field_serial_dialog_name, 2},
  [46] =
    {field_serial_dialog, 2, .inherited = true},
  [47] =
    {field_dialog_name, 2},
  [48] =
    {field_dialog, 2, .inherited = true},
  [49] =
    {field_command, 2},
  [50] =
    {field_alias, 2},
  [51] =
    {field_entity_or_map, 1},
    {field_script, 2},
  [53] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [56] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [58] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [60] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [63] =
    {field_dialog_option, 0},
  [64] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [66] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [69] =
    {field_serial_dialog, 3, .inherited = true},
    {field_serial_dialog_name, 2},
  [71] =
    {field_dialog, 3, .inherited = true},
    {field_dialog_name, 2},
  [73] =
    {field_type, 0},
  [74] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [78] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [80] =
    {field_property, 0},
    {field_value, 2},
  [82] =
    {field_argument, 4},
    {field_command, 2},
  [84] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [86] =
    {field_target, 1},
    {field_type, 0},
  [88] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [91] =
    {field_amplitude, 3},
    {field_distance, 4},
    {field_duration, 6},
  [94] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [97] =
    {field_label, 1},
    {field_script, 3},
  [99] =
    {field_color, 4},
    {field_duration, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
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
  [94] = 14,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(242);
      ADVANCE_MAP(
        '!', 458,
        '"', 5,
        '#', 446,
        '$', 238,
        '(', 459,
        ')', 460,
        '+', 488,
        ',', 405,
        '-', 14,
        '/', 11,
        ':', 450,
        ';', 423,
        '=', 424,
        '>', 444,
        'I', 152,
        '[', 404,
        ']', 406,
        '_', 445,
        'a', 54,
        'b', 130,
        'c', 18,
        'd', 66,
        'e', 147,
        'f', 30,
        'g', 172,
        'h', 114,
        'i', 153,
        'j', 194,
        'l', 20,
        'm', 22,
        'n', 43,
        'o', 154,
        'p', 23,
        'r', 37,
        's', 410,
        't', 109,
        'u', 155,
        'w', 38,
        'x', 414,
        'y', 96,
        '{', 430,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 5,
        '#', 235,
        '$', 238,
        '/', 11,
        '[', 404,
        ']', 406,
        'b', 334,
        'c', 340,
        'f', 262,
        'g', 373,
        'm', 257,
        'o', 311,
        'r', 305,
        't', 316,
        'w', 317,
        'y', 304,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 5,
        '$', 238,
        ',', 405,
        '/', 11,
        '>', 444,
        '[', 404,
        ']', 406,
        'e', 354,
        'n', 264,
        '{', 430,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(5);
      if (lookahead == '$') ADVANCE(238);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '[') ADVANCE(404);
      if (lookahead == 'i') ADVANCE(355);
      if (lookahead == 'l') ADVANCE(253);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 5,
        '-', 15,
        '/', 11,
        'I', 152,
        '[', 404,
        ']', 406,
        'a', 139,
        'b', 167,
        'd', 85,
        'e', 146,
        'f', 30,
        'i', 159,
        'l', 19,
        'm', 33,
        'n', 43,
        'o', 220,
        'p', 137,
        's', 83,
        't', 183,
        'w', 186,
        '{', 430,
        '}', 431,
        '#', 445,
        '_', 445,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(452);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(407);
      if (lookahead == '\\') ADVANCE(239);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '$', 238,
        ')', 460,
        ',', 405,
        '/', 11,
        ';', 423,
        '[', 404,
        ']', 406,
        'b', 336,
        'c', 250,
        'd', 300,
        'e', 369,
        'g', 361,
        'h', 322,
        'j', 376,
        'l', 365,
        'p', 254,
        'r', 255,
        's', 251,
        'u', 347,
        'w', 258,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        '$', 238,
        ',', 405,
        '/', 11,
        ';', 423,
        '[', 404,
        ']', 406,
        'm', 191,
        'p', 112,
        's', 409,
        'x', 414,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      END_STATE();
    case 8:
      if (lookahead == '$') ADVANCE(238);
      if (lookahead == ',') ADVANCE(405);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == ';') ADVANCE(423);
      if (lookahead == '[') ADVANCE(404);
      if (lookahead == ']') ADVANCE(406);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        ')', 460,
        '/', 11,
        'b', 336,
        'c', 250,
        'd', 300,
        'e', 369,
        'g', 361,
        'h', 322,
        'j', 376,
        'l', 365,
        'm', 375,
        'p', 254,
        'r', 255,
        's', 411,
        'u', 347,
        'w', 258,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        ')', 460,
        '/', 11,
        'b', 336,
        'c', 250,
        'd', 300,
        'e', 369,
        'g', 361,
        'h', 322,
        'j', 376,
        'l', 365,
        'p', 254,
        'r', 255,
        's', 251,
        'u', 347,
        'w', 258,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(244);
      END_STATE();
    case 12:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead == '/') ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '>') ADVANCE(505);
      if (lookahead == 'I') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(452);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(452);
      END_STATE();
    case 16:
      if (lookahead == '_') ADVANCE(62);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(213);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(150);
      if (lookahead == 'l') ADVANCE(171);
      if (lookahead == 'o') ADVANCE(145);
      if (lookahead == 'y') ADVANCE(40);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(108);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(108);
      if (lookahead == 's') ADVANCE(409);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(224);
      if (lookahead == 'i') ADVANCE(230);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(185);
      if (lookahead == 'x') ADVANCE(413);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(224);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(185);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(227);
      if (lookahead == 'h') ADVANCE(168);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(234);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(416);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(179);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(500);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(138);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(67);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(178);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(192);
      if (lookahead == 'g') ADVANCE(165);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(129);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(161);
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'h') ADVANCE(118);
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(222);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(156);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(133);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(148);
      if (lookahead == 'u') ADVANCE(135);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(196);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(162);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(141);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(123);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(226);
      END_STATE();
    case 49:
      if (lookahead == 'b') ADVANCE(90);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(127);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(128);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(71);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(55);
      if (lookahead == 'l') ADVANCE(113);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(425);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(416);
      if (lookahead == 't') ADVANCE(221);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(468);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(456);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(487);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(68);
      if (lookahead == 'l') ADVANCE(197);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(69);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(125);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(80);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(81);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(92);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(103);
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(416);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(502);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(490);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(440);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(415);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(465);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(453);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(463);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(439);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(470);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(454);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(496);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(485);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(492);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(421);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(498);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(134);
      if (lookahead == 'h') ADVANCE(36);
      if (lookahead == 'l') ADVANCE(177);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(508);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(231);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(156);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(188);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(182);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(163);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(207);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(216);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(164);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(200);
      END_STATE();
    case 100:
      if (lookahead == 'f') ADVANCE(495);
      END_STATE();
    case 101:
      if (lookahead == 'f') ADVANCE(117);
      END_STATE();
    case 102:
      if (lookahead == 'f') ADVANCE(39);
      END_STATE();
    case 103:
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 104:
      if (lookahead == 'g') ADVANCE(433);
      END_STATE();
    case 105:
      if (lookahead == 'g') ADVANCE(427);
      END_STATE();
    case 106:
      if (lookahead == 'g') ADVANCE(193);
      END_STATE();
    case 107:
      if (lookahead == 'g') ADVANCE(165);
      END_STATE();
    case 108:
      if (lookahead == 'g') ADVANCE(94);
      if (lookahead == 'p') ADVANCE(472);
      END_STATE();
    case 109:
      if (lookahead == 'h') ADVANCE(184);
      if (lookahead == 'r') ADVANCE(223);
      if (lookahead == 'w') ADVANCE(111);
      END_STATE();
    case 110:
      if (lookahead == 'h') ADVANCE(126);
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 111:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 112:
      if (lookahead == 'i') ADVANCE(230);
      if (lookahead == 'x') ADVANCE(413);
      END_STATE();
    case 113:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 114:
      if (lookahead == 'i') ADVANCE(61);
      END_STATE();
    case 115:
      if (lookahead == 'i') ADVANCE(107);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(202);
      END_STATE();
    case 117:
      if (lookahead == 'i') ADVANCE(166);
      END_STATE();
    case 118:
      if (lookahead == 'i') ADVANCE(211);
      END_STATE();
    case 119:
      if (lookahead == 'i') ADVANCE(143);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(209);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(210);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(160);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(205);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 127:
      if (lookahead == 'k') ADVANCE(416);
      END_STATE();
    case 128:
      if (lookahead == 'k') ADVANCE(479);
      END_STATE();
    case 129:
      if (lookahead == 'k') ADVANCE(84);
      END_STATE();
    case 130:
      if (lookahead == 'l') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(190);
      END_STATE();
    case 131:
      if (lookahead == 'l') ADVANCE(455);
      END_STATE();
    case 132:
      if (lookahead == 'l') ADVANCE(436);
      END_STATE();
    case 133:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 134:
      if (lookahead == 'l') ADVANCE(100);
      if (lookahead == 'r') ADVANCE(124);
      if (lookahead == 't') ADVANCE(217);
      END_STATE();
    case 135:
      if (lookahead == 'l') ADVANCE(131);
      END_STATE();
    case 136:
      if (lookahead == 'l') ADVANCE(225);
      END_STATE();
    case 137:
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(185);
      END_STATE();
    case 138:
      if (lookahead == 'l') ADVANCE(170);
      END_STATE();
    case 139:
      if (lookahead == 'l') ADVANCE(115);
      END_STATE();
    case 140:
      if (lookahead == 'l') ADVANCE(173);
      END_STATE();
    case 141:
      if (lookahead == 'l') ADVANCE(175);
      END_STATE();
    case 142:
      if (lookahead == 'l') ADVANCE(204);
      END_STATE();
    case 143:
      if (lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 144:
      if (lookahead == 'l') ADVANCE(140);
      END_STATE();
    case 145:
      if (lookahead == 'm') ADVANCE(149);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 146:
      if (lookahead == 'm') ADVANCE(174);
      if (lookahead == 'n') ADVANCE(219);
      END_STATE();
    case 147:
      if (lookahead == 'm') ADVANCE(174);
      if (lookahead == 'n') ADVANCE(219);
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 148:
      if (lookahead == 'm') ADVANCE(70);
      END_STATE();
    case 149:
      if (lookahead == 'm') ADVANCE(45);
      END_STATE();
    case 150:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 151:
      if (lookahead == 'm') ADVANCE(98);
      END_STATE();
    case 152:
      if (lookahead == 'n') ADVANCE(101);
      END_STATE();
    case 153:
      if (lookahead == 'n') ADVANCE(504);
      END_STATE();
    case 154:
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(201);
      if (lookahead == 'v') ADVANCE(87);
      END_STATE();
    case 155:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 156:
      if (lookahead == 'n') ADVANCE(416);
      END_STATE();
    case 157:
      if (lookahead == 'n') ADVANCE(448);
      END_STATE();
    case 158:
      if (lookahead == 'n') ADVANCE(461);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(503);
      END_STATE();
    case 160:
      if (lookahead == 'n') ADVANCE(106);
      END_STATE();
    case 161:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 162:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 163:
      if (lookahead == 'n') ADVANCE(214);
      END_STATE();
    case 164:
      if (lookahead == 'n') ADVANCE(206);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(151);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(121);
      END_STATE();
    case 167:
      if (lookahead == 'o') ADVANCE(190);
      END_STATE();
    case 168:
      if (lookahead == 'o') ADVANCE(229);
      END_STATE();
    case 169:
      if (lookahead == 'o') ADVANCE(473);
      END_STATE();
    case 170:
      if (lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 171:
      if (lookahead == 'o') ADVANCE(195);
      END_STATE();
    case 172:
      if (lookahead == 'o') ADVANCE(212);
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 173:
      if (lookahead == 'o') ADVANCE(228);
      END_STATE();
    case 174:
      if (lookahead == 'o') ADVANCE(215);
      END_STATE();
    case 175:
      if (lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 176:
      if (lookahead == 'o') ADVANCE(157);
      END_STATE();
    case 177:
      if (lookahead == 'o') ADVANCE(208);
      END_STATE();
    case 178:
      if (lookahead == 'p') ADVANCE(472);
      END_STATE();
    case 179:
      if (lookahead == 'p') ADVANCE(432);
      END_STATE();
    case 180:
      if (lookahead == 'r') ADVANCE(506);
      END_STATE();
    case 181:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 182:
      if (lookahead == 'r') ADVANCE(494);
      END_STATE();
    case 183:
      if (lookahead == 'r') ADVANCE(223);
      END_STATE();
    case 184:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 185:
      if (lookahead == 'r') ADVANCE(218);
      END_STATE();
    case 186:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 187:
      if (lookahead == 'r') ADVANCE(158);
      END_STATE();
    case 188:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 189:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 190:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 191:
      if (lookahead == 's') ADVANCE(409);
      END_STATE();
    case 192:
      if (lookahead == 's') ADVANCE(489);
      END_STATE();
    case 193:
      if (lookahead == 's') ADVANCE(429);
      END_STATE();
    case 194:
      if (lookahead == 's') ADVANCE(176);
      END_STATE();
    case 195:
      if (lookahead == 's') ADVANCE(74);
      END_STATE();
    case 196:
      if (lookahead == 's') ADVANCE(76);
      END_STATE();
    case 197:
      if (lookahead == 's') ADVANCE(77);
      END_STATE();
    case 198:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 199:
      if (lookahead == 's') ADVANCE(82);
      END_STATE();
    case 200:
      if (lookahead == 's') ADVANCE(95);
      END_STATE();
    case 201:
      if (lookahead == 't') ADVANCE(507);
      END_STATE();
    case 202:
      if (lookahead == 't') ADVANCE(477);
      END_STATE();
    case 203:
      if (lookahead == 't') ADVANCE(483);
      END_STATE();
    case 204:
      if (lookahead == 't') ADVANCE(435);
      END_STATE();
    case 205:
      if (lookahead == 't') ADVANCE(441);
      END_STATE();
    case 206:
      if (lookahead == 't') ADVANCE(442);
      END_STATE();
    case 207:
      if (lookahead == 't') ADVANCE(443);
      END_STATE();
    case 208:
      if (lookahead == 't') ADVANCE(467);
      END_STATE();
    case 209:
      if (lookahead == 't') ADVANCE(232);
      END_STATE();
    case 210:
      if (lookahead == 't') ADVANCE(233);
      END_STATE();
    case 211:
      if (lookahead == 't') ADVANCE(67);
      END_STATE();
    case 212:
      if (lookahead == 't') ADVANCE(169);
      END_STATE();
    case 213:
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 214:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 215:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 216:
      if (lookahead == 't') ADVANCE(79);
      END_STATE();
    case 217:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 218:
      if (lookahead == 't') ADVANCE(189);
      END_STATE();
    case 219:
      if (lookahead == 't') ADVANCE(120);
      END_STATE();
    case 220:
      if (lookahead == 'u') ADVANCE(201);
      END_STATE();
    case 221:
      if (lookahead == 'u') ADVANCE(187);
      END_STATE();
    case 222:
      if (lookahead == 'u') ADVANCE(142);
      END_STATE();
    case 223:
      if (lookahead == 'u') ADVANCE(73);
      END_STATE();
    case 224:
      if (lookahead == 'u') ADVANCE(198);
      END_STATE();
    case 225:
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 226:
      if (lookahead == 'u') ADVANCE(199);
      END_STATE();
    case 227:
      if (lookahead == 'v') ADVANCE(72);
      END_STATE();
    case 228:
      if (lookahead == 'w') ADVANCE(416);
      END_STATE();
    case 229:
      if (lookahead == 'w') ADVANCE(481);
      END_STATE();
    case 230:
      if (lookahead == 'x') ADVANCE(413);
      END_STATE();
    case 231:
      if (lookahead == 'x') ADVANCE(475);
      END_STATE();
    case 232:
      if (lookahead == 'y') ADVANCE(438);
      END_STATE();
    case 233:
      if (lookahead == 'y') ADVANCE(451);
      END_STATE();
    case 234:
      if (lookahead == 'y') ADVANCE(93);
      END_STATE();
    case 235:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(237);
      END_STATE();
    case 236:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(419);
      END_STATE();
    case 237:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(236);
      END_STATE();
    case 238:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(420);
      END_STATE();
    case 239:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(5);
      END_STATE();
    case 240:
      if (eof) ADVANCE(242);
      ADVANCE_MAP(
        '!', 458,
        '"', 5,
        '#', 446,
        '$', 238,
        '(', 459,
        ')', 460,
        '+', 488,
        ',', 405,
        '-', 14,
        '/', 11,
        ':', 450,
        ';', 423,
        '=', 424,
        '>', 444,
        'I', 152,
        '[', 404,
        ']', 406,
        '_', 445,
        'a', 54,
        'b', 130,
        'c', 18,
        'd', 66,
        'e', 147,
        'f', 30,
        'g', 172,
        'h', 114,
        'i', 153,
        'j', 194,
        'l', 20,
        'm', 21,
        'n', 43,
        'o', 154,
        'p', 24,
        'r', 37,
        's', 25,
        't', 109,
        'u', 155,
        'w', 38,
        'y', 96,
        '{', 430,
        '}', 431,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(240);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      END_STATE();
    case 241:
      if (eof) ADVANCE(242);
      ADVANCE_MAP(
        '"', 5,
        '$', 238,
        '/', 11,
        ';', 423,
        '[', 404,
        ']', 406,
        'a', 281,
        'd', 319,
        'i', 346,
        's', 269,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(241);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(13);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(244);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(244);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(343);
      if (lookahead == 'l') ADVANCE(362);
      if (lookahead == 'o') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(398);
      if (lookahead == 'h') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(501);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(352);
      if (lookahead == 'e') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(272);
      if (lookahead == 'u') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(368);
      if (lookahead == 'e') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(491);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(471);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(497);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(486);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(493);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(312);
      if (lookahead == 'n') ADVANCE(245);
      if (lookahead == 'p') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(434);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(370);
      if (lookahead == 'r') ADVANCE(395);
      if (lookahead == 'w') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(326);
      if (lookahead == 'p') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(366);
      if (lookahead == 'y') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(449);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(462);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(447);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(478);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(482);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(476);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(408);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(227);
      if (lookahead == 'h') ADVANCE(168);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(398);
      if (lookahead == 'h') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(416);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(417);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(418);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(420);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(237);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(452);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(403);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(136);
      if (lookahead == 'd') ADVANCE(86);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 241},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 6},
  [18] = {.lex_state = 6},
  [19] = {.lex_state = 6},
  [20] = {.lex_state = 6},
  [21] = {.lex_state = 6},
  [22] = {.lex_state = 6},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 6},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 6},
  [29] = {.lex_state = 6},
  [30] = {.lex_state = 6},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 6},
  [36] = {.lex_state = 6},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 6},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 6},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 6},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 6},
  [46] = {.lex_state = 6},
  [47] = {.lex_state = 6},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 241},
  [51] = {.lex_state = 241},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 241},
  [61] = {.lex_state = 241},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 241},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 241},
  [67] = {.lex_state = 241},
  [68] = {.lex_state = 241},
  [69] = {.lex_state = 241},
  [70] = {.lex_state = 241},
  [71] = {.lex_state = 241},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 241},
  [74] = {.lex_state = 241},
  [75] = {.lex_state = 241},
  [76] = {.lex_state = 4},
  [77] = {.lex_state = 4},
  [78] = {.lex_state = 241},
  [79] = {.lex_state = 241},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 241},
  [82] = {.lex_state = 241},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 7},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 241},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 241},
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 241},
  [122] = {.lex_state = 241},
  [123] = {.lex_state = 241},
  [124] = {.lex_state = 241},
  [125] = {.lex_state = 2},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 241},
  [130] = {.lex_state = 2},
  [131] = {.lex_state = 2},
  [132] = {.lex_state = 241},
  [133] = {.lex_state = 241},
  [134] = {.lex_state = 1},
  [135] = {.lex_state = 1},
  [136] = {.lex_state = 2},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 241},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 4},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 241},
  [143] = {.lex_state = 241},
  [144] = {.lex_state = 2},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 2},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 4},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 7},
  [151] = {.lex_state = 4},
  [152] = {.lex_state = 2},
  [153] = {.lex_state = 4},
  [154] = {.lex_state = 4},
  [155] = {.lex_state = 4},
  [156] = {.lex_state = 241},
  [157] = {.lex_state = 241},
  [158] = {.lex_state = 4},
  [159] = {.lex_state = 2},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 2},
  [162] = {.lex_state = 241},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 4},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 241},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 2},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 2},
  [175] = {.lex_state = 241},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 241},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 2},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 2},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 1},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 2},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 2},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 241},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 2},
  [197] = {.lex_state = 2},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 241},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 2},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 2},
  [213] = {.lex_state = 1},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 4},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 2},
  [220] = {.lex_state = 1},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 2},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 241},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 4},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 2},
  [234] = {.lex_state = 2},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 4},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 4},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 4},
  [242] = {.lex_state = 241},
  [243] = {.lex_state = 241},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 241},
  [247] = {.lex_state = 2},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 1},
  [250] = {.lex_state = 2},
  [251] = {.lex_state = 4},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 4},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 4},
  [265] = {.lex_state = 241},
  [266] = {.lex_state = 2},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 4},
  [272] = {.lex_state = 2},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 4},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 4},
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
  [295] = {.lex_state = 4},
  [296] = {.lex_state = 0},
  [297] = {.lex_state = 0},
  [298] = {.lex_state = 0},
  [299] = {.lex_state = 0},
  [300] = {.lex_state = 0},
  [301] = {.lex_state = 0},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 0},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 4},
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
  [336] = {.lex_state = 4},
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
    [sym_duration_suffix] = ACTIONS(1),
    [sym_distance_suffix] = ACTIONS(1),
    [sym_quantity_suffix] = ACTIONS(1),
    [aux_sym_QUANTITY_token1] = ACTIONS(1),
    [sym_COLOR] = ACTIONS(1),
    [sym_CONSTANT] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_add] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_wrap] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [sym_target_default] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_emote] = ACTIONS(1),
    [anon_sym_name] = ACTIONS(1),
    [anon_sym_portrait] = ACTIONS(1),
    [anon_sym_alignment] = ACTIONS(1),
    [anon_sym_border_tileset] = ACTIONS(1),
    [sym_identifier_type] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym_serial_dialog_option_type] = ACTIONS(1),
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_json_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_rand] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_save] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_erase] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
    [anon_sym_wait] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
    [anon_sym_show] = ACTIONS(1),
    [anon_sym_concat] = ACTIONS(1),
    [anon_sym_delete] = ACTIONS(1),
    [anon_sym_command] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_hide] = ACTIONS(1),
    [anon_sym_unhide] = ACTIONS(1),
    [sym_player] = ACTIONS(1),
    [anon_sym_pause] = ACTIONS(1),
    [anon_sym_unpause] = ACTIONS(1),
    [anon_sym_camera] = ACTIONS(1),
    [anon_sym_fade] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
    [anon_sym_out] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(326),
    [sym__root] = STATE(51),
    [sym_include_macro] = STATE(51),
    [sym_constant_assignment] = STATE(51),
    [sym_add_serial_dialog_settings] = STATE(51),
    [sym_add_dialog_settings] = STATE(51),
    [sym_dialog_definition] = STATE(51),
    [sym_serial_dialog_definition] = STATE(51),
    [sym_script_definition] = STATE(51),
    [aux_sym_document_repeat1] = STATE(51),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(7),
    [sym_QUOTED_STRING] = ACTIONS(9),
    [sym_CONSTANT] = ACTIONS(11),
    [anon_sym_include] = ACTIONS(13),
    [anon_sym_add] = ACTIONS(15),
    [anon_sym_serial_dialog] = ACTIONS(17),
    [anon_sym_dialog] = ACTIONS(19),
    [anon_sym_script] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 22,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(28), 1,
      anon_sym_json,
    ACTIONS(31), 1,
      anon_sym_rand,
    ACTIONS(34), 1,
      anon_sym_return,
    ACTIONS(37), 1,
      anon_sym_close,
    ACTIONS(40), 1,
      anon_sym_save,
    ACTIONS(43), 1,
      anon_sym_load,
    ACTIONS(46), 1,
      anon_sym_erase,
    ACTIONS(49), 1,
      anon_sym_goto,
    ACTIONS(52), 1,
      anon_sym_wait,
    ACTIONS(55), 1,
      anon_sym_block,
    ACTIONS(58), 1,
      anon_sym_show,
    ACTIONS(61), 1,
      anon_sym_concat,
    ACTIONS(64), 1,
      anon_sym_delete,
    ACTIONS(67), 1,
      anon_sym_hide,
    ACTIONS(70), 1,
      anon_sym_unhide,
    ACTIONS(73), 1,
      anon_sym_pause,
    ACTIONS(76), 1,
      anon_sym_unpause,
    ACTIONS(79), 1,
      anon_sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(26), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 31,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade_in,
      sym_action_camera_fade_out,
      sym_action_camera_shake,
      aux_sym_script_block_repeat1,
  [99] = 22,
    ACTIONS(82), 1,
      sym_BAREWORD,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    ACTIONS(86), 1,
      anon_sym_json,
    ACTIONS(88), 1,
      anon_sym_rand,
    ACTIONS(90), 1,
      anon_sym_return,
    ACTIONS(92), 1,
      anon_sym_close,
    ACTIONS(94), 1,
      anon_sym_save,
    ACTIONS(96), 1,
      anon_sym_load,
    ACTIONS(98), 1,
      anon_sym_erase,
    ACTIONS(100), 1,
      anon_sym_goto,
    ACTIONS(102), 1,
      anon_sym_wait,
    ACTIONS(104), 1,
      anon_sym_block,
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
      anon_sym_pause,
    ACTIONS(118), 1,
      anon_sym_unpause,
    ACTIONS(120), 1,
      anon_sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 31,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade_in,
      sym_action_camera_fade_out,
      sym_action_camera_shake,
      aux_sym_script_block_repeat1,
  [197] = 22,
    ACTIONS(82), 1,
      sym_BAREWORD,
    ACTIONS(86), 1,
      anon_sym_json,
    ACTIONS(88), 1,
      anon_sym_rand,
    ACTIONS(90), 1,
      anon_sym_return,
    ACTIONS(92), 1,
      anon_sym_close,
    ACTIONS(94), 1,
      anon_sym_save,
    ACTIONS(96), 1,
      anon_sym_load,
    ACTIONS(98), 1,
      anon_sym_erase,
    ACTIONS(100), 1,
      anon_sym_goto,
    ACTIONS(102), 1,
      anon_sym_wait,
    ACTIONS(104), 1,
      anon_sym_block,
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
      anon_sym_pause,
    ACTIONS(118), 1,
      anon_sym_unpause,
    ACTIONS(120), 1,
      anon_sym_camera,
    ACTIONS(122), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 31,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade_in,
      sym_action_camera_fade_out,
      sym_action_camera_shake,
      aux_sym_script_block_repeat1,
  [295] = 22,
    ACTIONS(82), 1,
      sym_BAREWORD,
    ACTIONS(86), 1,
      anon_sym_json,
    ACTIONS(88), 1,
      anon_sym_rand,
    ACTIONS(90), 1,
      anon_sym_return,
    ACTIONS(92), 1,
      anon_sym_close,
    ACTIONS(94), 1,
      anon_sym_save,
    ACTIONS(96), 1,
      anon_sym_load,
    ACTIONS(98), 1,
      anon_sym_erase,
    ACTIONS(100), 1,
      anon_sym_goto,
    ACTIONS(102), 1,
      anon_sym_wait,
    ACTIONS(104), 1,
      anon_sym_block,
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
      anon_sym_pause,
    ACTIONS(118), 1,
      anon_sym_unpause,
    ACTIONS(120), 1,
      anon_sym_camera,
    ACTIONS(124), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 31,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade_in,
      sym_action_camera_fade_out,
      sym_action_camera_shake,
      aux_sym_script_block_repeat1,
  [393] = 22,
    ACTIONS(82), 1,
      sym_BAREWORD,
    ACTIONS(86), 1,
      anon_sym_json,
    ACTIONS(88), 1,
      anon_sym_rand,
    ACTIONS(90), 1,
      anon_sym_return,
    ACTIONS(92), 1,
      anon_sym_close,
    ACTIONS(94), 1,
      anon_sym_save,
    ACTIONS(96), 1,
      anon_sym_load,
    ACTIONS(98), 1,
      anon_sym_erase,
    ACTIONS(100), 1,
      anon_sym_goto,
    ACTIONS(102), 1,
      anon_sym_wait,
    ACTIONS(104), 1,
      anon_sym_block,
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
      anon_sym_pause,
    ACTIONS(118), 1,
      anon_sym_unpause,
    ACTIONS(120), 1,
      anon_sym_camera,
    ACTIONS(126), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 31,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      sym_action_pause_script,
      sym_action_unpause_script,
      sym_action_camera_fade_in,
      sym_action_camera_fade_out,
      sym_action_camera_shake,
      aux_sym_script_block_repeat1,
  [491] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(130), 8,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(128), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [527] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(134), 6,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(132), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [561] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(138), 6,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(136), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [595] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 6,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(140), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [629] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(146), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(144), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [661] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(150), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(148), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [693] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(154), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(152), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [725] = 4,
    ACTIONS(158), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(156), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [758] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(164), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(162), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [788] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(168), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(166), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [818] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(172), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(170), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [848] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(176), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(174), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [878] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(180), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(178), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [908] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(184), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(182), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [938] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(188), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(186), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [968] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(192), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(190), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [998] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(196), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(194), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1028] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(200), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(198), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1058] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(204), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(202), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1088] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(208), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(206), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1118] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(212), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(210), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1148] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(216), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(214), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1178] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(220), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(218), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1208] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(224), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(222), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1238] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(228), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(226), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1268] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(232), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(230), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1298] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(236), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(234), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1328] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(238), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1358] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(244), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(242), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1388] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(248), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(246), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1418] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(250), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1448] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(256), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(254), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1478] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(260), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(258), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1508] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(264), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(262), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1538] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(268), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(266), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1568] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(272), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(270), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1598] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(276), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(274), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1628] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(280), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(278), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1658] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(284), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(282), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1688] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(288), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(286), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1718] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(292), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(290), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1748] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(296), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(294), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1778] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(300), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(298), 19,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
      anon_sym_show,
      anon_sym_concat,
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1808] = 11,
    ACTIONS(302), 1,
      ts_builtin_sym_end,
    ACTIONS(304), 1,
      sym_BAREWORD,
    ACTIONS(307), 1,
      sym_QUOTED_STRING,
    ACTIONS(310), 1,
      sym_CONSTANT,
    ACTIONS(313), 1,
      anon_sym_include,
    ACTIONS(316), 1,
      anon_sym_add,
    ACTIONS(319), 1,
      anon_sym_serial_dialog,
    ACTIONS(322), 1,
      anon_sym_dialog,
    ACTIONS(325), 1,
      anon_sym_script,
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
      aux_sym_document_repeat1,
  [1851] = 11,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      sym_QUOTED_STRING,
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
    ACTIONS(328), 1,
      ts_builtin_sym_end,
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
      aux_sym_document_repeat1,
  [1894] = 8,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(330), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(332), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(335), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1926] = 9,
    ACTIONS(338), 1,
      sym_QUOTED_STRING,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(88), 1,
      aux_sym_dialog_repeat1,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1960] = 9,
    ACTIONS(338), 1,
      sym_QUOTED_STRING,
    STATE(53), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(93), 1,
      aux_sym_dialog_repeat1,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1994] = 8,
    ACTIONS(344), 1,
      anon_sym_RBRACE,
    STATE(56), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2025] = 8,
    ACTIONS(346), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2056] = 8,
    ACTIONS(348), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2087] = 8,
    ACTIONS(350), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(80), 1,
      sym_dialog_parameter,
    STATE(181), 1,
      sym__dialog_parameter_string,
    STATE(246), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(342), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2118] = 6,
    ACTIONS(352), 1,
      anon_sym_LBRACK,
    ACTIONS(354), 1,
      anon_sym_RBRACK,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(211), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(356), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2144] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(360), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(362), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2163] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(364), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(366), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2182] = 6,
    ACTIONS(372), 1,
      sym_NUMBER,
    ACTIONS(374), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(368), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(370), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(309), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [2207] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(376), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(378), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2226] = 5,
    ACTIONS(352), 1,
      anon_sym_LBRACK,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(237), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(380), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2249] = 5,
    ACTIONS(352), 1,
      anon_sym_LBRACK,
    ACTIONS(358), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(253), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(382), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2272] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(384), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(386), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2291] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(388), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(390), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2309] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(392), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(394), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2327] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(396), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(398), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2345] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(400), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(402), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2363] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(404), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(406), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2381] = 8,
    ACTIONS(408), 1,
      anon_sym_LBRACK,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
    STATE(112), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [2409] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(416), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(418), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2427] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(420), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(422), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2445] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(424), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(426), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2463] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(428), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2479] = 8,
    ACTIONS(408), 1,
      anon_sym_LBRACK,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
    STATE(127), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [2507] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(430), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(432), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2525] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(434), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(436), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2543] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(438), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2559] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(440), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(442), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2577] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(444), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(446), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2595] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(448), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2610] = 8,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    ACTIONS(450), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    STATE(248), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
  [2637] = 8,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    ACTIONS(452), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    STATE(202), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
  [2664] = 8,
    ACTIONS(454), 1,
      anon_sym_RBRACE,
    ACTIONS(456), 1,
      sym_target_default,
    ACTIONS(459), 1,
      anon_sym_label,
    ACTIONS(462), 1,
      anon_sym_entity,
    STATE(222), 1,
      sym_target_entity,
    STATE(234), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(86), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2691] = 8,
    ACTIONS(465), 1,
      anon_sym_RBRACE,
    ACTIONS(467), 1,
      sym_target_default,
    ACTIONS(469), 1,
      anon_sym_label,
    ACTIONS(471), 1,
      anon_sym_entity,
    STATE(222), 1,
      sym_target_entity,
    STATE(234), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(89), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2718] = 8,
    ACTIONS(338), 1,
      sym_QUOTED_STRING,
    ACTIONS(475), 1,
      sym_identifier_type,
    ACTIONS(477), 1,
      anon_sym_GT,
    STATE(100), 1,
      aux_sym_dialog_repeat1,
    STATE(105), 1,
      aux_sym_dialog_repeat2,
    STATE(152), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(473), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2745] = 8,
    ACTIONS(467), 1,
      sym_target_default,
    ACTIONS(469), 1,
      anon_sym_label,
    ACTIONS(471), 1,
      anon_sym_entity,
    ACTIONS(479), 1,
      anon_sym_RBRACE,
    STATE(222), 1,
      sym_target_entity,
    STATE(234), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(86), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2772] = 8,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    ACTIONS(481), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    STATE(248), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
  [2799] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(483), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2814] = 9,
    ACTIONS(485), 1,
      sym_QUOTED_STRING,
    ACTIONS(487), 1,
      anon_sym_RBRACE,
    ACTIONS(489), 1,
      anon_sym_wrap,
    STATE(102), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(109), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    STATE(244), 1,
      sym_serial_dialog_parameter,
    STATE(323), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2843] = 8,
    ACTIONS(338), 1,
      sym_QUOTED_STRING,
    ACTIONS(477), 1,
      anon_sym_GT,
    ACTIONS(493), 1,
      sym_identifier_type,
    STATE(100), 1,
      aux_sym_dialog_repeat1,
    STATE(101), 1,
      aux_sym_dialog_repeat2,
    STATE(152), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(491), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2870] = 3,
    ACTIONS(495), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2886] = 7,
    ACTIONS(497), 1,
      sym_BAREWORD,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    ACTIONS(503), 1,
      anon_sym_label,
    ACTIONS(505), 1,
      anon_sym_index,
    STATE(276), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(501), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2910] = 7,
    ACTIONS(410), 1,
      anon_sym_entity,
    ACTIONS(412), 1,
      anon_sym_map,
    STATE(98), 1,
      sym_map,
    STATE(174), 1,
      sym_entity,
    STATE(248), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_player,
      sym_self,
  [2934] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(507), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2947] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(509), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2960] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(511), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2973] = 5,
    ACTIONS(515), 1,
      sym_QUOTED_STRING,
    ACTIONS(518), 1,
      sym_identifier_type,
    STATE(100), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(513), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2992] = 6,
    ACTIONS(477), 1,
      anon_sym_GT,
    ACTIONS(522), 1,
      sym_identifier_type,
    STATE(106), 1,
      aux_sym_dialog_repeat2,
    STATE(152), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(520), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3013] = 7,
    ACTIONS(485), 1,
      sym_QUOTED_STRING,
    ACTIONS(489), 1,
      anon_sym_wrap,
    STATE(104), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(114), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    STATE(244), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3036] = 7,
    ACTIONS(524), 1,
      sym_BAREWORD,
    ACTIONS(527), 1,
      anon_sym_RBRACE,
    ACTIONS(529), 1,
      sym_identifier_type,
    STATE(54), 1,
      sym_dialog_identifier,
    STATE(103), 1,
      aux_sym__dialog_block_repeat1,
    STATE(185), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3059] = 7,
    ACTIONS(485), 1,
      sym_QUOTED_STRING,
    ACTIONS(532), 1,
      anon_sym_RBRACE,
    ACTIONS(534), 1,
      sym_serial_dialog_option_type,
    STATE(151), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(164), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(241), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3082] = 6,
    ACTIONS(477), 1,
      anon_sym_GT,
    ACTIONS(538), 1,
      sym_identifier_type,
    STATE(106), 1,
      aux_sym_dialog_repeat2,
    STATE(152), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(536), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3103] = 6,
    ACTIONS(542), 1,
      sym_identifier_type,
    ACTIONS(544), 1,
      anon_sym_GT,
    STATE(106), 1,
      aux_sym_dialog_repeat2,
    STATE(152), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(540), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3124] = 7,
    ACTIONS(547), 1,
      sym_BAREWORD,
    ACTIONS(549), 1,
      anon_sym_RBRACE,
    ACTIONS(551), 1,
      sym_identifier_type,
    STATE(54), 1,
      sym_dialog_identifier,
    STATE(108), 1,
      aux_sym__dialog_block_repeat1,
    STATE(185), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3147] = 7,
    ACTIONS(547), 1,
      sym_BAREWORD,
    ACTIONS(551), 1,
      sym_identifier_type,
    ACTIONS(553), 1,
      anon_sym_RBRACE,
    STATE(54), 1,
      sym_dialog_identifier,
    STATE(103), 1,
      aux_sym__dialog_block_repeat1,
    STATE(185), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3170] = 7,
    ACTIONS(485), 1,
      sym_QUOTED_STRING,
    ACTIONS(534), 1,
      sym_serial_dialog_option_type,
    ACTIONS(555), 1,
      anon_sym_RBRACE,
    STATE(151), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(155), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(241), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3193] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(337), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(557), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3209] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(563), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(285), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3227] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(344), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(565), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3243] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(338), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(567), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3259] = 6,
    ACTIONS(569), 1,
      sym_QUOTED_STRING,
    ACTIONS(571), 1,
      anon_sym_wrap,
    STATE(114), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    STATE(244), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3279] = 5,
    ACTIONS(574), 1,
      anon_sym_RBRACE,
    ACTIONS(576), 1,
      anon_sym_wrap,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(115), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3297] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(342), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(579), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3313] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(581), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(129), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3331] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(301), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(583), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3347] = 5,
    ACTIONS(489), 1,
      anon_sym_wrap,
    ACTIONS(585), 1,
      anon_sym_RBRACE,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(120), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3365] = 5,
    ACTIONS(489), 1,
      anon_sym_wrap,
    ACTIONS(587), 1,
      anon_sym_RBRACE,
    STATE(243), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(115), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3383] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(589), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(327), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3401] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(591), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(328), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3419] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(593), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(288), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3437] = 5,
    ACTIONS(559), 1,
      anon_sym_LBRACK,
    ACTIONS(595), 1,
      sym_NUMBER,
    ACTIONS(597), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(47), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3455] = 3,
    ACTIONS(601), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3469] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(334), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(603), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3485] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(348), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(605), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3501] = 4,
    ACTIONS(499), 1,
      anon_sym_LBRACK,
    STATE(267), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(607), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3517] = 5,
    ACTIONS(609), 1,
      anon_sym_LBRACK,
    ACTIONS(611), 1,
      sym_NUMBER,
    ACTIONS(613), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(281), 2,
      sym_DISTANCE,
      sym_distance_expansion,
  [3535] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(615), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3546] = 3,
    ACTIONS(619), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3559] = 5,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(621), 1,
      anon_sym_RBRACK,
    ACTIONS(623), 1,
      sym_CONSTANT,
    STATE(245), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3576] = 5,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(623), 1,
      sym_CONSTANT,
    ACTIONS(625), 1,
      anon_sym_RBRACK,
    STATE(245), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3593] = 4,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    STATE(277), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(629), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3608] = 4,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    STATE(278), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(631), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3623] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(633), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3634] = 4,
    ACTIONS(637), 1,
      anon_sym_LBRACK,
    STATE(307), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(635), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3649] = 5,
    ACTIONS(611), 1,
      sym_NUMBER,
    ACTIONS(639), 1,
      anon_sym_RBRACK,
    ACTIONS(641), 1,
      sym_CONSTANT,
    STATE(165), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3666] = 3,
    ACTIONS(645), 1,
      sym_distance_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(643), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_over,
  [3679] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(647), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3690] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(649), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
      anon_sym_over,
  [3701] = 4,
    ACTIONS(651), 1,
      anon_sym_LBRACK,
    STATE(310), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(653), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3716] = 4,
    ACTIONS(651), 1,
      anon_sym_LBRACK,
    STATE(273), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(655), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3731] = 4,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    STATE(324), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(657), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3746] = 4,
    ACTIONS(663), 1,
      anon_sym_LBRACE,
    STATE(329), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(661), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3761] = 3,
    ACTIONS(667), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(665), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3774] = 4,
    ACTIONS(669), 1,
      anon_sym_LBRACK,
    STATE(292), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(671), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3789] = 5,
    ACTIONS(673), 1,
      anon_sym_RBRACE,
    ACTIONS(675), 1,
      sym_serial_dialog_option_type,
    STATE(148), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(241), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3806] = 4,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    STATE(332), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(678), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3821] = 5,
    ACTIONS(495), 1,
      sym_duration_suffix,
    ACTIONS(645), 1,
      sym_distance_suffix,
    ACTIONS(680), 1,
      sym_quantity_suffix,
    ACTIONS(682), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3838] = 4,
    ACTIONS(684), 1,
      sym_QUOTED_STRING,
    STATE(151), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(687), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3853] = 3,
    ACTIONS(691), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(689), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3866] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3877] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(695), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3888] = 5,
    ACTIONS(534), 1,
      sym_serial_dialog_option_type,
    ACTIONS(697), 1,
      anon_sym_RBRACE,
    STATE(148), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(241), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3905] = 5,
    ACTIONS(611), 1,
      sym_NUMBER,
    ACTIONS(699), 1,
      anon_sym_RBRACK,
    ACTIONS(701), 1,
      sym_CONSTANT,
    STATE(270), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3922] = 4,
    ACTIONS(651), 1,
      anon_sym_LBRACK,
    STATE(302), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(703), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3937] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(705), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3948] = 3,
    ACTIONS(709), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(707), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3961] = 3,
    ACTIONS(711), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(665), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3974] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(713), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3985] = 5,
    ACTIONS(611), 1,
      sym_NUMBER,
    ACTIONS(701), 1,
      sym_CONSTANT,
    ACTIONS(715), 1,
      anon_sym_RBRACK,
    STATE(270), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4002] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(717), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4013] = 5,
    ACTIONS(534), 1,
      sym_serial_dialog_option_type,
    ACTIONS(719), 1,
      anon_sym_RBRACE,
    STATE(148), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(241), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4030] = 4,
    ACTIONS(721), 1,
      anon_sym_COMMA,
    ACTIONS(723), 1,
      anon_sym_RBRACK,
    STATE(216), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4044] = 4,
    ACTIONS(725), 1,
      anon_sym_COMMA,
    ACTIONS(728), 1,
      anon_sym_RBRACK,
    STATE(166), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4058] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [4068] = 3,
    ACTIONS(732), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(734), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4080] = 4,
    ACTIONS(732), 1,
      anon_sym_RBRACK,
    ACTIONS(736), 1,
      anon_sym_COMMA,
    STATE(195), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4094] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(738), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4104] = 4,
    ACTIONS(740), 1,
      anon_sym_COMMA,
    ACTIONS(743), 1,
      anon_sym_RBRACK,
    STATE(171), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4118] = 3,
    ACTIONS(747), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(745), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4130] = 4,
    ACTIONS(747), 1,
      anon_sym_RBRACK,
    ACTIONS(749), 1,
      anon_sym_COMMA,
    STATE(198), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4144] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(751), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4154] = 3,
    ACTIONS(753), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(755), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4166] = 4,
    ACTIONS(757), 1,
      anon_sym_COMMA,
    ACTIONS(760), 1,
      anon_sym_RBRACK,
    STATE(176), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4180] = 4,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(762), 1,
      sym_CONSTANT,
    STATE(180), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4194] = 4,
    ACTIONS(764), 1,
      anon_sym_COMMA,
    ACTIONS(766), 1,
      anon_sym_RBRACK,
    STATE(215), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4208] = 3,
    ACTIONS(770), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(768), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4220] = 4,
    ACTIONS(772), 1,
      anon_sym_COMMA,
    ACTIONS(774), 1,
      anon_sym_RBRACK,
    STATE(193), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4234] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(776), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4244] = 4,
    ACTIONS(778), 1,
      anon_sym_COMMA,
    ACTIONS(781), 1,
      anon_sym_RBRACK,
    STATE(182), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4258] = 3,
    ACTIONS(783), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(785), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4270] = 3,
    ACTIONS(787), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(789), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4282] = 3,
    ACTIONS(793), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(791), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [4294] = 4,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    ACTIONS(795), 1,
      anon_sym_SEMI,
    STATE(311), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4308] = 4,
    ACTIONS(663), 1,
      anon_sym_LBRACE,
    ACTIONS(797), 1,
      anon_sym_SEMI,
    STATE(315), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4322] = 4,
    ACTIONS(450), 1,
      anon_sym_RBRACK,
    ACTIONS(799), 1,
      anon_sym_COMMA,
    STATE(182), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4336] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(801), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4346] = 4,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    ACTIONS(803), 1,
      anon_sym_SEMI,
    STATE(319), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4360] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(805), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4370] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(807), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4380] = 4,
    ACTIONS(625), 1,
      anon_sym_RBRACK,
    ACTIONS(809), 1,
      anon_sym_COMMA,
    STATE(176), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4394] = 3,
    ACTIONS(811), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(734), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4406] = 4,
    ACTIONS(813), 1,
      anon_sym_COMMA,
    ACTIONS(816), 1,
      anon_sym_RBRACK,
    STATE(195), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4420] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(665), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4430] = 3,
    ACTIONS(818), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(745), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4442] = 4,
    ACTIONS(820), 1,
      anon_sym_COMMA,
    ACTIONS(823), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4456] = 4,
    ACTIONS(825), 1,
      anon_sym_COMMA,
    ACTIONS(827), 1,
      anon_sym_RBRACE,
    STATE(227), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4470] = 4,
    ACTIONS(561), 1,
      sym_NUMBER,
    ACTIONS(623), 1,
      sym_CONSTANT,
    STATE(245), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4484] = 4,
    ACTIONS(787), 1,
      anon_sym_RBRACK,
    ACTIONS(829), 1,
      anon_sym_COMMA,
    STATE(209), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4498] = 4,
    ACTIONS(831), 1,
      anon_sym_COMMA,
    ACTIONS(833), 1,
      anon_sym_RBRACK,
    STATE(188), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4512] = 4,
    ACTIONS(835), 1,
      anon_sym_COMMA,
    ACTIONS(837), 1,
      anon_sym_RBRACK,
    STATE(166), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4526] = 4,
    ACTIONS(839), 1,
      anon_sym_COMMA,
    ACTIONS(841), 1,
      anon_sym_RBRACK,
    STATE(214), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4540] = 3,
    ACTIONS(843), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(845), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4552] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(847), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4562] = 4,
    ACTIONS(849), 1,
      anon_sym_COMMA,
    ACTIONS(851), 1,
      anon_sym_RBRACK,
    STATE(169), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4576] = 3,
    ACTIONS(853), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(789), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4588] = 4,
    ACTIONS(855), 1,
      anon_sym_COMMA,
    ACTIONS(858), 1,
      anon_sym_RBRACK,
    STATE(209), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4602] = 4,
    ACTIONS(860), 1,
      sym_QUOTED_STRING,
    ACTIONS(862), 1,
      anon_sym_RBRACE,
    STATE(199), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4616] = 4,
    ACTIONS(835), 1,
      anon_sym_COMMA,
    ACTIONS(864), 1,
      anon_sym_RBRACK,
    STATE(203), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4630] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(866), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4640] = 3,
    ACTIONS(868), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(870), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4652] = 4,
    ACTIONS(868), 1,
      anon_sym_RBRACK,
    ACTIONS(872), 1,
      anon_sym_COMMA,
    STATE(221), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4666] = 4,
    ACTIONS(711), 1,
      anon_sym_RBRACK,
    ACTIONS(874), 1,
      anon_sym_COMMA,
    STATE(171), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4680] = 4,
    ACTIONS(699), 1,
      anon_sym_RBRACK,
    ACTIONS(876), 1,
      anon_sym_COMMA,
    STATE(225), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4694] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(878), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [4704] = 4,
    ACTIONS(880), 1,
      anon_sym_COMMA,
    ACTIONS(882), 1,
      anon_sym_RBRACK,
    STATE(173), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4718] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(884), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4728] = 3,
    ACTIONS(886), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(870), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4740] = 4,
    ACTIONS(888), 1,
      anon_sym_COMMA,
    ACTIONS(891), 1,
      anon_sym_RBRACK,
    STATE(221), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4754] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(893), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4764] = 4,
    ACTIONS(895), 1,
      anon_sym_COMMA,
    ACTIONS(897), 1,
      anon_sym_RBRACK,
    STATE(201), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4778] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(899), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4788] = 4,
    ACTIONS(901), 1,
      anon_sym_COMMA,
    ACTIONS(904), 1,
      anon_sym_RBRACK,
    STATE(225), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4802] = 4,
    ACTIONS(611), 1,
      sym_NUMBER,
    ACTIONS(701), 1,
      sym_CONSTANT,
    STATE(270), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4816] = 4,
    ACTIONS(825), 1,
      anon_sym_COMMA,
    ACTIONS(906), 1,
      anon_sym_RBRACE,
    STATE(228), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4830] = 4,
    ACTIONS(908), 1,
      anon_sym_COMMA,
    ACTIONS(911), 1,
      anon_sym_RBRACE,
    STATE(228), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4844] = 3,
    ACTIONS(913), 1,
      anon_sym_LBRACE,
    STATE(71), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4855] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(858), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4864] = 3,
    ACTIONS(915), 1,
      anon_sym_serial_dialog,
    ACTIONS(917), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4875] = 3,
    ACTIONS(352), 1,
      anon_sym_LBRACK,
    STATE(17), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4886] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(919), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4895] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(893), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4904] = 3,
    ACTIONS(860), 1,
      sym_QUOTED_STRING,
    STATE(254), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4915] = 3,
    ACTIONS(921), 1,
      anon_sym_serial_dialog,
    ACTIONS(923), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4926] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(728), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4935] = 3,
    ACTIONS(925), 1,
      anon_sym_slot,
    ACTIONS(927), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(743), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4955] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(929), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [4964] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(931), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [4973] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(933), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4982] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(935), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4991] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(937), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [5000] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(760), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5009] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(776), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5018] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(939), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5027] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(781), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5036] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(870), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5045] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(941), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5054] = 3,
    ACTIONS(943), 1,
      anon_sym_serial_dialog,
    ACTIONS(945), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5065] = 3,
    ACTIONS(947), 1,
      anon_sym_command,
    ACTIONS(949), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5076] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(951), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5085] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(911), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5094] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(816), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5103] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(789), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5112] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(953), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5121] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(955), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5130] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(823), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5139] = 3,
    ACTIONS(957), 1,
      anon_sym_fade,
    ACTIONS(959), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5150] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(961), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5159] = 3,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    STATE(81), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5170] = 3,
    ACTIONS(663), 1,
      anon_sym_LBRACE,
    STATE(82), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5181] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(963), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [5190] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(734), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5199] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(745), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5208] = 3,
    ACTIONS(965), 1,
      anon_sym_SEMI,
    ACTIONS(967), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5219] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(891), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5228] = 3,
    ACTIONS(913), 1,
      anon_sym_LBRACE,
    STATE(69), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5239] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(904), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5248] = 3,
    ACTIONS(969), 1,
      anon_sym_in,
    ACTIONS(971), 1,
      anon_sym_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5259] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(973), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5268] = 2,
    ACTIONS(975), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5276] = 2,
    ACTIONS(977), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5284] = 2,
    ACTIONS(979), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5292] = 2,
    ACTIONS(981), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5300] = 2,
    ACTIONS(983), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5308] = 2,
    ACTIONS(985), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5316] = 2,
    ACTIONS(987), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5324] = 2,
    ACTIONS(989), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5332] = 2,
    ACTIONS(991), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5340] = 2,
    ACTIONS(993), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5348] = 2,
    ACTIONS(995), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5356] = 2,
    ACTIONS(997), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5364] = 2,
    ACTIONS(999), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5372] = 2,
    ACTIONS(1001), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5380] = 2,
    ACTIONS(1003), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5388] = 2,
    ACTIONS(1005), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5396] = 2,
    ACTIONS(1007), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5404] = 2,
    ACTIONS(1009), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5412] = 2,
    ACTIONS(1011), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5420] = 2,
    ACTIONS(1013), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5428] = 2,
    ACTIONS(1015), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5436] = 2,
    ACTIONS(1017), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5444] = 2,
    ACTIONS(1019), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5452] = 2,
    ACTIONS(1021), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5460] = 2,
    ACTIONS(1023), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5468] = 2,
    ACTIONS(1025), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5476] = 2,
    ACTIONS(1027), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5484] = 2,
    ACTIONS(1029), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5492] = 2,
    ACTIONS(1031), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5500] = 2,
    ACTIONS(1033), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5508] = 2,
    ACTIONS(1035), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5516] = 2,
    ACTIONS(1037), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5524] = 2,
    ACTIONS(1039), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5532] = 2,
    ACTIONS(1041), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5540] = 2,
    ACTIONS(1043), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5548] = 2,
    ACTIONS(1045), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5556] = 2,
    ACTIONS(682), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5564] = 2,
    ACTIONS(1047), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5572] = 2,
    ACTIONS(1049), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5580] = 2,
    ACTIONS(1051), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5588] = 2,
    ACTIONS(1053), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5596] = 2,
    ACTIONS(1055), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5604] = 2,
    ACTIONS(1057), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5612] = 2,
    ACTIONS(1059), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5620] = 2,
    ACTIONS(1061), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5628] = 2,
    ACTIONS(1063), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5636] = 2,
    ACTIONS(1065), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5644] = 2,
    ACTIONS(1067), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5652] = 2,
    ACTIONS(1069), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5660] = 2,
    ACTIONS(1071), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5668] = 2,
    ACTIONS(1073), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5676] = 2,
    ACTIONS(1075), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5684] = 2,
    ACTIONS(1077), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5692] = 2,
    ACTIONS(1079), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5700] = 2,
    ACTIONS(1081), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5708] = 2,
    ACTIONS(1083), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5716] = 2,
    ACTIONS(1085), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5724] = 2,
    ACTIONS(1087), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5732] = 2,
    ACTIONS(1089), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5740] = 2,
    ACTIONS(1091), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5748] = 2,
    ACTIONS(1093), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5756] = 2,
    ACTIONS(1095), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5764] = 2,
    ACTIONS(1097), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5772] = 2,
    ACTIONS(1099), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5780] = 2,
    ACTIONS(1101), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5788] = 2,
    ACTIONS(1103), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5796] = 2,
    ACTIONS(1105), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5804] = 2,
    ACTIONS(1107), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5812] = 2,
    ACTIONS(1109), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5820] = 2,
    ACTIONS(1111), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5828] = 2,
    ACTIONS(1113), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5836] = 2,
    ACTIONS(1115), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5844] = 2,
    ACTIONS(1117), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5852] = 2,
    ACTIONS(1119), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5860] = 2,
    ACTIONS(1121), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5868] = 2,
    ACTIONS(1123), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5876] = 2,
    ACTIONS(1125), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5884] = 2,
    ACTIONS(1127), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 99,
  [SMALL_STATE(4)] = 197,
  [SMALL_STATE(5)] = 295,
  [SMALL_STATE(6)] = 393,
  [SMALL_STATE(7)] = 491,
  [SMALL_STATE(8)] = 527,
  [SMALL_STATE(9)] = 561,
  [SMALL_STATE(10)] = 595,
  [SMALL_STATE(11)] = 629,
  [SMALL_STATE(12)] = 661,
  [SMALL_STATE(13)] = 693,
  [SMALL_STATE(14)] = 725,
  [SMALL_STATE(15)] = 758,
  [SMALL_STATE(16)] = 788,
  [SMALL_STATE(17)] = 818,
  [SMALL_STATE(18)] = 848,
  [SMALL_STATE(19)] = 878,
  [SMALL_STATE(20)] = 908,
  [SMALL_STATE(21)] = 938,
  [SMALL_STATE(22)] = 968,
  [SMALL_STATE(23)] = 998,
  [SMALL_STATE(24)] = 1028,
  [SMALL_STATE(25)] = 1058,
  [SMALL_STATE(26)] = 1088,
  [SMALL_STATE(27)] = 1118,
  [SMALL_STATE(28)] = 1148,
  [SMALL_STATE(29)] = 1178,
  [SMALL_STATE(30)] = 1208,
  [SMALL_STATE(31)] = 1238,
  [SMALL_STATE(32)] = 1268,
  [SMALL_STATE(33)] = 1298,
  [SMALL_STATE(34)] = 1328,
  [SMALL_STATE(35)] = 1358,
  [SMALL_STATE(36)] = 1388,
  [SMALL_STATE(37)] = 1418,
  [SMALL_STATE(38)] = 1448,
  [SMALL_STATE(39)] = 1478,
  [SMALL_STATE(40)] = 1508,
  [SMALL_STATE(41)] = 1538,
  [SMALL_STATE(42)] = 1568,
  [SMALL_STATE(43)] = 1598,
  [SMALL_STATE(44)] = 1628,
  [SMALL_STATE(45)] = 1658,
  [SMALL_STATE(46)] = 1688,
  [SMALL_STATE(47)] = 1718,
  [SMALL_STATE(48)] = 1748,
  [SMALL_STATE(49)] = 1778,
  [SMALL_STATE(50)] = 1808,
  [SMALL_STATE(51)] = 1851,
  [SMALL_STATE(52)] = 1894,
  [SMALL_STATE(53)] = 1926,
  [SMALL_STATE(54)] = 1960,
  [SMALL_STATE(55)] = 1994,
  [SMALL_STATE(56)] = 2025,
  [SMALL_STATE(57)] = 2056,
  [SMALL_STATE(58)] = 2087,
  [SMALL_STATE(59)] = 2118,
  [SMALL_STATE(60)] = 2144,
  [SMALL_STATE(61)] = 2163,
  [SMALL_STATE(62)] = 2182,
  [SMALL_STATE(63)] = 2207,
  [SMALL_STATE(64)] = 2226,
  [SMALL_STATE(65)] = 2249,
  [SMALL_STATE(66)] = 2272,
  [SMALL_STATE(67)] = 2291,
  [SMALL_STATE(68)] = 2309,
  [SMALL_STATE(69)] = 2327,
  [SMALL_STATE(70)] = 2345,
  [SMALL_STATE(71)] = 2363,
  [SMALL_STATE(72)] = 2381,
  [SMALL_STATE(73)] = 2409,
  [SMALL_STATE(74)] = 2427,
  [SMALL_STATE(75)] = 2445,
  [SMALL_STATE(76)] = 2463,
  [SMALL_STATE(77)] = 2479,
  [SMALL_STATE(78)] = 2507,
  [SMALL_STATE(79)] = 2525,
  [SMALL_STATE(80)] = 2543,
  [SMALL_STATE(81)] = 2559,
  [SMALL_STATE(82)] = 2577,
  [SMALL_STATE(83)] = 2595,
  [SMALL_STATE(84)] = 2610,
  [SMALL_STATE(85)] = 2637,
  [SMALL_STATE(86)] = 2664,
  [SMALL_STATE(87)] = 2691,
  [SMALL_STATE(88)] = 2718,
  [SMALL_STATE(89)] = 2745,
  [SMALL_STATE(90)] = 2772,
  [SMALL_STATE(91)] = 2799,
  [SMALL_STATE(92)] = 2814,
  [SMALL_STATE(93)] = 2843,
  [SMALL_STATE(94)] = 2870,
  [SMALL_STATE(95)] = 2886,
  [SMALL_STATE(96)] = 2910,
  [SMALL_STATE(97)] = 2934,
  [SMALL_STATE(98)] = 2947,
  [SMALL_STATE(99)] = 2960,
  [SMALL_STATE(100)] = 2973,
  [SMALL_STATE(101)] = 2992,
  [SMALL_STATE(102)] = 3013,
  [SMALL_STATE(103)] = 3036,
  [SMALL_STATE(104)] = 3059,
  [SMALL_STATE(105)] = 3082,
  [SMALL_STATE(106)] = 3103,
  [SMALL_STATE(107)] = 3124,
  [SMALL_STATE(108)] = 3147,
  [SMALL_STATE(109)] = 3170,
  [SMALL_STATE(110)] = 3193,
  [SMALL_STATE(111)] = 3209,
  [SMALL_STATE(112)] = 3227,
  [SMALL_STATE(113)] = 3243,
  [SMALL_STATE(114)] = 3259,
  [SMALL_STATE(115)] = 3279,
  [SMALL_STATE(116)] = 3297,
  [SMALL_STATE(117)] = 3313,
  [SMALL_STATE(118)] = 3331,
  [SMALL_STATE(119)] = 3347,
  [SMALL_STATE(120)] = 3365,
  [SMALL_STATE(121)] = 3383,
  [SMALL_STATE(122)] = 3401,
  [SMALL_STATE(123)] = 3419,
  [SMALL_STATE(124)] = 3437,
  [SMALL_STATE(125)] = 3455,
  [SMALL_STATE(126)] = 3469,
  [SMALL_STATE(127)] = 3485,
  [SMALL_STATE(128)] = 3501,
  [SMALL_STATE(129)] = 3517,
  [SMALL_STATE(130)] = 3535,
  [SMALL_STATE(131)] = 3546,
  [SMALL_STATE(132)] = 3559,
  [SMALL_STATE(133)] = 3576,
  [SMALL_STATE(134)] = 3593,
  [SMALL_STATE(135)] = 3608,
  [SMALL_STATE(136)] = 3623,
  [SMALL_STATE(137)] = 3634,
  [SMALL_STATE(138)] = 3649,
  [SMALL_STATE(139)] = 3666,
  [SMALL_STATE(140)] = 3679,
  [SMALL_STATE(141)] = 3690,
  [SMALL_STATE(142)] = 3701,
  [SMALL_STATE(143)] = 3716,
  [SMALL_STATE(144)] = 3731,
  [SMALL_STATE(145)] = 3746,
  [SMALL_STATE(146)] = 3761,
  [SMALL_STATE(147)] = 3774,
  [SMALL_STATE(148)] = 3789,
  [SMALL_STATE(149)] = 3806,
  [SMALL_STATE(150)] = 3821,
  [SMALL_STATE(151)] = 3838,
  [SMALL_STATE(152)] = 3853,
  [SMALL_STATE(153)] = 3866,
  [SMALL_STATE(154)] = 3877,
  [SMALL_STATE(155)] = 3888,
  [SMALL_STATE(156)] = 3905,
  [SMALL_STATE(157)] = 3922,
  [SMALL_STATE(158)] = 3937,
  [SMALL_STATE(159)] = 3948,
  [SMALL_STATE(160)] = 3961,
  [SMALL_STATE(161)] = 3974,
  [SMALL_STATE(162)] = 3985,
  [SMALL_STATE(163)] = 4002,
  [SMALL_STATE(164)] = 4013,
  [SMALL_STATE(165)] = 4030,
  [SMALL_STATE(166)] = 4044,
  [SMALL_STATE(167)] = 4058,
  [SMALL_STATE(168)] = 4068,
  [SMALL_STATE(169)] = 4080,
  [SMALL_STATE(170)] = 4094,
  [SMALL_STATE(171)] = 4104,
  [SMALL_STATE(172)] = 4118,
  [SMALL_STATE(173)] = 4130,
  [SMALL_STATE(174)] = 4144,
  [SMALL_STATE(175)] = 4154,
  [SMALL_STATE(176)] = 4166,
  [SMALL_STATE(177)] = 4180,
  [SMALL_STATE(178)] = 4194,
  [SMALL_STATE(179)] = 4208,
  [SMALL_STATE(180)] = 4220,
  [SMALL_STATE(181)] = 4234,
  [SMALL_STATE(182)] = 4244,
  [SMALL_STATE(183)] = 4258,
  [SMALL_STATE(184)] = 4270,
  [SMALL_STATE(185)] = 4282,
  [SMALL_STATE(186)] = 4294,
  [SMALL_STATE(187)] = 4308,
  [SMALL_STATE(188)] = 4322,
  [SMALL_STATE(189)] = 4336,
  [SMALL_STATE(190)] = 4346,
  [SMALL_STATE(191)] = 4360,
  [SMALL_STATE(192)] = 4370,
  [SMALL_STATE(193)] = 4380,
  [SMALL_STATE(194)] = 4394,
  [SMALL_STATE(195)] = 4406,
  [SMALL_STATE(196)] = 4420,
  [SMALL_STATE(197)] = 4430,
  [SMALL_STATE(198)] = 4442,
  [SMALL_STATE(199)] = 4456,
  [SMALL_STATE(200)] = 4470,
  [SMALL_STATE(201)] = 4484,
  [SMALL_STATE(202)] = 4498,
  [SMALL_STATE(203)] = 4512,
  [SMALL_STATE(204)] = 4526,
  [SMALL_STATE(205)] = 4540,
  [SMALL_STATE(206)] = 4552,
  [SMALL_STATE(207)] = 4562,
  [SMALL_STATE(208)] = 4576,
  [SMALL_STATE(209)] = 4588,
  [SMALL_STATE(210)] = 4602,
  [SMALL_STATE(211)] = 4616,
  [SMALL_STATE(212)] = 4630,
  [SMALL_STATE(213)] = 4640,
  [SMALL_STATE(214)] = 4652,
  [SMALL_STATE(215)] = 4666,
  [SMALL_STATE(216)] = 4680,
  [SMALL_STATE(217)] = 4694,
  [SMALL_STATE(218)] = 4704,
  [SMALL_STATE(219)] = 4718,
  [SMALL_STATE(220)] = 4728,
  [SMALL_STATE(221)] = 4740,
  [SMALL_STATE(222)] = 4754,
  [SMALL_STATE(223)] = 4764,
  [SMALL_STATE(224)] = 4778,
  [SMALL_STATE(225)] = 4788,
  [SMALL_STATE(226)] = 4802,
  [SMALL_STATE(227)] = 4816,
  [SMALL_STATE(228)] = 4830,
  [SMALL_STATE(229)] = 4844,
  [SMALL_STATE(230)] = 4855,
  [SMALL_STATE(231)] = 4864,
  [SMALL_STATE(232)] = 4875,
  [SMALL_STATE(233)] = 4886,
  [SMALL_STATE(234)] = 4895,
  [SMALL_STATE(235)] = 4904,
  [SMALL_STATE(236)] = 4915,
  [SMALL_STATE(237)] = 4926,
  [SMALL_STATE(238)] = 4935,
  [SMALL_STATE(239)] = 4946,
  [SMALL_STATE(240)] = 4955,
  [SMALL_STATE(241)] = 4964,
  [SMALL_STATE(242)] = 4973,
  [SMALL_STATE(243)] = 4982,
  [SMALL_STATE(244)] = 4991,
  [SMALL_STATE(245)] = 5000,
  [SMALL_STATE(246)] = 5009,
  [SMALL_STATE(247)] = 5018,
  [SMALL_STATE(248)] = 5027,
  [SMALL_STATE(249)] = 5036,
  [SMALL_STATE(250)] = 5045,
  [SMALL_STATE(251)] = 5054,
  [SMALL_STATE(252)] = 5065,
  [SMALL_STATE(253)] = 5076,
  [SMALL_STATE(254)] = 5085,
  [SMALL_STATE(255)] = 5094,
  [SMALL_STATE(256)] = 5103,
  [SMALL_STATE(257)] = 5112,
  [SMALL_STATE(258)] = 5121,
  [SMALL_STATE(259)] = 5130,
  [SMALL_STATE(260)] = 5139,
  [SMALL_STATE(261)] = 5150,
  [SMALL_STATE(262)] = 5159,
  [SMALL_STATE(263)] = 5170,
  [SMALL_STATE(264)] = 5181,
  [SMALL_STATE(265)] = 5190,
  [SMALL_STATE(266)] = 5199,
  [SMALL_STATE(267)] = 5208,
  [SMALL_STATE(268)] = 5219,
  [SMALL_STATE(269)] = 5228,
  [SMALL_STATE(270)] = 5239,
  [SMALL_STATE(271)] = 5248,
  [SMALL_STATE(272)] = 5259,
  [SMALL_STATE(273)] = 5268,
  [SMALL_STATE(274)] = 5276,
  [SMALL_STATE(275)] = 5284,
  [SMALL_STATE(276)] = 5292,
  [SMALL_STATE(277)] = 5300,
  [SMALL_STATE(278)] = 5308,
  [SMALL_STATE(279)] = 5316,
  [SMALL_STATE(280)] = 5324,
  [SMALL_STATE(281)] = 5332,
  [SMALL_STATE(282)] = 5340,
  [SMALL_STATE(283)] = 5348,
  [SMALL_STATE(284)] = 5356,
  [SMALL_STATE(285)] = 5364,
  [SMALL_STATE(286)] = 5372,
  [SMALL_STATE(287)] = 5380,
  [SMALL_STATE(288)] = 5388,
  [SMALL_STATE(289)] = 5396,
  [SMALL_STATE(290)] = 5404,
  [SMALL_STATE(291)] = 5412,
  [SMALL_STATE(292)] = 5420,
  [SMALL_STATE(293)] = 5428,
  [SMALL_STATE(294)] = 5436,
  [SMALL_STATE(295)] = 5444,
  [SMALL_STATE(296)] = 5452,
  [SMALL_STATE(297)] = 5460,
  [SMALL_STATE(298)] = 5468,
  [SMALL_STATE(299)] = 5476,
  [SMALL_STATE(300)] = 5484,
  [SMALL_STATE(301)] = 5492,
  [SMALL_STATE(302)] = 5500,
  [SMALL_STATE(303)] = 5508,
  [SMALL_STATE(304)] = 5516,
  [SMALL_STATE(305)] = 5524,
  [SMALL_STATE(306)] = 5532,
  [SMALL_STATE(307)] = 5540,
  [SMALL_STATE(308)] = 5548,
  [SMALL_STATE(309)] = 5556,
  [SMALL_STATE(310)] = 5564,
  [SMALL_STATE(311)] = 5572,
  [SMALL_STATE(312)] = 5580,
  [SMALL_STATE(313)] = 5588,
  [SMALL_STATE(314)] = 5596,
  [SMALL_STATE(315)] = 5604,
  [SMALL_STATE(316)] = 5612,
  [SMALL_STATE(317)] = 5620,
  [SMALL_STATE(318)] = 5628,
  [SMALL_STATE(319)] = 5636,
  [SMALL_STATE(320)] = 5644,
  [SMALL_STATE(321)] = 5652,
  [SMALL_STATE(322)] = 5660,
  [SMALL_STATE(323)] = 5668,
  [SMALL_STATE(324)] = 5676,
  [SMALL_STATE(325)] = 5684,
  [SMALL_STATE(326)] = 5692,
  [SMALL_STATE(327)] = 5700,
  [SMALL_STATE(328)] = 5708,
  [SMALL_STATE(329)] = 5716,
  [SMALL_STATE(330)] = 5724,
  [SMALL_STATE(331)] = 5732,
  [SMALL_STATE(332)] = 5740,
  [SMALL_STATE(333)] = 5748,
  [SMALL_STATE(334)] = 5756,
  [SMALL_STATE(335)] = 5764,
  [SMALL_STATE(336)] = 5772,
  [SMALL_STATE(337)] = 5780,
  [SMALL_STATE(338)] = 5788,
  [SMALL_STATE(339)] = 5796,
  [SMALL_STATE(340)] = 5804,
  [SMALL_STATE(341)] = 5812,
  [SMALL_STATE(342)] = 5820,
  [SMALL_STATE(343)] = 5828,
  [SMALL_STATE(344)] = 5836,
  [SMALL_STATE(345)] = 5844,
  [SMALL_STATE(346)] = 5852,
  [SMALL_STATE(347)] = 5860,
  [SMALL_STATE(348)] = 5868,
  [SMALL_STATE(349)] = 5876,
  [SMALL_STATE(350)] = 5884,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(247),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(250),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(321),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(232),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(296),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(297),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(236),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(279),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(238),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(336),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(251),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(282),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(252),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(284),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(291),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(321),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(296),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(297),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(236),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(279),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(238),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(336),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(251),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(282),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(252),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(291),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DURATION, 2, 0, 9),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 9),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_DURATION, 1, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 32),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 32),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 14),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 14),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 15),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 15),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 15),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 15),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 30),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 30),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 31),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 31),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 30),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 30),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_out, 8, 0, 61),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_out, 8, 0, 61),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 34),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 34),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 35),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 35),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 36),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 36),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 37),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 37),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 34),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 34),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 35),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 35),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command, 4, 0, 38),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 4, 0, 38),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_alias, 4, 0, 39),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 4, 0, 39),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_hide_command, 4, 0, 38),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 4, 0, 38),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unhide_command, 4, 0, 38),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 4, 0, 38),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_pause_script, 4, 0, 40),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 40),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unpause_script, 4, 0, 40),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 40),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 48),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 48),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 5, 0, 49),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 5, 0, 49),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 48),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 48),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command_arg, 6, 0, 54),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 6, 0, 54),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_shake, 7, 0, 58),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 7, 0, 58),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_in, 8, 0, 61),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_in, 8, 0, 61),
  [298] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 33),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 33),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [304] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(269),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(269),
  [310] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(343),
  [313] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [316] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(231),
  [319] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(247),
  [322] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [325] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(250),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 43),
  [332] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 43), SHIFT_REPEAT(246),
  [335] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 43), SHIFT_REPEAT(181),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [362] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 28),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 28),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(309),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [378] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [384] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [386] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [390] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [394] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [398] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [402] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [406] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [422] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [426] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [428] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 17),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [432] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [436] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 26),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [456] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(303),
  [459] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(233),
  [462] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(219),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [473] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 44),
  [475] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 44),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 24),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [491] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 27),
  [493] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 27),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [497] = {.entry = {.count = 1, .reusable = false}}, SHIFT(276),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [503] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [505] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [507] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 1, 0, 7),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 2, 0, 16),
  [513] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 46),
  [515] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 46), SHIFT_REPEAT(125),
  [518] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 46),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 47),
  [522] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 47),
  [524] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 29), SHIFT_REPEAT(83),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 29),
  [529] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 29), SHIFT_REPEAT(272),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 20),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [536] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 51),
  [538] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 51),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 52),
  [542] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 52),
  [544] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 52), SHIFT_REPEAT(298),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [551] = {.entry = {.count = 1, .reusable = false}}, SHIFT(272),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19),
  [571] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19), SHIFT_REPEAT(242),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [576] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(242),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(288),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 25),
  [601] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 25),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [615] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 0),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [633] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [643] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 1, 0, 0),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [647] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 50),
  [649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 9),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(310),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 42),
  [675] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 42), SHIFT_REPEAT(294),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [684] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22), SHIFT_REPEAT(217),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22),
  [689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 45),
  [691] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 45),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 55),
  [695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 56),
  [697] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 23),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(341),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [705] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 59),
  [707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 60),
  [709] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 60),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 41),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [725] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 17),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [736] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [740] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(196),
  [743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [757] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(200),
  [760] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [778] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [781] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(308),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 13),
  [793] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 13),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [805] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [807] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [813] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(265),
  [816] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [820] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(266),
  [823] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [829] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [835] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [847] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 1, 0, 0),
  [849] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [853] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [855] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(256),
  [858] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [860] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [862] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [868] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [872] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [874] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [878] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 10),
  [880] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [882] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [884] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [888] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(249),
  [891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [897] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [899] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [901] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [904] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [908] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(235),
  [911] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [915] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [929] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [931] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 21),
  [933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [937] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [941] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [943] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [951] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 53),
  [953] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [955] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [959] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [961] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [963] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 57),
  [965] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [967] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [969] = {.entry = {.count = 1, .reusable = true}}, SHIFT(313),
  [971] = {.entry = {.count = 1, .reusable = true}}, SHIFT(318),
  [973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [975] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [977] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [979] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [981] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [983] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [985] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [987] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [989] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [991] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [993] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [995] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [997] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [999] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [1001] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [1003] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1005] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1007] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [1009] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [1015] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [1017] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1019] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [1021] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1025] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [1029] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1031] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [1033] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [1035] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1037] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [1039] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [1041] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1043] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1045] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1047] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [1049] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1051] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1053] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1055] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [1057] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [1059] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [1061] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 9),
  [1063] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [1065] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [1067] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [1069] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [1071] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1073] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [1075] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1077] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1079] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1081] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [1083] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [1085] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [1087] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1089] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1091] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [1093] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [1095] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [1097] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [1099] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [1101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [1105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [1109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [1111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [1113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [1115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [1119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [1123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [1125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [1127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
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
