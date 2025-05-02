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
#define STATE_COUNT 428
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 189
#define ALIAS_COUNT 0
#define TOKEN_COUNT 81
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 40
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 68

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
  anon_sym_position = 79,
  sym_geometry = 80,
  sym_document = 81,
  sym_bareword_expansion = 82,
  sym_quoted_string_expansion = 83,
  sym_string_expansion = 84,
  sym_number_expansion = 85,
  sym_DURATION = 86,
  sym_duration_expansion = 87,
  sym_DISTANCE = 88,
  sym_distance_expansion = 89,
  sym_QUANTITY = 90,
  sym_quantity_expansion = 91,
  sym_color_expansion = 92,
  sym__root = 93,
  sym_include_macro = 94,
  sym_constant_assignment = 95,
  sym_add_serial_dialog_settings = 96,
  sym_serial_dialog_parameter_int = 97,
  sym_serial_dialog_parameter = 98,
  sym_add_dialog_settings = 99,
  sym_target_label = 100,
  sym_target_entity = 101,
  sym_add_dialog_settings_target = 102,
  sym__dialog_parameter_int = 103,
  sym__dialog_parameter_string = 104,
  sym_dialog_parameter = 105,
  sym_dialog_definition = 106,
  sym__dialog_block = 107,
  sym_dialog = 108,
  sym_dialog_identifier = 109,
  sym_dialog_option = 110,
  sym_serial_dialog_definition = 111,
  sym__serial_dialog_block = 112,
  sym_serial_dialog = 113,
  sym_serial_dialog_option = 114,
  sym_script_definition = 115,
  sym_script_block = 116,
  sym__script_item = 117,
  sym_json_literal = 118,
  sym_json_array = 119,
  sym_json_object = 120,
  sym_json_name_value_pair = 121,
  sym__json_item = 122,
  sym_rand_macro = 123,
  sym_label_definition = 124,
  sym__action_item = 125,
  sym_action_return_statement = 126,
  sym_action_close_dialog = 127,
  sym_action_close_serial_dialog = 128,
  sym_action_save_slot = 129,
  sym_action_load_slot = 130,
  sym_action_erase_slot = 131,
  sym_action_load_map = 132,
  sym_action_run_script = 133,
  sym_action_goto_label = 134,
  sym_action_goto_index = 135,
  sym_action_non_blocking_delay = 136,
  sym_action_blocking_delay = 137,
  sym_action_show_dialog = 138,
  sym_action_show_serial_dialog = 139,
  sym_action_concat_serial_dialog = 140,
  sym_action_delete_command = 141,
  sym_action_delete_command_arg = 142,
  sym_action_delete_alias = 143,
  sym_action_hide_command = 144,
  sym_action_unhide_command = 145,
  sym_entity = 146,
  sym_entity_identifier = 147,
  sym_entity_identifier_expansion = 148,
  sym_map = 149,
  sym_entity_or_map_identifier = 150,
  sym_entity_or_map_identifier_expansion = 151,
  sym_action_pause_script = 152,
  sym_action_unpause_script = 153,
  sym_action_camera_fade_in = 154,
  sym_action_camera_fade_out = 155,
  sym_action_camera_shake = 156,
  sym_action_play_entity_animation = 157,
  sym_camera = 158,
  sym_movable_identifier = 159,
  sym_movable_identifier_expansion = 160,
  sym_coordinate_identifier = 161,
  sym_coordinate_identifier_expansion = 162,
  sym_action_set_position = 163,
  aux_sym_document_repeat1 = 164,
  aux_sym_bareword_expansion_repeat1 = 165,
  aux_sym_quoted_string_expansion_repeat1 = 166,
  aux_sym_string_expansion_repeat1 = 167,
  aux_sym_number_expansion_repeat1 = 168,
  aux_sym_duration_expansion_repeat1 = 169,
  aux_sym_distance_expansion_repeat1 = 170,
  aux_sym_quantity_expansion_repeat1 = 171,
  aux_sym_color_expansion_repeat1 = 172,
  aux_sym_add_serial_dialog_settings_repeat1 = 173,
  aux_sym_add_dialog_settings_repeat1 = 174,
  aux_sym_add_dialog_settings_target_repeat1 = 175,
  aux_sym__dialog_block_repeat1 = 176,
  aux_sym_dialog_repeat1 = 177,
  aux_sym_dialog_repeat2 = 178,
  aux_sym_serial_dialog_repeat1 = 179,
  aux_sym_serial_dialog_repeat2 = 180,
  aux_sym_serial_dialog_repeat3 = 181,
  aux_sym_script_block_repeat1 = 182,
  aux_sym_json_array_repeat1 = 183,
  aux_sym_json_object_repeat1 = 184,
  aux_sym_entity_identifier_expansion_repeat1 = 185,
  aux_sym_entity_or_map_identifier_expansion_repeat1 = 186,
  aux_sym_movable_identifier_expansion_repeat1 = 187,
  aux_sym_coordinate_identifier_expansion_repeat1 = 188,
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
  [anon_sym_position] = "position",
  [sym_geometry] = "geometry",
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
  [sym_camera] = "camera",
  [sym_movable_identifier] = "movable_identifier",
  [sym_movable_identifier_expansion] = "movable_identifier_expansion",
  [sym_coordinate_identifier] = "coordinate_identifier",
  [sym_coordinate_identifier_expansion] = "coordinate_identifier_expansion",
  [sym_action_set_position] = "action_set_position",
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
  [aux_sym_movable_identifier_expansion_repeat1] = "movable_identifier_expansion_repeat1",
  [aux_sym_coordinate_identifier_expansion_repeat1] = "coordinate_identifier_expansion_repeat1",
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
  [anon_sym_position] = anon_sym_position,
  [sym_geometry] = sym_geometry,
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
  [sym_camera] = sym_camera,
  [sym_movable_identifier] = sym_movable_identifier,
  [sym_movable_identifier_expansion] = sym_movable_identifier_expansion,
  [sym_coordinate_identifier] = sym_coordinate_identifier,
  [sym_coordinate_identifier_expansion] = sym_coordinate_identifier_expansion,
  [sym_action_set_position] = sym_action_set_position,
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
  [aux_sym_movable_identifier_expansion_repeat1] = aux_sym_movable_identifier_expansion_repeat1,
  [aux_sym_coordinate_identifier_expansion_repeat1] = aux_sym_coordinate_identifier_expansion_repeat1,
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
  [anon_sym_position] = {
    .visible = true,
    .named = false,
  },
  [sym_geometry] = {
    .visible = true,
    .named = true,
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
  [sym_camera] = {
    .visible = true,
    .named = true,
  },
  [sym_movable_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_movable_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_coordinate_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_coordinate_identifier_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_action_set_position] = {
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
  [aux_sym_movable_identifier_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_coordinate_identifier_expansion_repeat1] = {
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
  field_coordinate = 7,
  field_count = 8,
  field_dialog = 9,
  field_dialog_identifier = 10,
  field_dialog_name = 11,
  field_dialog_option = 12,
  field_dialog_parameter = 13,
  field_distance = 14,
  field_duration = 15,
  field_entity = 16,
  field_entity_identifier = 17,
  field_entity_or_map = 18,
  field_entity_type = 19,
  field_fileName = 20,
  field_geometry = 21,
  field_index = 22,
  field_label = 23,
  field_map = 24,
  field_message = 25,
  field_movable = 26,
  field_option_type = 27,
  field_property = 28,
  field_script = 29,
  field_script_name = 30,
  field_serial_dialog = 31,
  field_serial_dialog_name = 32,
  field_serial_dialog_option = 33,
  field_serial_dialog_parameter = 34,
  field_serial_message = 35,
  field_slot = 36,
  field_suffix = 37,
  field_target = 38,
  field_type = 39,
  field_value = 40,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_amplitude] = "amplitude",
  [field_animation] = "animation",
  [field_argument] = "argument",
  [field_color] = "color",
  [field_command] = "command",
  [field_coordinate] = "coordinate",
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
  [field_geometry] = "geometry",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_message] = "message",
  [field_movable] = "movable",
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
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 2},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 1},
  [9] = {.index = 10, .length = 1},
  [10] = {.index = 11, .length = 2},
  [11] = {.index = 13, .length = 2},
  [12] = {.index = 15, .length = 1},
  [13] = {.index = 16, .length = 1},
  [14] = {.index = 17, .length = 1},
  [15] = {.index = 18, .length = 1},
  [16] = {.index = 19, .length = 1},
  [17] = {.index = 20, .length = 1},
  [18] = {.index = 21, .length = 1},
  [19] = {.index = 22, .length = 2},
  [20] = {.index = 24, .length = 2},
  [21] = {.index = 26, .length = 2},
  [22] = {.index = 28, .length = 1},
  [23] = {.index = 29, .length = 2},
  [24] = {.index = 31, .length = 2},
  [25] = {.index = 33, .length = 1},
  [26] = {.index = 34, .length = 2},
  [27] = {.index = 36, .length = 2},
  [28] = {.index = 38, .length = 2},
  [29] = {.index = 40, .length = 1},
  [30] = {.index = 41, .length = 1},
  [31] = {.index = 42, .length = 2},
  [32] = {.index = 44, .length = 1},
  [33] = {.index = 45, .length = 2},
  [34] = {.index = 47, .length = 1},
  [35] = {.index = 48, .length = 1},
  [36] = {.index = 49, .length = 1},
  [37] = {.index = 50, .length = 1},
  [38] = {.index = 51, .length = 1},
  [39] = {.index = 52, .length = 1},
  [40] = {.index = 53, .length = 1},
  [41] = {.index = 54, .length = 1},
  [42] = {.index = 55, .length = 1},
  [43] = {.index = 56, .length = 1},
  [44] = {.index = 57, .length = 2},
  [45] = {.index = 59, .length = 2},
  [46] = {.index = 61, .length = 2},
  [47] = {.index = 63, .length = 3},
  [48] = {.index = 66, .length = 2},
  [49] = {.index = 68, .length = 2},
  [50] = {.index = 70, .length = 3},
  [51] = {.index = 73, .length = 1},
  [52] = {.index = 74, .length = 2},
  [53] = {.index = 76, .length = 3},
  [54] = {.index = 79, .length = 2},
  [55] = {.index = 81, .length = 2},
  [56] = {.index = 83, .length = 4},
  [57] = {.index = 87, .length = 2},
  [58] = {.index = 89, .length = 2},
  [59] = {.index = 91, .length = 2},
  [60] = {.index = 93, .length = 3},
  [61] = {.index = 96, .length = 2},
  [62] = {.index = 98, .length = 2},
  [63] = {.index = 100, .length = 3},
  [64] = {.index = 103, .length = 3},
  [65] = {.index = 106, .length = 2},
  [66] = {.index = 108, .length = 2},
  [67] = {.index = 110, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_entity_type, 0},
  [2] =
    {field_type, 0},
  [3] =
    {field_fileName, 1},
  [4] =
    {field_serial_dialog, 2, .inherited = true},
    {field_serial_dialog_name, 1},
  [6] =
    {field_dialog, 2, .inherited = true},
    {field_dialog_name, 1},
  [8] =
    {field_script_name, 1},
  [9] =
    {field_label, 0},
  [10] =
    {field_target, 0},
  [11] =
    {field_entity, 1},
    {field_entity_type, 0},
  [13] =
    {field_label, 0},
    {field_value, 2},
  [15] =
    {field_suffix, 1},
  [16] =
    {field_serial_message, 0},
  [17] =
    {field_serial_dialog_parameter, 0},
  [18] =
    {field_serial_message, 0, .inherited = true},
  [19] =
    {field_dialog, 0},
  [20] =
    {field_script, 1},
  [21] =
    {field_duration, 1},
  [22] =
    {field_entity, 1},
    {field_target, 0},
  [24] =
    {field_entity, 1},
    {field_type, 0},
  [26] =
    {field_property, 0},
    {field_value, 1},
  [28] =
    {field_serial_dialog, 1},
  [29] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [31] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [33] =
    {field_serial_dialog_option, 0},
  [34] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [36] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [38] =
    {field_type, 0},
    {field_value, 1},
  [40] =
    {field_message, 0},
  [41] =
    {field_dialog_parameter, 0},
  [42] =
    {field_dialog_identifier, 0},
    {field_message, 1, .inherited = true},
  [44] =
    {field_dialog, 1, .inherited = true},
  [45] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [47] =
    {field_slot, 2},
  [48] =
    {field_map, 2},
  [49] =
    {field_label, 2},
  [50] =
    {field_index, 2},
  [51] =
    {field_serial_dialog_name, 2},
  [52] =
    {field_serial_dialog, 2, .inherited = true},
  [53] =
    {field_dialog_name, 2},
  [54] =
    {field_dialog, 2, .inherited = true},
  [55] =
    {field_command, 2},
  [56] =
    {field_alias, 2},
  [57] =
    {field_entity_or_map, 1},
    {field_script, 2},
  [59] =
    {field_geometry, 1},
    {field_type, 0},
  [61] =
    {field_coordinate, 2},
    {field_movable, 0},
  [63] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [66] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [68] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [70] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [73] =
    {field_dialog_option, 0},
  [74] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [76] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [79] =
    {field_serial_dialog, 3, .inherited = true},
    {field_serial_dialog_name, 2},
  [81] =
    {field_dialog, 3, .inherited = true},
    {field_dialog_name, 2},
  [83] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [87] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [89] =
    {field_property, 0},
    {field_value, 2},
  [91] =
    {field_argument, 4},
    {field_command, 2},
  [93] =
    {field_animation, 3},
    {field_count, 4},
    {field_entity_identifier, 0},
  [96] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [98] =
    {field_target, 1},
    {field_type, 0},
  [100] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [103] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [106] =
    {field_label, 1},
    {field_script, 3},
  [108] =
    {field_color, 4},
    {field_duration, 6},
  [110] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(265);
      ADVANCE_MAP(
        '!', 490,
        '"', 5,
        '#', 477,
        '$', 261,
        '(', 491,
        ')', 492,
        '+', 520,
        ',', 437,
        '-', 12,
        '/', 9,
        ':', 482,
        ';', 453,
        '=', 454,
        '>', 475,
        'I', 163,
        '[', 436,
        ']', 438,
        '_', 476,
        'a', 55,
        'b', 139,
        'c', 17,
        'd', 67,
        'e', 155,
        'f', 18,
        'g', 90,
        'h', 118,
        'i', 164,
        'j', 212,
        'l', 20,
        'm', 22,
        'n', 43,
        'o', 165,
        'p', 23,
        'r', 37,
        's', 442,
        't', 113,
        'u', 166,
        'w', 40,
        'x', 444,
        'y', 100,
        '{', 460,
        '}', 461,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(263);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 5,
        '#', 258,
        '$', 261,
        '/', 9,
        ';', 453,
        '[', 436,
        ']', 438,
        'b', 362,
        'c', 368,
        'f', 286,
        'g', 402,
        'm', 281,
        'o', 338,
        'r', 330,
        't', 342,
        'w', 343,
        'y', 332,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 5,
        '$', 261,
        ',', 437,
        '/', 9,
        '>', 475,
        '[', 436,
        ']', 438,
        'e', 384,
        'n', 288,
        '{', 460,
        '}', 461,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(5);
      if (lookahead == '$') ADVANCE(261);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '[') ADVANCE(436);
      if (lookahead == 'i') ADVANCE(383);
      if (lookahead == 'l') ADVANCE(277);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 5,
        '-', 13,
        '/', 9,
        '=', 454,
        'I', 163,
        '[', 436,
        ']', 438,
        'a', 150,
        'b', 180,
        'c', 16,
        'd', 87,
        'e', 154,
        'f', 18,
        'g', 89,
        'i', 172,
        'l', 19,
        'm', 36,
        'n', 43,
        'o', 242,
        'p', 146,
        's', 68,
        't', 198,
        'w', 203,
        '{', 460,
        '}', 461,
        '#', 476,
        '_', 476,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(484);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(439);
      if (lookahead == '\\') ADVANCE(262);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '$', 261,
        ',', 437,
        '/', 9,
        ';', 453,
        '[', 436,
        ']', 438,
        'm', 209,
        'p', 116,
        's', 441,
        'x', 444,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      END_STATE();
    case 7:
      if (lookahead == '$') ADVANCE(261);
      if (lookahead == ',') ADVANCE(437);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ';') ADVANCE(453);
      if (lookahead == '[') ADVANCE(436);
      if (lookahead == ']') ADVANCE(438);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        ')', 492,
        ',', 437,
        '/', 9,
        '[', 436,
        ']', 438,
        'b', 364,
        'c', 273,
        'd', 325,
        'e', 379,
        'g', 392,
        'h', 347,
        'j', 404,
        'l', 394,
        'p', 278,
        'r', 279,
        's', 274,
        'u', 375,
        'w', 282,
        '}', 461,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(267);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(266);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '>') ADVANCE(539);
      if (lookahead == 'I') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(484);
      END_STATE();
    case 13:
      if (lookahead == 'I') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(484);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(63);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(234);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(161);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(161);
      if (lookahead == 'l') ADVANCE(183);
      if (lookahead == 'o') ADVANCE(156);
      if (lookahead == 'y') ADVANCE(39);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(112);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 's') ADVANCE(441);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(246);
      if (lookahead == 'i') ADVANCE(252);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(202);
      if (lookahead == 'x') ADVANCE(443);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(246);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(202);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(249);
      if (lookahead == 'c') ADVANCE(204);
      if (lookahead == 'e') ADVANCE(142);
      if (lookahead == 'h') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(188);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(257);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(446);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(138);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(138);
      if (lookahead == 'o') ADVANCE(251);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(193);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(534);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(147);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'o') ADVANCE(52);
      if (lookahead == 'u') ADVANCE(69);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(210);
      if (lookahead == 'g') ADVANCE(178);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(192);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(244);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(167);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(123);
      if (lookahead == 'h') ADVANCE(124);
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(222);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(158);
      if (lookahead == 'u') ADVANCE(144);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(214);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(175);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(149);
      END_STATE();
    case 47:
      if (lookahead == 'a') ADVANCE(130);
      END_STATE();
    case 48:
      if (lookahead == 'a') ADVANCE(248);
      END_STATE();
    case 49:
      if (lookahead == 'a') ADVANCE(241);
      END_STATE();
    case 50:
      if (lookahead == 'b') ADVANCE(93);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(136);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(137);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(73);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead == 'l') ADVANCE(117);
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(455);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(446);
      if (lookahead == 't') ADVANCE(243);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(500);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(488);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(519);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(70);
      if (lookahead == 'l') ADVANCE(215);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(71);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(131);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(83);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(84);
      END_STATE();
    case 66:
      if (lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(107);
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(142);
      if (lookahead == 'h') ADVANCE(28);
      if (lookahead == 'l') ADVANCE(188);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(446);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(536);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(522);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(471);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(445);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(497);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(485);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(495);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(470);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(502);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(486);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(530);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(542);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(517);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(524);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(451);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(532);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(253);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(106);
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(195);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(191);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(191);
      if (lookahead == 'o') ADVANCE(231);
      if (lookahead == 'r') ADVANCE(95);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(167);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(141);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(196);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(197);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(176);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(232);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(227);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(153);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(177);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(218);
      END_STATE();
    case 104:
      if (lookahead == 'f') ADVANCE(528);
      END_STATE();
    case 105:
      if (lookahead == 'f') ADVANCE(122);
      END_STATE();
    case 106:
      if (lookahead == 'f') ADVANCE(38);
      END_STATE();
    case 107:
      if (lookahead == 'f') ADVANCE(38);
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 108:
      if (lookahead == 'g') ADVANCE(463);
      END_STATE();
    case 109:
      if (lookahead == 'g') ADVANCE(457);
      END_STATE();
    case 110:
      if (lookahead == 'g') ADVANCE(211);
      END_STATE();
    case 111:
      if (lookahead == 'g') ADVANCE(178);
      END_STATE();
    case 112:
      if (lookahead == 'g') ADVANCE(97);
      if (lookahead == 'p') ADVANCE(504);
      END_STATE();
    case 113:
      if (lookahead == 'h') ADVANCE(199);
      if (lookahead == 'r') ADVANCE(245);
      if (lookahead == 'w') ADVANCE(115);
      END_STATE();
    case 114:
      if (lookahead == 'h') ADVANCE(134);
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 115:
      if (lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 116:
      if (lookahead == 'i') ADVANCE(252);
      if (lookahead == 'x') ADVANCE(443);
      END_STATE();
    case 117:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 118:
      if (lookahead == 'i') ADVANCE(62);
      END_STATE();
    case 119:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(194);
      END_STATE();
    case 121:
      if (lookahead == 'i') ADVANCE(111);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(179);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(221);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(230);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(152);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(228);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(229);
      END_STATE();
    case 130:
      if (lookahead == 'i') ADVANCE(225);
      END_STATE();
    case 131:
      if (lookahead == 'i') ADVANCE(46);
      END_STATE();
    case 132:
      if (lookahead == 'i') ADVANCE(189);
      END_STATE();
    case 133:
      if (lookahead == 'i') ADVANCE(233);
      END_STATE();
    case 134:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 135:
      if (lookahead == 'i') ADVANCE(190);
      END_STATE();
    case 136:
      if (lookahead == 'k') ADVANCE(446);
      END_STATE();
    case 137:
      if (lookahead == 'k') ADVANCE(511);
      END_STATE();
    case 138:
      if (lookahead == 'k') ADVANCE(81);
      END_STATE();
    case 139:
      if (lookahead == 'l') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(208);
      END_STATE();
    case 140:
      if (lookahead == 'l') ADVANCE(487);
      END_STATE();
    case 141:
      if (lookahead == 'l') ADVANCE(466);
      END_STATE();
    case 142:
      if (lookahead == 'l') ADVANCE(104);
      if (lookahead == 'r') ADVANCE(128);
      if (lookahead == 't') ADVANCE(239);
      END_STATE();
    case 143:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 144:
      if (lookahead == 'l') ADVANCE(140);
      END_STATE();
    case 145:
      if (lookahead == 'l') ADVANCE(247);
      END_STATE();
    case 146:
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(201);
      END_STATE();
    case 147:
      if (lookahead == 'l') ADVANCE(182);
      END_STATE();
    case 148:
      if (lookahead == 'l') ADVANCE(184);
      END_STATE();
    case 149:
      if (lookahead == 'l') ADVANCE(185);
      END_STATE();
    case 150:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 151:
      if (lookahead == 'l') ADVANCE(224);
      END_STATE();
    case 152:
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 153:
      if (lookahead == 'l') ADVANCE(148);
      END_STATE();
    case 154:
      if (lookahead == 'm') ADVANCE(186);
      if (lookahead == 'n') ADVANCE(240);
      END_STATE();
    case 155:
      if (lookahead == 'm') ADVANCE(186);
      if (lookahead == 'n') ADVANCE(240);
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 156:
      if (lookahead == 'm') ADVANCE(160);
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 157:
      if (lookahead == 'm') ADVANCE(49);
      END_STATE();
    case 158:
      if (lookahead == 'm') ADVANCE(72);
      END_STATE();
    case 159:
      if (lookahead == 'm') ADVANCE(98);
      END_STATE();
    case 160:
      if (lookahead == 'm') ADVANCE(45);
      END_STATE();
    case 161:
      if (lookahead == 'm') ADVANCE(91);
      END_STATE();
    case 162:
      if (lookahead == 'm') ADVANCE(102);
      END_STATE();
    case 163:
      if (lookahead == 'n') ADVANCE(105);
      END_STATE();
    case 164:
      if (lookahead == 'n') ADVANCE(538);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(54);
      if (lookahead == 'u') ADVANCE(219);
      if (lookahead == 'v') ADVANCE(88);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(114);
      END_STATE();
    case 167:
      if (lookahead == 'n') ADVANCE(446);
      END_STATE();
    case 168:
      if (lookahead == 'n') ADVANCE(480);
      END_STATE();
    case 169:
      if (lookahead == 'n') ADVANCE(493);
      END_STATE();
    case 170:
      if (lookahead == 'n') ADVANCE(544);
      END_STATE();
    case 171:
      if (lookahead == 'n') ADVANCE(543);
      END_STATE();
    case 172:
      if (lookahead == 'n') ADVANCE(537);
      END_STATE();
    case 173:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 174:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 175:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 176:
      if (lookahead == 'n') ADVANCE(235);
      END_STATE();
    case 177:
      if (lookahead == 'n') ADVANCE(226);
      END_STATE();
    case 178:
      if (lookahead == 'n') ADVANCE(162);
      END_STATE();
    case 179:
      if (lookahead == 'n') ADVANCE(129);
      END_STATE();
    case 180:
      if (lookahead == 'o') ADVANCE(208);
      END_STATE();
    case 181:
      if (lookahead == 'o') ADVANCE(505);
      END_STATE();
    case 182:
      if (lookahead == 'o') ADVANCE(108);
      END_STATE();
    case 183:
      if (lookahead == 'o') ADVANCE(213);
      END_STATE();
    case 184:
      if (lookahead == 'o') ADVANCE(250);
      END_STATE();
    case 185:
      if (lookahead == 'o') ADVANCE(109);
      END_STATE();
    case 186:
      if (lookahead == 'o') ADVANCE(236);
      END_STATE();
    case 187:
      if (lookahead == 'o') ADVANCE(168);
      END_STATE();
    case 188:
      if (lookahead == 'o') ADVANCE(220);
      END_STATE();
    case 189:
      if (lookahead == 'o') ADVANCE(170);
      END_STATE();
    case 190:
      if (lookahead == 'o') ADVANCE(171);
      END_STATE();
    case 191:
      if (lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 192:
      if (lookahead == 'p') ADVANCE(504);
      END_STATE();
    case 193:
      if (lookahead == 'p') ADVANCE(462);
      END_STATE();
    case 194:
      if (lookahead == 'p') ADVANCE(223);
      END_STATE();
    case 195:
      if (lookahead == 'r') ADVANCE(540);
      END_STATE();
    case 196:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 197:
      if (lookahead == 'r') ADVANCE(526);
      END_STATE();
    case 198:
      if (lookahead == 'r') ADVANCE(245);
      END_STATE();
    case 199:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 200:
      if (lookahead == 'r') ADVANCE(256);
      END_STATE();
    case 201:
      if (lookahead == 'r') ADVANCE(238);
      END_STATE();
    case 202:
      if (lookahead == 'r') ADVANCE(238);
      if (lookahead == 's') ADVANCE(133);
      END_STATE();
    case 203:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 204:
      if (lookahead == 'r') ADVANCE(120);
      END_STATE();
    case 205:
      if (lookahead == 'r') ADVANCE(169);
      END_STATE();
    case 206:
      if (lookahead == 'r') ADVANCE(31);
      END_STATE();
    case 207:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 208:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 209:
      if (lookahead == 's') ADVANCE(441);
      END_STATE();
    case 210:
      if (lookahead == 's') ADVANCE(521);
      END_STATE();
    case 211:
      if (lookahead == 's') ADVANCE(459);
      END_STATE();
    case 212:
      if (lookahead == 's') ADVANCE(187);
      END_STATE();
    case 213:
      if (lookahead == 's') ADVANCE(76);
      END_STATE();
    case 214:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 215:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 216:
      if (lookahead == 's') ADVANCE(80);
      END_STATE();
    case 217:
      if (lookahead == 's') ADVANCE(85);
      END_STATE();
    case 218:
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 219:
      if (lookahead == 't') ADVANCE(541);
      END_STATE();
    case 220:
      if (lookahead == 't') ADVANCE(499);
      END_STATE();
    case 221:
      if (lookahead == 't') ADVANCE(509);
      END_STATE();
    case 222:
      if (lookahead == 't') ADVANCE(515);
      END_STATE();
    case 223:
      if (lookahead == 't') ADVANCE(478);
      END_STATE();
    case 224:
      if (lookahead == 't') ADVANCE(465);
      END_STATE();
    case 225:
      if (lookahead == 't') ADVANCE(472);
      END_STATE();
    case 226:
      if (lookahead == 't') ADVANCE(473);
      END_STATE();
    case 227:
      if (lookahead == 't') ADVANCE(474);
      END_STATE();
    case 228:
      if (lookahead == 't') ADVANCE(254);
      END_STATE();
    case 229:
      if (lookahead == 't') ADVANCE(255);
      END_STATE();
    case 230:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 231:
      if (lookahead == 't') ADVANCE(181);
      END_STATE();
    case 232:
      if (lookahead == 't') ADVANCE(200);
      END_STATE();
    case 233:
      if (lookahead == 't') ADVANCE(132);
      END_STATE();
    case 234:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 235:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 236:
      if (lookahead == 't') ADVANCE(77);
      END_STATE();
    case 237:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 238:
      if (lookahead == 't') ADVANCE(207);
      END_STATE();
    case 239:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 240:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 241:
      if (lookahead == 't') ADVANCE(135);
      END_STATE();
    case 242:
      if (lookahead == 'u') ADVANCE(219);
      END_STATE();
    case 243:
      if (lookahead == 'u') ADVANCE(205);
      END_STATE();
    case 244:
      if (lookahead == 'u') ADVANCE(151);
      END_STATE();
    case 245:
      if (lookahead == 'u') ADVANCE(75);
      END_STATE();
    case 246:
      if (lookahead == 'u') ADVANCE(216);
      END_STATE();
    case 247:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 248:
      if (lookahead == 'u') ADVANCE(217);
      END_STATE();
    case 249:
      if (lookahead == 'v') ADVANCE(74);
      END_STATE();
    case 250:
      if (lookahead == 'w') ADVANCE(446);
      END_STATE();
    case 251:
      if (lookahead == 'w') ADVANCE(513);
      END_STATE();
    case 252:
      if (lookahead == 'x') ADVANCE(443);
      END_STATE();
    case 253:
      if (lookahead == 'x') ADVANCE(507);
      END_STATE();
    case 254:
      if (lookahead == 'y') ADVANCE(468);
      END_STATE();
    case 255:
      if (lookahead == 'y') ADVANCE(483);
      END_STATE();
    case 256:
      if (lookahead == 'y') ADVANCE(545);
      END_STATE();
    case 257:
      if (lookahead == 'y') ADVANCE(96);
      END_STATE();
    case 258:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(260);
      END_STATE();
    case 259:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(449);
      END_STATE();
    case 260:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(259);
      END_STATE();
    case 261:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(450);
      END_STATE();
    case 262:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(5);
      END_STATE();
    case 263:
      if (eof) ADVANCE(265);
      ADVANCE_MAP(
        '!', 490,
        '"', 5,
        '#', 477,
        '$', 261,
        '(', 491,
        ')', 492,
        '+', 520,
        ',', 437,
        '-', 12,
        '/', 9,
        ':', 482,
        ';', 453,
        '=', 454,
        '>', 475,
        'I', 163,
        '[', 436,
        ']', 438,
        '_', 476,
        'a', 55,
        'b', 139,
        'c', 17,
        'd', 67,
        'e', 155,
        'f', 18,
        'g', 90,
        'h', 118,
        'i', 164,
        'j', 212,
        'l', 20,
        'm', 21,
        'n', 43,
        'o', 165,
        'p', 24,
        'r', 37,
        's', 25,
        't', 113,
        'u', 166,
        'w', 40,
        'y', 100,
        '{', 460,
        '}', 461,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(263);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      END_STATE();
    case 264:
      if (eof) ADVANCE(265);
      ADVANCE_MAP(
        '"', 5,
        '$', 261,
        ',', 437,
        '/', 9,
        ';', 453,
        '[', 436,
        ']', 438,
        'a', 305,
        'd', 345,
        'i', 374,
        's', 293,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(264);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(267);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(371);
      if (lookahead == 'l') ADVANCE(390);
      if (lookahead == 'o') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(428);
      if (lookahead == 'e') ADVANCE(361);
      if (lookahead == 'h') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(434);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(535);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(426);
      if (lookahead == 'l') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(381);
      if (lookahead == 'e') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(296);
      if (lookahead == 'u') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(370);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(398);
      if (lookahead == 'e') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(501);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(489);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(452);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(523);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(498);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(496);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(531);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(518);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(525);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(533);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(529);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(337);
      if (lookahead == 'n') ADVANCE(268);
      if (lookahead == 'p') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(464);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(399);
      if (lookahead == 'r') ADVANCE(425);
      if (lookahead == 'w') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(353);
      if (lookahead == 'p') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(414);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(512);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(395);
      if (lookahead == 'y') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(481);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(421);
      if (lookahead == 'r') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(506);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(527);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(479);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(510);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(516);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(514);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(440);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(249);
      if (lookahead == 'c') ADVANCE(204);
      if (lookahead == 'e') ADVANCE(142);
      if (lookahead == 'h') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(188);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(446);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(447);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(448);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(450);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(260);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(484);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_player);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_player);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(anon_sym_pause);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(anon_sym_pause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(anon_sym_unpause);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(anon_sym_unpause);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(anon_sym_camera);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(anon_sym_camera);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(435);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(anon_sym_fade);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 'c') ADVANCE(145);
      if (lookahead == 'd') ADVANCE(86);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(anon_sym_out);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(anon_sym_shake);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(anon_sym_animation);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(anon_sym_position);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_geometry);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 264},
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
  [46] = {.lex_state = 8},
  [47] = {.lex_state = 264},
  [48] = {.lex_state = 264},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 264},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 264},
  [61] = {.lex_state = 264},
  [62] = {.lex_state = 4},
  [63] = {.lex_state = 264},
  [64] = {.lex_state = 264},
  [65] = {.lex_state = 264},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 264},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 264},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 264},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 264},
  [74] = {.lex_state = 264},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 264},
  [77] = {.lex_state = 264},
  [78] = {.lex_state = 264},
  [79] = {.lex_state = 264},
  [80] = {.lex_state = 264},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 6},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 4},
  [98] = {.lex_state = 4},
  [99] = {.lex_state = 4},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 4},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 264},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 1},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 4},
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 4},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 1},
  [122] = {.lex_state = 2},
  [123] = {.lex_state = 2},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 264},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 264},
  [130] = {.lex_state = 2},
  [131] = {.lex_state = 2},
  [132] = {.lex_state = 1},
  [133] = {.lex_state = 4},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 264},
  [136] = {.lex_state = 264},
  [137] = {.lex_state = 264},
  [138] = {.lex_state = 264},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 2},
  [141] = {.lex_state = 1},
  [142] = {.lex_state = 264},
  [143] = {.lex_state = 2},
  [144] = {.lex_state = 2},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 1},
  [147] = {.lex_state = 1},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 264},
  [151] = {.lex_state = 1},
  [152] = {.lex_state = 4},
  [153] = {.lex_state = 4},
  [154] = {.lex_state = 264},
  [155] = {.lex_state = 264},
  [156] = {.lex_state = 2},
  [157] = {.lex_state = 2},
  [158] = {.lex_state = 264},
  [159] = {.lex_state = 2},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 2},
  [162] = {.lex_state = 264},
  [163] = {.lex_state = 264},
  [164] = {.lex_state = 2},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 1},
  [167] = {.lex_state = 1},
  [168] = {.lex_state = 264},
  [169] = {.lex_state = 4},
  [170] = {.lex_state = 4},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 2},
  [175] = {.lex_state = 264},
  [176] = {.lex_state = 264},
  [177] = {.lex_state = 2},
  [178] = {.lex_state = 264},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 4},
  [182] = {.lex_state = 6},
  [183] = {.lex_state = 264},
  [184] = {.lex_state = 2},
  [185] = {.lex_state = 4},
  [186] = {.lex_state = 4},
  [187] = {.lex_state = 264},
  [188] = {.lex_state = 4},
  [189] = {.lex_state = 2},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 2},
  [192] = {.lex_state = 264},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 264},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 2},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 2},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 2},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 2},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 4},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 264},
  [225] = {.lex_state = 4},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 2},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 2},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 2},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 2},
  [237] = {.lex_state = 1},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 2},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 2},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 2},
  [248] = {.lex_state = 264},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 2},
  [251] = {.lex_state = 2},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 264},
  [255] = {.lex_state = 2},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 2},
  [266] = {.lex_state = 2},
  [267] = {.lex_state = 1},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 264},
  [271] = {.lex_state = 0},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 1},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 2},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 4},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 0},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 4},
  [286] = {.lex_state = 0},
  [287] = {.lex_state = 0},
  [288] = {.lex_state = 4},
  [289] = {.lex_state = 0},
  [290] = {.lex_state = 0},
  [291] = {.lex_state = 0},
  [292] = {.lex_state = 0},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 0},
  [295] = {.lex_state = 0},
  [296] = {.lex_state = 4},
  [297] = {.lex_state = 0},
  [298] = {.lex_state = 0},
  [299] = {.lex_state = 2},
  [300] = {.lex_state = 0},
  [301] = {.lex_state = 4},
  [302] = {.lex_state = 0},
  [303] = {.lex_state = 2},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 0},
  [306] = {.lex_state = 0},
  [307] = {.lex_state = 4},
  [308] = {.lex_state = 2},
  [309] = {.lex_state = 264},
  [310] = {.lex_state = 2},
  [311] = {.lex_state = 0},
  [312] = {.lex_state = 0},
  [313] = {.lex_state = 0},
  [314] = {.lex_state = 0},
  [315] = {.lex_state = 0},
  [316] = {.lex_state = 0},
  [317] = {.lex_state = 0},
  [318] = {.lex_state = 2},
  [319] = {.lex_state = 4},
  [320] = {.lex_state = 0},
  [321] = {.lex_state = 264},
  [322] = {.lex_state = 264},
  [323] = {.lex_state = 0},
  [324] = {.lex_state = 264},
  [325] = {.lex_state = 0},
  [326] = {.lex_state = 0},
  [327] = {.lex_state = 2},
  [328] = {.lex_state = 0},
  [329] = {.lex_state = 1},
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
  [344] = {.lex_state = 4},
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
  [375] = {.lex_state = 4},
  [376] = {.lex_state = 0},
  [377] = {.lex_state = 0},
  [378] = {.lex_state = 4},
  [379] = {.lex_state = 0},
  [380] = {.lex_state = 0},
  [381] = {.lex_state = 0},
  [382] = {.lex_state = 0},
  [383] = {.lex_state = 0},
  [384] = {.lex_state = 0},
  [385] = {.lex_state = 4},
  [386] = {.lex_state = 0},
  [387] = {.lex_state = 0},
  [388] = {.lex_state = 0},
  [389] = {.lex_state = 0},
  [390] = {.lex_state = 0},
  [391] = {.lex_state = 0},
  [392] = {.lex_state = 0},
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
  [415] = {.lex_state = 4},
  [416] = {.lex_state = 0},
  [417] = {.lex_state = 0},
  [418] = {.lex_state = 0},
  [419] = {.lex_state = 0},
  [420] = {.lex_state = 0},
  [421] = {.lex_state = 0},
  [422] = {.lex_state = 0},
  [423] = {.lex_state = 0},
  [424] = {.lex_state = 0},
  [425] = {.lex_state = 0},
  [426] = {.lex_state = 0},
  [427] = {.lex_state = 0},
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
    [anon_sym_position] = ACTIONS(1),
    [sym_geometry] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(387),
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
  [2] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_label_definition] = STATE(2),
    [sym__action_item] = STATE(2),
    [sym_action_return_statement] = STATE(2),
    [sym_action_close_dialog] = STATE(2),
    [sym_action_close_serial_dialog] = STATE(2),
    [sym_action_save_slot] = STATE(2),
    [sym_action_load_slot] = STATE(2),
    [sym_action_erase_slot] = STATE(2),
    [sym_action_load_map] = STATE(2),
    [sym_action_run_script] = STATE(2),
    [sym_action_goto_label] = STATE(2),
    [sym_action_goto_index] = STATE(2),
    [sym_action_non_blocking_delay] = STATE(2),
    [sym_action_blocking_delay] = STATE(2),
    [sym_action_show_dialog] = STATE(2),
    [sym_action_show_serial_dialog] = STATE(2),
    [sym_action_concat_serial_dialog] = STATE(2),
    [sym_action_delete_command] = STATE(2),
    [sym_action_delete_command_arg] = STATE(2),
    [sym_action_delete_alias] = STATE(2),
    [sym_action_hide_command] = STATE(2),
    [sym_action_unhide_command] = STATE(2),
    [sym_entity] = STATE(234),
    [sym_entity_identifier] = STATE(407),
    [sym_entity_identifier_expansion] = STATE(407),
    [sym_action_pause_script] = STATE(2),
    [sym_action_unpause_script] = STATE(2),
    [sym_action_camera_fade_in] = STATE(2),
    [sym_action_camera_fade_out] = STATE(2),
    [sym_action_camera_shake] = STATE(2),
    [sym_action_play_entity_animation] = STATE(2),
    [sym_camera] = STATE(235),
    [sym_movable_identifier] = STATE(337),
    [sym_movable_identifier_expansion] = STATE(337),
    [sym_action_set_position] = STATE(2),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(23),
    [anon_sym_LBRACK] = ACTIONS(26),
    [anon_sym_RBRACE] = ACTIONS(29),
    [anon_sym_entity] = ACTIONS(31),
    [anon_sym_json] = ACTIONS(34),
    [anon_sym_rand] = ACTIONS(37),
    [anon_sym_RPAREN] = ACTIONS(29),
    [anon_sym_return] = ACTIONS(40),
    [anon_sym_close] = ACTIONS(43),
    [anon_sym_save] = ACTIONS(46),
    [anon_sym_load] = ACTIONS(49),
    [anon_sym_erase] = ACTIONS(52),
    [anon_sym_goto] = ACTIONS(55),
    [anon_sym_wait] = ACTIONS(58),
    [anon_sym_block] = ACTIONS(61),
    [anon_sym_show] = ACTIONS(64),
    [anon_sym_concat] = ACTIONS(67),
    [anon_sym_delete] = ACTIONS(70),
    [anon_sym_hide] = ACTIONS(73),
    [anon_sym_unhide] = ACTIONS(76),
    [sym_player] = ACTIONS(79),
    [sym_self] = ACTIONS(79),
    [anon_sym_pause] = ACTIONS(82),
    [anon_sym_unpause] = ACTIONS(85),
    [anon_sym_camera] = ACTIONS(88),
  },
  [3] = {
    [sym__script_item] = STATE(6),
    [sym_json_literal] = STATE(6),
    [sym_rand_macro] = STATE(6),
    [sym_label_definition] = STATE(6),
    [sym__action_item] = STATE(6),
    [sym_action_return_statement] = STATE(6),
    [sym_action_close_dialog] = STATE(6),
    [sym_action_close_serial_dialog] = STATE(6),
    [sym_action_save_slot] = STATE(6),
    [sym_action_load_slot] = STATE(6),
    [sym_action_erase_slot] = STATE(6),
    [sym_action_load_map] = STATE(6),
    [sym_action_run_script] = STATE(6),
    [sym_action_goto_label] = STATE(6),
    [sym_action_goto_index] = STATE(6),
    [sym_action_non_blocking_delay] = STATE(6),
    [sym_action_blocking_delay] = STATE(6),
    [sym_action_show_dialog] = STATE(6),
    [sym_action_show_serial_dialog] = STATE(6),
    [sym_action_concat_serial_dialog] = STATE(6),
    [sym_action_delete_command] = STATE(6),
    [sym_action_delete_command_arg] = STATE(6),
    [sym_action_delete_alias] = STATE(6),
    [sym_action_hide_command] = STATE(6),
    [sym_action_unhide_command] = STATE(6),
    [sym_entity] = STATE(234),
    [sym_entity_identifier] = STATE(407),
    [sym_entity_identifier_expansion] = STATE(407),
    [sym_action_pause_script] = STATE(6),
    [sym_action_unpause_script] = STATE(6),
    [sym_action_camera_fade_in] = STATE(6),
    [sym_action_camera_fade_out] = STATE(6),
    [sym_action_camera_shake] = STATE(6),
    [sym_action_play_entity_animation] = STATE(6),
    [sym_camera] = STATE(235),
    [sym_movable_identifier] = STATE(337),
    [sym_movable_identifier_expansion] = STATE(337),
    [sym_action_set_position] = STATE(6),
    [aux_sym_script_block_repeat1] = STATE(6),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(91),
    [anon_sym_LBRACK] = ACTIONS(93),
    [anon_sym_RBRACE] = ACTIONS(95),
    [anon_sym_entity] = ACTIONS(97),
    [anon_sym_json] = ACTIONS(99),
    [anon_sym_rand] = ACTIONS(101),
    [anon_sym_return] = ACTIONS(103),
    [anon_sym_close] = ACTIONS(105),
    [anon_sym_save] = ACTIONS(107),
    [anon_sym_load] = ACTIONS(109),
    [anon_sym_erase] = ACTIONS(111),
    [anon_sym_goto] = ACTIONS(113),
    [anon_sym_wait] = ACTIONS(115),
    [anon_sym_block] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [sym_player] = ACTIONS(129),
    [sym_self] = ACTIONS(129),
    [anon_sym_pause] = ACTIONS(131),
    [anon_sym_unpause] = ACTIONS(133),
    [anon_sym_camera] = ACTIONS(135),
  },
  [4] = {
    [sym__script_item] = STATE(5),
    [sym_json_literal] = STATE(5),
    [sym_rand_macro] = STATE(5),
    [sym_label_definition] = STATE(5),
    [sym__action_item] = STATE(5),
    [sym_action_return_statement] = STATE(5),
    [sym_action_close_dialog] = STATE(5),
    [sym_action_close_serial_dialog] = STATE(5),
    [sym_action_save_slot] = STATE(5),
    [sym_action_load_slot] = STATE(5),
    [sym_action_erase_slot] = STATE(5),
    [sym_action_load_map] = STATE(5),
    [sym_action_run_script] = STATE(5),
    [sym_action_goto_label] = STATE(5),
    [sym_action_goto_index] = STATE(5),
    [sym_action_non_blocking_delay] = STATE(5),
    [sym_action_blocking_delay] = STATE(5),
    [sym_action_show_dialog] = STATE(5),
    [sym_action_show_serial_dialog] = STATE(5),
    [sym_action_concat_serial_dialog] = STATE(5),
    [sym_action_delete_command] = STATE(5),
    [sym_action_delete_command_arg] = STATE(5),
    [sym_action_delete_alias] = STATE(5),
    [sym_action_hide_command] = STATE(5),
    [sym_action_unhide_command] = STATE(5),
    [sym_entity] = STATE(234),
    [sym_entity_identifier] = STATE(407),
    [sym_entity_identifier_expansion] = STATE(407),
    [sym_action_pause_script] = STATE(5),
    [sym_action_unpause_script] = STATE(5),
    [sym_action_camera_fade_in] = STATE(5),
    [sym_action_camera_fade_out] = STATE(5),
    [sym_action_camera_shake] = STATE(5),
    [sym_action_play_entity_animation] = STATE(5),
    [sym_camera] = STATE(235),
    [sym_movable_identifier] = STATE(337),
    [sym_movable_identifier_expansion] = STATE(337),
    [sym_action_set_position] = STATE(5),
    [aux_sym_script_block_repeat1] = STATE(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(91),
    [anon_sym_LBRACK] = ACTIONS(93),
    [anon_sym_entity] = ACTIONS(97),
    [anon_sym_json] = ACTIONS(99),
    [anon_sym_rand] = ACTIONS(101),
    [anon_sym_RPAREN] = ACTIONS(137),
    [anon_sym_return] = ACTIONS(103),
    [anon_sym_close] = ACTIONS(105),
    [anon_sym_save] = ACTIONS(107),
    [anon_sym_load] = ACTIONS(109),
    [anon_sym_erase] = ACTIONS(111),
    [anon_sym_goto] = ACTIONS(113),
    [anon_sym_wait] = ACTIONS(115),
    [anon_sym_block] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [sym_player] = ACTIONS(129),
    [sym_self] = ACTIONS(129),
    [anon_sym_pause] = ACTIONS(131),
    [anon_sym_unpause] = ACTIONS(133),
    [anon_sym_camera] = ACTIONS(135),
  },
  [5] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_label_definition] = STATE(2),
    [sym__action_item] = STATE(2),
    [sym_action_return_statement] = STATE(2),
    [sym_action_close_dialog] = STATE(2),
    [sym_action_close_serial_dialog] = STATE(2),
    [sym_action_save_slot] = STATE(2),
    [sym_action_load_slot] = STATE(2),
    [sym_action_erase_slot] = STATE(2),
    [sym_action_load_map] = STATE(2),
    [sym_action_run_script] = STATE(2),
    [sym_action_goto_label] = STATE(2),
    [sym_action_goto_index] = STATE(2),
    [sym_action_non_blocking_delay] = STATE(2),
    [sym_action_blocking_delay] = STATE(2),
    [sym_action_show_dialog] = STATE(2),
    [sym_action_show_serial_dialog] = STATE(2),
    [sym_action_concat_serial_dialog] = STATE(2),
    [sym_action_delete_command] = STATE(2),
    [sym_action_delete_command_arg] = STATE(2),
    [sym_action_delete_alias] = STATE(2),
    [sym_action_hide_command] = STATE(2),
    [sym_action_unhide_command] = STATE(2),
    [sym_entity] = STATE(234),
    [sym_entity_identifier] = STATE(407),
    [sym_entity_identifier_expansion] = STATE(407),
    [sym_action_pause_script] = STATE(2),
    [sym_action_unpause_script] = STATE(2),
    [sym_action_camera_fade_in] = STATE(2),
    [sym_action_camera_fade_out] = STATE(2),
    [sym_action_camera_shake] = STATE(2),
    [sym_action_play_entity_animation] = STATE(2),
    [sym_camera] = STATE(235),
    [sym_movable_identifier] = STATE(337),
    [sym_movable_identifier_expansion] = STATE(337),
    [sym_action_set_position] = STATE(2),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(91),
    [anon_sym_LBRACK] = ACTIONS(93),
    [anon_sym_entity] = ACTIONS(97),
    [anon_sym_json] = ACTIONS(99),
    [anon_sym_rand] = ACTIONS(101),
    [anon_sym_RPAREN] = ACTIONS(139),
    [anon_sym_return] = ACTIONS(103),
    [anon_sym_close] = ACTIONS(105),
    [anon_sym_save] = ACTIONS(107),
    [anon_sym_load] = ACTIONS(109),
    [anon_sym_erase] = ACTIONS(111),
    [anon_sym_goto] = ACTIONS(113),
    [anon_sym_wait] = ACTIONS(115),
    [anon_sym_block] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [sym_player] = ACTIONS(129),
    [sym_self] = ACTIONS(129),
    [anon_sym_pause] = ACTIONS(131),
    [anon_sym_unpause] = ACTIONS(133),
    [anon_sym_camera] = ACTIONS(135),
  },
  [6] = {
    [sym__script_item] = STATE(2),
    [sym_json_literal] = STATE(2),
    [sym_rand_macro] = STATE(2),
    [sym_label_definition] = STATE(2),
    [sym__action_item] = STATE(2),
    [sym_action_return_statement] = STATE(2),
    [sym_action_close_dialog] = STATE(2),
    [sym_action_close_serial_dialog] = STATE(2),
    [sym_action_save_slot] = STATE(2),
    [sym_action_load_slot] = STATE(2),
    [sym_action_erase_slot] = STATE(2),
    [sym_action_load_map] = STATE(2),
    [sym_action_run_script] = STATE(2),
    [sym_action_goto_label] = STATE(2),
    [sym_action_goto_index] = STATE(2),
    [sym_action_non_blocking_delay] = STATE(2),
    [sym_action_blocking_delay] = STATE(2),
    [sym_action_show_dialog] = STATE(2),
    [sym_action_show_serial_dialog] = STATE(2),
    [sym_action_concat_serial_dialog] = STATE(2),
    [sym_action_delete_command] = STATE(2),
    [sym_action_delete_command_arg] = STATE(2),
    [sym_action_delete_alias] = STATE(2),
    [sym_action_hide_command] = STATE(2),
    [sym_action_unhide_command] = STATE(2),
    [sym_entity] = STATE(234),
    [sym_entity_identifier] = STATE(407),
    [sym_entity_identifier_expansion] = STATE(407),
    [sym_action_pause_script] = STATE(2),
    [sym_action_unpause_script] = STATE(2),
    [sym_action_camera_fade_in] = STATE(2),
    [sym_action_camera_fade_out] = STATE(2),
    [sym_action_camera_shake] = STATE(2),
    [sym_action_play_entity_animation] = STATE(2),
    [sym_camera] = STATE(235),
    [sym_movable_identifier] = STATE(337),
    [sym_movable_identifier_expansion] = STATE(337),
    [sym_action_set_position] = STATE(2),
    [aux_sym_script_block_repeat1] = STATE(2),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(91),
    [anon_sym_LBRACK] = ACTIONS(93),
    [anon_sym_RBRACE] = ACTIONS(141),
    [anon_sym_entity] = ACTIONS(97),
    [anon_sym_json] = ACTIONS(99),
    [anon_sym_rand] = ACTIONS(101),
    [anon_sym_return] = ACTIONS(103),
    [anon_sym_close] = ACTIONS(105),
    [anon_sym_save] = ACTIONS(107),
    [anon_sym_load] = ACTIONS(109),
    [anon_sym_erase] = ACTIONS(111),
    [anon_sym_goto] = ACTIONS(113),
    [anon_sym_wait] = ACTIONS(115),
    [anon_sym_block] = ACTIONS(117),
    [anon_sym_show] = ACTIONS(119),
    [anon_sym_concat] = ACTIONS(121),
    [anon_sym_delete] = ACTIONS(123),
    [anon_sym_hide] = ACTIONS(125),
    [anon_sym_unhide] = ACTIONS(127),
    [sym_player] = ACTIONS(129),
    [sym_self] = ACTIONS(129),
    [anon_sym_pause] = ACTIONS(131),
    [anon_sym_unpause] = ACTIONS(133),
    [anon_sym_camera] = ACTIONS(135),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
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
  [36] = 3,
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
  [72] = 3,
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
  [108] = 3,
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
  [142] = 3,
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
  [176] = 3,
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
  [210] = 3,
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
  [244] = 3,
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
  [278] = 3,
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
  [312] = 3,
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
  [346] = 3,
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
  [380] = 3,
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
  [414] = 3,
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
  [448] = 3,
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
  [482] = 3,
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
  [516] = 3,
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
  [550] = 3,
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
  [584] = 3,
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
  [618] = 3,
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
  [652] = 3,
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
  [686] = 3,
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
  [720] = 3,
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
  [754] = 3,
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
  [788] = 3,
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
  [822] = 3,
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
  [856] = 3,
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
  [890] = 3,
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
  [924] = 3,
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
  [958] = 3,
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
  [992] = 3,
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
  [1026] = 3,
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
  [1060] = 3,
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
  [1094] = 3,
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
  [1128] = 3,
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
  [1162] = 3,
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
  [1196] = 3,
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
  [1230] = 3,
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
  [1264] = 3,
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
  [1298] = 3,
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
  [1332] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(301), 3,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(299), 22,
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
  [1366] = 11,
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
    ACTIONS(303), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(48), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [1409] = 11,
    ACTIONS(305), 1,
      ts_builtin_sym_end,
    ACTIONS(307), 1,
      sym_BAREWORD,
    ACTIONS(310), 1,
      sym_QUOTED_STRING,
    ACTIONS(313), 1,
      sym_CONSTANT,
    ACTIONS(316), 1,
      anon_sym_include,
    ACTIONS(319), 1,
      anon_sym_add,
    ACTIONS(322), 1,
      anon_sym_serial_dialog,
    ACTIONS(325), 1,
      anon_sym_dialog,
    ACTIONS(328), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(48), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [1452] = 8,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(331), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(333), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(336), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1484] = 9,
    ACTIONS(339), 1,
      sym_QUOTED_STRING,
    STATE(51), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(88), 1,
      aux_sym_dialog_repeat1,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1518] = 9,
    ACTIONS(339), 1,
      sym_QUOTED_STRING,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(91), 1,
      aux_sym_dialog_repeat1,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1552] = 8,
    ACTIONS(345), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1583] = 8,
    ACTIONS(347), 1,
      anon_sym_RBRACE,
    STATE(54), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1614] = 8,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1645] = 8,
    ACTIONS(351), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(66), 1,
      sym_dialog_parameter,
    STATE(247), 1,
      sym__dialog_parameter_string,
    STATE(322), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(341), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(343), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1676] = 6,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    ACTIONS(355), 1,
      anon_sym_RBRACK,
    ACTIONS(359), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(261), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(357), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1702] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(361), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(363), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1721] = 5,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    ACTIONS(359), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(328), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(365), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1744] = 6,
    ACTIONS(371), 1,
      sym_NUMBER,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(367), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(369), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(343), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [1769] = 3,
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
  [1788] = 3,
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
  [1807] = 5,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    ACTIONS(359), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(282), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(383), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1830] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(385), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(387), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1849] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(389), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(391), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1867] = 3,
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
  [1885] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1901] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(399), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(401), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1919] = 8,
    ACTIONS(403), 1,
      anon_sym_LBRACK,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
    STATE(140), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [1947] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(411), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(413), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1965] = 8,
    ACTIONS(403), 1,
      anon_sym_LBRACK,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
    STATE(131), 2,
      sym_entity_or_map_identifier,
      sym_entity_or_map_identifier_expansion,
  [1993] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(415), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(417), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2011] = 9,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(419), 1,
      anon_sym_RBRACK,
    ACTIONS(423), 1,
      anon_sym_camera,
    STATE(219), 1,
      sym_entity_identifier,
    STATE(231), 1,
      sym_movable_identifier,
    STATE(234), 1,
      sym_entity,
    STATE(235), 1,
      sym_camera,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(421), 2,
      sym_player,
      sym_self,
  [2041] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(425), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(427), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2059] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(429), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(431), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2077] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2093] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(435), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(437), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2111] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(439), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(441), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2129] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(443), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(445), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2147] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(447), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(449), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2165] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(451), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(453), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2183] = 8,
    ACTIONS(455), 1,
      anon_sym_RBRACE,
    ACTIONS(457), 1,
      sym_target_default,
    ACTIONS(459), 1,
      anon_sym_label,
    ACTIONS(461), 1,
      anon_sym_entity,
    STATE(218), 1,
      sym_target_entity,
    STATE(303), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(89), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2210] = 8,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    ACTIONS(463), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    STATE(306), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
  [2237] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(465), 1,
      anon_sym_LBRACK,
    ACTIONS(469), 1,
      sym_geometry,
    STATE(204), 1,
      sym_entity,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      sym_player,
      sym_self,
    STATE(424), 2,
      sym_coordinate_identifier,
      sym_coordinate_identifier_expansion,
  [2262] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(471), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2277] = 8,
    ACTIONS(457), 1,
      sym_target_default,
    ACTIONS(459), 1,
      anon_sym_label,
    ACTIONS(461), 1,
      anon_sym_entity,
    ACTIONS(473), 1,
      anon_sym_RBRACE,
    STATE(218), 1,
      sym_target_entity,
    STATE(303), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(81), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2304] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(475), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2319] = 8,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    ACTIONS(477), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    STATE(306), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
  [2346] = 8,
    ACTIONS(339), 1,
      sym_QUOTED_STRING,
    ACTIONS(481), 1,
      sym_identifier_type,
    ACTIONS(483), 1,
      anon_sym_GT,
    STATE(110), 1,
      aux_sym_dialog_repeat1,
    STATE(111), 1,
      aux_sym_dialog_repeat2,
    STATE(172), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(479), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2373] = 8,
    ACTIONS(485), 1,
      anon_sym_RBRACE,
    ACTIONS(487), 1,
      sym_target_default,
    ACTIONS(490), 1,
      anon_sym_label,
    ACTIONS(493), 1,
      anon_sym_entity,
    STATE(218), 1,
      sym_target_entity,
    STATE(303), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(89), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2400] = 8,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(423), 1,
      anon_sym_camera,
    ACTIONS(496), 1,
      anon_sym_RBRACK,
    STATE(235), 1,
      sym_camera,
    STATE(276), 1,
      sym_entity,
    STATE(304), 1,
      sym_movable_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(498), 2,
      sym_player,
      sym_self,
  [2427] = 8,
    ACTIONS(339), 1,
      sym_QUOTED_STRING,
    ACTIONS(483), 1,
      anon_sym_GT,
    ACTIONS(502), 1,
      sym_identifier_type,
    STATE(110), 1,
      aux_sym_dialog_repeat1,
    STATE(113), 1,
      aux_sym_dialog_repeat2,
    STATE(172), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(500), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2454] = 9,
    ACTIONS(504), 1,
      sym_QUOTED_STRING,
    ACTIONS(506), 1,
      anon_sym_RBRACE,
    ACTIONS(508), 1,
      anon_sym_wrap,
    STATE(106), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(108), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(283), 1,
      sym_serial_dialog_parameter,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    STATE(427), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2483] = 8,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(423), 1,
      anon_sym_camera,
    ACTIONS(510), 1,
      anon_sym_RBRACK,
    STATE(235), 1,
      sym_camera,
    STATE(276), 1,
      sym_entity,
    STATE(304), 1,
      sym_movable_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(498), 2,
      sym_player,
      sym_self,
  [2510] = 8,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    ACTIONS(512), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    STATE(272), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
  [2537] = 3,
    ACTIONS(516), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2553] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(423), 1,
      anon_sym_camera,
    STATE(235), 1,
      sym_camera,
    STATE(276), 1,
      sym_entity,
    STATE(304), 1,
      sym_movable_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(498), 2,
      sym_player,
      sym_self,
  [2577] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(469), 1,
      sym_geometry,
    ACTIONS(518), 1,
      anon_sym_RBRACK,
    STATE(204), 1,
      sym_entity,
    STATE(302), 1,
      sym_coordinate_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      sym_player,
      sym_self,
  [2601] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(469), 1,
      sym_geometry,
    ACTIONS(520), 1,
      anon_sym_RBRACK,
    STATE(204), 1,
      sym_entity,
    STATE(302), 1,
      sym_coordinate_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      sym_player,
      sym_self,
  [2625] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(407), 1,
      anon_sym_map,
    STATE(109), 1,
      sym_map,
    STATE(207), 1,
      sym_entity,
    STATE(306), 1,
      sym_entity_or_map_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 2,
      sym_player,
      sym_self,
  [2649] = 7,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(469), 1,
      sym_geometry,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    STATE(204), 1,
      sym_entity,
    STATE(211), 1,
      sym_coordinate_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      sym_player,
      sym_self,
  [2673] = 7,
    ACTIONS(524), 1,
      sym_BAREWORD,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    ACTIONS(530), 1,
      anon_sym_label,
    ACTIONS(532), 1,
      anon_sym_index,
    STATE(402), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(528), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2697] = 7,
    ACTIONS(534), 1,
      sym_BAREWORD,
    ACTIONS(536), 1,
      anon_sym_RBRACE,
    ACTIONS(538), 1,
      sym_identifier_type,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(105), 1,
      aux_sym__dialog_block_repeat1,
    STATE(239), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2720] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(540), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2733] = 6,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(542), 1,
      anon_sym_RBRACK,
    STATE(265), 1,
      sym_entity,
    STATE(313), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_player,
      sym_self,
  [2754] = 7,
    ACTIONS(546), 1,
      sym_BAREWORD,
    ACTIONS(549), 1,
      anon_sym_RBRACE,
    ACTIONS(551), 1,
      sym_identifier_type,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(105), 1,
      aux_sym__dialog_block_repeat1,
    STATE(239), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2777] = 7,
    ACTIONS(504), 1,
      sym_QUOTED_STRING,
    ACTIONS(508), 1,
      anon_sym_wrap,
    STATE(117), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(125), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(283), 1,
      sym_serial_dialog_parameter,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2800] = 6,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(554), 1,
      anon_sym_RBRACK,
    STATE(265), 1,
      sym_entity,
    STATE(313), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_player,
      sym_self,
  [2821] = 7,
    ACTIONS(504), 1,
      sym_QUOTED_STRING,
    ACTIONS(556), 1,
      anon_sym_RBRACE,
    ACTIONS(558), 1,
      sym_serial_dialog_option_type,
    STATE(152), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(153), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(281), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2844] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(560), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2857] = 5,
    ACTIONS(564), 1,
      sym_QUOTED_STRING,
    ACTIONS(567), 1,
      sym_identifier_type,
    STATE(110), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(562), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2876] = 6,
    ACTIONS(483), 1,
      anon_sym_GT,
    ACTIONS(571), 1,
      sym_identifier_type,
    STATE(114), 1,
      aux_sym_dialog_repeat2,
    STATE(172), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(569), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2897] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(573), 6,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [2910] = 6,
    ACTIONS(483), 1,
      anon_sym_GT,
    ACTIONS(577), 1,
      sym_identifier_type,
    STATE(114), 1,
      aux_sym_dialog_repeat2,
    STATE(172), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(575), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2931] = 6,
    ACTIONS(581), 1,
      sym_identifier_type,
    ACTIONS(583), 1,
      anon_sym_GT,
    STATE(114), 1,
      aux_sym_dialog_repeat2,
    STATE(172), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(579), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2952] = 6,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(586), 1,
      anon_sym_LBRACK,
    ACTIONS(588), 1,
      sym_NUMBER,
    ACTIONS(590), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(336), 2,
      sym_QUANTITY,
      sym_quantity_expansion,
  [2973] = 7,
    ACTIONS(534), 1,
      sym_BAREWORD,
    ACTIONS(538), 1,
      sym_identifier_type,
    ACTIONS(592), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym_dialog_identifier,
    STATE(102), 1,
      aux_sym__dialog_block_repeat1,
    STATE(239), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2996] = 7,
    ACTIONS(504), 1,
      sym_QUOTED_STRING,
    ACTIONS(558), 1,
      sym_serial_dialog_option_type,
    ACTIONS(594), 1,
      anon_sym_RBRACE,
    STATE(152), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(169), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(281), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3019] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(596), 6,
      sym_BAREWORD,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3032] = 6,
    ACTIONS(405), 1,
      anon_sym_entity,
    ACTIONS(469), 1,
      sym_geometry,
    STATE(204), 1,
      sym_entity,
    STATE(302), 1,
      sym_coordinate_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      sym_player,
      sym_self,
  [3053] = 6,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(588), 1,
      sym_NUMBER,
    ACTIONS(598), 1,
      anon_sym_RBRACK,
    ACTIONS(600), 1,
      sym_CONSTANT,
    STATE(326), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3073] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3085] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(315), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(604), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3101] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(397), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(606), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3117] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(404), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(608), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3133] = 6,
    ACTIONS(610), 1,
      sym_QUOTED_STRING,
    ACTIONS(612), 1,
      anon_sym_wrap,
    STATE(125), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(283), 1,
      sym_serial_dialog_parameter,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3153] = 6,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(588), 1,
      sym_NUMBER,
    ACTIONS(615), 1,
      anon_sym_RBRACK,
    ACTIONS(617), 1,
      sym_CONSTANT,
    STATE(262), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3173] = 5,
    ACTIONS(619), 1,
      anon_sym_LBRACK,
    ACTIONS(621), 1,
      sym_NUMBER,
    ACTIONS(623), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(333), 2,
      sym_DISTANCE,
      sym_distance_expansion,
  [3191] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(409), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(625), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3207] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(631), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(349), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3225] = 3,
    ACTIONS(635), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(633), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3239] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(358), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(637), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3255] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(639), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3267] = 5,
    ACTIONS(405), 1,
      anon_sym_entity,
    STATE(265), 1,
      sym_entity,
    STATE(313), 1,
      sym_entity_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_player,
      sym_self,
  [3285] = 5,
    ACTIONS(641), 1,
      anon_sym_RBRACE,
    ACTIONS(643), 1,
      anon_sym_wrap,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(134), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3303] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(646), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(393), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3321] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(648), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(394), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3339] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(650), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(398), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3357] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(652), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(127), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3375] = 5,
    ACTIONS(508), 1,
      anon_sym_wrap,
    ACTIONS(654), 1,
      anon_sym_RBRACE,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(145), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3393] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(352), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(656), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3409] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(658), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3421] = 5,
    ACTIONS(627), 1,
      anon_sym_LBRACK,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(660), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(350), 2,
      sym_DURATION,
      sym_duration_expansion,
  [3439] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(410), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(662), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3455] = 4,
    ACTIONS(526), 1,
      anon_sym_LBRACK,
    STATE(414), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3471] = 5,
    ACTIONS(508), 1,
      anon_sym_wrap,
    ACTIONS(666), 1,
      anon_sym_RBRACE,
    STATE(324), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(134), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [3489] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(668), 5,
      anon_sym_LBRACK,
      sym_NUMBER,
      aux_sym_QUANTITY_token1,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3501] = 6,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(588), 1,
      sym_NUMBER,
    ACTIONS(600), 1,
      sym_CONSTANT,
    ACTIONS(670), 1,
      anon_sym_RBRACK,
    STATE(326), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3521] = 3,
    ACTIONS(674), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(672), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3534] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(676), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3545] = 4,
    ACTIONS(678), 1,
      anon_sym_LBRACK,
    STATE(115), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(680), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3560] = 5,
    ACTIONS(373), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(588), 1,
      sym_NUMBER,
    ACTIONS(600), 1,
      sym_CONSTANT,
    STATE(326), 1,
      sym_QUANTITY,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3577] = 4,
    ACTIONS(682), 1,
      sym_QUOTED_STRING,
    STATE(152), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(685), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3592] = 5,
    ACTIONS(558), 1,
      sym_serial_dialog_option_type,
    ACTIONS(687), 1,
      anon_sym_RBRACE,
    STATE(170), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(281), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3609] = 4,
    ACTIONS(678), 1,
      anon_sym_LBRACK,
    STATE(403), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(689), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3624] = 4,
    ACTIONS(678), 1,
      anon_sym_LBRACK,
    STATE(411), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(691), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3639] = 3,
    ACTIONS(695), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3652] = 4,
    ACTIONS(699), 1,
      anon_sym_LBRACK,
    STATE(380), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(697), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3667] = 4,
    ACTIONS(678), 1,
      anon_sym_LBRACK,
    STATE(382), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(701), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3682] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    STATE(335), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(703), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3697] = 4,
    ACTIONS(709), 1,
      anon_sym_LBRACE,
    STATE(348), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(707), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3712] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    STATE(381), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(711), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3727] = 5,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(713), 1,
      anon_sym_RBRACK,
    ACTIONS(715), 1,
      sym_CONSTANT,
    STATE(298), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3744] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(717), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3755] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(719), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3766] = 3,
    ACTIONS(723), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(721), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_animation,
  [3779] = 4,
    ACTIONS(725), 1,
      anon_sym_LBRACK,
    STATE(420), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(727), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3794] = 4,
    ACTIONS(725), 1,
      anon_sym_LBRACK,
    STATE(422), 1,
      sym_color_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(729), 2,
      sym_COLOR,
      sym_CONSTANT,
  [3809] = 5,
    ACTIONS(621), 1,
      sym_NUMBER,
    ACTIONS(731), 1,
      anon_sym_RBRACK,
    ACTIONS(733), 1,
      sym_CONSTANT,
    STATE(323), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3826] = 5,
    ACTIONS(558), 1,
      sym_serial_dialog_option_type,
    ACTIONS(735), 1,
      anon_sym_RBRACE,
    STATE(170), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(281), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3843] = 5,
    ACTIONS(737), 1,
      anon_sym_RBRACE,
    ACTIONS(739), 1,
      sym_serial_dialog_option_type,
    STATE(170), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(281), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3860] = 3,
    ACTIONS(744), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(742), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_animation,
  [3873] = 3,
    ACTIONS(748), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(746), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3886] = 4,
    ACTIONS(750), 1,
      anon_sym_LBRACK,
    STATE(383), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(752), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3901] = 3,
    ACTIONS(754), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(672), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3914] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(756), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [3925] = 5,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(715), 1,
      sym_CONSTANT,
    ACTIONS(758), 1,
      anon_sym_RBRACK,
    STATE(298), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3942] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(760), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3953] = 5,
    ACTIONS(621), 1,
      sym_NUMBER,
    ACTIONS(762), 1,
      anon_sym_RBRACK,
    ACTIONS(764), 1,
      sym_CONSTANT,
    STATE(260), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3970] = 3,
    ACTIONS(768), 1,
      sym_distance_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(766), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_over,
  [3983] = 3,
    ACTIONS(772), 1,
      sym_quantity_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(770), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [3996] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(774), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4007] = 5,
    ACTIONS(516), 1,
      sym_duration_suffix,
    ACTIONS(768), 1,
      sym_distance_suffix,
    ACTIONS(772), 1,
      sym_quantity_suffix,
    ACTIONS(776), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4024] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(778), 4,
      anon_sym_LBRACK,
      sym_NUMBER,
      sym_CONSTANT,
      anon_sym_SEMI,
  [4035] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(780), 4,
      sym_BAREWORD,
      anon_sym_LBRACK,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4046] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(782), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4057] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(784), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4068] = 5,
    ACTIONS(621), 1,
      sym_NUMBER,
    ACTIONS(733), 1,
      sym_CONSTANT,
    ACTIONS(786), 1,
      anon_sym_RBRACK,
    STATE(323), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4085] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(788), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [4096] = 3,
    ACTIONS(792), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(790), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [4109] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(794), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
      anon_sym_over,
  [4120] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(796), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4130] = 4,
    ACTIONS(621), 1,
      sym_NUMBER,
    ACTIONS(733), 1,
      sym_CONSTANT,
    STATE(323), 1,
      sym_DISTANCE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4144] = 4,
    ACTIONS(798), 1,
      anon_sym_COMMA,
    ACTIONS(801), 1,
      anon_sym_RBRACK,
    STATE(193), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4158] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(803), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4168] = 4,
    ACTIONS(805), 1,
      anon_sym_COMMA,
    ACTIONS(807), 1,
      anon_sym_RBRACE,
    STATE(222), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4182] = 4,
    ACTIONS(809), 1,
      anon_sym_COMMA,
    ACTIONS(811), 1,
      anon_sym_RBRACK,
    STATE(223), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4196] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(813), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_EQ,
  [4206] = 4,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(815), 1,
      sym_CONSTANT,
    STATE(253), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4220] = 4,
    ACTIONS(817), 1,
      anon_sym_COMMA,
    ACTIONS(819), 1,
      anon_sym_RBRACK,
    STATE(226), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4234] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    ACTIONS(821), 1,
      anon_sym_SEMI,
    STATE(373), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4248] = 4,
    ACTIONS(674), 1,
      anon_sym_RBRACK,
    ACTIONS(823), 1,
      anon_sym_COMMA,
    STATE(228), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4262] = 4,
    ACTIONS(709), 1,
      anon_sym_LBRACE,
    ACTIONS(825), 1,
      anon_sym_SEMI,
    STATE(379), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4276] = 4,
    ACTIONS(827), 1,
      anon_sym_COMMA,
    ACTIONS(829), 1,
      anon_sym_RBRACK,
    STATE(230), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4290] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(831), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4300] = 4,
    ACTIONS(713), 1,
      anon_sym_RBRACK,
    ACTIONS(833), 1,
      anon_sym_COMMA,
    STATE(233), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4314] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(835), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_EQ,
  [4324] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(837), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4334] = 3,
    ACTIONS(839), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(841), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4346] = 4,
    ACTIONS(477), 1,
      anon_sym_RBRACK,
    ACTIONS(843), 1,
      anon_sym_COMMA,
    STATE(280), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4360] = 4,
    ACTIONS(845), 1,
      anon_sym_COMMA,
    ACTIONS(848), 1,
      anon_sym_RBRACK,
    STATE(210), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4374] = 4,
    ACTIONS(850), 1,
      anon_sym_COMMA,
    ACTIONS(852), 1,
      anon_sym_RBRACK,
    STATE(240), 1,
      aux_sym_coordinate_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(854), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4398] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(856), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4408] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(858), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4418] = 3,
    ACTIONS(860), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(841), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4430] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(862), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4440] = 4,
    ACTIONS(860), 1,
      anon_sym_RBRACK,
    ACTIONS(864), 1,
      anon_sym_COMMA,
    STATE(210), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4454] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(866), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4464] = 4,
    ACTIONS(868), 1,
      anon_sym_COMMA,
    ACTIONS(870), 1,
      anon_sym_RBRACK,
    STATE(244), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4478] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(872), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [4488] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(874), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4498] = 4,
    ACTIONS(805), 1,
      anon_sym_COMMA,
    ACTIONS(876), 1,
      anon_sym_RBRACE,
    STATE(246), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4512] = 4,
    ACTIONS(878), 1,
      anon_sym_COMMA,
    ACTIONS(881), 1,
      anon_sym_RBRACK,
    STATE(223), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4526] = 3,
    ACTIONS(883), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(885), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4538] = 4,
    ACTIONS(887), 1,
      anon_sym_EQ,
    ACTIONS(889), 1,
      anon_sym_fade,
    ACTIONS(891), 1,
      anon_sym_shake,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4552] = 4,
    ACTIONS(883), 1,
      anon_sym_RBRACK,
    ACTIONS(893), 1,
      anon_sym_COMMA,
    STATE(249), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4566] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(895), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [4576] = 4,
    ACTIONS(897), 1,
      anon_sym_COMMA,
    ACTIONS(900), 1,
      anon_sym_RBRACK,
    STATE(228), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4590] = 3,
    ACTIONS(904), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(902), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4602] = 4,
    ACTIONS(904), 1,
      anon_sym_RBRACK,
    ACTIONS(906), 1,
      anon_sym_COMMA,
    STATE(252), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4616] = 4,
    ACTIONS(908), 1,
      anon_sym_COMMA,
    ACTIONS(910), 1,
      anon_sym_RBRACK,
    STATE(256), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4630] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(912), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4640] = 4,
    ACTIONS(914), 1,
      anon_sym_COMMA,
    ACTIONS(917), 1,
      anon_sym_RBRACK,
    STATE(233), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4654] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(919), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4664] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(921), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_EQ,
  [4674] = 3,
    ACTIONS(925), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(923), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4686] = 3,
    ACTIONS(927), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(929), 2,
      sym_COLOR,
      sym_CONSTANT,
  [4698] = 4,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    ACTIONS(931), 1,
      anon_sym_SEMI,
    STATE(384), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4712] = 3,
    ACTIONS(935), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(933), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [4724] = 4,
    ACTIONS(518), 1,
      anon_sym_RBRACK,
    ACTIONS(937), 1,
      anon_sym_COMMA,
    STATE(264), 1,
      aux_sym_coordinate_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4738] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(939), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4748] = 3,
    ACTIONS(941), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(943), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4760] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(945), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4770] = 4,
    ACTIONS(542), 1,
      anon_sym_RBRACK,
    ACTIONS(947), 1,
      anon_sym_COMMA,
    STATE(273), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4784] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(949), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [4794] = 4,
    ACTIONS(951), 1,
      anon_sym_COMMA,
    ACTIONS(954), 1,
      anon_sym_RBRACE,
    STATE(246), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4808] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(956), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4818] = 3,
    ACTIONS(958), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(885), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4830] = 4,
    ACTIONS(960), 1,
      anon_sym_COMMA,
    ACTIONS(963), 1,
      anon_sym_RBRACK,
    STATE(249), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4844] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(672), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4854] = 3,
    ACTIONS(965), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(902), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4866] = 4,
    ACTIONS(967), 1,
      anon_sym_COMMA,
    ACTIONS(970), 1,
      anon_sym_RBRACK,
    STATE(252), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4880] = 4,
    ACTIONS(972), 1,
      anon_sym_COMMA,
    ACTIONS(974), 1,
      anon_sym_RBRACK,
    STATE(205), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4894] = 4,
    ACTIONS(629), 1,
      sym_NUMBER,
    ACTIONS(715), 1,
      sym_CONSTANT,
    STATE(298), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4908] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(976), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [4918] = 4,
    ACTIONS(496), 1,
      anon_sym_RBRACK,
    ACTIONS(978), 1,
      anon_sym_COMMA,
    STATE(193), 1,
      aux_sym_movable_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4932] = 4,
    ACTIONS(980), 1,
      anon_sym_COMMA,
    ACTIONS(982), 1,
      anon_sym_RBRACK,
    STATE(268), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(770), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [4956] = 4,
    ACTIONS(984), 1,
      sym_QUOTED_STRING,
    ACTIONS(986), 1,
      anon_sym_RBRACE,
    STATE(195), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4970] = 4,
    ACTIONS(988), 1,
      anon_sym_COMMA,
    ACTIONS(990), 1,
      anon_sym_RBRACK,
    STATE(269), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4984] = 4,
    ACTIONS(809), 1,
      anon_sym_COMMA,
    ACTIONS(992), 1,
      anon_sym_RBRACK,
    STATE(196), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4998] = 4,
    ACTIONS(994), 1,
      anon_sym_COMMA,
    ACTIONS(996), 1,
      anon_sym_RBRACK,
    STATE(271), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5012] = 4,
    ACTIONS(998), 1,
      anon_sym_COMMA,
    ACTIONS(1000), 1,
      anon_sym_RBRACK,
    STATE(217), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5026] = 4,
    ACTIONS(1002), 1,
      anon_sym_COMMA,
    ACTIONS(1005), 1,
      anon_sym_RBRACK,
    STATE(264), 1,
      aux_sym_coordinate_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5040] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1007), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5050] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1009), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5060] = 3,
    ACTIONS(1011), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5072] = 4,
    ACTIONS(1011), 1,
      anon_sym_RBRACK,
    ACTIONS(1015), 1,
      anon_sym_COMMA,
    STATE(275), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5086] = 4,
    ACTIONS(786), 1,
      anon_sym_RBRACK,
    ACTIONS(1017), 1,
      anon_sym_COMMA,
    STATE(277), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5100] = 3,
    ACTIONS(1019), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1021), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5112] = 4,
    ACTIONS(598), 1,
      anon_sym_RBRACK,
    ACTIONS(1023), 1,
      anon_sym_COMMA,
    STATE(279), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5126] = 4,
    ACTIONS(1025), 1,
      anon_sym_COMMA,
    ACTIONS(1027), 1,
      anon_sym_RBRACK,
    STATE(209), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5140] = 4,
    ACTIONS(1029), 1,
      anon_sym_COMMA,
    ACTIONS(1032), 1,
      anon_sym_RBRACK,
    STATE(273), 1,
      aux_sym_entity_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5154] = 3,
    ACTIONS(1034), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5166] = 4,
    ACTIONS(1036), 1,
      anon_sym_COMMA,
    ACTIONS(1039), 1,
      anon_sym_RBRACK,
    STATE(275), 1,
      aux_sym_color_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5180] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1041), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5190] = 4,
    ACTIONS(1043), 1,
      anon_sym_COMMA,
    ACTIONS(1046), 1,
      anon_sym_RBRACK,
    STATE(277), 1,
      aux_sym_distance_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5204] = 4,
    ACTIONS(1048), 1,
      anon_sym_COMMA,
    ACTIONS(1050), 1,
      anon_sym_RBRACK,
    STATE(201), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5218] = 4,
    ACTIONS(1052), 1,
      anon_sym_COMMA,
    ACTIONS(1055), 1,
      anon_sym_RBRACK,
    STATE(279), 1,
      aux_sym_quantity_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5232] = 4,
    ACTIONS(1057), 1,
      anon_sym_COMMA,
    ACTIONS(1060), 1,
      anon_sym_RBRACK,
    STATE(280), 1,
      aux_sym_entity_or_map_identifier_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5246] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1062), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [5255] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(881), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5264] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1064), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [5273] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(963), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5282] = 3,
    ACTIONS(1066), 1,
      anon_sym_serial_dialog,
    ACTIONS(1068), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5293] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1070), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5302] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1072), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5311] = 3,
    ACTIONS(1074), 1,
      anon_sym_serial_dialog,
    ACTIONS(1076), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5322] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(970), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5331] = 3,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    STATE(16), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5342] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(900), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5351] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1078), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5360] = 3,
    ACTIONS(1080), 1,
      anon_sym_command,
    ACTIONS(1082), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5371] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(841), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [5380] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(887), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5389] = 3,
    ACTIONS(1084), 1,
      anon_sym_slot,
    ACTIONS(1086), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5400] = 3,
    ACTIONS(709), 1,
      anon_sym_LBRACE,
    STATE(77), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5411] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(917), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5420] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1088), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5429] = 3,
    ACTIONS(1090), 1,
      anon_sym_LBRACE,
    STATE(71), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5440] = 3,
    ACTIONS(1092), 1,
      anon_sym_in,
    ACTIONS(1094), 1,
      anon_sym_out,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5451] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1005), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5460] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(866), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5469] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(801), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5478] = 3,
    ACTIONS(1096), 1,
      anon_sym_EQ,
    ACTIONS(1098), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5489] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1060), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5498] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1100), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [5507] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1102), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5516] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(885), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5525] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(902), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [5534] = 3,
    ACTIONS(705), 1,
      anon_sym_LBRACE,
    STATE(76), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5545] = 3,
    ACTIONS(1090), 1,
      anon_sym_LBRACE,
    STATE(78), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5556] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1032), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5565] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(848), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5574] = 3,
    ACTIONS(1104), 1,
      anon_sym_SEMI,
    ACTIONS(1106), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5585] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(721), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5594] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1108), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [5603] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1110), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5612] = 3,
    ACTIONS(1112), 1,
      anon_sym_serial_dialog,
    ACTIONS(1114), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5623] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1039), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5632] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1116), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5641] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(956), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5650] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1046), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5659] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1118), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [5668] = 3,
    ACTIONS(984), 1,
      sym_QUOTED_STRING,
    STATE(330), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5679] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1055), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5688] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1120), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [5697] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1122), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5706] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(1013), 2,
      sym_COLOR,
      sym_CONSTANT,
  [5715] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(954), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [5724] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(742), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5733] = 2,
    ACTIONS(1124), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5741] = 2,
    ACTIONS(1126), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5749] = 2,
    ACTIONS(1128), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5757] = 2,
    ACTIONS(1130), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5765] = 2,
    ACTIONS(1132), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5773] = 2,
    ACTIONS(1134), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5781] = 2,
    ACTIONS(1136), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5789] = 2,
    ACTIONS(1138), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5797] = 2,
    ACTIONS(1140), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5805] = 2,
    ACTIONS(1142), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5813] = 2,
    ACTIONS(1144), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5821] = 2,
    ACTIONS(776), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5829] = 2,
    ACTIONS(1146), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5837] = 2,
    ACTIONS(1148), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5845] = 2,
    ACTIONS(1150), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5853] = 2,
    ACTIONS(1152), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5861] = 2,
    ACTIONS(1154), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5869] = 2,
    ACTIONS(1156), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5877] = 2,
    ACTIONS(1158), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5885] = 2,
    ACTIONS(1160), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5893] = 2,
    ACTIONS(1162), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5901] = 2,
    ACTIONS(1164), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5909] = 2,
    ACTIONS(1166), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5917] = 2,
    ACTIONS(1168), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5925] = 2,
    ACTIONS(1170), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5933] = 2,
    ACTIONS(1172), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5941] = 2,
    ACTIONS(1174), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5949] = 2,
    ACTIONS(1176), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5957] = 2,
    ACTIONS(1178), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5965] = 2,
    ACTIONS(1180), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5973] = 2,
    ACTIONS(1182), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5981] = 2,
    ACTIONS(1184), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5989] = 2,
    ACTIONS(1186), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [5997] = 2,
    ACTIONS(723), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6005] = 2,
    ACTIONS(1188), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6013] = 2,
    ACTIONS(1190), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6021] = 2,
    ACTIONS(1192), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6029] = 2,
    ACTIONS(1194), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6037] = 2,
    ACTIONS(1196), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6045] = 2,
    ACTIONS(1198), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6053] = 2,
    ACTIONS(1200), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6061] = 2,
    ACTIONS(1202), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6069] = 2,
    ACTIONS(1204), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6077] = 2,
    ACTIONS(1206), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6085] = 2,
    ACTIONS(1208), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6093] = 2,
    ACTIONS(1210), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6101] = 2,
    ACTIONS(1212), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6109] = 2,
    ACTIONS(1214), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6117] = 2,
    ACTIONS(1216), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6125] = 2,
    ACTIONS(1218), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6133] = 2,
    ACTIONS(1220), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6141] = 2,
    ACTIONS(1222), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6149] = 2,
    ACTIONS(1224), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6157] = 2,
    ACTIONS(1226), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6165] = 2,
    ACTIONS(1228), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6173] = 2,
    ACTIONS(1230), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6181] = 2,
    ACTIONS(1232), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6189] = 2,
    ACTIONS(1234), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6197] = 2,
    ACTIONS(744), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6205] = 2,
    ACTIONS(1236), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6213] = 2,
    ACTIONS(1238), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6221] = 2,
    ACTIONS(1240), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6229] = 2,
    ACTIONS(1242), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6237] = 2,
    ACTIONS(1244), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6245] = 2,
    ACTIONS(1246), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6253] = 2,
    ACTIONS(1248), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6261] = 2,
    ACTIONS(1250), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6269] = 2,
    ACTIONS(1252), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6277] = 2,
    ACTIONS(1254), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6285] = 2,
    ACTIONS(1256), 1,
      anon_sym_position,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6293] = 2,
    ACTIONS(1258), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6301] = 2,
    ACTIONS(1260), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6309] = 2,
    ACTIONS(1262), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6317] = 2,
    ACTIONS(1264), 1,
      anon_sym_DASH_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6325] = 2,
    ACTIONS(1266), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6333] = 2,
    ACTIONS(1268), 1,
      anon_sym_animation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6341] = 2,
    ACTIONS(1270), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6349] = 2,
    ACTIONS(1272), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6357] = 2,
    ACTIONS(1274), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6365] = 2,
    ACTIONS(1276), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6373] = 2,
    ACTIONS(1278), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6381] = 2,
    ACTIONS(1280), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6389] = 2,
    ACTIONS(1282), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6397] = 2,
    ACTIONS(1284), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6405] = 2,
    ACTIONS(1286), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6413] = 2,
    ACTIONS(1288), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6421] = 2,
    ACTIONS(1290), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6429] = 2,
    ACTIONS(1292), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6437] = 2,
    ACTIONS(1294), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6445] = 2,
    ACTIONS(1296), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6453] = 2,
    ACTIONS(1298), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6461] = 2,
    ACTIONS(1300), 1,
      anon_sym_over,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6469] = 2,
    ACTIONS(1302), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6477] = 2,
    ACTIONS(1304), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6485] = 2,
    ACTIONS(1306), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [6493] = 2,
    ACTIONS(1308), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 36,
  [SMALL_STATE(9)] = 72,
  [SMALL_STATE(10)] = 108,
  [SMALL_STATE(11)] = 142,
  [SMALL_STATE(12)] = 176,
  [SMALL_STATE(13)] = 210,
  [SMALL_STATE(14)] = 244,
  [SMALL_STATE(15)] = 278,
  [SMALL_STATE(16)] = 312,
  [SMALL_STATE(17)] = 346,
  [SMALL_STATE(18)] = 380,
  [SMALL_STATE(19)] = 414,
  [SMALL_STATE(20)] = 448,
  [SMALL_STATE(21)] = 482,
  [SMALL_STATE(22)] = 516,
  [SMALL_STATE(23)] = 550,
  [SMALL_STATE(24)] = 584,
  [SMALL_STATE(25)] = 618,
  [SMALL_STATE(26)] = 652,
  [SMALL_STATE(27)] = 686,
  [SMALL_STATE(28)] = 720,
  [SMALL_STATE(29)] = 754,
  [SMALL_STATE(30)] = 788,
  [SMALL_STATE(31)] = 822,
  [SMALL_STATE(32)] = 856,
  [SMALL_STATE(33)] = 890,
  [SMALL_STATE(34)] = 924,
  [SMALL_STATE(35)] = 958,
  [SMALL_STATE(36)] = 992,
  [SMALL_STATE(37)] = 1026,
  [SMALL_STATE(38)] = 1060,
  [SMALL_STATE(39)] = 1094,
  [SMALL_STATE(40)] = 1128,
  [SMALL_STATE(41)] = 1162,
  [SMALL_STATE(42)] = 1196,
  [SMALL_STATE(43)] = 1230,
  [SMALL_STATE(44)] = 1264,
  [SMALL_STATE(45)] = 1298,
  [SMALL_STATE(46)] = 1332,
  [SMALL_STATE(47)] = 1366,
  [SMALL_STATE(48)] = 1409,
  [SMALL_STATE(49)] = 1452,
  [SMALL_STATE(50)] = 1484,
  [SMALL_STATE(51)] = 1518,
  [SMALL_STATE(52)] = 1552,
  [SMALL_STATE(53)] = 1583,
  [SMALL_STATE(54)] = 1614,
  [SMALL_STATE(55)] = 1645,
  [SMALL_STATE(56)] = 1676,
  [SMALL_STATE(57)] = 1702,
  [SMALL_STATE(58)] = 1721,
  [SMALL_STATE(59)] = 1744,
  [SMALL_STATE(60)] = 1769,
  [SMALL_STATE(61)] = 1788,
  [SMALL_STATE(62)] = 1807,
  [SMALL_STATE(63)] = 1830,
  [SMALL_STATE(64)] = 1849,
  [SMALL_STATE(65)] = 1867,
  [SMALL_STATE(66)] = 1885,
  [SMALL_STATE(67)] = 1901,
  [SMALL_STATE(68)] = 1919,
  [SMALL_STATE(69)] = 1947,
  [SMALL_STATE(70)] = 1965,
  [SMALL_STATE(71)] = 1993,
  [SMALL_STATE(72)] = 2011,
  [SMALL_STATE(73)] = 2041,
  [SMALL_STATE(74)] = 2059,
  [SMALL_STATE(75)] = 2077,
  [SMALL_STATE(76)] = 2093,
  [SMALL_STATE(77)] = 2111,
  [SMALL_STATE(78)] = 2129,
  [SMALL_STATE(79)] = 2147,
  [SMALL_STATE(80)] = 2165,
  [SMALL_STATE(81)] = 2183,
  [SMALL_STATE(82)] = 2210,
  [SMALL_STATE(83)] = 2237,
  [SMALL_STATE(84)] = 2262,
  [SMALL_STATE(85)] = 2277,
  [SMALL_STATE(86)] = 2304,
  [SMALL_STATE(87)] = 2319,
  [SMALL_STATE(88)] = 2346,
  [SMALL_STATE(89)] = 2373,
  [SMALL_STATE(90)] = 2400,
  [SMALL_STATE(91)] = 2427,
  [SMALL_STATE(92)] = 2454,
  [SMALL_STATE(93)] = 2483,
  [SMALL_STATE(94)] = 2510,
  [SMALL_STATE(95)] = 2537,
  [SMALL_STATE(96)] = 2553,
  [SMALL_STATE(97)] = 2577,
  [SMALL_STATE(98)] = 2601,
  [SMALL_STATE(99)] = 2625,
  [SMALL_STATE(100)] = 2649,
  [SMALL_STATE(101)] = 2673,
  [SMALL_STATE(102)] = 2697,
  [SMALL_STATE(103)] = 2720,
  [SMALL_STATE(104)] = 2733,
  [SMALL_STATE(105)] = 2754,
  [SMALL_STATE(106)] = 2777,
  [SMALL_STATE(107)] = 2800,
  [SMALL_STATE(108)] = 2821,
  [SMALL_STATE(109)] = 2844,
  [SMALL_STATE(110)] = 2857,
  [SMALL_STATE(111)] = 2876,
  [SMALL_STATE(112)] = 2897,
  [SMALL_STATE(113)] = 2910,
  [SMALL_STATE(114)] = 2931,
  [SMALL_STATE(115)] = 2952,
  [SMALL_STATE(116)] = 2973,
  [SMALL_STATE(117)] = 2996,
  [SMALL_STATE(118)] = 3019,
  [SMALL_STATE(119)] = 3032,
  [SMALL_STATE(120)] = 3053,
  [SMALL_STATE(121)] = 3073,
  [SMALL_STATE(122)] = 3085,
  [SMALL_STATE(123)] = 3101,
  [SMALL_STATE(124)] = 3117,
  [SMALL_STATE(125)] = 3133,
  [SMALL_STATE(126)] = 3153,
  [SMALL_STATE(127)] = 3173,
  [SMALL_STATE(128)] = 3191,
  [SMALL_STATE(129)] = 3207,
  [SMALL_STATE(130)] = 3225,
  [SMALL_STATE(131)] = 3239,
  [SMALL_STATE(132)] = 3255,
  [SMALL_STATE(133)] = 3267,
  [SMALL_STATE(134)] = 3285,
  [SMALL_STATE(135)] = 3303,
  [SMALL_STATE(136)] = 3321,
  [SMALL_STATE(137)] = 3339,
  [SMALL_STATE(138)] = 3357,
  [SMALL_STATE(139)] = 3375,
  [SMALL_STATE(140)] = 3393,
  [SMALL_STATE(141)] = 3409,
  [SMALL_STATE(142)] = 3421,
  [SMALL_STATE(143)] = 3439,
  [SMALL_STATE(144)] = 3455,
  [SMALL_STATE(145)] = 3471,
  [SMALL_STATE(146)] = 3489,
  [SMALL_STATE(147)] = 3501,
  [SMALL_STATE(148)] = 3521,
  [SMALL_STATE(149)] = 3534,
  [SMALL_STATE(150)] = 3545,
  [SMALL_STATE(151)] = 3560,
  [SMALL_STATE(152)] = 3577,
  [SMALL_STATE(153)] = 3592,
  [SMALL_STATE(154)] = 3609,
  [SMALL_STATE(155)] = 3624,
  [SMALL_STATE(156)] = 3639,
  [SMALL_STATE(157)] = 3652,
  [SMALL_STATE(158)] = 3667,
  [SMALL_STATE(159)] = 3682,
  [SMALL_STATE(160)] = 3697,
  [SMALL_STATE(161)] = 3712,
  [SMALL_STATE(162)] = 3727,
  [SMALL_STATE(163)] = 3744,
  [SMALL_STATE(164)] = 3755,
  [SMALL_STATE(165)] = 3766,
  [SMALL_STATE(166)] = 3779,
  [SMALL_STATE(167)] = 3794,
  [SMALL_STATE(168)] = 3809,
  [SMALL_STATE(169)] = 3826,
  [SMALL_STATE(170)] = 3843,
  [SMALL_STATE(171)] = 3860,
  [SMALL_STATE(172)] = 3873,
  [SMALL_STATE(173)] = 3886,
  [SMALL_STATE(174)] = 3901,
  [SMALL_STATE(175)] = 3914,
  [SMALL_STATE(176)] = 3925,
  [SMALL_STATE(177)] = 3942,
  [SMALL_STATE(178)] = 3953,
  [SMALL_STATE(179)] = 3970,
  [SMALL_STATE(180)] = 3983,
  [SMALL_STATE(181)] = 3996,
  [SMALL_STATE(182)] = 4007,
  [SMALL_STATE(183)] = 4024,
  [SMALL_STATE(184)] = 4035,
  [SMALL_STATE(185)] = 4046,
  [SMALL_STATE(186)] = 4057,
  [SMALL_STATE(187)] = 4068,
  [SMALL_STATE(188)] = 4085,
  [SMALL_STATE(189)] = 4096,
  [SMALL_STATE(190)] = 4109,
  [SMALL_STATE(191)] = 4120,
  [SMALL_STATE(192)] = 4130,
  [SMALL_STATE(193)] = 4144,
  [SMALL_STATE(194)] = 4158,
  [SMALL_STATE(195)] = 4168,
  [SMALL_STATE(196)] = 4182,
  [SMALL_STATE(197)] = 4196,
  [SMALL_STATE(198)] = 4206,
  [SMALL_STATE(199)] = 4220,
  [SMALL_STATE(200)] = 4234,
  [SMALL_STATE(201)] = 4248,
  [SMALL_STATE(202)] = 4262,
  [SMALL_STATE(203)] = 4276,
  [SMALL_STATE(204)] = 4290,
  [SMALL_STATE(205)] = 4300,
  [SMALL_STATE(206)] = 4314,
  [SMALL_STATE(207)] = 4324,
  [SMALL_STATE(208)] = 4334,
  [SMALL_STATE(209)] = 4346,
  [SMALL_STATE(210)] = 4360,
  [SMALL_STATE(211)] = 4374,
  [SMALL_STATE(212)] = 4388,
  [SMALL_STATE(213)] = 4398,
  [SMALL_STATE(214)] = 4408,
  [SMALL_STATE(215)] = 4418,
  [SMALL_STATE(216)] = 4430,
  [SMALL_STATE(217)] = 4440,
  [SMALL_STATE(218)] = 4454,
  [SMALL_STATE(219)] = 4464,
  [SMALL_STATE(220)] = 4478,
  [SMALL_STATE(221)] = 4488,
  [SMALL_STATE(222)] = 4498,
  [SMALL_STATE(223)] = 4512,
  [SMALL_STATE(224)] = 4526,
  [SMALL_STATE(225)] = 4538,
  [SMALL_STATE(226)] = 4552,
  [SMALL_STATE(227)] = 4566,
  [SMALL_STATE(228)] = 4576,
  [SMALL_STATE(229)] = 4590,
  [SMALL_STATE(230)] = 4602,
  [SMALL_STATE(231)] = 4616,
  [SMALL_STATE(232)] = 4630,
  [SMALL_STATE(233)] = 4640,
  [SMALL_STATE(234)] = 4654,
  [SMALL_STATE(235)] = 4664,
  [SMALL_STATE(236)] = 4674,
  [SMALL_STATE(237)] = 4686,
  [SMALL_STATE(238)] = 4698,
  [SMALL_STATE(239)] = 4712,
  [SMALL_STATE(240)] = 4724,
  [SMALL_STATE(241)] = 4738,
  [SMALL_STATE(242)] = 4748,
  [SMALL_STATE(243)] = 4760,
  [SMALL_STATE(244)] = 4770,
  [SMALL_STATE(245)] = 4784,
  [SMALL_STATE(246)] = 4794,
  [SMALL_STATE(247)] = 4808,
  [SMALL_STATE(248)] = 4818,
  [SMALL_STATE(249)] = 4830,
  [SMALL_STATE(250)] = 4844,
  [SMALL_STATE(251)] = 4854,
  [SMALL_STATE(252)] = 4866,
  [SMALL_STATE(253)] = 4880,
  [SMALL_STATE(254)] = 4894,
  [SMALL_STATE(255)] = 4908,
  [SMALL_STATE(256)] = 4918,
  [SMALL_STATE(257)] = 4932,
  [SMALL_STATE(258)] = 4946,
  [SMALL_STATE(259)] = 4956,
  [SMALL_STATE(260)] = 4970,
  [SMALL_STATE(261)] = 4984,
  [SMALL_STATE(262)] = 4998,
  [SMALL_STATE(263)] = 5012,
  [SMALL_STATE(264)] = 5026,
  [SMALL_STATE(265)] = 5040,
  [SMALL_STATE(266)] = 5050,
  [SMALL_STATE(267)] = 5060,
  [SMALL_STATE(268)] = 5072,
  [SMALL_STATE(269)] = 5086,
  [SMALL_STATE(270)] = 5100,
  [SMALL_STATE(271)] = 5112,
  [SMALL_STATE(272)] = 5126,
  [SMALL_STATE(273)] = 5140,
  [SMALL_STATE(274)] = 5154,
  [SMALL_STATE(275)] = 5166,
  [SMALL_STATE(276)] = 5180,
  [SMALL_STATE(277)] = 5190,
  [SMALL_STATE(278)] = 5204,
  [SMALL_STATE(279)] = 5218,
  [SMALL_STATE(280)] = 5232,
  [SMALL_STATE(281)] = 5246,
  [SMALL_STATE(282)] = 5255,
  [SMALL_STATE(283)] = 5264,
  [SMALL_STATE(284)] = 5273,
  [SMALL_STATE(285)] = 5282,
  [SMALL_STATE(286)] = 5293,
  [SMALL_STATE(287)] = 5302,
  [SMALL_STATE(288)] = 5311,
  [SMALL_STATE(289)] = 5322,
  [SMALL_STATE(290)] = 5331,
  [SMALL_STATE(291)] = 5342,
  [SMALL_STATE(292)] = 5351,
  [SMALL_STATE(293)] = 5360,
  [SMALL_STATE(294)] = 5371,
  [SMALL_STATE(295)] = 5380,
  [SMALL_STATE(296)] = 5389,
  [SMALL_STATE(297)] = 5400,
  [SMALL_STATE(298)] = 5411,
  [SMALL_STATE(299)] = 5420,
  [SMALL_STATE(300)] = 5429,
  [SMALL_STATE(301)] = 5440,
  [SMALL_STATE(302)] = 5451,
  [SMALL_STATE(303)] = 5460,
  [SMALL_STATE(304)] = 5469,
  [SMALL_STATE(305)] = 5478,
  [SMALL_STATE(306)] = 5489,
  [SMALL_STATE(307)] = 5498,
  [SMALL_STATE(308)] = 5507,
  [SMALL_STATE(309)] = 5516,
  [SMALL_STATE(310)] = 5525,
  [SMALL_STATE(311)] = 5534,
  [SMALL_STATE(312)] = 5545,
  [SMALL_STATE(313)] = 5556,
  [SMALL_STATE(314)] = 5565,
  [SMALL_STATE(315)] = 5574,
  [SMALL_STATE(316)] = 5585,
  [SMALL_STATE(317)] = 5594,
  [SMALL_STATE(318)] = 5603,
  [SMALL_STATE(319)] = 5612,
  [SMALL_STATE(320)] = 5623,
  [SMALL_STATE(321)] = 5632,
  [SMALL_STATE(322)] = 5641,
  [SMALL_STATE(323)] = 5650,
  [SMALL_STATE(324)] = 5659,
  [SMALL_STATE(325)] = 5668,
  [SMALL_STATE(326)] = 5679,
  [SMALL_STATE(327)] = 5688,
  [SMALL_STATE(328)] = 5697,
  [SMALL_STATE(329)] = 5706,
  [SMALL_STATE(330)] = 5715,
  [SMALL_STATE(331)] = 5724,
  [SMALL_STATE(332)] = 5733,
  [SMALL_STATE(333)] = 5741,
  [SMALL_STATE(334)] = 5749,
  [SMALL_STATE(335)] = 5757,
  [SMALL_STATE(336)] = 5765,
  [SMALL_STATE(337)] = 5773,
  [SMALL_STATE(338)] = 5781,
  [SMALL_STATE(339)] = 5789,
  [SMALL_STATE(340)] = 5797,
  [SMALL_STATE(341)] = 5805,
  [SMALL_STATE(342)] = 5813,
  [SMALL_STATE(343)] = 5821,
  [SMALL_STATE(344)] = 5829,
  [SMALL_STATE(345)] = 5837,
  [SMALL_STATE(346)] = 5845,
  [SMALL_STATE(347)] = 5853,
  [SMALL_STATE(348)] = 5861,
  [SMALL_STATE(349)] = 5869,
  [SMALL_STATE(350)] = 5877,
  [SMALL_STATE(351)] = 5885,
  [SMALL_STATE(352)] = 5893,
  [SMALL_STATE(353)] = 5901,
  [SMALL_STATE(354)] = 5909,
  [SMALL_STATE(355)] = 5917,
  [SMALL_STATE(356)] = 5925,
  [SMALL_STATE(357)] = 5933,
  [SMALL_STATE(358)] = 5941,
  [SMALL_STATE(359)] = 5949,
  [SMALL_STATE(360)] = 5957,
  [SMALL_STATE(361)] = 5965,
  [SMALL_STATE(362)] = 5973,
  [SMALL_STATE(363)] = 5981,
  [SMALL_STATE(364)] = 5989,
  [SMALL_STATE(365)] = 5997,
  [SMALL_STATE(366)] = 6005,
  [SMALL_STATE(367)] = 6013,
  [SMALL_STATE(368)] = 6021,
  [SMALL_STATE(369)] = 6029,
  [SMALL_STATE(370)] = 6037,
  [SMALL_STATE(371)] = 6045,
  [SMALL_STATE(372)] = 6053,
  [SMALL_STATE(373)] = 6061,
  [SMALL_STATE(374)] = 6069,
  [SMALL_STATE(375)] = 6077,
  [SMALL_STATE(376)] = 6085,
  [SMALL_STATE(377)] = 6093,
  [SMALL_STATE(378)] = 6101,
  [SMALL_STATE(379)] = 6109,
  [SMALL_STATE(380)] = 6117,
  [SMALL_STATE(381)] = 6125,
  [SMALL_STATE(382)] = 6133,
  [SMALL_STATE(383)] = 6141,
  [SMALL_STATE(384)] = 6149,
  [SMALL_STATE(385)] = 6157,
  [SMALL_STATE(386)] = 6165,
  [SMALL_STATE(387)] = 6173,
  [SMALL_STATE(388)] = 6181,
  [SMALL_STATE(389)] = 6189,
  [SMALL_STATE(390)] = 6197,
  [SMALL_STATE(391)] = 6205,
  [SMALL_STATE(392)] = 6213,
  [SMALL_STATE(393)] = 6221,
  [SMALL_STATE(394)] = 6229,
  [SMALL_STATE(395)] = 6237,
  [SMALL_STATE(396)] = 6245,
  [SMALL_STATE(397)] = 6253,
  [SMALL_STATE(398)] = 6261,
  [SMALL_STATE(399)] = 6269,
  [SMALL_STATE(400)] = 6277,
  [SMALL_STATE(401)] = 6285,
  [SMALL_STATE(402)] = 6293,
  [SMALL_STATE(403)] = 6301,
  [SMALL_STATE(404)] = 6309,
  [SMALL_STATE(405)] = 6317,
  [SMALL_STATE(406)] = 6325,
  [SMALL_STATE(407)] = 6333,
  [SMALL_STATE(408)] = 6341,
  [SMALL_STATE(409)] = 6349,
  [SMALL_STATE(410)] = 6357,
  [SMALL_STATE(411)] = 6365,
  [SMALL_STATE(412)] = 6373,
  [SMALL_STATE(413)] = 6381,
  [SMALL_STATE(414)] = 6389,
  [SMALL_STATE(415)] = 6397,
  [SMALL_STATE(416)] = 6405,
  [SMALL_STATE(417)] = 6413,
  [SMALL_STATE(418)] = 6421,
  [SMALL_STATE(419)] = 6429,
  [SMALL_STATE(420)] = 6437,
  [SMALL_STATE(421)] = 6445,
  [SMALL_STATE(422)] = 6453,
  [SMALL_STATE(423)] = 6461,
  [SMALL_STATE(424)] = 6469,
  [SMALL_STATE(425)] = 6477,
  [SMALL_STATE(426)] = 6485,
  [SMALL_STATE(427)] = 6493,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(300),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(300),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(392),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(319),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(327),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(318),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(413),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(290),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(363),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(372),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(288),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(378),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(296),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(385),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(142),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(285),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(415),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(293),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(341),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(342),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(225),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(413),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(255),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(290),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(363),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(372),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(288),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(378),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(296),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(385),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(285),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(415),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(293),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(341),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(342),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(225),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unpause_script, 4, 0, 44),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unpause_script, 4, 0, 44),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 17),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 17),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 18),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 18),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 18),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 18),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 8),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 8),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 34),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 34),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 35),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 35),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 34),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 34),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 36),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 36),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 37),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 37),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 38),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 38),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 39),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 39),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 40),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 40),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 38),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 38),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 39),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 39),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command, 4, 0, 42),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 4, 0, 42),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_alias, 4, 0, 43),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 4, 0, 43),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_hide_command, 4, 0, 42),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 4, 0, 42),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unhide_command, 4, 0, 42),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 4, 0, 42),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_pause_script, 4, 0, 44),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_pause_script, 4, 0, 44),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_set_position, 4, 0, 46),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_set_position, 4, 0, 46),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 54),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 54),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 5, 0, 55),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 5, 0, 55),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 54),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 54),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command_arg, 6, 0, 59),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 6, 0, 59),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_play_entity_animation, 6, 0, 60),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_play_entity_animation, 6, 0, 60),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_in, 8, 0, 66),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_in, 8, 0, 66),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_fade_out, 8, 0, 66),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_fade_out, 8, 0, 66),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_camera_shake, 8, 0, 67),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_camera_shake, 8, 0, 67),
  [299] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 41),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 41),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [307] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(300),
  [310] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(300),
  [313] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(392),
  [316] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [319] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(319),
  [322] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(327),
  [325] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(232),
  [328] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(318),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 49),
  [333] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 49), SHIFT_REPEAT(322),
  [336] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 49), SHIFT_REPEAT(247),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(322),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [363] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(328),
  [367] = {.entry = {.count = 1, .reusable = false}}, SHIFT(343),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(343),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 22),
  [377] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 22),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 32),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 32),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(282),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [387] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 4),
  [391] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 4),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [395] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 30),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 11),
  [413] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 11),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [417] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(305),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [427] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [431] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [433] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 21),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 5),
  [437] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 5),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 6),
  [441] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 6),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 7),
  [445] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 7),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [449] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [453] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(369),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(299),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(401),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 28),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [475] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 8),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 31),
  [481] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 31),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(356),
  [485] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [487] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(369),
  [490] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(299),
  [493] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(216),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(389),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(390),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 50),
  [502] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 50),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(321),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(366),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [514] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(377),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(332),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(418),
  [524] = {.entry = {.count = 1, .reusable = false}}, SHIFT(402),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(402),
  [530] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [532] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [538] = {.entry = {.count = 1, .reusable = false}}, SHIFT(308),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map, 1, 0, 0),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(368),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(331),
  [546] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 33), SHIFT_REPEAT(86),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 33),
  [551] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 33), SHIFT_REPEAT(308),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(362),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 15),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(419),
  [560] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 1, 0, 9),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 52),
  [564] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 52), SHIFT_REPEAT(130),
  [567] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 52),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 53),
  [571] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 53),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 12),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 56),
  [577] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 56),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 57),
  [581] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 57),
  [583] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 57), SHIFT_REPEAT(356),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(336),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 24),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier, 2, 0, 19),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(417),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(326),
  [602] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(315),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(397),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(404),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 23),
  [612] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 23), SHIFT_REPEAT(321),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(374),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(333),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(409),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(349),
  [633] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 29),
  [635] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 29),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(358),
  [639] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [641] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [643] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(321),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(393),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(394),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(398),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(352),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(350),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(410),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(414),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [668] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(425),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 2, 0, 0),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [682] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 26), SHIFT_REPEAT(220),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 26),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 27),
  [689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(403),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(411),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(317),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(380),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(382),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(298),
  [717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [719] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 3, 0, 0),
  [721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier, 2, 0, 10),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(420),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(422),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(423),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(323),
  [735] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 47),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 48),
  [739] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 48), SHIFT_REPEAT(419),
  [742] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier, 1, 0, 2),
  [744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [746] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 51),
  [748] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 51),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(383),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [760] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 4, 0, 0),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(371),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 1, 0, 0),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [770] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [774] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 3),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [780] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_or_map_identifier_expansion, 5, 0, 0),
  [782] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 61),
  [784] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 62),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(412),
  [788] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 64),
  [790] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 65),
  [792] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 65),
  [794] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 12),
  [796] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [798] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [801] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_movable_identifier_expansion_repeat1, 2, 0, 0),
  [803] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(325),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [813] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier, 3, 0, 20),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [829] = {.entry = {.count = 1, .reusable = true}}, SHIFT(395),
  [831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(334),
  [833] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [835] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier, 2, 0, 3),
  [837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [839] = {.entry = {.count = 1, .reusable = true}}, SHIFT(339),
  [841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(314),
  [843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [845] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(294),
  [848] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [850] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(338),
  [854] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier, 2, 0, 3),
  [856] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier, 2, 0, 45),
  [858] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 12),
  [860] = {.entry = {.count = 1, .reusable = true}}, SHIFT(426),
  [862] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [864] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [866] = {.entry = {.count = 1, .reusable = true}}, SHIFT(347),
  [868] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [870] = {.entry = {.count = 1, .reusable = true}}, SHIFT(345),
  [872] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 13),
  [874] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [876] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [878] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [881] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [883] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [885] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [887] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_camera, 1, 0, 0),
  [889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(301),
  [891] = {.entry = {.count = 1, .reusable = true}}, SHIFT(399),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [895] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 21),
  [897] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(250),
  [900] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [902] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [904] = {.entry = {.count = 1, .reusable = true}}, SHIFT(359),
  [906] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [908] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [910] = {.entry = {.count = 1, .reusable = true}}, SHIFT(364),
  [912] = {.entry = {.count = 1, .reusable = true}}, SHIFT(297),
  [914] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(254),
  [917] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [921] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier, 1, 0, 3),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [925] = {.entry = {.count = 1, .reusable = true}}, SHIFT(361),
  [927] = {.entry = {.count = 1, .reusable = true}}, SHIFT(367),
  [929] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [931] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [933] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 16),
  [935] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 16),
  [937] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [939] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier, 3, 0, 20),
  [941] = {.entry = {.count = 1, .reusable = true}}, SHIFT(376),
  [943] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [945] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [947] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [949] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [951] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(325),
  [954] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [956] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [958] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [960] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(309),
  [963] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [965] = {.entry = {.count = 1, .reusable = true}}, SHIFT(388),
  [967] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(310),
  [970] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [972] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [974] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [976] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 1, 0, 0),
  [978] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [980] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [982] = {.entry = {.count = 1, .reusable = true}}, SHIFT(391),
  [984] = {.entry = {.count = 1, .reusable = true}}, SHIFT(408),
  [986] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [988] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [990] = {.entry = {.count = 1, .reusable = true}}, SHIFT(396),
  [992] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [994] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [996] = {.entry = {.count = 1, .reusable = true}}, SHIFT(400),
  [998] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [1000] = {.entry = {.count = 1, .reusable = true}}, SHIFT(353),
  [1002] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_coordinate_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [1005] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_coordinate_identifier_expansion_repeat1, 2, 0, 0),
  [1007] = {.entry = {.count = 1, .reusable = true}}, SHIFT(316),
  [1009] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [1011] = {.entry = {.count = 1, .reusable = true}}, SHIFT(406),
  [1013] = {.entry = {.count = 1, .reusable = true}}, SHIFT(320),
  [1015] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [1017] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [1019] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [1021] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [1023] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [1025] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [1027] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [1029] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [1032] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_identifier_expansion_repeat1, 2, 0, 0),
  [1034] = {.entry = {.count = 1, .reusable = true}}, SHIFT(421),
  [1036] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(329),
  [1039] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_color_expansion_repeat1, 2, 0, 0),
  [1041] = {.entry = {.count = 1, .reusable = true}}, SHIFT(365),
  [1043] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [1046] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_distance_expansion_repeat1, 2, 0, 0),
  [1048] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [1050] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [1052] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [1055] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quantity_expansion_repeat1, 2, 0, 0),
  [1057] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [1060] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_or_map_identifier_expansion_repeat1, 2, 0, 0),
  [1062] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 25),
  [1064] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 14),
  [1066] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [1068] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [1070] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [1072] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [1074] = {.entry = {.count = 1, .reusable = true}}, SHIFT(354),
  [1076] = {.entry = {.count = 1, .reusable = true}}, SHIFT(355),
  [1078] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [1080] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [1082] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [1084] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [1086] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [1088] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [1090] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [1092] = {.entry = {.count = 1, .reusable = true}}, SHIFT(360),
  [1094] = {.entry = {.count = 1, .reusable = true}}, SHIFT(370),
  [1096] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 2, 0, 0),
  [1098] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 2, 0, 0),
  [1100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 63),
  [1102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [1104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [1106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [1108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [1110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(312),
  [1112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(344),
  [1114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(375),
  [1116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [1118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [1120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(311),
  [1122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 58),
  [1124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier_expansion, 5, 0, 0),
  [1126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [1128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(241),
  [1130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [1132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [1134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [1136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier_expansion, 3, 0, 0),
  [1138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [1140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [1142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [1144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [1146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(386),
  [1148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 3, 0, 0),
  [1150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [1152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [1154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [1156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [1158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [1160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [1162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [1164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [1166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [1168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [1170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(346),
  [1172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [1174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [1176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [1178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [1180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [1182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 5, 0, 0),
  [1184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(340),
  [1186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 3, 0, 0),
  [1188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 5, 0, 0),
  [1190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 2, 0, 0),
  [1192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_identifier_expansion, 4, 0, 0),
  [1194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [1196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [1198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 2, 0, 0),
  [1200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [1202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [1204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 2, 0, 0),
  [1206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(416),
  [1208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [1210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier_expansion, 4, 0, 0),
  [1212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(357),
  [1214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [1216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [1218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [1220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [1222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [1224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [1226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [1228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [1230] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [1232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [1234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_movable_identifier_expansion, 4, 0, 0),
  [1236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 3, 0, 0),
  [1238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [1240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [1242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [1244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [1246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 3, 0, 0),
  [1248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [1250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [1252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [1254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 3, 0, 0),
  [1256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [1258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [1260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [1262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [1264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [1266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 4, 0, 0),
  [1268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(405),
  [1270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [1272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [1274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [1276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [1278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 4, 0, 0),
  [1280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [1282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [1284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [1286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [1288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 4, 0, 0),
  [1290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coordinate_identifier_expansion, 2, 0, 0),
  [1292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(351),
  [1294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [1296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_color_expansion, 5, 0, 0),
  [1298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [1300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_distance_expansion, 5, 0, 0),
  [1302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [1304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_expansion, 5, 0, 0),
  [1306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [1308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
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
