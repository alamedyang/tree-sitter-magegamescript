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
#define STATE_COUNT 385
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 179
#define ALIAS_COUNT 0
#define TOKEN_COUNT 79
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 37
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 65

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
  anon_sym_animation = 78,
  sym_document = 79,
  sym_bareword_expansion = 80,
  sym_quoted_string_expansion = 81,
  sym_string_expansion = 82,
  sym_number_expansion = 83,
  sym_DURATION = 84,
  sym_duration_expansion = 85,
  sym_DISTANCE = 86,
  sym_distance_expansion = 87,
  sym_QUANTITY = 88,
  sym_quantity_expansion = 89,
  sym_color_expansion = 90,
  sym__root = 91,
  sym_include_macro = 92,
  sym_constant_assignment = 93,
  sym_add_serial_dialog_settings = 94,
  sym_serial_dialog_parameter_int = 95,
  sym_serial_dialog_parameter = 96,
  sym_add_dialog_settings = 97,
  sym_target_label = 98,
  sym_target_entity = 99,
  sym_add_dialog_settings_target = 100,
  sym__dialog_parameter_int = 101,
  sym__dialog_parameter_string = 102,
  sym_dialog_parameter = 103,
  sym_dialog_definition = 104,
  sym__dialog_block = 105,
  sym_dialog = 106,
  sym_dialog_identifier = 107,
  sym_dialog_option = 108,
  sym_serial_dialog_definition = 109,
  sym__serial_dialog_block = 110,
  sym_serial_dialog = 111,
  sym_serial_dialog_option = 112,
  sym_script_definition = 113,
  sym_script_block = 114,
  sym__script_item = 115,
  sym_json_literal = 116,
  sym_json_array = 117,
  sym_json_object = 118,
  sym_json_name_value_pair = 119,
  sym__json_item = 120,
  sym_rand_macro = 121,
  sym_label_definition = 122,
  sym__action_item = 123,
  sym_action_return_statement = 124,
  sym_action_close_dialog = 125,
  sym_action_close_serial_dialog = 126,
  sym_action_save_slot = 127,
  sym_action_load_slot = 128,
  sym_action_erase_slot = 129,
  sym_action_load_map = 130,
  sym_action_run_script = 131,
  sym_action_goto_label = 132,
  sym_action_goto_index = 133,
  sym_action_non_blocking_delay = 134,
  sym_action_blocking_delay = 135,
  sym_action_show_dialog = 136,
  sym_action_show_serial_dialog = 137,
  sym_action_concat_serial_dialog = 138,
  sym_action_delete_command = 139,
  sym_action_delete_command_arg = 140,
  sym_action_delete_alias = 141,
  sym_action_hide_command = 142,
  sym_action_unhide_command = 143,
  sym_entity = 144,
  sym_entity_identifier = 145,
  sym_entity_identifier_expansion = 146,
  sym_map = 147,
  sym_entity_or_map_identifier = 148,
  sym_entity_or_map_identifier_expansion = 149,
  sym_action_pause_script = 150,
  sym_action_unpause_script = 151,
  sym_action_camera_fade_in = 152,
  sym_action_camera_fade_out = 153,
  sym_action_camera_shake = 154,
  sym_action_play_entity_animation = 155,
  aux_sym_document_repeat1 = 156,
  aux_sym_bareword_expansion_repeat1 = 157,
  aux_sym_quoted_string_expansion_repeat1 = 158,
  aux_sym_string_expansion_repeat1 = 159,
  aux_sym_number_expansion_repeat1 = 160,
  aux_sym_duration_expansion_repeat1 = 161,
  aux_sym_distance_expansion_repeat1 = 162,
  aux_sym_quantity_expansion_repeat1 = 163,
  aux_sym_color_expansion_repeat1 = 164,
  aux_sym_add_serial_dialog_settings_repeat1 = 165,
  aux_sym_add_dialog_settings_repeat1 = 166,
  aux_sym_add_dialog_settings_target_repeat1 = 167,
  aux_sym__dialog_block_repeat1 = 168,
  aux_sym_dialog_repeat1 = 169,
  aux_sym_dialog_repeat2 = 170,
  aux_sym_serial_dialog_repeat1 = 171,
  aux_sym_serial_dialog_repeat2 = 172,
  aux_sym_serial_dialog_repeat3 = 173,
  aux_sym_script_block_repeat1 = 174,
  aux_sym_json_array_repeat1 = 175,
  aux_sym_json_object_repeat1 = 176,
  aux_sym_entity_identifier_expansion_repeat1 = 177,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 178,
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
  [anon_sym_animation] = "animation",
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
  [sym_quantity_expansion] = "quantity_expansion",
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
  [sym_entity_identifier] = "entity_identifier",
  [sym_entity_identifier_expansion] = "entity_identifier_expansion",
  [sym_map] = "map",
  [sym_entity_or_map_identifier] = "entity_or_map_identifier",
  [sym_entity_or_map_identifier_expansion] = "entity_or_map_identifier_expansion",
  [sym_action_pause_script] = "action_pause_script",
  [sym_action_unpause_script] = "action_unpause_script",
  [sym_action_camera_fade_in] = "action_camera_fade_in",
  [sym_action_camera_fade_out] = "action_camera_fade_out",
  [sym_action_camera_shake] = "action_camera_shake",
  [sym_action_play_entity_animation] = "action_play_entity_animation",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
  [aux_sym_distance_expansion_repeat1] = "distance_expansion_repeat1",
  [aux_sym_quantity_expansion_repeat1] = "quantity_expansion_repeat1",
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
  [aux_sym_entity_identifier_expansion_repeat1] = "entity_identifier_expansion_repeat1",
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
  [anon_sym_animation] = anon_sym_animation,
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
  [sym_quantity_expansion] = sym_quantity_expansion,
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
  [sym_entity_identifier] = sym_entity_identifier,
  [sym_entity_identifier_expansion] = sym_entity_identifier_expansion,
  [sym_map] = sym_map,
  [sym_entity_or_map_identifier] = sym_entity_or_map_identifier,
  [sym_entity_or_map_identifier_expansion] = sym_entity_or_map_identifier_expansion,
  [sym_action_pause_script] = sym_action_pause_script,
  [sym_action_unpause_script] = sym_action_unpause_script,
  [sym_action_camera_fade_in] = sym_action_camera_fade_in,
  [sym_action_camera_fade_out] = sym_action_camera_fade_out,
  [sym_action_camera_shake] = sym_action_camera_shake,
  [sym_action_play_entity_animation] = sym_action_play_entity_animation,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
  [aux_sym_distance_expansion_repeat1] = aux_sym_distance_expansion_repeat1,
  [aux_sym_quantity_expansion_repeat1] = aux_sym_quantity_expansion_repeat1,
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
  [aux_sym_entity_identifier_expansion_repeat1] = aux_sym_entity_identifier_expansion_repeat1,
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
  [anon_sym_animation] = {
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
  [sym_quantity_expansion] = {
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
  [sym_entity_identifier] = {
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
  [sym_action_play_entity_animation] = {
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
  [aux_sym_quantity_expansion_repeat1] = {
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
  [aux_sym_entity_identifier_expansion_repeat1] = {
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
  field_animation = 3,
  field_argument = 4,
  field_color = 5,
  field_command = 6,
  field_count = 7,
  field_dialog = 8,
  field_dialog_identifier = 9,
  field_dialog_name = 10,
  field_dialog_option = 11,
  field_dialog_parameter = 12,
  field_distance = 13,
  field_duration = 14,
  field_entity = 15,
  field_entity_identifier = 16,
  field_entity_or_map = 17,
  field_entity_type = 18,
  field_fileName = 19,
  field_index = 20,
  field_label = 21,
  field_map = 22,
  field_message = 23,
  field_option_type = 24,
  field_property = 25,
  field_script = 26,
  field_script_name = 27,
  field_serial_dialog = 28,
  field_serial_dialog_name = 29,
  field_serial_dialog_option = 30,
  field_serial_dialog_parameter = 31,
  field_serial_message = 32,
  field_slot = 33,
  field_suffix = 34,
  field_target = 35,
  field_type = 36,
  field_value = 37,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_amplitude] = "amplitude",
  [field_animation] = "animation",
  [field_argument] = "argument",
  [field_color] = "color",
  [field_command] = "command",
  [field_count] = "count",
  [field_dialog] = "dialog",
  [field_dialog_identifier] = "dialog_identifier",
  [field_dialog_name] = "dialog_name",
  [field_dialog_option] = "dialog_option",
  [field_dialog_parameter] = "dialog_parameter",
  [field_distance] = "distance",
  [field_duration] = "duration",
  [field_entity] = "entity",
  [field_entity_identifier] = "entity_identifier",
  [field_entity_or_map] = "entity_or_map",
  [field_entity_type] = "entity_type",
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
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 1},
  [9] = {.index = 10, .length = 2},
  [10] = {.index = 12, .length = 2},
  [11] = {.index = 14, .length = 1},
  [12] = {.index = 15, .length = 1},
  [13] = {.index = 16, .length = 1},
  [14] = {.index = 17, .length = 1},
  [15] = {.index = 18, .length = 1},
  [16] = {.index = 19, .length = 1},
  [17] = {.index = 20, .length = 1},
  [18] = {.index = 21, .length = 2},
  [19] = {.index = 23, .length = 2},
  [20] = {.index = 25, .length = 1},
  [21] = {.index = 26, .length = 2},
  [22] = {.index = 28, .length = 2},
  [23] = {.index = 30, .length = 1},
  [24] = {.index = 31, .length = 2},
  [25] = {.index = 33, .length = 2},
  [26] = {.index = 35, .length = 2},
  [27] = {.index = 37, .length = 1},
  [28] = {.index = 38, .length = 1},
  [29] = {.index = 39, .length = 2},
  [30] = {.index = 41, .length = 1},
  [31] = {.index = 42, .length = 2},
  [32] = {.index = 44, .length = 1},
  [33] = {.index = 45, .length = 1},
  [34] = {.index = 46, .length = 1},
  [35] = {.index = 47, .length = 1},
  [36] = {.index = 48, .length = 1},
  [37] = {.index = 49, .length = 1},
  [38] = {.index = 50, .length = 1},
  [39] = {.index = 51, .length = 1},
  [40] = {.index = 52, .length = 1},
  [41] = {.index = 53, .length = 1},
  [42] = {.index = 54, .length = 2},
  [43] = {.index = 56, .length = 3},
  [44] = {.index = 59, .length = 2},
  [45] = {.index = 61, .length = 2},
  [46] = {.index = 63, .length = 3},
  [47] = {.index = 66, .length = 1},
  [48] = {.index = 67, .length = 2},
  [49] = {.index = 69, .length = 3},
  [50] = {.index = 72, .length = 2},
  [51] = {.index = 74, .length = 2},
  [52] = {.index = 76, .length = 1},
  [53] = {.index = 77, .length = 4},
  [54] = {.index = 81, .length = 2},
  [55] = {.index = 83, .length = 2},
  [56] = {.index = 85, .length = 2},
  [57] = {.index = 87, .length = 3},
  [58] = {.index = 90, .length = 2},
  [59] = {.index = 92, .length = 2},
  [60] = {.index = 94, .length = 3},
  [61] = {.index = 97, .length = 3},
  [62] = {.index = 100, .length = 2},
  [63] = {.index = 102, .length = 2},
  [64] = {.index = 104, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_entity_type, 0},
  [2] =
    {field_fileName, 1},
  [3] =
    {field_serial_dialog, 2, .inherited = true},
    {field_serial_dialog_name, 1},
  [5] =
    {field_dialog, 2, .inherited = true},
    {field_dialog_name, 1},
  [7] =
    {field_script_name, 1},
  [8] =
    {field_label, 0},
  [9] =
    {field_target, 0},
  [10] =
    {field_entity, 1},
    {field_entity_type, 0},
  [12] =
    {field_label, 0},
    {field_value, 2},
  [14] =
    {field_suffix, 1},
  [15] =
    {field_serial_message, 0},
  [16] =
    {field_serial_dialog_parameter, 0},
  [17] =
    {field_serial_message, 0, .inherited = true},
  [18] =
    {field_dialog, 0},
  [19] =
    {field_script, 1},
  [20] =
    {field_duration, 1},
  [21] =
    {field_entity, 1},
    {field_target, 0},
  [23] =
    {field_property, 0},
    {field_value, 1},
  [25] =
    {field_serial_dialog, 1},
  [26] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [28] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [30] =
    {field_serial_dialog_option, 0},
  [31] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [33] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [35] =
    {field_type, 0},
    {field_value, 1},
  [37] =
    {field_message, 0},
  [38] =
    {field_dialog_parameter, 0},
  [39] =
    {field_dialog_identifier, 0},
    {field_message, 1, .inherited = true},
  [41] =
    {field_dialog, 1, .inherited = true},
  [42] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [44] =
    {field_slot, 2},
  [45] =
    {field_map, 2},
  [46] =
    {field_label, 2},
  [47] =
    {field_index, 2},
  [48] =
    {field_serial_dialog_name, 2},
  [49] =
    {field_serial_dialog, 2, .inherited = true},
  [50] =
    {field_dialog_name, 2},
  [51] =
    {field_dialog, 2, .inherited = true},
  [52] =
    {field_command, 2},
  [53] =
    {field_alias, 2},
  [54] =
    {field_entity_or_map, 1},
    {field_script, 2},
  [56] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [59] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [61] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [63] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [66] =
    {field_dialog_option, 0},
  [67] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [69] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [72] =
    {field_serial_dialog, 3, .inherited = true},
    {field_serial_dialog_name, 2},
  [74] =
    {field_dialog, 3, .inherited = true},
    {field_dialog_name, 2},
  [76] =
    {field_type, 0},
  [77] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [81] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [83] =
    {field_property, 0},
    {field_value, 2},
  [85] =
    {field_argument, 4},
    {field_command, 2},
  [87] =
    {field_animation, 3},
    {field_count, 4},
    {field_entity_identifier, 0},
  [90] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [92] =
    {field_target, 1},
    {field_type, 0},
  [94] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [97] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [100] =
    {field_label, 1},
    {field_script, 3},
  [102] =
    {field_color, 4},
    {field_duration, 6},
  [104] =
    {field_amplitude, 3},
    {field_distance, 4},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(251);
      ADVANCE_MAP(
        '!', 476,
        '"', 5,
        '#', 463,
        '$', 247,
        '(', 477,
        ')', 478,
        '+', 506,
        ',', 423,
        '-', 12,
        '/', 9,
        ':', 468,
        ';', 439,
        '=', 440,
        '>', 461,
        'I', 156,
        '[', 422,
        ']', 424,
        '_', 462,
        'a', 54,
        'b', 133,
        'c', 16,
        'd', 66,
        'e', 149,
        'f', 17,
        'g', 176,
        'h', 114,
        'i', 157,
        'j', 201,
        'l', 19,
        'm', 21,
        'n', 42,
        'o', 158,
        'p', 22,
        'r', 36,
        's', 428,
        't', 109,
        'u', 159,
        'w', 39,
        'x', 430,
        'y', 96,
        '{', 446,
        '}', 447,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 5,
        '#', 244,
        '$', 247,
        '/', 9,
        ';', 439,
        '[', 422,
        ']', 424,
        'b', 348,
        'c', 354,
        'f', 272,
        'g', 388,
        'm', 267,
        'o', 324,
        'r', 316,
        't', 328,
        'w', 329,
        'y', 318,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 5,
        '$', 247,
        ',', 423,
        '/', 9,
        '>', 461,
        '[', 422,
        ']', 424,
        'e', 370,
        'n', 274,
        '{', 446,
        '}', 447,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(5);
      if (lookahead == '$') ADVANCE(247);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '[') ADVANCE(422);
      if (lookahead == 'i') ADVANCE(369);
      if (lookahead == 'l') ADVANCE(263);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 5,
        '-', 13,
        '/', 9,
        'I', 156,
        '[', 422,
        ']', 424,
        'a', 144,
        'b', 172,
        'd', 86,
        'e', 148,
        'f', 17,
        'i', 164,
        'l', 18,
        'm', 35,
        'n', 42,
        'o', 229,
        'p', 141,
        's', 67,
        't', 189,
        'w', 192,
        '{', 446,
        '}', 447,
        '#', 462,
        '_', 462,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(470);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(425);
      if (lookahead == '\\') ADVANCE(248);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '$', 247,
        ',', 423,
        '/', 9,
        ';', 439,
        '[', 422,
        ']', 424,
        'm', 198,
        'p', 112,
        's', 427,
        'x', 430,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      END_STATE();
    case 7:
      if (lookahead == '$') ADVANCE(247);
      if (lookahead == ',') ADVANCE(423);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ';') ADVANCE(439);
      if (lookahead == '[') ADVANCE(422);
      if (lookahead == ']') ADVANCE(424);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        ')', 478,
        ',', 423,
        '/', 9,
        '[', 422,
        ']', 424,
        'b', 350,
        'c', 259,
        'd', 311,
        'e', 365,
        'g', 378,
        'h', 333,
        'j', 390,
        'l', 380,
        'p', 264,
        'r', 265,
        's', 260,
        'u', 361,
        'w', 268,
        '}', 447,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(253);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '>') ADVANCE(525);
      if (lookahead == 'I') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(470);
      END_STATE();
    case 13:
      if (lookahead == 'I') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(470);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(62);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(222);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(154);
      if (lookahead == 'l') ADVANCE(175);
      if (lookahead == 'o') ADVANCE(150);
      if (lookahead == 'y') ADVANCE(38);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(49);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(108);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(108);
      if (lookahead == 's') ADVANCE(427);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(233);
      if (lookahead == 'i') ADVANCE(239);
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead == 'o') ADVANCE(191);
      if (lookahead == 'x') ADVANCE(429);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(233);
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead == 'o') ADVANCE(191);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(236);
      if (lookahead == 'c') ADVANCE(193);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == 'h') ADVANCE(28);
      if (lookahead == 'l') ADVANCE(181);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(243);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(432);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(132);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(132);
      if (lookahead == 'o') ADVANCE(238);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(184);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(520);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(51);
      if (lookahead == 'u') ADVANCE(68);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead == 'g') ADVANCE(170);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(183);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(166);
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(231);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(160);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(119);
      if (lookahead == 'h') ADVANCE(120);
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(137);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(211);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(152);
      if (lookahead == 'u') ADVANCE(138);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(167);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(221);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(126);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(235);
      END_STATE();
    case 49:
      if (lookahead == 'b') ADVANCE(90);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(130);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(131);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(72);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(55);
      if (lookahead == 'l') ADVANCE(113);
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(441);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(432);
      if (lookahead == 't') ADVANCE(230);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(486);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(474);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(505);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(69);
      if (lookahead == 'l') ADVANCE(204);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(70);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(127);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(82);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(83);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(92);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(103);
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == 'h') ADVANCE(27);
      if (lookahead == 'l') ADVANCE(181);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(432);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(522);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(508);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(457);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(431);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(483);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(471);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(481);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(456);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(488);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(472);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(516);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(528);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(503);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(510);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(437);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(518);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(240);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(186);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(160);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(195);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(135);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(187);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(188);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(168);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(216);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(169);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(207);
      END_STATE();
    case 100:
      if (lookahead == 'f') ADVANCE(514);
      END_STATE();
    case 101:
      if (lookahead == 'f') ADVANCE(118);
      END_STATE();
    case 102:
      if (lookahead == 'f') ADVANCE(37);
      END_STATE();
    case 103:
      if (lookahead == 'f') ADVANCE(37);
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 104:
      if (lookahead == 'g') ADVANCE(449);
      END_STATE();
    case 105:
      if (lookahead == 'g') ADVANCE(443);
      END_STATE();
    case 106:
      if (lookahead == 'g') ADVANCE(200);
      END_STATE();
    case 107:
      if (lookahead == 'g') ADVANCE(170);
      END_STATE();
    case 108:
      if (lookahead == 'g') ADVANCE(94);
      if (lookahead == 'p') ADVANCE(490);
      END_STATE();
    case 109:
      if (lookahead == 'h') ADVANCE(190);
      if (lookahead == 'r') ADVANCE(232);
      if (lookahead == 'w') ADVANCE(111);
      END_STATE();
    case 110:
      if (lookahead == 'h') ADVANCE(129);
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 111:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 112:
      if (lookahead == 'i') ADVANCE(239);
      if (lookahead == 'x') ADVANCE(429);
      END_STATE();
    case 113:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 114:
      if (lookahead == 'i') ADVANCE(61);
      END_STATE();
    case 115:
      if (lookahead == 'i') ADVANCE(151);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(185);
      END_STATE();
    case 117:
      if (lookahead == 'i') ADVANCE(107);
      END_STATE();
    case 118:
      if (lookahead == 'i') ADVANCE(171);
      END_STATE();
    case 119:
      if (lookahead == 'i') ADVANCE(210);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(219);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(146);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(217);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(165);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(218);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(214);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(182);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 130:
      if (lookahead == 'k') ADVANCE(432);
      END_STATE();
    case 131:
      if (lookahead == 'k') ADVANCE(497);
      END_STATE();
    case 132:
      if (lookahead == 'k') ADVANCE(80);
      END_STATE();
    case 133:
      if (lookahead == 'l') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(197);
      END_STATE();
    case 134:
      if (lookahead == 'l') ADVANCE(473);
      END_STATE();
    case 135:
      if (lookahead == 'l') ADVANCE(452);
      END_STATE();
    case 136:
      if (lookahead == 'l') ADVANCE(100);
      if (lookahead == 'r') ADVANCE(124);
      if (lookahead == 't') ADVANCE(227);
      END_STATE();
    case 137:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 138:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 139:
      if (lookahead == 'l') ADVANCE(174);
      END_STATE();
    case 140:
      if (lookahead == 'l') ADVANCE(234);
      END_STATE();
    case 141:
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead == 'o') ADVANCE(191);
      END_STATE();
    case 142:
      if (lookahead == 'l') ADVANCE(177);
      END_STATE();
    case 143:
      if (lookahead == 'l') ADVANCE(178);
      END_STATE();
    case 144:
      if (lookahead == 'l') ADVANCE(117);
      END_STATE();
    case 145:
      if (lookahead == 'l') ADVANCE(213);
      END_STATE();
    case 146:
      if (lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 147:
      if (lookahead == 'l') ADVANCE(142);
      END_STATE();
    case 148:
      if (lookahead == 'm') ADVANCE(179);
      if (lookahead == 'n') ADVANCE(228);
      END_STATE();
    case 149:
      if (lookahead == 'm') ADVANCE(179);
      if (lookahead == 'n') ADVANCE(228);
      if (lookahead == 'r') ADVANCE(43);
      END_STATE();
    case 150:
      if (lookahead == 'm') ADVANCE(153);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 151:
      if (lookahead == 'm') ADVANCE(45);
      END_STATE();
    case 152:
      if (lookahead == 'm') ADVANCE(71);
      END_STATE();
    case 153:
      if (lookahead == 'm') ADVANCE(44);
      END_STATE();
    case 154:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 155:
      if (lookahead == 'm') ADVANCE(98);
      END_STATE();
    case 156:
      if (lookahead == 'n') ADVANCE(101);
      END_STATE();
    case 157:
      if (lookahead == 'n') ADVANCE(524);
      END_STATE();
    case 158:
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(208);
      if (lookahead == 'v') ADVANCE(87);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 160:
      if (lookahead == 'n') ADVANCE(432);
      END_STATE();
    case 161:
      if (lookahead == 'n') ADVANCE(466);
      END_STATE();
    case 162:
      if (lookahead == 'n') ADVANCE(479);
      END_STATE();
    case 163:
      if (lookahead == 'n') ADVANCE(529);
      END_STATE();
    case 164:
      if (lookahead == 'n') ADVANCE(523);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(106);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 167:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 168:
      if (lookahead == 'n') ADVANCE(223);
      END_STATE();
    case 169:
      if (lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 170:
      if (lookahead == 'n') ADVANCE(155);
      END_STATE();
    case 171:
      if (lookahead == 'n') ADVANCE(125);
      END_STATE();
    case 172:
      if (lookahead == 'o') ADVANCE(197);
      END_STATE();
    case 173:
      if (lookahead == 'o') ADVANCE(491);
      END_STATE();
    case 174:
      if (lookahead == 'o') ADVANCE(104);
      END_STATE();
    case 175:
      if (lookahead == 'o') ADVANCE(202);
      END_STATE();
    case 176:
      if (lookahead == 'o') ADVANCE(220);
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 177:
      if (lookahead == 'o') ADVANCE(237);
      END_STATE();
    case 178:
      if (lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 179:
      if (lookahead == 'o') ADVANCE(224);
      END_STATE();
    case 180:
      if (lookahead == 'o') ADVANCE(161);
      END_STATE();
    case 181:
      if (lookahead == 'o') ADVANCE(209);
      END_STATE();
    case 182:
      if (lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 183:
      if (lookahead == 'p') ADVANCE(490);
      END_STATE();
    case 184:
      if (lookahead == 'p') ADVANCE(448);
      END_STATE();
    case 185:
      if (lookahead == 'p') ADVANCE(212);
      END_STATE();
    case 186:
      if (lookahead == 'r') ADVANCE(526);
      END_STATE();
    case 187:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 188:
      if (lookahead == 'r') ADVANCE(512);
      END_STATE();
    case 189:
      if (lookahead == 'r') ADVANCE(232);
      END_STATE();
    case 190:
      if (lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 191:
      if (lookahead == 'r') ADVANCE(226);
      END_STATE();
    case 192:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 193:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 194:
      if (lookahead == 'r') ADVANCE(162);
      END_STATE();
    case 195:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 196:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 197:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 198:
      if (lookahead == 's') ADVANCE(427);
      END_STATE();
    case 199:
      if (lookahead == 's') ADVANCE(507);
      END_STATE();
    case 200:
      if (lookahead == 's') ADVANCE(445);
      END_STATE();
    case 201:
      if (lookahead == 's') ADVANCE(180);
      END_STATE();
    case 202:
      if (lookahead == 's') ADVANCE(75);
      END_STATE();
    case 203:
      if (lookahead == 's') ADVANCE(77);
      END_STATE();
    case 204:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 205:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 206:
      if (lookahead == 's') ADVANCE(84);
      END_STATE();
    case 207:
      if (lookahead == 's') ADVANCE(95);
      END_STATE();
    case 208:
      if (lookahead == 't') ADVANCE(527);
      END_STATE();
    case 209:
      if (lookahead == 't') ADVANCE(485);
      END_STATE();
    case 210:
      if (lookahead == 't') ADVANCE(495);
      END_STATE();
    case 211:
      if (lookahead == 't') ADVANCE(501);
      END_STATE();
    case 212:
      if (lookahead == 't') ADVANCE(464);
      END_STATE();
    case 213:
      if (lookahead == 't') ADVANCE(451);
      END_STATE();
    case 214:
      if (lookahead == 't') ADVANCE(458);
      END_STATE();
    case 215:
      if (lookahead == 't') ADVANCE(459);
      END_STATE();
    case 216:
      if (lookahead == 't') ADVANCE(460);
      END_STATE();
    case 217:
      if (lookahead == 't') ADVANCE(241);
      END_STATE();
    case 218:
      if (lookahead == 't') ADVANCE(242);
      END_STATE();
    case 219:
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 220:
      if (lookahead == 't') ADVANCE(173);
      END_STATE();
    case 221:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 222:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 223:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 224:
      if (lookahead == 't') ADVANCE(76);
      END_STATE();
    case 225:
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 226:
      if (lookahead == 't') ADVANCE(196);
      END_STATE();
    case 227:
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 228:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 229:
      if (lookahead == 'u') ADVANCE(208);
      END_STATE();
    case 230:
      if (lookahead == 'u') ADVANCE(194);
      END_STATE();
    case 231:
      if (lookahead == 'u') ADVANCE(145);
      END_STATE();
    case 232:
      if (lookahead == 'u') ADVANCE(74);
      END_STATE();
    case 233:
      if (lookahead == 'u') ADVANCE(205);
      END_STATE();
    case 234:
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 235:
      if (lookahead == 'u') ADVANCE(206);
      END_STATE();
    case 236:
      if (lookahead == 'v') ADVANCE(73);
      END_STATE();
    case 237:
      if (lookahead == 'w') ADVANCE(432);
      END_STATE();
    case 238:
      if (lookahead == 'w') ADVANCE(499);
      END_STATE();
    case 239:
      if (lookahead == 'x') ADVANCE(429);
      END_STATE();
    case 240:
      if (lookahead == 'x') ADVANCE(493);
      END_STATE();
    case 241:
      if (lookahead == 'y') ADVANCE(454);
      END_STATE();
    case 242:
      if (lookahead == 'y') ADVANCE(469);
      END_STATE();
    case 243:
      if (lookahead == 'y') ADVANCE(93);
      END_STATE();
    case 244:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(246);
      END_STATE();
    case 245:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(435);
      END_STATE();
    case 246:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(245);
      END_STATE();
    case 247:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(436);
      END_STATE();
    case 248:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(5);
      END_STATE();
    case 249:
      if (eof) ADVANCE(251);
      ADVANCE_MAP(
        '!', 476,
        '"', 5,
        '#', 463,
        '$', 247,
        '(', 477,
        ')', 478,
        '+', 506,
        ',', 423,
        '-', 12,
        '/', 9,
        ':', 468,
        ';', 439,
        '=', 440,
        '>', 461,
        'I', 156,
        '[', 422,
        ']', 424,
        '_', 462,
        'a', 54,
        'b', 133,
        'c', 16,
        'd', 66,
        'e', 149,
        'f', 17,
        'g', 176,
        'h', 114,
        'i', 157,
        'j', 201,
        'l', 19,
        'm', 20,
        'n', 42,
        'o', 158,
        'p', 23,
        'r', 36,
        's', 24,
        't', 109,
        'u', 159,
        'w', 39,
        'y', 96,
        '{', 446,
        '}', 447,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(249);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      END_STATE();
    case 250:
      if (eof) ADVANCE(251);
      ADVANCE_MAP(
        '"', 5,
        '$', 247,
        ',', 423,
        '/', 9,
        ';', 439,
        '[', 422,
        ']', 424,
        'a', 291,
        'd', 331,
        'i', 360,
        's', 279,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(250);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(253);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(357);
      if (lookahead == 'l') ADVANCE(376);
      if (lookahead == 'o') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(414);
      if (lookahead == 'e') ADVANCE(347);
      if (lookahead == 'h') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(521);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(412);
      if (lookahead == 'l') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(367);
      if (lookahead == 'e') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(282);
      if (lookahead == 'u') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(384);
      if (lookahead == 'e') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(343);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(487);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(475);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(482);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(489);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(517);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(504);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(511);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(519);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(368);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(515);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(323);
      if (lookahead == 'n') ADVANCE(254);
      if (lookahead == 'p') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(450);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(385);
      if (lookahead == 'r') ADVANCE(411);
      if (lookahead == 'w') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(339);
      if (lookahead == 'p') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(498);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(381);
      if (lookahead == 'y') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(480);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(407);
      if (lookahead == 'r') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(513);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(465);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(496);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(502);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(500);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(426);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(236);
      if (lookahead == 'c') ADVANCE(193);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == 'h') ADVANCE(28);
      if (lookahead == 'l') ADVANCE(181);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(432);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(433);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(434);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(436);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(246);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(470);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(sym_player);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(421);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(140);
      if (lookahead == 'd') ADVANCE(85);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(anon_sym_animation);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 250},
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
  [22] = {.lex_state = 8},
  [23] = {.lex_state = 8},
  [24] = {.lex_state = 8},
  [25] = {.lex_state = 8},
  [26] = {.lex_state = 8},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 8},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 8},
  [40] = {.lex_state = 8},
  [41] = {.lex_state = 8},
  [42] = {.lex_state = 8},
  [43] = {.lex_state = 8},
  [44] = {.lex_state = 8},
  [45] = {.lex_state = 8},
  [46] = {.lex_state = 250},
  [47] = {.lex_state = 250},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 250},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 250},
  [60] = {.lex_state = 250},
  [61] = {.lex_state = 250},
  [62] = {.lex_state = 4},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 250},
  [65] = {.lex_state = 250},
  [66] = {.lex_state = 250},
  [67] = {.lex_state = 250},
  [68] = {.lex_state = 250},
  [69] = {.lex_state = 250},
  [70] = {.lex_state = 250},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 250},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 250},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 250},
  [77] = {.lex_state = 250},
  [78] = {.lex_state = 250},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 6},
  [91] = {.lex_state = 3},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 250},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 4},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 1},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 250},
  [117] = {.lex_state = 250},
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 2},
  [120] = {.lex_state = 4},
  [121] = {.lex_state = 1},
  [122] = {.lex_state = 2},
  [123] = {.lex_state = 250},
  [124] = {.lex_state = 1},
  [125] = {.lex_state = 250},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 1},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 2},
  [130] = {.lex_state = 2},
  [131] = {.lex_state = 2},
  [132] = {.lex_state = 250},
  [133] = {.lex_state = 250},
  [134] = {.lex_state = 250},
  [135] = {.lex_state = 2},
  [136] = {.lex_state = 2},
  [137] = {.lex_state = 1},
  [138] = {.lex_state = 1},
  [139] = {.lex_state = 2},
  [140] = {.lex_state = 250},
  [141] = {.lex_state = 2},
  [142] = {.lex_state = 250},
  [143] = {.lex_state = 250},
  [144] = {.lex_state = 2},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 4},
  [147] = {.lex_state = 4},
  [148] = {.lex_state = 250},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 250},
  [152] = {.lex_state = 250},
  [153] = {.lex_state = 2},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 1},
  [156] = {.lex_state = 1},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 2},
  [159] = {.lex_state = 1},
  [160] = {.lex_state = 4},
  [161] = {.lex_state = 6},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 250},
  [165] = {.lex_state = 250},
  [166] = {.lex_state = 2},
  [167] = {.lex_state = 250},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 4},
  [171] = {.lex_state = 250},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 4},
  [174] = {.lex_state = 4},
  [175] = {.lex_state = 250},
  [176] = {.lex_state = 4},
  [177] = {.lex_state = 2},
  [178] = {.lex_state = 250},
  [179] = {.lex_state = 4},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 2},
  [183] = {.lex_state = 250},
  [184] = {.lex_state = 2},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 2},
  [199] = {.lex_state = 4},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 2},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 2},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 250},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 2},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 1},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 2},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 2},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 250},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 2},
  [231] = {.lex_state = 2},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 250},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 250},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 2},
  [239] = {.lex_state = 2},
  [240] = {.lex_state = 1},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 2},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 1},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 250},
  [254] = {.lex_state = 2},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 1},
  [257] = {.lex_state = 4},
  [258] = {.lex_state = 2},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 4},
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
  [271] = {.lex_state = 4},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 2},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 4},
  [280] = {.lex_state = 2},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 250},
  [284] = {.lex_state = 4},
  [285] = {.lex_state = 2},
  [286] = {.lex_state = 4},
  [287] = {.lex_state = 4},
  [288] = {.lex_state = 250},
  [289] = {.lex_state = 2},
  [290] = {.lex_state = 250},
  [291] = {.lex_state = 0},
  [292] = {.lex_state = 250},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 0},
  [295] = {.lex_state = 2},
  [296] = {.lex_state = 0},
  [297] = {.lex_state = 4},
  [298] = {.lex_state = 0},
  [299] = {.lex_state = 0},
  [300] = {.lex_state = 0},
  [301] = {.lex_state = 0},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 0},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 0},
  [306] = {.lex_state = 4},
  [307] = {.lex_state = 4},
  [308] = {.lex_state = 4},
  [309] = {.lex_state = 0},
  [310] = {.lex_state = 0},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 0},
  [313] = {.lex_state = 0},
  [314] = {.lex_state = 0},
  [315] = {.lex_state = 4},
  [316] = {.lex_state = 0},
  [317] = {.lex_state = 0},
  [318] = {.lex_state = 0},
  [319] = {.lex_state = 4},
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
  [354] = {.lex_state = 0},
  [355] = {.lex_state = 0},
  [356] = {.lex_state = 0},
  [357] = {.lex_state = 0},
  [358] = {.lex_state = 0},
  [359] = {.lex_state = 0},
  [360] = {.lex_state = 0},
  [361] = {.lex_state = 0},
  [362] = {.lex_state = 0},
  [363] = {.lex_state = 0},
  [364] = {.lex_state = 0},
  [365] = {.lex_state = 0},
  [366] = {.lex_state = 0},
  [367] = {.lex_state = 0},
  [368] = {.lex_state = 0},
  [369] = {.lex_state = 0},
  [370] = {.lex_state = 0},
  [371] = {.lex_state = 0},
  [372] = {.lex_state = 0},
  [373] = {.lex_state = 0},
  [374] = {.lex_state = 0},
  [375] = {.lex_state = 0},
  [376] = {.lex_state = 0},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 0},
  [379] = {.lex_state = 0},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 0},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 0},
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
    [anon_sym_serial_dialog] = ACTIONS(1),
    [anon_sym_settings] = ACTIONS(1),
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
    [anon_sym_script] = ACTIONS(1),
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
    [anon_sym_slot] = ACTIONS(1),
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
    [sym_self] = ACTIONS(1),
    [anon_sym_pause] = ACTIONS(1),
    [anon_sym_unpause] = ACTIONS(1),
    [anon_sym_camera] = ACTIONS(1),
    [anon_sym_fade] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
    [anon_sym_out] = ACTIONS(1),
    [anon_sym_shake] = ACTIONS(1),
    [anon_sym_animation] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(344),
    [sym__root] = STATE(47),
    [sym_include_macro] = STATE(47),
    [sym_constant_assignment] = STATE(47),
    [sym_add_serial_dialog_settings] = STATE(47),
    [sym_add_dialog_settings] = STATE(47),
    [sym_dialog_definition] = STATE(47),
    [sym_serial_dialog_definition] = STATE(47),
    [sym_script_definition] = STATE(47),
    [aux_sym_document_repeat1] = STATE(47),
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
  [0] = 27,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(26), 1,
      anon_sym_LBRACK,
    ACTIONS(31), 1,
      anon_sym_entity,
    ACTIONS(34), 1,
      anon_sym_json,
    ACTIONS(37), 1,
      anon_sym_rand,
    ACTIONS(40), 1,
      anon_sym_return,
    ACTIONS(43), 1,
      anon_sym_close,
    ACTIONS(46), 1,
      anon_sym_save,
    ACTIONS(49), 1,
      anon_sym_load,
    ACTIONS(52), 1,
      anon_sym_erase,
    ACTIONS(55), 1,
      anon_sym_goto,
    ACTIONS(58), 1,
      anon_sym_wait,
    ACTIONS(61), 1,
      anon_sym_block,
    ACTIONS(64), 1,
      anon_sym_show,
    ACTIONS(67), 1,
      anon_sym_concat,
    ACTIONS(70), 1,
      anon_sym_delete,
    ACTIONS(73), 1,
      anon_sym_hide,
    ACTIONS(76), 1,
      anon_sym_unhide,
    ACTIONS(82), 1,
      anon_sym_pause,
    ACTIONS(85), 1,
      anon_sym_unpause,
    ACTIONS(88), 1,
      anon_sym_camera,
    STATE(198), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(29), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(79), 2,
      sym_player,
      sym_self,
    STATE(340), 2,
      sym_entity_identifier,
      sym_entity_identifier_expansion,
    STATE(2), 32,
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
      sym_action_play_entity_animation,
      aux_sym_script_block_repeat1,
  [117] = 27,
    ACTIONS(91), 1,
      sym_BAREWORD,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    ACTIONS(95), 1,
      anon_sym_RBRACE,
    ACTIONS(97), 1,
      anon_sym_entity,
    ACTIONS(99), 1,
      anon_sym_json,
    ACTIONS(101), 1,
      anon_sym_rand,
    ACTIONS(103), 1,
      anon_sym_return,
    ACTIONS(105), 1,
      anon_sym_close,
    ACTIONS(107), 1,
      anon_sym_save,
    ACTIONS(109), 1,
      anon_sym_load,
    ACTIONS(111), 1,
      anon_sym_erase,
    ACTIONS(113), 1,
      anon_sym_goto,
    ACTIONS(115), 1,
      anon_sym_wait,
    ACTIONS(117), 1,
      anon_sym_block,
    ACTIONS(119), 1,
      anon_sym_show,
    ACTIONS(121), 1,
      anon_sym_concat,
    ACTIONS(123), 1,
      anon_sym_delete,
    ACTIONS(125), 1,
      anon_sym_hide,
    ACTIONS(127), 1,
      anon_sym_unhide,
    ACTIONS(131), 1,
      anon_sym_pause,
    ACTIONS(133), 1,
      anon_sym_unpause,
    ACTIONS(135), 1,
      anon_sym_camera,
    STATE(198), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(129), 2,
      sym_player,
      sym_self,
    STATE(340), 2,
      sym_entity_identifier,
      sym_entity_identifier_expansion,
    STATE(4), 32,
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
      sym_action_play_entity_animation,
      aux_sym_script_block_repeat1,
  [233] = 27,
    ACTIONS(91), 1,
      sym_BAREWORD,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    ACTIONS(97), 1,
      anon_sym_entity,
    ACTIONS(99), 1,
      anon_sym_json,
    ACTIONS(101), 1,
      anon_sym_rand,
    ACTIONS(103), 1,
      anon_sym_return,
    ACTIONS(105), 1,
      anon_sym_close,
    ACTIONS(107), 1,
      anon_sym_save,
    ACTIONS(109), 1,
      anon_sym_load,
    ACTIONS(111), 1,
      anon_sym_erase,
    ACTIONS(113), 1,
      anon_sym_goto,
    ACTIONS(115), 1,
      anon_sym_wait,
    ACTIONS(117), 1,
      anon_sym_block,
    ACTIONS(119), 1,
      anon_sym_show,
    ACTIONS(121), 1,
      anon_sym_concat,
    ACTIONS(123), 1,
      anon_sym_delete,
    ACTIONS(125), 1,
      anon_sym_hide,
    ACTIONS(127), 1,
      anon_sym_unhide,
    ACTIONS(131), 1,
      anon_sym_pause,
    ACTIONS(133), 1,
      anon_sym_unpause,
    ACTIONS(135), 1,
      anon_sym_camera,
    ACTIONS(137), 1,
      anon_sym_RBRACE,
    STATE(198), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(129), 2,
      sym_player,
      sym_self,
    STATE(340), 2,
      sym_entity_identifier,
      sym_entity_identifier_expansion,
    STATE(2), 32,
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
      sym_action_play_entity_animation,
      aux_sym_script_block_repeat1,
  [349] = 27,
    ACTIONS(91), 1,
      sym_BAREWORD,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    ACTIONS(97), 1,
      anon_sym_entity,
    ACTIONS(99), 1,
      anon_sym_json,
    ACTIONS(101), 1,
      anon_sym_rand,
    ACTIONS(103), 1,
      anon_sym_return,
    ACTIONS(105), 1,
      anon_sym_close,
    ACTIONS(107), 1,
      anon_sym_save,
    ACTIONS(109), 1,
      anon_sym_load,
    ACTIONS(111), 1,
      anon_sym_erase,
    ACTIONS(113), 1,
      anon_sym_goto,
    ACTIONS(115), 1,
      anon_sym_wait,
    ACTIONS(117), 1,
      anon_sym_block,
    ACTIONS(119), 1,
      anon_sym_show,
    ACTIONS(121), 1,
      anon_sym_concat,
    ACTIONS(123), 1,
      anon_sym_delete,
    ACTIONS(125), 1,
      anon_sym_hide,
    ACTIONS(127), 1,
      anon_sym_unhide,
    ACTIONS(131), 1,
      anon_sym_pause,
    ACTIONS(133), 1,
      anon_sym_unpause,
    ACTIONS(135), 1,
      anon_sym_camera,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
    STATE(198), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(129), 2,
      sym_player,
      sym_self,
    STATE(340), 2,
      sym_entity_identifier,
      sym_entity_identifier_expansion,
    STATE(6), 32,
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
      sym_action_play_entity_animation,
      aux_sym_script_block_repeat1,
  [465] = 27,
    ACTIONS(91), 1,
      sym_BAREWORD,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    ACTIONS(97), 1,
      anon_sym_entity,
    ACTIONS(99), 1,
      anon_sym_json,
    ACTIONS(101), 1,
      anon_sym_rand,
    ACTIONS(103), 1,
      anon_sym_return,
    ACTIONS(105), 1,
      anon_sym_close,
    ACTIONS(107), 1,
      anon_sym_save,
    ACTIONS(109), 1,
      anon_sym_load,
    ACTIONS(111), 1,
      anon_sym_erase,
    ACTIONS(113), 1,
      anon_sym_goto,
    ACTIONS(115), 1,
      anon_sym_wait,
    ACTIONS(117), 1,
      anon_sym_block,
    ACTIONS(119), 1,
      anon_sym_show,
    ACTIONS(121), 1,
      anon_sym_concat,
    ACTIONS(123), 1,
      anon_sym_delete,
    ACTIONS(125), 1,
      anon_sym_hide,
    ACTIONS(127), 1,
      anon_sym_unhide,
    ACTIONS(131), 1,
      anon_sym_pause,
    ACTIONS(133), 1,
      anon_sym_unpause,
    ACTIONS(135), 1,
      anon_sym_camera,
    ACTIONS(141), 1,
      anon_sym_RPAREN,
    STATE(198), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(129), 2,
      sym_player,
      sym_self,
    STATE(340), 2,
      sym_entity_identifier,
      sym_entity_identifier_expansion,
    STATE(2), 32,
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
      sym_action_play_entity_animation,
      aux_sym_script_block_repeat1,
  [581] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(145), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(143), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [617] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(149), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(147), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [653] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(153), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(151), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [689] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(157), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(155), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [723] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(161), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(159), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [757] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(165), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(163), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [791] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(169), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(167), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [825] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(173), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(171), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [859] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(177), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(175), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [893] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(181), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(179), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [927] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(185), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(183), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [961] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(189), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(187), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [995] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(193), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(191), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1029] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(197), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(195), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1063] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(201), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(199), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1097] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(205), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(203), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1131] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(209), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(207), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1165] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(213), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(211), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1199] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(217), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(215), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1233] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(221), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(219), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1267] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(225), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(223), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1301] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(229), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(227), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1335] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(233), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(231), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1369] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(237), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(235), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1403] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(241), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(239), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1437] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(245), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(243), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1471] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(249), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(247), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1505] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(253), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(251), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1539] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(257), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(255), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1573] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(261), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(259), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1607] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(265), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(263), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1641] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(269), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(267), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1675] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(273), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(271), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1709] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(277), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(275), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1743] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(281), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(279), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1777] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(285), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(283), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1811] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(289), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(287), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1845] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(293), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(291), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1879] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(297), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(295), 22,
      sym_BAREWORD,
      anon_sym_entity,
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
      sym_player,
      sym_self,
      anon_sym_pause,
      anon_sym_unpause,
      anon_sym_camera,
  [1913] = 11,
    ACTIONS(299), 1,
      ts_builtin_sym_end,
    ACTIONS(301), 1,
      sym_BAREWORD,
    ACTIONS(304), 1,
      sym_QUOTED_STRING,
    ACTIONS(307), 1,
      sym_CONSTANT,
    ACTIONS(310), 1,
      anon_sym_include,
    ACTIONS(313), 1,
      anon_sym_add,
    ACTIONS(316), 1,
      anon_sym_serial_dialog,
    ACTIONS(319), 1,
      anon_sym_dialog,
    ACTIONS(322), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(46), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [1956] = 11,
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
    ACTIONS(325), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(46), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [1999] = 9,
    ACTIONS(327), 1,
      sym_QUOTED_STRING,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(86), 1,
      aux_sym_dialog_repeat1,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2033] = 8,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(333), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(335), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(338), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2065] = 9,
    ACTIONS(327), 1,
      sym_QUOTED_STRING,
    STATE(48), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(88), 1,
      aux_sym_dialog_repeat1,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2099] = 8,
    ACTIONS(341), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2130] = 8,
    ACTIONS(343), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2161] = 8,
    ACTIONS(345), 1,
      anon_sym_RBRACE,
    STATE(54), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2192] = 8,
    ACTIONS(347), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(71), 1,
      sym_dialog_parameter,
    STATE(182), 1,
      sym__dialog_parameter_string,
    STATE(283), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(331), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2223] = 6,
    ACTIONS(349), 1,
      anon_sym_LBRACK,
    ACTIONS(351), 1,
      anon_sym_RBRACK,
    ACTIONS(355), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(225), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(353), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2249] = 5,
    ACTIONS(349), 1,
      anon_sym_LBRACK,
    ACTIONS(355), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(273), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(357), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2272] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(359), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(361), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2291] = 6,
    ACTIONS(367), 1,
      sym_NUMBER,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(363), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(365), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(365), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [2316] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(371), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(373), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2335] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(377), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2354] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(379), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(381), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2373] = 5,
    ACTIONS(349), 1,
      anon_sym_LBRACK,
    ACTIONS(355), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(261), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(383), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [2396] = 8,
    ACTIONS(385), 1,
      anon_sym_LBRACK,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(254), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
    STATE(131), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [2424] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(395), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2442] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(399), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2460] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(401), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(403), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2478] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(405), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(407), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2496] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(411), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2514] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(413), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(415), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2532] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(417), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(419), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2550] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(421), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2566] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(423), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(425), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2584] = 8,
    ACTIONS(385), 1,
      anon_sym_LBRACK,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(254), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
    STATE(135), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [2612] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(427), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(429), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2630] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(431), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2646] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(435), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2664] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(437), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(439), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2682] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(441), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(443), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2700] = 8,
    ACTIONS(445), 1,
      anon_sym_RBRACE,
    ACTIONS(447), 1,
      sym_target_default,
    ACTIONS(449), 1,
      anon_sym_label,
    ACTIONS(451), 1,
      anon_sym_entity,
    STATE(242), 1,
      sym_target_entity,
    STATE(285), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(84), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2727] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(453), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2742] = 8,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    ACTIONS(455), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(202), 1,
      sym_entity_or_map_identifier,
    STATE(254), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
  [2769] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(457), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2784] = 8,
    ACTIONS(447), 1,
      sym_target_default,
    ACTIONS(449), 1,
      anon_sym_label,
    ACTIONS(451), 1,
      anon_sym_entity,
    ACTIONS(459), 1,
      anon_sym_RBRACE,
    STATE(242), 1,
      sym_target_entity,
    STATE(285), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(79), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2811] = 8,
    ACTIONS(461), 1,
      anon_sym_RBRACE,
    ACTIONS(463), 1,
      sym_target_default,
    ACTIONS(466), 1,
      anon_sym_label,
    ACTIONS(469), 1,
      anon_sym_entity,
    STATE(242), 1,
      sym_target_entity,
    STATE(285), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(84), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2838] = 8,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    ACTIONS(472), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(254), 1,
      sym_entity,
    STATE(255), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
  [2865] = 8,
    ACTIONS(327), 1,
      sym_QUOTED_STRING,
    ACTIONS(476), 1,
      sym_identifier_type,
    ACTIONS(478), 1,
      anon_sym_GT,
    STATE(93), 1,
      aux_sym_dialog_repeat2,
    STATE(106), 1,
      aux_sym_dialog_repeat1,
    STATE(162), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(474), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2892] = 8,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    ACTIONS(480), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(254), 1,
      sym_entity,
    STATE(255), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
  [2919] = 8,
    ACTIONS(327), 1,
      sym_QUOTED_STRING,
    ACTIONS(478), 1,
      anon_sym_GT,
    ACTIONS(484), 1,
      sym_identifier_type,
    STATE(106), 1,
      aux_sym_dialog_repeat1,
    STATE(107), 1,
      aux_sym_dialog_repeat2,
    STATE(162), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(482), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2946] = 9,
    ACTIONS(486), 1,
      sym_QUOTED_STRING,
    ACTIONS(488), 1,
      anon_sym_RBRACE,
    ACTIONS(490), 1,
      anon_sym_wrap,
    STATE(99), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(101), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    STATE(293), 1,
      sym_serial_dialog_parameter,
    STATE(372), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2975] = 3,
    ACTIONS(494), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(492), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2991] = 7,
    ACTIONS(496), 1,
      sym_BAREWORD,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    ACTIONS(502), 1,
      anon_sym_label,
    ACTIONS(504), 1,
      anon_sym_index,
    STATE(376), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(500), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3015] = 7,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(389), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(254), 1,
      sym_entity,
    STATE(255), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_player,
      sym_self,
  [3039] = 6,
    ACTIONS(478), 1,
      anon_sym_GT,
    ACTIONS(508), 1,
      sym_identifier_type,
    STATE(110), 1,
      aux_sym_dialog_repeat2,
    STATE(162), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(506), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3060] = 7,
    ACTIONS(510), 1,
      sym_BAREWORD,
    ACTIONS(512), 1,
      anon_sym_RBRACE,
    ACTIONS(514), 1,
      sym_identifier_type,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(103), 1,
      aux_sym__dialog_block_repeat1,
    STATE(205), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3083] = 7,
    ACTIONS(486), 1,
      sym_QUOTED_STRING,
    ACTIONS(516), 1,
      anon_sym_RBRACE,
    ACTIONS(518), 1,
      sym_serial_dialog_option_type,
    STATE(146), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(179), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(284), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3106] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(520), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3119] = 7,
    ACTIONS(522), 1,
      sym_BAREWORD,
    ACTIONS(525), 1,
      anon_sym_RBRACE,
    ACTIONS(527), 1,
      sym_identifier_type,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(97), 1,
      aux_sym__dialog_block_repeat1,
    STATE(205), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3142] = 6,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(530), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      sym_entity,
    STATE(269), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_player,
      sym_self,
  [3163] = 7,
    ACTIONS(486), 1,
      sym_QUOTED_STRING,
    ACTIONS(490), 1,
      anon_sym_wrap,
    STATE(95), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(112), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    STATE(293), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3186] = 6,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(534), 1,
      anon_sym_LBRACK,
    ACTIONS(536), 1,
      sym_NUMBER,
    ACTIONS(538), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(303), 2,
      sym_QUANTITY,
      sym_quantity_expansion,
  [3207] = 7,
    ACTIONS(486), 1,
      sym_QUOTED_STRING,
    ACTIONS(518), 1,
      sym_serial_dialog_option_type,
    ACTIONS(540), 1,
      anon_sym_RBRACE,
    STATE(146), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(147), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(284), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3230] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(542), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3243] = 7,
    ACTIONS(510), 1,
      sym_BAREWORD,
    ACTIONS(514), 1,
      sym_identifier_type,
    ACTIONS(544), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(97), 1,
      aux_sym__dialog_block_repeat1,
    STATE(205), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3266] = 6,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(546), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      sym_entity,
    STATE(269), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_player,
      sym_self,
  [3287] = 6,
    ACTIONS(387), 1,
      anon_sym_entity,
    ACTIONS(548), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      sym_entity,
    STATE(251), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_player,
      sym_self,
  [3308] = 5,
    ACTIONS(552), 1,
      sym_QUOTED_STRING,
    ACTIONS(555), 1,
      sym_identifier_type,
    STATE(106), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(550), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3327] = 6,
    ACTIONS(478), 1,
      anon_sym_GT,
    ACTIONS(559), 1,
      sym_identifier_type,
    STATE(110), 1,
      aux_sym_dialog_repeat2,
    STATE(162), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(557), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3348] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(561), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3361] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(563), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3374] = 6,
    ACTIONS(567), 1,
      sym_identifier_type,
    ACTIONS(569), 1,
      anon_sym_GT,
    STATE(110), 1,
      aux_sym_dialog_repeat2,
    STATE(162), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(565), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3395] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3407] = 6,
    ACTIONS(574), 1,
      sym_QUOTED_STRING,
    ACTIONS(576), 1,
      anon_sym_wrap,
    STATE(112), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    STATE(293), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3427] = 5,
    ACTIONS(579), 1,
      anon_sym_RBRACE,
    ACTIONS(581), 1,
      anon_sym_wrap,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(113), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3445] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(584), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3457] = 5,
    ACTIONS(490), 1,
      anon_sym_wrap,
    ACTIONS(586), 1,
      anon_sym_RBRACE,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(126), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3475] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(592), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(328), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3493] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(594), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(323), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3511] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(356), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(596), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3527] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(270), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(598), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3543] = 5,
    ACTIONS(387), 1,
      anon_sym_entity,
    STATE(198), 1,
      sym_entity,
    STATE(269), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_player,
      sym_self,
  [3561] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(600), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3573] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(324), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3589] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(604), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(125), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3607] = 6,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(536), 1,
      sym_NUMBER,
    ACTIONS(606), 1,
      anon_sym_RBRACK,
    ACTIONS(608), 1,
      sym_CONSTANT,
    STATE(237), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3627] = 5,
    ACTIONS(610), 1,
      anon_sym_LBRACK,
    ACTIONS(612), 1,
      sym_NUMBER,
    ACTIONS(614), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(379), 2,
      sym_DISTANCE,
      sym_distance_expansion,
  [3645] = 5,
    ACTIONS(490), 1,
      anon_sym_wrap,
    ACTIONS(616), 1,
      anon_sym_RBRACE,
    STATE(292), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(113), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3663] = 6,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(536), 1,
      sym_NUMBER,
    ACTIONS(618), 1,
      anon_sym_RBRACK,
    ACTIONS(620), 1,
      sym_CONSTANT,
    STATE(298), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3683] = 3,
    ACTIONS(624), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(622), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3697] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(339), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3713] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(335), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(628), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3729] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(373), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(630), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3745] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(632), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(352), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3763] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(634), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(353), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3781] = 5,
    ACTIONS(588), 1,
      anon_sym_LBRACK,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(636), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(357), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3799] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(377), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3815] = 4,
    ACTIONS(498), 1,
      anon_sym_LBRACK,
    STATE(375), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(640), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3831] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(642), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3843] = 6,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(536), 1,
      sym_NUMBER,
    ACTIONS(620), 1,
      sym_CONSTANT,
    ACTIONS(644), 1,
      anon_sym_RBRACK,
    STATE(298), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3863] = 4,
    ACTIONS(648), 1,
      anon_sym_LBRACE,
    STATE(316), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(646), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3878] = 4,
    ACTIONS(650), 1,
      anon_sym_LBRACK,
    STATE(336), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(652), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3893] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(654), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3904] = 4,
    ACTIONS(650), 1,
      anon_sym_LBRACK,
    STATE(342), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(656), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3919] = 4,
    ACTIONS(650), 1,
      anon_sym_LBRACK,
    STATE(100), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(658), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3934] = 3,
    ACTIONS(662), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(660), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3947] = 4,
    ACTIONS(666), 1,
      anon_sym_LBRACK,
    STATE(361), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3962] = 4,
    ACTIONS(668), 1,
      sym_QUOTED_STRING,
    STATE(146), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(671), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3977] = 5,
    ACTIONS(518), 1,
      sym_serial_dialog_option_type,
    ACTIONS(673), 1,
      anon_sym_RBRACE,
    STATE(160), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(284), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3994] = 4,
    ACTIONS(650), 1,
      anon_sym_LBRACK,
    STATE(349), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(675), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4009] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(677), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
      anon_sym_over,
  [4020] = 3,
    ACTIONS(681), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(679), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4033] = 5,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(683), 1,
      anon_sym_RBRACK,
    ACTIONS(685), 1,
      sym_CONSTANT,
    STATE(267), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4050] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(687), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [4061] = 4,
    ACTIONS(648), 1,
      anon_sym_LBRACE,
    STATE(341), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(689), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4076] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(691), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4087] = 4,
    ACTIONS(693), 1,
      anon_sym_LBRACK,
    STATE(370), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(695), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4102] = 4,
    ACTIONS(693), 1,
      anon_sym_LBRACK,
    STATE(371), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(697), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4117] = 4,
    ACTIONS(699), 1,
      anon_sym_LBRACK,
    STATE(312), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(701), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4132] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    STATE(318), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(703), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [4147] = 5,
    ACTIONS(369), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(536), 1,
      sym_NUMBER,
    ACTIONS(620), 1,
      sym_CONSTANT,
    STATE(298), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4164] = 5,
    ACTIONS(707), 1,
      anon_sym_RBRACE,
    ACTIONS(709), 1,
      sym_serial_dialog_option_type,
    STATE(160), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(284), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4181] = 5,
    ACTIONS(494), 1,
      sym_duration_suffix,
    ACTIONS(712), 1,
      sym_distance_suffix,
    ACTIONS(714), 1,
      sym_quantity_suffix,
    ACTIONS(716), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4198] = 3,
    ACTIONS(720), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(718), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [4211] = 3,
    ACTIONS(722), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(679), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4224] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(724), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [4235] = 5,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(685), 1,
      sym_CONSTANT,
    ACTIONS(726), 1,
      anon_sym_RBRACK,
    STATE(267), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4252] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(728), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4263] = 5,
    ACTIONS(612), 1,
      sym_NUMBER,
    ACTIONS(730), 1,
      anon_sym_RBRACK,
    ACTIONS(732), 1,
      sym_CONSTANT,
    STATE(236), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4280] = 3,
    ACTIONS(712), 1,
      sym_distance_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(734), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_over,
  [4293] = 3,
    ACTIONS(714), 1,
      sym_quantity_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(736), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4306] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(738), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4317] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(740), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [4328] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(742), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4339] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(744), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4350] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(746), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4361] = 5,
    ACTIONS(612), 1,
      sym_NUMBER,
    ACTIONS(748), 1,
      anon_sym_RBRACK,
    ACTIONS(750), 1,
      sym_CONSTANT,
    STATE(296), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4378] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4389] = 3,
    ACTIONS(756), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(754), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [4402] = 5,
    ACTIONS(612), 1,
      sym_NUMBER,
    ACTIONS(750), 1,
      sym_CONSTANT,
    ACTIONS(758), 1,
      anon_sym_RBRACK,
    STATE(296), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4419] = 5,
    ACTIONS(518), 1,
      sym_serial_dialog_option_type,
    ACTIONS(760), 1,
      anon_sym_RBRACE,
    STATE(160), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(284), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4436] = 4,
    ACTIONS(762), 1,
      anon_sym_COMMA,
    ACTIONS(765), 1,
      anon_sym_RBRACK,
    STATE(180), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4450] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    ACTIONS(767), 1,
      anon_sym_SEMI,
    STATE(310), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4464] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(769), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4474] = 4,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(771), 1,
      sym_CONSTANT,
    STATE(203), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4488] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(773), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4498] = 4,
    ACTIONS(648), 1,
      anon_sym_LBRACE,
    ACTIONS(775), 1,
      anon_sym_SEMI,
    STATE(317), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4512] = 4,
    ACTIONS(777), 1,
      anon_sym_COMMA,
    ACTIONS(780), 1,
      anon_sym_RBRACK,
    STATE(186), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4526] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(782), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4536] = 4,
    ACTIONS(784), 1,
      anon_sym_COMMA,
    ACTIONS(786), 1,
      anon_sym_RBRACE,
    STATE(208), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4550] = 4,
    ACTIONS(788), 1,
      anon_sym_COMMA,
    ACTIONS(790), 1,
      anon_sym_RBRACK,
    STATE(180), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4564] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(792), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4574] = 4,
    ACTIONS(794), 1,
      anon_sym_COMMA,
    ACTIONS(796), 1,
      anon_sym_RBRACK,
    STATE(211), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4588] = 3,
    ACTIONS(798), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(800), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4600] = 4,
    ACTIONS(681), 1,
      anon_sym_RBRACK,
    ACTIONS(802), 1,
      anon_sym_COMMA,
    STATE(212), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4614] = 4,
    ACTIONS(804), 1,
      anon_sym_COMMA,
    ACTIONS(806), 1,
      anon_sym_RBRACK,
    STATE(214), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4628] = 4,
    ACTIONS(798), 1,
      anon_sym_RBRACK,
    ACTIONS(808), 1,
      anon_sym_COMMA,
    STATE(219), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4642] = 4,
    ACTIONS(683), 1,
      anon_sym_RBRACK,
    ACTIONS(810), 1,
      anon_sym_COMMA,
    STATE(215), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4656] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(812), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_animation,
  [4666] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(814), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4676] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(816), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [4686] = 4,
    ACTIONS(480), 1,
      anon_sym_RBRACK,
    ACTIONS(818), 1,
      anon_sym_COMMA,
    STATE(217), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4700] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(820), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4710] = 4,
    ACTIONS(822), 1,
      anon_sym_COMMA,
    ACTIONS(824), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4724] = 4,
    ACTIONS(826), 1,
      anon_sym_COMMA,
    ACTIONS(828), 1,
      anon_sym_RBRACK,
    STATE(196), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4738] = 3,
    ACTIONS(830), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(832), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4750] = 3,
    ACTIONS(836), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(834), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [4762] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(736), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4772] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(838), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4782] = 4,
    ACTIONS(784), 1,
      anon_sym_COMMA,
    ACTIONS(840), 1,
      anon_sym_RBRACE,
    STATE(227), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4796] = 4,
    ACTIONS(842), 1,
      anon_sym_COMMA,
    ACTIONS(844), 1,
      anon_sym_RBRACK,
    STATE(195), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4810] = 3,
    ACTIONS(846), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(848), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4822] = 4,
    ACTIONS(846), 1,
      anon_sym_RBRACK,
    ACTIONS(850), 1,
      anon_sym_COMMA,
    STATE(229), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4836] = 4,
    ACTIONS(852), 1,
      anon_sym_COMMA,
    ACTIONS(855), 1,
      anon_sym_RBRACK,
    STATE(212), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4850] = 3,
    ACTIONS(859), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(857), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4862] = 4,
    ACTIONS(859), 1,
      anon_sym_RBRACK,
    ACTIONS(861), 1,
      anon_sym_COMMA,
    STATE(232), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4876] = 4,
    ACTIONS(863), 1,
      anon_sym_COMMA,
    ACTIONS(866), 1,
      anon_sym_RBRACK,
    STATE(215), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4890] = 3,
    ACTIONS(868), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(800), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4902] = 4,
    ACTIONS(870), 1,
      anon_sym_COMMA,
    ACTIONS(873), 1,
      anon_sym_RBRACK,
    STATE(217), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4916] = 3,
    ACTIONS(875), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(877), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4928] = 4,
    ACTIONS(879), 1,
      anon_sym_COMMA,
    ACTIONS(882), 1,
      anon_sym_RBRACK,
    STATE(219), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4942] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(884), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_animation,
  [4952] = 3,
    ACTIONS(888), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(886), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4964] = 4,
    ACTIONS(546), 1,
      anon_sym_RBRACK,
    ACTIONS(890), 1,
      anon_sym_COMMA,
    STATE(186), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4978] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(892), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4988] = 4,
    ACTIONS(894), 1,
      sym_QUOTED_STRING,
    ACTIONS(896), 1,
      anon_sym_RBRACE,
    STATE(188), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5002] = 4,
    ACTIONS(788), 1,
      anon_sym_COMMA,
    ACTIONS(898), 1,
      anon_sym_RBRACK,
    STATE(189), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5016] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(900), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [5026] = 4,
    ACTIONS(902), 1,
      anon_sym_COMMA,
    ACTIONS(905), 1,
      anon_sym_RBRACE,
    STATE(227), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5040] = 3,
    ACTIONS(907), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(848), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5052] = 4,
    ACTIONS(909), 1,
      anon_sym_COMMA,
    ACTIONS(912), 1,
      anon_sym_RBRACK,
    STATE(229), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5066] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(679), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5076] = 3,
    ACTIONS(914), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(857), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5088] = 4,
    ACTIONS(916), 1,
      anon_sym_COMMA,
    ACTIONS(919), 1,
      anon_sym_RBRACK,
    STATE(232), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5102] = 4,
    ACTIONS(590), 1,
      sym_NUMBER,
    ACTIONS(685), 1,
      sym_CONSTANT,
    STATE(267), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5116] = 4,
    ACTIONS(921), 1,
      anon_sym_COMMA,
    ACTIONS(923), 1,
      anon_sym_RBRACK,
    STATE(241), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5130] = 3,
    ACTIONS(925), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(927), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5142] = 4,
    ACTIONS(929), 1,
      anon_sym_COMMA,
    ACTIONS(931), 1,
      anon_sym_RBRACK,
    STATE(243), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5156] = 4,
    ACTIONS(933), 1,
      anon_sym_COMMA,
    ACTIONS(935), 1,
      anon_sym_RBRACK,
    STATE(245), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5170] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(937), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5180] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(939), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5190] = 3,
    ACTIONS(941), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(943), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5202] = 4,
    ACTIONS(941), 1,
      anon_sym_RBRACK,
    ACTIONS(945), 1,
      anon_sym_COMMA,
    STATE(249), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5216] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(947), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5226] = 4,
    ACTIONS(748), 1,
      anon_sym_RBRACK,
    ACTIONS(949), 1,
      anon_sym_COMMA,
    STATE(250), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5240] = 4,
    ACTIONS(951), 1,
      anon_sym_COMMA,
    ACTIONS(953), 1,
      anon_sym_RBRACK,
    STATE(193), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5254] = 4,
    ACTIONS(644), 1,
      anon_sym_RBRACK,
    ACTIONS(955), 1,
      anon_sym_COMMA,
    STATE(252), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5268] = 4,
    ACTIONS(648), 1,
      anon_sym_LBRACE,
    ACTIONS(957), 1,
      anon_sym_SEMI,
    STATE(305), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5282] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(959), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [5292] = 3,
    ACTIONS(961), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(943), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5304] = 4,
    ACTIONS(963), 1,
      anon_sym_COMMA,
    ACTIONS(966), 1,
      anon_sym_RBRACK,
    STATE(249), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5318] = 4,
    ACTIONS(968), 1,
      anon_sym_COMMA,
    ACTIONS(971), 1,
      anon_sym_RBRACK,
    STATE(250), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5332] = 4,
    ACTIONS(973), 1,
      anon_sym_COMMA,
    ACTIONS(975), 1,
      anon_sym_RBRACK,
    STATE(222), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5346] = 4,
    ACTIONS(977), 1,
      anon_sym_COMMA,
    ACTIONS(980), 1,
      anon_sym_RBRACK,
    STATE(252), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5360] = 4,
    ACTIONS(612), 1,
      sym_NUMBER,
    ACTIONS(750), 1,
      sym_CONSTANT,
    STATE(296), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5374] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(982), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5384] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(873), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5393] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(943), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5402] = 3,
    ACTIONS(984), 1,
      anon_sym_serial_dialog,
    ACTIONS(986), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5413] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(988), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5422] = 3,
    ACTIONS(894), 1,
      sym_QUOTED_STRING,
    STATE(274), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5433] = 3,
    ACTIONS(990), 1,
      anon_sym_slot,
    ACTIONS(992), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5444] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(765), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5453] = 3,
    ACTIONS(994), 1,
      anon_sym_LBRACE,
    STATE(68), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5464] = 3,
    ACTIONS(349), 1,
      anon_sym_LBRACK,
    STATE(19), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5475] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(855), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5484] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(996), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5493] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(998), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5502] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(866), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5511] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(882), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5520] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(780), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5529] = 3,
    ACTIONS(1000), 1,
      anon_sym_SEMI,
    ACTIONS(1002), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5540] = 3,
    ACTIONS(1004), 1,
      anon_sym_serial_dialog,
    ACTIONS(1006), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5551] = 3,
    ACTIONS(1008), 1,
      anon_sym_command,
    ACTIONS(1010), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5562] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1012), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5571] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(905), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5580] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(912), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5589] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1014), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5598] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1016), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5607] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(919), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5616] = 3,
    ACTIONS(1018), 1,
      anon_sym_fade,
    ACTIONS(1020), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5627] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1022), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5636] = 3,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    STATE(78), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5647] = 3,
    ACTIONS(994), 1,
      anon_sym_LBRACE,
    STATE(64), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5658] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(769), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5667] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1024), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [5676] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(947), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5685] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1026), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [5694] = 3,
    ACTIONS(1028), 1,
      anon_sym_serial_dialog,
    ACTIONS(1030), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5705] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(848), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5714] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(857), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5723] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1032), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5732] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(800), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5741] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1034), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5750] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1036), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [5759] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(966), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5768] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1038), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5777] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(971), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5786] = 3,
    ACTIONS(1040), 1,
      anon_sym_in,
    ACTIONS(1042), 1,
      anon_sym_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5797] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(980), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5806] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1044), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5815] = 3,
    ACTIONS(648), 1,
      anon_sym_LBRACE,
    STATE(72), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5826] = 2,
    ACTIONS(1046), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5834] = 2,
    ACTIONS(1048), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5842] = 2,
    ACTIONS(1050), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5850] = 2,
    ACTIONS(1052), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5858] = 2,
    ACTIONS(1054), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5866] = 2,
    ACTIONS(1056), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5874] = 2,
    ACTIONS(1058), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5882] = 2,
    ACTIONS(1060), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5890] = 2,
    ACTIONS(1062), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5898] = 2,
    ACTIONS(1064), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5906] = 2,
    ACTIONS(1066), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5914] = 2,
    ACTIONS(1068), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5922] = 2,
    ACTIONS(1070), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5930] = 2,
    ACTIONS(1072), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5938] = 2,
    ACTIONS(1074), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5946] = 2,
    ACTIONS(1076), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5954] = 2,
    ACTIONS(1078), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5962] = 2,
    ACTIONS(1080), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5970] = 2,
    ACTIONS(1082), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5978] = 2,
    ACTIONS(1084), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5986] = 2,
    ACTIONS(1086), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5994] = 2,
    ACTIONS(1088), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6002] = 2,
    ACTIONS(1090), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6010] = 2,
    ACTIONS(1092), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6018] = 2,
    ACTIONS(1094), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6026] = 2,
    ACTIONS(1096), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6034] = 2,
    ACTIONS(1098), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6042] = 2,
    ACTIONS(1100), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6050] = 2,
    ACTIONS(1102), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6058] = 2,
    ACTIONS(1104), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6066] = 2,
    ACTIONS(1106), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6074] = 2,
    ACTIONS(1108), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6082] = 2,
    ACTIONS(1110), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6090] = 2,
    ACTIONS(1112), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6098] = 2,
    ACTIONS(1114), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6106] = 2,
    ACTIONS(1116), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6114] = 2,
    ACTIONS(1118), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6122] = 2,
    ACTIONS(1120), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6130] = 2,
    ACTIONS(1122), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6138] = 2,
    ACTIONS(1124), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6146] = 2,
    ACTIONS(1126), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6154] = 2,
    ACTIONS(1128), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6162] = 2,
    ACTIONS(1130), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6170] = 2,
    ACTIONS(1132), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6178] = 2,
    ACTIONS(1134), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6186] = 2,
    ACTIONS(1136), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6194] = 2,
    ACTIONS(1138), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6202] = 2,
    ACTIONS(1140), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6210] = 2,
    ACTIONS(1142), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6218] = 2,
    ACTIONS(1144), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6226] = 2,
    ACTIONS(1146), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6234] = 2,
    ACTIONS(1148), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6242] = 2,
    ACTIONS(1150), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6250] = 2,
    ACTIONS(1152), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6258] = 2,
    ACTIONS(1154), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6266] = 2,
    ACTIONS(1156), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6274] = 2,
    ACTIONS(1158), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6282] = 2,
    ACTIONS(1160), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6290] = 2,
    ACTIONS(1162), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6298] = 2,
    ACTIONS(1164), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6306] = 2,
    ACTIONS(1166), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6314] = 2,
    ACTIONS(1168), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6322] = 2,
    ACTIONS(1170), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6330] = 2,
    ACTIONS(1172), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6338] = 2,
    ACTIONS(716), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6346] = 2,
    ACTIONS(1174), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6354] = 2,
    ACTIONS(1176), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6362] = 2,
    ACTIONS(1178), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6370] = 2,
    ACTIONS(1180), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6378] = 2,
    ACTIONS(1182), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6386] = 2,
    ACTIONS(1184), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6394] = 2,
    ACTIONS(1186), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6402] = 2,
    ACTIONS(1188), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6410] = 2,
    ACTIONS(1190), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6418] = 2,
    ACTIONS(1192), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6426] = 2,
    ACTIONS(1194), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6434] = 2,
    ACTIONS(1196), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6442] = 2,
    ACTIONS(1198), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6450] = 2,
    ACTIONS(1200), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6458] = 2,
    ACTIONS(1202), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6466] = 2,
    ACTIONS(1204), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6474] = 2,
    ACTIONS(1206), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6482] = 2,
    ACTIONS(1208), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6490] = 2,
    ACTIONS(1210), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 117,
  [SMALL_STATE(4)] = 233,
  [SMALL_STATE(5)] = 349,
  [SMALL_STATE(6)] = 465,
  [SMALL_STATE(7)] = 581,
  [SMALL_STATE(8)] = 617,
  [SMALL_STATE(9)] = 653,
  [SMALL_STATE(10)] = 689,
  [SMALL_STATE(11)] = 723,
  [SMALL_STATE(12)] = 757,
  [SMALL_STATE(13)] = 791,
  [SMALL_STATE(14)] = 825,
  [SMALL_STATE(15)] = 859,
  [SMALL_STATE(16)] = 893,
  [SMALL_STATE(17)] = 927,
  [SMALL_STATE(18)] = 961,
  [SMALL_STATE(19)] = 995,
  [SMALL_STATE(20)] = 1029,
  [SMALL_STATE(21)] = 1063,
  [SMALL_STATE(22)] = 1097,
  [SMALL_STATE(23)] = 1131,
  [SMALL_STATE(24)] = 1165,
  [SMALL_STATE(25)] = 1199,
  [SMALL_STATE(26)] = 1233,
  [SMALL_STATE(27)] = 1267,
  [SMALL_STATE(28)] = 1301,
  [SMALL_STATE(29)] = 1335,
  [SMALL_STATE(30)] = 1369,
  [SMALL_STATE(31)] = 1403,
  [SMALL_STATE(32)] = 1437,
  [SMALL_STATE(33)] = 1471,
  [SMALL_STATE(34)] = 1505,
  [SMALL_STATE(35)] = 1539,
  [SMALL_STATE(36)] = 1573,
  [SMALL_STATE(37)] = 1607,
  [SMALL_STATE(38)] = 1641,
  [SMALL_STATE(39)] = 1675,
  [SMALL_STATE(40)] = 1709,
  [SMALL_STATE(41)] = 1743,
  [SMALL_STATE(42)] = 1777,
  [SMALL_STATE(43)] = 1811,
  [SMALL_STATE(44)] = 1845,
  [SMALL_STATE(45)] = 1879,
  [SMALL_STATE(46)] = 1913,
  [SMALL_STATE(47)] = 1956,
  [SMALL_STATE(48)] = 1999,
  [SMALL_STATE(49)] = 2033,
  [SMALL_STATE(50)] = 2065,
  [SMALL_STATE(51)] = 2099,
  [SMALL_STATE(52)] = 2130,
  [SMALL_STATE(53)] = 2161,
  [SMALL_STATE(54)] = 2192,
  [SMALL_STATE(55)] = 2223,
  [SMALL_STATE(56)] = 2249,
  [SMALL_STATE(57)] = 2272,
  [SMALL_STATE(58)] = 2291,
  [SMALL_STATE(59)] = 2316,
  [SMALL_STATE(60)] = 2335,
  [SMALL_STATE(61)] = 2354,
  [SMALL_STATE(62)] = 2373,
  [SMALL_STATE(63)] = 2396,
  [SMALL_STATE(64)] = 2424,
  [SMALL_STATE(65)] = 2442,
  [SMALL_STATE(66)] = 2460,
  [SMALL_STATE(67)] = 2478,
  [SMALL_STATE(68)] = 2496,
  [SMALL_STATE(69)] = 2514,
  [SMALL_STATE(70)] = 2532,
  [SMALL_STATE(71)] = 2550,
  [SMALL_STATE(72)] = 2566,
  [SMALL_STATE(73)] = 2584,
  [SMALL_STATE(74)] = 2612,
  [SMALL_STATE(75)] = 2630,
  [SMALL_STATE(76)] = 2646,
  [SMALL_STATE(77)] = 2664,
  [SMALL_STATE(78)] = 2682,
  [SMALL_STATE(79)] = 2700,
  [SMALL_STATE(80)] = 2727,
  [SMALL_STATE(81)] = 2742,
  [SMALL_STATE(82)] = 2769,
  [SMALL_STATE(83)] = 2784,
  [SMALL_STATE(84)] = 2811,
  [SMALL_STATE(85)] = 2838,
  [SMALL_STATE(86)] = 2865,
  [SMALL_STATE(87)] = 2892,
  [SMALL_STATE(88)] = 2919,
  [SMALL_STATE(89)] = 2946,
  [SMALL_STATE(90)] = 2975,
  [SMALL_STATE(91)] = 2991,
  [SMALL_STATE(92)] = 3015,
  [SMALL_STATE(93)] = 3039,
  [SMALL_STATE(94)] = 3060,
  [SMALL_STATE(95)] = 3083,
  [SMALL_STATE(96)] = 3106,
  [SMALL_STATE(97)] = 3119,
  [SMALL_STATE(98)] = 3142,
  [SMALL_STATE(99)] = 3163,
  [SMALL_STATE(100)] = 3186,
  [SMALL_STATE(101)] = 3207,
  [SMALL_STATE(102)] = 3230,
  [SMALL_STATE(103)] = 3243,
  [SMALL_STATE(104)] = 3266,
  [SMALL_STATE(105)] = 3287,
  [SMALL_STATE(106)] = 3308,
  [SMALL_STATE(107)] = 3327,
  [SMALL_STATE(108)] = 3348,
  [SMALL_STATE(109)] = 3361,
  [SMALL_STATE(110)] = 3374,
  [SMALL_STATE(111)] = 3395,
  [SMALL_STATE(112)] = 3407,
  [SMALL_STATE(113)] = 3427,
  [SMALL_STATE(114)] = 3445,
  [SMALL_STATE(115)] = 3457,
  [SMALL_STATE(116)] = 3475,
  [SMALL_STATE(117)] = 3493,
  [SMALL_STATE(118)] = 3511,
  [SMALL_STATE(119)] = 3527,
  [SMALL_STATE(120)] = 3543,
  [SMALL_STATE(121)] = 3561,
  [SMALL_STATE(122)] = 3573,
  [SMALL_STATE(123)] = 3589,
  [SMALL_STATE(124)] = 3607,
  [SMALL_STATE(125)] = 3627,
  [SMALL_STATE(126)] = 3645,
  [SMALL_STATE(127)] = 3663,
  [SMALL_STATE(128)] = 3683,
  [SMALL_STATE(129)] = 3697,
  [SMALL_STATE(130)] = 3713,
  [SMALL_STATE(131)] = 3729,
  [SMALL_STATE(132)] = 3745,
  [SMALL_STATE(133)] = 3763,
  [SMALL_STATE(134)] = 3781,
  [SMALL_STATE(135)] = 3799,
  [SMALL_STATE(136)] = 3815,
  [SMALL_STATE(137)] = 3831,
  [SMALL_STATE(138)] = 3843,
  [SMALL_STATE(139)] = 3863,
  [SMALL_STATE(140)] = 3878,
  [SMALL_STATE(141)] = 3893,
  [SMALL_STATE(142)] = 3904,
  [SMALL_STATE(143)] = 3919,
  [SMALL_STATE(144)] = 3934,
  [SMALL_STATE(145)] = 3947,
  [SMALL_STATE(146)] = 3962,
  [SMALL_STATE(147)] = 3977,
  [SMALL_STATE(148)] = 3994,
  [SMALL_STATE(149)] = 4009,
  [SMALL_STATE(150)] = 4020,
  [SMALL_STATE(151)] = 4033,
  [SMALL_STATE(152)] = 4050,
  [SMALL_STATE(153)] = 4061,
  [SMALL_STATE(154)] = 4076,
  [SMALL_STATE(155)] = 4087,
  [SMALL_STATE(156)] = 4102,
  [SMALL_STATE(157)] = 4117,
  [SMALL_STATE(158)] = 4132,
  [SMALL_STATE(159)] = 4147,
  [SMALL_STATE(160)] = 4164,
  [SMALL_STATE(161)] = 4181,
  [SMALL_STATE(162)] = 4198,
  [SMALL_STATE(163)] = 4211,
  [SMALL_STATE(164)] = 4224,
  [SMALL_STATE(165)] = 4235,
  [SMALL_STATE(166)] = 4252,
  [SMALL_STATE(167)] = 4263,
  [SMALL_STATE(168)] = 4280,
  [SMALL_STATE(169)] = 4293,
  [SMALL_STATE(170)] = 4306,
  [SMALL_STATE(171)] = 4317,
  [SMALL_STATE(172)] = 4328,
  [SMALL_STATE(173)] = 4339,
  [SMALL_STATE(174)] = 4350,
  [SMALL_STATE(175)] = 4361,
  [SMALL_STATE(176)] = 4378,
  [SMALL_STATE(177)] = 4389,
  [SMALL_STATE(178)] = 4402,
  [SMALL_STATE(179)] = 4419,
  [SMALL_STATE(180)] = 4436,
  [SMALL_STATE(181)] = 4450,
  [SMALL_STATE(182)] = 4464,
  [SMALL_STATE(183)] = 4474,
  [SMALL_STATE(184)] = 4488,
  [SMALL_STATE(185)] = 4498,
  [SMALL_STATE(186)] = 4512,
  [SMALL_STATE(187)] = 4526,
  [SMALL_STATE(188)] = 4536,
  [SMALL_STATE(189)] = 4550,
  [SMALL_STATE(190)] = 4564,
  [SMALL_STATE(191)] = 4574,
  [SMALL_STATE(192)] = 4588,
  [SMALL_STATE(193)] = 4600,
  [SMALL_STATE(194)] = 4614,
  [SMALL_STATE(195)] = 4628,
  [SMALL_STATE(196)] = 4642,
  [SMALL_STATE(197)] = 4656,
  [SMALL_STATE(198)] = 4666,
  [SMALL_STATE(199)] = 4676,
  [SMALL_STATE(200)] = 4686,
  [SMALL_STATE(201)] = 4700,
  [SMALL_STATE(202)] = 4710,
  [SMALL_STATE(203)] = 4724,
  [SMALL_STATE(204)] = 4738,
  [SMALL_STATE(205)] = 4750,
  [SMALL_STATE(206)] = 4762,
  [SMALL_STATE(207)] = 4772,
  [SMALL_STATE(208)] = 4782,
  [SMALL_STATE(209)] = 4796,
  [SMALL_STATE(210)] = 4810,
  [SMALL_STATE(211)] = 4822,
  [SMALL_STATE(212)] = 4836,
  [SMALL_STATE(213)] = 4850,
  [SMALL_STATE(214)] = 4862,
  [SMALL_STATE(215)] = 4876,
  [SMALL_STATE(216)] = 4890,
  [SMALL_STATE(217)] = 4902,
  [SMALL_STATE(218)] = 4916,
  [SMALL_STATE(219)] = 4928,
  [SMALL_STATE(220)] = 4942,
  [SMALL_STATE(221)] = 4952,
  [SMALL_STATE(222)] = 4964,
  [SMALL_STATE(223)] = 4978,
  [SMALL_STATE(224)] = 4988,
  [SMALL_STATE(225)] = 5002,
  [SMALL_STATE(226)] = 5016,
  [SMALL_STATE(227)] = 5026,
  [SMALL_STATE(228)] = 5040,
  [SMALL_STATE(229)] = 5052,
  [SMALL_STATE(230)] = 5066,
  [SMALL_STATE(231)] = 5076,
  [SMALL_STATE(232)] = 5088,
  [SMALL_STATE(233)] = 5102,
  [SMALL_STATE(234)] = 5116,
  [SMALL_STATE(235)] = 5130,
  [SMALL_STATE(236)] = 5142,
  [SMALL_STATE(237)] = 5156,
  [SMALL_STATE(238)] = 5170,
  [SMALL_STATE(239)] = 5180,
  [SMALL_STATE(240)] = 5190,
  [SMALL_STATE(241)] = 5202,
  [SMALL_STATE(242)] = 5216,
  [SMALL_STATE(243)] = 5226,
  [SMALL_STATE(244)] = 5240,
  [SMALL_STATE(245)] = 5254,
  [SMALL_STATE(246)] = 5268,
  [SMALL_STATE(247)] = 5282,
  [SMALL_STATE(248)] = 5292,
  [SMALL_STATE(249)] = 5304,
  [SMALL_STATE(250)] = 5318,
  [SMALL_STATE(251)] = 5332,
  [SMALL_STATE(252)] = 5346,
  [SMALL_STATE(253)] = 5360,
  [SMALL_STATE(254)] = 5374,
  [SMALL_STATE(255)] = 5384,
  [SMALL_STATE(256)] = 5393,
  [SMALL_STATE(257)] = 5402,
  [SMALL_STATE(258)] = 5413,
  [SMALL_STATE(259)] = 5422,
  [SMALL_STATE(260)] = 5433,
  [SMALL_STATE(261)] = 5444,
  [SMALL_STATE(262)] = 5453,
  [SMALL_STATE(263)] = 5464,
  [SMALL_STATE(264)] = 5475,
  [SMALL_STATE(265)] = 5484,
  [SMALL_STATE(266)] = 5493,
  [SMALL_STATE(267)] = 5502,
  [SMALL_STATE(268)] = 5511,
  [SMALL_STATE(269)] = 5520,
  [SMALL_STATE(270)] = 5529,
  [SMALL_STATE(271)] = 5540,
  [SMALL_STATE(272)] = 5551,
  [SMALL_STATE(273)] = 5562,
  [SMALL_STATE(274)] = 5571,
  [SMALL_STATE(275)] = 5580,
  [SMALL_STATE(276)] = 5589,
  [SMALL_STATE(277)] = 5598,
  [SMALL_STATE(278)] = 5607,
  [SMALL_STATE(279)] = 5616,
  [SMALL_STATE(280)] = 5627,
  [SMALL_STATE(281)] = 5636,
  [SMALL_STATE(282)] = 5647,
  [SMALL_STATE(283)] = 5658,
  [SMALL_STATE(284)] = 5667,
  [SMALL_STATE(285)] = 5676,
  [SMALL_STATE(286)] = 5685,
  [SMALL_STATE(287)] = 5694,
  [SMALL_STATE(288)] = 5705,
  [SMALL_STATE(289)] = 5714,
  [SMALL_STATE(290)] = 5723,
  [SMALL_STATE(291)] = 5732,
  [SMALL_STATE(292)] = 5741,
  [SMALL_STATE(293)] = 5750,
  [SMALL_STATE(294)] = 5759,
  [SMALL_STATE(295)] = 5768,
  [SMALL_STATE(296)] = 5777,
  [SMALL_STATE(297)] = 5786,
  [SMALL_STATE(298)] = 5797,
  [SMALL_STATE(299)] = 5806,
  [SMALL_STATE(300)] = 5815,
  [SMALL_STATE(301)] = 5826,
  [SMALL_STATE(302)] = 5834,
  [SMALL_STATE(303)] = 5842,
  [SMALL_STATE(304)] = 5850,
  [SMALL_STATE(305)] = 5858,
  [SMALL_STATE(306)] = 5866,
  [SMALL_STATE(307)] = 5874,
  [SMALL_STATE(308)] = 5882,
  [SMALL_STATE(309)] = 5890,
  [SMALL_STATE(310)] = 5898,
  [SMALL_STATE(311)] = 5906,
  [SMALL_STATE(312)] = 5914,
  [SMALL_STATE(313)] = 5922,
  [SMALL_STATE(314)] = 5930,
  [SMALL_STATE(315)] = 5938,
  [SMALL_STATE(316)] = 5946,
  [SMALL_STATE(317)] = 5954,
  [SMALL_STATE(318)] = 5962,
  [SMALL_STATE(319)] = 5970,
  [SMALL_STATE(320)] = 5978,
  [SMALL_STATE(321)] = 5986,
  [SMALL_STATE(322)] = 5994,
  [SMALL_STATE(323)] = 6002,
  [SMALL_STATE(324)] = 6010,
  [SMALL_STATE(325)] = 6018,
  [SMALL_STATE(326)] = 6026,
  [SMALL_STATE(327)] = 6034,
  [SMALL_STATE(328)] = 6042,
  [SMALL_STATE(329)] = 6050,
  [SMALL_STATE(330)] = 6058,
  [SMALL_STATE(331)] = 6066,
  [SMALL_STATE(332)] = 6074,
  [SMALL_STATE(333)] = 6082,
  [SMALL_STATE(334)] = 6090,
  [SMALL_STATE(335)] = 6098,
  [SMALL_STATE(336)] = 6106,
  [SMALL_STATE(337)] = 6114,
  [SMALL_STATE(338)] = 6122,
  [SMALL_STATE(339)] = 6130,
  [SMALL_STATE(340)] = 6138,
  [SMALL_STATE(341)] = 6146,
  [SMALL_STATE(342)] = 6154,
  [SMALL_STATE(343)] = 6162,
  [SMALL_STATE(344)] = 6170,
  [SMALL_STATE(345)] = 6178,
  [SMALL_STATE(346)] = 6186,
  [SMALL_STATE(347)] = 6194,
  [SMALL_STATE(348)] = 6202,
  [SMALL_STATE(349)] = 6210,
  [SMALL_STATE(350)] = 6218,
  [SMALL_STATE(351)] = 6226,
  [SMALL_STATE(352)] = 6234,
  [SMALL_STATE(353)] = 6242,
  [SMALL_STATE(354)] = 6250,
  [SMALL_STATE(355)] = 6258,
  [SMALL_STATE(356)] = 6266,
  [SMALL_STATE(357)] = 6274,
  [SMALL_STATE(358)] = 6282,
  [SMALL_STATE(359)] = 6290,
  [SMALL_STATE(360)] = 6298,
  [SMALL_STATE(361)] = 6306,
  [SMALL_STATE(362)] = 6314,
  [SMALL_STATE(363)] = 6322,
  [SMALL_STATE(364)] = 6330,
  [SMALL_STATE(365)] = 6338,
  [SMALL_STATE(366)] = 6346,
  [SMALL_STATE(367)] = 6354,
  [SMALL_STATE(368)] = 6362,
  [SMALL_STATE(369)] = 6370,
  [SMALL_STATE(370)] = 6378,
  [SMALL_STATE(371)] = 6386,
  [SMALL_STATE(372)] = 6394,
  [SMALL_STATE(373)] = 6402,
  [SMALL_STATE(374)] = 6410,
  [SMALL_STATE(375)] = 6418,
  [SMALL_STATE(376)] = 6426,
  [SMALL_STATE(377)] = 6434,
  [SMALL_STATE(378)] = 6442,
  [SMALL_STATE(379)] = 6450,
  [SMALL_STATE(380)] = 6458,
  [SMALL_STATE(381)] = 6466,
  [SMALL_STATE(382)] = 6474,
  [SMALL_STATE(383)] = 6482,
  [SMALL_STATE(384)] = 6490,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(262),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(287),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(277),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(295),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(321),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(184),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(263),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(301),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(351),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(257),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(319),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(308),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(271),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(307),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(272),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(313),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(314),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(197),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(279),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(321),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(184),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(263),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(301),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(351),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(257),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(319),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(308),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(271),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(307),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(272),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(313),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(314),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(279),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_shake, 8, 0, 64),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 8, 0, 64),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 7),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 7),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 16),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 16),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 17),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 17),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 17),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 17),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 32),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 32),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 33),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 33),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 32),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 32),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 34),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 34),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 35),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 35),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 37),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 37),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 38),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 38),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 39),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 39),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 36),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 36),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 37),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 37),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command, 4, 0, 40),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 4, 0, 40),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_alias, 4, 0, 41),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 4, 0, 41),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_hide_command, 4, 0, 40),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 4, 0, 40),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unhide_command, 4, 0, 40),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 4, 0, 40),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_pause_script, 4, 0, 42),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 42),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unpause_script, 4, 0, 42),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 42),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 50),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 50),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 5, 0, 51),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 5, 0, 51),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 50),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 50),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command_arg, 6, 0, 56),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 6, 0, 56),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_play_entity_animation, 6, 0, 57),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 6, 0, 57),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_in, 8, 0, 63),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_in, 8, 0, 63),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_out, 8, 0, 63),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_out, 8, 0, 63),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 36),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 36),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [301] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(262),
  [304] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(262),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(338),
  [310] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(157),
  [313] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(287),
  [316] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(277),
  [319] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(201),
  [322] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(295),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(283),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 45),
  [335] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 45), SHIFT_REPEAT(283),
  [338] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 45), SHIFT_REPEAT(182),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [361] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(365),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [373] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 30),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 30),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 6),
  [395] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 6),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [411] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [415] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 10),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [419] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 28),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 4),
  [425] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 4),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [435] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 3),
  [439] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 3),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 5),
  [443] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 5),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 7),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 26),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [463] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(325),
  [466] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(280),
  [469] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(238),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 46),
  [476] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 46),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 29),
  [484] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 29),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(290),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [496] = {.entry = {.count = 1, .reusable = false}}, SHIFT(376),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(376),
  [502] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [504] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [506] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 53),
  [508] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 53),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [514] = {.entry = {.count = 1, .reusable = false}}, SHIFT(258),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 22),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 11),
  [522] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31), SHIFT_REPEAT(80),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31),
  [527] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31), SHIFT_REPEAT(258),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(303),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 14),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 48),
  [552] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 48), SHIFT_REPEAT(128),
  [555] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 48),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 49),
  [559] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 49),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 2, 0, 18),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 1, 0, 8),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 54),
  [567] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 54),
  [569] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 54), SHIFT_REPEAT(326),
  [572] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21),
  [576] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21), SHIFT_REPEAT(290),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [581] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(290),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(324),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(337),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(379),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(382),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 27),
  [624] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 27),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(335),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(373),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(377),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(374),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(342),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(361),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [668] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24), SHIFT_REPEAT(199),
  [671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 25),
  [675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 11),
  [679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(370),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [707] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 44),
  [709] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 44), SHIFT_REPEAT(320),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 47),
  [720] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 47),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [724] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [734] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 1, 0, 0),
  [736] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [738] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 52),
  [740] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [742] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 0),
  [744] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 58),
  [746] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 59),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(369),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(296),
  [752] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 61),
  [754] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 62),
  [756] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 62),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(380),
  [760] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 43),
  [762] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 1, 0, 0),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [777] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [780] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0),
  [782] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [792] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 11),
  [794] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [796] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [798] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [800] = {.entry = {.count = 1, .reusable = true}}, SHIFT(268),
  [802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [806] = {.entry = {.count = 1, .reusable = true}}, SHIFT(329),
  [808] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [810] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [812] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier, 1, 0, 2),
  [814] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [816] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 12),
  [818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [820] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [824] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [826] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [828] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [830] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [832] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [834] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 15),
  [836] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 15),
  [838] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [846] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [852] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(230),
  [855] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [863] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(233),
  [866] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [868] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [870] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [873] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(330),
  [877] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [879] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(291),
  [882] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [884] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier, 2, 0, 9),
  [886] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [888] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [890] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [892] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [894] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [896] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [898] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [900] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [902] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(259),
  [905] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [909] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(288),
  [912] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [914] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [916] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(289),
  [919] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [921] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [933] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [935] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [937] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [939] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [941] = {.entry = {.count = 1, .reusable = true}}, SHIFT(363),
  [943] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [949] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [951] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [953] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [955] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [957] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [959] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 19),
  [961] = {.entry = {.count = 1, .reusable = true}}, SHIFT(378),
  [963] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(256),
  [966] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [968] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(253),
  [971] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [973] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [975] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [977] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(159),
  [980] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(384),
  [988] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [990] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [994] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [996] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [998] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [1000] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1002] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [1004] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [1006] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [1008] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [1010] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [1012] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 55),
  [1014] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [1016] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [1018] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [1020] = {.entry = {.count = 1, .reusable = true}}, SHIFT(383),
  [1022] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [1024] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 23),
  [1026] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 60),
  [1028] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [1030] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [1032] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [1036] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 13),
  [1038] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [1040] = {.entry = {.count = 1, .reusable = true}}, SHIFT(327),
  [1042] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [1044] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [1046] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [1052] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [1054] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1056] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1058] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1060] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [1062] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [1064] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [1066] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 0),
  [1068] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [1070] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1072] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [1074] = {.entry = {.count = 1, .reusable = true}}, SHIFT(348),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1078] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1080] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [1082] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [1084] = {.entry = {.count = 1, .reusable = true}}, SHIFT(381),
  [1086] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1088] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1090] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1092] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [1094] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [1096] = {.entry = {.count = 1, .reusable = true}}, SHIFT(309),
  [1098] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [1100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [1102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [1108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [1112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [1118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 2, 0, 0),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [1122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [1124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(302),
  [1126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [1128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [1130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [1132] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [1136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [1138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [1144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [1148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [1152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [1154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [1158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [1162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 3, 0, 0),
  [1164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [1166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [1170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [1172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [1174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [1178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [1180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [1182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [1184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [1186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [1188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [1190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 4, 0, 0),
  [1192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [1196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [1198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [1200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [1202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [1204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [1206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 5, 0, 0),
  [1208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [1210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
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
